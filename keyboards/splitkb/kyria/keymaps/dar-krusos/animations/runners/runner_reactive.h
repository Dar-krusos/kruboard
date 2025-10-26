#pragma once

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

typedef HSV (*reactive_f)(HSV hsv, uint16_t offset);

bool effect_runner_reactive_custom(effect_params_t* params, reactive_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = {rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, 0};
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < 65535 / qadd8(rgb_matrix_config.speed, 1)) {
                hsv.h = g_last_hit_tracker.hue[j];
                uint16_t tick = g_last_hit_tracker.tick[j];
                rgb = rgb_matrix_hsv_to_rgb(effect_func(hsv, tick));
                break;
            }
        }

        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_KEYREACTIVE_ENABLED
