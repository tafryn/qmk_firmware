#pragma once
#include "tafryn.h"

// clang-format off
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_DVORAK,
    KC_COLEMAK,
    KC_WORKMAN,
    KC_EPRM,
    KC_VERSION,
    KC_ALL_OFF,
    KC_KVMSWP1,
    KC_KVMSWP2,
    KC_MAKE,
    RGB_SLD,
    NEW_SAFE_RANGE
};
// clang-format on

#define TG_GAME  TG(_GAMEPAD)
#define LTR_HOME LT(_RAISE, KC_HOME)
#define LTL_PGUP LT(_LOWER, KC_PGUP)

#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RALT OSM(MOD_RALT)
#define OS_RGUI OSM(MOD_RGUI)

#define _______ KC_TRNS
#define ________ KC_TRNS

typedef union {
    uint32_t raw;
    struct {
        bool gamechat : 1;
    };
} userspace_config_t;

extern userspace_config_t userspace_config;

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record);
