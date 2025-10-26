RGB_MATRIX_EFFECT(BLANK)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool blank_anim_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 0, 0, 0);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

bool BLANK(effect_params_t* params) { return blank_anim_runner(params); }

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
