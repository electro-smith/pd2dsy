import argparse
import os
import json

#############################################################
### Python script to turn JSON into board support files ###
# Author: beserge #
# Largely adapted from grrrwaaa's oopsy #
#############################################################

# TODO: add an argument to make this path configurable
json_defaults_file = "component_defaults.json"

def map_helper(pair):
	# load the default components
	inpath = os.path.abspath(json_defaults_file)
	infile = open(inpath, 'r').read()
	component_defaults = json.loads(infile)

	# split up the component we got
	name = pair[0]
	defn = pair[1]

	# the default if it exists
	component = component_defaults[defn['component']]
	if(component):
		# copy component defaults into the def
		# TODO this should be recursive for object structures..
		for k in component:
			if not k in defn: 
				defn[k] = component[k]
	else:
		raise Exception("undefined component kind: ", defn['component'])

	return component

def generate_target_struct(target):
	# flesh out target components:
	target = json.loads(target)
	components = target['components']

	# alphabetize by component name
	components = sorted(components.items(), key=lambda x: x[1]['component'])

	components = list(map(map_helper, components))
	target['components'] = components
	if not 'name' in target:
		target['name'] = 'custom'

	if 'display' in target:
		# apply defaults
		target['display'] = {
			'driver': "daisy::SSD130x4WireSpi128x64Driver",
			'config': [],
			'dim': [128, 64]
		}
		
		target['defines']['OOPSY_TARGET_HAS_OLED'] = 1
		target['defines']['OOPSY_OLED_DISPLAY_WIDTH'] = target['display']['dim'][0]
		target['defines']['OOPSY_OLED_DISPLAY_HEIGHT'] = target['display']['dim'][1]

# 	}

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