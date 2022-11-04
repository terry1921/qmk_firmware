 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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
#include "oled.c"
#include "encoder.c"

//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC `|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |RGBTog|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | PLAY  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShf/E|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |MO(3) | /Enter  /       \Space \  |MO(2) | TG(1)| RGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
  KC_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,  KC_7,  KC_8,    KC_9,   KC_0,    RGB_TOG,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    KC_BSPC,
  KC_CAPS,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  MT(MOD_LSFT,KC_SPC),KC_Z,KC_X,KC_C, KC_V,    KC_B,  KC_MUTE,    KC_MPLY, KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, MT(MOD_RSFT,KC_ENT),
                    KC_LGUI, KC_LCTL, KC_LALT, MO(3), KC_ENT,     KC_SPC,  MO(2), TG(1), KC_RCTL, KC_RGUI
),
/*
 * COLEMAK_DHk
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC `|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |RGBTog|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | PLAY  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShf/E|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |MO(3) | /Enter  /       \Space \  |MO(2) | TG(1)| RGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[1] = LAYOUT(
  KC_TRNS,  KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,
  KC_TRNS,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                        KC_J,    KC_L,      KC_U,       KC_Y,   KC_SCLN,    KC_TRNS,
  KC_TRNS,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                        KC_M,    KC_N,      KC_E,       KC_I,   KC_O,       KC_TRNS,
  KC_TRNS,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_TRNS,      KC_TRNS, KC_K,    KC_H,      KC_TRNS,    KC_TRNS,KC_TRNS,    KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* Symbols
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  !   |   @  |   #  |   $  |   %  |  ^   |                    |      |      |      |      |      | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  &   |   =  |   -  |   +  |   [  |      |-------.    ,-------|      |   ]  |   `  |   \  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | PLAY  |------+------+------+------+------+------|
 * |LShift|  *   |  (   |  )   |   {  |      |-------|    |-------|      |   }  |  <   |  >   |  /   |RShf/E|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |MO(3) | /Enter  /       \Space \  |MO(2) | RAlt | RGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_AMPR,  KC_PEQL, KC_MINS, KC_PLUS, KC_LBRC, KC_TRNS,                         KC_TRNS, KC_RBRC, KC_GRV,  KC_BSLS, KC_SCLN, KC_QUOT,
  KC_TRNS,  KC_ASTR, KC_LPRN, KC_RPRN, KC_LCBR, KC_LCBR, KC_TRNS,       KC_TRNS, KC_TRNS, KC_RCBR, KC_LT,   KC_GT,   KC_TRNS, KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_RALT, KC_TRNS, KC_TRNS
),
/* Navigate
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC `|   1  |   2  |   3  |   4  | TG(4)|                    | TG(5)|   7  |   8  |   9  |   0  |RGBTog|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  | Vol+ | Play | Prvs | Next |   T  |                    | PgUp | Rctl |  Up  | LCTL | Del  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS | Vol- | MTSP | Rwnd | MFFD |   G  |-------.    ,-------| PgDn | Left | Down | Rigth| Del  | Bspc |
 * |------+------+------+------+------+------|  MUTE |    | PLAY  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  | Home |   ,  | END  |   /  |RShf/E|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |MO(2) | /Enter  /       \Space \  |MO(3) | RAlt | RGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[3] = LAYOUT(
  KC_TRNS,  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS, TG(4),                            TG(5),   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS,
  KC_TRNS,  KC_VOLU,  KC_MPLY,  KC_MPRV,  KC_MNXT, KC_TRNS,                          KC_PGUP, LCTL(KC_LEFT),KC_UP,LCTL(KC_RGHT),KC_DEL, KC_BSPC,
  KC_TRNS,  KC_VOLD,  KC_MSTP,  KC_MRWD,  KC_MFFD, KC_TRNS,                          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,  KC_BSPC,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,       KC_TRNS, KC_TRNS, KC_HOME, KC_TRNS, KC_END,   KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_RALT, KC_TRNS, KC_TRNS
),
/* NumPad
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |NumLoc|   /  |   *  |   -  | TO(0)|                    | TG(5)|      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   0  | 7    | 8    | 9    |  +   |      |                    | BLTog| BLON |Brght+| RGBM+| Hue+ | Sat+ |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   .  | 4    | 5    |6     |  ,   |      |-------.    ,-------|BLSTEP| BLOFF|Brght-| RGBM-| Hue- | Sat- |
 * |------+------+------+------+------+------|   MUTE |   | PLAY  |------+------+------+------+------+------|
 * | Enter| 1    |  2   | 3    |   =  |      |--------|   |-------|RGBPL | RGBBR| RGBRA| RGBSW| RGBKN| RGBXC|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |MO(2) | /Enter  /       \Space \  |MO(3) | RAlt | RGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[4] = LAYOUT(
  _______, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, TO(0),                           TG(5),   _______, _______, _______, _______, _______,
  KC_P0,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,                         BL_TOGG, BL_ON,   RGB_VAI, RGB_MOD, RGB_HUI, RGB_SAI,
  KC_PDOT, KC_P4,   KC_P5,   KC_P6,   KC_PCMM, _______,                         BL_STEP, BL_OFF,  RGB_VAD, RGB_RMOD,RGB_HUD, RGB_SAD,
  KC_PENT, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, _______, KC_TRNS,       KC_TRNS, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_K, RGB_M_X,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_RALT, KC_TRNS, KC_TRNS
),
/* Adjust
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      | TG(4)|                    | TO(0)|      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Reset| Debug| NKRO |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Power| Pwr  | sleep| wake |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  MUTE  |   | PLAY  |------+------+------+------+------+------|
 * | Calc | Mail | Slct | Exec |      |      |--------|   |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |MO(2) | /Enter  /       \Space \  |MO(3) | RAlt | RGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[5] = LAYOUT(
  _______,_______ , _______ ,         _______ ,  _______ , TG(4),                          TO(0),  _______, _______, _______,_______, _______,
  RESET,  DEBUG,    MAGIC_TOGGLE_NKRO,_______,   _______, _______,                         _______,_______, _______, _______,_______, _______,
  KC_PWR, KC_POWER, KC_SLEP,          KC_WAKE,   _______, _______,                         _______,_______, _______, _______,_______, _______,
  KC_CALC,KC_MAIL,  KC_SELECT,        KC_EXECUTE,_______, _______, KC_TRNS,       KC_TRNS, _______,_______, _______, _______,_______, _______,
                    KC_TRNS,          KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,KC_RALT, KC_TRNS, KC_TRNS
)
};
