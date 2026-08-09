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
	FN1,
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

// FN2 media-row mods
#define HM_MUTE LSFT_T(KC_MUTE) // Shift + Mute
#define HM_VOLD LSFT_T(KC_VOLD) // Shift + Volume Down
#define HM_VOLU LCTL_T(KC_VOLU) // Control + Volume Up
#define HM_MPRV LALT_T(KC_MPRV) // Alt + Previous Track
#define HM_MPLY LGUI_T(KC_MPLY) // GUI + Play/Pause


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

// // Shift + , → ;
// const key_override_t shift_comm_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
// // Shift + . → :
// const key_override_t shift_dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
// // Shift + ? → !
// const key_override_t shift_ques_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
// // Shift + / → back slash
// const key_override_t shift_slsh_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS);
// // Shift + / → |
// const key_override_t alt_slash_override = ko_make_basic(MOD_MASK_ALT, KC_SLSH, KC_PIPE);

// const key_override_t **key_overrides = (const key_override_t *[]){
//     &shift_comm_override,
//     &shift_dot_override,
//     &shift_ques_override,
//     &shift_slsh_override,
//     &alt_slash_override,
//     NULL
// };

// -------------------- Customer keycodes --------------------
#define MAC_SEARCH      G(KC_SPC)
#define CC_EUR          RALT(KC_5)    // €
#define CC_ACUT         RALT(KC_QUOT) // ´

// Momentary layer keys
#define MO_FN2 MO(FN2)

// Layer-tap keys
#define LT_FN1_SPC  LT(FN1, KC_SPC)     // FN1 (hold) + Space (tap)
#define LT_FN2_TAB  LT(FN2, KC_TAB)     // FN2 (hold) + Tab (tap)
#define LT_FN2_BSPC LT(FN2, KC_BSPC)    // FN2 (hold) + Backspace (tap)
#define LT_FN1_ENT  LT(FN1, KC_ENT)     // FN1 (hold) + Enter (tap)

// Ctrl + number keys
#define CTL_1 LCTL(KC_1)
#define CTL_2 LCTL(KC_2)
#define CTL_3 LCTL(KC_3)
#define CTL_4 LCTL(KC_4)

// -------------------- Keymap --------------------

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Row 0 : ESC, 1–0, MINS, EQL, BSPC,                    MUTE
    // Row 1 : TAB, Q–P, [Å], ['], [/],                      DEL
    // Row 2 : MO(FN2), A–L, [Ö], [Ä], ENT,                  HOME
    // Row 3 : LSFT, Z–M, ,, ., ?, RSFT,                      UP
    // Row 4 : LCTL, LALT, LGUI, SPC_FN1, TAB_FN2, BSPC_FN2, ENT_FN1, RALT, ←↓→

    [MAC_BASE] = LAYOUT_69_ansi(
        KC_ESC,      KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_MINS,     KC_EQL,      KC_BSPC,     KC_MUTE,
        KC_TAB,      KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        EU_ARNG,     KC_QUOT,     KC_SLSH,     KC_DEL,
        MO_FN2,      HM_A,        HM_S,        HM_D,        HM_F,        KC_G,        KC_H,        HM_J,        HM_K,        HM_L,        HM_ODIA,     EU_ADIA,     KC_ENT,      KC_HOME,
        KC_LSFT,     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_B,        KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_QUES,     KC_RSFT,     KC_UP,
        KC_LCTL,     KC_LALT,     KC_LGUI,     LT_FN1_SPC,  LT_FN2_TAB,  LT_FN2_BSPC, LT_FN1_ENT,  KC_RALT,     KC_LEFT,     KC_DOWN,     KC_RGHT),

    [WIN_BASE] = LAYOUT_69_ansi(
        KC_ESC,      KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_MINS,     KC_EQL,      KC_BSPC,     KC_MUTE,
        KC_TAB,      KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        EU_ARNG,     KC_QUOT,     KC_SLSH,     KC_DEL,
        MO_FN2,      KC_A,        KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,        KC_K,        KC_L,        EU_ODIA,     EU_ADIA,     KC_ENT,      KC_HOME,
        KC_LSFT,     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_B,        KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_QUES,     KC_RSFT,     KC_UP,
        KC_LCTL,     KC_LALT,     KC_LGUI,     KC_SPC,      LT_FN2_TAB,  LT_FN2_BSPC, LT_FN1_ENT,  KC_RALT,     KC_LEFT,     KC_DOWN,     KC_RGHT),

    [FN1] = LAYOUT_69_ansi(
        _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     RGB_TOG,
        _______,     KC_EXLM,     KC_AT,       KC_HASH,     KC_DLR,      KC_PERC,     KC_PIPE,     KC_LCBR,     KC_RCBR,     KC_COLN,     KC_QUOT,     CC_EUR,      XXXXXXX,     XXXXXXX,     KC_INS,
        _______,     KC_CIRC,     KC_AMPR,     KC_ASTR,     KC_MINS,     KC_EQL,      KC_SLSH,     KC_LPRN,     KC_RPRN,     KC_SCLN,     KC_DQUO,     XXXXXXX,     _______,     KC_END,
        _______,     KC_GRV,      KC_TILD,     CC_ACUT,     KC_UNDS,     KC_PLUS,     XXXXXXX,     KC_BSLS,     KC_LBRC,     KC_RBRC,     KC_LABK,     KC_RABK,     _______,     KC_PGUP,
        _______,     _______,     _______,     MAC_SEARCH,  _______,     _______,     MAC_SEARCH,  _______,     KC_HOME,     KC_PGDN,     KC_END),

    [FN2] = LAYOUT_69_ansi(
        KC_F12,      KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,       KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,      KC_F12,      _______,     _______,
        _______,     CTL_1,       CTL_2,       CTL_3,       CTL_4,       _______,     KC_PAGE_UP,  KC_HOME,     KC_UP,       KC_END,      _______,     _______,     _______,     _______,     KC_INS,
        HM_MUTE,     HM_VOLD,     HM_VOLU,     HM_MPRV,     HM_MPLY,     KC_MNXT,     KC_PGDN,     KC_LEFT,     KC_DOWN,     KC_RIGHT,    _______,     _______,     _______,     KC_END,
        _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     KC_PGUP,
        _______,     _______,     _______,     MAC_SEARCH,  _______,     _______,     MAC_SEARCH,  _______,     KC_HOME,     KC_PGDN,     KC_END)
};

#if defined(ENCODER_MAP_ENABLE)
	const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
		[MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
		[WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
		[FN1]      = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
		[FN2]	   = {ENCODER_CCW_CW(_______, _______)},
	};
#endif // ENCODER_MAP_ENABLE
