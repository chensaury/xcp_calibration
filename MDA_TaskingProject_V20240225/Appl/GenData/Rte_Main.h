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
 *          File:  Rte_Main.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Lifecycle Header File
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MAIN_H
# define _RTE_MAIN_H

# include "Rte.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* BSW Scheduler Life-Cycle API */
FUNC(void, RTE_CODE) SchM_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) SchM_Deinit(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/* RTE Life-Cycle API */
FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/* Extended Life-Cycle API */
FUNC(void, RTE_CODE) Rte_InitMemory(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_InitMemory_SystemApplication_OsCore0(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_InitMemory_SystemApplication_OsCore1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_InitMemory_SystemApplication_OsCore2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_InitMemory_SystemApplication_OsCore3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_InitMemory_SystemApplication_OsCore4(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_InitMemory_SystemApplication_OsCore5(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* _RTE_MAIN_H */
