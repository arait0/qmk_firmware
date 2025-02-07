#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define L1 1 // layer1
#define L2 2 // layer2

#define KC____ KC_NO
#define KC__o_ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------. ,-----------------------------------------.
 * | ESC    |   |   |      |      |   |   | |   |     |     |   |     |      |        |
 * |--------+---+---+------+------+-------| |---+-----+-----+---+-----+------+--------|
 * | Tab    | Q | W |   E  |  R   | T |   | |   |  Y  |  U  | I |  O  |  P   |   \    |
 * |--------+---+---+------+------+---|   | |   |-----+-----+---+-----+------+--------|
 * | LCtrl  | A | S |   D  |  F   | G |---| |---|  H  |  J  | K |  L  |  ;   |   "    |
 * |--------+---+---+------+------+---|   | |   |-----+-----+---+-----+------+--------|
 * | LShift | Z | X |   C  |  V   | B |   | |   |  N  |  M  | , |  .  |  /   | RShift |
 * `--------+---+---+------+------+-------' `---------+-----+---+-----+------+--------'
 *   | Esc  |   |   | LAlt | LGui |                   | BS  |   |     | RAlt | RGui   |
 *   `----------------------------'                   `------------------------------'
 *                          ,-------------. ,-----------.
 *                          |       |     | |   | F12   |
 *                  ,-------|-------|-----| |---+-------+----.
 *                  | Space | Back  |     | |   | Enter | L1 |
 *                  |       | Space |-----| |---|       |    |
 *                  |       |       | Del | |   |       |    |
 *                  `---------------------' `----------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,   KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_TAB,   KC_Q,  KC_W,  KC_E,    KC_R,    KC_T,  KC_NO,
        KC_LCTRL, KC_A,  KC_S,  KC_D,    KC_F,    KC_G,
        KC_LSFT,  KC_Z,  KC_X,  KC_C,    KC_V,    KC_B,  KC_NO,
        KC_ESC,   KC_NO, KC_NO, KC_LALT, KC_LGUI,
                                         KC_NO,   KC_NO,
                                                  KC_NO,
                                KC_SPC,  KC_BSPC, KC_DEL,
        // right hand
        KC_NO,      KC_6,    KC_7,  KC_8,    KC_9,    KC_0,      KC_ESC,
        RGUI(KC_C), KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,      KC_BSLASH,
                    KC_H,    KC_J,  KC_K,    KC_L,    KC_SCOLON, KC_QUOTE,
        RGUI(KC_V), KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,
                    KC_BSPC, KC_NO, KC_NO,   KC_RALT, KC_RGUI,
        KC_NO, KC_F12,
        KC_NO,
        KC_NO, KC_ENTER, MO(L1)
),

/* Keymap 1:
 *
 * ,----------------------------------. ,---------------------------------------------.
 * | ESC |    |    |    |    |    |   | |   |      |      |       |       |     |     |
 * |-----+----+----+----+----+----+---| |---+------+------+-------+-------+-----+-----|
 * | ESC | 1  | 2  | 3  | 4  | 5  |   | |   | 6    | 7    | 8     | 9     | 0   | *   |
 * |-----+----+----+----+----+----|   | |   +------+------+-------+-------+-----+-----|
 * |  *  | `  | [  | ]  | -  | =  |---| |---| Left | Down | Up    | Right |     |     |
 * |-----+----+----+----+----+----|   | |   +------+------+-------+-------+-----+-----|
 * |  *  |    |    |    |    |    |   | |   |      |      | LANG2 | LANG1 |     | *   |
 * `-----+----+----+----+----+--------' `---+------+------+-------+-------+-----+-----'
 *  | *  | *  | *  | *  | *  |                     | *    | *     | *     | *   | *  |
 *  `------------------------'                     `---------------------------------'
 *                            ,-------. ,-------.
 *                            | * | * | | * | * |
 *                       ,----|---|---| |---+---+---.
 *                       | L2 | * | * | | * | * |   |
 *                       |    |   |---| |---|   |   |
 *                       |    |   | * | | * |   |   |
 *                       `------------' `-----------'
 */
// MEDIA AND MOUSE
[L1] = LAYOUT_ergodox(
        // left hand
        KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,
        KC_TRNS, KC_GRV,  KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                      KC_TRNS, KC_TRNS,
                                                               KC_TRNS,
                                             MO(L2),  KC_TRNS, KC_TRNS,
        // right hand
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,
        KC_C,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0,    KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT, KC_NO,   KC_NO,
        KC_V,    KC_NO,   KC_NO,   KC_LANG2, KC_LANG1, KC_NO,   KC_TRNS,
                          KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_NO
),

/* Keymap 2:
 *
 * ,----------------------------------------------------. ,-------------------------------------------.
 * |     |         |         |       |          |    |  | |  |      |        |      |     |     |     |
 * |-----+---------+---------+-------+----------+----+--| |--+------+--------+------+-----+-----+-----|
 * | ESC | F1      | F2      | F3    | F4       | F5 |  | |  | F6   | F7     | F8   | F9  | F10 | F11 |
 * |-----+---------+---------+-------+----------+----|  | |  +------+--------+------+-----+-----+-----|
 * |  *  | MS_LEFT | MS_DOWN | MS_UP | MS_RIGHT |    |--| |--| HOME | PGDOWN | PGUP | END |     | F12 |
 * |-----+---------+---------+-------+----------+----|  | |  +------+--------+------+-----+-----+-----|
 * |  *  |         |         |       |          |    |  | |  |      |        |      |     |     |  *  |
 * `-----+---------+---------+-------+----------+-------' `--+------+--------+------+-----+-----+-----'
 *  | *  | *       | *       | *     | *        |                   | *      | *    | *   | *   |  * |
 *  `-------------------------------------------'                   `--------------------------------'
 *                                          ,-----------. ,-------.
 *                                          | * |   *   | | * | * |
 *                                      ,---|---|-------| |---+---+---.
 *                                      |   | * |   *   | | * | * |   |
 *                                      |   |   |-------| |---|   |   |
 *                                      |   |   | RESET | | * |   |   |
 *                                      `---------------' `-----------'
 */
// MEDIA AND MOUSE
[L2] = LAYOUT_ergodox(
        // left hand
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,
        KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_BTN1, KC_BTN2, KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_NO,   KC_TRNS, RESET,
        // right hand
        KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO,   KC_F6,   KC_F7,     KC_F8,   KC_F9,   KC_F10, KC_F11,
                 KC_HOME, KC_PGDOWN, KC_PGUP, KC_END,  KC_NO,  KC_F12,
        KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,  KC_TRNS,
                          KC_TRNS,   KC_TRNS, KC_TRNS, KC_NO,  KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_NO
),
};

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
      default:
        break;
    }

  return state;
};

