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
**  FILENAME     : Port.c                                                     **
**                                                                            **
**  VERSION      : 9.0.0                                                      **
**                                                                            **
**  DATE         : 2018-08-30                                                 **
**                                                                            **
**  VARIANT      : Variant PB                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Port Driver source file                                    **
**                                                                            **
**  SPECIFICATION(S) : Specification of Port Driver, AUTOSAR Release 4.2.2    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* [cover parentID={E856B263-08D5-4c7b-A28C-B8E999A614B1},
{AD0B28C9-D316-40a1-ABA7-4CDC9BCABA97}] [/cover] */


/* Inclusion of Port Register structure header file */
#include "IfxPort_reg.h"

/* Global functions like Set/Reset END INIT protection bit,
  Enable/Disable interrupts, Automic write function */
#include "McalLib.h"


/* Own header file, this includes own configuration file also */
#include "Port.h"

/* Conditional Inclusion of Developement Error Tracer File */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/* Include Safety Error header definition */
#if(PORT_SAFETY_ENABLE == STD_ON)
#include "Mcal_SafetyError.h"
#endif

#if (PORT_INIT_API_MODE != PORT_MCAL_SUPERVISOR)
#include "McalLib_OsStub.h"
#endif
/*******************************************************************************
**                          User Mode Supoort Macros                          **
*******************************************************************************/

/* [cover parentID={1A65EADD-AFD0-4845-B2D2-8257E086DD67}] [/cover] */
#if PORT_INIT_API_MODE ==  PORT_MCAL_SUPERVISOR
/* Library APIs  */
/* MISRA2012_RULE_4_9_JUSTIFICATION: Function like macro
 * 'PORT_LIB_INIT_WRITESAFETYENDINITPROTREG'
 * defined for User mode support in code.
 * No side effects foreseen by violating this MISRA rule. */
#define PORT_LIB_INIT_WRITESAFETYENDINITPROTREG(RegAdd,Data)   \
  Mcal_WriteSafetyEndInitProtReg(RegAdd,Data)
/* MISRA2012_RULE_4_9_JUSTIFICATION: Function like macro
* 'PORT_LIB_INIT_WRITESAFETYENDINITPROTREG'
* defined for User mode support in code.
* No side effects foreseen by violating this MISRA rule. */
#define PORT_LIB_INIT_WRITEPERIPENDINITPROTREG(RegAdd,Data) \
  Mcal_WritePeripEndInitProtReg(RegAdd,Data)

#else

/* MISRA2012_RULE_4_9_JUSTIFICATION: Function like macro
 * 'PORT_LIB_INIT_WRITESAFETYENDINITPROTREG'
 * defined for User mode support in code.
 * No side effects foreseen by violating this MISRA rule. */
#define PORT_LIB_INIT_WRITESAFETYENDINITPROTREG(RegAdd,Data)    \
  MCAL_LIB_WRITESAFETYENDINITPROTREG(RegAdd,Data)

/* MISRA2012_RULE_4_9_JUSTIFICATION: Function like macro
* 'PORT_LIB_INIT_WRITEPERIPENDINITPROTREG'
* defined for User mode support in code.
* No side effects foreseen by violating this MISRA rule. */
#define PORT_LIB_INIT_WRITEPERIPENDINITPROTREG(RegAdd,Data) \
  MCAL_LIB_WRITEPERIPENDINITPROTREG(RegAdd,Data)
#endif


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/* Version checks */
/* [cover parentID={D84FCB3F-517B-46fd-BA2F-94925DCBCEEB}] [/cover] */

#ifndef PORT_SW_MAJOR_VERSION
#error "PORT_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef PORT_SW_MINOR_VERSION
#error "PORT_SW_MINOR_VERSION is not defined. "
#endif

#ifndef PORT_SW_PATCH_VERSION
#error "PORT_SW_PATCH_VERSION is not defined. "
#endif

/* Check for Correct inclusion of headers */
#if ( PORT_SW_MAJOR_VERSION != 3U )
#error "PORT_SW_MAJOR_VERSION does not match. "
#endif
#if ( PORT_SW_MINOR_VERSION != 0U )
#error "PORT_SW_MINOR_VERSION does not match. "
#endif

#ifndef PORT_AR_RELEASE_MAJOR_VERSION
#error "PORT_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

#ifndef PORT_AR_RELEASE_MINOR_VERSION
#error "PORT_AR_RELEASE_MINOR_VERSION is not defined."
#endif

#ifndef PORT_AR_RELEASE_REVISION_VERSION
#error "PORT_AR_RELEASE_REVISION_VERSION is not defined."
#endif


#if ( PORT_AR_RELEASE_MAJOR_VERSION != 4U)
#error "PORT_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#if ( PORT_AR_RELEASE_MINOR_VERSION != 2U )
#error "PORT_AR_RELEASE_MINOR_VERSION does not match."
#endif

/* [cover parentID={7D755BBC-2E98-4aaf-B2E7-86E896E303B2} ] [/cover] */
#if (PORT_DEV_ERROR_DETECT == STD_ON)

#ifndef DET_AR_RELEASE_MAJOR_VERSION
#error "DET_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
#error "DET_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#endif

/*******************************************************************************
**                      Private Object Like Macro Definitions                 **
*******************************************************************************/
/*
  Offset definitions for data in Port configuration
*/
/* Initial Control data offset */
#define PORT_DATA_OFS_CTL      (0x0U)
/* Initial level data offset */
#define PORT_DATA_OFS_LEVEL    (0x4U)

/* If pin mode changeable is enabled */
#if (PORT_SET_PIN_MODE_API == STD_ON)
/* Pin mode changeable or not offset */
#define PORT_DATA_OFS_MODE     (0x7U)

#define PORT_OUT_PIN_MASK      (0xC0U)

#endif /* (PORT_SET_PIN_MODE_API) */

/* If Direction changeable is enabled */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/* If pin mode changeable is enabled */
#if (PORT_SET_PIN_MODE_API == STD_ON)
/* Pin direction data offset */
#define PORT_DATA_OFS_DIR      (0x8U)
/* Control data 2 offset */
#define PORT_DATA_OFS_CTL2     (0x9U)

#else
/* Pin direction data offset */
#define PORT_DATA_OFS_DIR      (0x7U)
/* Control data 2 offset */
#define PORT_DATA_OFS_CTL2     (0x8U)

#endif /* (PORT_SET_PIN_MODE_API) */
#endif /* (PORT_SET_PIN_DIRECTION_API) */

/* If pin mode changeable is enabled */
#if (PORT_SET_PIN_MODE_API == STD_ON)

/* If Direction changeable is enabled */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)

/* Emergency data offset */
#define PORT_DATA_OFS_EMER  (0xDU)

#else /* If Direction changeable is disabled */

/* Emergency data offset */
#define PORT_DATA_OFS_EMER  (0x8U)

#endif /* (PORT_SET_PIN_DIRECTION_API) */

#else /* If pin mode changeable is disabled */

/* If Direction changeable is enabled */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)

/* Emergency data offset */
#define PORT_DATA_OFS_EMER  (0xCU)

#else /* If Direction changeable is disabled */

/* Emergency data offset */
#define PORT_DATA_OFS_EMER  (0x7U)

#endif /* (PORT_SET_PIN_DIRECTION_API) */
#endif /* (PORT_SET_PIN_MODE_API) */

#if((PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON))
/* Mask to get direction info from Pin control value */
#define PORT_DIR_MSK           (0x80U)
#endif

/* IOCR0 register offset in Ifx_P */
#define PORT_IOCR0_REG_OFFSET  (0x4U)

/* LPCR register offset in Ifx_P */
#define PORT_LPCR_REG_OFFSET   (0x28U)

/* PCSR register offset in Ifx_P */
#define PORT_PCSR_REG_OFFSET   (0x19U)

/* PDISC register offset in Ifx_P */
#define PORT_PDISC_REG_OFFSET  (0x18U)


/* Status to indicate that PORT is initialized */
#define PORT_INITIALIZED  ((uint8)1)


/* Before Setting the Iocr register, To Check the Port number below
   macro's are used */

#define PORT_PIN_4_7           (0x00F0U)
#define PORT_PIN_8_11          (0x0F00U)
#define PORT_PIN_12_15         (0xF000U)

/* 8-bit mask value from 8th to 15th bit */
#define PORT_PDR1_MASK         (0xFF00U)

#if((PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON))
/* offset value where the port number is present */
#define PORT_NUMBER_OFFSET     (0x4U)

/* lower 8-bit mask value in hex to get the port number */
#define PORT_NUM_LOW8_MASK     (0x000000FFU)

/* lower 4-bit mask value in hex to get the pin number of a port */
#define PORT_PIN_LOW4_MASK     (0x0FU)

#endif


/* general constants */
#define PORT_NUMBER_32         (0x20U)
#define PORT_NUMBER_31         (0x1FU)
#define PORT_CONSTANT_0x01     (0x01U)
#if((PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON))
#define PORT_PIN_DIV           0x4
#define PORT_PIN_IOCR_LEN      0x8
#define PORT_PIN_MUL           0x8
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)
#if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)

/* Available Inverted Port Mask */
#define AVAILABLE_MODE_MASK    ((Port_PinModeType)(0xC7U))

#endif /*(PORT_SET_PIN_MODE_API==STD_ON) */
#endif
/* (PORT_DEV_ERROR_DETECT == STD_ON)*/

/* Maximum port pin number */
#define PORT_PIN_MAX_NUMBER    (0xFU)

/*PortLPCR available */
#define PORT_LPCR_AVAILABLE 0xFFFFU

/*PortPin available */
#define PIN_AVAILABLE 16

/* Shift for IOCR*/
#if (PORT_SET_PIN_MODE_API == STD_ON)
#define  IOCR_VALUE (0x4U)
#endif

/* Pin shift position */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
#define  PIN_SHIFT (0x1U)
#endif

/*mask for Errata*/
#define PORT_14_DISC_DISABLE      (0x0800U)
#if(PORT14_PDISC_MASK == PORT_14_DISC_DISABLE)
#define PORT_LPCR5_COUNTER        (0x5U)
#define PORT_NUM_14               (0xEU)
#define PORT_IOCR_PULLUP_ENABLE   (0x2U)
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
/* Mapping of 16 bit constant */
/* [cover parentID={5713A17A-3FA1-427f-A0B6-89125A17689A}] [/cover] */
/* [cover parentID={566ED99C-0D96-46ac-97BF-E97B04E2C700}] No Callout [/cover]*/
/* [cover parentID={33254E74-FBF6-488c-873C-B77A6484D4C9}] [/cover] */
#define PORT_START_SEC_CONST_ASIL_B_GLOBAL_16
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Port_Memmap.h header is included without safegaurd.*/
#include "Port_MemMap.h"

/* Total pin count for each port, This constant is used during DET check */
static const uint16 Port_kAvailablePins[] =
{
  PORT_AVAILABLE_PINS_PORT0,
  PORT_AVAILABLE_PINS_PORT1,
  PORT_AVAILABLE_PINS_PORT2,
  PORT_AVAILABLE_PINS_PORT3,
  PORT_AVAILABLE_PINS_PORT4,
  PORT_AVAILABLE_PINS_PORT5,
  PORT_AVAILABLE_PINS_PORT6,
  PORT_AVAILABLE_PINS_PORT7,
  PORT_AVAILABLE_PINS_PORT8,
  PORT_AVAILABLE_PINS_PORT9,
  PORT_AVAILABLE_PINS_PORT10,
  PORT_AVAILABLE_PINS_PORT11,
  PORT_AVAILABLE_PINS_PORT12,
  PORT_AVAILABLE_PINS_PORT13,
  PORT_AVAILABLE_PINS_PORT14,
  PORT_AVAILABLE_PINS_PORT15,
  PORT_AVAILABLE_PINS_PORT16,
  PORT_AVAILABLE_PINS_PORT17,
  PORT_AVAILABLE_PINS_PORT18,
  PORT_AVAILABLE_PINS_PORT19,
  PORT_AVAILABLE_PINS_PORT20,
  PORT_AVAILABLE_PINS_PORT21,
  PORT_AVAILABLE_PINS_PORT22,
  PORT_AVAILABLE_PINS_PORT23,
  PORT_AVAILABLE_PINS_PORT24,
  PORT_AVAILABLE_PINS_PORT25,
  PORT_AVAILABLE_PINS_PORT26,
  PORT_AVAILABLE_PINS_PORT27,
  PORT_AVAILABLE_PINS_PORT28,
  PORT_AVAILABLE_PINS_PORT29,
  PORT_AVAILABLE_PINS_PORT30,
  PORT_AVAILABLE_PINS_PORT31,
  PORT_AVAILABLE_PINS_PORT32,
  PORT_AVAILABLE_PINS_PORT33,
  PORT_AVAILABLE_PINS_PORT34,
  PORT_AVAILABLE_PINS_PORT35,
  PORT_AVAILABLE_PINS_PORT36,
  PORT_AVAILABLE_PINS_PORT37,
  PORT_AVAILABLE_PINS_PORT38,
  PORT_AVAILABLE_PINS_PORT39,
  #if(PORT_MAX_NUMBER == 40U)
  PORT_AVAILABLE_PINS_PORT40
  #else
  PORT_AVAILABLE_PINS_PORT40,
  PORT_AVAILABLE_PINS_PORT41
  #endif
};

