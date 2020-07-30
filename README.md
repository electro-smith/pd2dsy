# pd2dsy

Utility for converting Pure Data (Vanilla) patches to ready-to-compile Daisy projects.

## Pd Patches
Board controls can be brought into PD from receive objects.
For example, if we wanted to receive a bang when we pressed the button 1 on the pod we would use this object:
```r Button1 @hv_param```
Note: You can also set some defaults. ```r Knob1 @hv_param .5 0 1``` Defaults to .5, and ranges from 0 to 1.

Here's all of the control names for each board.

# Pod
| Name | Type |
| --- | --- |
| Knob1 | Float |
| Knob2 | Float |
| Button1 | Bang |
| Button2 | Bang |
| Encoder | Float |
| EncSwitch | Bang | 

# Patch
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

0. Add support for field and petal.
1. Double check licensing requirements, etc. and bundle a pre-compiled binaries for the arm toolchain into the project for built-in compilation
2. Add a GUI? (Web app / built in tester, similar to OWL platform?)
