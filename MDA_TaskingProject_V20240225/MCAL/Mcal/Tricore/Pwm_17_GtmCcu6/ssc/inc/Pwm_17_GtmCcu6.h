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
**  FILENAME     : Pwm_17_GtmCcu6.h                                           **
**                                                                            **
**  VERSION      : 9.0.0                                                      **
**                                                                            **
**  DATE         : 2018-08-07                                                 **
**                                                                            **
**  VARIANT      : Variant PB                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Pwm Driver header definition file                          **
**                                                                            **
**  SPECIFICATION(S) : Specification of Pwm Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                                                                            **
** Traceabilty      :                                                         **
*******************************************************************************/

#ifndef PWM_17_GTMCCU6_H
#define PWM_17_GTMCCU6_H
/* [cover parentID={B855907A-986E-43ce-931F-7DD6F128D11C}]
Header file (Static) defining prototypes of data structures and APIs.
Header file implements all preprocessor directives.
[/cover] */
/*******************************************************************************
**                      Includes                                              **
** Traceabilty      :                                                         **
*******************************************************************************/
/* [cover parentID={96AFF2C2-C88A-47dc-96E5-061F257B6F4C}]
Vendor ID and  Module ID 
[/cover] */
/* Inclusion of Platform_Types.h and Compiler.h */
/* [cover parentID={7C85BA64-7AA2-4bcf-8188-5E0FED5975AF}]
import version info type
[/cover] */
#include "Std_Types.h"
/* configuration data for PWM module */
#include "Pwm_17_GtmCcu6_Cfg.h"
/* Include Gtm Library */
#include "Mcu_17_TimerIp.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
** Traceabilty      :                                                         **
*******************************************************************************/
  /*
    Published parameters
  */
/* [cover parentID={96AFF2C2-C88A-47dc-96E5-061F257B6F4C}]
Vendor ID and  Module ID 
[/cover] */
#define PWM_17_GTMCCU6_VENDOR_ID                   ((uint16)(17U))
  /* Pwm Module ID */
#define PWM_17_GTMCCU6_MODULE_ID                   ((uint16)(121U))
  
/*
  Development error values
*/
#if ((PWM_17_GTMCCU6_DEV_ERROR_DETECT == STD_ON) || (PWM_17_GTMCCU6_SAFETY_ENABLE == STD_ON))
/* [cover parentID={D581EE39-070C-447c-97E2-397284485D85}]
   API Pwm_17_GtmCcu6_Init service called with wrong parameter
[/cover] */
#define PWM_17_GTMCCU6_E_INIT_FAILED          ((uint8)0x10)
/* [cover parentID={B2CE5E5D-345F-4656-AF9C-2DFB93B78942}]
   API service used without module initialization
[/cover] */
#define PWM_17_GTMCCU6_E_UNINIT               ((uint8)0x11)
/* [cover parentID={0A2EB31E-C51F-4e9c-AA96-879B25EC2543}]
   API service used with an invalid channel Identifier
[/cover] */
#define PWM_17_GTMCCU6_E_PARAM_CHANNEL        ((uint8)0x12)
/* [cover parentID={B661701B-4CFB-4d5c-9CA8-817B5F2001EC}]
   Usage of Pwm_SetPeriodAndDuty on PWM channel
   with class other than VARIABLE_PERIOD
[/cover] */
#define PWM_17_GTMCCU6_E_PERIOD_UNCHANGEABLE  ((uint8)0x13)
/* [cover parentID={0371188A-F5F0-4743-BD8E-70E8C630DDB9}]
   Init API service is already called
[/cover] */
#define PWM_17_GTMCCU6_E_ALREADY_INITIALIZED  ((uint8)0x14)
/* [cover parentID={47AA072E-60A4-4ac4-8702-05265E3F9A9C}]
   Function Pwm_GetVersionInfo called with invalid pointer
[/cover] */
#define PWM_17_GTMCCU6_E_PARAM_POINTER        ((uint8)0x15)

#if (PWM_17_GTMCCU6_SAFETY_ENABLE == STD_ON)
/* Safety Errors */

#if ((PWM_17_GTMCCU6_SET_PERIOD_AND_DUTY_API == STD_ON) \
                                       || (PWM_17_GTMCCU6_SET_DUTY_CYCLE_API == STD_ON))
