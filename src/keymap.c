#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "song_list.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

//macro to send a unicode character for a given keycode
#define SUC(kc, uc) \
case kc: \
if (record->event.pressed) { \
	send_unicode_string(uc); \
} \
break;
//abstraction for control key
bool ctrl_mode = true; //true = linux/win false = mac

void send_ctrl_string(bool ctrl_mode, uint16_t kc)
{
	switch (ctrl_mode) {
		case true:
			register_code16(LCTL(kc));
			break;

		case false:
			register_code16(LGUI(kc));
			break;
		}
}

void unsend_ctrl_string(bool ctrl_mode, uint16_t kc)
{
	switch (ctrl_mode) {
		case true:
			unregister_code16(LCTL(kc));
			break;
		case false:
			unregister_code16(LGUI(kc));
			break;
		}
}
// music
#define VICTORY_FANFARE_SHORT \
    ED_NOTE(_C6), \
    ED_NOTE(_C6), \
    ED_NOTE(_C6), \
    ED_NOTE(_C6), \
    W__NOTE(_REST), \
    QD_NOTE(_GS5), \
    QD_NOTE(_AS5), \
    Q__NOTE(_C6), \
    Q__NOTE(_AS5), \
    Q__NOTE(_C6), \

		#define IMPERIAL_MARCH \
		HD_NOTE(_A4), HD_NOTE(_A4), HD_NOTE(_A4), QD_NOTE(_F4), QD_NOTE(_C5), \
		HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4), \
		HD_NOTE(_E5), HD_NOTE(_E5), HD_NOTE(_E5), QD_NOTE(_F5), QD_NOTE(_C5), \
		HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4)

		#define TO_BOLDLY_GO \
		W__NOTE(_BF3 ), \
		Q__NOTE(_EF4 ), \
		WD_NOTE(_AF4 ), \
		W__NOTE(_REST), \
		H__NOTE(_G4  ), \
		Q__NOTE(_EF4 ), \
		H__NOTE(_C4  ), \
		W__NOTE(_REST), \
		QD_NOTE(_F4  ), \
		M__NOTE(_BF4, 128),


		float music_impr[][2] = SONG(IMPERIAL_MARCH);
