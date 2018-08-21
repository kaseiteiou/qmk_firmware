#ifndef SSD1306_H
#define SSD1306_H

#include <stdbool.h>
#include <stdio.h>
#include "pincontrol.h"

enum ssd1306_cmds {
  DisplayOff = 0xAE,
  DisplayOn = 0xAF,

  SetContrast = 0x81,
  DisplayAllOnResume = 0xA4,

  DisplayAllOn = 0xA5,
  NormalDisplay = 0xA6,
  InvertDisplay = 0xA7,
  SetDisplayOffset = 0xD3,
  SetComPins = 0xda,
  SetVComDetect = 0xdb,
  SetDisplayClockDiv = 0xD5,
  SetPreCharge = 0xd9,
  SetMultiPlex = 0xa8,
  SetLowColumn = 0x00,
  SetHighColumn = 0x10,
  SetStartLine = 0x40,

  SetMemoryMode = 0x20,
  ColumnAddr = 0x21,
  PageAddr = 0x22,

  ComScanInc = 0xc0,
  ComScanDec = 0xc8,
  SegRemap = 0xa0,
  SetChargePump = 0x8d,
  ExternalVcc = 0x01,
  SwitchCapVcc = 0x02,

  ActivateScroll = 0x2f,
  DeActivateScroll = 0x2e,
  SetVerticalScrollArea = 0xa3,
  RightHorizontalScroll = 0x26,
  LeftHorizontalScroll = 0x27,
  VerticalAndRightHorizontalScroll = 0x29,
  VerticalAndLeftHorizontalScroll = 0x2a,
};

// Controls the SSD1306 128x32 OLED display via i2c

#ifndef SSD1306_ADDRESS
#define SSD1306_ADDRESS 0x3C
#endif

#define DisplayHeight 32
#define DisplayWidth 128

#define FontHeight 8
#define FontWidth 6

#define MatrixRows (DisplayHeight / FontHeight)
#define MatrixCols (DisplayWidth / FontWidth)

struct CharacterMatrix {
  uint8_t display[MatrixRows][DisplayWidth];
  uint8_t *cursor;
  bool dirty;
};

struct CharacterMatrix display;

bool iota_gfx_init(bool rotate);
void iota_gfx_task(void);
bool iota_gfx_off(void);
bool iota_gfx_on(void);
void iota_gfx_flush(void);
void iota_gfx_clear_screen(void);

void iota_gfx_task_user(void);

void set_overwrite_mode(bool value);
void matrix_clear(struct CharacterMatrix *matrix);
void matrix_reset_cursor(struct CharacterMatrix *matrix);
void matrix_return(struct CharacterMatrix *matrix);
void matrix_newline(struct CharacterMatrix *matrix);
void matrix_write(struct CharacterMatrix *matrix, const char *data);
void matrix_write_range(struct CharacterMatrix *matrix, const char *data, uint8_t from, uint8_t width);
void matrix_write_ln(struct CharacterMatrix *matrix, const char *data);
void matrix_write_range_ln(struct CharacterMatrix *matrix, const char *data, uint8_t from, uint8_t width);
void matrix_render(struct CharacterMatrix *matrix);
void matrix_push(const struct CharacterMatrix *matrix);



#endif
