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

#include "pikatea_macropad_custom_1.h"

#define GROUND_PIN_F(PIN) setPinOutput(PIN);writePinLow(PIN);

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  //ground the pins that we need to ground
  // F4, F5, F6, F7, B1, B3, B2, B6, B5, B4, E6, D7

  GROUND_PIN_F(F4);
  GROUND_PIN_F(F5);
  GROUND_PIN_F(F6);
  GROUND_PIN_F(F7);
  GROUND_PIN_F(B1);
  GROUND_PIN_F(B3);
  GROUND_PIN_F(B2);
  GROUND_PIN_F(B6);
  GROUND_PIN_F(B5);
  GROUND_PIN_F(B4);
  GROUND_PIN_F(E6);
  GROUND_PIN_F(D7);
  GROUND_PIN_F(C6);
  GROUND_PIN_F(D4);
  GROUND_PIN_F(D0);
  GROUND_PIN_F(D1);

}

#undef GROUND_PIN_F
