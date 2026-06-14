#include QMK_KEYBOARD_H

enum custom_keycodes {
    HAT_UP = QK_USER_0,
    HAT_DOWN,
    HAT_LEFT,
    HAT_RIGHT,
};

const uint16_t PROGMEM boot_combo[] = {KC_MUTE, KC_MPLY, COMBO_END};
combo_t                key_combos[] = {
    COMBO(boot_combo, QK_BOOT),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        if (keycode == HAT_UP || keycode == HAT_DOWN || keycode == HAT_LEFT || keycode == HAT_RIGHT) {
            joystick_set_hat(JOYSTICK_HAT_CENTER);
            joystick_flush();
            return false;
        }
        return true;
    }

    switch (keycode) {
        case HAT_UP:
            joystick_set_hat(JOYSTICK_HAT_NORTH);
            joystick_flush();
            return false;
        case HAT_DOWN:
            joystick_set_hat(JOYSTICK_HAT_SOUTH);
            joystick_flush();
            return false;
        case HAT_LEFT:
            joystick_set_hat(JOYSTICK_HAT_WEST);
            joystick_flush();
            return false;
        case HAT_RIGHT:
            joystick_set_hat(JOYSTICK_HAT_EAST);
            joystick_flush();
            return false;
    }
    return true;
}

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_BLUE);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_A,      // GP0  - Button 1
                 KC_B,      // GP1  - Button 0
                 KC_C,      // GP28 - Button 2
                 KC_D,      // GP29 - Button 3
                 KC_MUTE,   // GP7  - Enc 0 Switch
                 KC_F20,    // GP4  - Enc 1 Switch
                 HAT_LEFT,  // GP9  - Joy Left
                 HAT_RIGHT, // GP10 - Joy Right
                 HAT_DOWN,  // GP11 - Joy Down
                 HAT_UP     // GP12 - Joy Up
                 ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
};
#endif
