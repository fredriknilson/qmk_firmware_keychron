/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

#include "keymap_eurkey.h"

// -------------------- Layers --------------------

enum layers{
	MAC_BASE,
	WIN_BASE,
	MAC_FN1,
	WIN_FN1,
	FN2,
};

// -------------------- Home Row Mods --------------------

// Left-hand home row mods
#define HM_A LSFT_T(KC_A) // Shift + A
#define HM_S LCTL_T(KC_S) // Control + S
#define HM_D LALT_T(KC_D) // Alt + D
#define HM_F LGUI_T(KC_F) // GUI + F

// Right-hand home row mods
#define HM_J    RGUI_T(KC_J) // GUI + J
#define HM_K    RALT_T(KC_K) // Alt + K
#define HM_L    RCTL_T(KC_L) // Control + L
#define HM_ODIA RSFT_T(EU_ODIA) // Shift + Ö


// -------------------- Custom keycode handling --------------------

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case RSFT_T(EU_ODIA):
            if (record->tap.count && record->event.pressed) {
                tap_code16(EU_ODIA); // Send EU_ODIA on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}


// -------------------- Key Overrides --------------------

// Shift + , → ;
const key_override_t shift_comm_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
// Shift + . → :
const key_override_t shift_dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
// Shift + ? → !
const key_override_t shift_ques_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
// Shift + / → back slash
const key_override_t shift_slsh_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS);
// Shift + / → |
const key_override_t alt_slash_override = ko_make_basic(MOD_MASK_ALT, KC_SLSH, KC_PIPE);

const key_override_t **key_overrides = (const key_override_t *[]){
    &shift_comm_override,
    &shift_dot_override,
    &shift_ques_override,
    &shift_slsh_override,
    &alt_slash_override,
    NULL
};

// -------------------- Customer keycodes --------------------
#define MAC_SEARCH              G(KC_SPC)

// -------------------- Keymap --------------------

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_69_ansi(
        KC_ESC,  KC_1,	   KC_2,	 KC_3,	  KC_4,    KC_5,	KC_6,	  KC_7,    KC_8,	KC_9,	 KC_0,	   KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,	   KC_W,	 KC_E,	  KC_R,    KC_T,	KC_Y,	  KC_U,    KC_I,	KC_O,	 KC_P,	   EU_ARNG,  KC_QUOT,  KC_SLSH,          KC_DEL,
        MO(FN2), KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     EU_ODIA,  EU_ADIA,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,	 KC_X,	  KC_C,    KC_V,	KC_B,	  KC_B,    KC_N,	KC_M,	 KC_COMM,  KC_DOT,	 KC_QUES,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPTN, KC_LCMMD, LT(MAC_FN1, KC_SPC), LT(FN2, KC_TAB), LT(FN2, KC_BSPC), LT(MAC_FN1, KC_ENT), KC_RALT,         KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_69_ansi(
        KC_ESC,  KC_1,	   KC_2,	 KC_3,	  KC_4,    KC_5,	KC_6,	  KC_7,    KC_8,	KC_9,	 KC_0,	   KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,	   KC_W,	 KC_E,	  KC_R,    KC_T,	KC_Y,	  KC_U,    KC_I,	KC_O,	 KC_P,	   EU_ARNG,  KC_QUOT,  KC_SLSH,          KC_DEL,
        MO(FN2), KC_A,	   KC_S,	 KC_D,	  KC_F,    KC_G,              KC_H,    KC_J,	KC_K,	 KC_L,	   EU_ODIA,  EU_ADIA,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,	 KC_X,	  KC_C,    KC_V,	KC_B,	  KC_B,    KC_N,	KC_M,	 KC_COMM,  KC_DOT,	 KC_QUES,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LALT,  KC_LWIN, KC_SPC, LT(FN2, KC_TAB), LT(FN2, KC_BSPC), LT(MAC_FN1, KC_ENT), KC_RALT,                       KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_FN1] = LAYOUT_69_ansi(
        KC_GRV,  KC_EXLM,  KC_AT,   KC_HASH,  KC_DLR,  KC_PERC, KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_UNDS,  KC_PLUS,  _______,          RGB_TOG,
        _______, KC_GRAVE, KC_LABK, KC_RABK,  KC_MINUS,KC_PIPE, KC_DLR,   KC_LCBR, KC_RCBR, KC_COLN, KC_CIRC,  XXXXXXX,  XXXXXXX,  XXXXXXX,          KC_INS,
        _______, KC_EXLM,  KC_ASTR, KC_SLASH, KC_EQUAL,KC_AMPR,           KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN,  KC_DQUO,  XXXXXXX,  _______,          KC_END,
        _______,           KC_TILD, KC_PLUS,  KC_BSLS, KC_UNDS, KC_PERC,  KC_PERC, KC_AT,   KC_LBRC, KC_RBRC,  KC_DOT,   KC_QUOT,  _______, KC_PGUP,
        _______, _______,  _______,           MAC_SEARCH,       _______,  _______,          MAC_SEARCH,        _______,            KC_HOME, KC_PGDN, KC_END),

    [WIN_FN1] = LAYOUT_69_ansi(
        KC_GRV,  KC_EXLM,  KC_AT,   KC_HASH,  KC_DLR,  KC_PERC, KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_UNDS,  KC_PLUS,  _______,          RGB_TOG,
        _______, KC_GRAVE, KC_LABK, KC_RABK,  KC_MINUS,KC_PIPE, KC_DLR,   KC_LCBR, KC_RCBR, KC_COLN, KC_CIRC,  XXXXXXX,  XXXXXXX,  XXXXXXX,          KC_INS,
        _______, KC_EXLM,  KC_ASTR, KC_SLASH, KC_EQUAL,KC_AMPR,           KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN,  KC_DQUO,  XXXXXXX,  _______,          KC_END,
        _______,           KC_TILD, KC_PLUS,  KC_BSLS, KC_UNDS, KC_PERC,  KC_PERC, KC_AT,   KC_LBRC, KC_RBRC,  KC_DOT,   KC_QUOT,  _______, KC_PGUP,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            KC_HOME, KC_PGDN, KC_END),

    [FN2] = LAYOUT_69_ansi(
        KC_F12,  KC_F1,    KC_F2,	 KC_F3,   KC_F4,   KC_F5,	KC_F6,	  KC_F7,   KC_F8,	KC_F9,	 KC_F10,   KC_F11,	 KC_F12,   _______,          _______,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          KC_INS,
        KC_MUTE, KC_VOLD,  KC_VOLU,  KC_MPRV, KC_MPLY, KC_MNXT,           RGB_MOD, RGB_VAD, RGB_VAI, RGB_HUI,  _______,  _______,  _______,          KC_END,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, KC_PGUP,
        _______, _______,  _______,           MAC_SEARCH,       _______,  _______,          MAC_SEARCH,        _______,            KC_HOME, KC_PGDN, KC_END)
};

#if defined(ENCODER_MAP_ENABLE)
	const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
		[MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
		[WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
		[MAC_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
		[WIN_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
		[FN2]	   = {ENCODER_CCW_CW(_______, _______)},
	};
#endif // ENCODER_MAP_ENABLE
