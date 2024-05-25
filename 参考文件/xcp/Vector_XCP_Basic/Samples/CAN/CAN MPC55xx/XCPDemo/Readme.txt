*******************************************************************************
*   XCP on CAN sample implementation for Motorola MPC55xx                     *
*                                                                             *
*   Date               : 15.05.2018                                           *
*   Version            : 2.0.0                                                *
*   Micro Controller   : MPC55xx                                              *
*   Compiler           : GNU (iSystem WINIdea)                                *
*                                                                             *
*   Copyright (c) 2018 by Vector Informatik GmbH. All rights reserved.        *
*******************************************************************************



-------------------------------------------------------------------------------
GENERAL NOTES
-------------------------------------------------------------------------------

This package is a fully functional ECU implementation for XCP on CAN.
It also shows how to integrate the VX1000 code library and XCP on CAN to
use the same memory resources.

It includes the free XCP Basic Driver from Vector

The example is kept as simple and straighforeward as possible, there is no 
operating system used.


The example implements pseudo tasks with 100us, 2ms, 100ms and 500ms cyclic rate. 
Task 100us reads an analog/digital converter, Task 2ms scales the value. 
Task 100ms flashes the LEDs according to a pattern in led_pattern.
There are some demo measurements and calibration parameters related to this.
The code in main.c should be quite self explaining.


There is a XCP on CAN Slave with 1000 Kbit/s, DTO-Id 0x200, CRO-Id 0x201
Supported XCP features:
- Unrestricted access, no Seed&Key
- Checksum calculation type ADD_14, maximum block size 0xFFFF
- Dynamic DAQ lists, ECU timestamps supported, resolution 11,377us, error 0.002%
- DAQ Events: As decribed above, number 0-3
- Calibration page switching and initialization (SET/GET_CAL_PAGE,COPY_CAL_PAGE)


The example demonstrates 3 different calibration concepts:
 1.
Parameters in Flash.
Can be modified in the Intel-HEX and are modified using Flash programming

2.
Parameters in Flash mapped to Ram with AUTOSAR calibration concept
Supports calibration page switching with seperate ECU/XCP access control


3.
Parameters in RAM initialized from Flash during startup

See the descriptions in main.c for details



-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
FOLDERS
-------------------------------------------------------------------------------
CANape10               CANape 10.0 sample project


-------------------------------------------------------------------------------
FILES
-------------------------------------------------------------------------------

Application
  main.c, main.h, project.h   Demo application, mainloop
  xcp_if.c                    XCP on CAN transport layer interface and callbacks
  cc_autosar.c
  cc_autosar.h
  cc_autosar_param.h          Defines and declares all parameters for the pointer based calibration concept


XCP Driver:
  xcp_cfg.h                   Include File for customizing the XCP driver
  XCPBasic.C                  XCP Driver ANSI-C Source
  xcp_par.c                   XCP Driver ANSI-C Source
  XCPBasic.H                  XCP Driver Include File
  xcp_par.h                   XCP Driver Include File
  xcp_def.h                   XCP Driver Include File

