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
 *              File: Os_Hal_Context_Lcfg.c
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

#define OS_HAL_CONTEXT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os hal dependencies */
#include "Os_Hal_Core.h"


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

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn;

/*! HAL dynamic ISR2 level context data: Level5 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn;

/*! HAL dynamic ISR2 level context data: Level6 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn;

/*! HAL dynamic ISR2 level context data: Level7 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn;

/*! HAL dynamic ISR2 level context data: Level8 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level8_Dyn;

/*! HAL dynamic ISR2 level context data: Level9 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn;

/*! HAL dynamic ISR2 level context data: Level10 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn;

/*! HAL dynamic ISR2 level context data: Level11 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level11_Dyn;

/*! HAL dynamic ISR2 level context data: Level12 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level12_Dyn;

/*! HAL dynamic ISR2 level context data: Level13 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level13_Dyn;

/*! HAL dynamic ISR2 level context data: Level14 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level14_Dyn;

/*! HAL dynamic ISR2 level context data: Level15 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level15_Dyn;

/*! HAL dynamic ISR2 level context data: Level16 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level16_Dyn;

/*! HAL dynamic ISR2 level context data: Level17 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level17_Dyn;

/*! HAL dynamic ISR2 level context data: Level18 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level18_Dyn;

/*! HAL dynamic ISR2 level context data: Level19 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level19_Dyn;

/*! HAL dynamic ISR2 level context data: Level20 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level20_Dyn;

/*! HAL dynamic ISR2 level context data: Level21 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level21_Dyn;

/*! HAL dynamic ISR2 level context data: Level22 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level22_Dyn;

/*! HAL dynamic ISR2 level context data: Level23 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level23_Dyn;

/*! HAL dynamic ISR2 level context data: Level24 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level24_Dyn;

/*! HAL dynamic ISR2 level context data: Level25 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level25_Dyn;

/*! HAL dynamic ISR2 level context data: Level26 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level26_Dyn;

/*! HAL dynamic ISR2 level context data: Level27 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level27_Dyn;

/*! HAL dynamic ISR2 level context data: Level28 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level28_Dyn;

/*! HAL dynamic ISR2 level context data: Level29 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level29_Dyn;

/*! HAL dynamic ISR2 level context data: Level30 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level30_Dyn;

/*! HAL dynamic ISR2 level context data: Level31 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level31_Dyn;

/*! HAL dynamic ISR2 level context data: Level32 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level32_Dyn;

/*! HAL dynamic ISR2 level context data: Level33 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level33_Dyn;

/*! HAL dynamic ISR2 level context data: Level34 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level34_Dyn;

/*! HAL dynamic ISR2 level context data: Level35 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level35_Dyn;

/*! HAL dynamic ISR2 level context data: Level36 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level36_Dyn;

/*! HAL dynamic task context data: APP_Task_Core0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_APP_Task_Core0_Dyn;

/*! HAL dynamic task context data: Core_OsTask_CDD */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Core_OsTask_CDD_Dyn;

/*! HAL dynamic task context data: Core_OsTask_IOHW */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Core_OsTask_IOHW_Dyn;

