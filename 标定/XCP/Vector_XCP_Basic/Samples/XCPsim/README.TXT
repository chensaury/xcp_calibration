*******************************************************************************
*   XCPSIM                                                                    *
*   XCP on Ethernet or CAN example for PC                                     *
*                                                                             *
*   Date               : 15.05.2018                                           *
*   Version            : 1.0                                                  *
*   Micro Controller   : Intel Pentium                                        *
*   Compiler           : Visual C++                                           *
*   Description        : ECU simulation with integrated XCP basic driver      *
*                        Supports:                                            *
*                         Checksum Calculation                                *
*                         DAQ                                                 *
*                         Event                                               *
*                         Seed&Key                                            *
*                                                                             *
*   Copyright (c) 2018 by Vector Informatik GmbH. All rights reserved.        *
*******************************************************************************

-------------------------------------------------------------------------------
GENERAL NOTES
-------------------------------------------------------------------------------
This program is an example implementation using the Vector XCP Basic Driver via 
Ethernet or CAN on a PC.

To make this demonstration functional, it is necessary to change the paths of
your VC++ compiler projeckt XCPSIM.DSP settings.

Limitations of the Basic Driver are discribed in the header of XcpBasic.c
-------------------------------------------------------------------------------




Files:
------


XCP Basic Driver
-------------------------------------------------------------------------------
XcpBasic.c          XCP Driver ANSI-C Source
XcpBasic.h          XCP Driver Include File

xcp_cfg.h           Include File for customizing XcpBasic.c
xcp_par.c           Include File for customizing XcpBasic.c
xcp_par.h           Include File for extern decl. xcp_par.c
xcp_def.h           Include File for customizing and check the XcpBasic.c configuration

-------------------------------------------------------------------------------


ECU simulation
-------------------------------------------------------------------------------
ecu.c               Simulation of an ECU which supplies some test signals and parameters
ecu.h
-------------------------------------------------------------------------------


TCP 
-------------------------------------------------------------------------------
tcp.c     TCP routines

-------------------------------------------------------------------------------


CAN 
-------------------------------------------------------------------------------
can.c     CAN routines


CAN driver library for Vector CAN Hardware
-------------------------------------------------------------------------------
vcanD.h         Prototype functions and structures for the lib
vcndrvms.lib
-------------------------------------------------------------------------------


Main module 
-------------------------------------------------------------------------------
XCPsim.C     Main module
XCPsim.H
-------------------------------------------------------------------------------


CANape example project
-------------------------------------------------------------------------------
CANape.INI     CANape setup file
XCPsim.a2l     CANape database A2L Format
XCPsim.exe     Executable
XCPsim.pdb     Linker MAP File (PDB format)
XCPsim?.cna    Some CANape example configurations
XCPsim1.cnp    CANape Panel Sample
Demo.scr       CANape Scripting Sample
-------------------------------------------------------------------------------
