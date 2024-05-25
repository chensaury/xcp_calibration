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
 *          File:  SchM_Icu_17_TimerIp.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header of BSW Scheduler for BSW Module <Icu_17_TimerIp>
 *********************************************************************************************************************/
#ifndef SCHM_ICU_17_TIMERIP_H
# define SCHM_ICU_17_TIMERIP_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Icu_17_TimerIp_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_CcuInterruptHandle(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_CcuInterruptHandle(void);
FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_CcuVariableupdate(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_CcuVariableupdate(void);
FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_EnableNotification(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_EnableNotification(void);
FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_EnableWakeup(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_EnableWakeup(void);
FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_GtmEnableEdgeCount(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_GtmEnableEdgeCount(void);
FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_GtmGetDutyCycle(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_GtmGetDutyCycle(void);
FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_ResetEdgeCount(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_ResetEdgeCount(void);
FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_SetActivationCondition(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_SetActivationCondition(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_ICU_17_TIMERIP_H */
