#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifndef DISABLE_RGB_MATRIX_REACTIVE_PASTEL_BRIGHT
RGB_MATRIX_EFFECT(REACTIVE_PASTEL_BRIGHT)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool reactive_pastel_bright_anim_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        HSV hsv = {0, rgb_matrix_config.hsv.s, 0};

        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < 65535 / rgb_matrix_config.speed) {
                hsv.h = g_last_hit_tracker.hue[j];
                uint16_t tick = g_last_hit_tracker.tick[j];
                hsv.s = rgb_matrix_config.hsv.s - scale16by8(tick, rgb_matrix_config.speed);
                if (hsv.s < 0)
                    hsv.s = 0;
                hsv.v = rgb_matrix_config.hsv.v - powf((float)scale16by8(tick, rgb_matrix_config.speed)/150,10);
                if (hsv.v < 0)
                    hsv.v = 0;
                break;
            }
        }

        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

bool REACTIVE_PASTEL_BRIGHT(effect_params_t* params) { return reactive_pastel_bright_anim_runner(params); }

#        endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif      // DISABLE_RGB_MATRIX_REACTIVE_PASTEL_BRIGHT
#endif          // RGB_MATRIX_KEYREACTIVE_ENABLED
