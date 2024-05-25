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
 *              File: Os_Hal_Lcfg.h
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

#ifndef OS_HAL_LCFG_H
# define OS_HAL_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! OS-Core identifier */
#define OS_CORE_ID_0 OS_CORE_ID_0
#define OS_CORE_ID_1 OS_CORE_ID_1
#define OS_CORE_ID_2 OS_CORE_ID_2
#define OS_CORE_ID_3 OS_CORE_ID_3
#define OS_CORE_ID_4 OS_CORE_ID_4
#define OS_CORE_ID_5 OS_CORE_ID_5

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! OS-Core identifier.
 * \details Logical Core IDs for all cores, which are physically available.
 *          Notation: OS_CORE_ID_<X> = <Y>, where
 *            - X equals the ECUC core ID and
 *            - Y is a continuous core ID number running from 0 to OS_COREID_COUNT-1.
 */
typedef enum
{
  OS_CORE_ID_MASTER = 0,
  OS_CORE_ID_0 = 0, /* 0x00000001 - OsCore0 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_CORE_ID_1 = 1, /* 0x00000002 - OsCore1 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_CORE_ID_2 = 2, /* 0x00000004 - OsCore2 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_CORE_ID_3 = 3, /* 0x00000008 - OsCore3 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_CORE_ID_4 = 4, /* 0x00000010 - OsCore4 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_CORE_ID_5 = 5, /* 0x00000020 - OsCore5 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_COREID_COUNT = 6
} CoreIdType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Lcfg.h
 *********************************************************************************************************************/
