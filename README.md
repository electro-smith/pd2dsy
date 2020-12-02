# pd2dsy

Utility for converting Pure Data (Vanilla) patches to ready-to-compile Daisy projects.

## Pd Patches
Board controls can be brought into PD from receive objects.
For example, if we wanted to receive a bang when we pressed the button 1 on the pod we would use this object:
```r Button1 @hv_param```
Note: You can also set some defaults. ```r Knob1 @hv_param .5 0 1``` Defaults to .5, and ranges from 0 to 1.

Here's all of the control names for each board.

### Pod

| Name | Type |
| --- | --- |
| Knob1 | Float |
| Knob2 | Float |
| Button1 | Bang |
| Button2 | Bang |
| Encoder | Float |
| EncSwitch | Bang | 

### Patch

| Name | Type |
| --- | --- |
| Ctrl1 | Float |
| Ctrl2 | Float |
| Ctrl3 | Float |
| Ctrl4 | Float |
| Gate1 | Bang |
| Gate2 | Bang |
| Encoder | Float |
| EncSwitch | Bang | 

### Petal

| Name | Type |
| ---- | ---- |
| Encoder | Float |
| EncSwitch | Bang |
| Knob1 | Float |
| Knob2 | Float |
| Knob3 | Float |
| Knob4 | Float |
| Knob5 | Float |
| Knob6 | Float |
| Switch1 | Bang |
| Switch2 | Bang |
| Switch3 | Bang |
| Switch4 | Bang |
| Switch5 | Bang |
| Switch6 | Bang |
| Switch7 | Bang |

## Installation/Setup

1. Clone the repo: `git clone https://github.com/electro-smith/pd2dsy`
2. Navigate inside the repo, and initialize the submodules to populate a few resources for the utility: `git submodule update --init`
3. Test that you have python installed, and that its the proper version. It should be python 2, not python 3. Test this by running: `python --version`
4. Install the necessary python packages for hvcc: `python -m pip install -r hvcc/requirements.txt`
5. Install arm-none-eabi-gcc toolchain, make, and dfu-util. There are [OS specific instructions in the Daisy Wiki](https://github.com/electro-smith/DaisyWiki/wiki).
6. Compile the libdaisy library for use in the libdaisy code generator by navigating into the libdaisy folder and running: `make`

You should now be able to run pd2dsy.py without issue.

## Usage

After you've made your patch in puredata, you can turn it into cpp by running the command:
```python pd2dsy.py --board <BOARD> <FILE>.pd```
<BOARD> should be replaced with the board you're using (seed, pod, patch).
<FILE> is the filename of your pd patch.

cd into the directory the script creates. You can then run make, and make program-dfu to flash your board just like with daisysp.

**For now, the script generates leaves the path to libdaisy as `../../libdaisy`. Which works if the generated folder is placed within the examples folder.
Otherwise, the Makefile should be edited to point to a valid libdaisy repository.**

## How It Works

There are a few pieces to this:

* HVCC - heavy compiler, a generator for creating portable source code based on Pure Data vanilla patches
* Daisy Interface handling - The controls and features available on the daisy platform need to be accessible from a pure data patch (buttons, knobs, leds, etc.)
* libdaisy template-based code generation - a script for populating a functional daisy program with the hvcc generated code, and generating the initialization and control/feedback for PD parameters
* compilation - a distributable copy of the arm toolchain and scripts for building the code without installing extra tools.

## Next steps

0. Add support for Daisy Field.
1. Clean up board support to be metadata based, and a bit easier to add new boards
2. SDRAM support for larger buffers/delays.
3. Add support different types of controls (i.e. switches are currently only bangs, but should also be able to be toggles). 
4. Double check licensing requirements, etc. and bundle a pre-compiled binaries for the arm toolchain into the project for built-in compilation
5. Add a GUI? (Web app / built in tester, similar to OWL platform?)
