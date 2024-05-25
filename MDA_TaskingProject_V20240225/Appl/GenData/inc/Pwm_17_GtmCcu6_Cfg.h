
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
**  FILENAME  : Pwm_17_GtmCcu6_Cfg.h                                          **
**                                                                            **
**  VERSION   : 5.0.0                                                         **
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
#ifndef PWM_17_GTMCCU6_CFG_H
#define PWM_17_GTMCCU6_CFG_H
/* [cover parentID={75A26C19-B4C5-46bb-BA8C-4F0198C370B0}]
Header file (Generated) containing constants and pre-processor macros
[/cover] */
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
** Traceabilty      :                                                         **
*******************************************************************************/
#define PWM_17_GTMCCU6_AR_RELEASE_MAJOR_VERSION  (4U)
#define PWM_17_GTMCCU6_AR_RELEASE_MINOR_VERSION  (2U)
#define PWM_17_GTMCCU6_AR_RELEASE_REVISION_VERSION  (2U)

#define PWM_17_GTMCCU6_SW_MAJOR_VERSION  (4U)
#define PWM_17_GTMCCU6_SW_MINOR_VERSION  (0U)
#define PWM_17_GTMCCU6_SW_PATCH_VERSION  (0U)



/*
                    Container:PwmGeneral
*/
/*
  Configuration: PWM_17_GTMCCU6_DEV_ERROR_DETECT :
  Configuration of Development Error Detection 
  API Parameter Checking is enabled if this compiler
  switch is STD_ON.
  All errors are reported to Det_ReportError if the
  switch is STD_ON.
  Adds/removes the Development error detection 
  from the code 
  - if STD_ON, Development error detection is enabled
  - if STD_OFF, Development error detection is disabled
*/
/* [cover parentID={61CA5D14-580B-423d-8BD3-028AC621166B}]
  PWM_17_GTMCCU6_DEV_ERROR_DETECT
[/cover] */
#define PWM_17_GTMCCU6_DEV_ERROR_DETECT                 (STD_OFF)


/*
  Configuration: PWM_17_GTMCCU6_MULTICORE_ERROR_DETECT :
  Adds/removes the Multicore error detection and reporting 
  from the code 
  - if STD_ON, Multicore error detection and reporting is enabled
  - if STD_OFF, Multicore error detection and reporting is disabled
*/
/* [cover parentID={D3464E1D-0C54-42a7-9281-A62CE32EABCA}]
  PWM_17_GTMCCU6_MULTICORE_ERROR_DETECT
[/cover] */
#define PWM_17_GTMCCU6_MULTICORE_ERROR_DETECT                 (STD_OFF)



/* [cover parentID={279C0376-DFB7-40d8-8117-44CEA7A69219}]
  PWM_17_GTMCCU6_INSTANCE_ID
[/cover] */
/* Instance ID for PWM_17_Gtm module */
#define PWM_17_GTMCCU6_INSTANCE_ID         ((uint8)0U)

/*
  Configuration: PWM_17_GTMCCU6_DE_INIT_API
  Configuration of Pwm_DeInit API
  Adds/removes the service Pwm_DeInit() 
  from the code 
  - if STD_ON, Pwm_DeInit() can be used
  - if STD_OFF, Pwm_DeInit() cannot be used
*/
/* [cover parentID={FAD51E9B-6B1E-48be-B874-ACB3458C745D}]
  PWM_17_GTMCCU6_DE_INIT_API
[/cover] */
#define PWM_17_GTMCCU6_DE_INIT_API                      (STD_ON)


/*
  Configuration: PWM_17_GTMCCU6_GET_OUTPUT_STATE_API
  Configuration of PWM_17_GTMCCU6_GET_OUTPUT_STATE_API
  Adds/removes the service Pwm_GetOutputState() 
  from the code 
  - if STD_ON, Pwm_GetOutputState() can be used
  - if STD_OFF, Pwm_GetOutputState() cannot be used
*/
/* [cover parentID={4C591A61-3B15-424d-B2B0-0833F3285274}]
 PWM_17_GTMCCU6_GET_OUTPUT_STATE_API
[/cover] */
#define PWM_17_GTMCCU6_GET_OUTPUT_STATE_API                       (STD_ON)


/*
  Configuration: PWM_17_GTMCCU6_SET_DUTY_CYCLE_API
  Configuration of PWM_17_GTMCCU6_SET_DUTY_CYCLE_API
  Adds/removes the service Pwm_GetOutputState() 
  from the code 
  - if STD_ON, Pwm_SetDutyCycle() can be used
  - if STD_OFF,Pwm_SetDutyCycle() cannot be used
*/
/* [cover parentID={3F1AA295-573E-4121-A3C8-0F2C52A1B6FD}]
  PWM_17_GTMCCU6_SET_DUTY_CYCLE_API
[/cover] */
#define PWM_17_GTMCCU6_SET_DUTY_CYCLE_API                       (STD_ON)


