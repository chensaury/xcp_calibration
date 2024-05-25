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
 *              File: Os_Hal_Context_Lcfg.h
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


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_CONTEXT_LCFG_H
# define OS_HAL_CONTEXT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Context_Types.h"

/* Os kernel module dependencies */
# include "Os_Core_Cfg.h"

/* Os hal dependencies */
# include "Os_Hal_Os_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn;

/*! HAL dynamic ISR2 level context data: Level5 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn;

/*! HAL dynamic ISR2 level context data: Level6 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn;

/*! HAL dynamic ISR2 level context data: Level7 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn;

/*! HAL dynamic ISR2 level context data: Level8 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level8_Dyn;

/*! HAL dynamic ISR2 level context data: Level9 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn;

/*! HAL dynamic ISR2 level context data: Level10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn;

/*! HAL dynamic ISR2 level context data: Level11 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level11_Dyn;

/*! HAL dynamic ISR2 level context data: Level12 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level12_Dyn;

/*! HAL dynamic ISR2 level context data: Level13 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level13_Dyn;

/*! HAL dynamic ISR2 level context data: Level14 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level14_Dyn;

/*! HAL dynamic ISR2 level context data: Level15 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level15_Dyn;

/*! HAL dynamic ISR2 level context data: Level16 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level16_Dyn;

/*! HAL dynamic ISR2 level context data: Level17 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level17_Dyn;

/*! HAL dynamic ISR2 level context data: Level18 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level18_Dyn;

/*! HAL dynamic ISR2 level context data: Level19 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level19_Dyn;

/*! HAL dynamic ISR2 level context data: Level20 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level20_Dyn;

/*! HAL dynamic ISR2 level context data: Level21 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level21_Dyn;

/*! HAL dynamic ISR2 level context data: Level22 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level22_Dyn;

/*! HAL dynamic ISR2 level context data: Level23 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level23_Dyn;

/*! HAL dynamic ISR2 level context data: Level24 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level24_Dyn;

/*! HAL dynamic ISR2 level context data: Level25 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level25_Dyn;

/*! HAL dynamic ISR2 level context data: Level26 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level26_Dyn;

/*! HAL dynamic ISR2 level context data: Level27 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level27_Dyn;

/*! HAL dynamic ISR2 level context data: Level28 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level28_Dyn;

/*! HAL dynamic ISR2 level context data: Level29 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level29_Dyn;

/*! HAL dynamic ISR2 level context data: Level30 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level30_Dyn;

/*! HAL dynamic ISR2 level context data: Level31 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level31_Dyn;

/*! HAL dynamic ISR2 level context data: Level32 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level32_Dyn;

/*! HAL dynamic ISR2 level context data: Level33 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level33_Dyn;

/*! HAL dynamic ISR2 level context data: Level34 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level34_Dyn;

/*! HAL dynamic ISR2 level context data: Level35 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level35_Dyn;

/*! HAL dynamic ISR2 level context data: Level36 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level36_Dyn;

/*! HAL dynamic task context data: APP_Task_Core0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_APP_Task_Core0_Dyn;


/*! HAL dynamic task context data: Core_OsTask_CDD */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Core_OsTask_CDD_Dyn;


/*! HAL dynamic task context data: Core_OsTask_IOHW */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Core_OsTask_IOHW_Dyn;


/*! HAL dynamic task context data: Core_OsTask_PSI5 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Core_OsTask_PSI5_Dyn;


/*! HAL dynamic task context data: Core_OsTask_PT2000 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Core_OsTask_PT2000_Dyn;


/*! HAL dynamic task context data: IdleTask_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;


/*! HAL dynamic task context data: Init_Core0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Core0_Dyn;


/*! HAL dynamic task context data: SchM_Core0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SchM_Core0_Dyn;


/*! HAL exception context data: OsCore0 */
extern VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

# define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore1_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore1_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore1_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore1_Isr_Level3_Dyn;

/*! HAL dynamic task context data: APP_Task_Core1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_APP_Task_Core1_Dyn;


/*! HAL dynamic task context data: IdleTask_OsCore1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore1_Dyn;


/*! HAL dynamic task context data: Init_Core1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Core1_Dyn;


/*! HAL dynamic task context data: SchM_Core1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SchM_Core1_Dyn;


/*! HAL exception context data: OsCore1 */
extern VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore1_ExceptionContext;

# define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore2_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore2_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore2_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore2_Isr_Level3_Dyn;

