#include "ergodox_ez.h"
#include "led.h"
#include "mousekey.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"

#define BASE   0 // default layer
#define SYMB   1 // symbols layer
#define MDIA   2 // media layer
#define SPEC   3 // special layer
#define RBASE  4 // reverse default layer

#define LSymb 10 // left symbol-shift key
#define LMdia 11 // left media-shift key
#define LSpec 12 // left special-shift key
#define RSymb 13 // right symbol-shift key
#define RMdia 14 // right media-shift key
#define RSpec 15 // right special-shift key

#define NotEq 16 // != macro
#define GrtEq 17 // >= macro
#define LesEq 18 // <= macro
#define DeRef 19 // -> macro
#define Asig  20 // <- macro

#define MUL   21 // mouse up left
#define MUR   22 // mouse up right
#define MDL   23 // mouse down left
#define MDR   24 // mouse down right

#define RGB_SLD 25
/*
 * The Ordinary Layout for the Ergodox EZ keyboard, v5
 *
 * Modifications from the default Ergodox EZ layout
 * by Nicholas Keene ergodoxez@nicholaskeene.com
 *
 * No rights reserved. This software is in the public domain.
 * Credit me if you are friendly but if you're a jerk don't bother.
 * If you use or modify this layout I would love to hear from you.
 *
 * Details: readme.md
 *          https://github.com/nrrkeene/qmk_firmware/tree/master/keyboards/ergodox/keymaps/ordinary
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/******* Base Layer ****************************************************************************************************
 *
 * ,------------------------------------------------------.       ,------------------------------------------------------.
 * | Special `~ |   1  |   2  |   3  |   4  |   5  | ESC  |       |  -   |   6  |   7  |   8  |   9  |   0  | =+ Special |
 * |------------+------+------+------+------+-------------|       |------+------+------+------+------+------+------------|
 * | Media  Tab |   Q  |   W  |   E  |   R  |   T  |   [  |       |  ]   |   Y  |   U  |   I  |   O  |   P  | \|   Media |
 * |------------+------+------+------+------+------|      |       |      |------+------+------+------+------+------------|
 * | Symbol ESC |  ^A  |   S  |   D  |  ^F  |   G  |------|       |------|   H  |  ^J  |   K  |   L  |  ^;  | '"  Symbol |
 * |------------+------+------+------+------+------|Shift |       | Tab  |------+------+------+------+------+------------|
 * | Capitals   |   Z  |   X  |   C  |   V  |   B  | -Tab |       |      |   N  |   M  |   ,  |   .  |  /   |   Capitals |
 * `------------+------+------+------+------+-------------'       `-------------+------+------+------+------+------------'
 *      | LCtrl | Meh  |Hyper | LGui | LAlt |                                   | RAlt | RGui | Hyper|  Meh | RCtrl |
 *      `-----------------------------------'                                   `-----------------------------------'
 *                                          ,-------------.       ,-------------.
 *                                          | Home | End  |       | Left | Right|
 *                                   ,------|------|------|       |------+------+------.
 *                                   |      |      | PgUp |       |  Up  |      |      |
 *                                   |Backsp| Del  |------|       |------| Enter| Space|
 *                                   |      |      | PgDn |       | Down |      |      |
 *                                   `--------------------'       `--------------------'
 */
