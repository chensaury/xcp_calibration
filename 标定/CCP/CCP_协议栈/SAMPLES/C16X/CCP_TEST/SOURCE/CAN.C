/*----------------------------------------------------------------------------
| File:
|   can.c
|
| Project:
|
| Description:
|   Mini CAN driver for C16x
|
|-----------------------------------------------------------------------------
| Copyright (c) 1998 by Vector Informatik GmbH.  All rights reserved.
 ----------------------------------------------------------------------------*/

#include "CAN.H"
#include "CAN_ID.H"


//****************************************************************************
// Function      void CAN_vInit(void)
//
//----------------------------------------------------------------------------
// Description   This function initializes the CAN.
//
//----------------------------------------------------------------------------
// Returnvalue   none
//
//----------------------------------------------------------------------------
// Parameters    none
//
//****************************************************************************

#define ID_TO_UAR(id) (((id&0x0007)<<13) | ((id>>3)&0x00FF))

#define CAN_MODE_INVALID  0
#define CAN_MODE_TRANSMIT 1
#define CAN_MODE_RECEIVE  2

static void CAN_InitObject( ubyte ObjNr, uword id, ubyte mode, ubyte dlc ) {

  CAN_OBJ[ObjNr].Data[0] = 0x00;   // set data byte 0
  CAN_OBJ[ObjNr].Data[1] = 0x00;   // set data byte 1
  CAN_OBJ[ObjNr].Data[2] = 0x00;   // set data byte 2
  CAN_OBJ[ObjNr].Data[3] = 0x00;   // set data byte 3
  CAN_OBJ[ObjNr].Data[4] = 0x00;   // set data byte 4
  CAN_OBJ[ObjNr].Data[5] = 0x00;   // set data byte 5
  CAN_OBJ[ObjNr].Data[6] = 0x00;   // set data byte 6
  CAN_OBJ[ObjNr].Data[7] = 0x00;   // set data byte 7

  if (mode==CAN_MODE_TRANSMIT) {

    // Transmit message object is valid
    CAN_OBJ[ObjNr].MCR  = 0x5695;    // set Message Control Register

    // message direction is transmit
    // standard 11-bit identifier
    // 8 valid data bytes
    CAN_OBJ[ObjNr].MCFG = 0x08 | (dlc<<4); // set Message Configuration Register

    CAN_OBJ[ObjNr].UAR  = ID_TO_UAR(id);  // set Upper Arbitration Register
    CAN_OBJ[ObjNr].LAR  = 0x0000;         // set Lower Arbitration Register

  }

  else if (mode==CAN_MODE_RECEIVE) {

    // Receive message object is valid
    CAN_OBJ[8].MCR  = 0x5595;    // set Message Control Register

    // message direction is receive
    // standard 11-bit identifier
    CAN_OBJ[8].MCFG = 0x00;      // set Message Configuration Register

    CAN_OBJ[8].UAR  = ID_TO_UAR(CRO_ID);    // set Upper Arbitration Register
    CAN_OBJ[8].LAR  = 0x0000;    // set Lower Arbitration Register
  }

  else {

    // Message object is not valid
    CAN_OBJ[ObjNr].MCR  = 0x5555;    // set Message Control Register

  }

}

