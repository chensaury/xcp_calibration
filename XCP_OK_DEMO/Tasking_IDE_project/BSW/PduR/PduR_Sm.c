/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PduR_Sm.c
 *      Project:  Gw_AsrPduRCfg5
 *       Module:  MICROSAR PDU Router
 *    Generator:  Configurator 5
 *
 *  Description:  Vector implementation of AUTOSAR PDU Router
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */
/* *INDENT-ON* */

#define PDUR_SM_SOURCE
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Sm.h"
#include "SchM_PduR.h"
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * PduR_Sm_SaTaFromMetaDataCalculationStrategy_GetSa
 *********************************************************************************************************************/
/*! \brief       This function extract the source address from the meta data.
 *  \details     -
 *  \param[in]   smSaTaFromMetaDataCalculationStrategyRomIdx Source Target address Rom Idx
 *  \param[in]   metaData  Meta data contains Source Target address
 *  \return      PduR_SmSaType   metaData + offset & mask;
 *  \pre         -
 *********************************************************************************************************************/
#if(PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROM == STD_ON)
LOCAL_INLINE FUNC(PduR_SmSaType, PDUR_CODE) PduR_Sm_SaTaFromMetaDataCalculationStrategy_GetSa(PduR_SmSaTaFromMetaDataCalculationStrategyRomIterType smSaTaFromMetaDataCalculationStrategyRomIdx,
                                                                                              uint32 metaData);
#endif
/**********************************************************************************************************************
 * PduR_Sm_SaTaFromMetaDataCalculationStrategy_GetTa
 *********************************************************************************************************************/
/*! \brief       This function extract the target address from the meta data.
 *  \details     -
 *  \param[in]   smSaTaFromMetaDataCalculationStrategyRomIdx Source Target address Rom Idx.
 *  \param[in]   metaData  Meta data contains Source Target address.
 *  \return      PduR_SmSaType   metaData + offset & mask.
 *  \pre         -
 *********************************************************************************************************************/
#if(PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROM == STD_ON)
LOCAL_INLINE FUNC(PduR_SmTaType, PDUR_CODE) PduR_Sm_SaTaFromMetaDataCalculationStrategy_GetTa(PduR_SmSaTaFromMetaDataCalculationStrategyRomIterType smSaTaFromMetaDataCalculationStrategyRomIdx,
                                                                                              uint32 metaData);
#endif
/**********************************************************************************************************************
 * PduR_Sm_GetMetaData
 *********************************************************************************************************************/
/*! \brief       This function extract meta data.
 *  \details     -
 *  \param[in]   info contains metadata.
 *  \param[in]   metaDataLength meta data length.
 *  \return      meta data.
 *  \pre         -
 *********************************************************************************************************************/
#if(PDUR_SMDATAPLANEROM == STD_ON)
LOCAL_INLINE FUNC(uint32, PDUR_CODE) PduR_Sm_GetMetaData(P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, uint8 metaDataLength);
#endif
 /*********************************************************************************************************************
 * PduR_Sm_GetMetaData
 *********************************************************************************************************************/
/*! \brief       This function updates the Fib table while a routing was learned.
 *  \details     -
 *  \param[in]   sourceAdress    source adress
 *  \param[in]   smDataPlaneIdx  Data plan Idx
 *  \param[in]   learnedConnectionId  learned connection Id.
 *  \pre         -
 *********************************************************************************************************************/
#if(PDUR_SMDATAPLANEROM == STD_ON)
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Sm_UpdateFib(PduR_SmDataPlaneRomIterType smDataPlaneIdx, PduR_SmSaType sourceAdress, PduR_ConnectionIdOfSmSrcRomType learnedConnectionId);
#endif
/**********************************************************************************************************************
 * PduR_Sm_CheckLearned
 *********************************************************************************************************************/
/*! \brief       This function checks if a routing is learned.
 *  \details     -
 *  \param[in]   smDataPlaneIdx   Data plane Idx.
 *  \param[in]   targetAdress     target adress.
 *  \param[in]   destConnection   destination connection Id.
 *  \return      PduR_FilterReturnType
 *                - PDUR_FILTER_PASS  Let the routing pass.
 *                - PDUR_FILTER_BLOCK Block the routing, it is not the learned destination connection
 *  \pre         -
 *********************************************************************************************************************/
#if(PDUR_SMDATAPLANEROM == STD_ON)
LOCAL_INLINE FUNC(PduR_FilterReturnType, PDUR_CODE) PduR_Sm_CheckLearned(PduR_SmDataPlaneRomIterType smDataPlaneIdx, PduR_SmTaType targetAdress, PduR_ConnectionIdOfSmGDestRomType destConnection);
#endif

#define PDUR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#if (PDUR_SMDATAPLANEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Sm_Init(void)
{
  PduR_SmFibRamIterType smFibRamIdx;
  for(smFibRamIdx = 0; smFibRamIdx < PduR_GetSizeOfSmFibRam(); smFibRamIdx++)
  {
    PduR_SetLearnedConnectionIdOfSmFibRam(smFibRamIdx, PDUR_SM_UNLEARNED_CONNECTION);   /* SBSW_PDUR_CSL01 */
  }
}
#endif

#if (PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_LinearTaToSaCalculationStrategy_GetSa_AddOffset
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_SmSaType, PDUR_CODE) PduR_Sm_LinearTaToSaCalculationStrategy_GetSa_AddOffset(PduR_SmLinearTaToSaCalculationStrategyRomIterType smLinearTaToSaCalculationStrategyIdx, uint32 metaData)
{
  PduR_MaskOfSmLinearTaToSaCalculationStrategyRomType mask = PduR_GetMaskOfSmLinearTaToSaCalculationStrategyRom(smLinearTaToSaCalculationStrategyIdx);
  PduR_OffsetOfSmLinearTaToSaCalculationStrategyRomType offset = PduR_GetOffsetOfSmLinearTaToSaCalculationStrategyRom(smLinearTaToSaCalculationStrategyIdx);
  PduR_SmSaType sourceAdress = (metaData + offset) & mask;
  return sourceAdress;
}
#endif

#if (PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_LinearTaToSaCalculationStrategy_SubtractOffset
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_SmSaType, PDUR_CODE) PduR_Sm_LinearTaToSaCalculationStrategy_GetSa_SubtractOffset(PduR_SmLinearTaToSaCalculationStrategyRomIterType smLinearTaToSaCalculationStrategyIdx, uint32 metaData)
{
  PduR_MaskOfSmLinearTaToSaCalculationStrategyRomType mask = PduR_GetMaskOfSmLinearTaToSaCalculationStrategyRom(smLinearTaToSaCalculationStrategyIdx);
  PduR_OffsetOfSmLinearTaToSaCalculationStrategyRomType offset = PduR_GetOffsetOfSmLinearTaToSaCalculationStrategyRom(smLinearTaToSaCalculationStrategyIdx);
  PduR_SmSaType sourceAdress = (metaData - offset) & mask;
  return sourceAdress;
}
#endif

#if (PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_SaTaFromMetaDataCalculationStrategy_GetSa
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_SmSaType, PDUR_CODE) PduR_Sm_SaTaFromMetaDataCalculationStrategy_GetSa(PduR_SmSaTaFromMetaDataCalculationStrategyRomIterType smSaTaFromMetaDataCalculationStrategyRomIdx,
                                                                                              uint32 metaData)
{
  /* Get adress startbit / mask */
  PduR_SaStartBitOfSmSaTaFromMetaDataCalculationStrategyRomType saStartBitPos = PduR_GetSaStartBitOfSmSaTaFromMetaDataCalculationStrategyRom(smSaTaFromMetaDataCalculationStrategyRomIdx);
  PduR_SaMaskOfSmSaTaFromMetaDataCalculationStrategyRomType saMask = PduR_GetSaMaskOfSmSaTaFromMetaDataCalculationStrategyRom(smSaTaFromMetaDataCalculationStrategyRomIdx);

  /* Extract SA and TA from meta data */
  PduR_SmSaType sourceAdress = (metaData >> saStartBitPos) & saMask;
  return sourceAdress;
}
#endif

