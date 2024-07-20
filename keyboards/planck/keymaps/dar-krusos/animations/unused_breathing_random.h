#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#   ifndef DISABLE_RGB_MATRIX_ADJUST_PREVIEW_REACTIVE
RGB_MATRIX_EFFECT(ADJUST_PREVIEW_REACTIVE)
#       ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool adjust_preview_reactive_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv = {0, 0, 0};
    static bool change = 0;

    hsv.v = sin8(scale16by8(g_rgb_timer, rgb_matrix_config.speed / 2));
    if (change == 0 && hsv.v <= 3) {
        change = 1;
        hsv.h = random8();
        hsv.s = 150 + scale8(random8(), 256-150);
    }
    if (change == 1 && hsv.v > 3)
        change = 0;

    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b); // led number = 30

    return rgb_matrix_check_finished_leds(led_max);
}

    bool ADJUST_PREVIEW_REACTIVE(effect_params_t* params) { return adjust_preview_reactive_runner(params); }


#       endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#   endif      // DISABLE_RGB_MATRIX_ADJUST_PREVIEW_REACTIVE
#endif          // RGB_MATRIX_KEYREACTIVE_ENABLED
