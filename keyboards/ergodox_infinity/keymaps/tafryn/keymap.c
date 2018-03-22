#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "./visualizer.h"

#define _______ KC_TRNS

#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_RCTL OSM(MOD_RCTL)
#define OSM_RALT OSM(MOD_RALT)
#define OSM_RGUI OSM(MOD_RGUI)

enum custom_layers {
    _QWERTY,
    _DVORAK,
    _COLEMAK,
    _WORKMAN,
    _GAME,
    _GAMECHAT,
    _MOUSE,
    _NUM,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    DVORAK,
    COLEMAK,
    WORKMAN,
    GAME,
    MOUSE,
    NUM,
    LOWER,
    RAISE,
    EPRM,
    VRSN,
    RGB_SLD,
    ALL_OFF,
    GAMECHAT,
    KVMSWP1,
    KVMSWP2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic QWERTY layer
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   -    |  1  |  2  |  3  |  4  |  5  | Esc  |           |Esc(`)|  6  |  7  |  8  |  9  |  0  |   =    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  E  |  R  |  T  |MOUSE |           | NUM  |  Y  |  U  |  I  |  O  |  P  |  BSPC  |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |  Ctrl  |  A  |  S  |  D  |  F  |  G  |------|           |------|  H  |  J  |  K  |  L  |  ;  |   '"   |
 * |--------+-----+-----+-----+-----+-----|  [{  |           |  ]}  |-----+-----+-----+-----+-----+--------|
 * | LShift |  Z  |  X  |  C  |  V  |  B  |      |           |      |  N  |  M  |  ,  |  .  |  /  | RShift |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   |OSM_C |OSM_A|OSM_G|Left |Right|                                     |Down |  Up |OSM_G|OSM_A|OSM_C |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,-----------.           ,-----------.
 *                                   |Ctrl | Alt |           | Alt |Ctrl |
 *                             ,-----|-----|-----|           |-----+-----+-----.
 *                             |BSPC |     |Lock |           |A_OFF|     |Space|
 *                             |     |LGUI |-----|           |-----|Enter|     |
 *                             |LOWER|     |RAISE|           |LOWER|     |RAISE|
 *                             `-----------------'           `-----------------'
 */
[_QWERTY] = LAYOUT_ergodox(
  // left hand
  KC_MINUS, KC_1,     KC_2,     KC_3,    KC_4,    KC_5, KC_ESC,
  KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T, TG(_MOUSE),
  KC_LCTL,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,
  KC_LSPO,  KC_Z,     KC_X,     KC_C,    KC_V,    KC_B, KC_LBRC,
  OSM_LCTL, OSM_LALT, OSM_LGUI, KC_LEFT, KC_RGHT,

                                                  KC_LCTL, KC_LALT,
                                                           KC_LOCK,
                            LT(_LOWER, KC_BSPC),  KC_LGUI, RAISE,

  // right hand
  KC_GESC,  KC_6, KC_7,    KC_8,    KC_9,     KC_0,      KC_EQUAL,
  TG(_NUM), KC_Y, KC_U,    KC_I,    KC_O,     KC_P,      KC_BSPACE,
            KC_H, KC_J,    KC_K,    KC_L,     KC_SCOLON, KC_QUOTE,
  KC_RBRC,  KC_N, KC_M,    KC_COMM, KC_DOT,   KC_SLSH,   KC_RSPC,
                  KC_DOWN, KC_UP,   OSM_RGUI, OSM_RALT,  OSM_RCTL,

  KC_RALT, KC_RCTL,
  ALL_OFF,
  LOWER,   KC_ENT,  LT(_RAISE, KC_SPACE)
),

/* Keymap 1: Basic Dvorak layer
 *
 * ,---------------------------------------------.           ,--------------------------------------------.
 * |  Esc   |  1  |  2  |  3  |  4  |  5  |  `   |           |  =   |  6  |  7  |  8  |  9  |  0  |   \    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  '  |  ,  |  .  |  P  |  Y  | Del  |           | NUM  |  F  |  G  |  C  |  R  |  L  |   /    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |  Ctrl  |  A  |  O  |  E  |  U  |  I  |------|           |------|  D  |  H  |  T  |  N  |  S  |   -    |
 * |--------+-----+-----+-----+-----+-----|  [{  |           |  ]}  |-----+-----+-----+-----+-----+--------|
 * | LShift |  ;  |  Q  |  J  |  K  |  X  |MOUSE |           |MOUSE |  B  |  M  |  W  |  V  |  Z  | RShift |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   |OSM_C |OSM_A|Left |Right|LOWER|                                     |RAISE|Down | Up  | Alt | Ctrl |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,-----------.           ,-----------.
 *                                   |Home | End |           |PgDn |PgUp |
 *                             ,-----|-----|-----|           |-----+-----+-----.
 *                             |     |     |Lock |           |A_OFF|     |     |
 *                             |BSPC |LGUI |-----|           |-----|Enter|Space|
 *                             |     |     |RAISE|           |LOWER|     |     |
 *                             `-----------------'           `-----------------'
 */
[_DVORAK] = LAYOUT_ergodox(
  // left hand
  KC_ESC,   KC_1,     KC_2,    KC_3,     KC_4,  KC_5, KC_GRV,
  KC_TAB,   KC_QUOT,  KC_COMM, KC_DOT,   KC_P,  KC_Y, KC_DEL,
  KC_LCTL,  KC_A,     KC_O,    KC_E,     KC_U,  KC_I,
  KC_LSPO,  KC_SCLN,  KC_Q,    KC_J,     KC_K,  KC_X, LT(_MOUSE, KC_LBRC),
  OSM_LCTL, OSM_LALT, KC_LEFT, KC_RIGHT, LOWER,

                                                KC_HOME, KC_END,
                                                         KC_LOCK,
                                       KC_BSPC, KC_LGUI, TT(_RAISE),

  // right hand
  KC_EQUAL,             KC_6, KC_7,  KC_8,    KC_9,     KC_0, KC_BSLS,
  TG(_NUM),             KC_F, KC_G,  KC_C,    KC_R,     KC_L, KC_SLSH,
                        KC_D, KC_H,  KC_T,    KC_N,     KC_S, KC_MINS,
  LT(_MOUSE, KC_RBRC),  KC_B, KC_M,  KC_W,    KC_V,     KC_Z, KC_RSPC,
                              RAISE, KC_DOWN, KC_UP, KC_LALT, KC_RCTL,

  KC_PGDN,    KC_PGUP,
  ALL_OFF,
  TT(_LOWER), KC_ENT,   KC_SPACE
),

/* Keymap 2: Basic Colemak layer
 *
 * ,---------------------------------------------.           ,--------------------------------------------.
 * |  Esc   |  1  |  2  |  3  |  4  |  5  | Esc  |           |Esc(`)|  6  |  7  |  8  |  9  |  0  |   =    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  F  |  P  |  G  |MOUSE |           | NUM  |  J  |  L  |  U  |  Y  |  ;  |   -    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |  Ctrl  |  A  |  R  |  S  |  T  |  D  |------|           |------|  H  |  N  |  E  |  I  |  O  |   '    |
 * |--------+-----+-----+-----+-----+-----|  [{  |           |  ]}  |-----+-----+-----+-----+-----+--------|
 * | LShift |  Z  |  X  |  C  |  V  |  B  |      |           |      |  K  |  M  |  ,  |  .  |  /  | RShift |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   |OSM_C |OSM_A|OSM_G|Left |Right|                                     |Down |  Up |OSM_G|OSM_A|OSM_C |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,-----------.           ,-----------.
 *                                   |Ctrl | Alt |           | Alt |Ctrl |
 *                             ,-----|-----|-----|           |-----+-----+-----.
 *                             |BSPC |     |Lock |           |A_OFF|     |Space|
 *                             |     |LGUI |-----|           |-----|Enter|     |
 *                             |LOWER|     |RAISE|           |LOWER|     |RAISE|
 *                             `-----------------'           `-----------------'
 */
[_COLEMAK] = LAYOUT_ergodox(
  // left hand
  KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5, KC_ESC,
  KC_TAB,   KC_Q,     KC_W,     KC_F,    KC_P,    KC_G, TG(_MOUSE),
  KC_LCTL,  KC_A,     KC_R,     KC_S,    KC_T,    KC_D,
  KC_LSPO,  KC_Z,     KC_X,     KC_C,    KC_V,    KC_B, KC_LBRC,
  OSM_LCTL, OSM_LALT, OSM_LGUI, KC_LEFT, KC_RGHT,

                                                  KC_LCTL, KC_LALT,
                                                           KC_LOCK,
                            LT(_LOWER, KC_BSPC),  KC_LGUI, RAISE,

  // right hand
  KC_GESC,  KC_6, KC_7,    KC_8,    KC_9,     KC_0,     KC_EQUAL,
  TG(_NUM), KC_J, KC_L,    KC_U,    KC_Y,     KC_SCLN,  KC_MINS,
            KC_H, KC_N,    KC_E,    KC_I,     KC_O,     KC_QUOT,
  KC_RBRC,  KC_K, KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSPC,
                  KC_DOWN, KC_UP,   OSM_RGUI, OSM_RALT, OSM_RCTL,

  KC_RALT, KC_RCTL,
  ALL_OFF,
  LOWER,   KC_ENT,  LT(_RAISE, KC_SPACE)
),

/* Keymap 3: Basic Workman layer
 *
 * ,---------------------------------------------.           ,--------------------------------------------.
 * |   -    |  1  |  2  |  3  |  4  |  5  | Esc  |           |Esc(`)|  6  |  7  |  8  |  9  |  0  |   =    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  D  |  R  |  W  |  B  |MOUSE |           | NUM  |  J  |  F  |  U  |  P  |  ;  |  BSPC  |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |  Ctrl  |  A  |  S  |  H  |  T  |  G  |------|           |------|  Y  |  N  |  E  |  O  |  I  |   '"   |
 * |--------+-----+-----+-----+-----+-----|  [{  |           |  ]}  |-----+-----+-----+-----+-----+--------|
 * | LShift |  Z  |  X  |  M  |  C  |  V  |      |           |      |  K  |  L  |  ,  |  .  |  /  | RShift |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   |OSM_C |OSM_A|OSM_G|Left |Right|                                     |Down |  Up |OSM_G|OSM_A|OSM_C |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,-----------.           ,-----------.
 *                                   |Ctrl | Alt |           | Alt |Ctrl |
 *                             ,-----|-----|-----|           |-----+-----+-----.
 *                             |BSPC |     |Lock |           |A_OFF|     |Space|
 *                             |     |LGUI |-----|           |-----|Enter|     |
 *                             |LOWER|     |RAISE|           |LOWER|     |RAISE|
 *                             `-----------------'           `-----------------'
 */
[_WORKMAN] = LAYOUT_ergodox(
  // left hand
  KC_MINUS, KC_1,     KC_2,     KC_3,    KC_4,    KC_5, KC_ESC,
  KC_TAB,   KC_Q,     KC_D,     KC_R,    KC_W,    KC_B, TG(_MOUSE),
  KC_LCTL,  KC_A,     KC_S,     KC_H,    KC_T,    KC_G,
  KC_LSPO,  KC_Z,     KC_X,     KC_M,    KC_C,    KC_V, KC_LBRC,
  OSM_LCTL, OSM_LALT, OSM_LGUI, KC_LEFT, KC_RGHT,

                                                  KC_LCTL, KC_LALT,
                                                           KC_LOCK,
                            LT(_LOWER, KC_BSPC),  KC_LGUI, RAISE,

  // right hand
  KC_GESC,  KC_6, KC_7,    KC_8,    KC_9,     KC_0,      KC_EQUAL,
  TG(_NUM), KC_J, KC_F,    KC_U,    KC_P,     KC_SCOLON, KC_BSPACE,
            KC_Y, KC_N,    KC_E,    KC_O,     KC_I,      KC_QUOTE,
  KC_RBRC,  KC_K, KC_L,    KC_COMM, KC_DOT,   KC_SLSH,   KC_RSPC,
                  KC_DOWN, KC_UP,   OSM_RGUI, OSM_RALT,  OSM_RCTL,

  KC_RALT, KC_RCTL,
  ALL_OFF,
  LOWER,   KC_ENT,  LT(_RAISE, KC_SPACE)
),

/* Keymap 4: Lower
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  !   |  @   |  #   |  $   |  %   |      |           |      |  ^   |  &   |  *   |  (   |  )   |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  1   |  2   |  3   |  4   |  5   |------|           |------|  6   |  7   |  8   |  9   |  0   |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  6   |  7   |  8   |  9   |  0   |      |           |      |  =   |  [   |  ]   |  {   |  }   |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.           ,-------------.
 *                                       |      |      |           |      |      |
 *                                ,------|------|------|           |------+------+------.
 *                                |      |      |      |           |      |      |      |
 *                                |      |      |------|           |------|      |      |
 *                                |      |      |      |           |      |      |      |
 *                                `--------------------'           `--------------------'
 */
[_LOWER] = LAYOUT_ergodox(
  // left hand
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, _______, _______, _______, _______,

                                       _______, _______,
                                                _______,
                              _______, _______, _______,

  // right hand
  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_EQL,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______,
                    _______, _______, _______, _______, _______,

  _______, _______,
  _______,
  _______, _______, _______
),

/* Keymap 5: Raise
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |PrScr |      |CPgUp |      | App  |      |           |      |      | Home |  Up  | PgUp |C-A-D |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |ScrLk | Back |CPgDn | Fwd  | Ins  |------|           |------|      | Left | Down |Right |KVMSW1|        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |Pause |      |      |      |CapsLk|      |           |      |      | End  |      | PgDn |KVMSW2|        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.           ,-------------.
 *                                       |      |      |           |      |      |
 *                                ,------|------|------|           |------+------+------.
 *                                |      |      |      |           |      |      |      |
 *                                |      |      |------|           |------|      |      |
 *                                |      |      |      |           |      |      |      |
 *                                `--------------------'           `--------------------'
 */
[_RAISE] = LAYOUT_ergodox(
  // left hand
  _______, KC_F1,   KC_F2,   KC_F3,         KC_F4,   KC_F5,   KC_F11,
  _______, KC_PSCR, _______, LCTL(KC_PGUP), _______, KC_APP,  _______,
  _______, KC_SLCK, KC_WBAK, LCTL(KC_PGDN), KC_WFWD, KC_INS,
  _______, KC_PAUS, _______, _______,       _______, KC_CAPS, _______,
  _______, _______, _______, _______,       _______,

                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  // right hand
  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,      _______,
  _______, _______, KC_HOME, KC_UP,   KC_PGUP, LCA(KC_DEL), _______,
           _______, KC_LEFT, KC_DOWN, KC_RGHT, KVMSWP1,     _______,
  _______, _______, KC_END,  _______, KC_PGDN, KVMSWP2,     _______,
                    _______, _______, _______, _______,     _______,

  _______, _______,
  _______,
  _______, _______,  _______
),

/* Keymap 6: Adjust
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |      |      |      |AG Nrm|AG Swp|Reset |           |Reset |TRM on|TRMoff|      | EPRM |Debug |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |BlTogg|BlStep|BlDec |BlInc |      |------|           |------|      |QWERTY|DVORAK|COLEMK|WRKMAN|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |BlOff |BlOn  |      |      |           |      | GAME |MOUSE | NUM  |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |      |      |
 *                               |      |      |------|           |------|      |      |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
[_ADJUST] = LAYOUT_ergodox(
  // left hand
  VRSN,    _______, _______, _______, AG_NORM, AG_SWAP, RESET,
  _______, _______, _______, _______, _______, _______, _______,
  _______, BL_TOGG, BL_STEP, BL_DEC,  BL_INC,  _______,
  _______, _______, _______, BL_OFF,  BL_ON,   _______, _______,
  _______, _______, _______, _______, _______,

                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  // right hand
  RESET,   TERM_ON,   TERM_OFF,   _______,  EPRM,    DEBUG,   _______,
  _______, _______,   _______,    _______,  _______, _______, _______,
           _______,   QWERTY,     DVORAK,   COLEMAK, WORKMAN, _______,
  _______, TO(_GAME), TO(_MOUSE), TO(_NUM), _______, _______, _______,
                      _______,    _______,  _______, _______, _______,

  _______, _______,
  _______,
  _______, _______,  _______
),

/* Keymap 7: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Rclk | MsUp | Lclk |Wh Up |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|Wh Dn |------|           |------| Prev |VolDn |VolUp | Next | Play |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |WhLeft| Mclk |WhRght|      |      |           |      |      | Mute |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |Wh Up |           |      |Brwser|Brwser|
 *                               | Lclk | Rclk |------|           |------|Back  |Fwd   |
 *                               |      |      |Wh Dn |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
// MOUSE
[_MOUSE] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
  _______, _______, KC_WH_L, KC_BTN3, KC_WH_R, _______, _______,
  _______, _______, _______, _______, _______,

                                       _______, _______,
                                                KC_WH_U,
                              KC_BTN1, KC_BTN2, KC_WH_D,

  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
           KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, _______,
  _______, _______, KC_MUTE, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,

  _______, _______,
  _______,
  _______, KC_WBAK, KC_WFWD
),

/* Keymap 8: GAME
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  `   |  1   |  2   |  3   |  4   |  5   |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   F1   | Tab  |  Q   |  W   |  E   |  R   |  T   |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   F2   |  G   |  A   |  S   |  D   |  F   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------| Alt  |           |      |------+------+------+------+------+--------|
 * |   F3   |Shift |  Z   |  X   |  C   |  V   |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  O   |  P   |  I   |  Y   |LOWER |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      | Ctrl |  B   |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      | Lock |           |      |      |      |
 *                               |Space |  H   |------|           |------|GMCHAT|      |
 *                               |      |      |  M   |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
[_GAME] = LAYOUT_ergodox(
  // left hand
  KC_ESC, KC_GRV,  KC_1, KC_2, KC_3,     KC_4, KC_5,
  KC_F1,  KC_TAB,  KC_Q, KC_W, KC_E,     KC_R, KC_T,
  KC_F2,  KC_G,    KC_A, KC_S, KC_D,     KC_F,
  KC_F3,  KC_LSFT, KC_Z, KC_X, KC_C,     KC_V, KC_LALT,
  KC_O,   KC_P,    KC_I, KC_Y, LOWER,

                                                  KC_LCTL, KC_B,
                                                           KC_LOCK,
                                        KC_SPACE, KC_H,    KC_M,

  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,

  _______, _______,
  _______,
  _______, GAMECHAT, _______
),

/* Keymap 9: GAME_CHAT
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |      |      |
 *                               |      |      |------|           |------|GMCHAT|      |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
[_GAMECHAT] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,

                                                  _______, _______,
                                                           _______,
                                         _______, _______, _______,

  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,

  _______, _______,
  _______,
  _______, GAMECHAT,  _______
),


/* Keymap 10: NUMPAD
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |NumLk |  /   |  *   |  -   |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   |Enter |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  0   |  .   |Enter |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |      |      |
 *                               |      |      |------|           |------|      |      |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
[_NUM] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,

                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  // right hand
  _______, _______, KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, _______,
  _______, _______, KC_KP_7,    KC_KP_8,     KC_KP_9,        KC_KP_PLUS,  _______,
           _______, KC_KP_4,    KC_KP_5,     KC_KP_6,        KC_KP_PLUS,  _______,
  _______, _______, KC_KP_1,    KC_KP_2,     KC_KP_3,        KC_KP_ENTER, _______,
                    KC_KP_0,    KC_KP_0,     KC_KP_DOT,      KC_KP_ENTER, _______,

  _______, _______,
  _______,
  _______, _______,  _______
),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
    case LOWER:
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
    case RAISE:
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
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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
    case ALL_OFF:
      layer_clear();
      return false;
      break;
    case GAMECHAT:
      if (record->event.pressed) {
        if (IS_LAYER_ON(_GAMECHAT)) {
          layer_clear();
          layer_on(_GAME);
          SEND_STRING(SS_TAP(X_ENTER));
        }
        else {
          layer_clear();
          layer_on(_GAMECHAT);
          SEND_STRING(SS_TAP(X_ENTER));
        }
      }
      return false;
      break;
    case KVMSWP1:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LCTRL)SS_TAP(X_LCTRL)"1");
      }
      return false;
      break;
    case KVMSWP2:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LCTRL)SS_TAP(X_LCTRL)"2");
      }
      return false;
      break;
  }
  return true;
}

/**
 * Runs just one time when the keyboard initializes.
 */
void matrix_init_user(void) {

};

/**
 * Runs constantly in the background, in a loop.
 */
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_led_lower_off();
  ergodox_led_raise_off();
  ergodox_led_adjust_off();

  switch (layer) {
    case _LOWER:
      ergodox_led_lower_on();
      break;
    case _RAISE:
      ergodox_led_raise_on();
      break;
    case _ADJUST:
      ergodox_led_adjust_on();
      break;
  }
};
