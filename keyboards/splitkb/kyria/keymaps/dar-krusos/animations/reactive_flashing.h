#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifndef DISABLE_RGB_MATRIX_REACTIVE_FLASHING
RGB_MATRIX_EFFECT(REACTIVE_FLASHING)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool reactive_flashing_anim_runner(effect_params_t* params, reactive_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv = {rand() % (255 + 1 - 0) + 0, 255, 255};
    uint16_t max_tick = 65535 / rgb_matrix_config.speed;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint16_t tick = max_tick;
        // Reverse search to find most re   cent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                break;
            }
        }

        uint16_t offset = scale16by8(tick, rgb_matrix_config.speed);
        RGB      rgb    = rgb_matrix_hsv_to_rgb(effect_func(hsv, offset));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}

static HSV REACTIVE_FLASHING_math(HSV hsv, uint16_t offset) {
    hsv.v = scale8(255 - offset, hsv.v);
    return hsv;
}

bool REACTIVE_FLASHING(effect_params_t* params) { return reactive_flashing_anim_runner(params, &REACTIVE_FLASHING_math); }

#        endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif      // DISABLE_RGB_MATRIX_REACTIVE_FLASHING
#endif          // RGB_MATRIX_KEYREACTIVE_ENABLED
