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
 *         File:  PduR_RmTp_TxInst.h
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
#if !defined (PDUR_RMTP_TXINST_H)
# define PDUR_RMTP_TXINST_H

/**********************************************************************************************************************
   LOCAL MISRA / PCLINT JUSTIFICATION
**********************************************************************************************************************/
/* *INDENT-OFF* */
/* PRQA  S 0777 EOF */ /* MD_MSR_Rule5.1_0777 */
/* *INDENT-ON* */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* \trace SPEC-2020230, SPEC-38402 */

# include "PduR_Types.h"
# include "PduR_Cfg.h"
# include "PduR_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define PDUR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TriggerTransmit
 *********************************************************************************************************************/
/*! \brief       The function is called to start the transmission and perform TxSm state handling
 *  \details     TxSm is in the state "Idle"
 *  \param[in]   rmDestRomIdx   Id of destination PDU reference.
 *  \param[in]   rmGDestRomIdx  Id of global PDU reference.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_TriggerTransmit(PduR_RmDestRomIterType rmDestRomIdx, PduR_RmGDestRomIterType rmGDestRomIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TriggerTransmit_RmTxinstIdle
 *********************************************************************************************************************/
/*! \brief       The function is called to start the transmission and perform TxSm state handling
 *  \details     TxSm is in the state "Idle"
 *  \param[in]   rmDestRomIdx   Id of destination PDU reference.
 *  \param[in]   rmGDestRomIdx  Id of global PDU reference.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_TriggerTransmit_RmTxinstIdle(PduR_RmDestRomIterType rmDestRomIdx, PduR_RmGDestRomIterType rmGDestRomIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TriggerTransmit_RmTxinstWaiting
 *********************************************************************************************************************/
/*! \brief       This function moves the tigger transmit call to the main task
 *  \details     TxSm is in the state "Idle"
 *  \param[in]   rmDestRomIdx   Id of destination PDU reference.
 *  \param[in]   rmGDestRomIdx  Id of global PDU reference.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_TriggerTransmit_RmTxinstWaiting(PduR_RmDestRomIterType rmDestRomIdx, PduR_RmGDestRomIterType rmGDestRomIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TriggerTransmit_FatalError
 *********************************************************************************************************************/
/*! \brief       If this function is called something went totally wrong
 *  \details     -
 *  \param[in]   rmDestRomIdx   Id of destination PDU reference.
 *  \param[in]   rmGDestRomIdx  Id of global PDU reference.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_TriggerTransmit_FatalError(PduR_RmDestRomIterType rmDestRomIdx, PduR_RmGDestRomIterType rmGDestRomIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CopyTxData
 *********************************************************************************************************************/
/*! \brief       This function is called by the PduR GwTp to query the transmit data of an I-PDU segment.
 *  \details     TxSm is in the state "Active"
 *  \param[in]   rmGDestRomIdx     Routing Manager GDest Idx.
 *  \param[in]   info              Data pointer and length.
 *                                 A copy size of 0 can be used to get the available data size.
 *  \param[in]   retry             not supported
 *  \param[out]  availableDataPtr  Indicates the remaining number of bytes that are available in the PduR Tx buffer.
 *                                 AvailableTxDataCntPtr can be used by TP modules that support dynamic payload lengths
 *                                 (e.g. Iso FrTp) to determine the size of the following CFs.
 *  \return      BufReq_ReturnType
 *               BUFREQ_OK         The data has been copied successfully.
 *               BUFREQ_E_NOT_OK   Get data fails.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 ***********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CopyTxData(PduR_RmGDestRomIterType rmGDestRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
                                                               P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CopyTxData_RmTxinstActive
 *********************************************************************************************************************/
