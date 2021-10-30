#!/usr/bin/env python
#
# OVERVIEW:
# - hvcc needs to be run on the input file (with appropriate flags for generating project).
# - each of the "GENERATE" sections need to do certain things related to the Heavy_<PatchName>.cpp/.hpp generated files
# - new output folder is created with the puredata files' name, containing new project.
# - optionally, we could have it build the example after, but that'd require bringing the toolchain along for the ride.
#
# * INCLUDES: need to include the generated "Heavy_PatchName.hpp" file
# * GLOBALS: need to declare Heavy_PatchName object with samplerate set.
# * AUDIOCALLBACK:
#     * Send float parameters to Heavy_PatchName object via Heavy_PatchName::sendFloatToReceiver()
#     * call Heavy_PatchName object's process function
# * PREINIT: 
#     * probe Heavy object for number of channels and control data.
#     * configure Audio for 2 or 4 channel audio depending.
# * POSTINIT: 
#     * configure daisy::Parameter objects with same min/max and linear curve settings for passing to Heavy
#     * sendFloatToReceiver for all defaults.
#
#
import os
import time
import json
import sys
import argparse
import subprocess
import hvcc

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

def main():
    tick = time.time()

    boardlist = ['seed', 'patch', 'patch_sm', 'patch_init', 'pod', 'field']

    parser = argparse.ArgumentParser(description='Utility for converting Puredate files to Daisy projects, uses HVCC inside')
    parser.add_argument('pd_input', help='path to puredata file.')
    parser.add_argument('-b',  '--board', help=f'hardware platform for generated output. The supported boards are: {", ".join(boardlist)}', default='seed')
    parser.add_argument('-p',  '--search_paths', action='append', help="Add a list of directories to search through for abstractions.")
    parser.add_argument('-d', '--directory', type=str, help="set the parent directory of the output.", default='.')
    parser.add_argument('-f', '--force', help='replace existing files without prompt', action='store_true')
    parser.add_argument('--ram', type=str, help='follow with "speed" or "size" to optimize RAM usage for your desired parameter (defaults to speed).', default='speed')
    parser.add_argument('--rom', type=str, help='follow with "speed", "size", or "double_size" to optimize ROM usage for your desired parameter (defaults to speed).', default='speed')
    parser.add_argument('--libdaisy-depth', type=int, help='specify the number of directories between the project and libDaisy.', default=2)
    parser.add_argument('--no-build',  help='prevent automatic building and flashing after hvcc generation', action='store_true')
    # parser.add_argument('--list-boards', help='list boards that have integrated support', action='store_true')

    args = parser.parse_args()
    inpath = os.path.abspath(args.pd_input)
    search_paths = args.search_paths or []
    copyright = ""

    # why can't we have nice things
    # if args.list_boards:
    #     boardlist = ['seed', 'patch', 'patch_sm', 'patch_init', 'pod', 'field']
    #     print(', '.join(boardlist))
    #     halt()

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

    meta = {"daisy": {"board": args.board}}
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
        print(f'\n\{Colours.green}Note: a rom type of "{rom_type}" means you\'ll be running your project with the provided bootloader.{Colours.end}')

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

            # clear any exceptions such that results can be JSONified if necessary
            r["notifs"]["exception"] = []

        # print any warnings
        for i, warning in enumerate(r["notifs"].get("warnings", [])):
            print("{4:3d}) {2}Warning{3} {0}: {1}".format(
                r["stage"], warning["message"], Colours.yellow, Colours.end, i + 1))

    if verbose:
        print("Total compile time: {0:.2f}ms".format(1000 * (time.time() - tick)))

    if not args.no_build:
        daisy_src = os.path.join(output, 'daisy/source')
        if meta['daisy'].get('bootloader', False):
            build_process = subprocess.Popen(f'make -C {daisy_src} && make program-app -C {daisy_src}',
                shell=True, stderr=subprocess.STDOUT)
        else:
            build_process = subprocess.Popen(f'make -C {daisy_src} && make program-dfu -C {daisy_src}',
                shell=True, stderr=subprocess.STDOUT)
            
        build_process.wait()

if __name__ == "__main__":
    main()