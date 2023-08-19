#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  LO_SWCH,
  MACRO_0,
  MACRO_1,
  MACRO_2,
  MACRO_3,
  MACRO_4,
  MACRO_5
};

enum planck_layers {
  _DVORAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _DISABLE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define DISABLE MO(_DISABLE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Dvorak
  * ,-----------------------------------------------------------------------------------.
  * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |  /   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl |Win+D | GUI  | Alt  |Lower |    Space    |Raise | Left |  Up  | Down |Right |
  * `-----------------------------------------------------------------------------------'
  */
  [_DVORAK] = LAYOUT_planck_grid(
    KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENTER,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLASH,
    KC_LCTL, MACRO_0, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_NO,   RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT
  ),

  /* Qwerty
  * ,-----------------------------------------------------------------------------------.
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl |Win+D | GUI  | Alt  |Lower |    Space    |Raise | Left |  Up  | Down |Right |
  * `-----------------------------------------------------------------------------------'
  */
  [_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENTER,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, KC_SLASH,
    KC_LCTL, MACRO_0, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_NO,   RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT
  ),

  /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   7  |   8  |   9  |   -  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Del  |   1  |   2  |   3  |   4  |   5  |   (  |   4  |   5  |   6  |   +  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |   6  |   7  |   8  |  9   |   0  |   )  |   1  |   2  |   3  |   *  |   /  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |   0  |   .  |   ,  |      |   =  |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, _______,
    KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LPRN, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_PENT,
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RPRN, KC_KP_1, KC_KP_2, KC_KP_3, KC_PAST, KC_PSLS,
    _______, _______, _______, _______, _______, _______, KC_NO,   KC_PDOT, KC_KP_0, KC_COMM, KC_NO,   KC_EQL
  ),