float music_vic[][2] = SONG(TO_BOLDLY_GO);

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  LSFT_NE_UE, NE_UE,
	LSFT_NE_OE, NE_OE,
	LSFT_NE_AE, NE_AE,
	LSFT_NE_SS, NE_SS,
	NE_SCRIPT_L, NE_LEFT_GUILLEMET, NE_RIGHT_GUILLEMET, NE_DOLLAR,  NE_LOW_QUOTE, //second layer keycodes
	NE_DOUBLE_QUOTE, NE_RIGHT_DOUBLE_QUOTE, NE_EM_DASH, NE_CEDILLE, NE_BULLET,
	NE_SUP_ONE, NE_SUP_TWO, NE_SUP_THREE, NE_SNG_ANG_QUOT, NE_SNG_ANG_QUOT_RI,NE_EN_DASH,
	NE_CENT, NE_YEN, NE_SNG_LOW_QUOT, NE_SNG_QUOT_LE, NE_SNG_QUOT_RI, NE_ELLIPSIS, NE_RING_ABOVE, NE_LONG_S,	//layer 3 keycodes
	NE_FEMALE_ORD,NE_MALE_ORD,NE_NUMERO,NE_MID_DOT,NE_POUND,NE_CURRENCY,NE_TREMA, //layer 4 keycodes
	LOWER_ONE, LOWER_TWO, LOWER_THREE, NE_FEM, NE_MAL, NE_HERM, NE_VARKAPPA, MTH_LANGLE, MTH_RANGLE, LOWER_ZERO, //layer 5: greek keycodes
	NE_XI, NE_LAMB, NE_CHI, NE_OMEG, NE_KAPP, NE_PSI, NE_GAMM, NE_PHI2, NE_PHI, NE_SIGMA2,
	NE_IOTA, NE_ALPH, NE_EPSL, NE_OMCR, NE_SIGM, NE_NU, NE_RHO, NE_TAU, NE_DELT,
	NE_NU2, NE_EPSL2, NE_ETA, NE_PI, NE_ZETA, NE_BETA, NE_MU, NE_RHO2, NE_THET2,
	NE_THET, SECURE_SPACE,NE_NON_BRK_HYPHEN,
	NE_CAP_XI, NE_SQRT, NE_CAP_LAMBDA, NE_COMPLEX, NE_CAP_OMEGA, NE_CROSS_PROD, //layer 6: math keycodes
	NE_CAP_PSI, NE_CAP_GAM, NE_CAP_PHI, NE_FRAC_NUM, NE_SUBSETOF, NE_INTEGRAL, NE_FORALL,
	NE_EXIST, NE_NAT_NUM, NE_REAL_NUM, NE_PARTIAL, NE_CAP_DELTA, NE_NABLA, NE_UNION,
	NE_INTERSECTION, NE_ALEPH, NE_CAP_PI, NE_DBL_BAR_Z, NE_LONG_DBL_ARR_LE, NE_LE_RI_ARR,
	NE_LONG_DBL_ARR_RI, NE_LONG_ARR_RI, NE_CAP_THETA, NE_NOT, NE_OR, NE_AND,
	NE_ORTHO,NE_ANGLE,NE_PARALLEL,NE_ARROW_RI,NE_INFINITY,NE_PROPTO,NE_EMPTY_SET,
	NE_IN_SET,NE_CAP_SIGMA,SECURE_SPACE_NARROW,NE_SOFT_HYPHEN,
  CSTM_CTRL_MODE_TOG,  //macro keys
  PLY_IMPR, PLY_FF,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,
  DANCE_12,
  DANCE_13,
  DANCE_14,
  DANCE_15,
  DANCE_16,
  DANCE_17,
  DANCE_18,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    TD(DANCE_0),    TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_5),    KC_TRANSPARENT,  TD(DANCE_11),   TD(DANCE_12),   TD(DANCE_13),   TD(DANCE_14),   TD(DANCE_15),   TD(DANCE_16),   KC_BSPACE,
    KC_TAB,         TD(DANCE_6),    TD(DANCE_7),    KC_L,           TD(DANCE_8),    KC_W,           KC_HYPR,         KC_RCTRL, KC_K,           KC_H,           KC_G,           KC_F,           KC_Q,           NE_SS,
    MO(2),          KC_U,           KC_I,           TD(DANCE_9),    KC_E,           KC_O,           KC_MEH,          MO(2),          KC_S,           KC_N,           KC_R,           KC_T,           KC_D,           KC_Y,
    KC_LSPO,        NE_UE,          NE_OE,          NE_AE,          KC_P,           TD(DANCE_10),                                    KC_B,           KC_M,           TD(DANCE_17),   TD(DANCE_18),   KC_UP,          KC_J,
    TT(6),          LCTL(KC_LALT),  KC_LALT,        KC_LGUI,        KC_LCTRL,       MO(5),                                                                                                          KC_RSPC,        LCTL(KC_S),     LCTL(KC_F),     KC_LEFT,        KC_DOWN,        KC_RIGHT,       
                                                   KC_SPACE,       MO(3),          MO(4),                                           KC_LGUI,        KC_ENTER,       KC_BSPACE
  ),
  [1] = LAYOUT_moonlander(
    LSFT(DE_ACUT),  KC_CIRC,        S(ALGR(US_S)),  NE_SCRIPT_L,    NE_LEFT_GUILLEMET,NE_RIGHT_GUILLEMET, KC_TRANSPARENT,  NE_EM_DASH,     NE_DOLLAR,      ALGR(US_5),     NE_LOW_QUOTE,   NE_DOUBLE_QUOTE,NE_RIGHT_DOUBLE_QUOTE, KC_TRANSPARENT,	//	NE_CEDILLE, //Tapdance with KC_DELETE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,       KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,       KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                        KC_TRANSPARENT, KC_TRANSPARENT, NE_EN_DASH,       NE_BULLET, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                        KC_TRANSPARENT, KC_PGUP,        KC_PGDOWN,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, NE_SUP_ONE,			NE_SUP_TWO,NE_SUP_THREE,	NE_SNG_ANG_QUOT,	NE_SNG_ANG_QUOT_RI,	KC_TRANSPARENT,	KC_TRANSPARENT, NE_CENT,		NE_YEN,			NE_SNG_LOW_QUOT,		NE_SNG_QUOT_LE,		NE_SNG_QUOT_RI,		NE_RING_ABOVE,
    KC_TRANSPARENT, NE_ELLIPSIS,		KC_UNDS,	KC_LBRACKET,		KC_RBRACKET,			KC_CIRC,						KC_TRANSPARENT,	KC_TRANSPARENT, KC_EXLM,		KC_LABK,		KC_RABK,		KC_EQUAL,		KC_AMPR,		NE_LONG_S,
    KC_TRANSPARENT, KC_BSLASH,			KC_SLASH, KC_LCBR,				KC_RCBR,					KC_ASTR,						KC_TRANSPARENT,	KC_TRANSPARENT, KC_QUES,		KC_LPRN,		KC_RPRN,		KC_MINS,		KC_COLN,		KC_AT,
    KC_TRANSPARENT, KC_HASH,				KC_DLR,		KC_PIPE,				KC_TILD, 					KC_GRAVE,																						KC_PLUS,		KC_PERC,		KC_DQUO,		KC_QUOTE,		KC_SCOLON,	KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, NE_FEMALE_ORD,	NE_MALE_ORD,		NE_NUMERO,			KC_TRANSPARENT,	NE_MID_DOT,			KC_TRANSPARENT,KC_MINUS,        NE_POUND,       NE_CURRENCY,		KC_TAB,					KC_SLASH,				KC_ASTR,				KC_MINS,
    KC_SPACE,       KC_PGUP,        KC_BSPACE,      KC_UP,          KC_DELETE,      KC_PGDOWN,      KC_TRANSPARENT,KC_TRANSPARENT,  KC_TRANSPARENT, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         KC_TRANSPARENT,KC_TRANSPARENT,  KC_KP_ASTERISK, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_TRANSPARENT,
    KC_LSHIFT,      KC_ESCAPE,      KC_TAB,         KC_INSERT,      KC_ENTER,       KC_PC_UNDO,                                     KC_KP_SLASH,    KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT,  KC_KP_0,        KC_KP_0,        KC_KP_DOT,      KC_KP_COMMA,    TO(0),
                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
	[4] = LAYOUT_moonlander(
    KC_TRANSPARENT, LOWER_ONE, 			LOWER_TWO,			LOWER_THREE,		NE_FEM,					NE_MAL,					KC_TRANSPARENT, 		NE_NON_BRK_HYPHEN, NE_HERM,     NE_VARKAPPA,    MTH_LANGLE, MTH_RANGLE,		LOWER_ZERO,		KC_TRANSPARENT,
    KC_TRANSPARENT, NE_XI,          KC_TRANSPARENT, NE_LAMB,				NE_CHI,         NE_OMEG,			  KC_TRANSPARENT, 		KC_TRANSPARENT, NE_KAPP,				NE_PSI,					NE_GAMM,		NE_PHI2,			NE_PHI, 			NE_SIGMA2,
    KC_TRANSPARENT, KC_TRANSPARENT, NE_IOTA,				NE_ALPH, 				NE_EPSL, 				NE_OMCR, 				KC_TRANSPARENT, 		KC_TRANSPARENT, NE_SIGM,				NE_NU,					NE_RHO,			NE_TAU,				NE_DELT,			NE_NU2,
    KC_TRANSPARENT, KC_TRANSPARENT, NE_EPSL2, 			NE_ETA,					NE_PI,					NE_ZETA,                                            NE_BETA,				NE_MU,					NE_RHO2,		NE_THET2,			NE_THET,			KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    SECURE_SPACE,   KC_TRANSPARENT, KC_TRANSPARENT,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT,	NE_NOT,					NE_OR,						NE_AND,					NE_ORTHO,			NE_ANGLE,				KC_TRANSPARENT,		NE_SOFT_HYPHEN,	NE_PARALLEL,				NE_ARROW_RI,	NE_INFINITY,				NE_PROPTO,			NE_EMPTY_SET,	KC_TRANSPARENT,
    KC_TRANSPARENT, NE_CAP_XI,			NE_SQRT,					NE_CAP_LAMBDA,	NE_COMPLEX,		NE_CAP_OMEGA,		KC_TRANSPARENT,		KC_TRANSPARENT,	NE_CROSS_PROD,			NE_CAP_PSI,		NE_CAP_GAM,					NE_CAP_PHI,			NE_FRAC_NUM,	KC_TRANSPARENT,
    KC_TRANSPARENT, NE_SUBSETOF,		NE_INTEGRAL,			NE_FORALL,			NE_EXIST,			NE_IN_SET,			KC_TRANSPARENT,		KC_TRANSPARENT,	NE_CAP_SIGMA,				NE_NAT_NUM,		NE_REAL_NUM,				NE_PARTIAL,			NE_CAP_DELTA,	NE_NABLA,
    KC_TRANSPARENT, NE_UNION,				NE_INTERSECTION,	NE_ALEPH,				NE_CAP_PI,		NE_DBL_BAR_Z,																			NE_LONG_DBL_ARR_LE,	NE_LE_RI_ARR,	NE_LONG_DBL_ARR_RI,	NE_LONG_ARR_RI,	NE_CAP_THETA,	KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,		KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    SECURE_SPACE_NARROW, KC_TRANSPARENT, KC_TRANSPARENT,              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
    [6] = LAYOUT_moonlander(
    TO(0),          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          AU_TOG,		RESET,          KC_TRANSPARENT, KC_TRANSPARENT, TO(7),          TO(8),          KC_ASRP, UNICODE_MODE_MAC,
    KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         MU_TOG,		WEBUSB_PAIR,    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_ASUP, UNICODE_MODE_LNX,
    CSTM_CTRL_MODE_TOG,KC_F11,      KC_PGUP,        KC_UP,          KC_PGDOWN,      KC_F12,         MU_MOD,		KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_ASDN, UNICODE_MODE_WINC,
    KC_LSHIFT,      KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT,                           RGB_MOD,        RGB_HUI,        RGB_VAI,        RGB_SPI,        RGB_SAI, TOGGLE_LAYER_COLOR,
    KC_TRANSPARENT, KC_TRANSPARENT, PLY_IMPR,       PLY_FF,         KC_TRANSPARENT, KC_MS_BTN3,                               KC_TRANSPARENT, RGB_HUD,        RGB_VAD,        RGB_SPD,        RGB_SAD, RGB_TOG,
                                                    KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                           KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_WH_UP
  ),
  [7] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_ESCAPE,  KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         RSFT(KC_X),     RSFT(KC_V),     RSFT(KC_L),     RSFT(KC_C),     RSFT(KC_W),     RSFT(KC_K), KC_TRANSPARENT, RSFT(KC_K),     RSFT(KC_H),     RSFT(KC_G),     RSFT(KC_F),     RSFT(KC_Q),     NE_SS,
    KC_TRANSPARENT, RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_A),     RSFT(KC_E),     RSFT(KC_O),     RSFT(KC_S), KC_TRANSPARENT, RSFT(KC_S),     RSFT(KC_N),     RSFT(KC_R),     RSFT(KC_T),     RSFT(KC_D),     RSFT(DE_Y),
    KC_LSHIFT,      RSFT(NE_UE),    RSFT(NE_OE),    RSFT(NE_AE),    RSFT(KC_P),     RSFT(DE_Z),                                 RSFT(KC_B),     RSFT(KC_M),     KC_COMMA,       KC_DOT,         RSFT(KC_J),     KC_RSHIFT,
    KC_LCTRL,       KC_LGUI,        KC_LALT,        KC_LEFT,        KC_RIGHT,       KC_ENTER,                                                                                                       KC_ENTER,       KC_UP,          KC_DOWN,        KC_TRANSPARENT, KC_TRANSPARENT, TO(0),
    KC_SPACE,       KC_LALT,        KC_LCTRL,                       KC_RCTRL,       KC_RALT,        KC_SPACE
  ),
  [8] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,  KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,  KC_TRANSPARENT, KC_Z,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_LCTRL,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,  KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LSHIFT,      KC_Y,           KC_X,           KC_C,           KC_V,           KC_B,                                            KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_TRANSPARENT, KC_ASTG,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ENTER,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),
    KC_SPACE,       KC_LCTRL,       KC_LALT,                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,0}, {0,0,0}, {15,166,195}, {32,176,255}, {195,61,255}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {50,153,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {50,153,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {50,153,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {50,153,244}, {50,153,244}, {85,203,158}, {31,255,255}, {168,243,193}, {0,233,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,233,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,233,217}, {0,233,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,233,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {50,153,244}, {15,166,195}, {85,203,158}, {85,203,158}, {10,225,255}, {32,176,255} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {15,166,195}, {15,166,195}, {15,166,195}, {15,166,195}, {15,166,195}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {15,166,195}, {15,166,195}, {15,166,195}, {0,0,0}, {15,166,195}, {15,166,195}, {15,166,195}, {15,166,195}, {15,166,195}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {15,166,195}, {15,166,195}, {15,166,195}, {0,0,0} },

    [3] = { {31,255,255}, {31,255,255}, {31,255,255}, {32,176,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {141,255,233}, {141,255,233}, {0,0,0}, {141,255,233}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {141,255,233}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0} },

    [4] = { {168,243,193}, {168,243,193}, {168,243,193}, {168,243,193}, {168,243,193}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {168,243,193}, {168,243,193}, {168,243,193}, {168,243,193}, {168,243,193}, {168,243,193}, {168,243,193}, {168,243,193}, {168,243,193}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {168,243,193}, {168,243,193}, {168,243,193}, {168,243,193} },

    [5] = { {0,233,217}, {0,233,217}, {0,233,217}, {0,233,217}, {0,233,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,233,217}, {0,233,217}, {0,233,217}, {0,233,217}, {0,233,217}, {0,233,217}, {0,233,217}, {0,233,217}, {0,233,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,233,217}, {0,233,217}, {0,233,217}, {0,233,217} },

    [6] = { {180,255,233}, {0,0,0}, {0,183,238}, {32,176,255}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {85,203,158}, {85,203,158}, {0,0,0}, {134,255,213}, {134,255,213}, {85,203,158}, {85,203,158}, {0,0,0}, {134,255,213}, {134,255,213}, {85,203,158}, {85,203,158}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,183,238}, {0,183,238}, {0,0,0}, {0,183,238}, {195,61,255}, {195,61,255}, {195,61,255}, {14,255,255}, {14,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {14,255,255}, {14,255,255}, {180,255,233}, {0,0,0}, {0,183,238}, {14,255,255}, {14,255,255}, {180,255,233}, {0,183,238}, {0,183,238}, {14,255,255}, {14,255,255}, {85,203,158}, {0,0,0}, {0,183,238}, {14,255,255}, {14,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {14,255,255}, {50,153,244}, {50,153,244}, {0,0,0}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0} },

    [7] = { {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {10,225,255}, {157,53,253}, {157,53,253}, {157,53,253}, {10,225,255}, {10,225,255}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {10,225,255}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {0,183,238}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {85,203,158}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {134,255,213}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253}, {157,53,253} },

    [8] = { {31,255,255}, {0,0,0}, {50,153,244}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,205,155}, {0,0,0}, {0,0,0}, {0,0,0}, {0,205,155}, {0,205,155}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,205,155}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {50,153,244}, {0,183,238}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,205,155}, {0,205,155}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,205,155}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NE_UE:
    if (record->event.pressed) {
			unregister_code16(NE_UE);
			send_unicode_string("ü");
    }
    break;
    case LSFT_NE_UE:
    if (record->event.pressed) {
			unregister_code16(LSFT_NE_UE);
      send_unicode_string("Ü");
    }
    break;
		case NE_OE:
		if (record->event.pressed) {
			send_unicode_string("ö");
		}
		break;
		case LSFT_NE_OE :
    if (record->event.pressed) {
      send_unicode_string("Ö");
    }
    break;

		case NE_AE:
    if (record->event.pressed) {
      send_unicode_string("ä");
    }
    break;

		case LSFT_NE_AE:
    if (record->event.pressed) {
      send_unicode_string("Ä");
    }
    break;

		case NE_SS:
		if (record->event.pressed) {
			send_unicode_string("ß");

		}
		break;

		case LSFT_NE_SS:
		if (record->event.pressed) {
			send_unicode_string("ẞ");

		}
		break;
		//SUC(NE_°,"°")//layer 2 start
		//SUC(NE_§,"§")
		SUC(NE_SCRIPT_L, "ℓ")
		SUC(NE_LEFT_GUILLEMET, "»")
		SUC(NE_RIGHT_GUILLEMET,"«")
		SUC(NE_DOLLAR,"$")
		//SUC(NE_€,"€")
		SUC(NE_LOW_QUOTE, "„")
		SUC(NE_DOUBLE_QUOTE, "“")
		SUC(NE_RIGHT_DOUBLE_QUOTE, "”")
		SUC(NE_CEDILLE, "¸")
		SUC(NE_EM_DASH, "—")
		SUC(NE_EN_DASH,"–")
		SUC(NE_BULLET, "•")//layer 2 end
		SUC(NE_SUP_ONE,"¹")//layer 3 start
		SUC(NE_SUP_TWO,"²")
		SUC(NE_SUP_THREE,"³")
		SUC(NE_SNG_ANG_QUOT, "›")
		SUC(NE_SNG_ANG_QUOT_RI, "‹")
		SUC(NE_CENT, "¢")
		SUC(NE_YEN, "¥")
		SUC(NE_SNG_LOW_QUOT, "‚")
		SUC(NE_SNG_QUOT_LE, "‘")
		SUC(NE_SNG_QUOT_RI, "’")
		SUC(NE_ELLIPSIS, "…")
		SUC(NE_RING_ABOVE, "˚")
		SUC(NE_LONG_S,"ſ")//layer 3 end
		SUC(NE_FEMALE_ORD,"ª")//layer 4 start
		SUC(NE_MALE_ORD,"º")
		SUC(NE_NUMERO,"№")
		SUC(NE_MID_DOT, "·")
		SUC(NE_POUND, "£")
		SUC(NE_CURRENCY, "¤")
		SUC(NE_TREMA,"¨")//layer 4 end
		SUC(LOWER_ONE,"₁")//layer 5 end
		SUC(LOWER_TWO,"₂")
		SUC(LOWER_THREE  ,"₃")
		SUC(NE_FEM  ,"♀")
		SUC(NE_MAL  ,"♂")
		SUC(NE_HERM  ,"⚥")
		SUC(NE_VARKAPPA,"ϰ")
		SUC(MTH_LANGLE,"⟨")
		SUC(MTH_RANGLE,"⟩")
		SUC(LOWER_ZERO,"₀")
		SUC(NE_NON_BRK_HYPHEN,"‑")
		SUC(NE_XI, "ξ")
		SUC(NE_LAMB,"λ")
		SUC(NE_CHI,"χ")
		SUC(NE_OMEG,"ω")
		SUC(NE_KAPP,"κ")
		SUC(NE_PSI,"ψ")
		SUC(NE_GAMM,"γ")
		SUC(NE_PHI2,"ϕ")
		SUC(NE_PHI,"φ")
		SUC(NE_SIGMA2,"ς")
		SUC(NE_IOTA,"ι")
		SUC(NE_ALPH, "α")
    SUC(NE_EPSL,"ε")
		SUC(NE_OMCR,"ο")
		SUC(NE_SIGM,"σ")
		SUC(NE_NU,"ν")
		SUC(NE_RHO,"ρ")
		SUC(NE_TAU,"τ")
		SUC(NE_DELT,"δ")
		SUC(NE_NU2,"υ")
		SUC(NE_EPSL2,"")
		SUC(NE_ETA,"η")
		SUC(NE_PI,"π")
		SUC(NE_ZETA,"ζ")
		SUC(NE_BETA,"β")
		SUC(NE_MU,"μ")
		SUC(NE_RHO2,"ϱ")
		SUC(NE_THET2,"ϑ")
		SUC(NE_THET,"θ")
		SUC(SECURE_SPACE," ")//(U+00A0 NO-BREAK SPACE)//layer 5 end
		SUC(NE_CAP_XI,"Ξ")//layer 6: math keycodes
		SUC(NE_SQRT,"√")
		SUC(NE_CAP_LAMBDA,"Λ")
		SUC(NE_COMPLEX,"ℂ")
		SUC(NE_CAP_OMEGA,"Ω")
		SUC(NE_CROSS_PROD,"⨯")
		SUC(NE_CAP_PSI,"Ψ")
		SUC(NE_CAP_GAM,"Γ")
		SUC(NE_CAP_PHI,"Φ")
		SUC(NE_FRAC_NUM,"ℚ")
		SUC(NE_SUBSETOF,"⊂")
		SUC(NE_INTEGRAL,"∫")
		SUC(NE_FORALL,"∀")
		SUC(NE_EXIST,"∃")
		SUC(NE_NAT_NUM,"ℕ")
		SUC(NE_REAL_NUM,"ℝ")
		SUC(NE_PARTIAL,"∂")
		SUC(NE_CAP_DELTA, "Δ")
		SUC(NE_NABLA, "∇")
		SUC(NE_UNION,"∪")
		SUC(NE_INTERSECTION,"∩")
		SUC(NE_ALEPH,"ℵ")
		SUC(NE_CAP_PI,"Π")
		SUC(NE_DBL_BAR_Z,"ℤ")
		SUC(NE_LONG_DBL_ARR_LE,"⇐")
		SUC(NE_LE_RI_ARR,"⇔")
		SUC(NE_LONG_DBL_ARR_RI,"⇒")
		SUC(NE_LONG_ARR_RI, "↦")
		SUC(NE_CAP_THETA,"Θ")
		SUC(NE_NOT,"¬")
		SUC(NE_OR,"∨")
		SUC(NE_AND,"∧")
		SUC(NE_ORTHO,"⊥")
		SUC(NE_ANGLE,"∡")
		SUC(NE_SOFT_HYPHEN,"")
		SUC(NE_PARALLEL,"∥")
		SUC(NE_ARROW_RI,"→")
		SUC(NE_INFINITY,"∞")
		SUC(NE_PROPTO,"∝")
		SUC(NE_EMPTY_SET,"∅")
		SUC(NE_IN_SET,"∈")
		SUC(NE_CAP_SIGMA,"∑")
    SUC(SECURE_SPACE_NARROW," ")//(U+202F NARROW NO-BREAK SPACE)
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
		case CSTM_CTRL_MODE_TOG:
			if (record->event.pressed) {
				if (ctrl_mode == true) {
					ctrl_mode = false;
					send_string("Mac\n");
					break;
				}

				if (ctrl_mode == false) {
					ctrl_mode = true;
					send_string("Lnx\n");
					break;
				}
			}
			case PLY_IMPR:
			if (record->event.pressed) {
				PLAY_SONG(music_impr);
			}
			break;
			case PLY_FF:
			if (record->event.pressed) {
				PLAY_SONG(music_vic);
			}
			break;
			return false;
		}
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[19];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: register_code16(KC_GRAVE); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: unregister_code16(KC_GRAVE); break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_1);
        tap_code16(KC_1);
        tap_code16(KC_1);
    }
    if(state->count > 3) {
        tap_code16(KC_1);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_1); break;
        case SINGLE_HOLD: register_code16(KC_CIRC); break;
        case DOUBLE_TAP: register_code16(KC_1); register_code16(KC_1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_1); register_code16(KC_1);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_1); break;
        case SINGLE_HOLD: unregister_code16(KC_CIRC); break;
        case DOUBLE_TAP: unregister_code16(KC_1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_1); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_2);
        tap_code16(KC_2);
        tap_code16(KC_2);
    }
    if(state->count > 3) {
        tap_code16(KC_2);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_2); break;
	case SINGLE_HOLD: register_code16(S(ALGR(US_S))); break;
        case DOUBLE_TAP: register_code16(KC_2); register_code16(KC_2); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_2); register_code16(KC_2);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_2); break;
	case SINGLE_HOLD: unregister_code16(S(ALGR(US_S))); break;
        case DOUBLE_TAP: unregister_code16(KC_2); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_2); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_3);
        tap_code16(KC_3);
        tap_code16(KC_3);
    }
    if(state->count > 3) {
        tap_code16(KC_3);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_3); break;
	case SINGLE_HOLD: send_unicode_string("ℓ"); break;
        case DOUBLE_TAP: register_code16(KC_3); register_code16(KC_3); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_3); register_code16(KC_3);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_3); break;
	case SINGLE_HOLD: unregister_code16(NE_SCRIPT_L); break;
        case DOUBLE_TAP: unregister_code16(KC_3); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_3); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_4);
        tap_code16(KC_4);
        tap_code16(KC_4);
    }
    if(state->count > 3) {
        tap_code16(KC_4);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
	case SINGLE_TAP: register_code16(KC_4); break;
	case SINGLE_HOLD: send_unicode_string("»"); break;
	case DOUBLE_TAP: register_code16(KC_4); register_code16(KC_4); break;
	case DOUBLE_SINGLE_TAP: tap_code16(KC_4); register_code16(KC_4);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
	case SINGLE_TAP: unregister_code16(KC_4); break;
	case SINGLE_HOLD: unregister_code16(NE_LEFT_GUILLEMET); break;
	case DOUBLE_TAP: unregister_code16(KC_4); register_code16(KC_4); break;
	case DOUBLE_SINGLE_TAP: unregister_code16(KC_4);
    }
    dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_5);
        tap_code16(KC_5);
        tap_code16(KC_5);
    }
    if(state->count > 3) {
        tap_code16(KC_5);
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_5); break;
	case SINGLE_HOLD: send_unicode_string("«"); break;
        case DOUBLE_TAP: register_code16(KC_5); register_code16(KC_5); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_5); register_code16(KC_5);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_5); break;
	case SINGLE_HOLD: unregister_code16(NE_RIGHT_GUILLEMET); break;
        case DOUBLE_TAP: unregister_code16(KC_5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_5); break;
    }
    dance_state[5].step = 0;
}



