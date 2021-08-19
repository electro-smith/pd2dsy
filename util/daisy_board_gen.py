import argparse
import os
import json

#############################################################
### Python script to turn JSON into board support files ###
# Author: beserge #
# Largely adapted from grrrwaaa's oopsy #
#############################################################

component_defs = '{\
	Switch: {\
		typename: "daisy::Switch",\
		pin: "a",\
		type: "daisy::Switch::TYPE_MOMENTARY",\
		polarity: "daisy::Switch::POLARITY_INVERTED",\
		pull: "daisy::Switch::PULL_UP",\
		process: "${name}.Debounce();",\
		updaterate: "${name}.SetUpdateRate(seed.AudioCallbackRate());",\
		mapping: [\
			{ name: "${name}", get: "(hardware.${name}.Pressed()?1.f:0.f)", range: [0, 1] },\
			{\
				name: "${name}_rise",\
				get: "(hardware.${name}.RisingEdge()?1.f:0.f)",\
				range: [0, 1]\
			},\
			{\
				name: "${name}_fall",\
				get: "(hardware.${name}.FallingEdge()?1.f:0.f)",\
				range: [0, 1]\
			},\
			{\
				name: "${name}_seconds",\
				get: "(hardware.${name}.TimeHeldMs()*0.001f)",\
				range: null\
			}\
	  	]\
	},\
	Switch3: {\
		typename: "daisy::Switch3",\
		pin: "a,b",\
		mapping: [\
			{ name: "${name}", get: "(hardware.${name}.Read()*0.5f+0.5f)", range: [0, 2] }\
		]\
	},\
	Encoder: {\
		typename: "daisy::Encoder",\
		pin: "a,b,click",\
		process: "${name}.Debounce();",\
		updaterate: "${name}.SetUpdateRate(seed.AudioCallbackRate());",\
		mapping: [\
			{\
				name: "${name}",\
				get: "(hardware.${name}.Increment()*0.5f+0.5f)",\
				range: [-1, 1]\
			},\
			{\
				name: "${name}_press",\
				get: "(hardware.${name}.Pressed()?1.f:0.f)",\
				range: [0, 1]\
			},\
			{\
				name: "${name}_rise",\
				get: "(hardware.${name}.RisingEdge()?1.f:0.f)",\
				range: [0, 1]\
			},\
			{\
				name: "${name}_fall",\
				get: "(hardware.${name}.FallingEdge()?1.f:0.f)",\
				range: [0, 1]\
			},\
			{\
				name: "${name}_seconds",\
				get: "(hardware.${name}.TimeHeldMs()*0.001f)",\
				range: null\
			}\
		]\
	},\
	GateIn: {\
		typename: "daisy::GateIn",\
		pin: "a",\
		mapping: [\
			{ name: "${name}", get: "(hardware.${name}.State()?1.f:0.f)", range: [0, 1] },\
			{ name: "${name}_trig", get: "(hardware.${name}.Trig()?1.f:0.f)", range: [0, 1] }\
		]\
	},\
	AnalogControl: {\
		typename: "daisy::AnalogControl",\
		pin: "a",\
		flip: false,\
		invert: false,\
		slew: "1.0/seed.AudioCallbackRate()",\
		process: "${name}.Process();",\
		updaterate: "${name}.SetSampleRate(seed.AudioCallbackRate());",\
		mapping: [{ name: "${name}", get: "(hardware.${name}.Value())", range: [0, 1] }]\
	},\
	Led: {\
		typename: "daisy::Led",\
		pin: "a",\
		invert: true,\
		postprocess: "${name}.Update();",\
		mapping: [{ name: "${name}", set: "hardware.${name}.Set($<name>);" }]\
	},\
	RgbLed: {\
		typename: "daisy::RgbLed",\
		pin: "r,g,b",\
		invert: true,\
		postprocess: "${name}.Update();",\
		mapping: [\
			{ name: "${name}_red", set: "hardware.${name}.SetRed($<name>);" },\
			{ name: "${name}_green", set: "hardware.${name}.SetGreen($<name>);" },\
			{ name: "${name}_blue", set: "hardware.${name}.SetBlue($<name>);" },\
			{ name: "${name}", set: "hardware.${name}.Set(clamp(-$<name>, 0.f, 1.f), 0.f, clamp($<name>, 0.f, 1.f));" },\
			{ name: "${name}_white", set: "hardware.${name}.Set($<name>,$<name>,$<name>);" }\
		]\
	},\
	GateOut: {\
		typename: "daisy::dsy_gpio",\
		pin: "a",\
		mode: "DSY_GPIO_MODE_OUTPUT_PP",\
		pull: "DSY_GPIO_NOPULL",\
		mapping: [\
			{ name: "${name}", set: "dsy_gpio_write(&hardware.${name}, $<name> } 0.f);" }\
		]\
	},\
	CVOuts: {\
		typename: "daisy::DacHandle::Config",\
		pin: "",\
		bitdepth: "daisy::DacHandle::BitDepth::BITS_12",\
		buff_state: "daisy::DacHandle::BufferState::ENABLED",\
		mode: "daisy::DacHandle::Mode::POLLING",\
		channel: "daisy::DacHandle::Channel::BOTH",\
		mapping: [\
			{\
				name: "${name}1",\
				set: "hardware.${name}.WriteValue(daisy::DacHandle::Channel::ONE, $<name> * 4095)",\
				where: "main"\
			},\
			{\
				name: "${name}2",\
				set: "hardware.${name}.WriteValue(daisy::DacHandle::Channel::TWO, $<name> * 4095)",\
				where: "main"\
			}\
		]\
	}\
}'


