/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Dio.c                                                      **
**                                                                            **
**  VERSION      : 6.0.0                                                      **
**                                                                            **
**  DATE         : 2018-08-30                                                 **
**                                                                            **
**  VARIANT      : Variant LT                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Dio Driver source file                                     **
**                                                                            **
**  SPECIFICATION(S) : Specification of Dio Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/* [cover parentID={684B8436-0E72-4797-A3B4-2A4FBDD083F0},
                   {AC8683E3-C8D8-4704-B9CC-4620683FE9C3}] [/cover] */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* Inclusion of Port Register structure header file */
#include "IfxPort_reg.h"

/* Own header file, this includes own configuration file also */
#include "Dio.h"
/* Include Mcal.h to import the library functions */
#include "McalLib.h"
/* Conditional Inclusion of Safety Error Tracer File */
#if (DIO_SAFETY_ENABLE == STD_ON)
#include "Mcal_SafetyError.h"
#endif /* (DIO_SAFETY_ENABLE == STD_ON) */
/* Conditional Inclusion of Developement Error Tracer File */
#if (DIO_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* ((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON)) */
/* [cover parentID={8B5F941B-CE96-41e1-A7FA-E41C785A6AE5}]
   Dio do not have User Mode Supoort Macros
   [/cover] */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/* Version checks */

#ifndef DIO_SW_MAJOR_VERSION
#error "DIO_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef DIO_SW_MINOR_VERSION
#error "DIO_SW_MINOR_VERSION is not defined. "
#endif

#ifndef DIO_SW_PATCH_VERSION
#error "DIO_SW_PATCH_VERSION is not defined. "
#endif

/* Check for Correct inclusion of headers */
#if ( DIO_SW_MAJOR_VERSION != 3U )
#error "DIO_SW_MAJOR_VERSION does not match. "
#endif
#if ( DIO_SW_MINOR_VERSION != 0U )
#error "DIO_SW_MINOR_VERSION does not match. "
#endif

#ifndef DIO_AR_RELEASE_MAJOR_VERSION
#error "DIO_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

#ifndef DIO_AR_RELEASE_MINOR_VERSION
#error "DIO_AR_RELEASE_MINOR_VERSION is not defined."
#endif

#ifndef DIO_AR_RELEASE_REVISION_VERSION
#error "DIO_AR_RELEASE_REVISION_VERSION is not defined."
#endif
/* [cover parentID={F7FBC1BE-361C-48d8-BE05-13B8C0CF8618}]
  [/cover] */
#if ( DIO_AR_RELEASE_MAJOR_VERSION != 4U)
#error "DIO_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#if ( DIO_AR_RELEASE_MINOR_VERSION != 2U )
#error "DIO_AR_RELEASE_MINOR_VERSION does not match."
#endif

/* [cover parentID={905B21B2-76DD-4e4d-8BE1-81E809E398B0}]
  [/cover] */
#if (DIO_DEV_ERROR_DETECT == STD_ON)

#ifndef DET_AR_RELEASE_MAJOR_VERSION
#error "DET_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
#error "DET_AR_RELEASE_MAJOR_VERSION does not match."
#endif



#endif /* End for DIO_DEV_ERROR_DETECT */



/*******************************************************************************
**                      Private Object Like Macro Definitions                 **
*******************************************************************************/
#if ((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))

/* Maximum Port Pin ID */
#if(MAX_AVAILABLE_PORT == 40U)
#define DIO_MAX_VALID_PORT_PIN_ID    (0x290U)
#else
#define DIO_MAX_VALID_PORT_PIN_ID    (0x298U)
#endif

/* 0th Bit Mask value */
#define DIO_CHANNEL_BIT_MASK         (0x01U)

/* Error status values */
#define DIO_NO_ERROR                 (1U)
#define DIO_ERROR                    (0U)

/* Port numbers */
#define DIO_NUMBER_31                (0x1FU)
#define DIO_NUMBER_32                (0x20U)
#endif /* DIO_DEV_ERROR_DETECT == STD_ON */

#define DIO_NUMBER_0                 (0x0U)
#define DIO_NUMBER_16                (0x10U)
#define DIO_NUMBER_1                 (0x1U)

/* lower 4 bit mask value */
#define DIO_PIN_LOW4_MASK     (0x0FU)

/* Bit 4 to 11 Mask value */
#define DIO_4_TO_11_MASK      (0x0FF0U)

/* This is the reset bit set for Pn_Omr register*/
#define DIO_OMR_RESET_BIT            (0x1U)

/* Port Number offset */
#define DIO_PORT_NUM_OFFSET   (0x4U)

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* IOCR0 register offset in Port_RegType */
#define DIO_PORT_IOCR0_REG_OFFSET  (0x4U)

/* Mask to get direction info from Pin control value */
#define DIO_PORT_DIR_MSK             (0x80U)

/*  Port pin input dirction value */
#define DIO_PORT_PIN_IN              (0x00U)

/* This is the mask to toggle bit set for Pn_Omr Register */
#define DIO_OMR_MASK_BIT            ((uint32)0x00010001)

#endif
/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/* [cover parentID={5713A17A-3FA1-427f-A0B6-89125A17689A},
                            {72DABBEB-F27B-4677-B6B4-B53F634341BA}] [/cover] */
/* [cover parentID={2757CB7F-252C-4231-80B1-F6375E8BAE83},
                   {EA0715EE-3E3C-4aac-A42E-4B5CFC96CEED},
                   {566ED99C-0D96-46ac-97BF-E97B04E2C700}] [/cover] */
/* Start of memory mapping of 16 bit constant */
#define DIO_START_SEC_CONST_ASIL_B_GLOBAL_16
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Dio_Memmap.h header is included without safegaurd.*/
#include "Dio_MemMap.h"

/* MISRA2012_RULE_8_9_JUSTIFICATION: Variable Dio_kMaskAllPortPins cannot be
defined at block scope as it declared as static const under memmap section
DIO_START_SEC_CONST_ASIL_B_GLOBAL_16 */
/* Mask values for all the ports.
   This constant is used to mask the All port pins within the port */
static const Dio_PortLevelType Dio_kMaskAllPortPins[] =
{
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT0,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT1,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT2,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT3,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT4,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT5,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT6,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT7,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT8,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT9,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT10,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT11,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT12,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT13,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT14,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT15,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT16,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT17,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT18,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT19,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT20,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT21,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT22,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT23,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT24,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT25,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT26,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT27,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT28,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT29,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT30,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT31,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT32,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT33,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT34,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT35,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT36,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT37,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT38,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT39,
  #if(MAX_AVAILABLE_PORT == 40U)
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT40
  #else
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT40,
  (Dio_PortLevelType)DIO_MASK_ALL_PINS_PORT41
  #endif

};

