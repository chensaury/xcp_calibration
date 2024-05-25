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
**  FILENAME  : Adc_Cfg.h                                                     **
**                                                                            **
**  VERSION   : 6.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2024-02-23, 10:02:53                                          **
**                                                                            **
**  GENERATOR : Build b170330-0431                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Adc.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Adc configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of ADC Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef ADC_CFG_H
#define ADC_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define ADC_AR_RELEASE_MAJOR_VERSION      (4U)
#define ADC_AR_RELEASE_MINOR_VERSION      (2U)
#define ADC_AR_RELEASE_REVISION_VERSION   (2U)

#define ADC_SW_MAJOR_VERSION  (2U)
#define ADC_SW_MINOR_VERSION  (1U)
#define ADC_SW_PATCH_VERSION  (0U)


/*
  Configuration Options: ADC_PRIORITY_IMPLEMENTATION
  Options for the Priority Mechanism supported in ADC Driver
*/
#define ADC_PRIORITY_NONE  (0U)
#define ADC_PRIORITY_HW  (1U)
#define ADC_PRIORITY_HW_SW  (2U) 

/*
  Configuration Options: ADC_RESULT_HANDLING_IMPLEMENTATION
  Options for the Result Handling Mechanism supported in ADC Driver
*/
#define ADC_INTERRUPT_MODE_RESULT_HANDLING  (0U)
#define ADC_DMA_MODE_RESULT_HANDLING  (1U)
#define ADC_POLLING_MODE_RESULT_HANDLING  (2U) 

/*
  Configuration Options: ADC_SLEEP_MODE_CFG
  Options for the Sleep Mode supported in ADC Driver
*/
#define ADC_SLEEP_MODE_ACCEPT  (0U)
#define ADC_SLEEP_MODE_REJECT  (1U)

/*
  Configuration Options: ADC_RESULT_ALIGNMENT
  Options for the Result Alignment supported in ADC Driver
*/
#define ADC_ALIGN_RIGHT  (0U)
#define ADC_ALIGN_LEFT  (1U)


/*
  Configuration Options: ADC_SUPPLY_VOLTAGE
  Options for the Supply Voltages supported in ADC Driver
*/
#define ADC_VOLTAGE_CONTROLLED_BY_SUPPLY  (0U)
#define ADC_VOLTAGE_5V  (1U)
#define ADC_VOLTAGE_3P3V  (2U)

/*
  Configuration Options for DEM
  Options for the enabling/disabling of DEM in ADC Driver
*/
#define ADC_DISABLE_DEM_REPORT  (0U)
#define ADC_ENABLE_DEM_REPORT  (1U)

/*
  Configuration Options for the setting the privilege mode in ADC Driver
*/
#define ADC_MCAL_SUPERVISOR  (0U)
#define ADC_MCAL_USER1  (1U)


