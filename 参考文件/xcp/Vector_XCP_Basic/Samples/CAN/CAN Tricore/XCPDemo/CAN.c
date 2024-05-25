//****************************************************************************
// @Module        MultiCAN Controller 
// @Filename      CAN.c
// @Project       demo1767.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1767
//
// @Compiler      Tasking 3.1
//
// @Codegenerator 1.0
//
// @Description   This file contains functions that use the CAN module.
//
//----------------------------------------------------------------------------
// @Date          16.12.2010 18:24:58
//
//****************************************************************************

// USER CODE BEGIN (CAN_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (CAN_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

#define SetListCommand(Value) CAN_PANCTR = Value; while (CAN_PANCTR & CAN_PANCTR_BUSY);

// USER CODE BEGIN (CAN_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// Structure for a single MultiCAN object
// A total of 64 such object structures exists

struct stCanObj 
{
  uword  uwMOFCR;    // Function Control Register
  uword  uwMOFGPR;   // FIFO/Gateway Pointer Register
  uword  uwMOIPR;    // Interrupt Pointer Register
  uword  uwMOAMR;    // Acceptance Mask Register
  ubyte  ubData[8];  // Message Data 0..7
  uword  uwMOAR;     // Arbitration Register
  uword  uwMOCTR;    // Control Register
};

#define CAN_HWOBJ ((struct stCanObj volatile *) 0xF0005000)

// USER CODE BEGIN (CAN_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CAN_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CAN_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CAN_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (CAN_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (CAN_General,9)

// USER CODE END


