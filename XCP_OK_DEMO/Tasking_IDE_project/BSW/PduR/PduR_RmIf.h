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
 *         File:  PduR_RmIf.h
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
#if !defined (PDUR_RMIF_H)
# define PDUR_RMIF_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
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
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

# if (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_Init_TTSingleBuffer
 *********************************************************************************************************************/
/*! \brief       This function initializes the single buffer with default values
 *  \details     -
 *  \pre         PduR_InitMemory() has been executed, if the start up code does not initialize variables.
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The function must be called on task level and has not to be interrupted
 *               by other administrative function calls.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_Init_TTSingleBuffer(void);
# endif

# if (PDUR_DEDICATEDTXBUFFEROFRMBUFFEREDIFPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_Init_DedicatedTxBuffer
 *********************************************************************************************************************/
/*! \brief       This function assign dedicated buffer to routing pathways
 *  \details     -
 *  \pre         PduR_InitMemory() has been executed, if the start up code does not initialize variables.
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The function must be called on task level and has not to be interrupted
 *               by other administrative function calls.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_Init_DedicatedTxBuffer(void);
# endif

# if (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_RmIf_Init_FiFoRoutingState
**********************************************************************************************************************/
/*! \brief       Initialize FiFo Routing State for communication interface routing.
 *  \details     -
 *  \pre         PduR_InitMemory() has been executed, if the startup code does not initialise variables.
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_Init_FiFoRoutingState(void);
# endif

# if((PDUR_EXISTS_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
  PduR_RmIf_RxIndication_MultiIf
**********************************************************************************************************************/
/*! \brief       The function is called by the GwIf to indicate the complete reception of a 1:n GwIf I-PDU.
 *  \details     The PDU Router evaluates the multi destination I-PDU handle and performs appropriate handle and
 *               port conversion.
 *               The call is routed to upper IF modules using the appropriate I-PDU handle of the destination layers.
 *  \param[in]   rmSrcIdx          ID of the received GwIf I-PDU
 *  \param[in]   info              Payload information of the received I-PDU (pointer to data and data length).
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
**********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_RxIndication_MultiIf(PduR_RmSrcRomIterType rmSrcIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif

# if(PDUR_HASIFTXFIFOOFGENERALPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmIf_TxConfirmation_StateHandler_WAIT_FOR_TXCONFIRMATION
**********************************************************************************************************************/
/*! \brief       This function is executed if the TxConfirmation is called and the Pdu is in state WAIT_FOR_TXCONFIRMATION
 *  \details     -
 *  \param[in]   rmGDestRomIdx           Index for the RmGDestRom table
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_TxConfirmation_StateHandler_WAIT_FOR_TXCONFIRMATION(PduR_RmGDestRomIterType rmGDestRomIdx);
# endif

# if(PDUR_HASIFTXFIFOOFGENERALPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
  PduR_RmIf_TxConfirmation_StateHandler_UnexpectedCall
**********************************************************************************************************************/
/*! \brief       This function is executed if the TxConfirmation is called and the Pdu is NOT in state WAIT_FOR_TXCONFIRMATION
 *  \details     -
 *  \param[in]   rmGDestRomIdx           Index for the RmGDestRom table
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_TxConfirmation_StateHandler_UnexpectedCall(PduR_RmGDestRomIterType rmGDestRomIdx);
# endif

# if ((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
  PduR_RmIf_FifoHandling_StateHandler_WAIT_FOR_RXINDICATION
**********************************************************************************************************************/
/*! \brief       This function is executed if the RxIndication is called and the Pdu is in state WAIT_FOR_TXCONFIRMATION
 *  \details     -
 *  \param[in]   rmDest            Index for the RmDestRom table
 *  \param[in]   rmGDest           Index for the RmGDestRom table
 *  \param[in]   info              Pointer to the data
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_FifoHandling_StateHandler_WAIT_FOR_RXINDICATION(PduR_RmDestRomIterType rmDest, PduR_RmGDestRomIdxOfRmDestRomType rmGDest,
                                                                                P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif

# if ((PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
  PduR_RmIf_FifoHandling_StateHandler_QueueNotEmpty
**********************************************************************************************************************/
/*! \brief       This function is executed if the RxIndication is called and the Pdu is NOT in state WAIT_FOR_TXCONFIRMATION
 *  \details     -
 *  \param[in]   rmDest            Index for the RmDestRom table
 *  \param[in]   rmGDest           Index for the RmGDestRom table
 *  \param[in]   info              Pointer to the data
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_FifoHandling_StateHandler_QueueNotEmpty(PduR_RmDestRomIterType rmDest, PduR_RmGDestRomIdxOfRmDestRomType rmGDest, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif

# if((PDUR_MAIN_FUNCTION == STD_ON) && (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_MainFunction
 *********************************************************************************************************************/
