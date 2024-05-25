/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Application_Lcfg.c
 *   Generation Time: 2024-01-08 16:27:30
 *           Project: Bsw_Project - Version 1.0
 *          Delivery: CBD1900078_D01
 *      Tool Version: DaVinci Configurator (beta) 5.18.42 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_APPLICATION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Application_Cfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Application.h"

/* Os kernel module dependencies */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_ScheduleTable_Lcfg.h"
#include "Os_ScheduleTable.h"
#include "Os_ServiceFunction_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Timer.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: SystemApplication_OsCore0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: SystemApplication_OsCore1 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore1_Dyn;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: SystemApplication_OsCore2 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore2_Dyn;

#define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: SystemApplication_OsCore3 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore3_Dyn;

#define OS_STOP_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: SystemApplication_OsCore4 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore4_Dyn;

#define OS_STOP_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: SystemApplication_OsCore5 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore5_Dyn;

#define OS_STOP_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for application alarms: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_1ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_20ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_SchM_Core0_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtCDD_CtCDD),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtIoHardWare_Adc_Write),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtMDA_Control_Logic_MDA_Control_Logic),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtPSI5_Handler_PSI5MAIN_HD),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtPT2000_Handler_PT2000_Diag_HD),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtPT2000_Handler_PT2000_Main_HD),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtPWM_Handler_PWM_SET),
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC0SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC1SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC2SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC3SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC8SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_4),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_5),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DMACH0SR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DMACH3SR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DMACH4SR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DMACH5SR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DMACH6SR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DMACH7SR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DMACH8SR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DMACH9SR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_DMAERR0SR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GTMATOM0SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GTMATOM1SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GTMATOM2SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GTMATOM4SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GTMTIM2SR3_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GTMTIM2SR5_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GTMTOM0SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GTMTOM0SR1_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GTMTOM0SR2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GTMTOM0SR3_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_QSPI0ERR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_QSPI0PT_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_QSPI1ERR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_QSPI1PT_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_QSPI2ERR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_QSPI2PT_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_QSPI3ERR_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_QSPI3PT_ISR),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore0),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_APP_Task_Core0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Core_OsTask_CDD),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Core_OsTask_IOHW),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Core_OsTask_PSI5),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Core_OsTask_PT2000),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Init_Core0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SchM_Core0),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore0 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore0_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId        = */ OS_APPID2MASK((Os_AppAccessMaskType)SystemApplication_OsCore0),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore0_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore0_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore0_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore0_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore0_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore0_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore0_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for application alarms: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE1_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtMotor_FL_CpApMotor_FL),
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer1),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_0),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer1),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore1),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_APP_Task_Core1),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore1),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Init_Core1),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SchM_Core1),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore1 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore1 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore1_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore1,
  /* .AccessRightId        = */ OS_APPID2MASK((Os_AppAccessMaskType)SystemApplication_OsCore1),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore1_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore1_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore1_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore1_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore1_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore1_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore1_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore1_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore1
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for application alarms: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtMotor_FR_CpApMotor_FR),
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer2),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_1),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer2),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore2),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_APP_Task_Core2),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore2),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Init_Core2),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SchM_Core2),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore2 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore2 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore2_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore2,
  /* .AccessRightId        = */ OS_APPID2MASK((Os_AppAccessMaskType)SystemApplication_OsCore2),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore2_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore2_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore2_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore2_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore2_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore2_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore2_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore2_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore2
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for application alarms: SystemApplication_OsCore3 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore3_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE3_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtMotor_RL_CpApMotor_RL),
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore3 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore3_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer3),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore3 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore3_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore3 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore3_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_2),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer3),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore3),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore3 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore3_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore3 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore3_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore3 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore3_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_APP_Task_Core3),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore3),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Init_Core3),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SchM_Core3),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore3 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore3_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore3 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore3 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore3_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore3,
  /* .AccessRightId        = */ OS_APPID2MASK((Os_AppAccessMaskType)SystemApplication_OsCore3),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore3_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore3_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore3_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore3_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore3_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore3_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore3_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore3_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE3_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore3
};

#define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for application alarms: SystemApplication_OsCore4 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore4_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE4_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CtMotor_RR_CpApMotor_RR),
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore4 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore4_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer4),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore4 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore4_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore4 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore4_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_3),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer4),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore4),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore4 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore4_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore4 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore4_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore4 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore4_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_APP_Task_Core4),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore4),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Init_Core4),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SchM_Core4),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore4 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore4_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore4 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore4 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore4_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore4,
  /* .AccessRightId        = */ OS_APPID2MASK((Os_AppAccessMaskType)SystemApplication_OsCore4),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore4_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore4_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore4_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore4_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore4_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore4_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore4_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore4_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE4_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore4
};

#define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for application alarms: SystemApplication_OsCore5 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore5_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE6_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Core5swc_Runnable),
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore5 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore5_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer5),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore5 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore5_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore5 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore5_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_ISRS + 1u] =
{
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer5),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore5),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore5 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore5_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore5 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore5_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore5 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore5_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_APP_Task_Core5),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore5),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Init_Core5),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SchM_Core5),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore5 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore5_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore5 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore5 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore5_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore5,
  /* .AccessRightId        = */ OS_APPID2MASK((Os_AppAccessMaskType)SystemApplication_OsCore5),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore5_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore5_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore5_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore5_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore5_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore5_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore5_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore5_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE5_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore5
};

#define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for applications. */
CONSTP2CONST(Os_AppConfigType, OS_CONST, OS_CONST) OsCfg_AppRefs[OS_APPID_COUNT + 1] =   /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  &OsCfg_App_SystemApplication_OsCore0,
  &OsCfg_App_SystemApplication_OsCore1,
  &OsCfg_App_SystemApplication_OsCore2,
  &OsCfg_App_SystemApplication_OsCore3,
  &OsCfg_App_SystemApplication_OsCore4,
  &OsCfg_App_SystemApplication_OsCore5,
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Application_Lcfg.c
 *********************************************************************************************************************/