  /* Raise
  * ,-----------------------------------------------------------------------------------.
  * |  F13 |  F1  |  F2  |  F3  |  F4  | Vol- | Vol+ |   &  |   *  |   [  |   ]  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Del  |  F5  |  F6  |  F7  |  F8  | Home | End  |   _  |   -  |   {  |   }  |   |  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |  F9  |  F10 |  F11 |  F12 | PgUp | PgDw |Macro1|Macro2|Macro3|Macro4|   \  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |PrtScr| Prev | Next | Play |
  * `-----------------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_planck_grid(
    KC_F13,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_VOLD, KC_VOLU, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, _______,
    KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_HOME, KC_END,  KC_UNDS, KC_MINS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGUP, KC_PGDN, MACRO_1, MACRO_2, MACRO_3, MACRO_4, KC_BSLS,
    _______, _______, _______, _______, _______, _______, KC_NO,   _______, KC_PSCR, KC_MPRV, KC_MNXT, KC_MPLY
  ),

  /* Adjust (Lower + Raise)
  * ,-----------------------------------------------------------------------------------.
  * |Disabl|      |      |      |      |AudTog|      |      |      |      |      | Sleep|
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Caps |      |      |      |      |KBMUOF|KBMUON|      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |RGBTog|Macro5|      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |Layout|      |      |             |      |      |QKBOOT|      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_ADJUST] = LAYOUT_planck_grid(
    DISABLE, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, _______, KC_SLEP,
    KC_CAPS, _______, _______, _______, _______, MU_OFF,  MU_ON,   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, RGB_TOG, MACRO_5, _______, _______, _______, _______, _______,
    _______, _______, LO_SWCH, _______, _______, _______, KC_NO,   _______, _______, QK_BOOT, _______, _______
  ),

  /* DISABLE
  * ,-----------------------------------------------------------------------------------.
  * |Disabl|      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_DISABLE] = LAYOUT_ortho_4x12(
    DISABLE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),
};

bool disabled = false;
extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

static uint32_t startup_timer = 0;
static uint32_t startup_state = 0;
static bool caps_lock = false;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// const uint8_t PROGMEM ledmap[][_LED_TOTAL][3] = {
//     [0] = { {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191}, {201,255,191} },

//     [1] = { {0,219,235}, {0,219,235}, {0,219,235}, {0,219,235}, {0,219,235}, {0,219,235}, {0,219,235}, {141,255,233}, {141,255,233}, {141,255,233}, {0,219,235}, {0,183,238}, {0,219,235}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {0,219,235}, {141,255,233}, {141,255,233}, {141,255,233}, {0,219,235}, {0,229,233}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {0,219,235}, {141,255,233}, {141,255,233}, {141,255,233}, {0,219,235}, {0,219,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,220,225}, {141,255,233}, {0,220,225}, {0,0,0}, {0,229,233} },

//     [2] = { {0,0,0}, {0,219,235}, {0,219,235}, {0,219,235}, {0,219,235}, {141,255,233}, {141,255,233}, {0,219,235}, {0,219,235}, {0,219,235}, {0,219,235}, {0,0,0}, {0,219,235}, {0,219,235}, {0,219,235}, {0,219,235}, {0,219,235}, {141,255,233}, {141,255,233}, {0,219,235}, {0,219,235}, {0,219,235}, {0,219,235}, {0,219,235}, {0,0,0}, {0,219,235}, {0,219,235}, {0,219,235}, {0,219,235}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {0,219,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233} },

//     [3] = { {201,255,191}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,219,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {201,255,191}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

// };

/*void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}*/

// void rgb_matrix_indicators_user(void) {
//   if (g_suspend_state || keyboard_config.disable_layer_led) { return; }

//   /*if (startup_state == 2) {
//     switch (biton32(layer_state)) {
//       case 0:
//         set_layer_color(0);
//         break;
//       case 1:
//         set_layer_color(1);
//         break;
//       case 2:
//         set_layer_color(2);
//         break;
//       case 3:
//         set_layer_color(3);
//         break;
//     default:i
//       if (rgb_matrix_get_flags() == LED_FLAG_NONE)
//         rgb_matrix_set_color_all(0, 0, 0);
//       break;
//     }
//   } else*/ if (startup_state == 1) {
//     rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SOLID_REACTIVE_RANDOM);
//     startup_state = 2;
//   }
// }

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LO_SWCH:
      if (record->event.pressed) {
        if (layer_state_cmp(default_layer_state, _DVORAK))
          default_layer_set(1UL<<_QWERTY);
        else
          default_layer_set(1UL<<_DVORAK);
      }
      return false;
    break;
    case KC_CAPS:
      if (record->event.pressed) {
        if (!caps_lock)
          caps_lock = !caps_lock;
        else {
          caps_lock = !caps_lock;
          planck_ez_left_led_off();
          planck_ez_right_led_off();
        }
      }
    break;
    case MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_D)));

    }
    break;
    case MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_M)))));

    }
    break;
    case MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_W)))));

    }
    break;
    case MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_V)))));

    }
    break;
    case MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_Z)))));

    }
    break;
    case MACRO_5:
      if (record->event.pressed) {
          if (rgb_matrix_get_mode() == RGB_MATRIX_CUSTOM_SOLID_REACTIVE_RANDOM)
              rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SOLID_REACTIVE_FLASHING);
          else
              rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SOLID_REACTIVE_RANDOM);
        }
    break;
    case RGB_TOG:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    break;
    case KC_ESCAPE:
      if (record->event.pressed && startup_state == 0) {
        startup_state = 1;
        rgb_matrix_set_speed_noeeprom(60);
        return false;
      }
    break;
    case DISABLE:
      if (record->event.pressed) {
        disabled = !disabled;
        if (disabled) {
          layer_on(_DISABLE);
          rgblight_disable_noeeprom();
        } else {
          layer_off(_DISABLE);
          rgblight_enable_noeeprom();
        }
      }
      return false;
      break;
    default:
      if (startup_state < 2)
        return false;
    break;

  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif

    if (timer_elapsed32(startup_timer) > 4600 && timer_elapsed32(startup_timer) < 4700) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SOLID_REACTIVE_RANDOM);
        rgb_matrix_set_speed_noeeprom(60);
        startup_state = 2;
    }

    if (caps_lock) {
        planck_ez_left_led_on();
        planck_ez_right_led_on();
    }
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif
