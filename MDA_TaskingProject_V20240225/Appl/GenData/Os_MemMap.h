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
 *              File: Os_MemMap.h
 *   Generation Time: 2024-01-08 16:27:32
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

                                                                                                                        /* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */

#include "Os_MemMap_OsCodeInt.h"
#include "Os_MemMap_OsSectionsInt.h"
#include "Os_MemMap_StacksInt.h"

/**********************************************************************************************************************
 *  CODE SECTIONS  (Tasking)
 *********************************************************************************************************************/

#ifdef OS_START_SEC_OS_COREINITHOOK_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OS_COREINITHOOK_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_OS_COREINITHOOK_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OS_COREINITHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OS_COREINITHOOK_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OS_COREINITHOOK_CODE_OPEN
#  error Section OS_OS_COREINITHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_OS_COREINITHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OS_COREINITHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_ADC0SR0_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_ADC0SR0_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_ADC0SR0_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_ADC0SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_ADC0SR0_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_ADC0SR0_ISR_CODE_OPEN
#  error Section OS_ADC0SR0_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_ADC0SR0_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_ADC0SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_ADC1SR0_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_ADC1SR0_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_ADC1SR0_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_ADC1SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_ADC1SR0_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_ADC1SR0_ISR_CODE_OPEN
#  error Section OS_ADC1SR0_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_ADC1SR0_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_ADC1SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_ADC2SR0_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_ADC2SR0_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_ADC2SR0_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_ADC2SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_ADC2SR0_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_ADC2SR0_ISR_CODE_OPEN
#  error Section OS_ADC2SR0_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_ADC2SR0_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_ADC2SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_ADC3SR0_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_ADC3SR0_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_ADC3SR0_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_ADC3SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_ADC3SR0_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_ADC3SR0_ISR_CODE_OPEN
#  error Section OS_ADC3SR0_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_ADC3SR0_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_ADC3SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_ADC8SR0_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_ADC8SR0_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_ADC8SR0_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_ADC8SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_ADC8SR0_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_ADC8SR0_ISR_CODE_OPEN
#  error Section OS_ADC8SR0_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_ADC8SR0_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_ADC8SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_APP_Task_Core0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_APP_Task_Core0_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_APP_Task_Core0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_APP_Task_Core0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_APP_Task_Core0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_APP_Task_Core0_CODE_OPEN
#  error Section OS_APP_Task_Core0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_APP_Task_Core0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_APP_Task_Core0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_APP_Task_Core1_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_APP_Task_Core1_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_APP_Task_Core1_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_APP_Task_Core1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_APP_Task_Core1_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_APP_Task_Core1_CODE_OPEN
#  error Section OS_APP_Task_Core1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_APP_Task_Core1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_APP_Task_Core1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_APP_Task_Core2_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_APP_Task_Core2_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_APP_Task_Core2_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_APP_Task_Core2_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_APP_Task_Core2_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_APP_Task_Core2_CODE_OPEN
#  error Section OS_APP_Task_Core2_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_APP_Task_Core2_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_APP_Task_Core2_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_APP_Task_Core3_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_APP_Task_Core3_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_APP_Task_Core3_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_APP_Task_Core3_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_APP_Task_Core3_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_APP_Task_Core3_CODE_OPEN
#  error Section OS_APP_Task_Core3_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_APP_Task_Core3_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_APP_Task_Core3_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_APP_Task_Core4_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_APP_Task_Core4_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_APP_Task_Core4_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_APP_Task_Core4_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_APP_Task_Core4_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_APP_Task_Core4_CODE_OPEN
#  error Section OS_APP_Task_Core4_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_APP_Task_Core4_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_APP_Task_Core4_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_APP_Task_Core5_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_APP_Task_Core5_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_APP_Task_Core5_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_APP_Task_Core5_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_APP_Task_Core5_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_APP_Task_Core5_CODE_OPEN
#  error Section OS_APP_Task_Core5_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_APP_Task_Core5_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_APP_Task_Core5_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_CanIsr_0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CanIsr_0_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_CanIsr_0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CanIsr_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CanIsr_0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CanIsr_0_CODE_OPEN
#  error Section OS_CanIsr_0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_CanIsr_0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CanIsr_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_CanIsr_1_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CanIsr_1_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_CanIsr_1_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CanIsr_1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CanIsr_1_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CanIsr_1_CODE_OPEN
#  error Section OS_CanIsr_1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_CanIsr_1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CanIsr_1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_CanIsr_2_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CanIsr_2_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_CanIsr_2_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CanIsr_2_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CanIsr_2_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CanIsr_2_CODE_OPEN
#  error Section OS_CanIsr_2_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_CanIsr_2_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CanIsr_2_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_CanIsr_3_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CanIsr_3_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_CanIsr_3_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CanIsr_3_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CanIsr_3_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CanIsr_3_CODE_OPEN
#  error Section OS_CanIsr_3_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_CanIsr_3_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CanIsr_3_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_CanIsr_4_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CanIsr_4_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_CanIsr_4_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CanIsr_4_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CanIsr_4_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CanIsr_4_CODE_OPEN
#  error Section OS_CanIsr_4_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_CanIsr_4_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CanIsr_4_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_CanIsr_5_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CanIsr_5_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_CanIsr_5_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CanIsr_5_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CanIsr_5_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CanIsr_5_CODE_OPEN
#  error Section OS_CanIsr_5_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_CanIsr_5_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CanIsr_5_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Core_OsTask_CDD_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Core_OsTask_CDD_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_Core_OsTask_CDD_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Core_OsTask_CDD_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Core_OsTask_CDD_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Core_OsTask_CDD_CODE_OPEN
#  error Section OS_Core_OsTask_CDD_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Core_OsTask_CDD_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Core_OsTask_CDD_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Core_OsTask_IOHW_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Core_OsTask_IOHW_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_Core_OsTask_IOHW_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Core_OsTask_IOHW_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Core_OsTask_IOHW_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Core_OsTask_IOHW_CODE_OPEN
#  error Section OS_Core_OsTask_IOHW_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Core_OsTask_IOHW_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Core_OsTask_IOHW_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Core_OsTask_PSI5_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Core_OsTask_PSI5_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_Core_OsTask_PSI5_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Core_OsTask_PSI5_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Core_OsTask_PSI5_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Core_OsTask_PSI5_CODE_OPEN
#  error Section OS_Core_OsTask_PSI5_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Core_OsTask_PSI5_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Core_OsTask_PSI5_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Core_OsTask_PT2000_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Core_OsTask_PT2000_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_Core_OsTask_PT2000_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Core_OsTask_PT2000_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Core_OsTask_PT2000_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Core_OsTask_PT2000_CODE_OPEN
#  error Section OS_Core_OsTask_PT2000_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Core_OsTask_PT2000_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Core_OsTask_PT2000_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_DMACH0SR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_DMACH0SR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_DMACH0SR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_DMACH0SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_DMACH0SR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_DMACH0SR_ISR_CODE_OPEN
#  error Section OS_DMACH0SR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_DMACH0SR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_DMACH0SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_DMACH3SR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_DMACH3SR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_DMACH3SR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_DMACH3SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_DMACH3SR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_DMACH3SR_ISR_CODE_OPEN
#  error Section OS_DMACH3SR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_DMACH3SR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_DMACH3SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_DMACH4SR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_DMACH4SR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_DMACH4SR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_DMACH4SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_DMACH4SR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_DMACH4SR_ISR_CODE_OPEN
#  error Section OS_DMACH4SR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_DMACH4SR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_DMACH4SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_DMACH5SR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_DMACH5SR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_DMACH5SR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_DMACH5SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_DMACH5SR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_DMACH5SR_ISR_CODE_OPEN
#  error Section OS_DMACH5SR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_DMACH5SR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_DMACH5SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_DMACH6SR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_DMACH6SR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_DMACH6SR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_DMACH6SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_DMACH6SR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_DMACH6SR_ISR_CODE_OPEN
#  error Section OS_DMACH6SR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_DMACH6SR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_DMACH6SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_DMACH7SR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_DMACH7SR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_DMACH7SR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_DMACH7SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_DMACH7SR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_DMACH7SR_ISR_CODE_OPEN
#  error Section OS_DMACH7SR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_DMACH7SR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_DMACH7SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_DMACH8SR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_DMACH8SR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_DMACH8SR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_DMACH8SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_DMACH8SR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_DMACH8SR_ISR_CODE_OPEN
#  error Section OS_DMACH8SR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_DMACH8SR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_DMACH8SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_DMACH9SR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_DMACH9SR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_DMACH9SR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_DMACH9SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_DMACH9SR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_DMACH9SR_ISR_CODE_OPEN
#  error Section OS_DMACH9SR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_DMACH9SR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_DMACH9SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_DMAERR0SR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_DMAERR0SR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_DMAERR0SR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_DMAERR0SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_DMAERR0SR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_DMAERR0SR_ISR_CODE_OPEN
#  error Section OS_DMAERR0SR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_DMAERR0SR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_DMAERR0SR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GTMATOM0SR0_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GTMATOM0SR0_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_GTMATOM0SR0_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GTMATOM0SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GTMATOM0SR0_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GTMATOM0SR0_ISR_CODE_OPEN
#  error Section OS_GTMATOM0SR0_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_GTMATOM0SR0_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GTMATOM0SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GTMATOM1SR0_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GTMATOM1SR0_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_GTMATOM1SR0_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GTMATOM1SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GTMATOM1SR0_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GTMATOM1SR0_ISR_CODE_OPEN
#  error Section OS_GTMATOM1SR0_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_GTMATOM1SR0_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GTMATOM1SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GTMATOM2SR0_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GTMATOM2SR0_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_GTMATOM2SR0_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GTMATOM2SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GTMATOM2SR0_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GTMATOM2SR0_ISR_CODE_OPEN
#  error Section OS_GTMATOM2SR0_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_GTMATOM2SR0_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GTMATOM2SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GTMATOM4SR0_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GTMATOM4SR0_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_GTMATOM4SR0_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GTMATOM4SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GTMATOM4SR0_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GTMATOM4SR0_ISR_CODE_OPEN
#  error Section OS_GTMATOM4SR0_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_GTMATOM4SR0_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GTMATOM4SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GTMTIM2SR3_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GTMTIM2SR3_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_GTMTIM2SR3_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GTMTIM2SR3_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GTMTIM2SR3_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GTMTIM2SR3_ISR_CODE_OPEN
#  error Section OS_GTMTIM2SR3_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_GTMTIM2SR3_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GTMTIM2SR3_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GTMTIM2SR5_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GTMTIM2SR5_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_GTMTIM2SR5_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GTMTIM2SR5_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GTMTIM2SR5_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GTMTIM2SR5_ISR_CODE_OPEN
#  error Section OS_GTMTIM2SR5_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_GTMTIM2SR5_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GTMTIM2SR5_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GTMTOM0SR0_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GTMTOM0SR0_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_GTMTOM0SR0_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GTMTOM0SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GTMTOM0SR0_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GTMTOM0SR0_ISR_CODE_OPEN
#  error Section OS_GTMTOM0SR0_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_GTMTOM0SR0_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GTMTOM0SR0_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GTMTOM0SR1_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GTMTOM0SR1_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_GTMTOM0SR1_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GTMTOM0SR1_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GTMTOM0SR1_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GTMTOM0SR1_ISR_CODE_OPEN
#  error Section OS_GTMTOM0SR1_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_GTMTOM0SR1_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GTMTOM0SR1_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GTMTOM0SR2_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GTMTOM0SR2_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_GTMTOM0SR2_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GTMTOM0SR2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GTMTOM0SR2_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GTMTOM0SR2_ISR_CODE_OPEN
#  error Section OS_GTMTOM0SR2_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_GTMTOM0SR2_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GTMTOM0SR2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GTMTOM0SR3_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GTMTOM0SR3_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_GTMTOM0SR3_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GTMTOM0SR3_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GTMTOM0SR3_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GTMTOM0SR3_ISR_CODE_OPEN
#  error Section OS_GTMTOM0SR3_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_GTMTOM0SR3_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GTMTOM0SR3_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Init_Core0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Init_Core0_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_Init_Core0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Init_Core0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Init_Core0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Init_Core0_CODE_OPEN
#  error Section OS_Init_Core0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Init_Core0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Init_Core0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Init_Core1_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Init_Core1_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_Init_Core1_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Init_Core1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Init_Core1_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Init_Core1_CODE_OPEN
#  error Section OS_Init_Core1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Init_Core1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Init_Core1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Init_Core2_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Init_Core2_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_Init_Core2_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Init_Core2_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Init_Core2_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Init_Core2_CODE_OPEN
#  error Section OS_Init_Core2_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Init_Core2_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Init_Core2_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Init_Core3_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Init_Core3_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_Init_Core3_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Init_Core3_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Init_Core3_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Init_Core3_CODE_OPEN
#  error Section OS_Init_Core3_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Init_Core3_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Init_Core3_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Init_Core4_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Init_Core4_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_Init_Core4_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Init_Core4_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Init_Core4_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Init_Core4_CODE_OPEN
#  error Section OS_Init_Core4_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Init_Core4_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Init_Core4_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Init_Core5_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Init_Core5_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_Init_Core5_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Init_Core5_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Init_Core5_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Init_Core5_CODE_OPEN
#  error Section OS_Init_Core5_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Init_Core5_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Init_Core5_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QSPI0ERR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QSPI0ERR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_QSPI0ERR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QSPI0ERR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QSPI0ERR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QSPI0ERR_ISR_CODE_OPEN
#  error Section OS_QSPI0ERR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QSPI0ERR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QSPI0ERR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QSPI0PT_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QSPI0PT_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_QSPI0PT_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QSPI0PT_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QSPI0PT_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QSPI0PT_ISR_CODE_OPEN
#  error Section OS_QSPI0PT_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QSPI0PT_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QSPI0PT_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QSPI1ERR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QSPI1ERR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_QSPI1ERR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QSPI1ERR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QSPI1ERR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QSPI1ERR_ISR_CODE_OPEN
#  error Section OS_QSPI1ERR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QSPI1ERR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QSPI1ERR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QSPI1PT_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QSPI1PT_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_QSPI1PT_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QSPI1PT_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QSPI1PT_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QSPI1PT_ISR_CODE_OPEN
#  error Section OS_QSPI1PT_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QSPI1PT_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QSPI1PT_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QSPI2ERR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QSPI2ERR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_QSPI2ERR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QSPI2ERR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QSPI2ERR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QSPI2ERR_ISR_CODE_OPEN
#  error Section OS_QSPI2ERR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QSPI2ERR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QSPI2ERR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QSPI2PT_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QSPI2PT_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_QSPI2PT_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QSPI2PT_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QSPI2PT_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QSPI2PT_ISR_CODE_OPEN
#  error Section OS_QSPI2PT_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QSPI2PT_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QSPI2PT_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QSPI3ERR_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QSPI3ERR_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_QSPI3ERR_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QSPI3ERR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QSPI3ERR_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QSPI3ERR_ISR_CODE_OPEN
#  error Section OS_QSPI3ERR_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QSPI3ERR_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QSPI3ERR_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QSPI3PT_ISR_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QSPI3PT_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_QSPI3PT_ISR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QSPI3PT_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QSPI3PT_ISR_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QSPI3PT_ISR_CODE_OPEN
#  error Section OS_QSPI3PT_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QSPI3PT_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QSPI3PT_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SchM_Core0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SchM_Core0_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_SchM_Core0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SchM_Core0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SchM_Core0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SchM_Core0_CODE_OPEN
#  error Section OS_SchM_Core0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SchM_Core0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SchM_Core0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SchM_Core1_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SchM_Core1_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_SchM_Core1_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SchM_Core1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SchM_Core1_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SchM_Core1_CODE_OPEN
#  error Section OS_SchM_Core1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SchM_Core1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SchM_Core1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SchM_Core2_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SchM_Core2_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_SchM_Core2_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SchM_Core2_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SchM_Core2_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SchM_Core2_CODE_OPEN
#  error Section OS_SchM_Core2_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SchM_Core2_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SchM_Core2_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SchM_Core3_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SchM_Core3_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_SchM_Core3_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SchM_Core3_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SchM_Core3_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SchM_Core3_CODE_OPEN
#  error Section OS_SchM_Core3_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SchM_Core3_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SchM_Core3_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SchM_Core4_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SchM_Core4_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_SchM_Core4_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SchM_Core4_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SchM_Core4_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SchM_Core4_CODE_OPEN
#  error Section OS_SchM_Core4_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SchM_Core4_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SchM_Core4_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SchM_Core5_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SchM_Core5_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code "OS_SchM_Core5_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SchM_Core5_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SchM_Core5_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SchM_Core5_CODE_OPEN
#  error Section OS_SchM_Core5_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SchM_Core5_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section code restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SchM_Core5_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_GLOBALSHARED_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_GLOBALSHARED_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_GLOBALSHARED_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_GLOBALSHARED_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_GLOBALSHARED_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_GLOBALSHARED_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_GLOBALSHARED_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_GLOBALSHARED_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_GLOBALSHARED_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_GLOBALSHARED_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_GLOBALSHARED_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore0_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore0_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore0_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore0_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore0_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore0_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore0_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore0_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore0_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore0_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore1_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore1_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_CONST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore1_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore1_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore1_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_CONST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore1_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore1_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_CONST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore1_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore1_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_CONST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore1_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore1_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_CONST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore1_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore1_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore1_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore1_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore1_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore1_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_CONST_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore1_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore1_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_CONST_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore1_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore1_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_CONST_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore1_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore1_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore1_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore2_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore2_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_CONST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore2_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore2_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore2_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_CONST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore2_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore2_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_CONST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore2_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore2_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_CONST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore2_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore2_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_CONST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore2_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore2_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore2_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore2_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore2_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore2_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_CONST_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore2_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore2_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_CONST_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore2_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore2_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_CONST_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore2_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore2_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore2_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore3_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore3_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_CONST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore3_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore3_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore3_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_CONST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore3_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore3_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_CONST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore3_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore3_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_CONST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore3_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore3_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_CONST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore3_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore3_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore3_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore3_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore3_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore3_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_CONST_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore3_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore3_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_CONST_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore3_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore3_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_CONST_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore3_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore3_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore3_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore4_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore4_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_CONST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore4_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore4_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore4_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_CONST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore4_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore4_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_CONST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore4_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore4_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_CONST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore4_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore4_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_CONST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore4_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore4_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore4_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore4_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore4_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore4_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_CONST_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore4_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore4_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_CONST_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore4_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore4_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_CONST_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore4_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore4_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore4_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore5_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore5_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_CONST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore5_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore5_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore5_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_CONST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore5_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore5_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_CONST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore5_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore5_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_CONST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore5_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore5_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_CONST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore5_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore5_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore5_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore5_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore5_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore5_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_CONST_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore5_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore5_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_CONST_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore5_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore5_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_CONST_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom "OS_SystemApplication_OsCore5_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom "OS_SystemApplication_OsCore5_CONST_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore5_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


/**********************************************************************************************************************
 *  VAR SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_GLOBALSHARED_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore2_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore3_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore4_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_SystemApplication_OsCore5_VAR_FAST_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


/* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */
