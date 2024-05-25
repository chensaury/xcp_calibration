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
 *          File:  Rte_Os_OsCore4_swc.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Application header file for SW-C <Os_OsCore4_swc>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_OS_OSCORE4_SWC_H
# define _RTE_OS_OSCORE4_SWC_H

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

# include "Os.h"
# include "Rte_Os_OsCore4_swc_Type.h"
# include "Rte_DataHandleType.h"


# define Os_OsCore4_swc_START_SEC_CODE
# include "Os_OsCore4_swc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_GetCounterValue GetCounterValue
#  define RTE_RUNNABLE_GetElapsedValue GetElapsedValue
# endif

FUNC(Std_ReturnType, Os_OsCore4_swc_CODE) GetCounterValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE4_SWC_APPL_VAR) Value); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, Os_OsCore4_swc_CODE) GetElapsedValue(CounterType parg0, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE4_SWC_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_OS_OSCORE4_SWC_APPL_VAR) ElapsedValue); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */

# define Os_OsCore4_swc_STOP_SEC_CODE
# include "Os_OsCore4_swc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Os_Service_E_OK (0U)

#  define RTE_E_Os_Service_E_OS_ID (3U)

#  define RTE_E_Os_Service_E_OS_VALUE (8U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_OS_OSCORE4_SWC_H */

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
