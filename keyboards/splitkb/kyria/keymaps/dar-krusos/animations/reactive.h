#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
RGB_MATRIX_EFFECT(REACTIVE)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV REACTIVE_math(HSV hsv, uint16_t tick) {
    uint16_t offset = powf((float)scale16by8(tick, qadd8(rgb_matrix_config.speed, 1))/150,10);
    hsv.v = scale8(255 - offset, rgb_matrix_config.hsv.v);
    return hsv;
}

bool REACTIVE(effect_params_t* params) {
    return effect_runner_reactive_custom(params, &REACTIVE_math);
}

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // RGB_MATRIX_KEYREACTIVE_ENABLED
