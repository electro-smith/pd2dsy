# pd2dsy

Utility for converting Pure Data (Vanilla) patches to Daisy projects.

## Installation/Setup

1. Test that you have python installed, and that its the proper version. It should be >= 3.8. Test this by running `python --version` on the command line. You may need to use the `python3` command instead for this and following commands.
2. Clone the repo: `git clone https://github.com/electro-smith/pd2dsy`
3. Run the `install.sh` script located in the root directory. This should install required python modules, update your libdaisy, and build it for you. It also creates a _virtual environment_, which is a self-contained python environment for specific projects. 
4. In order to actually use the python modules you just installed, you'll need to be running from the virtual environment. On Mac and Linux, you can do this by running `./pd_env/bin/activate` (or `source ./pd_env/bin/activate` if you get permission errors). On Windows, it'll be `./pd_env/Scripts/activate.sh`.
5. Install arm-none-eabi-gcc toolchain, make, and dfu-util. There are [OS specific instructions in the Daisy Wiki](https://github.com/electro-smith/DaisyWiki/wiki).

You should now be able to run pd2dsy.py without issue.

## Usage

After you've made your patch in puredata, you can turn it into cpp by running the command:
```python pd2dsy.py --board <BOARD> <FILE>.pd```

\<BOARD\> should be replaced with the board you're using (pod, patch, patch_init, field, petal).
\<FILE\> is the filename of your pd patch.

Your patch will be built and uploaded automatically, assuming you have a Daisy in DFU mode plugged into USB. If you'd like to build and upload manually, you can navigate to the folder that it created and run `make`, then `make program-dfu`.

**For now, the script leaves the path to libdaisy as `../libdaisy`, which works if the generated folder is placed within the root directory.
Otherwise, the Makefile should be edited (or the `--libdaisy-depth` option should be used) to point to a valid libdaisy repository.**

## Optional features

### -c, --custom-json

If you've designed your own prototype or board based on the Daisy platform, you can specify the I/O in a custom JSON file. Details for how this works can be found in the tool that actually performs this generation, [json2daisy](https://github.com/electro-smith/json2daisy).

### --ram

You can specify whether you'd like to optimize your project's RAM usage for `speed` or `size`. The Daisy's internal SRAM has a fast access time, but it can be quite limited at 512kB (or even less if you're using the bootloader!). The external SDRAM (note the _D_), while it can be slower to access, affords a hefty 64MB of space. Currently, only the heap is placed in SDRAM if `size` is selected (meaning all dynamic allocations happen in SDRAM), but that's the best use-case for it anyway, since the largest program you could squeeze onto the Daisy would only be around 512kB.

The appropriate linker is automatically supplied and chosen in the makefile if you select `size`, so all you need to do is rebuild the project.

### --rom

You can specify whether you'd like to optimize your project's ROM usage for `speed` or `size`. The Daisy's internal flash allows programs to start very quickly, and offers very slightly better performance. However, if your program is too hefty to fit in the Daisy's 128kB of internal flash, then you'll need to execute the program from SRAM using the Daisy bootloader (for up to 512kB). Selecting `size` will configure your project for the bootloader, and all you need to do is upload the bootloader, build your program, then upload the resulting binary to the bootloader. If you need even more size, you can execute your programs directly from the 8MB QSPI flash chip with `double_size`, though performance may take a hit in certain scenarios.

<!-- [Detailed steps are provided here](wiki/RunningLargePrograms.md), but note that the linker script selection will be handled for you. -->

Both `--ram` and `--rom` default to `speed`.

### -d, --directory

The parent directory of your project can be specified. This is convenient if you'd like to build from somewhere other than your intended project directory, for example:

~~~bash
python pd2dsy.py -d build path/to/source.pd
~~~

This would place your project in the `build` subdirectory. If it doesn't exist, then pd2dsy will ask if you'd like to create it.

### --libdaisy-depth

pd2dsy generates a number of helpful files that need to know where your libDaisy folder is located. If you don't want to change them all manually, then you can specify how far away the libDaisy folder is from your project folder:

~~~bash
python pd2dsy.py --libdaisy-depth 2 path/to/source.pd
~~~

This will tell all the project files to look two directories above the current one to find libDaisy (as in `../../libDaisy`). This does require that libDaisy exists in _some_ parent directory of your project, but you can of course specify it manually if you prefer.

# Interacting with the Daisy I/O

Each board has a selection of physical I/O that can interact with your PD patch. Most components have an _alias_, which allows you to refer to the same input/output by different names if you have a preference. All names and aliases are _case insensitive_, so you can style them however you like (e.g. `GateIn`).

