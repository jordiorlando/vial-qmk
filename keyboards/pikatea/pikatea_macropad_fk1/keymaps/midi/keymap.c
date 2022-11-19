/* Copyright 2022 Jack Kester
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

/*
This keymap mulates a MIDI slider with the encoder. Changing layers
changes the Midi channel used. Compatible with Vial.
*/
extern MidiDevice midi_device;
// Channel values
uint8_t channelVal[6] = {0, 0, 0, 0, 0, 0};
// Step size
uint8_t stepSize = 2;
// Current layer
uint8_t currentLayer = 0;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LT(1, KC_F15),    LT(2, KC_F16),    LT(3, KC_MPRV),    LT(4, KC_MPLY),    LT(5, KC_MNXT),    KC_MUTE
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (currentLayer == 0) {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
    } else {
        if (clockwise) {
            channelVal[currentLayer] += stepSize;
            if (channelVal[currentLayer] > 127) {
                channelVal[currentLayer] = 127;
            }
            midi_send_cc(&midi_device, currentLayer + 1, 7, channelVal[currentLayer]);
        } else {
            if (channelVal[currentLayer] >= stepSize) {
                channelVal[currentLayer] -= stepSize;
            } else {
                channelVal[currentLayer] = 0;
            }
            midi_send_cc(&midi_device, currentLayer + 1, 7, channelVal[currentLayer]);
        }
    }
    return true;
}

//save the layer state to a variable
layer_state_t layer_state_set_user(layer_state_t state) {
    currentLayer = get_highest_layer(state);
    return state;
}
