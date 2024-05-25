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
**  FILENAME     : Port.h                                                     **
**                                                                            **
**  VERSION      : 8.0.0                                                      **
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
**  DESCRIPTION  : Port Driver header definition file                         **
**                                                                            **
**  SPECIFICATION(S) : Specification of Port Driver, AUTOSAR Release 4.2.2    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/* [cover parentID={D7726A2C-6661-41d6-9A98-46EF8E4879D4}] [/cover]*/

#ifndef PORT_H
#define PORT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* [cover parentID={AAF7D3BC-A1F6-4e48-8A0D-B8EFFD43B096}] [/cover]*/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "Mcal_Compiler.h"
/* Pre-compile/static configuration parameters for PORT  */
#include "Port_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* [cover parentID={C36182D2-AC03-421b-88C1-48B91AE9317B}] [/cover]*/
/* PORT Vendor ID */
#define PORT_VENDOR_ID                     (17U)
/* PORT Module ID */
#define PORT_MODULE_ID                     (124U)

/* Development error codes */
#if (PORT_DEV_ERROR_DETECT == STD_ON )||(PORT_SAFETY_ENABLE == STD_ON)

/* Service is called with invalid parameter Pin */
#define PORT_E_PARAM_PIN                ((uint8)0x0AU)

/* Init Service is called with NULL configuration pointer */
#define PORT_E_INIT_FAILED              ((uint8)0x0CU)

/* Service is called before Port_Init (Vendor Specific) */
#define PORT_E_UNINIT                   ((uint8)0x0FU)

/* Service is called with NULL_PTR */
#define PORT_E_PARAM_POINTER            ((uint8)0x10U)

/* Service is called for a Pin that is configured as direction
   not changeable during runtime */
#define PORT_E_DIRECTION_UNCHANGEABLE   ((uint8)0x0BU)

/* Service is called for Pin with invalid mode */
#define PORT_E_PARAM_INVALID_MODE       ((uint8)0x0DU)

/* Service is called for a Pin that is configured as mode
   not changeable during runtime */
#define PORT_E_MODE_UNCHANGEABLE        ((uint8)0x0EU)



/*
  Service ID number for all PORT driver services
*/
/* Service ID for Port_Init */
#define PORT_SID_INIT                   ((uint8)0x0U)
/* Service ID for Port_SetPinDirection */
#define PORT_SID_SETPINDIRECTION        ((uint8)0x1U)
/* Service ID for Port_RefreshPortDirection */
#define PORT_SID_REFRESHPORTDIR         ((uint8)0x2U)
/* Service ID for Port_GetVersionInfo */
#define PORT_SID_GETVERSIONINFO         ((uint8)0x3U)
/* Service ID for Port_SetPinMode */
#define PORT_SID_SETPINMODE             ((uint8)0x4U)

#endif /*(PORT_DEV_ERROR_DETECT == STD_ON) */

/* PORT MODULE INSTANCE ID */
#define PORT_INSTANCE_ID                ((uint8)0x0U)

#define PORT_SID_INIT_CHECK                  ((uint8)0x01U)
/*
  Macros required for configuring the PORT driver
*/

/*
  Position of the bit field Pn_IOCR.PC
*/
#define PORT_IOCR_PC_POS                (0x3U)

/*
  Macros to define pin mode i.e. pin functionality
  These are used internally to define other macros
*/
#define  PORT_PIN_MODE_GPIO             (0x00U)
#define  PORT_PIN_MODE_ALT1             (0x08U)
#define  PORT_PIN_MODE_ALT2             (0x10U)
#define  PORT_PIN_MODE_ALT3             (0x18U)
#define  PORT_PIN_MODE_ALT4             (0x20U)
#define  PORT_PIN_MODE_ALT5             (0x28U)
#define  PORT_PIN_MODE_ALT6             (0x30U)
#define  PORT_PIN_MODE_ALT7             (0x38U)

/* Macros to define whether pin direction can be changed
   during runtime or not */
