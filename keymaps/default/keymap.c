#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TG(1),              // GP0 (Layer)
        LGUI(KC_PAGE_UP),   // GP2 (Up)
        LGUI(KC_PAGE_DOWN), // GP3 (Down)
        LGUI(KC_LEFT),      // GP4 (Left)
        LGUI(KC_RIGHT)      // GP5 (Right)
        ),
    [1] = LAYOUT(
        TG(1),              // GP0 (Layer)
        KC_UP,              // GP2 (Up)
        KC_DOWN,            // GP3 (Down)
        KC_LEFT,            // GP4 (Left)
        KC_RIGHT            // GP5 (Right)
        ),
};
