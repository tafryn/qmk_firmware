#include QMK_KEYBOARD_H
#include "tafryn.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ergodox_pretty_wrapper(
  KC_ESC,   ________________NUMBER_L__________________, KC_GRV, KC_MINS,  ________________NUMBER_R__________________, KC_EQUAL,
  KC_TAB,   ________________QWERTY_L1_________________, KC_DEL, TG(_NUM), ________________QWERTY_R1_________________, KC_BSPACE,
  KC_LCTL,  ________________QWERTY_L2_________________,                   ________________QWERTY_R2_________________, KC_QUOTE,
  KC_LSFT,  ________________QWERTY_L3_________________, KC_LBRC, KC_RBRC, ________________QWERTY_R3_________________, KC_RSFT,
  ________________DOX_L4____________________,                                      ________________DOX_R4____________________,
                                            ________________DOXTHUMBS_________________
),

[_DVORAK] = LAYOUT_ergodox_pretty_wrapper(
  KC_ESC,   ________________NUMBER_L__________________, KC_GRV, KC_EQUAL, ________________NUMBER_R__________________, KC_BSLS,
  KC_TAB,   ________________DVORAK_L1_________________, KC_DEL, TG(_NUM), ________________DVORAK_R1_________________, KC_SLASH,
  KC_LCTL,  ________________DVORAK_L2_________________,                   ________________DVORAK_R2_________________, KC_MINUS,
  KC_LSFT,  ________________DVORAK_L3_________________, KC_LBRC, KC_RBRC, ________________DVORAK_R3_________________, KC_RSFT,
  ________________DOX_L4____________________,                                      ________________DOX_R4____________________,
                                            ________________DOXTHUMBS_________________
),

[_COLEMAK] = LAYOUT_ergodox_pretty_wrapper(
  KC_ESC,   ________________NUMBER_L__________________, KC_GRV, KC_BSLS,  ________________NUMBER_R__________________, KC_EQUAL,
  KC_TAB,   ________________COLEMAK_L1________________, KC_DEL, TG(_NUM), ________________COLEMAK_R1________________, KC_MINUS,
  KC_LCTL,  ________________COLEMAK_L2________________,                   ________________COLEMAK_R2________________, KC_QUOTE,
  KC_LSFT,  ________________COLEMAK_L3________________, KC_LBRC, KC_RBRC, ________________COLEMAK_R3________________, KC_RSFT,
  ________________DOX_L4____________________,                                      ________________DOX_R4____________________,
                                            ________________DOXTHUMBS_________________
),

[_WORKMAN] = LAYOUT_ergodox_pretty_wrapper(
  KC_ESC,   ________________NUMBER_L__________________, KC_MINS, KC_BSLS, ________________NUMBER_R__________________, KC_EQUAL,
  KC_TAB,   ________________WORKMAN_L1________________, KC_DEL, TG(_NUM), ________________WORKMAN_R1________________, KC_BSPACE,
  KC_LCTL,  ________________WORKMAN_L2________________,                   ________________WORKMAN_R2________________, KC_QUOTE,
  KC_LSFT,  ________________WORKMAN_L3________________, KC_LBRC, KC_RBRC, ________________WORKMAN_R3________________, KC_RSFT,
  ________________DOX_L4____________________,                                      ________________DOX_R4____________________,
                                            ________________DOXTHUMBS_________________
),

[_LOWER] = LAYOUT_ergodox_pretty_wrapper(
  _______, ________________FUNC_L____________________, KC_F11,   KC_F12, ________________FUNC_R____________________, _______,
  _______, ________________LOWER_L1__________________, _______, _______, ________________LOWER_R1__________________, _______,
  _______, ________________LOWER_L2__________________,                   ________________LOWER_R2__________________, _______,
  _______, ________________LOWER_L3__________________, _______, _______, ________________LOWER_R3__________________, _______,
  _______, _______, _______, _______, _______,                                   _______, _______, _______, _______, _______,
                                            ________________DOXTHUMBS_________________
),

[_RAISE] = LAYOUT_ergodox_pretty_wrapper(
  _______, ________________FUNC_L____________________, KC_F11,   KC_F12, ________________FUNC_R____________________, _______,
  _______, ________________RAISE_L1__________________, _______, _______, ________________RAISE_R1__________________, _______,
  _______, ________________RAISE_L2__________________,                   ________________RAISE_R2__________________, _______,
  _______, ________________RAISE_L3__________________, _______, _______, ________________RAISE_R3__________________, _______,
  _______, _______, _______, _______, _______,                                   _______, _______, _______, _______, _______,
                                            ________________DOXTHUMBS_________________
),

[_ADJUST] = LAYOUT_ergodox_pretty_wrapper(
  _______, ________________BLANK_____________________, _______, _______, ________________BLANK_____________________, _______,
  _______, ________________ADJUST_L1_________________, _______, _______, ________________ADJUST_R1_________________, _______,
  _______, ________________ADJUST_L2_________________,                   ________________ADJUST_R2_________________, _______,
  _______, ________________ADJUST_L3_________________, _______, _______, ________________ADJUST_R3_________________, _______,
  _______, _______, _______, _______, _______,                                   _______, _______, _______, _______, _______,
                                            ________________DOXTHUMBS_________________
),

[_GAMEPAD] = LAYOUT_ergodox_pretty_wrapper(
  GP_LL0,  ________________GAMEPAD_L0________________, GP_LR0,  _______, ________________BLANK_____________________, _______,
  GP_LL1,  ________________GAMEPAD_L1________________, GP_LR1,  _______, ________________BLANK_____________________, _______,
  GP_LL2,  ________________GAMEPAD_L2________________,                   ________________BLANK_____________________, _______,
  GP_LL3,  ________________GAMEPAD_L3________________, GP_LR3,  _______, ________________BLANK_____________________, _______,
  ________________GAMEPAD_L4________________,                                    _______, _______, _______, _______, _______,
                                       ________________GP_DOXTHUMBS______________
),

[_NUM] = LAYOUT_ergodox_pretty_wrapper(
  _______, ________________BLANK_____________________, _______, _______, ________________NUMPAD_R0_________________, _______,
  _______, ________________BLANK_____________________, _______, _______, ________________NUMPAD_R1_________________, _______,
  _______, ________________BLANK_____________________,                   ________________NUMPAD_R2_________________, _______,
  _______, ________________BLANK_____________________, _______, _______, ________________NUMPAD_R3_________________, _______,
  _______, _______, _______, _______, _______,                                    ________________NUMPAD_R4_________________,
                                            ________________DOXTHUMBS_________________
),

};
// clang-format on

layer_state_t layer_state_set_keymap(layer_state_t state) {
    ergodox_board_led_off();

    uint8_t layer = biton32(state);

    switch (layer) {
        case 0:
            ergodox_board_led_off();
            break;
        default:
            ergodox_board_led_on();
            break;
    }

    return state;
}