Components that act as an input (like a Switch, for example) are accessible with Pd's `receive` object, and require the `@hv_param` attribute in order to be recognized as an external input. If your Switch is named `sw`, then the Pd object would look like `r sw @hv_param`. Outputs, like an LED, use the `send` object (i.e. `s led @hv_param`). The examples make this usage pretty clear.

Some components have _variants_, which allow you to interact with them in multiple ways. For example, you can receive a bang from a `Gate In` instead of a float if you add `_trig` to the end of the gate's name (or any of its aliases). So, if a `Gate In`'s name is `gatein1`, you would use `gatein1_trig`.

Here's what each component expects for its default behavior and variants:

| Type | _variant | Behavior |
| --- | --- | --- |
| **Inputs** | --- | --- |
| Voltage Input | --- | Returns a floating point representation of the voltage at its input. The typical range is 0-5 V, which is represented as 0-1. |
| Bipolar Voltage Input | --- | Similar to a regular voltage input, but can represent negative voltages. |
| Switch | --- | Returns a bang on the signal's rising edge (i.e. when the switch is actuated). |
| Switch | _press | Returns a float representing the current state (1 = pressed, 0 = not pressed) |
| Switch | _fall | Returns a bang on the signal's falling edge (i.e. when the switch is released). |
| Switch | _seconds | Returns a float representing the number of seconds the switch has been held down. |
| SPDT Switch | --- | Returns a float representing the current state, either 0 or 1. |
| Encoder | --- | Returns a 1 if turned one direction, -1 if turned in the other, and 0 otherwise. |
| Encoder | \_rise | Returns a bang when the encoder is pressed. The special alias _EncSwitch_ is always bound to this. |
| Encoder | _press | Same as switch _press. |
| Encoder | _fall | Same as switch _fall. |
| Encoder | _seconds | Same as switch _seconds. |
| Gate In | --- | Returns a float representing the current gate voltage, where a _high_ voltage is 1 and a _low_ voltage is 0. |
| Gate In | _trig | Returns a bang on the rising edge of the gate signal. |
| **Outputs** | --- | --- |
| CV Out | --- | Expects a floating point value from 0-1, usually converted to 0-5V. |
| Gate Out | --- | Expects a floating point value from 0-1. 0 sets the output low, and 1 sets it high. |
| LED | --- | Expects a floating point value from 0-1. The brightness is PWM modulated to match the input. |
| RGB LED | --- | Expects a floating point value from 0-1. The default behavior sets all three colors to the same brightness. |
| RGB LED | _white | Same as default. |
| RGB LED | _red | Expects a floating point value from 0-1. Sets the brightness of the red LED only. |
| RGB LED | _green | Expects a floating point value from 0-1. Sets the brightness of the green LED only. |
| RGB LED | _blue | Expects a floating point value from 0-1. Sets the brightness of the blue LED only. |

Here's how the newly added sensors are addressed:

| Type | _variant | Behavior |
| --- | --- | --- |
| **Inputs** | --- | --- |
| BME280 | --- | Returns the temperature in degrees C. |
| BME280 | _temp | Behaves the same as the default option. |
| BME280 | _hum | Returns the humidity in relative percentage. |
| BME280 | _press | Returns the pressure in pascals (1 atm ~= 100 kPa) |
| BME280 | _alt | Returns the estimated altitude in meters |
| BMP390 | --- | Returns the temperature in degrees C. |
| BMP390 | _temp | Behaves the same as the default option. |
| BMP390 | _press | Returns the pressure in pascals (1 atm ~= 100 kPa) |
| BMP390 | _alt | Returns the estimated altitude in meters |
| Hall Sensor | --- | Returns the current state of the sensor (0 if no field present, otherwise 1). |
| Hall Sensor | _count | Returns the number of times the hall sensor has been activated. |
| TLV93D | --- | Returns the magnitude of the field's force vector in uT (i.e. the amount of field). |
| TLV93D | _x, _y, _z | Returns the field's strength in the given axis in uT. |
| TLV93D | _amount | Behaves the same as the default option. |
| TLV93D | _azimuth | Returns the field's azimuth for spherical coordinates. |
| TLV93D | _polar | Returns the field's 3D inclination for spherical coordinates. |
| MPR121 | --- | Returns whether channel 0 is touched according to the threshold. |
| MPR121 | _ch0 ... _ch11 | Returns a 1 if the given channel is touched according to the threshold, otherwise 0. |
| MPR121 | _ch0_raw ... _ch11_raw | Returns the raw sensor data for the given channel as a 10-bit unsigned integer. |
| APDS9960 | --- | Returns the current read gesture (1-4) if detected, otherwise 0. |
| APDS9960 | _gest | Behaves the same as the default option. |
| APDS9960 | _prox | Returns the detected proximity in undefined units (meant for relative distance detection). |
| APDS9960 | _red, _green, _blue, _clear | Returns the detected brightness of the given color as a 16-bit unsigned integer. |
| VL53L1X | --- | Returns the distance measurement in mm. |
| Neo Trellis | --- | Sends a bang when the first button (index 0) is pressed. |
| Neo Trellis | _0 ... _15 | Sends a bang when the given button is pressed. |
| Neo Trellis | \_0\_falling ... \_15\_falling | Sends a bang when the given button is released. |
| Neo Trellis | \_0\_state ... \_15\_state | Returns the current state of the given button (1 = pressed, 0 = released). |
| BNO055 | --- | Returns the X component of the accelerometer in m/s^2. |
| BNO055 | \_accel\_x, \_accel\_y, \_accel\_z | Returns the given axis from the accelerometer in m/s^2. |
| BNO055 | \_magnet\_x, \_magnet\_y, \_magnet\_z | Returns the given axis from the magnetometer in uT. |
| BNO055 | \_gyro\_x, \_gyro\_y, \_gyro\_z | Returns the given axis from the gyroscope in dps (degrees per second). |
| BNO055 | \_euler\_x, \_euler\_y, \_euler\_z | Returns the rotation along the given axis in degrees. |
| BNO055 | \_linear\_accel\_x, \_linear\_accel\_y, \_linear\_accel\_z | Returns the linear acceleration in the given axis in m/s^2. |
| BNO055 | \_grav\_x, \_grav\_y, \_grav\_z | Returns the acceleration due to gravity along the given axis in m/s^2. |
| BNO055 | \_quat\_w, \_quat\_x, \_quat\_y, \_quat\_z | Returns the orientation represented as a quaternion. |
| **Outputs** | --- |
| Stepper Motor | --- | Expects a floating point value of any arbitrary size, representing the number of steps to rotate. The sign of the number determines direction. |
| Stepper Motor | _release | Triggers the stepper motor to relax its fields when a positive value is received, allowing the motor to spin freely. |
| DC Motor | --- | Expects a floating point value from -1 to 1. The magnitude controls the speed, the sign controls direction, and a value of zero stops the motor. |
| Neo Trellis LEDs | _0 ... _15 | Expects an integer from 0-255 to control the led brightness of the corresponding pad. |

# Daisy Board I/O

## patch

| Name | Aliases | Type | Variants |
| --- | --- | --- | --- |
| knob1 | knob, ctrl, ctrl1 | Voltage Input | --- |
| knob2 | ctrl2 | Voltage Input | --- |
| knob3 | ctrl3 | Voltage Input | --- |
| knob4 | ctrl4 | Voltage Input | --- |
| encoder | --- | Encoder | encoder_press, encoder_rise, encoder_fall, encoder_seconds |
| gateout | --- | Gate Out | --- |
| cvout1 | cvout | CV Out | --- |
| cvout2 | --- | CV Out | --- |
| gatein1 | gate, gate1 | Gate In | gatein1_trig |
| gatein2 | gate2 | Gate In | gatein2_trig |

## patch_init

| Name | Aliases | Type | Variants |
| --- | --- | --- | --- |
| cv_1 | knob, knob1, ctrl, ctrl1 | Voltage Input | --- |
| cv_2 | knob2, ctrl2 | Voltage Input | --- |
| cv_3 | knob3, ctrl3 | Voltage Input | --- |
| cv_4 | knob4, ctrl4 | Voltage Input | --- |
| cv_5 | knob5, ctrl5 | Voltage Input | --- |
| cv_6 | knob6, ctrl6 | Voltage Input | --- |
| cv_7 | knob7, ctrl7 | Voltage Input | --- |
| cv_8 | knob8, ctrl8 | Voltage Input | --- |
| adc_9 | --- | Voltage Input | --- |
| adc_10 | --- | Voltage Input | --- |
| adc_11 | --- | Voltage Input | --- |
| adc_12 | --- | Voltage Input | --- |
| gate_out_1 | gateout, gateout1 | Gate Out | --- |
| gate_out_2 | gateout2 | Gate Out | --- |
| cvout1 | cvout, cv_out_1 | CV Out | --- |
| cvout2 | cv_out_2 | CV Out | --- |
| gate_in_1 | gate, gate1 | Gate In | gate_in_1_trig |
| gate_in_2 | gate2 | Gate In | gate_in_2_trig |
| sw1 | switch, switch1, button | Switch | sw1_press, sw1_fall, sw1_seconds |
| sw2 | switch2, toggle | Switch | sw2_press, sw2_fall, sw2_seconds |

