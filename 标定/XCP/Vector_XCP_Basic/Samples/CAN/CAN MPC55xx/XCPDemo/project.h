/*----------------------------------------------------------------------------
| File:
|   project.h  
|
| Project:
|   XCP on CAN Demo with CANape Calibration Tool
|
| Description:
|   Uses an iSystem or Freescale 5554 Eval Board 
|
 ----------------------------------------------------------------------------*/

#ifndef __PROJECT_H__
#define __PROJECT_H__


// Define the microcontroller here
// Don't forget to adjust the clock frequency in mpc5500_usrdef.inc (8MHz 5554, 40MHz 5567)
#define MPC5554
//#define MPC5567

// Define the evalboard type here
#define ISYSTEM_BOARD
//#define FREESCALE_BOARD

#define CPU_CLOCK 128 //Mhz
//#define CPU_CLOCK 120 //Mhz

//#define VX_NEXUS_DATATRACE
#define VX_NEXUS_SERIAL

//#define SINGLE_TASK



//-----------------------------------------------------------------------------
// General

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#ifdef MPC5554
  #include "mpc5554.h"       
#else
  #ifdef MPC5567
    #include "mpc5567.h"
  #else
    #error
  #endif
#endif

#include "ad.h"

typedef unsigned char  vuint8;
typedef signed char    vsint8;   
typedef unsigned short vuint16;
typedef signed short   vsint16;
typedef unsigned long  vuint32; 
typedef signed long    vsint32;


//-----------------------------------------------------------------------------
// Calibration Concept

// Enable AUTOSAR or INCIRCUIT calibration concept
#define CC_AUTOSAR // Enable AUTOSAR (pointer table in RAM) calibration concept in general (for VX or for XCP on CAN)
//#define CC_INCIRCUIT // Enable INCIRCUIT (pointer table in FLASH) calibration concept in general (for VX or for XCP on CAN)
#define CC_CALRAM_SIZE    512	// Define the size in Bytes of calibration RAM used for the calibration concept
#define CC_DOUBLE_POINTERED // Define when the calibration concept is double pointered to support calibration page switching

#define CC_PPC

// Declare all parameters
// Must be done before inculding cc_autosar.h and after defining the calibration concept !!!!
#define DECLARE_PARAMETERS
#include "cc_autosar_params.h"

// Declare the data structures needed for the AUTOSAR calibration concept
#if defined(CC_AUTOSAR) || defined(CC_INCIRCUIT)
  #include "cc_autosar.h"
#endif


//-----------------------------------------------------------------------------
// VX1000
#include "vx1000_mpc5xxx.h"


//-----------------------------------------------------------------------------
// XCP on CAN 

#define CAN_CYCLIC_TX_ID      0x100
#define CAN_XCP_TX_ID         0x200
#define CAN_XCP_RX_ID         0x201

#include "can.h"
#include "xcpbasic.h"


//-----------------------------------------------------------------------------

// Use the VX1000 clock also as a time base in main.c
#define SYSTEM_CLOCK() VX1000_CLOCK()
#define SYSTEM_CLOCK_TICKS_PER_US VX1000_CLOCK_TICKS_PER_US
#define SYSTEM_CLOCK_TICKS_PER_MS VX1000_CLOCK_TICKS_PER_MS
  

// External 
extern void XcpHandler( void );
extern void FatalError( void );

#endif

