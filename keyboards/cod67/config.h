/*
Copyright 2018 MechMerlin

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    Gray
#define PRODUCT         cod67
#define DESCRIPTION     60% Custom Keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14


#define MATRIX_ROW_PINS { C7, C6, B6, B5, B4 }
#define MATRIX_COL_PINS { D7, F7, F6, F5, F4, F1, F0, E6, B0, B7, D0, D1, D2, D3 }
#define UNUSED_PINS


/*
//From Yang - rows are incorrectly ordered?
#define MATRIX_ROW_PINS { B5, C6, C7, D7, B4 }
#define MATRIX_COL_PINS { D7, F7, F6, F5, F4, F1, F0, E6, B0, B7, D0, D1, D2, D3 }
#define UNUSED_PINS
*/

/* COL2ROW, ROW2COL, or CUSTOM_MATRIX */
#define DIODE_DIRECTION COL2ROW

/*
Pins already defined:
B0, B4, B5, B6, B7
C6, C7
D0, D1, D2, D3, D7
E6
F0, F1, F4, F5, F6, F7

Tried:
B1, B2, B3
C0, C1, C2, C3, C4, C5
D4, D5, D6
E0, E1, E2, E3, E4, E5, E7
F2, F3

Up in the air: D4 or D6? Both listed as Backlight pins

Yang - Backlight pin is D6, caps lock LED is D4, RGB is B2

*/

#define BACKLIGHT_PIN D6
#define BACKLIGHT_LEVELS 3

//WS2812
#define RGB_DI_PIN B2
#define RGBLED_NUM 20

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for magic key command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#endif
