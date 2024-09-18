/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define QMKENV mac

#if !defined(QMKENV)
#error "QMKENV is not defined. Please define it as 'linux' or 'mac'."
#elif (QMKENV != mac) && (QMKENV != linux)
#error "QMKENV must be defined as either 'mac' or 'linux'."
#endif

#if (QMKENV == mac)
#include "/usr/local/share/qmkontext/qmkontext.h"
#elif (QMKENV == linux)
#include "/usr/share/qmkontext/qmkontext.h"
#endif

#if defined(CONSOLE_ENABLE)
#if defined(COMMAND_ENABLE)
#include "print.h"
#endif
#endif

#include "action_layer.h"

enum {
    CURRENT_PROGRAM,
    MAX_COMMAND
} qmkontext_commands;

enum layers {
    _LAYER_MAC_0,
    _LAYER_MAC_1,
    _LAYER_LIN_0,
    _LAYER_LIN_1
};

enum custom_keycodes {
    QMK_TRI = SAFE_RANGE,
    QMK_SQUAR,
    QMK_CROSS
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define COMMAND_CURRENT_PROGRAM 1
#define CURRENT_PROGRAM_DEFAULT 0
#define CURRENT_PROGRAM_ANDROID_STUDIO 1
#define CURRENT_PROGRAM_CHROME 2
#define CURRENT_PROGRAM_RUST_ROVER 3
#define CURRENT_PROGRAM_CLION 4
#define CURRENT_PROGRAM_SLACK 5
#define CURRENT_PROGRAM_PHPSTORM 6
#define CURRENT_PROGRAM_PYCHARM 7

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER_MAC_0] = LAYOUT_iso_110(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_MUTE,  KC_PSCR, KC_SCRL, KC_PAUS,    TG(1),     QMK_TRI,  QMK_SQUAR, QMK_CROSS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,    KC_PSLS,  KC_PAST,   KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_DEL,  KC_END,  KC_PGDN,    KC_P7,     KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,                                 KC_P4,     KC_P5,    KC_P6,     KC_PPLS,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                     KC_UP,               KC_P1,     KC_P2,    KC_P3,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                KC_RALT,  KC_RCMD,  MO(1),    KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,               KC_PDOT,   KC_PENT
    ),
    [_LAYER_MAC_1] = LAYOUT_iso_110(
        //                                                                                                                                                                          O        TR       SQ         X
        _______,  KC_BRID,  KC_BRIU,  _______,  _______,  RGB_VAD,  RGB_VAI, KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_TOG,  _______, _______, RGB_TOG,    _______,   _______,  _______,   QK_BOOT,
        _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,    _______,   _______,  _______,   _______,
        _______,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______, _______,  _______,  _______,  _______,  _______,  _______,            _______, _______, _______,    _______,   _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,   _______,  _______,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______, NK_TOGG,  _______,  _______,  _______,  _______,  _______,                     _______,             _______,   _______,  _______,
        _______,  _______,  _______,  _______,                      _______,                               _______,  _______,  _______,  _______,  _______, _______, _______,                         _______,   _______
    ),
    [_LAYER_LIN_0] = LAYOUT_iso_110(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_MUTE,  KC_PSCR, KC_SCRL, KC_PAUS,    TG(3),     QMK_TRI,  QMK_SQUAR, QMK_CROSS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,    KC_PSLS,  KC_PAST,   KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_DEL,  KC_END,  KC_PGDN,    KC_P7,     KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,                                 KC_P4,     KC_P5,    KC_P6,     KC_PPLS,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                     KC_UP,               KC_P1,     KC_P2,    KC_P3,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                KC_RALT,  KC_RGUI,  MO(3),    KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,               KC_PDOT,   KC_PENT
    ),
    [_LAYER_LIN_1] = LAYOUT_iso_110(
        //                                                                                                                                                                          O        TR       SQ         X
        _______,  KC_BRID,  KC_BRIU,  _______,  _______,  RGB_VAD,  RGB_VAI, KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_TOG,  _______, _______, RGB_TOG,    _______,   _______,  _______,   QK_BOOT,
        _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,    _______,   _______,  _______,   _______,
        _______,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______, _______,  _______,  _______,  _______,  _______,  _______,            _______, _______, _______,    _______,   _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,   _______,  _______,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______, NK_TOGG,  _______,  _______,  _______,  _______,  _______,                     _______,             _______,   _______,  _______,
        _______,  _______,  _______,  _______,                      _______,                               _______,  _______,  _______,  _______,  _______, _______, _______,                         _______,   _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_LAYER_MAC_0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LAYER_MAC_1]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_LAYER_LIN_0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LAYER_LIN_1]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif

// clang-format on

bool is_mac(void) {
    return IS_LAYER_ON(_LAYER_MAC_0);
}

bool is_linux(void) {
    return IS_LAYER_ON(_LAYER_LIN_0);
}

void enable_debug_mode(void) {
#if defined(CONSOLE_ENABLE)
#if defined(COMMAND_ENABLE)
    debug_enable = true;
    debug_matrix = true;
#endif
#endif
}

