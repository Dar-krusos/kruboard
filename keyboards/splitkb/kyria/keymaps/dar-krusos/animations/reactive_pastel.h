#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
RGB_MATRIX_EFFECT(REACTIVE_PASTEL)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool reactive_pastel_anim_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        HSV hsv = {0, rgb_matrix_config.hsv.s, 0};

        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < 65535 / qadd8(rgb_matrix_config.speed, 1)) {
                hsv.h = g_last_hit_tracker.hue[j];
                uint16_t offset = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
                hsv.s = scale8(255 - offset, rgb_matrix_config.hsv.s);
                hsv.v = scale8(255 - offset, rgb_matrix_config.hsv.v);
                break;
            }
        }

        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

bool REACTIVE_PASTEL(effect_params_t* params) { return reactive_pastel_anim_runner(params); }

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // RGB_MATRIX_KEYREACTIVE_ENABLED
