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
 *              File: Os_Spinlock_Lcfg.h
 *   Generation Time: 2024-01-08 16:27:33
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

#ifndef OS_SPINLOCK_LCFG_H
# define OS_SPINLOCK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Spinlock_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Spinlock configuration data: Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL */
extern CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL;

/*! Spinlock configuration data: Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR */
extern CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR;

/*! Spinlock configuration data: Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL */
extern CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL;

/*! Spinlock configuration data: Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR */
extern CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR;

/*! Spinlock configuration data: Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct */
extern CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct;

/*! Spinlock configuration data: Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct */
extern CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct;

/*! Spinlock configuration data: Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct */
extern CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct;

/*! Spinlock configuration data: Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct */
extern CONST(Os_SpinlockConfigType, OS_CONST) OsCfg_Spinlock_Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct;

/*! Object reference table for spinlocks. */
extern CONSTP2CONST(Os_SpinlockConfigType, OS_CONST, OS_CONST) OsCfg_SpinlockRefs[OS_SPINLOCKID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_SPINLOCK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Spinlock_Lcfg.h
 *********************************************************************************************************************/