#define PORT_STOP_SEC_CONST_ASIL_B_GLOBAL_16
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Port_Memmap.h header is included without safegaurd.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Port_Memmap.h header included as per Autosar
   guidelines. */
#include "Port_MemMap.h"

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/* [cover parentID={72DABBEB-F27B-4677-B6B4-B53F634341BA}] [/cover] */
#define PORT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Port_Memmap.h header is included without safegaurd.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Port_Memmap.h header included as per Autosar
   guidelines. */
#include "Port_MemMap.h"

/* To store the Port driver configuration pointer */
static  const Port_ConfigType  *Port_kConfigPtr;

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define PORT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Port_Memmap.h header is included without safegaurd.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Port_Memmap.h header included as per
Autosar  guidelines. */
#include "Port_MemMap.h"

#if ((PORT_DEV_ERROR_DETECT == STD_ON )||(PORT_SAFETY_ENABLE == STD_ON))
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define PORT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Port_Memmap.h header is included without safegaurd.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Port_Memmap.h header included as per
Autosar guidelines. */
#include "Port_MemMap.h"
/* Init Status Variable. It has to be initialized to "0U" after every reset as 0
  represents the deinitialized state */
static uint8 Port_InitStatus;
/* Stop 8 bit variable section */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define PORT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Port_Memmap.h header is included without safegaurd.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Port_Memmap.h header included as per
Autosar guidelines. */
#include "Port_MemMap.h"
#endif

/*[cover parentID={4579FE20-92DA-4848-93DB-7AD4FD35DD50}] [/cover]*/
#define PORT_START_SEC_CODE_ASIL_B_GLOBAL
/*mapping of code and data to specific memory sections via memory mapping file*/
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Port_Memmap.h header is included without safegaurd.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Port_Memmap.h header included as per
Autosar guidelines. */
/*[cover parentID={EA0715EE-3E3C-4aac-A42E-4B5CFC96CEED}] [/cover]*/
#include "Port_MemMap.h"



/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*INLINE function to initialize Port module*/
LOCAL_INLINE void Port_lIOInit(void);

/*INLINE function to initialize Port module*/
LOCAL_INLINE void Port_lPDRInit(void);

/*INLINE function to extract the Address of Px_OUT register */
LOCAL_INLINE Ifx_P *Port_lAdr(uint32 PortNumber);

/*INLINE function to to check if the port
  is available or not for the microcontroller */
LOCAL_INLINE uint32 Port_lIsPortAvailable31(uint32 Port);

/*INLINE function to check if the port
  is available or not for the microcontroller */
LOCAL_INLINE uint32 Port_lIsPortAvailable63(uint32 Port);

/*INLINE function to check if the port is
  available or not for the microcontroller    */
LOCAL_INLINE uint32 Port_lIsPortAvailable(uint32 Port);

/*INLINE function to check if the port is read only or it is writable */
LOCAL_INLINE uint32 Port_lIsPortReadOnly31(uint32 Port);

/*INLINE function to check if the port is read only or it is writable */
LOCAL_INLINE uint32 Port_lIsPortReadOnly63(uint32 Port);

/*INLINE function to check if the port is read only or it is writable*/
LOCAL_INLINE uint32 Port_lIsPortReadOnly(uint32 Port);

/*INLINE function to check if the port pin is
  available or not for the microcontroller      */
LOCAL_INLINE uint16 Port_lIsPinAvailable(uint32 Port, uint32 Pin);

/*INLINE function to check if any of the
  portpin 8-15 is available or not for the micro*/
LOCAL_INLINE uint16 Port_lIsPortPdr1Available(uint32 Port);

/*INLINE function to check if the IOCRx register for the port
   is available or not for the micro */
LOCAL_INLINE uint16 Port_lIsPortIocrAvailable(uint32 Port, uint16 Pin);

#if((PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON))
#if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
/*INLINE function to check if the Pin Parameter */
LOCAL_INLINE uint8 Port_lChkPin
(
  Port_PinType Pin, uint32 PortNo, uint32 PinNo
);
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON)*/
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)
#if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)

/*INLINE function to check the error
  in the Port_SetPinMode Api  */
LOCAL_INLINE uint32 Port_lModeErrChk
(
  uint8 Dir, Port_PinModeType Mode, uint32 ConfigIndex, uint32 PinNumber
);
#endif
/* (PORT_DEV_ERROR_DETECT == STD_ON)*/
#endif
/*(PORT_SET_PIN_MODE_API==STD_ON) */

#if((PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON))
/*INLINE function to extract port number Port_PinType data */
LOCAL_INLINE uint32 Port_lNumber(Port_PinType Pin);

/*INLINE function to extract pin number from Port_PinType data*/
LOCAL_INLINE uint32 Port_lPinNumber(Port_PinType Pin);
#endif

/*INLINE function to to check if the port supports LVDS
   for the microcontroller */
LOCAL_INLINE uint32 Port_lIsPortLVDSAvailable31(uint32 Port);

/*INLINE function to to check if the port supports LVDS
   for the microcontroller */
LOCAL_INLINE uint32 Port_lIsPortLVDSAvailable63(uint32 Port);

/*INLINE function to to check if the port supports LVDS
   for the microcontroller */
LOCAL_INLINE uint32 Port_lIsPortLVDSAvailable(uint32 Port);

/*INLINE function to to check if the port supports PCSR
   for the microcontroller */
LOCAL_INLINE uint32 Port_lIsPortPCSRAvailable31(uint32 Port);

/*INLINE function to to check if the port supports PCSR
   for the microcontroller */
LOCAL_INLINE uint32 Port_lIsPortPCSRAvailable63(uint32 Port);

/*INLINE function to to check if the port supports PCSR
   for the microcontroller */
LOCAL_INLINE uint32 Port_lIsPortPCSRAvailable(uint32 Port);

/*INLINE function to to check if the port supports PDISC
   for the microcontroller */
LOCAL_INLINE uint32 Port_lIsPortPDISCAvailable31(uint32 Port);

/*INLINE function to to check if the port supports PDISC
   for the microcontroller */
LOCAL_INLINE uint32 Port_lIsPortPDISCAvailable63(uint32 Port);

/*INLINE function to to check if the port supports PDISC
   for the microcontroller */
LOCAL_INLINE uint32 Port_lIsPortPDISCAvailable(uint32 Port);

/*INLINE function to to check if the port supports PCSR
   for the microcontroller */
LOCAL_INLINE uint32 Port_lIsPortPinPairAvailable(uint32 PortLPCRvalue);

#if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
/*Local Function to report Safety Error and DET*/
static void Port_lReportError(const uint8 ApiId, const uint8 ErrorId);
#endif

#if(PORT_INIT_CHECK_API==STD_ON)
LOCAL_INLINE Std_ReturnType Port_lPDRCheck(const Port_ConfigType* const ConfigPtr);

LOCAL_INLINE Std_ReturnType Port_lIOnitCheck(const Port_ConfigType* const ConfigPtr);
#endif

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Traceability:[cover parentID={F82C0F6A-6278-481b-8D05-B522AA65EF34}]       **
**                                                                            **
** Syntax : void Port_Init                                                    **
**                    (                                                       **
**                      const Port_ConfigType *const  ConfigPtr               **
**                    )                                                       **
**                                                                            **
** Description : This Api:                                                    **
**   - Initializes all the ports as per configuration                         **
**   - Initializes the whole port structure of MCU                            **
**   - Can be used to initialize and reinitialize the                         **
**     port with different configuration                                      **
**   - Should be called first in order to initialize                          **
**     the port for use                                                       **
**    [/cover]                                                                **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Reentrant                                                  **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to Port configuration               **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
*******************************************************************************/
/* [cover parentID={B728EB0E-7DF1-43a6-BA99-26E5E5AB2820}][/cover] */

void Port_Init ( const Port_ConfigType * const ConfigPtr )
{
  #if (PORT_DEV_ERROR_DETECT == STD_ON )||(PORT_SAFETY_ENABLE == STD_ON)
  uint8                              ErrStatus = E_OK;
  #endif

  /* [cover parentID={6F871482-D2C8-4afb-A935-87C2319D52B2}]
   If DET and SAFETY Error Check is Enabled
  [/cover] */

  #if (PORT_DEV_ERROR_DETECT == STD_ON )||(PORT_SAFETY_ENABLE == STD_ON)
  /* [cover parentID={C28ED7B4-5DAE-4726-83F7-334BABF41846}]
  Check if the input parameter is NULL pointer
  [/cover] */

  if (ConfigPtr == NULL_PTR)
  {
    /* Report PORT_E_INIT_FAILED DET */
    /* [cover parentID={24BA64CA-5C45-4e1d-82B5-7EFC96F508A0},
    {F2DD6BD3-013C-4a22-8732-73DD8E007C43}]
    Report error PORT_E_INIT_FAILED
    [/cover] */
    Port_lReportError(PORT_SID_INIT, PORT_E_INIT_FAILED);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={F52B69B6-0EF6-43ad-8C12-069D84206D26}]
  Have all checks passed?
  [/cover] */
  if(ErrStatus == (uint8)E_OK)
  #endif /*(PORT_DEV_ERROR_DETECT == STD_ON)*/
  {
    /* [cover parentID={3B6B18C3-8A08-4265-B81F-38BF48B7609A}]
    Intitialize all  Port Variables
    [/cover] */
    /* The function Port_Init() shall also initialize all variables
      used by the PORT driver module to an initial state.
      There are no such variables in the port module
    */

    Port_kConfigPtr = ConfigPtr;
    /* Initialise General Purpose I/O Ports and Peripheral I/O Lines */
    /* [cover parentID={C4061DE2-BE40-4247-B2EA-45125A8C94C2}]
     Initialise General Purpose I/O Ports and Peripheral I/O Lines
    [/cover] */

    Port_lIOInit();

    /* [cover parentID={6554EAD4-0747-405a-B40D-904D5321D11A}]
     Set Driver state as Intialized
    [/cover] */
    #if (PORT_DEV_ERROR_DETECT == STD_ON )||(PORT_SAFETY_ENABLE == STD_ON)
    Port_InitStatus = PORT_INITIALIZED;
    #endif
  }
}/* Port_Init */


