/*******************************************************************************

  File Name   : vectable.c
  Date	      : 09.07.2001
  Version     : 1.0
  Desciption  : vector table for CARD12.D60 Demo Board with TwinPEEK monitor
		vectors are remapped to 0x07A6

*******************************************************************************/



// -----------------------------------------------------------------------------
// DEFINITION
// -----------------------------------------------------------------------------

#include <stddef.h>

typedef struct
{
  char sprung;
  void (* const _vectab)();
}jmpTable;

#define vjmp  0x06
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// extern declared interrupt service routines and functions
// -----------------------------------------------------------------------------
extern void _stext(void);	// startup routine
extern void irq_dummy(void);	// empty function
extern void _timer_0(void);	// timer_0 interrupt service routine

jmpTable Table[] = {
  vjmp, irq_dummy,		// CGM LLH
  vjmp, irq_dummy,		// CAN transmit
  vjmp, irq_dummy,		// CAN receive
  vjmp, irq_dummy,		// CAN error
  vjmp, irq_dummy,		// reserved
  vjmp, irq_dummy,		//
  vjmp, irq_dummy,		//
  vjmp, irq_dummy,		// CAN wake-up
  vjmp, irq_dummy,		// ATD
  vjmp, irq_dummy,		// SCI 2
  vjmp, irq_dummy,		// SCI 1
  vjmp, irq_dummy,		// SPI
  vjmp, irq_dummy,		// Pulse acc input
  vjmp, irq_dummy,		// Pulse acc overf
  vjmp, irq_dummy,		// Timer overflow
  vjmp, irq_dummy,		// Timer channel 7
  vjmp, irq_dummy,		// Timer channel 6
  vjmp, irq_dummy,		// Timer channel 5
  vjmp, irq_dummy,		// Timer channel 4
  vjmp, irq_dummy,		// Timer channel 3
  vjmp, irq_dummy,		// Timer channel 2
  vjmp, irq_dummy,		// Timer channel 1
  vjmp,  _timer_0,		// Timer channel 0
  vjmp, irq_dummy,		// Real time
  vjmp, irq_dummy,		// IRQ
  vjmp, irq_dummy,		// XIRQ
  vjmp, irq_dummy,		// WI
  vjmp, irq_dummy,		// illegal
  vjmp, irq_dummy,		// cop fail
  vjmp, irq_dummy,		// clock fail
  //vjmp, _stext,		  // reset
};
// -----------------------------------------------------------------------------
