/* Copyright 2015-2023 Jack Humbert
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

enum planck_layers { _QWERTY, _LOWER, _RAISE, _ADJUST, _SETTINGS };

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap Dance enums
enum {
    TD_LOS, // OS/UNLOCK/LOCK
    TD_CPY, // Copy, Select, Paste, Cut
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the Win tap dance. Put it here so it can be used in any keymap
void win_finished(tap_dance_state_t *state, void *user_data);
void win_reset(tap_dance_state_t *state, void *user_data);
// Same for Copy-Paste
void cpy_finished(tap_dance_state_t *state, void *user_data);
void cpy_reset(tap_dance_state_t *state, void *user_data);

const key_override_t ansi_scln_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_SCLN, DE_COLN, 1<<_QWERTY);
const key_override_t ansi_quot_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_QUOT, DE_DQUO, 1<<_QWERTY);
const key_override_t ansi_comm_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_COMM, DE_LABK, 1<<_QWERTY);
const key_override_t ansi_dot_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_DOT, DE_RABK, 1<<_QWERTY);
const key_override_t ansi_slsh_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_SLSH, DE_QUES, 1<<_QWERTY);

const key_override_t *key_overrides[] = {
    &ansi_scln_ovrd,
    &ansi_quot_ovrd,
    &ansi_comm_ovrd,
    &ansi_dot_ovrd,
    &ansi_slsh_ovrd,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SETNG TG(_SETTINGS)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | TDOS |      | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    DE_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    DE_SCLN, DE_QUOT,
    KC_LSFT, DE_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    DE_COMM, DE_DOT,  DE_SLSH, KC_ENT ,
    KC_LCTL, TD(TD_LOS), TD(TD_CPY), KC_LALT, LOWER, KC_RSFT, KC_SPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   µ  |   {  |   }  |  |   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    DE_TILD, DE_EXLM, DE_AT,   DE_HASH, DE_DLR,  DE_PERC, DE_CIRC, DE_AMPR,    DE_ASTR,    DE_LPRN, DE_RPRN, KC_DEL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   DE_UNDS,    DE_PLUS,    _______, _______, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  DE_MICR,    DE_LCBR,    DE_RCBR, DE_PIPE, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   °  |   [  |   ]  |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    DE_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   DE_MINS, DE_EQL,  _______, _______, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  DE_DEG, DE_LBRC, DE_RBRC, DE_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  Ü   |      |  Ö   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Ä   |  ß   |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      | Setn |
 * `-----------------------------------------------------------------------------------'
 */
 [_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, DE_UDIA, _______, DE_ODIA, _______, _______,
    _______, DE_ADIA, DE_SS  , _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SETNG
),

/* Settings
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SETTINGS] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_SPDU, UG_SPDD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'win' tap dance.
static td_tap_t wintap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
// Same for Copy-paste
static td_tap_t cpytap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void win_finished(tap_dance_state_t *state, void *user_data) {
    wintap_state.state = cur_dance(state);
    switch (wintap_state.state)
    {
    case TD_SINGLE_TAP: register_code(KC_LWIN); break;
    case TD_SINGLE_HOLD: register_code(KC_LWIN); break;
    case TD_DOUBLE_TAP: register_code16(LCA(KC_DEL)); break;
    case TD_DOUBLE_HOLD: register_code16(LWIN(KC_L)); break;
    // Last case is for fast typing. Assuming your key is `f`:
    // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
    case TD_DOUBLE_SINGLE_TAP: tap_code(KC_LWIN); register_code(KC_LWIN); break;
    default: break;
    }
}

void win_reset(tap_dance_state_t *state, void *user_data) {
    switch (wintap_state.state)
    {
    case TD_SINGLE_TAP: unregister_code(KC_LWIN); break;
    case TD_SINGLE_HOLD: unregister_code(KC_LWIN); break;
    case TD_DOUBLE_TAP: unregister_code16(LCA(KC_DEL)); break;
    case TD_DOUBLE_HOLD: unregister_code16(LWIN(KC_L)); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_LWIN); break;
    default: break;
    }
    wintap_state.state = TD_NONE;
}

void cpy_finished(tap_dance_state_t *state, void *user_data) {
    cpytap_state.state = cur_dance(state);
    switch (cpytap_state.state)
    {
    case TD_SINGLE_TAP: register_code16(C(KC_C)); break;
    case TD_SINGLE_HOLD: register_code16(C(KC_A)); break;
    case TD_DOUBLE_TAP: register_code16(C(KC_V)); break;
    case TD_DOUBLE_HOLD: register_code16(C(KC_X)); break;
    case TD_DOUBLE_SINGLE_TAP: tap_code16(C(KC_C)); register_code16(C(KC_C)); break;
    default: break;
    }
}

void cpy_reset(tap_dance_state_t *state, void *user_data) {
    switch (cpytap_state.state)
    {
    case TD_SINGLE_TAP: unregister_code16(C(KC_C)); break;
    case TD_SINGLE_HOLD: unregister_code16(C(KC_A)); break;
    case TD_DOUBLE_TAP: unregister_code16(C(KC_V)); break;
    case TD_DOUBLE_HOLD: unregister_code16(C(KC_X)); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code16(C(KC_C)); break;
    default: break;
    }
    cpytap_state.state = TD_NONE;
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for OS, twice for Ctrl+Alt+Del, double-tap and hold for Win+L
    [TD_LOS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, win_finished, win_reset),
    // Tap = Copy, Hold = Select All, DTap = Paste, DTap hold = Cut
    [TD_CPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cpy_finished, cpy_reset),
};