/* Configuration: ADC_DEINIT_API
Adc_DeInit API configuration
- if STD_ON, Adc_DeInit API is available
- if STD_OFF, Adc_DeInit API is not available
*/
#define ADC_DEINIT_API  (STD_ON)
/* Configuration: ADC_ENABLE_START_STOP_GROUP_API
Start/Stop Group conversion API configuration
- if STD_ON, Adc_StartGroupConversion() and Adc_StopGroupConversion() Group
conversion APIs are available
- if STD_OFF, Adc_StartGroupConversion() and Adc_StopGroupConversion() Group
conversion APIs are not available
*/
#define ADC_ENABLE_START_STOP_GROUP_API  (STD_ON)
/* Configuration: ADC_HW_TRIGGER_API
Adc HW Trigger API configuration
- if STD_ON, Adc_EnableHardwareTrigger() and Adc_DisableHardwareTrigger() APIs
are available
- if STD_OFF, Adc_EnableHardwareTrigger() and Adc_DisableHardwareTrigger() APIs
are not available
*/
#define ADC_HW_TRIGGER_API  (STD_ON)
/* Configuration: ADC_READ_GROUP_API
Adc_ReadGroup API switch
- if STD_ON, Adc_ReadGroup() API is available
- if STD_OFF, Adc_ReadGroup() API is not available
*/
#define ADC_READ_GROUP_API  (STD_ON)
/* Configuration: ADC_VERSION_INFO_API
Version Information API configuration
- if STD_ON, Adc_GetVersionInfo API is available
- if STD_OFF, Adc_GetVersionInfo API is not available
*/
#define ADC_VERSION_INFO_API  (STD_OFF)
/* Configuration: ADC_STARTUP_CALIB_API
Calibration API configuration
- if STD_ON, Adc_GetStartupCalStatus() and Adc_TriggerStartupCal() API are available
- if STD_OFF, Adc_GetStartupCalStatus() and Adc_TriggerStartupCal() API are not available
*/
#define ADC_STARTUP_CALIB_API  (STD_ON)
/* Configuration: ADC_TRIGGER_ONE_CONV_ENABLE
Dummy Converison before startup calibration (Refer Errata ADC_TC.083)
- if STD_ON, Execute of one dummy conversion for each configured HW unit, before start-up calibration is triggered in the API Adc_TriggerStartupCal()
- if STD_OFF, Dont Execute of one dummy conversion for each configured HW unit, before start-up calibration is triggered in the API Adc_TriggerStartupCal()
*/
#define ADC_TRIGGER_ONE_CONV_ENABLE  (STD_OFF)
/*
Configuration: ADC_DEV_ERROR_DETECT
Preprocessor switch for enabling the development error detection and 
reporting. 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled 
*/
#define ADC_DEV_ERROR_DETECT  (STD_OFF)
/*
Configuration: ADC_ENABLE_LIMIT_CHECK
Preprocessor switch for enabling the limit checking feature of ADC. 
- if STD_ON, Limit checking feature of ADC is Enabled 
- if STD_OFF,Limit checking feature of ADC is Disabled 
*/
#define ADC_ENABLE_LIMIT_CHECK  (STD_OFF)
/* Configuration: ADC_GRP_NOTIF_CAPABILITY
Adc Notification capability configuration 
- if STD_ON, Notification capability is Enabled 
- if STD_OFF, Notification capability is Disabled 
*/
#define ADC_GRP_NOTIF_CAPABILITY  (STD_ON)
/* Configuration: ADC_ENABLE_QUEUING
Determines, if the queuing mechanism is active in case of priority mechanism 
disabled.
Note: This macro is only applicable in NO_PRIORITY MODE. Queueing is enabled 
only if AdcEnableStartStopGroupApi is set to true, since only SW triggered
groups can be Queued.
- if STD_ON, Queuing mechanism in no priority is Enabled.
- if STD_OFF, Queuing mechanism in no priority is Disabled.
*/
#define ADC_ENABLE_QUEUING  (STD_OFF)

/* Configuration: ADC_PRIORITY_IMPLEMENTATION
Determines the type of prioritization mechanism
*/
#define ADC_PRIORITY_IMPLEMENTATION  (ADC_PRIORITY_HW)

/* Configuration: ADC_RESULT_HANDLING_IMPLEMENTATION
Determines the result handling mechanism
*/
#define ADC_RESULT_HANDLING_IMPLEMENTATION  (ADC_INTERRUPT_MODE_RESULT_HANDLING)

/* Configuration: ADC_SLEEP_MODE_CFG
Determines the status of Sleep mode
*/
#define ADC_SLEEP_MODE_CFG  (ADC_SLEEP_MODE_ACCEPT)

/* Configuration: ADC_RESULT_ALIGNMENT
Determines the type of Result Alignment
*/
#define ADC_RESULT_ALIGNMENT  (ADC_ALIGN_RIGHT)

/* Configuration: ADC_SUPPLY_VOLTAGE
Determines the type of Supply Voltage
*/
#define ADC_SUPPLY_VOLTAGE  (ADC_VOLTAGE_5V)
/*
Configuration: ADC_SAFETY_ENABLE
Switch for enabling the Safety Checking feature of ADC. 
- if STD_ON, Safety checking feature of ADC is Enabled 
- if STD_OFF,Safety checking feature of ADC is Disabled 
*/
#define ADC_SAFETY_ENABLE  (STD_OFF)
/*
Configuration: ADC_INIT_CHECK_API
Switch for enabling the Init Checking feature of ADC. 
- if STD_ON, Init checking feature of ADC is Enabled 
- if STD_OFF,Init checking feature of ADC is Disabled 
*/
#define ADC_INIT_CHECK_API  (STD_ON)
/*
Configuration: ADC_MULTICORE_ERROR_DETECT
Switch for enabling the Multicore error detection feature of ADC. 
- if STD_ON, Multicore Error Detection feature of ADC is Enabled 
- if STD_OFF,Multicore Error Detection feature of ADC is Disabled 
*/
#define ADC_MULTICORE_ERROR_DETECT  (STD_OFF)
/*
Configuration: ADC_LOW_POWER_STATE_SUPPORT
Switch for enabling the Low Power States Support features of ADC. 
- if STD_ON, Low Power States Support feature of ADC is Enabled 
- if STD_OFF,Low Power States Support feature of ADC is Disabled 
*/
#define ADC_LOW_POWER_STATE_SUPPORT  (STD_OFF)
/* This parameter provides the bit state for Configured Power modes with decreasing
   power consumptions based on the instances of Adc Power State Configurations i.e.
   0th bit position indicates the 1st instances,1st bit position indicates the 2nd instances so on..*/
