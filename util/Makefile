# Project Name
# GENERATE TARGET

# Library Locations
LIBDAISY_DIR = # LIBDAISY DEPTHlibdaisy
HVCC_DIR = source

# HVCC Sources
CPP_SOURCES = $(wildcard *.cpp) \
$(wildcard $(HVCC_DIR)/*.cpp)

C_INCLUDES = -I$(HVCC_DIR)/ \
-I.

C_SOURCES = $(wildcard $(HVCC_DIR)/*.c)

# LINKER

# BOOTLOADER

# Core location, and generic makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile