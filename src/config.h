/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 210



#define USB_SUSPEND_WAKEUP_DELAY 0

#define AUTO_SHIFT_TIMEOUT 175
//#define NO_AUTO_SHIFT_TAB
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC
#define FIRMWARE_VERSION u8"pbrEb/MBzY4"
#define RGB_MATRIX_STARTUP_SPD 60
#define UNICODE_SELECTED_MODES UC_MAC, UC_LNX, UC_WINC
