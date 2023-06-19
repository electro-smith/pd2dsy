BUILD = build
DIST = dist

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
ACTIVATE_COMMAND = . pd_env/bin/activate
SEPARATOR = :
PYI_CMD = pyinstaller
else ifeq ($(UNAME), Darwin)
ACTIVATE_COMMAND = . pd_env/bin/activate
SEPARATOR = :
PYI_CMD = python3 -m PyInstaller
else
ACTIVATE_COMMAND = ./pd_env/Scripts/activate
SEPARATOR = ;
PYI_CMD = python -m PyInstaller
endif

DATA_ITEMS = \
libdaisy$(SEPARATOR)libdaisy \
examples$(SEPARATOR)examples \
util$(SEPARATOR)util \
LICENSE$(SEPARATOR). \
$(BUILD)/hvcc/hvcc$(SEPARATOR)hvcc \
$(BUILD)/Sun-Valley-ttk-theme/sun-valley.tcl$(SEPARATOR)sv_ttk/ \
$(BUILD)/Sun-Valley-ttk-theme/theme$(SEPARATOR)sv_ttk/theme \
$(BUILD)/json2daisy/src/json2daisy$(SEPARATOR)json2daisy

DATA_CMDS = $(addprefix --add-data ",$(addsuffix ",$(DATA_ITEMS)))

pyi-build: $(BUILD)
	./install.sh

	git clone https://github.com/electro-smith/json2daisy $(BUILD)/json2daisy
	git clone https://github.com/rdbende/Sun-Valley-ttk-theme $(BUILD)/Sun-Valley-ttk-theme
	git clone -b feature/daisy_json https://github.com/CorvusPrudens/hvcc $(BUILD)/hvcc

	$(ACTIVATE_COMMAND); \
	$(PYI_CMD) pd2dsy_gui.py --windowed --hidden-import darkdetect $(DATA_CMDS);

$(BUILD):
	mkdir -p $@

clean:
	rm -rf $(BUILD)
	rm -rf $(DIST)
