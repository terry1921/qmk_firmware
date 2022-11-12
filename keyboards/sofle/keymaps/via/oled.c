
#ifdef OLED_ENABLE

static void render_logo(void) {
        /*
        * >                     <
        * > Terry the Rockstar  <
        * >                     <
        */
        /*static const char PROGMEM terry_logo[] = {
            0x10, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0x11,
            0x10, 0x54, 0x65, 0x72, 0x72, 0x79, 0xC9, 0x74, 0x68, 0x65, 0xC9, 0x52, 0x6F, 0x63, 0x6B, 0x73, 0x74, 0x61, 0x72, 0xC9, 0x11,
            0x10, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0x11, 0x00
        };*/

        /*
        * > Android   @@  @@  <
        * > Developer @@  @@  <
        * >        @Terry1921 <
        */
        static const char PROGMEM twitter_android[] = {
            0x10, 0xC9, 0x41, 0x6E, 0x64, 0x72, 0x6F, 0x69, 0x64, 0xC9, 0xC9, 0xC9, 0x9B, 0x9C, 0xC9, 0xC9, 0x9B, 0x9C, 0xC9, 0xC9, 0x11,
            0x10, 0xC9, 0x44, 0x65, 0x76, 0x65, 0x6C, 0x6F, 0x70, 0x65, 0x72, 0xC9, 0xBB, 0xBC, 0xC9, 0xC9, 0xBB, 0xBC, 0xC9, 0xC9, 0x11,
            0x10, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0x40, 0x54, 0x65, 0x72, 0x72, 0x79, 0x31, 0x39, 0x32, 0x31, 0xC9, 0x11, 0x00
        };
        /*
        * >    @terry1921     <
        * >                   <
        * > Android Developer <
        * android developer
        */
        /*static const char PROGMEM twitter_logo[] = {
            0x10, 0xC9, 0xC9, 0xC9, 0xC9, 0x40, 0x54, 0x65, 0x72, 0x72, 0x79, 0x31, 0x39, 0x32, 0x31, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0x11,
            0x10, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0xC9, 0x11,
            0x10, 0xC9, 0x41, 0x6E, 0x64, 0x72, 0x6F, 0x69, 0x64, 0xC9, 0x44, 0x65, 0x76, 0x65, 0x6C, 0x6F, 0x70, 0x65, 0x72, 0xC9, 0x11, 0x00
        };*/

        oled_write_P(twitter_android, false);
}

static void print_status(void) {
    // Print current mode
    oled_write_P(PSTR("Terry\n\n"), false);
    // print state
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("NumP"), false);
            break;
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
        case 1:
        case 4:
            oled_write_P(PSTR("Base\n\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Symbl\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("Navig\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Extra"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);

    /* wpm counter */
    /*uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(0, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 15);
    oled_write(" wpm", false);*/
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // print status keyboard
        print_status();
    } else {
        // render logo facherito
        render_logo();
    }
    return false;
}

#endif
