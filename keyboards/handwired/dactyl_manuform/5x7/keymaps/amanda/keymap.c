// NOTE: to compile the keymap run:
// `qmk compile -kb handwired/dactyl_manuform/5x7 -km amanda -e CONVERT_TO=rp2040_ce`
// This will generate a .uf2 file in the .build directory at the top level where the repo is cloned.
// To flash the remaps, enter boot mode on the keyboard, then copy the .uf2 file to the keyboard's microcontroller after it pops up as an ejectable device.
//
// Run `nix-shell -p qmk --command fish` to enter a dev shell with qmk installed and our fish shell config loaded so that we have our usual shortcuts and aliases available.
//
// TODO:
// - I want something better for hitting esc, I don't think I like having it on my thumb here.
// - I want to explore using leader.
// - Interesting to see if we can do all of the number keys on layer X,
//  but they are one row lower. Could keep the symbols there too, on layer X + 1 or something.
//
//  - Combos:
//      https://docs.qmk.fm/#/feature_combo

#include <stdint.h>

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
// #define _QWERTY 0
// #define _VIMNAV 1
// #define _POG    2
// #define _FN     3
// #define _NUMPAD 4
// #define _GAMING 5
#define _QWERTY 0
#define _POG    1
#define _FN     2
#define _NUMPAD 3
#define _GAMING 4

// Some basic macros
#define TASK    LCTL(LSFT(KC_ESC))
#define TAB_R   LCTL(KC_TAB)
#define TAB_L   LCTL(LSFT(KC_TAB))
#define TAB_RO  LCTL(LSFT(KC_T))

#define MOD_CSHF MOD_LCTL | MOD_LSFT
#define MOD_CA MOD_LCTL | MOD_LALT
// #define MOD_OVERRIDE (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))

// const key_override_t plus_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_PLUS, KC_1, (1 << _QWERTY));
// const key_override_t n2_key_override =   ko_make_with_layers(MOD_MASK_SHIFT, KC_LBRC, KC_2, (1 << _QWERTY));
// const key_override_t n3_key_override =   ko_make_with_layers(MOD_MASK_SHIFT, KC_LCBR, KC_3, (1 << _QWERTY));
// const key_override_t n4_key_override =   ko_make_with_layers(MOD_MASK_SHIFT, KC_LPRN, KC_4, (1 << _QWERTY));
// const key_override_t n5_key_override =   ko_make_with_layers(MOD_MASK_SHIFT, KC_AMPR, KC_5, (1 << _QWERTY));
// const key_override_t eq_key_override =   ko_make_with_layers(MOD_MASK_SHIFT, KC_EQUAL, KC_6, (1 << _QWERTY));
// const key_override_t n7_key_override =   ko_make_with_layers(MOD_MASK_SHIFT, KC_RPRN, KC_7, (1 << _QWERTY));
// const key_override_t n8_key_override =   ko_make_with_layers(MOD_MASK_SHIFT, KC_RCBR, KC_8, (1 << _QWERTY));
// const key_override_t n9_key_override =   ko_make_with_layers(MOD_MASK_SHIFT, KC_RBRC, KC_9, (1 << _QWERTY));
// const key_override_t n0_key_override =   ko_make_with_layers(MOD_MASK_SHIFT, KC_ASTR, KC_0, (1 << _QWERTY));
// const key_override_t exclam_prcnt_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_EXCLAIM, KC_PERC, ((1 << _QWERTY) | (1 << _VIMNAV)));
// const key_override_t dollar_grave_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOLLAR, KC_GRAVE, ((1 << _QWERTY) | (1 << _VIMNAV)));
// const key_override_t BSLS_hash_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSLS, KC_HASH, ((1 << _QWERTY) | (1 << _VIMNAV)));
// const key_override_t at_carat_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_AT, KC_CIRC, ((1 << _QWERTY) | (1 << _VIMNAV)));
// const key_override_t at_carat_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_AT, KC_CIRC, (1 << _QWERTY));

