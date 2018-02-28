// QMK Firmware Satan GH60 French ISO keymap
#include "satan.h"
#include "keymap_french.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0 // Base Layer
#define _FL 1 // Function Layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap _BL: Base Layer (Default Layer)
 * ,-----------------------------------------------------------.
 * |Esc²| &|  é|  "|  '|  (|  -|  è|  _|  ç|  à|  )|  =| Backsp|
 * |-----------------------------------------------------------|
 * |Tab  |  A|  Z|  E|  R|  T|  Y|  U|  I|  O|  P|  ^|  $| Entr|
 * |-------------------------------------------------------    |
 * |CAPS   |  Q|  S|  D|  F|  G|  H|  J|  K|  L|  M|  %|  *|   |
 * |-----------------------------------------------------------|
 * |Shft| \ |  W|  X|  C|  V|  B|  N|  ,|  ;|  :|  !|Shift     |
 * |-----------------------------------------------------------|
 * |Ctrl|Win |Alt |      Space            |Alt |Win |Fn  |Ctrl |
 * `-----------------------------------------------------------'
 */

[_BL] = KEYMAP_ISO_SPLITRSHIFT(
  F(0),    FR_AMP,  FR_EACU, FR_QUOT, FR_APOS, FR_LPRN, FR_MINS, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN, FR_EQL,  KC_BSPC, \
  KC_TAB,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    FR_CIRC, FR_DLR,  KC_NO, \
  KC_CAPS, FR_Q,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    FR_M,    FR_UGRV, FR_ASTR, KC_ENT,  \
  KC_LSFT, FR_LESS, FR_W,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EXLM, KC_RSFT, KC_NO, \
  KC_LCTL, KC_LGUI, KC_LALT,                             KC_SPC,                            KC_RALT, KC_RGUI, MO(_FL), KC_RCTL ),

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * |Rst| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   Del |
   * |-----------------------------------------------------------|
   * |     |   |   | Up|   |   |   |   |   |   |Prt|BL+|Vo+|     |
   * |-------------------------------------------------------    |
   * |       |   |Lft|Dwn|Rgt|   |   |   |   |   |   |BL-|Vo-|   |
   * |-----------------------------------------------------------|
   * |    |   |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                       |    |    |    |     |
   * `-----------------------------------------------------------'
   */
[_FL] = KEYMAP_ISO_SPLITRSHIFT(
  #ifdef RGBLIGHT_ENABLE
  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DELETE, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_INC,  KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC,  BL_TOGG, \
  KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ),
  #else
  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,     KC_F11,  KC_F12,            KC_DELETE, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCREEN, BL_INC,  KC_AUDIO_VOL_UP,   KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    BL_DEC,  KC_AUDIO_VOL_DOWN, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,           KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS,                               KC_TRNS,    KC_TRNS, KC_TRNS,           KC_TRNS ),
  #endif
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(FR_SUP2);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(FR_SUP2);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