/* Error reported when Pwm_17_GtmCcu6_SetDutyCycle or \
              Pwm_17_GtmCcu6_SetPeriodAndDuty APIs called with incorrect duty.*/
#define PWM_17_GTMCCU6_E_PARAM_DUTY    ((uint8)0xC9)
#endif

/* Error reported when Pwm Isr is called with incorrect compare 
   match interrupt.*/
#define PWM_17_GTMCCU6_E_INVALID_ISR    ((uint8)0xC8)

#if (PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED == STD_ON)
/* [cover parentID={8C33C558-59CE-455d-A1EA-1E87FCAB7198}]
   PWM_17_GTMCCU6_E_PARAM_NOTIFICATION
[/cover] */
/* API Pwm_17_GtmCcu6_EnableNotification services called with
                                 invalid notification type.*/
#define PWM_17_GTMCCU6_E_PARAM_NOTIFICATION    ((uint8)0xCA)
/* Error reported when Enable Notification is called for the channel where no
   notification is configured.*/
   /* [cover parentID={E8FCD7ED-4708-4491-914A-32540B25CEF1}]
   PWM_17_GTMCCU6_E_NO_NOTIF_CONFIGURED
[/cover] */
#define PWM_17_GTMCCU6_E_NO_NOTIF_CONFIGURED    ((uint8)0xCC)
#endif
#if (PWM_17_GTMCCU6_SET_PERIOD_AND_DUTY_API == STD_ON)
/* Error reported when Pwm_17_GtmCcu6_SetPeriodAndDuty APIs called with \
 incorrect period.*/
#define PWM_17_GTMCCU6_E_PARAM_PERIOD    ((uint8)0xCB)
#endif
#endif

/*
 * PWM Service Id's
*/
/* Pwm_Init() Service ID */
#define PWM_17_GTMCCU6_SID_INIT                 ((uint8)0x00)
/* Pwm_DeInit() Service ID */
#define PWM_17_GTMCCU6_SID_DEINIT               ((uint8)0x01)
/* Pwm_SetDuty() Service ID */
#define PWM_17_GTMCCU6_SID_SETDUTY              ((uint8)0x02)
/* Pwm_SetPeriodAndDuty() Service ID */
#define PWM_17_GTMCCU6_SID_SET_PERIOD_DUTY      ((uint8)0x03)
/* Pwm_SetOutputToIdle() Service ID */
#define PWM_17_GTMCCU6_SID_SETOP2IDLE           ((uint8)0x04)
/* Pwm_GetOutputState() Service ID */
#define PWM_17_GTMCCU6_SID_GETOPSTATE           ((uint8)0x05)
/* Pwm_DisableNotification() Service ID */
#define PWM_17_GTMCCU6_SID_DISABLENOTIFI        ((uint8)0x06)
/* Pwm_EnableNotification() Service ID */
#define PWM_17_GTMCCU6_SID_ENABLENOTIFI         ((uint8)0x07)
/* Pwm_GetVersionInfo() Service ID */
#define PWM_17_GTMCCU6_SID_GETVERSIONINFO       ((uint8)0x08)
/*Pwm ISR service ID*/
#define PWM_17_GTMCCU6_SID_ISR                  ((uint8)0x09)
/*Pwm Init Check service ID*/
#define PWM_17_GTMCCU6_SID_INITCHECK            ((uint8)0x10)
#endif /* PWM_17_GTMCCU6_DEV_ERROR_DETECT */

/* Multi-core DETs*/
/* Report DET PWM module not configured for this Core*/
#define PWM_17_GTMCCU6_E_CORE_NOT_CONFIGURED     ((uint8)0x64)
/* [cover parentID={E3883A82-81DD-4402-96D5-42BA11077AFD}]
   PWM channel is not allocated to this core
[/cover] */
#define PWM_17_GTMCCU6_E_CORE_CHANNEL_MISMATCH   ((uint8)0x65)

/* To indicate not referenced to other channel  */
#define PWM_17_GTMCCU6_NOT_REFERENCED           (0x1FU)

/* PWM Channel class types */
#define PWM_17_GTMCCU6_FIXED_PERIOD               ((Pwm_17_GtmCcu6_ChannelClassType)(0x0U))
#define PWM_17_GTMCCU6_FIXED_PERIOD_SHIFTED       ((Pwm_17_GtmCcu6_ChannelClassType)(0x1U))
#define PWM_17_GTMCCU6_FIXED_PERIOD_CENTER_ALIGNED\
                                       ((Pwm_17_GtmCcu6_ChannelClassType)(0x2U))
