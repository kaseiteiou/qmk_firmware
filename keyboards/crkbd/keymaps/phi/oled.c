#ifdef SSD1306OLED

#include "crkbd.h"
#include "ssd1306.h"

#define L_BASE     0
#define L_SYMB     (2 << (1 - 1))
#define L_FUNCTION (2 << (2 - 1))
#define L_MOUSE    (2 << (3 - 1))
#define L_WHEEL    (2 << (4 - 1))

#define MOD_CTL (MOD_BIT(KC_LCTRL) | MOD_BIT(KC_RCTRL))
#define MOD_SFT (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))
#define MOD_ALT (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))
#define MOD_GUI (MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI))

extern uint8_t is_master;

void matrix_init_user(void) {
    // SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    TWI_Init(TWI_BIT_PRESCALE_1, TWI_BITLENGTH_FROM_FREQ(1, 800000));
    iota_gfx_init(!has_usb());   // turns on the display
}

void matrix_scan_user(void) {
    iota_gfx_task();
}

char *get_layer_name(void) {
    switch (layer_state)
    {
      case L_BASE:
        return "Base";
      case L_SYMB:
        return "Symbol";
      case L_FUNCTION:
        return "Function";
      case L_MOUSE:
        return "Mouse";
      case L_WHEEL | L_MOUSE:
        return "Wheel";
      default:
        return "(Undefined)";
    }
}

int keyfreq_count = 0;

char right_image[MatrixRows * MatrixCols + 1] = {
    0x20, 0x20, 0x20, 0x93, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x93, 0x63, 0x72, 0x6b, 0x62, 0x64, 0x20, 0x70, 0x68, 0x69,
    0x20, 0x93, 0x20, 0x20, 0x20, 0x20, 0x20, 0x93, 0x20, 0x20, 0x20, 0x20, 0x20, 0x93, 0x20, 0x20, 0x20, 0x93, 0x20, 0x20,
    0xd0, 0xd1, 0xd0, 0xd1, 0xd0, 0xd1, 0xd0, 0xd1, 0xd0, 0xd1, 0xd0, 0xd1, 0xd0, 0xd1, 0xd0, 0xd1, 0xd0, 0xd1, 0xd0, 0xd1,
    0xd2, 0xd3, 0xd2, 0xd3, 0xd2, 0xd3, 0xd2, 0xd3, 0xd2, 0xd3, 0xd2, 0xd3, 0xd2, 0xd3, 0xd2, 0xd3, 0xd2, 0xd3, 0xd2, 0xd3,
    0
};

void matrix_write_keyfreq_log(struct CharacterMatrix *matrix) {
    static uint8_t background_image[MatrixRows][MatrixCols] = {
      { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0x00 },
      { 0x9d, 0x00, 0x00, 0x00, 0x00, 0x9d, 0x00, 0x00, 0x00, 0x00, 0x9d, 0x00, 0x00, 0x00, 0xb9, 0xba, 0xba, 0xba, 0xbb, 0x00 },
      { 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0xbc, 0xbd, 0xbd, 0xbd, 0xbe, 0x9e },
      { 0xb2, 0xb3, 0xb2, 0xb3, 0xb2, 0xb3, 0xb2, 0xb3, 0xb2, 0xb3, 0xb2, 0xb3, 0xb2, 0xb3, 0xb2, 0xb3, 0xb2, 0xb3, 0xb2, 0xb3 },
    };
    static char log1[21] = {
      0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc
    };
    static char log2[21] = {
      0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c
    };
    static int last_time = 0;

    log2[19] =
        keyfreq_count ==  0 ? 0x9c :
        keyfreq_count <  40 ? 0x9b :
        keyfreq_count <  80 ? 0x9a :
        keyfreq_count < 120 ? 0x99 :
        keyfreq_count < 160 ? 0x98 :
        keyfreq_count < 200 ? 0x97 :
        keyfreq_count < 240 ? 0x96 :
        keyfreq_count < 280 ? 0x95 : 0x94;

    log1[19] =
        keyfreq_count < 320 ? 0xdc :
        keyfreq_count < 360 ? 0xdb :
        keyfreq_count < 400 ? 0xda :
        keyfreq_count < 440 ? 0xd9 :
        keyfreq_count < 480 ? 0xd8 :
        keyfreq_count < 520 ? 0xd7 :
        keyfreq_count < 560 ? 0xd6 :
        keyfreq_count < 600 ? 0xd5 : 0xd4;

    /* shift the log every 60 seconds */
    if (timer_elapsed(last_time) > 60000) {
        last_time = timer_read();
        keyfreq_count = 0;
        for (int i = 0; i < 19; i++) {
          log1[i] = log1[i + 1];
          log2[i] = log2[i + 1];
        }
        log1[19] = 0x9c;
        log2[19] = 0xbb;
    }

    matrix_write_ln(matrix, log1);
    matrix_write(matrix, log2);
    matrix_set_bg(matrix, background_image);
}

void matrix_render_user(struct CharacterMatrix *matrix) {
    if (is_master) {
        uint8_t mods = get_mods();
        if (mods & MOD_CTL) matrix_write(matrix, "C-");
        if (mods & MOD_ALT) matrix_write(matrix, "M-");
        if (mods & MOD_SFT) matrix_write(matrix, "S-");
        if (mods & MOD_GUI) matrix_write(matrix, "A-");
        matrix_write_ln(matrix, get_layer_name());
        matrix_write_keyfreq_log(matrix);
    } else {
        matrix_write(matrix, right_image);
    }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
    if (memcmp(dest->bg_display, source->bg_display, sizeof(dest->bg_display))) {
        memcpy(dest->bg_display, source->bg_display, sizeof(dest->bg_display));
    }
    if (memcmp(dest->display, source->display, sizeof(dest->display))) {
        memcpy(dest->display, source->display, sizeof(dest->display));
        dest->dirty = true;
    }
}

void iota_gfx_task_user(void) {
    struct CharacterMatrix matrix;
    matrix_clear(&matrix);
    matrix_render_user(&matrix);
    matrix_update(&display, &matrix);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        keyfreq_count++;
    }
    return true;
}

#endif
