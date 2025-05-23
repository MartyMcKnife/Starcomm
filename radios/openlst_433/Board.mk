RADIOS += openlst_433
BOOTLOADERS += openlst_433
openlst_433_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

# Source files
openlst_433_SRCS := \
    $(openlst_433_DIR)/board.c

openlst_433_CFLAGS := -DCUSTOM_BOARD_INIT -I$(openlst_433_DIR)

# Disable UART0 in the bootloader to save space
openlst_433_BOOTLOADER_CFLAGS := -DUART0_ENABLED=0