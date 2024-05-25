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
 *              File: Os_Core_Lcfg.c
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

#define OS_CORE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Core_Cfg.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Barrier_Lcfg.h"
#include "Os_Common.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Resource_Lcfg.h"
#include "Os_Scheduler_Lcfg.h"
#include "Os_Spinlock_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os.h"

/* Os hal dependencies */
#include "Os_Hal_Core_Cfg.h"
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Kernel_Lcfg.h"


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

#define OS_START_SEC_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core status: OsCore0 */
OS_LOCAL VAR(Os_CoreAsrStatusType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_Status_Dyn;

#define OS_STOP_SEC_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Thread class data for: OsCore0 */
OS_LOCAL VAR(Os_ThreadClassType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_ThreadClass;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core status: OsCore1 */
OS_LOCAL VAR(Os_CoreAsrStatusType, OS_VAR_NOINIT) OsCfg_Core_OsCore1_Status_Dyn;

#define OS_STOP_SEC_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Thread class data for: OsCore1 */
OS_LOCAL VAR(Os_ThreadClassType, OS_VAR_NOINIT) OsCfg_Core_OsCore1_ThreadClass;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORESTATUS_CORE2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core status: OsCore2 */
OS_LOCAL VAR(Os_CoreAsrStatusType, OS_VAR_NOINIT) OsCfg_Core_OsCore2_Status_Dyn;

#define OS_STOP_SEC_CORESTATUS_CORE2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Thread class data for: OsCore2 */
OS_LOCAL VAR(Os_ThreadClassType, OS_VAR_NOINIT) OsCfg_Core_OsCore2_ThreadClass;

#define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORESTATUS_CORE3_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core status: OsCore3 */
OS_LOCAL VAR(Os_CoreAsrStatusType, OS_VAR_NOINIT) OsCfg_Core_OsCore3_Status_Dyn;

#define OS_STOP_SEC_CORESTATUS_CORE3_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Thread class data for: OsCore3 */
OS_LOCAL VAR(Os_ThreadClassType, OS_VAR_NOINIT) OsCfg_Core_OsCore3_ThreadClass;

#define OS_STOP_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORESTATUS_CORE4_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core status: OsCore4 */
OS_LOCAL VAR(Os_CoreAsrStatusType, OS_VAR_NOINIT) OsCfg_Core_OsCore4_Status_Dyn;

#define OS_STOP_SEC_CORESTATUS_CORE4_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Thread class data for: OsCore4 */
OS_LOCAL VAR(Os_ThreadClassType, OS_VAR_NOINIT) OsCfg_Core_OsCore4_ThreadClass;

#define OS_STOP_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORESTATUS_CORE5_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core status: OsCore5 */
OS_LOCAL VAR(Os_CoreAsrStatusType, OS_VAR_NOINIT) OsCfg_Core_OsCore5_Status_Dyn;

#define OS_STOP_SEC_CORESTATUS_CORE5_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Thread class data for: OsCore5 */
OS_LOCAL VAR(Os_ThreadClassType, OS_VAR_NOINIT) OsCfg_Core_OsCore5_ThreadClass;

#define OS_STOP_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core boot barrier: OsCore0 */
OS_LOCAL VAR(Os_CoreBootBarrierType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_BootBarrier_Dyn;

/*! Dynamic core boot barrier: OsCore1 */
OS_LOCAL VAR(Os_CoreBootBarrierType, OS_VAR_NOINIT) OsCfg_Core_OsCore1_BootBarrier_Dyn;

/*! Dynamic core boot barrier: OsCore2 */
OS_LOCAL VAR(Os_CoreBootBarrierType, OS_VAR_NOINIT) OsCfg_Core_OsCore2_BootBarrier_Dyn;

/*! Dynamic core boot barrier: OsCore3 */
OS_LOCAL VAR(Os_CoreBootBarrierType, OS_VAR_NOINIT) OsCfg_Core_OsCore3_BootBarrier_Dyn;

/*! Dynamic core boot barrier: OsCore4 */
OS_LOCAL VAR(Os_CoreBootBarrierType, OS_VAR_NOINIT) OsCfg_Core_OsCore4_BootBarrier_Dyn;

/*! Dynamic core boot barrier: OsCore5 */
OS_LOCAL VAR(Os_CoreBootBarrierType, OS_VAR_NOINIT) OsCfg_Core_OsCore5_BootBarrier_Dyn;

#define OS_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core data: OsCore0 */
VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core data: OsCore1 */
VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore1_Dyn;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core data: OsCore2 */
VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore2_Dyn;

#define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core data: OsCore3 */
VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore3_Dyn;

#define OS_STOP_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core data: OsCore4 */
VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore4_Dyn;

#define OS_STOP_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core data: OsCore5 */
VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore5_Dyn;

#define OS_STOP_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for core hooks: OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_Core_OsCore0_HookRefs[OS_CFG_NUM_CORE_OSCORE0_HOOKS + 1u] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore0),
  NULL_PTR
};

/*! Object reference table for core applications: OsCore0 */
OS_LOCAL CONST(Os_AppConfigRefType, OS_CONST) OsCfg_Core_OsCore0_AppRefs[OS_CFG_NUM_CORE_OSCORE0_APPS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core IOC communications: OsCore0 */
OS_LOCAL CONST(Os_IocConfigRefType, OS_CONST) OsCfg_Core_OsCore0_IocRefs[OS_CFG_NUM_CORE_OSCORE0_IOCS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core barriers: OsCore0 */
OS_LOCAL CONST(Os_BarrierBaseConfigRefType, OS_CONST) OsCfg_Core_OsCore0_BarrierRefs[OS_CFG_NUM_BARRIERS + 1u] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */ 
{
  NULL_PTR
};

/*! Object reference table for core resources: OsCore0 */
OS_LOCAL CONST(Os_ResourceConfigRefType, OS_CONST) OsCfg_Core_OsCore0_ResourceRefs[OS_CFG_NUM_CORE_OSCORE0_RESOURCES + 1u] =
{
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_RES_SCHEDULER_OsCore0),
  NULL_PTR
};

/*! Object reference table for core stacks: OsCore0 */
OS_LOCAL CONST(Os_StackConfigRefType, OS_CONST) OsCfg_Core_OsCore0_StackRefs[OS_CFG_NUM_CORE_OSCORE0_STACKS + 1u] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_Core_OsTask_IOHW,
  (Os_StackConfigRefType) &OsCfg_Stack_Core_OsTask_PT2000,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Init,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Isr_Core,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Isr_Level22,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Isr_Level23,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Isr_Level24,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Isr_Level25,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Isr_Level48,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Kernel,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio100,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio4294967295,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio56,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio59,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio60,
  (Os_StackConfigRefType) &OsCfg_Stack_SchM_Core0,
  NULL_PTR
};

/*! Object reference table for core ISRs: OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_Core_OsCore0_IsrRefs[OS_CFG_NUM_CORE_OSCORE0_ISRS + 1u] =
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

/*! Core configuration data: OsCore0 */
CONST(Os_CoreAsrConfigType, OS_CONST) OsCfg_Core_OsCore0 =
{
  /* .Core              = */
  {
    /* .Status               = */ OS_CORE_CASTSTATUS_COREASRSTATUS_2_CORESTATUS(OsCfg_Core_OsCore0_Status_Dyn),
    /* .HwConfig             = */ &OsCfg_Hal_Core_OsCore0,
    /* .InterruptSourceRefs  = */ OsCfg_Hal_Core_OsCore0_InterruptSourceRefs,
    /* .InterruptSourceCount = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_INTERRUPTSOURCEREFS,
    /* .Id                   = */ OS_CORE_ID_0,
    /* .IsAsrCore            = */ TRUE,
    /* .IsAutostart          = */ TRUE,
    /* .IsMasterStartAllowed = */ TRUE,
    /* .HasPrivilegedHardwareAccess = */ TRUE
  },
  /* .Dyn               = */ &OsCfg_Core_OsCore0_Dyn,
  /* .Scheduler         = */ &OsCfg_Scheduler_OsCore0,
  /* .IdleTask          = */ &OsCfg_Task_IdleTask_OsCore0,
  /* .KernelApp         = */ &OsCfg_App_SystemApplication_OsCore0,
  /* .KernelStack       = */ &OsCfg_Stack_OsCore0_Kernel,
  /* .PreStartTask      = */ NULL_PTR,
  /* .StartupHookRef    = */ NULL_PTR,
  /* .ShutdownHookRef   = */ NULL_PTR,
  /* .ErrorHookRef      = */ NULL_PTR,
  /* .ProtectionHookRef = */ NULL_PTR,
  /* .InitHookRef       = */ &OsCfg_Hook_Os_CoreInitHook_OsCore0,
  /* .HookRefs          = */ OsCfg_Core_OsCore0_HookRefs,
  /* .HookCount         = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_HOOKS,
  /* .AppRefs           = */ OsCfg_Core_OsCore0_AppRefs,
  /* .AppCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_APPS,
  /* .ResourceRefs      = */ OsCfg_Core_OsCore0_ResourceRefs,
  /* .ResourceCount     = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_RESOURCES,
  /* .HwConfig          = */ &OsCfg_Hal_CoreAsr_OsCore0,
  /* .MemoryProtection  = */ NULL_PTR,
  /* .OsMpAccessRights  = */ NULL_PTR,
  /* .TimingProtection  = */ NULL_PTR,
  /* .StackRefs         = */ OsCfg_Core_OsCore0_StackRefs,
  /* .StackCount        = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_STACKS,
  /* .CoreIdx           = */ OS_COREASRCOREIDX_0,
  /* .XSignal           = */ &OsCfg_XSig_OsCore0,
  /* .IocRefs           = */ OsCfg_Core_OsCore0_IocRefs,
  /* .IocCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_IOCS,
  /* .Trace             = */ NULL_PTR,
  /* .Barrier           = */ &OsCfg_Barrier_OsCore0,
  /* .BarrierRefs       = */ OsCfg_Core_OsCore0_BarrierRefs,
  /* .BarrierCount      = */ (Os_ObjIdxType)OS_CFG_NUM_BARRIERS,
  /* .ThreadClass       = */ &OsCfg_Core_OsCore0_ThreadClass,
  /* .IsrRefs           = */ OsCfg_Core_OsCore0_IsrRefs,
  /* .IsrCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_ISRS
}
;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for core hooks: OsCore1 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_Core_OsCore1_HookRefs[OS_CFG_NUM_CORE_OSCORE1_HOOKS + 1u] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore1),
  NULL_PTR
};

/*! Object reference table for core applications: OsCore1 */
OS_LOCAL CONST(Os_AppConfigRefType, OS_CONST) OsCfg_Core_OsCore1_AppRefs[OS_CFG_NUM_CORE_OSCORE1_APPS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core IOC communications: OsCore1 */
OS_LOCAL CONST(Os_IocConfigRefType, OS_CONST) OsCfg_Core_OsCore1_IocRefs[OS_CFG_NUM_CORE_OSCORE1_IOCS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core barriers: OsCore1 */
OS_LOCAL CONST(Os_BarrierBaseConfigRefType, OS_CONST) OsCfg_Core_OsCore1_BarrierRefs[OS_CFG_NUM_BARRIERS + 1u] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */ 
{
  NULL_PTR
};

/*! Object reference table for core resources: OsCore1 */
OS_LOCAL CONST(Os_ResourceConfigRefType, OS_CONST) OsCfg_Core_OsCore1_ResourceRefs[OS_CFG_NUM_CORE_OSCORE1_RESOURCES + 1u] =
{
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_RES_SCHEDULER_OsCore1),
  NULL_PTR
};

/*! Object reference table for core stacks: OsCore1 */
OS_LOCAL CONST(Os_StackConfigRefType, OS_CONST) OsCfg_Core_OsCore1_StackRefs[OS_CFG_NUM_CORE_OSCORE1_STACKS + 1u] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore1_Init,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore1_Isr_Core,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore1_Kernel,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore1_Task_Prio100,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore1_Task_Prio20,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore1_Task_Prio4294967295,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore1_Task_Prio50,
  NULL_PTR
};

/*! Object reference table for core ISRs: OsCore1 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_Core_OsCore1_IsrRefs[OS_CFG_NUM_CORE_OSCORE1_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_0), 
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer1), 
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore1), 
  NULL_PTR
};

/*! Core configuration data: OsCore1 */
CONST(Os_CoreAsrConfigType, OS_CONST) OsCfg_Core_OsCore1 =
{
  /* .Core              = */
  {
    /* .Status               = */ OS_CORE_CASTSTATUS_COREASRSTATUS_2_CORESTATUS(OsCfg_Core_OsCore1_Status_Dyn),
    /* .HwConfig             = */ &OsCfg_Hal_Core_OsCore1,
    /* .InterruptSourceRefs  = */ OsCfg_Hal_Core_OsCore1_InterruptSourceRefs,
    /* .InterruptSourceCount = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE1_INTERRUPTSOURCEREFS,
    /* .Id                   = */ OS_CORE_ID_1,
    /* .IsAsrCore            = */ TRUE,
    /* .IsAutostart          = */ FALSE,
    /* .IsMasterStartAllowed = */ FALSE,
    /* .HasPrivilegedHardwareAccess = */ FALSE
  },
  /* .Dyn               = */ &OsCfg_Core_OsCore1_Dyn,
  /* .Scheduler         = */ &OsCfg_Scheduler_OsCore1,
  /* .IdleTask          = */ &OsCfg_Task_IdleTask_OsCore1,
  /* .KernelApp         = */ &OsCfg_App_SystemApplication_OsCore1,
  /* .KernelStack       = */ &OsCfg_Stack_OsCore1_Kernel,
  /* .PreStartTask      = */ NULL_PTR,
  /* .StartupHookRef    = */ NULL_PTR,
  /* .ShutdownHookRef   = */ NULL_PTR,
  /* .ErrorHookRef      = */ NULL_PTR,
  /* .ProtectionHookRef = */ NULL_PTR,
  /* .InitHookRef       = */ &OsCfg_Hook_Os_CoreInitHook_OsCore1,
  /* .HookRefs          = */ OsCfg_Core_OsCore1_HookRefs,
  /* .HookCount         = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE1_HOOKS,
  /* .AppRefs           = */ OsCfg_Core_OsCore1_AppRefs,
  /* .AppCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE1_APPS,
  /* .ResourceRefs      = */ OsCfg_Core_OsCore1_ResourceRefs,
  /* .ResourceCount     = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE1_RESOURCES,
  /* .HwConfig          = */ &OsCfg_Hal_CoreAsr_OsCore1,
  /* .MemoryProtection  = */ NULL_PTR,
  /* .OsMpAccessRights  = */ NULL_PTR,
  /* .TimingProtection  = */ NULL_PTR,
  /* .StackRefs         = */ OsCfg_Core_OsCore1_StackRefs,
  /* .StackCount        = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE1_STACKS,
  /* .CoreIdx           = */ OS_COREASRCOREIDX_1,
  /* .XSignal           = */ &OsCfg_XSig_OsCore1,
  /* .IocRefs           = */ OsCfg_Core_OsCore1_IocRefs,
  /* .IocCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE1_IOCS,
  /* .Trace             = */ NULL_PTR,
  /* .Barrier           = */ &OsCfg_Barrier_OsCore1,
  /* .BarrierRefs       = */ OsCfg_Core_OsCore1_BarrierRefs,
  /* .BarrierCount      = */ (Os_ObjIdxType)OS_CFG_NUM_BARRIERS,
  /* .ThreadClass       = */ &OsCfg_Core_OsCore1_ThreadClass,
  /* .IsrRefs           = */ OsCfg_Core_OsCore1_IsrRefs,
  /* .IsrCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE1_ISRS
}
;

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for core hooks: OsCore2 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_Core_OsCore2_HookRefs[OS_CFG_NUM_CORE_OSCORE2_HOOKS + 1u] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore2),
  NULL_PTR
};

/*! Object reference table for core applications: OsCore2 */
OS_LOCAL CONST(Os_AppConfigRefType, OS_CONST) OsCfg_Core_OsCore2_AppRefs[OS_CFG_NUM_CORE_OSCORE2_APPS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core IOC communications: OsCore2 */
OS_LOCAL CONST(Os_IocConfigRefType, OS_CONST) OsCfg_Core_OsCore2_IocRefs[OS_CFG_NUM_CORE_OSCORE2_IOCS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core barriers: OsCore2 */
OS_LOCAL CONST(Os_BarrierBaseConfigRefType, OS_CONST) OsCfg_Core_OsCore2_BarrierRefs[OS_CFG_NUM_BARRIERS + 1u] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */ 
{
  NULL_PTR
};

/*! Object reference table for core resources: OsCore2 */
OS_LOCAL CONST(Os_ResourceConfigRefType, OS_CONST) OsCfg_Core_OsCore2_ResourceRefs[OS_CFG_NUM_CORE_OSCORE2_RESOURCES + 1u] =
{
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_RES_SCHEDULER_OsCore2),
  NULL_PTR
};

/*! Object reference table for core stacks: OsCore2 */
OS_LOCAL CONST(Os_StackConfigRefType, OS_CONST) OsCfg_Core_OsCore2_StackRefs[OS_CFG_NUM_CORE_OSCORE2_STACKS + 1u] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore2_Init,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore2_Isr_Core,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore2_Kernel,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore2_Task_Prio100,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore2_Task_Prio20,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore2_Task_Prio4294967295,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore2_Task_Prio50,
  NULL_PTR
};

/*! Object reference table for core ISRs: OsCore2 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_Core_OsCore2_IsrRefs[OS_CFG_NUM_CORE_OSCORE2_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_1), 
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer2), 
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore2), 
  NULL_PTR
};

/*! Core configuration data: OsCore2 */
CONST(Os_CoreAsrConfigType, OS_CONST) OsCfg_Core_OsCore2 =
{
  /* .Core              = */
  {
    /* .Status               = */ OS_CORE_CASTSTATUS_COREASRSTATUS_2_CORESTATUS(OsCfg_Core_OsCore2_Status_Dyn),
    /* .HwConfig             = */ &OsCfg_Hal_Core_OsCore2,
    /* .InterruptSourceRefs  = */ OsCfg_Hal_Core_OsCore2_InterruptSourceRefs,
    /* .InterruptSourceCount = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE2_INTERRUPTSOURCEREFS,
    /* .Id                   = */ OS_CORE_ID_2,
    /* .IsAsrCore            = */ TRUE,
    /* .IsAutostart          = */ FALSE,
    /* .IsMasterStartAllowed = */ FALSE,
    /* .HasPrivilegedHardwareAccess = */ FALSE
  },
  /* .Dyn               = */ &OsCfg_Core_OsCore2_Dyn,
  /* .Scheduler         = */ &OsCfg_Scheduler_OsCore2,
  /* .IdleTask          = */ &OsCfg_Task_IdleTask_OsCore2,
  /* .KernelApp         = */ &OsCfg_App_SystemApplication_OsCore2,
  /* .KernelStack       = */ &OsCfg_Stack_OsCore2_Kernel,
  /* .PreStartTask      = */ NULL_PTR,
  /* .StartupHookRef    = */ NULL_PTR,
  /* .ShutdownHookRef   = */ NULL_PTR,
  /* .ErrorHookRef      = */ NULL_PTR,
  /* .ProtectionHookRef = */ NULL_PTR,
  /* .InitHookRef       = */ &OsCfg_Hook_Os_CoreInitHook_OsCore2,
  /* .HookRefs          = */ OsCfg_Core_OsCore2_HookRefs,
  /* .HookCount         = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE2_HOOKS,
  /* .AppRefs           = */ OsCfg_Core_OsCore2_AppRefs,
  /* .AppCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE2_APPS,
  /* .ResourceRefs      = */ OsCfg_Core_OsCore2_ResourceRefs,
  /* .ResourceCount     = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE2_RESOURCES,
  /* .HwConfig          = */ &OsCfg_Hal_CoreAsr_OsCore2,
  /* .MemoryProtection  = */ NULL_PTR,
  /* .OsMpAccessRights  = */ NULL_PTR,
  /* .TimingProtection  = */ NULL_PTR,
  /* .StackRefs         = */ OsCfg_Core_OsCore2_StackRefs,
  /* .StackCount        = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE2_STACKS,
  /* .CoreIdx           = */ OS_COREASRCOREIDX_2,
  /* .XSignal           = */ &OsCfg_XSig_OsCore2,
  /* .IocRefs           = */ OsCfg_Core_OsCore2_IocRefs,
  /* .IocCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE2_IOCS,
  /* .Trace             = */ NULL_PTR,
  /* .Barrier           = */ &OsCfg_Barrier_OsCore2,
  /* .BarrierRefs       = */ OsCfg_Core_OsCore2_BarrierRefs,
  /* .BarrierCount      = */ (Os_ObjIdxType)OS_CFG_NUM_BARRIERS,
  /* .ThreadClass       = */ &OsCfg_Core_OsCore2_ThreadClass,
  /* .IsrRefs           = */ OsCfg_Core_OsCore2_IsrRefs,
  /* .IsrCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE2_ISRS
}
;

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for core hooks: OsCore3 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_Core_OsCore3_HookRefs[OS_CFG_NUM_CORE_OSCORE3_HOOKS + 1u] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore3),
  NULL_PTR
};

/*! Object reference table for core applications: OsCore3 */
OS_LOCAL CONST(Os_AppConfigRefType, OS_CONST) OsCfg_Core_OsCore3_AppRefs[OS_CFG_NUM_CORE_OSCORE3_APPS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core IOC communications: OsCore3 */
OS_LOCAL CONST(Os_IocConfigRefType, OS_CONST) OsCfg_Core_OsCore3_IocRefs[OS_CFG_NUM_CORE_OSCORE3_IOCS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core barriers: OsCore3 */
OS_LOCAL CONST(Os_BarrierBaseConfigRefType, OS_CONST) OsCfg_Core_OsCore3_BarrierRefs[OS_CFG_NUM_BARRIERS + 1u] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */ 
{
  NULL_PTR
};

/*! Object reference table for core resources: OsCore3 */
OS_LOCAL CONST(Os_ResourceConfigRefType, OS_CONST) OsCfg_Core_OsCore3_ResourceRefs[OS_CFG_NUM_CORE_OSCORE3_RESOURCES + 1u] =
{
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_RES_SCHEDULER_OsCore3),
  NULL_PTR
};

/*! Object reference table for core stacks: OsCore3 */
OS_LOCAL CONST(Os_StackConfigRefType, OS_CONST) OsCfg_Core_OsCore3_StackRefs[OS_CFG_NUM_CORE_OSCORE3_STACKS + 1u] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore3_Init,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore3_Isr_Core,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore3_Kernel,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore3_Task_Prio100,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore3_Task_Prio20,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore3_Task_Prio4294967295,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore3_Task_Prio50,
  NULL_PTR
};

/*! Object reference table for core ISRs: OsCore3 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_Core_OsCore3_IsrRefs[OS_CFG_NUM_CORE_OSCORE3_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_2), 
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer3), 
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore3), 
  NULL_PTR
};

/*! Core configuration data: OsCore3 */
CONST(Os_CoreAsrConfigType, OS_CONST) OsCfg_Core_OsCore3 =
{
  /* .Core              = */
  {
    /* .Status               = */ OS_CORE_CASTSTATUS_COREASRSTATUS_2_CORESTATUS(OsCfg_Core_OsCore3_Status_Dyn),
    /* .HwConfig             = */ &OsCfg_Hal_Core_OsCore3,
    /* .InterruptSourceRefs  = */ OsCfg_Hal_Core_OsCore3_InterruptSourceRefs,
    /* .InterruptSourceCount = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE3_INTERRUPTSOURCEREFS,
    /* .Id                   = */ OS_CORE_ID_3,
    /* .IsAsrCore            = */ TRUE,
    /* .IsAutostart          = */ FALSE,
    /* .IsMasterStartAllowed = */ FALSE,
    /* .HasPrivilegedHardwareAccess = */ FALSE
  },
  /* .Dyn               = */ &OsCfg_Core_OsCore3_Dyn,
  /* .Scheduler         = */ &OsCfg_Scheduler_OsCore3,
  /* .IdleTask          = */ &OsCfg_Task_IdleTask_OsCore3,
  /* .KernelApp         = */ &OsCfg_App_SystemApplication_OsCore3,
  /* .KernelStack       = */ &OsCfg_Stack_OsCore3_Kernel,
  /* .PreStartTask      = */ NULL_PTR,
  /* .StartupHookRef    = */ NULL_PTR,
  /* .ShutdownHookRef   = */ NULL_PTR,
  /* .ErrorHookRef      = */ NULL_PTR,
  /* .ProtectionHookRef = */ NULL_PTR,
  /* .InitHookRef       = */ &OsCfg_Hook_Os_CoreInitHook_OsCore3,
  /* .HookRefs          = */ OsCfg_Core_OsCore3_HookRefs,
  /* .HookCount         = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE3_HOOKS,
  /* .AppRefs           = */ OsCfg_Core_OsCore3_AppRefs,
  /* .AppCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE3_APPS,
  /* .ResourceRefs      = */ OsCfg_Core_OsCore3_ResourceRefs,
  /* .ResourceCount     = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE3_RESOURCES,
  /* .HwConfig          = */ &OsCfg_Hal_CoreAsr_OsCore3,
  /* .MemoryProtection  = */ NULL_PTR,
  /* .OsMpAccessRights  = */ NULL_PTR,
  /* .TimingProtection  = */ NULL_PTR,
  /* .StackRefs         = */ OsCfg_Core_OsCore3_StackRefs,
  /* .StackCount        = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE3_STACKS,
  /* .CoreIdx           = */ OS_COREASRCOREIDX_3,
  /* .XSignal           = */ &OsCfg_XSig_OsCore3,
  /* .IocRefs           = */ OsCfg_Core_OsCore3_IocRefs,
  /* .IocCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE3_IOCS,
  /* .Trace             = */ NULL_PTR,
  /* .Barrier           = */ &OsCfg_Barrier_OsCore3,
  /* .BarrierRefs       = */ OsCfg_Core_OsCore3_BarrierRefs,
  /* .BarrierCount      = */ (Os_ObjIdxType)OS_CFG_NUM_BARRIERS,
  /* .ThreadClass       = */ &OsCfg_Core_OsCore3_ThreadClass,
  /* .IsrRefs           = */ OsCfg_Core_OsCore3_IsrRefs,
  /* .IsrCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE3_ISRS
}
;

#define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for core hooks: OsCore4 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_Core_OsCore4_HookRefs[OS_CFG_NUM_CORE_OSCORE4_HOOKS + 1u] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore4),
  NULL_PTR
};

/*! Object reference table for core applications: OsCore4 */
OS_LOCAL CONST(Os_AppConfigRefType, OS_CONST) OsCfg_Core_OsCore4_AppRefs[OS_CFG_NUM_CORE_OSCORE4_APPS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core IOC communications: OsCore4 */
OS_LOCAL CONST(Os_IocConfigRefType, OS_CONST) OsCfg_Core_OsCore4_IocRefs[OS_CFG_NUM_CORE_OSCORE4_IOCS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core barriers: OsCore4 */
OS_LOCAL CONST(Os_BarrierBaseConfigRefType, OS_CONST) OsCfg_Core_OsCore4_BarrierRefs[OS_CFG_NUM_BARRIERS + 1u] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */ 
{
  NULL_PTR
};

/*! Object reference table for core resources: OsCore4 */
OS_LOCAL CONST(Os_ResourceConfigRefType, OS_CONST) OsCfg_Core_OsCore4_ResourceRefs[OS_CFG_NUM_CORE_OSCORE4_RESOURCES + 1u] =
{
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_RES_SCHEDULER_OsCore4),
  NULL_PTR
};

/*! Object reference table for core stacks: OsCore4 */
OS_LOCAL CONST(Os_StackConfigRefType, OS_CONST) OsCfg_Core_OsCore4_StackRefs[OS_CFG_NUM_CORE_OSCORE4_STACKS + 1u] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore4_Init,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore4_Isr_Core,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore4_Kernel,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore4_Task_Prio100,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore4_Task_Prio20,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore4_Task_Prio4294967295,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore4_Task_Prio50,
  NULL_PTR
};

/*! Object reference table for core ISRs: OsCore4 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_Core_OsCore4_IsrRefs[OS_CFG_NUM_CORE_OSCORE4_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_3), 
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer4), 
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore4), 
  NULL_PTR
};

/*! Core configuration data: OsCore4 */
CONST(Os_CoreAsrConfigType, OS_CONST) OsCfg_Core_OsCore4 =
{
  /* .Core              = */
  {
    /* .Status               = */ OS_CORE_CASTSTATUS_COREASRSTATUS_2_CORESTATUS(OsCfg_Core_OsCore4_Status_Dyn),
    /* .HwConfig             = */ &OsCfg_Hal_Core_OsCore4,
    /* .InterruptSourceRefs  = */ OsCfg_Hal_Core_OsCore4_InterruptSourceRefs,
    /* .InterruptSourceCount = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE4_INTERRUPTSOURCEREFS,
    /* .Id                   = */ OS_CORE_ID_4,
    /* .IsAsrCore            = */ TRUE,
    /* .IsAutostart          = */ FALSE,
    /* .IsMasterStartAllowed = */ FALSE,
    /* .HasPrivilegedHardwareAccess = */ FALSE
  },
  /* .Dyn               = */ &OsCfg_Core_OsCore4_Dyn,
  /* .Scheduler         = */ &OsCfg_Scheduler_OsCore4,
  /* .IdleTask          = */ &OsCfg_Task_IdleTask_OsCore4,
  /* .KernelApp         = */ &OsCfg_App_SystemApplication_OsCore4,
  /* .KernelStack       = */ &OsCfg_Stack_OsCore4_Kernel,
  /* .PreStartTask      = */ NULL_PTR,
  /* .StartupHookRef    = */ NULL_PTR,
  /* .ShutdownHookRef   = */ NULL_PTR,
  /* .ErrorHookRef      = */ NULL_PTR,
  /* .ProtectionHookRef = */ NULL_PTR,
  /* .InitHookRef       = */ &OsCfg_Hook_Os_CoreInitHook_OsCore4,
  /* .HookRefs          = */ OsCfg_Core_OsCore4_HookRefs,
  /* .HookCount         = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE4_HOOKS,
  /* .AppRefs           = */ OsCfg_Core_OsCore4_AppRefs,
  /* .AppCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE4_APPS,
  /* .ResourceRefs      = */ OsCfg_Core_OsCore4_ResourceRefs,
  /* .ResourceCount     = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE4_RESOURCES,
  /* .HwConfig          = */ &OsCfg_Hal_CoreAsr_OsCore4,
  /* .MemoryProtection  = */ NULL_PTR,
  /* .OsMpAccessRights  = */ NULL_PTR,
  /* .TimingProtection  = */ NULL_PTR,
  /* .StackRefs         = */ OsCfg_Core_OsCore4_StackRefs,
  /* .StackCount        = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE4_STACKS,
  /* .CoreIdx           = */ OS_COREASRCOREIDX_4,
  /* .XSignal           = */ &OsCfg_XSig_OsCore4,
  /* .IocRefs           = */ OsCfg_Core_OsCore4_IocRefs,
  /* .IocCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE4_IOCS,
  /* .Trace             = */ NULL_PTR,
  /* .Barrier           = */ &OsCfg_Barrier_OsCore4,
  /* .BarrierRefs       = */ OsCfg_Core_OsCore4_BarrierRefs,
  /* .BarrierCount      = */ (Os_ObjIdxType)OS_CFG_NUM_BARRIERS,
  /* .ThreadClass       = */ &OsCfg_Core_OsCore4_ThreadClass,
  /* .IsrRefs           = */ OsCfg_Core_OsCore4_IsrRefs,
  /* .IsrCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE4_ISRS
}
;

#define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for core hooks: OsCore5 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_Core_OsCore5_HookRefs[OS_CFG_NUM_CORE_OSCORE5_HOOKS + 1u] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore5),
  NULL_PTR
};

/*! Object reference table for core applications: OsCore5 */
OS_LOCAL CONST(Os_AppConfigRefType, OS_CONST) OsCfg_Core_OsCore5_AppRefs[OS_CFG_NUM_CORE_OSCORE5_APPS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core IOC communications: OsCore5 */
OS_LOCAL CONST(Os_IocConfigRefType, OS_CONST) OsCfg_Core_OsCore5_IocRefs[OS_CFG_NUM_CORE_OSCORE5_IOCS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core barriers: OsCore5 */
OS_LOCAL CONST(Os_BarrierBaseConfigRefType, OS_CONST) OsCfg_Core_OsCore5_BarrierRefs[OS_CFG_NUM_BARRIERS + 1u] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */ 
{
  NULL_PTR
};

/*! Object reference table for core resources: OsCore5 */
OS_LOCAL CONST(Os_ResourceConfigRefType, OS_CONST) OsCfg_Core_OsCore5_ResourceRefs[OS_CFG_NUM_CORE_OSCORE5_RESOURCES + 1u] =
{
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_RES_SCHEDULER_OsCore5),
  NULL_PTR
};

/*! Object reference table for core stacks: OsCore5 */
OS_LOCAL CONST(Os_StackConfigRefType, OS_CONST) OsCfg_Core_OsCore5_StackRefs[OS_CFG_NUM_CORE_OSCORE5_STACKS + 1u] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore5_Init,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore5_Isr_Core,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore5_Kernel,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore5_Task_Prio100,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore5_Task_Prio20,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore5_Task_Prio4294967295,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore5_Task_Prio50,
  NULL_PTR
};

/*! Object reference table for core ISRs: OsCore5 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_Core_OsCore5_IsrRefs[OS_CFG_NUM_CORE_OSCORE5_ISRS + 1u] =
{
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer5), 
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore5), 
  NULL_PTR
};

/*! Core configuration data: OsCore5 */
CONST(Os_CoreAsrConfigType, OS_CONST) OsCfg_Core_OsCore5 =
{
  /* .Core              = */
  {
    /* .Status               = */ OS_CORE_CASTSTATUS_COREASRSTATUS_2_CORESTATUS(OsCfg_Core_OsCore5_Status_Dyn),
    /* .HwConfig             = */ &OsCfg_Hal_Core_OsCore5,
    /* .InterruptSourceRefs  = */ OsCfg_Hal_Core_OsCore5_InterruptSourceRefs,
    /* .InterruptSourceCount = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE5_INTERRUPTSOURCEREFS,
    /* .Id                   = */ OS_CORE_ID_5,
    /* .IsAsrCore            = */ TRUE,
    /* .IsAutostart          = */ FALSE,
    /* .IsMasterStartAllowed = */ FALSE,
    /* .HasPrivilegedHardwareAccess = */ FALSE
  },
  /* .Dyn               = */ &OsCfg_Core_OsCore5_Dyn,
  /* .Scheduler         = */ &OsCfg_Scheduler_OsCore5,
  /* .IdleTask          = */ &OsCfg_Task_IdleTask_OsCore5,
  /* .KernelApp         = */ &OsCfg_App_SystemApplication_OsCore5,
  /* .KernelStack       = */ &OsCfg_Stack_OsCore5_Kernel,
  /* .PreStartTask      = */ NULL_PTR,
  /* .StartupHookRef    = */ NULL_PTR,
  /* .ShutdownHookRef   = */ NULL_PTR,
  /* .ErrorHookRef      = */ NULL_PTR,
  /* .ProtectionHookRef = */ NULL_PTR,
  /* .InitHookRef       = */ &OsCfg_Hook_Os_CoreInitHook_OsCore5,
  /* .HookRefs          = */ OsCfg_Core_OsCore5_HookRefs,
  /* .HookCount         = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE5_HOOKS,
  /* .AppRefs           = */ OsCfg_Core_OsCore5_AppRefs,
  /* .AppCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE5_APPS,
  /* .ResourceRefs      = */ OsCfg_Core_OsCore5_ResourceRefs,
  /* .ResourceCount     = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE5_RESOURCES,
  /* .HwConfig          = */ &OsCfg_Hal_CoreAsr_OsCore5,
  /* .MemoryProtection  = */ NULL_PTR,
  /* .OsMpAccessRights  = */ NULL_PTR,
  /* .TimingProtection  = */ NULL_PTR,
  /* .StackRefs         = */ OsCfg_Core_OsCore5_StackRefs,
  /* .StackCount        = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE5_STACKS,
  /* .CoreIdx           = */ OS_COREASRCOREIDX_5,
  /* .XSignal           = */ &OsCfg_XSig_OsCore5,
  /* .IocRefs           = */ OsCfg_Core_OsCore5_IocRefs,
  /* .IocCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE5_IOCS,
  /* .Trace             = */ NULL_PTR,
  /* .Barrier           = */ &OsCfg_Barrier_OsCore5,
  /* .BarrierRefs       = */ OsCfg_Core_OsCore5_BarrierRefs,
  /* .BarrierCount      = */ (Os_ObjIdxType)OS_CFG_NUM_BARRIERS,
  /* .ThreadClass       = */ &OsCfg_Core_OsCore5_ThreadClass,
  /* .IsrRefs           = */ OsCfg_Core_OsCore5_IsrRefs,
  /* .IsrCount          = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE5_ISRS
}
;

#define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for system spinlocks. */
OS_LOCAL CONST(Os_SpinlockConfigRefType, OS_CONST) OsCfg_SystemSpinlockRefs[OS_CFG_NUM_SYSTEM_SPINLOCKS + 1u] =
{
  &OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL,
  &OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR,
  &OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL,
  &OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR,
  &OsCfg_Spinlock_Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct,
  &OsCfg_Spinlock_Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct,
  &OsCfg_Spinlock_Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct,
  &OsCfg_Spinlock_Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct,
  NULL_PTR
};

/*! Object reference table for core boot barriers. */
CONSTP2VAR(Os_CoreBootBarrierType, AUTOMATIC, OS_CONST) OsCfg_CoreBootBarrierRefs[OS_COREID_COUNT + 1u] =               /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */  
{
  &OsCfg_Core_OsCore0_BootBarrier_Dyn,
  &OsCfg_Core_OsCore1_BootBarrier_Dyn,
  &OsCfg_Core_OsCore2_BootBarrier_Dyn,
  &OsCfg_Core_OsCore3_BootBarrier_Dyn,
  &OsCfg_Core_OsCore4_BootBarrier_Dyn,
  &OsCfg_Core_OsCore5_BootBarrier_Dyn,
  NULL_PTR
};

/*! System configuration data. */
CONST(Os_SystemConfigType, OS_CONST) OsCfg_System =
{
  /* .VersionInfo      = */
  {
    /* .vendorID         = */ OS_VENDOR_ID,
    /* .moduleID         = */ OS_MODULE_ID,
    /* .sw_major_version = */ OS_SW_MAJOR_VERSION,
    /* .sw_minor_version = */ OS_SW_MINOR_VERSION,
    /* .sw_patch_version = */ OS_SW_PATCH_VERSION
  },
  /* .NumberOfAsrCores = */ OS_COREASRCOREIDX_COUNT,
  /* .SpinlockRefs     = */ OsCfg_SystemSpinlockRefs,
  /* .SpinlockCount    = */ (Os_ObjIdxType)OS_CFG_NUM_SYSTEM_SPINLOCKS,
  /* .HwConfig         = */ &OsCfg_Hal_System,
  /* .MemoryProtection = */ NULL_PTR,
  /* .InterruptSourceRefs  = */ OsCfg_Hal_System_InterruptSourceRefs,
  /* .InterruptSourceCount = */ (Os_ObjIdxType)OS_CFG_NUM_SYSTEM_INTERRUPTSOURCEREFS,
  /* .Core2Thread      = */ &OsCfg_Hal_Core2Thread
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
 *  END OF FILE: Os_Core_Lcfg.c
 *********************************************************************************************************************/