void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    if(state->count > 3) {
        tap_code16(KC_X);
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_X); break;
        case SINGLE_HOLD: register_code16(S(KC_X)); break;
        case DOUBLE_TAP: send_ctrl_string(ctrl_mode, KC_X); break;
        //case DOUBLE_HOLD: send_ctrl_string(ctrl_mode, KC_X)); break;
        //case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X);
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_X); break;
        case SINGLE_HOLD: unregister_code16(S(KC_X)); break;
        case DOUBLE_TAP: unsend_ctrl_string(ctrl_mode, KC_X); break;
        //case DOUBLE_HOLD: unsend_ctrl_string(ctrl_mode, KC_X)); break;
        //case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if(state->count > 3) {
        tap_code16(KC_V);
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_V); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_V)); break;
        case DOUBLE_TAP: send_ctrl_string(ctrl_mode, KC_V); break;
        //case DOUBLE_HOLD: send_ctrl_string(ctrl_mode, KC_V)); break;
        //case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_V); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_V)); break;
        case DOUBLE_TAP: unsend_ctrl_string(ctrl_mode, KC_V); break;
        //case DOUBLE_HOLD: unsend_ctrl_string(ctrl_mode, KC_V)); break;
        //case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if(state->count > 3) {
        tap_code16(KC_C);
    }
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_C); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_C)); break;
        case DOUBLE_TAP: send_ctrl_string(ctrl_mode, KC_C); break;
        //case DOUBLE_HOLD: send_ctrl_string(ctrl_mode, KC_C)); break;
        //case DOUBLE_SINGLE_TAP: tap_code16(KC_C); register_code16(KC_C);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_C); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_C)); break;
        case DOUBLE_TAP: unsend_ctrl_string(ctrl_mode, KC_C); break;
        //case DOUBLE_HOLD: unsend_ctrl_string(ctrl_mode, KC_C)); break;
        //case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_A);
        tap_code16(KC_A);
        tap_code16(KC_A);
    }
    if(state->count > 3) {
        tap_code16(KC_A);
    }
}

