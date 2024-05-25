
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
**  FILENAME  : Pwm_17_GtmCcu6_PBcfg.c                                        **
**                                                                            **
**  VERSION   : 8.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2024-02-23, 10:02:41                                      **
**                                                                            **
**  GENERATOR : Build b170330-0431                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Pwm.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Pwm configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Pwm Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include module header File */
#include "Pwm_17_GtmCcu6.h"
#include "Mcu_17_TimerIp.h"
/* [cover parentID={E86E979E-8B2D-4605-BF57-7FFD88121727}]
  Generated File containing objects to data structures
[/cover] */
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*
Pre Compile time parameters are placed in Pwm_Cfg.h
*/
/* Precompile macros for Alternate port pin selection  */
/* [cover parentID={773C76D6-1285-4e38-9D78-FB3A595E2C45}]
 GtmTimerPortPinSelect [/cover]*/
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Usage of this macro depends upon configuration done in tresos*/
#define PWM_ALT_SELA ((uint16)0x00)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Usage of this macro depends upon configuration done in tresos*/
#define PWM_ALT_SELB ((uint16)0x01)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Usage of this macro depends upon configuration done in tresos*/
#define PWM_ALT_SELC ((uint16)0x02)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Usage of this macro depends upon configuration done in tresos*/
#define PWM_ALT_SELD ((uint16)0x03)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Usage of this macro depends upon configuration done in tresos*/
#define PWM_ALT_SELE ((uint16)0x04)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Usage of this macro depends upon configuration done in tresos*/
#define PWM_ALT_SELF ((uint16)0x05)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Usage of this macro depends upon configuration done in tresos*/
#define PWM_ALT_SELG ((uint16)0x06)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Usage of this macro depends upon configuration done in tresos*/
#define PWM_ALT_SELH ((uint16)0x07)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Usage of this macro depends upon configuration done in tresos*/
#define PWM_ALT_SELI ((uint16)0x08)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Usage of this macro depends upon configuration done in tresos*/
#define PWM_ALT_SELJ ((uint16)0x09)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Usage of this macro depends upon configuration done in tresos*/
#define PWM_ALT_SELK ((uint16)0x0A)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Usage of this macro depends upon configuration done in tresos*/
#define PWM_ALT_SELL ((uint16)0x0B)
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*
Configuration:
PWM Channel Configuration:
Elements / Attributes
1. Notification function pointer (if required)
2. Shift Value, only for PWM_FIXED_PERIOD_SHIFTED Class
   Input a value between 0 and 0x8000.
3. Default Duty Cycle ( duty cycle value between
   0 and 0x8000)
4. Pwm_Period:
   Enter in ticks
   PWM070: All time units should be in ticks.
5. Pwm_ConfigChannel:
   Go in the following parameter order
   a) Reference to Channel Number, for a Shifted, Center Aligned and
   Zero Shifted channel, a reference must be given. For a variable
   and Fixed Period channel class, reference should not be given.
   Reference should be given in the form of channel number index.
   b) Channel Class
      Possible Options: PWM_FIXED_PERIOD, PWM_FIXED_PERIOD_SHIFTED,
      PWM_FIXED_PERIOD_CENTER_ALIGNED, PWM_VARIABLE_PERIOD
   c) Channel Idle State:
      Possible Options: PWM_LOW, PWM_HIGH
      Output line goes into Idle state either after Pwm_SetOutputtoIdle
      or Pwm_DeInit.
   d) Channel Polarity:
      Possible Options: PWM_LOW, PWM_HIGH
      Initial Polarity state of the channel.
   e) GTM timer Configuration:
      Select timer reference :TOM/ATOM.
      Clockselect and port pin.
 */
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*
Function Like Macro:Pwm_lConfigChannel
Macro that packs the PWM Channel Information.
Input Parameters:
ShiftReset: Shifted channel is reset by itself or by other channel
ChannelClass : Channel Class
ChannelCoherency : Channel Coherency
IdleState : Idle State
Polarity : Channel Polarity
AssignedHwUnit : Hardware Unit Used
*/
/*MISRA2012_RULE_4_9_JUSTIFICATION: Function like macro is used to reduce the
  memory usage */
