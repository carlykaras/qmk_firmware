// Runyx Keymap
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _SYMB 1
#define _GAME 2
#define _GAMECT 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  GAME,
  GAMECT,
};

//Transparency & Shorthands
#define KC_ KC_TRNS
#define _______ KC_TRNS
#define KC_RS RESET

//Layer Toggles
//MO is momentary, TO is toggle
#define KC_SFUN MO(1)
#define KC_GFUN MO(3)
#define KC_TOG2 TO(2)
#define KC_BASE TO(0)

//Modifiers
#define KC_SNT RSFT_T(KC_ENT)
#define KC_ZALT LALT_T(KC_Z)

//Macros
#define KC_LBK LGUI(LCTL(LALT(KC_DOWN)))
#define KC_LUP LGUI(LCTL(LALT(KC_UP)))

//Issue: When RGUI and RASE are swapped, RASE+any key will stick the board on SYMB

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GESC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL,ZALT, X  , C  , V  , B  ,    ,         , N  , M  ,COMM,DOT ,SLSH,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,SFUN,SPC ,          SNT,SFUN,RGUI
  //                  `----+----+----'        `----+----+----'
  ),

//
  [_SYMB] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      GRV,    ,    ,    ,    ,    ,                   ,    ,UNDS,MINS, EQL, DEL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LBK ,LPRN,RPRN,    ,    ,               MINS,PLUS,EQL ,LBRC,RBRC,BASE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LUP ,LCBR,RCBR,    ,    ,                   ,LEFT,DOWN, UP ,RGHT,PLUS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      RS ,    ,LABK,RABK,    ,LCBR,    ,         ,RCBR,    ,VOLD,VOLU,    ,TOG2,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,BSPC,         DEL ,    ,RALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_GAME] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   , P7 , P8 , P9 ,    ,BASE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   , P4 , P5 , P6 ,PPLS,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    , P1 , P2 , P3 ,PDOT,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           , GFUN,SPC ,         SNT,P0,
  //                  `----+----+----'        `----+----+----'
  ),

  [_GAMECT] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , Y  , U  , I  , O  , P  ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , H  , J  , K  , L  , N  ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    , N  , M  ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),
/*

Bring to Front: Control + Alt + Cmd + ↑
Sent to Back: Control + Alt + Cmd + ↓

  [_DESIGN] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,  V ,  O , R  , T  ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),
*/
};

//I am not swapping default layers, so this seems unnecessary?

/*
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case SYMB:
      if (record->event.pressed) {
        layer_on(_SYMB);
        update_tri_layer(_SYMB, _GAME, _GAMECT);
      } else {
        layer_off(_SYMB);
        update_tri_layer(_SYMB, _GAME, _GAMECT);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        layer_on(_GAME);
        update_tri_layer(_SYMB, _GAME, _GAMECT);
      } else {
        layer_off(_GAME);
        update_tri_layer(_SYMB, _GAME, _GAMECT);
      }
      return false;
      break;
    case GAMECT:
      if (record->event.pressed) {
        layer_on(_GAMECT);
      } else {
        layer_off(_GAMECT);
      }
      return false;
      break;
  }
  return true;
}
*/
