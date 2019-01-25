#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

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

#define KC____ KC_NO
#define KC__o_ KC_TRNS


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
 * | *   | [  | ]  | =  | -    | `   | | Left  | Down | Up    | Right |      | DEL  |
 * |-----+----+----+----+------+-----| |-------+------+-------+-------+------+------|
 * | *   | {  | }  | +  | _    | ~   | |       |      | LANG2 | LANG1 |      | *    |
 * '---------------+----+------+-----| |-------+------+-------+---------------------'
 *                 | *  | FUNC | DEL | |       |      | *     |
 *                 '-----------------' '----------------------'
 */
  [_num_] = LAYOUT_kc( \
    ESC, 1,    2,    3,    4,    5,        6,    7,    8,     9,     0,   BSPC,\
    _o_, LBRC, RBRC, EQL,  MINS, GRV,      LEFT, DOWN, UP,    RIGHT, ___, DEL,\
    _o_, LCBR, RCBR, PLUS, UNDS, TILD,     ___,  ___,  LANG2, LANG1, ___, _o_,\
                     _o_,  FUNC, DEL,      ___,  ___,  _o_ \
  ),

/* Function Layer
 * ,----------------------------------------, ,------------------------------------------.
 * | ESC  | F1   | F2  | F3   | F4   | F5   | | F6  | F7     | F8      | F9  | F10 | F11 |
 * |------+------+-----+------+------+------| |-----+--------+---------+-----+-----+-----|
 * | *    |      |     |      |      |      | | F11 | F12    |         |     |     | F12 |
 * |------+------+-----+------+------+------| |-----+--------+---------+-----+-----+-----|
 * | *    | DISP |     |      |      |      | |     | Qwerty | Eucalyn |     |     | *   |
 * '-------------------+------+------+------| |-----+--------+---------+-----------------'
 *                     | *    |      |      | |     |        | *       |
 *                     '--------------------' '------------------------'
 */
  [_func_] = LAYOUT_kc( \
    ESC, F1,   F2,  F3,  F4,  F5,     F6,   F7,     F8,      F9,  F10, F11,\
    _o_, ___,  ___, ___, ___, ___,    HOME, PGDOWN, PGUP,    END, ___, F12,\
    _o_, DISP, ___, ___, ___, ___,    ___,  QWERTY, EUCALYN, ___, ___, _o_,\
                    _o_, ___, ___,    ___,  ___,    _o_ \
  )

};



// ----------------------------------------------------------------------------------------------------
// custom oled information function

bool displayStatus = false;



int current_layer;
void update_current_layer(void) {
    uint8_t default_layer = eeconfig_read_default_layer();
    switch (default_layer) {
        case 1UL<<_qwerty_:
            current_layer = _qwerty_;
            break;
        case 1UL<<_eucalyn_:
            current_layer = _eucalyn_;
            break;
        default:
            current_layer = -1;
            break;
    }
}

char current_layer_str[24] = {};
const char *get_layer(void) {
    switch (current_layer) {
        case _qwerty_:
            strcpy(current_layer_str, "Qwerty");
            break;
        case _eucalyn_:
            strcpy(current_layer_str, "Eucalyn");
            break;
        default:
            strcpy(current_layer_str, "Unknown");
            break;
    }
    return current_layer_str;
}

void write_layer(struct CharacterMatrix *matrix) {
    char q1[] = {0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0};
    char q2[] = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0};
    char q3[] = {0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0};
    char e1[] = {0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0};
    char e2[] = {0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0};
    char e3[] = {0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0};

    switch (current_layer) {
        case _qwerty_:
            matrix_write_ln(matrix, q1);
            matrix_write_ln(matrix, q2);
            matrix_write_ln(matrix, q3);
            break;
        case _eucalyn_:
            matrix_write_ln(matrix, e1);
            matrix_write_ln(matrix, e2);
            matrix_write_ln(matrix, e3);
            break;
    }
}

long counter = 0;
char counter_str[24] = {};
const char *get_count(void) {
    snprintf(counter_str, sizeof(counter_str), "flame:%14ld", counter++);
    if (counter == LONG_MAX) {
        counter = 0;
    }
    return counter_str;
}

char time_str[24] = {};
const char *get_time(void) {
    int time = timer_read();
    snprintf(time_str, sizeof(time_str), "time:%15d", time);
    return time_str;
}

// ----------------------------------------------------------------------------------------------------




void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif

    update_current_layer();
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

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_layer_state());
    //matrix_write_ln(matrix, read_keylog());

    //matrix_write_ln(matrix, get_layer());
    //if (displayStatus) {
    //    matrix_write_ln(matrix, get_time());
    //    matrix_write_ln(matrix, get_count());
    //}

    write_layer(matrix);

  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}

#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_qwerty_);
        current_layer = _qwerty_;
      }
      return false;
      break;
    case EUCALYN:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_eucalyn_);
        current_layer = _eucalyn_;
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
        displayStatus = !displayStatus;
      }
      return false;
      break;
  }
  return true;
}