#define ADC_POWER_MODES_AVAILABLE  (0x00000000U)
/*
Configuration: ADC_SYNC_CONV_ENABLE
Switch for Enabling the synchronous conversions across ADC HW groups. 
- if STD_ON, Synchronous conversions across ADC HW groups is Enabled 
- if STD_OFF,Synchronous conversions across ADC HW groups is Disabled 
*/
#define ADC_SYNC_CONV_ENABLE  (STD_ON)
/* Configuration: ADC_RUN_TIME_API_MODE
Determines the privilege mode in which the runtime APIs would operate
*/
#define ADC_RUN_TIME_API_MODE  (ADC_MCAL_SUPERVISOR)

/* Configuration: ADC_INIT_DEINIT_API_MODE
Determines the privilege mode in which the Initialization and De-initialization APIs would operate
*/
#define ADC_INIT_DEINIT_API_MODE  (ADC_MCAL_SUPERVISOR)

/* Configuration: ADC_MAX_CH_CONV_TIME
Determines the maximum channel conversion time in terms of wait loop count
*/
#define ADC_MAX_CH_CONV_TIME  (6000U)
/* Configuration: ADC_CLC_FAILURE_DEM_NOTIF and ADC_E_CLC_FAILURE
   Determines whether DEM for CLC failure is enabled or disabled.
*/
#define ADC_CLC_FAILURE_DEM_NOTIF  (ADC_DISABLE_DEM_REPORT)

/* Configuration: ADC_CONV_STOP_TIME_DEM_NOTIF and ADC_E_CONV_STOP_TIME_FAILURE
   Determines whether wait counts configured at AdcMaxChConvTimeCount to
   stop the conversion is sufficient or not.
*/
#define ADC_CONV_STOP_TIME_DEM_NOTIF  (ADC_DISABLE_DEM_REPORT)


/* This parameter contains the maximum number of ADC Channel groups 
configured across HW units and configuration sets.
It is required for Queue mechanism in No Priority mode of operation.
For example, if there are 4 HW Units configured with maximum 2, 3, 4 and 5 
groups respectively in each HW Units,then ADC_MAX_GROUPS 
must be configured as 5.*/
#define ADC_MAX_GROUPS  (1U)

              
/*This parameter provides the array index for the Hw Unit 0 in the Adc_Hw_Unit
Data structure of CPU Core0. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC0_KERNEL_INDEX_CORE0  (0U)

/*This parameter provides the array index for the Hw Unit 1 in the Adc_Hw_Unit
Data structure of CPU Core0. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC1_KERNEL_INDEX_CORE0  (1U)

/*This parameter provides the array index for the Hw Unit 2 in the Adc_Hw_Unit
Data structure of CPU Core0. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC2_KERNEL_INDEX_CORE0  (2U)

/*This parameter provides the array index for the Hw Unit 3 in the Adc_Hw_Unit
Data structure of CPU Core0. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC3_KERNEL_INDEX_CORE0  (3U)

/*This parameter provides the array index for the Hw Unit 4 in the Adc_Hw_Unit
Data structure of CPU Core0. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC4_KERNEL_INDEX_CORE0  (0xFFU)

/*This parameter provides the array index for the Hw Unit 5 in the Adc_Hw_Unit
Data structure of CPU Core0. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC5_KERNEL_INDEX_CORE0  (0xFFU)

/*This parameter provides the array index for the Hw Unit 6 in the Adc_Hw_Unit
Data structure of CPU Core0. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC6_KERNEL_INDEX_CORE0  (0xFFU)

/*This parameter provides the array index for the Hw Unit 7 in the Adc_Hw_Unit
Data structure of CPU Core0. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC7_KERNEL_INDEX_CORE0  (0xFFU)

/*This parameter provides the array index for the Hw Unit 8 in the Adc_Hw_Unit
Data structure of CPU Core0. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC8_KERNEL_INDEX_CORE0  (4U)

/*This parameter provides the array index for the Hw Unit 9 in the Adc_Hw_Unit
Data structure of CPU Core0. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC9_KERNEL_INDEX_CORE0  (0xFFU)

/*This parameter provides the array index for the Hw Unit 10 in the Adc_Hw_Unit
Data structure of CPU Core0. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC10_KERNEL_INDEX_CORE0  (0xFFU)

/*This parameter provides the array index for the Hw Unit 11 in the Adc_Hw_Unit
Data structure of CPU Core0. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC11_KERNEL_INDEX_CORE0  (0xFFU)
  
/*** Group of all the indexes used for all the KERNELs on CPU Core0 ***/
#define ADCX_KERNEL_INDEX_CORE0   ADC0_KERNEL_INDEX_CORE0,\
ADC1_KERNEL_INDEX_CORE0,\
ADC2_KERNEL_INDEX_CORE0,\
ADC3_KERNEL_INDEX_CORE0,\
ADC4_KERNEL_INDEX_CORE0,\
ADC5_KERNEL_INDEX_CORE0,\
ADC6_KERNEL_INDEX_CORE0,\
ADC7_KERNEL_INDEX_CORE0,\
ADC8_KERNEL_INDEX_CORE0,\
ADC9_KERNEL_INDEX_CORE0,\
ADC10_KERNEL_INDEX_CORE0,\
ADC11_KERNEL_INDEX_CORE0
  
/* This parameter stores the maximum number of ADC HW Units configured 
on CPU Core0 across all configuration sets.*/
#define ADC_KERNEL_USED_COUNT_CORE0  (5U)


/*This parameter provides the array index for the Hw Unit 0 in the Adc_Hw_Unit
Data structure of CPU Core1. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC0_KERNEL_INDEX_CORE1  (0xFFU)

/*This parameter provides the array index for the Hw Unit 1 in the Adc_Hw_Unit
Data structure of CPU Core1. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC1_KERNEL_INDEX_CORE1  (0xFFU)

/*This parameter provides the array index for the Hw Unit 2 in the Adc_Hw_Unit
Data structure of CPU Core1. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC2_KERNEL_INDEX_CORE1  (0xFFU)

/*This parameter provides the array index for the Hw Unit 3 in the Adc_Hw_Unit
Data structure of CPU Core1. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC3_KERNEL_INDEX_CORE1  (0xFFU)

/*This parameter provides the array index for the Hw Unit 4 in the Adc_Hw_Unit
Data structure of CPU Core1. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC4_KERNEL_INDEX_CORE1  (0xFFU)

/*This parameter provides the array index for the Hw Unit 5 in the Adc_Hw_Unit
Data structure of CPU Core1. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC5_KERNEL_INDEX_CORE1  (0xFFU)

/*This parameter provides the array index for the Hw Unit 6 in the Adc_Hw_Unit
Data structure of CPU Core1. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC6_KERNEL_INDEX_CORE1  (0xFFU)

/*This parameter provides the array index for the Hw Unit 7 in the Adc_Hw_Unit
Data structure of CPU Core1. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC7_KERNEL_INDEX_CORE1  (0xFFU)

/*This parameter provides the array index for the Hw Unit 8 in the Adc_Hw_Unit
Data structure of CPU Core1. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC8_KERNEL_INDEX_CORE1  (0xFFU)

/*This parameter provides the array index for the Hw Unit 9 in the Adc_Hw_Unit
Data structure of CPU Core1. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC9_KERNEL_INDEX_CORE1  (0xFFU)

/*This parameter provides the array index for the Hw Unit 10 in the Adc_Hw_Unit
Data structure of CPU Core1. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC10_KERNEL_INDEX_CORE1  (0xFFU)

/*This parameter provides the array index for the Hw Unit 11 in the Adc_Hw_Unit
Data structure of CPU Core1. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC11_KERNEL_INDEX_CORE1  (0xFFU)
  
/*** Group of all the indexes used for all the KERNELs on CPU Core1 ***/
#define ADCX_KERNEL_INDEX_CORE1   ADC0_KERNEL_INDEX_CORE1,\
ADC1_KERNEL_INDEX_CORE1,\
ADC2_KERNEL_INDEX_CORE1,\
ADC3_KERNEL_INDEX_CORE1,\
ADC4_KERNEL_INDEX_CORE1,\
ADC5_KERNEL_INDEX_CORE1,\
ADC6_KERNEL_INDEX_CORE1,\
ADC7_KERNEL_INDEX_CORE1,\
ADC8_KERNEL_INDEX_CORE1,\
ADC9_KERNEL_INDEX_CORE1,\
ADC10_KERNEL_INDEX_CORE1,\
ADC11_KERNEL_INDEX_CORE1
  
/* This parameter stores the maximum number of ADC HW Units configured 
on CPU Core1 across all configuration sets.*/
#define ADC_KERNEL_USED_COUNT_CORE1  (0U)


/*This parameter provides the array index for the Hw Unit 0 in the Adc_Hw_Unit
Data structure of CPU Core2. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC0_KERNEL_INDEX_CORE2  (0xFFU)

/*This parameter provides the array index for the Hw Unit 1 in the Adc_Hw_Unit
Data structure of CPU Core2. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC1_KERNEL_INDEX_CORE2  (0xFFU)

/*This parameter provides the array index for the Hw Unit 2 in the Adc_Hw_Unit
Data structure of CPU Core2. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC2_KERNEL_INDEX_CORE2  (0xFFU)

/*This parameter provides the array index for the Hw Unit 3 in the Adc_Hw_Unit
Data structure of CPU Core2. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC3_KERNEL_INDEX_CORE2  (0xFFU)

/*This parameter provides the array index for the Hw Unit 4 in the Adc_Hw_Unit
Data structure of CPU Core2. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC4_KERNEL_INDEX_CORE2  (0xFFU)

/*This parameter provides the array index for the Hw Unit 5 in the Adc_Hw_Unit
Data structure of CPU Core2. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC5_KERNEL_INDEX_CORE2  (0xFFU)

/*This parameter provides the array index for the Hw Unit 6 in the Adc_Hw_Unit
Data structure of CPU Core2. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC6_KERNEL_INDEX_CORE2  (0xFFU)

/*This parameter provides the array index for the Hw Unit 7 in the Adc_Hw_Unit
Data structure of CPU Core2. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC7_KERNEL_INDEX_CORE2  (0xFFU)

/*This parameter provides the array index for the Hw Unit 8 in the Adc_Hw_Unit
Data structure of CPU Core2. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC8_KERNEL_INDEX_CORE2  (0xFFU)

/*This parameter provides the array index for the Hw Unit 9 in the Adc_Hw_Unit
Data structure of CPU Core2. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC9_KERNEL_INDEX_CORE2  (0xFFU)

/*This parameter provides the array index for the Hw Unit 10 in the Adc_Hw_Unit
Data structure of CPU Core2. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC10_KERNEL_INDEX_CORE2  (0xFFU)

/*This parameter provides the array index for the Hw Unit 11 in the Adc_Hw_Unit
Data structure of CPU Core2. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC11_KERNEL_INDEX_CORE2  (0xFFU)
  
/*** Group of all the indexes used for all the KERNELs on CPU Core2 ***/
#define ADCX_KERNEL_INDEX_CORE2   ADC0_KERNEL_INDEX_CORE2,\
ADC1_KERNEL_INDEX_CORE2,\
ADC2_KERNEL_INDEX_CORE2,\
ADC3_KERNEL_INDEX_CORE2,\
ADC4_KERNEL_INDEX_CORE2,\
ADC5_KERNEL_INDEX_CORE2,\
ADC6_KERNEL_INDEX_CORE2,\
ADC7_KERNEL_INDEX_CORE2,\
ADC8_KERNEL_INDEX_CORE2,\
ADC9_KERNEL_INDEX_CORE2,\
ADC10_KERNEL_INDEX_CORE2,\
ADC11_KERNEL_INDEX_CORE2
  
/* This parameter stores the maximum number of ADC HW Units configured 
on CPU Core2 across all configuration sets.*/
#define ADC_KERNEL_USED_COUNT_CORE2  (0U)


