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

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    K07, K01, K11, K21, K31, K41, K51, K61, K71, K70, K60, K50, K40,   K30,  \
    K09,  K03, K13, K23, K33, K43, K53, K63, K73, K72, K62, K52, K42,  K32,       K22,  \
    K05,   K15, K25, K35, K45, K55, K65, K75, K74, K64, K54, K44,    K34,       K24, K14,  \
    K19,K17,K27, K37, K47, K57, K67, K77, K76, K66, K56, K46,    K36,K26,  K16, K06, \
    K29,  K39,  K49,                  K79,             K58,  K48,  K38,  K28,   K18, K08 \
) \
{ \
    { KC_NO, KC_NO, KC_NO, K30, K40, K50, K60, K70 }, \
    { K01, K11, K21, K31, K41, K51, K61, K71 }, \
    { KC_NO, KC_NO, K22, K32, K42, K52, K62, K72 }, \
    { K03, K13, K23, K33, K43, K53, K63, K73 }, \
    { KC_NO, K14, K24, K34, K44, K54, K64, K74 }, \
    { K05, K15, K25, K35, K45, K55, K65, K75 }, \
    { K06, K16, K26, K36, K46, K56, K66, K76 }, \
    { K07, K17, K27, K37, K47, K57, K67, K77 }, \
    { K08, K18, K28, K38, K48, K58, KC_NO, KC_NO }, \
    { K09, K19, K29, K39, K49, KC_NO, KC_NO, K79 } \
}
