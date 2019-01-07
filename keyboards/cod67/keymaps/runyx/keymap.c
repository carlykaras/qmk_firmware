/* Copyright 2018 MechMerlin
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


#define _QWERTY 0
#define _SYMB 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
};


//Transparency & Shorthands
#define KC_RS RESET

//Layer Toggles
//MO is momentary, TO is toggle
#define KC_SFUN MO(1)
#define KC_BASE TO(0)

#define KC_LTOG RGB_TOG
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Qwerty
 * ,-----------------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
 * |-----------------------------------------------------------------------------------------+
 * | Fn      |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh |  U  | FN  |
 * |-----------------------------------------------------------------------------------------+
 * | LCtl |  Fn  |  LGui  |      Space      |      Space     | RAlt | Rctl |  L  |  D  |  R  |
 * `-----------------------------------------------------------------------------------------'
 */

	//Figure out backlighting toggle

		[_QWERTY] = LAYOUT_60_ansi_split_space_2ulshift(
			KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
			KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
			KC_SFUN, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
			KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RGB_MOD, KC_UP, RGB_TOG,
			KC_LCTL, KC_SFUN, KC_LGUI, KC_SPC, KC_SPC, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
		),

		[_SYMB] = LAYOUT_60_ansi_split_space_2ulshift(
			_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
			_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
			_______,_______,_______,_______,_______,_______,KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,_______,_______,_______,
			_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
			RESET,_______,_______,_______,_______,_______,_______,_______,_______,_______
		)

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