#define PWM_17_GTMCCU6_VARIABLE_PERIOD           \
                                       ((Pwm_17_GtmCcu6_ChannelClassType)(0x3U))

/* The PWM channel is in low state.*/
#define PWM_17_GTMCCU6_LOW   ((Pwm_17_GtmCcu6_OutputStateType)(0U))
/* The PWM channel is in High state.*/
#define PWM_17_GTMCCU6_HIGH  ((Pwm_17_GtmCcu6_OutputStateType)(1U))

#if (PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED == STD_ON)

/* [cover parentID={62162C26-B59C-4b2c-9FE7-E787D02E08E7}]
Pwm_17_GtmCcu6_EdgeNotificationType implemented as uint8
[/cover] */

/* Definition of the type of notification of a PWM channel */
/* [cover parentID={C080AEB0-3B63-4402-96C0-0A364467219A}] */
typedef uint8 Pwm_17_GtmCcu6_EdgeNotificationType;
/*  [/cover] */
#endif /* PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED */

#if (PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED == STD_ON)
/* Notification will be called when a rising edge occurs on the PWM Output
     signal.*/
#define PWM_17_GTMCCU6_RISING_EDGE     ((Pwm_17_GtmCcu6_EdgeNotificationType)(1))
/* Notification will be called when a falling edge occurs on the PWM
   output signal */
#define PWM_17_GTMCCU6_FALLING_EDGE    ((Pwm_17_GtmCcu6_EdgeNotificationType)(2))
/* Notification will be called when both a rising edge or falling edge
   (means any edge) occurs on the PWM output signal */
#define PWM_17_GTMCCU6_BOTH_EDGES      ((Pwm_17_GtmCcu6_EdgeNotificationType)(3))

#endif /* PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED */

#define PWM_17_GTMCCU6_NON_COHERENT                      ((uint8)0x0U)
#define PWM_17_GTMCCU6_COHERENT                          ((uint8)0x1U)
#define PWM_17_GTMCCU6_GTM_TIMER                         ((uint8)0x00)
#define PWM_17_GTMCCU6_CCU6_TIMER                        ((uint8)0x01)
/*******************************************************************************
**                      Functions like Macro                                  **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
*******************************************************************************/
/* PWM027: */
/* Output state of a PWM channel. Note that this will be read from the output
   state on the LTC cell (Assigned_HwUnit) connected to the port pin.
   This will not be read directly from the Port Pin. However both will be
   the same. */
/* [cover parentID={58C389D3-41C2-44b3-B61A-F4EFC4BD3F3D}] */
typedef uint8 Pwm_17_GtmCcu6_OutputStateType;
/*  [/cover] */

/* Numeric identifier of a PWM channel */
/* Maximum 32 channels can be supported.
If proper configuration setup made by user */
/* [cover parentID={EDD51680-C50C-42ed-AEC2-D8CDEB3EFD96}] */
typedef uint8 Pwm_17_GtmCcu6_ChannelType;
/*  [/cover] */

/* Type definition of the period of a PWM channel.*/
/* [cover parentID={90181520-735E-4d24-98F7-97D01F29E761}] */
typedef uint32 Pwm_17_GtmCcu6_PeriodType;
/*  [/cover] */

/* [cover parentID={62162C26-B59C-4b2c-9FE7-E787D02E08E7}]
Pwm_17_GtmCcu6_ChannelClassType implemented as uint8
[/cover] */
/* [cover parentID={B45626F8-177F-4719-9933-B2B22DC6ADCE}] */
typedef uint8 Pwm_17_GtmCcu6_ChannelClassType;
/*  [/cover] */