/*This parameter provides the array index for the Hw Unit 0 in the Adc_Hw_Unit
Data structure of CPU Core3. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC0_KERNEL_INDEX_CORE3  (0xFFU)

/*This parameter provides the array index for the Hw Unit 1 in the Adc_Hw_Unit
Data structure of CPU Core3. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC1_KERNEL_INDEX_CORE3  (0xFFU)

/*This parameter provides the array index for the Hw Unit 2 in the Adc_Hw_Unit
Data structure of CPU Core3. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC2_KERNEL_INDEX_CORE3  (0xFFU)

/*This parameter provides the array index for the Hw Unit 3 in the Adc_Hw_Unit
Data structure of CPU Core3. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC3_KERNEL_INDEX_CORE3  (0xFFU)

/*This parameter provides the array index for the Hw Unit 4 in the Adc_Hw_Unit
Data structure of CPU Core3. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC4_KERNEL_INDEX_CORE3  (0xFFU)

/*This parameter provides the array index for the Hw Unit 5 in the Adc_Hw_Unit
Data structure of CPU Core3. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC5_KERNEL_INDEX_CORE3  (0xFFU)

/*This parameter provides the array index for the Hw Unit 6 in the Adc_Hw_Unit
Data structure of CPU Core3. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC6_KERNEL_INDEX_CORE3  (0xFFU)

/*This parameter provides the array index for the Hw Unit 7 in the Adc_Hw_Unit
Data structure of CPU Core3. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC7_KERNEL_INDEX_CORE3  (0xFFU)

/*This parameter provides the array index for the Hw Unit 8 in the Adc_Hw_Unit
Data structure of CPU Core3. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC8_KERNEL_INDEX_CORE3  (0xFFU)

/*This parameter provides the array index for the Hw Unit 9 in the Adc_Hw_Unit
Data structure of CPU Core3. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC9_KERNEL_INDEX_CORE3  (0xFFU)

/*This parameter provides the array index for the Hw Unit 10 in the Adc_Hw_Unit
Data structure of CPU Core3. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC10_KERNEL_INDEX_CORE3  (0xFFU)

/*This parameter provides the array index for the Hw Unit 11 in the Adc_Hw_Unit
Data structure of CPU Core3. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC11_KERNEL_INDEX_CORE3  (0xFFU)
  
/*** Group of all the indexes used for all the KERNELs on CPU Core3 ***/
#define ADCX_KERNEL_INDEX_CORE3   ADC0_KERNEL_INDEX_CORE3,\
ADC1_KERNEL_INDEX_CORE3,\
ADC2_KERNEL_INDEX_CORE3,\
ADC3_KERNEL_INDEX_CORE3,\
ADC4_KERNEL_INDEX_CORE3,\
ADC5_KERNEL_INDEX_CORE3,\
ADC6_KERNEL_INDEX_CORE3,\
ADC7_KERNEL_INDEX_CORE3,\
ADC8_KERNEL_INDEX_CORE3,\
ADC9_KERNEL_INDEX_CORE3,\
ADC10_KERNEL_INDEX_CORE3,\
ADC11_KERNEL_INDEX_CORE3
  
/* This parameter stores the maximum number of ADC HW Units configured 
on CPU Core3 across all configuration sets.*/
#define ADC_KERNEL_USED_COUNT_CORE3  (0U)


/*This parameter provides the array index for the Hw Unit 0 in the Adc_Hw_Unit
Data structure of CPU Core4. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC0_KERNEL_INDEX_CORE4  (0xFFU)

/*This parameter provides the array index for the Hw Unit 1 in the Adc_Hw_Unit
Data structure of CPU Core4. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC1_KERNEL_INDEX_CORE4  (0xFFU)

/*This parameter provides the array index for the Hw Unit 2 in the Adc_Hw_Unit
Data structure of CPU Core4. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC2_KERNEL_INDEX_CORE4  (0xFFU)

/*This parameter provides the array index for the Hw Unit 3 in the Adc_Hw_Unit
Data structure of CPU Core4. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC3_KERNEL_INDEX_CORE4  (0xFFU)

/*This parameter provides the array index for the Hw Unit 4 in the Adc_Hw_Unit
Data structure of CPU Core4. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC4_KERNEL_INDEX_CORE4  (0xFFU)

/*This parameter provides the array index for the Hw Unit 5 in the Adc_Hw_Unit
Data structure of CPU Core4. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC5_KERNEL_INDEX_CORE4  (0xFFU)

/*This parameter provides the array index for the Hw Unit 6 in the Adc_Hw_Unit
Data structure of CPU Core4. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC6_KERNEL_INDEX_CORE4  (0xFFU)

/*This parameter provides the array index for the Hw Unit 7 in the Adc_Hw_Unit
Data structure of CPU Core4. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC7_KERNEL_INDEX_CORE4  (0xFFU)

/*This parameter provides the array index for the Hw Unit 8 in the Adc_Hw_Unit
Data structure of CPU Core4. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC8_KERNEL_INDEX_CORE4  (0xFFU)

/*This parameter provides the array index for the Hw Unit 9 in the Adc_Hw_Unit
Data structure of CPU Core4. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC9_KERNEL_INDEX_CORE4  (0xFFU)

/*This parameter provides the array index for the Hw Unit 10 in the Adc_Hw_Unit
Data structure of CPU Core4. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC10_KERNEL_INDEX_CORE4  (0xFFU)

/*This parameter provides the array index for the Hw Unit 11 in the Adc_Hw_Unit
Data structure of CPU Core4. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC11_KERNEL_INDEX_CORE4  (0xFFU)
  
/*** Group of all the indexes used for all the KERNELs on CPU Core4 ***/
#define ADCX_KERNEL_INDEX_CORE4   ADC0_KERNEL_INDEX_CORE4,\
ADC1_KERNEL_INDEX_CORE4,\
ADC2_KERNEL_INDEX_CORE4,\
ADC3_KERNEL_INDEX_CORE4,\
ADC4_KERNEL_INDEX_CORE4,\
ADC5_KERNEL_INDEX_CORE4,\
ADC6_KERNEL_INDEX_CORE4,\
ADC7_KERNEL_INDEX_CORE4,\
ADC8_KERNEL_INDEX_CORE4,\
ADC9_KERNEL_INDEX_CORE4,\
ADC10_KERNEL_INDEX_CORE4,\
ADC11_KERNEL_INDEX_CORE4
  
