/*
 *  QMK Firmware 0.6.93
 *  DZ60 ISO French keymap
 */

#include QMK_KEYBOARD_H

// DZ60 PCB
#include "dz60.h"
// The french keymap header allows use of FR_* keycodes (see keymap_french.h)
#include "keymap_french.h"

/* ISO Layout key sizes (62 keys) (Ducky Channel)
 * .--------------------------------------------------------------------------.
 * |1   |1   |1   |1   |1   |1   |1   |1   |1   |1   |1   |1   |1   |2        |
 * |--------------------------------------------------------------------------|
 * |1.5   |1   |1   |1   |1   |1   |1   |1   |1   |1   |1   |1   |1   |1.5    |
 * |-------------------------------------------------------------------.      |
 * |1.75   |1   |1   |1   |1   |1   |1   |1   |1   |1   |1   |1   |1   |1.25  |
 * |--------------------------------------------------------------------------|
 * |1.25 |1   |1   |1   |1   |1   |1   |1   |1   |1   |1   |1   |2.75         |
 * |--------------------------------------------------------------------------|
 * |1.25 |1.25 |1.25 |6.25                            |1.25 |1.25 |1.25 |1.25 |
 * '--------------------------------------------------------------------------'
 */

/* _BL: Base Layer (default layer)
 * .--------------------------------------------------------------------------.
 * |Esc |&   |é   |"   |'   |(   |-   |è   |_   |ç   |à   |)   |=   |Backspace|
 * |--------------------------------------------------------------------------|
 * |Tab   |A   |Z   |E   |R   |T   |Y   |U   |I   |O   |P   |^   |$   |       |
 * |-------------------------------------------------------------------.      |
 * |CapsLck|Q   |S   |D   |F   |G   |H   |J   |K   |L   |M   |ù   |*   |Enter |
 * |--------------------------------------------------------------------------|
 * |Shift|<   |W   |X   |C   |V   |B   |N   |,   |;   |:   |!   |Shift        |
 * |--------------------------------------------------------------------------|
 * |Ctrl |Win  |Alt  |Space                           |AltGr|Win  |Fn   |Ctrl |
 * '--------------------------------------------------------------------------'
 */
#define _BL 0

/* _FL: Function Layer
 * .--------------------------------------------------------------------------.
 * |²   |F1  |F2  |F3  |F4  |F5  |F6  |F7  |F8  |F9  |F10 |F11 |F12 |Reset    |
 * |--------------------------------------------------------------------------|
 * |      |Home|    |Up  |    |PgUp|    |    |Ins |    |PrSc|Lgt+|Vol+|       |
 * |-------------------------------------------------------------------.      |
 * |       |End |Lft |Dwn |Rgt |PgDn|    |    |    |    |    |Lgt-|Vol-|      |
 * |--------------------------------------------------------------------------|
 * |     |    |    |    |    |Del |    |    |    |    |    |    |             |
 * |--------------------------------------------------------------------------|
 * |     |     |     |                                |     |     |     |     |
 * '--------------------------------------------------------------------------'
 */
#define _FL 1

// Keymap (keycodes: https://docs.qmk.fm/keycodes.html)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BL] = LAYOUT_60_iso(
    KC_ESC,  FR_AMP,  FR_EACU, FR_QUOT, FR_APOS, FR_LPRN, FR_MINS, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN, FR_EQL,  KC_BSPC, \
    KC_TAB,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    FR_CIRC, FR_DLR, \
    KC_CAPS, FR_Q,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    FR_M,    FR_UGRV, FR_ASTR, KC_ENT, \
    KC_LSFT, FR_LESS, FR_W,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EXLM, KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT,                             KC_SPC,                            KC_RALT, KC_RGUI, MO(_FL), KC_RCTL ),

  [_FL] = LAYOUT_60_iso(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,     KC_F6,   KC_F7,   KC_F8,     KC_F9,   KC_F10,     KC_F11,  KC_F12,            RESET, \
    KC_TRNS, KC_HOME, KC_TRNS, KC_UP,   KC_TRNS,  KC_PGUP,   KC_TRNS, KC_TRNS, KC_INSERT, KC_TRNS, KC_PSCREEN, BL_INC,  KC_AUDIO_VOL_UP, \
    KC_TRNS, KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,    BL_DEC,  KC_AUDIO_VOL_DOWN, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_DELETE, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS, KC_MUTE, \
    KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS,                               KC_TRNS,    KC_TRNS, KC_TRNS,           KC_TRNS ),

};
