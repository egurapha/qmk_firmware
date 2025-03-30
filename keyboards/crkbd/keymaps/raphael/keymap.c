/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

void matrix_init_user(void) {
    // Wait briefly for the matrix to settle.
    wait_ms(50);

    // Get the state of row 0.
    uint8_t row0 = matrix_get_row(0);

    // Check for Q+W combo.
    bool qw_combo = (row0 & (1 << 1)) && (row0 & (1 << 2));
    // Check for O+P combo.
    bool op_combo = (row0 & (1 << 9)) && (row0 & (1 << 10));

    if (qw_combo || op_combo) {
        bootloader_jump();
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSLS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            MT(MOD_LSFT, KC_EQL),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, MT(MOD_RSFT, KC_QUOT),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            MT(MOD_LCTL, KC_GRV),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, MT(MOD_RALT, KC_MINUS),
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            MT(MOD_LGUI, KC_TAB),   TT(1),  LT(1, KC_ENT),     MT(MOD_RGUI, KC_BSPC),  LT(2, KC_SPC), TT(2)
        //`--------------------------'  `--------------------------'
    ),

    [1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
              TO(0), KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY,                       CW_TOGG, KC_PGDN, KC_PGUP, KC_LBRC, KC_RBRC, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_BSPC, KC_DEL,  _______, KC_VOLD, KC_VOLU, KC_MUTE,                      KC_LEFT,  KC_DOWN,   KC_UP, KC_RGHT, KC_HOME,  KC_END,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, TO(0),  _______,     _______, _______, TO(0)
        //`--------------------------'  `--------------------------'
    ),

    [2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
              TO(0),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT,                      _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, TO(0),  _______,     _______, _______, TO(0)
        //`--------------------------'  `--------------------------'
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