/* Enable / Disable the use of the function */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/*******************************************************************************
** Traceability:[cover parentID={2795E968-B7CE-458b-A38E-D63D1FC188C2}]       **
**                                                                            **
** Syntax :void Port_SetPinDirection                                          **
**                    (                                                       **
**                      const Port_PinType Pin,                               **
**                      const Port_PinDirectionType Direction                 **
**                    )                                                       **
**                                                                            **
** Description :  This Api:                                                   **
**  - sets the port pin direction during runtime                              **
**  - Is available for parameter Pin                                          **
**    whose direction is configured as changeable during run time             **
**  - Is only available if the pre-compiler switch                            **
**    PORT_SET_PIN_DIRECTION_API is set STD_ON.                               **
** [/cover]                                                                   **
** Service ID:  0x01                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :   Pin - port pin ID whose direction has                  **
**                      to be set                                             **
**                     Direction - port pin direction                         **
**                      to be set                                             **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
*******************************************************************************/
/* [cover parentID={DD6796CD-419A-4189-970F-EC176967EBD0}]
Port_SetPinDirection
[/cover] */
void Port_SetPinDirection(
  const Port_PinType Pin,
  const Port_PinDirectionType Direction
)
{
  /* Each Port Number for the hardware unit  */
  uint32               PortNumber;
  uint32               PinNumber;


  #if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
  uint8                ErrReport;
  #endif /*PORT_DEV_ERROR_DETECT == STD_ON*/
  uint32               ConfigIndex;
  uint32               Index;
  const uint8         *IocrDataPtr;
  volatile uint32      *IocrRegPtr;
  const uint32        *DataPtr;
  Ifx_P               *PortAddressPtr;
  #if (PORT_DEV_ERROR_DETECT == STD_ON )||(PORT_SAFETY_ENABLE == STD_ON)
  uint8                              ErrStatus = E_OK;
  #endif
  /* Check for DET: PORT_E_UNINIT */
  /* [cover parentID={519C69CD-AB3D-42d6-AF95-BC951091AD26}]
  Safety and DET check is ON
  [/cover] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON )||(PORT_SAFETY_ENABLE == STD_ON)

  if (Port_InitStatus != PORT_INITIALIZED)
  {
    /* [cover parentID={728D2C40-6863-43f7-8B78-19FB8BE61441},
       {021083E1-BEAD-46bb-B559-4DA063B6D6A3}]
       Check if Pin is valid
       [/cover] */

    /* Report PORT_E_UNINIT DET if Port initialisation is not done */
    /* [cover parentID={E56C5A05-4008-4a4e-B324-379E94B61979}]
    Report DET
    [/cover] */
    Port_lReportError(PORT_SID_SETPINDIRECTION, PORT_E_UNINIT);
    /* Skip the API functionality and return from the API */
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={DE864396-318F-4c9a-A6C3-3466313D6004}]
  Have all checked passed
  [/cover] */
  if(ErrStatus == (uint8)E_OK)
  #endif /* PORT_DEV_ERROR_DETECT */
  {
    /* Extract the port number and pin number from the Pin Symbolic ID */
    /* [cover parentID={AE6816B0-647B-45c0-9412-F1E7870997AC}]
    Extract Pin Number from Pin symbolic id
    [/cover] */
    PortNumber = (uint32)Port_lNumber(Pin);
    /* [cover parentID={AF149DEE-8562-4a78-A480-54C5EC924D7F}]
    Extract Port Number from Pin symbolic id
    [/cover] */
    PinNumber  = (uint32)Port_lPinNumber(Pin);
    /* [cover parentID={680F23BE-BE75-4381-BB60-DFA81F793974}]
    Safety and DET check is ON
    [/cover] */
    #if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
    /*  Function parameters are checked in the order in which they are
               passed.
    */
    /*  Check if Pin is valid */
    /* [cover parentID={E84A49BC-A223-4ebd-B952-82ED816CC379}]
    Check if Pin is valid
    [/cover] */
    ErrReport = Port_lChkPin(Pin, PortNumber, PinNumber);

    if (ErrReport == (uint8)1U)
    {
      /*Report PORT_E_PARAM_PIN DET if the pin is out of range */
      /* [cover parentID={A873ECB9-A48C-431f-B4D2-B2C2D8F88D41}]
      Report DET PORT_E_PARAM_PIN
      [/cover] */
      Port_lReportError(PORT_SID_SETPINDIRECTION, PORT_E_PARAM_PIN);
      ErrStatus = (uint8)E_NOT_OK;
    }
    /* [cover parentID={069D6832-BF8C-4a96-8CB8-55B552F337DB}]
    Have all check passed
    [/cover] */
    if(ErrStatus == (uint8)E_OK)
    #endif /* PORT_DEV_ERROR_DETECT == STD_ON */
    {
      {
        /* [cover parentID={31152497-8D82-4430-8747-4EB5E38812F5}]
        Check for availble ports
        [/cover] */
        ConfigIndex = 0U;
        /* [cover parentID={8C8E216C-509B-47ac-9A9E-8F3508B8904F}]
        check if port is available
        [/cover] */
        for(Index = 0U; Index < PortNumber; Index++)
        {
          /* [cover parentID={31613E83-6AD8-485c-9BAE-D37E83EB1086}]
          check if port is available
          [/cover] */
          if(Port_lIsPortAvailable(Index) != (uint32)0U)
          {
            ConfigIndex++; /* to identify the Index of configuration*/
          }
        }

        /* Get the config data location for specified Port */
        /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to access configuration 
        data for each port */
        /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration
        data for each port */
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
        configuration address calculation for each port and is within allowed 
        range*/
         DataPtr = (const uint32*)(const void*) ( \
        (Port_kConfigPtr->PortConfigSetPtr) + ConfigIndex);

        /*parameter Pin is valid, check for pin direction changeable DET error */
        /*
        Check if the direction is configured as changeable or not
        */

        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
         configuration address calculation for each port and is within allowed
        range.*/
        /* [cover parentID={A334B935-4BA7-4b2d-9E15-833FC8D28A08}]
        Is the directionof the specified pin configured as changable
        [/cover] */
        if ( ((*(DataPtr + PORT_DATA_OFS_DIR)) & ((uint32)0x01U << PinNumber))
             == (uint32)PORT_PIN_DIRECTION_NOT_CHANGEABLE
           )
        {
          /* [cover parentID={F9F1FB83-95BC-4b2e-A0E0-682C717B488C}]
          Safety and DET check on
          [/cover] */

          #if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
          /* Report PORT_E_DIRECTION_UNCHANGEABLE DET if pin is configured for
             direction not changeable
          */
          /* [cover parentID={5EA89E27-51E4-4224-86DC-7A28BD595F38}]
           Report DET PORT_E_DIRECTION_UNCHANGEABLE
          [/cover] */
          /* [cover parentID={3B687236-2279-44b3-AFDD-85E97281DF7C}]
          Report Port_E_Direction
          [/cover] */
          Port_lReportError(PORT_SID_SETPINDIRECTION, PORT_E_DIRECTION_UNCHANGEABLE);
          #endif /* PORT_DEV_ERROR_DETECT */
        }
        else
        {

          IocrDataPtr = (const uint8*)(DataPtr);
          /* Get Port Address */
          /* [cover parentID={30CB73AA-E6E7-4e75-89B1-3CB01C229116}]
          Get Port Address
          [/cover] */
          PortAddressPtr = Port_lAdr(PortNumber);
          /* Get the IOCR0 register address of particular port */
          /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to calculate SFR address
           for each port */
          /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to calculate SFR address
           for each port */
          /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
                        SFR address calculation and is within allowed range.*/
          IocrRegPtr = ((volatile uint32*)(volatile void*)PortAddressPtr + \
         ((PinNumber / (uint32)PORT_PIN_DIV) + (uint32)PORT_IOCR0_REG_OFFSET));
          /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
            configuration address calculation for each pin and is within allowed
            range.*/
          /* [cover parentID={978123C1-9373-4a8e-8866-21FA2FE9D41E}][/cover] */
          if((*(IocrDataPtr + PinNumber) & (uint8)PORT_DIR_MSK) == (uint8)Direction)
          {
            /* [cover parentID={49EF9B7C-7285-43c7-B045-2D566FDD679E}][/cover] */
            Mcal_SetBitAtomic(IocrRegPtr, \
           ((PinNumber % ((uint32)PORT_PIN_DIV)) * (uint32)PORT_PIN_MUL), \
            PORT_PIN_IOCR_LEN, *(IocrDataPtr + PinNumber));
          }
          else
          {
            /* [cover parentID={E392C2BC-EE42-4d9d-B55F-90876B470B2B}][/cover] */
            Mcal_SetBitAtomic(IocrRegPtr, \
            ((PinNumber % ((uint32)PORT_PIN_DIV)) * (uint32)PORT_PIN_MUL), \
            PORT_PIN_IOCR_LEN, *((const uint8*)(DataPtr + PORT_DATA_OFS_CTL2) \
            + PinNumber));
          }
        }
      }
    }
  }
  /* MISRA2012_RULE_2_2_JUSTIFICATION:Value assigned to variable
         IocrRegPtr is passed to Mcal_SetBitAtomic operation*/
  /* MISRA2012_RULE_8_13_JUSTIFICATION: No side effects foreseen
  by violating this MISRA rule, as the pointer GlbIndexStatusPtr is
  accessed using assembly instruction. */
} /* Port_SetPinDirection */
#endif /* Direction changes allowed / Port_SetPinDirection API is ON */

/*******************************************************************************
** Traceability:  [cover parentID={8E391A13-5734-4f2a-BDEC-0ED98080F44B}]     **
**                                                                            **
** Syntax :   void Port_RefreshPortDirection ( void )                         **
**                                                                            **
** Description :  This Api:                                                   **
**   - refreshes the direction for all the port                               **
**     pins that are configured as direction not changeable during run time   **
** [/cover]                                                                   **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
*******************************************************************************/
void Port_RefreshPortDirection(void)
{
  uint32                LoopCtr;
  /* Each Port Number for the hardware unit  */
  uint32                PortNumber;
  uint32                ConfigIndex;
  #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  /* Direction changeable allowed */
  uint32                DirectionData;
  uint32                PinPos;
  #endif /* PORT_SET_PIN_DIRECTION_API */
  const uint32          *DataPtr;
  const uint8           *IocrDataPtr;
  volatile uint8        *IocrRegPtr;
  Ifx_P *PortAddressPtr;

  #if (PORT_DEV_ERROR_DETECT == STD_ON )||(PORT_SAFETY_ENABLE == STD_ON)
  uint8                              ErrStatus = E_OK;
  #endif

  /* [cover parentID={26108B2E-0030-4583-810D-4F9BD60FB0CA}]
    If DET and SAFETY Error Check is Enabled
  [/cover] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON )||(PORT_SAFETY_ENABLE == STD_ON)
  /* [cover parentID={85D09314-E613-4457-82DD-834629B1861C}]
     Check if the Port is initialized
    [/cover] */
  /* Check for DET: PORT_E_UNINIT */
  if (Port_InitStatus != PORT_INITIALIZED)
  {
    /* [cover parentID={6DCD26C5-5DA2-4cd7-BE4B-0707E60CBA45},
    {021083E1-BEAD-46bb-B559-4DA063B6D6A3}]
     Report error PORT_E_UNINIT
      [/cover] */
    /* Report PORT_E_UNINIT DET if Port initialisation is not done*/
    Port_lReportError(PORT_SID_REFRESHPORTDIR, PORT_E_UNINIT);
    /*  Skip the API functionality and return from the API */
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={64BA028C-EFB8-440b-9F75-D837C37F4334}]
  Have all checks passed?
  [/cover] */
  if(ErrStatus == E_OK)
  #endif /* (PORT_DEV_ERROR_DETECT) == STD_ON*/
  {
    /* Loop from Port 0 till last Port */
    PortNumber = 0U;
    ConfigIndex = 0U;
    /* [cover parentID={E235D887-A3D6-4a3b-928B-544874EA9DDA}]
    Refresh All Ports
    [/cover] */
    do
    {
      /* [cover parentID={048A6B7E-A14B-4a96-88A5-DCB6E57ED548},
      {E06735D6-076F-4a2c-84B7-86E956B7E680}, 
      {E1E7197A-AB3F-46ef-B939-6ED36FB89690}]
      Check if the port is available
      [/cover] */

      if(Port_lIsPortAvailable(PortNumber) != (uint32)0U)
      {
        /* Pointer to the data for the port */
        DataPtr = (const uint32*)(const void*)
                  /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to access 
                  configuration data for each port */
                  /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access 
                  configuration data for each port */
                  /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is 
                  used due to configuration address calculation for each port   
                  and is within allowed range.*/
                  ((Port_kConfigPtr->PortConfigSetPtr) + ConfigIndex);

        /* [cover parentID={10A8B1D3-CACA-4205-9625-D08F224833E0}]
        Are changes in Pin direction allowed
        [/cover] */
        #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
        /* Direction changeable allowed */
        /* Get the direction changeable configuration for all the port pins */
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
        configuration address calculation for each port and is within allowed
        range.*/
        DirectionData = *(DataPtr + PORT_DATA_OFS_DIR);
        #endif /* PORT_SET_PIN_DIRECTION_API == STD_ON*/

        /* Pointer to control data for the first pin */
        /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to access configuration
        data for each port */
        /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration
        data for each port */
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
         configuration address calculation for each port and is within allowed
         range.*/
        IocrDataPtr = (const uint8*)(const void*)(DataPtr + PORT_DATA_OFS_CTL);

        /* Pointer to control register for the first pin */
        /* Get Port Address */
        /* [cover parentID={97F0EB43-CEEA-4e13-9551-78AD7822B738}]
        Get Port Address
        [/cover] */
        PortAddressPtr = Port_lAdr(PortNumber);

        /* Get the IOCR0 register address of particular port */
        IocrRegPtr = (volatile uint8 *)(volatile void*)
                     /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to calculate 
                     SFR address for each port */
                     /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to calculate
                     SFR address for each port */
                     ((volatile uint32 *)(volatile void*)PortAddressPtr + \
                      /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to calculate 
                      SFR address for each port */
                      /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to calculate 
                      SFR address for each port */
                      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
                      SFR address calculation and is within allowed range.*/
                      PORT_IOCR0_REG_OFFSET);
        /* [cover parentID={9D1A197B-09B9-457f-9D5F-088C8BA6BCA7}]
         [/cover] */
        #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
        PinPos = 0x01U;
        #endif /* PORT_SET_PIN_DIRECTION_API */

        /* Start from the first pin */
        LoopCtr = 0U;
        /* [cover parentID={5FEA88DC-BA19-495b-8EC5-239555D42EA6}]
        LoopNode1
        [/cover] */
        do
        {
          if(Port_lIsPinAvailable(PortNumber, LoopCtr) != (uint16)0U)
          {
            /* [cover parentID={C242AA37-ADF0-4b0e-8B99-9F8A896C0FF7}]
            Direction changeable is disabled
            [/cover] */
            /* [cover parentID={95C93A92-7730-4bdc-A8B0-888F6704A177}]
             Direction changeable is enabled
             [/cover] */
            #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
            /* Direction changeable is enabled */
            if((DirectionData & PinPos) == (uint32)PORT_PIN_DIRECTION_NOT_CHANGEABLE)
            {
              /* Direction of the pin cannot be changed during run time */
              /* Write the default value to the control bit fields of the Pin */
              *IocrRegPtr =  *IocrDataPtr;
            }
            #else
            {
              /* Direction changeable is disabled */
              /* Write the default value to the control bit fields of the Pin */
              *IocrRegPtr = *IocrDataPtr;
            }
            #endif /* PORT_SET_PIN_DIRECTION_API */
          }
          /* Increment to point to the next pin in register */
          IocrRegPtr++;
          /* Increment to point to the next pin in configuration set */
          IocrDataPtr++;
          /* [cover parentID={9DE176C3-612D-4210-B034-7755FF5572B8}]
          Write default value to control field bit
          [/cover] */
          /* [cover parentID={6442CCBA-4597-4b82-8518-14B15F0D9914}][/cover] */
          #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
          /* Shift the pin position to next pin */
          /* [cover parentID={ACDC676A-2312-44e2-B88F-8F4BB1AC6BF9}]
          Write Default value to control bit fileld of pin
          [/cover] */
          PinPos = PinPos << PIN_SHIFT;
          #endif /* PORT_SET_PIN_DIRECTION_API */
          /* Loop for each pin in the port */
          LoopCtr++;
        } while (LoopCtr <= (uint32)PORT_PIN_MAX_NUMBER );
        ConfigIndex++;
      }
      PortNumber++;
    } while (PortNumber <= (uint32)PORT_MAX_NUMBER); /* Loop for all the ports */
  }
}/* Port_RefreshPortDirection */

