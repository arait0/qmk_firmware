#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LAYER1 1
#define _LAYER2 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LAYER1,
  LAYER2,
};

#define KC_QWERTY QWERTY
#define KC_L1 LAYER1
#define KC_L2 LAYER2

#define KC____ KC_NO
#define KC__o_ KC_TRNS
#define KC_RESET RESET


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-------------------------------------------, ,------------------------------------------,
 * | Tab    | Q    | W    | E    | R    | T    | | Y     | U  | I    | O    |  P   |  \/|   |
 * |--------+------+------+------+------+------| |-------+----+------+------+------+--------|
 * | LCtrl  | A    | S    | D    | F    | G    | | H     | J  | K    | L    | ;/:  |  '/"   |
 * |--------+------+------+------+------+------| |-------+----+------+------+------+--------|
 * | LShift | Z    | X    | C    | V    | B    | | N     | M  | ,    | .    | //?  | RShift |
 * '----------------------+------+------+------' '-------+----+-----------------------------'
 *                        | LAlt | LGui | SPC  | | Enter | L1 | BSPC |
 *                        '--------------------' '-------------------'
 */
  [_QWERTY] = LAYOUT_kc( \
    TAB,  Q, W, E,    R,    T,      Y,   U,  I,    O,   P,     BSLS,\
    LCTL, A, S, D,    F,    G,      H,   J,  K,    L,   SCLN,  QUOT,\
    LSFT, Z, X, C,    V,    B,      N,   M,  COMM, DOT, SLSH,  RSFT,\
                LALT, LGUI, SPC,    ENT, L1, BSPC \
  ),

/* LAYER1
 * ,--------------------------, ,-------------------------------------------.
 * | ESC | 1 | 2 | 3 | 4 | 5  | | 6    | 7    | 8     | 9     | 0    | BSPC |
 * |-----+---+---+---+---+----| |------+------+-------+-------+------+------|
 * | *   | ` | [ | ] | - | =  | | Left | Down | Up    | Right |      | DEL  |
 * |-----+---+---+---+---+----| |------+------+-------+-------+------+------|
 * | *   |   |   |   |   |    | |      |      | LANG2 | LANG1 |      | *    |
 * '-------------+---+---+----| |------+------+-------+---------------------'
 *               | * | * | L2 | |      |      |       |
 *               '------------' '---------------------'
 */
  [_LAYER1] = LAYOUT_kc( \
    ESC, 1,   2,    3,    4,    5,     6,    7,    8,     9,     0,   BSPC,\
    _o_, GRV, LBRC, RBRC, MINS, EQL,   LEFT, DOWN, UP,    RIGHT, ___, DEL,\
    _o_, ___, ___,  ___,  ___,  ___,   ___,  ___,  LANG2, LANG1, ___, _o_,\
                    _o_,  _o_,  L2,    ___,  ___,  ___ \
  ),

/* LAYER2
 * ,--------------------------------------------------, ,----------------------------------------.
 * | ESC  | F1      | F2      | F3    | F4       | F5 | | F6   | F7     | F8   | F9  | F10 | F11 |
 * |------+---------+---------+-------+----------+----| |------+--------+------+-----+-----+-----|
 * | *    | MS_LEFT | MS_DOWN | MS_UP | MS_RIGHT |    | | HOME | PGDOWN | PGUP | END |     | F12 |
 * |------+---------+---------+-------+----------+----| |------+--------+------+-----+-----+-----|
 * | *    |         |         | BTN1  | BTN2     |    | |      |        |      |     |     | *   |
 * '--------------------------+-------+----------+----| |------+--------+------+-----------------'
 *                            | RESET | *        |    | |      |        | *    |
 *                            '-----------------------' '----------------------'
 */
  [_LAYER2] = LAYOUT_kc( \
    ESC, F1,   F2,   F3,    F4,   F5,     F6,   F7,     F8,   F9,  F10, F11,\
    _o_, MS_L, MS_D, MS_U,  MS_R, ___,    HOME, PGDOWN, PGUP, END, ___, F12,\
    _o_, ___,  ___,  BTN1,  BTN2, ___,    ___,  ___,    ___,  ___, ___, _o_,\
                     RESET, ___,  ___,    ___,  ___,    _o_ \
 )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LAYER1:
      if (record->event.pressed) {
        layer_on(_LAYER1);
      } else {
        layer_off(_LAYER1);
      }
      return false;
      break;
    case LAYER2:
      if (record->event.pressed) {
        layer_on(_LAYER2);
      } else {
        layer_off(_LAYER2);
      }
      return false;
      break;
  }
  return true;
}
