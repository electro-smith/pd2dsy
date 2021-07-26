# Project Name
# GENERATE TARGET

# Library Locations
LIBDAISY_DIR = # LIBDAISY DEPTHlibdaisy
HVCC_DIR = c

# HVCC Sources
CPP_SOURCES = $(wildcard $(HVCC_DIR)/*.cpp)
C_INCLUDES = -I$(HVCC_DIR)/
C_SOURCES = $(wildcard $(HVCC_DIR)/*.c)

# Project Source
CPP_SOURCES += $(TARGET).cpp 

# LINKER

# BOOTLOADER

# Core location, and generic makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile

program-boot:
	$(OCD) -s $(OCD_DIR) $(OCDFLAGS) \
		-c "program $(BOOTLOADER) verify reset exit $(FLASH_ADDRESS)"

program-boot-dfu:
	dfu-util -a 0 -s $(FLASH_ADDRESS):leave -D $(BOOTLOADER) -d ,0483:df11