--------------------------------------------------------------------------------

                 CCP 2.1 Sample Implementation and Documentation

                    Vector Informatik GmbH, Stuttgart

--------------------------------------------------------------------------------

                            Date:     16.10.2003
                            Version:  1.42

--------------------------------------------------------------------------------

Vector Informatik GmbH
Ingersheimer Strasse 24
D-70499 Stuttgart
TEL:   +49 711 80670 350
EMAIL: rainer.zaiser@vector-informatik.de
WEB:   www.vector-informatik.de

--------------------------------------------------------------------------------

File CCP.ZIP:
-------------


CCP Driver Sourcecode:
----------------------

CCP.C         CCP 2.1 Driver ANSI-C Source

CCP.H         CCP 2.1 Driver Include File

CCPPAR.H      Include File for customizing CCP.C



Documentation:
--------------

DOC\

 CCP21.PDF      ASAM CCP 2.1 Specification (Acrobat Reader)

 CCP.DOC        Reference Documentation for the CCP Driver CCP.C (MS Word)

 CCPINTRO.PDF   Small Introduction to CCP (Acrobat Reader)




Platform dependend code examples:
----------------------------------

CANDRV\

 CAN_CCP.C    Platform specific code examples
              Interface to FLASH and EEPROM programming
              Interface to Vector embedded CAN Drivers



Infineon C16x Sample:
---------------------

  See README.TXT in the C16x directory



Motorola HC12 Sample:
---------------------

  See README.TXT in the HC12 directory
  See CCP_TEST.PDF in the HC12 directory




PC Application:
----------------

The file PCAPP.ZIP contains some PC tools and source code.


CCPSIM\

 CCPSIM.EXE    Win95/32 Application emulating a ECU with CCP
 CANAPE.INI    Setup for CANape with CCPSIM
 *.CNA         Sample Configurations for CANape
 CCPSIM.A2L    ASAP2 database for CCPSIM
 CCP.AML       ASAP2 AML for CCP
 CCPSIM.MAP    Borland-Map for CCPSIM
 CCPSIM.DB     CANape database for CCPSIM
 CCPSIM\SOURCE Source for CCPSIM


CCPLOG\

 CCPLOG.EXE    Win95/32 Application logging CCP commands on screen
 CCPLOG\SOURCE Source for CCPLOG





To run the sample programs CCPSIM or CCPLOG on Windows95 you will
need a Vector CANcardX, CAN-AC2/PCI or CANpari with the appropriate drivers.

The CANape demonstration version (>=2.0) may be run together with CCPSIM
without hardware using the virtual CAN channel feature of the Vector Application
CAN drivers.

Ask for the latest CANape demo or visit our web site on www.vector-informatik.de

Please contact us for samples with flash programming for Siemens C167, Motorola HC12 and
Hitachi SH7055. 

--------------------------------------------------------------------------------

Notes:
------

- More information on ASAM/ASAP activities and documentation
  are available on the internet at www.asam.de

- The ANSI C CCP driver sourcecode has been used on different platforms:

    Borland C++
    Microsoft Visual C++ 
    Tasking C16x
    Keil C16x
    Cosmic HC12
    Hiware HC08
    Hitachi Hew

  We try to keep the code as portable as possible.
  Please give us a note, if you run into a problem on another platform.

- There is a workaround in function ccpWriteMta due to a code optimizer bug
  in COSMICs HC12 compiler.

- The driver is restricted to a unique number of ODTs in all DAQ Lists.

- The driver does not return the current MTA in the responce to a DNLOAD
  command.

--------------------------------------------------------------------------------

Flash Programming:
------------------

The CCP standard provides support for Flash Programming by the commands
CCP_PROGRAM, CCP_PROGRAM6 and CLEAR_MEMORY. This assumes that the complete
Flash Programming functionality is integrated into the ECUs CCP driver.

An alternative approach is downloading the Flash Programming function into
the ECUs memory only when they are needed. The Vector CCP sample CCP driver
and CANape provide this as an additional option to the standard CCP method.

To enable this option in the ECU CCP driver

#define CCP_BOOTLOADER_DOWNLOAD
#undef CCP_PROGRAM

has to be added to CCPPAR.H

There will be two new, non standard CCP commands:

  CCP_PROGRAM_PREPARE

    BYTE 0x1E
    BYTE ctr
    WORD size

  This command anounces the beginning of the code download. MTA[0] contains
  the memory address to where the download will be done. size is the number
  of bytes which will be downloaded.
  The ECU has to make sure that the given memory range is free and the donload
  does not interfere with the ECUs normal operation.
  The sample CCP driver will call a function named

     ccpDisableNormalOperation( addr, size )

  when this command is received.


  CCP_PROGRAM_START
    BYTE 0x1F
    BYTE ctr
    WORD reserved
    WORD croId
    WORD dtoId

  This commands starts the downloaded routine at memory location MTA[0].
  croId and dtoId are the CAN identifiers to be used from now on.


Both new commands are protected by the seed and key CAL resource.
After executing the CCP_PROGRAM_START command, only the CCP commands
CCP_SET_MTA,CCP_PROGRAM, CCP_PROGRAM6 and CLEAR_MEMORY may be supported.

