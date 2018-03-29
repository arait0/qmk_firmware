#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define L1 1 // layer1
#define L2 2 // layer2
#define L3 3 // layer3

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,---------------------------------------------.   ,-------------------------------------------------.
 * | ESC    |  1  |  2  |   3  |  4  |  5  |     |   | =/+ |   6  |   7   |   8  |   9  |  0  |  -/_   |
 * |--------+-----+-----+------+-----+-----------|   |-----+------+-------+------+------+-----+--------|
 * | Tab    |  Q  |  W  |   E  |  R  |  T  |     |   |  [  |   Y  |   U   |   I  |   O  |  P  |  \/|   |
 * |--------+-----+-----+------+-----+-----|     |   |     |------+-------+------+------+-----+--------|
 * | LCtrl  |  A  |  S  |   D  |  F  |  G  |-----|   |-----|   H  |   J   |   K  |   L  | ;/: |  '/"   |
 * |--------+-----+-----+------+-----+-----| ~L2 |   |  ]  |------+-------+------+------+-----+--------|
 * | LShift |  Z  |  X  |   C  |  V  |  B  |     |   |     |   N  |   M   |   ,  |   .  | //? | RShift |
 * `--------+-----+-----+------+-----+-----------'   `------------+-------+------+------+-----+--------'
 *   | LGui |     | `/~ | LAlt | Del |                            | Space | RAlt | RGui | App | RCtrl |
 *   `-------------------------------'                            `-----------------------------------'
 *                               ,---------------.   ,--------------.
 *                               |  Left | Right |   | Home | End   |
 *                       ,-------|-------|-------|   |------+-------+-----.
 *                       | Space | Back  | Up    |   | PgUp | Enter | ~L1 |
 *                       |       | space |-------|   |------|       |     |
 *                       |       |       | Down  |   | PgDn |       |     |
 *                       `-----------------------'   `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,  KC_2,     KC_3,    KC_4,      KC_5, KC_NO,
        KC_TAB,   KC_Q,  KC_W,     KC_E,    KC_R,      KC_T, KC_NO,
        KC_LCTRL, KC_A,  KC_S,     KC_D,    KC_F,      KC_G,
        KC_LSFT,  KC_Z,  KC_X,     KC_C,    KC_V,      KC_B, MO(L2),
        KC_LGUI,  KC_NO, KC_GRAVE, KC_LALT, KC_DELETE,
                                            KC_LEFT,   KC_RIGHT,
                                                       KC_UP,
                                  KC_SPACE, KC_BSPACE, KC_DOWN,
        // right hand
        KC_EQUAL,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,      KC_MINS,
        KC_LBRACKET, KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,      KC_BSLASH,
                     KC_H,     KC_J,     KC_K,    KC_L,    KC_SCOLON, KC_QUOTE,
        KC_RBRACKET, KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,
                               KC_SPACE, KC_RALT, KC_RGUI, KC_APP,    KC_RCTRL,
        KC_HOME,     KC_END,
        KC_PGUP,
        KC_PGDOWN,   KC_ENTER, MO(L1)
),
/* Keymap 1:
 *
 * ,---------------------------------------------.    ,---------------------------------------------------.
 * | `/~ |  F1  |  F2  |  F3  |  F4  |  F5  |    |    | NumLk |   F6  |   F7 |   F8 |   F9  |   F10 | F11 |
 * |-----+------+------+------+------+------+----|    |-------+-------+------+------+-------+-------+-----|
 * |  œ |      |      |      |      |      |    |    | PrtSc |  Esc  | Back | Del  | RAlt  | RCtrl | F12 |
 * |-----+------+------+------+------+------|    |    |       +-------+------+------+-------+-------+-----|
 * |  œ |      |      |      |      |      |----|    |-------| Left  | Down | Up   | Right |       |     |
 * |-----+------+------+------+------+------| œ |    | Ins   +-------+------+------+-------+-------+-----|
 * |  œ |      |      |      |      |      |    |    |       | Space |      |  `/~ | RAlt  |       | œ  |
 * `-----+------+------+------+------+-----------'    `-------+-------+------+------+-------+-------+-----'
 *  | œ | œ   | œ   | œ   |  œ  |                                |  œ  |  œ  |  œ   |  œ   | œ |
 *  `--------------------------------'                                `----------------------------------'
 *                                      ,---------.       ,---------.
 *                                      | œ | œ |       | œ | œ |
 *                                 ,----|----|----|       |----+----+----.
 *                                 | œ | œ | œ |       | œ | œ | œ |
 *                                 |    |    |----|       |----|    |    |
 *                                 |    |    | œ |       | œ |    |    |
 *                                 `--------------'       `--------------'
 */