void CAN_vInit(void)
{

  //  ------------ CAN Control/Status Register --------------
  //  start the initialization of the CAN Modul
  C1CSR  = 0x0041;  // set INIT and CCE

  ///  ------------ Bit Timing Register ---------------------
  /// baudrate =  500,000 KBaud
  /// there are 5 time quanta before sample point
  /// there are 4 time quanta after sample point
  /// the (re)synchronization jump width is 2 time quanta
  C1BTR  = 0x2580;  // set Bit Timing Register

  C1GMS  = 0xE0FF;  // set Global Mask Short Register

  C1UGML = 0xFFFF;  // set Upper Global Mask Long Register

  C1LGML = 0xF8FF;  // set Lower Global Mask Long Register

  CAN_InitObject(0,0,CAN_MODE_INVALID,0);
  CAN_InitObject(1,0,CAN_MODE_INVALID,0);
  CAN_InitObject(2,0,CAN_MODE_INVALID,0);
  CAN_InitObject(3,0,CAN_MODE_INVALID,0);
  CAN_InitObject(4,0,CAN_MODE_INVALID,0);
  CAN_InitObject(5,0,CAN_MODE_INVALID,0);
  CAN_InitObject(6,0,CAN_MODE_INVALID,0);
  CAN_InitObject(7,0,CAN_MODE_INVALID,0);
  CAN_InitObject(8,0,CAN_MODE_INVALID,0);
  CAN_InitObject(9,0,CAN_MODE_INVALID,0);
  CAN_InitObject(10,0,CAN_MODE_INVALID,0);
  CAN_InitObject(11,0,CAN_MODE_INVALID,0);
  CAN_InitObject(12,0,CAN_MODE_INVALID,0);
  CAN_InitObject(13,0,CAN_MODE_INVALID,0);
  CAN_InitObject(14,0,CAN_MODE_INVALID,0);

  // Stress Sample
  #ifdef C_SAMPLE_STRESS
    CAN_InitObject(0,500,CAN_MODE_TRANSMIT,8);
    CAN_InitObject(1,501,CAN_MODE_TRANSMIT,8);
    CAN_InitObject(2,502,CAN_MODE_TRANSMIT,8);
    CAN_InitObject(3,503,CAN_MODE_TRANSMIT,8);
    CAN_InitObject(4,504,CAN_MODE_TRANSMIT,8);
    CAN_InitObject(5,505,CAN_MODE_TRANSMIT,8);
    CAN_InitObject(6,506,CAN_MODE_TRANSMIT,8);
    CAN_InitObject(7,507,CAN_MODE_TRANSMIT,8);
  #endif

  // CCP/XCP
  CAN_InitObject(8,CRO_ID,CAN_MODE_RECEIVE,8);
  CAN_InitObject(9,DTO_ID,CAN_MODE_TRANSMIT,8);

  //  reset CCE and INIT
  C1CSR = 0x0000;

}


//****************************************************************************
// Function      void CAN_vGetMsgObj(ubyte ObjNr, TCAN_Obj *pstObj)
//
//----------------------------------------------------------------------------
// Description   This function fills the forwarded SW message object with the
//               content of the chosen HW message object.
//
//               The structure of the SW message object is defined in the
//               header file CAN.H (see TCAN_Obj).
//
//----------------------------------------------------------------------------
// Returnvalue   none
//
//----------------------------------------------------------------------------
// Parameters    Number of the message object to be read (0-14)
// Parameters    Pointer on a message object to be filled by this function.
//
//****************************************************************************

void CAN_vGetMsgObj(ubyte ObjNr, TCAN_Obj *pstObj)
{
  ubyte i,l;
  register CAN_OBJ_PTR po = CAN_OBJP(ObjNr);

  pstObj->ubMsgCfg = po->MCFG;

  pstObj->ulId = ((po->UAR & 0xe000) >> 13) + ((po->UAR & 0x00ff) <<  3);

  l = (po->MCFG & 0xf0) >> 4;
  for(i = 0; i < l; i++)
  {
    pstObj->ubData[i] = po->Data[i];
  }

  if (ObjNr < 14 || (po->MCR & 0x000c) != 0x0008)
  {
    po->MCR = 0xfdff;  // reset NEWDAT
  }
}


//****************************************************************************
// Function      bit CAN_bRequestMsgObj(ubyte ObjNr)
//
//----------------------------------------------------------------------------
// Description   If a TRANSMIT OBJECT is to be reconfigured it must first be
//               accessed. The access to the transmit object is exclusive.
//               This function checks whether the choosen message object is
//               still executing a transmit request, or if the object can 
//               be accessed exclusively.
//               After the message object is reserved, it can be reconfigured
//               by using the function CAN_vConfigMsgObj or CAN_vLoadData.
//               Both functions enable access to the object for the CAN
//               controller.
//               By calling the function CAN_vTransmit transfering of data
//               is started.
//
//----------------------------------------------------------------------------
// Returnvalue   0 message object is busy (a transfer is actice), else 1
//
//----------------------------------------------------------------------------
// Parameters    Number of the message object (0-13)
//
//
//****************************************************************************

bit CAN_bRequestMsgObj(ubyte ObjNr)
{
  register CAN_OBJ_PTR po = CAN_OBJP(ObjNr);

  if((po->MCR & 0x3000) == 0x1000)  // if reset TXRQ 
  {
    po->MCR = 0xfbff;               // set CPUUPD 
    return 1;
  }

  return 0;
}


//****************************************************************************
// Function      bit CAN_bNewData(ubyte ObjNr)
//
//----------------------------------------------------------------------------
// Description   This function checks whether the selected RECEIVE OBJECT has
//               received a new message. If so the function returns the
//               value "1". 
//
//----------------------------------------------------------------------------
// Returnvalue   1 the message object has received a new message, else 0
//
//----------------------------------------------------------------------------
// Parameters    Number of the message object (0-14)
//
//****************************************************************************

