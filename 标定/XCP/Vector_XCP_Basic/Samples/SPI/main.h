/*----------------------------------------------------------------------------
| File:
|   MAIN.H
|
| Project:
|   XCP on SPI Sample
|
 ----------------------------------------------------------------------------*/

#include <atmel91.h>

#ifndef uint8
#define uint8   unsigned char
#endif
#ifndef uint16
#define uint16  unsigned short
#endif
#ifndef uint32
#define uint32  unsigned long
#endif
#ifndef int8
#define int8    signed char
#endif
#ifndef int16
#define int16   signed short
#endif
#ifndef int32
#define int32   signed long
#endif

typedef enum { kFalse = 0, kTrue = 1 } Bool;

#define DUMMY_TIME_MS          20
#define TOGGLE_LED_TIME_MS    500
#define ECU_EVENT_TIME_MS       2

extern uint32 ulTimerCounter0;