void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_A); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_A)); break;
        case DOUBLE_TAP: send_ctrl_string(ctrl_mode, KC_A); break;
        //case DOUBLE_HOLD: send_ctrl_string(ctrl_mode, KC_A)); break;
        //case DOUBLE_SINGLE_TAP: tap_code16(KC_A); register_code16(KC_A);
    }
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_A); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_A)); break;
        case DOUBLE_TAP: unsend_ctrl_string(ctrl_mode, KC_A); break;
        //case DOUBLE_HOLD: unsend_ctrl_string(ctrl_mode, KC_A)); break;
        //case DOUBLE_SINGLE_TAP: unregister_code16(KC_A); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(qk_tap_dance_state_t *state, void *user_data);
void dance_10_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_10_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_10(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Z);
        tap_code16(KC_Z);
        tap_code16(KC_Z);
    }
    if(state->count > 3) {
        tap_code16(KC_Z);
    }
}

void dance_10_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_Z); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_Z)); break;
        case DOUBLE_TAP: send_ctrl_string(ctrl_mode,KC_Z); break;
        //case DOUBLE_HOLD: send_ctrl_string(ctrl_mode, KC_Z)); break;
        //case DOUBLE_SINGLE_TAP: tap_code16(KC_Z); register_code16(KC_Z);
    }
}