/*
  Configuration: PWM_17_GTMCCU6_SET_OUTPUT_TO_IDLE_API
  Configuration of PWM_17_GTMCCU6_SET_OUTPUT_TO_IDLE_API
  Adds/removes the service Pwm_SetOutputToIdle() 
  from the code 
  - if STD_ON, Pwm_SetOutputToIdle() can be used
  - if STD_OFF,Pwm_SetOutputToIdle() cannot be used
*/
/* [cover parentID={25FD5FD2-F693-46ce-B492-CA3151EDC1DB}]
  PWM_17_GTMCCU6_SET_OUTPUT_TO_IDLE_API
[/cover] */
#define PWM_17_GTMCCU6_SET_OUTPUT_TO_IDLE_API                       (STD_ON)


/*
  Configuration: PWM_17_GTMCCU6_SET_PERIOD_AND_DUTY_API
  Configuration of PWM_17_GTMCCU6_SET_PERIOD_AND_DUTY_API
  Adds/removes the service Pwm_SetPeriodAndDuty() 
  from the code 
  - if STD_ON, Pwm_SetPeriodAndDuty() can be used
  - if STD_OFF,Pwm_SetPeriodAndDuty() cannot be used
*/
/* [cover parentID={78791071-59C8-4edd-BD07-D53A4811D6DE}]
PWM_17_GTMCCU6_SET_PERIOD_AND_DUTY_API
[/cover] */
#define PWM_17_GTMCCU6_SET_PERIOD_AND_DUTY_API                       (STD_ON)


/* Enables the handling of Shifted channel by offset
  - if STD_ON, Shifted channel is handled by offset
  - if STD_OFF, Shifted channel andled by trigger from 
               referenced Fixed period channel
*/
/* [cover parentID={2EB84631-8771-4449-A4F2-D9BF6DFA185D}]
 PWM_17_GTMCCU6_HANDLE_SHIFT_BY_OFFSET
[/cover] */
#define PWM_17_GTMCCU6_HANDLE_SHIFT_BY_OFFSET                       (STD_OFF)


/*
  Configuration: PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED
  Adds/removes the service Pwm_EnableNotification()
  and Pwm_DisableNotification() from the code 
  - if STD_ON, Notification API's can be used
  - if STD_OFF, Notification API's cannot be used
*/
/* [cover parentID={FCCD9183-235F-45b5-82E4-B604C1B328E8}]
 PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED
[/cover] */
#define PWM_17_GTMCCU6_NOTIFICATION_SUPPORTED           (STD_ON)


/*
  Configuration: PWM_NOTIFICATION_FOR_0_AND_100
  Enable Notification for 0% and 100% duty 
  - if STD_ON, Notification for 0% and 100% duty is supported
  - if STD_OFF, Notification for 0% and 100% duty is not supported
*/
/* [cover parentID={D1BDA65B-2277-4ddc-A3C8-81BFBC272A68}]
PWM_17_GTMCCU6_NOTIF_FOR_100_0_ENABLE  
[/cover] */
#define PWM_17_GTMCCU6_NOTIF_FOR_100_0_ENABLE           (STD_ON)


/*
Configuration: PWM_17_GTMCCU6_DUTYCYCLE_UPDATED_ENDPERIOD
Feature to have the duty cycle change, whether to update
the duty at the end period or not.
*/
/* [cover parentID={3C49FFF3-4799-4fad-842A-A8ACA763E9C6}]
PWM_17_GTMCCU6_DUTYCYCLE_UPDATED_ENDPERIOD
[/cover] */
#define PWM_17_GTMCCU6_DUTYCYCLE_UPDATED_ENDPERIOD      (STD_ON)


/* [cover parentID={96181217-BA79-41ac-A491-22C12491A0DF}]
PWM_17_GTMCCU6_DUTY_PERIOD_UPDATED_ENDPERIOD
[/cover] */
/*
  Configuration: PWM_DUTY_PERIOD_UPDATED_ENDPERIOD
   Applicable for Variable Period Channel Class.
   Feature to have the duty cycle / period change, whether to update
   the duty / period at the end period or not.
   */
#define PWM_17_GTMCCU6_DUTY_PERIOD_UPDATED_ENDPERIOD    (STD_ON)


/* [cover parentID={30CB4BB9-57C4-4cd6-8ED5-543788510CE4}]
 PWM_17_GTMCCU6_SAFETY_ENABLE
[/cover] */
#define PWM_17_GTMCCU6_SAFETY_ENABLE    (STD_OFF)