/* To provide Notification the following type will be used */
typedef void (*Pwm_17_GtmCcu6_NotifiPtrType)(void);
/* The following struct type is a channel dependent configuration */
/*
   All the member names are given as per bmd file to maintain
   consistency
*/
typedef struct
{
	Pwm_17_GtmCcu6_ChannelType PwmChanneId;
  /* defines timer modules used
    0 - GTM
    1 - CCU6 */
  uint8 PwmTimerUsed;
  
  #if (PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED == STD_ON)

  /* The following parameter is a function pointer to provide notification */
  Pwm_17_GtmCcu6_NotifiPtrType PwmNotification;
  #endif /* PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED */

  /* Pwm_ChannelInfo constitutes
      Reference_Channel, Pwm_ChannelMode, Pwm_IdleState and
      Assigned_HwUnit.
      While forming the variable, user has to form this in the following
      manner. [Note : Use macro Pwm_lConfigChannel() for configuration ]
      PwmChannelInfo =
                        (((ShiftReset) << 5UL)         |   \
                         ((ChannelClass) << 3UL)        |   \
                         ((ChannelCoherency) << 2UL)    |   \
                         ((IdleState) << 1UL)           |   \
                         (Polarity)                         \
                        ) 
     Where :
            bit 5:
            To indicate ccu0 is reset by its own compare match or from 
            other channel
            bit 3-4:
            PwmChannelClass :  Used to indicate whether channel is
                                FIXED_PERIOD
                                FIXED_PERIOD_SHIFTED
                                FIXED_PERIOD_CENTER_ALIGNED
                                VARIABLE_PERIOD
            bit 2:
            PwmCoherency   : Informs the channel wise Coherency Selection.
                              1 - Coherent or 0 - non Coherent.
            bit 1:
            PwmIdleState   : Informs the channel Idle State.
                              PWM_17_GTMCCU6_HIGH or PWM_17_GTMCCU6_LOW

            bit 0:
            PwmPolarity    : Informs the channels start state
                              PWM_17_GTMCCU6_HIGH Or PWM_17_GTMCCU6_LOW
  */
  uint16 PwmChannelInfo;

  /* Default period of PWM channel. This value is fixed permanently for a PWM
      channel configured with Fixed Period Type. */
  Pwm_17_GtmCcu6_PeriodType PwmPeriodDefault;

  /* Default Duty Cycle of a PWM channel */
  uint32 PwmDutycycleDefault;

  /* The following parameter informs the % of shift required.
      The range will be from 0x0000 to 0x8000.
      For 0% shift : value=0x0000, for 100% shift : value=0x8000 */
  uint32 PwmShiftValue;
  
  /* Pointer to GTM/CCU6 timer channel information */
  const void* PwmTimerPtr;
  
}Pwm_17_GtmCcu6_ChannelConfigType;

typedef struct
{
  /* No of Gtm channels */
  Pwm_17_GtmCcu6_ChannelType             MaxChannels;
  /* Pwm Channel Configuration */
  const Pwm_17_GtmCcu6_ChannelConfigType *Pwm_ChannelConfigPtr;
  
}Pwm_17_GtmCcu6_CoreConfigType;

/* The following struct type is utilized to configure PWM module */
/* [cover parentID={EF60FD1E-CB3C-4852-BB19-46C724FEF5EB}] */
/* [cover parentID={EF028585-25D2-4302-9E9F-BA868BE7E9C8}] */
/*Pwm_17_GtmCcu6_ConfigType*/
/*  [/cover] */
typedef struct
{
  Pwm_17_GtmCcu6_CoreConfigType* PwmCoreAdd[PWM_17_GTMCCU6_MAX_CORES];
  uint8*                         PwmChannelIdxmapPtr;
  uint32                         PwmCcu6ChIdx[MCU_17_CCU6_NO_OF_KERNELS];

}Pwm_17_GtmCcu6_ConfigType;
/*  [/cover] */

/*Structure to hold the different details of a channel*/
typedef struct
{
  uint8 ModuleId;
  uint8 ModuleNo;
  uint8 ChannelNo; /* Specifies the Channel Number       */
  uint8 GroupNo; 
}Pwm_17_GtmCcu6_ChannelIdentifierType;

typedef struct
{
  uint32  Pwm_GlobChn;
  uint32  Pwm_CurrentPeriodVal;
}Pwm_17_GtmCcu6_ChannelStatusType;

typedef struct
{
  uint32 Pwm_CoreInitStatus;
  uint32 Pwm_CCU6PMStatus[MCU_17_CCU6_NO_OF_KERNELS];
}Pwm_17_GtmCcu6_CoreStatusType;


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

