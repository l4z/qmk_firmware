// Copyright 2021 JasonRen(biu)
// Copyright 2022 Drashna Jael're (@Drashna Jael're)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "hotdox76v2.h"
#include <string.h>
#include <transactions.h>
#include "oled_font_lib/logo2.h"
#include "oled_font_lib/ext_font.h"


#ifdef RGB_MATRIX_ENABLE
// clang-format off
led_config_t g_led_config = {
    {
        { NO_LED, 34, 33, 32, 35, 37, 36     },
        { 27, 28, 29, 30, 31, NO_LED, NO_LED },
        { 26, 25, 24, 23, 22, 21, 20         },
        { 14, 15, 16, 17, 18, 19, NO_LED     },
        { 13, 12, 11, 10,  9,  8,  7         },
        {   0, 1,  2,   3, 4,  5,  6         },
        /*right*/
        { NO_LED, 77, 76, 75, 78, 80, 79     },
        { 70, 71, 72, 73, 74, NO_LED, NO_LED },
        { 69, 68, 67, 66, 65, 64, 63         },
        { 57, 58, 59, 60, 61, 62, NO_LED     },
        { 56, 55, 54, 53, 52, 51, 50         },
        { 43, 44, 45, 46, 47, 48, 49         }
    },
    {
        // LED Index to Physical Position
        {0,0},    {17,0},  {34,0},  {52,0},  {69,0},  {86,0},  {103,0},
        {103,13}, {86,13}, {69,13}, {52,13}, {34,13}, {17,13}, {0,13},
        {0,26},   {17,26}, {34,26}, {52,26}, {69,26}, {86,26},
        {103,38}, {86,38}, {69,38}, {52,38}, {34,38}, {17,38}, {0,38},
        {0,51},   {17,51}, {34,51}, {52,51}, {69,51},
                  {86,64}, {69,64}, {52,64}, {34,64}, {17,64}, {0,64},
                  {69,64}, {52,64}, {34,64}, {17,64}, {0,64},

        {224,0},  {207,0},  {190,0},  {172,0},  {155,0},  {138,0},  {121,0},
        {121,13}, {138,13}, {155,13}, {172,13}, {190,13}, {207,13}, {224,13},
        {224,26}, {207,26}, {190,26}, {172,26}, {155,26}, {138,26},
        {121,38}, {138,38}, {155,38}, {172,38}, {190,38}, {207,38}, {224,38},
        {224,51}, {207,51}, {190,51}, {172,51}, {155,51},
                  {138,64}, {155,64}, {172,64}, {190,64}, {207,64}, {224,64},
                  {155,64}, {172,64}, {190,64}, {207,64}, {224,64}


    },
    {
      // LED Index to Flag
      4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
      2,2,2,2,2,
      4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
      2,2,2,2,2
    }
};
// clang-format on
#endif

#ifdef OLED_ENABLE

#    define UNC (' ')

typedef enum {
	KEY_OVERRIDES,
    DT_TERM
} state_to_show_t;

typedef struct _master_to_slave_t {
    state_to_show_t  state_to_show;
    bool ko_enabled;
    uint16_t dt;
} master_to_slave_t;
master_to_slave_t m2s;
master_to_slave_t s2m;

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {

	m2s.state_to_show = KEY_OVERRIDES;
	m2s.ko_enabled = true;
    m2s.dt = TAPPING_TERM;
	s2m.state_to_show = KEY_OVERRIDES;
	s2m.ko_enabled = true;
    s2m.dt = TAPPING_TERM;

    if (is_keyboard_left()) {
        return OLED_ROTATION_180;
    } else {
        return OLED_ROTATION_0;
    }
}

void oled_show(uint8_t start_line, const char *data, uint8_t gap_w, uint8_t l, uint8_t actual_length, bool read_data_from_progmem) {
    uint8_t j = 0, k = 0;
    uint8_t logo_w = 0; // used to be 32 for camel logo
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
            oled_show(1, PSTR("1:FN"), gap_w, len, 4, true);
            break;
        case 2:
            oled_show(1, PSTR("2:CONTROL"), gap_w, len, 9, true);
            break;
        case 3:
            oled_show(1, PSTR("3:UNUSED"), gap_w, len, 8, true);
            break;
        default:
            oled_show(1, PSTR("UNKNOWN"), gap_w, len, 7, true);
            break;
    }
}

