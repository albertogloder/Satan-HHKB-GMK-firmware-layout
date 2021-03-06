#include "satan.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

// Fillers to make layering more clear
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| \ | ~ |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|bksp |
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift| fn |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN  |Ctrl |
   * `-----------------------------------------------------------'
   */
[_BL] = KEYMAP_HHKB(
  KC_GRV,  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FL), \
  KC_NO, KC_LCTL, KC_LALT,          KC_SPC,                                               KC_NO, KC_LGUI, KC_RALT, KC_NO),

[_FL] = KEYMAP_HHKB(
  #ifdef RGBLIGHT_ENABLE
  KC_PSCR, KC_BSLS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGUP, \
  _______, _______, KC_UP, _______, _______, _______, KC_CALC, _______, _______, _______, KC_UP, KC_HOME,   KC_END, KC_PGDN,  \
  _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT,          KC_RETURN, \
  _______,          KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC, _______, _______, \
  KC_NO, _______, _______,                   KC_MPLY,                                     KC_NO, _______, _______, KC_NO),
  #else
  KC_PSCR, KC_BSLS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGUP, \
  _______, _______, KC_UP, _______, _______, _______, KC_CALC, _______, _______, _______, KC_UP, KC_HOME,   KC_END, KC_PGDN,  \
  _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT,          KC_RETURN, \
  _______,          KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC, _______, _______, \
  KC_NO, _______, _______,                   KC_MPLY,                                     KC_NO, _______, _______, KC_NO),
  #endif
};