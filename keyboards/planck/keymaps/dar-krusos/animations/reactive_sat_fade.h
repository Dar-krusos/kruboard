#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifndef DISABLE_RGB_MATRIX_REACTIVE_SAT_FADE
RGB_MATRIX_EFFECT(REACTIVE_SAT_FADE)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool reactive_sat_fade_anim_runner(effect_params_t* params) {
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

                uint8_t offset = powf((float)scale16by8(tick, rgb_matrix_config.speed)/150,10);
                hsv.v = 255 - offset;
                break;
            }
        }

        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}

bool REACTIVE_SAT_FADE(effect_params_t* params) { return reactive_sat_fade_anim_runner(params); }

#        endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif      // DISABLE_RGB_MATRIX_REACTIVE_SAT_FADE
#endif          // RGB_MATRIX_KEYREACTIVE_ENABLED