#if (PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_SaTaFromMetaDataCalculationStrategy_GetTa
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_SmTaType, PDUR_CODE) PduR_Sm_SaTaFromMetaDataCalculationStrategy_GetTa(PduR_SmSaTaFromMetaDataCalculationStrategyRomIterType smSaTaFromMetaDataCalculationStrategyRomIdx,
                                                                                              uint32 metaData)
{
  /* Get adress startbit / mask */
  PduR_TaStartBitOfSmSaTaFromMetaDataCalculationStrategyRomType taStartBitPos = PduR_GetTaStartBitOfSmSaTaFromMetaDataCalculationStrategyRom(smSaTaFromMetaDataCalculationStrategyRomIdx);
  PduR_TaMaskOfSmSaTaFromMetaDataCalculationStrategyRomType taMask = PduR_GetTaMaskOfSmSaTaFromMetaDataCalculationStrategyRom(smSaTaFromMetaDataCalculationStrategyRomIdx);

  /* Extract SA and TA from meta data */
  PduR_SmTaType targetAdress = (metaData >> taStartBitPos) & taMask;
  return targetAdress;
}
#endif

#if (PDUR_SMDATAPLANEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_GetMetaData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint32, PDUR_CODE) PduR_Sm_GetMetaData(P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, uint8 metaDataLength)
{
  uint32 metaData = 0u;         /* PRQA S 2981 */ /* MD_MSR_RetVal */
  SduDataPtrType metaDataPtr = &info->SduDataPtr[info->SduLength - metaDataLength];
  uint8 itMetaData;
  for(itMetaData = metaDataLength; itMetaData > 0u; itMetaData--)
  {
    metaData = (((uint32) (metaData << 8u)) | metaDataPtr[itMetaData - 1u]);
  }
  return metaData;
}
#endif

#if (PDUR_SMDATAPLANEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_UpdateFib
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Sm_UpdateFib(PduR_SmDataPlaneRomIterType smDataPlaneIdx, PduR_SmSaType sourceAdress, PduR_ConnectionIdOfSmSrcRomType learnedConnectionId)
{
  PduR_SmFibRamIterType smFibRamIdx = PduR_GetSmFibRamStartIdxOfSmDataPlaneRom(smDataPlaneIdx) + sourceAdress;
  SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
  PduR_SetLearnedConnectionIdOfSmFibRam(smFibRamIdx, (PduR_LearnedConnectionIdOfSmFibRamType) learnedConnectionId);     /* SBSW_PDUR_CSL01 */
  SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
}
#endif

#if (PDUR_SMDATAPLANEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_CheckLearned
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_FilterReturnType, PDUR_CODE) PduR_Sm_CheckLearned(PduR_SmDataPlaneRomIterType smDataPlaneIdx, PduR_SmTaType targetAdress, PduR_ConnectionIdOfSmGDestRomType destConnection)
{
  PduR_FilterReturnType filterResult;
  PduR_SmFibRamIterType smFibRamIdx = PduR_GetSmFibRamStartIdxOfSmDataPlaneRom(smDataPlaneIdx) + targetAdress;
  PduR_LearnedConnectionIdOfSmFibRamType learnedConnectionId;

  SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
  learnedConnectionId = PduR_GetLearnedConnectionIdOfSmFibRam(smFibRamIdx);
  SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();

  if((learnedConnectionId == PDUR_SM_UNLEARNED_CONNECTION) ||   /* Related connection is no learned yet. */
     (learnedConnectionId == destConnection))   /* Routing destination connection is the learned connection. */
  {
    filterResult = PDUR_FILTER_PASS;    /* Let the routing pass */
  }
  else
  {
    filterResult = PDUR_FILTER_BLOCK;   /* Block the routing, it is not the learned destination connection */
  }
  return filterResult;
}
#endif

#if(PDUR_SMDATAPLANEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_SrcFilter_LinearTaToSaCalculationStrategy
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Sm_SrcFilter_LinearTaToSaCalculationStrategy(PduR_SmSrcRomIdxOfRmSrcRomType smSrcRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  PduR_SmDataPlaneRomIterType smDataPlaneIdx = PduR_GetSmDataPlaneRomIdxOfSmSrcRom(smSrcRomIdx);
  PduR_SmLinearTaToSaCalculationStrategyRomIterType smLinearTaToSaCalculationStrategyIdx = PduR_GetSmLinearTaToSaCalculationStrategyRomIdxOfSmDataPlaneRom(smDataPlaneIdx);

  /* Get adress info from Pdu */
  uint32 metaData = PduR_Sm_GetMetaData(info, PduR_GetMetaDataLengthOfSmSrcRom(smSrcRomIdx));   /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  PduR_Sm_LinearTaToSaCalculationStrategy_GetSaFctPtrType getSaFctPtr =
    PduR_GetSmLinearTaToSaCalculationStrategyGetSaFctPtr(PduR_GetSmLinearTaToSaCalculationStrategyGetSaFctPtrIdxOfSmSrcRom(smSrcRomIdx));
  PduR_SmSaType sourceAdress = getSaFctPtr(smLinearTaToSaCalculationStrategyIdx, metaData);     /* SBSW_PDUR_CSL03 */

  /* Update FIB */
  PduR_Sm_UpdateFib(smDataPlaneIdx, sourceAdress, PduR_GetConnectionIdOfSmSrcRom(smSrcRomIdx));
}
#endif

