#include "device_info.h"


// version code, 1byte, max = 0 -> 255
#define APP_FW_VER_MAJOR   42
#define APP_FW_VER_MINOR   42
#if !(defined APP_FW_VER_MAJOR && defined APP_FW_VER_MINOR)
#error You need to define APP_FW_VER_MAJOR and APP_FW_VER_MINOR
#endif

// Merge major and minor version code to U16 value.
#define FW_VER_NUM VER_CODE_TO_NUM(APP_FW_VER_MAJOR, APP_FW_VER_MINOR)

// #define PROJECT_CHAMELEON_ULTRA
#define NO_SLEEP_TILL_CHAMELEON
