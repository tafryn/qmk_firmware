#pragma once
#include "tafryn.h"

#define LAYOUT_ergodox_wrapper(...)         LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)  LAYOUT_ergodox_pretty(__VA_ARGS__)

#define ________________BLANK_____________________    _______,    _______,    _______,    _______,    _______

#define ________________NUMBER_L__________________    KC_1,       KC_2,       KC_3,       KC_4,       KC_5
#define ________________NUMBER_R__________________    KC_6,       KC_7,       KC_8,       KC_9,       KC_0
#define ________________FUNC_L____________________    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5
#define ________________FUNC_R____________________    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10

#define ________________QWERTY_L1_________________    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T
#define ________________QWERTY_L2_________________    KC_A,       KC_S,       KC_D,       KC_F,       KC_G
#define ________________QWERTY_L3_________________    KC_Z,       KC_L,       KC_C,       KC_V,       KC_B

#define ________________QWERTY_R1_________________    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P
#define ________________QWERTY_R2_________________    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN
#define ________________QWERTY_R3_________________    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLASH

#define ________________DVORAK_L1_________________    KC_QUOTE,   KC_COMM,    KC_DOT,     KC_P,       KC_Y
#define ________________DVORAK_L2_________________    KC_A,       KC_O,       KC_E,       KC_U,       KC_I
#define ________________DVORAK_L3_________________    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X

#define ________________DVORAK_R1_________________    KC_F,       KC_G,       KC_C,       KC_R,       KC_L
#define ________________DVORAK_R2_________________    KC_D,       KC_H,       KC_T,       KC_N,       KC_S
#define ________________DVORAK_R3_________________    KC_B,       KC_M,       KC_W,       KC_V,       KC_Z

#define ________________COLEMAK_L1________________    KC_Q,       KC_W,       KC_F,       KC_P,       KC_G
#define ________________COLEMAK_L2________________    KC_A,       KC_R,       KC_S,       KC_T,       KC_D
#define ________________COLEMAK_L3________________    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B

#define ________________COLEMAK_R1________________    KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN
#define ________________COLEMAK_R2________________    KC_H,       KC_N,       KC_E,       KC_I,       KC_O
#define ________________COLEMAK_R3________________    KC_K,       KC_M,       KC_COMM,    KC_DOT,     KC_SLASH

#define ________________WORKMAN_L1________________    KC_Q,       KC_D,       KC_R,       KC_W,       KC_B
#define ________________WORKMAN_L2________________    KC_A,       KC_S,       KC_H,       KC_T,       KC_G
#define ________________WORKMAN_L3________________    KC_Z,       KC_X,       KC_M,       KC_C,       KC_V

#define ________________WORKMAN_R1________________    KC_J,       KC_F,       KC_U,       KC_P,       KC_SCLN
#define ________________WORKMAN_R2________________    KC_Y,       KC_N,       KC_E,       KC_O,       KC_I
#define ________________WORKMAN_R3________________    KC_K,       KC_L,       KC_COMM,    KC_DOT,     KC_SLASH

#define ________________LOWER_L1__________________    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC
#define ________________LOWER_L2__________________    KC_1,       KC_2,       KC_3,       KC_4,       KC_5
#define ________________LOWER_L3__________________    KC_GRAVE,   KC_QUOTE,   KC_BSLS,    KC_SLASH,   KC_MINUS

#define ________________LOWER_R1__________________    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN
#define ________________LOWER_R2__________________    KC_6,       KC_7,       KC_8,       KC_9,       KC_0
#define ________________LOWER_R3__________________    KC_EQUAL,   KC_LBRC,    KC_RBRC,    KC_LCBR,    KC_RCBR

#define ________________RAISE_L1__________________    KC_PSCREEN, KC_WBAK,    KC_UP,      KC_WFWD,    KC_APP
#define ________________RAISE_L2__________________    KC_SLCK,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_CAPS
#define ________________RAISE_L3__________________    KC_PAUSE,   ________,   ________,   ________,   ________

#define ________________RAISE_R1__________________    KC_INSERT,  C(KC_PGUP), KC_PGUP,    C(KC_PGDN), G(KC_L)
#define ________________RAISE_R2__________________    KC_DELETE,  KC_HOME,    KC_PGDOWN,  KC_END,     KC_KVMSWP1
#define ________________RAISE_R3__________________    ________,   ________,   ________,   ________,   KC_KVMSWP2

#define ________________ADJUST_L1_________________    RGB_HUI,    RGB_SAI,    RGB_TOG,    RGB_VAI,    RGB_MOD
#define ________________ADJUST_L2_________________    BL_STEP,    BL_DEC,     BL_TOGG,    BL_INC,     BL_BRTG
#define ________________ADJUST_L3_________________    RGB_HUD,    RGB_SAD,    RGB_SPD,    RGB_VAD,    RGB_RMOD

#define ________________ADJUST_R1_________________    RESET,      ________,   KC_EPRM,    ________,   KC_VERSION
#define ________________ADJUST_R2_________________    ________,   KC_QWERTY,  KC_DVORAK,  KC_COLEMAK, KC_WORKMAN
#define ________________ADJUST_R3_________________    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MPLY,    KC_MNXT

#define ________________NUMPAD_R0_________________    ________,   KC_NUMLOCK, KC_PSLS,    KC_PAST,    KC_KP_MINUS
#define ________________NUMPAD_R1_________________    ________,   KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_PLUS
#define ________________NUMPAD_R2_________________    ________,   KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_KP_PLUS
#define ________________NUMPAD_R3_________________    ________,   KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_KP_ENTER
#define ________________NUMPAD_R4_________________                KC_KP_0,    KC_KP_0,    KC_KP_DOT,  KC_KP_ENTER, ________

#define _______________________GAMEPAD_L0_______________________  KC_ESC,     KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5
#define _______________________GAMEPAD_L1_______________________  KC_F1,      KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T
#define _______________________GAMEPAD_L2_______________________  KC_F2,      KC_G,       KC_A,       KC_S,       KC_D,       KC_F
#define _______________________GAMEPAD_L3_______________________  KC_F2,      KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_LALT
#define _______________________GAMEPAD_L4_______________________  KC_F4,      KC_P,       KC_Y,       KC_I,       KC_LOWER

#define _____GAMEPAD_THUMB_L______  KC_LCTL, KC_B, \
                                             KC_O, \
                          KC_SPACE,    KC_H, KC_M

#define ________________DOX_L4____________________    OS_LCTL,    OS_LALT,    KC_LEFT,    KC_RIGHT,   KC_LOWER
#define ________________DOX_R4____________________    KC_RAISE,   KC_DOWN,    KC_UP,      KC_RALT,    KC_RCTL
#define ________________DOXTHUMBS_________________                KC_HOME,    KC_END,     KC_PGDN,    KC_PGUP, \
                                                                              TG_GAME,    KC_ALL_OFF, \
                                                      KC_BSPC,    KC_LGUI,    TT(_RAISE), TT(_LOWER), KC_ENT,  KC_SPACE
