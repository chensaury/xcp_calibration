
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
**  FILENAME  : Icu_17_TimerIp_PBcfg.c                                        **
**                                                                            **
**  VERSION   : 10.0.0                                                        **
**                                                                            **
**  DATE, TIME: 2024-02-23, 10:02:54                                      **
**                                                                            **
**  GENERATOR : Build b170330-0431                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : NA                                                **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Icu configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Icu Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/* [cover parentID={14AF8E74-51FE-4399-8A99-5789F2CD773D}]
Icu_17_TimerIp_MemMap.h file inclusion for config data
[/cover] */

/* [cover parentID={F285FCB3-45C4-4d79-8FAE-8B06A60000B5}]  [/cover] */ 

/*******************************************************************************
**                       Includes                                             **
*******************************************************************************/

/* Include module header File */
#include "Icu_17_TimerIp.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GTM_INTERRUPT_LEVEL_MODE          (0U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GTM_INTERRUPT_PULSE_MODE          (1U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GTM_INTERRUPT_PULSE_NOTIFY_MODE   (2U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GTM_INTERRUPT_SINGLE_PULSE_MODE   (3U)

/* GTM TBU selections */
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_TIMEBASE_TBU_TS0 (0U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_TIMEBASE_TBU_TS1 (1U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_TIMEBASE_TBU_TS2 (2U)

/* CCU6 Connections */
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU6_CCINA  (0U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU6_CCINB  (1U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU6_CCINC  (2U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU6_CCIND  (3U)

/* #define for wakeup capable or not */
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_WAKEUPCAPABLE                ((uint8)1)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_NOT_WAKEUPCAPABLE            ((uint8)0)

/* Configurable Clocks used in pbcfg.h*/
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GTM_CONFIGURABLE_CLOCK_0   (0U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GTM_CONFIGURABLE_CLOCK_1   (1U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GTM_CONFIGURABLE_CLOCK_2   (2U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GTM_CONFIGURABLE_CLOCK_3   (3U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GTM_CONFIGURABLE_CLOCK_4   (4U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GTM_CONFIGURABLE_CLOCK_5   (5U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GTM_CONFIGURABLE_CLOCK_6   (6U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GTM_CONFIGURABLE_CLOCK_7   (7U)
 /*MISRA2012_RULE_2_5_JUSTIFICATION:
   Uses depends upon configuration done in configuration tool*/
#define ICU_INPUT_OF_CURRENT_TIM_CHANNEL  (0U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_INPUT_OF_PREVIOUS_TIM_CHANNEL  (1U)

/*
Configuration Options:
IcuAssignedHwunit
*/

/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_ERS0   (0U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_ERS1   (1U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_ERS2   (2U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_ERS3   (3U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_ERS4   (4U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_ERS5   (5U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_ERS6   (6U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_ERS7   (7U)

/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_INPUT_CHL_A   (0 << 3U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_INPUT_CHL_B   (1 << 3U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_INPUT_CHL_C   (2 << 3U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_INPUT_CHL_D   (3 << 3U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_INPUT_CHL_E   (4 << 3U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_INPUT_CHL_F   (5 << 3U)

/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_OGU0   (0 << 6U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_OGU1   (1 << 6U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_OGU2   (2 << 6U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_OGU3   (3 << 6U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_OGU4   (4 << 6U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_OGU5   (5 << 6U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_OGU6   (6 << 6U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_OGU7   (7 << 6U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_IMMEDIATE_EDGE_PROPAGATION_MODE   (0U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_DEGLITCH_WITH_HOLD_COUNTER   (3U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_DEGLITCH_WITH_UPDOWN_COUNTER   (1U)
/*
Define for unused ERU Line 
*/
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ERU_OGULINE_UNUSED   ((uint16)(0xFFFFU))

  /* CCU defines */
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU60_CC60 0x00U
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU60_CC61 0x10U
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU60_CC62 0x20U
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU61_CC60 0x01U
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU61_CC61 0x11U
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU61_CC62 0x21U
/*
Define for CCU6 SRC Nodes 
*/
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU6_NODE_SR0   (0U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU6_NODE_SR1   (1U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU6_NODE_SR2   (2U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CCU6_NODE_SR3   (3U)
/*
Define for GPT12 Timers 
*/
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_GPT12_T2   (0U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_GPT12_T3   (1U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_GPT12_T4   (2U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_GPT12_T5   (3U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_ASSIGN_GPT12_T6   (4U)
/*
Define for GPT12 Timer Prescalar 
*/
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GPT12_BPS1_FGPT_8   (0U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GPT12_BPS1_FGPT_4   (1U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GPT12_BPS1_FGPT_32   (2U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GPT12_BPS1_FGPT_16   (3U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GPT12_BPS2_FGPT_4   (0U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GPT12_BPS2_FGPT_2   (1U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GPT12_BPS2_FGPT_16   (2U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GPT12_BPS2_FGPT_8   (3U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_GPT12_BPSX_NONE   (0xFFU)

/*
Define for Core identification 
*/
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CORE0   (0U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CORE1   (0x100U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CORE2   (0x200U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CORE3   (0x300U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CORE4   (0x400U)
/*MISRA2012_RULE_2_5_JUSTIFICATION:
  Uses depends upon configuration done in configuration tool*/
#define ICU_CORE5   (0x500U)


/*******************************************************************************
**                      Private Function like Macros                          **
*******************************************************************************/


/*******************************************************************************
**                       Function Declarations                                **
*******************************************************************************/

/******************************************************************************/
/******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* 
   Channel Configuration 
 */
/***********Start of CORE 0 configurations**************/
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}] */
/* Memory mapping for config data */
/* [/cover] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header usage as per Autosar
   guideline.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
#include "Icu_17_TimerIp_MemMap.h"
/* [cover parentID={63629861-9B79-4f68-A58D-AB55F8757346}] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/

static const Icu_17_TimerIp_ChannelConfigType Icu_17_TimerIp_kChannelConfigCore_0[ ] =
{
  {
      /* ICU Channel 0 */
    (Icu_17_TimerIp_NotifiPtrType)0,/*Notification-function name*/
    {
      (uint8)ICU_17_TIMERIP_MODE_SIGNAL_MEASUREMENT,/*Measurement Mode*/
      (uint8)ICU_17_TIMERIP_RISING_EDGE,/*Default Start Edge */
      (uint8)ICU_17_TIMERIP_DUTY_CYCLE,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      /* Assigned Hardware Resource Number */
      /* MISRA2012_RULE_10_4_JUSTIFICATION: No side effects foreseen
        by violating this MISRA rule.*/
      /* MISRA2012_RULE_10_1_JUSTIFICATION: No side effects foreseen
        by violating this MISRA rule. */
      (uint16)19U,
      (uint8)ICU_17_TIMERIP_GTM_OPTION, /* Assigned Hw Unit */
      9, /* PinSelection */
      0U,/* Reserved */
      0U,/* Filtering time for rising edge */
      0U,/* Filtering time for falling edge */
      0U, /* Overflow ISR threshold */
      ICU_GTM_INTERRUPT_SINGLE_PULSE_MODE,/* TIM interrupt mode/ CCU6 Int Node */
      ICU_GTM_CONFIGURABLE_CLOCK_0, /* Channel Clock Select */
      ICU_TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */
      0U, /* Enables Filter for the Channel */
      /*Decides the filter Counter frequency for the TIM Channel */
      ICU_GTM_CONFIGURABLE_CLOCK_0,
      /*Decides the filter mode for rising Edge of the TIM Channel Input */
      ICU_IMMEDIATE_EDGE_PROPAGATION_MODE,
      /*Decides the filter mode for falling Edge of the TIM Channel Input */
      ICU_IMMEDIATE_EDGE_PROPAGATION_MODE,
      /*Input channel select : current chl or previous chl */
      ICU_INPUT_OF_CURRENT_TIM_CHANNEL
    },
#if (ICU_17_TIMERIP_REPORT_WAKEUP_SOURCE == STD_ON)
    {
      0U /*Not applicable*/
    },
#endif
    /* Ram needed for this channel */
    0U
  },
  {
      /* ICU Channel 1 */
    (Icu_17_TimerIp_NotifiPtrType)0,/*Notification-function name*/
    {
      (uint8)ICU_17_TIMERIP_MODE_SIGNAL_MEASUREMENT,/*Measurement Mode*/
      (uint8)ICU_17_TIMERIP_RISING_EDGE,/*Default Start Edge */
      (uint8)ICU_17_TIMERIP_DUTY_CYCLE,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      /* Assigned Hardware Resource Number */
      /* MISRA2012_RULE_10_4_JUSTIFICATION: No side effects foreseen
        by violating this MISRA rule.*/
      /* MISRA2012_RULE_10_1_JUSTIFICATION: No side effects foreseen
        by violating this MISRA rule. */
      (uint16)21U,
      (uint8)ICU_17_TIMERIP_GTM_OPTION, /* Assigned Hw Unit */
      9, /* PinSelection */
      0U,/* Reserved */
      0U,/* Filtering time for rising edge */
      0U,/* Filtering time for falling edge */
      0U, /* Overflow ISR threshold */
      ICU_GTM_INTERRUPT_LEVEL_MODE,/* TIM interrupt mode/ CCU6 Int Node */
      ICU_GTM_CONFIGURABLE_CLOCK_1, /* Channel Clock Select */
      ICU_TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */
      0U, /* Enables Filter for the Channel */
      /*Decides the filter Counter frequency for the TIM Channel */
      ICU_GTM_CONFIGURABLE_CLOCK_1,
      /*Decides the filter mode for rising Edge of the TIM Channel Input */
      ICU_IMMEDIATE_EDGE_PROPAGATION_MODE,
      /*Decides the filter mode for falling Edge of the TIM Channel Input */
      ICU_IMMEDIATE_EDGE_PROPAGATION_MODE,
      /*Input channel select : current chl or previous chl */
      ICU_INPUT_OF_CURRENT_TIM_CHANNEL
    },
#if (ICU_17_TIMERIP_REPORT_WAKEUP_SOURCE == STD_ON)
    {
      0U /*Not applicable*/
    },
#endif
    /* Ram needed for this channel */
    1U
  }
};

/*  [/cover] */

/* [cover parentID={8C015093-183F-4d05-9AB7-4F5846518315}] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/

static const Icu_17_TimerIp_CoreConfigType Icu_17_TimerIp_kConfigCore_0 =
{
  /* Pointer to Channel Configuration structure */

  &Icu_17_TimerIp_kChannelConfigCore_0[0],
  /* MaxChannelCore */
  2,
  /* chunks of union required */
  2,

};
/*  [/cover] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header usage as per Autosar
   guideline.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
#include "Icu_17_TimerIp_MemMap.h"
/***********End of CORE 0 configurations**************/

/* 
   Channel Configuration 
 */
/***********Start of CORE 1 configurations**************/
/***********End of CORE 1 configurations**************/

/* 
   Channel Configuration 
 */
/***********Start of CORE 2 configurations**************/
/***********End of CORE 2 configurations**************/

/* 
   Channel Configuration 
 */
/***********Start of CORE 3 configurations**************/
/***********End of CORE 3 configurations**************/

/* 
   Channel Configuration 
 */
/***********Start of CORE 4 configurations**************/
/***********End of CORE 4 configurations**************/

/* 
   Channel Configuration 
 */
/***********Start of CORE 5 configurations**************/
/***********End of CORE 5 configurations**************/

/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}] */
/* Memory mapping for config data */
/* [/cover] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header usage as per Autosar
   guideline.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
#include "Icu_17_TimerIp_MemMap.h"
/* MISRA2012_RULE_8_7_JUSTIFICATION: Module configuration data structure
   declaration as per Autosar guidelines. This data structure may be needed
   by SW units using Icu Driver APIs */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Definition is as per Autosar guidelines */
/* [cover parentID={C5A15715-FF71-486f-B715-DE62FDB0275C}] */

const Icu_17_TimerIp_ConfigType Icu_17_TimerIp_Config =
{
  /* Pointer to channel configuration set per core */
  {

    &Icu_17_TimerIp_kConfigCore_0,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
  },
#if (ICU_17_TIMERIP_SINGLE_CORE == STD_OFF)
  {
    (uint16)(ICU_CORE0 | (uint8)0),    
    (uint16)(ICU_CORE0 | (uint8)1)    
  },
#endif
  #if (ICU_17_TIMERIP_ERU_SIGEDGE_USED == STD_ON)
  {
    ERU_OGULINE_UNUSED,
    ERU_OGULINE_UNUSED,
    ERU_OGULINE_UNUSED,
    ERU_OGULINE_UNUSED,
    ERU_OGULINE_UNUSED,
    ERU_OGULINE_UNUSED,
    ERU_OGULINE_UNUSED,
    ERU_OGULINE_UNUSED
  },
  #endif
  #if (ICU_17_TIMERIP_GPT12_USED == STD_ON)
  ICU_GPT12_BPSX_NONE,
  ICU_GPT12_BPSX_NONE
  #endif

};
/*  [/cover] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header usage as per Autosar
   guideline.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
#include "Icu_17_TimerIp_MemMap.h"

