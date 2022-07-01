#!/usr/bin/env python

import os
import re
import time
import json
import sys
import argparse
import subprocess
import shutil
import hvcc

BOARDLIST = ['pod', 'patch', 'patch_init', 'field', 'petal']

class Colours:
    purple = "\033[95m"
    cyan = "\033[96m"
    dark_cyan = "\033[36m"
    blue = "\033[94m"
    green = "\033[92m"
    yellow = "\033[93m"
    red = "\033[91m"
    bold = "\033[1m"
    underline = "\033[4m"
    end = "\033[0m"

class InputObject:
    def __init__(self, pd_input, **kwargs):
        self.pd_input = pd_input
        self.board = kwargs.get('board', BOARDLIST[0])
        self.custom_json = kwargs.get('custom_json', None)
        self.search_paths = kwargs.get('search_paths', None)
        self.directory = kwargs.get('directory', None)
        self.force = kwargs.get('force', False)
        self.ram = kwargs.get('ram', 'speed')
        self.rom = kwargs.get('rom', 'speed')
        self.libdaisy_depth = kwargs.get('libdaisy_depth', 1)
        self.no_build = kwargs.get('no_build', False)

# # Note -- this probably already exists as a module, but here's mine
def queryUser(prompt, fallback='n'):
    trueTuple = ('y', 'yes')
    falseTuple = ('n', 'no')
    if fallback.lower() in trueTuple:
        response = input(prompt + ' [Y/n] ')
        return response.lower().strip() not in falseTuple
    elif fallback.lower() in falseTuple:
        response = input(prompt + ' [y/N] ')
        return response.lower().strip() in trueTuple
    else:
        response = input(prompt + ' [y/n] ')
        while (response.lower().strip() not in ('y', 'yes', 'n', 'no')):
            response = input(prompt + 'please provide a valid yes/no input ')
        return True if response.lower().strip() in trueTuple else False

def halt():
    print('No files generated.')
    sys.exit(1)