#define Pwm_lConfigChannel(ShiftReset,                   \
                           ChannelClass,                 \
                           ChannelCoherency,             \
                           IdleState,                    \
                           Polarity)                     \
              ((uint16)( ((ShiftReset) << 5U)          |   \
                         ((ChannelClass) << 3U)        |   \
                         ((ChannelCoherency) << 2U)    |   \
                         ((IdleState) << 1U)           |   \
                         ((Polarity))                       \
                       ))
/******************************************************************************/
/******************************************************************************/





                                                                                                
    
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}]
Memory Mapping config data
[/cover] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
  before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
/* [cover parentID={933763AC-75AA-40a0-9A52-62A3E13015EE}]
 Data Structure to hold index map
[/cover] */
static const uint8 Pwm_ChannelIndexMap [6] =
{
  0x0U,
  0x1U,
  0x2U,
  0x3U,
  0x4U,
  0x5U,
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
  before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"

/* Loop for all the cores */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
  before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"

/* [cover parentID={B70285DD-C6A1-4806-B583-9A5D242FFA6C}]
  Gtm Channel Structure for selected Core
[/cover] */
static const Mcu_17_Gtm_TomAtomChConfigType Pwm_kChannelConfigGtm_Core0[6] = 
{
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x0U,
    0x2U, /* Channel Control Register*/
    0x64U, /* CN0 in ticks */
    0x64U, /* CM0 in ticks */
    0x32U, /* CM1 in ticks */
    0x64U, /* SR0 in ticks */
    0x32U, /* SR1 in ticks */
    (uint32)((uint32)43U | (uint32)(PWM_ALT_SELI << 15U)),/* portpinout*/
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x2U,
    0x2U, /* Channel Control Register*/
    0x64U, /* CN0 in ticks */
    0x64U, /* CM0 in ticks */
    0x32U, /* CM1 in ticks */
    0x64U, /* SR0 in ticks */
    0x32U, /* SR1 in ticks */
    (uint32)((uint32)44U | (uint32)(PWM_ALT_SELI << 15U)),/* portpinout*/
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x3U,
    0x2U, /* Channel Control Register*/
    0x64U, /* CN0 in ticks */
    0x64U, /* CM0 in ticks */
    0x32U, /* CM1 in ticks */
    0x64U, /* SR0 in ticks */
    0x32U, /* SR1 in ticks */
    (uint32)((uint32)45U | (uint32)(PWM_ALT_SELI << 15U)),/* portpinout*/
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x403U,
    0x2U, /* Channel Control Register*/
    0x0U, /* CN0 in ticks */
    0x0U, /* CM0 in ticks */
    0x0U, /* CM1 in ticks */
    0x0U, /* SR0 in ticks */
    0x0U, /* SR1 in ticks */
    (uint32)((uint32)46U | (uint32)(PWM_ALT_SELK << 15U)),/* portpinout*/
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x200U,
    0x2U, /* Channel Control Register*/
    0x0U, /* CN0 in ticks */
    0x0U, /* CM0 in ticks */
    0x0U, /* CM1 in ticks */
    0x0U, /* SR0 in ticks */
    0x0U, /* SR1 in ticks */
    (uint32)((uint32)144U | (uint32)(PWM_ALT_SELI << 15U)),/* portpinout*/
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x107U,
    0x2U, /* Channel Control Register*/
    0x0U, /* CN0 in ticks */
    0x0U, /* CM0 in ticks */
    0x0U, /* CM1 in ticks */
    0x0U, /* SR0 in ticks */
    0x0U, /* SR1 in ticks */
    (uint32)((uint32)150U | (uint32)(PWM_ALT_SELJ << 15U)),/* portpinout*/
    0x80U /* Period,Duty Interrupt and mode*/
  },
};
/* [cover parentID={590D92B5-1B71-4d3f-BAEC-819D90AF138E}]
  Channel Structure for selected Core
[/cover] */
static const Pwm_17_GtmCcu6_ChannelConfigType Pwm_kChannelConfigurationCore0[] =
{
/*******************************************************************************
 *  Channel Number        : 0
 *  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_0_Drive1
 *  Channel Class         : PWM_VARIABLE_PERIOD
*******************************************************************************/
  {
    0, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    #if (PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED == STD_ON)
    NULL_PTR, /* Notification function */
    #endif
    Pwm_lConfigChannel(
                    0U,/* Channel reset from other channel or not*/
                    PWM_17_GTMCCU6_VARIABLE_PERIOD,/* Channel Class */
                    PWM_17_GTMCCU6_COHERENT,/* Coherency */
                    PWM_17_GTMCCU6_LOW, /* channel Idle state */
                    PWM_17_GTMCCU6_LOW  /* channel polarity */
                  ),
    (Pwm_17_GtmCcu6_PeriodType)0x64, /* Default Period */
    (uint32)0x32, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    (const void*)&Pwm_kChannelConfigGtm_Core0[0]
 /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
  * by violating this MISRA rule. */
  },
/*******************************************************************************
 *  Channel Number        : 1
 *  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_1_Drive2
 *  Channel Class         : PWM_VARIABLE_PERIOD
*******************************************************************************/
  {
    1, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    #if (PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED == STD_ON)
    NULL_PTR, /* Notification function */
    #endif
    Pwm_lConfigChannel(
                    0U,/* Channel reset from other channel or not*/
                    PWM_17_GTMCCU6_VARIABLE_PERIOD,/* Channel Class */
                    PWM_17_GTMCCU6_COHERENT,/* Coherency */
                    PWM_17_GTMCCU6_LOW, /* channel Idle state */
                    PWM_17_GTMCCU6_LOW  /* channel polarity */
                  ),
    (Pwm_17_GtmCcu6_PeriodType)0x64, /* Default Period */
    (uint32)0x32, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    (const void*)&Pwm_kChannelConfigGtm_Core0[1]
 /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
  * by violating this MISRA rule. */
  },
/*******************************************************************************
 *  Channel Number        : 2
 *  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_2_Drive3
 *  Channel Class         : PWM_VARIABLE_PERIOD
*******************************************************************************/
  {
    2, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    #if (PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED == STD_ON)
    NULL_PTR, /* Notification function */
    #endif
    Pwm_lConfigChannel(
                    0U,/* Channel reset from other channel or not*/
                    PWM_17_GTMCCU6_VARIABLE_PERIOD,/* Channel Class */
                    PWM_17_GTMCCU6_COHERENT,/* Coherency */
                    PWM_17_GTMCCU6_LOW, /* channel Idle state */
                    PWM_17_GTMCCU6_LOW  /* channel polarity */
                  ),
    (Pwm_17_GtmCcu6_PeriodType)0x64, /* Default Period */
    (uint32)0x32, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    (const void*)&Pwm_kChannelConfigGtm_Core0[2]
 /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
  * by violating this MISRA rule. */
  },
/*******************************************************************************
 *  Channel Number        : 3
 *  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_3_Drive4
 *  Channel Class         : PWM_VARIABLE_PERIOD
*******************************************************************************/
  {
    3, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    #if (PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED == STD_ON)
    NULL_PTR, /* Notification function */
    #endif
    Pwm_lConfigChannel(
                    0U,/* Channel reset from other channel or not*/
                    PWM_17_GTMCCU6_VARIABLE_PERIOD,/* Channel Class */
                    PWM_17_GTMCCU6_COHERENT,/* Coherency */
                    PWM_17_GTMCCU6_LOW, /* channel Idle state */
                    PWM_17_GTMCCU6_LOW  /* channel polarity */
                  ),
    (Pwm_17_GtmCcu6_PeriodType)0x0, /* Default Period */
    (uint32)0x0, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    (const void*)&Pwm_kChannelConfigGtm_Core0[3]
 /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
  * by violating this MISRA rule. */
  },
/*******************************************************************************
 *  Channel Number        : 4
 *  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_4_PWMOUT1
 *  Channel Class         : PWM_VARIABLE_PERIOD
*******************************************************************************/
  {
    4, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    #if (PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED == STD_ON)
    NULL_PTR, /* Notification function */
    #endif
    Pwm_lConfigChannel(
                    0U,/* Channel reset from other channel or not*/
                    PWM_17_GTMCCU6_VARIABLE_PERIOD,/* Channel Class */
                    PWM_17_GTMCCU6_COHERENT,/* Coherency */
                    PWM_17_GTMCCU6_LOW, /* channel Idle state */
                    PWM_17_GTMCCU6_LOW  /* channel polarity */
                  ),
    (Pwm_17_GtmCcu6_PeriodType)0x0, /* Default Period */
    (uint32)0x0, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    (const void*)&Pwm_kChannelConfigGtm_Core0[4]
 /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
  * by violating this MISRA rule. */
  },
/*******************************************************************************
 *  Channel Number        : 5
 *  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_5_PWMOUT2
 *  Channel Class         : PWM_VARIABLE_PERIOD
*******************************************************************************/
  {
    5, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    #if (PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED == STD_ON)
    NULL_PTR, /* Notification function */
    #endif
    Pwm_lConfigChannel(
                    0U,/* Channel reset from other channel or not*/
                    PWM_17_GTMCCU6_VARIABLE_PERIOD,/* Channel Class */
                    PWM_17_GTMCCU6_COHERENT,/* Coherency */
                    PWM_17_GTMCCU6_LOW, /* channel Idle state */
                    PWM_17_GTMCCU6_LOW  /* channel polarity */
                  ),
    (Pwm_17_GtmCcu6_PeriodType)0x0, /* Default Period */
    (uint32)0x0, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    (const void*)&Pwm_kChannelConfigGtm_Core0[5]
 /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
  * by violating this MISRA rule. */
  },
};
/* [cover parentID={4792FFBE-31C3-4655-841B-ABD19E034213}]
  Code data Structure for selected Core
[/cover] */
static const Pwm_17_GtmCcu6_CoreConfigType Pwm_CoreConfigCore0 =
{
  (Pwm_17_GtmCcu6_ChannelType)6U,
    (const Pwm_17_GtmCcu6_ChannelConfigType*)&Pwm_kChannelConfigurationCore0
    /* MISRA2012_RULE_1_3_JUSTIFICATION: Var Pwm_kChannelConfigurationCore<x> is 
  of type Pwm_17_GtmCcu6_ChannelConfigType. No side effects foreseen
  by violating this MISRA rule. */
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
  before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
  before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
/* MISRA2012_RULE_8_7_JUSTIFICATION: Module configuration data structure
   declaration as per Autosar guidelines. This data structure is needed
   by SW units using Pwm Driver APIs */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Definition is as per Autosar guidelines */
/* [cover parentID={64A5C335-632A-4007-B2CD-2FAC1B118DDB}]
   Pwm config structure
[/cover] */
const Pwm_17_GtmCcu6_ConfigType Pwm_17_GtmCcu6_Config =
{
  {
    /* MISRA2012_RULE_11_8_JUSTIFICATION: No side effects foreseen
   * by violating this MISRA rule */
    (Pwm_17_GtmCcu6_CoreConfigType*)&Pwm_CoreConfigCore0,
   /* MISRA2012_RULE_11_8_JUSTIFICATION: No side effects foreseen
   * by violating this MISRA rule */
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
  },
  /* MISRA2012_RULE_11_8_JUSTIFICATION: No side effects foreseen
   * by violating this MISRA rule */
  (uint8*)&Pwm_ChannelIndexMap,
  { 
    0xffffffffU,
    0xffffffffU
  }
   
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
  before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
