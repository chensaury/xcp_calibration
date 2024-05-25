*******************************************************************************
*   XCP demo with RS232C Serial driver                                        *
*                                                                             *
*   Date               : 15.05.2018                                           *
*   Version            : 1.1.0                                                *
*   Micro Controller   : Atmel ATMEGA 163                                     *
*   Compiler           : ICCAVR                                               *
*   Description        : XCP basic driver demo                                *
*                                                                             *
*                                                                             *
*   Copyright (c) 2018 by Vector Informatik GmbH. All rights reserved.        *
*******************************************************************************


-------------------------------------------------------------------------------
GENERAL NOTES
-------------------------------------------------------------------------------
This program is a example implementation using the XCP driver from Vector via 
RS232C on the Atmel ATMEGA 163.


-------------------------------------------------------------------------------


-------------------------------------------------------------------------------
FOLDERS
-------------------------------------------------------------------------------
CANape          : CANape project with configuration examples
------------------------------------------------------------------------------




-------------------------------------------------------------------------------
Files
-------------------------------------------------------------------------------



XCP_IF 
-------------------------------------------------------------------------------
XCP_IF.C 
  This module provides the adaption to a particular platform
  It contains all platform specific functions

UARTINTR 
-------------------------------------------------------------------------------
UARTINTR.c     UART interrupt routines
UARTINTR.h

XCP basic Driver 
-------------------------------------------------------------------------------
XcpBasic.c          XCP 1.0.02 Driver ANSI-C Source
XcpBasic.h          XCP 1.0.02 Driver Include File
xcp_par.h           Include File for customizing XCPBasic.C
xcp_cfg.h           Include File for customizing XCPBasic.C
xcp_def.h           Include File for check some dependents from the config. files

Main module 
-------------------------------------------------------------------------------
TEST1.C     Main module
TEST1.H
-------------------------------------------------------------------------------

Project files for ICCAVR
-------------------------------------------------------------------------------
TEST1.prj    
TEST1.src
-------------------------------------------------------------------------------









