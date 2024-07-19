#ifndef DISABLE_RGB_MATRIX_LAYER_ADJUST_REACTIVE_FLASHING
RGB_MATRIX_EFFECT(LAYER_ADJUST_REACTIVE_FLASHING)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool layer_adjust_reactive_flashing_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    HSV hsv = {rand() % (255 + 1 - 0) + 0, 255, 255};

    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b);

    return rgb_matrix_check_finished_leds(led_max);
}

bool LAYER_ADJUST_REACTIVE_FLASHING(effect_params_t* params) { return layer_adjust_reactive_flashing_runner(params); }


#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // DISABLE_RGB_MATRIX_LAYER_ADJUST_REACTIVE_FLASHING
