#include QMK_KEYBOARD_H
#include "tafryn.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define ONE_GRV LT(1, KC_GRAVE)
#define CTL_Z LCTL_T(KC_Z)
#define ALT_SHFT LALT(KC_LSFT)
#define ALT_MENU LALT_T(KC_MENU)
#define LG_QUOT LGUI_T(KC_QUOT)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_SLS LCTL_T(KC_SLSH)
#define LT2_COL LT(_RAISE, KC_SCLN)

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*     [_QWERTY] = LAYOUT_dactyl_pretty_wrapper( */
/*         KC_EQL , ________________NUMBER_L__________________,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC, */
/*         KC_DEL , KC_Q  ,KC_W   , KC_E  , KC_R  , KC_T  ,                                        KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS, */
/*         KC_BSPC, KC_A  ,KC_S   , KC_D  , KC_F  , KC_G  ,                                        KC_H   , KC_J  , KC_K  , KC_L  ,LT2_COL,LG_QUOT, */
/*         KC_LSFT, CTL_Z ,KC_X   , KC_C  , KC_V  , KC_B  ,                                        KC_N   , KC_M  ,KC_COMM, KC_DOT,CTL_SLS,KC_RSFT, */
/*         ONE_GRV,KC_QUOT,ALT_SHFT,KC_LEFT,KC_RGHT,                                                        KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,TT(_LOWER), */
/*                                                         ALT_MENU,KC_LGUI,       KC_RALT,CTL_ESC, */
/*                                                                  KC_HOME,        KC_PGUP, */
/*                                                 KC_SPC, KC_BSPC, KC_END ,        KC_PGDN, KC_TAB, KC_ENT */
/*     ), */
/*     [_LOWER] = LAYOUT_6x6( */
/*         _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                       KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 , */
/*         _______,KC_EXLM,KC_AT  ,KC_LBRC,KC_RBRC,KC_PIPE,                                       KC_UP  ,KC_P7  ,KC_P8  ,KC_P9  ,KC_PAST,KC_F12 , */
/*         _______,KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_GRV ,                                       KC_DOWN,KC_P4  ,KC_P5  ,KC_P6  ,KC_PPLS,_______, */
/*         _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,                                       KC_AMPR,KC_P1  ,KC_P2  ,KC_P3  ,KC_PSLS,_______, */
/*         RESET  ,_______,_______,_______,_______,_______,                                       _______,_______,KC_PDOT,KC_P0  ,KC_PEQL,_______, */
/*                                                 _______,_______,_______,       _______,_______,_______, */
/*                                                                 _______,       _______, */
/*                                                                 _______,       _______ */
/*     ), */
/*     [_RAISE] = LAYOUT_6x6( */
/*         _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______, */
/*         _______,_______,_______,KC_MS_U,_______,_______,                                       _______,_______,_______,_______,_______,_______, */
/*         _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,                                       _______,_______,_______,_______,_______,KC_MPLY, */
/*         _______,_______,_______,_______,_______,_______,                                       _______,_______,KC_MPRV,KC_MNXT,_______,_______, */
/*         RESET  ,_______,_______,KC_BTN1,KC_BTN2,_______,                                       KC_WBAK,KC_VOLU,KC_VOLD,KC_MUTE,_______,_______, */
/*                                                 _______,_______,_______,       _______,_______,_______, */
/*                                                                 _______,       _______, */
/*                                                                 _______,       _______ */
/*     ) */
/* }; */

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic QWERTY layer
 *
 * ,--------------------------------------.                          ,--------------------------------------.
 * |  Esc   |  1  |  2  |  3  |  4  |  5  |                          |  6  |  7  |  8  |  9  |  0  |   =    |
 * |--------+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  E  |  R  |  T  |                          |  Y  |  U  |  I  |  O  |  P  |  BSPC  |
 * |--------+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+--------|
 * |  Ctrl  |  A  |  S  |  D  |  F  |  G  |                          |  H  |  J  |  K  |  L  |  ;  |   '    |
 * |--------+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+--------|
 * | LShift |  Z  |  X  |  C  |  V  |  B  |                          |  N  |  M  |  ,  |  .  |  /  | RShift |
 * `--------+-----+-----+-----+-----+-----'                          `-----+-----+-----+-----+-----+--------'
 *   |OSM_C |OSM_A|Left |Right|LOWER|                                      |RAISE|Down | Up  | Alt | Ctrl |
 *   `------------------------------'                                      `------------------------------'
 *                                        ,-----------.  ,-----------.
 *                                        |Home | End |  |PgDn |PgUp |
 *                                  ,-----|-----|-----|  |-----+-----+-----.
 *                                  |     |     |Lock |  |A_OFF|     |     |
 *                                  |BkSpc|LGUI |-----|  |-----|Enter|Space|
 *                                  |     |     |RAISE|  |LOWER|     |     |
 *                                  `-----------------'  `-----------------'
 */
[_QWERTY] = LAYOUT_dactyl_pretty_wrapper(
  KC_ESC,   ________________NUMBER_L__________________,              ________________NUMBER_R__________________, KC_EQUAL,
  KC_TAB,   ________________QWERTY_L1_________________,              ________________QWERTY_R1_________________, KC_BSPACE,
  KC_LCTL,  ________________QWERTY_L2_________________,              ________________QWERTY_R2_________________, KC_QUOTE,
  KC_LSFT,  ________________QWERTY_L3_________________,              ________________QWERTY_R3_________________, KC_RSFT,
  ________________DOX_L4____________________,                                 ________________DOX_R4____________________,
                                        ________________DOXTHUMBS_________________
),

/* Keymap 1: Basic Dvorak layer
 *
 * ,--------------------------------------.                          ,-------------------------------------.
 * |  Esc   |  1  |  2  |  3  |  4  |  5  |                          |  6  |  7  |  8  |  9  |  0  |   \    |
 * |--------+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+--------|
 * |  Tab   |  '  |  ,  |  .  |  P  |  Y  |                          |  F  |  G  |  C  |  R  |  L  |   /    |
 * |--------+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+--------|
 * |  Ctrl  |  A  |  O  |  E  |  U  |  I  |                          |  D  |  H  |  T  |  N  |  S  |   -    |
 * |--------+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+--------|
 * | LShift |  ;  |  Q  |  J  |  K  |  X  |                          |  B  |  M  |  W  |  V  |  Z  | RShift |
 * `--------+-----+-----+-----+-----+-----'                          `-----+-----+-----+-----+-----+--------'
 *   |OSM_C |OSM_A|Left |Right|LOWER|                                      |RAISE|Down | Up  | Alt | Ctrl |
 *   `------------------------------'                                      `------------------------------'
 *                                        ,-----------.  ,-----------.
 *                                        |Home | End |  |PgDn |PgUp |
 *                                  ,-----|-----|-----|  |-----+-----+-----.
 *                                  |     |     |Lock |  |A_OFF|     |     |
 *                                  |BkSpc|LGUI |-----|  |-----|Enter|Space|
 *                                  |     |     |RAISE|  |LOWER|     |     |
 *                                  `-----------------'  `-----------------'
 */
[_DVORAK] = LAYOUT_dactyl_pretty_wrapper(
  KC_ESC,   ________________NUMBER_L__________________,              ________________NUMBER_R__________________, KC_BSLS,
  KC_TAB,   ________________DVORAK_L1_________________,              ________________DVORAK_R1_________________, KC_SLASH,
  KC_LCTL,  ________________DVORAK_L2_________________,              ________________DVORAK_R2_________________, KC_MINUS,
  KC_LSFT,  ________________DVORAK_L3_________________,              ________________DVORAK_R3_________________, KC_RSFT,
  ________________DOX_L4____________________,                                 ________________DOX_R4____________________,
                                        ________________DOXTHUMBS_________________
),

/* Keymap 2: Basic Colemak layer
 *
 * ,--------------------------------------.                          ,-------------------------------------.
 * |  Esc   |  1  |  2  |  3  |  4  |  5  |                          |  6  |  7  |  8  |  9  |  0  |   =    |
 * |--------+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  F  |  P  |  G  |                          |  J  |  L  |  U  |  Y  |  ;  |   -    |
 * |--------+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+--------|
 * |  Ctrl  |  A  |  R  |  S  |  T  |  D  |                          |  H  |  N  |  E  |  I  |  O  |   '    |
 * |--------+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+--------|
 * | LShift |  Z  |  X  |  C  |  V  |  B  |                          |  K  |  M  |  ,  |  .  |  /  | RShift |
 * `--------+-----+-----+-----+-----+-----'                          `-----+-----+-----+-----+-----+--------'
 *   |OSM_C |OSM_A|Left |Right|LOWER|                                      |RAISE|Down | Up  | Alt | Ctrl |
 *   `------------------------------'                                      `------------------------------'
 *                                        ,-----------.  ,-----------.
 *                                        |Home | End |  |PgDn |PgUp |
 *                                  ,-----|-----|-----|  |-----+-----+-----.
 *                                  |     |     |Lock |  |A_OFF|     |     |
 *                                  |BkSpc|LGUI |-----|  |-----|Enter|Space|
 *                                  |     |     |RAISE|  |LOWER|     |     |
 *                                  `-----------------'  `-----------------'
 */
[_COLEMAK] = LAYOUT_dactyl_pretty_wrapper(
  KC_ESC,   ________________NUMBER_L__________________,              ________________NUMBER_R__________________, KC_EQUAL,
  KC_TAB,   ________________COLEMAK_L1________________,              ________________COLEMAK_R1________________, KC_MINUS,
  KC_LCTL,  ________________COLEMAK_L2________________,              ________________COLEMAK_R2________________, KC_QUOTE,
  KC_LSFT,  ________________COLEMAK_L3________________,              ________________COLEMAK_R3________________, KC_RSFT,
  ________________DOX_L4____________________,                                 ________________DOX_R4____________________,
                                        ________________DOXTHUMBS_________________
),

/* Keymap 3: Basic Workman layer
 *
 * ,--------------------------------------.                          ,-------------------------------------.
 * |  Esc   |  1  |  2  |  3  |  4  |  5  |                          |  6  |  7  |  8  |  9  |  0  |   =    |
 * |--------+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  D  |  R  |  W  |  B  |                          |  J  |  F  |  U  |  P  |  ;  |  BSPC  |
 * |--------+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+--------|
 * |  Ctrl  |  A  |  S  |  H  |  T  |  G  |                          |  Y  |  N  |  E  |  O  |  I  |   '"   |
 * |--------+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+--------|
 * | LShift |  Z  |  X  |  M  |  C  |  V  |                          |  K  |  L  |  ,  |  .  |  /  | RShift |
 * `--------+-----+-----+-----+-----+-----'                          `-----+-----+-----+-----+-----+--------'
 *   |OSM_C |OSM_A|Left |Right|LOWER|                                      |RAISE|Down | Up  | Alt | Ctrl |
 *   `------------------------------'                                      `------------------------------'
 *                                        ,-----------.  ,-----------.
 *                                        |Home | End |  |PgDn |PgUp |
 *                                  ,-----|-----|-----|  |-----+-----+-----.
 *                                  |     |     |Lock |  |A_OFF|     |     |
 *                                  |BkSpc|LGUI |-----|  |-----|Enter|Space|
 *                                  |     |     |RAISE|  |LOWER|     |     |
 *                                  `-----------------'  `-----------------'
 */
[_WORKMAN] = LAYOUT_dactyl_pretty_wrapper(
  KC_ESC,   ________________NUMBER_L__________________,              ________________NUMBER_R__________________, KC_EQUAL,
  KC_TAB,   ________________WORKMAN_L1________________,              ________________WORKMAN_R1________________, KC_BSPACE,
  KC_LCTL,  ________________WORKMAN_L2________________,              ________________WORKMAN_R2________________, KC_QUOTE,
  KC_LSFT,  ________________WORKMAN_L3________________,              ________________WORKMAN_R3________________, KC_RSFT,
  ________________DOX_L4____________________,                                 ________________DOX_R4____________________,
                                        ________________DOXTHUMBS_________________
),

/* Keymap 4: Lower
 *
 * ,--------------------------------------------.                          ,-------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |                          |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |---------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |         |  !   |  @   |  #   |  $   |  %   |                          |  ^   |  &   |  *   |  (   |  )   |        |
 * |---------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |         |  1   |  2   |  3   |  4   |  5   |                          |  6   |  7   |  8   |  9   |  0   |        |
 * |---------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |         |  `   |  '   |  \   |  /   |  -   |                          |  =   |  [   |  ]   |  {   |  }   |        |
 * `---------+------+------+------+------+------'                          `------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                        |      |      |      |      |      |
 *   `-----------------------------------'                                        `----------------------------------'
 *                                            ,-------------.  ,-------------.
 *                                            |      |      |  |      |      |
 *                                     ,------|------|------|  |------+------+------.
 *                                     |      |      |      |  |      |      |      |
 *                                     |      |      |------|  |------|      |      |
 *                                     |      |      |      |  |      |      |      |
 *                                     `--------------------'  `--------------------'
 */
[_LOWER] = LAYOUT_dactyl_pretty_wrapper(
  _______, ________________FUNC_L____________________,              ________________FUNC_R____________________, _______,
  _______, ________________LOWER_L1__________________,              ________________LOWER_R1__________________, _______,
  _______, ________________LOWER_L2__________________,              ________________LOWER_R2__________________, _______,
  _______, ________________LOWER_L3__________________,              ________________LOWER_R3__________________, _______,
  _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______,
                                        ________________DOXTHUMBS_________________
),

/* Keymap 5: Raise
 *
 * ,--------------------------------------------.                          ,-------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |                          |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |---------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |         |PrScr | Back |  Up  | Fwd  | App  |                          |Insert|C-PgUp| PgUp |C-PgDn|GUI-L |        |
 * |---------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |         |ScrLk | Left | Down |Right |CapsLk|                          |Delete| Home | PgDn | End  |KVMSW1|        |
 * |---------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |         |Pause |      |      |      |      |                          |      |      |      |      |KVMSW2|        |
 * `---------+------+------+------+------+------'                          `------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                        |      |      |      |      |      |
 *   `-----------------------------------'                                        `----------------------------------'
 *                                            ,-------------.  ,-------------.
 *                                            |      |      |  |      |      |
 *                                     ,------|------|------|  |------+------+------.
 *                                     |      |      |      |  |      |      |      |
 *                                     |      |      |------|  |------|      |      |
 *                                     |      |      |      |  |      |      |      |
 *                                     `--------------------'  `--------------------'
 */
[_RAISE] = LAYOUT_dactyl_pretty_wrapper(
  _______, ________________FUNC_L____________________,              ________________FUNC_R____________________, _______,
  _______, ________________RAISE_L1__________________,              ________________RAISE_R1__________________, _______,
  _______, ________________RAISE_L2__________________,              ________________RAISE_R2__________________, _______,
  _______, ________________RAISE_L3__________________,              ________________RAISE_R3__________________, _______,
  _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______,
                                        ________________DOXTHUMBS_________________
),

/* Keymap 6: Adjust
 *
 * ,-------------------------------------------.                          ,-------------------------------------------.
 * |        |      |      |      |      |      |                          |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |        |RGBHUI|RGBSAI|RGBTOG|RGBVAI|RGBMOD|                          |RESET |      | EPRM |      | VRSN |        |
 * |--------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |        |BLSTEP|BL_DEC|BL_TOG|BL_INC|BLBRTG|                          |      |QWERTY|DVORAK|COLEMK|WRKMAN|        |
 * |--------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |        |RGBHUD|RGBSAD|RGBSPD|RGBVAD|RGBRMO|                          | MUTE |VOL_DN|VOL_UP| PLAY | NEXT |        |
 * `--------+------+------+------+------+------'                          `------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                        |      |      |      |      |      |
 *   `----------------------------------'                                        `----------------------------------'
 *                                           ,-------------.  ,-------------.
 *                                           |      |      |  |      |      |
 *                                    ,------|------|------|  |------+------+------.
 *                                    |      |      |      |  |      |      |      |
 *                                    |      |      |------|  |------|      |      |
 *                                    |      |      |      |  |      |      |      |
 *                                    `--------------------'  `--------------------'
 */
[_ADJUST] = LAYOUT_dactyl_pretty_wrapper(
  _______, ________________BLANK_____________________,              ________________BLANK_____________________, _______,
  _______, ________________ADJUST_L1_________________,              ________________ADJUST_R1_________________, _______,
  _______, ________________ADJUST_L2_________________,              ________________ADJUST_R2_________________, _______,
  _______, ________________ADJUST_L3_________________,              ________________ADJUST_R3_________________, _______,
  _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______,
                                        ________________DOXTHUMBS_________________
),

/* Keymap 7: GAME
 *
 * ,-------------------------------------------.                          ,-------------------------------------------.
 * |  Esc   |  `   |  1   |  2   |  3   |  4   |                          |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |   F1   | Tab  |  Q   |  W   |  E   |  R   |                          |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |   F2   |  G   |  A   |  S   |  D   |  F   |                          |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |   F3   |Shift |  Z   |  X   |  C   |  V   |                          |      |      |      |      |      |        |
 * `--------+------+------+------+------+------'                          `------+------+------+------+------+--------'
 *   |  F4  |  P   |  Y   |  I   |LOWER |                                        |      |      |      |      |      |
 *   `----------------------------------'                                        `----------------------------------'
 *                                           ,-------------.  ,-------------.
 *                                           | Ctrl |  B   |  |      |      |
 *                                    ,------|------|------|  |------+------+------.
 *                                    |      |      |  O   |  |      |      |      |
 *                                    |Space |  H   |------|  |------|GMCHAT|      |
 *                                    |      |      |  M   |  |      |      |      |
 *                                    `--------------------'  `--------------------'
 */
[_GAMEPAD] = LAYOUT_dactyl_pretty_wrapper(
  GP_LL0,  ________________GAMEPAD_L0________________,              ________________BLANK_____________________, _______,
  GP_LL1,  ________________GAMEPAD_L1________________,              ________________BLANK_____________________, _______,
  GP_LL2,  ________________GAMEPAD_L2________________,              ________________BLANK_____________________, _______,
  GP_LL3,  ________________GAMEPAD_L3________________,              ________________BLANK_____________________, _______,
  ________________GAMEPAD_L4________________,                               _______, _______, _______, _______, _______,
                                       ________________GP_DOXTHUMBS______________
),

/* Keymap 8: NUMPAD
 *
 * ,-------------------------------------------.                          ,-------------------------------------------.
 * |        |      |      |      |      |      |                          |      |NumLk |  /   |  *   |  -   |        |
 * |--------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                          |      |  7   |  8   |  9   |  +   |        |
 * |--------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                          |      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|                          |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                          |      |  1   |  2   |  3   |Enter |        |
 * `--------+------+------+------+------+------'                          `------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                        |  0   |  0   |  .   |Enter |      |
 *   `----------------------------------'                                        `----------------------------------'
 *                                           ,-------------.  ,-------------.
 *                                           |      |      |  |      |      |
 *                                    ,------|------|------|  |------+------+------.
 *                                    |      |      |      |  |      |      |      |
 *                                    |      |      |------|  |------|      |      |
 *                                    |      |      |      |  |      |      |      |
 *                                    `--------------------'  `--------------------'
 */
[_NUM] = LAYOUT_dactyl_pretty_wrapper(
  _______, ________________BLANK_____________________,              ________________NUMPAD_R0_________________, _______,
  _______, ________________BLANK_____________________,              ________________NUMPAD_R1_________________, _______,
  _______, ________________BLANK_____________________,              ________________NUMPAD_R2_________________, _______,
  _______, ________________BLANK_____________________,              ________________NUMPAD_R3_________________, _______,
  _______, _______, _______, _______, _______,                               ________________NUMPAD_R4_________________,
                                        ________________DOXTHUMBS_________________
),

};
// clang-format on
