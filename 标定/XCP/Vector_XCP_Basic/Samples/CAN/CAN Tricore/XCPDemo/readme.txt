*******************************************************************************
*   XCP on CAN sample implementation for Tricore TC17x7                       *
*                                                                             *
*   Date               : 15.05.2018                                           *
*   Version            : 1.0.3                                                *
*   Micro Controller   : TC17x7                                               *
*   Compiler           : TASKING EDE 2.5                                      *
*                                                                             *
*   Copyright (c) 2018 by Vector Informatik GmbH. All rights reserved.        *
*******************************************************************************


-------------------------------------------------------------------------------
GENERAL NOTES
-------------------------------------------------------------------------------
This package is a fully functional ECU implementation
It includes the free XCP Basic driver from Vector
The example is kept as simple and straighforeward as possible, there is no 
operating system used. 
The framework and the CAN driver were created using Infineons Dave.

To switch the example code for different Tricore variants and evaluation boards,
the Dave project has to be changed accordingly. This typically affects the clock 
frequency setting and the IO ports used for CAN. All other target specific settings
are located in project.h.


The example implements 2 pseudo tasks with 10ms and 100ms cyclic rate. 
Task 10ms reads an analog/digital converter and
scales and filters the value. Task 100ms drives the evaluation boards LEDs with
a configurable pattern read from a calibration curve.


The example implements a XCP Slave with 500 Kbit/s, DTO-Id 0x200, CRO-Id 0x201
Supported XCP features are:
- Unrestricted access, no Seed&Key
- Checksum calculation type ADD_14, maximum block size 0xFFFF
- Dynamic DAQ lists, ECU timestamps supported, resolution 11,377us, error 0.002%
- DAQ Events: ADC_TASK 0 10ms, BACKGROUND_TASK 1 100ms
- Calibration page switching and initialization (SET/GET_CAL_PAGE,COPY_CAL_PAGE)
- Flash programming with a XCP Flash Bootloader


The example supports a tool transparent calibration concept with on demand 
mapping of FLASH to OVRAM using the Tricore OVR feature

Calibration FLASH area:     0xA0100000-0xA010FFFF
Calibration pages:          2 FLASH=0, RAM=1
Overlay RAM size:           8 KByte
Overlay RAM segment size:   512 Byte
Overlay RAM segment count:  16

Memory map:
FLASH
  0xA0000000 - 0xA00FFFFF Code and Constant Data
  0xA0100000 - 0xA01FFFFF Calibration Data
RAM
  0xD0000000 - 0xD000FFFF Measurement Data
OVRAM
  0xAFE8000  - 0xAFE81FFF Overlay RAM



-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
FOLDERS
-------------------------------------------------------------------------------
CANape                 CANape 8.0 project with configuration examples
CANape90               CANape 9.0 project with configuration examples


-------------------------------------------------------------------------------
FILES
-------------------------------------------------------------------------------

Application
  project.h            Target specific settings
  demo.c, demo.h	   Demo application, mainloop
  xcp_if.c             XCP on CAN transport layer interface and callbacks
  xcp_cc_tc_ovram.c	   XCP on CAN calibration concept and overlay ram handler

DAVE generated files:
  ADC0.C, ADC0.H	   Analog/digital converter
  CAN.C, CAN.H		   CAN driver						    
  MAIN.C, MAIN.H	   Main file

XCP Driver:
  xcp_cfg.h            Include File for customizing the XCP driver
  xcp_def.h            XCP Driver Include File
  XCPBasic.H           XCP Driver Include File
  XCPBasic.C           XCP Driver ANSI-C Source
