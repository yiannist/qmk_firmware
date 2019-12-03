#include QMK_KEYBOARD_H

// An atreus-like, Portuguese-friendly keyboard mapping

enum mitosis_layers
  {
   _xQ, // qwerty
   _xN, // numbers
   _xF  // functions
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   *  q    w      e      r      t        ||        y     u    i     o     p
   *  a    s      d      f      g        ||        h     j    k     l     ç
   *  z    x      c      v      b        ||        n     m    ,     .     ;
   *      esc    ralt  shift   ctrl      ||       alt   del  ins  enter
   *      FN2    tab   super   bksp      ||      space  FN1   ´     ~
   */
  [_xQ] = LAYOUT(
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,
      /*,   */ KC_ESC,  KC_RALT, KC_LSFT, KC_LCTL,     KC_LALT, KC_DEL,  KC_INS,  KC_ENT,
      /*,   */ MO(_xF), KC_TAB,  KC_LGUI, KC_BSPC,     KC_SPC,  MO(_xN), KC_LBRC, KC_QUOT),
  /*
   *  !     @      up     {     }        ||     pgup    7     8     9    *
   *  #    left   down  right   $        ||     pgdn    4     5     6    +
   *  [     ]      (      )     &        ||       '     1     2     3    \
   *       esc    ralt  shift  ctrl      ||      alt   del   ins    =
   *       FN2    tab   super  bksp      ||     space  FN1    -     0
   */
  [_xN] = LAYOUT(
      KC_EXLM, KC_AT,   KC_UP,   KC_RCBR,  KC_PIPE,    KC_PGUP, KC_7,    KC_8,    KC_9,     KC_ASTR,
      KC_HASH, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DLR,     KC_PGDN, KC_4,    KC_5,    KC_6,     KC_PLUS,
      KC_RBRC, KC_BSLS, KC_LPRN, KC_RPRN,  KC_AMPR,    KC_GRV,  KC_1,    KC_2,    KC_3,     KC_NUBS,
      /*,   */ _______, _______, _______, _______,     _______, _______, _______, KC_EQL,
      /*,   */ _______, _______, _______, _______,     _______, _______, KC_MINS, KC_0),
  /*
   *  !     @      up     <     >        ||     vol+    F7    F8    F9    F10
   *  #    left   down  right   $        ||     vol-    F4    F5    F6    F11
   *  [     ]      (      )     &        ||      -      F1    F2    F3    F12
   *      reset   ralt  shift  ctrl      ||     alt     del   ins  enter
   *       FN2    tab   super  bksp      ||    space    FN1    ´     ~
   */
  [_xF] = LAYOUT(
      KC_EXLM, KC_AT,   KC_UP,   KC_LT,    KC_GT,       KC_VOLU, KC_F7,   KC_F8,   KC_F9,    KC_F10,
      KC_HASH, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DLR,      KC_VOLD, KC_F4,   KC_F5,   KC_F6,    KC_F11,
      KC_RBRC, KC_BSLS, KC_LPRN, KC_RPRN,  KC_AMPR,     KC_MINS, KC_F1,   KC_F2,   KC_F3,    KC_F12,
      /*,   */ RESET,   _______, _______, _______,     _______, _______, _______, _______,
      /*,   */ _______, _______, _______, _______,     _______, _______, _______, _______),
};

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  switch (layer) {
  case _xQ:
    set_led_off;
    break;
  case _xN:
    set_led_magenta;
    break;
  case _xF:
    set_led_yellow;
    break;
  default:
    break;
  }
};
