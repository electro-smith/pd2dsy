import os
from sys import platform
import threading
import tkinter as tk
from tkinter import ttk
import sv_ttk
import darkdetect

import pd2dsy
import dsy_gui

USE_DARK_THEME = darkdetect.isDark() and not (platform == 'linux')
PROJECT_DIRECTORY = os.path.abspath(os.path.dirname(os.path.realpath(__file__)))

LOG_PATH = os.path.join(PROJECT_DIRECTORY, 'pd2dsy_build.txt')

root = tk.Tk()

upper_frame = ttk.Frame(root, padding="3 3 12 12")
lower_frame = ttk.Frame(root, padding="5 5 5 5")

status_style = ttk.Style()
status_frame = ttk.Frame(root)

upper_frame.pack(fill=tk.BOTH, expand=False)
lower_frame.pack(fill=tk.BOTH, expand=True)
status_frame.pack(fill=tk.BOTH, anchor=tk.S)

# Top bar
menubar = tk.Menu(root)
filemenu = tk.Menu(menubar, tearoff=0)
config_name = os.path.join(PROJECT_DIRECTORY, 'pd2dsy_config.json')

examples_dir = os.path.join(PROJECT_DIRECTORY, 'examples', 'gui_projects')
project_examples = (
    ('Field example', os.path.join(examples_dir, 'field', 'field_example.pd2dsy')),
    ('Patch example', os.path.join(examples_dir, 'patch', 'patch_example.pd2dsy')),
    ('patch.init() example', os.path.join(examples_dir, 'patch_init', 'patch_init_example.pd2dsy')),
    ('Petal example', os.path.join(examples_dir, 'petal', 'petal_example.pd2dsy')),
    ('Pod example', os.path.join(examples_dir, 'pod', 'pod_example.pd2dsy')),
)
project_manager = dsy_gui.ProjectManager(root, filemenu, window_title='pd2dsy',
    configuration_file=config_name, examples=project_examples)
menubar.add_cascade(label="File", menu=filemenu)

helpmenu = tk.Menu(menubar, tearoff=0)
helpmenu.add_command(label="Help Index", command=lambda: 0)
helpmenu.add_command(label="About...", command=lambda: 0)
menubar.add_cascade(label="Help", menu=helpmenu)

root.config(menu=menubar)

# Status bar
status_bar = dsy_gui.StatusBarWrapper(status_frame, darktheme_override=USE_DARK_THEME)

# Main UI elements
pd_browser = dsy_gui.FileBrowserWrapper(upper_frame, 0, 0, 'Pd File', id='w1',
    filetypes=(('Pd file', '*.pd'), ('all files', '*.*')))

json_browser = dsy_gui.FileBrowserWrapper(upper_frame, 3, 0, 'Custom JSON', id='w6',
    filetypes=(('JSON file', '*.json'), ('all files', '*.*')))

def board_dropdown_callback(value):
    json_browser.enable(value == 'Custom')

board_dropdown_options = pd2dsy.BOARDLIST
board_dropdown_options.append('custom')
board_dropdown_options = [name.replace('_', ' ').capitalize() for name in board_dropdown_options]
board_dropdown_translation = {name: original for name, original in zip(board_dropdown_options, pd2dsy.BOARDLIST)}

board_dropdown = dsy_gui.OptionWrapper(upper_frame, 0, 2, 'Board', board_dropdown_options, id='w2',
    callback=board_dropdown_callback)

ram_options = dsy_gui.RadioWrapper(upper_frame, 0, 4, 'RAM Option', ('Speed', 'Size'), id='w3')

terminal_output = dsy_gui.TextFieldWrapper(lower_frame)

def bootloader_thread():
    try:
        pass
    except Exception as e:
        terminal_output.append(str(e) + '\n')

def bootloader():
    thread = threading.Thread(target=bootloader_thread)
    thread.start()

flash_bootloader = dsy_gui.ButtonWrapper(upper_frame, 0, 9, 'Flash Bootloader', bootloader)

def rom_callback(value):
    flash_bootloader.enable(value == 'Size')

rom_options = dsy_gui.RadioWrapper(upper_frame, 1, 4, 'ROM Option', ('Speed', 'Size'), id='w4', callback=rom_callback)

output_browser = dsy_gui.FileBrowserWrapper(upper_frame, 0, 7, 'Output Folder', files=False, id='w5')

def print_error(error, message):
    terminal_output.append('Error: ', color="#df3626")
    terminal_output.append(error + '\n', color='#59b8f7')
    terminal_output.append(message + '\n')

