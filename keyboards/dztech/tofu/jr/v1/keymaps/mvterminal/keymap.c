/* Copyright 2025 6ooker <erik@katzenberger.cloud>
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
#include "sendstring_german.h"

// clang-format off

enum custom_keycodes {
    CODE = SAFE_RANGE,
    CUST_DIA,
    CUST_MULT,
    CUST_DIV,
    CUST_CURRENCY,
    CUST_UACC,
};

enum layers{
    TY_BASE,
    TZ_BASE,
    FN,
    MISC
};

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
    TD_GES, // GRV,TILD/ESC
    TD_CPY, // Copy/Paste/Cut
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the Win tap dance. Put it here so it can be used in any keymap
void win_finished(tap_dance_state_t *state, void *user_data);
void win_reset(tap_dance_state_t *state, void *user_data);
// Same for Copy-Paste
void cpy_finished(tap_dance_state_t *state, void *user_data);
void cpy_reset(tap_dance_state_t *state, void *user_data);

// Layer defines
#define TY PDF(TY_BASE)
#define TZ PDF(TZ_BASE)
#define CONF MO(MISC)

void leader_start_user(void) {
    // Do smthing when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_U, KC_D)) {
        // Leader, u, d
        SEND_STRING("sudo apt update\n");
    } else if (leader_sequence_two_keys(KC_U, KC_G)) {
        // Leader, u, g
        SEND_STRING("sudo apt upgrade -y\n");
    } else if (leader_sequence_two_keys(KC_I, KC_I)) {
        // Leader, i, i
        SEND_STRING("if () {}" SS_TAP(X_LEFT) SS_TAP(X_ENT));
    } else if (leader_sequence_two_keys(KC_I, KC_F)) {
        // Leader, i, f
        SEND_STRING("for () {}" SS_TAP(X_LEFT) SS_TAP(X_ENT));
    } else if (leader_sequence_two_keys(KC_I, KC_W)) {
        // Leader, i, w
        SEND_STRING("while () {}" SS_TAP(X_LEFT) SS_TAP(X_ENT));
    } else if (leader_sequence_one_key(KC_M)) {
        // Leader, m
        SEND_STRING("erik.katzenberger@exclusive-networks.de");
    }
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    static bool code_is_held = false;
    switch (keycode) {

        case KC_BSPC:
            {
                // Initialize a bool var that keeps track of the delete key status: registered or not?
                static bool delkey_registered;
                if (record->event.pressed) {
                    // Detect the activation of either shift keys
                    if (mod_state & MOD_MASK_SHIFT) {
                        // First temporarily canceling both shifts so that it isn't applied to the KC_DEL keycode
                        del_mods(MOD_MASK_SHIFT);
                        register_code(KC_DEL);
                        // Update the bool var to reflect the status of KC_DEL
                        delkey_registered = true;
                        // Reapplying modifier state so that the held shift key(s) still work even after having tapped the Backspace/Del Key
                        set_mods(mod_state);
                        return false;
                    }
                } else { // on release of KC_BSPC
                    // In case KC_DEL is still being sent even after the release of KC_BSPC
                    if (delkey_registered) {
                        unregister_code(KC_DEL);
                        delkey_registered = false;
                        return false;
                    }
                }
          // Let QMK process the KC_BSPC keycode as usual outside of shift
          return true;
      }
        case CODE:
            {
                code_is_held = record->event.pressed;
                break;
            }

        case KC_W:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("|");
                        return false;
                    }
                }
                return true;
            }

        case KC_Q:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("\\");
                        return false;
                    }
                }
                return true;
            }

        case KC_E:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        register_code16(DE_EURO);
                        return false;
                    }
                }
                return true;
            }

        case KC_X:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("#");
                        return false;
                    }
                }
                return true;
            }

        case KC_C:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("&");
                        return false;
                    }
                }
                return true;
            }

        case KC_V:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("@");
                        return false;
                    }
                }
                return true;
            }

        case KC_B:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("{");
                        return false;
                    }
                }
                return true;
            }

        case KC_N:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("}");
                        return false;
                    }
                }
                return true;
            }

        case KC_F:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("[");
                        return false;
                    }
                }
                return true;
            }

        case KC_G:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("]");
                        return false;
                    }
                }
                return true;
            }

        case KC_U:
            {
                static bool udia_registered;
                if (record->event.pressed) {
                    if (code_is_held) {
                        register_code(DE_UDIA);
                        udia_registered = true;
                        return false;
                    }
                } else {
                    if (udia_registered) {
                        unregister_code(DE_UDIA);
                        udia_registered = false;
                        return false;
                    }
                }
                return true;
            }

        case KC_A:
            {
                static bool adia_registered;
                if (record->event.pressed) {
                    if (code_is_held) {
                        register_code(DE_ADIA);
                        adia_registered = true;
                        return false;
                    }
                } else {
                    if (adia_registered) {
                        unregister_code(DE_ADIA);
                        adia_registered = false;
                        return false;
                    }
                }
                return true;
            }

        case KC_O:
            {
                static bool odia_registered;
                if (record->event.pressed) {
                    if (code_is_held) {
                        register_code(DE_ODIA);
                        odia_registered = true;
                        return false;
                    }
                } else {
                    if (odia_registered) {
                        unregister_code(DE_ODIA);
                        odia_registered = false;
                        return false;
                    }
                }
                return true;
            }

    }
    return true;
};


const key_override_t ansi_one_ovrd   = ko_make_with_layers(MOD_MASK_SHIFT, KC_1, DE_EXLM, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_two_ovrd   = ko_make_with_layers(MOD_MASK_SHIFT, KC_2, DE_AT, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_three_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_3, DE_HASH, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_four_ovrd  = ko_make_with_layers(MOD_MASK_SHIFT, KC_4, DE_DLR, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_five_ovrd  = ko_make_with_layers(MOD_MASK_SHIFT, KC_5, DE_PERC, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_six_ovrd   = ko_make_with_layers(MOD_MASK_SHIFT, KC_6, DE_CIRC, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_seven_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_7, DE_AMPR, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_eight_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_8, DE_ASTR, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_nine_ovrd  = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, DE_LPRN, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_zero_ovrd  = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, DE_RPRN, 1<<TY_BASE|1<<TZ_BASE);
//const key_override_t ansi_grv_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_GRV, DE_TILD, 1<<TY_BASE|1<<TZ_BASE); // old, no override for tapdance
const key_override_t ansi_grv_ovrd   = ko_make_with_layers(MOD_MASK_SHIFT, TD(TD_GES), DE_TILD, 1<<TY_BASE|1<<TZ_BASE); // Override to correctly work with tapdance
const key_override_t ansi_mins_ovrd  = ko_make_with_layers(MOD_MASK_SHIFT, DE_MINS, DE_UNDS, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_eql_ovrd   = ko_make_with_layers(MOD_MASK_SHIFT, DE_EQL, DE_PLUS, 1<<TY_BASE|1<<TZ_BASE);

const key_override_t ansi_lbrc_ovrd  = ko_make_with_layers(MOD_MASK_SHIFT, DE_LBRC, DE_LCBR, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_rbrc_ovrd  = ko_make_with_layers(MOD_MASK_SHIFT, DE_RBRC, DE_RCBR, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_bsls_ovrd  = ko_make_with_layers(MOD_MASK_SHIFT, DE_BSLS, DE_PIPE, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_scln_ovrd  = ko_make_with_layers(MOD_MASK_SHIFT, DE_SCLN, DE_COLN, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_quot_ovrd  = ko_make_with_layers(MOD_MASK_SHIFT, DE_QUOT, DE_DQUO, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_comm_ovrd  = ko_make_with_layers(MOD_MASK_SHIFT, DE_COMM, DE_LABK, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_dot_ovrd   = ko_make_with_layers(MOD_MASK_SHIFT, DE_DOT, DE_RABK, 1<<TY_BASE|1<<TZ_BASE);
const key_override_t ansi_slsh_ovrd  = ko_make_with_layers(MOD_MASK_SHIFT, DE_SLSH, DE_QUES, 1<<TY_BASE|1<<TZ_BASE);

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
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [TY_BASE] = LAYOUT_65_ansi(
        TD(TD_GES),KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DE_MINS, DE_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    DE_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DE_LBRC, DE_RBRC, DE_BSLS, KC_PGUP,
        QK_LEAD,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    DE_SCLN, DE_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,  DE_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    DE_COMM, DE_DOT,  DE_SLSH, CODE,             KC_UP,   TD(TD_CPY),
        KC_LCTL, TD(TD_LOS),KC_LALT,                           KC_SPC,           KC_RALT, MO(FN),  CONF,             KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [TZ_BASE] = LAYOUT_65_ansi(
        TD(TD_GES),KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DE_MINS, DE_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,    DE_LBRC, DE_RBRC, DE_BSLS, KC_PGUP,
        QK_LEAD,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    DE_SCLN, DE_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,  DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    DE_COMM, DE_DOT,  DE_SLSH, CODE,             KC_UP,   TD(TD_CPY),
        KC_LCTL, TD(TD_LOS),KC_LALT,                           KC_SPC,           KC_RALT, MO(FN),  CONF,             KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [FN] = LAYOUT_65_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, RGB_TOG,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,          _______, _______, _______,          _______, _______, _______
    ),
    [MISC] = LAYOUT_65_ansi(
        QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_HOME,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SCRL, KC_PAUS, QK_BOOT, KC_PGUP,
        KC_CAPS, RGB_SPI, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EE_CLR,  KC_PGDN,
        KC_LSFT, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,          KC_VOLU, KC_MUTE,
        _______, _______, _______,                            _______,          _______, _______, _______,          KC_MPRV, KC_VOLD, KC_MNXT
    )
};


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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    uint8_t layer = get_highest_layer(layer_state|default_layer_state);

    // Layer indicator only with keycodes
    if (layer > 0) {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                }
            }
        }
    }

    // Caps Lock Indicator on alphas
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }

    // Mark Leaderkey
    if (leader_sequence_active()) {
        rgb_matrix_set_color(30, 0xFF, 0xFF, 0xFF);
    }

    return false;
}


// RGB only on indicators
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}


// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for OS, twice for Ctrl+Alt+Del, double-tap and hold for Win+L
    [TD_LOS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, win_finished, win_reset),
    // Tap once for Grave/Tilde, double-tap for ESC
    [TD_GES] = ACTION_TAP_DANCE_DOUBLE(DE_GRV, KC_ESC),
    // Tap = Copy, Hold = Select All, DTap = Paste, DTap hold = Cut
    [TD_CPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cpy_finished, cpy_reset),
};
