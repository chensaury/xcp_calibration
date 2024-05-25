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
 *              File: Os_Hal_Core_Lcfg.h
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

#ifndef OS_HAL_CORE_LCFG_H
# define OS_HAL_CORE_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Core_Cfg.h"
# include "Os_Hal_Core_Types.h"

/* Os kernel module dependencies */
# include "Os_Hal_Interrupt_Types.h"

/* Os hal dependencies */


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

/* Core entry symbol declarations */
extern uint8 _start_tc0[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _start_tc1[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _start_tc2[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _start_tc3[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _start_tc4[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _start_tc5[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore0 */
extern CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore0_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE0_INTERRUPTSOURCEREFS + 1u];

/*! HAL core configuration data: OsCore0 */
extern CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore0;

/*! HAL AUTOSAR core configuration data: OsCore0 */
extern CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore0;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore1 */
extern CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore1_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE1_INTERRUPTSOURCEREFS + 1u];

/*! HAL core configuration data: OsCore1 */
extern CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore1;

/*! HAL AUTOSAR core configuration data: OsCore1 */
extern CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore1;

# define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore2 */
extern CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore2_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE2_INTERRUPTSOURCEREFS + 1u];

/*! HAL core configuration data: OsCore2 */
extern CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore2;

/*! HAL AUTOSAR core configuration data: OsCore2 */
extern CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore2;

# define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE3_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore3 */
extern CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore3_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE3_INTERRUPTSOURCEREFS + 1u];

/*! HAL core configuration data: OsCore3 */
extern CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore3;

/*! HAL AUTOSAR core configuration data: OsCore3 */
extern CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore3;

# define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE4_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore4 */
extern CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore4_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE4_INTERRUPTSOURCEREFS + 1u];

/*! HAL core configuration data: OsCore4 */
extern CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore4;

/*! HAL AUTOSAR core configuration data: OsCore4 */
extern CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore4;

# define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE5_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore5 */
extern CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore5_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE5_INTERRUPTSOURCEREFS + 1u];

/*! HAL core configuration data: OsCore5 */
extern CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore5;

/*! HAL AUTOSAR core configuration data: OsCore5 */
extern CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore5;

# define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core to thread configuration data. */
extern CONST(Os_Hal_Core2ThreadConfigType, OS_CONST) OsCfg_Hal_Core2Thread;

/*! HAL system configuration data. */
extern CONST(Os_Hal_SystemConfigType, OS_CONST) OsCfg_Hal_System;

/*! HAL system initialized interrupt sources. */
extern CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_System_InterruptSourceRefs[OS_CFG_NUM_SYSTEM_INTERRUPTSOURCEREFS + 1u];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_CORE_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core_Lcfg.h
 *********************************************************************************************************************/
 