#define  PORT_PIN_DIRECTION_NOT_CHANGEABLE    (0x00U)
#define  PORT_PIN_DIRECTION_CHANGEABLE        (0x01U)

/* Macros to define whether pin mode can be changed
   during runtime or not */
#define  PORT_PIN_MODE_NOT_CHANGEABLE   (0x00U)
#define  PORT_PIN_MODE_CHANGEABLE       (0x01U)

#define  PORT_PIN_EMERGENCY_STOP_DISABLE   (0x00U)
#define  PORT_PIN_EMERGENCY_STOP_ENABLE    (0x01U)

#define PORT_LPCR_DEFAULT              (0xFFFF0000U)

/* Mode of operation */
#define PORT_MCAL_SUPERVISOR                 (0U)
#define PORT_MCAL_USER1                      (1U)


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* [cover parentID={B692440B-7809-488e-B797-0EBC5D6E0320}] */
/* Type definition for numeric id for port pins */
typedef uint16 Port_PinType;
/* [/cover] */

/* Type definition for port pin direction */
/* [cover parentID={42893DBB-5EE7-4426-93C4-1DFDC50FF5D8}] */
typedef enum
{
  PORT_PIN_IN = 0x00U,
  PORT_PIN_OUT = 0x80U
} Port_PinDirectionType;
/* [/cover] */

/* [cover parentID={7227015E-ABC2-4c60-8EBD-1BF3DAB58349}] */
/* Type definition for Port pin mode */
typedef uint8 Port_PinModeType;
/* [/cover] */

/* [cover parentID={5D5FC124-711E-4727-BE2D-F18113C5AF18}] */
/* structure definition for PORT n input output control register Pn_IOCRx */
typedef struct
{

  uint8 PC0;      /* Pin 0  control */
  uint8 PC1;      /* Pin 1  control */
  uint8 PC2;      /* Pin 2  control */
  uint8 PC3;      /* Pin 3  control */
  uint8 PC4;      /* Pin 4  control */
  uint8 PC5;      /* Pin 5  control */
  uint8 PC6;      /* Pin 6  control */
  uint8 PC7;      /* Pin 7  control */
  uint8 PC8;      /* Pin 8  control */
  uint8 PC9;      /* Pin 9  control */
  uint8 PC10;     /* Pin 10 control */
  uint8 PC11;     /* Pin 11 control */
  uint8 PC12;     /* Pin 12 control */
  uint8 PC13;     /* Pin 13 control */
  uint8 PC14;     /* Pin 14 control */
  uint8 PC15;     /* Pin 15 control */

} Port_n_ControlType;
/* [/cover] */

typedef struct
{

  unsigned int P0        : 1;    /* Pin 0  */
  unsigned int P1        : 1;    /* Pin 1  */
  unsigned int P2        : 1;    /* Pin 2  */
  unsigned int P3        : 1;    /* Pin 3  */
  unsigned int P4        : 1;    /* Pin 4  */
  unsigned int P5        : 1;    /* Pin 5  */
  unsigned int P6        : 1;    /* Pin 6  */
  unsigned int P7        : 1;    /* Pin 7  */
  unsigned int P8        : 1;    /* Pin 8  */
  unsigned int P9        : 1;    /* Pin 9  */
  unsigned int P10        : 1;    /* Pin 10  */
  unsigned int P11        : 1;    /* Pin 11  */
  unsigned int P12        : 1;    /* Pin 12  */
  unsigned int P13        : 1;    /* Pin 13  */
  unsigned int P14        : 1;    /* Pin 14  */
  unsigned int P15        : 1;    /* Pin 15  */
  unsigned int reserved: 16;

} Port_n_PinType;
/* [/cover] */



/* Type definition for port pin Hardware Supported Mode structure
*/
typedef struct
{

  uint8 U[PORT_TOTAL_AVAILABLE_PORTS];

} Port_n_ModeType;


