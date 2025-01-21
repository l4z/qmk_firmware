// Copyright 2021 JasonRen(biu)
// Copyright 2022 Drashna Jael're (@Drashna Jael're)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "oled_font_lib/ext_font.h"
#include QMK_KEYBOARD_H

typedef enum {
    BASE,
    SYMBOLS,
    FN,
    CONTROL
} my_layers_t;

void keyboard_post_init_user(void) {
    layer_on(SYMBOLS);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌──────┬───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┬──────┐
     * │ `    │ 1 │ 2 │ 3 │ 4 │ 5 │ = │                     │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │    - │
     * ├──────┼───┼───┼───┼───┼───┼───┤                     ├───┼───┼───┼───┼───┼───┼──────┤
     * │ Tab  │ Q │ W │ E │ R │ T │ = │                     │ Y │ Y │ U │ I │ O │ P │    \ │
     * ├──────┼───┼───┼───┼───┼───┤   │                     │   ├───┼───┼───┼───┼───┼──────┤
     * │Escape│ A │ S │ D │ F │ G ├───┤                     ├───┤ H │ J │ K │ L │ ; │    ' │
     * ├──────┼───┼───┼───┼───┼───┤   │                     │   ├───┼───┼───┼───┼───┼──────┤
     * │Shift │ Z │ X │ C │ V │ B │ B │                     │ N │ N │ M │ , │ . │ / │ Shift│
     * └──┬───┼───┼───┼───┼───┼───┴───┘ ┌───┬───┐ ┌───┬───┐ └───┴───┼───┼───┼───┼───┼───┬──┘
     *    │Ctl│F4 │F5 │GUI│Alt│         │ C │ V │ │Alt│ A │         │ ← │ ↓ │ ↑ │ → │GUI│
     *    └───┴───┴───┴───┴───┘     ┌───┼───┼───┤ ├───┼───┼───┐     └───┴───┴───┴───┴───┘
     *                              │   │   │PgU│ │PgD│   │   │
     *                              │Bsp│Bsp├───┤ ├───┤Ent│   │
     *                              │   │   │Del│ │Ctl│   │   │
     *                              └───┴───┴───┘ └───┴───┴───┘
     */
    [0] = LAYOUT_ergodox_pretty(
//        KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,           KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,  KC_EQL, KC_BSPC,
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,              KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LCBR,           KC_RCBR,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
        KC_GRV,MT(MOD_LSFT,KC_A),MT(MOD_LCTL,KC_S),MT(MOD_LALT,KC_D),LT(2,KC_F),LT(3,KC_G),
        											   LT(3,KC_H),LT(2,KC_J),MT(MOD_RALT,KC_K),MT(MOD_RCTL,KC_L),MT(MOD_RSFT,KC_SCLN),KC_BSLS,
       KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LPRN,           KC_RPRN,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_UP,  KC_ENT,
          KC_LCTL, KC_LGUI, KC_LALT,  MO(2),  MO(3),                                            KC_QUOT, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT,
                                                     KC_LBRC, KC_F18,            KC_F18, KC_RBRC,
                                                              KC_F19,            KC_F19,
                                             KC_SPC, KC_BSPC, KC_F20,            KC_F20, KC_ENT, KC_SPC
    ),

    [1] = LAYOUT_ergodox_pretty(
//       _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,               KC_7,    KC_8,    KC_9,    KC_0, _______, _______, _______,
       _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,            KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
          _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______,
                                                    _______, _______,            _______, _______,
                                                             _______,            _______,
                                           _______, _______, _______,            _______, _______, _______
    ),

    [2] = LAYOUT_ergodox_pretty(
         TG(1),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,              KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_F11,
       _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______,  KC_F12,
       _______, KC_LSFT, KC_LCTL, KC_LALT,   MO(2),   MO(4),                                MO(4),   MO(2), KC_RALT, KC_RCTL, KC_RSFT, KC_PSCR,
       _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, KC_PGUP, _______,
          _______, _______, _______,  MO(2),  MO(4),                                            _______, _______, KC_HOME, KC_PGDN,  KC_END,
                                                    _______, _______,            _______, _______,
                                                             _______,            _______,
                                           _______, _______, _______,            _______, _______, _______
    ),

    [3] = LAYOUT_ergodox_pretty(
         TG(1), _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
       _______, KC_LSFT, KC_LCTL, KC_LALT,   MO(3),   MO(4),                                MO(4),   MO(3), KC_RALT, KC_RCTL, KC_RSFT, _______,
       _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
          _______, _______, _______,    MO(3),   MO(4),                                         _______, _______, _______, _______, _______,
                                                    KO_TOGG, DT_PRNT,            RM_TOGG, RM_NEXT,
                                                               DT_UP,            RM_SATU,
                                           _______, _______, DT_DOWN,            RM_HUEU, RM_VALD, RM_VALU
    )
};

#ifdef KEY_OVERRIDE_ENABLE

const key_override_t l_paren_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_LPRN, KC_LT, 1);
const key_override_t r_paren_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_RPRN, KC_GT, 1);

const key_override_t l_brace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_LBRC);
const key_override_t r_brace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, KC_RBRC);

const key_override_t kc_1_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EXLM, KC_1);
const key_override_t kc_2_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_2);
const key_override_t kc_3_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_3);
const key_override_t kc_4_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DLR, KC_4);
const key_override_t kc_5_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PERC, KC_5);
const key_override_t kc_6_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_CIRC, KC_6);
const key_override_t kc_7_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_7);
const key_override_t kc_8_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_ASTR, KC_8);
const key_override_t kc_9_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_LPRN, KC_9, ~1);
const key_override_t kc_0_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_RPRN, KC_0, ~1);

const key_override_t *key_overrides[] = {
	&l_paren_key_override,
	&r_paren_key_override,
	&l_brace_key_override,
	&r_brace_key_override,
    &kc_1_key_override,
    &kc_2_key_override,
    &kc_3_key_override,
    &kc_4_key_override,
    &kc_5_key_override,
    &kc_6_key_override,
    &kc_7_key_override,
    &kc_8_key_override,
    &kc_9_key_override,
    &kc_0_key_override
};

#endif

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // see: rgb_config_t rgb_matrix_config;

    if (rgb_matrix_config.mode > 1) {
        return true;
    }

    // fav hue 23 * 8
    // nav for fav hue 2 * 8
    const hsv_t hsv = rgb_matrix_config.hsv;
    const rgb_t rgb = hsv_to_rgb(hsv);

    // saturation variations
    const rgb_t white_rgb = hsv_to_rgb((hsv_t){hsv.h, 0, hsv.v});
    const rgb_t desat_rgb = hsv_to_rgb((hsv_t){hsv.h, hsv.s / 2 + 32, hsv.v});
    
    // hue variations
    const rgb_t opp_rgb = hsv_to_rgb((hsv_t){hsv.h - 107, hsv.s, hsv.v});
    const rgb_t less_rgb = hsv_to_rgb((hsv_t){hsv.h - 43, hsv.s, hsv.v});
    const rgb_t more_rgb = hsv_to_rgb((hsv_t){hsv.h + 107, hsv.s, hsv.v});

    const uint8_t mod_state = get_mods();

    // numbers: 1 <= i < 7; 46 <= i < 50
    // FN keys: 1 <= i < 7; 44 <= i < 50
    // FN keys 2nd row: 8 <= i < 13; 51 <= i < 56
    // home row (a-g, h-;): 15 <= i < 20, 58 <= i < 63
    // arrows cluster: 68, 70, 71, 72
    // underglow left: 38 <= i < 43
    // underglow right: 81 <= i < 86
    // thumb cluster left: 32 <= i < 38 // starts at 'space', goes to bottom corner, then far corner, finally 1 up
    // thumb cluster right: 75 <= i < 81 // starts at 'space', goes to bottom corner, then far corner, finally 1 up

    for (int i = led_min; i < led_max; i++) {
        rgb_t i_color = rgb;

        if ((i == 0 || (i >= 34 && i < 38) || (i >= 75 && i < 81)) && layer_state & (1 << CONTROL)) {
            i_color = less_rgb;
        } else if ((i >= 1 && i < 7) || (i >= 46 && i < 50)) {
            if (layer_state & (1 << FN)) {
                i_color = white_rgb;
            } else {
                const bool shifted = mod_state & MOD_MASK_SHIFT;
                const bool symbols = layer_state & (1 << SYMBOLS);
                i_color = (shifted == symbols) ? opp_rgb : more_rgb;
            }
        } else if (i >= 44 && i < 46 && layer_state & (1 << FN)) {
            i_color = white_rgb;
        } else if ((i >= 15 && i < 20) || (i >= 58 && i < 63)) {
            i_color = desat_rgb;
        } else if (i == 68 || i == 70 || i == 71 || i == 72) {
            i_color = opp_rgb;
        }

        RGB_MATRIX_INDICATOR_SET_COLOR(i, i_color.r, i_color.g, i_color.b);
    }

    return false;
}
#endif

#ifdef OLED_ENABLE
typedef enum {
    KEY_OVERRIDES,
    DT_TERM
} state_to_show_t;

state_to_show_t state_to_show;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {

    state_to_show = KEY_OVERRIDES;

    if (is_keyboard_left()) {
        return OLED_ROTATION_180;
    } else {
        return OLED_ROTATION_0;
    }
}

void oled_show(uint8_t start_line, const char *data, uint8_t gap_w, uint8_t l, uint8_t actual_length, bool read_data_from_progmem) {
    uint8_t j = 0, k = 0;
    uint8_t logo_w = 0; // used to be 32 for alpacca logo
    for (j = 0; j < l; ++j) {      // char index
        const char character = read_data_from_progmem ? pgm_read_byte(&data[j]) : data[j];
        const unsigned char *character_font;
        if (j < actual_length) {
            character_font = ext_big_font[character - 0x20];
        } else {
            character_font = ext_big_font[0]; // whitespace
        }
        for (k = 0; k < 12; ++k) { // font pixel column byte index, each
            // base + logo_w(32) + gap_w(12) +l*font_w(12)+current_byte_index
            oled_write_raw_byte(pgm_read_byte(&character_font[k]), start_line * 2 * 128 + logo_w + gap_w + j * 12 + k);
            oled_write_raw_byte(pgm_read_byte(&character_font[k + 12]), start_line * 2 * 128 + 128 + logo_w + gap_w + j * 12 + k);
        }
    }
    for (j = 0; j < gap_w; ++j) {
        oled_write_raw_byte(pgm_read_byte(&blank_block), start_line * 2 * 128 + logo_w + j);
        oled_write_raw_byte(pgm_read_byte(&blank_block), start_line * 2 * 128 + logo_w + gap_w + l * 12 + j);

        oled_write_raw_byte(pgm_read_byte(&blank_block), start_line * 2 * 128 + 128 + logo_w + j);
        oled_write_raw_byte(pgm_read_byte(&blank_block), start_line * 2 * 128 + 128 + logo_w + gap_w + l * 12 + j);
    }
}

void render_kb_state(void) {
    uint8_t len = 10;
    uint8_t gap_w = 2;
    switch (state_to_show) {
#ifdef KEY_OVERRIDE_ENABLE
        case KEY_OVERRIDES:
            bool en = key_override_is_enabled();
            oled_show(0, PSTR("KEY OVRDS:"), gap_w, len, 10, true);
            if (en) {
                oled_show(1, PSTR("ON"), gap_w + 10, len - 1, 2, true);
            } else {
                oled_show(1, PSTR("OFF"), gap_w + 10, len - 1, 3, true);
            }
            return;
#endif
#ifdef DYNAMIC_TAPPING_TERM_ENABLE
        case DT_TERM:
            oled_show(0, PSTR("DT TERM:"), gap_w, len, 8, true);
            static char value_line[9];
            int actual_length = sprintf(value_line, "%dms", g_tapping_term);
            oled_show(1, value_line, gap_w + 10, len - 1, actual_length, false);
            return;
#endif
        default:
            oled_show(0, PSTR("!Unhandled"), gap_w, len, 10, true);
            oled_show(1, PSTR(""), gap_w, len, 0, true);
            return;
    }
}

void render_layer(uint8_t layer) {
    uint8_t gap_w = 2;
    uint8_t len = 10;
    oled_show(0, PSTR("LAYER:"), gap_w, len, 6, true);
    // with defaut font (half height): oled_write_P(PSTR("Layer: "), false);
    switch (layer) {
        case 0:
            oled_show(1, PSTR("0:BASE"), gap_w, len, 6, true);
        break;
        case 1:
            oled_show(1, PSTR("1:SYMBOLS"), gap_w, len, 9, true);
        break;
        case 2:
            oled_show(1, PSTR("2:FN"), gap_w, len, 4, true);
        break;
        case 3:
            oled_show(1, PSTR("3:CONTROL"), gap_w, len, 9, true);
        break;
        case 4:
            oled_show(1, PSTR("4:UNUSED"), gap_w, len, 8, true);
        break;
        default:
            oled_show(1, PSTR("UNKNOWN"), gap_w, len, 7, true);
        break;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_kb_state();
    } else {
        // layer_state is uint32_t
        render_layer(biton32(layer_state));
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef KEY_OVERRIDE_ENABLE
        case KO_TOGG:
        case KO_ON:
        case KO_OFF:
            if (record->event.pressed) {
                state_to_show = KEY_OVERRIDES;
            }
        return true;
#endif
#ifdef DYNAMIC_TAPPING_TERM_ENABLE
        case DT_PRNT:
        case DT_UP:
        case DT_DOWN:
            if (record->event.pressed) {
                state_to_show = DT_TERM;
            }
        return true;
#endif
        default:
            return true;
    }
}

#endif
