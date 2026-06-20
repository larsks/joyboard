#include QMK_KEYBOARD_H

enum custom_keycodes {
    HAT_UP = QK_USER_0,
    HAT_DOWN,
    HAT_LEFT,
    HAT_RIGHT,
    MICMUTE,
    SAVE_LAYER,
};

const uint16_t PROGMEM boot_combo[] = {KC_MUTE, MICMUTE, COMBO_END};
combo_t                key_combos[] = {
    COMBO(boot_combo, QK_BOOT),
};

void keyboard_post_init_user(void) {
    uint8_t saved_layer = eeconfig_read_user();
    if (saved_layer > 0 && saved_layer < 3) {
        layer_move(saved_layer);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    joystick_set_hat(JOYSTICK_HAT_CENTER);
    joystick_flush();
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool retval = true;

    // Toggle switches: let QMK handle layer keycodes; tap others once
    if (record->event.key.col >= 10 && record->event.key.col <= 13) {
        if (IS_QK_TO(keycode)) {
            return true;
        }
        if (record->event.pressed) {
            if (keycode == SAVE_LAYER) {
                eeconfig_update_user(get_highest_layer(layer_state));
            } else {
                tap_code16(keycode);
            }
        }
        return false;
    }

    if (!record->event.pressed) {
        if (keycode == HAT_UP || keycode == HAT_DOWN || keycode == HAT_LEFT || keycode == HAT_RIGHT) {
            joystick_set_hat(JOYSTICK_HAT_CENTER);
            joystick_flush();
            retval = false;
        } else if (keycode == MICMUTE) {
            host_system_send(0);
            retval = false;
        }
        return retval;
    }

    switch (keycode) {
        case HAT_UP:
            joystick_set_hat(JOYSTICK_HAT_NORTH);
            retval = false;
            break;
        case HAT_DOWN:
            joystick_set_hat(JOYSTICK_HAT_SOUTH);
            retval = false;
            break;
        case HAT_LEFT:
            joystick_set_hat(JOYSTICK_HAT_WEST);
            retval = false;
            break;
        case HAT_RIGHT:
            joystick_set_hat(JOYSTICK_HAT_EAST);
            retval = false;
            break;
        case MICMUTE:
            host_system_send(0xA9);
            retval = false;
            break;
    }
    joystick_flush();
    return retval;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Joystick
    LAYOUT(        //
        JS_0,      // GP28 - Button 0
        JS_1,      // GP29 - Button 1
        JS_2,      // GP1  - Button 2
        JS_3,      // GP0  - Button 3
        HAT_UP,    // GP12 - Joy Up
        HAT_DOWN,  // GP11 - Joy Down
        HAT_RIGHT, // GP10 - Joy Right
        HAT_LEFT,  // GP9  - Joy Left
        KC_MUTE,   // GP4  - Enc 0 Switch
        MICMUTE,   // GP7  - Enc 1 Switch
        TO(2),     // GP14 - Toggle 0 A
        TO(1),     // GP15 - Toggle 0 B
        TO(0),     // GP26 - Toggle 1 A
        SAVE_LAYER // GP27 - Toggle 1 B
        ),

    // Arrow keys
    LAYOUT(             //
        KC_F13,         // GP28 - Button 0
        KC_F14,         // GP29 - Button 1
        KC_F15,         // GP1  - Button 2
        KC_F16,         // GP0  - Button 3
        LGUI(KC_UP),    // GP12 - Joy Up
        LGUI(KC_DOWN),  // GP11 - Joy Down
        LGUI(KC_RIGHT), // GP10 - Joy Right
        LGUI(KC_LEFT),  // GP9  - Joy Left
        KC_TRNS,        // GP4  - Enc 0 Switch
        KC_TRNS,        // GP7  - Enc 1 Switch
        TO(0),          // GP14 - Toggle 0 A
        TO(2),          // GP15 - Toggle 0 B
        TO(0),          // GP26 - Toggle 1 A (unmapped)
        SAVE_LAYER      // GP27 - Toggle 1 B (save default layer)
        ),

    // Desktop control
    LAYOUT(             //
        KC_TRNS,        // GP28 - Button 0
        KC_TRNS,        // GP29 - Button 1
        KC_TRNS,        // GP1  - Button 2
        KC_TRNS,        // GP0  - Button 3
        LGUI(KC_PGUP),  // GP12 - Joy Up
        LGUI(KC_PGDN),  // GP11 - Joy Down
        LGUI(KC_RIGHT), // GP10 - Joy Right
        LGUI(KC_LEFT),  // GP9  - Joy Left
        KC_TRNS,        // GP4  - Enc 0 Switch
        KC_TRNS,        // GP7  - Enc 1 Switch
        TO(0),          // GP14 - Toggle 0 A
        TO(2),          // GP15 - Toggle 0 B
        TO(0),          // GP26 - Toggle 1 A (unmapped)
        SAVE_LAYER      // GP27 - Toggle 1 B (save default layer)
        ),

    // Browser control
    LAYOUT(            //
        KC_TRNS,       // GP28 - Button 0
        KC_TRNS,       // GP29 - Button 1
        KC_TRNS,       // GP1  - Button 2
        KC_TRNS,       // GP0  - Button 3
        KC_UP,         // GP12 - Joy Up
        KC_DOWN,       // GP11 - Joy Down
        LCTL(KC_PGDN), // GP10 - Joy Right
        LCTL(KC_PGUP), // GP9  - Joy Left
        KC_TRNS,       // GP4  - Enc 0 Switch
        KC_TRNS,       // GP7  - Enc 1 Switch
        TO(1),         // GP14 - Toggle 0 A
        TO(0),         // GP15 - Toggle 0 B
        TO(0),         // GP26 - Toggle 1 A (unmapped)
        SAVE_LAYER     // GP27 - Toggle 1 B (save default layer)
        ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    {ENCODER_CCW_CW(KC_BRID, KC_BRIU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    {ENCODER_CCW_CW(KC_BRID, KC_BRIU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    {ENCODER_CCW_CW(KC_BRID, KC_BRIU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    {ENCODER_CCW_CW(KC_BRID, KC_BRIU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif
