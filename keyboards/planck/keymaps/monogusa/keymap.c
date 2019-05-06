#include "planck.h"
#include "action_layer.h"

#define _qwerty_  0  // Qwerty
#define _eucalyn_ 1  // Eucalyn
#define _num_     2  // Number Layer
#define _func_    3  // Function Layer

#define ___ KC_NO
#define _o_ KC_TRNS

// Macro name shortcuts
#define NUM MO(_num_)
#define QWERTY M(_qwerty_)
#define EUCALYN M(_eucalyn_)


extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty Layer
 * ,-------------------------------------------------------------------------------------,
 * | Tab    | Q    | W    | E   | R   | T   | Y     | U    | I    | O    |  P   |  \/|   |
 * |--------+------+------+-----+-----+-----|-------+------+------+------+------+--------|
 * | LCtrl  | A    | S    | D   | F   | G   | H     | J    | K    | L    | ;/:  |  '/"   |
 * |--------+------+------+-----+-----+-----|-------+------+------+------+------+--------|
 * | LShift | Z    | X    | C   | V   | B   | N     | M    | ,    | .    | //?  | RShift |
 * |--------+------+------+-----+-----+-------------+------+------+------+------+--------|
 * | LGui   | LAlt | LGui | DEL | SPC | BS  | Enter | NUM  | RGUI | RAlt | ESC  | RCtrl  |
 * `-------------------------------------------------------------------------------------'
 */
[_qwerty_] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,    KC_Y,   KC_U, KC_I,    KC_O,    KC_P,    KC_BSLS},
  {KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,    KC_H,   KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LGUI, KC_LALT, KC_LGUI, KC_DEL, KC_SPC, KC_BSPC, KC_ENT, NUM,  KC_LGUI, KC_RALT, KC_ESC,  KC_RCTL}
},

/* Eucalyn Layer
 * ,-----------------------------------------------------------------------------------,
 * | Tab    | Q    | W    | ,   | .   | ;/: | M     | R   | D    | Y    |  P  | \/|    |
 * |--------+------+------+-----+-----+-----|-------+-----+------+------+-----+--------|
 * | LCtrl  | A    | O    | E   | I   | U   | G     | T   | N    | S    |  B  | '/"    |
 * |--------+------+------+-----+-----+-----|-------+-----+------+------+-----+--------|
 * | LShift | Z    | X    | C   | V   | F   | H     | J   | K    | L    | //? | RShift |
 * |--------+------+------+-----+-----+-------------+-----+------+------+-----+--------|
 * | LGui   | LAlt | LGui | DEL | SPC | BS  | Enter | NUM | RGUI | RAlt | ESC | RCtrl  |
 * `-----------------------------------------------------------------------------------'
 */
[_eucalyn_] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_COMM, KC_DOT, KC_SCLN, KC_M,   KC_R, KC_D,    KC_Y,    KC_P,    KC_BSLS},
  {KC_LCTL, KC_A,    KC_O,    KC_E,    KC_I,   KC_U,    KC_G,   KC_T, KC_N,    KC_S,    KC_B,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_F,    KC_H,   KC_J, KC_K,    KC_L,    KC_SLSH, KC_RSFT},
  {KC_LGUI, KC_LALT, KC_LGUI, KC_DEL,  KC_SPC, KC_BSPC, KC_ENT, NUM,  KC_LGUI, KC_RALT, KC_ESC, KC_RCTL}
},

/* Number Layer
 * ,----------------------------------------------------------------------------------------.
 * | ESC   | 1    | 2    | 3    | 4    | 5    | 6    | 7     | 8     | 9     | 0    |       |
 * |-------+------+------+------+------+------|------+-------+-------+-------+------+-------|
 * | *     | [    | ]    | =/+  | -/_  | HOME | Left | Down  | Up    | Right | PgUp |       |
 * |-------+------+------+------+------+------|------+-------+-------+-------+------+-------|
 * | *     | DEL  | BS   |      | `/~  | END  |      | Enter | LANG2 | LANG1 | PgDn | *     |
 * |-------+------+------+------+------+-------------+-------+-------+-------+------+-------|
 * | *     | *    | *    | *    | FUNC |      |      |       | *     | *     | *    | *     |
 * `----------------------------------------------------------------------------------------'
 */
[_num_] = {
  {KC_ESC, KC_1,    KC_2,    KC_3,   KC_4,       KC_5,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0,      ___},
  {_o_,    KC_LBRC, KC_RBRC, KC_EQL, KC_MINS,    KC_HOME, KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT, KC_PGUP,   ___},
  {_o_,    KC_DEL,  KC_BSPC, ___,    KC_GRV,     KC_END,  ___,     KC_ENT,  KC_LANG2, KC_LANG1, KC_PGDOWN, _o_},
  {_o_,    _o_,     _o_,     _o_,    MO(_func_), ___,     ___,     ___,     _o_,      _o_,      _o_,       _o_}
},

/* Function Layer
 * ,------------------------------------------------------------------------------------------.
 * | ESC  | F1   | F2   | F3   | F4   | F5   | F6   | F7     | F8      | F9   | F10  | F11    |
 * |------+------+------+------+------+------|------+--------+---------+------+------+--------|
 * | *    |      |      |      |      |      |      |        |         |      |      | F12    |
 * |------+------+------+------+------+------|------+--------+---------+------+------+--------|
 * | *    |      |      |      |      |      |      | Qwerty | Eucalyn |      |      | *      |
 * |------+------+------+------+------+-------------+--------+---------+------+------+--------|
 * |      | *    | *    |      |      |      |      |        |         |      |      | *      |
 * `------------------------------------------------------------------------------------------'
 */
[_func_] = {
  {KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7,  KC_F8,   KC_F9, KC_F10, KC_F11},
  {_o_,    ___,   ___,   ___,   ___,   ___,   ___,   ___,    ___,     ___,   ___,    KC_F12},
  {_o_,    ___,   ___,   ___,   ___,   ___,   ___,   QWERTY, EUCALYN, ___,   ___,    _o_},
  {___,    _o_,   _o_,   ___,   ___,   ___,   ___,   ___,    ___,     ___,   ___,    _o_}
},

};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _qwerty_:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_qwerty_);
          }
          break;
        case _eucalyn_:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_eucalyn_);
          }
          break;
      }
    return MACRO_NONE;
};