bit CAN_bNewData(ubyte ObjNr)
{

  if((CAN_OBJ[ObjNr].MCR & 0x0300) == 0x0200)  // if NEWDAT
  {
    return 1;
  }

  return 0;
}


//****************************************************************************
// Function      void CAN_vTransmit(ubyte ObjNr)
//
//----------------------------------------------------------------------------
// Description   This function triggers the CAN controller to send the 
//               selected message.
//               If the selected message object is a TRANSMIT OBJECT then 
//               this function triggers the sending of a data frame.
//               If however the selected message object is a RECEIVE OBJECT
//               this function triggers the sending of a remote frame.
//
//----------------------------------------------------------------------------
// Returnvalue   none
//
//----------------------------------------------------------------------------
// Parameters    Number of the message object to be sent (0-13)
//
//
//****************************************************************************

void CAN_vTransmit(ubyte ObjNr)
{
  CAN_OBJ[ObjNr].MCR = 0xe7ff;  // set TXRQ,reset CPUUPD
}

void CAN_vSetMsgDlc(ubyte ObjNr, ubyte dlc)
{
  CAN_OBJ[ObjNr].MCFG &= 0x0F;
  CAN_OBJ[ObjNr].MCFG |= (dlc<<4);
}



//****************************************************************************
// Function      void CAN_vLoadData(ubyte ObjNr, ubyte *pubData)
//
//----------------------------------------------------------------------------
// Description   If a harware TRANSMIT OBJECT has to be loaded with data
//                but not with a new identifier, this function may be used
//                instead of the function CAN_vConfigMsgObj.
//                The message object should be accessed by calling the function
//                CAN_bRequestMsgObj before calling this function. This
//                prevents the CAN controller from working with invalid data.
//
//----------------------------------------------------------------------------
// Returnvalue   none
//
//----------------------------------------------------------------------------
// Parameters    Number of the message object to be configured (0-14)
// Parameters    Pointer on a data buffer
//
//
//****************************************************************************

void CAN_vLoadData(ubyte ObjNr, ubyte *pubData)
{
  ubyte i,l;
  register CAN_OBJ_PTR po = CAN_OBJP(ObjNr);

  po->MCR = 0xfaff;  // set CPUUPD and NEWDAT

  l = (po->MCFG & 0xf0) >> 4;
  for(i = 0; i < l; i++)
  {
    po->Data[i] = *(pubData++);
  }

  po->MCR = 0xf7ff;  // reset CPUUPD
}


//****************************************************************************
// Function      bit CAN_bMsgLost(ubyte ObjNr)
//
//----------------------------------------------------------------------------
// Description   If a RECEIVE OBJECT receives new data before the old object
//                has been read, the old object is lost. The CAN controller
//                indicates this by setting the message lost bit (MSGLST).
//                This function returns the status of this bit.
//                
//                Note:
//                This function resets the message lost bit (MSGLST).
//
//----------------------------------------------------------------------------
// Returnvalue   1 the message object has lost a message, else 0
//
//----------------------------------------------------------------------------
// Parameters    Number of the message object (0-14)
//
//
//****************************************************************************

bit CAN_bMsgLost(ubyte ObjNr)
{
  register CAN_OBJ_PTR po = CAN_OBJP(ObjNr);

  if ((po->MCR & 0x0c00) == 0x0800)  // if set MSGLST 
  {
    po->MCR = 0xf7ff;                // reset MSGLST 
    return 1;
  }

  return 0;
}



//****************************************************************************
// Function      void CAN_vReleaseObj(ubyte ObjNr)
//
//----------------------------------------------------------------------------
// Description   This function resets the NEWDAT flag of the selected RECEIVE
//               OBJECT, so that the CAN controller have access to it.
//               This function must be called if the function CAN_bNewData
//               detects, that new data are present in the message object and
//               the actual data have been read by calling the function
//               CAN_vGetMsgObj. 
//
//----------------------------------------------------------------------------
// Returnvalue   none
//
//----------------------------------------------------------------------------
// Parameters    Number of the message object (0-14)
//
//****************************************************************************

void CAN_vReleaseObj(ubyte ObjNr)
{
  CAN_OBJ[ObjNr].MCR = 0xfdff;     // reset NEWDAT
}




