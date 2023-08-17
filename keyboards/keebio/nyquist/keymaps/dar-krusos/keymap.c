#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _DISABLE,
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  DISABLE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl |Win+D | GUI  | Alt  |Lower |Space |Space |Raise | Left |  Up  | Down |Right |
  * `-----------------------------------------------------------------------------------'
  */
  [_BASE] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH,
    KC_LCTL, MACRO_0, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
  ),

  /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   7  |   8  |   9  |   -  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Del  |   1  |   2  |   3  |   4  |   5  |   (  |   4  |   5  |   6  |   +  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |   6  |   7  |   8  |  9   |   0  |   )  |   1  |   2  |   3  |   *  |   /  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |   0  |   .  |   ,  |      |   =  |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, _______,
    KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LPRN, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_PENT,
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RPRN, KC_KP_1, KC_KP_2, KC_KP_3, KC_PAST, KC_PSLS,
    _______, _______, _______, _______, _______, _______, _______, KC_PDOT, KC_KP_0, KC_COMM, KC_NO,   KC_EQL
  ),

  /* Raise
  * ,-----------------------------------------------------------------------------------.
  * |  F13 |  F1  |  F2  |  F3  |  F4  | Vol- | Vol+ |   {  |   }  |   (  |   )  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Del  |  F5  |  F6  |  F7  |  F8  | Home | End  |   _  |   -  |   [  |   ]  |   |  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |  F9  |  F10 |  F11 |  F12 | PgUp | PgDw |Macro1|Macro2|Macro3|Macro4|   \  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |PrtScr| Prev | Next | Play |
  * `-----------------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_ortho_4x12(
    KC_F13,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_VOLD, KC_VOLU, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, _______,
    KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_HOME, KC_END,  KC_UNDS, KC_MINS, KC_LBRC, KC_RBRC, KC_PIPE,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGUP, KC_PGDN, MACRO_1, MACRO_2, MACRO_3, MACRO_4, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_MPRV, KC_MNXT, KC_MPLY
  ),

  /* Adjust (Lower + Raise)
  * ,-----------------------------------------------------------------------------------.
  * |Disabl|      |      |      |      |AudTog|      |      |      |      |      | Sleep|
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Caps |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |RGBTog|      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |QKBOOT|      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_ADJUST] = LAYOUT_ortho_4x12(
    DISABLE, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, _______, KC_SLEP,
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, _______, _______
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
static uint32_t startup_timer = 0;

layer_state_t layer_state_set_user(layer_state_t state) {
  switch(biton32(state)) {
  case _LOWER:
    rgblight_sethsv_noeeprom(HSV_CYAN);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT);
    break;
  case _RAISE:
    rgblight_sethsv_noeeprom(HSV_RED);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT);
    break;
  case _ADJUST:
    rgblight_sethsv_noeeprom(HSV_PURPLE);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT);
    break;
  default:
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
    break;
  }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) layer_on(_LOWER);
      else layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      return false;
      break;
    case RAISE:
      if (record->event.pressed) layer_on(_RAISE);
      else layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      return false;
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
    case RGB_TOG:
      if (record->event.pressed)
        rgblight_toggle_noeeprom();
      return false;
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
  }
  return true;
}

void matrix_scan_user(void) {
  if (timer_elapsed32(startup_timer) > 0 && timer_elapsed32(startup_timer) < 100) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
  }
}
