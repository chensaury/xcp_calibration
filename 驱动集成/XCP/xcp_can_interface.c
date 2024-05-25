/*
 * xcp.can_interface.c
 *
 *  Created on: 31.12.2023
 *      Author: 
 */

/*******************************************************************************

  File Name   : ccp_can_interface.c
  Date        : 28.09.2001
  Version     : 1.0.1
  Description  : additional functions for CCP


*******************************************************************************/


// -----------------------------------------------------------------------------
// INCLUDE FILES
// -----------------------------------------------------------------------------
//#include "Cpu0_Main.h"
//#include "ccp.h"
#include "xcp_can_interface.h"   // additional functions for CCP usage

#include "OsCfg_Isr.h"
#include "CanIf_MsgHandler_Xcp.h"
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Empty Interrupt Service Routine
// -----------------------------------------------------------------------------
//@interrupt void irq_dummy(void) {       // dummy function,
//}                                       // interrupt vect.
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// SENDING an CRM-DTO when receiving an CRO
// -----------------------------------------------------------------------------
unsigned char ApplXcpSend(unsigned char len, CCP_BYTEPTR msg )
{
	
	CanMsgHandler_XcpTransmitCrm(msg,len);
  return 1;
}
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// CONVERT pointer
// -----------------------------------------------------------------------------
unsigned long* ccpGetPointer( unsigned char addr_ext, unsigned long addr )        
{
	/* avoid compiler warning due to unused parameters */
	addr_ext = addr_ext;

	return (unsigned long*) addr;
}
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// CALCULATE new measuerments
// -----------------------------------------------------------------------------
void ccpUserBackground( void )
{
}
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Define
// -----------------------------------------------------------------------------
//CCP_BYTE ccpDisableNormalOperation( unsigned char* a, CCP_WORD s ) 
//{
//	ApplXcpInterruptDisable();                  // disables all interrupts, e.g. TIMER_0
//  return 1;
//}
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Disable/Enable Interrupt Functions
// -----------------------------------------------------------------------------
CCP_BYTE disable_interrupt_count = 0;       // init counter

void ApplXcpInterruptDisable() {

	__disable();
  //_asm("SEI");                          // set I-Bit
  disable_interrupt_count++;            // incr. counter
}

void ApplXcpInterruptEnable() {

  if (--disable_interrupt_count==0) {   // if interrupts only one time disabled
    //_asm("CLI");                        // enable them
	  __enable ();
  }
}
// -----------------------------------------------------------------------------

