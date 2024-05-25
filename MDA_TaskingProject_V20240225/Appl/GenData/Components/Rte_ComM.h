/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_ComM.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Application header file for SW-C <ComM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_COMM_H
# define _RTE_COMM_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_ComM_Type.h"
# include "Rte_DataHandleType.h"


# define ComM_START_SEC_CODE
# include "ComM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ComM_MainFunction_0 ComM_MainFunction_0
#  define RTE_RUNNABLE_ComM_MainFunction_1 ComM_MainFunction_1
#  define RTE_RUNNABLE_ComM_MainFunction_2 ComM_MainFunction_2
#  define RTE_RUNNABLE_ComM_MainFunction_3 ComM_MainFunction_3
#  define RTE_RUNNABLE_ComM_MainFunction_4 ComM_MainFunction_4
#  define RTE_RUNNABLE_ComM_MainFunction_5 ComM_MainFunction_5
#  define RTE_RUNNABLE_GetCurrentComMode ComM_GetCurrentComMode
#  define RTE_RUNNABLE_GetInhibitionStatus ComM_GetInhibitionStatus
#  define RTE_RUNNABLE_GetMaxComMode ComM_GetMaxComMode
#  define RTE_RUNNABLE_GetRequestedComMode ComM_GetRequestedComMode
#  define RTE_RUNNABLE_LimitChannelToNoComMode ComM_LimitChannelToNoComMode
#  define RTE_RUNNABLE_LimitECUToNoComMode ComM_LimitECUToNoComMode
#  define RTE_RUNNABLE_PreventWakeUp ComM_PreventWakeUp
#  define RTE_RUNNABLE_ReadInhibitCounter ComM_ReadInhibitCounter
#  define RTE_RUNNABLE_RequestComMode ComM_RequestComMode
#  define RTE_RUNNABLE_ResetInhibitCounter ComM_ResetInhibitCounter
#  define RTE_RUNNABLE_SetECUGroupClassification ComM_SetECUGroupClassification
# endif

FUNC(void, ComM_CODE) ComM_MainFunction_0(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ComM_CODE) ComM_MainFunction_1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ComM_CODE) ComM_MainFunction_2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ComM_CODE) ComM_MainFunction_3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ComM_CODE) ComM_MainFunction_4(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ComM_CODE) ComM_MainFunction_5(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, ComM_CODE) ComM_GetCurrentComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, ComM_CODE) ComM_GetInhibitionStatus(NetworkHandleType parg0, P2VAR(ComM_InhibitionStatusType, AUTOMATIC, RTE_COMM_APPL_VAR) Status); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, ComM_CODE) ComM_GetMaxComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, ComM_CODE) ComM_GetRequestedComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, ComM_CODE) ComM_LimitChannelToNoComMode(NetworkHandleType parg0, boolean Status); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, ComM_CODE) ComM_LimitECUToNoComMode(boolean Status); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, ComM_CODE) ComM_PreventWakeUp(NetworkHandleType parg0, boolean Status); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, ComM_CODE) ComM_ReadInhibitCounter(P2VAR(uint16, AUTOMATIC, RTE_COMM_APPL_VAR) CounterValue); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, ComM_CODE) ComM_RequestComMode(ComM_UserHandleType parg0, ComM_ModeType ComMode); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, ComM_CODE) ComM_ResetInhibitCounter(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, ComM_CODE) ComM_SetECUGroupClassification(ComM_InhibitionStatusType Status); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define ComM_STOP_SEC_CODE
# include "ComM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComM_ChannelLimitation_E_NOT_OK (1U)

#  define RTE_E_ComM_ChannelWakeUp_E_NOT_OK (1U)

#  define RTE_E_ComM_ECUModeLimitation_E_NOT_OK (1U)

#  define RTE_E_ComM_UserRequest_E_MODE_LIMITATION (2U)

#  define RTE_E_ComM_UserRequest_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_COMM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1330:  MISRA rule: 16.4
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
