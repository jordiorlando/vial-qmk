/* Copyright 2020 Jack Kester
 * Copyright 2022 Jordi Pakey-Rodriguez
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

#define MIDI_CC_VOLUME 7
#define MIDI_CC_MUTE 120

/*
This keymap emulates a MIDI slider with the encoder. Changing layers
changes the Midi channel used. Compatible with Vial.
*/
extern MidiDevice midi_device;
// Channel values
uint8_t channelVal[6] = {127, 127, 127, 127, 127, 127};
// Step size
uint8_t stepSize = 2;
// Current layer
uint8_t currentLayer = 0;

enum keycodes {
    ENC_BTN = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LT(1,KC_F15), LT(2,KC_F16), LT(3,KC_MPRV), LT(4,KC_MPLY), LT(5,KC_MNXT), ENC_BTN
    ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ENC_BTN:
        if (record->event.pressed) {
            if (currentLayer == 0) {
                tap_code(KC_MUTE);
            }
            midi_send_cc(&midi_device, currentLayer, MIDI_CC_MUTE, 0);
        }
        return false; // Skip all further processing of this key
    default:
        return true; // Process all other keycodes normally
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (currentLayer == 0) {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
    }
    if (clockwise) {
        channelVal[currentLayer] += stepSize;
        if (channelVal[currentLayer] > 127) {
            channelVal[currentLayer] = 127;
        }
        midi_send_cc(&midi_device, currentLayer, MIDI_CC_VOLUME, channelVal[currentLayer]);
    } else {
        channelVal[currentLayer] -= stepSize;
        if (channelVal[currentLayer] > 127) {
            channelVal[currentLayer] = 0;
        }
        midi_send_cc(&midi_device, currentLayer, MIDI_CC_VOLUME, channelVal[currentLayer]);
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    currentLayer = get_highest_layer(state);
    return state;
}
