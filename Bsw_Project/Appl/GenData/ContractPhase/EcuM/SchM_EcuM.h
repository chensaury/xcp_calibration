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
 *          File:  SchM_EcuM.h
 *        Config:  E:/Autosar_CP/TC397_Classic/SIP_0317/give_customer/Bsw_Project/Bsw_Project.dpa
 *    BSW Module:  EcuM
 *  Generated at:  Tue Mar 21 20:44:33 2023
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header of BSW Scheduler for BSW Module <EcuM> (Contract Phase)
 *********************************************************************************************************************/
#ifndef SCHM_ECUM_H
# define SCHM_ECUM_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_EcuM_Type.h"

# define ECUM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, ECUM_CODE) EcuM_MainFunction(void); /* PRQA S 3451 */ /* MD_Rte_3451 */

# define ECUM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0(void);
FUNC(void, RTE_CODE) SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0(void);
FUNC(void, RTE_CODE) SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_1(void);
FUNC(void, RTE_CODE) SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_1(void);
FUNC(void, RTE_CODE) SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_2(void);
FUNC(void, RTE_CODE) SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_2(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_ECUM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