void dance_10_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_Z); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_Z)); break;
        case DOUBLE_TAP: unsend_ctrl_string(ctrl_mode,KC_Z); break;
        //case DOUBLE_HOLD: unsend_ctrl_string(ctrl_mode, KC_Z)); break;
        //case DOUBLE_SINGLE_TAP: unregister_code16(KC_Z); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(qk_tap_dance_state_t *state, void *user_data);
void dance_11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_11_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_11(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: send_unicode_string("–"); break;
        case SINGLE_HOLD: send_unicode_string("—"); break;
        case DOUBLE_TAP: send_unicode_string("–"); send_unicode_string("—"); break;
        case DOUBLE_SINGLE_TAP: tap_code16(NE_EN_DASH); register_code16(NE_EN_DASH);
    }
}

void dance_11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(NE_EN_DASH); break;
        case SINGLE_HOLD: unregister_code16(NE_EM_DASH); break;
        case DOUBLE_TAP: unregister_code16(NE_EN_DASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(NE_EN_DASH); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(qk_tap_dance_state_t *state, void *user_data);
void dance_12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_12_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_12(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_6);
        tap_code16(KC_6);
        tap_code16(KC_6);
    }
    if(state->count > 3) {
        tap_code16(KC_6);
    }
}

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_6); break;
        case SINGLE_HOLD: send_unicode_string("$"); break;
        case DOUBLE_TAP: register_code16(KC_6); register_code16(KC_6); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_6); register_code16(KC_6);
    }
}

