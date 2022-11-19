/*
Copyright 2020 Jack Kester

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID    0x5049
#define PRODUCT_ID   0x0004
#define DEVICE_VER   0x0001
#define MANUFACTURER Jack_Kester
#define PRODUCT      Pikatea Macropad FK1

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { D3 }
#define MATRIX_COL_PINS { D1, D0, D4, C6, D7, E6}

#define DIODE_DIRECTION COL2ROW

/* Rotary Encoder */
#define ENCODERS_PAD_A { B4 }
#define ENCODERS_PAD_B { B5 }
#define ENCODER_RESOLUTION 4

/* Use basic MIDI */
#define MIDI_ADVANCED

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Use 1000hz polling */
#define USB_POLLING_INTERVAL_MS 1

/* Define Bootmagic Lite key (just next to the encoder) */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 4