/*! HAL dynamic task context data: APP_Task_Core2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_APP_Task_Core2_Dyn;


/*! HAL dynamic task context data: IdleTask_OsCore2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore2_Dyn;


/*! HAL dynamic task context data: Init_Core2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Core2_Dyn;


/*! HAL dynamic task context data: SchM_Core2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SchM_Core2_Dyn;


/*! HAL exception context data: OsCore2 */
extern VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore2_ExceptionContext;

# define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore3_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore3_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore3_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore3_Isr_Level3_Dyn;

/*! HAL dynamic task context data: APP_Task_Core3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_APP_Task_Core3_Dyn;


/*! HAL dynamic task context data: IdleTask_OsCore3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore3_Dyn;


/*! HAL dynamic task context data: Init_Core3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Core3_Dyn;


/*! HAL dynamic task context data: SchM_Core3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SchM_Core3_Dyn;


/*! HAL exception context data: OsCore3 */
extern VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore3_ExceptionContext;

# define OS_STOP_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore4 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore4_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore4_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore4_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore4_Isr_Level3_Dyn;

/*! HAL dynamic task context data: APP_Task_Core4 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_APP_Task_Core4_Dyn;


/*! HAL dynamic task context data: IdleTask_OsCore4 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore4_Dyn;


/*! HAL dynamic task context data: Init_Core4 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Core4_Dyn;


/*! HAL dynamic task context data: SchM_Core4 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SchM_Core4_Dyn;


/*! HAL exception context data: OsCore4 */
extern VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore4_ExceptionContext;

# define OS_STOP_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore5 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore5_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore5_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore5_Isr_Level2_Dyn;

/*! HAL dynamic task context data: APP_Task_Core5 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_APP_Task_Core5_Dyn;


/*! HAL dynamic task context data: IdleTask_OsCore5 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore5_Dyn;


/*! HAL dynamic task context data: Init_Core5 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Init_Core5_Dyn;


/*! HAL dynamic task context data: SchM_Core5 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SchM_Core5_Dyn;


/*! HAL exception context data: OsCore5 */
extern VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore5_ExceptionContext;

# define OS_STOP_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0;

/*! HAL ISR2 context configuration data: ADC0SR0_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC0SR0_ISR;

/*! HAL ISR2 context configuration data: ADC1SR0_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC1SR0_ISR;

/*! HAL ISR2 context configuration data: ADC2SR0_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC2SR0_ISR;

/*! HAL ISR2 context configuration data: ADC3SR0_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC3SR0_ISR;

/*! HAL ISR2 context configuration data: ADC8SR0_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC8SR0_ISR;

/*! HAL ISR2 context configuration data: CanIsr_4 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_4;

/*! HAL ISR2 context configuration data: CanIsr_5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_5;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer0;

/*! HAL ISR2 context configuration data: DMACH0SR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH0SR_ISR;

/*! HAL ISR2 context configuration data: DMACH3SR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH3SR_ISR;

/*! HAL ISR2 context configuration data: DMACH4SR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH4SR_ISR;

/*! HAL ISR2 context configuration data: DMACH5SR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH5SR_ISR;

/*! HAL ISR2 context configuration data: DMACH6SR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH6SR_ISR;

/*! HAL ISR2 context configuration data: DMACH7SR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH7SR_ISR;

/*! HAL ISR2 context configuration data: DMACH8SR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH8SR_ISR;

/*! HAL ISR2 context configuration data: DMACH9SR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMACH9SR_ISR;

/*! HAL ISR2 context configuration data: DMAERR0SR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DMAERR0SR_ISR;

/*! HAL ISR2 context configuration data: GTMATOM0SR0_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMATOM0SR0_ISR;

/*! HAL ISR2 context configuration data: GTMATOM1SR0_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMATOM1SR0_ISR;

/*! HAL ISR2 context configuration data: GTMATOM2SR0_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMATOM2SR0_ISR;

/*! HAL ISR2 context configuration data: GTMATOM4SR0_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMATOM4SR0_ISR;

/*! HAL ISR2 context configuration data: GTMTIM2SR3_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTIM2SR3_ISR;

/*! HAL ISR2 context configuration data: GTMTIM2SR5_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTIM2SR5_ISR;

/*! HAL ISR2 context configuration data: GTMTOM0SR0_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTOM0SR0_ISR;

/*! HAL ISR2 context configuration data: GTMTOM0SR1_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTOM0SR1_ISR;

/*! HAL ISR2 context configuration data: GTMTOM0SR2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTOM0SR2_ISR;

/*! HAL ISR2 context configuration data: GTMTOM0SR3_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTOM0SR3_ISR;

/*! HAL ISR2 context configuration data: QSPI0ERR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI0ERR_ISR;

/*! HAL ISR2 context configuration data: QSPI0PT_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI0PT_ISR;

/*! HAL ISR2 context configuration data: QSPI1ERR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI1ERR_ISR;

/*! HAL ISR2 context configuration data: QSPI1PT_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI1PT_ISR;

/*! HAL ISR2 context configuration data: QSPI2ERR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI2ERR_ISR;

/*! HAL ISR2 context configuration data: QSPI2PT_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI2PT_ISR;

/*! HAL ISR2 context configuration data: QSPI3ERR_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI3ERR_ISR;

/*! HAL ISR2 context configuration data: QSPI3PT_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QSPI3PT_ISR;

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore0;

/*! HAL task context configuration data: APP_Task_Core0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_APP_Task_Core0;

/*! HAL task context configuration data: Core_OsTask_CDD */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Core_OsTask_CDD;