CCP_PROGRAM(size=0) should perform a software reset. CANape will then
automatically reconnect to the ECU.

CANape defines a file format containing Flash Programing routines. The extension
is .FKL. The file may be specified in CANape's driver setup dialog for CCP or in
CANape.INI:

FLASH_KERNEL_FILE_NAME=c16x.fkl


The FKL file look like this:


[FLASH_KERNEL_CONFIG]

FLASH_KERNEL_NAME="C16x"
FLASH_KERNEL_COMMENT="Flash Kernel, C167, AMD 27064 FLASH, XRAM"
FLASH_KERNEL_FILE_ADDR=0xe000
FLASH_KERNEL_SIZE=0x07ff
FLASH_KERNEL_RAM_ADDR=0xe000
FLASH_KERNEL_RAM_START=0xe00e

[FLASH_KERNEL_DATA]

:20E00E0088D088C008D4A8CDD4D0020008D6A8DDDA0018E498C098D088C0F0DD0802DA0069
:04E02E00EEE3DB0042
:20E03200F0DDF0CCDA001CE6DB0088808860F08DF4C004003D23F06CDA0018E5E15C29C1AF
:20E05200E6FC60EA28C1088148C03DFC49C03DF7DA00BEE40D1588F088E0D4D00200A8C006
...


The FKL files have to be located in the CANape \EXEC directory. CANape will
then automatically find them and provide a selection in the CCP driver setup
dialog. If "Direct" is selected, CANape will use the standard CCP approach.



--------------------------------------------------------------------------------

Integration with Vector embedded CANdrivers:
--------------------------------------------


1. File

   Please link the following files to your application

      *  ccp.c       -  CCP driver
      *  ccp.h       -  Header
      *  can_ccp.c   -  Interface between  CCP und Vector-CAN-Driver


2. Messages

   Your CANdb must contain the CCP messages, a transmit message and a receive message.
   For example:

   TX:   CCP_DTO  8 bytes
   RX:   CCP_CRO  8 bytes

   Note that both messages have a length of 8 bytes.

   Please define a dummy data byte at byte position 7 to avoid optimization in older
   generation tool version (bug).


3. Generationtool settings

   *  In "Node Options" activate 'use CCP'.

   *  In "CCP settings" enter:

      -  Stationaddress.

      -  Select the names CCP messages.

      -  Select 'Synchronous data acquisition" if required.
         Set MAX_DAQ to the number of event channels.
         Set MAX_ODT to the number of messages per channel.
         Activate the TX-Queue, minumum size is MAX_DAQ*MAX_ODT.

      -  Activate "Checksum Calculation" if Offline Calibration is required.

      -  Activate Flash Programmierung if required.

      -  Activate Flash Seed&Key if required.


4. Application

   *  #include "ccp.h" if you need to call CCP driver functions.

   *  Call ccpInit() on Power On Initialisation.

   *  Call ccpBackgound() in your idle loop if checksum calculation is required.
      Each call to ccpBackground() will calculate a chunk 255 checksum bytes.

   *  If "Synchronous data acquisition" is activated, insert calls to ccpDaq(x) in
      the appropriate locations. <x> is the number of the CCP event channel. The
      used event channels have to be specified in CANape Options/Driver/Events.


--------------------------------------------------------------------------------

Summary of changes from V2.0 to V2.1:
-------------------------------------

Changed Commands:

   CONNECT          ECU address always Intel..
   DISCONNECT
   TEST
                    Not compatible to 2.0 if ECU was Motorola !

   EXCHANGE_ID      Additional Resource Availability Mask, Resource Protection Mask.

   GET_SEED         Limited to one resource in one call,
   UNLOCK           Error message if mutliple resources.

   START_STOP       New Prepare mode and Prescaler
                    Event Channel instead of Transmission Interval
                    In V2.0 
                      Event Channel = 1-254: Time sync 0-FE ms
                      Event Channel = 0    : As fast as possible
                      Event Channel = 255  : Event synch
                    Not compatible to 2.0

   BUILD_CHKSUM     Bytecount up to 4 byte.
                    Not compatible to 2.0


   SET_SESSION_STATUS
   GET_SESSION_STATUS
                    New Resume Bit.


New Commands:

   TEST             Check for the presence of a ECU.
                    Same as CONNECT, but no effect.

   GET_CCP_VERSION  Version control.

   GET_ACT_CAL_PAGE Query active page.
                    Oposite of SET_ACT_CAL_PAGE.

   START_STOP_ALL   Synchronized start of multiple DAQ lists


Removed Commands:

   WCO


Other:

   Version control.
   ASAP AML definition.
   Errormatrix.
   Improved documentation.
   New error code for DAQ overload.
   A ODT may be restricted to byte objects and single address extensions.
   DLC may be < 8.
   New errorcodess 0x01, 0x12, 0x36.
   GET_SEED, UNLOCK, DNLOAD6, SHORT_UP, SELECT_CAL_PAGE optional.
   All DAQ commands optional.



