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
 *          File:  SchM_ComM.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header of BSW Scheduler for BSW Module <ComM>
 *********************************************************************************************************************/
#ifndef SCHM_COMM_H
# define SCHM_COMM_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_ComM_Type.h"

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */

# define COMM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, COMM_CODE) ComM_MainFunction_0(void); /* PRQA S 3451 */ /* MD_Rte_3451 */
FUNC(void, COMM_CODE) ComM_MainFunction_1(void); /* PRQA S 3451 */ /* MD_Rte_3451 */
FUNC(void, COMM_CODE) ComM_MainFunction_2(void); /* PRQA S 3451 */ /* MD_Rte_3451 */
FUNC(void, COMM_CODE) ComM_MainFunction_3(void); /* PRQA S 3451 */ /* MD_Rte_3451 */
FUNC(void, COMM_CODE) ComM_MainFunction_4(void); /* PRQA S 3451 */ /* MD_Rte_3451 */
FUNC(void, COMM_CODE) ComM_MainFunction_5(void); /* PRQA S 3451 */ /* MD_Rte_3451 */

# define COMM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1(void);
FUNC(void, RTE_CODE) SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_COMM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
