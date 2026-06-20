#include QMK_KEYBOARD_H

enum custom_keycodes {
    HAT_UP = QK_USER_0,
    HAT_DOWN,
    HAT_LEFT,
    HAT_RIGHT,
    MICMUTE,
    SAVE_LAYER,
    NEXT_LAYER,
    PREV_LAYER,
    SHOW_LAYER,
};

#define NUM_LAYERS 4
#define SYSTEM_MICROPHONE_MUTE 0xA9

// Press both encoder buttons to enter BOOTSEL mode
const uint16_t PROGMEM boot_combo[] = {KC_MUTE, MICMUTE, COMBO_END};

// Press blue arcade buttons to type out the current layer number
const uint16_t PROGMEM layer_combo[] = {JS_0, JS_1, COMBO_END};

combo_t key_combos[] = {
    COMBO(boot_combo, QK_BOOT),
    COMBO(layer_combo, SHOW_LAYER),
};

// Always resolve combos from layer 0.
uint8_t combo_ref_from_layer(uint8_t layer) {
    return 0;
}

void keyboard_post_init_user(void) {
    // Restore active layer from flash
    uint8_t saved_layer = eeconfig_read_user();
    if (saved_layer > 0 && saved_layer < NUM_LAYERS) {
        layer_move(saved_layer);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    joystick_set_hat(JOYSTICK_HAT_CENTER);
    joystick_flush();
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Toggle switches: let QMK handle layer keycodes; tap others once
    if (record->event.key.col >= 10 && record->event.key.col <= 13) {
        if (IS_QK_TO(keycode)) {
            return true;
        }
        if (record->event.pressed) {
            uint8_t current = get_highest_layer(layer_state);
            if (keycode == SAVE_LAYER) {
                eeconfig_update_user(current);
            } else if (keycode == NEXT_LAYER) {
                layer_move((current + 1) % NUM_LAYERS);
            } else if (keycode == PREV_LAYER) {
                layer_move((current + NUM_LAYERS - 1) % NUM_LAYERS);
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
            return false;
        } else if (keycode == MICMUTE) {
            host_system_send(0);
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
        case MICMUTE:
            host_system_send(SYSTEM_MICROPHONE_MUTE);
            return false;
        case SHOW_LAYER: {
            const uint16_t digits[] = {KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9};
            uint8_t        layer    = get_highest_layer(layer_state);
            if (layer < 10) {
                tap_code16(digits[layer]);
            }
            return false;
        }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Joystick
    LAYOUT(         //
        JS_0,       // GP28 - Button 0
        JS_1,       // GP29 - Button 1
        JS_2,       // GP1  - Button 2
        JS_3,       // GP0  - Button 3
        HAT_UP,     // GP12 - Joy Up
        HAT_DOWN,   // GP11 - Joy Down
        HAT_RIGHT,  // GP10 - Joy Right
        HAT_LEFT,   // GP9  - Joy Left
        KC_MUTE,    // GP4  - Enc 0 Switch
        MICMUTE,    // GP7  - Enc 1 Switch
        PREV_LAYER, // GP14 - Toggle 0 A
        NEXT_LAYER, // GP15 - Toggle 0 B
        TO(0),      // GP26 - Toggle 1 A
        SAVE_LAYER  // GP27 - Toggle 1 B
        ),

    // Arrow keys
    LAYOUT(       //
        KC_F13,   // GP28 - Button 0
        KC_F14,   // GP29 - Button 1
        KC_F15,   // GP1  - Button 2
        KC_F16,   // GP0  - Button 3
        KC_UP,    // GP12 - Joy Up
        KC_DOWN,  // GP11 - Joy Down
        KC_RIGHT, // GP10 - Joy Right
        KC_LEFT,  // GP9  - Joy Left
        KC_TRNS,  // GP4  - Enc 0 Switch
        KC_TRNS,  // GP7  - Enc 1 Switch
        KC_TRNS,  // GP14 - Toggle 0 A
        KC_TRNS,  // GP15 - Toggle 0 B
        KC_TRNS,  // GP26 - Toggle 1 A
        KC_TRNS   // GP27 - Toggle 1 B
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
        KC_TRNS,        // GP14 - Toggle 0 A
        KC_TRNS,        // GP15 - Toggle 0 B
        KC_TRNS,        // GP26 - Toggle 1 A
        KC_TRNS         // GP27 - Toggle 1 B
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
        KC_TRNS,       // GP14 - Toggle 0 A
        KC_TRNS,       // GP15 - Toggle 0 B
        KC_TRNS,       // GP26 - Toggle 1 A
        KC_TRNS        // GP27 - Toggle 1 B
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
