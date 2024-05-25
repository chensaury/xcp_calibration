*******************************************************************************
*   CCP_TEST - CCP integration with free CAN driver                           *
*                                                                             *
*   Date               : 20.09.2001                                           *
*   Version            : 3.3.3                                                *
*   Micro Controller   : Motorola HC12 D60                                    *
*   Compiler           : COSMIC                                               *
*   Description        : ECU simulation with integrated CCP driver            *
*                        supports:                                            *
*                         Flash Kernel Download                               *
*                         Checksum Calculation                                *
*                                                                             *
*   Copyright (c) 2001 by Vector Informatik GmbH. All rights reserved.        *
*******************************************************************************


-------------------------------------------------------------------------------
GENERAL NOTES
-------------------------------------------------------------------------------
This package is a full running ECU simulation, including a free CAN and
CCP driver from VECTOR.

To make this demonstration functional it is necessary to change the paths of
your COSMIC compiler in the following files:

     - compile.bat
     - ccp_test.lkf  (link file, adapt vector start address etc...)


The application is optimized for "CARD12.D60" evaluation boards and runs
at address $1000. The application has to be started manually with a terminal
program, like OCConsole.exe

When you use another evaluation board you have to change the following files:

     - vectable.c    (remapped vector table from ROM into RAM by internal
                      monitor program TwinPEEK, CARD12.D60)

     - ccp_test.lkf  (link file, adapt vector start address etc...)


Note: The "CARD12.D60" evaluation board can be obtained by
      www.elektronikladen.de/en_card12.html
-------------------------------------------------------------------------------



-------------------------------------------------------------------------------
ECU simulation
-------------------------------------------------------------------------------
ECU.C contains a simulation of an electronic controller unit and per-
forms some calculations. The internal TIMER_0 is used to call ccpDaq() every
10ms (can be initialized) by a interrupt service routine (TIMER.C).

Because the internal monitor "TwinPEEK" needs some RAM to remap the vector
table, the ecu.c file size is minimized with '#if !defined (COSMIC_HC12_TwinPEEK)'
lines.
It might be happen, that CANape displays an error like:

  "Baseaddress calram not found. Could not update! Delete?"

Press "No all" to save the data base of the examples. When you use another
evaluation board, you can delete "-dCOSMIC_HC12_TwinPEEK" in the batch file to
use the complete ecu.c file.
-------------------------------------------------------------------------------



-------------------------------------------------------------------------------
FOLDERS
-------------------------------------------------------------------------------
CANape          : CANape project with configuration examples
Errors          : error folder used by COSMIC compiler
Hex             : compiled Motorola-S file
Include         : all include files
Linker          : generated map file
Object          : object folder used by COSMIC compiler
Source          : all source codes
Tool            : OCConsole - terminal program
-------------------------------------------------------------------------------



-------------------------------------------------------------------------------
Download Motorola-S file into D60 / CARD12.D60 evaluation board
-------------------------------------------------------------------------------
To download the compiled and generated ccp_test.hex file in to your HC12 eval.
board you have to use the monitor program OCConsole, which is found in the
folder "Tool".

- connect your CARD12.D60 board with COM1
- start OCConsole.exe
- ensure your options are correctly set:
  COM1
  baud rate: 19200
  parity: no (keine)
  data bits: 8
  stop bits: 1
- ensure your Card12.D60 is ready by pressing the red reset button on the board
  if so, the internal TwinPEEK monitor is answering
- then press X to delete your flash rom, press Y
- now enter L, "Loading...." appears
- now click on the "Transfer..." button, select the ccp_demo.hex file
- press "Senden"
- while loading up the hex file, asterisks appears along the lines
- when finished, type G 1000   (the main program starts at adress $1000)
- press ENTER
-------------------------------------------------------------------------------