[BASE] = KEYMAP(
// left hand
 F(LSpec)  ,KC_1           ,KC_2   ,KC_3   ,KC_4  ,KC_5  ,KC_ESC
,F(LMdia)  ,KC_Q           ,KC_W   ,KC_E   ,KC_R  ,KC_T  ,KC_LBRC
,F(LSymb)  ,LT(RBASE, KC_A),KC_S   ,KC_D   ,LT(RBASE, KC_F)  ,KC_G
,KC_LSFT   ,KC_Z           ,KC_X   ,KC_C   ,KC_V  ,KC_B  ,LSFT(KC_TAB)
,KC_LCTL   ,MEH_T(KC_NO)   ,ALL_T(KC_NO),KC_LGUI,KC_LALT
                                         ,KC_HOME,KC_END
                                                 ,KC_PGUP
                                 ,KC_BSPC,KC_DEL ,KC_PGDN
                                                                  // right hand
                                                                 ,KC_MINS ,KC_6 ,KC_7           ,KC_8   ,KC_9   ,KC_0             ,F(RSpec)
                                                                 ,KC_RBRC ,KC_Y ,KC_U           ,KC_I   ,KC_O   ,KC_P             ,F(RMdia)
                                                                          ,KC_H ,LT(RBASE, KC_J),KC_K   ,KC_L   ,LT(RBASE,KC_SCLN),F(RSymb)
                                                                 ,KC_TAB  ,KC_N ,KC_M           ,KC_COMM,KC_DOT ,KC_SLSH          ,KC_RSFT
                                                                                ,KC_RALT        ,KC_RGUI,KC_HYPR,KC_MEH           ,KC_RCTL
                                                                 ,KC_LEFT ,KC_RGHT
                                                                 ,KC_UP
                                                                 ,KC_DOWN ,KC_ENT ,KC_SPC
),

/******* Symbols Layer *************************************************************************************************
 *
 * ,-----------------------------------------------------.       ,-----------------------------------------------------.
 * |           |  F1  |  F2  |  F3  |  F4  |  F5  | Esc  |       |  -   |  F6  |  F7  |  F8  |  F9  |  F10 |           |
 * |-----------+------+------+------+------+-------------|       |------+------+------+------+------+------+-----------|
 * |           |   !  |   @  |   {  |   }  |   &  |  <   |       |  >   |   |  |   7  |   8  |   9  |   /  |           |
 * |-----------+------+------+------+------+------|      |       |      |------+------+------+------+------+-----------|
 * |       ESC |   #  |   $  |   (  |   )  |   `  |------|       |------|   /  |   4  |   5  |   6  |   *  |           |
 * |-----------+------+------+------+------+------|  '   |       |  "   |------+------+------+------+------+-----------|
 * |           |   %  |   ^  |   [  |   ]  |   ~  |      |       |      |   \  |   1  |   2  |   3  |   -  |           |
 * `-----------+------+------+------+------+-------------'       `-------------+------+------+------+------+-----------'
 *     |   ;   |   &  |   *  |   <  |   >  |                                   |   0  |   .  |   =  |   +  | Enter |
 *     `-----------------------------------'                                   `-----------------------------------'
 *                                         ,-------------.       ,-------------.
 *                                         | |||| | |||| |       | |||| | |||| |
 *                                  ,------|------|------|       |------+------+------.
 *                                  | Plus | Equal| |||| |       |  <-  | Under| Dash |
 *                                  |      |      |------|       |------| Score|      |
 *                                  |  +   |   =  |  !=  |       |  ->  |  _   |  -   |
 *                                  `--------------------'       `--------------------'
 */
[SYMB] = KEYMAP(
// left hand
 KC_TRNS ,KC_F1       ,KC_F2        ,KC_F3   ,KC_F4   ,KC_F5   ,KC_ESC
,KC_TRNS ,KC_EXLM     ,KC_AT        ,KC_LCBR ,KC_RCBR ,KC_AMPR ,LSFT(KC_COMM)
,KC_ESC  ,KC_HASH     ,KC_DLR       ,KC_LPRN ,KC_RPRN ,KC_GRV
,KC_TRNS ,KC_PERC     ,KC_CIRC      ,KC_LBRC ,KC_RBRC ,KC_TILD ,KC_QUOT
,KC_SCLN ,KC_AMPR     ,KC_ASTR ,LSFT(KC_COMM),LSFT(KC_DOT)
                                                      ,M(GrtEq),M(LesEq)
                                                               ,KC_NO
                                             ,KC_PLUS ,KC_EQL  ,M(NotEq)
                                                                 // right hand
                                                                 ,KC_MINS     ,KC_F6        ,KC_F7 ,KC_F8  ,KC_F9 ,KC_F10  ,KC_TRNS
                                                                 ,LSFT(KC_DOT),KC_PIPE      ,KC_7  ,KC_8   ,KC_9  ,KC_SLSH ,KC_TRNS
                                                                              ,KC_SLSH      ,KC_4  ,KC_5   ,KC_6  ,KC_ASTR ,KC_TRNS
                                                                 ,LSFT(KC_QUOT),KC_BSLS     ,KC_1  ,KC_2   ,KC_3  ,KC_MINS ,KC_TRNS
                                                                                            ,KC_0  ,KC_DOT ,KC_EQL,KC_PLUS ,KC_ENT
                                                                 ,KC_NO       ,KC_NO
                                                                 ,M(Asig)
                                                                 ,M(DeRef)    ,LSFT(KC_MINS),KC_MINS
),

