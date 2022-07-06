import os
from pathlib import Path
import json
from sys import platform
import tkinter as tk
from tkinter import ttk
from tkinter import filedialog
from tkinter import messagebox
import darkdetect


class SaveableWrapper:

    def __init__(self, id=None):
        self.variable = tk.StringVar()
        self.id = id

    def get_value(self):
        return self.variable.get()

    def load_from_save(self, value):
        self.variable.set(value)

    def reset_state(self):
        pass


class FileBrowserWrapper(SaveableWrapper):

    def __init__(self, frame, column, row, label_text, callback=None, files=True, multiple=False, disable_input=True, filetypes=None, **kwargs):
        super().__init__(**kwargs)
        ttk.Label(frame, text=label_text).grid(column=column, row=row, sticky=tk.W)

        self.variable = tk.StringVar()
        self.display_variable = tk.StringVar()
        self.text_box = ttk.Entry(frame, width=16, textvariable=self.display_variable)
        if disable_input:
            self.text_box.config(state='readonly')
        self.text_box.grid(column=column, row=row + 1, sticky=(tk.W, tk.E))

        self.browse = ttk.Button(frame, text="Browse", command=self.update_callback)
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

        self.initial_path = None
        self.initial_interaction = False
        self.filetypes = filetypes
        if not files:
            self.filetypes = None
        self.default_dir = None

    def update_callback(self, *args):
        kwargs = {}
        if self.filetypes is not None:
            kwargs['filetypes'] = self.filetypes
        if self.default_dir is not None:
            kwargs['initialdir'] = self.default_dir

        return_value = self.call_matrix[(self.open_files, self.open_multiple)](**kwargs)

        if return_value:
            if self.open_files:
                self.default_dir = os.path.dirname(os.path.abspath(return_value))
            else:
                self.default_dir = os.path.abspath(return_value)

            if self.callback is not None:
                self.callback(return_value)
            self.variable.set(return_value)
            display_name = os.path.basename(return_value)
            self.display_variable.set(display_name)

    def load_from_save(self, value):
        self.variable.set(value)
        display_name = os.path.basename(value)
        self.display_variable.set(display_name)

    def reset_state(self):
        self.variable.set('')
        self.display_variable.set('')

    def enable(self, state: bool):
        new_state = tk.NORMAL if state else tk.DISABLED
        self.browse.config(state=new_state)


class OptionWrapper(SaveableWrapper):

    def __init__(self, frame, column, row, label_text, options, callback=None, **kwargs):
        super().__init__(**kwargs)
        self.options = options
        self.variable = tk.StringVar(frame)
        self.variable.set(options[0])

        self.variable.trace_add("write", self.trace_callback)
        self.callback = callback

        self.label =  ttk.Label(frame, text=label_text).grid(column=column, row=row, sticky=tk.W)
        self.dropdown = ttk.OptionMenu(frame, self.variable, options[0], *options)
        self.dropdown.grid(column=column, row=row + 1, sticky=tk.W)

    def trace_callback(self, *args):
        if self.callback is not None:
            self.callback(self.variable.get())

    def load_from_save(self, value):
        if value in self.options:
            self.variable.set(value)

    def reset_state(self):
        self.variable.set(self.options[0])

    def enable(self, state: bool):
        new_state = tk.NORMAL if state else tk.DISABLED
        self.dropdown.config(state=new_state)


class RadioWrapper(SaveableWrapper):

    def __init__(self, frame, column, row, label_text, options, callback=None, **kwargs):
        super().__init__(**kwargs)
        self.options = options
        ttk.Label(frame, text=label_text).grid(column=column, row=row, sticky=tk.W)

        self.variable = tk.StringVar(frame)
        self.variable.set(options[0])

        self.variable.trace_add("write", self.trace_callback)
        self.callback = callback

        self.buttons = []
        for i, option in zip(range(len(options)), options):
            button = ttk.Radiobutton(frame, text=option, value=option, variable=self.variable)
            button.grid(column=column, row=row + 1 + i, sticky=tk.W)
            self.buttons.append(button)

    def trace_callback(self, *args):
        if self.callback is not None:
            self.callback(self.variable.get())

    def load_from_save(self, value):
        if value in self.options:
            self.variable.set(value)

    def reset_state(self):
        self.variable.set(self.options[0])

    def enable(self, state: bool):
        new_state = tk.NORMAL if state else tk.DISABLED
        for button in self.buttons:
            button.config(state=new_state)


