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
 *              File: Os_Spinlock_Lcfg.c
 *   Generation Time: 2024-01-08 16:27:32
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

#define OS_SPINLOCK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Spinlock_Lcfg.h"
#include "Os_Spinlock.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Scheduler_Types.h"
#include "Os_Trace_Lcfg.h"

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

#define OS_START_SEC_CORESHARED_0X00000003_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic spinlock data: Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL */
OS_LOCAL VAR(Os_SpinlockType, OS_VAR_NOINIT) OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL_Dyn;

#define OS_STOP_SEC_CORESHARED_0X00000003_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORESHARED_0X00000005_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic spinlock data: Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR */
OS_LOCAL VAR(Os_SpinlockType, OS_VAR_NOINIT) OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR_Dyn;

#define OS_STOP_SEC_CORESHARED_0X00000005_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORESHARED_0X00000009_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic spinlock data: Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL */
OS_LOCAL VAR(Os_SpinlockType, OS_VAR_NOINIT) OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL_Dyn;

#define OS_STOP_SEC_CORESHARED_0X00000009_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORESHARED_0X00000011_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic spinlock data: Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR */
OS_LOCAL VAR(Os_SpinlockType, OS_VAR_NOINIT) OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR_Dyn;

#define OS_STOP_SEC_CORESHARED_0X00000011_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORESHARED_0X00000003_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic spinlock data: Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct */
OS_LOCAL VAR(Os_SpinlockType, OS_VAR_NOINIT) OsCfg_Spinlock_Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct_Dyn;

#define OS_STOP_SEC_CORESHARED_0X00000003_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORESHARED_0X00000005_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic spinlock data: Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct */
OS_LOCAL VAR(Os_SpinlockType, OS_VAR_NOINIT) OsCfg_Spinlock_Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct_Dyn;

#define OS_STOP_SEC_CORESHARED_0X00000005_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORESHARED_0X00000009_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic spinlock data: Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct */
OS_LOCAL VAR(Os_SpinlockType, OS_VAR_NOINIT) OsCfg_Spinlock_Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct_Dyn;

#define OS_STOP_SEC_CORESHARED_0X00000009_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORESHARED_0X00000011_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic spinlock data: Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct */
OS_LOCAL VAR(Os_SpinlockType, OS_VAR_NOINIT) OsCfg_Spinlock_Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct_Dyn;

#define OS_STOP_SEC_CORESHARED_0X00000011_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Spinlock configuration data: Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL */
CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_SPINLOCK_CASTDYN_SPINLOCK_2_LOCK(OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL_Dyn),
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1)),
    /* .Type                  = */ OS_LOCKTYPE_SPINLOCK
  },
  /* .Method          = */ OS_SPINLOCKMETHOD_CAT2,
  /* .CeilingPriority = */ (Os_TaskPrioType)0uL,
  /* .Mode            = */ OS_SPINLOCKMODE_SUPERVISOR,
  /* .Trace           = */ OS_SPINLOCKTRACE_ENABLED,
  /* .Checks          = */ OS_SPINLOCKCHECK_ENABLED,
  /* .Order           = */ (Os_SpinlockOrderType)0uL,
  /* .TimingHookTrace = */ NULL_PTR
};

/*! Spinlock configuration data: Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR */
CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_SPINLOCK_CASTDYN_SPINLOCK_2_LOCK(OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR_Dyn),
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore2)),
    /* .Type                  = */ OS_LOCKTYPE_SPINLOCK
  },
  /* .Method          = */ OS_SPINLOCKMETHOD_CAT2,
  /* .CeilingPriority = */ (Os_TaskPrioType)0uL,
  /* .Mode            = */ OS_SPINLOCKMODE_SUPERVISOR,
  /* .Trace           = */ OS_SPINLOCKTRACE_ENABLED,
  /* .Checks          = */ OS_SPINLOCKCHECK_ENABLED,
  /* .Order           = */ (Os_SpinlockOrderType)0uL,
  /* .TimingHookTrace = */ NULL_PTR
};

/*! Spinlock configuration data: Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL */
CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_SPINLOCK_CASTDYN_SPINLOCK_2_LOCK(OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL_Dyn),
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore3)),
    /* .Type                  = */ OS_LOCKTYPE_SPINLOCK
  },
  /* .Method          = */ OS_SPINLOCKMETHOD_CAT2,
  /* .CeilingPriority = */ (Os_TaskPrioType)0uL,
  /* .Mode            = */ OS_SPINLOCKMODE_SUPERVISOR,
  /* .Trace           = */ OS_SPINLOCKTRACE_ENABLED,
  /* .Checks          = */ OS_SPINLOCKCHECK_ENABLED,
  /* .Order           = */ (Os_SpinlockOrderType)0uL,
  /* .TimingHookTrace = */ NULL_PTR
};