#define PWM_17_GTMCCU6_START_SEC_CODE_ASIL_B_GLOBAL
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*******************************************************************************
** Syntax : void Pwm_17_GtmCcu6_Init(const Pwm_17_GtmCcu6_ConfigType *        **
**                                                            ConfigPtr)      **
**                                                                            **
** Service ID:  0x0                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): Config - Pointer to configuration set                     **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Driver Module Initialization                                 **
**               1.This function will initialize all relevant registers of the**
**                 configured hardware (Assigned_HW_Unit) with the values of  **
**                 structure given by user in Pwm_Configuration[].            **
**               2. This service will disable all notifications.              **
**               3. Resources that are not configured in the configuration    **
**                  file will not be changed.                                 **
**               4. This function shall initialize all internals variables    **
**               5. After initialization the PWM driver will start to generate**
**                  PWM signal(s) with the configured default values          **
**                                                                            **
*******************************************************************************/
extern void Pwm_17_GtmCcu6_Init
(
  const Pwm_17_GtmCcu6_ConfigType * const ConfigPtr
);

#if (PWM_17_GTMCCU6_DE_INIT_API == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_GtmCcu6_DeInit(void)                                  **
**                                                                            **
** Service ID:  0x1                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in):  none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : Service for PWM De-Initialization                            **
**               1.After the call of this service, the state of the used      **
**                 peripherals/registers will set to power on reset state.    **
**               2.This service will disable all used interrupts and          **
**                  notifications.                                            **
**               3.This service clear all pending interrupt flags             **
**               4.All global variables will get reset                        **
**               5.All channel output signal state will set to Idle State     **
**                                                                            **
*******************************************************************************/
extern void Pwm_17_GtmCcu6_DeInit
(
  void
);

#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Pwm_17_GtmCcu6_DeInit()  \
           (ERROR_Pwm_17_GtmCcu6_DeInit_NOT_SELECTED)

#endif /* PWM_17_GTMCCU6_DE_INIT_API */
#if (PWM_17_GTMCCU6_SET_DUTY_CYCLE_API == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_GtmCcu6_SetDutyCycle(                                 **
**                                Pwm_17_GtmCcu6_ChannelType ChannelNumber,   **
**                                uint16          DutyCycle                   **
**               )                                                            **
**                                                                            **
** Service ID:  0x2                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel    **
**                   DutyCycle     : To set Duty Cycle for a PWM channel      **
**                                   Min=0x0000 Max=0x8000                    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : Service to set Duty cycle                                    **
**               1.This service will allow to set the duty cycle of the PWM   **
**                 channel.                                                   **
**               2.If the duty cycle = 0% (value=0x0000), then the PWM output **
**                 state will set to Idle level.                              **
**               3.If the duty cycle=100% (value=0x8000), then the PWM output **
**                 state will set to Active level.                            **
**               4.If the duty cycle>100%(value>0x8000), then the PWM output  **
**                 will be undefined behavior (recommended that, user not to  **
**                 provide this range of value)                               **
**               5 If the duty cycle >0% and <100%,then the PWM output will   **
**                 set to active state according to duty cycle and period     **
**                 parameters and then to idle state.                         **
**               6.Dependency on PWM_17_GTMCCU6_DUTYCYCLE_UPDATED_ENDPERIOD   **
**                 configuration parameter.                                   **
**                                                                            **
*******************************************************************************/

#if (PWM_17_GTMCCU6_DUTY_SHIFT_IN_TICKS == STD_OFF)    
extern void Pwm_17_GtmCcu6_SetDutyCycle
(
  const Pwm_17_GtmCcu6_ChannelType ChannelNumber,
  const uint16          DutyCycle
);
#else
extern void Pwm_17_GtmCcu6_SetDutyCycle
(
  const Pwm_17_GtmCcu6_ChannelType ChannelNumber,
  const uint32          DutyCycle
);
#endif
#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Pwm_17_GtmCcu6_SetDutyCycle(ChannelNumber, DutyCycle)   \
            (ERROR_Pwm_17_GtmCcu6_SetDutyCycle_NOT_SELECTED)

#endif /* PWM_17_GTMCCU6_SET_DUTY_CYCLE_API */

