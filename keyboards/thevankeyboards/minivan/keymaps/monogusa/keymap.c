#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _qwerty_ 0
#define _eucalyn_ 1
#define _num_ 3
#define _func_ 4

// Macro name shortcuts
#define QWERTY M(_qwerty_)
#define EUCALYN M(_eucalyn_)

// Fillers to make layering more clear
#define ___ KC_NO
#define _o_ KC_TRNS


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_qwerty_] = LAYOUT( /* Qwerty */
    KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T,   KC_Y,      KC_U, KC_I,    KC_O,     KC_P,     KC_BSLS,
    KC_LCTL, KC_A,    KC_S,    KC_D, KC_F, KC_G,   KC_H,      KC_J, KC_K,    KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B,   KC_N,      KC_M, KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LGUI, KC_LALT, KC_LGUI,             KC_SPC, MO(_num_),                KC_LANG2, KC_LANG1, KC_RCTL
  ),

  [_eucalyn_] = LAYOUT( /* Eucalyn */
    KC_TAB,  KC_Q,    KC_W,    KC_COMM, KC_DOT, KC_SCLN, KC_M,      KC_R, KC_D, KC_Y,     KC_P,     KC_BSLS,
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_I,   KC_U,    KC_G,      KC_T, KC_N, KC_S,     KC_B,     KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_F,    KC_H,      KC_J, KC_K, KC_L,     KC_SLSH,  KC_RSFT,
    KC_LGUI, KC_LALT, KC_LGUI,                  KC_SPC,  MO(_num_),             KC_LANG2, KC_LANG1, KC_RCTL
  ),

  [_num_] = LAYOUT( /* Number Layer */
    KC_ESC, KC_1,    KC_2,    KC_3,     KC_4,     KC_5,       KC_6,    KC_7,    KC_8,   KC_9,     KC_0, KC_BSPC,
    _o_,    KC_LBRC, KC_RBRC, KC_EQUAL, KC_MINS,  ___,        KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, ___,  KC_ENT,
    _o_,    KC_ENT,  ___,     ___,      KC_GRAVE, ___,        KC_ENT,  KC_BSPC, KC_DEL, ___,      ___,  _o_,
    _o_,    _o_,     _o_,                         MO(_func_), ___,                      _o_,      _o_,  _o_
  ),

  [_func_] = LAYOUT( /* Function Layer */
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,   KC_F7,     KC_F8,   KC_F9,  KC_F10, KC_F11,
    _o_,    ___,   ___,   ___,   ___,   ___,   KC_HOME, KC_PGDOWN, KC_PGUP, KC_END, ___,    KC_F12,
    _o_,    ___,   ___,   ___,   ___,   ___,   ___,     QWERTY,    EUCALYN, ___,    ___,    _o_,
    _o_,    _o_,   _o_,                 ___,   ___,                         _o_,    _o_,    _o_
  )

};

const uint16_t PROGMEM fn_actions[] = {

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _eucalyn_:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_eucalyn_);
          }
          break;
        case _qwerty_:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_qwerty_);
          }
          break;
      }
    return MACRO_NONE;
};