def generate_target_struct(target):
    # flesh out target components:
    components = json.loads(target)['components']

    # alphabetize by component name
    components = sorted(components.items(), key=lambda x: x[1]['component'])
# 	  .map((pair) => {
# 		let [name, def] = pair;
# 		def.name = name;
# 		let component = component_defs[def.component];
# 		if (component) {
# 		  # copy component defaults into the def
# 		  # TODO this should be recursive for object structures...
# 		  for (let k of Object.keys(component)) {
# 			if (def[k] == undefined) def[k] = component[k];
# 		  }
# 		} else {
# 		  throw new Error("undefined component kind: " + def.component);
# 		}
# 		return def;
# 	});
# 	target.components = components;
# 	target.name = target.name || "custom"

# 	if (target.display) {
# 		# apply defaults:
# 		target.display = Object.assign({
# 			driver: "daisy::SSD130x4WireSpi128x64Driver",
# 			config: [],
# 			dim: [128, 64]
# 		}, target.display)
# 		target.defines.OOPSY_TARGET_HAS_OLED = 1
# 		target.defines.OOPSY_OLED_DISPLAY_WIDTH = target.display.dim[0]
# 		target.defines.OOPSY_OLED_DISPLAY_HEIGHT = target.display.dim[1]
# 	}
  
# 	return `
# #include "daisy_seed.h"
# ${target.display ? `#include "dev/oled_ssd130x.h"` : ""}
# // name: ${target.name}
# struct Daisy {
  