//****************************************************************************
// @Function      void CAN_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the CAN function 
//                library. It is assumed that the SFRs used by this library 
//                are in their reset state. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          16.12.2010
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void CAN_vInit(void)
{

  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of the Module Clock:
  ///  -----------------------------------------------------------------------

  ///  - the CAN module is not stopped during sleep mode
  ///  - fractional divider mode is selected
  ///  - required CAN module clock is 40,00 MHz
  ///  - real CAN module clock is 39,97 MHz

  MAIN_vResetENDINIT();
  CAN_CLC        =  0x00000008;  // load clock control register
  while ((CAN_CLC & 0x00000002)==2);  //wait until module is enabled
  CAN_FDR        =  0x00008266;  // load fractional divider register
  MAIN_vSetENDINIT();

  //   - wait until Panel has finished the initialisation
  while (CAN_PANCTR & CAN_PANCTR_BUSY);

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAN Node 0:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Node 0:
  ///  - set INIT and CCE

  CAN_NCR0       =  0x00000041;  // load node 0 control register
  CAN_NIPR0      =  0x00000000;  // load node 0 interrupt pointer register

  ///  Configuration of the Node 0 Error Counter:
  ///  - the error warning threshold value (warning level) is 96

  CAN_NECNT0     =  0x00600000;  // load node 0 error counter register


  CAN_NPCR0      =  0x00000000;  // load node 0 port control register

  ///  Configuration of the used CAN Port Pins:
  ///  - P3.12 is used as  CAN node 0 input signal 1 ( RXDCAN0)
  ///  - the pull-up device is assigned
  ///  - output driver characteristic: medium driver

  P3_IOCR12      = (P3_IOCR12 & ~0x000000F0) | 0x00000020; // load control 
                                                           // register

  ///  - P3.13 is used as  CAN node 0 output signal 1 ( TXDCAN0)
  ///  - the push/pull function is activated
  ///  - output driver characteristic: strong driver, sharp edge
  ///  - the emergency stop function is disabled

  P3_IOCR12      = (P3_IOCR12 & ~0x0000F000) | 0x00009000; // load control 
                                                           // register

  ///  Configuration of the Node 0 Baud Rate:
  ///  - required baud rate = 500000 baud
  ///  - real baud rate     = 499674 baud
  ///  - sample point       = 60,00 %
  ///  - there are 5 time quanta before sample point
  ///  - there are 4 time quanta after sample point
  ///  - the (re)synchronization jump width is 2 time quanta

  CAN_NBTR0      =  0x00003447;  // load  node 0 bit timing register

  ///  Configuration of the Frame Counter:
  ///  - Frame Counter Mode: the counter is incremented upon the reception 
  ///    and transmission of frames
  ///  - frame counter: 0x0000

  CAN_NFCR0      =  0x00000000;  // load  node 0 frame counter register

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAN Node 1:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Node 1:
  ///  - set INIT and CCE

  CAN_NCR1       =  0x00000041;  // load node 1 control register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the CAN Message Object List Structure:
  ///  -----------------------------------------------------------------------
  ///  Allocate MOs for list 1:
  SetListCommand(0x01020002);  // MO2 for list 1
  SetListCommand(0x01010002);  // MO1 for list 1
  SetListCommand(0x01000002);  // MO0 for list 1

  ///  -----------------------------------------------------------------------
  ///  Configuration of the CAN Message Objects 0 - 63:
  ///  -----------------------------------------------------------------------
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 0:
  ///  -----------------------------------------------------------------------
  ///  - message object 0 is valid
  ///  - message object is used as transmit object
  ///  - this message object is assigned to list 1 (node 0)

  CAN_MOCTR0     =  0x0EA80000;  // load MO0 control register

  ///  - this object is a STANDARD MESSAGE OBJECT
  ///  - 4 valid data bytes

  CAN_MOFCR0     =  0x04000000;  // load MO0 function control register


  CAN_MOFGPR0    =  0x00000000;  // load MO0 FIFO/gateway pointer register

  ///  - only accept receive frames with matching IDE bit
  ///  - acceptance mask 11-bit: 0x7FF

  CAN_MOAMR0     =  0x3FFFFFFF;  // load MO0 acceptance mask register

  ///  - priority class 3; transmit acceptance filtering is based on the list 
  ///    order (like class 1)
  ///  - standard 11-bit identifier
  ///  - identifier 11-bit:      0x100

  CAN_MOAR0      =  0xC4000000;  // load MO0 arbitration register

  CAN_MODATAL0   =  0x00000000;  // load MO0 data register low
  CAN_MODATAH0   =  0x00000000;  // load MO0 data register high

  ///  - use message pending register 0 bit position 0

  CAN_MOIPR0     =  0x00000000;  // load MO0 interrupt pointer register
  CAN_MOCTR0     =  0x00200000;  // set MSGVAL

  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 1:
  ///  -----------------------------------------------------------------------
  ///  - message object 1 is valid
  ///  - message object is used as transmit object
  ///  - this message object is assigned to list 1 (node 0)

  CAN_MOCTR1     =  0x0EA80000;  // load MO1 control register

  ///  - this object is a STANDARD MESSAGE OBJECT
  ///  - 8 valid data bytes

  CAN_MOFCR1     =  0x08000000;  // load MO1 function control register


  CAN_MOFGPR1    =  0x00000000;  // load MO1 FIFO/gateway pointer register

  ///  - only accept receive frames with matching IDE bit
  ///  - acceptance mask 11-bit: 0x7FF

  CAN_MOAMR1     =  0x3FFFFFFF;  // load MO1 acceptance mask register

  ///  - priority class 3; transmit acceptance filtering is based on the list 
  ///    order (like class 1)
  ///  - standard 11-bit identifier
  ///  - identifier 11-bit:      0x200

  CAN_MOAR1      =  0xC8000000;  // load MO1 arbitration register

  CAN_MODATAL1   =  0x00000000;  // load MO1 data register low
  CAN_MODATAH1   =  0x00000000;  // load MO1 data register high

  ///  - use message pending register 0 bit position 1

  CAN_MOIPR1     =  0x00000100;  // load MO1 interrupt pointer register
  CAN_MOCTR1     =  0x00200000;  // set MSGVAL

  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 2:
  ///  -----------------------------------------------------------------------
  ///  - message object 2 is valid
  ///  - message object is used as receive object
  ///  - this message object is assigned to list 1 (node 0)

  CAN_MOCTR2     =  0x00A00000;  // load MO2 control register

  ///  - this object is a STANDARD MESSAGE OBJECT
  ///  - 8 valid data bytes

  CAN_MOFCR2     =  0x08000000;  // load MO2 function control register


  CAN_MOFGPR2    =  0x00000000;  // load MO2 FIFO/gateway pointer register

  ///  - only accept receive frames with matching IDE bit
  ///  - acceptance mask 11-bit: 0x7FF

  CAN_MOAMR2     =  0x3FFFFFFF;  // load MO2 acceptance mask register

  ///  - priority class 3; transmit acceptance filtering is based on the list 
  ///    order (like class 1)
  ///  - standard 11-bit identifier
  ///  - identifier 11-bit:      0x201

  CAN_MOAR2      =  0xC8040000;  // load MO2 arbitration register

  ///  - use message pending register 0 bit position 2

  CAN_MOIPR2     =  0x00000200;  // load MO2 interrupt pointer register
  CAN_MOCTR2     =  0x00200000;  // set MSGVAL

  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 3:
  ///  -----------------------------------------------------------------------
  ///  - message object 3 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 4:
  ///  -----------------------------------------------------------------------
  ///  - message object 4 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 5:
  ///  -----------------------------------------------------------------------
  ///  - message object 5 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 6:
  ///  -----------------------------------------------------------------------
  ///  - message object 6 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 7:
  ///  -----------------------------------------------------------------------
  ///  - message object 7 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 8:
  ///  -----------------------------------------------------------------------
  ///  - message object 8 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 9:
  ///  -----------------------------------------------------------------------
  ///  - message object 9 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 10:
  ///  -----------------------------------------------------------------------
  ///  - message object 10 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 11:
  ///  -----------------------------------------------------------------------
  ///  - message object 11 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 12:
  ///  -----------------------------------------------------------------------
  ///  - message object 12 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 13:
  ///  -----------------------------------------------------------------------
  ///  - message object 13 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 14:
  ///  -----------------------------------------------------------------------
  ///  - message object 14 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 15:
  ///  -----------------------------------------------------------------------
  ///  - message object 15 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 16:
  ///  -----------------------------------------------------------------------
  ///  - message object 16 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 17:
  ///  -----------------------------------------------------------------------
  ///  - message object 17 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 18:
  ///  -----------------------------------------------------------------------
  ///  - message object 18 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 19:
  ///  -----------------------------------------------------------------------
  ///  - message object 19 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 20:
  ///  -----------------------------------------------------------------------
  ///  - message object 20 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 21:
  ///  -----------------------------------------------------------------------
  ///  - message object 21 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 22:
  ///  -----------------------------------------------------------------------
  ///  - message object 22 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 23:
  ///  -----------------------------------------------------------------------
  ///  - message object 23 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 24:
  ///  -----------------------------------------------------------------------
  ///  - message object 24 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 25:
  ///  -----------------------------------------------------------------------
  ///  - message object 25 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 26:
  ///  -----------------------------------------------------------------------
  ///  - message object 26 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 27:
  ///  -----------------------------------------------------------------------
  ///  - message object 27 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 28:
  ///  -----------------------------------------------------------------------
  ///  - message object 28 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 29:
  ///  -----------------------------------------------------------------------
  ///  - message object 29 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 30:
  ///  -----------------------------------------------------------------------
  ///  - message object 30 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 31:
  ///  -----------------------------------------------------------------------
  ///  - message object 31 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 32:
  ///  -----------------------------------------------------------------------
  ///  - message object 32 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 33:
  ///  -----------------------------------------------------------------------
  ///  - message object 33 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 34:
  ///  -----------------------------------------------------------------------
  ///  - message object 34 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 35:
  ///  -----------------------------------------------------------------------
  ///  - message object 35 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 36:
  ///  -----------------------------------------------------------------------
  ///  - message object 36 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 37:
  ///  -----------------------------------------------------------------------
  ///  - message object 37 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 38:
  ///  -----------------------------------------------------------------------
  ///  - message object 38 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 39:
  ///  -----------------------------------------------------------------------
  ///  - message object 39 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 40:
  ///  -----------------------------------------------------------------------
  ///  - message object 40 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 41:
  ///  -----------------------------------------------------------------------
  ///  - message object 41 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 42:
  ///  -----------------------------------------------------------------------
  ///  - message object 42 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 43:
  ///  -----------------------------------------------------------------------
  ///  - message object 43 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 44:
  ///  -----------------------------------------------------------------------
  ///  - message object 44 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 45:
  ///  -----------------------------------------------------------------------
  ///  - message object 45 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 46:
  ///  -----------------------------------------------------------------------
  ///  - message object 46 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 47:
  ///  -----------------------------------------------------------------------
  ///  - message object 47 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 48:
  ///  -----------------------------------------------------------------------
  ///  - message object 48 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 49:
  ///  -----------------------------------------------------------------------
  ///  - message object 49 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 50:
  ///  -----------------------------------------------------------------------
  ///  - message object 50 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 51:
  ///  -----------------------------------------------------------------------
  ///  - message object 51 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 52:
  ///  -----------------------------------------------------------------------
  ///  - message object 52 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 53:
  ///  -----------------------------------------------------------------------
  ///  - message object 53 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 54:
  ///  -----------------------------------------------------------------------
  ///  - message object 54 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 55:
  ///  -----------------------------------------------------------------------
  ///  - message object 55 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 56:
  ///  -----------------------------------------------------------------------
  ///  - message object 56 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 57:
  ///  -----------------------------------------------------------------------
  ///  - message object 57 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 58:
  ///  -----------------------------------------------------------------------
  ///  - message object 58 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 59:
  ///  -----------------------------------------------------------------------
  ///  - message object 59 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 60:
  ///  -----------------------------------------------------------------------
  ///  - message object 60 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 61:
  ///  -----------------------------------------------------------------------
  ///  - message object 61 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 62:
  ///  -----------------------------------------------------------------------
  ///  - message object 62 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 63:
  ///  -----------------------------------------------------------------------
  ///  - message object 63 is not valid

  ///  -----------------------------------------------------------------------
  ///  Configuration of Service Request Nodes 0 - 15:
  ///  -----------------------------------------------------------------------
  //   -----------------------------------------------------------------------
  //   Start the CAN Nodes:
  //   -----------------------------------------------------------------------
  CAN_NCR0      &= ~0x00000041;  // reset INIT and CCE


  // USER CODE BEGIN (Init,3)

  // USER CODE END

} //  End of function CAN_vInit