/* Enable / Disable the use of the function */
#if (PORT_SET_PIN_MODE_API == STD_ON)
/*******************************************************************************
** Traceability:[cover parentID={3424D3D4-48B3-4d9a-A769-CC90A3B309FB}]       **
**                                                                            **
** Syntax :void Port_SetPinMode                                               **
**                    (                                                       **
**                      const Port_PinType Pin,                               **
**                      const Port_PinModeType Mode                           **
**                    )                                                       **
**                                                                            **
** Description :  This Api:                                                   **
**   - Sets the port pin mode during runtime.                                 **
**   - This function is available if the PORT_SET_PIN_MODE_API is set ON      **
** [/cover]                                                                   **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :    Pin - port pin ID whose direction has                 **
**                      to be set                                             **
**                      Mode - port pin mode to be set                        **
**                                                                            **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
*******************************************************************************/
/* [cover parentID={DD6796CD-419A-4189-970F-EC176967EBD0}]
Port_SetPinMode
[/cover] */
void Port_SetPinMode(const Port_PinType Pin, const Port_PinModeType Mode)
{
  /* Each Port Number for the hardware unit  */
  uint32           PortNumber;
  uint32           PinNumber;
  #if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
  uint32           ErrMode;
  uint8            ErrReport;
  uint8            Direction;
  #endif
  uint32           ConfigIndex;
  uint32           Index;
  const uint32     *DataPtr;
  volatile uint32  *IocrRegPtr;
  uint8            ReadMode;
  uint8            SetMode;
  Ifx_P           *PortAddressPtr;

  /* [cover parentID={E88E8FD6-6EF8-4b35-8789-E25321923A81},
  {FE1BC003-5F92-447e-966C-3C31F1649F10}]
  Safety and DET Check ON
  [/cover] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON )||(PORT_SAFETY_ENABLE == STD_ON)
  uint8                              ErrStatus = E_OK;
  #endif
  /* [cover parentID={E88E8FD6-6EF8-4b35-8789-E25321923A81}]
  Safety and DET Check ON
  [/cover] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
  /* Report PORT_E_UNINIT DET if Port initialisation is not done
  */
  /* [cover parentID={68AC2E2E-727A-4ed9-8329-5FA09734AA39}]
  Check if Port is not intialized
  [/cover] */
  if (Port_InitStatus != PORT_INITIALIZED)
  {
    /* [cover parentID={039B2EB7-6CF9-4cd0-B539-616E24209F34},
    {728D2C40-6863-43f7-8B78-19FB8BE61441},{021083E1-BEAD-46bb-B559-4DA063B6D6A3}]
     Report DET PORT_E_UNINIT
     [/cover] */
    Port_lReportError(PORT_SID_SETPINMODE, PORT_E_UNINIT);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={20D124CE-1F65-47f6-9186-0E8F84C69F2E}]
  Have all checks passed?
  [/cover] */

  if(ErrStatus == E_OK)
  #endif /* PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Extract the port number and pin number from the Pin Symbolic ID */
    /* [cover parentID={031208B9-77C2-44e2-90F7-C288DD4A08E6}]
    Extract the pin number  from the Pin Symbolic ID
    [/cover] */
    PortNumber = (uint32)Port_lNumber(Pin);
    /* [cover parentID={ABE23C13-9E60-4124-B8A9-DECFB6A3C518}]
    Extract the port number  from the Pin Symbolic ID
    [/cover] */
    PinNumber  = (uint32)Port_lPinNumber(Pin);
    /* [cover parentID={FE1BC003-5F92-447e-966C-3C31F1649F10}]
    Safety and DET Check ON
    [/cover] */
    #if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
    /*  Function parameters are checked in the order in which they are
      passed.
    */
    /* Check if Pin is valid */
    /* [cover parentID={A0A4DB52-61AD-4734-B1C2-49ABBD76F872}]
    Check if Pin is valid
    [/cover] */
    ErrReport = Port_lChkPin(Pin, PortNumber, PinNumber);

    if (ErrReport == (uint8)1U)
    {

      /* [cover parentID={D5FE479C-3B6A-4871-949A-7B7D4BCEC667},
      {728D2C40-6863-43f7-8B78-19FB8BE61441}]
       Report DET PORT_E_PARAM_PIN
      [/cover] */
      /*Report PORT_E_PARAM_PIN DET if the pin is out of range */
      Port_lReportError(PORT_SID_SETPINMODE, PORT_E_PARAM_PIN);
      ErrStatus = (uint8)E_NOT_OK;
    }
    /* [cover parentID={D1C48326-519E-40a7-BF4F-8171CFB5E5DF}]
    Have all checks passed?
    [/cover] */
    if(ErrStatus == (uint8)E_OK)
    #endif

    {
      ConfigIndex = 0U;
      /* [cover parentID={58731E92-3FAD-4cc1-9825-3C42C3ACED3D}]
      Check for available Port
      [/cover] */
      for(Index = 0U; Index < PortNumber; Index++)
      {
        /* [cover parentID={B532B0B2-3AC6-40c2-BD12-B195CB12FAEF}]
        Check if Port is  available
        [/cover] */
        if(Port_lIsPortAvailable(Index) != (uint32)0U)
        {
          ConfigIndex++; /* to identify the Index of configuration*/
        }
      }
      /* Get the config data location for specified Port */
      /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to access configuration data
      for each port */
      /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration data
      for each port */
      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
      configuration address calculation for each port and is within allowed range.*/
      DataPtr = (const uint32*)(const void*) \
      ((Port_kConfigPtr->PortConfigSetPtr) + ConfigIndex);

      /* Get Port Address */
      /* [cover parentID={2AC99FEF-646E-4b2c-B3A4-DF4484F576C0}]
      Get Port Address
      [/cover] */
      PortAddressPtr = Port_lAdr(PortNumber);
      /* Get the IOCR0 register address of particular port */
      /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to calculate SFR address
      for each port */
      /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to calculate SFR address
       for each port */
      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
                    SFR address calculation and is within allowed range.*/
  
      IocrRegPtr = ((volatile uint32*)(volatile void*)PortAddressPtr + \
                    (PinNumber / (uint32)4) + PORT_IOCR0_REG_OFFSET);
      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
      configuration data calculation for each port and is within allowed range.*/
      /* [cover parentID={D519305E-CD8B-436d-8177-8C84F4B33053}]
      Check if mode is invalid
      [/cover] */
      if ((((*(DataPtr + PORT_DATA_OFS_MODE)) & ((uint32)PORT_CONSTANT_0x01  \
      << PinNumber))
           == (uint32)PORT_PIN_MODE_NOT_CHANGEABLE)
         )
      {
        /* [cover parentID={6B6A40CE-F352-41fb-B28C-FA862B043E1C},
        {9ED9E1FD-FDA0-44b6-9E2E-5000A24BED70},]
        Report DET PORT_E_MODE_UNCHANGEABLE
        [/cover] */
        /* [cover parentID={80B05273-FBFF-411b-8564-1A25350606F0}]
        DET Checks or Safety checks enabled
        [/cover] */
        /* Report PORT_E_MODE_UNCHANGEABLE DET if the pin is configured
         as mode not changeable */
        #if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
        Port_lReportError(PORT_SID_SETPINMODE, PORT_E_MODE_UNCHANGEABLE);
        #endif

      }
      else
      {
        /* [cover parentID={20DDBF5B-7556-4271-BE51-C64109F6BFEC}]
        DET Checks or Safety checks enabled
        [/cover] */
        #if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
        SFR data calculation for each pin and is within allowed range.*/
        Direction = *((volatile uint8*)(IocrRegPtr) + (PinNumber % IOCR_VALUE));
        ErrMode = Port_lModeErrChk(Direction, Mode, ConfigIndex, PinNumber);
        if (ErrMode == (uint32)1U)
        {
          /* [cover parentID={6448ED38-EC9B-4411-A0B0-4628AE3D66C5},
          {5DE0A5CB-C343-4aec-8DB2-5FBE7C0D4CFA}]
          Report DET PORT_E_PARAM_INVALID_MODE
          [/cover] */
          /* Report PORT_E_PARAM_INVALID_MODE DET if pin mode is not valid */
          Port_lReportError(PORT_SID_SETPINMODE, PORT_E_PARAM_INVALID_MODE);

        }
        else
        #endif
        {
          /*Read the IOCR register value for the Pin */
          /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
          SFR data calculation for each pin and is within allowed range.*/
          ReadMode = *((volatile uint8*)(IocrRegPtr) + (PinNumber % (IOCR_VALUE)));
          /* Get the IOCR register value for new Mode */
          SetMode = ((ReadMode & (uint8)PORT_OUT_PIN_MASK) | (uint8)Mode);
          /* [cover parentID={92E68909-8F48-407d-BA48-267EFDF6E342}]
          Set the new mode in IOCR register
          [/cover] */
          /* Set the new mode in IOCR register */
          Mcal_SetBitAtomic(IocrRegPtr, (PinNumber % ((uint32)PORT_PIN_DIV)) \
          * (uint32)PORT_PIN_MUL, PORT_PIN_IOCR_LEN, SetMode);
        }
      }

    }
  }
  /* MISRA2012_RULE_2_2_JUSTIFICATION:Value assigned to variable
  SetMode is passed to Mcal_SetBitAtomic operation*/
  /* MISRA2012_RULE_8_13_JUSTIFICATION:IocrRegPtr is declared as volatile.
  Declaring as pointing to const is not necessary*/
}/* Port_SetPinMode */
#endif /* (PORT_SET_PIN_MODE_API == STD_ON) */


/* Enable / Disable the use of the function */
#if (PORT_VERSION_INFO_API == STD_ON)
/*******************************************************************************
** Traceability:[cover parentID={2D85A6DA-805F-4156-9E3F-0E11E7BE2604}]       **
**                                                                            **
** Syntax :void Port_GetVersionInfo                                           **
**                    (                                                       **
**                       Std_VersionInfoType* const versioninfo               **
**                    )                                                       **
**                                                                            **
** Description :  This Api:                                                   **
**   - This function returns the version information of this module           **
**     The version information include : Module ID, Vendor ID,                **
**     Vendor specific version numbers                                        **
**   - This function is available if the PORT_VERSION_INFO_API is             **
**     set ON                                                                 **
**  [/cover]                                                                  **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
**                                                                            **
** Parameters (out):  versioninfo - Pointer to store the                      **
**                    version information of this module.                     **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
*******************************************************************************/

