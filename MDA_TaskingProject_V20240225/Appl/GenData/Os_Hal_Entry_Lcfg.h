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
 *              File: Os_Hal_Entry_Lcfg.h
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


                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_ENTRY_LCFG_H
# define OS_HAL_ENTRY_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Core_Types.h"
# include "Os_Hal_Compiler.h"


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

# define OS_START_SEC_INTVEC_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_INTVEC_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXCVEC_CORE0_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_EXCVEC_CORE0_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_EXCVEC_CORE0_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_EXCVEC_CORE0_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTVEC_CORE0_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CORE0_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CORE0_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_INTVEC_CORE0_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXCVEC_CORE1_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_EXCVEC_CORE1_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_EXCVEC_CORE1_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_EXCVEC_CORE1_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTVEC_CORE1_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CORE1_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CORE1_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_INTVEC_CORE1_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXCVEC_CORE2_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_EXCVEC_CORE2_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_EXCVEC_CORE2_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_EXCVEC_CORE2_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTVEC_CORE2_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CORE2_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CORE2_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_INTVEC_CORE2_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXCVEC_CORE3_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_EXCVEC_CORE3_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_EXCVEC_CORE3_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_EXCVEC_CORE3_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTVEC_CORE3_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CORE3_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CORE3_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_INTVEC_CORE3_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXCVEC_CORE4_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_EXCVEC_CORE4_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_EXCVEC_CORE4_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_EXCVEC_CORE4_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTVEC_CORE4_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CORE4_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CORE4_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_INTVEC_CORE4_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXCVEC_CORE5_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_EXCVEC_CORE5_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_EXCVEC_CORE5_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_EXCVEC_CORE5_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTVEC_CORE5_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CORE5_CODE_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CORE5_CODE_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_INTVEC_CORE5_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_ENTRY_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Lcfg.h
 *********************************************************************************************************************/
