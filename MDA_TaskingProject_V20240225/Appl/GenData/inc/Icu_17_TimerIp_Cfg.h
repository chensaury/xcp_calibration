
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
**  FILENAME  : Icu_17_TimerIp_Cfg.h                                          **
**                                                                            **
**  VERSION   : 9.0.0                                                         **
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
/* [cover parentID={8AC26D8F-A810-4529-9571-EE829383AC63}] */
/*  [/cover] */
#ifndef ICU_17_TIMERIP_CFG_H
#define ICU_17_TIMERIP_CFG_H




/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*Section to Generate Autosar Specific Version Information*/

/* [cover parentID={BC4B5EEA-8EF3-4508-A932-9616FD65E7D0}] */
#define ICU_17_TIMERIP_AR_RELEASE_MAJOR_VERSION  (4U)
/*  [/cover] */
/* [cover parentID={8E4163B8-9E3E-424b-AA07-DDAF5DF3842A}] */
#define ICU_17_TIMERIP_AR_RELEASE_MINOR_VERSION  (2U)
/*  [/cover] */
/* [cover parentID={03A382FC-9EED-46f4-A322-7E270B7DDC83}] */
#define ICU_17_TIMERIP_AR_RELEASE_REVISION_VERSION  (2U)
/*  [/cover] */

/*Section to Generate Vendor Specific Version Information*/
/* Vendor specific implementation version information */
/* [cover parentID={9409C226-D472-4a6c-9D71-76B8F4E17A83}] */
#define ICU_17_TIMERIP_SW_MAJOR_VERSION   (3U)
/*  [/cover] */
/* [cover parentID={C3F168AC-A903-41cb-8DBE-4F5E3337CC2E}] */
#define ICU_17_TIMERIP_SW_MINOR_VERSION   (0U)
/*  [/cover] */
/* [cover parentID={03F840A4-DB19-4c51-B929-2E434B7E60F9}] */
#define ICU_17_TIMERIP_SW_PATCH_VERSION   (0U)
/*  [/cover] */

/*
    Configuration : ICU_17_TIMERIP_SAFETY_ENABLE
    Pre-processor switch to enable/disable the ICU driver safety features.
*/
/* [cover parentID={87E4ECE5-453F-4a5f-B2AF-3B35AABAE31F}] */
#define ICU_17_TIMERIP_SAFETY_ENABLE (STD_OFF)
/*  [/cover] */
/*
    Configuration : ICU_17_TIMERIP_INITCHECK_API
    Pre-processor switch to enable/disable the ICU init check API.
*/
/* [cover parentID={554F6FC7-4AC4-4608-8A0C-4C4D7BD75DD6}] */
#define ICU_17_TIMERIP_INITCHECK_API (STD_ON)
/*  [/cover] */

/* ICU026: General Configuration */
/*
Configuration to decide the mode of execution of Run Time API's
*/
/* [cover parentID={7DFA8562-90CA-4283-A7FB-BD59DCE8D2E3}] */
#define ICU_17_TIMERIP_RUNTIME_API_MODE     ICU_17_TIMERIP_MCAL_SUPERVISOR
/*  [/cover] */
/*
Configuration to decide the mode of execution of Init and DeInit API's
*/
/* [cover parentID={17E85140-0787-4702-9291-06C994114161}] */
#define ICU_17_TIMERIP_INIT_DEINIT_API_MODE  ICU_17_TIMERIP_MCAL_SUPERVISOR
/*  [/cover] */
/*
Configuration: ICU_17_TIMERIP_DEV_ERROR_DETECT
Adds/removes the Development Error Detection 
from the code 
- if STD_ON, Development error detection is enabled
- if STD_OFF, Development error detection is disabled
*/
/* [cover parentID={7304BC44-03B3-4635-A96A-23F8139C0E62}] */
#define ICU_17_TIMERIP_DEV_ERROR_DETECT           (STD_OFF)
/*  [/cover] */
/*
Configuration: ICU_17_TIMERIP_MULTICORE_ERROR_DETECT
Adds/removes the Multi-Core Development Error Detection 
from the code 
- if STD_ON, Multi-Core Development error detection is enabled
- if STD_OFF, Multi-Core Development error detection is disabled
*/
/* [cover parentID={ACA78BB7-4768-4cc5-9CAF-2725B3A07A5D}] */
#define ICU_17_TIMERIP_MULTICORE_ERROR_DETECT           (STD_OFF)
/*  [/cover] */
/*
Configuration: ICU_17_TIMERIP_REPORT_WAKEUP_SOURCE
Preprocessor switch to enable/disable the wakeup source reporting
- if STD_ON, Reports wakeup to higher layer
- if STD_OFF, Reporting is switched off
*/
/* [cover parentID={39695C37-0636-4440-A4B2-370FA4F81E34}] */
#define ICU_17_TIMERIP_REPORT_WAKEUP_SOURCE       (STD_OFF)
/*  [/cover] */

