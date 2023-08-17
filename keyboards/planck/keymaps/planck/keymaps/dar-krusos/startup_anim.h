#ifndef DISABLE_RGB_MATRIX_STARTUP
RGB_MATRIX_EFFECT(STARTUP)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

typedef HSV (*dx_dy_i_f)(HSV hsv, int16_t dx, int16_t dy, uint8_t i, uint8_t time, uint16_t offset, uint8_t mode);

uint8_t timer = 0;

bool startup_effect_runner(effect_params_t* params, dx_dy_i_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 2);
    
    if (timer_elapsed32(timer) < 1200) {
        return led_max < DRIVER_LED_TOTAL;
    } else if (timer_elapsed32(timer) < 2150) {
        for (uint8_t i = 0; i < 12; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, dx, dy, i, time, 1200, 0));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        for (uint8_t i = DRIVER_LED_TOTAL-12; i < DRIVER_LED_TOTAL; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, dx, dy, i, time, 1200, 1));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    } else if (timer_elapsed32(timer) < 3100) {
        if (timer_elapsed32(timer) < 2400) {
            rgb_matrix_set_color(11, 0, 0, 0);
            rgb_matrix_set_color(DRIVER_LED_TOTAL-11, 0, 0, 0);
        }
        
        for (uint8_t i = 12; i < 24; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, dx, dy, i, time, 2150, 1));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        for (uint8_t i = DRIVER_LED_TOTAL-24; i < DRIVER_LED_TOTAL-12; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, dx, dy, i, time, 2150, 0));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    } else if (timer_elapsed32(timer) < 3800) {
        HSV hsv = {0, 0, rgb_matrix_config.hsv.v};

        // Left side
        for (uint8_t i = 0; i < 6; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(hsv, dx, dy, i, time, 3100, 2));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        for (uint8_t i = 12; i < 18; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(hsv, dx, dy, i, time, 3100, 2));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        for (uint8_t i = DRIVER_LED_TOTAL-23; i < DRIVER_LED_TOTAL-17; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(hsv, dx, dy, i, time, 3100, 2));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        for (uint8_t i = DRIVER_LED_TOTAL-11; i < DRIVER_LED_TOTAL-5; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(hsv, dx, dy, i, time, 3100, 2));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }

        // Right side
        for (uint8_t i = 6; i < 12; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(hsv, dx, dy, i, time, 3100, 3));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        for (uint8_t i = 18; i < 24; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(hsv, dx, dy, i, time, 3100, 3));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        for (uint8_t i = DRIVER_LED_TOTAL-17; i < DRIVER_LED_TOTAL-11; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(hsv, dx, dy, i, time, 3100, 3));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        for (uint8_t i = DRIVER_LED_TOTAL-5; i < DRIVER_LED_TOTAL; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
            RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(hsv, dx, dy, i, time, 3100, 3));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    } else if (timer_elapsed32(timer) < 4500) {
        HSV hsv = {0, 0, rgb_matrix_config.hsv.v};
        for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_TEST_LED_FLAGS();
                int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
                int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
                RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(hsv, dx, dy, i, time, 3800, 4));
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    } else if (timer_elapsed32(timer) < 4600) {
        rgb_matrix_set_color_all(0, 0, 0);
    }

    return led_max < DRIVER_LED_TOTAL;
}

static HSV STARTUP_math(HSV hsv, int16_t dx, int16_t dy, uint8_t i, uint8_t time, uint16_t offset, uint8_t mode) {
    int32_t v = 0;

    if (mode == 0) {
        v = hsv.v - abs(scale8(g_led_config.point[i].x, 228) + 28 - (timer_elapsed32(timer) - offset)) * 8;
        hsv.v = scale8(v < 0 ? 0 : v, hsv.v);
    } else if (mode == 1) {
        v = hsv.v - abs(scale8(225-g_led_config.point[i].x, 228) + 28 - (timer_elapsed32(timer) - offset)) * 8;
        hsv.v = scale8(v < 0 ? 0 : v, hsv.v);
    } else if (mode == 2) {
        v = -2*scale8(g_led_config.point[i].x, 228) + timer_elapsed32(timer) - offset;
        if (v > 255) v = 255;
        if (v < 0) v = 0;
        hsv.v = scale8(v, hsv.v);
    } else if (mode == 3) {
        v = -2*scale8(224 - g_led_config.point[i].x, 228) + timer_elapsed32(timer) - offset;
        if (v > 255) v = 255;
        if (v < 0) v = 0;
        hsv.v = scale8(v, hsv.v);
    } else {
        v = (timer_elapsed32(timer) - offset)/3;
        hsv.v = hsv.v - v;
        if (hsv.v < 0) hsv.v = 0; 
    }
    
    hsv.h = atan2_8(dy, dx) + time;
    return hsv;
}

bool STARTUP(effect_params_t* params) { return startup_effect_runner(params, &STARTUP_math); }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // DISABLE_RGB_MATRIX_STARTUP
