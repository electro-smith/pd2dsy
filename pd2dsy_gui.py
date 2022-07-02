from sys import platform
import threading
import tkinter as tk
from tkinter import ttk
import sv_ttk
import darkdetect

import pd2dsy
import dsy_gui

USE_DARK_THEME = darkdetect.isDark() and not (platform == 'linux')

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
project_manager = dsy_gui.ProjectManager(root, filemenu, window_title='pd2dsy')
menubar.add_cascade(label="File", menu=filemenu)

helpmenu = tk.Menu(menubar, tearoff=0)
helpmenu.add_command(label="Help Index", command=lambda: 0)
helpmenu.add_command(label="About...", command=lambda: 0)
menubar.add_cascade(label="Help", menu=helpmenu)

root.config(menu=menubar)

# Status bar
status_bar = dsy_gui.StatusBarWrapper(status_frame, darktheme_override=USE_DARK_THEME)

# Main UI elements
pd_browser = dsy_gui.FileBrowserWrapper(upper_frame, 0, 0, 'Pd File', id='w1')

board_dropdown_options = pd2dsy.BOARDLIST
board_dropdown_options.append('custom')
board_dropdown_options = [name.replace('_', ' ').capitalize() for name in board_dropdown_options]
board_dropdown_translation = {name: original for name, original in zip(board_dropdown_options, pd2dsy.BOARDLIST)}

board_dropdown = dsy_gui.OptionWrapper(upper_frame, 0, 2, 'Board', board_dropdown_options, id='w2')

ram_options = dsy_gui.RadioWrapper(upper_frame, 0, 4, 'RAM Option', ('Speed', 'Size'), id='w3')
rom_options = dsy_gui.RadioWrapper(upper_frame, 1, 4, 'ROM Option', ('Speed', 'Size'), id='w4')

output_browser = dsy_gui.FileBrowserWrapper(upper_frame, 0, 7, 'Output Folder', files=False, id='w5')

# libdaisy_browser = FileBrowserWrapper(upper_frame, 3, 0, 'libDaisy Folder', files=False)
json_browser = dsy_gui.FileBrowserWrapper(upper_frame, 3, 0, 'Custom JSON', id='w6')

terminal_output = dsy_gui.TextFieldWrapper(lower_frame)

def compile_thread():
    inputs = {
        'pd_input': pd_browser.get_value(),
        'board': board_dropdown_translation[board_dropdown.get_value()],
        'custom_json': json_browser.get_value(),
        'search_paths': [],
        'directory': output_browser.get_value(),
        'force': True,
        'ram': ram_options.get_value().lower(),
        'rom': rom_options.get_value().lower(),
        'libdaisy_depth': 2,
        'no_build': False,
    }
    args = pd2dsy.InputObject(**inputs)
    try:
        pd2dsy.main(args)
    except Exception as e:
        terminal_output.append(str(e) + '\n')

def compile():
    thread = threading.Thread(target=compile_thread)
    thread.start()

compile_button = dsy_gui.ButtonWrapper(upper_frame, 0, 9, 'Compile & Flash', compile)

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
root.minsize(500, 500)

root.mainloop()