BUILD_ERRORS = {
    'cannot find -ldaisy': f"""This probably means you haven't compiled libDaisy.
The libDaisy folder this program uses is located in {os.path.join(PROJECT_DIRECTORY, 'libdaisy')}.
If you open this path up in your terminal (type in "cd {os.path.join(PROJECT_DIRECTORY, 'libdaisy')}"
without the quotes and hit enter), then type in "make" without quotes and hit enter,
you should be able to build libDaisy without a problem. If you get an error (like "cannot find command make"),
then you may need to install the Daisy toolchain. Instructions can be found at:
https://github.com/electro-smith/DaisyWiki/wiki/1.-Setting-Up-Your-Development-Environment#1-Install-the-Toolchain""",
}

NORMAL_FLASH_ERRORS = {
    'No DFU capable USB device available': f"""This probably means your daisy isn't
in DFU mode. For the normal system bootloader,
you can enter DFU mode by holding the BOOT button
down and then pressing the RESET button. Then once
you release the RESET button, you can also let go of
the BOOT button."""
}

BOOTLOADER_FLASH_ERRORS = {

}

def check_for_common_errors(error_dict, logfile, spurious_errors=['Error during download get_status']):
    errors = []
    with open(logfile, 'r') as file:
        for line in file:
            for error, response in error_dict.items():
                if error in line:
                    errors.append([error, response])
            for error in spurious_errors:
                if error in line:
                    return None

    return errors

def compile_thread():
    inputs = {
        'pd_input': pd_browser.get_value(),
        'board': board_dropdown_translation.get(board_dropdown.get_value(), None),
        'custom_json': json_browser.get_value(),
        'search_paths': [],
        'directory': output_browser.get_value(),
        'force': True,
        'ram': ram_options.get_value().lower(),
        'rom': rom_options.get_value().lower(),
        'no_build': False,
        'log': LOG_PATH,
    }

    encountered_error = False

    # Validate arguments
    if inputs['pd_input'] == '':
        print_error("file error", "please provide an input Pd file.")
        encountered_error = True
    elif not os.path.exists(inputs['pd_input']):
        print_error("file error", f"unable to open Pd file at \"{inputs['pd_input']}\"")
        encountered_error = True

    if board_dropdown.get_value() == 'Custom':
        if inputs['custom_json'] == '':
            print_error("file error", "please provide a custom JSON file.")
            encountered_error = True
        elif not os.path.exists(inputs['custom_json']):
            print_error("file error", f"unable to open JSON file at \"{inputs['custom_json']}\"")
            encountered_error = True

    if inputs['directory'] != '':
        # if not os.path.exists(inputs['directory']):
        #     print_error("unable to open selected output ")
        #     return
        pass
    else:
        inputs['directory'] = os.path.dirname(inputs['pd_input'])

    if encountered_error:
        # terminal_output.append('\n')
        return

    terminal_output.append('Compiling...\n')

    args = pd2dsy.InputObject(**inputs)
    try:
        output, meta, linker_file, args = pd2dsy.run_hvcc(args)
        return_code, main_file, logfile = pd2dsy.compile_project(output, meta, linker_file, args)
        if return_code:
            errors = check_for_common_errors(BUILD_ERRORS, logfile)

            if errors is not None:
                if len(errors) == 0:
                    print_error(f"""unkown error occurred. If your problem persists,
    check the log file at "{LOG_PATH}"
    to check for errors and consider posting it
    to the Daisy Forum.""")
                else:
                    for error, response in errors:
                        print_error(error, response)

                terminal_output.append('\n')
                return

        terminal_output.append("Flashing Daisy...\n")

        return_code, logfile = pd2dsy.flash_project(output, meta, main_file, args)
        if return_code:
            errors = check_for_common_errors(NORMAL_FLASH_ERRORS, logfile)
            if errors is not None:
                if len(errors) == 0:
                    print_error('unkown error', f"""If your problem persists,
    check the log file at "{LOG_PATH}" to check for errors and consider posting it to the Daisy Forum.""")
                else:
                    for error, response in errors:
                        print_error(error, response)

                terminal_output.append('\n')
                return

        terminal_output.append('Daisy successfully flashed!\n')

    except Exception as e:
        # An exception almost certainly means an hvcc generated error
        terminal_output.append('Pd translation error:\n', color="#df3626")
        terminal_output.append(str(e) + '\n')

def compile():
    thread = threading.Thread(target=compile_thread)
    thread.start()

compile_button = dsy_gui.ButtonWrapper(upper_frame, 0, 10, 'Flash Program', compile)

for child in upper_frame.winfo_children():
    child.grid_configure(padx=5, pady=5)

project_manager.set_file_browsers([pd_browser, output_browser, json_browser])
project_manager.set_saveable_wrappers([pd_browser, output_browser, json_browser, board_dropdown, ram_options, rom_options])
project_manager.startup()

if USE_DARK_THEME:
    sv_ttk.use_dark_theme()
else:
    sv_ttk.use_light_theme()

root.update()
root.update()
# After one update cycle, we can set the initial rendered size as the minimum
# root.minsize(root.winfo_width(), root.winfo_height())
root.minsize(500, 550)

root.mainloop()