/*! HAL dynamic task context data: Core_OsTask_PSI5 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Core_OsTask_PSI5_Dyn;

/*! HAL dynamic task context data: Core_OsTask_PT2000 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Core_OsTask_PT2000_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;

/*! HAL dynamic task context data: Init_Core0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Core0_Dyn;

/*! HAL dynamic task context data: SchM_Core0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SchM_Core0_Dyn;

/*! HAL exception context data: OsCore0 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore1_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore1_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore1_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore1_Isr_Level3_Dyn;

/*! HAL dynamic task context data: APP_Task_Core1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_APP_Task_Core1_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore1_Dyn;

/*! HAL dynamic task context data: Init_Core1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Core1_Dyn;

/*! HAL dynamic task context data: SchM_Core1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SchM_Core1_Dyn;

/*! HAL exception context data: OsCore1 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore1_ExceptionContext;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore2_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore2_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore2_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore2_Isr_Level3_Dyn;

/*! HAL dynamic task context data: APP_Task_Core2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_APP_Task_Core2_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore2_Dyn;

/*! HAL dynamic task context data: Init_Core2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Core2_Dyn;

/*! HAL dynamic task context data: SchM_Core2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SchM_Core2_Dyn;

/*! HAL exception context data: OsCore2 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore2_ExceptionContext;

#define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore3_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore3_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore3_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore3_Isr_Level3_Dyn;

/*! HAL dynamic task context data: APP_Task_Core3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_APP_Task_Core3_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore3_Dyn;

/*! HAL dynamic task context data: Init_Core3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Core3_Dyn;

/*! HAL dynamic task context data: SchM_Core3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SchM_Core3_Dyn;

/*! HAL exception context data: OsCore3 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore3_ExceptionContext;

#define OS_STOP_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore4_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore4_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore4_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore4_Isr_Level3_Dyn;

/*! HAL dynamic task context data: APP_Task_Core4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_APP_Task_Core4_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore4_Dyn;

/*! HAL dynamic task context data: Init_Core4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Core4_Dyn;

/*! HAL dynamic task context data: SchM_Core4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SchM_Core4_Dyn;

/*! HAL exception context data: OsCore4 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore4_ExceptionContext;

#define OS_STOP_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore5 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore5_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore5_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore5_Isr_Level2_Dyn;

/*! HAL dynamic task context data: APP_Task_Core5 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_APP_Task_Core5_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore5 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore5_Dyn;

/*! HAL dynamic task context data: Init_Core5 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Core5_Dyn;

/*! HAL dynamic task context data: SchM_Core5 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SchM_Core5_Dyn;

/*! HAL exception context data: OsCore5 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore5_ExceptionContext;

#define OS_STOP_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Init_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: ADC0SR0_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC0SR0_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Level22_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Level22_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_ADC0SR0_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)22<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: ADC1SR0_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC1SR0_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Level23_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Level23_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_ADC1SR0_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)23<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: ADC2SR0_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC2SR0_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Level24_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Level24_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_ADC2SR0_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)24<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: ADC3SR0_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC3SR0_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Level25_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Level25_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_ADC3SR0_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)25<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: ADC8SR0_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC8SR0_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Level48_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Level48_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_ADC8SR0_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)48<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CanIsr_4 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_4 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_CanIsr_4,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CanIsr_5 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_5 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_CanIsr_5,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerHrtIsr,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: DMACH0SR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH0SR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_DMACH0SR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: DMACH3SR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH3SR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_DMACH3SR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: DMACH4SR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH4SR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_DMACH4SR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: DMACH5SR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH5SR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_DMACH5SR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: DMACH6SR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH6SR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_DMACH6SR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: DMACH7SR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH7SR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_DMACH7SR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: DMACH8SR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH8SR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_DMACH8SR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: DMACH9SR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH9SR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_DMACH9SR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: DMAERR0SR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMAERR0SR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_DMAERR0SR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: GTMATOM0SR0_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMATOM0SR0_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_GTMATOM0SR0_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: GTMATOM1SR0_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMATOM1SR0_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_GTMATOM1SR0_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: GTMATOM2SR0_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMATOM2SR0_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_GTMATOM2SR0_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: GTMATOM4SR0_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMATOM4SR0_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_GTMATOM4SR0_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: GTMTIM2SR3_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTIM2SR3_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_GTMTIM2SR3_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: GTMTIM2SR5_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTIM2SR5_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_GTMTIM2SR5_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: GTMTOM0SR0_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTOM0SR0_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_GTMTOM0SR0_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: GTMTOM0SR1_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTOM0SR1_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_GTMTOM0SR1_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: GTMTOM0SR2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTOM0SR2_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_GTMTOM0SR2_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: GTMTOM0SR3_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTOM0SR3_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_GTMTOM0SR3_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: QSPI0ERR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI0ERR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_QSPI0ERR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: QSPI0PT_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI0PT_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_QSPI0PT_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: QSPI1ERR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI1ERR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_QSPI1ERR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: QSPI1PT_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI1PT_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_QSPI1PT_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: QSPI2ERR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI2ERR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_QSPI2ERR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: QSPI2PT_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI2PT_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_QSPI2PT_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: QSPI3ERR_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI3ERR_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_QSPI3ERR_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: QSPI3PT_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI3PT_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_QSPI3PT_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_XSigRecvIsrHandler,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: APP_Task_Core0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_APP_Task_Core0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio60_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio60_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_APP_Task_Core0,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Core_OsTask_CDD */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Core_OsTask_CDD =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio56_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio56_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Core_OsTask_CDD,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Core_OsTask_IOHW */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Core_OsTask_IOHW =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Core_OsTask_IOHW_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Core_OsTask_IOHW_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Core_OsTask_IOHW,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Core_OsTask_PSI5 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Core_OsTask_PSI5 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio59_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio59_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Core_OsTask_PSI5,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Core_OsTask_PT2000 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Core_OsTask_PT2000 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Core_OsTask_PT2000_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Core_OsTask_PT2000_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Core_OsTask_PT2000,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: IdleTask_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Init_Core0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Core0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio100_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio100_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Init_Core0,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: SchM_Core0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SchM_Core0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_SchM_Core0_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_SchM_Core0_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_SchM_Core0,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL kernel stack configuration data: OsCore0_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel =
{
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn)+1)  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Init_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Init_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CanIsr_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_CanIsr_0,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerHrtIsr,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_XSigRecvIsrHandler,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: APP_Task_Core1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_APP_Task_Core1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Task_Prio50_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Task_Prio50_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_APP_Task_Core1,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: IdleTask_OsCore1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Task_Prio4294967295_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Task_Prio4294967295_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Init_Core1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Core1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Task_Prio100_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Task_Prio100_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Init_Core1,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: SchM_Core1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SchM_Core1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Task_Prio20_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Task_Prio20_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_SchM_Core1,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL kernel stack configuration data: OsCore1_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore1_Kernel =
{
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Kernel_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Kernel_Dyn)+1)  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Init_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Init_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CanIsr_1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_CanIsr_1,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerHrtIsr,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_XSigRecvIsrHandler,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: APP_Task_Core2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_APP_Task_Core2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Task_Prio50_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Task_Prio50_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_APP_Task_Core2,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: IdleTask_OsCore2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Task_Prio4294967295_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Task_Prio4294967295_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Init_Core2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Core2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Task_Prio100_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Task_Prio100_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Init_Core2,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: SchM_Core2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SchM_Core2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Task_Prio20_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Task_Prio20_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_SchM_Core2,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL kernel stack configuration data: OsCore2_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore2_Kernel =
{
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Kernel_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Kernel_Dyn)+1)  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore3 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore3_Init_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore3_Init_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CanIsr_2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore3_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore3_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_CanIsr_2,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer3 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore3_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore3_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerHrtIsr,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore3 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore3_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore3_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_XSigRecvIsrHandler,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: APP_Task_Core3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_APP_Task_Core3 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore3_Task_Prio50_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore3_Task_Prio50_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_APP_Task_Core3,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: IdleTask_OsCore3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore3 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore3_Task_Prio4294967295_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore3_Task_Prio4294967295_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Init_Core3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Core3 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore3_Task_Prio100_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore3_Task_Prio100_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Init_Core3,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: SchM_Core3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SchM_Core3 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore3_Task_Prio20_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore3_Task_Prio20_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_SchM_Core3,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL kernel stack configuration data: OsCore3_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore3_Kernel =
{
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore3_Kernel_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore3_Kernel_Dyn)+1)  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
};