/*
Configuration: ICU_17_TIMERIP_DE_INIT_API
Adds/removes Icu_DeInit API 
from the code 
- if STD_ON, Icu_DeInit is enabled
- if STD_OFF, Icu_DeInit is disabled
*/
/* [cover parentID={68B0F57E-E7F2-4876-9289-451A30466201}] */
#define ICU_17_TIMERIP_DE_INIT_API                (STD_ON)
/*  [/cover] */
/*
Configuration: ICU_17_TIMERIP_DISABLE_WAKEUP_API
Adds/removes Icu_DisableWakeup API 
from the code 
- if STD_ON, Icu_DisableWakeup is enabled
- if STD_OFF, Icu_DisableWakeup is disabled
*/
/* [cover parentID={42C01C5E-163D-4446-BA59-52007E702B54}] */
#define ICU_17_TIMERIP_DISABLE_WAKEUP_API         (STD_ON)
/*  [/cover] */
/*
Configuration: ICU_17_TIMERIP_ENABLE_WAKEUP_API
Adds/removes Icu_EnableWakeup API 
from the code 
- if STD_ON, Icu_EnableWakeup is enabled
- if STD_OFF, Icu_EnableWakeup is disabled
*/
/* [cover parentID={D785661D-4F83-4767-AA7A-41EC67515059}] */
#define ICU_17_TIMERIP_ENABLE_WAKEUP_API          (STD_ON)
/*  [/cover] */
/*
Configuration: ICU_17_TIMERIP_EDGE_COUNT_API
Adds/removes Edge Count Measurement APIs 
from the code 
- if STD_ON, Icu_EnableEdgeCount, Icu_DisableEdgeCount
         Icu_ResetEdgeCount, Icu_GetEdgeNumbers is enabled
- if STD_OFF, Icu_EnableEdgeCount, Icu_DisableEdgeCount
         Icu_ResetEdgeCount, Icu_GetEdgeNumbers is disabled
*/
/* [cover parentID={71FAFB09-39CB-47aa-8095-6E6237030B32}] */
#define ICU_17_TIMERIP_EDGE_COUNT_API             (STD_ON)
/*  [/cover] */
/*
Configuration: ICU_17_TIMERIP_GET_DUTY_CYCLE_VALUES_API
Adds/removes Icu_GetDutyCycleValues API 
from the code 
- if STD_ON, Icu_GetDutyCycleValues is enabled
- if STD_OFF, Icu_GetDutyCycleValues is disabled
*/
/* [cover parentID={325B0634-D9A5-4169-863E-D83ABDF7826A}] */
#define ICU_17_TIMERIP_GET_DUTY_CYCLE_VALUES_API  (STD_ON)
/*  [/cover] */
/*
Configuration: ICU_17_TIMERIP_GET_INPUT_STATE_API
Adds/removes Icu_GetInputState API 
from the code 
- if STD_ON, Icu_GetInputState is enabled
- if STD_OFF, Icu_GetInputState is disabled
*/
/* [cover parentID={FF37A879-D575-4f41-9B26-E1EE9F89DEC4}] */
#define ICU_17_TIMERIP_GET_INPUT_STATE_API        (STD_ON)
/*  [/cover] */
/*
Configuration: ICU_17_TIMERIP_GET_TIME_ELAPSED_API
Adds/removes Icu_GetTimeElapsed API 
from the code 
- if STD_ON, Icu_GetTimeElapsed is enabled
- if STD_OFF, Icu_GetTimeElapsed is disabled
*/
/* [cover parentID={AE1E2451-EFFC-42a0-A65F-C5B3B4E8EC33}] */
#define ICU_17_TIMERIP_GET_TIME_ELAPSED_API       (STD_ON)
/*  [/cover] */
/*
Configuration: ICU_17_TIMERIP_GET_VERSION_INFO_API
Adds/removes Icu_GetVersionInfo API 
from the code 
- if STD_ON, Icu_GetVersionInfo is enabled
- if STD_OFF, Icu_GetVersionInfo is disabled
*/
/* [cover parentID={FB2C1251-9A49-4829-8DA1-2F927A1F49B6}] */
#define ICU_17_TIMERIP_GET_VERSION_INFO_API       (STD_OFF)
/*  [/cover] */
/*
Configuration: ICU_17_TIMERIP_SET_MODE_API
Adds/removes Icu_SetMode API 
from the code 
- if STD_ON, Icu_SetMode is enabled
- if STD_OFF, Icu_SetMode is disabled
*/
/* [cover parentID={E02C3468-6A06-49d8-99B4-3A50907586A3}] */
#define ICU_17_TIMERIP_SET_MODE_API               (STD_ON)
/*  [/cover] */
/*
Configuration: ICU_17_TIMERIP_TIMESTAMP_API
Adds/removes Time Stamp APIs 
from the code 
- if STD_ON, Icu_StartTimestamp, Icu_StopTimestamp
         Icu_GetTimestampIndex is enabled
- if STD_OFF, Icu_StartTimestamp, Icu_StopTimestamp
         Icu_GetTimestampIndex is disabled
*/
/* [cover parentID={F4888B17-56BA-4ec7-ADCD-34C5EF6EA3C1}] */
#define ICU_17_TIMERIP_TIMESTAMP_API              (STD_OFF)
/*  [/cover] */

