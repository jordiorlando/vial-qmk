/*
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
#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_BRICK(
    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,
    KC_J,    KC_K,    KC_L,    KC_M,    KC_N,    KC_O,    KC_P,    KC_Q,    KC_R,
    KC_S,    KC_T,    KC_U,    KC_V,    KC_W,    KC_X,    KC_Y,    KC_Z,    KC_1,
    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_ENT,  KC_ESC,  KC_BSPC, KC_TAB,  KC_SPC,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
    KC_BSLS, KC_SCLN, KC_QUOT, KC_GRV,  KC_COMM, KC_DOT,  KC_SLSH, KC_CAPS, KC_F1,
    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_F12,  KC_PSCR, KC_DEL,  KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP
  )

};

/*

#define LAYOUT_BRICK( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, \
    K40, K41, K42, K43, K44, K45, K46, K47, K48, \
    K50, K51, K52, K53, K54, K55, K56, K57, K58, \
    K60, K61, K62, K63, K64, K65, K66, K67, K68, \
    K70, K71, K72, K73, K74, K75, K76, K77, K78\
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08 }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18 }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28 }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38 }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48 }, \
    { K50, K51, K52, K53, K54, K55, K56, K57, K58 }, \
    { K60, K61, K62, K63, K64, K65, K66, K67, K68 }, \
    { K70, K71, K72, K73, K74, K75, K76, K77, K78 }\
}

*/
