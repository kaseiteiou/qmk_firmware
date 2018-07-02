#include "ergo42.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define BASE  0
#define RAISE 1
#define MOUSE 3
#define WHEEL 4

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   `  |   Q  |   W  |   E  |   R  |   T  |      |   |      |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |   |      |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   B  |      |   |      |  B   |   N  |   M  |   ,  |   .  |  /   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |Lang2 |Space | ESC  |   | Tab  |Enter |Lang1 |      |      |      |      |
 * |      |      |      |      |Alt   |      |      |   |      |      |Raise |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[BASE] = KEYMAP( \
  KC_JYEN,  KC_Q,    KC_W,    KC_E,            KC_R,             KC_T,   _______, /**/ _______, KC_Y,   KC_U,                KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LCTRL, KC_A,    KC_S,    LT(MOUSE, KC_D), KC_F,             KC_G,   _______, /**/ _______, KC_H,   KC_J,                KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,            KC_V,             KC_B,   _______, /**/ _______, KC_B,   KC_N,                KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
  _______,  _______, _______, _______,         LALT_T(KC_LANG2), KC_SPC, KC_ESC,  /**/ KC_TAB,  KC_ENT, LT(RAISE, KC_LANG1), _______, _______, _______, _______  \
),

/* Raise
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |  BS  |   1  |   2  |   3  |   4  |   5  |      |   |      |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      | Left | Down |   {  |   (  |   [  |      |   |      |   ]  |   )  |   }  |  Up  |Right |  =   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |      |   |      |   ^  |   &  |   *  |      |   |  |  \   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      | GUI  |      |      |   |Reset |      |------|      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[RAISE] = KEYMAP( \
  KC_BSPC, KC_1,    KC_2,    KC_3,       KC_4,    KC_5,    _______, /**/ _______, KC_6,    KC_7,    KC_8,       KC_9,    KC_0,         S(KC_EQL), \
  _______, KC_LEFT, KC_DOWN, S(KC_LBRC), S(KC_9), KC_LBRC, _______, /**/ _______, KC_RBRC, S(KC_0), S(KC_RBRC), KC_UP,   KC_RIGHT,     KC_EQL,    \
  _______, S(KC_1), S(KC_2), S(KC_3),    S(KC_4), S(KC_5), _______, /**/ _______, S(KC_6), S(KC_7), S(KC_8),    _______, S(KC_BSLASH), KC_BSLASH, \
  _______, _______, _______, _______,    KC_LGUI, _______, _______, /**/ RESET,   _______, _______, _______,    _______, _______,      _______ \
),

/* Mouse
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |      |Wheel |------|Accel |      |      |   |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |      |      |      |LClick|RClick|      |   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[MOUSE] = KEYMAP( \
  _______, _______, _______,   _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, MO(WHEEL), _______, KC_ACL0, _______, _______, /**/ _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______, _______, _______,   _______, KC_BTN1, KC_BTN2, _______, /**/ _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______,   _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______  \
),

/* WHEEL
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |      |------|------|      |      |      |   |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[WHEEL] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, /**/ _______, KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______  \
),

};