//****************************************************************************
// @Function      void CAN_vGetMsgObj(ubyte ubObjNr, CAN_SWObj *pstObj) 
//
//----------------------------------------------------------------------------
// @Description   This function fills the forwarded SW message object with 
//                the content of the chosen HW message object.
//                
//                The structure of the SW message object is defined in the 
//                header file CAN.h (see CAN_SWObj).
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object to be read (0-63)
// @Parameters    *pstObj: 
//                Pointer on a message object to be filled by this function
//
//----------------------------------------------------------------------------
// @Date          16.12.2010
//
//****************************************************************************

// USER CODE BEGIN (GetMsgObj,1)

// USER CODE END

void CAN_vGetMsgObj(ubyte ubObjNr, CAN_SWObj *pstObj)
{
  ubyte i;

  // get DLC
  pstObj->usMOCfg  = (CAN_HWOBJ[ubObjNr].uwMOFCR & 0x0f000000) >> 24;
  for(i = 0; i < pstObj->usMOCfg; i++)
  {
    pstObj->ubData[i] = CAN_HWOBJ[ubObjNr].ubData[i];
  }

  pstObj->usMOCfg  = (pstObj->usMOCfg << 4);    // shift DLC
  if(CAN_HWOBJ[ubObjNr].uwMOCTR & 0x00000800)   // if transmit object
  {
    pstObj->usMOCfg  = pstObj->usMOCfg | 0x08;  // set DIR
  }

  if(CAN_HWOBJ[ubObjNr].uwMOAR & 0x20000000)    // extended identifier
  {
    pstObj->uwID     = CAN_HWOBJ[ubObjNr].uwMOAR & 0x1fffffff;
    pstObj->uwMask   = CAN_HWOBJ[ubObjNr].uwMOAMR & 0x1fffffff;
    pstObj->usMOCfg  = pstObj->usMOCfg | 0x04;  // set IDE
  }
  else                                          // standard identifier 
  {
    pstObj->uwID   = (CAN_HWOBJ[ubObjNr].uwMOAR & 0x1fffffff) >> 18;
    pstObj->uwMask = (CAN_HWOBJ[ubObjNr].uwMOAMR & 0x1fffffff) >> 18;
  }

  pstObj->usCounter = (CAN_HWOBJ[ubObjNr].uwMOIPR & 0xffff0000) >> 16;

} //  End of function CAN_vGetMsgObj