class ButtonWrapper:

    def __init__(self, frame, column, row, label_text, callback):

        self.button = ttk.Button(frame, text=label_text, command=self.action_callback)
        self.button.grid(column=column, row=row, sticky=tk.W)

        self.callback = callback

    def action_callback(self, *args):
        self.callback()

    def enable(self, state: bool):
        new_state = tk.NORMAL if state else tk.DISABLED
        self.button.config(state=new_state)


class TextFieldWrapper:

    foreground_color = "#FFFFFF"
    background_color = "#101010"

    def __init__(self, frame):

        self.field = tk.Text(frame, bg=self.background_color,
            fg=self.foreground_color, height=10, width=10, insertontime=0)
        self.field.pack(fill=tk.BOTH, expand=True)

        self.scrollbar = ttk.Scrollbar(self.field)
        self.scrollbar.pack(side = 'right',fill='y')
        self.scrollbar.config(command=self.field.yview)
        self.field.config(yscrollcommand=self.scrollbar.set)

        # kill all events that can change the text,
        # including all typing (even shortcuts for
        # copy and select all)
        self.field.bind("<<Cut>>", self.kill_event)
        self.field.bind("<<Paste>>", self.kill_event)
        self.field.bind("<<Paste-Selection>>", self.kill_event)
        self.field.bind("<<Clear>>", self.kill_event)
        self.field.bind("<Key>", self.kill_event)
        # restore copy and select all
        for evt in self.field.event_info("<<Copy>>"):
            self.field.bind(evt, self.do_copy)
        for evt in self.field.event_info("<<Select-All>>"):
            self.field.bind(evt, self.do_select_all)

        self.tags = {}

    def append(self, text, color=foreground_color):
        sticky = self.scrollbar.get()[1] >= 0.99

        if color != self.foreground_color:
            tag_to_use = None
            for key, item in self.tags.items():
                if color == item:
                    tag_to_use = key
                    break

            if tag_to_use is None:
                new_tag_name = self.generate_tag_name()
                self.tags[new_tag_name] = color
                self.field.tag_configure(new_tag_name, foreground=color)
                tag_to_use = new_tag_name

            self.field.insert(tk.END, text, tag_to_use)

        else:
            self.field.insert(tk.END, text)

        if sticky:
            self.field.see(tk.END)

    def kill_event(self, evt):
        return 'break'

    def do_copy(self, evt):
        self.field.event_generate('<<Copy>>')

    def do_select_all(self, evt):
        self.field.event_generate('<<Select-All>>')

    def generate_tag_name(self):
        return f'tag_{len(self.tags)}'


