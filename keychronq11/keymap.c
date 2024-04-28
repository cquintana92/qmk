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

#include "/usr/share/qmkontext/qmkontext.h"


// clang-format off

enum layers{
   _LAYER_0,
   _LAYER_1,
   _LAYER_MOV,
};

enum custom_keycodes {
    MACRO_1 = SAFE_RANGE,
    MACRO_2,
    MACRO_3,
    MACRO_4,
    MACRO_5
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_LAYER_0] = LAYOUT_92_iso(
       KC_MUTE,         KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,       KC_F12,   KC_INS,   KC_DEL,   RGB_TOG,
       MACRO_1,         KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,      KC_EQL,   KC_BSPC,            KC_PGUP,
       MACRO_2,         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,      KC_RBRC,                      KC_PGDN,
       MACRO_3,         KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,      KC_NUHS,  KC_ENT,             KC_HOME,
       MACRO_4,         KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                KC_RSFT,  KC_UP,
       MACRO_5,         KC_LCTL,  KC_LWIN,  KC_LALT,  MO(_LAYER_1),       KC_SPC,                        KC_SPC,             KC_RALT,  MO(_LAYER_1), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

   [_LAYER_1] = LAYOUT_92_iso(
       RGB_TOG,         _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  QK_BOOT,  RGB_TOG,
       MACRO_1,         _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
       MACRO_2,         RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
       MACRO_3,         _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
       MACRO_4,         _______,  _______,  _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
       QK_BOOT,         _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

   [_LAYER_MOV] = LAYOUT_92_iso(
       _______,         _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
       _______,         _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
       _______,         _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
       _______,         _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
       KC_LSFT,         _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
       _______,         _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  KC_HOME,  _______,  KC_END),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_DIRECTIONS][NUM_DIRECTIONS] = {
   [_LAYER_0]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
   [_LAYER_1]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
   [_LAYER_MOV] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE

void enable_debug_mode(void) {
#if defined(CONSOLE_ENABLE)
#if defined(COMMAND_ENABLE)
    debug_enable=true;
    debug_matrix=true;
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
            return true;
    }
    return false;
}

// Init function
void keyboard_post_init_user(void) {
    enable_debug_mode();
    //setup_default_rgb();
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

void on_m1_pressed(uint8_t layer, bool pressed) {
    switch (layer) {
        // If is on layer 0, enable layer 1
        case _LAYER_0:
            layer_on(_LAYER_1);
            break;
        // If is on layer 1, disable layer 1
        case _LAYER_1:
            layer_off(_LAYER_1);
            break;
    }
}

void on_m2_pressed(uint8_t layer, bool pressed) {
    if (layer != _LAYER_0) return;
    switch (current_program) {
        case CURRENT_PROGRAM_ANDROID_STUDIO:
        case CURRENT_PROGRAM_RUST_ROVER:
        case CURRENT_PROGRAM_PHPSTORM:
        case CURRENT_PROGRAM_CLION:
            if (pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_F10)));
            }
            break;
        case CURRENT_PROGRAM_SLACK:
            if (pressed) {
                send_emoji("joy");
            }
            break;
    }
}

void on_m3_pressed(uint8_t layer, bool pressed) {
    if (layer != _LAYER_0) return;
    switch (current_program) {
        case CURRENT_PROGRAM_ANDROID_STUDIO:
        case CURRENT_PROGRAM_RUST_ROVER:
            if (pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_F9)));
            }
            break;
        case CURRENT_PROGRAM_SLACK:
            if (pressed) {
                send_emoji("tada");
            }
            break;
    }
}

void on_m4_pressed(uint8_t layer, bool pressed) {
    if (layer != _LAYER_0) return;
    if (!pressed) return;
    SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_PSCR))));
}

void on_m5_pressed(uint8_t layer, bool pressed) {
    switch (layer) {
        // If is on layer 0, enable layer 1
        case _LAYER_0:
            layer_on(_LAYER_MOV);
            break;
        // If is on layer 1, disable layer 1
        case _LAYER_MOV:
            layer_off(_LAYER_MOV);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t layer = get_highest_layer(layer_state);
    bool pressed = record->event.pressed;
    switch (keycode) {
    case MACRO_1:
        on_m1_pressed(layer, pressed);
        break;
    case MACRO_2:
        on_m2_pressed(layer, pressed);
        break;
    case MACRO_3:
        on_m3_pressed(layer, pressed);
        break;
    case MACRO_4:
        on_m4_pressed(layer, pressed);
        break;
    case MACRO_5:
        on_m5_pressed(layer, pressed);
        break;
    }
    return true;
};

// RGB
void set_key_color(uint8_t layer, led_t* led_state, uint8_t row, uint8_t col, uint8_t index) {
    uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col,row});

    // SPECIAL KEY CODES
    switch (keycode) {
        case QK_BOOT:
        rgb_matrix_sethsv(HSV_RED);
        return;
    }

    // If LAYER1 and the key has a keycode, paint it green
    if (layer == _LAYER_MOV) {
        rgb_matrix_set_color(index, RGB_BLUE);
        return;
    }

    if (layer == _LAYER_1) {
        if (keycode > KC_TRNS) {
            rgb_matrix_set_color(index, RGB_GREEN);
        }

        switch (keycode) {
            case MACRO_1:
                rgb_matrix_set_color(index, RGB_WHITE);
                break;
            default:
                rgb_matrix_set_color(index, RGB_ORANGE);
                break;
        }
        return;
    }

    // LAYER 0
    switch (keycode) {
        case MACRO_1:
            if (layer == _LAYER_0) {
                if (is_current_program_jetbrains()) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                } else if (current_program == CURRENT_PROGRAM_SLACK) {
                    rgb_matrix_set_color(index, RGB_YELLOW);
                }
            }
            break;
        case MACRO_2:
            if (layer == _LAYER_0) {
                if (is_current_program_jetbrains()) {
                    rgb_matrix_set_color(index, RGB_ORANGE);
                } else if (current_program == CURRENT_PROGRAM_SLACK) {
                    rgb_matrix_set_color(index, RGB_PINK);
                }
            }
            break;
        case MACRO_3:
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
            rgb_matrix_set_color(index, RGB_WHITE);
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

