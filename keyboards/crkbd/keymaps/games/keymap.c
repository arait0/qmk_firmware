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

#define KC____ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_kc( \
    ___, ___, ___, ___, ___, ___,   ___, ___, ___, ___, ___, ___,\
    ___, ___,   H,   J,   K,   L,     H,   J,   K,   L, ___, ___,\
    ___, ___, ___, ___, ___, ___,   ___, ___, ___, ___, ___, ___,\
                   ___, SPC, ___,   ___, SPC, ___ \
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

  return true;
}
