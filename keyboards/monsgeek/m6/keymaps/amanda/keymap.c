/* Copyright (C) 2023 jonylee@hfd
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

enum __layers {
    _QWERTY,
    _POG,
    _FN,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define MOD_CSHF MOD_LCTL | MOD_LSFT
#define MOD_CA MOD_LCTL | MOD_LALT
#define MOD_SUPCSH MOD_LGUI | MOD_LCTL | MOD_LSFT

// Tap Dance declarations
// enum {
//     TD_ESC_CAPS_WORD,
// };

// Tap Dance definitions
// void esc_capsword_finished(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1)
//         tap_code(KC_ESC);
//     else if (state->count == 2)
//         tap_code16(CW_TOGG);
// }
//
// void esc_capsword_reset(tap_dance_state_t *state, void *user_data) {}
//
// tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Escape, twice for Caps Lock
//     [TD_ESC_CAPS_WORD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_capsword_finished, esc_capsword_reset), // ACTION_TAP_DANCE_DOUBLE(KC_ESC, CW_TOGG),
// };

// void keyboard_post_init_user(void) {
//     // Disable all RGB matrix effects and turn all LEDs off
//     rgb_matrix_disable_noeeprom();
// }

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     if (host_keyboard_led_state().caps_lock) {
//         RGB_MATRIX_INDICATOR_SET_COLOR(60, 255, 255, 255); // assuming caps lock is at led #5
//     } else {
//         RGB_MATRIX_INDICATOR_SET_COLOR(60, 0, 0, 0);
//     }
//     return false;
// }

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     // Turn off all LEDs for this frame
//     for (uint8_t i = led_min; i < led_max; i++) {
//         rgb_matrix_set_color(i, 0, 0, 0);
//     }
//
//     // Light up Caps Lock LED if active
//     if (host_keyboard_led_state().caps_lock) {
//         const uint8_t caps_led = 60; // your Caps Lock LED index
//         rgb_matrix_set_color(caps_led, 255, 255, 255); // white
//     }
//
//     return false; // prevents default RGB effects
// }

// void keyboard_post_init_user(void) {
//     rgb_matrix_disable();
// }

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT( /* Base */
        KC_GRV,        KC_1,             KC_2,               KC_3,               KC_4,               KC_5, KC_6, KC_7,               KC_8,    KC_9,  KC_0,    KC_MINS,               KC_EQL,  KC_BSPC,                KC_DEL,
        LT(_POG,       KC_TAB),          KC_Q,               KC_W,               KC_E,               KC_R, KC_T, KC_Y,               KC_U,    KC_I,  KC_O,    KC_P,                  KC_LBRC, KC_RBRC,       KC_BSLS, KC_PGUP,
        KC_ESC,        MT(MOD_CA, KC_A), KC_S,               KC_D,               MT(MOD_LALT, KC_F), KC_G, KC_H, MT(MOD_LALT, KC_J), LT(_POG, KC_K), KC_L,    MT(MOD_LGUI, KC_SCLN), KC_QUOT, KC_NUHS,       KC_ENT,  KC_PGDN,
        OSM(MOD_LSFT), KC_NUBS,          MT(MOD_LCTL, KC_Z), MT(MOD_CSHF, KC_X), KC_C,               KC_V, KC_B, KC_B,               KC_N,    KC_M,  KC_COMM, KC_DOT,                KC_SLSH, OSM(MOD_RSFT), KC_UP,
        MT(MOD_SUPCSH, KC_CAPS), KC_LALT, OSM(MOD_LSFT), KC_LCTL,                                                KC_SPC, KC_RWIN, TT(_FN), KC_LEFT, KC_DOWN, KC_RGHT),

    [_POG] = LAYOUT( /* Base */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_INS,
        _______, _______, KC_PLUS, KC_LCBR, KC_RCBR, KC_HOME, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        CW_TOGG, _______, KC_EQL, KC_LPRN, KC_RPRN, KC_END,  _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, KC_UNDS, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,                   _______, _______,          _______, _______,                  _______, _______,           _______,    _______,    _______),

    [_FN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,   _______,           QK_BOOT,
        _______, _______, MS_WHLD, MS_UP,   MS_WHLU, _______, _______, _______, _______,  _______, KC_PSCR, _______, _______, _______,          _______,
        _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______,           _______,
        _______, _______, _______, _______, MS_BTN1, MS_BTN2, MS_BTN3,  _______, KC_MUTE, KC_VOLD, KC_VOLU,  _______, _______, _______,  _______,
        _______,                   _______, _______,          _______, _______,                  _______, _______,           _______,  _______, _______),

    // [MAC_B] = LAYOUT( /* Base */
    //     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,KC_EQL,   KC_BSPC,          KC_HOME,
    //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,KC_RBRC,  KC_BSLS,          KC_PGUP,
    //     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,KC_NUHS,  KC_ENT,           KC_PGDN,
    //     KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT, KC_UP,
    //     KC_LCTL,                   KC_LGUI, KC_SPC,           KC_LALT, KC_SPC,                    KC_RGUI, MO(WIN_FN),       KC_LEFT, KC_DOWN, KC_RGHT),
    //
    // [MAC_W] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_W,
    //     _______, _______, _______,                   _______,                            _______, _______, _______,          KC_A,    KC_S,    KC_D),
    //
    // [MAC_FN] = LAYOUT( /* FN */
    //     KC_GRV,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_F5,   KC_F6,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,KC_VOLU,  _______,           RM_NEXT,
    //     _______, _______,TG(MAC_W),_______, _______, _______, _______, _______, KC_INS,  DF(WIN_B),KC_PSCR,_______, _______, _______,           KC_HOME,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_TOGG, RM_SPDD, RM_SPDU, _______, RM_HUEU,           KC_END,
    //     _______, _______, _______, _______, KC_CALC, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,  RM_VALU,
    //     _______,                   _______, _______,          _______, _______,                  _______, _______,           RM_SATD,  RM_VALD, RM_SATU),
};

