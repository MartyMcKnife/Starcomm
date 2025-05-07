RADIOS += my_radio
BOOTLOADERS += my_radio
my_radio_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

# Source files
my_radio_SRCS := \
    $(my_radio_DIR)/board.c

my_radio_CFLAGS := -DCUSTOM_BOARD_INIT -I$(my_radio_DIR)

# Disable UART0 in the bootloader to save space
my_radio_BOOTLOADER_CFLAGS := -DUART0_ENABLED=0