/* Copyright 2024 Yiancar-Designs
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
#include "keymap_german.h"

// clang-format off

enum my_keycodes {
  RETRO_RGB = QK_USER_0
};

enum layers{
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
const key_override_t ansi_grv_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_GRV, DE_TILD, 1<<BASE); // old, no override for tapdance
//const key_override_t ansi_grv_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, TD(TD_GES), DE_TILD, 1<<BASE); // Override to correctly work with tapdance
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
const key_override_t **key_overrides = (const key_override_t *[]){
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
    &ansi_grv_ovrd,
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
    NULL // Null terminate the array!
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_tkl_ansi_tsangan( /* Base */
    KC_ESC,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SCRL, KC_PAUS,
    DE_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    DE_MINS, DE_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   DE_Y,   KC_U,   KC_I,    KC_O,    KC_P,    DE_LBRC, DE_RBRC, DE_BSLS, KC_DEL,  KC_END,  KC_PGDN,
    KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    DE_SCLN, DE_QUOT,          KC_ENT,
    KC_LSFT, DE_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   DE_COMM, DE_DOT,  DE_SLSH,          KC_RSFT,                   KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                                            KC_RALT, MO(FN),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[FN] = LAYOUT_tkl_ansi_tsangan( /* FN */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_MUTE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, RM_TOGG, RM_NEXT, RM_HUED, RM_HUEU, RM_SATD, RM_SATU, RM_VALD, RM_VALU, RM_SPDD, RM_SPDU,          _______,                   _______,
    _______, _______, _______,                   RETRO_RGB,                                            _______, _______, _______, _______, _______, _______),

};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = 50; i <= 55; i++) {
            rgb_matrix_set_color(i, 255, 86, 0);
        }
    } else if ((rgb_matrix_get_mode() == RGB_MATRIX_TYPING_HEATMAP) || (rgb_matrix_get_mode() == RGB_MATRIX_DIGITAL_RAIN)) {
        for (uint8_t i = 50; i <= 55; i++) {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RETRO_RGB:
        if (record->event.pressed) {
            switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_INDICATOR);
                }
                break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                }
                break;
            }
        }
        return false; // Skip all further processing of this key
    default:
        return true; // Process all other keycodes normally
    }
}
