#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifndef DISABLE_RGB_MATRIX_REACTIVE_PASTEL
RGB_MATRIX_EFFECT(REACTIVE_PASTEL)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool reactive_pastel_anim_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        HSV hsv = {0, 255, 0};

        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < 65535 / rgb_matrix_config.speed) {
                hsv.h = g_last_hit_tracker.hue[j];
                uint8_t offset = scale16by8(g_last_hit_tracker.tick[j], rgb_matrix_config.speed);
                hsv.s = rgb_matrix_config.hsv.s - offset;
                hsv.v = rgb_matrix_config.hsv.v - offset;
                break;
            }
        }

        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}

bool REACTIVE_PASTEL(effect_params_t* params) { return reactive_pastel_anim_runner(params); }

#        endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif      // DISABLE_RGB_MATRIX_REACTIVE_PASTEL
#endif          // RGB_MATRIX_KEYREACTIVE_ENABLED
