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
 *         File:  PduR_Fm.c
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

#define PDUR_FM_SOURCE
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Bm.h"
#include "PduR_Fm.h"
#include "PduR_RmTp.h"
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
#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_DissolveFifoElementTxBufferRelation
 *********************************************************************************************************************/
/*! \brief      ReleaseTx buffer Fifo Element connection in case of a shared buffer
 *  \details    -
 *  \param[in]  fmFifoElementRamIdx    Fifo State Id used for state handling
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Fm_DissolveFifoElementTxBufferRelation(PduR_FmFifoElementRamIterType fmFifoElementRamIdx);
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_ReleaseFifoElement
 *********************************************************************************************************************/
/*! \brief      Reset Fifo Element.
 *  \details    -
 *  \param[in]  fmFifoElementRamIdx    Fifo State Id used for state handling.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Fm_ReleaseFifoElement(PduR_FmFifoElementRamIterType fmFifoElementRamIdx);
#endif

#define PDUR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#if(PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_Init(void)
{
  {
    PduR_FmFifoRamIterType fmFifoRamIdx;
    for(fmFifoRamIdx = 0u; fmFifoRamIdx < PduR_GetSizeOfFmFifoRam(); fmFifoRamIdx++)
    {
# if(PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
      PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRamIdx, PDUR_RM_TX_IDLE_TPTXSMSTATEOFFMFIFORAM);     /* SBSW_PDUR_CSL01 */
# endif
      PduR_SetPendingConfirmationsOfFmFifoRam(fmFifoRamIdx, 0u);        /* SBSW_PDUR_CSL01 */
      PduR_SetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRamIdx, PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRamIdx));      /* SBSW_PDUR_CSL01 */
      PduR_SetFmFifoElementRamWriteIdxOfFmFifoRam(fmFifoRamIdx, PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRamIdx));     /* SBSW_PDUR_CSL01 */
      PduR_SetFillLevelOfFmFifoRam(fmFifoRamIdx, 0u);   /* SBSW_PDUR_CSL01 */
    }
  }
  {
    PduR_FmFifoElementRamIterType fmFifoElementRamIdx;
    for(fmFifoElementRamIdx = 0u; fmFifoElementRamIdx < PduR_GetSizeOfFmFifoElementRam(); fmFifoElementRamIdx++)
    {
      PduR_SetStateOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_FM_IDLE_STATEOFFMFIFOELEMENTRAM);       /* SBSW_PDUR_CSL01 */
      PduR_SetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_NO_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM);      /* SBSW_PDUR_CSL01 */
      PduR_SetDedicatedTxBufferOfFmFifoElementRam(fmFifoElementRamIdx, FALSE);  /* SBSW_PDUR_CSL01 */
      PduR_SetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_NO_RMDESTROMIDXOFFMFIFOELEMENTRAM);      /* SBSW_PDUR_CSL01 */
    }
  }
  {
    PduR_FmFifoInstanceRamIterType fmFifoInstanceRamIdx;
    for(fmFifoInstanceRamIdx = 0u; fmFifoInstanceRamIdx < PduR_GetSizeOfFmFifoInstanceRam(); fmFifoInstanceRamIdx++)
    {
      PduR_SetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(fmFifoInstanceRamIdx, PDUR_NO_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM);   /* SBSW_PDUR_CSL01 */
    }
  }
}
#endif