/* Stop of memory mapping of 16 bit constant */
#define DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_16
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Dio_Memmap.h header is included without safegaurd.*/
/*MISRA2012_RULE_20_1_JUSTIFICATION: Dio_Memmap.h header included as per
Autosar guidelines. */
#include "Dio_MemMap.h"
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#if((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define DIO_START_SEC_CONST_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Dio_Memmap.h header is included without safegaurd.*/
/*MISRA2012_RULE_20_1_JUSTIFICATION: Dio_Memmap.h header included as per
Autosar guidelines. */
#include "Dio_MemMap.h"
static const Dio_ConfigType * const Dio_kConfigPtr = &Dio_Config;
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Dio_Memmap.h header is included without safegaurd.*/
/*MISRA2012_RULE_20_1_JUSTIFICATION: Dio_Memmap.h header included as per
Autosar guidelines. */
#include "Dio_MemMap.h"
#endif /*(DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON)*/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*[[cover parentID={4579FE20-92DA-4848-93DB-7AD4FD35DD50}] [/cover] */
#define DIO_START_SEC_CODE_ASIL_B_GLOBAL
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Dio_Memmap.h header is included without safegaurd.*/
/*MISRA2012_RULE_20_1_JUSTIFICATION: Dio_Memmap.h header included as per
Autosar guidelines. */
#include "Dio_MemMap.h"

#if((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))

/* Function to Report Error*/
static void Dio_lReportError(const uint8 ApiId, const uint8 ErrorId);

#endif

#if((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))

/* INLINE Function to check if ChannelId is valid or not*/
LOCAL_INLINE uint8 Dio_lCheckChannelId(const Dio_ChannelType ChannelId,
                          const Dio_PortType PortNumber, const uint8 PinNumber);

/* INLINE Function to check if GroupIdptr is valid or not*/
LOCAL_INLINE uint8 Dio_lCheckGroupId
( const Dio_ChannelGroupType * const GroupIdPtr);

/* INLINE Function to check if PortId is valid or not*/
LOCAL_INLINE uint8 Dio_lCheckPortId (const Dio_PortType PortId);

/* INLINE Function to check if GroupIdPtr is configured or not*/
LOCAL_INLINE uint8 Dio_lCheckChGrpValue
(const Dio_ChannelGroupType * const GroupIdPtr);

/* INLINE Function to check if the port is
      available or not for the microcontroller*/
LOCAL_INLINE uint32 Dio_lIsPortAvailable31(const uint32 Port);

/* INLINE Function to check if the port is
       available or not for the microcontroller*/
LOCAL_INLINE uint32 Dio_lIsPortAvailable63(const uint32 Port);

/* INLINE Function to check if the port is
       available or not for the microcontroller*/
LOCAL_INLINE uint32 Dio_lIsPortAvailable(const uint32 Port);

/* INLINE Function to check if the
     port is read only or it is writable */
LOCAL_INLINE uint32 Dio_lIsPortReadOnly31(const uint32 Port);

/* INLINE Function to check if the
     port is read only or it is writable */
LOCAL_INLINE uint32 Dio_lIsPortReadOnly63(const uint32 Port);

/* INLINE Function to check if the port
          is read only or it is writable */
LOCAL_INLINE uint32 Dio_lIsPortReadOnly(const uint32 Port);

/* INLINE Function to check if the Pin
          available or not for the input parameter port */
LOCAL_INLINE uint16 Dio_lIsPinAvailable(const uint32 Port, const uint8 Pin);
#endif /* ((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))*/

/* INLINE function to identify the port number from the passed ChannelId */
LOCAL_INLINE Dio_PortType Dio_lGetPortNumber(const Dio_ChannelType ChannelId);

/* INLINE function to extract the Address of Px module */
LOCAL_INLINE Ifx_P *Dio_lGetPortAdr(const Dio_PortType PortNumber);

/* INLINE function to identify the pin number from the passed ChannelId */
LOCAL_INLINE uint8 Dio_lGetPinNumber(const Dio_ChannelType ChannelId);

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Traceability:[cover parentID={2FCCA836-116C-4ec3-9866-ED48D757D432}]       **
**                                                                            **
** Syntax           : Dio_LevelType Dio_ReadChannel                           **
**                    (                                                       **
**                     const Dio_ChannelType ChannelId                        **
**                    )                                                       **
**                                                                            **
** Description :  This Api:                                                   **
**      - returns the level of specified channel                              **
**      - The specified channel can be input or output                        **
**      - returns the physical level of the channel                           **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  : ChannelId - ChannelId whose level to be read            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : RetVal - The Api returns level                          **
**                    of the specified channel                                **
**                                                                            **
*******************************************************************************/

