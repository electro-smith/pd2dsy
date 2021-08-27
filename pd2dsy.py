#!/usr/bin/env python
#
# OVERVIEW:
# - hvcc needs to be run on the input file (with appropriate flags for generating project.
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
# TODO:
# * Add json or yaml meta data file for board info (details on controls, names, etc.)
# * Determine how to handle non-analog controls like buttons, encoders, etc.
# * Determine how to handle the DaisySeed / DaisyBoard difference for lack of hw.Configure() or not.
#     for now it can be detected/generated into the PREINIT section.
#
import os
import sys
import argparse
import subprocess
import shutil
import fileinput
#import hvcc.hvcc as hv

#sorry for all the global vars....
basename = ''
filename = ''
board = ''
linker = ''
bootloader = ''
ram_type = ''
rom_type = ''
libdaisy_depth = ''

def searchReplace(file, find, replace):
    f = open(file,'r')
    filedata = f.read()
    f.close()

    newdata = filedata.replace(find, replace)

    f = open(file,'w')
    f.write(newdata)
    f.close()

paths = {
    "Directory" : "",
    "Template" : "",
    "Makefile" : "",
    "Boards" : "",
    "Launch" : "",
    "Tasks" : "",
    "Properties" : "",
}

"""
#ifdef DEBUG
asm("bkpt 255");
#endif
"""
    
replaceComments = {
    "Includes"  :  "// GENERATE INCLUDES",
    "Globals"   :  "// GENERATE GLOBALS",
    "Debug"     :  "// GENERATE DEBUG",
    "Preinit"   :  "// GENERATE PREINIT",
    "ADC"       :  "// GENERATE ADC",
    "Loop"      :  "// GENERATE INFINITELOOP",
    "Debounce"  :  "// GENERATE DEBOUNCE",
    "Controls"  :  "// GENERATE CONTROLS",
    "Target"    :  "# GENERATE TARGET",
    "Linker"    :  "# LINKER",
    "Bootloader":  "# BOOTLOADER",
    "Depth"     :  "# LIBDAISY DEPTH",
    "Board"     :  "// GENERATE BOARD",
}
    
def generateCpp():
    #Includes
    searchReplace(paths["Template"], replaceComments["Includes"], '#include "c/Heavy_' + basename + '.hpp"')

    #Globals
    searchReplace(paths["Template"], replaceComments["Globals"], 'Heavy_' + basename + ' hv(SAMPLE_RATE);')

    #Bootloader debug
    if rom_type == 'size':
        searchReplace(paths["Template"], replaceComments["Debug"], '#ifdef DEBUG\n    asm("bkpt 255");\n    #endif\n')
        
    #Preinit
    st = ''
    if (board == 'seed'):
        st = 'hardware->Configure();'
    searchReplace(paths["Template"], replaceComments["Preinit"], st)

    #ADC
    st = ''
    if (board != "seed"):
        st = 'hardware->StartAdc();'
    searchReplace(paths["Template"], replaceComments["ADC"], st)

    #InfiniteLoop
    if (board == 'patch'):
        searchReplace(paths["Template"], replaceComments["Loop"], 'hardware->DisplayControls(false);')
    
    #Debounce
    if (board != "seed"):
        searchReplace(paths["Template"], replaceComments["Debounce"], 'hardware->DebounceControls();\nhardware->UpdateAnalogControls();')

    #Controls
    if(board == "seed"):
        searchReplace(paths["Template"], replaceComments["Controls"], "hv.sendFloatToReceiver(info.hash, 0.f);")

        
def generateMakefile():
    searchReplace(paths["Makefile"], replaceComments["Target"], 'TARGET = ' + basename)
    searchReplace(paths["Makefile"], replaceComments["Linker"], linker)
    searchReplace(paths["Makefile"], replaceComments["Bootloader"], bootloader)
    searchReplace(paths["Makefile"], replaceComments["Depth"], libdaisy_depth)

def generateVSCode():
    searchReplace(paths["Launch"], replaceComments["Target"], basename)
    searchReplace(paths["Tasks"], replaceComments["Depth"], libdaisy_depth)
    searchReplace(paths["Properties"], replaceComments["Depth"], libdaisy_depth)
        
def generateBoard():
    #board type
    searchReplace(paths["Board"], replaceComments["Board"], '#define DSY_BOARD Daisy' + board.capitalize())    

    #remove comments around board init stuff
    searchReplace(paths["Board"], "/* " + board, "")    
    searchReplace(paths["Board"], board + " */", "")    
    
replaceFunctions = {
    "Includes" : generateCpp,
    "Makefile" : generateMakefile,
    "Board"    : generateBoard,
    "VSCode"   : generateVSCode,
}

# Note -- this probably already exists as a module, but here's mine
def queryUser(prompt, fallback='n'):
    trueTuple = ('y', 'yes')
    falseTuple = ('n', 'no')
    if fallback.lower() in trueTuple:
        response = raw_input(prompt + ' [Y/n] ')
        return response.lower().strip() not in falseTuple
    elif fallback.lower() in falseTuple:
        response = raw_input(prompt + ' [y/N] ')
        return response.lower().strip() in trueTuple
    else:
        response = raw_input(prompt + ' [y/n] ')
        while (response.lower().strip() not in ('y', 'yes', 'n', 'no')):
            response = raw_input(prompt + 'please provide a valid yes/no input ')
        return True if response.lower().strip() in trueTuple else False

def halt():
    print('No files generated.')
    sys.exit(1)