class ProjectManager:

    def __init__(self, root, menu, configuration_file="config.json", window_title="Program", examples=None):

        modifier = 'Cmd' if platform == 'darwin' else 'Ctrl'

        menu.add_command(label="New", command=self.operation_new, accelerator=f'{modifier}+N')
        menu.add_command(label="Open", command=self.operation_open, accelerator=f'{modifier}+O')

        self.menu_recent = tk.Menu(menu, tearoff=False)
        menu.add_cascade(menu=self.menu_recent, label='Open recent')

        menu.add_separator()

        menu.add_command(label="Save", command=self.operation_save, accelerator=f'{modifier}+S')
        menu.add_command(label="Save as...", command=self.operation_save_as, accelerator=f'{modifier}+Shift+S')

        self.example_paths = []

        if examples is not None:
            menu.add_separator()

            self.menu_examples = tk.Menu(menu, tearoff=False)
            menu.add_cascade(menu=self.menu_examples, label="Examples")

            for example in examples:
                self.menu_examples.add_command(label=example[0], command=lambda f=example[1]: self.load_recent_or_example(f))
                self.example_paths.append(example[1])

        modifier = 'Command' if platform == 'darwin' else 'Control'

        root.bind(f'<{modifier}-n>', self.operation_new)
        root.bind(f'<{modifier}-o>', self.operation_open)
        root.bind(f'<{modifier}-s>', self.operation_save)
        root.bind(f'<{modifier}-Shift-KeyPress-S>', self.operation_save_as)

        self.root = root
        self.window_title = window_title

        self.configuration_file = configuration_file
        self.config = {
            "current_project_path": None,
            "last_open_path": None,
            "last_save_as_path": None,
            "recent_paths": [],
            "file_browser_paths": {},
        }

        root.protocol('WM_DELETE_WINDOW', self.on_close)
        self.current_project = None
        self.unchanged_settings = {}

        self.saveable_wrappers = []
        self.fb_wrappers = []

    def set_file_browsers(self, fb_wrappers):
        self.fb_wrappers = fb_wrappers
        for wrapper in self.fb_wrappers:
            self.config['file_browser_paths'][wrapper.id] = None

    def set_saveable_wrappers(self, saveable_wrappers):
        self.saveable_wrappers = saveable_wrappers
        for obj in self.saveable_wrappers:
            obj.variable.trace_add("write", self.update_project_state)

    def initialize_paths(self):
        home_dir = str(Path.home())
        if self.config['last_open_path'] is None:
            self.config['last_open_path'] = home_dir
        if self.config['last_save_as_path'] is None:
            self.config['last_save_as_path'] = home_dir

        for browser in self.fb_wrappers:
            saved_path = self.config['file_browser_paths'].get(browser.id, None)
            if saved_path is not None:
                browser.default_dir = saved_path
            else:
                browser.default_dir = home_dir

    def startup(self):
        try:
            with open(self.configuration_file, 'r') as file:
                config_data = json.load(file)
                for key, item in config_data.items():
                    self.config[key] = item

                if len(self.config['recent_paths']) > 0:
                    for path in self.config['recent_paths']:
                        self.menu_recent.add_command(label=path, command=lambda f=path: self.load_recent_or_example(f))
                else:
                    self.menu_recent.add_command(label="no recent files")

                self.initialize_paths()

                if self.config['current_project_path'] is not None:
                    self.load_project(self.config['current_project_path'])
                else:
                    self.set_unchanged()
                    self.update_project_state()
        except FileNotFoundError:
            self.menu_recent.add_command(label="no recent files")
            self.set_unchanged()
            self.update_project_state()
            self.initialize_paths()

    def set_unchanged(self):
        self.unchanged_settings = self.get_save_dict()

    def get_unchanged(self):
        current_settings = self.get_save_dict()
        for id, value in current_settings.items():
            original = self.unchanged_settings.get(id, None)
            if original != value:
                return False
        return True

    def update_project_state(self, *args):
        project_title = self.config['current_project_path']
        if self.config['current_project_path'] is None:
            project_title = 'Untitled Project'
        else:
            project_title = os.path.basename(self.config['current_project_path']).replace('.pd2dsy', '')
        unchanged_character = '' if self.get_unchanged() else '●'
        self.root.title(f'{unchanged_character} {project_title} - {self.window_title}')

    def update_recent_files(self, most_recent):
        if most_recent in self.config['recent_paths']:
            self.config['recent_paths'].remove(most_recent)
        self.config['recent_paths'].insert(0, most_recent)
        if len(self.config['recent_paths']) > 10:
            self.config['recent_paths'] = self.config['recent_paths'][:10]

        self.menu_recent.delete(0, tk.END)

        for path in self.config['recent_paths']:
            self.menu_recent.add_command(label=path, command=lambda f=path: self.load_recent_or_example(f))

    def reset_objects(self):
        for obj in self.saveable_wrappers:
            obj.reset_state()

    def ask_to_save(self, end_message=''):
        if not self.get_unchanged():
            return messagebox.askyesnocancel('Unsaved Changes', f'Save changes{end_message}?')
        return False

    def get_save_dict(self):
        save_dict = {}
        for obj in self.saveable_wrappers:
            if obj in self.fb_wrappers:
                # Convert project paths to relative for cross-platform compatibility
                full_path = obj.get_value()
                if not full_path or self.config['current_project_path'] is None:
                    save_dict[obj.id] = full_path
                else:
                    proj_path = os.path.dirname(self.config['current_project_path'])
                    save_dict[obj.id] = os.path.relpath(full_path, proj_path)
            else:
                save_dict[obj.id] = obj.get_value()
        return save_dict

    def save_config(self):
        try:
            for browser in self.fb_wrappers:
                self.config['file_browser_paths'][browser.id] = browser.default_dir
            with open(self.configuration_file, 'w') as file:
                json.dump(self.config, file)
        except OSError as e:
            raise e

    def save_project(self, save_path):
        try:
            self.config['current_project_path'] = save_path
            with open(save_path, 'w') as file:
                json.dump(self.get_save_dict(), file)
            self.update_recent_files(save_path)
            self.save_config()
            self.set_unchanged()
            self.update_project_state()
        except OSError as e:
            raise e

    def get_is_fb(self, id):
        for obj in self.fb_wrappers:
            if obj.id == id:
                return True
        return False

    def load_project(self, load_path):
        try:
            with open(load_path, 'r') as file:
                project_data = json.load(file)
                wrappers_as_dict = {w.id: w for w in self.saveable_wrappers}
                for id, value in project_data.items():
                    if self.get_is_fb(id):
                        # expand the relative path into a full one
                        if value:
                            proj_path = os.path.dirname(load_path)
                            absolute_path = os.path.abspath(os.path.join(proj_path, value))
                            wrappers_as_dict[id].load_from_save(absolute_path)
                        else:
                            wrappers_as_dict[id].load_from_save(value)
                    else:
                        wrappers_as_dict[id].load_from_save(value)
                self.config['current_project_path'] = load_path
                self.update_recent_files(load_path)
        except FileNotFoundError as e:
            self.config['current_project_path'] = None
            self.reset_objects()

        self.save_config()
        self.set_unchanged()
        self.update_project_state()

    def load_recent_or_example(self, file):
        save_status = self.ask_to_save(end_message=' before opening')
        if save_status is None:
            return

        if save_status:
            self.operation_save()

        self.load_project(file)

    def operation_new(self, *args):
        save_status = self.ask_to_save(' before opening new project')
        if save_status is None:
            return

        if save_status:
            self.operation_save()

        self.config['current_project_path'] = None
        self.save_config()
        self.reset_objects()
        self.set_unchanged()
        self.update_project_state()

    def operation_open(self, *args):
        save_status = self.ask_to_save(end_message=' before opening')
        if save_status is None:
            return

        if save_status:
            self.operation_save()

        kwargs = {}
        if self.config['last_save_as_path'] is not None:
            kwargs['initialdir'] = self.config['last_save_as_path']
        file_path = filedialog.askopenfilename(filetypes=(('pd2dsy project', '*.pd2dsy'), ('all files', '*.*')), **kwargs)
        if file_path:
            self.config['last_open_path'] = os.path.dirname(os.path.abspath(file_path))
            self.load_project(file_path)

    def operation_save(self, *args):
        if self.config['current_project_path'] is None or self.config['current_project_path'] in self.example_paths:
            self.operation_save_as()
        else:
            if not self.get_unchanged():
                self.save_project(self.config['current_project_path'])

    def operation_save_as(self, *args):
        kwargs = {}
        if self.config['last_save_as_path'] is not None:
            kwargs['initialdir'] = self.config['last_save_as_path']
        file_path = filedialog.asksaveasfilename(filetypes=(('pd2dsy project', '*.pd2dsy'), ('all files', '*.*')), **kwargs)
        if file_path:
            self.config['last_save_as_path'] = os.path.dirname(os.path.abspath(file_path))
            self.save_project(file_path)

    def on_close(self):
        save_status = self.ask_to_save(' before closing')
        if save_status is None:
            return

        if save_status:
            self.operation_save()
            self.save_config()
        else:
            self.save_config()

        self.root.destroy()


class StatusBarWrapper:
    def __init__(self, frame, darktheme_override=None):
        self.status_bar = ttk.Label(frame, text="", anchor=tk.W, padding='5 2 5 2')
        self.status_bar.pack(side=tk.BOTTOM, fill=tk.X)

        darktheme_var = darkdetect.isDark()
        if darktheme_override is not None:
            darktheme_var = darktheme_override

        if darktheme_var:
            self.status_bar.config(background="#303030")
        else:
            self.status_bar.config(background="#CCCCCC")

    def set_value(self, value):
        self.status_bar.config(text=value)