Dio_LevelType Dio_ReadChannel(const Dio_ChannelType ChannelId)
{
  uint32         PinPosition;
  Dio_PortType   PortNumber;
  uint8          PinNumber;
  Dio_LevelType  RetVal;
  const Ifx_P *GetPortAddressPtr;

  /* Return value should be zero for errors*/
  RetVal = (Dio_LevelType)STD_LOW;

  /* GetPortNumber will get the Port Number */
  PortNumber = Dio_lGetPortNumber(ChannelId);
  /* GetPinNumber will get the Pin Number */
  PinNumber = Dio_lGetPinNumber(ChannelId);

  /* [cover parentID={D6CF8A26-846E-41bd-B070-735583623161}]
     Det is Enabled or Safety is Enabled
     [/cover] */

  #if ((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT ==STD_ON))
  uint8 ErrStatus;
  ErrStatus = E_OK;

  /* [cover parentID={78B6E21A-C072-44ff-9DCD-F5FBA4760844}]
     Verify ChannelID
     [/cover] */
  /* [cover parentID={D3D46F48-C883-4029-903D-504C0D98DA08}]
     Check For Channel Id
     [/cover] */

  if(Dio_lCheckChannelId(ChannelId, PortNumber, PinNumber) == (uint8)DIO_ERROR)
  {

    /* The port id passed to the Api is invalid. Report error id
         DIO_E_PARAM_INVALID_PORT_ID to the error hook Api */
    /* [cover parentID={A9221E36-068F-4ce1-9580-D2984C1523D2}]
       Report Error
       [/cover] */
    Dio_lReportError(DIO_SID_READCHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={603FF38D-C496-4f72-BAFE-0A0A3DA18E06}]
     Have all Checked Passed
     [/cover] */
  if(ErrStatus == (uint8)E_OK)
  #endif /*DIO_DEV_ERROR_DETECT == STD_ON*/
  {
    /* GetPortAddressPtr will hold the port address */
    GetPortAddressPtr = Dio_lGetPortAdr(PortNumber);

    /* Get the Pin position */
    PinPosition = ((uint32)DIO_NUMBER_1 << PinNumber);


    /* Read the Channel level and decide the return value */
    /* [cover parentID={D5B9A5B5-0FCB-4e7e-BD3D-3048FD74EB2F}]
       PinPosition Not Low
       [/cover] */
    if ((PinPosition & (uint32)(GetPortAddressPtr->IN.U)) != (uint32)STD_LOW)
    {
      RetVal = (Dio_LevelType)STD_HIGH;
    }
  }
  /* [cover parentID={F2E636E0-8CA6-4fd7-A2A9-5C3BD7911445}]
     Return the Value
     [/cover] */
  return RetVal;
}/* Dio_ReadChannel */


/*******************************************************************************
** Traceability:[cover parentID={2E143AC8-A3EE-4bb0-BAFF-6EA8BC0DA0AA}]       **
**                                                                            **
** Syntax           : void Dio_WriteChannel                                   **
**                    (                                                       **
**                    const Dio_ChannelType ChannelId,                        **
**                     const Dio_LevelType Level                              **
**                    )                                                       **
**                                                                            **
**                                                                            **
** Description :  This Api:                                                   **
**      - sets the specified level for specified channel                      **
**      - Possible levels for channel are STD_HIGH and STD_LOW                **
**      - The real physical level of pin is not                               **
**        modified if the specified channel is configured as input            **
**      - For input channel this Api writes into the output                   **
**        register, so that pin level can be set immediately when direction   **
**        changed by PORT driver                                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x01                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters(in)   : ChannelId - ID of DIO channel                           **
**                    Level - Level to be written                             **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
void Dio_WriteChannel(const Dio_ChannelType ChannelId,
                      const Dio_LevelType Level)
{

  const Ifx_P *GetPortAddressPtr;
  uint32 OmrVal;
  Dio_PortType   PortNumber;
  uint8          PinNumber;
  uint8          Offset;

  OmrVal = DIO_OMR_RESET_BIT;
  Offset = DIO_NUMBER_16;

  /* GetPortNumber will get the Port Number */
  PortNumber = Dio_lGetPortNumber(ChannelId);
  /* GetPinNumber will get the Pin Number */
  PinNumber = Dio_lGetPinNumber(ChannelId);

  /* [cover parentID={59CCA3A3-E3DA-4fce-89C5-38A12781B286}]
     Det is enbled or Safety is Enabled
     [/cover] */
  #if ((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT ==STD_ON))
  
  uint32      PortReadOnly;
  uint8 ErrStatus;
  ErrStatus = E_OK;
  /* [cover parentID={0A70EE06-DF89-405b-BBC5-52B76610249A}]
     Get Read Only Port
     [/cover] */
  PortReadOnly = Dio_lIsPortReadOnly((uint32)PortNumber);
  /* [cover parentID={963C4E08-5B22-4465-9347-708C76E676F5}]
     For Channel Id
     [/cover] */
  /* [cover parentID={7F92A6DB-EF37-47b0-B65A-33993D901BF2}]
     Check for ChannelID
     [/cover] */
  if((Dio_lCheckChannelId(ChannelId, PortNumber, PinNumber) ==
      (uint8)DIO_ERROR) || (PortReadOnly != (uint32)DIO_NUMBER_0))
  {
    /* The channel id passed to the Api is invalid. Report error id.
        DIO_E_PARAM_INVALID_CHANNEL_ID to the error hook Api */

    /* [cover parentID={F6317F92-278C-4501-BC53-02A8BEEB0A91}]
       Report Error
       [/cover] */
    Dio_lReportError(DIO_SID_WRITECHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={9B9B7CD6-F0D7-4548-B082-52B225435AB4}]
     Have all checks Passed
     [/cover] */
  if(ErrStatus == (uint8)E_OK)
  #endif /* DIO_DEV_ERROR_DETECT == STD_ON*/
  {
    /* Decide the value to be written depending
      on the input parameter Level */
    /* [cover parentID={6D6740AD-E184-4a0b-9408-DB950AA309DF}]
       Decide the value to be witten
       [/cover] */
    if (Level != (Dio_LevelType)STD_LOW)
    {
      Offset = DIO_NUMBER_0;
    }

    /* GetPortAddressPtr will hold the port address */
    GetPortAddressPtr = Dio_lGetPortAdr(PortNumber);

    /* Write to the PORT OMR register to reflect at the channel*/
    /* [cover parentID={5D9F71A3-819D-4eb0-B877-F999764818E8}]
       Write to the Channel
       [/cover] */
    Mcal_SetBitAtomic(&(GetPortAddressPtr->OMR),Offset,16,(OmrVal << PinNumber));
  }
  /* MISRA2012_RULE_2_2_JUSTIFICATION:Value assigned to variable
  GetPortAddressPtr is passed to Mcal_SetBitAtomic operation*/
  /* MISRA2012_RULE_2_2_JUSTIFICATION:Value assigned to variable
  OmrVal is passed to Mcal_SetBitAtomic operation*/
  /* MISRA2012_RULE_2_2_JUSTIFICATION:Value assigned to variable
  Offset is passed to Mcal_SetBitAtomic operation*/
}/* Dio_WriteChannel */

/*******************************************************************************
** Traceability:[cover parentID={4EB38A01-F94D-4e46-8CBA-0F0E549CDD4E}]       **
**                                                                            **
** Syntax           : Dio_PortLevelType Dio_ReadPort                          **
**                    (                                                       **
**                     const Dio_PortType PortId                              **
**                    )                                                       **
**                                                                            **
** Description :  This Api:                                                   **
**      - returns the level of specified port                                 **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in):  PortId - Port id whose level to be read                  **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value     : RetVal - The Api returns level                          **
**                    of the specified port                                   **
**                                                                            **
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(const Dio_PortType PortId)
{
  const Ifx_P   *GetPortAddressPtr;
  Dio_PortLevelType  RetVal;

  /* [cover parentID={27DC0E96-0DDD-433a-8245-07EF2D1E1A63}]
     DET is Enabled or Safety is Enabled
     [/cover] */

  #if ((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT ==STD_ON))
  uint8 ErrStatus;
  ErrStatus = E_OK;
  /* Return value should be zero for errors*/
  RetVal = (Dio_PortLevelType)STD_LOW;

  /* [cover parentID={F283A2B8-3B51-4360-87FD-4A12EEA5161B}]
     Verify Port Id
     [/cover] */

  /* [cover parentID={BD6402BA-0071-4a55-98ED-A5F046F56D4C}]
     Check for PortID
     [/cover] */

  if(Dio_lCheckPortId(PortId) == (uint8)DIO_ERROR)
  {

    /* The port id passed to the Api is invalid. Report error id
     DIO_E_PARAM_INVALID_PORT_ID to the error hook Api */
    /* [cover parentID={EAA5B4E6-5EA8-4be8-897B-7993024E5475}]
       Report Error
       [/cover] */
    Dio_lReportError(DIO_SID_READPORT, DIO_E_PARAM_INVALID_PORT_ID);
    ErrStatus = E_NOT_OK;
  }
  /* [cover parentID={EEDD33A5-A37C-4019-B837-20961EA3EF72}]
     Have all Checks Passed
     [/cover] */
  if(ErrStatus == (uint8)E_OK)
  #endif /*DIO_DEV_ERROR_DETECT == STD_ON*/
  {
    GetPortAddressPtr = Dio_lGetPortAdr(PortId);
    /* [cover parentID={EA1BE923-0188-482c-B5C2-82A1E4640CDE}]
       Read Value from the Port
       [/cover] */
    RetVal = ((Dio_PortLevelType)GetPortAddressPtr->IN.U &
              Dio_kMaskAllPortPins[PortId]);
  }
  /* [cover parentID={AF145CB7-62AF-43f9-9A40-6EEB5F272FF6}]
     Return the Read Value
     [/cover] */
  return (RetVal);
}/* Dio_ReadPort */


