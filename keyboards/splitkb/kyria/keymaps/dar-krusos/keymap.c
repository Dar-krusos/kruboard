#include QMK_KEYBOARD_H
#include "eeprom.h"

enum layers {
    _DVORAK = 0,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _DISABLE,
};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  LO_SWCH,
  DESKTOP,
  ALTF4,
  MACRO_1,
  MACRO_2,
  MACRO_3,
  MACRO_4,
  MACRO_5,
  RGB_SAT,
  RGB_VAL,
  RGB_TYP
};


// Aliases for readability
#define DVORAK   DF(_DVORAK)
#define QWERTY   DF(_QWERTY)

#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define DISABLE TG(_DISABLE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Dvorak
 *
 * ,-----------------------------------------.                              ,-------------------------------------------.
 * | Esc  | ' "  | , <  | . >  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |  Bksp  |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  | Enter  |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |LShift| ; :  |   Q  |   J  |   K  |   X  |DSKTOP|CapsLk|  | Left |  Up  |   B  |   M  |   W  |   V  |   Z  |   /    |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                      | LAlt | Ctrl | Space| Lower| LGUI |  | Down | Right| Raise|VOlDwn|VOlUp |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_DVORAK] = LAYOUT(
     KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                                           KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
     KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                                           KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENTER,
     KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    DESKTOP, KC_CAPS,    KC_LEFT, KC_UP,   KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH,
                                KC_LALT, KC_LCTL, KC_SPC,  LOWER,   KC_LGUI,    KC_DOWN, KC_RGHT, RAISE,   KC_VOLD, KC_VOLU
    ),

/*
 * Base Layer: QWERTY
 *
 * ,-----------------------------------------.                              ,-------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | Enter  |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |DSKTOP|CapsLk|  | Left |  Up  |   N  |   M  | ,  < | . >  | /  ? |  ' "   |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                      | LAlt | Ctrl | Space| Lower| LGUI |  | Down | Right| Raise|VOlDwn|VOlUp |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENTER,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    DESKTOP, KC_CAPS,    KC_LEFT, KC_UP,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
                                KC_LALT, KC_LCTL, KC_SPC,  LOWER,   KC_LGUI,    KC_DOWN, KC_RGHT, RAISE,   KC_VOLD, KC_VOLU
    ),

/*
 * Lower
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |   `  |      |      |Macro1|      |      |                              |  Tab |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | Del  |   1  |   2  |   3  |   4  |   5  |                              |   (  |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |   6  |   7  |   8  |   9  |   0  |      |      |  |      |      |   )  |   1  |   2  |   3  |   +  |   /  |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
 *                      |      |      |      |      |      |  | Space|   ,  |   0  |   .  |   =  |
 *                      `----------------------------------'  `----------------------------------'
*/
    [_LOWER] = LAYOUT(
     KC_GRV,  KC_NO,   KC_NO,   ALTF4,  KC_NO,   KC_NO,                                           KC_TAB,  KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, _______,
     KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                           KC_LPRN, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_PENT,
     _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______,    KC_NO,   KC_NO,   KC_RPRN, KC_KP_1, KC_KP_2, KC_KP_3, KC_PAST, KC_PSLS,
                                _______, _______, _______, _______, _______,    KC_SPC,  KC_COMM, KC_KP_0, KC_PDOT, KC_EQL
    ),

/*
 * Raise
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |  F13 |   !  |   @  |   #  |   $  |   %  |                              |   ^  |   &  |   *  |   [  |   ]  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |                              | Home |   _  |   -  |   (  |   )  |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |      |      |  |      |      | End  |Macro1|Macro2|Macro3|Macro4|   \  |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
 *                      |  F11 |  F12 | PgUp |      | PgDn |  |PrtScr| Prev |      | Next | Play |
 *                      `----------------------------------'  `----------------------------------'
*/
    [_RAISE] = LAYOUT(
     KC_F13,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, _______,
     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                          KC_HOME, KC_UNDS, KC_MINS, KC_LBRC, KC_RBRC, _______,
     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______,    _______, _______, KC_END,  MACRO_1, MACRO_2, MACRO_3, MACRO_4, KC_BSLS,
                                KC_F11,  KC_F12,  KC_PGUP, _______, KC_PGDN,    KC_PSCR, KC_MPRV, _______, KC_MNXT, KC_MPLY
    ),

/*
 * Adjust (Lower + Raise)
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |Disabl|      |      |      |      |      |                              |      |      |Layout|      |      | Sleep|
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |RGBSat|RGBVal|RGBTog|RGBTyp|      |                              |      |AudTog|      |      |      |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |NUMLCK|
 * `--------------------+------+------+------+------+------+  |------+------+------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
*/
    [_ADJUST] = LAYOUT(
     DISABLE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                          KC_NO,   KC_NO,   LO_SWCH, KC_NO,   KC_NO,   KC_SLEP,
     KC_NO,   RGB_SAT, RGB_VAL, MACRO_5, RGB_TYP, KC_NO,                                          KC_NO,   KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,
     _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NUM,
                                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

/*
 * DISABLE
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |Disabl|      |      |      |      |      |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |         |      |      |      |      |      |      |      |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
 *                      |      |      |      |      |      |         |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
*/
    [_DISABLE] = LAYOUT(
     DISABLE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

// /*
//  * Layer template
//  *
//  * ,-----------------------------------------.                              ,-----------------------------------------.
//  * |   `  |   !  |   @  |   #  |   $  |   %  |                              |      |   7  |   8  |   9  |   *  |      |
//  * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
//  * | Del  |   1  |   2  |   3  |   4  |   5  |                              |   =  |   4  |   5  |   6  |   -  |      |
//  * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
//  * |      |   6  |   7  |   8  |   9  |   0  |      |      |  |      |      |   ,  |   1  |   2  |   3  |   +  |   /  |
//  * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
//  *                      |      |      |      |      |      |  |      |      |      |   0  |   .  |
//  *                      `----------------------------------'  `----------------------------------'
// */
//     [_LAYERINDEX] = LAYOUT(
//      _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
//                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
//     ),
};

extern rgb_config_t rgb_matrix_config;

static bool startup_state = true;
static bool rgb_on = true;
static bool mute = false;
static uint8_t layer_sat = 255;
static uint8_t layer_val = 255;
static uint32_t startup_timer = 0;

typedef union {
  uint32_t raw;
  struct {
    uint8_t reactive_mode :4;
    // uint8_t sat_falloff :2;
  };
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    rgb_matrix_enable();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_STARTUP);
    debug_enable=true;
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.reactive_mode = 0;
    // user_config.sat_falloff = 1;
    eeconfig_update_user(user_config.raw);
}