/*
Configuration: ICU_17_TIMERIP_SIGNAL_MEASUREMENT_API
Adds/removes Signal Measurement APIs 
from the code 
- if STD_ON, Icu_StartSignalMeasurement, Icu_StopSignalMeasurement
         are enabled
- if STD_OFF, Icu_StartSignalMeasurement, Icu_StopSignalMeasurement
         are disabled
*/
/* [cover parentID={31B250F1-0A62-44f8-BE46-6C3C96ABB17C}] */
#define ICU_17_TIMERIP_SIGNAL_MEASUREMENT_API              (STD_ON)
/*  [/cover] */

/*
Configuration: ICU_17_TIMERIP_EDGE_DETECT_API
Adds/removes Edge Detect APIs 
from the code 
- if STD_ON, Edge Detection functionality is enabled
- if STD_OFF, Edge Detection functionality is disabled
*/
/* [cover parentID={8E6986B5-F526-441e-B934-5BE5B8795BBF}] */
#define ICU_17_TIMERIP_EDGE_DETECT_API                     (STD_ON)
/*  [/cover] */

/*
Configuration: ICU_17_TIMERIP_WAKEUP_FUNCTIONALITY_API
Adds/removes the service Icu_CheckWakeup() 
from the code 
- if ON, the service Icu_CheckWakeup() is enabled
- if OFF, the service Icu_CheckWakeup() is disabled
*/
/* [cover parentID={CFE5D177-287D-4ef8-9862-8BD06770817C}] */
#define ICU_17_TIMERIP_WAKEUP_FUNCTIONALITY_API        (STD_ON) 
/*  [/cover] */

/*
Configuration: ICU_17_TIMERIP_INSTANCE_ID
InstanceId of ICU module
*/
/* InstanceId of ICU module  */
/* [cover parentID={3864605E-440C-4549-98D0-C416DC1F9DE8}] */
#define ICU_17_TIMERIP_INSTANCE_ID       ((uint8)0)
/*  [/cover] */


/*
  Core 0 Configurations    
*/

  /* [cover parentID={BC525132-BDA7-4065-A7E7-056A9779C95C}] */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef IcuConf_IcuChannel_IcuChannel_P34_1_PWMIN1
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define IcuConf_IcuChannel_IcuChannel_P34_1_PWMIN1       ((Icu_17_TimerIp_ChannelType)0U)
#endif
/*  [/cover] */

  /* [cover parentID={BC525132-BDA7-4065-A7E7-056A9779C95C}] */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef IcuConf_IcuChannel_IcuChannel_P34_3_PWMIN2
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define IcuConf_IcuChannel_IcuChannel_P34_3_PWMIN2       ((Icu_17_TimerIp_ChannelType)1U)
#endif
/*  [/cover] */

/* Core 0 Configurations summary */
/* [cover parentID={87737856-2F5B-4e98-9266-A5B86EE6176A}] */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define ICU_17_TIMERIP_MAX_CHANNELS_CORE0                   (2U)
/*  [/cover] */
/* [cover parentID={5A803795-0344-4bef-ACBC-D7B3F18CAB5E}] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define ICU_17_TIMERIP_CHNL_DATA_MAX_CHANNELS_CORE0         (2U)
/*  [/cover] */


/*
  Core 1 Configurations    
*/

/* Core 1 Configurations summary */
/* [cover parentID={87737856-2F5B-4e98-9266-A5B86EE6176A}] */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define ICU_17_TIMERIP_MAX_CHANNELS_CORE1                   (0U)
/*  [/cover] */
/* [cover parentID={5A803795-0344-4bef-ACBC-D7B3F18CAB5E}] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define ICU_17_TIMERIP_CHNL_DATA_MAX_CHANNELS_CORE1         (0U)
/*  [/cover] */