/*******************************************************************************
** Traceability:[cover parentID={D2AB80C0-4E8B-4a48-BC44-AB5FC27792DA}]       **
**                                                                            **
** Syntax           : void Dio_WritePort                                      **
**                    (                                                       **
**                     const Dio_PortType PortId,                             **
**                     const Dio_PortLevelType Level                          **
**                    )                                                       **
**                                                                            **
**                                                                            **
** Description :  This Api:                                                   **
**      - sets the specified level for specified port                         **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters(in)   : PortId - ID of DIO port                                 **
**                    Level - Level to be written                             **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/

void Dio_WritePort (const Dio_PortType PortId, const  Dio_PortLevelType Level)
{
  const Ifx_P *GetPortAddressPtr;
  /* [cover parentID={0A678F0C-6A6B-4c0e-839B-19AAE20E59C7}]
     Det is Enabled or Safety is Enabled
     [/cover] */
  #if ((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT ==STD_ON))
  
  uint32  PortReadOnly;
  uint8 ErrStatus;
  ErrStatus = E_OK;
  
  /* PortReadOnly will check for Read Only Ports */
  /* [cover parentID={49A0980B-276B-45a6-A280-F65C4158F4C3}]
     Call Dio_IsPortReadOnly
     [/cover] */
  PortReadOnly = Dio_lIsPortReadOnly((uint32)PortId);
  /* [cover parentID={ABFED0B5-B7B3-40e5-ABDB-0084EF6C87F2}]
     Check For Port
     [/cover] */
  /* [cover parentID={5BE793E5-0E7A-4532-8CCB-3C2DE2394F08}]
     If Port is incorrect
     [/cover] */
  if((Dio_lCheckPortId(PortId)
      == (uint8)DIO_ERROR) || (PortReadOnly != (uint32)DIO_NUMBER_0))
  {
    /* The port id passed to the Api is invalid. Report error id
       DIO_E_PARAM_INVALID_PORT_ID to the error hook Api */
    /* [cover parentID={51683A2E-5638-40ed-A6C8-05873E317DBF}]
       Report Error
       [/cover] */
    Dio_lReportError(DIO_SID_WRITEPORT, DIO_E_PARAM_INVALID_PORT_ID);
    ErrStatus = E_NOT_OK;
  }
  /* [cover parentID={7170CAC6-E245-4ccc-8CA8-1D74D32755DA}]
     Have all checks passed
     [/cover] */
  if(ErrStatus == (uint8)E_OK)
  #endif /*DIO_DEV_ERROR_DETECT == STD_ON*/
  {
    /* Write the Level to the Port OUT register
            GetPortAddressPtr will hold the port address */
    /* [cover parentID={74DAB331-7573-4f6c-99D5-2C4067A50D79}]
       Get Port Address and Hold it
       [/cover] */
    GetPortAddressPtr = Dio_lGetPortAdr(PortId);
    /* [cover parentID={91FF9E21-EFE0-4569-9AE1-F210780650AF}]
       Write to the Port
       [/cover] */
    Mcal_SetBitAtomic(&(GetPortAddressPtr->OUT), DIO_NUMBER_0,16,(uint16)Level);

  }
  /* MISRA2012_RULE_2_2_JUSTIFICATION:Value assigned to variable
  GetPortAddressPtr is passed to Mcal_SetBitAtomic operation*/
  /* MISRA2012_RULE_2_7_JUSTIFICATION:Variable Level is passed to
  Mcal_SetBitAtomic operation*/
}/* Dio_WritePort */


/*******************************************************************************
** Traceability:[cover parentID={F36DDC75-C36E-4698-91A0-DDCB86FEBD75}]       **
**                                                                            **
** Syntax           : Dio_PortLevelType Dio_ReadChannelGroup                  **
**                    (                                                       **
**                      const Dio_ChannelGroupType * const ChannelGroupIdPtr  **
**                    )                                                       **
**                                                                            **
** Description :  This Api:                                                   **
**  - returns the level of specified channel group                            **
**  [/cover]                                                                  **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  : ChannelGroupIdPtr -                                     **
**                    pointer to channel group configuration                  **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value     : RetVal - The Api returns level                          **
**                    of the specified channel group                          **
**                                                                            **
*******************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup
( const Dio_ChannelGroupType* const ChannelGroupIdPtr)
{
  const Ifx_P   *GetPortAddressPtr;
  Dio_PortLevelType  RetVal;

  /* [cover parentID={9983D909-3C6D-4c94-9009-93F130372431}]
     Det is Enabled or Safety is Enabled
     [/cover] */

  #if ((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT ==STD_ON))

  uint8 ErrStatus;
  ErrStatus = E_OK;

  /* Return value should be zero for errors*/
  RetVal = (Dio_PortLevelType)STD_LOW;
  /*  [cover parentID={3D6FB53B-C8DB-4bf6-8D0D-66B5091A75A3}]
      Verify GroupId
      [/cover] */

  /*  [cover parentID={D6AA7AB3-0F4F-480d-8EE6-1C6404026E7A}]
      Check for GroupID
      [/cover] */

  if( Dio_lCheckGroupId(ChannelGroupIdPtr) == (uint8)DIO_ERROR)
  {
    /* The group id passed to the Api is invalid. Report error id
         DIO_E_PARAM_INVALID__GROUP to the error hook Api */
    /* [cover parentID={4801209C-8E6E-4add-A591-830CD2141060}]
       Report Error
       [/cover] */
    Dio_lReportError(DIO_SID_READCHANNELGROUP, DIO_E_PARAM_INVALID_GROUP);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={01553059-1114-447e-9EEB-C3805171FE0F}]
     Have all Checks Passed
     [/cover] */
  if(ErrStatus == (uint8)E_OK)
  #endif /* DIO_DEV_ERROR_DETECT == STD_ON*/
  {
    /* GetPortAddressPtr will hold the port address  */
    GetPortAddressPtr = Dio_lGetPortAdr(ChannelGroupIdPtr->port);

    /* [cover parentID={733B3CB2-186F-485d-9F4D-C057A0D238BA}]
       Mask the Value from the Port Address to be read
       [/cover] */

    RetVal = (Dio_PortLevelType)((uint32)GetPortAddressPtr->IN.U &
                                 (uint32)ChannelGroupIdPtr->mask);
    /* [cover parentID={1D39EFAE-369C-4f91-A972-803282E528E1}]
       Allign the values to be read
       [/cover] */
    RetVal = (RetVal >> ChannelGroupIdPtr->offset);
  }
  /* [cover parentID={346DF988-B72F-441d-9246-57CB0A401A60}]
     Return the Level of the ChannelGroup
     [/cover] */
  return (RetVal);
} /* Dio_ReadChannelGroup */


