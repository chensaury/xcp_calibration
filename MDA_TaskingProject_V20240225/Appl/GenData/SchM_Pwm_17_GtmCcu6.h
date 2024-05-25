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
 *          File:  SchM_Pwm_17_GtmCcu6.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header of BSW Scheduler for BSW Module <Pwm_17_GtmCcu6>
 *********************************************************************************************************************/
#ifndef SCHM_PWM_17_GTMCCU6_H
# define SCHM_PWM_17_GTMCCU6_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Pwm_17_GtmCcu6_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_Pwm_17_GtmCcu6_HandleNotification(void);
FUNC(void, RTE_CODE) SchM_Exit_Pwm_17_GtmCcu6_HandleNotification(void);
FUNC(void, RTE_CODE) SchM_Enter_Pwm_17_GtmCcu6_PeriodAndDutyUpdate(void);
FUNC(void, RTE_CODE) SchM_Exit_Pwm_17_GtmCcu6_PeriodAndDutyUpdate(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_PWM_17_GTMCCU6_H */