/******* Media Layer *******************************************************************************************************
 *
 * ,---------------------------------------------------------------.    ,---------------------------------------------------------------.
 * |      |   F11   |   F12   |   F13   |   F14   |   F15   | Esc  |    | |||| |   F16   |   F17   |   F18   |   F19   |   F20   |      |
 * |------+---------+---------+---------+---------+----------------|    |------+---------+---------+---------+---------+---------+------|
 * |      |Shut Down|MouseUpLf|Mouse Up |MouseUpRg|Volume Up|Scroll|    |Scroll|PrintScrn|   Home  |    Up   |   PgUp  |   Mail  |      |
 * |------+---------+---------+---------+---------+---------|  Up  |    |  Up  |---------+---------+---------+---------+---------+------|
 * |  ESC |  Sleep  |MouseLeft|MouseDown|MouseRght|Volume Dn|------|    |------| Num Lock|   Left  |   Down  |   Right | MyComp  |      |
 * |------+---------+---------+---------+---------+---------|Scroll|    |Scroll|---------+---------+---------+---------+---------+------|
 * |      |  ||||   |MouseDnLf|MouseDown|MouseDnRg|  Mute   | Down |    | Down |  ||||   |   End   |   Down  |   PgDn  |  ||||   |      |
 * `------+---------+---------+---------+---------+----------------'    `----------------+---------+---------+---------+---------+------'
 *  | ||| |  ||||   |  MClick | LClick  |  R Click|                                      |  Insert |   Del   |   ||||  |  ||||   | ||| |
 *  `---------------------------------------------'                                      `---------------------------------------------'
 *                                                   ,-------------.    ,-------------.
 *                                                   | Stop |Refrsh|    | Prev | Next |
 *                                            ,------|------|------|    |------+------+------.
 *                                            |Brwser|Brwser|Search|    |VolUp |      |      |
 *                                            |Back  | Fwd  |------|    |------| Stop | Play-|
 *                                            |      |      | Home |    |VolDn |      | Pause|
 *                                            `--------------------'    `--------------------'
 */
[MDIA] = KEYMAP(
// left hand
 KC_TRNS ,KC_F1   ,KC_F12  ,KC_F13   ,KC_F14  ,KC_F15  ,KC_ESC
,KC_TRNS ,KC_NO   ,M(MUL)  ,KC_MS_U  ,M(MUR)  ,KC_VOLU ,KC_WH_U
,KC_ESC  ,KC_NO   ,KC_MS_L ,KC_MS_D  ,KC_MS_R ,KC_VOLD
,KC_TRNS ,KC_NO   ,M(MDL)  ,KC_MS_D  ,M(MDR)  ,KC_MUTE ,KC_WH_D
,KC_NO   ,KC_NO   ,KC_BTN3 ,KC_BTN1  ,KC_BTN2
                                               ,KC_WSTP ,KC_WREF
                                                        ,KC_WSCH
                                      ,KC_WBAK ,KC_NO   ,KC_WHOM
                                                                     // right hand
                                                                     ,KC_NO    ,KC_F16  ,KC_F17       ,KC_F18       ,KC_F19  ,KC_F20  ,KC_TRNS
                                                                     ,KC_WH_U  ,KC_PSCR ,KC_HOME      ,KC_UP        ,KC_PGUP ,KC_NO   ,KC_TRNS
                                                                               ,KC_NLCK ,KC_LEFT      ,KC_DOWN      ,KC_RIGHT,KC_NO   ,KC_TRNS
                                                                     ,KC_WH_D  ,KC_NO   ,KC_END       ,KC_DOWN      ,KC_PGDN ,KC_NO   ,KC_TRNS
                                                                                        ,KC_INS       ,KC_DEL       ,KC_NO   ,KC_NO   ,KC_NO
                                                                     ,KC_MPRV  ,KC_MNXT
                                                                     ,KC_VOLU
                                                                     ,KC_VOLD  ,KC_MSTP ,KC_MPLY
),

