/*
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

Independantly of the above copyright notice,
the VENDOR_ID:PRODUCT_ID of 0x16D0:10A6 is trademark Griffin Barrett,
please replace this if you modify the code

*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */


/* Change these if you modify the code */
#define VENDOR_ID       0x16D0
#define PRODUCT_ID      0x10A6
/* Change these if you modify the code */

#define DEVICE_VER      0xFFFD
#define MANUFACTURER    Pikatea and Griffin Barrett
#define PRODUCT         funn_gus_prototype

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 9

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 4


#define MATRIX_ROW_PINS { B1, B3, B2 }
#define MATRIX_ROW_PIN_COUNT 3
/* It is arbitrary, but we use a grey code to limit transitions in the external chip.
Only one bit changes per row change, so there should be no timing related digital glitching */
#define MATRIX_ROW_MASKS { 4, 0, 2, 3, 1, 5, 7, 6 }
/*  Row num : bit mask : CD4051B pin grounded
 *  0 : 100 : 4
 *  1 : 000 : 0
 *  2 : 010 : 2
 *  3 : 011 : 3
 *  4 : 001 : 1
 *  5 : 101 : 5
 *  6 : 111 : 7
 *  7 : 110 : 6
 */

#define MATRIX_COL_PINS { D3, D2, D7, E6, F6, B6, F7, B4, B5 }

#define MATRIX_IO_DELAY 15

/* DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define DIODE_DIRECTION COL2ROW

//encoder
#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTION 4
