#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#   ifndef DISABLE_RGB_MATRIX_PREVIEW_REACTIVE_WHITE
RGB_MATRIX_EFFECT(PREVIEW_REACTIVE_WHITE)
#       ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool preview_reactive_white_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t min_val = rgb_matrix_config.hsv.v;
    static uint8_t hue;
    static bool change = 0;
    uint8_t offset = 255 - powf((float)(scale16by8(g_rgb_timer, rgb_matrix_config.speed)%255)/125,10);

    if (change == 0 && offset <= 0) {
        change = 1;
        hue = random8();
    }
    if (change == 1 && offset > 0)
        change = 0;

    HSV hsv = {hue, offset, offset > min_val ? offset : min_val};
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    rgb_matrix_set_color(20, rgb.r, rgb.g, rgb.b); // led number = 20

    return rgb_matrix_check_finished_leds(led_max);
}

bool PREVIEW_REACTIVE_WHITE(effect_params_t* params) { return preview_reactive_white_runner(params); }


#       endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#   endif      // DISABLE_RGB_MATRIX_PREVIEW_REACTIVE_WHITE
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