# 	void Init(bool boost = false) {
# 		seed.Configure();
# 		seed.Init(boost);
# 		${components.filter((e) => e.init)
# 		.map((e) => `
# 		${template(e.init, e)}`
# 		).join("")}
# 		${components.filter((e) => e.typename == "daisy::Switch")
# 		.map((e, i) => `
# 		${e.name}.Init(seed.GetPin(${e.pin}), seed.AudioCallbackRate(), ${e.type}, ${e.polarity}, ${e.pull});`
# 		).join("")}
# 		${components.filter((e) => e.typename == "daisy::Switch3").map((e, i) => `
# 		${e.name}.Init(seed.GetPin(${e.pin.a}), seed.GetPin(${e.pin.b}));`
# 		).join("")}
# 		${components.filter((e) => e.typename == "daisy::GateIn").map((e, i) => `
# 		dsy_gpio_pin ${e.name}_pin = seed.GetPin(${e.pin});
# 		${e.name}.Init(&${e.name}_pin);`
# 		).join("")}
# 		${components.filter((e) => e.typename == "daisy::Encoder").map((e, i) => `
# 		${e.name}.Init(seed.GetPin(${e.pin.a}), seed.GetPin(${e.pin.b}), seed.GetPin(${e.pin.click}), seed.AudioCallbackRate());`
# 		).join("")}
# 		static const int ANALOG_COUNT = ${
# 		components.filter((e) => e.typename == "daisy::AnalogControl").length};
# 		daisy::AdcChannelConfig cfg[ANALOG_COUNT];
# 		${components.filter((e) => e.typename == "daisy::AnalogControl").map((e, i) => `
# 		cfg[${i}].InitSingle(seed.GetPin(${e.pin}));`).join("")}
# 		seed.adc.Init(cfg, ANALOG_COUNT);
# 		${components.filter((e) => e.typename == "daisy::AnalogControl").map((e, i) => `
# 		${e.name}.Init(seed.adc.GetPtr(${i}), seed.AudioCallbackRate(), ${e.flip}, ${e.invert});`).join("")}
# 		${components.filter((e) => e.typename == "daisy::Led").map((e, i) => `
# 		${e.name}.Init(seed.GetPin(${e.pin}), ${e.invert});
# 		${e.name}.Set(0.0f);`).join("")}	
# 	  	${components.filter((e) => e.typename == "daisy::RgbLed").map((e, i) => `
# 		${e.name}.Init(seed.GetPin(${e.pin.r}), seed.GetPin(${e.pin.g}), seed.GetPin(${e.pin.b}), ${e.invert});
# 		${e.name}.Set(0.0f, 0.0f, 0.0f);`).join("")}
# 		${components.filter((e) => e.typename == "daisy::dsy_gpio").map((e, i) => `
# 		${e.name}.pin  = seed.GetPin(${e.pin});
# 		${e.name}.mode = ${e.mode};
# 		${e.name}.pull = ${e.pull};
# 		dsy_gpio_init(&${e.name});`).join("")}
# 		${components.filter((e) => e.typename == "daisy::DacHandle::Config").map((e, i) => `
# 		${e.name}.bitdepth   = ${e.bitdepth};
# 		${e.name}.buff_state = ${e.buff_state};
# 		${e.name}.mode       = ${e.mode};
# 		${e.name}.chn        = ${e.channel};
# 		seed.dac.Init(${e.name});
# 		seed.dac.WriteValue(${e.channel}, 0);`).join("")}
# 		${target.display ? `
# 		daisy::OledDisplay<${target.display.driver}>::Config display_config;
# 		display_config.driver_config.transport_config.Defaults(); ${(target.display.config || []).map(e=>`
# 		${e}`).join("")}
# 		display.Init(display_config);`:`// no display`}
# 	}
  
# 	void ProcessAllControls() {
# 		${components.filter((e) => e.process).map((e) => `
# 		${template(e.process, e)}`).join("")}
# 		${components.filter((e) => e.meta).map((e) => e.meta.map(m=>`
# 		${template(m, e)}`).join("")).join("")}
# 	}
	
# 	void PostProcess() {
# 		${components.filter((e) => e.postprocess).map((e) => `
# 		${template(e.postprocess, e)}`).join("")}
# 	}
	
# 	void Display() {
# 		${components.filter((e) => e.display).map((e) => `
# 		${template(e.display, e)}`).join("")}
# 	}
  
# 	void SetAudioSampleRate(daisy::SaiHandle::Config::SampleRate samplerate) {
# 		seed.SetAudioSampleRate(samplerate);
# 		SetHidUpdateRates();
# 	}
# 	void SetAudioBlockSize(size_t size) {
# 		seed.SetAudioBlockSize(size);
# 		SetHidUpdateRates();
# 	}
# 	void SetHidUpdateRates() {
# 		${components.filter((e) => e.updaterate).map((e) => `
# 		${template(e.updaterate, e)}`).join("")}
# 	}
  
# 	daisy::DaisySeed seed;
# 	${components.map((e) => `
# 	${e.typename} ${e.name};`).join("")}
# 	${target.display ? `daisy::OledDisplay<${target.display.driver}> display;`:`// no display`}
# 	int menu_click = 0, menu_hold = 0, menu_rotate = 0;
# };`;
# }

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Utility for generating board support files from JSON.')
    parser.add_argument('json_input', help='Path to json file.')
    parser.add_argument('-o', '--output', help='Path to output to. Defaults to board_support.h', default='board_support.h')

    args = parser.parse_args()
    inpath = os.path.abspath(args.json_input)
    outpath = os.path.abspath(args.output)

    print('Generating Board File...')
    infile = open(inpath, 'r').read()
    generate_target_struct(infile)