/* This parameter stores the maximum number of ADC HW Units configured 
on CPU Core4 across all configuration sets.*/
#define ADC_KERNEL_USED_COUNT_CORE4  (0U)


/*This parameter provides the array index for the Hw Unit 0 in the Adc_Hw_Unit
Data structure of CPU Core5. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC0_KERNEL_INDEX_CORE5  (0xFFU)

/*This parameter provides the array index for the Hw Unit 1 in the Adc_Hw_Unit
Data structure of CPU Core5. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC1_KERNEL_INDEX_CORE5  (0xFFU)

/*This parameter provides the array index for the Hw Unit 2 in the Adc_Hw_Unit
Data structure of CPU Core5. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC2_KERNEL_INDEX_CORE5  (0xFFU)

/*This parameter provides the array index for the Hw Unit 3 in the Adc_Hw_Unit
Data structure of CPU Core5. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC3_KERNEL_INDEX_CORE5  (0xFFU)

/*This parameter provides the array index for the Hw Unit 4 in the Adc_Hw_Unit
Data structure of CPU Core5. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC4_KERNEL_INDEX_CORE5  (0xFFU)

/*This parameter provides the array index for the Hw Unit 5 in the Adc_Hw_Unit
Data structure of CPU Core5. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC5_KERNEL_INDEX_CORE5  (0xFFU)

/*This parameter provides the array index for the Hw Unit 6 in the Adc_Hw_Unit
Data structure of CPU Core5. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC6_KERNEL_INDEX_CORE5  (0xFFU)

/*This parameter provides the array index for the Hw Unit 7 in the Adc_Hw_Unit
Data structure of CPU Core5. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC7_KERNEL_INDEX_CORE5  (0xFFU)

/*This parameter provides the array index for the Hw Unit 8 in the Adc_Hw_Unit
Data structure of CPU Core5. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC8_KERNEL_INDEX_CORE5  (0xFFU)

/*This parameter provides the array index for the Hw Unit 9 in the Adc_Hw_Unit
Data structure of CPU Core5. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC9_KERNEL_INDEX_CORE5  (0xFFU)

/*This parameter provides the array index for the Hw Unit 10 in the Adc_Hw_Unit
Data structure of CPU Core5. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC10_KERNEL_INDEX_CORE5  (0xFFU)

/*This parameter provides the array index for the Hw Unit 11 in the Adc_Hw_Unit
Data structure of CPU Core5. Value of 0xFF is for an unconfigured Hw Unit */
#define ADC11_KERNEL_INDEX_CORE5  (0xFFU)
  
/*** Group of all the indexes used for all the KERNELs on CPU Core5 ***/
#define ADCX_KERNEL_INDEX_CORE5   ADC0_KERNEL_INDEX_CORE5,\
ADC1_KERNEL_INDEX_CORE5,\
ADC2_KERNEL_INDEX_CORE5,\
ADC3_KERNEL_INDEX_CORE5,\
ADC4_KERNEL_INDEX_CORE5,\
ADC5_KERNEL_INDEX_CORE5,\
ADC6_KERNEL_INDEX_CORE5,\
ADC7_KERNEL_INDEX_CORE5,\
ADC8_KERNEL_INDEX_CORE5,\
ADC9_KERNEL_INDEX_CORE5,\
ADC10_KERNEL_INDEX_CORE5,\
ADC11_KERNEL_INDEX_CORE5
  
/* This parameter stores the maximum number of ADC HW Units configured 
on CPU Core5 across all configuration sets.*/
#define ADC_KERNEL_USED_COUNT_CORE5  (0U)


/* This parameter stores the maximum number of ADC HW Units present in the HW*/
#define ADC_MAX_KERNELS  (9U)

/* This parameter stores the ADC HW Unit ID of the last KERNEL + 1 present in the HW*/
#define ADC_MAX_KERNEL_ID  (12U)

