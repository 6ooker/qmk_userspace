// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _UMLAUT,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT(
        KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Z,   KC_U,   KC_I,   KC_O,   KC_P,        KC_BSPC,
        KC_CAPS,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,                 KC_ENT,
        KC_LSFT,  MO(_UMLAUT),   KC_Y,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,   KC_DOT,   KC_RSFT,
        KC_LCTL,   KC_LGUI,   KC_LALT,                  KC_SPC,                    KC_RALT,    MO(_FN),   KC_RCTL
    ),
    [_UMLAUT] = LAYOUT(
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   DE_UDIA,   _______,   DE_ODIA,   _______,    KC_DEL,
        _______,   DE_ADIA,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,                         _______,                                    _______,   _______,   _______
    ),
    [_FN] = LAYOUT(
         KC_ESC,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,                         _______,                                    _______,   _______,   _______
    )
};