def main(args):
    tick = time.time()

    inpath = os.path.abspath(args.pd_input)
    search_paths = args.search_paths or []
    copyright = ""

    results = {}
    verbose = False

    basename = os.path.basename(inpath).split('.')[0]
    parent = args.directory
    output = os.path.join(parent, basename)

    if os.path.exists(output) and not args.force:
        if queryUser(f'"{output}" already exists. Overwrite?'):
            pass
        else:
            halt()

    print(f'Generating project in "{output}"')

    if args.custom_json == '':
        if args.board is None:
            print(f'{Colours.red}Error:{Colours.end} when not using custom JSON (-c), the board must be specified (-b)')
            halt()
        else:
            meta = {"daisy": {"board": args.board}}
    else:
        try:
            with open(args.custom_json, 'rb') as file:
                custom_json = json.load(file)
        except FileNotFoundError:
            print(f'{Colours.red}Error:{Colours.end} unable to open custom json file "{args.custom_json}"')
            halt()
        meta = {"daisy": {"board": custom_json['name'], "board_file": args.custom_json}}

    meta_path = os.path.join(os.path.dirname(__file__), "util/daisy.json")
    ram_type = args.ram

    if ram_type not in ('size', 'speed'):
        print(f'{Colours.red}Error:{Colours.end} unknown ram option "{ram_type}"')
        halt()

    global rom_type
    rom_type = args.rom

    if rom_type not in ('size', 'speed', 'double_size'):
        print(f'{Colours.red}Error:{Colours.end} unknown rom option "{rom_type}"')
        halt()

    if rom_type in ('size', 'double_size'):
        print(f'\n{Colours.green}Note: a rom type of "{rom_type}" means you\'ll be running your project with the Daisy bootloader.{Colours.end}')

    linker_file = ''
    if rom_type == 'double_size':
        linker_file = 'qspi_linker_sdram.lds' if ram_type == 'size' else 'qspi_linker.lds'
        meta['daisy']['bootloader'] = True
    elif rom_type == 'size':
        linker_file = 'sram_linker_sdram.lds' if ram_type == 'size' else 'sram_linker.lds'
        meta['daisy']['bootloader'] = True
    elif ram_type == 'size':
        linker_file = 'default_linker_sdram.lds'

    meta['daisy']['linker_script'] = linker_file

    with open(meta_path, 'w') as file:
        json.dump(meta, file)

    results = hvcc.compile_dataflow(
        in_path=inpath,
        out_dir=output,
        patch_name=basename,
        patch_meta_file=meta_path,
        search_paths=search_paths,
        generators=('daisy'),
        verbose=verbose,
        copyright=copyright,
    )

    for r in list(results.values()):
        # print any errors
        if r["notifs"].get("has_error", False):
            for i, error in enumerate(r["notifs"].get("errors", [])):
                print("{4:3d}) {2}Error{3} {0}: {1}".format(
                    r["stage"], error["message"], Colours.red, Colours.end, i + 1))

            # only print exception if no errors are indicated
            if len(r["notifs"].get("errors", [])) == 0 and r["notifs"].get("exception", None) is not None:
                print("{2}Error{3} {0} exception: {1}".format(
                    r["stage"], r["notifs"]["exception"], Colours.red, Colours.end))

            sys.exit(1)
            # # clear any exceptions such that results can be JSONified if necessary
            # r["notifs"]["exception"] = []

        # print any warnings
        for i, warning in enumerate(r["notifs"].get("warnings", [])):
            print("{4:3d}) {2}Warning{3} {0}: {1}".format(
                r["stage"], warning["message"], Colours.yellow, Colours.end, i + 1))

    if verbose:
        print("Total compile time: {0:.2f}ms".format(1000 * (time.time() - tick)))

    # Reorganize project structure to be more friendly

    # delete unused folders
    shutil.rmtree(os.path.join(output, 'c'))
    shutil.rmtree(os.path.join(output, 'hv'))
    shutil.rmtree(os.path.join(output, 'ir'))
    shutil.copytree(os.path.join(output, 'daisy'), output, dirs_exist_ok=True)
    shutil.rmtree(os.path.join(output, 'daisy'))
    os.unlink(os.path.join(output, 'build.json'))

    # Find main file
    main_file = None
    target = None
    main_regex = re.compile('(HeavyDaisy_.+?).cpp')
    for file in os.listdir(os.path.join(output, 'source')):
        match = main_regex.search(file)
        if match is not None:
            main_file = file
            target = match.group(1)
            break

    # If we can find the main file, then we can easily make the project structure even a bit nicer
    if main_file is not None:
        shutil.move(os.path.join(output, 'source', main_file), os.path.join(output, main_file))
        os.unlink(os.path.join(output, 'source', 'Makefile'))

        makefile_path = os.path.join(os.path.dirname(__file__), 'util', 'Makefile')
        with open(makefile_path, 'r') as file:
            makefile = file.read()

        makefile = makefile.replace('# GENERATE TARGET', f'TARGET={target}')
        makefile = makefile.replace('# LIBDAISY DEPTH', '../'*args.libdaisy_depth)
        if meta['daisy'].get('bootloader', False):
            makefile = makefile.replace('# BOOTLOADER', 'C_DEFS += -DBOOT_APP')

        if linker_file != '':
            makefile = makefile.replace('# LINKER', f'LDSCRIPT = {linker_file}')
            shutil.copy2(os.path.join(os.path.dirname(__file__), 'util', linker_file), os.path.join(output, linker_file))
        with open(os.path.join(output, 'Makefile'), 'w') as file:
            file.write(makefile)

        if not args.no_build:
            if meta['daisy'].get('bootloader', False):
                build_process = subprocess.Popen(f'make -C {output} && make program-app -C {output}',
                    shell=True, stderr=subprocess.STDOUT)
            else:
                build_process = subprocess.Popen(f'make -C {output} && make program-dfu -C {output}',
                    shell=True, stderr=subprocess.STDOUT)

            build_process.wait()

    else:
        # If we weren't able to find the main file, then just resort to normal building
        if not args.no_build:
            daisy_src = os.path.join(output, 'source')
            if meta['daisy'].get('bootloader', False):
                build_process = subprocess.Popen(f'make -C {daisy_src} && make program-app -C {daisy_src}',
                    shell=True, stderr=subprocess.STDOUT)
            else:
                build_process = subprocess.Popen(f'make -C {daisy_src} && make program-dfu -C {daisy_src}',
                    shell=True, stderr=subprocess.STDOUT)

            build_process.wait()

if __name__ == "__main__":

    parser = argparse.ArgumentParser(description='Utility for converting Puredate files to Daisy projects, uses HVCC inside')
    parser.add_argument('pd_input', help='path to puredata file.')
    parser.add_argument('-b', '--board', help=f'hardware platform for generated output. The supported boards are: {", ".join(BOARDLIST)}', default=None)
    parser.add_argument('-c', '--custom-json', type=str, help='provide a custom JSON board description', default='')
    parser.add_argument('-p', '--search_paths', action='append', help="Add a list of directories to search through for abstractions.")
    parser.add_argument('-d', '--directory', type=str, help="set the parent directory of the output.", default='.')
    parser.add_argument('-f', '--force', help='replace existing files without prompt', action='store_true')
    parser.add_argument('--ram', type=str, help='follow with "speed" or "size" to optimize RAM usage for your desired parameter (defaults to speed).', default='speed')
    parser.add_argument('--rom', type=str, help='follow with "speed", "size", or "double_size" to optimize ROM usage for your desired parameter (defaults to speed).', default='speed')
    parser.add_argument('--libdaisy-depth', type=int, help='specify the number of directories between the project and libDaisy.', default=1)
    parser.add_argument('--no-build',  help='prevent automatic building and flashing after hvcc generation', action='store_true')

    args = parser.parse_args()
    main(args)