/* [cover parentID={C68DD73A-BA58-4b13-8261-3BBD6DD8045D}]
Retrive the version information of the module
[/cover] */
/* [cover parentID={CE925AA6-2D11-46a5-A4ED-E3D7CF38220B}]
Port_GetVersionInfo
[/cover] */
void Port_GetVersionInfo(Std_VersionInfoType* const versioninfo)
{
  /* [cover parentID={F1B2FC7D-0D47-4bf6-A8CB-788E079F5D5A}]
  If DET and SAFETY Error Check is Enabled
  [/cover] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON )||(PORT_SAFETY_ENABLE == STD_ON)
  uint8                              ErrStatus = E_OK;
  #endif

  #if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
  /* [cover parentID={4F879E61-746A-4e5e-9724-82CD99391085},
  {596C3A26-27A1-4f7a-AE83-9DB7A230E457}]
  Check if the input parameter is NULL pointer
  [/cover] */
  /* Check for DET: PORT_E_PARAM_POINTER */
  if ((versioninfo) == NULL_PTR)
  {
    /* [cover parentID={88D66642-8765-4500-AF00-C99E1DAB1E7C}]
       Report error PORT_E_PARAM_POINTER
       [/cover] */
    /* Report PORT_E_PARAM_POINTER DET if service called with
       NULL_PTR
    */
    Port_lReportError(PORT_SID_GETVERSIONINFO, PORT_E_PARAM_POINTER);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={785EA334-13E9-4b89-94C7-73C6F5BFD253}]
  Have all checks passed?
  [/cover] */
  if(ErrStatus == E_OK)
  #endif /*(PORT_VERSION_INFO_API==STD_ON)&&(PORT_DEV_ERROR_DETECT==STD_ON)*/
  {
    /* [cover parentID={C68DD73A-BA58-4b13-8261-3BBD6DD8045D}]
    Retrive the version information of the module
    [/cover] */
    /* Vendor ID information */
    ((Std_VersionInfoType*)(versioninfo))->vendorID = PORT_VENDOR_ID;
    /* Port module ID information */
    ((Std_VersionInfoType*)(versioninfo))->moduleID = PORT_MODULE_ID;
    /* Port module Software major version information */
    ((Std_VersionInfoType*)(versioninfo))->sw_major_version =
      (uint8)PORT_SW_MAJOR_VERSION;
    /* Port module Software minor version information */
    ((Std_VersionInfoType*)(versioninfo))->sw_minor_version =
      (uint8)PORT_SW_MINOR_VERSION;
    /* Port module Software patch version information */
    ((Std_VersionInfoType*)(versioninfo))->sw_patch_version =
      (uint8)PORT_SW_PATCH_VERSION;
  }
}
#endif /*(PORT_VERSION_INFO_API == STD_ON)*/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax :LOCAL_INLINE void Port_lIOInit(void)                               **
**                                                                            **
** Description :  This INLINE function:                                       **
**   -initializes Port registers                                              **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Port_lIOInit(void)
{
  const uint32            *DataPtr;
  const Port_n_ConfigType *ConfigDataPtr;
  /* Each Port Number for the hardware unit */
  uint32                   PortNumber;
  /* Each Port level for the hardware unit */
  uint32                   PortLevel;
  /* Each Port level for the hardware unit */
  uint32                   EmerStopConf;
  /* Index to identify the port configuration information
  from the configuration array  */
  uint32                   ConfigIndex;
  Ifx_P                   *PortAddressPtr;
  const uint32            *LVDSDataPtr;
  const uint32            *PCSRDataPtr;
  const uint32            *PDISCDataPtr;
  volatile const uint32   *LVDSRegPtr;
  volatile const uint32   *PCSRRegPtr;
  volatile const uint32   *PDISCRegPtr;
  uint32                   counter;


  /* Function call to initialize PDR registers */
  /* [cover parentID={F889D63E-004B-47cc-98F4-647C43A94E70}]
  Initialize PDR registers
  [/cover] */

  Port_lPDRInit();
  ConfigIndex = 0U;

  /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to access configuration data */
  /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration data */
  LVDSDataPtr = (const uint32*)(const void*) \
                (Port_kConfigPtr->Port_LVDSConfigTypePtr);

  /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration data */
  /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to access configuration data */
  PCSRDataPtr = (const uint32*)(const void*)\
                (Port_kConfigPtr->Port_PCSRConfigTypePtr);

  /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to access configuration data */
  /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration data */
  PDISCDataPtr = (const uint32*)(const void*)(Port_kConfigPtr->PDiscSet);
  /* [cover parentID={D5D7B024-C6C2-42ce-B672-F4E7A96B355E}]
  Write P_OUT and IOCR registers for all Ports
  [/cover] */
  /* writing P_OUT and IOCR registers */
  for(PortNumber = (uint32)0U; PortNumber <= (uint32)PORT_MAX_NUMBER; PortNumber++)
  {
    /* [cover parentID={3B7F727B-8DC6-48e8-A3AF-7B1D3554463C}]
    Check if the Port is available
    [/cover] */
    /* [cover parentID={FB4FAE3B-D48D-4544-8A66-3530CA70E831}]
    Is Port Available ?
    [/cover] */
    if(Port_lIsPortAvailable(PortNumber) != (uint32)0U)
    {
      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
      configuration address calculation for each port and is within allowed range.*/
      ConfigDataPtr = (Port_kConfigPtr->PortConfigSetPtr) + ConfigIndex ;

      /* Address of each port configuration */
      /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to access configuration data
      for each port */
      /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration data
      for each port */
      DataPtr = (const uint32 *)(const void*)(ConfigDataPtr);
      /* [cover parentID={539753A5-0E20-4ff6-8130-0AACC3226BC6}]
      Get Port address
      [/cover] */
      PortAddressPtr = Port_lAdr(PortNumber);
      /*
      OUT register is written before IOCR bit field to avoid
      the glitches on the pin
      */
      /* [cover parentID={27484890-FB95-4d48-B051-75AF3ABDD47E}]
      Check For Read Only Port
      [/cover] */
      /* [cover parentID={110E0152-3E23-412d-8616-2CBCAFDA4AFD}]
      Check For Read Only Port
      [/cover] */
      if(Port_lIsPortReadOnly(PortNumber) == (uint32)0U)
      {
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
        configuration data calculation for each port and is within allowed range.*/
        PortLevel = (*(DataPtr + PORT_DATA_OFS_LEVEL));
        PortAddressPtr->OUT.U = (uint32)PortLevel;
      }
      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
      configuration data calculation for each port and is within allowed range.*/
      /* [cover parentID={B16CEA6F-BCC5-43c7-B827-91A30008E176}]
      Configure the Port for Emergency stop
      [/cover] */
      EmerStopConf = (*(DataPtr + PORT_DATA_OFS_EMER));
      /* MISRA2012_RULE_11_3_JUSTIFICATION: Conversion between pointers of
      different object types due to SFR access. */
      /* MISRA2012_RULE_11_8_JUSTIFICATION: Cast does not affect the
      const/volatile properties*/

      PORT_LIB_INIT_WRITEPERIPENDINITPROTREG((uint32*) & (PortAddressPtr->ESR.U), \
                                             EmerStopConf);
      /* [cover parentID={26C66A27-1BE3-4703-95D0-4882A6650331}]
      Update the first set of  IOCR bits
      [/cover] */
      PortAddressPtr->IOCR0.U  = *DataPtr;
      DataPtr++;
      /* [cover parentID={77729584-F9FC-49de-925A-0C8A68591029}]
      Update the IOCR bit feld
      [/cover] */
      /* [cover parentID={714A20D0-2413-4477-A94F-9494BB046A34}]
      Check if  IOCR4  bits is avilable for the Port
      [/cover] */
      if(Port_lIsPortIocrAvailable(PortNumber, (uint16)PORT_PIN_4_7) != (uint16)0U)
      {
        /* [cover parentID={6E9FC89A-4FB8-4802-B770-B975959180BE}]
        Update the second  set of  IOCR bits
        [/cover] */
        PortAddressPtr->IOCR4.U  = *DataPtr;
      }
      DataPtr++;
      /* [cover parentID={9431ECB4-295D-4115-8202-7F5ACA538AF2}]
      Check if IOCR8  bits is avilable for the Port
      [/cover] */
      if(Port_lIsPortIocrAvailable(PortNumber, (uint16)PORT_PIN_8_11) != (uint16)0U)
      {
        /* [cover parentID={178C5145-A9A3-4260-B89D-5CD445E0C467}]
        Update the third set of  IOCR bits
        [/cover] */
        PortAddressPtr->IOCR8.U  = *DataPtr;
      }
      DataPtr++;
      /* [cover parentID={D9F7A37F-E54F-451e-ADAB-E959A6D4B3EF}]
      Check if IOCR12  bits is avilable for the Port
      [/cover] */
      if(Port_lIsPortIocrAvailable(PortNumber, (uint16)PORT_PIN_12_15) != (uint16)0U)
      {
        PortAddressPtr->IOCR12.U = *DataPtr;
      }
      /* [cover parentID={2A9011F1-4A12-4d0d-A327-5FD4C3C08996}]
      Check if Port supports LVDS
      [/cover] */
      if(Port_lIsPortLVDSAvailable(PortNumber) != (uint32)0U)
      {
        /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to calculate SFR address
        for each port */
        /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to calculate SFR address
        for each port */
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
        SFR address calculation and is within allowed range.*/
        LVDSRegPtr  = ((volatile uint32*)(volatile void*)PortAddressPtr + \
                       PORT_LPCR_REG_OFFSET);
        /* [cover parentID={54B20FB1-FE53-4c0d-8157-572AF5B3424B}]
        Checks if the Port Pin Pair for LVDS is available
        [/cover] */
        for(counter = (uint32)0U; (counter < (uint32)PORT_MAX_LPCR_REG);
            counter++)
        {
          /* [cover parentID={1EE0D069-1BB6-4be4-9B85-A8FB2C5A6638}]
          Checks if the Port Pin Pair for LVDS is available
          [/cover] */
          if(Port_lIsPortPinPairAvailable(*LVDSDataPtr) == (uint32)0U)
          {
            /*Fix for errata PORTS_TC.H012 - */
            #if(PORT14_PDISC_MASK == PORT_14_DISC_DISABLE)
            Ifx_P_PDISC DiscReg;
            if((PortNumber == PORT_NUM_14) && (counter == PORT_LPCR5_COUNTER))
            {
              if(1U == Mcal_GetBitAtomic(*LVDSDataPtr, 1, 1))
              {
                DiscReg.U = (P14_PDISC.U) & (~(uint32)(PORT14_PDISC_MASK));
                PORT_LIB_INIT_WRITEPERIPENDINITPROTREG(&P14_PDISC, DiscReg.U);
                P14_IOCR8.B.PC11 = PORT_IOCR_PULLUP_ENABLE;

              }
            }
            #endif

            /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to calculate SFR
            address for each port */
            /* MISRA2012_RULE_1_3_JUSTIFICATION:This rule  violation is agreed
            as we need to store the address passed is in the called function
            in many scenarios.*/
            /* MISRA2012_RULE_11_8_JUSTIFICATION: Cast does not affect
            the const/volatile properties*/
            PORT_LIB_INIT_WRITEPERIPENDINITPROTREG((uint32*)LVDSRegPtr, \
                                                   *LVDSDataPtr);
          }
          LVDSRegPtr++;
          LVDSDataPtr++;
        }
      }
      /* [cover parentID={00ACE833-4BAB-4805-9CFF-13A3C27783BC}]
      Take action depending on whether Port supports PCSR
      [/cover] */
      /* [cover parentID={05CAAD9A-A3DC-47fc-82B3-6E642BA3EE6C}]
       Check if Port supports PCSR
       [/cover] */
      /* [cover parentID={F98F129E-A66D-4d23-9F02-6C9937313727}]
       Take action depending on whether Port supports PDISC
      [/cover] */
      if(Port_lIsPortPCSRAvailable(PortNumber) != (uint32)0U)
      {
        /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to calculate SFR address
        for each port */
        /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to calculate SFR address
        for each port */
        PCSRRegPtr = ((volatile uint32*)(volatile void*)PortAddressPtr +
                      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is 
                      used due to SFR address calculation and is within allowed
                      range.*/
                      PORT_PCSR_REG_OFFSET);
        /* PCSRn */
        /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to calculate SFR address
        for each port */
        /* MISRA2012_RULE_1_3_JUSTIFICATION:This rule  violation is agreed as we
        need to store the address passed is in the called function in many 
        scenarios.*/
        /* MISRA2012_RULE_11_8_JUSTIFICATION: Cast does not affect
         the const/volatile properties*/

        PORT_LIB_INIT_WRITESAFETYENDINITPROTREG((uint32*)PCSRRegPtr, *PCSRDataPtr);
        PCSRDataPtr++;
      }
      /* [cover parentID={70D88098-B0C1-4866-B940-8B460232350A}]
         Check if Port supports PDISC
      [/cover] */
      if(Port_lIsPortPDISCAvailable(PortNumber) != (uint32)0U)
      {
        /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to calculate SFR address
          for each port */
        /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to calculate SFR address
          for each port */
        PDISCRegPtr = ((volatile uint32*)(volatile void*)PortAddressPtr +
                       /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic 
                       is used due to SFR address calculation and is within 
                       allowed range.*/
                       PORT_PDISC_REG_OFFSET);

        /* PDISC */
        /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to calculate SFR address
         for each port */
        /* MISRA2012_RULE_1_3_JUSTIFICATION:This rule  violation is agreed as we
         need to store the address passed is in the called
         function in many scenarios.*/
        /* MISRA2012_RULE_11_8_JUSTIFICATION: Cast does not affect
           the const/volatile properties*/
        PORT_LIB_INIT_WRITEPERIPENDINITPROTREG((uint32 *)PDISCRegPtr, \
                                               *PDISCDataPtr );
        PDISCDataPtr++;
      }
      ConfigIndex++;
    }
  } /* For loop */
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax :LOCAL_INLINE void Port_lPDRInit(void)                              **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - initializes Port PDR registers                                         **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
**Parameters (out):  None                                                     **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Port_lPDRInit(void)
{
  /* Each Port Number for the hardware unit  */
  uint32                  PortNumber;
  /* Index to identify the port configuration information
  from the configuration array  */
  uint32                  ConfigIndex;
  Ifx_P            *PortAddressPtr;

  /* [cover parentID={AB50D951-A1C0-448b-99DE-EA5D2A0179F9}]
  Loop To Configure Port Registers
  [/cover] */
  ConfigIndex = 0U;
  /* Port driver strength is configured in Port PDR0 register */
  /* [cover parentID={905FD984-26E8-4fb2-B472-B5CBCB3293BC}]
  Take action depending on whether Port is Available
  [/cover] */
  for (PortNumber = (uint32)0U; PortNumber <= (uint32)PORT_MAX_NUMBER;
       PortNumber++)
    /* Parameter Port is checked for validity */
  {
    /* [cover parentID={1B381BA8-061B-4edb-A49C-9359ECEE68BA}]
    Check if Port is Available
    [/cover] */
    if(Port_lIsPortAvailable(PortNumber) != (uint32)0U)
    {
      /* [cover parentID={111499FF-49CE-46aa-B9D1-44AF4FAA5AA8}]
      Get port address
      [/cover] */
      PortAddressPtr = Port_lAdr(PortNumber);
      /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration
       data  for each port */
      /* MISRA2012_RULE_11_8_JUSTIFICATION: Cast does not affect the
      const/volatile properties*/
      /* [cover parentID={2D7A1D09-E3DA-407b-9096-883803226046}]
      Initialize Port PDR0 register with Driver Strength 0
      [/cover] */
      PORT_LIB_INIT_WRITEPERIPENDINITPROTREG(( uint32 *) \
                                             &PortAddressPtr->PDR0.U, \
                                             Port_kConfigPtr->PortConfigSetPtr \
                                             [ConfigIndex].DriverStrength0);
      /* [cover parentID={9623618E-924D-4522-99B1-89AEEA26EB02}]
      Check For Available PDR Port
      [/cover] */
      /* [cover parentID={D08048AB-415B-4e0d-8E84-F0DF58E5B4C2}]
      Check if PDR1 is Available for Port
      [/cover] */
      if(Port_lIsPortPdr1Available(PortNumber) != (uint16)0U)
      {
        /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration
         data for each port */
        /* MISRA2012_RULE_11_8_JUSTIFICATION: Cast does not affect the
          const/volatile properties*/
        /* [cover parentID={39547610-8FF7-4f5d-8C8B-711E03CE320F}]
        Initialize Port PDR1 register with Driver Strength 1
        [/cover] */
        PORT_LIB_INIT_WRITEPERIPENDINITPROTREG \
        ((uint32*) &PortAddressPtr->PDR1.U, Port_kConfigPtr->PortConfigSetPtr \
         [ConfigIndex].DriverStrength1);
      }
      ConfigIndex++;
    }
  }/* For loop */
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax :LOCAL_INLINE Ifx_P * Port_lAdr                                     **
**                    (                                                       **
**                      const uint32 PortNumber                               **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - returns the address of P<x> Module                                     **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :   PortNumber - Port number whose address                 **
**                                  needs to be calculated                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  RetVal - P<x> Module address                            **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE Ifx_P * Port_lAdr(const uint32 PortNumber)
{
  Ifx_P *RetVal;
  /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is performed to
  calculate address for a Port Number */
  RetVal = ( (&MODULE_P00 + PortNumber));
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax :LOCAL_INLINE uint32 Port_lIsPortAvailable31                        **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the port is available or not for the microcontroller.        **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :   Port - Port number to be checked                       **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetVal - Value which denotes whether the port is        **
**                    available or not                                        **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortAvailable31(const uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port)) &
             ((uint32)PORTS_AVAILABLE_00_31)
           );
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax :LOCAL_INLINE uint32 Port_lIsPortAvailable63                        **
**                    (                                                       **
**                      const uint32 Port                                     **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the port is available or not for the microcontroller.        **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :   Port - Port number to be checked                       **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetVal - Value which denotes whether the port is        **
**                    available or not                                        **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortAvailable63(const uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port - (uint32)PORT_NUMBER_32)) &
             ((uint32)PORTS_AVAILABLE_32_63)
           );
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax :LOCAL_INLINE uint32 Port_lIsPortAvailable                          **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the port is available or not for the microcontroller.        **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :   Port - Port number to be checked                       **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetVal - Value which denotes whether the port is        **
**                    available or not                                        **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortAvailable(const uint32 Port)
{
  uint32 RetVal;
  /* [cover parentID={5C445631-C50C-4baa-A4DC-364030A53954}]
  Port 31 Available
  [/cover] */

  /* [cover parentID={7C716CF4-1068-4953-B34B-6AF97561368D}]
  Port 63 Available
  [/cover] */

  /* [cover parentID={CF494E3C-EA55-4bac-90AF-7CAAF933E8BC}]
  Is Port Greater than port number 31
  [/cover] */
  RetVal = ((Port > (uint32)PORT_NUMBER_31) ? (Port_lIsPortAvailable63(Port)) :
            (Port_lIsPortAvailable31(Port))
           );
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax :LOCAL_INLINE uint32 Port_lIsPortReadOnly31                         **
**                    (                                                       **
**                      const uint32 Port                                     **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the port is read only or it is writable.                     **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :   Port - Port number to be checked                       **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetVal - Value which denotes whether the port is        **
**                    is read only or not                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortReadOnly31(const uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port)) &
             ((uint32)PORTS_READONLY_00_31)
           );
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax :LOCAL_INLINE uint32 Port_lIsPortReadOnly63                         **
**                    (                                                       **
**                      const uint32 Port                                     **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the port is read only or it is writable.                     **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :   Port - Port number to be checked                       **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetVal - Value which denotes whether the port is        **
**                    is read only or not                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortReadOnly63(const uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port - (uint32)PORT_NUMBER_32)) &
             ((uint32)PORTS_READONLY_32_63)
           );
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax :LOCAL_INLINE uint32 Port_lIsPortReadOnly                           **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the port is read only or it is writable.                     **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :   Port - Port number to be checked                       **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetVal - Value which denotes whether the port is        **
**                    is read only or not                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortReadOnly(const uint32 Port)
{
  uint32 RetVal;
  /* [cover parentID={83301BDA-9DEC-419f-B02D-B4578B2DBD91}]
  Port 31 Readonly
  [/cover] */

  /* [cover parentID={C2A6F94C-D372-4956-BC90-528E09D2DE13}]
  Port 63 ReadOnly
  [/cover] */

  /* [cover parentID={632CAF6E-1BB3-4cc6-9666-2F44B555340E}]
  Is port less than or equal to Port Number 31?
  [/cover] */
  RetVal = ((Port <= (uint32)PORT_NUMBER_31) ? (Port_lIsPortReadOnly31(Port)) :
            (Port_lIsPortReadOnly63(Port))
           );
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint16 Port_lIsPinAvailable                **
**                    (                                                       **
**                      const uint32 Port                                     **
**                      const uint32 Pin                                      **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if the pin is available for port.                               **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Port, Pin - Port and Pin to be checked                 **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : RetVal -Value which denotes whether the Pin is          **
**                     available for the Port or not.                         **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint16 Port_lIsPinAvailable(const uint32 Port, const uint32 Pin)
{
  uint16 RetVal;
  RetVal = (uint16)(((uint32)PORT_CONSTANT_0x01 << (Pin)) &
                    (uint32)(Port_kAvailablePins[(Port)])
                   );
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint16 Port_lIsPortPdr1Available           **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks availablity of PDR1 register for the port  by checking          **
**     if any of the portpin 8 - 15 is available or not for the Port.         **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Port - Port to be checked                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal - Value which denotes whether PDR1 register      **
**                    present for the port or not                             **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint16 Port_lIsPortPdr1Available(const uint32 Port)
{
  uint16 RetVal;

  RetVal = (uint16)(((uint32)(PORT_PDR1_MASK)) &
                    (uint32)(Port_kAvailablePins[(Port)]));
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint16 Port_lIsPortIocrAvailable           **
**                    (                                                       **
**                      const uint32 Port,                                    **
**                      const uint16 Pin                                      **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - checks if IOCR_x register for the port is available or not             **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Port, Pin - Port and Pin to be checked                 **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes whether Iocr_x register   **
**                    is available or not for the Port                        **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint16 Port_lIsPortIocrAvailable(const uint32 Port, const uint16 Pin)
{
  uint16 RetVal;

  RetVal = (uint16)( ((uint32)(Pin)) & (uint32)(Port_kAvailablePins[(Port)]) );
  return(RetVal);
}

/* [cover parentID={DC88B28F-B066-4dc4-AE1E-F818AF563C72}]
DET is ON or Safety is ON
[/cover] */
#if (PORT_SET_PIN_MODE_API == STD_ON)
#if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lModeErrChk                    **
**                    (                                                       **
**                      const uint8 Dir,                                      **
**                      const Port_PinModeType Mode,                          **
**                      const uint32 ConfigIndex,                             **
**                      const uint32 PinNumber                                **
**                    )                                                       **
**                                                                            **
** Description      : This INLINE function:                                   **
**   - Checks for the validity of mode.                                       **
**   - This function is available if the PORT_SET_PIN_MODE_API is set ON and  **
**     PORT_DEV_ERROR_DETECT is set ON                                        **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :   Dir - Current direction of a pin                      **
**                      Mode - port pin mode to be set                        **
**                      ConfigIndex - Array Index                             **
**                      PinNumber - port pin number                           **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : 0 - No error in the pin mode                            **
**                    1 - Error in the pin mode                               **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lModeErrChk
(
  const uint8 Dir, const Port_PinModeType Mode, const uint32 ConfigIndex,
  const uint32 PinNumber
)
{
  uint32 ErrStatus;

  ErrStatus = 0U;


  /* [cover parentID={65841578-2C62-4e98-9B75-1D0A717AC55F}]
  Is Pin Configured as Input
  [/cover] */
  /* parameter Pin is valid, check for the pin valid mode */
  if ((Dir & (uint8)PORT_DIR_MSK) == (uint8)PORT_PIN_IN)
  {
    /* [cover parentID={32605480-8D08-4653-994C-3E5F79D26B08}]
    Is mode set as GPIO
    [/cover] */
    if (Mode != (Port_PinModeType)PORT_PIN_MODE_GPIO)
    {
      ErrStatus = 1U;
    }
  }
  /* [cover parentID={65D53813-A790-48d2-981F-4ABFDA160F2F}]
  Is mode available
  [/cover] */
  else if ( (Mode & AVAILABLE_MODE_MASK) != (uint8)0U)
  {
    ErrStatus = 1U;
  }
  else
  {
    uint32 Position;        /* Variables for determining if the specified*/
    uint32 Mode_supported;  /* mode is supported or not */

    Position = (uint32) Mode >> PORT_IOCR_PC_POS;
    Mode_supported = ((uint32)PORT_CONSTANT_0x01) << Position;
    /* [cover parentID={2ED65F0E-0C08-4fd6-8CF0-5731A2C25FD4}]
    Is mode supported by hardware
    [/cover] */
    if(((uint32)(Port_kConfigPtr-> \
                 PortPinHwSupportedModes[ConfigIndex].U[PinNumber]) &
        Mode_supported ) == (uint32)0U
      )
    {
      ErrStatus = 1U;
    }
  }

  return(ErrStatus);
}
#endif /*(PORT_DEV_ERROR_DETECT == STD_ON)*/
#endif /*(PORT_SET_PIN_MODE_API == STD_ON)*/

#if((PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON))
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lNumber                        **
**                    (                                                       **
**                      const Port_PinType pin                                **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - extract the port number from pin symbolic ID                           **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Pin - Pin symbolic Id                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes port number extracted     **
**                    from pin symbolic ID                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lNumber(const Port_PinType Pin)
{
  uint32 RetVal;
  RetVal = (((uint32)(Pin) >> (uint32)PORT_NUMBER_OFFSET) &
            (uint32)PORT_NUM_LOW8_MASK);
  return(RetVal);
}

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lPinNumber                     **
**                    (                                                       **
**                      const Port_PinType pin                                **
**                    )                                                       **
**                                                                            **
** Description :  This INLINE function:                                       **
**   - extract the pin number from pin symbolic ID                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Pin - Pin symbolic Id                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes pin number extracted      **
**                    from pin symbolic ID                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lPinNumber(const Port_PinType Pin)
{
  uint32 RetVal;
  RetVal = ((uint32)(Pin) & (uint32)PORT_PIN_LOW4_MASK);
  return(RetVal);
}
#endif

#if((PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON))
#if (PORT_DEV_ERROR_DETECT == STD_ON)||(PORT_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint8 Port_lChkPin                         **
**                    (                                                       **
**                      const Port_PinType Pin,                               **
**                      const uint32 PortNo,                                  **
**                      const uint32 PinNo                                    **
**                    )                                                       **
**                                                                            **
** Description      : This INLINE function:                                   **
**   - Checks for the error in Pin parameter.                                 **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Pin -  Pin Symbolic id                                 **
**                     PinNo - portpin number                                 **
**                     PortNo - port number                                   **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : 0 - Portpin is valid                                    **
**                    1 - Portpin is invalid                                  **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint8 Port_lChkPin(const Port_PinType Pin, const uint32 PortNo,
 const uint32 PinNo)
{
  uint8 RetVal;
  uint32 PortReadOnly;
  uint32 PinAvailable;
  uint32 PortAvailable;
  RetVal = 0U;
  /* [cover parentID={38E2CA34-E6F4-46b6-8763-A05BD1DF95D7}]
  Is pin within the range ?
  [/cover] */

  if((uint32)Pin < (uint32)PORT_MAX_PIN_ID)
  {
    /* [cover parentID={1E678276-85F8-47f1-808F-F6C09EAAAE28}]
    Check if the Port is Available
    [/cover] */
    PortAvailable = Port_lIsPortAvailable(PortNo);
    /* [cover parentID={2C8297DF-55BD-4826-9761-3B68EA9533D0}]
    Check if the Port is Read Only
    [/cover] */
    PortReadOnly  = Port_lIsPortReadOnly(PortNo);
    /* [cover parentID={5C34E60D-02DD-4189-9617-3A9D6DE60537}]
    Is Port Available ?
    [/cover] */
    if( PortAvailable != (uint32)0U )
    {
      /* [cover parentID={2C5053DE-3EB5-4f39-BCC3-6F2294B4BFA7}]
      Check if the Pin is Avaialble
      [/cover] */
      PinAvailable  = Port_lIsPinAvailable(PortNo, PinNo);
    }
    else
    {
      /* If Port is not available, then Pin also Not available */
      PinAvailable = (uint32)0U;
    }
    /* [cover parentID={0F80C124-78C4-4b67-834A-2AC7C8884E39}]
    Is Port Read Only Or  Pin not Available ?*/
    if ( ((PortReadOnly != (uint32)0U) || (PinAvailable == (uint32)0U))
       )
    {
      RetVal = 1U;
    }
  }
  else
  {
    RetVal = 1U;
  }
  return(RetVal);
}
#endif
#endif /*(PORT_SET_PIN_DIRECTION_API==STD_ON)||(PORT_SET_PIN_MODE_API==STD_ON)*/

/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lIsPortLVDSAvailable31         **
**                    (                                                       **
**                      const uint32 Port                                     **
**                    )                                                       **
**                                                                            **
** Description      : This INLINE function:                                   **
**   - Checks if the port supports LVDS                                       **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Port - Port to be checked                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes whether Port supports LVDS**
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortLVDSAvailable31(const uint32 Port)
{
  uint32 RetVal;
  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port)) &
             ((uint32)PORTS_LVDS_00_31)
           );
  return(RetVal);
}
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lIsPortLVDSAvailable63         **
**                    (                                                       **
**                      const uint32 Port                                     **
**                    )                                                       **
**                                                                            **
** Description      : This INLINE function:                                   **
**   - Checks if the port supports LVDS                                       **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Port - Port to be checked                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes whether Port supports LVDS**
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortLVDSAvailable63(const uint32 Port)
{
  uint32 RetVal;
  RetVal = (((uint32)(PORT_CONSTANT_0x01) <<
             (Port - (uint32)PORT_NUMBER_32)) &
            ((uint32)PORTS_LVDS_32_63)
           );
  return(RetVal);
}
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lIsPortLVDSAvailable           **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description      : This INLINE function:                                   **
**   - Checks if the port supports LVDS                                       **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Port - Port to be checked                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes whether Port supports LVDS**
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortLVDSAvailable(const uint32 Port)
{
  uint32 RetVal;
  /* [cover parentID={AE46A589-B65C-459f-8163-A97E954810C0}]
  Check LVDS support for ports wih port number between 0 to 31
  [/cover] */
  /* [cover parentID={05BAFEDA-DC67-4f5f-8213-2BBE6789DF8C}]
  Check LVDS support for ports wih port number between 32 to 63
  [/cover] */
  /* [cover parentID={3E89142B-CE48-4c07-97AA-2D2C1D1D5822}]
  Is port greater than port number 31?
  [/cover] */
  RetVal = ((Port > (uint32)PORT_NUMBER_31) ?
            (Port_lIsPortLVDSAvailable63(Port)) :
            (Port_lIsPortLVDSAvailable31(Port))
           );
  return(RetVal);
}
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lIsPortPCSRAvailable31         **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description      : This INLINE function:                                   **
**   - Checks if the port supports PCSR                                       **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Port - Port to be checked                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes whether Port supports PCSR**
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortPCSRAvailable31(const uint32 Port)
{
  uint32 RetVal;
  RetVal = (((uint32)(PORT_CONSTANT_0x01) << (Port)) &
            ((uint32)PORTS_PCSR_00_31)
           );
  return(RetVal);
}
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lIsPortPCSRAvailable63         **
**                    (                                                       **
**                      const uint32 Port                                     **
**                    )                                                       **
**                                                                            **
** Description      : This INLINE function:                                   **
**   - Checks if the port supports PCSR                                       **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Port - Port to be checked                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes whether Port supports PCSR**
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortPCSRAvailable63(const uint32 Port)
{
  uint32 RetVal;
  RetVal = (((uint32)(PORT_CONSTANT_0x01) <<
             (Port - (uint32)PORT_NUMBER_32)) &
            ((uint32)PORTS_PCSR_32_63)
           );
  return(RetVal);
}
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lIsPortPCSRAvailable           **
**                    (                                                       **
**                      const uint32 Port                                     **
**                    )                                                       **
**                                                                            **
** Description      : This INLINE function:                                   **
**   - Checks if the port supports PCSR                                       **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Port - Port to be checked                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes whether Port supports PCSR**
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortPCSRAvailable(const uint32 Port)
{
  uint32 RetVal;
  /* [cover parentID={E1EF6255-238F-40a3-A886-2290D5FBF7BE}]
  Check PCSR support for ports wih port number between 0 to 31
  [/cover] */

  /* [cover parentID={AB03B297-A776-40a3-9EB9-853A56324F5A}]
  Check PCSR support for ports wih port number between 32 to 63
  [/cover] */

  /* [cover parentID={E3104988-DBA1-4ece-8AAD-044BF3F63A33}]
  Is port greater than port number 31?
  [/cover] */
  RetVal = ((Port > (uint32)PORT_NUMBER_31) ?
            (Port_lIsPortPCSRAvailable63(Port)) :
            (Port_lIsPortPCSRAvailable31(Port))
           );
  return(RetVal);
}
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lIsPortPinPairAvailable        **
**                    (                                                       **
**                     const uint32 PortLPCRvalue                             **
**                    )                                                       **
**                                                                            **
** Description      : This INLINE function:                                   **
**   - Checks if the portpinpair for lvds is available                        **
**     for the microcontroller.                                               **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  : PortLPCRvalue - Port LPCR Reg value to be checked       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal - Value which denotes the LVDS configuration     **
**                    for the PortPinPair.                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortPinPairAvailable(const uint32 PortLPCRvalue)
{
  uint32 RetVal;
  RetVal = ( (PortLPCRvalue >> PIN_AVAILABLE) & (uint32)PORT_LPCR_AVAILABLE );
  return(RetVal);
}

#if (PORT_DEV_ERROR_DETECT == STD_ON)|| (PORT_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
**                                                                            **
** Syntax : static void Port_lReportError( const uint8 ApiId,                 **
**                                          const uint8 ErrorId)              **
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
static void Port_lReportError(const uint8 ApiId, const uint8 ErrorId)
{
  /* [cover parentID={054709CF-D078-4a72-8C21-098111AD14C5}]
  Is DEt Enabled
  [/cover] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* [cover parentID={4DB52DC1-D227-424b-AC57-D58D53065A99}]
  Report Error
  [/cover] */
  Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, \
                  ApiId, ErrorId);
  /* End of report to DET */
  #endif
  /* [cover parentID={363CAEEB-D6E7-446b-8CB0-B2A4A195EFDA}]
  Is Safety Enable
  [/cover] */
  #if (PORT_SAFETY_ENABLE == STD_ON)
  Mcal_ReportSafetyError(PORT_MODULE_ID, PORT_INSTANCE_ID, \
                         ApiId, ErrorId);
  /* End of report to Safety */
  #endif
}
#endif
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lIsPortPDISCAvailable          **
**                    (                                                       **
**                      const uint32 Port                                     **
**                    )                                                       **
**                                                                            **
** Description      : This INLINE function:                                   **
**   - Checks if the port supports PDISC                                      **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Port - Port to be checked                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     :RetValue -Value which denotes whether Port supports PDISC**
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortPDISCAvailable(const uint32 Port)
{
  uint32 RetVal;
  /* [cover parentID={A95D65A7-37C1-4713-908E-B66F29DF5F82}]
  Check PDISC support for ports wih port number between 0 to 31
  [/cover] */

  /* [cover parentID={FEBCBC52-A4C1-47f7-A29E-2D3C4F0F1808}]
  Check PDISC support for ports wih port number between 32 to 63
  [/cover] */

  /* [cover parentID={45687500-EEA8-4eb3-A360-0460F0D2E11E}]
  Is port greater than or equal to port number 31?
  [/cover] */
  RetVal = ((Port > (uint32)PORT_NUMBER_31) ?
            (Port_lIsPortPDISCAvailable63(Port)) :
            (Port_lIsPortPDISCAvailable31(Port))
           );
  return(RetVal);
}
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lIsPortPDISCAvailable31        **
**                    (                                                       **
**                     const uint32 Port                                      **
**                    )                                                       **
**                                                                            **
** Description      : This INLINE function:                                   **
**   - Checks if the port supports PDISC                                      **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Port - Port to be checked                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetValue -Value which denotes whether Port supports PDISC**
**                                                                            **
*******************************************************************************/

LOCAL_INLINE uint32 Port_lIsPortPDISCAvailable31(const uint32 Port)
{
  uint32 RetVal;
  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port)) &
             ((uint32)PORTS_PDISC_00_31)
           );
  return(RetVal);
}
/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Port_lIsPortPDISCAvailable63        **
**                    (                                                       **
**                      const uint32 Port                                     **
**                    )                                                       **
**                                                                            **
** Description      : This INLINE function:                                   **
**   - Checks if the port supports PDISC                                      **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in)  :  Port - Port to be checked                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     :RetValue -Value which denotes whether Port supports PDISC**
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Port_lIsPortPDISCAvailable63(const uint32 Port)
{
  uint32 RetVal;
  RetVal = (((uint32)(PORT_CONSTANT_0x01) <<
           (Port - (uint32)PORT_NUMBER_32)) &
           ((uint32)PORTS_PDISC_32_63)
           );
  return(RetVal);
}