void clear_rgb(void) {
    for (uint8_t i = 0; i < 61; i++) {
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

    for (uint8_t i = 0; i < 61; i++) {
        // operation keys
        if ((i>=20 && i<=23) || \
            i==30 || i==49 || i==58 || i==61) {
            HSV hsv = {247, layer_sat, layer_val};
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        // mute
        if (i==51) {
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
    rgb_matrix_set_speed_noeeprom(60);
    set_to_reactive();
    startup_state = false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return state;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (rgb_on) {
        // clear_rgb();
        switch (get_highest_layer(layer_state)) {
            case _LOWER:
                for (uint8_t i = led_min; i < led_max; i++) {
                    // operation keys
                    if (i==30 || i==24) {
                        HSV hsv = {247, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // numbers
                    if ((i<=23 && i>=19) || \
                        (i<= 17 && i>=13)) {
                        HSV hsv = {15, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // numpad operations
                    if (i==56 || i==60 || i==50 || i==54 || i==44 || i==48 || i==49 || i==41) {
                        HSV hsv = {95, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // numpad numbers
                    if ((i>=57 && i<=59) || \
                        (i>=51 && i<=53) || \
                        (i>=45 && i<=47) || \
                        (i>=38 && i<=40)) {
                        HSV hsv = {161, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                }
                break;
            case _RAISE:
                for (uint8_t i = led_min; i < led_max; i++) {
                    // special characters
                    if ((i>=25 && i<=30) || \
                        i==35 || \
                        i==49 || \
                        (i>=51 && i<=54) || \
                        (i>=56 && i<=60)) {
                        HSV hsv = {195, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // F1-12
                    if (i==9 || i==10 || \
                        (i>=13 && i<=17) || \
                        (i>=19 && i<=23)) {
                        HSV hsv = {15, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // operation keys
                    if (i==6 || i==8 || i==24 || i==30 || i==37 || i==38 || i==40 || i==41 || i==44 || i==50) {
                        HSV hsv = {247, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // macros
                    if (i>=45 && i<=48) {
                        HSV hsv = {41, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                }
                break;
            case _ADJUST:
                set_sat_val();
                // switch (user_config.reactive_mode) { // set reactive preview animation
                //     case 0:
                //         rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE);
                //         break;
                //     case 1:
                //         rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE_SAT_FADE);
                //         break;
                //     case 2:
                //         rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE_PASTEL);
                //         break;
                //     case 3:
                //         rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE_PASTEL_BRIGHT);
                //         break;
                //     case 4:
                //         rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE_WHITE);
                //         break;
                //     case 5:
                //         rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PREVIEW_REACTIVE_FLASHING);
                //         break;
                // }

                for (uint8_t i = led_min; i < led_max; i++) {
                    // operation keys
                    if ((i>=20 && i<=23) || \
                        i==30 || i==49 || i==58 || i==61) {
                        HSV hsv = {247, layer_sat, layer_val};
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    }
                    // mute
                    if (i==51) {
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
                break;
            default:
                break;
        }
    } else if (!rgb_on && layer_state_cmp(layer_state, _ADJUST)) {
        HSV hsv = {247, layer_sat, layer_val};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(29, rgb.r, rgb.g, rgb.b); // set SONG_1 color
    }

    // for (uint8_t i = led_min; i < led_max; i++) {
    //     switch(get_highest_layer(layer_state|default_layer_state)) {
    //         case 2:
    //             rgb_matrix_set_color(i, RGB_BLUE);
    //             break;
    //         case 3:
    //             rgb_matrix_set_color(i, RGB_YELLOW);
    //             break;
    //         case 4:
    //             rgb_matrix_set_color(i, RGB_GREEN);
    //             break;
    //         default:
    //             break;
    //     }
    // }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ESCAPE:
      if (record->event.pressed) {
        if (startup_state == true) {
            startup();
            return false;
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
    case DESKTOP:
      if (record->event.pressed)
        SEND_STRING(SS_LGUI(SS_TAP(X_D)));
      break;
    case ALTF4:
      if (record->event.pressed)
        SEND_STRING(SS_LALT(SS_TAP(X_F4)));
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
        if (!rgb_on) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_BLANK);
            clear_rgb();

            HSV hsv = {247, layer_sat, layer_val};
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(29, rgb.r, rgb.g, rgb.b); // set SONG_1 color
        } else
            adjust_colors();
      }
      break;
    case DISABLE:
      if (record->event.pressed) {
        rgblight_toggle_noeeprom();
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

void matrix_scan_user(void) {
    if (startup_state == true && timer_elapsed32(startup_timer) > 4600 && timer_elapsed32(startup_timer) < 4700)
        startup();
}
