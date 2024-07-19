#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

typedef HSV (*reactive_f)(HSV hsv, uint16_t offset);

bool solid_reactive_random_anim_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t max_tick = 65535 / rgb_matrix_config.speed;

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        HSV hsv = {0, 255, 0};
        uint16_t tick = max_tick;

        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                hsv.h = g_last_hit_tracker.hue[j];

                // if (sat_falloff == 2) {
                    hsv.s = g_last_hit_tracker.sat[j];
                    uint8_t offset = scale16by8(tick, rgb_matrix_config.speed);
                // } else
                //     uint8_t offset = powf((float)scale16by8(tick, rgb_matrix_config.speed)/150,10);

                hsv.s = scale8(255 - offset, hsv.s);
                hsv.v = 255 - offset;
                if (hsv.v < 0) hsv.v = 0;
                break;
            }
        }

        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}

bool SOLID_REACTIVE_RANDOM(effect_params_t* params) { return solid_reactive_random_anim_runner(params); }

#        endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif      // DISABLE_RGB_MATRIX_SOLID_REACTIVE_RANDOM
#endif          // RGB_MATRIX_KEYREACTIVE_ENABLED