#if(PORT_INIT_CHECK_API==STD_ON)
/*******************************************************************************
** Traceability      : [cover parentID={7B5DEFB5-5759-49d1-8475-3278D54022D8} ]
                       [/cover]                                               **
**                                                                            **
** Syntax           :Std_ReturnType Port_InitCheck (const Port_ConfigType*    **
**                   const ConfigPtr)                                         **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   :ConfigPtr - Pointer to Port configuration                **
**                                                                            **
** Parameters (out) :                                                         **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Due to invalid          **
**                      parameters.                                           **
**                                                                            **
** Description      : This API checks the initialization values after PORT is **
**                    initialized. It should be called after Port_Init to check**
**                    the initialization values.                              **
*******************************************************************************/
Std_ReturnType Port_InitCheck (const Port_ConfigType* const ConfigPtr)
{
  Std_ReturnType ErrorFlag = E_NOT_OK;
  Std_ReturnType RetVal = E_OK;
  /* [cover parentID={E902428A-35D9-4dfd-B658-9A18DFD7CB45}]
  ConfigPtr is NULL?
  [/cover] */
  if(ConfigPtr == NULL_PTR)
  {
    RetVal = E_NOT_OK;
  }
  #if ((PORT_DEV_ERROR_DETECT == STD_ON ) \
  ||(PORT_SAFETY_ENABLE == STD_ON))
  else
  {
    /* [cover parentID={C17AFE8A-2945-4c18-B092-47FDEE39024B}]
    Port is Intialized?
    [/cover] */
    if (Port_InitStatus != PORT_INITIALIZED)
    {
      RetVal = E_NOT_OK;
    }

  }
  #endif
  /* [cover parentID={D094A249-D5F6-475b-BF37-6ABADB782148}]
  All checks passed?
  [/cover] */
  if(RetVal == E_OK)
{
  /* [cover parentID={D1522922-812F-4a46-9C76-3A693E6263A7}]
  Call PDR check
  [/cover] */
  ErrorFlag = Port_lPDRCheck(ConfigPtr);
    /* [cover parentID={365139A3-B1A1-431e-9D3A-2DF0D6A8F1DC}]
    If result is E_OK
    [/cover] */
    if(ErrorFlag == E_OK)
    {
      /* [cover parentID={72472CE6-122C-4d65-902F-2E028BAD242C}]
      Call lIOInit check
      [/cover] */
      ErrorFlag = Port_lIOnitCheck(ConfigPtr);
    }

  }
  return ErrorFlag;
}
/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           :Std_ReturnType Port_lPDRCheck (const Port_ConfigType*    **
**                   const ConfigPtr)                                         **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to Port configuration               **
**                                                                            **
** Parameters (out) :                                                         **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Due to invalid          **
**                      parameters.                                           **
**                                                                            **
** Description      : This API checks the initialization values after PORT is **
**                   initialized. It should be called after Port_Init to check**
**                    the initialization values.                              **
*******************************************************************************/
LOCAL_INLINE Std_ReturnType Port_lPDRCheck(const Port_ConfigType* const ConfigPtr)
{
  /* Each Port Number for the hardware unit  */
  uint32                  PortNumber;
  Ifx_P            const *PortAddressPtr;
  uint32                  ConfigIndex;
  uint32 SfrVal;
  uint32 CfgVal;
  volatile uint32 CompareFlag = 0xFFFFFFFFU;
  Std_ReturnType ErrorFlag = E_NOT_OK;
  /* [cover parentID={53EEC855-043E-4456-B3AB-5302A039AECA}]
  Loop Among Available Ports
  [/cover] */
  ConfigIndex = 0U;
  /* [cover parentID={AE95EDF9-336D-4845-A949-BC8507FA06E4}]
  Check for available ports_1
  [/cover] */
  for (PortNumber = (uint32)0U; PortNumber <= (uint32)PORT_MAX_NUMBER; PortNumber++)
  {
    /* [cover parentID={345D0DE6-F794-4fc6-90CA-21BFC217AE1B}]
    If Available Port not equal to zero
    [/cover] */
    /* [cover parentID={345D0DE6-F794-4fc6-90CA-21BFC217AE1B}]
    If Available Port not equal to zero
    [/cover] */
    if(Port_lIsPortAvailable(PortNumber) != (uint32)0U)
    {
      /* [cover parentID={3F9B0CF9-4D0A-4577-95A0-37CE3971A60B}]
      Get Port Address
      [/cover] */
      PortAddressPtr = Port_lAdr(PortNumber);

      SfrVal = PortAddressPtr->PDR0.U;
      CfgVal = ConfigPtr->PortConfigSetPtr [ConfigIndex].DriverStrength0;
      CompareFlag &= ~(SfrVal ^ CfgVal);
      /* [cover parentID={04CB7276-80BB-4436-B294-B6CE9444955D}]
      Check for Available Ports_2
      [/cover] */
      /* [cover parentID={EE726271-930A-43ba-A4F7-F2A19EC9064E}]
      If Available Port not equal to zero
      [/cover] */
      if(Port_lIsPortPdr1Available(PortNumber) != (uint16)0U)
      {

        SfrVal = PortAddressPtr->PDR1.U;
        CfgVal = ConfigPtr->PortConfigSetPtr[ConfigIndex].DriverStrength1;
        CompareFlag &= ~(SfrVal ^ CfgVal);
      }
      ConfigIndex++;
    }

  }
  /* [cover parentID={EB60E0CA-F98A-4a90-96DC-FC24A2497925}]
  Check for Flag
  [/cover] */
  if (CompareFlag != 0xFFFFFFFFU)
  {
    ErrorFlag = E_NOT_OK;
  }
  else
  {
    ErrorFlag = E_OK;
  }
  return ErrorFlag;
}
/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           :Std_ReturnType Port_lPDRCheck (const Port_ConfigType*    **
**                   const ConfigPtr)                                         **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   :ConfigPtr - Pointer to Port configuration                **
**                                                                            **
** Parameters (out) :                                                         **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Due to invalid          **
**                      parameters.                                           **
**                                                                            **
** Description      : This API checks the initialization values after PORT is **
**                   initialized. It should be called after Port_Init to check**
**                    the initialization values.                              **
*******************************************************************************/

