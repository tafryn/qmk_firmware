#pragma once
#include QMK_KEYBOARD_H
#include <version.h>
#include "wrappers.h"
#include "process_records.h"

enum custom_layers {
    _QWERTY = 0,
    _DVORAK,
    _COLEMAK,
    _WORKMAN,
    _GAMEPAD,
    _NUM,
    _LOWER,
    _RAISE,
    _ADJUST,
};

layer_state_t layer_state_set_keymap(layer_state_t state);
