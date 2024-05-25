/*----------------------------------------------------------------------------
| File:
|   fake_os.c
|
| Project:
|   CCP driver example
|   CANape Calibration Tool
|
| Description:
|   CCP sample for C16x
|
|-----------------------------------------------------------------------------
| Copyright (c) 1998 by Vector Informatik GmbH.  All rights reserved.
 ----------------------------------------------------------------------------*/

#include <reg167.h>

#include "applmain.h"

/* interrupt-levels for C167 */
#define kDCan82527ILVL     5 /* may not collide with other interrupt-source */
#define kDCan82527GLVL_1   0
#define kDCan82527GLVL_2   1

/****************************************************************/
/*  Hardware Init */
/****************************************************************/

static void hardware_init ( void )
{
	#if 1 /* enable internal 82527, enable interrupts and define their priorities */
		XP0IC = (0x40 | (kDCan82527ILVL << 2) | kDCan82527GLVL_1);
	#endif

	#if 0	/* externer CAN !!! CAPCON12 = Vector at address 70H */
		EXICON = 0x200;
		CC12IC = (0x40 | (kDCan82527ILVL << 2) | kDCan82527GLVL_1);
	#endif

  /* Timer 4 als zykl Fkt im 1 ms Raster */
  IEN   = 0;
  T4CON = 0x86; /* -> T4UDE=0, T4UD=1, T4R=0, T4M=0, T4I=6 */
//  T4IC  = 0x31;
  T4IC  = 0x15; /* ILevel = 5; Grouplevel = 1 */
  T4    = 0x186; /* 390 timer ticks mit 25,6µs pro tick = timerinterrupt alle 10 ms */
  T4IE  = 1;
  T4R   = 1;
  IEN   = 1;


  /// ------------ Timer 3 Control Register ----------
  ///  timer 3 works in timer mode
  ///  prescaler factor is 32
  ///  up/down control bit is reset
  ///  external up/down control is disabled
  ///  alternate output (toggle T3OUT) function is disabled
  T3CON = 0x0002;  // 20Mhz / 0-8,1-16,2-32,3-64,...
  T3    = 0x0000;  // load timer 3 register
  T3R   = 1;       // set timer 3 run bit

}

/****************************************************************/
/*  Timerinterrupt 4 GPT 1 alle 10 ms                            */
/****************************************************************/
interrupt(0x24) using (own_rb) void Timer2Isr(void)
{

 T4IE = 0;
 T4R  = 0;
 T4IR = 0;
 T4   = 0x186; // 10ms (390)

 timer_function();

 T4R  = 1;
 T4IE = 1;
}

/****************************************************************/
/*  Main */
/****************************************************************/

void main ( void )
{
  hardware_init();
  main_function();
}
