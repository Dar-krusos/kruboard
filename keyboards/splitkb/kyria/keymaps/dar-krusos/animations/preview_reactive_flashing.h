#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
RGB_MATRIX_EFFECT(PREVIEW_REACTIVE_FLASHING)
#   ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool preview_reactive_flashing_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed * 4);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (i == PREVIEW_KEY) {
            HSV hsv = {rand() % (255 + 1 - 0) + 0, 255, 255};
            RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            HSV hsv = {0, 0, rgb_matrix_config.hsv.v};

            if (i < 31) { // left half
                // TO-DO sync left and right phase
                hsv.v = scale8(hsv.v - time + atan2_8(dy, dx) * 3, hsv.v / 2);
                // hsv.v = scale8(time - atan2_8(dy, dx) * 3, hsv.v / 2);
            }
            if (i >= 31) { // right half
                hsv.v = scale8(hsv.v - time - atan2_8(dy, dx) * 3, hsv.v / 2);
            }

            RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        } else
            rgb_matrix_set_color(i, 0, 0, 0);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

bool PREVIEW_REACTIVE_FLASHING(effect_params_t* params) { return preview_reactive_flashing_runner(params); }


#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // RGB_MATRIX_KEYREACTIVE_ENABLED
