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

#include "pikatea_macropad_custom.h"

#define GROUND_PIN_F(PIN) setPinOutput(PIN);writePinLow(PIN);

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  //ground the pins that we need to ground

  GROUND_PIN_F(D3); //key1
  GROUND_PIN_F(B4); //key2
  GROUND_PIN_F(E6); //key3
  GROUND_PIN_F(C6); //key4
  GROUND_PIN_F(D0); //key5
  GROUND_PIN_F(B6); //knob key
  GROUND_PIN_F(F5); //encoder 1
  GROUND_PIN_F(B1); //encoder 2

}

#undef GROUND_PIN_F