//****************************************************************************
// @Function      ubyte CAN_ubRequestMsgObj(ubyte ubObjNr) 
//
//----------------------------------------------------------------------------
// @Description   If a TRANSMIT OBJECT is to be reconfigured it must first be 
//                accessed. The access to the transmit object is exclusive. 
//                This function checks whether the choosen message object is 
//                still executing a transmit request, or if the object can be 
//                accessed exclusively.
//                After the message object is reserved, it can be 
//                reconfigured by using the function CAN_vConfigMsgObj or 
//                CAN_vLoadData.
//                Both functions enable access to the object for the CAN 
//                controller. 
//                By calling the function CAN_vTransmit transfering of data 
//                is started.
//
//----------------------------------------------------------------------------
// @Returnvalue   0 message object is busy (a transfer is active), else 1
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object (0-63)
//
//----------------------------------------------------------------------------
// @Date          16.12.2010
//
//****************************************************************************

// USER CODE BEGIN (RequestMsgObj,1)

// USER CODE END

ubyte CAN_ubRequestMsgObj(ubyte ubObjNr)
{
  ubyte ubReturn;

  ubReturn = 0;
  if((CAN_HWOBJ[ubObjNr].uwMOCTR & 0x00000100) == 0x00000000)  // if reset TXRQ 
  {
    CAN_HWOBJ[ubObjNr].uwMOCTR = 0x00000020;                   // reset MSGVAL 
    ubReturn = 1;
  }
  return(ubReturn);

} //  End of function CAN_ubRequestMsgObj