## petal

| Name | Aliases | Type | Variants |
| --- | --- | --- | --- |
| sw1 | switch, switch1 | Switch | sw1_press, sw1_fall, sw1_seconds |
| sw2 | switch2 | Switch | sw2_press, sw2_fall, sw2_seconds |
| sw3 | switch3 | Switch | sw3_press, sw3_fall, sw3_seconds |
| sw4 | switch4 | Switch | sw4_press, sw4_fall, sw4_seconds |
| sw5 | switch5 | Switch | sw5_press, sw5_fall, sw5_seconds |
| sw6 | switch6 | Switch | sw6_press, sw6_fall, sw6_seconds |
| sw7 | switch7 | Switch | sw7_press, sw7_fall, sw7_seconds |
| encoder | --- | Encoder | encoder_press, encoder_rise, encoder_fall, encoder_seconds |
| knob1 | knob, ctrl, ctrl1 | Voltage Input | --- |
| knob2 | ctrl2 | Voltage Input | --- |
| knob3 | ctrl3 | Voltage Input | --- |
| knob4 | ctrl4 | Voltage Input | --- |
| knob5 | ctrl5 | Voltage Input | --- |
| knob6 | ctrl6 | Voltage Input | --- |
| expression | --- | Voltage Input | --- |
| led_ring_1 ... led_ring_8 | --- | RGB LED | led_ring_1_red, led_ring_1_green, led_ring_1_blue, led_ring_1_white |
| led_fs_1 | --- | LED | --- |
| led_fs_2 | --- | LED | --- |
| led_fs_3 | --- | LED | --- |
| led_fs_4 | --- | LED | --- |

## pod

| Name | Aliases | Type | Variants |
| --- | --- | --- | --- |
| sw1 | switch, button, switch1, button1 | Switch | sw1_press, sw1_fall, sw1_seconds |
| sw2 | switch2, button2 | Switch | sw2_press, sw2_fall, sw2_seconds |
| knob1 | knob, ctrl, ctrl1 | Voltage Input | --- |
| knob2 | ctrl2 | Voltage Input | --- |
| encoder | --- | Encoder | encoder_press, encoder_rise, encoder_fall, encoder_seconds |
| led1 | led | RGB LED | led1_red, led1_green, led1_blue, led1_white |
| led2 | --- | RGB LED | led2_red, led2_green, led2_blue, led2_white |
| gatein | gate, gate1 | Gate In | gatein_trig |

## field

| Name | Aliases | Type | Variants |
| --- | --- | --- | --- |
| sw1 | switch, button, switch1, button1 | Switch | sw1_press, sw1_fall, sw1_seconds |
| sw2 | switch2, button2 | Switch | sw2_press, sw2_fall, sw2_seconds |
| cv1 | --- | Bipolar Voltage Input | --- |
| cv2 | --- | Bipolar Voltage Input | --- |
| cv3 | --- | Bipolar Voltage Input | --- |
| cv4 | --- | Bipolar Voltage Input | --- |
| knob1 | knob, ctrl, ctrl1 | Voltage Input | --- |
| knob2 | ctrl2 | Voltage Input | --- |
| knob3 ... knob8 | --- | Voltage Input | --- |
| cvout1 | cvout | CV Out | --- |
| cvout2 | --- | CV Out | --- |
| gatein | --- | Gate In | gatein_trig |
| gateout | --- | Gate Out | --- |
| pada1 ... pada8 | --- | Switch | pada1_press, pada1_fall |
| padb1 ... padb8 | --- | Switch | padb1_press, padb1_fall |
| led_key_a1 ... led_key_a8 | --- | LED | --- |
| led_key_b1 ... led_key_b8 | --- | LED | --- |
| led_knob_1 ... led_knob_8 | --- | LED | --- |

-------------------

## How It Works

There are a few pieces to this:

* HVCC - heavy compiler, a generator for creating portable source code based on Pure Data vanilla patches
* json2daisy - a utility for converting json board descriptions to libDaisy-based C++ headers
* Daisy Interface handling - The controls and features available on the daisy platform need to be accessible from a pure data patch (buttons, knobs, leds, etc.)
* compilation - a distributable copy of the arm toolchain and scripts for building the code without installing extra tools.

## Next steps

1. Double check licensing requirements, etc. and bundle a pre-compiled binaries for the arm toolchain into the project for built-in compilation
2. Add a GUI? (Web app / built in tester, similar to OWL platform?)