/*******************************************************************************
** Traceability:[cover parentID={46E02FDD-4650-4411-BAA5-F708750A821F}]       **
**                                                                            **
** Syntax           : void Dio_WriteChannelGroup                              **
**                    (                                                       **
**                      const Dio_ChannelGroupType *const ChannelGroupIdPtr   **
**                      Dio_PortLevelType Level                               **
**                    )                                                       **
**                                                                            **
** Description :  This Api:                                                   **
**  - sets the level of specified channel group                               **
**  - The value for all the pins the channel group are set at one shot        **
**  - Other pins of the port and pins that are configured as                  **
**    input remains unchanged                                                 **
**  [/cover]                                                                  **
**                                                                            **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  : ChannelGroupIdPtr -                                     **
**                    pointer to channel group configuration                  **
**                    Level - Sets level of specified channel group           **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
void Dio_WriteChannelGroup
( const Dio_ChannelGroupType * const ChannelGroupIdPtr,
  const Dio_PortLevelType Level)
{

  Ifx_P *GetPortAddressPtr;
  uint32          PortVal;
  uint32          PortResetVal;

  /* [cover parentID={3CA5CBC4-3BDA-45cd-9A28-ECFEF9D7701D}]
     Det is Enabled or Safety is Enabled
     [/cover] */
  #if ((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT ==STD_ON))
  uint8  ErrStatus;
  uint8  DioErrorStatus;
  
  ErrStatus = E_OK;
  /* [cover parentID={A5D86D3E-A74B-477c-84BE-45128301E9D4}]
     If Invalid ChannelGroup
     [/cover] */
  /* [cover parentID={1D325D81-BD2F-4f1b-AF97-62C94394B62E}]
     Verify Group Id
     [/cover] */
  if(Dio_lCheckGroupId(ChannelGroupIdPtr) == (uint8)DIO_ERROR)
  {
    DioErrorStatus = DIO_ERROR;
  }

  /* Check if the port is Analog port for Write operation */
  /* [cover parentID={382F4FCB-4C5B-439d-9357-A2154158A6A3}]
     If Read Only port not Zero
     [/cover] */
  /* [cover parentID={31C3A394-C76B-4763-A4ED-34F6F8A4EE96}]
     Verify Read Only Port
    [/cover] */
  else if (Dio_lIsPortReadOnly((uint32)(ChannelGroupIdPtr->port))
           != (uint32)DIO_NUMBER_0)
  {
    DioErrorStatus = DIO_ERROR;
  }
  else
  {
    DioErrorStatus = DIO_NO_ERROR;
  }
  /* [cover parentID={5E8EACC6-B779-4ba0-8587-78732826E2B1}]
     Check for Status
     [/cover] */
  if (DioErrorStatus == DIO_ERROR)
  {
    /* The group id passed to the Api is invalid. Report error id
          DIO_E_PARAM_INVALID__GROUP to the error hook Api */
    /* [cover parentID={EF0EFB86-DEB2-453d-8AB2-88BE43DE43E8}]
       Report Error
       [/cover] */
    Dio_lReportError(DIO_SID_WRITECHANNELGROUP, DIO_E_PARAM_INVALID_GROUP);
    ErrStatus = (uint8)E_NOT_OK;

  }
  /* [cover parentID={272C597D-86F8-48a7-A27B-9F6E70D48153}]
     Have all Checks passed
     [/cover] */
  if(ErrStatus == (uint8)E_OK)
  #endif /*DIO_DEV_ERROR_DETECT == STD_ON*/
  {
    /* Passed Level is masked as per the configuration */
    /*  Level is shifted by the configured offset */
    /* [cover parentID={2C1D1042-D567-421c-9B6C-162222122D1A}]
       Mask the Value to set the bit
       [/cover] */
    /* PortVal is used to set the bits */
    PortVal = (uint32)(((uint32)Level << (uint32)ChannelGroupIdPtr->offset) & \
                       (uint32) ChannelGroupIdPtr->mask);
    /* [cover parentID={9269F549-B50A-4414-A6E6-2773054576C5}]
       Mask the value to reset the remaining bits
       [/cover] */
    /* PortResetVal is used to reset the bits */
    PortResetVal = ((~PortVal) & ((uint32)ChannelGroupIdPtr->mask));

    /* [cover parentID={D42FD32D-CE91-4004-91AE-43C9E2ACC180}]
       Allign the data to be set
       [/cover] */
    PortVal = (PortVal | (PortResetVal << DIO_NUMBER_16));

    /* GetPortAddressPtr will hold the port address */
    /* [cover parentID={D6E8EE9F-DCFE-4aee-A248-CDD041DC13D4}]
       Get Port Address
       [/cover] */
    GetPortAddressPtr = Dio_lGetPortAdr(ChannelGroupIdPtr->port);
    /* [cover parentID={E9161F6A-BF3D-48c0-B300-9BBF777C0C1B}]
       Update the Channel Group
       [/cover] */
    GetPortAddressPtr->OMR.U = PortVal;
  }
} /* Dio_WriteChannelGroup */