/*! Spinlock configuration data: Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR */
CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_SPINLOCK_CASTDYN_SPINLOCK_2_LOCK(OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR_Dyn),
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore4)),
    /* .Type                  = */ OS_LOCKTYPE_SPINLOCK
  },
  /* .Method          = */ OS_SPINLOCKMETHOD_CAT2,
  /* .CeilingPriority = */ (Os_TaskPrioType)0uL,
  /* .Mode            = */ OS_SPINLOCKMODE_SUPERVISOR,
  /* .Trace           = */ OS_SPINLOCKTRACE_ENABLED,
  /* .Checks          = */ OS_SPINLOCKCHECK_ENABLED,
  /* .Order           = */ (Os_SpinlockOrderType)0uL,
  /* .TimingHookTrace = */ NULL_PTR
};

/*! Spinlock configuration data: Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct */
CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_SPINLOCK_CASTDYN_SPINLOCK_2_LOCK(OsCfg_Spinlock_Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct_Dyn),
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore1)),
    /* .Type                  = */ OS_LOCKTYPE_SPINLOCK
  },
  /* .Method          = */ OS_SPINLOCKMETHOD_CAT2,
  /* .CeilingPriority = */ (Os_TaskPrioType)0uL,
  /* .Mode            = */ OS_SPINLOCKMODE_SUPERVISOR,
  /* .Trace           = */ OS_SPINLOCKTRACE_ENABLED,
  /* .Checks          = */ OS_SPINLOCKCHECK_ENABLED,
  /* .Order           = */ (Os_SpinlockOrderType)0uL,
  /* .TimingHookTrace = */ NULL_PTR
};

/*! Spinlock configuration data: Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct */
CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_SPINLOCK_CASTDYN_SPINLOCK_2_LOCK(OsCfg_Spinlock_Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct_Dyn),
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore2)),
    /* .Type                  = */ OS_LOCKTYPE_SPINLOCK
  },
  /* .Method          = */ OS_SPINLOCKMETHOD_CAT2,
  /* .CeilingPriority = */ (Os_TaskPrioType)0uL,
  /* .Mode            = */ OS_SPINLOCKMODE_SUPERVISOR,
  /* .Trace           = */ OS_SPINLOCKTRACE_ENABLED,
  /* .Checks          = */ OS_SPINLOCKCHECK_ENABLED,
  /* .Order           = */ (Os_SpinlockOrderType)0uL,
  /* .TimingHookTrace = */ NULL_PTR
};

/*! Spinlock configuration data: Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct */
CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_SPINLOCK_CASTDYN_SPINLOCK_2_LOCK(OsCfg_Spinlock_Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct_Dyn),
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore3)),
    /* .Type                  = */ OS_LOCKTYPE_SPINLOCK
  },
  /* .Method          = */ OS_SPINLOCKMETHOD_CAT2,
  /* .CeilingPriority = */ (Os_TaskPrioType)0uL,
  /* .Mode            = */ OS_SPINLOCKMODE_SUPERVISOR,
  /* .Trace           = */ OS_SPINLOCKTRACE_ENABLED,
  /* .Checks          = */ OS_SPINLOCKCHECK_ENABLED,
  /* .Order           = */ (Os_SpinlockOrderType)0uL,
  /* .TimingHookTrace = */ NULL_PTR
};

/*! Spinlock configuration data: Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct */
CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_SPINLOCK_CASTDYN_SPINLOCK_2_LOCK(OsCfg_Spinlock_Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct_Dyn),
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore0) | OS_APPID2MASK(SystemApplication_OsCore4)),
    /* .Type                  = */ OS_LOCKTYPE_SPINLOCK
  },
  /* .Method          = */ OS_SPINLOCKMETHOD_CAT2,
  /* .CeilingPriority = */ (Os_TaskPrioType)0uL,
  /* .Mode            = */ OS_SPINLOCKMODE_SUPERVISOR,
  /* .Trace           = */ OS_SPINLOCKTRACE_ENABLED,
  /* .Checks          = */ OS_SPINLOCKCHECK_ENABLED,
  /* .Order           = */ (Os_SpinlockOrderType)0uL,
  /* .TimingHookTrace = */ NULL_PTR
};

/*! Object reference table for spinlocks. */
CONSTP2CONST(Os_SpinlockConfigType, OS_CONST, OS_CONST) OsCfg_SpinlockRefs[OS_SPINLOCKID_COUNT + 1] =           /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
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
 *  END OF FILE: Os_Spinlock_Lcfg.c
 *********************************************************************************************************************/
