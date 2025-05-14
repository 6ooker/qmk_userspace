// Copyright 2023 Massdrop, Inc.
// SPDX-License-Identifier: GPL-2.0-or-later
// Keymap by @6ooker

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

// clang-format off

enum layers {
    BASE,
    FN
};


const key_override_t ansi_one_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_1, DE_EXLM, 1<<BASE);
const key_override_t ansi_two_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_2, DE_AT, 1<<BASE);
const key_override_t ansi_three_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_3, DE_HASH, 1<<BASE);
const key_override_t ansi_four_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_4, DE_DLR, 1<<BASE);
const key_override_t ansi_five_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_5, DE_PERC, 1<<BASE);
const key_override_t ansi_six_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_6, DE_CIRC, 1<<BASE);
const key_override_t ansi_seven_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_7, DE_AMPR, 1<<BASE);
const key_override_t ansi_eight_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_8, DE_ASTR, 1<<BASE);
const key_override_t ansi_nine_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, DE_LPRN, 1<<BASE);
const key_override_t ansi_zero_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, DE_RPRN, 1<<BASE);
const key_override_t ansi_mins_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_MINS, DE_UNDS, 1<<BASE);
const key_override_t ansi_eql_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_EQL, DE_PLUS, 1<<BASE);

const key_override_t ansi_lbrc_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_LBRC, DE_LCBR, 1<<BASE);
const key_override_t ansi_rbrc_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_RBRC, DE_RCBR, 1<<BASE);
const key_override_t ansi_bsls_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_BSLS, DE_PIPE, 1<<BASE);
const key_override_t ansi_scln_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_SCLN, DE_COLN, 1<<BASE);
const key_override_t ansi_quot_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_QUOT, DE_DQUO, 1<<BASE);
const key_override_t ansi_comm_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_COMM, DE_LABK, 1<<BASE);
const key_override_t ansi_dot_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_DOT, DE_RABK, 1<<BASE);
const key_override_t ansi_slsh_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_SLSH, DE_QUES, 1<<BASE);

// This globally defines all key overrides to be used
// CHANGED as described here: https://docs.qmk.fm/ChangeLog/20240825#key-override-keymap-c-signature-change-24120
const key_override_t *key_overrides[] = {
    &ansi_one_ovrd,
    &ansi_two_ovrd,
    &ansi_three_ovrd,
    &ansi_four_ovrd,
    &ansi_five_ovrd,
    &ansi_six_ovrd,
    &ansi_seven_ovrd,
    &ansi_eight_ovrd,
    &ansi_nine_ovrd,
    &ansi_zero_ovrd,
    &ansi_mins_ovrd,
    &ansi_eql_ovrd,
    &ansi_lbrc_ovrd,
    &ansi_rbrc_ovrd,
    &ansi_bsls_ovrd,
    &ansi_scln_ovrd,
    &ansi_quot_ovrd,
    &ansi_comm_ovrd,
    &ansi_dot_ovrd,
    &ansi_slsh_ovrd,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐┌───┬───┬───┐
     * │Esc││F1 │F2 │F3 │F4 ││F5 │F6 │F7 │F8 ││F9 │F10│F11│F12││F13││PSc│Scr│Pse│
     * └───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┘└───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐┌───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp││Ins│Hom│PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤├───┼───┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  ││Del│End│PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤└───┴───┴───┘
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤    ┌───┐
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │    │ ↑ │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤┌───┼───┼───┐
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Menu│Ctrl││ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘└───┴───┴───┘
     */
    [BASE] = LAYOUT_tkl_f13_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,     KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DE_MINS, DE_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    DE_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DE_LBRC, DE_RBRC, DE_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    DE_SCLN, DE_QUOT,          KC_ENT,
        KC_LSFT,          DE_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    DE_COMM, DE_DOT,  DE_SLSH,          KC_RSFT,             KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(FN),   KC_APP, KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [FN] = LAYOUT_tkl_f13_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,    _______, _______, _______,
        _______, RM_TOGG, RM_VALU, RM_SPDU, RM_HUEU, RM_SATU, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, RM_NEXT, RM_VALD, RM_SPDD, RM_HUED, RM_SATD, _______, _______, _______, _______, _______, _______,          _______,
        _______,          RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,_______, NK_TOGG, _______, _______, _______, _______,          _______,             _______,
        _______, _______, _______,                            EE_CLR,                             _______, _______, _______, _______,    _______, _______, _______
    )
};
