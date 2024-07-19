#ifndef DISABLE_RGB_MATRIX_LAYER_ADJUST_REACTIVE_RANDOM
RGB_MATRIX_EFFECT(LAYER_ADJUST_REACTIVE_RANDOM)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool layer_adjust_reactive_random_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    static bool change = 0;
    static uint8_t  hue;
    static uint8_t  sat;
    uint8_t         val = sin8(scale16by8(g_rgb_timer, rgb_matrix_config.speed / 2));

    // uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 2);
    // uint8_t sat2 = sin8(time);
    // uint8_t val = sin8(time);

    if (change == 0 && val <= 3) {
        change = 1;
        hue = random8();
        sat = 150 + scale8(random8(), 256-150);
    }
    if (change == 1 && val > 3) {
        change = 0;
    }

    HSV hsv = {hue, sat, val};
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b); // led number = 30

    return rgb_matrix_check_finished_leds(led_max);
}

bool LAYER_ADJUST_REACTIVE_RANDOM(effect_params_t* params) { return layer_adjust_reactive_random_runner(params); }


#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // DISABLE_RGB_MATRIX_LAYER_ADJUST_REACTIVE_RANDOM
