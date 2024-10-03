#ifndef DISABLE_RGB_MATRIX_BLANK
RGB_MATRIX_EFFECT(BLANK)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool BLANK(effect_params_t* params) { return false; }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // DISABLE_RGB_MATRIX_BLANK
