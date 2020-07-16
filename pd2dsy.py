# !/usr/bin/env python
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
import argparse
import subprocess
import shutil
import fileinput
#import hvcc.hvcc as hv

def searchReplace(file, find, replace):
    f = open(file,'r')
    filedata = f.read()
    f.close()

    newdata = filedata.replace(find, replace)

    f = open(file,'w')
    f.write(newdata)
    f.close()

def main():
    parser = argparse.ArgumentParser(description='Utility for converting Puredate files to Daisy projects, uses HVCC inside')
    parser.add_argument('pd_input', help='path to puredata file.')
    parser.add_argument('-b',  '--board', help='hardware platform for generated output.', default='seed')
    args = parser.parse_args()
    inpath = os.path.abspath(args.pd_input)
    basename = os.path.basename(inpath).split('.')[0]
    board = args.board
    print(("Converting {} for {} platform".format(basename, board)))

    # run heavy
    command = 'python hvcc/hvcc.py {} -o {} -n {} -g c'.format(inpath, basename, basename)
    os.system(command)

    # Copy over template.cpp, Makefile, and daisy_boards.h
    shutil.copy(os.path.abspath('util/template.cpp'), os.path.abspath(basename + '/c/'))
    shutil.copy(os.path.abspath('util/Makefile'), os.path.abspath(basename + '/c/'))
    shutil.copy(os.path.abspath('util/daisy_boards.h'), os.path.abspath(basename + '/c/'))

    # Modify template
    filename = basename + '.cpp'
    templatePath = os.path.abspath(basename + '/c/' + filename)
    os.rename(os.path.abspath(basename + '/c/template.cpp'), templatePath)

    # this is a lazy way to do this for now
    searchReplace(templatePath, '// GENERATE INCLUDES START', '#include "Heavy_' + basename + '.hpp"')
    searchReplace(templatePath, '// GENERATE GLOBALS START', 'Heavy_' + basename + ' hv(SAMPLE_RATE);')

    adc = ''
    if (board == 'seed'):
        searchReplace(templatePath, '// GENERATE PREINIT START', 'hardware.Configure();')
    else:
        adc = 'hardware.AdcStart();'
        
    searchReplace(templatePath, '// ADC', adc)
    
    # Modify Makefile
    makePath = os.path.abspath(basename + '/c/' + 'Makefile')
    searchReplace(makePath, '# TARGET LOCATION #', 'TARGET = ' + basename)
    cppSources = 'CPP_SOURCES = ' + filename + ' \\\nHeavy_' + basename + '.cpp \\'

    searchReplace(makePath, '# CPP LOCATION #', cppSources)
    
    # Modify Boards
    boardPath = os.path.abspath(basename + '/c/' + 'daisy_boards.h')
    searchReplace(boardPath, '// GENERATE BOARD', '#define DSY_BOARD Daisy' + board.capitalize())
    
if __name__ == "__main__":
    main()