/* [cover parentID={5D5FC124-711E-4727-BE2D-F18113C5AF18}] */
/*
  Structure definition for PORT n configuration
*/
typedef struct
{
  /* Port pins mode, direction and characteristics configuration */
  Port_n_ControlType  PinControl;
  /* Port pins initial level configuration */
  Port_n_PinType      PinLevel;
  /* Port pins drive strength configuration */
  uint32              DriverStrength0;
  /* Port pins drive strength configuration */
  uint32              DriverStrength1;
  /* If Mode changeable is enabled */
  #if (PORT_SET_PIN_MODE_API == STD_ON)
  /* Port pin run time mode changeable or not configuration */
  Port_n_PinType      ModeChangeControl;
  #endif /* PORT_SET_PIN_MODE_API */
  /* If Direction changeable is enabled */
  #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  /* Port pin run time direction changeable or not configuration */
  Port_n_PinType      DirChangeControl;
  /* Port pins mode, and characteristics configuration if
     direction is changeable */
  Port_n_ControlType  PinControl2;
  #endif /* PORT_SET_PIN_DIRECTION_API */
  Port_n_PinType      EmergencyStopConf;
} Port_n_ConfigType;
/* [/cover] */


/* LVDS config type */
typedef struct
{
  uint32 LPCR0; /* for Pinpair 0,1   */
  #if(PORT_MAX_LPCR_REG > 1U)
  uint32 LPCR1; /* for Pinpair 2,3   */
  #endif
  #if(PORT_MAX_LPCR_REG > 2U)
  uint32 LPCR2; /* for Pinpair 4,5   */
  #endif
  #if(PORT_MAX_LPCR_REG > 3U)
  uint32 LPCR3; /* for Pinpair 6,7   */
  #endif
  #if(PORT_MAX_LPCR_REG > 4U)
  uint32 LPCR4; /* for Pinpair 8,9   */
  #endif
  #if(PORT_MAX_LPCR_REG > 5U)
  uint32 LPCR5; /* for Pinpair 10,11 */
  #endif
  #if(PORT_MAX_LPCR_REG > 6U)
  uint32 LPCR6; /* for Pinpair 12,13 */
  #endif
  #if(PORT_MAX_LPCR_REG > 7U)
  uint32 LPCR7; /* for Pinpair 14,15 */
  #endif
} Port_n_LVDSConfigType;


/* PCSR config type */
typedef uint32 Port_n_PCSRConfigType;

/* [cover parentID={141E6EB8-5A51-45fd-B679-ACAEE1B9BD53}
{F77EBC90-3FA0-4521-AFEF-72DD45D68298}] */
/* Structure definition for PORT driver configuration */
/* All the ports and port pins must be configured even if they are not used */

typedef struct
{
  /* Pointer to PORT SET configuration */
  const Port_n_ConfigType* PortConfigSetPtr;

  const uint32* PDiscSet;
  #if (PORT_SET_PIN_MODE_API == STD_ON)
  #if (PORT_DEV_ERROR_DETECT == STD_ON )||(PORT_SAFETY_ENABLE == STD_ON)
  /* Port pin Hardware supported modes configuration */
  const Port_n_ModeType *PortPinHwSupportedModes;
  #endif /*(PORT_SET_PIN_MODE_API==STD_ON) */
  #endif
  /* (PORT_DEV_ERROR_DETECT == STD_ON) */
  /* Configuration data for LVDS */
  const Port_n_LVDSConfigType* Port_LVDSConfigTypePtr;
  const Port_n_PCSRConfigType* Port_PCSRConfigTypePtr;
} Port_ConfigType;
/* [/cover] */

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/



