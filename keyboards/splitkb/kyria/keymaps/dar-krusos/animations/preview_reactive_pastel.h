#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#   ifndef DISABLE_RGB_MATRIX_PREVIEW_REACTIVE_PASTEL
RGB_MATRIX_EFFECT(PREVIEW_REACTIVE_PASTEL)
#       ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool preview_reactive_pastel_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    static uint8_t hue;
    static bool change = 0;
    uint8_t offset = rgb_matrix_config.hsv.s - scale16by8(g_rgb_timer, rgb_matrix_config.speed);
    uint8_t offset_v = rgb_matrix_config.hsv.v - scale16by8(g_rgb_timer, rgb_matrix_config.speed);

    if (change == 0 && offset <= 0) {
        change = 1;
        hue = random8();
    }
    if (change == 1 && offset > 0)
        change = 0;

    HSV hsv = {hue, offset, offset_v};
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    rgb_matrix_set_color(20, rgb.r, rgb.g, rgb.b); // led number = 20

    return rgb_matrix_check_finished_leds(led_max);
}

bool PREVIEW_REACTIVE_PASTEL(effect_params_t* params) { return preview_reactive_pastel_runner(params); }


#       endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#   endif      // DISABLE_RGB_MATRIX_PREVIEW_REACTIVE_PASTEL
#endif          // RGB_MATRIX_KEYREACTIVE_ENABLED