/*! HAL task context configuration data: Core_OsTask_IOHW */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Core_OsTask_IOHW;

/*! HAL task context configuration data: Core_OsTask_PSI5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Core_OsTask_PSI5;

/*! HAL task context configuration data: Core_OsTask_PT2000 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Core_OsTask_PT2000;

/*! HAL task context configuration data: IdleTask_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0;

/*! HAL task context configuration data: Init_Core0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Core0;

/*! HAL task context configuration data: SchM_Core0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SchM_Core0;

/*! HAL kernel stack configuration data: OsCore0_Kernel */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore1;

/*! HAL ISR2 context configuration data: CanIsr_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_0;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer1;

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore1;

/*! HAL task context configuration data: APP_Task_Core1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_APP_Task_Core1;

/*! HAL task context configuration data: IdleTask_OsCore1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore1;

/*! HAL task context configuration data: Init_Core1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Core1;

/*! HAL task context configuration data: SchM_Core1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SchM_Core1;

/*! HAL kernel stack configuration data: OsCore1_Kernel */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore1_Kernel;

# define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore2 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore2;

/*! HAL ISR2 context configuration data: CanIsr_1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_1;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer2 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer2;

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore2 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore2;

/*! HAL task context configuration data: APP_Task_Core2 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_APP_Task_Core2;

/*! HAL task context configuration data: IdleTask_OsCore2 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore2;

/*! HAL task context configuration data: Init_Core2 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Core2;

/*! HAL task context configuration data: SchM_Core2 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SchM_Core2;

/*! HAL kernel stack configuration data: OsCore2_Kernel */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore2_Kernel;

# define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE3_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore3 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore3;

/*! HAL ISR2 context configuration data: CanIsr_2 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_2;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer3 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer3;

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore3 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore3;

/*! HAL task context configuration data: APP_Task_Core3 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_APP_Task_Core3;

/*! HAL task context configuration data: IdleTask_OsCore3 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore3;

/*! HAL task context configuration data: Init_Core3 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Core3;

/*! HAL task context configuration data: SchM_Core3 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SchM_Core3;

/*! HAL kernel stack configuration data: OsCore3_Kernel */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore3_Kernel;

# define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE4_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore4 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore4;

/*! HAL ISR2 context configuration data: CanIsr_3 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_3;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer4 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer4;

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore4 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore4;

/*! HAL task context configuration data: APP_Task_Core4 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_APP_Task_Core4;

/*! HAL task context configuration data: IdleTask_OsCore4 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore4;

/*! HAL task context configuration data: Init_Core4 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Core4;

/*! HAL task context configuration data: SchM_Core4 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SchM_Core4;

/*! HAL kernel stack configuration data: OsCore4_Kernel */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore4_Kernel;

# define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE5_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore5;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer5;

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore5;

/*! HAL task context configuration data: APP_Task_Core5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_APP_Task_Core5;

/*! HAL task context configuration data: IdleTask_OsCore5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore5;

/*! HAL task context configuration data: Init_Core5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Init_Core5;

/*! HAL task context configuration data: SchM_Core5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SchM_Core5;

/*! HAL kernel stack configuration data: OsCore5_Kernel */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore5_Kernel;

# define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
extern CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_CONTEXT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_Lcfg.h
 *********************************************************************************************************************/