/*
  Core 2 Configurations    
*/

/* Core 2 Configurations summary */
/* [cover parentID={87737856-2F5B-4e98-9266-A5B86EE6176A}] */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define ICU_17_TIMERIP_MAX_CHANNELS_CORE2                   (0U)
/*  [/cover] */
/* [cover parentID={5A803795-0344-4bef-ACBC-D7B3F18CAB5E}] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define ICU_17_TIMERIP_CHNL_DATA_MAX_CHANNELS_CORE2         (0U)
/*  [/cover] */

/*
  Core 3 Configurations    
*/

/* Core 3 Configurations summary */
/* [cover parentID={87737856-2F5B-4e98-9266-A5B86EE6176A}] */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define ICU_17_TIMERIP_MAX_CHANNELS_CORE3                   (0U)
/*  [/cover] */
/* [cover parentID={5A803795-0344-4bef-ACBC-D7B3F18CAB5E}] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define ICU_17_TIMERIP_CHNL_DATA_MAX_CHANNELS_CORE3         (0U)
/*  [/cover] */

/*
  Core 4 Configurations    
*/

/* Core 4 Configurations summary */
/* [cover parentID={87737856-2F5B-4e98-9266-A5B86EE6176A}] */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define ICU_17_TIMERIP_MAX_CHANNELS_CORE4                   (0U)
/*  [/cover] */
/* [cover parentID={5A803795-0344-4bef-ACBC-D7B3F18CAB5E}] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define ICU_17_TIMERIP_CHNL_DATA_MAX_CHANNELS_CORE4         (0U)
/*  [/cover] */

/*
  Core 5 Configurations    
*/

/* Core 5 Configurations summary */
/* [cover parentID={87737856-2F5B-4e98-9266-A5B86EE6176A}] */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define ICU_17_TIMERIP_MAX_CHANNELS_CORE5                   (0U)
/*  [/cover] */
/* [cover parentID={5A803795-0344-4bef-ACBC-D7B3F18CAB5E}] */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define ICU_17_TIMERIP_CHNL_DATA_MAX_CHANNELS_CORE5         (0U)
/*  [/cover] */



/***************************************************************************
TOTAL NUMBER OF CONFIGURED CHANNELS 
****************************************************************************/
/* [cover parentID={E99EED83-B152-44d0-9481-A45254ACBE20}] */
#define ICU_17_TIMERIP_MAX_CHANNELS         (2U)
/*  [/cover] */
/* Macro to idntify single core execution */
#define  ICU_17_TIMERIP_SINGLE_CORE    (STD_ON)
#define  ICU_17_TIMERIP_SINGLE_CORE_ID 0

/*
Derived parameters
Vendor specific configuration switches
Format : ICU_<HW>_<MODE>_USED  (Vendor Specific)
HW : TIM, CCU6, ERU, GPT12
STD_ON: <HW> is used for <MODE>.
STD_OFF: <HW> is not used for <MODE>.
*/
/* GTM TIM hardware resource usage */
/* [cover parentID={F5D8F328-055E-436c-9FEA-4B758D081BDE}] */
#define ICU_17_TIMERIP_GTM_TIM_USED         (STD_ON)
/*  [/cover] */
/* CCU6 hardware resource usage */
/* [cover parentID={BC11C91E-2E8A-44e7-88DA-9C743C30D069}] */
#define ICU_17_TIMERIP_CCU6_USED             (STD_OFF)
/*  [/cover] */

/* [cover parentID={5FC97717-0B33-43d5-A413-35E2F09F906E}] */
/* CCU6 Kerenl-0 allocation to ICU */
#define ICU_17_TIMERIP_CCU6_KERNEL0_USED    (STD_OFF)
/*  [/cover] */
/* [cover parentID={D83A549C-AF16-4368-9E74-ADE3CBAC1ED5}] */
/* CCU6 Kerenl-1 allocation to ICU */
#define ICU_17_TIMERIP_CCU6_KERNEL1_USED    (STD_OFF)
/*  [/cover] */

/* GPT12 hardware resource usage */
/* [cover parentID={61B3DFBB-A8F7-40f5-B00D-4DB9F37C7289}] */
#define ICU_17_TIMERIP_GPT12_USED           (STD_OFF)
/*  [/cover] */
/* ERU hardware resource usage */
/* [cover parentID={838D586C-6157-4ad3-86B2-D89029110992}] */
#define ICU_17_TIMERIP_ERU_SIGEDGE_USED     (STD_OFF)
/*  [/cover] */

#endif  /* ICU_17_TIMERIP_CFG_H */


