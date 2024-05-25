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
 *              File: Os_Hal_Timer_Lcfg.c
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

#define OS_HAL_TIMER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Timer_Lcfg.h"
#include "Os_Hal_Timer.h"

/* Os kernel module dependencies */

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



/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL timer configuration data: SystemTimer0 */
CONST(Os_Hal_TimerFrtConfigType, OS_CONST) OsCfg_Hal_TimerFrt_SystemTimer0 =
{
  /* CounterRegisterAddress            = */ OS_HAL_TIMER_STM0_BASE + OS_HAL_TIMER_STM_TIM0_OFFSET,
  /* CompareRegisterAddress            = */ OS_HAL_TIMER_STM0_BASE + OS_HAL_TIMER_STM_CMP0_OFFSET,
  /* CMCONRegisterAddress              = */ OS_HAL_TIMER_STM0_BASE + OS_HAL_TIMER_STM_CMCON_OFFSET,
  /* CMCONMask                         = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_MASK,
  /* CMCONValue                        = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_VALUE,
  /* InterruptSRCRegisterAddress       = */ OS_HAL_INT_SRC_BASE + OS_HAL_INT_SRC_STM0_CH0_OFFSET,
  /* ICRRegisterAddress                = */ OS_HAL_TIMER_STM0_BASE + OS_HAL_TIMER_STM_ICR_OFFSET,
  /* ICRMask                           = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_MASK,
  /* ICRValue                          = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_VALUE,
  /* ReloadValue                       = */ 0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL timer configuration data: SystemTimer1 */
CONST(Os_Hal_TimerFrtConfigType, OS_CONST) OsCfg_Hal_TimerFrt_SystemTimer1 =
{
  /* CounterRegisterAddress            = */ OS_HAL_TIMER_STM1_BASE + OS_HAL_TIMER_STM_TIM0_OFFSET,
  /* CompareRegisterAddress            = */ OS_HAL_TIMER_STM1_BASE + OS_HAL_TIMER_STM_CMP0_OFFSET,
  /* CMCONRegisterAddress              = */ OS_HAL_TIMER_STM1_BASE + OS_HAL_TIMER_STM_CMCON_OFFSET,
  /* CMCONMask                         = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_MASK,
  /* CMCONValue                        = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_VALUE,
  /* InterruptSRCRegisterAddress       = */ OS_HAL_INT_SRC_BASE + OS_HAL_INT_SRC_STM1_CH0_OFFSET,
  /* ICRRegisterAddress                = */ OS_HAL_TIMER_STM1_BASE + OS_HAL_TIMER_STM_ICR_OFFSET,
  /* ICRMask                           = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_MASK,
  /* ICRValue                          = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_VALUE,
  /* ReloadValue                       = */ 0
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL timer configuration data: SystemTimer2 */
CONST(Os_Hal_TimerFrtConfigType, OS_CONST) OsCfg_Hal_TimerFrt_SystemTimer2 =
{
  /* CounterRegisterAddress            = */ OS_HAL_TIMER_STM2_BASE + OS_HAL_TIMER_STM_TIM0_OFFSET,
  /* CompareRegisterAddress            = */ OS_HAL_TIMER_STM2_BASE + OS_HAL_TIMER_STM_CMP0_OFFSET,
  /* CMCONRegisterAddress              = */ OS_HAL_TIMER_STM2_BASE + OS_HAL_TIMER_STM_CMCON_OFFSET,
  /* CMCONMask                         = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_MASK,
  /* CMCONValue                        = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_VALUE,
  /* InterruptSRCRegisterAddress       = */ OS_HAL_INT_SRC_BASE + OS_HAL_INT_SRC_STM2_CH0_OFFSET,
  /* ICRRegisterAddress                = */ OS_HAL_TIMER_STM2_BASE + OS_HAL_TIMER_STM_ICR_OFFSET,
  /* ICRMask                           = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_MASK,
  /* ICRValue                          = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_VALUE,
  /* ReloadValue                       = */ 0
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL timer configuration data: SystemTimer3 */
CONST(Os_Hal_TimerFrtConfigType, OS_CONST) OsCfg_Hal_TimerFrt_SystemTimer3 =
{
  /* CounterRegisterAddress            = */ OS_HAL_TIMER_STM3_BASE + OS_HAL_TIMER_STM_TIM0_OFFSET,
  /* CompareRegisterAddress            = */ OS_HAL_TIMER_STM3_BASE + OS_HAL_TIMER_STM_CMP0_OFFSET,
  /* CMCONRegisterAddress              = */ OS_HAL_TIMER_STM3_BASE + OS_HAL_TIMER_STM_CMCON_OFFSET,
  /* CMCONMask                         = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_MASK,
  /* CMCONValue                        = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_VALUE,
  /* InterruptSRCRegisterAddress       = */ OS_HAL_INT_SRC_BASE + OS_HAL_INT_SRC_STM3_CH0_OFFSET,
  /* ICRRegisterAddress                = */ OS_HAL_TIMER_STM3_BASE + OS_HAL_TIMER_STM_ICR_OFFSET,
  /* ICRMask                           = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_MASK,
  /* ICRValue                          = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_VALUE,
  /* ReloadValue                       = */ 0
};

#define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL timer configuration data: SystemTimer4 */
CONST(Os_Hal_TimerFrtConfigType, OS_CONST) OsCfg_Hal_TimerFrt_SystemTimer4 =
{
  /* CounterRegisterAddress            = */ OS_HAL_TIMER_STM4_BASE + OS_HAL_TIMER_STM_TIM0_OFFSET,
  /* CompareRegisterAddress            = */ OS_HAL_TIMER_STM4_BASE + OS_HAL_TIMER_STM_CMP0_OFFSET,
  /* CMCONRegisterAddress              = */ OS_HAL_TIMER_STM4_BASE + OS_HAL_TIMER_STM_CMCON_OFFSET,
  /* CMCONMask                         = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_MASK,
  /* CMCONValue                        = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_VALUE,
  /* InterruptSRCRegisterAddress       = */ OS_HAL_INT_SRC_BASE + OS_HAL_INT_SRC_STM4_CH0_OFFSET,
  /* ICRRegisterAddress                = */ OS_HAL_TIMER_STM4_BASE + OS_HAL_TIMER_STM_ICR_OFFSET,
  /* ICRMask                           = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_MASK,
  /* ICRValue                          = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_VALUE,
  /* ReloadValue                       = */ 0
};

#define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL timer configuration data: SystemTimer5 */
CONST(Os_Hal_TimerFrtConfigType, OS_CONST) OsCfg_Hal_TimerFrt_SystemTimer5 =
{
  /* CounterRegisterAddress            = */ OS_HAL_TIMER_STM5_BASE + OS_HAL_TIMER_STM_TIM0_OFFSET,
  /* CompareRegisterAddress            = */ OS_HAL_TIMER_STM5_BASE + OS_HAL_TIMER_STM_CMP0_OFFSET,
  /* CMCONRegisterAddress              = */ OS_HAL_TIMER_STM5_BASE + OS_HAL_TIMER_STM_CMCON_OFFSET,
  /* CMCONMask                         = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_MASK,
  /* CMCONValue                        = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_VALUE,
  /* InterruptSRCRegisterAddress       = */ OS_HAL_INT_SRC_BASE + OS_HAL_INT_SRC_STM5_CH0_OFFSET,
  /* ICRRegisterAddress                = */ OS_HAL_TIMER_STM5_BASE + OS_HAL_TIMER_STM_ICR_OFFSET,
  /* ICRMask                           = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_MASK,
  /* ICRValue                          = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_VALUE,
  /* ReloadValue                       = */ 0
};

#define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Hal_Timer_Lcfg.c
 *********************************************************************************************************************/
