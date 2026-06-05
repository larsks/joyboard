#include QMK_KEYBOARD_H

enum custom_keycodes {
    HAT_UP = QK_USER_0,
    HAT_DOWN,
    HAT_LEFT,
    HAT_RIGHT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case HAT_UP:
        joystick_set_hat(record->event.pressed ? JOYSTICK_HAT_NORTH : JOYSTICK_HAT_CENTER);
        joystick_flush();
        return false;
    case HAT_DOWN:
        joystick_set_hat(record->event.pressed ? JOYSTICK_HAT_SOUTH : JOYSTICK_HAT_CENTER);
        joystick_flush();
        return false;
    case HAT_LEFT:
        joystick_set_hat(record->event.pressed ? JOYSTICK_HAT_WEST : JOYSTICK_HAT_CENTER);
        joystick_flush();
        return false;
    case HAT_RIGHT:
        joystick_set_hat(record->event.pressed ? JOYSTICK_HAT_EAST : JOYSTICK_HAT_CENTER);
        joystick_flush();
        return false;
    }
    return true;
}

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
    case 2:
        rgblight_sethsv_noeeprom(HSV_RED);
        break;
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(TO(1),             // GP0 (Layer)
                 LGUI(KC_PAGE_DOWN), // GP2 (Down)
                 LGUI(KC_PAGE_UP),   // GP3 (Up)
                 LGUI(KC_RIGHT),     // GP4 (Right)
                 LGUI(KC_LEFT)       // GP5 (Left)
                 ),
    [1] = LAYOUT(TO(2),    // GP0 (Layer)
                 KC_DOWN,  // GP2 (Down)
                 KC_UP,    // GP3 (Up)
                 KC_RIGHT, // GP4 (Right)
                 KC_LEFT   // GP5 (Left)
                 ),
    [2] = LAYOUT(TO(0),     // GP0 (Layer)
                 HAT_DOWN,  // GP2 (Down)
                 HAT_UP,    // GP3 (Up)
                 HAT_RIGHT, // GP4 (Right)
                 HAT_LEFT   // GP5 (Left)
                 ),
};