void dance_12_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_6); break;
        case SINGLE_HOLD: unregister_code16(NE_DOLLAR); break;
        case DOUBLE_TAP: unregister_code16(KC_6); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_6); break;
    }
    dance_state[12].step = 0;
}
void on_dance_13(qk_tap_dance_state_t *state, void *user_data);
void dance_13_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_13_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_13(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_7);
        tap_code16(KC_7);
        tap_code16(KC_7);
    }
    if(state->count > 3) {
        tap_code16(KC_7);
    }
}

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_7); break;
        case SINGLE_HOLD: register_code16(ALGR(US_5)); break;
        case DOUBLE_TAP: register_code16(KC_7); register_code16(KC_7); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_7); register_code16(KC_7);
    }
}

void dance_13_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_7); break;
        case SINGLE_HOLD: unregister_code16(ALGR(US_5)); break;
        case DOUBLE_TAP: unregister_code16(KC_7); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_7); break;
    }
    dance_state[13].step = 0;
}
void on_dance_14(qk_tap_dance_state_t *state, void *user_data);
void dance_14_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_14_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_14(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_8);
        tap_code16(KC_8);
        tap_code16(KC_8);
    }
    if(state->count > 3) {
        tap_code16(KC_8);
    }
}

void dance_14_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_8); break;
        case SINGLE_HOLD: send_unicode_string("„"); break;
        case DOUBLE_TAP: register_code16(KC_8); register_code16(KC_8); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_8); register_code16(KC_8);
    }
}

