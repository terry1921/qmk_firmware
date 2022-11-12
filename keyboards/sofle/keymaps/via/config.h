// Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang

#pragma once

#if defined(KEYBOARD_sofle_rev1)
// Add RGB underglow and top facing lighting
#   define DYNAMIC_KEYMAP_LAYER_COUNT 6
#   define RGB_DI_PIN D3
#   define RGBLED_NUM 70
#   define RGBLED_SPLIT \
        {36, 36}
#   ifdef RGB_MATRIX_ENABLE
#       define DRIVER_LED_TOTAL RGBLED_NUM
#       define RGB_MATRIX_SPLI RGBLED_SPLIT
#       define SPLIT_TRANSPORT_MIRROR
#   else
#       define RGBLIGHT_ANIMATIONS
#       define RGBLIGHT_LIMIT_VAL 120
#       define RGBLIGHT_HUE_STEP 10
#       define RGBLIGHT_SAT_STEP 17
#       define RGBLIGHT_VAL_STEP 17
#   endif
#endif