/******* Special Layer *****************************************************************************************************
 *
 * ,-------------------------------------------------------.    ,-------------------------------------------------------.
 * |             |  Esc |      |      |      |      |      |    |      |      |      |      |   -  | Bspc |             |
 * |-------------+------+------+------+------+-------------|    |------+------+------+------+------+------+-------------|
 * |             |      |      |      |      |      |      |    |      |      |      |      |  [   |   ]  |             |
 * |-------------+------+------+------+------+------|      |    |      |------+------+------+------+------+-------------|
 * | ESC         |      |      |      |      |      |------|    |------|      |      |      |      |      |             |
 * |-------------+------+------+------+------+------|      |    |      |------+------+------+------+------+-------------|
 * | Caps Lock   |      |      |      |      |      |      |    |      |      |      |      |      |      | Caps Lock   |
 * `-------------+------+------+------+------+-------------'    `-------------+------+------+------+------+-------------'
 *      |        |      |      |      |      |                                |      |      |      |      |        |
 *      `------------------------------------'                                `------------------------------------'
 *                                         ,-------------.     ,-------------.
 *                                         |      |  TOG |     |  TOG |      |
 *                                  ,------|------|------|     |------+------+------.
 *                                  |      |      |      |     |      |      |      |
 *                                  |  VAD |  VAI |------|     |------|  MOD |  SLD |
 *                                  |      |      |      |     |      |      |      |
 *                                  `--------------------'     `--------------------'
 */
[SPEC] = KEYMAP(
// left hand
 KC_TRNS ,KC_ESC  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_ESC  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_CAPS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                             ,RGB_TOG ,RGB_TOG
                                                      ,RGB_TOG
                                     ,RGB_VAD,RGB_VAI ,RGB_TOG
                                                             // right hand
                                                             ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_MINS ,KC_BSPC ,KC_TRNS
                                                             ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_LBRC ,KC_RBRC ,KC_TRNS
                                                                      ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                             ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_CAPS
                                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                             ,RGB_TOG ,RGB_TOG
                                                             ,RGB_TOG
                                                             ,RGB_TOG ,RGB_MOD , RGB_SLD
),

/******* Reverse Base Layer *********************************************************************************************
 *
 * ,------------------------------------------------------.       ,------------------------------------------------------.
 * |    =+      |   0  |   9  |   8  |   7  |   6  |  -   |       |  Esc |   5  |   4  |   3  |   2  |   1  |    `~      |
 * |------------+------+------+------+------+-------------|       |------+------+------+------+------+------+------------|
 * |    \|      |   P  |   O  |   I  |   U  |   Y  |   ]  |       |  [   |   T  |   R  |   E  |   W  |   Q  |    Tab     |
 * |------------+------+------+------+------+------|      |       |      |------+------+------+------+------+------------|
 * |    '"      |   ;  |   L  |   K  |   J  |   H  |------|       |------|   G  |   F  |   D  |   S  |  A   |    ESC     |
 * |------------+------+------+------+------+------| Tab  |       |Shift |------+------+------+------+------+------------|
 * | Capitals   |   /  |   .  |   ,  |   M  |   N  |      |       | -Tab |   B  |   V  |   C  |   X  |  Z   |   Capitals |
 * `------------+------+------+------+------+-------------'       `-------------+------+------+------+------+------------'
 *      | LCtrl | Meh  |Hyper | LAlt | LGui |                                   | RGui | RAlt | Hyper|  Meh | RCtrl |
 *      `-----------------------------------'                                   `-----------------------------------'
 *                                         ,-------------.       ,-------------.
 *                                         | Left | Right|       | Home | End  |
 *                                  ,------|------|------|       |------+------+------.
 *                                  |      |      |  Up  |       | PgUp |      |      |
 *                                  |Space |Enter |------|       |------|BackSp| Del  |
 *                                  |      |      | Down |       | PgDn |      |      |
 *                                  `--------------------'       `--------------------'
 */