#if(PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_DestFilter_LinearTaToSaCalculationStrategy
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_FilterReturnType, PDUR_CODE) PduR_Sm_DestFilter_LinearTaToSaCalculationStrategy(PduR_SmGDestRomIdxOfRmGDestRomType smGDestRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  PduR_SmDataPlaneRomIterType smDataPlaneIdx = PduR_GetSmDataPlaneRomIdxOfSmGDestRom(smGDestRomIdx);
  PduR_SmLinearTaToSaCalculationStrategyRomIterType smLinearTaToSaCalculationStrategyIdx = PduR_GetSmLinearTaToSaCalculationStrategyRomIdxOfSmDataPlaneRom(smDataPlaneIdx);

  /* Get target adress from meta data */
  uint32 metaData = PduR_Sm_GetMetaData(info, PduR_GetMetaDataLengthOfSmGDestRom(smGDestRomIdx));       /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  PduR_MaskOfSmLinearTaToSaCalculationStrategyRomType mask = PduR_GetMaskOfSmLinearTaToSaCalculationStrategyRom(smLinearTaToSaCalculationStrategyIdx);
  PduR_SmTaType targetAdress = metaData & mask;

  /* Check if destination is already known */
  return PduR_Sm_CheckLearned(smDataPlaneIdx, targetAdress, PduR_GetConnectionIdOfSmGDestRom(smGDestRomIdx));
}
#endif

#if (PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_SrcFilter_SaTaFromMetaDataCalculationStrategy
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Sm_SrcFilter_SaTaFromMetaDataCalculationStrategy(PduR_SmSrcRomIdxOfRmSrcRomType smSrcRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  PduR_SmDataPlaneRomIterType smDataPlaneRomIdx = PduR_GetSmDataPlaneRomIdxOfSmSrcRom(smSrcRomIdx);

  /* Get adress info from Pdu */
  uint32 metaData = PduR_Sm_GetMetaData(info, PduR_GetMetaDataLengthOfSmSrcRom(smSrcRomIdx));   /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  PduR_SmSaType sa = PduR_Sm_SaTaFromMetaDataCalculationStrategy_GetSa(PduR_GetSmSaTaFromMetaDataCalculationStrategyRomIdxOfSmDataPlaneRom(smDataPlaneRomIdx), metaData);

  /* Update FIB */
  PduR_Sm_UpdateFib(smDataPlaneRomIdx, sa, PduR_GetConnectionIdOfSmSrcRom(smSrcRomIdx));
}
#endif

#if (PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_DestFilter_SaTaFromMetaDataCalculationStrategy
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_FilterReturnType, PDUR_CODE) PduR_Sm_DestFilter_SaTaFromMetaDataCalculationStrategy(PduR_SmGDestRomIdxOfRmGDestRomType smGDestRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  PduR_SmDataPlaneRomIterType smDataPlaneRomIdx = PduR_GetSmDataPlaneRomIdxOfSmGDestRom(smGDestRomIdx);

  /* Get adress info from Pdu */
  uint32 metaData = PduR_Sm_GetMetaData(info, PduR_GetMetaDataLengthOfSmGDestRom(smGDestRomIdx));       /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  PduR_SmSaType ta = PduR_Sm_SaTaFromMetaDataCalculationStrategy_GetTa(PduR_GetSmSaTaFromMetaDataCalculationStrategyRomIdxOfSmDataPlaneRom(smDataPlaneRomIdx), metaData);

  /* Check if destination is already known */
  return PduR_Sm_CheckLearned(smDataPlaneRomIdx, ta, PduR_GetConnectionIdOfSmGDestRom(smGDestRomIdx));
}
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: PduR_Sm.c
 *********************************************************************************************************************/
