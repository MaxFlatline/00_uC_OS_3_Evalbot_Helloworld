# Global makefile for the whole project

# Toolset
CC = arm-none-eabi-gcc

# Default target variables
TARGET_FAMILY = LM3S
TARGET_DEVICE = lm3s9b92
TARGET_CORE = cortex-m3
DFP_VERSION = 1.1.1


# Default compiler flags
CF = -0g -g -Wall

# Default include paths

# Default sources directories
PROJECT_ROOT_DIR = ..
STARTUP_DIR = $(PROJECT_ROOT_DIR)/Sources/Startup
CORE_DIR = $(PROJECT_ROOT_DIR)/Sources/Core
TARGET_LIB_DIR = $(CMSIS_PACK_ROOT)/Keil/$(TARGET_FAMILY)/$(DFP_VERSION)
DEFAULT_OUTPUT_DIR = $(PROJECT_ROOT_DIR)/Output/Core

# Main target
Helloworld: Main
	arm-none-eabi-gcc -mcpu=$(TARGET_CORE) \
	-I $(TARGET_LIB_DIR)/Device/Include \
        -Og -g -Wall \
        -mthumb \
        -c \
        -o $(DEFAULT_OUTPUT_DIR)/startup_lm3s.o \
        ../Sources/Startup/startup_lm3s.c
        #../Sources/Core/Src/main.c ../Sources/Startup/startup_lm3s.c

Main: Output_dir
	$(CC) -mcpu=$(TARGET_CORE) \
        -I $(TARGER_LIB_DIR)/Device/Include \
        -Og -g -Wall \
        -mthumb \
        -c \
        -o $(DEFAULT_OUTPUT_DIR)/main.o \
        ../Sources/Core/Src/main.c

# Directories
Output_dir:
	mkdir -p $(DEFAULT_OUTPUT_DIR)