//****************************************************************************
// @Function      ubyte CAN_ubNewData(ubyte ubObjNr) 
//
//----------------------------------------------------------------------------
// @Description   This function checks whether the selected RECEIVE OBJECT 
//                has received a new message. If so the function returns the 
//                value '1'.
//
//----------------------------------------------------------------------------
// @Returnvalue   1 the message object has received a new message, else 0
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object (0-63)
//
//----------------------------------------------------------------------------
// @Date          16.12.2010
//
//****************************************************************************

// USER CODE BEGIN (NewData,1)

// USER CODE END

ubyte CAN_ubNewData(ubyte ubObjNr)
{
  ubyte ubReturn;

  ubReturn = 0;
  if((CAN_HWOBJ[ubObjNr].uwMOCTR & 0x00000008))    // if NEWDAT 
  {
    ubReturn = 1;
  }
  return(ubReturn);

} //  End of function CAN_ubNewData


//****************************************************************************
// @Function      void CAN_vTransmit(ubyte ubObjNr) 
//
//----------------------------------------------------------------------------
// @Description   This function triggers the CAN controller to send the 
//                selected message.
//                If the selected message object is a TRANSMIT OBJECT then 
//                this function triggers the sending of a data frame. If 
//                however the selected message object is a RECEIVE OBJECT 
//                this function triggers the sending of a remote frame.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object (0-63)
//
//----------------------------------------------------------------------------
// @Date          16.12.2010
//
//****************************************************************************

// USER CODE BEGIN (Transmit,1)

// USER CODE END

void CAN_vTransmit(ubyte ubObjNr)
{
  CAN_HWOBJ[ubObjNr].uwMOCTR = 0x07000000;  // set TXRQ,TXEN0,TXEN1

} //  End of function CAN_vTransmit


//****************************************************************************
// @Function      void CAN_vLoadData(ubyte ubObjNr, ubyte *pubData) 
//
//----------------------------------------------------------------------------
// @Description   If a hardware TRANSMIT OBJECT has to be loaded with data 
//                but not with a new identifier, this function may be used 
//                instead of the function CAN_vConfigMsgObj. The message 
//                object should be accessed by calling the function 
//                CAN_ubRequestMsgObj before calling this function. This 
//                prevents the CAN controller from working with invalid data.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object to be configured (0-63)
// @Parameters    *pubData: 
//                Pointer on a data buffer
//
//----------------------------------------------------------------------------
// @Date          16.12.2010
//
//****************************************************************************

// USER CODE BEGIN (LoadData,1)

// USER CODE END

void CAN_vLoadData(ubyte ubObjNr, ubyte *pubData)
{
  ubyte i;

  CAN_HWOBJ[ubObjNr].uwMOCTR = 0x00080000;       // set NEWDAT

  for(i = 0; i < (CAN_HWOBJ[ubObjNr].uwMOFCR & 0x0f000000) >> 24; i++)
  {
    CAN_HWOBJ[ubObjNr].ubData[i] = *(pubData++);
  }

  CAN_HWOBJ[ubObjNr].uwMOCTR = 0x00200040;       // reset RTSEL, set MSGVAL

} //  End of function CAN_vLoadData


//****************************************************************************
// @Function      void CAN_vReleaseObj(ubyte ubObjNr) 
//
//----------------------------------------------------------------------------
// @Description   This function resets the NEWDAT flag of the selected 
//                RECEIVE OBJECT, so that the CAN controller have access to 
//                it. This function must be called if the function 
//                CAN_ubNewData detects, that new data are present in the 
//                message object and the actual data have been read by 
//                calling the function CAN_vGetMsgObj. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object (0-63)
//
//----------------------------------------------------------------------------
// @Date          16.12.2010
//
//****************************************************************************

// USER CODE BEGIN (ReleaseObj,1)

// USER CODE END

void CAN_vReleaseObj(ubyte ubObjNr)
{
  CAN_HWOBJ[ubObjNr].uwMOCTR = 0x00000008;     // reset NEWDAT

} //  End of function CAN_vReleaseObj



// USER CODE BEGIN (CAN_General,10)

// USER CODE END