def main():
    parser = argparse.ArgumentParser(description='Utility for converting Puredate files to Daisy projects, uses HVCC inside')
    parser.add_argument('pd_input', help='path to puredata file.')
    parser.add_argument('-b',  '--board', help='hardware platform for generated output.', default='seed')
    parser.add_argument('-p',  '--search_paths', action='append', help="Add a list of directories to search through for abstractions.")
    parser.add_argument('-c',  '--hvcc_cmd', type=str, help="hvcc command.", default='python hvcc/hvcc.py')
    parser.add_argument('-d', '--directory', type=str, help="set the parent directory of the output.", default='.')
    parser.add_argument('--ram', type=str, help='follow with "speed" or "size" to optimize RAM usage for your desired parameter (defaults to speed).', default='speed')
    parser.add_argument('--rom', type=str, help='follow with "speed", "size", or "double_size" to optimize ROM usage for your desired parameter (defaults to speed).', default='speed')
    parser.add_argument('--libdaisy-depth', type=int, help='specify the number of directories between the project and libDaisy.', default=2)

    args = parser.parse_args()
    inpath = os.path.abspath(args.pd_input)
    search_paths = args.search_paths or []

    global ram_type
    ram_type = args.ram

    if ram_type not in ('size', 'speed'):
        print('Error: unknown ram option "' + ram_type + '"')
        halt()

    global rom_type
    rom_type = args.rom

    if rom_type not in ('size', 'speed', 'double_size'):
        print('Error: unknown rom option "' + rom_type + '"')
        halt()

    if rom_type in ('size', 'double_size'):
        print('\n\033[0;32mNote: a rom type of "' + rom_type + '" means you\'ll be running your project with the provided bootloader.\033[0m')

    global libdaisy_depth
    libdaisy_depth = "../" * args.libdaisy_depth

    global basename
    basename = os.path.basename(inpath).split('.')[0]

    parent = args.directory
    output = os.path.join(parent, basename)

    global board
    board = args.board.lower()
    print(("Converting {} for {} platform".format(basename, board)))

    # run heavy
    if not os.path.exists(parent):
        if not queryUser('Directory "' + parent + '" does not exist. Create?', fallback='y'):
            halt()
        # normpath prevents makedirs from getting confused
        os.makedirs(os.path.normpath(parent))
    
    if os.path.exists(output):
        beautified = output if output[:2] != './' else output[2:]
        if not queryUser('Directory "' + beautified + '" already exists. Overwrite?'):
            halt()
        shutil.rmtree(output)
        os.mkdir(output)
    else:
        os.mkdir(output)
    
    command = '{} {} {} -o {} -n {} -g c'.format(args.hvcc_cmd, inpath, ' '.join('-p '+p for p in search_paths), output, basename)
    os.system(command)

    # Copy over template.cpp, Makefile, and daisy_boards.h
    shutil.copy(os.path.abspath('util/template.cpp'), os.path.abspath(output))
    shutil.copy(os.path.abspath('util/Makefile'), os.path.abspath(output))
    shutil.copy(os.path.abspath('util/daisy_boards.h'), os.path.abspath(output))

    # Copy over vscode files
    vscode_dir = os.path.join(os.path.abspath(output), '.vscode')
    os.mkdir(vscode_dir)
    for file in os.listdir('util/vscode'):
        shutil.copy(os.path.abspath(os.path.join('util/vscode',file)), vscode_dir)

    # Sort out linkers and copy if necessary
    global linker
    linker_var = 'LDSCRIPT = '
    linker_file = None
    if rom_type == 'double_size':
        linker = linker_var + 'qspi_linker_sdram.lds' if ram_type == 'size' else linker_var + 'qspi_linker.lds'
        linker_file = 'util/qspi_linker_sdram.lds' if ram_type == 'size' else 'util/qspi_linker.lds'
    elif rom_type == 'size':
        linker = linker_var + 'sram_linker_sdram.lds' if ram_type == 'size' else linker_var + 'sram_linker.lds'
        linker_file = 'util/sram_linker_sdram.lds' if ram_type == 'size' else 'util/sram_linker.lds'
    elif ram_type == 'size':
        linker = linker_var + 'default_linker_sdram.lds'
        linker_file = 'util/default_linker_sdram.lds'

    if linker_file is not None:
        shutil.copy(os.path.abspath(linker_file), os.path.abspath(output))

    # Get name of linker and copy to project
    # WARNING -- this is a simple search, make sure nothing else has the name 'bootloader' in it
    global bootloader
    if rom_type in ('size', 'double_size'):
        for file in os.listdir(os.path.abspath('util')):
            if 'bootloader' in file:
                bootloader = 'BOOTLOADER = ' + file + '\nC_DEFS += -DBOOT_VOLATILE'
                shutil.copy(os.path.abspath(os.path.join('util', file)), os.path.abspath(output))
                break
    else:
        bootloader = ''

    #template filename
    global filename
    filename = basename + '.cpp'

    #paths to files, and move template
    paths["Directory"] = os.path.abspath(output)
    paths["Template"] = os.path.abspath(output + '/' + filename)
    os.rename(os.path.abspath(output + '/template.cpp'), paths["Template"])
       
    paths["Makefile"] = os.path.abspath(output + '/Makefile')        
    paths["Board"] = os.path.abspath(output + '/daisy_boards.h')

    paths["Properties"] = os.path.abspath(os.path.join(output, '.vscode/c_cpp_properties.json'))
    paths["Launch"] = os.path.abspath(os.path.join(output, '.vscode/launch.json'))
    paths["Tasks"] = os.path.abspath(os.path.join(output, '.vscode/tasks.json'))

    for i in replaceFunctions:
        replaceFunctions[i]()
    
if __name__ == "__main__":
    # Forcing python 2 compliance
    if sys.version_info.major != 2:
        print("\033[0;31mpd2dsy requires python 2 (refer to the README for a setup guide)\033[0m")
        sys.exit(1)
    main()
