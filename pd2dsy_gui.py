import os
import tkinter as tk
from tkinter import ttk
from tkinter import filedialog
import sv_ttk
import darkdetect

import pd2dsy


class FileBrowserWrapper:

    def __init__(self, frame, column, row, label_text, callback=None, files=True, multiple=False, disable_input=True):
        ttk.Label(frame, text=label_text).grid(column=column, row=row, sticky=tk.W)

        self.text_var = tk.StringVar()
        self.text_box = ttk.Entry(frame, width=16, textvariable=self.text_var)
        if disable_input:
            self.text_box.config(state='readonly')
        self.text_box.grid(column=column, row=row + 1, sticky=(tk.W, tk.E))

        self.browse = ttk.Button(frame, text="Browse", command=self.browse_callback)
        self.browse.grid(column=column + 1, row=row + 1, sticky=tk.W)

        self.open_files = files
        self.open_multiple = multiple
        self.callback = callback

        self.call_matrix = {
            (False, False): filedialog.askdirectory,
            (False, True): filedialog.askdirectory,
            (True, False): filedialog.askopenfilename,
            (True, True): filedialog.askopenfilenames
        }

        self.full_path = ''

    def browse_callback(self, *args):
        return_value = self.call_matrix[(self.open_files, self.open_multiple)]()
        if self.callback is not None:
            self.callback(return_value)
        self.full_path = return_value
        display_name = os.path.basename(self.full_path)
        self.text_var.set(display_name)

    def get_value(self):
        return self.full_path


class OptionWrapper:

    def __init__(self, frame, column, row, label_text, options):
        self.variable = tk.StringVar(frame)
        self.variable.set(options[0])

        self.label =  ttk.Label(frame, text=label_text).grid(column=column, row=row, sticky=tk.W)
        self.dropdown = ttk.OptionMenu(frame, self.variable, *options)
        self.dropdown.grid(column=column, row=row + 1, sticky=tk.W)

    def get_value(self):
        return self.variable.get()

class RadioWrapper:

    def __init__(self, frame, column, row, label_text, options):
        ttk.Label(frame, text=label_text).grid(column=column, row=row, sticky=tk.W)

        self.variable = tk.StringVar(frame)
        self.variable.set(options[0])

        for i, option in zip(range(len(options)), options):
            button = ttk.Radiobutton(frame, text=option, value=option, variable=self.variable)
            button.grid(column=column, row=row + 1 + i, sticky=tk.W)

    def get_value(self):
        return self.variable.get()

class ButtonWrapper:

    def __init__(self, frame, column, row, label_text, callback):

        self.browse = ttk.Button(frame, text=label_text, command=self.action_callback)
        self.browse.grid(column=column, row=row, sticky=tk.W)

        self.callback = callback

    def action_callback(self, *args):
        self.callback()


class TextFieldWrapper:

    def __init__(self, frame):

        self.field = tk.Text(frame, bg='black', fg='white', height=10, width=10, state='disabled')
        self.field.pack(fill=tk.BOTH, expand=True)


root = tk.Tk()
root.title("pd2dsy")

upper_frame = ttk.Frame(root, padding="3 3 12 12")
lower_frame = ttk.Frame(root, padding="5 5 5 5")

status_style = ttk.Style()
status_frame = ttk.Frame(root)

upper_frame.pack(fill=tk.BOTH, expand=False)
lower_frame.pack(fill=tk.BOTH, expand=True)
status_frame.pack(fill=tk.BOTH, anchor=tk.S)

def dummy():
    pass

# Top bar
menubar = tk.Menu(root)
filemenu = tk.Menu(menubar, tearoff=0)
filemenu.add_command(label="New", command=dummy)
filemenu.add_command(label="Open", command=dummy)
filemenu.add_command(label="Save", command=dummy)
filemenu.add_separator()
filemenu.add_command(label="Exit", command=root.quit)
menubar.add_cascade(label="File", menu=filemenu)

helpmenu = tk.Menu(menubar, tearoff=0)
helpmenu.add_command(label="Help Index", command=dummy)
helpmenu.add_command(label="About...", command=dummy)
menubar.add_cascade(label="Help", menu=helpmenu)

# Main UI elements
pd_browser = FileBrowserWrapper(upper_frame, 0, 0, 'Pd File')

board_dropdown_options = pd2dsy.BOARDLIST
board_dropdown_options.append('custom')
board_dropdown_options = [name.replace('_', ' ').capitalize() for name in board_dropdown_options]
board_dropdown_translation = {name: original for name, original in zip(board_dropdown_options, pd2dsy.BOARDLIST)}

board_dropdown = OptionWrapper(upper_frame, 0, 2, 'Board', board_dropdown_options)

ram_options = RadioWrapper(upper_frame, 0, 4, 'RAM Option', ('Speed', 'Size'))
rom_options = RadioWrapper(upper_frame, 1, 4, 'ROM Option', ('Speed', 'Size'))

output_browser = FileBrowserWrapper(upper_frame, 0, 7, 'Output Folder', files=False)

# libdaisy_browser = FileBrowserWrapper(upper_frame, 3, 0, 'libDaisy Folder', files=False)
json_browser = FileBrowserWrapper(upper_frame, 3, 0, 'Custom JSON')


def compile():
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
    pd2dsy.main(args)


compile_button = ButtonWrapper(upper_frame, 0, 9, 'Compile & Flash', compile)

terminal_output = TextFieldWrapper(lower_frame)

status_bar = ttk.Label(status_frame, text="This is the status", anchor=tk.W, padding='5 2 5 2')
status_bar.pack(side=tk.BOTTOM, fill=tk.X)

for child in upper_frame.winfo_children():
    child.grid_configure(padx=5, pady=5)

root.config(menu=menubar)

if darkdetect.isDark():
    sv_ttk.use_dark_theme()
    status_bar.config(background="#303030")
else:
    sv_ttk.use_light_theme()
    status_bar.config(background="#AAAAAA")

root.update()
root.update()
# After one update cycle, we can set the initial rendered size as the minimum
root.minsize(root.winfo_width(), root.winfo_height())

root.mainloop()