/*! \brief       This function is called by the PduR GwTp to query the transmit data of an I-PDU segment.
 *  \details     TxSm is in the state "Active"
 *  \param[in]   rmGDestRomIdx     Routing Manager GDest Idx.
 *  \param[in]   pduLength         length to copy.
 *  \param[out]  sduDataPtr        data pointer.
 *                                 A copy size of 0 can be used to get the available data size.
 *  \param[in]   retry             not supported
 *  \param[out]  availableDataPtr  Indicates the remaining number of bytes that are available in the PduR Tx buffer.
 *                                 AvailableTxDataCntPtr can be used by TP modules that support dynamic payload lengths
 *                                 (e.g. Iso FrTp) to determine the size of the following CFs.
 *  \return      BufReq_ReturnType
 *               BUFREQ_OK         The data has been copied successfully.
 *               BUFREQ_E_NOT_OK   Get data fails.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 ***********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CopyTxData_RmTxinstActive(PduR_RmGDestRomIterType rmGDestRomIdx, PduLengthType pduLength,
                                                                              SduDataPtrType sduDataPtr,
                                                                              P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC,
                                                                                                                                             PDUR_APPL_DATA) availableDataPtr);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CopyTxData_UnexpectedCall
 *********************************************************************************************************************/
/*! \brief       This function is called by the PduR GwTp to query the transmit data of an I-PDU segment. But the
 *               routing is already aborted.
 *  \details     TxSm is in the state "Aborted"
 *  \param[in]   rmGDestRomIdx    Routing Manager GDest Idx.
 *  \param[in]   pduLength         length to copy.
 *  \param[out]  sduDataPtr        data pointer.
 *                                 A copy size of 0 can be used to get the available data size.
 *  \param[in]   retry             not supported
 *  \param[out]  availableDataPtr  Indicates the remaining number of bytes that are available in the PduR Tx buffer.
 *                                 AvailableTxDataCntPtr can be used by TP modules that support dynamic payload lengths
 *                                 (e.g. Iso FrTp) to determine the size of the following CFs.
 *  \return      BufReq_ReturnType
 *               BUFREQ_OK         The data has been copied successfully.
 *               BUFREQ_E_NOT_OK   Get data fails.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 ***********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CopyTxData_UnexpectedCall(PduR_RmGDestRomIterType rmGDestRomIdx, PduLengthType pduLength,
                                                                              SduDataPtrType sduDataPtr,
                                                                              P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC,
                                                                                                                                             PDUR_APPL_DATA) availableDataPtr);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CopyTxData_RmTxinstAborted
 *********************************************************************************************************************/
/*! \brief       This function is called by the PduR GwTp to query the transmit data of an I-PDU segment. But the
 *               routing is already aborted.
 *  \details     TxSm is in the state "Aborted"
 *  \param[in]   rmGDestRomIdx     Routing Manager GDest Idx.
 *  \param[in]   pduLength         length to copy.
 *  \param[out]  sduDataPtr        data pointer.
 *                                 A copy size of 0 can be used to get the available data size.
 *  \param[in]   retry             not supported
 *  \param[out]  availableDataPtr  Indicates the remaining number of bytes that are available in the PduR Tx buffer.
 *                                 AvailableTxDataCntPtr can be used by TP modules that support dynamic payload lengths
 *                                 (e.g. Iso FrTp) to determine the size of the following CFs.
 *  \return      BufReq_ReturnType
 *               BUFREQ_E_NOT_OK   Routing is aborted
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 ***********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CopyTxData_RmTxinstAborted(PduR_RmGDestRomIterType rmGDestRomIdx, PduLengthType pduLength,
                                                                               SduDataPtrType sduDataPtr,
                                                                               P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC,
                                                                                                                                              PDUR_APPL_DATA) availableDataPtr);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmTp_TxInst_TxConfirmation
**********************************************************************************************************************/
/*! \brief       The function confirms a successful transmission of a GwTp TX SDU or to report an error that
 *               occurred during transmission.
 *  \details     -
 *  \param[in]   rmGDestRomIdx                   Routing Manager GDest Idx.
 *  \param[out]  result                          Result of the TP transmission\n
 *               E_OK                            The TP transmission has been completed successfully.\n
 *               E_NOT_OK                        The PDU Router is in the PDUR_UNINIT state\n
 *                                               or the id is not valid\n
 *                                               or the id is not forwarded in this identity\n
 *                                               or the request was not accepted by the destination upper layer.\n
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TxInst_TxConfirmation(PduR_RmGDestRomIterType rmGDestRomIdx, Std_ReturnType result);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TxConfirmation_RmTxinstActiveOrRmTxinstAborted
 *********************************************************************************************************************/
