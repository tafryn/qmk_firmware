#include "process_records.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ENT:
            if (record->event.pressed) {
                if (userspace_config.gamechat) {
                    layer_clear();
                    layer_on(_GAMEPAD);
                    userspace_config.gamechat ^= 1;
                    SEND_STRING(SS_TAP(X_ENTER));
                    return false;
                } else if (IS_LAYER_ON(_GAMEPAD)) {
                    layer_clear();
                    userspace_config.gamechat ^= 1;
                    SEND_STRING(SS_TAP(X_ENTER));
                    return false;
                }
            }
            return true;
            break;
        case KC_QWERTY ... KC_WORKMAN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(keycode - KC_QWERTY);
            }
            return false;
            break;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                if (IS_LAYER_ON(_ADJUST)) {
                    layer_off(_LOWER);
                    layer_off(_RAISE);
                }
            } else {
                layer_off(_LOWER);
                if (IS_LAYER_ON(_ADJUST)) {
                    layer_off(_ADJUST);
                    layer_on(_RAISE);
                }
            }
            return false;
            break;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                if (IS_LAYER_ON(_ADJUST)) {
                    layer_off(_RAISE);
                    layer_off(_LOWER);
                }
            } else {
                layer_off(_RAISE);
                if (IS_LAYER_ON(_ADJUST)) {
                    layer_off(_ADJUST);
                    layer_on(_LOWER);
                }
            }
            return false;
            break;
        case KC_ALL_OFF:
            layer_clear();
            userspace_config.raw = 0;
            return false;
            break;
        case KC_KVMSWP1:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LCTRL) SS_TAP(X_LCTRL) "1");
            }
            return false;
            break;
        case KC_KVMSWP2:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LCTRL) SS_TAP(X_LCTRL) "2");
            }
            return false;
            break;
        case KC_EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case KC_VERSION:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case RGB_SLD:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                rgblight_mode(1);
#endif
            }
            return false;
            break;
    }
    return true;
}
