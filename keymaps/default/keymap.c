#include QMK_KEYBOARD_H

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_BLUE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0:
        rgblight_sethsv_noeeprom(HSV_BLUE);
        break;
    case 1:
        rgblight_sethsv_noeeprom(HSV_GREEN);
        break;
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(TO(1),              // GP0 (Layer)
                 LGUI(KC_PAGE_DOWN), // GP2 (Down)
                 LGUI(KC_PAGE_UP),   // GP3 (Up)
                 LGUI(KC_RIGHT),     // GP4 (Right)
                 LGUI(KC_LEFT)       // GP5 (Left)
                 ),
    [1] = LAYOUT(TO(0),    // GP0 (Layer)
                 KC_DOWN,  // GP2 (Down)
                 KC_UP,    // GP3 (Up)
                 KC_RIGHT, // GP4 (Right)
                 KC_LEFT   // GP5 (Left)
                 ),
};