/*! \brief       The function confirms a successful transmission of a GwTp TX SDU or to report an error that
 *               occurred during transmission.
 *  \details     TxSm is in the state Active Or Aborted. In case of 1:N result E_NOT_OK is acceptable, decrement Confirmation count.
 *  \param[in]   rmGDestRomIdx Routing Manager GDest Idx.
 *  \param[out]  result     result of the transmission.
 *               E_OK       The TP transmission has been completed successfully.\n
 *               E_NOT_OK   The transmission fails.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TxInst_TxConfirmation_RmTxinstActiveOrRmTxinstAborted(PduR_RmGDestRomIterType rmGDestRomIdx, Std_ReturnType result);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_TxConfirmation_UnexpectedCall
 *********************************************************************************************************************/
/*! \brief       The function is called unexpectedly because the TxSm is in state "Idle"
 *  \details     -
 *  \param[in]   rmGDestRomIdx Routing Manager GDest Idx.
 *  \param[out]  result     result of the transmission.
 *               E_OK       The TP transmission has been completed successfully.\n
 *               E_NOT_OK   The transmission fails.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TxInst_TxConfirmation_UnexpectedCall(PduR_RmGDestRomIterType rmGDestRomIdx, Std_ReturnType result);
# endif


# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CancelTransmit
 *********************************************************************************************************************/
/*! \brief       The function is called to cancel a transmission if a routing is disabled.
 *  \details     -
 *  \param[in]   rmGDestRomIdx Routing Manager GDest Idx.
 *  \return      cancel transmit successful or not.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CancelTransmit(PduR_RmDestRomIterType rmGDestRomIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CancelTransmit_RmTxinstWaiting
 *********************************************************************************************************************/
/*! \brief       The function is called to cancel a transmission if a routing is disabled.
 *  \details     -
 *  \param[in]   rmGDestRomIdx Routing Manager GDest Idx.
 *  \return      cancel transmit successful or not.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CancelTransmit_RmTxinstWaiting(PduR_RmDestRomIterType rmGDestRomIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CancelTransmit_RmTxinstActive
 *********************************************************************************************************************/
/*! \brief       The function is called to cancel a transmission if a routing is disabled.
 *  \details     -
 *  \param[in]   rmGDestRomIdx Routing Manager GDest Idx.
 *  \return      cancel transmit successful or not.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CancelTransmit_RmTxinstActive(PduR_RmDestRomIterType rmGDestRomIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CancelTransmit_RmTxinstAborted
 *********************************************************************************************************************/
/*! \brief       The function is called to cancel a transmission but the routing is already aborted
 *  \details     -
 *  \param[in]   rmGDestRomIdx Routing Manager GDest Idx.
 *  \return      cancel transmit successful or not.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CancelTransmit_RmTxinstAborted(PduR_RmDestRomIterType rmGDestRomIdx);
# endif

# if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_CancelTransmit_FatalError
 *********************************************************************************************************************/
/*! \brief       If this function is called something went totally wrong
 *  \details     Tx State machine in state "FatalError"
 *  \param[in]   rmGDestRomIdx Routing Manager GDest Idx.
 *  \return      FatalError -> E_NOT_OK unexpected call.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmTp_TxInst_CancelTransmit_FatalError(PduR_RmDestRomIterType rmGDestRomIdx);
# endif

# if((PDUR_MAIN_FUNCTION == STD_ON) && (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmTp_TxInst_MainFunction
 *********************************************************************************************************************/
/*!
 * \brief        Process deferred Tp Pdus in context of cyclic MainFunction
 * \details      -
 * \param[in]    rmGDestRomIdx            internal RmGDestRom index
 * \pre          -
 * \context      TASK
 * \reentrant    TRUE
 * \synchronous  TRUE
**********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmTp_TxInst_MainFunction(PduR_RmGDestRomIterType rmGDestRomIdx);
# endif

# define PDUR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
#endif /* PDUR_RMTP_TXINST_H */
/**********************************************************************************************************************
 *  END OF FILE: PduR_RmTp_TxInst.h
 *********************************************************************************************************************/