[RBASE] = KEYMAP(
// left hand
 KC_EQL    ,KC_0        ,KC_9   ,KC_8   ,KC_7  ,KC_6  ,KC_MINS
,KC_BSLS   ,KC_P        ,KC_O   ,KC_I   ,KC_U  ,KC_Y  ,KC_RBRC
,KC_QUOT     ,LT(RBASE, KC_SCLN)     ,KC_L   ,KC_K   ,LT(RBASE, KC_J)  ,KC_H
,KC_RSFT   ,KC_SLSH     ,KC_DOT ,KC_COMM,KC_M  ,KC_N  ,KC_TAB
,KC_RCTL   ,MEH_T(KC_NO),ALL_T(KC_NO),KC_RALT,KC_RGUI
                                             ,KC_LEFT ,KC_RGHT
                                                      ,KC_UP
                                    ,KC_SPC  ,KC_ENT  ,KC_DOWN
                                                                  // right hand
                                                                 ,KC_ESC      ,KC_5   ,KC_4   ,KC_3   ,KC_2    ,KC_1  ,KC_GRV
                                                                 ,KC_LBRC     ,KC_T   ,KC_R   ,KC_E   ,KC_W    ,KC_Q  ,KC_TAB
                                                                              ,KC_G   ,LT(RBASE, KC_F),KC_D   ,KC_S   ,LT(RBASE, KC_A)  ,KC_ESC
                                                                 ,LSFT(KC_TAB),KC_B   ,KC_V   ,KC_C   ,KC_X    ,KC_Z  ,KC_LSFT
                                                                                      ,KC_LGUI,KC_LALT,KC_HYPR ,KC_MEH,KC_LCTL
                                                                 ,KC_HOME     ,KC_END
                                                                 ,KC_PGUP
                                                                 ,KC_PGDN     ,KC_BSPC ,KC_DEL
)
};

const uint16_t PROGMEM fn_actions[] = {
     // the faux shift keys are implemented as macro taps
     [LSymb] = ACTION_MACRO_TAP(LSymb)
    ,[LMdia] = ACTION_MACRO_TAP(LMdia)
    ,[LSpec] = ACTION_MACRO_TAP(LSpec)
    ,[RSymb] = ACTION_MACRO_TAP(RSymb)
    ,[RMdia] = ACTION_MACRO_TAP(RMdia)
    ,[RSpec] = ACTION_MACRO_TAP(RSpec)
};

int16_t symb_shift = 0;
int16_t mdia_shift = 0;
int16_t spec_shift = 0;

