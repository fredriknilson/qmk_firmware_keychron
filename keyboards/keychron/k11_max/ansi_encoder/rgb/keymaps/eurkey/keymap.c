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

// -------------------- Tab dance --------------------s

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[12];

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_1);
        tap_code16(KC_1);
        tap_code16(KC_1);
    }
    if(state->count > 3) {
        tap_code16(KC_1);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_1); break;
        case DOUBLE_TAP: register_code16(KC_1); register_code16(KC_1); break;
        case DOUBLE_HOLD: register_code16(LCTL(KC_1)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_1); register_code16(KC_1);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_1); break;
        case DOUBLE_TAP: unregister_code16(KC_1); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(KC_1)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_1); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_2);
        tap_code16(KC_2);
        tap_code16(KC_2);
    }
    if(state->count > 3) {
        tap_code16(KC_2);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_2); break;
        case DOUBLE_TAP: register_code16(KC_2); register_code16(KC_2); break;
        case DOUBLE_HOLD: register_code16(LCTL(KC_2)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_2); register_code16(KC_2);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_2); break;
        case DOUBLE_TAP: unregister_code16(KC_2); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(KC_2)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_2); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_3);
        tap_code16(KC_3);
        tap_code16(KC_3);
    }
    if(state->count > 3) {
        tap_code16(KC_3);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_3); break;
        case DOUBLE_TAP: register_code16(KC_3); register_code16(KC_3); break;
        case DOUBLE_HOLD: register_code16(LCTL(KC_3)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_3); register_code16(KC_3);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_3); break;
        case DOUBLE_TAP: unregister_code16(KC_3); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(KC_3)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_3); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_4);
        tap_code16(KC_4);
        tap_code16(KC_4);
    }
    if(state->count > 3) {
        tap_code16(KC_4);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_4); break;
        case DOUBLE_TAP: register_code16(KC_4); register_code16(KC_4); break;
        case DOUBLE_HOLD: register_code16(LCTL(KC_4)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_4); register_code16(KC_4);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_4); break;
        case DOUBLE_TAP: unregister_code16(KC_4); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(KC_4)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_4); break;
    }
    dance_state[3].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Z);
        tap_code16(KC_Z);
        tap_code16(KC_Z);
    }
    if(state->count > 3) {
        tap_code16(KC_Z);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_Z); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Z); register_code16(KC_Z);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_Z); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Z); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    if(state->count > 3) {
        tap_code16(KC_X);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_X); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_X)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_X); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_X)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if(state->count > 3) {
        tap_code16(KC_C);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_C); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_C)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_C); register_code16(KC_C);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_C); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_C)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if(state->count > 3) {
        tap_code16(KC_V);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_V); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_V)); break;
        case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_V))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_V); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_V)); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(LSFT(KC_V))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
    }
    dance_state[8].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
};

#define TD_1 TD(DANCE_0)
#define TD_2 TD(DANCE_1)
#define TD_3 TD(DANCE_2)
#define TD_4 TD(DANCE_3)
#define TD_Z TD(DANCE_5)
#define TD_X TD(DANCE_6)
#define TD_C TD(DANCE_7)
#define TD_V TD(DANCE_8)


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

// -------------------- Keymap --------------------
	
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_69_ansi(
        KC_ESC,  TD_1,	   TD_2,	 TD_3,	  TD_4,    KC_5,	KC_6,	  KC_7,    KC_8,	KC_9,	 KC_0,	   KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,	   KC_W,	 KC_E,	  KC_R,    KC_T,	KC_Y,	  KC_U,    KC_I,	KC_O,	 KC_P,	   EU_ARNG,  KC_QUOT,  KC_SLSH,          KC_DEL,
        MO(FN2), HM_A,     HM_S,     HM_D,    HM_F,    KC_G,              KC_H,    HM_J,    HM_K,    HM_L,     HM_ODIA,  EU_ADIA,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,	 TD_X,	  TD_C,    TD_V,	KC_B,	  KC_B,    KC_N,	KC_M,	 KC_COMM,  KC_DOT,	 KC_QUES,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPTN, KC_LCMMD, LT(MAC_FN1, KC_SPC), LT(FN2, KC_TAB), LT(FN2, KC_BSPC), LT(MAC_FN1, KC_ENT), KC_RCMMD,        KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_69_ansi(
        KC_ESC,  KC_1,	   KC_2,	 KC_3,	  KC_4,    KC_5,	KC_6,	  KC_7,    KC_8,	KC_9,	 KC_0,	   KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,	   KC_W,	 KC_E,	  KC_R,    KC_T,	KC_Y,	  KC_U,    KC_I,	KC_O,	 KC_P,	   EU_ARNG,  KC_QUOT,  KC_SLSH,          KC_DEL,
        MO(FN2), KC_A,	   KC_S,	 KC_D,	  KC_F,    KC_G,              KC_H,    KC_J,	KC_K,	 KC_L,	   EU_ODIA,  EU_ADIA,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,	 KC_X,	  KC_C,    KC_V,	KC_B,	  KC_B,    KC_N,	KC_M,	 KC_COMM,  KC_DOT,	 KC_QUES,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LALT,  KC_LWIN, KC_SPC, LT(FN2, KC_TAB), LT(FN2, KC_BSPC), LT(MAC_FN1, KC_ENT), KC_RALT,                       KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_FN1] = LAYOUT_69_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU, KC_MCTRL, KC_LNPAD,RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______, KC_GRAVE, KC_LABK, KC_RABK,  KC_MINUS,KC_PIPE, KC_DLR,   KC_LCBR, KC_RCBR, KC_COLN, KC_CIRC,  XXXXXXX,  XXXXXXX,  XXXXXXX,          KC_INS,
        _______, KC_EXLM,  KC_ASTR, KC_SLASH, KC_EQUAL,KC_AMPR,           KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN,  KC_DQUO,  XXXXXXX,  _______,          KC_END,
        _______,           KC_TILD, KC_PLUS,  KC_BSLS, KC_UNDS, KC_PERC,  KC_PERC, KC_AT,   KC_LBRC, KC_RBRC,  KC_DOT,   KC_QUOT,  _______, KC_PGUP,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            KC_HOME, KC_PGDN, KC_END),

    [WIN_FN1] = LAYOUT_69_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______, KC_GRAVE, KC_LABK, KC_RABK,  KC_MINUS,KC_PIPE, KC_DLR,   KC_LCBR, KC_RCBR, KC_COLN, KC_CIRC,  XXXXXXX,  XXXXXXX,  XXXXXXX,          KC_INS,
        _______, KC_EXLM,  KC_ASTR, KC_SLASH, KC_EQUAL,KC_AMPR,           KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN,  KC_DQUO,  XXXXXXX,  _______,          KC_END,
        _______,           KC_TILD, KC_PLUS,  KC_BSLS, KC_UNDS, KC_PERC,  KC_PERC, KC_AT,   KC_LBRC, KC_RBRC,  KC_DOT,   KC_QUOT,  _______, KC_PGUP,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            KC_HOME, KC_PGDN, KC_END),

    [FN2] = LAYOUT_69_ansi(
        KC_TILD, KC_F1,    KC_F2,	 KC_F3,   KC_F4,   KC_F5,	KC_F6,	  KC_F7,   KC_F8,	KC_F9,	 KC_F10,   KC_F11,	 KC_F12,   _______,          _______,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        KC_MUTE, KC_VOLD,  KC_VOLU,  KC_MPRV, KC_MPLY, KC_MNXT,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, RGB_VAI,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            RGB_MOD, RGB_VAD, RGB_HUI)
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