void dance_14_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_8); break;
        case SINGLE_HOLD: unregister_code16(NE_LOW_QUOTE); break;
        case DOUBLE_TAP: unregister_code16(KC_8); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_8); break;
    }
    dance_state[14].step = 0;
}
void on_dance_15(qk_tap_dance_state_t *state, void *user_data);
void dance_15_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_15_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_15(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_9);
        tap_code16(KC_9);
        tap_code16(KC_9);
    }
    if(state->count > 3) {
        tap_code16(KC_9);
    }
}

void dance_15_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_9); break;
	case SINGLE_HOLD: send_unicode_string("“"); break;
        case DOUBLE_TAP: register_code16(KC_9); register_code16(KC_9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_9); register_code16(KC_9);
    }
}

void dance_15_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_9); break;
        case SINGLE_HOLD: unregister_code16(NE_DOUBLE_QUOTE); break;
        case DOUBLE_TAP: unregister_code16(KC_9); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_9); break;
    }
    dance_state[15].step = 0;
}
void on_dance_16(qk_tap_dance_state_t *state, void *user_data);
void dance_16_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_16_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_16(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_0);
        tap_code16(KC_0);
        tap_code16(KC_0);
    }
    if(state->count > 3) {
        tap_code16(KC_0);
    }
}

void dance_16_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(KC_0); break;
        case SINGLE_HOLD: send_unicode_string("”"); break;
        case DOUBLE_TAP: register_code16(KC_0); register_code16(KC_0); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_0); register_code16(KC_0);
    }
}

void dance_16_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(KC_0); break;
        case SINGLE_HOLD: unregister_code16(NE_RIGHT_DOUBLE_QUOTE); break;
        case DOUBLE_TAP: unregister_code16(KC_0); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_0); break;

    }
    dance_state[16].step = 0;
}
void on_dance_17(qk_tap_dance_state_t *state, void *user_data);
void dance_17_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_17_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_17(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_17_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: send_unicode_string("–"); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_17_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(NE_EN_DASH); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[17].step = 0;
}
void on_dance_18(qk_tap_dance_state_t *state, void *user_data);
void dance_18_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_18_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_18(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_18_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: send_unicode_string("•"); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_18_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(NE_BULLET); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[18].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
        [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
        [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
        [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
        [DANCE_17] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
        [DANCE_18] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset),
};