bool mdia_lock = false;
bool symb_lock = false;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        // There are two shift keys for each layer so we increment a layer_shift var when one
        // is pressed and decrement when one is released. The shift counts are bound between 0 and 2
        // only because sometimes rapid pressing led to irregular events; this way the states
        // are self healing during use.

        case LSymb:
        if (record->event.pressed) {
           if (record->tap.count && (!symb_shift) && (!symb_lock) && (!spec_shift)) {
                register_code(KC_ESC);
            } else {
                //if(spec_shift) symb_lock = !symb_lock;
                if(++symb_shift > 2) symb_shift = 2;
                layer_on(SYMB);
            }
        } else {
            if(record->tap.count && (!symb_shift) && (!symb_lock) && (!spec_shift)) {
                unregister_code(KC_ESC);
            } else {
                if(--symb_shift < 0) symb_shift = 0;
                if((!symb_shift) && (!symb_lock)) layer_off(SYMB);
            }
        }
        break;

        case LMdia:
        if (record->event.pressed) {
           if (record->tap.count && (!mdia_shift) && (!mdia_lock) && (!spec_shift)) {
                register_code(KC_TAB);
            } else {
                //if(spec_shift) mdia_lock = !mdia_lock;
                if(++mdia_shift > 2) mdia_shift = 2;
                layer_on(MDIA);
            }
        } else {
            if(record->tap.count && (!mdia_shift) && (!mdia_lock) && (!spec_shift)) {
                unregister_code(KC_TAB);
            } else {
                if(--mdia_shift < 0) mdia_shift = 0;
                if((!mdia_shift) && (!mdia_lock)) layer_off(MDIA);
            }
        }
        break;

        case LSpec:
        if (record->event.pressed) {                                     // when the LSpec button is pressed
            //if(symb_shift) symb_lock = !symb_lock;                       // if another layer button is engaged, then
            //else if(mdia_shift) mdia_lock = !mdia_lock;                  // lock that layer, be it caps or symb or mdia
            if (record->tap.count && !record->tap.interrupted && (!spec_shift)) {
                register_code(KC_GRV);                                   // otherwise, if it's an uninterrupted tap, emit a char
            } else {
                if(++spec_shift > 2) spec_shift = 2;
                layer_on(SPEC);                                          // otherwise, turn on the Special layer
            }
        } else {
            if(record->tap.count && !record->tap.interrupted && (!spec_shift)) {
                unregister_code(KC_GRV);
            } else {
                if(--spec_shift < 0) spec_shift = 0;
                if(!spec_shift) layer_off(SPEC);
            }
        }
        break;

        case RSymb:
        if (record->event.pressed) {
            if (record->tap.count && (!symb_shift) && (!symb_lock) && (!spec_shift)) {
                register_code(KC_QUOT);
            } else {
                if(++symb_shift > 2) symb_shift = 2;
                //if(spec_shift) symb_lock = !symb_lock;
                layer_on(SYMB);
            }
        } else {
            if(record->tap.count && (!symb_shift) && (!symb_lock) && (!spec_shift)) {
                unregister_code(KC_QUOT);
            } else {
                if(--symb_shift < 0) symb_shift = 0;
                if((!symb_shift) && (!symb_lock)) layer_off(SYMB);
            }
        }
        break;

        case RMdia:
        if (record->event.pressed) {
            if (record->tap.count && (!mdia_shift) && (!mdia_lock) && (!spec_shift)) {
                register_code(KC_BSLS);
            } else {
                if(++mdia_shift > 2) mdia_shift = 2;
                //if(spec_shift) mdia_lock = !mdia_lock;
                layer_on(MDIA);
            }
        } else {
            if(record->tap.count && (!mdia_shift) && (!mdia_lock) && (!spec_shift)) {
                unregister_code(KC_BSLS);
            } else {
                if(--mdia_shift < 0) mdia_shift = 0;
                if((!mdia_shift) && (!mdia_lock)) layer_off(MDIA);
            }
        }
        break;

        case RSpec:
        if (record->event.pressed) {
            //if(symb_shift) symb_lock = !symb_lock;
            //else if(mdia_shift) mdia_lock = !mdia_lock;
            if (record->tap.count && !record->tap.interrupted && (!spec_shift)) {
                register_code(KC_EQL);
            } else {
                if(++spec_shift > 2) spec_shift = 2;
                layer_on(SPEC);
            }
        } else {
            if(record->tap.count && !record->tap.interrupted && (!spec_shift)) {
                unregister_code(KC_EQL);
            } else {
                if(--spec_shift < 0) spec_shift = 0;
                if(!spec_shift) layer_off(SPEC);
            }
        }
        break;

        case NotEq:
        if (record->event.pressed) {
            return MACRO( I(10), D(LSFT), T(EXLM), U(LSFT), T(EQL), END  ); // !=
        }
        break;

        case GrtEq:
        if (record->event.pressed) {
            return MACRO( I(10), D(LSFT), T(COMM), U(LSFT), T(EQL), END  ); // <=
        }
        break;

        case LesEq:
        if (record->event.pressed) {
            return MACRO( I(10), D(LSFT), T(DOT), U(LSFT), T(EQL), END  ); // >=
        }
        break;

        case DeRef:
        if (record->event.pressed) {
            return MACRO( I(10), T(MINS), D(LSFT), T(DOT), U(LSFT), END  ); // ->
        }
        break;

        case Asig:
        if (record->event.pressed) {
            return MACRO( I(10), D(LSFT), T(COMM), U(LSFT), T(MINS), END  ); // <-
        }
        break;

        case RGB_SLD:
          if (record->event.pressed) {
            #ifdef RGBLIGHT_ENABLE
            rgblight_mode(1);
            #endif
          }
          return false;
          break;


        // mouse diagonals

        case MUL: // mouse up left
        if (record->event.pressed) {
            mousekey_on(KC_MS_UP);
            mousekey_on(KC_MS_LEFT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_UP);
            mousekey_off(KC_MS_LEFT);
            mousekey_send();
        }
        break;

        case MUR: // mouse up right
        if (record->event.pressed) {
            mousekey_on(KC_MS_UP);
            mousekey_on(KC_MS_RIGHT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_UP);
            mousekey_off(KC_MS_RIGHT);
            mousekey_send();
        }
        break;

        case MDL: // mouse down left
        if (record->event.pressed) {
            mousekey_on(KC_MS_DOWN);
            mousekey_on(KC_MS_LEFT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_DOWN);
            mousekey_off(KC_MS_LEFT);
            mousekey_send();
        }
        break;

        case MDR: // mouse down right
        if (record->event.pressed) {
            mousekey_on(KC_MS_DOWN);
            mousekey_on(KC_MS_RIGHT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_DOWN);
            mousekey_off(KC_MS_RIGHT);
            mousekey_send();
        }
        break;

        default:
            // none
            break;
    }

    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
  rgblight_enable();
  #endif
};