#if (PWM_17_GTMCCU6_SET_PERIOD_AND_DUTY_API == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_GtmCcu6_SetPeriodAndDuty(                             **
**                                Pwm_17_GtmCcu6_ChannelType ChannelNumber,   **
**                                Pwm_17_GtmCcu6_PeriodType  Period,          **
**                                           uint16          DutyCycle        **
**                                    )                                       **
**                                                                            **
** Service ID:  0x3                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel    **
**                   Period        : Period of the PWM signal                 **
**                   DutyCycle     : To set Duty Cycle for a PWM channel      **
**                                   Min=0x0000 Max=0x8000                    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : Service to set period and Duty cycle                         **
**               1.This service will allow to set the duty cycle of the PWM   **
**                 channel.                                                   **
**               2.Valid only for variable period                             **
**               3.If the duty cycle=0% (value=0x8000), then the PWM output   **
**                 state will set to Idle level.                              **
**               4.If the duty cycle=100% (value=0x8000), then the PWM output **
**                 state will set to Active level.                            **
**               5.If the duty cycle>100%(value>0x8000), then the PWM output  **
**                 will be undefined behavior (recommended that, user not to  **
**                 provide this range of value)                               **
**               6 If the duty cycle >0% and <100%,then the PWM output will   **
**                 set to active state according to duty cycle and period     **
**                 parameters and then to idle state.                         **
**               7.To scale the duty cycle passed period  will be used        **
**                                                                            **
*******************************************************************************/
#if (PWM_17_GTMCCU6_DUTY_SHIFT_IN_TICKS == STD_OFF)
extern void Pwm_17_GtmCcu6_SetPeriodAndDuty
(
  const Pwm_17_GtmCcu6_ChannelType ChannelNumber,
  const Pwm_17_GtmCcu6_PeriodType  Period,
  const uint16          DutyCycle
);
#else
extern void Pwm_17_GtmCcu6_SetPeriodAndDuty
(
  const Pwm_17_GtmCcu6_ChannelType ChannelNumber,
  const Pwm_17_GtmCcu6_PeriodType  Period,
  const uint32          DutyCycle
);
#endif
#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Pwm_17_GtmCcu6_SetPeriodAndDuty(ChannelNumber, Period, DutyCycle) \
                  (ERROR_Pwm_17_GtmCcu6_SetPeriodAndDuty_NOT_SELECTED)

#endif /* PWM_17_GTMCCU6_SET_PERIOD_AND_DUTY_API */

#if (PWM_17_GTMCCU6_SET_OUTPUT_TO_IDLE_API == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_GtmCcu6_SetOutputToIdle                               **
**                              (Pwm_17_GtmCcu6_ChannelType ChannelNumber)    **
**                                                                            **
** Service ID:  0x4                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : Service for to set PWM output to Idle State                  **
**               1.This API will be useful to set output to Idle immediately  **
**                                                                            **
*******************************************************************************/
extern void Pwm_17_GtmCcu6_SetOutputToIdle
(
  const Pwm_17_GtmCcu6_ChannelType ChannelNumber
);
#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Pwm_17_GtmCcu6_SetOutputToIdle(ChannelNumber)\
         (ERROR_Pwm_17_GtmCcu6_SetOutputToIdle_NOT_SELECTED)

#endif /* PWM_17_GTMCCU6_SET_OUTPUT_TO_IDLE_API */


#if (PWM_17_GTMCCU6_GET_OUTPUT_STATE_API == STD_ON)
/*******************************************************************************
** Syntax : Pwm_17_GtmCcu6_OutputStateType Pwm_17_GtmCcu6_GetOutputState      **
**                                    (Pwm_17_GtmCcu6_ChannelType             **
**                                                            ChannelNumber)  **
**                                                                            **
** Service ID:  0x5                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     Pwm_17_GtmCcu6_OutputStateType                           **
**                                                                            **
** Description : Service to read the PWM output state                         **
**               1.If development error detection is enabled and an error is  **
**                  detected the service returns PWM_17_GTMCCU6_LOW.          **
**               2.Output state of a PWM channel. Note that this will be read **
**                 from the output state on the LTC cell (Assigned_HwUnit)    **
**                 connected to the port pin. This will not be read directly  **
**                 from the Port Pin. However both will be the same           **
**                                                                            **
*******************************************************************************/
extern Pwm_17_GtmCcu6_OutputStateType Pwm_17_GtmCcu6_GetOutputState
(
  const Pwm_17_GtmCcu6_ChannelType ChannelNumber
);
#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Pwm_17_GtmCcu6_GetOutputState(ChannelNumber) \
         (ERROR_Pwm_17_GtmCcu6_GetOutputState_NOT_SELECTED)