#if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FlushFiFo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FlushFiFo(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamIdx;
  PduR_RmBufferedIfPropertiesRomIdxOfRmGDestRomType rmBufferedIfPropertiesRomIdx = PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(rmGDestRomIdx);

  for(fmFifoElementRamIdx = PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRomIdx); fmFifoElementRamIdx < PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(fmFifoRomIdx); fmFifoElementRamIdx++)
  {
    PduR_GetFctPtrOfFm_FlushFifoElement_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(fmFifoElementRamIdx)) (fmFifoElementRamIdx);   /* SBSW_PDUR_CSL01 */
  }
  PduR_SetIfSmStateOfRmBufferedIfPropertiesRam(rmBufferedIfPropertiesRomIdx, PduR_GetNextState_For_Init_If_Routing_StateOfIfRoutingStateTable(PduR_GetFifoTypeOfRmBufferedIfPropertiesRom(rmBufferedIfPropertiesRomIdx)));      /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  PduR_SetFillLevelOfFmFifoRam(fmFifoRomIdx, 0u);       /* PRQA S 2842 */ /* MD_PduR_2842 */ /* SBSW_PDUR_CSL02 */
  PduR_SetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx, PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRomIdx));  /* PRQA S 2842 */ /* MD_PduR_2842 */ /* SBSW_PDUR_CSL02 */
  PduR_SetFmFifoElementRamWriteIdxOfFmFifoRam(fmFifoRomIdx, PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRomIdx)); /* PRQA S 2842 */ /* MD_PduR_2842 */ /* SBSW_PDUR_CSL02 */
}
#endif

#if ((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM  == STD_ON))
/**********************************************************************************************************************
 * PduR_Fm_FreeFifoElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FreeFifoElement(PduR_FmFifoRomIterType fmFifoRomIdx, PduR_FmFifoElementRamWriteIdxOfFmFifoRamType fmFifoElementRamWriteIdx)
{
  /* no buffer available -> roll back release FiFo */
  if(PduR_GetFillLevelOfFmFifoRam(fmFifoRomIdx) > 0u)   /* COV_PDUR_FATAL_ERROR */
  {
    PduR_DecFillLevelOfFmFifoRam(fmFifoRomIdx); /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    PduR_SetFmFifoElementRamWriteIdxOfFmFifoRam(fmFifoRomIdx, fmFifoElementRamWriteIdx);        /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */

    if(!PduR_IsDedicatedTxBufferOfFmFifoElementRam(fmFifoElementRamWriteIdx))   /* COV_PDUR_FATAL_ERROR */
    {
      PduR_SetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx, PDUR_FM_IDLE_STATEOFFMFIFOELEMENTRAM);  /* SBSW_PDUR_CSL01 */
    }
    else
    {
      PduR_Det_ReportError(PDUR_FM_FREEFIFOELEMENT, PDUR_E_FATAL);
    }
  }
  else
  {
    PduR_Det_ReportError(PDUR_FM_FREEFIFOELEMENT, PDUR_E_FATAL);
  }
}
#endif

#if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FlushFifoElement_FmSmStateHandler_FM_WRITE_READ_ACTIVE_OR_FM_WRITE_FINISHED_READ_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FlushFifoElement_FmSmStateHandler_FM_WRITE_READ_ACTIVE_OR_FM_WRITE_FINISHED_READ_ACTIVE(PduR_FmFifoElementRamIterType fmFifoElementRamIdx)
{
  PduR_BmTxBufferRomIdxOfFmFifoElementRamType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamIdx);
  PduR_BmTxBufferInstanceRomStartIdxOfBmTxBufferRomType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(bmTxBufferRomIdx);
  PduR_Fm_ReleaseFifoElement(fmFifoElementRamIdx);
  if(PduR_IsDedicatedTxBufferOfFmFifoElementRam(fmFifoElementRamIdx))   /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
  {
    PduR_SetStateOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM);        /* SBSW_PDUR_CSL01 */
  }
  else
  {
    PduR_SetStateOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_FM_IDLE_STATEOFFMFIFOELEMENTRAM); /* SBSW_PDUR_CSL01 */
    PduR_Fm_DissolveFifoElementTxBufferRelation(fmFifoElementRamIdx);
  }
  PduR_Bm_ResetTxBuffer(bmTxBufferRomIdx);
  PduR_Bm_ResetTxBufferInstance(bmTxBufferInstanceRomIdx);
}
#endif

#if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FlushFifoElement_FmSmStateHandler_FM_WRITE_ACTIVE_OR_FM_WRITE_FINISHED_READ_PENDING_OR_FM_READ_FINISHED
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FlushFifoElement_FmSmStateHandler_FM_WRITE_ACTIVE_OR_FM_WRITE_FINISHED_READ_PENDING_OR_FM_READ_FINISHED(PduR_FmFifoElementRamIterType fmFifoElementRamIdx)
{
  PduR_BmTxBufferRomIdxOfFmFifoElementRamType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamIdx);
  PduR_Fm_ReleaseFifoElement(fmFifoElementRamIdx);
  if(PduR_IsDedicatedTxBufferOfFmFifoElementRam(fmFifoElementRamIdx))   /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
  {
    PduR_SetStateOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM);        /* SBSW_PDUR_CSL01 */
  }
  else
  {
    PduR_SetStateOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_FM_IDLE_STATEOFFMFIFOELEMENTRAM); /* SBSW_PDUR_CSL01 */
    PduR_Fm_DissolveFifoElementTxBufferRelation(fmFifoElementRamIdx);
  }
  PduR_Bm_ResetTxBuffer(bmTxBufferRomIdx);
}
#endif

#if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FlushFifoElement_FmSmStateHandler_NoAction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FlushFifoElement_FmSmStateHandler_NoAction(PduR_FmFifoElementRamIterType fmFifoElementRamIdx)     /* COV_PDUR_ONLY_TT_SINGLE_BUFFER */
{
  PDUR_DUMMY_STATEMENT(fmFifoElementRamIdx);    /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_ActivateNext
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_ActivateNext(PduR_FmFifoRamIterType fmFifoRamIdx)
{
  PduR_FmFifoElementRamIterType peekedfmFifoElementRamTPReadIdx;
  if(PduR_Fm_Peek(fmFifoRamIdx, &peekedfmFifoElementRamTPReadIdx) == E_OK)      /* SBSW_PDUR_STACK_VARIABLE */
  {
    PduR_GetFctPtrOfFm_ActivateNext_FmSmStateHandler(PduR_GetStateOfFmFifoElementRam(peekedfmFifoElementRamTPReadIdx)) (peekedfmFifoElementRamTPReadIdx, E_OK); /* SBSW_PDUR_CSL03 */
  }
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_ActivateNext_FmSmStateHandler_FM_WRITE_FINISHED_READ_PENDING
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_ActivateNext_FmSmStateHandler_FM_WRITE_FINISHED_READ_PENDING(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx, Std_ReturnType result)
{
  PduR_RmSrcRomIterType rmSrcIdx = PduR_GetRmSrcRomIdxOfRmDestRom(PduR_GetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamWriteIdx));
  PduR_FmFifoRamIterType fmFifoRamIdx = PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_GetFctPtrOfRmTp_FinishReception_TpTxSmStateHandler(PduR_GetTpTxSmStateOfFmFifoRam(fmFifoRamIdx)) (rmSrcIdx, result);     /* SBSW_PDUR_CSL03 */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_ActivateNext_FmSmStateHandler_FM_WRITE_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_ActivateNext_FmSmStateHandler_FM_WRITE_ACTIVE(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx, Std_ReturnType result)
{
  PduR_RmSrcRomIterType rmSrcIdx = PduR_GetRmSrcRomIdxOfRmDestRom(PduR_GetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamWriteIdx));
  PduR_FmFifoRamIterType fmFifoRamIdx = PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_GetFctPtrOfRmTp_CheckReady2Transmit_TpTxSmStateHandler(PduR_GetTpTxSmStateOfFmFifoRam(fmFifoRamIdx)) (rmSrcIdx); /* SBSW_PDUR_CSL03 */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
 /**********************************************************************************************************************
 * PduR_Fm_ActivateNext_FmSmStateHandler_FatalError
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_ActivateNext_FmSmStateHandler_FatalError(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx, Std_ReturnType result)   /* COV_PDUR_FATAL_ERROR */
{
  PduR_Det_ReportError(PDUR_FM_ACTIVATENEXT, PDUR_E_FATAL);
  PDUR_DUMMY_STATEMENT(fmFifoElementRamWriteIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_ActivateRead_FmSmStateHandler_FM_WRITE_FINISHED_READ_PENDING
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_ActivateRead_FmSmStateHandler_FM_WRITE_FINISHED_READ_PENDING(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx)
{
  PduR_SetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx, PDUR_FM_WRITE_FINISHED_READ_ACTIVE_STATEOFFMFIFOELEMENTRAM);        /* SBSW_PDUR_CSL03 */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_ActivateRead_FmSmStateHandler_FM_WRITE_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_ActivateRead_FmSmStateHandler_FM_WRITE_ACTIVE(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx)
{
  PduR_SetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx, PDUR_FM_WRITE_READ_ACTIVE_STATEOFFMFIFOELEMENTRAM); /* SBSW_PDUR_CSL03 */
}
#endif
#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_ActivateRead_FmSmStateHandler_NoAction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_ActivateRead_FmSmStateHandler_NoAction(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx)    /* COV_PDUR_TP_ONLY */
{
  PDUR_DUMMY_STATEMENT(fmFifoElementRamWriteIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_ActivateRead_FmSmStateHandler_FatalError
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_ActivateRead_FmSmStateHandler_FatalError(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx)  /* COV_PDUR_FATAL_ERROR */
{
  PduR_Det_ReportError(PDUR_FMACTIVATEREAD, PDUR_E_FATAL);
  PDUR_DUMMY_STATEMENT(fmFifoElementRamWriteIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FinishWrite_FmSmStateHandler_NoAction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FinishWrite_FmSmStateHandler_NoAction(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx, Std_ReturnType result)      /* COV_PDUR_TP_ONLY */
{
  PDUR_DUMMY_STATEMENT(fmFifoElementRamWriteIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FinishWrite_FmSmStateHandler_FM_READ_FINISHED
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FinishWrite_FmSmStateHandler_FM_READ_FINISHED(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx, Std_ReturnType result)
{
  /* Reset buffer */
  PduR_Bm_ResetTxBuffer(PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamWriteIdx));
  /* Reset Fifo element */
  PduR_Fm_ReleaseFifoElement(fmFifoElementRamWriteIdx);
  if(PduR_IsDedicatedTxBufferOfFmFifoElementRam(fmFifoElementRamWriteIdx))      /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
  {
    PduR_SetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx, PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM);   /* SBSW_PDUR_CSL03 */
  }
  else
  {
    PduR_SetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx, PDUR_FM_IDLE_STATEOFFMFIFOELEMENTRAM);    /* SBSW_PDUR_CSL03 */
    /* release buffer connection */
    PduR_Fm_DissolveFifoElementTxBufferRelation(fmFifoElementRamWriteIdx);
  }
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif
#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FinishWrite_FmSmStateHandler_FM_WRITE_READ_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FinishWrite_FmSmStateHandler_FM_WRITE_READ_ACTIVE(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx, Std_ReturnType result)
{
  PduR_SetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx, PDUR_FM_WRITE_FINISHED_READ_ACTIVE_STATEOFFMFIFOELEMENTRAM);        /* SBSW_PDUR_CSL03 */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif
#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FinishWrite_FmSmStateHandler_FM_WRITE_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FinishWrite_FmSmStateHandler_FM_WRITE_ACTIVE(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx, Std_ReturnType result)
{
  if(result == E_OK)
  {
    PduR_SetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx, PDUR_FM_WRITE_FINISHED_READ_PENDING_STATEOFFMFIFOELEMENTRAM);     /* SBSW_PDUR_CSL03 */
  }
  else
  {
    /* Reset Fifo element */
    PduR_Fm_ReleaseFifoElement(fmFifoElementRamWriteIdx);
    /* Reset buffer */
    PduR_Bm_ResetTxBuffer(PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamWriteIdx));
    if(PduR_IsDedicatedTxBufferOfFmFifoElementRam(fmFifoElementRamWriteIdx))    /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
    {
      PduR_SetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx, PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM); /* SBSW_PDUR_CSL03 */
    }
    else
    {
      /* Shared buffer */
      PduR_SetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx, PDUR_FM_IDLE_STATEOFFMFIFOELEMENTRAM);  /* SBSW_PDUR_CSL03 */
      PduR_Fm_DissolveFifoElementTxBufferRelation(fmFifoElementRamWriteIdx);
    }
  }
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FinishRead_FmSmStateHandler_FM_WRITE_FINISHED_READ_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FinishRead_FmSmStateHandler_FM_WRITE_FINISHED_READ_ACTIVE(PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx, Std_ReturnType result)
{
  /* Reset Fifo element */
  PduR_Fm_ReleaseFifoElement(fmFifoElementRamReadIdx);
  /* Reset buffer */
  PduR_Bm_ResetTxBuffer(PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamReadIdx));
  if(PduR_IsDedicatedTxBufferOfFmFifoElementRam(fmFifoElementRamReadIdx))       /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
  {
    PduR_SetStateOfFmFifoElementRam(fmFifoElementRamReadIdx, PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM);    /* SBSW_PDUR_CSL03 */
  }
  else
  {
    PduR_SetStateOfFmFifoElementRam(fmFifoElementRamReadIdx, PDUR_FM_IDLE_STATEOFFMFIFOELEMENTRAM);     /* SBSW_PDUR_CSL03 */
    PduR_Fm_DissolveFifoElementTxBufferRelation(fmFifoElementRamReadIdx);
  }
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FinishRead_FmSmStateHandler_FM_WRITE_READ_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FinishRead_FmSmStateHandler_FM_WRITE_READ_ACTIVE(PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx, Std_ReturnType result)
{
  PduR_SetStateOfFmFifoElementRam(fmFifoElementRamReadIdx, PDUR_FM_READ_FINISHED_STATEOFFMFIFOELEMENTRAM);      /* SBSW_PDUR_CSL03 */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FinishRead_FmSmStateHandler_FatalError
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FinishRead_FmSmStateHandler_FatalError(PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx, Std_ReturnType result)      /* COV_PDUR_FATAL_ERROR */
{
  PduR_Det_ReportError(PDUR_FMFINISHREAD, PDUR_E_FATAL);
  PDUR_DUMMY_STATEMENT(fmFifoElementRamReadIdx);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FinishRead_FmSmStateHandler_NoAction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FinishRead_FmSmStateHandler_NoAction(PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx, Std_ReturnType result)        /* COV_PDUR_TP_ONLY */
{
  PDUR_DUMMY_STATEMENT(fmFifoElementRamReadIdx);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_ActivateWrite_FmSmStateHandler_FM_ALLOCATED_WITH_BUFFER
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_ActivateWrite_FmSmStateHandler_FM_ALLOCATED_WITH_BUFFER(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx)
{
  PduR_SetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx, PDUR_FM_WRITE_ACTIVE_STATEOFFMFIFOELEMENTRAM);      /* SBSW_PDUR_CSL03 */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_ActivateWrite_FmSmStateHandler_FatalError
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_ActivateWrite_FmSmStateHandler_FatalError(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx) /* COV_PDUR_FATAL_ERROR */
{
  PduR_Det_ReportError(PDUR_FM_ACTIVATEWRITE, PDUR_E_FATAL);
  PDUR_DUMMY_STATEMENT(fmFifoElementRamWriteIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if ((PDUR_RPGROM == STD_ON) && (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_Fm_TpDisableRouting_FmSmStateHandler_NoAction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_TpDisableRouting_FmSmStateHandler_NoAction(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  PDUR_DUMMY_STATEMENT(rmGDestRomIdx);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if ((PDUR_RPGROM == STD_ON) && (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_Fm_TpDisableRouting_FmSmStateHandler_FM_WRITE_FINISHED_READ_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_TpDisableRouting_FmSmStateHandler_FM_WRITE_FINISHED_READ_ACTIVE(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx);
  PduR_RmTp_CancelTransmitPreparation(fmFifoElementRamReadIdx);
}
#endif

#if ((PDUR_RPGROM == STD_ON) && (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_Fm_TpDisableRouting_FmSmStateHandler_FM_WRITE_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_TpDisableRouting_FmSmStateHandler_FM_WRITE_ACTIVE(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx);
  PduR_RmSrcRomIterType rmSrcIdx = PduR_GetRmSrcRomIdxOfRmDestRom(PduR_GetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamReadIdx));
  PduR_TpRxSmStateOfRmBufferedTpPropertiesRamType tpRxSmState = PduR_GetTpRxSmStateOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_GetFctPtrOfRmTp_CancelReceive_TpRxSmStateHandler(tpRxSmState) (rmSrcIdx);        /* SBSW_PDUR_CSL03 */
}
#endif

#if ((PDUR_RPGROM == STD_ON) && (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_Fm_TpDisableRouting_FmSmStateHandler_FM_WRITE_READ_ACTIVE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_TpDisableRouting_FmSmStateHandler_FM_WRITE_READ_ACTIVE(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx);
  PduR_RmSrcRomIterType rmSrcIdx = PduR_GetRmSrcRomIdxOfRmDestRom(PduR_GetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamReadIdx));
  PduR_TpRxSmStateOfRmBufferedTpPropertiesRamType tpRxSmState = PduR_GetTpRxSmStateOfRmBufferedTpPropertiesRam(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(rmSrcIdx));
  PduR_GetFctPtrOfRmTp_CancelReceive_TpRxSmStateHandler(tpRxSmState) (rmSrcIdx);        /* SBSW_PDUR_CSL03 */
  PduR_RmTp_CancelTransmitPreparation(fmFifoElementRamReadIdx);
}
#endif

#if ((PDUR_HASIFTXFIFOOFGENERALPROPERTIESROM == STD_ON) || (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_Fm_Peek
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_Fm_Peek(PduR_FmFifoRamIterType fmFifoRamIdx, P2VAR(PduR_FmFifoElementRamIterType, AUTOMATIC, PDUR_APPL_DATA) fmFifoElementRamIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* Start search on last read idx */
  PduR_FmFifoElementRamReadIdxOfFmFifoRamType fmFifoElementRamTPReadIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRamIdx);
  /* FifoElements in the queue? */
  while(PduR_GetFillLevelOfFmFifoRam(fmFifoRamIdx) > 0u)
  {
    /* Get next element */
    if(fmFifoElementRamTPReadIdx >= ((PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(fmFifoRamIdx) - 1u)))
    {
      /* Wrap-around */
      fmFifoElementRamTPReadIdx = PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRamIdx);
    }
    else
    {
      fmFifoElementRamTPReadIdx++;
    }
    *fmFifoElementRamIdx = fmFifoElementRamTPReadIdx;   /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    /* FifoElement active? */
    if(PduR_Fm_IsFifoElementAllocated(fmFifoElementRamTPReadIdx) == E_OK)
    {
      retVal = E_OK;
      PduR_DecFillLevelOfFmFifoRam(fmFifoRamIdx);       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
      PduR_SetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRamIdx, fmFifoElementRamTPReadIdx);      /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
      break;
    }
    /* FifoElement is invalid -> Adapt fill level and update read pointer */
    else
    {
      PduR_DecFillLevelOfFmFifoRam(fmFifoRamIdx);       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
      PduR_SetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRamIdx, fmFifoElementRamTPReadIdx);      /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
      /* must be done because the Index in not set back to the begining. The Idx move through the buffer and the next element is initialized with pending */
    }
  }
  return retVal;
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_AssignFifoElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_Fm_AssignFifoElement(PduR_FmFifoRamIterType fmFifoRamIdx, P2VAR(PduR_FmFifoElementRamWriteIdxOfFmFifoRamType, AUTOMATIC, PDUR_APPL_DATA) fmFifoElementRamIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* Start search on last write idx */
  PduR_FmFifoElementRamWriteIdxOfFmFifoRamType fmFifoElementRamWriteIdx = PduR_GetFmFifoElementRamWriteIdxOfFmFifoRam(fmFifoRamIdx); /* PRQA S 2842 */ /* MD_PduR_2842 */

  /* Free FifoElement available? */
  if(PduR_Fm_AllocateFifoElement(fmFifoElementRamWriteIdx) == E_OK)     /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
  {
    /* Return the found free FiFoElement */
    *fmFifoElementRamIdx = fmFifoElementRamWriteIdx;    /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    /* Get next fifo element */ /* Check if the write Idx is at the end (EndIdx -1) */
    if(fmFifoElementRamWriteIdx >= (PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(fmFifoRamIdx) - 1u))      /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
    {
      /* Wrap-around */
      fmFifoElementRamWriteIdx = PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRamIdx);
    }
    else
    {
      fmFifoElementRamWriteIdx++;
    }
    /* Update global FifoElement write pointer. This pointer points to the next available Fifo element. */
    PduR_SetFmFifoElementRamWriteIdxOfFmFifoRam(fmFifoRamIdx, fmFifoElementRamWriteIdx);        /* PRQA S 2842 */ /* MD_PduR_2842 */ /* SBSW_PDUR_CSL03 */
    retVal = E_OK;
  }
  return retVal;
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_AssignFifoElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_Fm_AllocateFifoElement(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  if(PduR_Fm_IsFifoElementAllocated(fmFifoElementRamWriteIdx) != E_OK)
  {
    PduR_SetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx, PDUR_FM_ALLOCATED_STATEOFFMFIFOELEMENTRAM);       /* SBSW_PDUR_CSL03 */
    retVal = E_OK;
  }
  return retVal;
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_IsFifoElementAllocated
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
*********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_Fm_IsFifoElementAllocated(PduR_FmFifoElementRamIterType fmFifoElementRamIdx)
{
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* Is a TxBuffer assigned/allocated to the FifoElement? */
  if(PduR_IsDedicatedTxBufferOfFmFifoElementRam(fmFifoElementRamIdx))   /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
  {
    if((PduR_GetStateOfFmFifoElementRam(fmFifoElementRamIdx) == (PduR_BmTxBufferInstanceRomIterType) PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM))    /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
    {
      retVal = E_NOT_OK;
    }
  }
  else
  {
    if((PduR_GetStateOfFmFifoElementRam(fmFifoElementRamIdx) == (PduR_BmTxBufferInstanceRomIterType) PDUR_FM_IDLE_STATEOFFMFIFOELEMENTRAM))
    {
      retVal = E_NOT_OK;
    }
  }
  return retVal;
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_AssignTxBuffer2FifoElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
  *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_AssignTxBuffer2FifoElement(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx, PduR_BmTxBufferRomIdxOfFmFifoElementRamType bmTxBufferRomIdx)
{
  /* Initialize buffer and assign to FifoElement */
  PduR_SetStateOfFmFifoElementRam(fmFifoElementRamWriteIdx, PDUR_FM_ALLOCATED_WITH_BUFFER_STATEOFFMFIFOELEMENTRAM);     /* SBSW_PDUR_CSL01 */
  PduR_SetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamWriteIdx, bmTxBufferRomIdx);       /* SBSW_PDUR_CSL03 */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_DissolveFifoElementTxBufferRelation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
  *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Fm_DissolveFifoElementTxBufferRelation(PduR_FmFifoElementRamIterType fmFifoElementRamIdx)
{
  PduR_SetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_NO_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM);  /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_ReleaseFifoElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
  *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Fm_ReleaseFifoElement(PduR_FmFifoElementRamIterType fmFifoElementRamIdx)
{
  PduR_SetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_NO_RMDESTROMIDXOFFMFIFOELEMENTRAM);  /* SBSW_PDUR_CSL03 */
  PduR_SetStateOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_FM_IDLE_STATEOFFMFIFOELEMENTRAM);   /* SBSW_PDUR_CSL03 */
}
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: PduR_Fm.c
 *********************************************************************************************************************/