/* Enable / Disable the use of the Api */
/* [cover parentID={17DCE761-49D9-4ca9-A476-D98ACE8298BF}]
   Check FlipChannel is Enabled
   [/cover] */

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID={8A96E708-10AB-415b-BF43-BCF62D23D341}]      **
**                                                                            **
** Syntax           : Dio_LevelType Dio_FlipChannel                           **
**                    (                                                       **
**                      Dio_ChannelType ChannelId                             **
**                    )                                                       **
**                                                                            **
** Description :  This Api: Flip the channel level                            **
**      - returns the inverted level of specified output channel              **
**      - The specified channel is input, API shall have no influence         **
**        on the physical output of the channel                               **
**      - The specified channel is input, API shall have no influence         **
**        on the result of next Read service                                  **
**  [/cover]                                                                  **
**                                                                            **
** Service ID:  0x11                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  : ChannelId - ChannelId whose level to be inverted        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : RetVal - The Api returns the level                      **
**                  of the specified channel after inversion                  **
**                                                                            **
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(const Dio_ChannelType ChannelId)
{
  Ifx_P           *GetPortAddressPtr;
  uint32           OmrVal;
  uint8           PinNumber;
  uint8           PortNumber;
  uint32           PinPosition;
  Dio_LevelType    RetVal;
  const volatile uint8  *IocrRegPtr;

  OmrVal = DIO_OMR_MASK_BIT;

  PortNumber = Dio_lGetPortNumber(ChannelId);
  PinNumber  = Dio_lGetPinNumber(ChannelId);

  /* Check for the validity of symbolic channel ID
       Reported DET if error detected */
  /*  [cover parentID={81C4C43A-7788-4a73-BCF7-01A94BD186D3}]
      Det is Enabled or Safety is Enabled
      [/cover] */

  #if ((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT ==STD_ON))
  uint32      PortReadOnly;
  uint8 ErrStatus;
  
  ErrStatus = E_OK;
  
  /* Return value should be zero for errors*/
  RetVal = (Dio_LevelType)STD_LOW;
  /*  [cover parentID={A419B2D4-06A5-4d49-8498-B38271904669}]
      Calculate Read Only Status
      [/cover] */
  PortReadOnly = Dio_lIsPortReadOnly((uint32)PortNumber);
  
  /*  [cover parentID={8A9FC015-41E4-4000-A9BC-EF4F83F485FD}]
      Check for Channel ID
      [/cover] */
  /*  [cover parentID={34C1CCA4-3EE6-427d-8B03-026FD3290AAE}]
      Verify ChannelId
      [/cover] */
  
  if((Dio_lCheckChannelId(ChannelId, PortNumber, PinNumber) ==
      (uint8)DIO_ERROR) || (PortReadOnly != (uint32)DIO_NUMBER_0))
  {
    /* The channel id passed to the Api is invalid. Report error id.
                DIO_E_PARAM_INVALID_CHANNEL_ID to the error hook Api */

    /* [cover parentID={EAEC7876-029B-4986-8589-F98EE5B8DE74}]
       Report Error
       [/cover] */
    Dio_lReportError(DIO_SID_FLIPCHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    ErrStatus = (uint8)E_NOT_OK;
  }
  
  /* [cover parentID={9362FE94-3BC9-4e9b-A6FB-774E45F36DF3}]
     Have all Checks Passed
     [/cover] */
  if(ErrStatus == (uint8)E_OK)
  #endif /*DIO_DEV_ERROR_DETECT == STD_ON*/
  {
   
    volatile uint32 DummyRead;
    
    /* GetPortAddressPtr will hold the port address */
    GetPortAddressPtr = Dio_lGetPortAdr(PortNumber);
    /* MISRA2012_RULE_11_5_JUSTIFICATION: Conversion from pointer to void to
       pointer to other type is done to calculate 1 Byte data
       for a Pin Number. */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: cast performed between a pointer to
    object type and a pointer to a different object type is done to calculate
    1 Byte data for a Pin Number.*/
    /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
       SFR address calculation and is within allowed range.*/
    /* Get the IOCR0 register address of particular port */
    IocrRegPtr =(const volatile uint8*)((const volatile uint32*)\
                (const volatile void*)GetPortAddressPtr + \
                DIO_PORT_IOCR0_REG_OFFSET);
                  

    /* Get the Pin position */
    PinPosition = ((uint32)DIO_NUMBER_1 << (uint32)PinNumber);
    /*Check the channel is configured as output channel*/
    /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used to
          calculate data for given Pin Number and is within allowed range.*/
    /* [cover parentID={C8DF62DD-CD44-4b95-88B7-6727C0AC308E}]
        Check the Configuration of Channel
         [/cover] */
    if((*(IocrRegPtr + PinNumber) & (uint8)DIO_PORT_DIR_MSK)
        != (uint8)DIO_PORT_PIN_IN)
    {
      OmrVal = (OmrVal << PinNumber);

      /* [cover parentID={B1112551-9C26-47af-9F1C-AA86A729E347}]
          Update the Channel
          [/cover] */
      GetPortAddressPtr->OMR.U = OmrVal;
      
      /*After write to the OMR register, one SPB clock cycle delay is required
      for the pins flipped value to propogate back to IN register. Hence a 
      dummy read of OMR is added to add the SPB clock cycle delay */
      DummyRead = GetPortAddressPtr->OMR.U;
      UNUSED_PARAMETER(DummyRead);
    }
       
        /* [cover parentID={02C5BC82-8241-4e86-97EB-6DB8AFFA8ED5}]
       Read the Channel level to be returned
       [/cover] */
    RetVal = (Dio_LevelType)((PinPosition & (uint32)(GetPortAddressPtr->IN.U))\
                             >> (uint32)PinNumber);
  }
  /* [cover parentID={946ACB5F-29A7-41c6-885D-408D5FD2407A}]
     Return the Value
     [/cover] */
  return RetVal;
}/* Dio_FlipChannel */
#endif /*(DIO_FLIP_CHANNEL_API == STD_ON) */

/* [cover parentID={B2B9AE16-52E9-46b5-9FA6-EDA7D473F3BE}]
   Check VersionInfo Enabled
   [/cover] */
#if (DIO_VERSION_INFO_API == STD_ON)
/*******************************************************************************
** Traceability:[cover parentID= {F37CBFFC-7762-467b-B7A5-8AF16D9DB201}]      **
**                                                                            **
** Syntax :void Dio_GetVersionInfo                                            **
**                    (                                                       **
**                      Std_VersionInfoType * const VersionInfo               **
**                    )                                                       **
**                                                                            **
** Description :  This Api:                                                   **
**   - This Api returns the version information of this module                **
**     The version information include : Module ID, Vendor ID,                **
**     Vendor specific version numbers                                        **
**   - This Api is available if the DIO_VERSION_INFO_API is                   **
**     set ON                                                                 **
**  [/cover]                                                                  **
**                                                                            **
** Service ID:  0x12                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  VersionInfo - Pointer to where to store the             **
**                    version information of this module.                     **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
*******************************************************************************/
/* [cover parentID={C023A192-753C-482f-9EEE-D50FF5D959D7}]
   Dio_GetVersionInfo
   [/cover] */
void Dio_GetVersionInfo(Std_VersionInfoType * const VersionInfo)
{

  /* [cover parentID={B80D52E2-6F3F-42b0-A066-9EC8DE66B63B}]
    Det is Enabled or Safety is Enabled
    [/cover] */
  #if ((DIO_SAFETY_ENABLE == STD_ON)||(DIO_DEV_ERROR_DETECT == STD_ON))

  /* Check for DET: DIO_E_PARAM_POINTER */
  /* [cover parentID={D5D98A08-5CED-4a94-893B-9E8363955F6D}]
     Check Error
     [/cover] */
  if ((VersionInfo) == NULL_PTR)
  {
    /*  Report DIO_E_PARAM_POINTER DET if service called with NULL_PTR */
    /* [cover parentID={1DBFAD1B-8F73-47f6-8B64-6453F708FECD}]
       Report Error
       [/cover] */
    Dio_lReportError(DIO_SID_GETVERSIONINFO, DIO_E_PARAM_POINTER);
  }
  else
  #endif /*DIO_DEV_ERROR_DETECT == STD_ON*/
  {

    /* Vendor ID information */
    /* [cover parentID={FFAF0D49-4F4A-48ea-9D16-74B3CC4FE03C}]
       Update Module_ID,Instance_ID and SW Version
       [/cover] */
    ((Std_VersionInfoType*)(VersionInfo))->vendorID = DIO_VENDOR_ID;
    /*DIO module ID information */
    ((Std_VersionInfoType*)(VersionInfo))->moduleID = DIO_MODULE_ID;
    /*DIO Instance ID information */
    /* DIO module Software major version information */
    ((Std_VersionInfoType*)(VersionInfo))->sw_major_version =
      (uint8)DIO_SW_MAJOR_VERSION;
    /* DIO module Software minor version information */
    ((Std_VersionInfoType*)(VersionInfo))->sw_minor_version =
      (uint8)DIO_SW_MINOR_VERSION;
    /* DIO module Software patch version information */
    ((Std_VersionInfoType*)(VersionInfo))->sw_patch_version =
      (uint8)DIO_SW_PATCH_VERSION;
  }
}
#endif /* #if (DIO_VERSION_INFO_API == STD_ON) */


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/* [cover parentID={63917478-91DF-434f-8C6C-59E511835B77}]
   Check Det  is Enabled
   [/cover] */
#if((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))
/*******************************************************************************
**                                                                            **
** Syntax : LOCAL_INLINE void Dio_lReportError( const uint8 ApiId,            **
**                                          const uint8 ErrorId)              **
**                                                                            **
**                                                                            **
** Service ID:       None                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Reentrant                                                **
**                                                                            **
** Parameters (in):  ApiId - Service ID of the API reporting an error         **
**                   ErrorId - ID of the error reported                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
** Description :    Function to report Safety Error and DET                   **
*                                                                             **
*******************************************************************************/
static void Dio_lReportError(const uint8 ApiId, const uint8 ErrorId)
{
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  Det_ReportError(
    DIO_MODULE_ID,
    DIO_INSTANCE_ID,
    ApiId,
    ErrorId);/* End of report to DET */
  #endif
  #if (DIO_SAFETY_ENABLE == STD_ON)
  Mcal_ReportSafetyError(
    DIO_MODULE_ID,
    DIO_INSTANCE_ID,
    ApiId,
    ErrorId);/* End of report to Safety */

  #endif
}/* Dio_lReportError */
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : uint8 Dio_lCheckChannelId                               **
**                    (                                                       **
**                     const Dio_ChannelType ChannelId,                       **
**                     const Dio_PortType PortNumber,                         **
**                     const uint8 PinNumber                                  **
**                    )                                                       **
**                                                                            **
** Description      : Function to check if ChannelId is valid or not          **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  ChannelId  - ChannelId to be checked                    **
**                    PortNumber - Port Number of ChannelId                   **
**                    PinNumber - Pin Number of ChannelId                     **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : ErrStatus                                               **
**                    DIO_ERROR - denotes ChannelId is valid                  **
**                    DIO_NO_ERROR - denotes ChannelId is invalid             **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint8 Dio_lCheckChannelId(const Dio_ChannelType ChannelId,
                           const Dio_PortType PortNumber, const uint8 PinNumber)
{

  uint32       Index;
  uint32       ConfigIndex;
  uint32       PortAvailable;
  uint32       PinAvailable;
  uint8        ErrStatus;

  ErrStatus = (uint8)DIO_NO_ERROR;
  ConfigIndex = DIO_NUMBER_0;

  /* [cover parentID={A3FAA4D9-94E0-4551-B208-AF2032F87771}]
     ChannelID > MaxPort Pin
     [/cover] */
  /* If the DIO channel ID is greater than the max value of Port pin ID */
  if(ChannelId > (uint16)DIO_MAX_VALID_PORT_PIN_ID)
  {
    ErrStatus = (uint8)DIO_ERROR;
  }
  else
  {

    PortAvailable = Dio_lIsPortAvailable((uint32)PortNumber);
    PinAvailable  = Dio_lIsPinAvailable((uint32)PortNumber, PinNumber);
    /* [cover parentID={13EA46B8-0352-44ab-BF65-000C655745D0}]
       Available Port is Zero or Available Pin is Zero
       [/cover] */
    if( (PortAvailable == (uint32)DIO_NUMBER_0)
        || (PinAvailable == (uint32)DIO_NUMBER_0) )
    {
      ErrStatus = (uint8)DIO_ERROR;
    }
    else
    {
      /* [cover parentID={0BCE364E-2B1F-46d7-9339-7D5AFC719D66}]
         Index Of Configuration
         [/cover] */
      for(Index = (uint32)DIO_NUMBER_0; Index <= (uint32)PortNumber; Index++)
      {
        /* [cover parentID={F2B75736-ECF0-4c2f-8D45-A658E8C73262}]
           Identify Configuration
           [/cover] */
        if(Dio_lIsPortAvailable(Index) != (uint32)DIO_NUMBER_0)
        {
          ConfigIndex++; /* to identify the Index of configuration*/
        }
      }
      /*decremented since the ConfigIndex value is 1 for Index 0*/
      ConfigIndex--;
      /* [cover parentID={AF6C6856-F626-4f56-8CCA-5472851357B3}]
         If Port Not Configured
         [/cover] */
      if(
        Dio_kConfigPtr->Dio_PortChannelIdConfigPtr[ConfigIndex].Dio_PortIdConfig
        == DIO_PORT_NOT_CONFIGURED)
      {
        ErrStatus = (uint8)DIO_ERROR;
      }
      else
      {
        /* [cover parentID={D7C72517-6C6C-4aed-B7FA-63656D4ACC86}]
           Check Configuration Pointer
           [/cover] */
        if(
          ((Dio_kConfigPtr->Dio_PortChannelIdConfigPtr[ConfigIndex].\
            Dio_ChannelConfig) & ((uint16)DIO_NUMBER_1 << (uint16)PinNumber))
          == (uint16)DIO_NUMBER_0)
        {
          ErrStatus = (uint8)DIO_ERROR;
        }
      }
    }
  }

  return (ErrStatus);
}/* Dio_lCheckChannelId */

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : uint8 Dio_lCheckGroupId                                 **
**                    (                                                       **
**                      const Dio_ChannelGroupType * const GroupIdPtr         **
**                    )                                                       **
**                                                                            **
** Parameters (in) :  GroupIdPtr  - Pointer for ChannelGroup to be checked    **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  GroupIdPtr  - Pointer to ChannelGroup to be checked     **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : ErrStatus                                               **
**                    DIO_ERROR - denotes GroupIdPtr is valid                 **
**                    DIO_NO_ERROR - denotes GroupIdPtr is invalid            **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint8 Dio_lCheckGroupId
(
  const Dio_ChannelGroupType * const GroupIdPtr
)
{

  uint8  ErrStatus;

  /* Initialise the Error status to DIO_ERROR */
  ErrStatus = (uint8)DIO_ERROR;
  /* [cover parentID={1231543B-7056-4868-9C42-989E7118912B}]
     Is Parameter Null
     [/cover] */
  /* Check GroupIdPtr for NULL_PTR */
  if (GroupIdPtr != NULL_PTR)
  {
    ErrStatus = Dio_lCheckChGrpValue(GroupIdPtr);
  } /* GroupIdPtr != NULL_PTR */
  return (ErrStatus);

}/* Dio_lCheckGroupId */

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : uint8 Dio_lCheckChGrpValue                              **
**                    (                                                       **
**                      const Dio_ChannelGroupType * const GroupIdPtr         **
**                    )                                                       **
**                                                                            **
**                                                                            **
** Description      : Function to validate GroupIdPtr                         **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  GroupIdPtr  - Pointer for ChannelGroup to be checked    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : ErrStatus                                               **
**                    DIO_ERROR - denotes GroupIdPtr is valid                 **
**                    DIO_NO_ERROR - denotes GroupIdPtr is invalid            **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint8 Dio_lCheckChGrpValue
(
  const Dio_ChannelGroupType * const GroupIdPtr
)
{

  uint32 Index;
  uint8  ErrStatus = DIO_ERROR;


  /* [cover parentID={C3808803-B5CE-409d-8A72-75C1D3DD4AF0}]
     Channel Group Configuration
     [/cover] */
  for(Index = 0U; Index < (Dio_kConfigPtr->Dio_ChannelGroupConfigSize); Index++)
  {
    /* [cover parentID={867658FF-ACFA-4c86-B59C-D95FC16D97B1}]
       Group Identification Pointer
       [/cover] */
    if (GroupIdPtr == &(Dio_kConfigPtr->Dio_ChannelGroupConfigPtr[Index]))
    {
      /*DIO114: channel group is valid within the current configuration*/
      ErrStatus = (uint8)DIO_NO_ERROR;
    }
  }


  return ErrStatus;
}/* Dio_lCheckChGrpValue */

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : uint8 Dio_lCheckPortId                                  **
**                    (                                                       **
**                     const Dio_PortType PortId                              **
**                    )                                                       **
**                                                                            **
** Description      : Function to check if PortId is valid or not             **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  PortId  - Port to be checked                            **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : ErrStatus                                               **
**                    DIO_ERROR - denotes PortId is valid                     **
**                    DIO_NO_ERROR - denotes PortId is invalid                **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint8 Dio_lCheckPortId (const Dio_PortType PortId)
{
  uint32      Index;
  uint32      ConfigIndex;
  uint32      PortAvailable;
  uint8       ErrStatus;

  ErrStatus = (uint8)DIO_NO_ERROR;
  ConfigIndex = 0U;

  PortAvailable = (uint32)Dio_lIsPortAvailable((uint32)PortId);

  /* Check for the validity of symbolic port ID */
  /* [cover parentID={94327A98-1764-443a-A210-F3E30B6367CA}]
     Checdk for Validity of symbolic PortId
     [/cover] */
  if( (PortAvailable == (uint32)0U) )
  {
    ErrStatus = (uint8)DIO_ERROR;
  }
  else
  {
    /* [cover parentID={69B22E69-B4DC-4142-82D9-E8A2F008F412}]
       Identify the Index of configuration
       [/cover] */
    for(Index = (uint32)0U; Index <= (uint32)PortId; Index++)
    {
      /* [cover parentID={C82597CE-E447-489e-BACB-D84CD01B8FA4}]
         Check for Port
         [/cover] */
      if(Dio_lIsPortAvailable(Index) != (uint32)0U)
      {
        ConfigIndex++; /* to identify the Index of configuration*/
      }
    }

    ConfigIndex--;/*decremented since the ConfigIndex value is 1 for Index 0*/
    /* [cover parentID={DC80E749-616F-4375-982F-89EBD013F9CF}]
       Check for Configuration
       [/cover] */
    if(
      Dio_kConfigPtr->Dio_PortChannelIdConfigPtr[ConfigIndex].Dio_PortIdConfig
      == DIO_PORT_NOT_CONFIGURED)
    {
      ErrStatus = (uint8)DIO_ERROR;
    }

  }

  return (ErrStatus);
}/* Dio_lCheckPortId */


/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Dio_lIsPortAvailable31              **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the port is available or not for the microcontroller.        **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Port  - Port to be checked                              **
**                                                                            **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetVal - Value which denotes whether the port is        **
**                    available or not                                        **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Dio_lIsPortAvailable31(const uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(DIO_CHANNEL_BIT_MASK) << (Port)) &
             ((uint32)DIO_PORTS_AVAILABLE_00_31));         
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Dio_lIsPortAvailable63              **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the port is available or not for the microcontroller.        **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Port  - Port to be checked                              **
**                                                                            **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetVal - Value which denotes whether the port is        **
**                    available or not                                        **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Dio_lIsPortAvailable63(const uint32 Port)
{
  uint32 RetVal;

  RetVal = (((uint32)(DIO_CHANNEL_BIT_MASK) << (Port - (uint32)DIO_NUMBER_32)) &
            ((uint32)DIO_PORTS_AVAILABLE_32_63));         
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Dio_lIsPortAvailable                **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the port is available or not for the microcontroller.        **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Port  - Port to be checked                              **
**                                                                            **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetVal - Value which denotes whether the port is        **
**                    available or not                                        **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Dio_lIsPortAvailable(const uint32 Port)
{
  uint32 RetVal;
  /* [cover parentID={68C41933-A848-4640-BF33-302B2B7AB6FA}]
     Is Port Number is greater than 31
     [/cover] */
  RetVal = ((Port > (uint32)DIO_NUMBER_31) ? (Dio_lIsPortAvailable63(Port)) :
            (Dio_lIsPortAvailable31(Port)));         
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Dio_lIsPortReadOnly31               **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the port is read only or it is writable.                     **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Port  - Port to be checked                              **
**                                                                            **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes whether the Port          **
**                    is read only or not                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Dio_lIsPortReadOnly31(const uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(DIO_CHANNEL_BIT_MASK) << (Port)) & \
             ((uint32)DIO_PORTS_READONLY_00_31));         
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Dio_lIsPortReadOnly63               **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the port is read only or it is writable.                     **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Port  - Port to be checked                              **
**                                                                            **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes whether the Port          **
**                    is read only or not                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Dio_lIsPortReadOnly63(const uint32 Port)
{
  uint32 RetVal;

  RetVal = (((uint32)(DIO_CHANNEL_BIT_MASK) <<(Port - (uint32)DIO_NUMBER_32)) & 
            ((uint32)DIO_PORTS_READONLY_32_63));
           
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Dio_lIsPortReadOnly                 **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the port is read only or it is writable.                     **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Port  - Port to be checked                              **
**                                                                            **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes whether the Port          **
**                    is read only or not                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Dio_lIsPortReadOnly(const uint32 Port)
{
  uint32 RetVal;
  /* [cover parentID={81CA48C5-FB00-43d0-91AD-78E3AA367A2F}]
     Is port less than or equal to 31
     [/cover] */
  RetVal = ((Port <= (uint32)DIO_NUMBER_31) ? (Dio_lIsPortReadOnly31(Port)) : \
            (Dio_lIsPortReadOnly63(Port)) );        
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint16 Dio_lIsPinAvailable                 **
**                    (                                                       **
**                     const uint32 Port,                                     **
**                     const uint8 Pin                                        **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the pin is available for port.                               **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  : Port - Port number                                      **
**                    Pin  - Pin to be validated for Port                     **
**                                                                            **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetVal -Value which denotes whether the Pin is present  **
**                    on the Port or not.                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint16 Dio_lIsPinAvailable(const uint32 Port, const uint8 Pin)
{
  uint16 RetVal;

  RetVal =  ( (uint16)((uint32)DIO_CHANNEL_BIT_MASK << (Pin)) & \
              Dio_kMaskAllPortPins[Port] );
  return RetVal;
}
#endif /*(DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : Dio_PortType Dio_lGetPortNumber                         **
**                    (                                                       **
**                     const Dio_ChannelType ChannelId                        **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - extract the port number from pin symbolic ID                           **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:   Reentrant                                                    **
**                                                                            **
** Parameters (in)  : ChannelId -                                             **
**                    Pin Symbolic containing port number                     **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes port number extracted     **
**                    from pin symbolic ID                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE Dio_PortType Dio_lGetPortNumber(const Dio_ChannelType ChannelId)
{
  Dio_PortType RetVal;

  RetVal = (Dio_PortType)((ChannelId & (uint16)DIO_4_TO_11_MASK) \
                            >> (uint16)DIO_PORT_NUM_OFFSET);                       
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax :       Ifx_P * Dio_lGetPortAdr                                     **
**                    (                                                       **
**                     const Dio_PortType PortNumber                          **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - returns the address of P<x> Module                                     **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  uint32 PortNumber                                       **
**                                                                            **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  RetVal - P<x> Module address                            **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE Ifx_P *Dio_lGetPortAdr(const Dio_PortType PortNumber)
{
  Ifx_P *RetVal;
  /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is performed to
   calculate address for a Port Number */
  RetVal = ( ((Ifx_P *)&MODULE_P00 + PortNumber ));
  return(RetVal);

}
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : uint8 Dio_lGetPinNumber                                 **
**                    (                                                       **
**                     const Dio_ChannelType ChannelId                        **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - extract the pin number from pin symbolic ID                            **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  : ChannelId                                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes pin number extracted      **
**                    from pin symbolic ID                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint8 Dio_lGetPinNumber(const Dio_ChannelType ChannelId)
{
  uint8 RetVal;

  RetVal = (uint8)(ChannelId & (uint16)DIO_PIN_LOW4_MASK );
  return(RetVal);
}


#define DIO_STOP_SEC_CODE_ASIL_B_GLOBAL
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Dio_Memmap.h header is included without safegaurd.*/
/*MISRA2012_RULE_20_1_JUSTIFICATION: Dio_Memmap.h header included as per
Autosar guidelines. */
#include "Dio_MemMap.h"
/***************** End of Dio driver module **********************************/
