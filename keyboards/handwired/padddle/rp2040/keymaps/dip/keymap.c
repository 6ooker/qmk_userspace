// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _DEFAULT,
    _WALK,
    _DODGE,
    _JUMP,
    _SPECIAL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_ortho_1x1(LSFT(KC_W)),
    [_WALK] = LAYOUT_ortho_1x1(KC_W),
    [_DODGE] = LAYOUT_ortho_1x1(KC_LSFT),
    [_JUMP] = LAYOUT_ortho_1x1(KC_SPC),
    [_SPECIAL] = LAYOUT_ortho_1x1(KC_F20)
};

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index)
    {
    case 0:
        if(active) { layer_on(_WALK); } else { layer_off(_WALK); }
        break;

    case 1:
        if(active) { layer_on(_DODGE); } else { layer_off(_DODGE); }
        break;

    case 2:
        if(active) { layer_on(_JUMP); } else { layer_off(_JUMP); }
        break;

    case 3:
        if(active) { layer_on(_SPECIAL); } else { layer_off(_SPECIAL); }
        break;
    }
    return true;
}
