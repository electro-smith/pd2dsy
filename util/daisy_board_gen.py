import argparse
import os
import json

#############################################################
### Python script to turn JSON into board support files ###
# Author: beserge #
# Largely adapted from grrrwaaa's oopsy #
#############################################################

# TODO: add an argument to make these paths configurable
json_defaults_file = "component_defaults.json"
template_path = 'template.h'

# helper for loading and processing the defaults, component list, etc
def map_load(pair):
	# load the default components
	inpath = os.path.abspath(json_defaults_file)
	infile = open(inpath, 'r').read()
	component_defaults = json.loads(infile)

	pair[1]['name'] = pair[0]

	# the default if it exists
	component = component_defaults[pair[1]['component']]
	if(component):
		# copy component defaults into the def
		# TODO this should be recursive for object structures..
		for k in component:
			if not k in pair[1]: 
				pair[1][k] = component[k]
	else:
		raise Exception("undefined component kind: ", pair[1]['component'])

	return pair[1]

def filter_match(set, key, match):
	return filter(lambda x: x.get(key, '') == match, set)

def filter_has(set, key):
	return filter(lambda x: x.get(key, '') != '', set)

# filter out the components we need, then map them onto the init for that part
def filter_map_init(set, key, match):
	filtered = filter_match(set, key, match)
	return "\n\t\t".join(map(lambda x: x['map_init'].format_map(x), filtered))

# filter out the components with a certain field, then fill in the template
def filter_map_template(set, name):
	filtered = filter_has(set, name)
	return "\n\t\t".join(map(lambda x: x[name].format_map(x), filtered))

def flatten_pin_dicts(comp):
	newcomp = {}
	for key,val in comp.items():
		if (isinstance(val, dict) and key == 'pin'):
			for subkey, subval in val.items():
				newcomp[key + '_' + subkey] = subval
		else:
			newcomp[key] = val

	return newcomp

def bools_to_lower_str(comp):
	new_comp = {}
	for key, val in comp.items():
		new_comp[key] = str(val).lower() if isinstance(val, bool) else val

	return new_comp

def generate_target_struct(target):
	# flesh out target components:
	target = json.loads(target)
	components = target['components']

	# alphabetize by component name
	components = sorted(components.items(), key=lambda x: x[1]['component'])
	components = list(map(map_load, components))

	# flatten pin dicts into multiple entries
	# e.g. "pin": {"a": 12} => "pin_a": 12
	components = [flatten_pin_dicts(comp) for comp in components]

	# convert booleans to properly cased strings
	components = [bools_to_lower_str(comp) for comp in components]

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



	template = open(template_path, 'r').read()

	replacements = {}
	replacements['display_conditional'] = ('#include "dev/oled_ssd130x.h"' if ('display' in target) else  "")
	replacements['target_name'] = target['name']
	replacements['init'] = filter_map_template(components, 'init')

	replacements['switch'] = filter_map_init(components, 'typename', 'daisy::Switch')
	replacements['gatein'] = filter_map_init(components, 'typename', 'daisy::GateIn')
	replacements['encoder'] = filter_map_init(components, 'typename', 'daisy::Encoder')
	replacements['switch3'] = filter_map_init(components, 'typename', 'daisy::Switch3')
	replacements['encoder'] = filter_map_init(components, 'typename', 'daisy::Encoder')
	replacements['analogcount'] = 'static const int ANALOG_COUNT = ' + str(len(list(filter_match(components, 'typename', 'daisy::AnalogControl')))) + ';'

	# these got crazy
	replacements['analogctrlone'] = filter_match(components, 'typename', 'daisy::AnalogControl')
	replacements['analogctrlone'] = "\n\t\t".join(map(lambda x, i: 'cfg[' + str(i) + '].InitSingle(seed.GetPin(' + str(x['pin']) + '));\n', replacements['analogctrlone'], range(len(list(replacements)))))
	replacements['analogctrltwo'] = filter_match(components, 'typename', 'daisy::AnalogControl')
	replacements['analogctrltwo'] = "\n\t\t".join(map(lambda x, i: x['name'] + '.Init(seed.adc.GetPtr(' + str(i) + '), seed.AudioCallbackRate(), ' + str(x['flip']).lower() + ', ' + str(x['invert']).lower() + '});\n', replacements['analogctrltwo'], range(len(list(replacements)))))

	replacements['led'] = filter_map_init(components, 'typename', 'daisy::Led')
	replacements['rgbled'] = filter_map_init(components, 'typename', 'daisy::RgbLed')
	replacements['gateout'] = filter_map_init(components, 'typename', 'daisy_gpio')
	replacements['dachandle'] = filter_map_init(components, 'typename', 'daisy::DacHandle::Config')
	
	
	replacements['display'] = '// no display' if not 'display' in target else \
		'daisy::OledDisplay<' + target['display']['driver'] + '>::Config display_config;\n' +\
		'display_config.driver_config.transport_config.Defaults();\n' +\
		"".join(map(lambda x: x, target['display'].get('config', {}))) +\
		'display.Init(display_config);\n'

	replacements['process'] = filter_map_template(components, 'process')
	# There's also this after {process}. I don't see any meta in the defaults json at this time. Is this needed?
	# ${components.filter((e) => e.meta).map((e) => e.meta.map(m=>`${template(m, e)}`).join("")).join("")}

	replacements['postprocess'] = filter_map_template(components, 'postprocess')
	replacements['displayprocess'] = filter_map_template(components, 'display')
	replacements['hidupdaterates'] = filter_map_template(components, 'updaterate')

	replacements['comps'] = ";\n\t".join(map(lambda x: x['typename'] + ' ' + x['name'], components)) + ';'
	replacements['dispdec'] = ('daisy::OledDisplay<' + target['display']['driver'] + '> display;') if ('display' in target) else  "// no display"

	template = template.format_map(replacements)
	return template

if __name__ == "__main__":
	parser = argparse.ArgumentParser(description='Utility for generating board support files from JSON.')
	parser.add_argument('json_input', help='Path to json file.')
	parser.add_argument('-o', '--output', help='Path to output to. Defaults to board_support.h', default='board_support.h')

	args = parser.parse_args()
	inpath = os.path.abspath(args.json_input)
	outpath = os.path.abspath(args.output)

	print('Generating Board File...')
	infile = open(inpath, 'r').read()
	template_code = generate_target_struct(infile)
	open(outpath, 'w').write(template_code)