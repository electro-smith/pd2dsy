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

#sorry for all the global vars....
basename = ''
filename = ''
board = ''

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
    "Boards" : ""
}
    
replaceComments = {
    "Includes"  : "// GENERATE INCLUDES",
    "Globals"   :  "// GENERATE GLOBALS",
    "Preinit"   :  "// GENERATE PREINIT",
    "ADC"       :  "// GENERATE ADC",
    "Target"    :  "# GENERATE TARGET",
    "C"         :  "# GENERATE C",
    "CPP"       :  "# GENERATE CPP",
    "Board" :  "// GENERATE BOARD"
}
    
def generateIncludes():
    searchReplace(paths["Template"], replaceComments["Includes"], '#include "Heavy_' + basename + '.hpp"')

def generateGlobals():
    searchReplace(paths["Template"], replaceComments["Globals"], 'Heavy_' + basename + ' hv(SAMPLE_RATE);')

def generatePreinit():
    st = ''
    if (board == 'seed'):
        st = 'hardware->Configure();'
    searchReplace(paths["Template"], replaceComments["Preinit"], st)
        
def generateAdc():
    st = ''
    if (board != "seed"):
        st = 'hardware->StartAdc();'
    searchReplace(paths["Template"], replaceComments["ADC"], st)
  
def generateTarget():
    searchReplace(paths["Makefile"], replaceComments["Target"], 'TARGET = ' + basename)
    
def generateCpp():
    cppSources = 'CPP_SOURCES = ' + filename + ' \\\nHeavy_' + basename + '.cpp \\'
    searchReplace(paths["Makefile"], replaceComments["CPP"], cppSources)

def generateC():
    files = "C_SOURCES = "
    for file in os.listdir(paths["Directory"]):
        if file.endswith(".c"):
            files += file + " \\\n"
    searchReplace(paths["Makefile"], replaceComments["C"], files)
        
def generateBoard():
    #board type
    searchReplace(paths["Board"], replaceComments["Board"], '#define DSY_BOARD Daisy' + board.capitalize())    
    #remove comments around board init stuff
    searchReplace(paths["Board"], "/* " + board, "")    
    searchReplace(paths["Board"], board + " */", "")    
    
replaceFunctions = {
    "Includes" : generateIncludes,
    "Globals"  : generateGlobals,
    "Preinit"  : generatePreinit,
    "ADC"      : generateAdc,
    "Target"   : generateTarget,
    "CPP"      : generateCpp,
    "C"        : generateC,
    "Board"    : generateBoard
}

def main():
    parser = argparse.ArgumentParser(description='Utility for converting Puredate files to Daisy projects, uses HVCC inside')
    parser.add_argument('pd_input', help='path to puredata file.')
    parser.add_argument('-b',  '--board', help='hardware platform for generated output.', default='seed')

    args = parser.parse_args()
    inpath = os.path.abspath(args.pd_input)

    global basename
    basename = os.path.basename(inpath).split('.')[0]

    global board
    board = args.board
    print(("Converting {} for {} platform".format(basename, board)))

    # run heavy
    command = 'python hvcc/hvcc.py {} -o {} -n {} -g c'.format(inpath, basename, basename)
    os.system(command)

    # Copy over template.cpp, Makefile, and daisy_boards.h
    shutil.copy(os.path.abspath('util/template.cpp'), os.path.abspath(basename + '/c/'))
    shutil.copy(os.path.abspath('util/Makefile'), os.path.abspath(basename + '/c/'))
    shutil.copy(os.path.abspath('util/daisy_boards.h'), os.path.abspath(basename + '/c/'))

    #template filename
    global filename
    filename = basename + '.cpp'

    #paths to files, and move template
    paths["Directory"] = os.path.abspath(basename +'/c/')
    paths["Template"] = os.path.abspath(basename + '/c/' + filename)
    os.rename(os.path.abspath(basename + '/c/template.cpp'), paths["Template"])

    paths["Makefile"] = os.path.abspath(basename + '/c/' + 'Makefile')        
    paths["Board"] = os.path.abspath(basename + '/c/' + 'daisy_boards.h')

    for i in replaceFunctions:
        replaceFunctions[i]()
    
if __name__ == "__main__":
    main()
