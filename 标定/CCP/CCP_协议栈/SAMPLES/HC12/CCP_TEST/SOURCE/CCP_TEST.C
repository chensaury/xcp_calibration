/*******************************************************************************

  File Name   : ccp_test.c
  Date        : 08.11.2001
  Version     : 3.4
  Desciption  : CAN driver for CCP without using interrupts
                - FLASH Memory;
                - Timer_0 implementation;

*******************************************************************************/


// -----------------------------------------------------------------------------
// INCLUDE FILES
// -----------------------------------------------------------------------------
#include <iod60.h>                      // standard HC12 io
#include "ccp_can_interface.h"          // additional functions for CCP usage
#include "timer.h"                      // Timer_0
#include "boot_can.h"                   // free CAN Driver
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// VARIABLES
// -----------------------------------------------------------------------------
unsigned int p_counter = 0;             // primitive counter
unsigned char receive_buffer[8];        // receive buffer
// -----------------------------------------------------------------------------




// -----------------------------------------------------------------------------
// MAIN program
// -----------------------------------------------------------------------------
void main(void) {

   DDRH=128;                                       // PORTH, Pin7 = Output
   DDRG=255;                                       // PORTG  = Output

   PORTH=128;                                      // LED off on demo board
   PORTG=255;                                      // all LEDs ON

   init_timer_0(10);                               // enable timer_0, 10ms

   ccpBootInit(CCP_CRO_ID, CCP_DTO_ID);            // set IDs

   ecuInit ();                                     // initialize triangle, etc
   ccpInit();                                      // ini CAN Driver

   while(1) {
     p_counter++;                                  // incr. counter
     ccpBackground();                              // calculate checksum

     if (ccpBootReceiveCro(receive_buffer)) {      // if new CRO message received,
       ccpCommand(receive_buffer);                 // call ccpCommand
       if (PORTH==0) PORTH=128; else PORTH=0;      // Toggle LED
     }

     CCP_DISABLE_INTERRUPT;                        // Disable all Interrupts to protect
                                                   // ccpSendCallBack function call

     if (ccpBootTransmitCrmPossible()) {           // if new Transmit possible
       ccpSendCallBack();                          // send SendCallBack - enables ECU to
                                                   // send new DTO's.
                                                   // ccpSendCallBack have to run through
                                                   // without being interrupted!
     }
     CCP_ENABLE_INTERRUPT;                         // Enable all Interrupts
   }
}
// -----------------------------------------------------------------------------
