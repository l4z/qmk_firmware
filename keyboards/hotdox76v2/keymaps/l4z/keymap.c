// Copyright 2021 JasonRen(biu)
// Copyright 2022 Drashna Jael're (@Drashna Jael're)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,           KC_EQL,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LPRN,           KC_RPRN,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_DEL,
        KC_GRV,MT(MOD_LSFT,KC_A),MT(MOD_LCTL,KC_S),MT(MOD_LALT,KC_D),LT(1,KC_F),LT(2,KC_G),
        																		 LT(2,KC_H),LT(1,KC_J),MT(MOD_RALT,KC_K),MT(MOD_RCTL,KC_L),MT(MOD_RSFT,KC_SCLN), KC_BSLS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR,           KC_RCBR,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,    KC_ENT,
          KC_LCTL, KC_LGUI, KC_LALT, MO(1),   MO(2),                                            KC_QUOT, KC_SLSH, KC_LEFT,  KC_DOWN, KC_RGHT,
                                                     KC_LBRC, KC_F18,            KC_F18, KC_RBRC,
                                                              KC_F19,            KC_F19,
                                             KC_SPC, KC_BSPC, KC_F20,            KC_F20, KC_ENT, KC_SPC
    ),

    [1] = LAYOUT_ergodox_pretty(
       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,            _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
       _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______,  KC_F12,
       _______, KC_LSFT, KC_LCTL, KC_LALT,   MO(1),   MO(3),                       MO(3),   MO(1), KC_RALT, KC_RCTL, KC_RSFT, KC_PSCR,
       _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, KC_PGUP, _______,
          _______, _______, _______,   MO(1),   MO(3),                                         _______, _______, KC_HOME,  KC_PGDN, KC_END,
                                                    _______, _______,            _______, _______,
                                                             _______,            _______,
                                           _______, _______, _______,            _______, _______, _______
    ),

    [2] = LAYOUT_ergodox_pretty(
       _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
       _______, KC_LSFT, KC_LCTL, KC_LALT,   MO(3),   MO(2),                       MO(2),   MO(3), KC_RALT, KC_RCTL, KC_RSFT, KC_PSCR,
       _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
          _______, _______, _______,    MO(3),   MO(2),                                         _______, _______, _______, _______, _______,
                                                    _______, DT_PRNT,            UG_TOGG, UG_NEXT,
                                                               DT_UP,            UG_SATU,
                                           _______, _______, DT_DOWN,            UG_HUEU, UG_VALD, UG_VALU
    )
};
