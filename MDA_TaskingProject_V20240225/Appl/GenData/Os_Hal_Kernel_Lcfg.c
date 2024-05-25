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
 *              File: Os_Hal_Kernel_Lcfg.c
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

#define OS_HAL_KERNEL_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Kernel_Lcfg.h"

/* Os kernel module dependencies */
#include "Os_Common.h"
#include "Os_Core.h"
#include "Os_Spinlock_Lcfg.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Core_Lcfg.h"


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

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for cores (sorted by logical ID). */
CONSTP2CONST(Os_CoreConfigType, OS_CONST, OS_CONST) OsCfg_CoreRefs[OS_COREID_COUNT + 1u] =                /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_CORE_CASTCONFIG_COREASR_2_CORE(OsCfg_Core_OsCore0),
  OS_CORE_CASTCONFIG_COREASR_2_CORE(OsCfg_Core_OsCore1),
  OS_CORE_CASTCONFIG_COREASR_2_CORE(OsCfg_Core_OsCore2),
  OS_CORE_CASTCONFIG_COREASR_2_CORE(OsCfg_Core_OsCore3),
  OS_CORE_CASTCONFIG_COREASR_2_CORE(OsCfg_Core_OsCore4),
  OS_CORE_CASTCONFIG_COREASR_2_CORE(OsCfg_Core_OsCore5),
  NULL_PTR
};

/*! Object reference table for cores (sorted by physical ID). */
CONSTP2CONST(Os_CoreConfigType, OS_CONST, OS_CONST) OsCfg_CorePhysicalRefs[OS_CFG_COREPHYSICALID_COUNT + 1u] =
{
  OS_CORE_CASTCONFIG_COREASR_2_CORE(OsCfg_Core_OsCore0),
  OS_CORE_CASTCONFIG_COREASR_2_CORE(OsCfg_Core_OsCore1),
  OS_CORE_CASTCONFIG_COREASR_2_CORE(OsCfg_Core_OsCore2),
  OS_CORE_CASTCONFIG_COREASR_2_CORE(OsCfg_Core_OsCore3),
  OS_CORE_CASTCONFIG_COREASR_2_CORE(OsCfg_Core_OsCore4),
  NULL_PTR,
  OS_CORE_CASTCONFIG_COREASR_2_CORE(OsCfg_Core_OsCore5),
  NULL_PTR
};

/*! Object reference table for HAL kernel stacks. */
CONSTP2CONST(Os_Hal_ContextStackConfigType, OS_CONST, OS_CONST) OsCfg_Stack_KernelStacks[OS_CFG_COREPHYSICALID_COUNT + 1u] = /* PRQA S 1533 */ /* MD_Os_Rule8.9_1533 */
{
  &OsCfg_Hal_Stack_OsCore0_Kernel,
  &OsCfg_Hal_Stack_OsCore1_Kernel,
  &OsCfg_Hal_Stack_OsCore2_Kernel,
  &OsCfg_Hal_Stack_OsCore3_Kernel,
  &OsCfg_Hal_Stack_OsCore4_Kernel,
  NULL_PTR,
  &OsCfg_Hal_Stack_OsCore5_Kernel,
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
 *  END OF FILE: Os_Hal_Kernel_Lcfg.c
 *********************************************************************************************************************/
