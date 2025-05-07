// OpenLST
// Copyright (C) 2018 Planet Labs Inc.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef _BOARD_H
#define _BOARD_H

// We use a 27MHz clock
#define F_CLK 27000000

/* Damon Stewart 16/10/2024 */

// Set frequency to 436Mhz
#define RF_FSCTRL1 0x06
#define RF_FSCTRL0 0x00
#define RF_FREQ2 0x10
#define RF_FREQ1 0x2F
#define RF_FREQ0 0x69

// Bandwidth and data rates 20Kb/s
#define RF_SYNC_WORD1 0xD3
#define RF_SYNC_WORD0 0x91
#define RF_CHAN_BW_E 3
#define RF_CHAN_BW_M 3
#define RF_CHAN_BW_RANGING_E 3
#define RF_CHAN_BW_RANGING_M 3
#define RF_DRATE_E 8
#define RF_DRATE_M 32
#define RF_DRATE_RANGING_E 8
#define RF_DRATE_RANGING_M 132
#define RF_CHANSPC_E 3
#define RF_CHANSPC_M 185
#define RF_CHANSPC_RANGING_E 3
#define RF_CHANSPC_RANGING_M 185
#define RF_DEVIATN_E 1
#define RF_DEVIATN_M 1
#define RF_DEVIATN_RANGING_E 2
#define RF_DEVIATN_RANGING_M 4
#define RF_FSCAL3_CONFIG 201
#define RF_FSCAL2_CONFIG 10
#define RF_FSCAL1_CONFIG 0
#define RF_FSCAL0_CONFIG 31
#define RF_TEST0_CONFIG 9

// Auto reboot params
#define AUTO_REBOOT_SECONDS 600
#define AUTO_REBOOT_MAX 604800

/***********************/

#define CUSTOM_BOARD_INIT 1
#define BOARD_HAS_TX_HOOK 1
#define BOARD_HAS_RX_HOOK 1
#define CONFIG_CAPABLE_RF_RX 1
#define CONFIG_CAPABLE_RF_TX 1

// Enable the power supply sense lines AN0 and AN1
#define ADCCFG_CONFIG 0b00000011

#define RADIO_RANGING_RESPONDER 1

void board_init(void);

#define BOARD_HAS_LED 1
void board_led_set(__bit led_on);

// These are macros to save space in the bootloader
// Enable bias to on-board 1W RF power amp (RF6504)
#define board_pre_tx() P2_0 = 1;
// Disable on-board power amp bias, to save power
#define board_pre_rx() P2_0 = 0;

#endif