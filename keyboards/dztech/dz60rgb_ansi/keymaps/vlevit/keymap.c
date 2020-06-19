#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
      Caps Lock = FN1
      RCTL Tap = Compose Key (KC_APP)
      +LCTL Tap = English layout+
      +LSFT Tap = Russian layout+
    */
    [0] = LAYOUT_60_ansi(
        KC_GESC,          KC_1,           KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,           KC_Q,           KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(1),            KC_A,           KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,           KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        LCTL_T(KC_LANG1), LGUI_T(KC_F20), KC_LALT,                            KC_SPC,                             KC_RALT, TT(1),   MO(2),   RCTL_T(KC_APP)
    ),
    /* VI + Emacs: C-hjkl, C-p, C-n, C-b, C-f */
    [1] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, KC_UP,   _______, _______, _______, KC_CALC, _______, KC_INS,  _______, KC_UP, KC_SLCK, KC_PAUS, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_RGHT, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,   KC_HOME, KC_PGUP,          _______,
        _______,          KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_LEFT, KC_DOWN, _______,  _______, KC_END,  KC_PGDN,          _______,
        _______, _______, _______,                            _______,                            _______,  _______, _______, _______
    ),
    [2] = LAYOUT_60_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, RGB_TOG, RGB_M_P, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, _______, RESET,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, MO(3)
    ),
    [3] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PWR, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )
};

void rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
        rgb_matrix_set_color(41, 0xFF, 0xFF, 0xFF);
    }
    if (host_keyboard_led_state().num_lock) {
        rgb_matrix_set_color(19, 0xFF, 0xFF, 0xFF);
    }
}
