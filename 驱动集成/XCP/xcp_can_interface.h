/*
 * xcp_can_interface.h
 *
 *  Created on: Created on: 31.12.2023
 *      Author: tanwenyang
 */

#ifndef APPSW_TRICORE_XCP_XCP_CAN_INTERFACE_H_
#define APPSW_TRICORE_XCP_XCP_CAN_INTERFACE_H_
/*******************************************************************************

  File Name   : ccp_can_interface.h
  Date        : 27.07.2001
  Version     : 1.0
  Description  : additional functions for CCP


*******************************************************************************/

// -----------------------------------------------------------------------------
// PROTOTYPES

#define CCP_BYTE    unsigned char
#define CCP_WORD    unsigned short
#define CCP_DWORD   unsigned long
#define CCP_BYTEPTR unsigned char*
// -----------------------------------------------------------------------------
void irq_dummy(void);                                    // empty ISR
unsigned char  ApplXcpSend( unsigned char len,CCP_BYTEPTR msg );
//CCP_BYTE ccpSend( CCP_BYTEPTR pointdata );
unsigned long* ccpGetPointer( CCP_BYTE addr_ext, CCP_DWORD addr );

void ccpUserBackground( void );

void ApplXcpInterruptDisable();                                // I-bit SET
void ApplXcpInterruptEnable();                                 // I-bit CLEAR
// -----------------------------------------------------------------------------



#endif /* 0_APPSW_TRICORE_XCP_XCP_CAN_INTERFACE_H_ */