void render_kb_state_tpe(master_to_slave_t sync_data) {
    uint8_t len = 10;
    uint8_t gap_w = 2;
    switch (sync_data.state_to_show) {
        case KEY_OVERRIDES:
            bool en = sync_data.ko_enabled;
            oled_show(0, PSTR("KEY OVRDS:"), gap_w, len, 10, true);
            if (en) {
            	oled_show(1, PSTR("ON"), gap_w + 10, len - 1, 2, true);
            } else {
            	oled_show(1, PSTR("OFF"), gap_w + 10, len - 1, 3, true);
            }
            return;
#    ifdef DYNAMIC_TAPPING_TERM_ENABLE
        case DT_TERM:
            oled_show(0, PSTR("DT TERM:"), gap_w, len, 8, true);
    		static char value_line[9];
			int actual_length = sprintf(value_line, "%dms", sync_data.dt);
            oled_show(1, value_line, gap_w + 10, len - 1, actual_length, false);
            return;
#    endif
        default:
            oled_show(0, PSTR("!Unhandled"), gap_w, len, 10, true);
            oled_show(1, PSTR(""), gap_w, len, 0, true);
            return;
    }
}

void render_kb_state(void) {
    if (is_keyboard_master()) {
        render_kb_state_tpe(m2s);
    } else {
        render_kb_state_tpe(s2m);
    }
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_left()) {
        // layer_state is uint32_t
//        render_kb_state();
        render_layer(biton32(layer_state));
    } else {
        render_kb_state();
    }
    return false;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case TOG_OLED:
            if (record->event.pressed) {
                if (is_oled_on()) {
                    oled_off();
                } else {
                    oled_on();
                }
            }
            return false;
        default:
            return true;
    }
    return true;
}

//void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KO_TOGG:
        case KO_ON:
        case KO_OFF:
            if (record->event.pressed) {
                bool ko_enabled = keycode == KO_TOGG ? !key_override_is_enabled() : key_override_is_enabled();
            	m2s.state_to_show = KEY_OVERRIDES;
                m2s.ko_enabled = ko_enabled;
            }
            return true;
#    ifdef DYNAMIC_TAPPING_TERM_ENABLE
        case DT_PRNT:
        case DT_UP:
        case DT_DOWN:
            if (record->event.pressed) {
                uint16_t dt = g_tapping_term;
                if (keycode == DT_UP) {
                	dt += DYNAMIC_TAPPING_TERM_INCREMENT;
                } else if (keycode == DT_DOWN) {
                    dt -= DYNAMIC_TAPPING_TERM_INCREMENT;
                }
            	m2s.state_to_show = DT_TERM;
                m2s.dt = dt;
            }
            return true;
#    endif
        default:
            return true;
    }
}

void user_sync_alpa_slave_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
    const master_to_slave_t *m2s_p = (const master_to_slave_t *)in_data;
    s2m.state_to_show = m2s_p->state_to_show;
    s2m.ko_enabled = m2s_p->ko_enabled;
    s2m.dt = m2s_p->dt;
}

void keyboard_post_init_kb(void) {
    transaction_register_rpc(KEYBOARD_CURRENT_ALPA_SYNC, user_sync_alpa_slave_handler);
    keyboard_post_init_user();
}

void housekeeping_task_kb(void) {
    if (is_keyboard_master()) {
        if (!is_oled_on()) {
            m2s.state_to_show = KEY_OVERRIDES;
            m2s.ko_enabled = true;
            m2s.dt = TAPPING_TERM;
        }
        // Interact with slave every 200ms
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 200) {
            if (transaction_rpc_exec(KEYBOARD_CURRENT_ALPA_SYNC, sizeof(m2s), &m2s, sizeof(s2m), &s2m)) {
                last_sync = timer_read32();
                dprint("Slave sync successed!\n");
            } else {
                dprint("Slave sync failed!\n");
            }
        }
    }
}

#endif

#ifdef SWAP_HANDS_ENABLE
__attribute__((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0,  6}, {1,  6}, {2,  6}, {3,  6}, {4,  6}, {5,  6}, {6, 6}},
    {{0,  7}, {1,  7}, {2,  7}, {3,  7}, {4,  7}, {5,  7}, {6,  7}},
    {{0,  8}, {1,  8}, {2,  8}, {3,  8}, {4,  8}, {5,  8}, {6,  8}},
    {{0,  9}, {1,  9}, {2,  9}, {3,  9}, {4,  9}, {5,  9}, {6,  9}},
    {{0, 10}, {1, 10}, {2, 10}, {3, 10}, {4, 10}, {5, 10},  {6, 10}},
    {{0, 11}, {1, 11}, {2, 11}, {3, 11}, {4, 11}, {5, 11},  {6, 11}},

    /* Right hand, matrix positions */
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}},
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}},
    {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}},
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}}
};
#endif