#endif /* PWM_17_GTMCCU6_GET_OUTPUT_STATE_API */


#if (PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_GtmCcu6_DisableNotification                           **
**                                  (Pwm_17_GtmCcu6_ChannelType ChannelNumber)**
**                                                                            **
** Service ID: 0x6                                                            **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: reentrant                                                      **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : This service will disable all PWM signal notifications of    **
**               this channel. (PWM023:)                                      **
**                                                                            **
*******************************************************************************/
extern void Pwm_17_GtmCcu6_DisableNotification
(
  const Pwm_17_GtmCcu6_ChannelType ChannelNumber
);
#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Pwm_17_GtmCcu6_DisableNotification(ChannelNumber) \
        (ERROR_Pwm_17_GtmCcu6_DisableNotification_NOT_SELECTED)

#endif /* PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED */

/*******************************************************************************
** Syntax :          void Pwm_17_GtmCcu6_GetVersionInfo( Std_VersionInfoType  **
**                                            *VersionInfoPtr)                **
**                                                                            **
** Service ID:       0x8                                                      **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non reentrant                                            **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): versioninfo : Pointer to hold the version values         **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : 1. This service will return the version infos of PWM driver  **
**                                                                            **
** Traceabilty      :                                                         **
**                                                                            **
*******************************************************************************/
#if (PWM_17_GTMCCU6_VERSION_INFO_API == STD_ON)
extern void Pwm_17_GtmCcu6_GetVersionInfo\
                                   (Std_VersionInfoType * const VersionInfoPtr);
#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Pwm_17_GtmCcu6_GetVersionInfo(VersionInfoPtr)                         \
  (ERROR_Pwm_17_GtmCcu6_GetVersionInfo_NOT_SELECTED)
#endif /* (PWM_17_GTMCCU6_VERSION_INFO_API) */

#if (PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_GtmCcu6_EnableNotification(                           **
**                            Pwm_17_GtmCcu6_ChannelType   ChannelNumber,     **
**                            Pwm_17_GtmCcu6_EdgeNotificationType Notification**
**                                     )                                      **
** Service ID: 0x7                                                            **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: reentrant                                                      **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel    **
**                   Notification  : PWM_17_GTMCCU6_RISING_EDGE or            **
**                                   PWM_17_GTMCCU6_FALLING_EDGE or           **
**                                   PWM_17_GTMCCU6_BOTH_EDGES                **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : This service will enable the PWM signal notification         **
**               according to notification parameter. PWM024:                 **
**                                                                            **
*******************************************************************************/
extern void Pwm_17_GtmCcu6_EnableNotification
(
  const Pwm_17_GtmCcu6_ChannelType          ChannelNumber,
  const Pwm_17_GtmCcu6_EdgeNotificationType Notification
);
#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Pwm_17_GtmCcu6_EnableNotification(ChannelNumber,Notification)       \
         (ERROR_Pwm_17_GtmCcu6_EnableNotification_NOT_SELECTED)

#endif /* PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED */

#if (PWM_17_GTMCCU6_INITCHECK_API == STD_ON)
/******************************************************************************
** Syntax : void Pwm_17_GtmCcu6_InitCheck(const Pwm_17_GtmCcu6_ConfigType    **
**                                                                *ConfigPtr)**
**                                                                           **
** Service ID:      0x10                                                     **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      non reentrant                                            **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out):E_OK - Init Check Sucessfull                             **
**                  E_NOT_OK - Init Check Failed                             **
**                                                                           **
** Return value:    none                                                     **
**                                                                           **
** Description : This routine verifies the initialization the PWM driver.    **
**                                                                           **
** Traceabilty      :                                                        **
******************************************************************************/
extern Std_ReturnType Pwm_17_GtmCcu6_InitCheck
(
  const Pwm_17_GtmCcu6_ConfigType * const ConfigPtr
);
#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Pwm_17_GtmCcu6_InitCheck(ConfigPtr)       \
                                  (ERROR_Pwm_17_GtmCcu6_InitCheck_NOT_SELECTED)
#endif
#define PWM_17_GTMCCU6_STOP_SEC_CODE_ASIL_B_GLOBAL
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
#include "Pwm_17_GtmCcu6_PBcfg.h"
#endif  /* PWM_17_GTMCCU6_H */