/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define PORT_START_SEC_CODE_ASIL_B_GLOBAL
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "Port_MemMap.h"

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax : void Port_Init                                                    **
**                    (                                                       **
**                      const Port_ConfigType * ConfigPtr                     **
**                    )                                                       **
**                                                                            **
** Description : This Api:                                                    **
**   - Initializes all the ports as per configuration                         **
**   - Initializes the whole port structure of MCU                            **
**   - Can be used to initialize and reinitialize the                         **
**     port with different configuration                                      **
**   - Should be called first in order to initialize                          **
**     the port for use                                                       **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to Port configuration               **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
*******************************************************************************/
extern void Port_Init
(
  const Port_ConfigType * ConfigPtr
);

/* Enable / Disable the use of the function */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/*******************************************************************************
** Traceability     :                                                         **
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
**                                                                            **
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
extern void Port_SetPinDirection
(
  const Port_PinType Pin,
  const Port_PinDirectionType Direction
);
#else
/* MISRA2012_RULE_4_9_JUSTIFICATION: With PortSetPinDirectionApi disabled
Port_SetPinDirection is implemented as Function like macro*/
#define Port_SetPinDirection(Pin,Direction) \
                (ERROR_Port_SetPinDirection_NOT_SELECTED)
#endif /* (PORT_SET_PIN_DIRECTION_API) */

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax :   void Port_RefreshPortDirection ( void )                         **
**                                                                            **
** Description :  This Api:                                                   **
**   - refreshes the direction for all the port                               **
**     pins that are configured as direction not changeable during run time   **
**                                                                            **
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
extern void Port_RefreshPortDirection(void);

/* Enable / Disable the use of the function */
#if ( PORT_VERSION_INFO_API == STD_ON )
/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax :void Port_GetVersionInfo                                           **
**                    (                                                       **
**                     Std_VersionInfoType* const versioninfo                 **
**                    )                                                       **
**                                                                            **
** Description :  This Api:                                                   **
**   - This function returns the version information of this module           **
**     The version information include : Module ID, Vendor ID,                **
**     Vendor specific version numbers                                        **
**   - This function is available if the PORT_VERSION_INFO_API is             **
**     set ON                                                                 **
**                                                                            **
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
extern void Port_GetVersionInfo
(
  Std_VersionInfoType* const versioninfo
);
#else
/* MISRA2012_RULE_4_9_JUSTIFICATION: With Port_GetVersionInfo disabled
Port_GetVersionInfo is implemented as Function like macro*/
#define Port_GetVersionInfo(versioninfo) \
                        (ERROR_Port__GetVersionInfo_NOT_SELECTED)
#endif /* PORT_VERSION_INFO_API == STD_ON */

/* Enable / Disable the use of the function */
#if (PORT_SET_PIN_MODE_API == STD_ON)
/*******************************************************************************
** Traceability     :                                                         **
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
**                                                                            **
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
extern void Port_SetPinMode
(
  const Port_PinType Pin,
  const Port_PinModeType Mode
);
#else
/* MISRA2012_RULE_4_9_JUSTIFICATION: With Port_SetPinMode disabled
Port_SetPinMode is implemented as Function like macro*/
#define Port_SetPinMode(Pin,Mode) (ERROR_Port_SetPinMode_NOT_SELECTED)
#endif /* (PORT_SET_PIN_MODE_API) */

#if(PORT_INIT_CHECK_API==STD_ON)
/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           :Std_ReturnType Port_InitCheck (const Port_ConfigType*    **
**                   const ConfigPtr)                                         **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   :                                                         **
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
extern Std_ReturnType Port_InitCheck (const Port_ConfigType* const ConfigPtr);
#else
 /* MISRA2012_RULE_4_9_JUSTIFICATION: With Port_InitCheck disabled
Port_InitCheck is implemented as Function like macro*/
#define Port_InitCheck(ConfigPtr) (ERROR_Port_InitCheck_NOT_SELECTED)
#endif

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#define PORT_STOP_SEC_CODE_ASIL_B_GLOBAL
/*mapping of code and data to specific memory sections via memory mapping file*/
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines
Port_Memmap.h header is included without safegaurd.*/
#include "Port_MemMap.h"

#include "Port_PBcfg.h"

#endif   /*  PORT_H  */

