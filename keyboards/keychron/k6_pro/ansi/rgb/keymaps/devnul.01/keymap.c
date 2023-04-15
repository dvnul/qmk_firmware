/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "g/keymap_combo.h"

#include "leaderkey.h"

// clang-format off
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
enum layers{
  MAC_BASE,
  WIN_BASE,
  MAC_FN1,
  WIN_FN1,
  FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_68(
     KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, RGB_MOD,
     KC_TAB,  KC_QUOT,     KC_COMMA,     KC_DOT,    KC_P,    KC_Y,    KC_F,     KC_G,    KC_C,    KC_R,    KC_L,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_HOME,
     KC_CAPS, KC_A,     KC_O,     KC_E,    KC_U,    LSFT_T(KC_I),      RSFT_T(KC_D),    KC_H,    KC_T,    KC_N,     KC_S,  KC_MINS,     KC_ENT, KC_PGUP ,
     KC_LSFT,  KC_SCLN,     KC_Q,  LCMD_T(KC_J),  LCTL_T(KC_K),    LOPT_T(KC_X),    ROPT_T(KC_B),    RCTL_T(KC_M), RCMD_T(KC_W),  KC_V,   KC_Z,  KC_RSFT, KC_UP, KC_PGDN,
     KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                       KC_RCMMD,MO(MAC_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),

[WIN_BASE] = LAYOUT_ansi_68(
     KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, RGB_MOD,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                       KC_RALT, MO(WIN_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),

[MAC_FN1] = LAYOUT_ansi_68(
     KC_GRV,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LNPD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  RGB_TOG,
     _______,  _______,  _______,  KC_UP,    _______,   _______, _______,  KC_7,     KC_8,     KC_9,     _______,  _______,  _______, _______,    RESET,
     _______,  KC_HOME, KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END,    _______, KC_4,      KC_5,     KC_6,     _______,  _______,  _______,            _______,
     _______,  _______, KC_PGUP, _______, KC_PGDN,    KC_ACL1,   KC_ACL2, KC_1,      KC_2,      KC_3,  _______,    _______,   _______, _______, _______,
        _______,  _______,     _______,                                   KC_0,      _______,  _______, _______,  _______ , _______, _______ ),


[WIN_FN1] = LAYOUT_ansi_68(
     KC_GRV,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_____,  RGB_TOG,
     KC_____,  BT_HST1,  BT_HST2,  BT_HST3,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,            KC_____,
     KC_____,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____,
     KC_____,  KC_____,  KC_____,                                KC_____,                      KC_____,  KC_____,  KC_____,  KC_____,  KC_____,  KC_____),

[FN2] = LAYOUT_ansi_68(
     KC_TILD,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_____,  KC_____,
     RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI,    RGB_SPI,   _______, KC_BTN1, KC_MS_U,  KC_BTN2,   _______,  _______,  _______, _______,    _______,
     _______, RGB_RMOD, RGB_VAD,  RGB_HUD,    RGB_SAD, RGB_SPD,  _______, KC_MS_L,   KC_MS_D,  KC_MS_R, KC_ACL1,  KC_ACL0,  _______,   _______,
      _______, _______,  _______, _______,  KC_ACL1,   BAT_LVL,  KC_ACL2,   _______, KC_WH_U,  KC_WH_D,  _______, _______,  _______,   _______,

     KC_____,  KC_____,  KC_____,                                KC_BTN2, KC_____,  KC_BTN1, KC_____,   KC_____,  KC_____,  KC_LEAD),
};


