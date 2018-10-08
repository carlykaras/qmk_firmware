#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _SYMB 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR SYMB
#define KC_RASE SYMB

#define KC_LAY1 MO(_SYMB)
#define KC_BASE TG(_QWERTY)
#define KC_RS RESET

#define KC_SWK SH_TG

#define KC_SNT RSFT_T(KC_ENT)
#define KC_ZALT LALT_T(KC_Z)

#define KC_SYFN LT(_SYMB, KC_TAB)


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
     BSPC, 6  , 7  , 8  , 9  , 0  ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     BSLS, Y  , U  , I  , O  , P  ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     QUOT,SCLN, H  , J  , K  , L  ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     RALT,SLSH, DOT,COMM, N  ,  M ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        LSFT,    ,SNT,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

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
      } else {
        layer_off(_SYMB);
      }
      return false;
      break;
  }
  return true;
}
