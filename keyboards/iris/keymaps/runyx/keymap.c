#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _SYMB 1
#define _GAME 2
#define _GAMECT 3
//#define _DESIGN 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  GAME,
  GAMECT,
//  DESIGN,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR SYMB
#define KC_RASE SYMB
#define KC_GCT GAMECT

#define KC_LAY1 MO(_SYMB)
#define KC_LAY2 MO(_GAME)
#define KC_TOG2 TG(_GAME)
#define KC_BASE TG(_QWERTY)
#define KC_RS RESET

#define KC_SWK SH_TG

//define KC_SSB RSFT_T(KC_SPC)
#define KC_SNT RSFT_T(KC_ENT)
#define KC_ZALT LALT_T(KC_Z)

#define KC_CTFN LT(_GAMECT, KC_TAB)
#define KC_SYFN LT(_SYMB, KC_TAB)

//#define KC_QU MT(MOD_RSFT, KC_TOG2)

//When RGUI and RASE are swapped, RASE+any key will stick the board on SYMB

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL,ZALT, X  , C  , V  , B  ,    ,         , N  , M  ,COMM,DOT ,SLSH,RALT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LOWR,SPC ,          SNT,RASE,RGUI
  //                  `----+----+----'        `----+----+----'
  ),

//
  [_SYMB] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV ,EXLM, AT ,HASH,DLR ,    ,                   ,AMPR,ASTR,MINS, EQL, DEL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LBRC,RBRC,    ,    ,    ,               VOLU,VOLD,    ,LBRC,RBRC,BASE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RS,LCBR,RCBR,    ,    ,    ,                   ,LEFT,DOWN, UP ,RGHT,PIPE,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     PSCR, LT , GT ,    ,    ,LCBR,    ,         ,RCBR,    ,VOLD,VOLU,    ,TOG2,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,BSPC,         DEL ,    ,RALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_GAME] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   , P7 , P8 , P9 ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   , P4 , P5 , P6 ,PPLS,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    , P1 , P2 , P3 ,PDOT,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           , GCT ,SPC ,         SNT,P0,
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
    [_DESIGN] = LAYOUT_kc(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,MINS, EQL,BSPC,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       LSFT, 1  , 2  , 3  , 4  , 5  ,               VOLU,VOLD, 8  ,LBRC,RBRC,BASE,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       DEL ,    ,LEFT,RGHT, UP ,LBRC,               LEFT,DOWN, UP ,RGHT,PLUS,PIPE,
    //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
       BL_S,    ,    ,    ,DOWN,LCBR,LPRN,     RPRN,RCBR, P1 , P2 , P3 ,MINS,    ,
    //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                             ,    ,BSPC,         DEL ,    ,
    //                  `----+----+----'        `----+----+----'
    ),
  */

};

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
