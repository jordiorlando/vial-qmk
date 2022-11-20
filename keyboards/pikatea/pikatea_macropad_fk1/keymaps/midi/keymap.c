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

#define ENCODER_ROW 0
#define ENCODER_COL 5
#define STEP_SIZE 4
#define MIDI_CC_VOLUME 7
#define MIDI_CC_MUTE 120

/*
This keymap emulates a MIDI slider with the encoder. Changing layers
changes the Midi channel used. Compatible with Vial.
*/
extern MidiDevice midi_device;
// Channel values
uint8_t channelVal[6] = {127, 127, 127, 127, 127, 127};
// Current layer
uint8_t currentLayer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LT(1,KC_F15), LT(2,KC_F16), LT(3,KC_MPRV), LT(4,KC_MPLY), LT(5,KC_MNXT), KC_MUTE
    ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    // Create a keypos_t variable that points to the encoder's location
    keypos_t encoderPos;
    encoderPos.row = clockwise ? KEYLOC_ENCODER_CW : KEYLOC_ENCODER_CCW;
    encoderPos.col = 0;
    // Get the keycode for the current layer (catches KC_TRNS properly)
    uint16_t currentKeycode = keymap_key_to_keycode(currentLayer, encoderPos);
    // Only do MIDI stuff if the encoder is unassigned on this layer
    if ((currentKeycode == KC_NO) || (currentKeycode == KC_TRNS)) {
        // Increase or decrease the channel value by STEP_SIZE
        channelVal[currentLayer] += clockwise ? STEP_SIZE : -STEP_SIZE;
        // Check for and correct overflow
        if (channelVal[currentLayer] > 127) {
            channelVal[currentLayer] = clockwise ? 127 : 0;
        }
        // Send a MIDI Volume Control Change (CC) message
        midi_send_cc(&midi_device, currentLayer, MIDI_CC_VOLUME, channelVal[currentLayer]);
        // Don't process this keycode any further
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Only do stuff when the encoder button is pressed
    if ((record->event.key.row == ENCODER_ROW) && (record->event.key.col == ENCODER_COL) && record->event.pressed) {
        // Get the keycode for the current layer (catches KC_TRNS properly)
        uint16_t currentKeycode = keymap_key_to_keycode(currentLayer, record->event.key);
        // Only do MIDI stuff if the encoder button is unassigned on this layer
        if ((currentKeycode == KC_NO) || (currentKeycode == KC_TRNS)) {
            // Send a MIDI Mute Control Change (CC) message
            midi_send_cc(&midi_device, currentLayer, MIDI_CC_MUTE, 0);
            // Don't process this keycode any further
            return false;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    currentLayer = get_highest_layer(state);
    return state;
}
