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

## TODO: refactor these cray function names

def map_helper(pair):
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

def my_filter(set, key, match):
	return filter(lambda x: x.get(key, '') == match, set)

component_inits = {'daisy::Switch': '{name}.Init(seed.GetPin({pin}), seed.AudioCallbackRate(), {type}, {polarity}, {pull});\n',
					'daisy::GateIn': 'dsy_gpio_pin {name}_pin = seed.GetPin({pin});\n _{name}.Init({name}_pin);',

				}

def my_map(comp):
	init_str = component_inits[comp['typename']]
	return init_str.format_map(comp)


# filter out the components we need, then map them onto the init for that part
def map_filter_init_helper(set, key, match):
	filtered = my_filter(set, key, match)
	return "".join(map(my_map, filtered))

def generate_target_struct(target):
	# flesh out target components:
	target = json.loads(target)
	components = target['components']

	# alphabetize by component name
	components = sorted(components.items(), key=lambda x: x[1]['component'])
	components = list(map(map_helper, components))

	print(components, "\n\n")

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
	replacements['display_conditional'] = (target['display'] if ('display' in target) else  "")
	replacements['target_name'] = target['name']
	replacements['init'] = "".join(map(lambda x: x['init'], filter(lambda x: x.get('init', ''), components)))

	replacements['switch'] = map_filter_init_helper(components, 'typename', 'daisy::Switch')
	replacements['gatein'] = map_filter_init_helper(components, 'typename', 'daisy::GateIn')

	# this one is tricky to replace because of ['pin']['a']
	replacements['switch3'] = "".join(map(lambda x: x['name'] + '.Init(seed.GetPin(' + str(x['pin']['a']) + '), ' + 'seed.GetPin(' + str(x['pin']['b']) + ');\n', my_filter(components, 'typename', 'daisy::Switch3')))
	
	return template.format_map(replacements)

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
	print(template_code)