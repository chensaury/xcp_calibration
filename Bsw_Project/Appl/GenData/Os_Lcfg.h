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
 *              File: Os_Lcfg.h
 *   Generation Time: 2023-04-07 21:29:29
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

#ifndef OS_LCFG_H
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */


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

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_APP_Task_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  APP_Task_Core0()
 *********************************************************************************************************************/
extern FUNC(void, OS_APP_TASK_CORE0_CODE) Os_Task_APP_Task_Core0(void);

# define OS_STOP_SEC_APP_Task_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_APP_Task_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  APP_Task_Core1()
 *********************************************************************************************************************/
extern FUNC(void, OS_APP_TASK_CORE1_CODE) Os_Task_APP_Task_Core1(void);

# define OS_STOP_SEC_APP_Task_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_APP_Task_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  APP_Task_Core2()
 *********************************************************************************************************************/
extern FUNC(void, OS_APP_TASK_CORE2_CODE) Os_Task_APP_Task_Core2(void);

# define OS_STOP_SEC_APP_Task_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_APP_Task_Core3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  APP_Task_Core3()
 *********************************************************************************************************************/
extern FUNC(void, OS_APP_TASK_CORE3_CODE) Os_Task_APP_Task_Core3(void);

# define OS_STOP_SEC_APP_Task_Core3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_APP_Task_Core4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  APP_Task_Core4()
 *********************************************************************************************************************/
extern FUNC(void, OS_APP_TASK_CORE4_CODE) Os_Task_APP_Task_Core4(void);

# define OS_STOP_SEC_APP_Task_Core4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_APP_Task_Core5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  APP_Task_Core5()
 *********************************************************************************************************************/
extern FUNC(void, OS_APP_TASK_CORE5_CODE) Os_Task_APP_Task_Core5(void);

# define OS_STOP_SEC_APP_Task_Core5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Init_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Core0()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_CORE0_CODE) Os_Task_Init_Core0(void);

# define OS_STOP_SEC_Init_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Init_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Core1()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_CORE1_CODE) Os_Task_Init_Core1(void);

# define OS_STOP_SEC_Init_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Init_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Core2()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_CORE2_CODE) Os_Task_Init_Core2(void);

# define OS_STOP_SEC_Init_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Init_Core3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Core3()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_CORE3_CODE) Os_Task_Init_Core3(void);

# define OS_STOP_SEC_Init_Core3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Init_Core4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Core4()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_CORE4_CODE) Os_Task_Init_Core4(void);

# define OS_STOP_SEC_Init_Core4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Init_Core5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Core5()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_CORE5_CODE) Os_Task_Init_Core5(void);

# define OS_STOP_SEC_Init_Core5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SchM_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SchM_Core0()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCHM_CORE0_CODE) Os_Task_SchM_Core0(void);

# define OS_STOP_SEC_SchM_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SchM_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SchM_Core1()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCHM_CORE1_CODE) Os_Task_SchM_Core1(void);

# define OS_STOP_SEC_SchM_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SchM_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SchM_Core2()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCHM_CORE2_CODE) Os_Task_SchM_Core2(void);

# define OS_STOP_SEC_SchM_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SchM_Core3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SchM_Core3()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCHM_CORE3_CODE) Os_Task_SchM_Core3(void);

# define OS_STOP_SEC_SchM_Core3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SchM_Core4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SchM_Core4()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCHM_CORE4_CODE) Os_Task_SchM_Core4(void);

# define OS_STOP_SEC_SchM_Core4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SchM_Core5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SchM_Core5()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCHM_CORE5_CODE) Os_Task_SchM_Core5(void);

# define OS_STOP_SEC_SchM_Core5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsr_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsr_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISR_0_CODE) Os_Isr_CanIsr_0(void);

# define OS_STOP_SEC_CanIsr_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
