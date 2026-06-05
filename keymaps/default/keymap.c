#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TG(1),              // GP0 (Layer)
        LGUI(KC_PAGE_DOWN), // GP2 (Down)
        LGUI(KC_PAGE_UP),   // GP3 (Up)
        LGUI(KC_RIGHT),     // GP4 (Right)
        LGUI(KC_LEFT)       // GP5 (Left)
        ),
    [1] = LAYOUT(
        TG(1),              // GP0 (Layer)
        KC_DOWN,            // GP2 (Down)
        KC_UP,              // GP3 (Up)
        KC_RIGHT,           // GP4 (Right)
        KC_LEFT             // GP5 (Left)
        ),
};
