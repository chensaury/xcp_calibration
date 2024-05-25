
/*****************************************************************************
| Project Name:   XCP on CAN demo for Infineon Tricore TC17x7, TC1387, TC1782
|    File Name:   
|
|  Description:  Project main include file
|
|-----------------------------------------------------------------------------
|               D E M O
|-----------------------------------------------------------------------------
|
|       Please note, that the demo and example programs 
|       only show special aspects of the software. 
|       With regard to the fact that these programs are meant 
|       for demonstration purposes only,
|       Vector Informatik's liability shall be expressly excluded in cases 
|       of ordinary negligence, to the extent admissible by law or statute.
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2010 by Vector Informatik GmbH.           All rights reserved.
|
|       This software is copyright protected and 
|       proporietary to Vector Informatik GmbH.
|       Vector Informatik GmbH grants to you only
|       those rights as set out in the license conditions.
|       All other rights remain with Vector Informatik GmbH.
| 
|       Diese Software ist urheberrechtlich geschuetzt. 
|       Vector Informatik GmbH raeumt Ihnen an dieser Software nur 
|       die in den Lizenzbedingungen ausdruecklich genannten Rechte ein.
|       Alle anderen Rechte verbleiben bei Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Ds           Sven Deckardt             Vector Informatik GmbH
| Za           Rainer Zaiser             Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
|  Date       Version  Author  Description
| ----------  -------  ------  -----------------------------------------------
| 2010-03-26  1.0      Za      New
| 2010-12-16  1.1      Za      Bypass example added
| 2010-12-16  1.2      Za      TC1387 support added
| 2011-01-11  1.3      Za      TC1782 support added
|***************************************************************************/

#define VERSION 0x10

// Set the target type
// Please generate code for the associated .DAV file first (use TC1767.DAV for TC1387,TC1782)
// Set compiler project options to the correct microcontroller

// #define EASYKIT_TC1767 or TRIBOARD_TC1797 or TRIBOARD_TC1387	or TRIBOARD_TC1782
#define TRIBOARD_TC1797

// Only the TRIBOARD_TC1797 has external RAM
// Enable the external RAM on the TRIBOARD_TC1797 evaluation board at 0xD8000000
#ifdef TRIBOARD_TC1797
  #define EXTERNAL_RAM
#endif

// General
#include <string.h>

// Dave
// #include "main.h"  modefy by walter


//-------------------------------------------------------------------------------------
// XCP on CAN

// XCP on CAN support is always enabled
// XCP on CAN specific setting are in xcp_cfg.h

// Calibration concept
#define XCP_CC_TC_OVRAM // Enable Tricore OVRAM calibration concept for XCP on CAN

#include "xcpBasic.h"

extern void XcpHandler( void );



//-------------------------------------------------------------------------------------
// VX1000

// VX1000 support is integrated into the XCP on CAN driver
// Just enable it here
// VX1000 specific setting are in vx1000_tricore.cfg.h

// #define VX1000_ENABLED

#ifdef VX1000_ENABLED

  #include "VX1000_TRICORE.h"

#endif
 
