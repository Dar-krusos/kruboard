/* To Do
- Block last hit counter when layers on
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
  DSKTOP,
  MACRO_0,
  MACRO_1,
  MACRO_2,
  MACRO_3,
  SONG_1,
  MACRO_4,
  RGB_SAT,
  RGB_VAL,
  RGB_TYP
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
    KC_LCTL, DSKTOP, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_NO,   RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT
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
    KC_LCTL, DSKTOP, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_NO,   RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT
  ),

  /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |   `  |   !  |   @  |   #  |   $  |   %  | Tab  |   7  |   8  |   9  |   -  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Del  |   1  |   2  |   3  |   4  |   5  |  (   |   4  |   5  |   6  |   +  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |   6  |   7  |   8  |   9  |   0  |  )   |   1  |   2  |   3  |   *  |   /  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |   .  |   0  |   ,  |      |   =  |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TAB,  KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, _______,
    KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LPRN, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_PENT,
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RPRN, KC_KP_1, KC_KP_2, KC_KP_3, KC_PAST, KC_PSLS,
    _______, _______, _______, _______, _______, _______, _______, KC_PDOT, KC_KP_0, KC_COMM, KC_NO,   KC_EQL
  ),

  /* Raise
  * ,-----------------------------------------------------------------------------------.
  * |  F13 |  F1  |  F2  |  F3  |  F4  |      |   ^  |   &  |   *  |   {  |   }  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Del  |  F5  |  F6  |  F7  |  F8  | PgUp | Home |   _  |   -  |   [  |   ]  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |  F9  |  F10 |  F11 |  F12 | PgDn | End  |Macro1|Macro2|Macro3|Macro4|   \  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |PrtScr| Prev | Next | Play |
  * `-----------------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_planck_grid(
    KC_F13,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, _______,
    KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_PGUP, KC_HOME, KC_UNDS, KC_MINS, KC_LBRC, KC_RBRC, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGDN, KC_END,  MACRO_0, MACRO_1, MACRO_2, MACRO_3, KC_BSLS,
    _______, _______, _______, _______, _______, _______, KC_NO,   _______, KC_PSCR, KC_MPRV, KC_MNXT, KC_MPLY
  ),

  /* Adjust (Lower + Raise)
  * ,-----------------------------------------------------------------------------------.
  * |Disabl|      |      |      | Song1|      |LEDlvl|      |Reboot|      |      | Sleep|
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Caps |      |      | Vol- | Vol+ |KBMuse|AudTog|      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |RGBSat|RGBVal|RGBTog|RGBTyp|      |      |      |      |NumLck|
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |Layout|      |      |             |      |      |Bootld|      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_ADJUST] = LAYOUT_planck_grid(
    DISABLE, KC_NO,   KC_NO,   KC_NO,   SONG_1, KC_NO, LED_LEVEL, KC_NO,   QK_RBT,  KC_NO,   KC_NO,   KC_SLEP,
    KC_CAPS, KC_NO,   KC_NO,   KC_VOLD, KC_VOLU, MU_TOGG, KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    _______, KC_NO,   KC_NO,   RGB_SAT, RGB_VAL, MACRO_4, RGB_TYP, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NUM,
    KC_NO,   KC_NO,   LO_SWCH, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_NO,   KC_NO
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
static uint8_t layer_sat = 255;
static uint8_t layer_val = 255;
static uint32_t startup_timer = 0;

#ifdef AUDIO_ENABLE
    float everything_stays[][2] = SONG(EVERYTHING_STAYS);
#endif

typedef union {
  uint32_t raw;
  struct {
    uint8_t reactive_mode :4;
    // uint8_t sat_falloff :2;
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
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_STARTUP);
    // debug_enable=true;
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.reactive_mode = 0;
    // user_config.sat_falloff = 1;
    eeconfig_update_user(user_config.raw);
}

void clear_rgb(void) {
    for (uint8_t i = 0; i < 47; i++) {
        rgb_matrix_set_color(i, 0, 0, 0);
    }
}

void set_sat_val(void) {
    switch (user_config.reactive_mode) {
        case 2:
        case 3:
            layer_sat = rgb_matrix_config.hsv.s * 0.75 + 10;
            layer_val = rgb_matrix_config.hsv.v * 0.75 + 10;
            break;
        default:
            layer_sat = rgb_matrix_config.hsv.s;
            layer_val = rgb_matrix_config.hsv.v;
            break;
    }
}
void set_to_reactive(void) {
    // TO DO
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

    set_sat_val();
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
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_REACTIVE_PASTEL_BRIGHT);
            break;
        case 4:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_REACTIVE_WHITE);
            break;
        case 5:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_REACTIVE_FLASHING);
            break;
    }
}

void adjust_colors(void) {
    set_sat_val();
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
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE_PASTEL_BRIGHT);
            break;
        case 4:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE_WHITE);
            break;
        case 5:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE_FLASHING);
            break;
    }

    for (uint8_t i=0; i < 47; i++) {
        // macros
        if (i==4) {
            HSV hsv = {41, layer_sat, layer_val};
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        // operation keys
        if (i==0 || i==8 || i==11 || i==12 || \
            (i>=15 && i<=18) || \
            (i>=27 && i<=29) || \
            i==35 || i==38 || i==44) {
            HSV hsv = {247, layer_sat, layer_val};
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        // mute
        if (i==18) {
            if (!mute) {
                HSV hsv = {247, layer_sat, layer_val};
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            } else {
                HSV hsv = {166, layer_sat, layer_val};
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
    }
}

void startup(void) {
    stop_all_notes();
    rgb_matrix_set_speed_noeeprom(60);
    set_to_reactive();
    startup_state = false;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);

    if (rgb_on && !caps_lock) {
        switch (get_highest_layer(layer_state_set_user(state))) {
            case PLANCK_EZ_LED_LOWER:
                planck_ez_left_led_on();
                break;
            case PLANCK_EZ_LED_RAISE:
                planck_ez_right_led_on();
                break;
            case PLANCK_EZ_LED_ADJUST:
                planck_ez_right_led_on();
                planck_ez_left_led_on();
                break;
            default:
                planck_ez_left_led_off();
                planck_ez_right_led_off();
                break;
        }
    }
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    clear_rgb();
    // #define LAYER_ACTIVE

    if (rgb_on && !music) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_BLANK);
        switch (get_highest_layer(state)) {
            case _LOWER:
                for (uint8_t i=0; i < 48; i++) {
                    // special characters
                    if (i>=0 && i<=5) {
                        HSV hsv = {195, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // operation keys
                    if (i==0 || i==6 || i==12) {
                        HSV hsv = {247, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // numbers
                    if ((i>=13 && i<=17) || \
                        (i>=25 && i<=29)) {
                        HSV hsv = {15, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // numpad numbers
                    if ((i>=7 && i<=9) || \
                        (i>=19 && i<=21) || \
                        (i>=31 && i<=33) || \
                        (i>=42 && i<=44)) {
                        HSV hsv = {161, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }

                    // numpad operations
                    if (i==6 || i==10 || i==18 || i==22 || i==30 || i==34 || i==35 || i==46) {
                        HSV hsv = {95, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                }
                break;
            case _RAISE:
                for (uint8_t i=0; i < 48; i++) {
                    // special characters
                    if ((i>=6 && i<=10) || \
                        (i>=19 && i<=22) || \
                        i==35) {
                        HSV hsv = {195, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // F1-12
                    if ((i>=1 && i<=4) || \
                        (i>=13 && i<=16) || \
                        (i>=25 && i<=28)) {
                        HSV hsv = {15, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // operation keys
                    if (i==0 || i==12 || i==17 || i==18 || i==29 || i==30 || i>=43) {
                        HSV hsv = {247, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // macros
                    if (i>=31 && i<=34) {
                        HSV hsv = {41, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                }
                break;
            case _ADJUST:
                adjust_colors();
                break;
            default: //  for any other layers, or the default layer
                set_to_reactive();
                // #undef LAYER_ACTIVE
                break;
        }
    } else if (!rgb_on && layer_state_cmp(state, _ADJUST)) {
        HSV hsv = {247, layer_sat, layer_val};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(29, rgb.r, rgb.g, rgb.b); // set SONG_1 color
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ESCAPE:
      if (record->event.pressed) {
        if (startup_state == true) {
            startup();
            return false;
        } else {
            stop_all_notes();
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
    case DSKTOP:
      if (record->event.pressed)
        SEND_STRING(SS_LGUI(SS_TAP(X_D)));
      break;
    case MACRO_0:
      if (record->event.pressed)
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_M)))));
      break;
    case MACRO_1:
      if (record->event.pressed)
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_W)))));
      break;
    case MACRO_2:
      if (record->event.pressed)
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_V)))));
      break;
    case MACRO_3:
      if (record->event.pressed)
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_Z)))));
      break;
    case MACRO_4:
      if (record->event.pressed) {
        rgb_on = !rgb_on;
        if (!rgb_on) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_BLANK);
            clear_rgb();
            planck_ez_left_led_off();
            planck_ez_right_led_off();

            HSV hsv = {247, layer_sat, layer_val};
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(29, rgb.r, rgb.g, rgb.b); // set SONG_1 color
        } else
            adjust_colors();
      }
      break;
    case SONG_1:
      if (record->event.pressed)
        #ifdef AUDIO_ENABLE
            PLAY_SONG(everything_stays);
        #endif
      break;
    case DISABLE:
      if (record->event.pressed) {
        rgblight_toggle_noeeprom();
      }
      break;
    case KC_CAPS:
      if (record->event.pressed) {
        caps_lock = !caps_lock;
        if (rgb_on) {
            if (caps_lock) {
                planck_ez_left_led_on();
                planck_ez_right_led_on();
            } else {
                planck_ez_left_led_off();
                planck_ez_right_led_off();
            }
        }
      }
      break;
    case MU_TOGG: // music mode key
      if (record->event.pressed) {
        music = !music;
        if (!music) {
            set_to_reactive();
            if (rgb_on) rgb_matrix_set_color(17, 194, 4, 77);
        } else {
            clear_rgb();
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_BLANK);
        }
      }
      break;
    case KC_MUTE:
      if (record->event.pressed) {
        mute = !mute;
        if (!mute) {
            HSV hsv = {247, layer_sat, layer_val};
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(18, rgb.r, rgb.g, rgb.b);
        } else {
            HSV hsv = {166, layer_sat, layer_val};
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(18, rgb.r, rgb.g, rgb.b);
        }
      }
      break;
    case RGB_SAT:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT)
                rgb_matrix_decrease_sat();
            else
                rgb_matrix_increase_sat();
            adjust_colors();
        }
        break;
    case RGB_VAL:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT)
                rgb_matrix_decrease_val();
            else
                rgb_matrix_increase_val();
            adjust_colors();
        }
        break;
    case RGB_TYP:
        if (record->event.pressed) {
            user_config.reactive_mode += 1;
            if (user_config.reactive_mode > 5)
                user_config.reactive_mode = 0;

            eeconfig_update_user(user_config.raw);
            adjust_colors();
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
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
    case QK_BOOT:
        return false;
    default:
        return true;
    }
}
#endif
