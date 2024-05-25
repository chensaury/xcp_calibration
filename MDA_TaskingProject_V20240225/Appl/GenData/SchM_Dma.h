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
 *          File:  SchM_Dma.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header of BSW Scheduler for BSW Module <Dma>
 *********************************************************************************************************************/
#ifndef SCHM_DMA_H
# define SCHM_DMA_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Dma_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_Dma_ChEventStatus(void);
FUNC(void, RTE_CODE) SchM_Exit_Dma_ChEventStatus(void);
FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelConfigUpdate(void);
FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelConfigUpdate(void);
FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelFreezeResume(void);
FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelFreezeResume(void);
FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelHWTrigger(void);
FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelHWTrigger(void);
FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelInitDeinit(void);
FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelInitDeinit(void);
FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelStartStop(void);
FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelStartStop(void);
FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelSwitchBuffer(void);
FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelSwitchBuffer(void);
FUNC(void, RTE_CODE) SchM_Enter_Dma_InterruptStatus(void);
FUNC(void, RTE_CODE) SchM_Exit_Dma_InterruptStatus(void);
FUNC(void, RTE_CODE) SchM_Enter_Dma_MEErrorStatus(void);
FUNC(void, RTE_CODE) SchM_Exit_Dma_MEErrorStatus(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_DMA_H */
