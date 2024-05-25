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
 *              File: Os_Isr_Lcfg.c
 *   Generation Time: 2024-01-08 16:27:31
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

#define OS_ISR_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Isr_Lcfg.h"
#include "Os_Isr.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_Timer.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os_XSignal_Lcfg.h"
#include "Os_XSignal.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"


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

/*! Dynamic ISR data: ADC0SR0_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_ADC0SR0_ISR_Dyn;

/*! Dynamic ISR data: ADC1SR0_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_ADC1SR0_ISR_Dyn;

/*! Dynamic ISR data: ADC2SR0_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_ADC2SR0_ISR_Dyn;

/*! Dynamic ISR data: ADC3SR0_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_ADC3SR0_ISR_Dyn;

/*! Dynamic ISR data: ADC8SR0_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_ADC8SR0_ISR_Dyn;

/*! Dynamic ISR data: CanIsr_4 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsr_4_Dyn;

/*! Dynamic ISR data: CanIsr_5 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsr_5_Dyn;

/*! Dynamic ISR data: CounterIsr_SystemTimer0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimer0_Dyn;

/*! Dynamic ISR data: DMACH0SR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_DMACH0SR_ISR_Dyn;

/*! Dynamic ISR data: DMACH3SR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_DMACH3SR_ISR_Dyn;

/*! Dynamic ISR data: DMACH4SR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_DMACH4SR_ISR_Dyn;

/*! Dynamic ISR data: DMACH5SR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_DMACH5SR_ISR_Dyn;

/*! Dynamic ISR data: DMACH6SR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_DMACH6SR_ISR_Dyn;

/*! Dynamic ISR data: DMACH7SR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_DMACH7SR_ISR_Dyn;

/*! Dynamic ISR data: DMACH8SR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_DMACH8SR_ISR_Dyn;

/*! Dynamic ISR data: DMACH9SR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_DMACH9SR_ISR_Dyn;

/*! Dynamic ISR data: DMAERR0SR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_DMAERR0SR_ISR_Dyn;

/*! Dynamic ISR data: GTMATOM0SR0_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_GTMATOM0SR0_ISR_Dyn;

/*! Dynamic ISR data: GTMATOM1SR0_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_GTMATOM1SR0_ISR_Dyn;

/*! Dynamic ISR data: GTMATOM2SR0_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_GTMATOM2SR0_ISR_Dyn;

/*! Dynamic ISR data: GTMATOM4SR0_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_GTMATOM4SR0_ISR_Dyn;

/*! Dynamic ISR data: GTMTIM2SR3_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_GTMTIM2SR3_ISR_Dyn;

/*! Dynamic ISR data: GTMTIM2SR5_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_GTMTIM2SR5_ISR_Dyn;

/*! Dynamic ISR data: GTMTOM0SR0_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_GTMTOM0SR0_ISR_Dyn;

/*! Dynamic ISR data: GTMTOM0SR1_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_GTMTOM0SR1_ISR_Dyn;

/*! Dynamic ISR data: GTMTOM0SR2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_GTMTOM0SR2_ISR_Dyn;

/*! Dynamic ISR data: GTMTOM0SR3_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_GTMTOM0SR3_ISR_Dyn;

/*! Dynamic ISR data: QSPI0ERR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_QSPI0ERR_ISR_Dyn;

/*! Dynamic ISR data: QSPI0PT_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_QSPI0PT_ISR_Dyn;

/*! Dynamic ISR data: QSPI1ERR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_QSPI1ERR_ISR_Dyn;

/*! Dynamic ISR data: QSPI1PT_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_QSPI1PT_ISR_Dyn;

/*! Dynamic ISR data: QSPI2ERR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_QSPI2ERR_ISR_Dyn;

/*! Dynamic ISR data: QSPI2PT_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_QSPI2PT_ISR_Dyn;

/*! Dynamic ISR data: QSPI3ERR_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_QSPI3ERR_ISR_Dyn;

/*! Dynamic ISR data: QSPI3PT_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_QSPI3PT_ISR_Dyn;

/*! Dynamic ISR data: XSignalIsr_OsCore0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_XSignalIsr_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic ISR data: CanIsr_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsr_0_Dyn;

/*! Dynamic ISR data: CounterIsr_SystemTimer1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimer1_Dyn;

/*! Dynamic ISR data: XSignalIsr_OsCore1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_XSignalIsr_OsCore1_Dyn;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic ISR data: CanIsr_1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsr_1_Dyn;

/*! Dynamic ISR data: CounterIsr_SystemTimer2 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimer2_Dyn;

/*! Dynamic ISR data: XSignalIsr_OsCore2 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_XSignalIsr_OsCore2_Dyn;

#define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic ISR data: CanIsr_2 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsr_2_Dyn;

/*! Dynamic ISR data: CounterIsr_SystemTimer3 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimer3_Dyn;

/*! Dynamic ISR data: XSignalIsr_OsCore3 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_XSignalIsr_OsCore3_Dyn;

#define OS_STOP_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic ISR data: CanIsr_3 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsr_3_Dyn;

/*! Dynamic ISR data: CounterIsr_SystemTimer4 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimer4_Dyn;

/*! Dynamic ISR data: XSignalIsr_OsCore4 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_XSignalIsr_OsCore4_Dyn;

#define OS_STOP_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic ISR data: CounterIsr_SystemTimer5 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimer5_Dyn;

/*! Dynamic ISR data: XSignalIsr_OsCore5 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_XSignalIsr_OsCore5_Dyn;

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

/*! ISR configuration data: ADC0SR0_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC0SR0_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ADC0SR0_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Level22,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_ADC0SR0_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ADC0SR0_ISR,
  /* .IsrId                     = */ ADC0SR0_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: ADC1SR0_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC1SR0_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ADC1SR0_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Level23,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_ADC1SR0_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ADC1SR0_ISR,
  /* .IsrId                     = */ ADC1SR0_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: ADC2SR0_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC2SR0_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ADC2SR0_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Level24,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_ADC2SR0_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ADC2SR0_ISR,
  /* .IsrId                     = */ ADC2SR0_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: ADC3SR0_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC3SR0_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ADC3SR0_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Level25,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_ADC3SR0_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ADC3SR0_ISR,
  /* .IsrId                     = */ ADC3SR0_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: ADC8SR0_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC8SR0_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ADC8SR0_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level24_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Level48,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_ADC8SR0_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ADC8SR0_ISR,
  /* .IsrId                     = */ ADC8SR0_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CanIsr_4 */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_4 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsr_4,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level36_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsr_4_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsr_4,
  /* .IsrId                     = */ CanIsr_4,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CanIsr_5 */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_5 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsr_5,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level25_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsr_5_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsr_5,
  /* .IsrId                     = */ CanIsr_5,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CounterIsr_SystemTimer0 */
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer0 =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimer0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimer0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer0,
  /* .IsrId                     = */ CounterIsr_SystemTimer0,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer0)
};
/*! ISR configuration data: DMACH0SR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH0SR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_DMACH0SR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_DMACH0SR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_DMACH0SR_ISR,
  /* .IsrId                     = */ DMACH0SR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: DMACH3SR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH3SR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_DMACH3SR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level8_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_DMACH3SR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_DMACH3SR_ISR,
  /* .IsrId                     = */ DMACH3SR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: DMACH4SR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH4SR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_DMACH4SR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_DMACH4SR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_DMACH4SR_ISR,
  /* .IsrId                     = */ DMACH4SR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: DMACH5SR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH5SR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_DMACH5SR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_DMACH5SR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_DMACH5SR_ISR,
  /* .IsrId                     = */ DMACH5SR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: DMACH6SR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH6SR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_DMACH6SR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level11_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_DMACH6SR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_DMACH6SR_ISR,
  /* .IsrId                     = */ DMACH6SR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: DMACH7SR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH7SR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_DMACH7SR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level12_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_DMACH7SR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_DMACH7SR_ISR,
  /* .IsrId                     = */ DMACH7SR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: DMACH8SR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH8SR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_DMACH8SR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level13_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_DMACH8SR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_DMACH8SR_ISR,
  /* .IsrId                     = */ DMACH8SR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: DMACH9SR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH9SR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_DMACH9SR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level14_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_DMACH9SR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_DMACH9SR_ISR,
  /* .IsrId                     = */ DMACH9SR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: DMAERR0SR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMAERR0SR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_DMAERR0SR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level23_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_DMAERR0SR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_DMAERR0SR_ISR,
  /* .IsrId                     = */ DMAERR0SR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: GTMATOM0SR0_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMATOM0SR0_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_GTMATOM0SR0_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level26_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_GTMATOM0SR0_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_GTMATOM0SR0_ISR,
  /* .IsrId                     = */ GTMATOM0SR0_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: GTMATOM1SR0_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMATOM1SR0_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_GTMATOM1SR0_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level27_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_GTMATOM1SR0_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_GTMATOM1SR0_ISR,
  /* .IsrId                     = */ GTMATOM1SR0_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: GTMATOM2SR0_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMATOM2SR0_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_GTMATOM2SR0_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level28_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_GTMATOM2SR0_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_GTMATOM2SR0_ISR,
  /* .IsrId                     = */ GTMATOM2SR0_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: GTMATOM4SR0_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMATOM4SR0_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_GTMATOM4SR0_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level29_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_GTMATOM4SR0_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_GTMATOM4SR0_ISR,
  /* .IsrId                     = */ GTMATOM4SR0_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: GTMTIM2SR3_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTIM2SR3_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_GTMTIM2SR3_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level30_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_GTMTIM2SR3_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_GTMTIM2SR3_ISR,
  /* .IsrId                     = */ GTMTIM2SR3_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: GTMTIM2SR5_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTIM2SR5_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_GTMTIM2SR5_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level31_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_GTMTIM2SR5_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_GTMTIM2SR5_ISR,
  /* .IsrId                     = */ GTMTIM2SR5_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: GTMTOM0SR0_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTOM0SR0_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_GTMTOM0SR0_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level32_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_GTMTOM0SR0_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_GTMTOM0SR0_ISR,
  /* .IsrId                     = */ GTMTOM0SR0_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: GTMTOM0SR1_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTOM0SR1_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_GTMTOM0SR1_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level33_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_GTMTOM0SR1_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_GTMTOM0SR1_ISR,
  /* .IsrId                     = */ GTMTOM0SR1_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: GTMTOM0SR2_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTOM0SR2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_GTMTOM0SR2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level34_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_GTMTOM0SR2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_GTMTOM0SR2_ISR,
  /* .IsrId                     = */ GTMTOM0SR2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: GTMTOM0SR3_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTOM0SR3_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_GTMTOM0SR3_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level35_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_GTMTOM0SR3_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_GTMTOM0SR3_ISR,
  /* .IsrId                     = */ GTMTOM0SR3_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: QSPI0ERR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI0ERR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QSPI0ERR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level21_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_QSPI0ERR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_QSPI0ERR_ISR,
  /* .IsrId                     = */ QSPI0ERR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: QSPI0PT_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI0PT_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QSPI0PT_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level22_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_QSPI0PT_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_QSPI0PT_ISR,
  /* .IsrId                     = */ QSPI0PT_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: QSPI1ERR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI1ERR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QSPI1ERR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level19_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_QSPI1ERR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_QSPI1ERR_ISR,
  /* .IsrId                     = */ QSPI1ERR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: QSPI1PT_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI1PT_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QSPI1PT_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level20_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_QSPI1PT_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_QSPI1PT_ISR,
  /* .IsrId                     = */ QSPI1PT_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: QSPI2ERR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI2ERR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QSPI2ERR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level15_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_QSPI2ERR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_QSPI2ERR_ISR,
  /* .IsrId                     = */ QSPI2ERR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: QSPI2PT_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI2PT_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QSPI2PT_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level16_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_QSPI2PT_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_QSPI2PT_ISR,
  /* .IsrId                     = */ QSPI2PT_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: QSPI3ERR_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI3ERR_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QSPI3ERR_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level17_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_QSPI3ERR_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_QSPI3ERR_ISR,
  /* .IsrId                     = */ QSPI3ERR_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: QSPI3PT_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI3PT_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QSPI3PT_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level18_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_QSPI3PT_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_QSPI3PT_ISR,
  /* .IsrId                     = */ QSPI3PT_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: XSignalIsr_OsCore0 */
CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore0 =
{
  /* .Isr           = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_XSignalIsr_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_XSignalIsr_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore0,
  /* .IsrId                     = */ XSignalIsr_OsCore0,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .FunctionTable = */ &OsCfg_Isr_XSignalIsr_OsCore0_FuncTable,
  /* .RecvPortRefs  = */ OsCfg_Isr_XSignalIsr_OsCore0_PortRefs,
  /* .RecvPortCount = */ (Os_ObjIdxType)OS_CFG_NUM_ISR_XSIGNALISR_OSCORE0_PORTS,
  /* .IntTrigger    = */ &OsCfg_Hal_XSig_XSignalIsr_OsCore0
};
#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CanIsr_0 */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsr_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore1_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore1_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsr_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore1,
    /* .Core                  = */ &OsCfg_Core_OsCore1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsr_0,
  /* .IsrId                     = */ CanIsr_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CounterIsr_SystemTimer1 */
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer1 =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimer1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore1_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore1_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimer1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore1,
    /* .Core                  = */ &OsCfg_Core_OsCore1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer1,
  /* .IsrId                     = */ CounterIsr_SystemTimer1,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer1)
};
/*! ISR configuration data: XSignalIsr_OsCore1 */
CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore1 =
{
  /* .Isr           = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_XSignalIsr_OsCore1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore1_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore1_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_XSignalIsr_OsCore1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore1,
    /* .Core                  = */ &OsCfg_Core_OsCore1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore1,
  /* .IsrId                     = */ XSignalIsr_OsCore1,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .FunctionTable = */ &OsCfg_Isr_XSignalIsr_OsCore1_FuncTable,
  /* .RecvPortRefs  = */ OsCfg_Isr_XSignalIsr_OsCore1_PortRefs,
  /* .RecvPortCount = */ (Os_ObjIdxType)OS_CFG_NUM_ISR_XSIGNALISR_OSCORE1_PORTS,
  /* .IntTrigger    = */ &OsCfg_Hal_XSig_XSignalIsr_OsCore1
};
#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CanIsr_1 */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_1 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsr_1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore2_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore2_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsr_1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore2,
    /* .Core                  = */ &OsCfg_Core_OsCore2,
    /* .IntApiState           = */ &OsCfg_Core_OsCore2_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsr_1,
  /* .IsrId                     = */ CanIsr_1,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CounterIsr_SystemTimer2 */
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer2 =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimer2,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore2_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore2_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimer2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore2,
    /* .Core                  = */ &OsCfg_Core_OsCore2,
    /* .IntApiState           = */ &OsCfg_Core_OsCore2_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer2,
  /* .IsrId                     = */ CounterIsr_SystemTimer2,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer2)
};
/*! ISR configuration data: XSignalIsr_OsCore2 */
CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore2 =
{
  /* .Isr           = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_XSignalIsr_OsCore2,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore2_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore2_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_XSignalIsr_OsCore2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore2,
    /* .Core                  = */ &OsCfg_Core_OsCore2,
    /* .IntApiState           = */ &OsCfg_Core_OsCore2_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore2,
  /* .IsrId                     = */ XSignalIsr_OsCore2,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .FunctionTable = */ &OsCfg_Isr_XSignalIsr_OsCore2_FuncTable,
  /* .RecvPortRefs  = */ OsCfg_Isr_XSignalIsr_OsCore2_PortRefs,
  /* .RecvPortCount = */ (Os_ObjIdxType)OS_CFG_NUM_ISR_XSIGNALISR_OSCORE2_PORTS,
  /* .IntTrigger    = */ &OsCfg_Hal_XSig_XSignalIsr_OsCore2
};
#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CanIsr_2 */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_2 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsr_2,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore3_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore3_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsr_2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore3,
    /* .Core                  = */ &OsCfg_Core_OsCore3,
    /* .IntApiState           = */ &OsCfg_Core_OsCore3_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsr_2,
  /* .IsrId                     = */ CanIsr_2,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CounterIsr_SystemTimer3 */
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer3 =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimer3,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore3_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore3_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimer3_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore3,
    /* .Core                  = */ &OsCfg_Core_OsCore3,
    /* .IntApiState           = */ &OsCfg_Core_OsCore3_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer3,
  /* .IsrId                     = */ CounterIsr_SystemTimer3,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer3)
};
/*! ISR configuration data: XSignalIsr_OsCore3 */
CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore3 =
{
  /* .Isr           = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_XSignalIsr_OsCore3,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore3_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore3_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_XSignalIsr_OsCore3_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore3,
    /* .Core                  = */ &OsCfg_Core_OsCore3,
    /* .IntApiState           = */ &OsCfg_Core_OsCore3_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore3,
  /* .IsrId                     = */ XSignalIsr_OsCore3,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .FunctionTable = */ &OsCfg_Isr_XSignalIsr_OsCore3_FuncTable,
  /* .RecvPortRefs  = */ OsCfg_Isr_XSignalIsr_OsCore3_PortRefs,
  /* .RecvPortCount = */ (Os_ObjIdxType)OS_CFG_NUM_ISR_XSIGNALISR_OSCORE3_PORTS,
  /* .IntTrigger    = */ &OsCfg_Hal_XSig_XSignalIsr_OsCore3
};
#define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CanIsr_3 */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_3 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsr_3,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore4_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore4_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsr_3_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore4,
    /* .Core                  = */ &OsCfg_Core_OsCore4,
    /* .IntApiState           = */ &OsCfg_Core_OsCore4_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsr_3,
  /* .IsrId                     = */ CanIsr_3,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CounterIsr_SystemTimer4 */
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer4 =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimer4,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore4_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore4_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimer4_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore4,
    /* .Core                  = */ &OsCfg_Core_OsCore4,
    /* .IntApiState           = */ &OsCfg_Core_OsCore4_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer4,
  /* .IsrId                     = */ CounterIsr_SystemTimer4,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer4)
};
/*! ISR configuration data: XSignalIsr_OsCore4 */
CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore4 =
{
  /* .Isr           = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_XSignalIsr_OsCore4,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore4_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore4_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_XSignalIsr_OsCore4_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore4,
    /* .Core                  = */ &OsCfg_Core_OsCore4,
    /* .IntApiState           = */ &OsCfg_Core_OsCore4_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore4,
  /* .IsrId                     = */ XSignalIsr_OsCore4,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .FunctionTable = */ &OsCfg_Isr_XSignalIsr_OsCore4_FuncTable,
  /* .RecvPortRefs  = */ OsCfg_Isr_XSignalIsr_OsCore4_PortRefs,
  /* .RecvPortCount = */ (Os_ObjIdxType)OS_CFG_NUM_ISR_XSIGNALISR_OSCORE4_PORTS,
  /* .IntTrigger    = */ &OsCfg_Hal_XSig_XSignalIsr_OsCore4
};
#define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CounterIsr_SystemTimer5 */
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer5 =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimer5,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore5_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore5_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimer5_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore5,
    /* .Core                  = */ &OsCfg_Core_OsCore5,
    /* .IntApiState           = */ &OsCfg_Core_OsCore5_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer5,
  /* .IsrId                     = */ CounterIsr_SystemTimer5,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer5)
};
/*! ISR configuration data: XSignalIsr_OsCore5 */
CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore5 =
{
  /* .Isr           = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_XSignalIsr_OsCore5,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore5_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore5_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_XSignalIsr_OsCore5_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore5,
    /* .Core                  = */ &OsCfg_Core_OsCore5,
    /* .IntApiState           = */ &OsCfg_Core_OsCore5_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore5,
  /* .IsrId                     = */ XSignalIsr_OsCore5,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .FunctionTable = */ &OsCfg_Isr_XSignalIsr_OsCore5_FuncTable,
  /* .RecvPortRefs  = */ OsCfg_Isr_XSignalIsr_OsCore5_PortRefs,
  /* .RecvPortCount = */ (Os_ObjIdxType)OS_CFG_NUM_ISR_XSIGNALISR_OSCORE5_PORTS,
  /* .IntTrigger    = */ &OsCfg_Hal_XSig_XSignalIsr_OsCore5
};
#define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 ISRs. */
CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC0SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC1SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC2SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC3SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC8SR0_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_2),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_3),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_4),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_5),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer0),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer1),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer2),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer3),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer4),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer5),
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
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore1),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore2),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore3),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore4),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore5),
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
 *  END OF FILE: Os_Isr_Lcfg.c
 *********************************************************************************************************************/