typedef struct HsvColor
{
    unsigned char h;
    unsigned char s;
    unsigned char v;
} HsvColor;

HsvColor my_hsv;

HsvColor RgbToHsv(unsigned char r, unsigned char g, unsigned char b, HsvColor hsv)
{
    unsigned char rgbMin, rgbMax;

    rgbMin = r < g ? (r < b ? r : b) : (g < b ? g : b);
    rgbMax = r > g ? (r > b ? r : b) : (g > b ? g : b);

    hsv.v = rgbMax;
    if (hsv.v == 0)
    {
        hsv.h = 0;
        hsv.s = 0;
        return hsv;
    }

    hsv.s = (255 * ((long)(rgbMax - rgbMin))) / hsv.v;
    if (hsv.s == 0)
    {
        hsv.h = 0;
        return hsv;
    }

    if (rgbMax == r)
        hsv.h = 0 + 43 * (g - b) / (rgbMax - rgbMin);
    else if (rgbMax == g)
        hsv.h = 85 + 43 * (b - r) / (rgbMax - rgbMin);
    else
        hsv.h = 171 + 43 * (r - g) / (rgbMax - rgbMin);

    return hsv;
}


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  #ifdef RGBLIGHT_ENABLE
    unsigned char red, green, blue;


    // shift or caps lock turns on red light
    if((keyboard_report->mods & MOD_BIT(KC_LSFT))
    || (keyboard_report->mods & MOD_BIT(KC_RSFT))
    || (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))) {
        ergodox_right_led_1_on();
        red = 0xff;
    } else {
        ergodox_right_led_1_off();
        red = 0x00;
    }

    // Symbol layer turns on green light
    if(layer_state & (1UL<<SYMB)) {
        ergodox_right_led_2_on();
        green = 0xff;
    } else {
        ergodox_right_led_2_off();
        green = 0x00;
    }

    // Media layer turns on blue light
    if(layer_state & (1UL<<MDIA)) {
        ergodox_right_led_3_on();
        blue = 0xff;
    } else {
        ergodox_right_led_3_off();
        blue = 0x00;
    }

    // Special layer turns on all light
    if(layer_state & (1UL<<SPEC)) {
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
    }

    // if all layers activated, turn off underlighting
    if (red == 0xff && green == 0xff && blue == 0xff) {
        red = 0x00;
        green = 0x00;
        blue = 0x00;
    }

    // if no layers activated, turn on white underlighting
    else if (red == 0x00 && green == 0x00 && blue == 0x00) {
        red = 0xff;
        green = 0xff;
        blue = 0xff;
    }


    my_hsv = RgbToHsv(red, green, blue, my_hsv);
    rgblight_sethsv(my_hsv.h,my_hsv.s,my_hsv.v);
    // rgblight_sethsv(0,255,255);
    #endif


};
