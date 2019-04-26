#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

#include "games/tetris.h"
#include "games/screen.h"

Tetris g_tetris;

extern keymap_config_t keymap_config;

extern uint8_t is_master;

#define _qwerty_  0  // Qwerty
#define _eucalyn_ 1  // Eucalyn
#define _num_     2  // Number Layer
#define _func_    3  // Function Layer

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EUCALYN,
  NUM,
  FUNC,
  DISPLAY
};

#define KC_QWERTY QWERTY
#define KC_EUCALYN EUCALYN
#define KC_NUM NUM
#define KC_FUNC FUNC
#define KC_DISP DISPLAY
#define KC_RESET RESET

#define KC____ KC_NO
#define KC__o_ KC_TRNS

#define KC_SLBRC S(KC_LBRC)
#define KC_SRBRC S(KC_RBRC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty Layer
 * ,-------------------------------------------, ,-------------------------------------------,
 * | Tab    | Q    | W    | E    | R    | T    | | Y     | U   | I    | O    |  P   |  \/|   |
 * |--------+------+------+------+------+------| |-------+-----+------+------+------+--------|
 * | LCtrl  | A    | S    | D    | F    | G    | | H     | J   | K    | L    | ;/:  |  '/"   |
 * |--------+------+------+------+------+------| |-------+-----+------+------+------+--------|
 * | LShift | Z    | X    | C    | V    | B    | | N     | M   | ,    | .    | //?  | RShift |
 * '----------------------+------+------+------' '-------+-----+-----------------------------'
 *                        | LGui | SPC  | BSPC | | Enter | NUM | RAlt |
 *                        '--------------------' '--------------------'
 */
  [_qwerty_] = LAYOUT_kc( \
    TAB,  Q, W, E,    R,   T,        Y,   U,   I,    O,   P,     BSLS,\
    LCTL, A, S, D,    F,   G,        H,   J,   K,    L,   SCLN,  QUOT,\
    LSFT, Z, X, C,    V,   B,        N,   M,   COMM, DOT, SLSH,  RSFT,\
                LGUI, SPC, BSPC,     ENT, NUM, RALT \
  ),

/* Eucalyn Layer
 * ,-------------------------------------------, ,------------------------------------------,
 * | Tab    | Q    | W    | ,    | .    | ;/:  | | M     | R   | D    | Y    |  P  | \/|    |
 * |--------+------+------+------+------+------| |-------+-----+------+------+-----+--------|
 * | LCtrl  | A    | O    | E    | I    | U    | | G     | T   | N    | S    |  F  | '/"    |
 * |--------+------+------+------+------+------| |-------+-----+------+------+-----+--------|
 * | LShift | Z    | X    | C    | V    | B    | | H     | J   | K    | L    | //? | RShift |
 * '----------------------+------+------+------' '-------+-----+----------------------------'
 *                        | LGui | SPC  | BSPC | | Enter | NUM | RAlt |
 *                        '--------------------' '--------------------'
 */
  [_eucalyn_] = LAYOUT_kc( \
    TAB,  Q,    W,    COMM, DOT, SCLN,     M,   R,   D,   Y,    P,    BSLS,\
    LCTL, A,    O,    E,    I,   U,        G,   T,   N,   S,    F,    QUOT,\
    LSFT, Z,    X,    C,    V,   B,        H,   J,   K,   L,    SLSH, RSFT,\
                      LGUI, SPC, BSPC,     ENT, NUM, RALT \
  ),