#define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore4 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore4 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore4_Init_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore4_Init_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CanIsr_3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_3 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore4_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore4_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_CanIsr_3,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer4 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer4 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore4_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore4_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerHrtIsr,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore4 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore4 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore4_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore4_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_XSigRecvIsrHandler,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: APP_Task_Core4 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_APP_Task_Core4 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore4_Task_Prio50_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore4_Task_Prio50_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_APP_Task_Core4,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: IdleTask_OsCore4 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore4 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore4_Task_Prio4294967295_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore4_Task_Prio4294967295_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Init_Core4 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Core4 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore4_Task_Prio100_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore4_Task_Prio100_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Init_Core4,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: SchM_Core4 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SchM_Core4 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore4_Task_Prio20_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore4_Task_Prio20_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_SchM_Core4,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL kernel stack configuration data: OsCore4_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore4_Kernel =
{
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore4_Kernel_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore4_Kernel_Dyn)+1)  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
};

#define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore5 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore5 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore5_Init_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore5_Init_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer5 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer5 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore5_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore5_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerHrtIsr,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore5 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore5 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore5_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore5_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_XSigRecvIsrHandler,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)69<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: APP_Task_Core5 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_APP_Task_Core5 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore5_Task_Prio50_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore5_Task_Prio50_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_APP_Task_Core5,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: IdleTask_OsCore5 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore5 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore5_Task_Prio4294967295_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore5_Task_Prio4294967295_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Init_Core5 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Core5 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore5_Task_Prio100_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore5_Task_Prio100_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Init_Core5,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: SchM_Core5 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SchM_Core5 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore5_Task_Prio20_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore5_Task_Prio20_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_SchM_Core5,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL kernel stack configuration data: OsCore5_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore5_Kernel =
{
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore5_Kernel_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore5_Kernel_Dyn)+1)  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
};

#define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u] =
{
  &OsCfg_Hal_Context_OsCore0_ExceptionContext,
  &OsCfg_Hal_Context_OsCore1_ExceptionContext,
  &OsCfg_Hal_Context_OsCore2_ExceptionContext,
  &OsCfg_Hal_Context_OsCore3_ExceptionContext,
  &OsCfg_Hal_Context_OsCore4_ExceptionContext,
  NULL_PTR,
  &OsCfg_Hal_Context_OsCore5_ExceptionContext,
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
 *  END OF FILE: Os_Hal_Context_Lcfg.c
 *********************************************************************************************************************/
