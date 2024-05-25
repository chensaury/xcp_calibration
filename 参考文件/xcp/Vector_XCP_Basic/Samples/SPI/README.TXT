*******************************************************************************
*   XCP on SPI                                                                *
*                                                                             *
*   Date               : 15.05.2018                                           *
*   Version            : 1.1                                                  *
*   Micro Controller   : Atmel AT91 (ARM7)                                    *
*   Compiler           : Green Hills                                          *
*   Description        : Simple XCP on SPI driver example                     *
*   Features           :                                                      *
*                        Seed&Key                                             *
*                        Checksum Calculation                                 *
*                        Dummy Event Generation                               *
*                        Multi event timestamped DAQ                          *
*                                                                             *
*                                                                             *
*   Copyright (c) 2018 by Vector Informatik GmbH. All rights reserved.        *
*******************************************************************************

-------------------------------------------------------------------------------
Files:


XCP Basic Driver 
-------------------------------------------------------------------------------
XCPBasic.c          XCP Basic Driver Source
XCPBasic.h          XCP Basic Driver Include
xcp_par.h           Include File for customizing XCPBasic.C
xcp_cfg.h           Include File for customizing XCPBasic.C
xcp_def.h           Include File for check some dependents from the config. files


SPI Driver 
-------------------------------------------------------------------------------
SPI.c               SPI driver and the callbacks for xcpBasic.c
SPI.h


Main Module 
-------------------------------------------------------------------------------
MAIN.C              Main module
MAIN.H


CANape project files
-------------------------------------------------------------------------------
CANape.INI          CANape project file
XCP.A2L             CANape database in A2L Format
*.CNA               CANape example configurations
gen.map             Linker MAP File in Greenhills ASCII Format