/* [cover parentID={1B4A7B8C-C6A8-456b-9A19-53DF826ABC68}]
 PWM_17_GTMCCU6_INITCHECK_API
[/cover] */
#define PWM_17_GTMCCU6_INITCHECK_API    (STD_ON)


/*
  Configuration: PWM_17_GTMCCU6_VERSION_INFO_API
  Adds/removes the service Pwm_GetVersionInfo() 
  from the code 
  - if STD_ON, Pwm_GetVersionInfo() can be used
  - if STD_OFF, Pwm_GetVersionInfo() cannot be used
*/
/* [cover parentID={4F0F6D7D-4008-4899-A89D-3B61AC92032B}]
 PWM_17_GTMCCU6_DUTY_SHIFT_IN_TICKS
[/cover] */
#define PWM_17_GTMCCU6_VERSION_INFO_API                 (STD_OFF)



/* Configuration : PwmDutyShiftInTicks
   This parameter enables the user to enter the duty cycle and 
   shift value in absolute ticks, instead of percentage
*/
/* [cover parentID={9707B448-7679-4bc6-9E89-A837B095B432}]
 PWM_17_GTMCCU6_DUTY_SHIFT_IN_TICKS 
[/cover] */
#define PWM_17_GTMCCU6_DUTY_SHIFT_IN_TICKS     (STD_OFF)


/* Configured PWM Channels Symbolic Names */

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#ifndef Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_0_Drive1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_0_Drive1     ((Pwm_17_GtmCcu6_ChannelType)0)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#ifndef Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_1_Drive2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_1_Drive2     ((Pwm_17_GtmCcu6_ChannelType)1)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#ifndef Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_2_Drive3
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_2_Drive3     ((Pwm_17_GtmCcu6_ChannelType)2)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#ifndef Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_3_Drive4
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_3_Drive4     ((Pwm_17_GtmCcu6_ChannelType)3)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#ifndef Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_4_PWMOUT1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_4_PWMOUT1     ((Pwm_17_GtmCcu6_ChannelType)4)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#ifndef Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_5_PWMOUT2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_5_PWMOUT2     ((Pwm_17_GtmCcu6_ChannelType)5)
#endif


/*
   Configuration:Max channels configured for Pwm, max channelas are same across
   variants.
*/

/* [cover parentID={995E2C8C-C822-4607-A21E-DFBF8C0BF9EC}]
Pwm Max Channels macro
[/cover] */
#define PWM_17_GTMCCU6_MAX_CHANNELS         ((Pwm_17_GtmCcu6_ChannelType)6)
/* [cover parentID={15AF1FE1-2C23-40c3-AAD0-DBCF55243C9F}]
PWM_17_GTMCCU6_MAX_CORES
[/cover] */
#define PWM_17_GTMCCU6_MAX_CORES            (6U)


/* Loop for all the cores */
/* [cover parentID={6191409D-6AB2-4ca6-A5D5-8A80CEAC1611}]
PWM_17_GTMCCU6_MAX_CHANNELS_CORE
[/cover] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_MAX_CHANNELS_CORE0               (6U)
/* [cover parentID={6191409D-6AB2-4ca6-A5D5-8A80CEAC1611}]
PWM_17_GTMCCU6_MAX_CHANNELS_CORE
[/cover] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_MAX_CHANNELS_CORE1               (0U)
/* [cover parentID={6191409D-6AB2-4ca6-A5D5-8A80CEAC1611}]
PWM_17_GTMCCU6_MAX_CHANNELS_CORE
[/cover] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_MAX_CHANNELS_CORE2               (0U)
/* [cover parentID={6191409D-6AB2-4ca6-A5D5-8A80CEAC1611}]
PWM_17_GTMCCU6_MAX_CHANNELS_CORE
[/cover] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_MAX_CHANNELS_CORE3               (0U)
/* [cover parentID={6191409D-6AB2-4ca6-A5D5-8A80CEAC1611}]
PWM_17_GTMCCU6_MAX_CHANNELS_CORE
[/cover] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_MAX_CHANNELS_CORE4               (0U)
/* [cover parentID={6191409D-6AB2-4ca6-A5D5-8A80CEAC1611}]
PWM_17_GTMCCU6_MAX_CHANNELS_CORE
[/cover] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_MAX_CHANNELS_CORE5               (0U)
/* [cover parentID={AD9BF8EC-C4D4-4dec-A59C-46EB5ED6502B}]
PWM_17_GTMCCU6_GTM_TIMER_USED
[/cover] */
#define PWM_17_GTMCCU6_GTM_TIMER_USED              (STD_ON)
/* [cover parentID={00ACF3E4-45EC-43c2-88F8-33426B424F23}]
PWM_17_GTMCCU6_CCU6_TIMER_USED
[/cover] */
#define PWM_17_GTMCCU6_CCU6_TIMER_USED             (STD_OFF)
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

#endif