LOCAL_INLINE Std_ReturnType Port_lIOnitCheck(const Port_ConfigType* const ConfigPtr)
{
  const Port_n_ConfigType *ConfigDataPtr;
  /* Each Port level for the hardware unit */
  uint32                   EmerStopConf;
  const uint32            *DataPtr;
  Std_ReturnType ErrorFlag = E_NOT_OK;

  Ifx_P                   const *PortAddressPtr;
  /* Each Port Number for the hardware unit */
  uint32                   PortNumber;
  uint32 SfrVal;
  uint32 CfgVal;
  const uint32            *LVDSDataPtr;
  const uint32            *PCSRDataPtr;
  const uint32            *PDISCDataPtr;
  volatile const uint32   *LVDSRegPtr;
  volatile const uint32   *PCSRRegPtr;
  volatile const uint32   *PDISCRegPtr;
  volatile uint32 CompareFlag = 0xFFFFFFFFU;
  /* Index to identify the port configuration information
  from the configuration array  */
  uint32                   ConfigIndex;
  uint32                   counter;
  /* [cover parentID={1A58972A-934B-4579-9BA0-73DE290A3B98}]
  Loop among Available Ports
  [/cover] */
  ConfigIndex = 0U;
  /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration data
  for each port */
  /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to access configuration data */
  LVDSDataPtr = (const uint32*)(const void*)(ConfigPtr->Port_LVDSConfigTypePtr);
  /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration data
  for each port */
  /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to access configuration data */
  PCSRDataPtr = (const uint32*)(const void*)  (ConfigPtr->Port_PCSRConfigTypePtr);
  /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration data
  for each port */
  /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to access configuration data */
  PDISCDataPtr = (const uint32*)(const void*) (ConfigPtr->PDiscSet);
  /* [cover parentID={9FDD7385-47AA-4913-9918-E2C345F6402F}]
  Check For Available Ports
  [/cover] */
  for(PortNumber = (uint32)0U; PortNumber <= (uint32)PORT_MAX_NUMBER ; PortNumber++)
  {
    /* [cover parentID={F70B7330-D368-4523-8648-6EDA997FAB06}]
    If Available Port not equal to zero
    [/cover] */
    if(Port_lIsPortAvailable(PortNumber) != (uint32)0U)
    {
      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
      configuration address calculation for each port and is within allowed range.*/
      ConfigDataPtr = (ConfigPtr->PortConfigSetPtr) + ConfigIndex ;
      /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration data
      for each port */
      /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to access configuration data
      for each port */
      DataPtr = (const uint32 *)(const void*)(ConfigDataPtr);
      /* [cover parentID={64FE7B89-0357-48b9-94DB-23633F4E37CD}]
      Get Port Address
      [/cover] */
      PortAddressPtr = Port_lAdr(PortNumber);
      /* [cover parentID={0852F649-2816-45c5-A612-99950D0C6C76}]
      Check for read only ports
      [/cover] */
      /* [cover parentID={223985C4-2E26-43d6-A501-DD9A64A93DEF}]
      If ReadOnly Port not equal to zero
      [/cover] */
      if(Port_lIsPortReadOnly(PortNumber) == (uint32)0U)
      {
        SfrVal = PortAddressPtr->OUT.U ;
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
        configuration data calculation for each port and is within allowed range.*/
        CfgVal = (*(DataPtr + PORT_DATA_OFS_LEVEL));
        CompareFlag &= ~(SfrVal ^ CfgVal);
      }

      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
      configuration data calculation for each port and is within allowed range.*/
      EmerStopConf = (*(DataPtr + PORT_DATA_OFS_EMER));
      SfrVal = PortAddressPtr->ESR.U;
      CfgVal = EmerStopConf;
      CompareFlag &= ~(SfrVal ^ CfgVal);
      SfrVal = PortAddressPtr->IOCR0.U ;
      CfgVal = *(DataPtr);
      DataPtr++;
      CompareFlag &= ~(SfrVal ^ CfgVal);
      /* [cover parentID={2477DBB6-8164-49f6-9398-7EC5D83849F4}]
      If fisrt set of IOCR is not equal to zero
      [/cover] */
      if(Port_lIsPortIocrAvailable(PortNumber, (uint16)PORT_PIN_4_7) != (uint16)0U)
      {
        SfrVal = PortAddressPtr->IOCR4.U;
        CfgVal = *(DataPtr);
        CompareFlag &= ~(SfrVal ^ CfgVal);
      }
      DataPtr++;
      /* [cover parentID={BC7CE8C3-8254-4e04-AAC9-02E7A859E2A9}]
      If second set of IOCR is not equal to zero
      [/cover] */
      if(Port_lIsPortIocrAvailable(PortNumber, (uint16)PORT_PIN_8_11) != (uint16)0U)
      {
        SfrVal = PortAddressPtr->IOCR8.U;
        CfgVal = *(DataPtr);
        CompareFlag &= ~(SfrVal ^ CfgVal);
      }
      DataPtr++;
      /* [cover parentID={A3AF9558-B526-4d2e-980F-AF369F6A340C}]
      If third set of IOCR is not equal to zero
      [/cover] */
      if(Port_lIsPortIocrAvailable(PortNumber, (uint16)PORT_PIN_12_15) != (uint16)0U)
      {
        SfrVal = PortAddressPtr->IOCR12.U;
        CfgVal = *(DataPtr);
        CompareFlag &= ~(SfrVal ^ CfgVal);
      }
      /* [cover parentID={C84B2C24-2296-4411-94E5-B8806A07E34C}]
      Check for Available LVDS
      [/cover] */
      /* [cover parentID={9DBD42FA-B5D2-49cc-AC36-720BE37AF9A7}]
      If LVDS Port not equal to zero
      [/cover] */
      if(Port_lIsPortLVDSAvailable(PortNumber) != (uint32)0U)
      {
        /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to calculate SFR address
        for each port */
        /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration 
        data for each port */
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
        SFR address calculation and is within allowed range.*/
        /* MISRA2012_RULE_11_8_JUSTIFICATION: Cast does not affect the
        const/volatile properties*/
        LVDSRegPtr  = ((volatile uint32*)(volatile void*)PortAddressPtr \
        + PORT_LPCR_REG_OFFSET);
        /* [cover parentID={A7E42B70-13DF-4658-ABD5-58F8CA46B1AB}]
        Check for LVDS
        [/cover] */
        for(counter = (uint32)0U; (counter < (uint32)PORT_MAX_LPCR_REG);
            counter++)
        {
          /* [cover parentID={9A60ED46-B1E1-4bc0-BD65-9CE89CC35314}]
          If LVDS Pin is available
          [/cover] */
          if(Port_lIsPortPinPairAvailable(*LVDSDataPtr) == (uint32)0U)
          {
            SfrVal = *(LVDSRegPtr);
            CfgVal = *(LVDSDataPtr);
            CompareFlag &= ~(SfrVal ^ CfgVal);
          }
          LVDSRegPtr++;
          LVDSDataPtr++;
        }
      }
      /* [cover parentID={B488AB94-6D94-42e5-8D80-0C648C39AE82}]
      Check for PCSR Ports
      [/cover] */

      /* [cover parentID={B69735DA-9884-4f43-BD56-5B31DB027120}]
      If PCSR Port not equal to zero
      [/cover] */
      /* [cover parentID={960B09E9-B096-4213-AABD-0CFDEAD31235}]
      Check for PDISC Port
      [/cover] */
      /* [cover parentID={BF88175E-977A-4160-84BC-CA4EF25904B7}]
      If PDISC Port not equal to zero
      [/cover] */
      if(Port_lIsPortPCSRAvailable(PortNumber) != (uint32)0U)
      {
        /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration 
        data for each port */
        /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to calculate SFR address
        for each port */
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
        SFR address calculation and is within allowed range.*/
        /* MISRA2012_RULE_11_8_JUSTIFICATION: Cast does not affect the
        const/volatile properties*/
        PCSRRegPtr = ((volatile uint32*)(volatile void*)PortAddressPtr \
        + PORT_PCSR_REG_OFFSET);
        SfrVal = *(PCSRRegPtr);
        CfgVal = *(PCSRDataPtr);
        CompareFlag &= ~(SfrVal ^ CfgVal);
        PCSRDataPtr++;
      }
      if(Port_lIsPortPDISCAvailable(PortNumber) != (uint32)0U)
      { 
        /* MISRA2012_RULE_11_3_JUSTIFICATION: Performed to access configuration
        data for each port */
        /* MISRA2012_RULE_11_5_JUSTIFICATION: Performed to calculate SFR address
        for each port */
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic is used due to
        SFR address calculation and is within allowed range.*/
        /* MISRA2012_RULE_11_8_JUSTIFICATION: Cast does not affect the
        const/volatile properties*/
        PDISCRegPtr = ((volatile uint32*)(volatile void*)PortAddressPtr \
        + PORT_PDISC_REG_OFFSET);
        SfrVal = *(PDISCRegPtr);
        CfgVal = *(PDISCDataPtr);
        CompareFlag &= ~(SfrVal ^ CfgVal);
        PDISCDataPtr++;
      }
      ConfigIndex++;
    }
  }
  if (CompareFlag != 0xFFFFFFFFU)
  {
    ErrorFlag = E_NOT_OK;
  }
  else
  {
    ErrorFlag = E_OK;
  }
  return ErrorFlag;
}
#endif

#define PORT_STOP_SEC_CODE_ASIL_B_GLOBAL
/*mapping of code and data to specific memory sections via memory mapping file*/
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Port_Memmap.h header is included without safegaurd.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Port_Memmap.h header included as per
Autosar guidelines. */
#include "Port_MemMap.h"
