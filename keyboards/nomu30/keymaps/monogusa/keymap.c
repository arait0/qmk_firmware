#include QMK_KEYBOARD_H

#define _BASE 0
#define _NUMS 1
#define _SYMS 2
#define _FUNC 3

#define _QWERTY 0
#define _L1 1
#define _L2 2
#define _L3 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  L1,
  L2,
  L3,
};

#define ___ KC_NO
#define _o_ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RCTL,
        ___, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_RSFT,
        ___, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, L1
    ),
    [_L1] = LAYOUT(
        KC_ESC, KC_TAB, ___, ___, ___, ___, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_BSPC,
        ___, KC_COLN, KC_DQUO, KC_COMM, KC_SLSH, KC_BSLS, KC_RALT, KC_RGUI, KC_RSFT, KC_RCTL, KC_ENT,
        ___, KC_SCLN, KC_QUOT, KC_DOT, KC_SPC, ___, ___, L2, ___
    ),
    [_L2] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_F12, ___, KC_RALT, KC_RGUI, KC_RCTL, L3,
        ___, KC_6, KC_7, KC_8, KC_9, KC_0, ___, ___, KC_LANG2, KC_LANG1, KC_RSFT,
        ___, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL, KC_GRV, ___, ___, ___
    ),
    [_L3] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, ___, ___, ___, ___, ___, ___,
        ___, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, ___, ___, ___, ___, ___,
        ___, RESET, ___, ___, KC_F11, KC_F12, ___, ___, ___
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case L1:
      if (record->event.pressed) {
        layer_on(_L1);
      } else {
        layer_off(_L1);
      }
      return false;
      break;
    case L2:
      if (record->event.pressed) {
        layer_on(_L2);
      } else {
        layer_off(_L2);
      }
      return false;
      break;
    case L3:
      if (record->event.pressed) {
        layer_on(_L3);
      } else {
        layer_off(_L3);
      }
      return false;
      break;
  }
  return true;
}