void setup_default_rgb(void) {
    // Set RGB to known state
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

uint8_t current_program = CURRENT_PROGRAM_DEFAULT;
bool on_current_program(uint8_t program) {
    current_program = program;
    return true;
}

bool is_current_program_jetbrains(void) {
    switch (current_program) {
        case CURRENT_PROGRAM_ANDROID_STUDIO:
        case CURRENT_PROGRAM_CLION:
        case CURRENT_PROGRAM_PHPSTORM:
        case CURRENT_PROGRAM_RUST_ROVER:
        case CURRENT_PROGRAM_PYCHARM:
            return true;
    }
    return false;
}

// Init function
void keyboard_post_init_user(void) {
    enable_debug_mode();
    setup_default_rgb();
    qmkontext_init();
    qmkontext_register_callback(COMMAND_CURRENT_PROGRAM, on_current_program);
}

void raw_hid_receive(uint8_t* data, uint8_t length) {
    if (qmkontext_on_receive(data, length)) return;
}

// Macros
void send_emoji(const char* emoji) {
    SEND_STRING(SS_LSFT(SS_TAP(X_DOT)));
    send_string(emoji);
    SEND_STRING(SS_LSFT(SS_TAP(X_DOT)));
}

void on_triangle_press(uint8_t layer, bool pressed) {
    if (!pressed) return;
    if (layer == _LAYER_MAC_0 || layer == _LAYER_LIN_0) {
        switch (current_program) {
            case CURRENT_PROGRAM_ANDROID_STUDIO:
            case CURRENT_PROGRAM_PHPSTORM:
            case CURRENT_PROGRAM_CLION:
            case CURRENT_PROGRAM_RUST_ROVER:
            case CURRENT_PROGRAM_PYCHARM:
                if (is_mac()) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_R)));
                } else if (is_linux()) {
                    SEND_STRING(SS_LSFT(SS_TAP(X_F10)));
                }
                break;
            case CURRENT_PROGRAM_SLACK:
                send_emoji("joy");
                break;
        }
    }
}

void on_square_press(uint8_t layer, bool pressed) {
    if (!pressed) return;
    if (layer == _LAYER_MAC_0 || layer == _LAYER_LIN_0) {
        switch (current_program) {
            case CURRENT_PROGRAM_ANDROID_STUDIO:
            case CURRENT_PROGRAM_PHPSTORM:
            case CURRENT_PROGRAM_CLION:
            case CURRENT_PROGRAM_RUST_ROVER:
            case CURRENT_PROGRAM_PYCHARM:
                if (is_mac()) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_R)));
                } else if (is_linux()) {
                    SEND_STRING(SS_LSFT(SS_TAP(X_F9)));
                }
                break;
            case CURRENT_PROGRAM_SLACK:
                send_emoji("tada");
                break;
        }
    }
}

void on_cross_press(uint8_t layer, bool pressed) {
    if (!pressed) return;
    if (is_mac()) {
        dprint("on_cross_press: Mac\n");
        SEND_STRING(SS_LCTL(SS_LSFT(SS_LCMD(SS_TAP(X_4)))));
    } else if (is_linux()) {
        dprint("on_cross_press: Linux\n");
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_PSCR))));
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    uint8_t layer = get_highest_layer(layer_state);
    bool pressed = record->event.pressed;
    switch (keycode) {
        case QMK_TRI:
            on_triangle_press(layer, pressed);
            break;
        case QMK_SQUAR:
            on_square_press(layer, pressed);
            break;
        case QMK_CROSS:
            on_cross_press(layer, pressed);
            break;
    }
    return true;
};

// RGB
void set_key_color(uint8_t layer, led_t* led_state, uint8_t row, uint8_t col, uint8_t index) {
    uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});

    // If LAYER1 and the key has a keycode, paint it green
    if (layer == _LAYER_MAC_1 || layer == _LAYER_LIN_1) {
        if (keycode > KC_TRNS) {
            rgb_matrix_set_color(index, RGB_GREEN);
        }
    }

    switch (keycode) {
        case QMK_TRI:
            if (layer == _LAYER_MAC_0 || layer == _LAYER_LIN_0) {
                if (is_current_program_jetbrains()) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                } else if (current_program == CURRENT_PROGRAM_SLACK) {
                    rgb_matrix_set_color(index, RGB_YELLOW);
                }
            }
            break;
        case QMK_SQUAR:
            if (layer == _LAYER_MAC_0 || layer == _LAYER_LIN_0) {
                if (is_current_program_jetbrains()) {
                    rgb_matrix_set_color(index, RGB_ORANGE);
                } else if (current_program == CURRENT_PROGRAM_SLACK) {
                    rgb_matrix_set_color(index, RGB_PINK);
                }
            }
            break;
        case QMK_CROSS:
            rgb_matrix_set_color(index, RGB_PURPLE);
            break;
        case QK_BOOT:
            rgb_matrix_set_color(index, RGB_RED);
            break;
        case KC_CAPS:
            if (led_state->caps_lock) {
                rgb_matrix_set_color(index, RGB_RED);
            }
            break;
        case KC_NUM:
            if (!led_state->num_lock) {
                rgb_matrix_set_color(index, RGB_OFF);
            }
        default:
            break;
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);
    led_t led_state = host_keyboard_led_state();
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index >= led_min && index < led_max && index != NO_LED) {
                set_key_color(layer, &led_state, row, col, index);
            }
        }
    }

    return false;
}
