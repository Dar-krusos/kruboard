#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#   ifndef DISABLE_RGB_MATRIX_PREVIEW_REACTIVE_FLASHING
RGB_MATRIX_EFFECT(PREVIEW_REACTIVE_FLASHING)
#       ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool preview_reactive_flashing_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv = {rand() % (255 + 1 - 0) + 0, 255, 255};
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    rgb_matrix_set_color(20, rgb.r, rgb.g, rgb.b);

    return rgb_matrix_check_finished_leds(led_max);
}

bool PREVIEW_REACTIVE_FLASHING(effect_params_t* params) { return preview_reactive_flashing_runner(params); }


#       endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#   endif      // DISABLE_RGB_MATRIX_PREVIEW_REACTIVE_FLASHING
#endif          // RGB_MATRIX_KEYREACTIVE_ENABLED
