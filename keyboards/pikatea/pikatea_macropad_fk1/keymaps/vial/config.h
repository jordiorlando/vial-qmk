/* Copyright 2020 Jack Kester
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define VIAL_KEYBOARD_UID {0x1D, 0x7D, 0x67, 0xF9, 0xCF, 0xB3, 0x5A, 0xBE}

/* Use one more layer than the number of switches */
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

/* Uncomment this if not using VIAL_INSECURE = yes */
// #define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
// #define VIAL_UNLOCK_COMBO_COLS { 4, 5 }
