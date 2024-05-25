--------------------------------------------------------------------------------

                    CCP 2.1 Sample for C167

                    Vector Informatik GmbH, Stuttgart

--------------------------------------------------------------------------------

Files:
------

MAKEFILE
MAKECONF       Makefiles for tasking compiler

B.BAT          Build all

CCP.C          CCP 2.1 Driver ANSI-C Source
CCP.H          CCP 2.1 Driver Include File

CCPPAR.H       Include File for customizing CCP.C

CAN.H          Simple polling (not interrupt driven) CAN driver
CAN.C

APPLMAIN.C     Main module
APPLMAIN.H

FAKE_OS.C      Controller initialization
CSTARTXF.ASM

ECU.C          ECU simulation
ECU.H          Provides some measurement and calibration values for CANape demonstration

CANape.INI     CANape setup file
CCPtest.DB     CANape database
CCPtest.A2L    CANape database A2L Format
CCPtest.HEX    Executable
CCPtest.ABS    Linker MAP in IEEE format
CCPtest?.CNA   Some CANape example configurations


