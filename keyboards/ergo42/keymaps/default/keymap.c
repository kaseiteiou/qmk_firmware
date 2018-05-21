#include "ergo42.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define BASE  0
#define RAISE 1
#define MOUSE 2
#define WHEEL 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   `  |   Q  |   W  |   E  |   R  |   T  |  Y   |   |  =   |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   B  |  N   |   |  B   |   N  |   M  |   ,  |   .  |   /  |  \   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |  BS  |PrtSc | App  | GUI  |Lang2/|Space | ESC  |   | Tab  |Enter |Lang1/| Left | Down |  Up  |Right |
 * |      |      |      |      |Alt   |      |      |   |      |      |Raise |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[BASE] = KEYMAP( \
  KC_JYEN,  KC_Q,    KC_W,   KC_E,            KC_R,             KC_T,   KC_Y,    /**/ KC_EQL,  KC_Y,   KC_U,                KC_I,    KC_O,    KC_P,    KC_MINS,   \
  KC_LCTRL, KC_A,    KC_S,   LT(MOUSE, KC_D), KC_F,             KC_G,   S(KC_9), /**/ S(KC_0), KC_H,   KC_J,                KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,   KC_C,            KC_V,             KC_B,   KC_N,    /**/ KC_B,    KC_N,   KC_M,                KC_COMM, KC_DOT,  KC_SLSH, KC_BSLASH, \
  KC_BSPC,  KC_PSCR, KC_APP, KC_LGUI,         LALT_T(KC_LANG2), KC_SPC, KC_ESC,  /**/ KC_TAB,  KC_ENT, LT(RAISE, KC_LANG1), KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT   \
),

/* Raise
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |Reest |   1  |   2  |   3  |   4  |   5  |   6  |   |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   [  |   |   ]  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |   |   }  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      | Next | Vol- | Vol+ | Play |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[RAISE] = KEYMAP( \
  RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       /**/ KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_LBRC,    /**/ KC_RBRC,    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______, \
  _______, KC_F1,    KC_F2,  KC_F3,   KC_F4,   KC_F5,   S(KC_LBRC), /**/ S(KC_RBRC), KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  _______, _______, _______, _______, _______, _______, _______,    /**/ _______,    _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Mouse
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |      |Wheel |      |Accel |      |      |   |      | Left | Down |  Up  |Right |      |      |
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
 * |      |      |Wheel |      |      |      |      |   |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[WHEEL] = KEYMAP( \
  _______, _______, _______,   _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, MO(WHEEL), _______, _______, _______, _______, /**/ _______, KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, _______, _______, \
  _______, _______, _______,   _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______,   _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______  \
),

};
