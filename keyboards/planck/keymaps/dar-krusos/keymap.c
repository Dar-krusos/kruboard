/* To Do
- Find a way to set variables in keymap that can be read in animation headers, and combine like headers
*/

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
  MACRO_5,
  MACRO_6
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
#define DISABLE TG(_DISABLE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Dvorak
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
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
  * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
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
  * |Disabl|      |      |      |      |      |      |      |      |      |      | Sleep|
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Caps |      |      |      |      |KBMuse|AudTog|      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |RGBTog|RGBTyp|      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |Layout|      |      |             |      |      |QKBOOT|      |NUMLCK|
  * `-----------------------------------------------------------------------------------'
  */
  [_ADJUST] = LAYOUT_planck_grid(
    DISABLE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SLEP,
    KC_CAPS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   MU_TOGG, KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MACRO_5, MACRO_6, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   LO_SWCH, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_NO,   KC_NUM
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
  [_DISABLE] = LAYOUT_planck_grid(
    DISABLE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
};

extern rgb_config_t rgb_matrix_config;

static bool startup_state = true;
static bool caps_lock = false;
static bool rgb_on = true;
static bool music = false;
static bool mute = false;
static uint8_t adjust = 0;
static uint32_t startup_timer = 0;

typedef union {
  uint32_t raw;
  struct {
    uint8_t reactive_mode :3;
    uint8_t sat_falloff :2;
  };
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
    planck_ez_left_led_level(255/4);
    planck_ez_right_led_level(255/4);
    planck_ez_left_led_off();
    planck_ez_right_led_off();
    user_config.raw = eeconfig_read_user();
    rgb_matrix_enable();
    // debug_enable=true;
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.reactive_mode = 0;
    user_config.sat_falloff = 1;
    eeconfig_update_user(user_config.raw);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void clear_rgb(void) {
    for (uint8_t i = 0; i < 47; i++) {
        rgb_matrix_set_color(i, 0, 0, 0);
    }
}

void set_to_reactive(void) {
    // switch (user_config.reactive_mode) {
    //     case 0:
    //     case 2:
    //         user_config.sat_falloff = 1;
    //         break;
    //     case 1:
    //     case 3:
    //         user_config.sat_falloff = 2;
    //         break;
    //     default:
    //         break;
    // }

    switch (user_config.reactive_mode) {
        case 0:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_REACTIVE);
            break;
        case 1:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_REACTIVE_SAT_FADE);
            break;
        case 2:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_REACTIVE_PASTEL);
            break;
        case 3:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_REACTIVE_WHITE);
            break;
        case 4:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_REACTIVE_FLASHING);
            break;
    }
}

void startup(void) {
    rgb_matrix_set_speed_noeeprom(60);
    set_to_reactive();
    startup_state = false;
}

bool rgb_matrix_indicators_user(void) {
    if (music) return false;
    if (adjust == 0 && layer_state_is(_ADJUST))
        adjust = 1;

    if (!rgb_on) {
        if (adjust == 2)
            adjust = 1;

        if (layer_state_is(_ADJUST)) {
            rgb_matrix_set_color(29, 194, 4, 77); // set MACRO_5 color
        } else if (adjust == 1 && !layer_state_is(_ADJUST)) {
            rgb_matrix_set_color(29, 0, 0, 0); // clear MACRO_5 color
            adjust = 0;
        }
    } else {
        if (adjust == 1 && layer_state_is(_ADJUST)) {
            clear_rgb();
            switch (user_config.reactive_mode) { // set reactive preview animation
                case 0:
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE);
                    break;
                case 1:
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE_SAT_FADE);
                    break;
                case 2:
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE_PASTEL);
                    break;
                case 3:
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE_WHITE);
                    break;
                case 4:
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE_FLASHING);
                    break;
            }
            adjust = 2;
        } else if (adjust == 2 && layer_state_is(_ADJUST)) {
            rgb_matrix_set_color(0, 194, 4, 77); // DISABLE
            rgb_matrix_set_color(11, 194, 4, 77); // set KC_SLEP color
            rgb_matrix_set_color(12, 194, 4, 77); // set KC_CAPS color
            if (!music) rgb_matrix_set_color(17, 194, 4, 77); // set MU_TOGG off color
            else rgb_matrix_set_color(17, 41, 50, 227); // set MU_TOGG on color
            if (!mute) rgb_matrix_set_color(18, 194, 4, 77); // set MU_TOGG off color
            else rgb_matrix_set_color(18, 41, 50, 227); // set MU_TOGG on color
            rgb_matrix_set_color(29, 194, 4, 77); // set MACRO_5 color
            rgb_matrix_set_color(38, 194, 4, 77); // set LO_SWCH color
            rgb_matrix_set_color(44, 194, 4, 77); // set QK_BOOT color
            rgb_matrix_set_color(46, 194, 4, 77); // set KC_NUM color
        } else if (adjust == 2 && !layer_state_is(_ADJUST)) {
            for (int8_t i = sizeof(g_last_hit_tracker.count) - 1; i >= 0; i--) {
                g_last_hit_tracker.tick[i] = 30000;
            }
            clear_rgb();
            set_to_reactive();
            adjust = 0;
        }
    }

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ESCAPE:
      if (record->event.pressed && startup_state == true) {
        startup();
        return false;
      }
      break;
    case MACRO_0:
      if (record->event.pressed)
        SEND_STRING(SS_LGUI(SS_TAP(X_D)));
      break;
    case MACRO_1:
      if (record->event.pressed)
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_M)))));
      break;
    case MACRO_2:
      if (record->event.pressed)
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_W)))));
      break;
    case MACRO_3:
      if (record->event.pressed)
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_V)))));
      break;
    case MACRO_4:
      if (record->event.pressed)
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_Z)))));
      break;
    case MACRO_5:
      if (record->event.pressed) {
        rgb_on = !rgb_on;
        if (!rgb_on)
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_BLANK);
        else
            set_to_reactive();

        clear_rgb();
      }
      break;
    case MACRO_6:
        if (record->event.pressed) {
            user_config.reactive_mode += 1;
            if (user_config.reactive_mode > 4)
                user_config.reactive_mode = 0;

            eeconfig_update_user(user_config.raw);
            adjust = 0; // resets adjust rgb
        }
        break;
    case DISABLE:
      if (record->event.pressed) {
        rgblight_toggle_noeeprom();
      }
      break;
    case KC_CAPS:
      if (record->event.pressed) {
        caps_lock = !caps_lock;
      }
      break;
    case MU_TOGG:
      if (record->event.pressed) {
        if (!music) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_BLANK);
            clear_rgb();
            if (rgb_on) rgb_matrix_set_color(17, 41, 50, 227);
        } else {
            set_to_reactive();
            if (rgb_on) rgb_matrix_set_color(17, 194, 4, 77);
        }
        music = !music;
      }
      break;
    case KC_MUTE:
      if (record->event.pressed) {
        if (!mute) {
            if (rgb_on) rgb_matrix_set_color(18, 41, 50, 227);
            mute = true;
        } else {
            if (rgb_on) rgb_matrix_set_color(18, 194, 4, 77);
            mute = false;
        }
      }
      break;
    case LO_SWCH:
      if (record->event.pressed) {
        if (layer_state_cmp(default_layer_state, _DVORAK))
          default_layer_set(1UL<<_QWERTY);
        else default_layer_set(1UL<<_DVORAK);
      }
      break;
    default:
      if (startup_state == true)
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

    if (startup_state == true && timer_elapsed32(startup_timer) > 4600 && timer_elapsed32(startup_timer) < 4700)
        startup();

    if (caps_lock) {
        planck_ez_left_led_on();
        planck_ez_right_led_on();
    }
    if (!rgb_on && !caps_lock) {
        planck_ez_left_led_off();
        planck_ez_right_led_off();
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
