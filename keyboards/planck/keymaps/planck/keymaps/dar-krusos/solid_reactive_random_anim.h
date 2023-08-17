#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS


typedef HSV (*reactive_f)(HSV hsv, uint16_t offset);

bool solid_reactive_random_anim_runner(effect_params_t* params, reactive_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv = {0, 255, 255};
    uint16_t max_tick = 65535 / rgb_matrix_config.speed;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint16_t tick = max_tick;
        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                hsv.h = g_last_hit_tracker.color[j];
                break;
            }
        }

        uint16_t offset = scale16by8(tick, rgb_matrix_config.speed);
        RGB      rgb    = rgb_matrix_hsv_to_rgb(effect_func(hsv, offset));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

static HSV SOLID_REACTIVE_RANDOM_math(HSV hsv, uint16_t offset) {
    hsv.s = scale8(255 - offset, hsv.s);
    hsv.v = scale8(255 - offset, hsv.v);
    if (hsv.v < 0) hsv.v = 0;
    return hsv;
}

bool SOLID_REACTIVE_RANDOM(effect_params_t* params) { return solid_reactive_random_anim_runner(params, &SOLID_REACTIVE_RANDOM_math); }

#        endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif      // DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#endif          // RGB_MATRIX_KEYREACTIVE_ENABLED