// This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//     &plus_key_override,
//     &n2_key_override,
//     &n3_key_override,
//     &n4_key_override,
//     &n5_key_override,
//     &eq_key_override,
//     &n7_key_override,
//     &n8_key_override,
//     &n9_key_override,
//     &n0_key_override,
//     &exclam_prcnt_override,
//     &dollar_grave_override,
//     &BSLS_hash_override,
//     &at_carat_override,
//     NULL // Null terminate the array of overrides!
// };


enum custom_keycodes {
    S_TRUE = SAFE_RANGE,
    S_FALSE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // TODO: Can I be holding down shift and check if that's what I'm pressing right now as well...
    switch (keycode) {
    case S_TRUE:
        if (record->event.pressed) {
            SEND_STRING("true");
        }
        break;
    case S_FALSE:
        if (record->event.pressed) {
            SEND_STRING("false");
        }
        break;
    }

    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// [1] |^| |^|
// [2] |3| |5|
//     [4] [6]

/*
 *  Old Colemak layout:
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   |    |  +/1  | [/2 | {/3  | (/4  |  &/5 | Reset|           |      | =/6  | )/7  | }/8  | }/9  | ast/0|  !/%   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  | W    |   F  |   P  |   B  | Home |           | End  |   J  |   L  |   U  |   Y  |   -  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   R  |   S  | T/Alt|   G  |------|           |------|   M  | N/Alt| E/POG|   I  |   O  | ;/POG  |
 * |--------+------+------+------+------+------|  '"  |           | FN   |------+------+------+------+------+--------|
 * | LShift | Z:CS | X:POG|   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |//LGUI| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |NUMPAD|  $   | Left | Right|      |                                       |      | Up   | Down |  @/^ |   POG  |
 *   `----------------------------------'                                       `------------------------------------'
 *
 *                                .--------------------.         .-------------------------.
 *                                | BSPC | LCTRL| POG  |         |   LCTRL   | ENTER| SPC  |  -- (1, 3, 5)
 *                                |------|------|------|         |-----------|------|------|
 *                                | Vim  |LShift| RWIN |         | LAlt/Caps | POG  | LGUI |  -- (2, 4, 6)
 *                                ----------------------         ---------------------------*
 *
 *  Current Qwerty layout:
 * ,---------------------------------------------------------.          ,--------------------------------------------------.
 * |   Esc  |    1    |    2     |   3  |   4  |   5  | Reset|          |      |   6  |   7  |   8  |   9  |   0  |    -   |
 * |--------+---------+----------+------+------+------+------|          |------+------+------+------+------+------+--------|
 * |  Del   |   Q     |    W     |   E  |   R  |   T  |   [  |          |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+---------+----------+------+------+------|      |          |      |------+------+------+------+------+--------|
 * |    `   |   A     |    S     |   D  | F/Alt|   G  |------|          |------|   H  | J/Alt| K/POG|   L  |   ;  | '"/POG |
 * |--------+---------+----------+------+------+------|  INS |          | FN   |------+------+------+------+------+--------|
 * | LShift | Z:LCTRL |  X:M_CS  |   C  |   V  |   B  |      |          |      |   M  |   N  |   ,  |   .  |//LGUI| RShift |
 * `--------+---------|----------+------+------+------+------'          `-------------+------+------+------+------+--------'
 *   |NUMPAD|  $   | Left | Right|      |                                       |      | Up   | Down |  M_CA |   POG  |
 *   `----------------------------------'                                       `------------------------------------'
 *
 *                                .--------------------.         .-------------------------.
 *                                | BSPC | LCTRL| POG  |         |   LCTRL   | ENTER| SPC  |  -- (1, 3, 5)
 *                                |------|------|------|         |-----------|------|------|
 *                                | Tab  |LShift| RWIN |         | LAlt/Caps | POG  | LGUI |  -- (2, 4, 6)
 *                                ----------------------         ---------------------------
 *
 *
 */
[_QWERTY] = LAYOUT_5x7(
   // left hand
   // KC_PIPE,                KC_PLUS,               KC_LBRC,                 KC_LCBR,    KC_LPRN,              KC_AMPR,   XXXXXXX,
   KC_ESC,                 KC_1,                  KC_2,                    KC_3,       KC_4,                 KC_5,      XXXXXXX,
   KC_DEL,                 KC_Q,                  KC_W,                    KC_E,       KC_R,                 KC_T,      KC_LBRC,
   KC_GRV,                 KC_A,                  KC_S,                    KC_D,       MT(MOD_LALT, KC_F),   KC_G,      KC_INS,
   OSM(MOD_LSFT),          MT(MOD_LCTL, KC_Z),    MT(MOD_CSHF, KC_X),      KC_C,       KC_V,                 KC_B,
   TT(_NUMPAD),            KC_LGUI,               KC_LEFT,                 KC_RGHT,

                           KC_TAB, KC_BSPC,          // 2, 1
                           OSM(MOD_LSFT), KC_LCTL,   // 4, 3
                           KC_RWIN, TT(_POG),        // 6, 5
    // right hand
    // TG(_GAMING),           KC_EQUAL, KC_RPRN,            KC_RCBR,            KC_RBRC,   KC_ASTR,               KC_EXCLAIM,
    TG(_GAMING),           KC_6,     KC_7,               KC_8,               KC_9,      KC_0,                  KC_MINUS,
    KC_RBRC,               KC_Y,     KC_U,               KC_I,               KC_O,      KC_P,                  KC_BSLS,
    TT(_FN),               KC_H,     MT(MOD_LALT, KC_J), LT(_POG, KC_K),     KC_L,      KC_SCLN,               KC_QUOT,
                           KC_M,     KC_N,               KC_COMM,            KC_DOT,    MT(MOD_LGUI, KC_SLSH), OSM(MOD_RSFT),
                                                         KC_UP,              KC_DOWN,   MT(MOD_CA, KC_PLUS),                 MO(_POG), // 1  , 2
                           KC_SPC, KC_LGUI,                   // 2, 1
                           KC_ENT, MO(_POG),                  // 4, 3
                           KC_LCTL, MT(MOD_LALT, KC_CAPS)),   // 6, 5
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |false |      |   {  |   }  |      |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |true  |   =  |   (  |   )  |   &  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   _  |   [  |   ]  |      |      |           |      |   ,  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// [_VIMNAV] = LAYOUT_5x7(
//   // left hand
//    _______,   KC_1,      KC_2,      KC_3,     KC_4,      KC_5,     _______,
//    _______,   _______,   _______,   _______,  _______,   _______,  _______,
//    _______,   _______ ,  _______,   _______,  _______,   _______,  _______,
//    _______,   _______,   _______,   _______,  _______,   _______,
//    _______,   _______,   _______,   _______,
//                                _______, _______,
//                                _______, _______,
//                                _______, _______,
//    // right hand
//                 _______,   KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      _______,
//                 _______,   KC_TILDE,  _______,   _______,   _______,   _______,   _______,
//                 _______,   KC_H,      KC_J,      KC_K,      KC_L,      _______,   _______,
//                            _______,   _______,   _______,   _______,   _______,   _______,
//                                                  _______,   _______,   _______,   _______,
//    _______, _______,
//    _______, _______,
//    _______, _______),

[_POG] = LAYOUT_5x7(
  // left hand
   _______,   KC_F1,     KC_F2,     KC_F3,    KC_F4,     KC_F5,    _______,
   _______,   S_FALSE,   KC_NUM,    KC_LCBR,  KC_RCBR,   KC_INS,   _______,
   _______,   S_TRUE ,   KC_EQL ,   KC_LPRN,  KC_RPRN,   KC_DEL,   _______,
   _______,   _______,   KC_UNDS,   KC_LBRC,  KC_RBRC,   KC_AMPR,
   KC_MSTP,   KC_MPLY,   KC_MPRV,   KC_MNXT,
                               _______, _______,
                               _______, _______,
                               _______, _______,
   // right hand
                _______,   KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,
                _______,   _______,   _______,   _______,   _______,   _______,   _______,
                _______,   _______,   _______,   _______,   _______,   _______,   _______,
                           _______,   _______,   _______,   _______,   _______,   _______,
                                                 _______,   _______,   _______,   _______,
   _______, _______,
   _______, _______,
   _______, _______),

[_FN] = LAYOUT_5x7(
  // left hand
   _______,   KC_F1,     KC_F2,      KC_F3,    KC_F4,     KC_F5,    QK_BOOT,
   _______,   _______,   _______,    KC_UP,    _______,   KC_PGUP,  _______,
   _______,   _______,   KC_LEFT,    KC_DOWN,  KC_RGHT,   KC_PGDN,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,
   KC_MSTP,   KC_MPLY,   KC_MPRV,   KC_MNXT,
                               _______, _______,
                               _______, _______,
                               _______, _______,
   // right hand
                _______,   KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,
                _______,   _______,   _______,   _______,   _______,   _______,   _______,
                _______,   _______,   _______,   _______,   _______,   _______,   _______,
                           _______,   _______,   _______,   _______,   _______,   _______,
                                                 _______,   _______,   _______,   _______,
   _______, _______,
   _______, _______,
   _______, _______),

[_GAMING] = LAYOUT_5x7(
   // left hand
   KC_ESC,          KC_1,                  KC_1,                  KC_2,   KC_3,                 KC_4,   KC_5,
   KC_TAB,          KC_TAB,                KC_Q,                  KC_W,   KC_E,                 KC_R,   KC_T,
   KC_CAPS,         OSM(MOD_LSFT),         KC_A,                  KC_S,   KC_D,                 KC_F,   KC_G,
   KC_LCTL,         KC_Z,                  KC_X,                  KC_C,   KC_V,                 KC_B,
   KC_Z,            KC_LGUI,               KC_LEFT,               KC_RGHT,
                           // 2   , 1
                           KC_LALT, KC_SPC,
                           // 4  , 3
                           KC_LCTL, KC_LALT,
                           // 6, 5
                           KC_RWIN, KC_G,
   // right hand

                _______,   _______,   _______,   _______,   _______,   _______,   _______,
                _______,   _______,   _______,   _______,   _______,   _______,   _______,
                _______,   _______,   _______,   _______,   _______,   _______,   _______,
                           _______,   _______,   _______,   _______,   _______,   _______,
                                                 _______,   _______,   _______,   _______,
   _______, _______,
   _______, _______,
   _______, _______),

[_NUMPAD] = LAYOUT_5x7(
  // left hand
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,
   _______,   _______,   _______,   _______,
                               _______, _______,
                               _______, _______,
                               _______, _______,
   // right hand
                _______,   _______,   KC_NUM,   _______,    KC_PMNS,   KC_PPLS,   _______,
                _______,   _______,   KC_P7,     KC_P8,     KC_P9,     _______,   _______,
                _______,   _______,   KC_P4,     KC_P5,     KC_P6,     KC_PAST,   _______,
                           KC_COMM,   KC_P1,     KC_P2,     KC_P3,     KC_PSLS,   _______,
                                                 KC_P0,     KC_PDOT,   _______,   _______,
   _______, _______,
   _______, _______,
   _______, _______),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |false | NUM  |   {  |   }  |      |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |true  |   =  |   (  |   )  |   &  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   _  |   [  |   ]  |      |      |           |      |   ,  |   1  |   2  |   3  |   -  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |   0  |   .  |   /  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

};