/* This parameter defines the ADC HW Unit ID for the last primary KERNEL */
#define ADC_LAST_PRIMARY_KERNELID  (4U)

/* This parameter provides the Request Source available per ADC KERNEL */
#define ADC_REQSRC_COUNT (3U)

/* This parameter provides the Request Source used per ADC KERNEL */
#define ADC_REQSRC_USED_COUNT (3U)


/******Symbolic Name for all the AdcGroup with Group ID******/
/******Symbolic Name for all the AdcGroup of HW Unit 0******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcGroup_AdcGroup_G0
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcGroup_AdcGroup_G0  (0U)
#endif

/******Symbolic Name for all the AdcGroup of HW Unit 1******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcGroup_AdcGroup_G1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcGroup_AdcGroup_G1  (32U)
#endif

/******Symbolic Name for all the AdcGroup of HW Unit 2******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcGroup_AdcGroup_G2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcGroup_AdcGroup_G2  (64U)
#endif

/******Symbolic Name for all the AdcGroup of HW Unit 3******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcGroup_AdcGroup_G3
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcGroup_AdcGroup_G3  (96U)
#endif

/******Symbolic Name for all the AdcGroup of HW Unit 8******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcGroup_AdcGroup_G8
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcGroup_AdcGroup_G8  (256U)
#endif


/******Symbolic Name for all the AdcChannel with Channel ID******/
/******Symbolic Name for all the AdcChannel of HW Unit 0******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_DC8714_SO3
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_DC8714_SO3  (0U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_DC8714_SO4
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_DC8714_SO4  (1U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_DC8714_SO1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_DC8714_SO1  (2U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_KL30_uC
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_KL30_uC  (3U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_PressureRR2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_PressureRR2  (4U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_DC8714_SO2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_DC8714_SO2  (5U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_AccPedlPos
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_AccPedlPos  (6U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_BrkPedlPos
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_BrkPedlPos  (7U)
#endif

/******Symbolic Name for all the AdcChannel of HW Unit 1******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_PressureFL1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_PressureFL1  (0U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_PressureFL2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_PressureFL2  (1U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_PressureFR1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_PressureFR1  (2U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_PressureFR2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_PressureFR2  (3U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_PressureRL1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_PressureRL1  (4U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_PressureRL2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_PressureRL2  (5U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_PressureRR1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_PressureRR1  (6U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_ANI_18_uC
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_ANI_18_uC  (7U)
#endif

/******Symbolic Name for all the AdcChannel of HW Unit 2******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_SuspHeightFL
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_SuspHeightFL  (0U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_SuspHeightFR
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_SuspHeightFR  (1U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_SuspHeightRL
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_SuspHeightRL  (2U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_SuspHeightRR
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_SuspHeightRR  (3U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_AdcChannel_4
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_AdcChannel_4  (4U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_AdcChannel_5
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_AdcChannel_5  (5U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_G2H6_IMUACCX
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_G2H6_IMUACCX  (6U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_G2H7_IMUACCY
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_G2H7_IMUACCY  (7U)
#endif

/******Symbolic Name for all the AdcChannel of HW Unit 3******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_ANI_11_uC
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_ANI_11_uC  (0U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_G3H1_IMURollRate
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_G3H1_IMURollRate  (1U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_G3H2_IMUPitchRate
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_G3H2_IMUPitchRate  (2U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_G3H3_IMUYawRate
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_G3H3_IMUYawRate  (3U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_G3H4_IMURollAngle
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_G3H4_IMURollAngle  (4U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_G3H5_IMUPitchAngle
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_G3H5_IMUPitchAngle  (5U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_G3H6_IMUYawAngle
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_G3H6_IMUYawAngle  (6U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_G3H7_IMUVelNorth
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_G3H7_IMUVelNorth  (7U)
#endif

/******Symbolic Name for all the AdcChannel of HW Unit 8******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_G8H0_IMUVelEast
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_G8H0_IMUVelEast  (0U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_G8H1_IMUVelEarth
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_G8H1_IMUVelEarth  (1U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_SteerWhlAngle
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_SteerWhlAngle  (2U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_SteerWhlHandTrq
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_SteerWhlHandTrq  (3U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_SteerWhlAngleRate
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_SteerWhlAngleRate  (4U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_G8H5_IMUACCZ
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_G8H5_IMUACCZ  (5U)
#endif
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/ 
#ifndef AdcConf_AdcChannel_AdcChannel_AN38_N35
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
   in generated code due to Autosar Naming constraints.*/

#define AdcConf_AdcChannel_AdcChannel_AN38_N35  (6U)
#endif


/******Symbolic Name for Power State Config******/

#endif


