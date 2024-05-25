/*******************************************************************************

  File Name     : timer.c
  Date          : 12.07.2001
  Version       : 1.2
  Description   : modul using timer_0 interrupt,
                  timer_0 triggers an interrupt (_timer_0) when time is up,
                  then new values are calculatet in the ecuCyclic function
                  and transmittet by a ccpDaq(1) call.

*******************************************************************************/


// -----------------------------------------------------------------------------
// INCLUDE FILES
// -----------------------------------------------------------------------------
#include <iod60.h>                            // standard register of HC12
#include <math.h>                             // math library
#include "timer.h"                            // timer_0 routine
// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// VARIABLES
// -----------------------------------------------------------------------------
unsigned long counter=0;                        // counter for timer_0
unsigned char prescale_int=0;                   // prescaler (dez number)
unsigned char prescale_bin=0;                   // prescaler (bin number)
// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// Interrupt Service Routine for Timer_0 //
// -----------------------------------------------------------------------------
@interrupt void _timer_0(void) {

 TC0 = TC0 + counter;                         // incr. TimerCounter
 TFLG1=1;                                     // clear interrupt flag

                            /*
                               the TFLG1 flag must be cleared before ccpDaq() is
                               called, because  this sub routine enables all
                               interrupts at the end, at this time the TFLG1 flag
                               is still 1, so the interrupt by the timer occurs
                               another time.

                               normally the interrupts are enabled at the end of
                               the interrupt service routine of timer_0.
                            */

 ecuCyclic();                                 // calculate new values
 ccpDaq(1);                                   // transmit new values
};
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// initialize timer_0, calculate value of timer counter //
// -----------------------------------------------------------------------------

void init_timer_0 (unsigned long millisec) {

 if (millisec>1000) millisec = 1000;          // max millisec value = 1000 ms
 if (millisec<1) millisec = 1;                // min millisec value =    1 ms

 prescale_int=128;                            // set prescaler (dez)
 prescale_bin=7;                              // set prescaler (bin)
// -----------------------------------------------------------------------------


// ************************************
   counter=millisec*8000/prescale_int;        // calculate value of timer
// ************************************

 TIOS=1;                                      // set timer_0 to Output Compare
 TMSK1=1;                                     // set timer_0 interrupt enable flag
 TMSK2=prescale_bin;                          // set prescale (bin)
 TC0=counter;                                 // set value of timer counter
 cli();                                       // authorize interrupts
 TSCR=128;                                    // start main timer
}
// -----------------------------------------------------------------------------
