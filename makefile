BUILD = build
DIST = dist

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
ACTIVATE_COMMAND = . pd_env/bin/activate
else ifeq ($(UNAME), Darwin)
ACTIVATE_COMMAND = . pd_env/bin/activate
else
ACTIVATE_COMMAND = ./pd_env/Scripts/activate
endif

pyi-build: $(BUILD)
	./install.sh

	git clone https://github.com/electro-smith/json2daisy $(BUILD)/json2daisy
	git clone https://github.com/rdbende/Sun-Valley-ttk-theme $(BUILD)/Sun-Valley-ttk-theme
	git clone -b feature/daisy_json https://github.com/CorvusPrudens/hvcc $(BUILD)/hvcc

	$(ACTIVATE_COMMAND); \
	pyinstaller pd2dsy_gui.spec;

$(BUILD):
	mkdir -p $@

clean:
	rm -rf $(BUILD)
	rm -rf $(DIST)
