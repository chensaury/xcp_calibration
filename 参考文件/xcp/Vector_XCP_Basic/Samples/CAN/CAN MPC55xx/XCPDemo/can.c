/*----------------------------------------------------------------------------
| File:
|   
|
| Project:
|   Sample XCP driver for MPC5554
|   CANape Calibration Tool
|
| Description:
|   
|   
|
 ----------------------------------------------------------------------------*/

#include "project.h"


volatile tInternalMsgObject *pCanObject;
vuint8 txObjActive;
        

/*****************************************************************************
* Name         :  CanInit  
* Called by    :  main
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function initialized the CAN controller
******************************************************************************/

void CanInit( void )
{
   vuint8  i; 
   
   /* Initialize FlexCAN A pins */
   SIU.PCR[83].R = 0x0400; /* Pin assignment set to CAN tx */
   SIU.PCR[84].R = 0x0400; /* Pin assignment set to CAN rx */

   FlexCAN.canMCR &= ~(kFlexCANStop); /* Enable CAN by clearing MDIS     */
   FlexCAN.canMCR |= kFlexCANSoftReset; /* Perform  soft reset */
      
   /* Wait till soft reset is active */
   while (FlexCAN.canMCR & kFlexCANSoftReset)
   {
      ;
   }
   
   FlexCAN.canMCR |= kFlexCANFreeze;      /* Set freeze bit   */
   FlexCAN.canMCR |= kFlexCANHalt;        
   
   /* Wait for freeze acknowledge */
   while ( (FlexCAN.canMCR & kFlexCANFrzAck) == 0 ) 
   {
      ;
   }

   /* Initialize all operation modes */
   FlexCAN.canCtrl0 = CAN_CTRL0;
   FlexCAN.canCtrl1 = CAN_CTRL1; 
   FlexCAN.canCtrl2 = CAN_CTRL2;
   FlexCAN.prDiv    = CAN_PRESDIV;
   FlexCAN.canMaxMB = CAN_MAX_OBJ;

   /* Initialize global mask registers (All bits checked) */
   FlexCAN.rxGMskHi = (0xFFFF & (~0xE000));
   FlexCAN.rxGMskLo = 0xFFFF;
   FlexCAN.rx14MskHi = (0xFFFF & (~0xE000));
   FlexCAN.rx14MskLo = 0xFFFF;
   FlexCAN.rx15MskHi = (0xFFFF & (~0xE000));
   FlexCAN.rx15MskLo = 0xFFFF;
  
   /* Init all objects */
   for (i=0;i<64;i++) FlexCAN.canObject[i].CtrlStat = kTxCodeInactive;

   /* Init RX objects */
   FlexCAN.canObject[CAN_RX_OBJ].CtrlStat = kRxCodeNotActive;
   FlexCAN.canObject[CAN_RX_OBJ].IdHi = CAN_RX_ID<<2;  
   FlexCAN.canObject[CAN_RX_OBJ].CtrlStat = kRxCodeEmpty;   
     
   /* Disable and clear all interrupts (default) */
   FlexCAN.iMask0 = 0x00000000;
   FlexCAN.iMask1 = 0x00000000;
   /* Clear status flags by writing '1' */              
   FlexCAN.iFlag0 = 0xFFFFFFFF;            
   FlexCAN.iFlag1 = 0xFFFFFFFF;            

   FlexCAN.canMCR &= ~kFlexCANHalt;      /* Switch to normal mode */
   FlexCAN.canMCR &= ~kFlexCANFreeze;    /* Clear freeze bit      */
   
   txObjActive = 0;
}





/*****************************************************************************
* Name         :  CanTransmit  
* Called by    :  Transport Layer
* Preconditions:  CAN interface must be initialized before call
* Parameters   :  Pointer to transmit object
* Return code  :  kCanTxOk or kCanTxFailed
* Description  :  This function transmits a CAN message 
******************************************************************************/
vuint8 CanTransmit( vuint16 id, vuint8 dlc, vuint8 *data)
{
   vuint8 i, *src, *dst;
   volatile tInternalMsgObject *pCanObject = &FlexCAN.canObject[CAN_TX_OBJ];
   
   /* Check if CAN controller is ready to transmit a new message */
   if ( (FlexCAN.canMCR & kFlexCANNotRdy) ||   // Disabled or in freeze mode
        (FlexCAN.ESR & kFlexCANBoff)  ||       // Bus off
        (txObjActive) )
      {
        return 0;
      }

   
   /* Set transmit buffer inactive */
   pCanObject->CtrlStat = kTxCodeInactive;

   /* Copy message object in message buffer */
   pCanObject->IdHi = id<<2;
   src = data;
   dst = (vuint8 *)pCanObject->DataFld;
   for (i=0;i<dlc;i++) dst[i] = src[i];
   
   /* Transmit message object */
   pCanObject->CtrlStat = (kTxCodeTransmit | dlc);

   txObjActive = 1; 
   return 1;
}


/*****************************************************************************
* Name         :  CanMsgTransmitted  
* Called by    :  Transport Layer
* Preconditions:  CAN interface must be initialized before call
* Parameters   :  -
* Return code  :  1 = Transmitted or Idle, 0 = Not transmitted yet
* Description  :  This function returns 1 if a message can be transmitted and
*                 if the previous message has been acknowledged
*                 
******************************************************************************/
vuint8 CanMsgTransmitted( void )
{

   if (txObjActive==0) return 1;
   
   if ( (CAN_TX_OBJ_IFLAG&CAN_TX_OBJ_MASK) == 0 ) return 0; // Transmit in progress

   /* clear flag by writing '1' */
   CAN_TX_OBJ_IFLAG = CAN_TX_OBJ_MASK;  
   txObjActive = 0;
   return 1;
                  
}


/*****************************************************************************
* Name         :  ProcessRxMessage
* Called by    :  main module                                               
* Preconditions:  CAN hardware has to be initialized before call
* Parameters   :  -
* Return code  :  -
* Description  :  Processing of the Id of the received CAN messages. After the 
*                 Type of the message is determined, the right RxCanMsg handle
*                 is passed to FblHandleRxMsg().
*                 Finally the receivebuffer is released.
******************************************************************************/
vuint8 CanGetRxMsg( vuint8 *dlc, vuint16 *id, vuint32 *data )
{
  volatile vuint16 dummy;       
  

  if (CAN_RX_OBJ_IFLAG & CAN_RX_OBJ_MASK) {
    *dlc = (vuint8)(FlexCAN.canObject[CAN_RX_OBJ].CtrlStat & 0x0f); /* Lock RX buffer */
    *id  = (vuint16)(FlexCAN.canObject[CAN_RX_OBJ].IdHi >> 2);
    data[0] = *(vuint32*)&FlexCAN.canObject[CAN_RX_OBJ].DataFld[0];
    data[1] = *(vuint32*)&FlexCAN.canObject[CAN_RX_OBJ].DataFld[4];
    CAN_RX_OBJ_IFLAG = CAN_RX_OBJ_MASK;  /* clear flag by writing '1' */
    dummy = FlexCAN.timer;            /* Global unlock rx buffers */
    return 1;
  }
  else {  
    return 0;
  }

        
}







/* End of file ***************************************************************/

