--------------------------------------------------------------------------------

                 XCP 1.0 Sample Implementation and Documentation

                    Vector Informatik GmbH, Stuttgart

--------------------------------------------------------------------------------

                            Date:     01.09.2017
                            Version:  1.30.04

--------------------------------------------------------------------------------

Vector Informatik GmbH
Ingersheimer Strasse 24
D-70499 Stuttgart
TEL:   +49 711 80670 0
EMAIL: support@vector.com
WEB:   www.vector.com

--------------------------------------------------------------------------------


File XCP_Delivery.exe
---------------------


XCP Driver Sourcecode:
----------------------

XCP Basic Driver\
-----------------
XcpBasic.c          XCP 1.0 basic Driver ANSI-C Source (Free)
XcpBasic.h          XCP 1.0 basic Driver Include File (Free)

xcp_cfg.h           Include File for customizing XcpBasic.c
xcp_par.c           Include File for customizing XcpBasic.c
xcp_par.h           Include File for extern decl. xcp_par.c
xcp_def.h           Include File for customizing and check the XcpBasic.c configuration
_xcp_appl.c         Template for the XCP application callback functions.
                    This is just an example and may be modified.

--------------------------------------------------------------------------------
Documentation:
--------------------------------------------------------------------------------

DOC\XCP General Overview\
--------------------------
XCP Datasheet_EN.pdf

TechnicalReference_XCP_Protocol_Layer.pdf

How to integrate a automatic detection of map file names v1.0._EN.pdf
How to make a Seed & Key.DLL for XCP.pdf


!!!! Agreement on the Delivery of CANape Driver Generator and Library !!!!!
---------------------------------------------------------------------------

EULA\
------
eula-de.pdf
eula-en.pdf

DOC\Specification\Version 1.0\
-------------------------------
 XCP -Part 1- Overview -1.0.pdf
 XCP -Part 2- Protocol Layer Specification -1.0.pdf

 XCP -Part 3- Transport Layer Specification  XCP on Ethernet (TCP_IP and UDP_IP) -1.0.pdf
 XCP -Part 3- Transport Layer Specification  XCP on SxI -1.0.pdf
 XCP -Part 3- Transport Layer Specification  XCP on CAN -1.0.pdf

 XCP -Part 4- Interface Specification -1.0.pdf

 XCP -Part 5- Example Communication Sequences -1.0.pdf


DOC\Specification\Version 1.1\
-------------------------------
 XCP -Part 1- ASAM_XCP_Part1-Overview_V1-1-0.pdf
 XCP -Part 2- ASAM_XCP_Part2-Protocol-Layer-Specification_V1-1-0.pdf

 XCP -Part 3- ASAM_XCP_Part3-Transport-Layer-Specification_XCPonCAN_V1-1-0.pdf
 XCP -Part 3- ASAM_XCP_Part3-Transport-Layer-Specification_XCPonEthernet_TCP_IP.pdf
 XCP -Part 3- ASAM_XCP_Part3-Transport-Layer-Specification_XCPonFlexRay_V1-1-0.pdf
 XCP -Part 3- ASAM_XCP_Part3-Transport-Layer-Specification_XCPonSxI_V1-1-0.pdf
 XCP -Part 3- ASAM_XCP_Part3-Transport-Layer-Specification_XCPonUSB_V1-1-0.pdf

 XCP -Part 4- ASAM_XCP_Part4-Interface-Specification_V1-1-0.pdf

 XCP -Part 5- ASAM_XCP_Part5-Example-Communication-Sequences_V1-1-0.pdf



--------------------------------------------------------------------------------
 Samples:
--------------------------------------------------------------------------------

SAMPLES\CAN\CAN MPC55xx
------------------------
                         XCP on CAN sample implementation for a Power PC MPC55xx


SAMPLES\CAN\CAN Tricore
------------------------
                         XCP on CAN sample implementation for Tricore TC17x7


SAMPLES\RS232
------------------------
                        Simple Implementation on a Atmel ATMEGA 163 using a RS232 Interface


SAMPLES\SPI
------------------------
                         Simple  Implementation on a Atmel AT91 ARM7 using a SPI in DMA mode


SAMPLES\XCPSIM
------------------------
                         PC based implementation using Ethernet or CAN
