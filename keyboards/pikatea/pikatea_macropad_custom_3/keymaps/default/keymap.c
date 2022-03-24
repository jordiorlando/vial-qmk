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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE,
    _LOWER,
};

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//     QMKBEST = SAFE_RANGE,
//     QMKURL
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_direct(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_A, KC_B),
    [_LOWER] = LAYOUT_direct(KC_1, KC_2, KC_3, KC_4, KC_5, KC_0, KC_7, KC_8, KC_9, KC_0, KC_A, KC_B)
};


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // Volume control
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_4);
        } else {
            tap_code(KC_5);
        }
    } else if (index == 2) {
        if (clockwise) {
            tap_code(KC_6);
        } else {
            tap_code(KC_7);
        }
    }
return true;
}
#endif