/* Number Layer
 * ,---------------------------------, ,--------------------------------------------.
 * | ESC | 1  | 2  | 3  | 4    | 5   | | 6     | 7    | 8     | 9     | 0    | BSPC |
 * |-----+----+----+----+------+-----| |-------+------+-------+-------+------+------|
 * | *   | [  | {  | =  | -    | `   | | Left  | Down | Up    | Right |      | DEL  |
 * |-----+----+----+----+------+-----| |-------+------+-------+-------+------+------|
 * | *   | ]  | }  | +  | _    | ~   | |       |      | LANG2 | LANG1 |      | *    |
 * '---------------+----+------+-----| |-------+------+-------+---------------------'
 *                 | *  | FUNC | DEL | |       |      | *     |
 *                 '-----------------' '----------------------'
    _o_, LBRC, LCBR, EQL,  MINS, GRV,      LEFT, DOWN, UP,    RIGHT, ___, DEL,\
    _o_, RBRC, RCBR, PLUS, UNDS, TILD,     ___,  ___,  LANG2, LANG1, ___, _o_,\
 */
  [_num_] = LAYOUT_kc( \
    ESC, 1,    2,     3,    4,    5,        6,    7,    8,     9,     0,   BSPC,\
    _o_, LBRC, SLBRC, EQL,  MINS, GRV,      LEFT, DOWN, UP,    RIGHT, ___, DEL,\
    _o_, RBRC, SRBRC, PLUS, UNDS, TILD,     ___,  ___,  LANG2, LANG1, ___, _o_,\
                     _o_,  FUNC, DEL,      ___,  ___,  _o_ \
  ),

/* Function Layer
 * ,-----------------------------------------------------, ,-------------------------------------------.
 * | ESC  | F1      | F2      | F3    | F4       | F5    | | F6   | F7     | F8      | F9  | F10 | F11 |
 * |------+---------+---------+-------+----------+-------| |------+--------+---------+-----+-----+-----|
 * | *    | MS_LEFT | MS_DOWN | MS_UP | MS_RIGHT |       | | HOME | PGDOWN | PGUP    | END |     | F12 |
 * |------+---------+---------+-------+----------+-------| |------+--------+---------+-----+-----+-----|
 * | *    | DISP    |         | BTN1  | BTN2     |       | |      | Qwerty | Eucalyn |     |     | *   |
 * '--------------------------+-------+----------+-------| |------+--------+---------+-----------------'
 *                            | *     |          | RESET | |      |        | *       |
 *                            '--------------------------' '-------------------------'
 */
  [_func_] = LAYOUT_kc( \
    ESC, F1,   F2,   F3,   F4,   F5,       F6,   F7,     F8,      F9,  F10, F11,\
    _o_, MS_L, MS_D, MS_U, MS_R, ___,      HOME, PGDOWN, PGUP,    END, ___, F12,\
    _o_, DISP, ___,  BTN1, BTN2,  ___,      ___,  QWERTY, EUCALYN, ___, ___, _o_,\
                     _o_,  ___,  RESET,    ___,  ___,    _o_ \
  )

};





void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}


//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
const char *read_layer_state(void);
const char *read_keylog(void);
const char *read_mode_icon(bool swap);

void matrix_scan_user(void) {
   iota_gfx_task();
}


void iota_gfx_task_user(void) {
  ScreenMatrix matrix;
  screen_clear(&matrix);

  tetris_update(&g_tetris);
  tetris_render(&g_tetris, &matrix);

  screen_update(&g_screen, &matrix);
}



#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
    case KC_H:
      tetris_move(&g_tetris, 0);
      break;
    case KC_L:
      tetris_move(&g_tetris, 1);
      break;
    case KC_J:
      tetris_rotate(&g_tetris, 0);
      break;
    case KC_K:
      tetris_rotate(&g_tetris, 1);
      break;
    case KC_SPC:
      tetris_move(&g_tetris, 2);
      break;
    }
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_qwerty_);
      }
      return false;
      break;
    case EUCALYN:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_eucalyn_);
      }
      return false;
      break;
    case NUM:
      if (record->event.pressed) {
        layer_on(_num_);
      } else {
        layer_off(_num_);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_func_);
      } else {
        layer_off(_func_);
      }
      return false;
      break;
    case DISPLAY:
      if (record->event.pressed) {
        // displayStatus = !displayStatus;
      }
      return false;
      break;
  }
  return true;
}