/*!
 * \brief        Process deferred If Pdus in context of cyclic MainFunction
 * \details      -
 * \param[in]    rmGDestRomIdx            internal RmGDestRom index
 * \pre         -
 * \context      TASK
 * \reentrant    TRUE
 * \synchronous  TRUE
**********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_MainFunction(PduR_RmGDestRomIterType rmGDestRomIdx);
# endif

# if((PDUR_EXISTS_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON) || (PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
  PduR_RmIf_DispatchIfDestPdu
**********************************************************************************************************************/
/*! \brief       This funtion forwards the received Pdu to the corresponding destination function.
 *  \details     -
 *  \param[in]   rmDestRomIdx      RmDestRom Handle
 *  \param[in]   info              Payload information of the received I-PDU (pointer to data and data length).
 *  \return      Std_ReturnType    E_OK:     The SDU has been routed successfully.
 *                                 E_NOT_OK: The SDU has not been routed successfully.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
**********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_DispatchIfDestPdu(PduR_RmDestRomEndIdxOfRmSrcRomType rmDestRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif

# if ((PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON) && (PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_RmIf_MultipleSourceHandler_CancelTransmit
 *********************************************************************************************************************/
/*! \brief        The function is called by the PduR to cancel the transmission on the destination buses in case of a
 *                FanIn Transport Protocol Routing.
 *  \details      The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *                The call is routed to multiple TP module using the appropriate I-PDU handle of the destination layer.
 *  \param[in]    rmDestRomIdx           ID of the destination Pdu
 *  \return       Std_ReturnType            cancelation successful.
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 **********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_MultipleSourceHandler_CancelTransmit(PduR_RmDestRomIterType rmDestRomIdx);
# endif

# if ((PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
 /**********************************************************************************************************************
  PduR_RmIf_MultipleSourceHandler_TriggerTransmit
**********************************************************************************************************************/
/*! \brief       The function is called by the PduR to request the PduR TX I-PDU data before transmission in case of
 *               a FanIn routing.
 *  \details     The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *               The call is routed to an upper IF module or to the gateway using the appropriate I-PDU handle.
 *  \param[in]   rmGDestRomIdx        ID of the transmitted GwIf I-PDU
 *  \param[in]  info                        Payload information of the received I-PDU (pointer to data and data length).
 *  \return      Std_ReturnType    E_OK:     The SDU has been copied and the SduLength indicates
 *                                           the number of copied bytes.
 *                                 E_NOT_OK: The SDU has not been copied and the SduLength has not been set.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
***********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_RmIf_MultipleSourceHandler_TriggerTransmit(PduR_RmGDestRomIdxOfTxIf2UpType rmGDestRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif

# if (PDUR_TXCONFIRMATIONUSEDOFTXIF2UP == STD_ON)
/**********************************************************************************************************************
  PduR_RmIf_MultipleSourceHandler_TxConfirmation
**********************************************************************************************************************/
/*! \brief        The function is called by the PduR to indicate the complete transmission of a communication interface I-PDU.
 *  \details      The PDU Router evaluates the Gw I-PDU handle and performs appropriate handle and port conversion.
 *                The call is routed to an upper IF module or to the gateway depending on the pending Confirmation.
 *   \param[in]   rmGDestRomIdx           ID of the transmitted GwIf I-PDU
 *   \pre         -
 *   \context     TASK|ISR1|ISR2
 *   \reentrant   TRUE
 *   \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_RmIf_MultipleSourceHandler_TxConfirmation(PduR_RmGDestRomIdxOfTxIf2UpType rmGDestRomIdx);
# endif

# define PDUR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
#endif /* PDUR_RMIF_H */
/**********************************************************************************************************************
 *  END OF FILE: PduR_RmIf.h
 *********************************************************************************************************************/
