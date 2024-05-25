/*----------------------------------------------------------------------------
| File:
|   applmain.c
|
| Project:
|   CCP driver example
|   CANape Calibration Tool
|
| Description:
|   Mini CCP application for C16x
|
|-----------------------------------------------------------------------------
| Copyright (c) 1998 by Vector Informatik GmbH.  All rights reserved.
 ----------------------------------------------------------------------------*/

#include <reg167.h>
#include "ccp.h"
#include "ecu.h"
#include "can.h"
#include "applmain.h"


//------------------------------------------------------------------------------
// Global

unsigned long gTimer;
unsigned long gCounter;

// Current Calibration page
CCP_BYTE ccpCalPage = 0; // Default ROM

/*----------------------------------------------------------------------------*/
/* Transmit the CCP message */
/* Id is CCP_DTO_ID, which is configured at compile time in CAN.C */

void ccpSend( CCP_BYTEPTR msg )
{
  CAN_vLoadData(9,msg);
  CAN_vTransmit(9);
}


/*----------------------------------------------------------------------------*/
/* Convert a memory address from CCP 8/32bit into a C pointer */

CCP_MTABYTEPTR ccpGetPointer( CCP_BYTE addr_ext, CCP_DWORD addr )
{
  if (ccpCalPage==1 && addr>=0x14000 && addr<0x18000) { /* CALRAM */
    return (CCP_MTABYTEPTR) ( addr + 0x30000UL );
  }

  return (CCP_MTABYTEPTR) addr;
}


/*----------------------------------------------------------------------------*/
// CCP Callbacks

void ccpUserBackground( void )
{
}

CCP_BYTE ccpDisableNormalOperation( CCP_MTABYTEPTR a, CCP_WORD s )
{
  return 1;
}


/*----------------------------------------------------------------------------*/
/* Calibration RAM/ROM Selection */


CCP_DWORD ccpGetCalPage( void )
{
  return (CCP_DWORD)ccpCalPage;
}

void ccpSetCalPage( CCP_DWORD a )
{
  ccpCalPage = (CCP_BYTE)a;

    if (ccpCalPage==1) { /* RAM */
      #pragma asm
        mov DPP1,#11h
      #pragma endasm
    } else {             /* ROM */
      #pragma asm
        mov DPP1,#05h
      #pragma endasm
    }

}

void ccpInitCalPage( void ) {

    #define CALROM_ADDR 0x14000
    #define CALRAM_ADDR 0x44000
    huge unsigned char *p1 = (huge unsigned char *)CALROM_ADDR;
    huge unsigned char *p2 = (huge unsigned char *)CALRAM_ADDR;
    unsigned int i;
    for (i=0;i<0x4000;i++) {
      *p2++ = *p1++;
    }
}


//------------------------------------------------------------------------------
// 10ms Timer Isr

void timer_function( void ) {

  // ms Timer
  gTimer += 10;

  // ECU Simulation
  ecuCyclic();

  // 10 ms
  // Data Acquisition on Channel 2
  ccpDaq(2);

}


//------------------------------------------------------------------------------
// Main Loop

void main_function ( void )
{

  // Initialize global variables
  gTimer = 0;
  gCounter = 0;

  // Initialize CAN driver
  CAN_vInit();

  // initialize Calibration RAM
  ccpInitCalPage();

  // Initialize the ECU sample
  ecuInit();

  // Initialize CCP driver
  ccpInit();

  // Mainloop
  for (;;) {

    gCounter++;

    // Check for incomming CCP receive message (CRO)
    if (CAN_bNewData(8)) {

      TCAN_Obj o;

      CAN_vGetMsgObj(8,&o);
      CAN_vReleaseObj(8);
      ccpCommand(&o.ubData[0]);
    }

    // Check for pending CCP transmit messages (DTO)
    if (CAN_bRequestMsgObj(9)) {
      ccpSendCallBack();
    }

    // Perform any CCP background processing
    ccpBackground();

  } // Mainloop
}