// MEDIA AND MOUSE
[L1] = LAYOUT_ergodox(
       // left hand
       KC_GRAVE, KC_F1,      KC_F2,    KC_F3,      KC_F4,       KC_F5, KC_NO,
       KC_TRNS,  KC_NO,      KC_NO,    KC_NO,      KC_NO,       KC_NO, KC_NO,
       KC_TRNS,  KC_MS_LEFT, KC_MS_UP, KC_MS_DOWN, KC_MS_RIGHT, KC_NO,
       KC_TRNS,  KC_NO,      KC_NO,    KC_MS_BTN1, KC_MS_BTN2,  KC_NO, KC_TRNS,
       KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,
                                                   KC_TRNS,     KC_TRNS,
                                                                KC_TRNS,
                                       KC_TRNS,    KC_TRNS,     KC_TRNS,
       // right hand
       KC_NUMLOCK, KC_F6,     KC_F7,     KC_F8,     KC_F9,    KC_F10,   KC_F11,
       KC_PSCREEN, KC_ESCAPE, KC_BSPACE, KC_DELETE, KC_RALT,  KC_RCTRL, KC_F12,
                   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT, KC_NO,    KC_NO,
       KC_INSERT,  KC_SPACE,  KC_NO,     KC_GRAVE,  KC_RALT,  KC_NO,    KC_TRNS,
                              KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,    KC_TRNS,
       KC_TRNS,
       KC_TRNS,    KC_TRNS,   KC_TRNS
),
/* Keymap 2:
 *
 * ,---------------------------------------------.   ,-----------------------------------------.
 * | `/~ |  F1  |  F2  |  F3  |  F4  |  F5  |    |   | NumLock | F6 | F7 | F8 | F9 | F10 | F11 |
 * |-----+------+------+------+------+------+----|   |---------+----+----+----+----+-----+-----|
 * |  œ |      |      |      |      |      |    |   |         |  7 |  8 |  9 |  / |     | F12 |
 * |-----+------+------+------+------+------|    |   |         +----+----+----+----+-----+-----|
 * |  œ |      |      |      |      |      |----|   |---------|  4 |  5 |  6 |  * |     |     |
 * |-----+------+------+------+------+------| œ |   |         +----+----+----+----+-----+-----|
 * |  œ |      |      |      |      |      |    |   |         |  1 |  2 |  3 |  - |     | œ  |
 * `-----+------+------+------+------+-----------'   `---------+----+----+----+----+-----+-----'
 *  | œ | œ   | œ   | œ   |  œ  |                              |  0 |  . |  + |     | œ |
 *  `--------------------------------'                              `-------------------------'
 *                                     ,---------.   ,---------.
 *                                     | œ | œ |   | œ | œ |
 *                                ,----|----|----|   |----+----+----.
 *                                | œ | œ | œ |   | œ | œ | œ |
 *                                |    |    |----|   |----|    |    |
 *                                |    |    | œ |   | œ |    |    |
 *                                `--------------'   `--------------'
 */
// SYMBOLS
[L2] = LAYOUT_ergodox(
       // left hand
       KC_GRAVE, KC_F1,      KC_F2,    KC_F3,      KC_F4,       KC_F5, KC_NO,
       KC_TRNS,  KC_NO,      KC_NO,    KC_NO,      KC_NO,       KC_NO, KC_NO,
       KC_TRNS,  KC_MS_LEFT, KC_MS_UP, KC_MS_DOWN, KC_MS_RIGHT, KC_NO,
       KC_TRNS,  KC_NO,      KC_NO,    KC_MS_BTN1, KC_MS_BTN2,  KC_NO, KC_TRNS,
       KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,
                                                   KC_TRNS,     KC_TRNS,
                                                                KC_TRNS,
                                       KC_TRNS,    KC_TRNS,     KC_TRNS,
       // right hand
       KC_NUMLOCK, KC_F6,   KC_F7,   KC_F8,     KC_F9,          KC_F10, KC_F11,
       KC_NO,      KC_KP_7, KC_KP_8, KC_KP_9,   KC_KP_SLASH,    KC_NO,  KC_F12,
                   KC_KP_4, KC_KP_5, KC_KP_6,   KC_KP_ASTERISK, KC_NO,  KC_NO,
       KC_NO,      KC_KP_1, KC_KP_2, KC_KP_3,   KC_KP_MINUS,    KC_NO,  KC_TRNS,
                            KC_KP_0, KC_KP_DOT, KC_KP_PLUS,     KC_NO,  KC_TRNS,
       KC_TRNS,    KC_TRNS,
       KC_TRNS,
       KC_TRNS,    KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(L1)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  ergodox_led_all_set(LED_BRIGHTNESS_LO);

  uint8_t layer = biton32(state);
  switch (layer) {
      case BASE:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case L1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case L2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case L3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
