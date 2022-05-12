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

extern MidiDevice midi_device;
// Store value
int val = 0;
// Step amount
int stepAmount = 2;
// store current layer
int currentLayer = 0;

enum custom_keycodes {
    MIDI_CC80 = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_F13,   KC_F14, KC_F15,   KC_F16,   KC_MEDIA_PREV_TRACK,    KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,    KC_MUTE
    ),
    [1] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    ),
    [2] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    ),
    [3] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    ),
    [4] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    ),
    [5] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    ),
    [6] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    ),
    [7] = LAYOUT_all(
        _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______
    )
};


//create a virtual Midi Slider with the encoder
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // Volume control
    if (clockwise) {
        val = val + stepAmount;
        if (val > 127) {
            val = 127;
        }
        midi_send_cc(&midi_device, currentLayer+1, 7, val);
    } else {
        val = val - stepAmount;
        if (val < 0) {
            val = 0;
        }
        midi_send_cc(&midi_device, currentLayer+1, 7, val);
    }
    return true;
}
#endif

//save the layer state to a variable
layer_state_t layer_state_set_user(layer_state_t state) {
    currentLayer = get_highest_layer(state);
    return state;
}

