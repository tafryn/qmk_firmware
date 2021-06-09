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

// Shortened Aliases
#define TG_GAME     TG(_GAMEPAD)
#define LTL_ENTER   LT(_LOWER, KC_ENTER)
#define LTL_TAB     LT(_LOWER, KC_TAB)

// One-shot Mods
#define OS_LCTL     OSM(MOD_LCTL)
#define OS_LALT     OSM(MOD_LALT)
#define OS_LGUI     OSM(MOD_LGUI)
#define OS_RCTL     OSM(MOD_RCTL)
#define OS_RALT     OSM(MOD_RALT)
#define OS_RGUI     OSM(MOD_RGUI)

// Low Row Mods (Dvorak)
#define LALT_SCLN   LALT_T(KC_SCLN)
#define LGUI_KC_Q   LGUI_T(KC_Q)
#define LSFT_KC_J   LSFT_T(KC_J)
#define LCTL_KC_K   LCTL_T(KC_K)

#define RCTL_KC_M   RCTL_T(KC_M)
#define RSFT_KC_W   RSFT_T(KC_W)
#define RGUI_KC_V   RGUI_T(KC_V)
#define RALT_KC_Z   RALT_T(KC_Z)

#define _______     KC_TRNS
#define ________    KC_TRNS

// clang-format on

typedef union {
    uint32_t raw;
    struct {
        bool gamechat : 1;
    };
} userspace_config_t;

extern userspace_config_t userspace_config;

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record);
