/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 * 
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  BswM_PduR.h
 *        \brief  MICROSAR Basic Software Mode Manager
 *
 *      \details  Callback header for PduR.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#if !defined BSWM_PDUR_H
# define BSWM_PDUR_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT VERSIONS
 *********************************************************************************************************************/

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

# define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 

/**********************************************************************************************************************
 *  BswM_PduR_RxIndication()
 *********************************************************************************************************************/
/*! \brief      Function called by PduR to inform the BswM about a received PDU.
 * \details     Occurrence of event is stored and depending rules are arbitrated.
 * \param[in]   RxPduId     The PduR ID of received PDU.
 * \param[in]   PduInfoPtr  Pointer which stores all informations about the PDU. Not used by this implementation.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for RxPduId which does not belong to the same configured port.
 * \synchronous TRUE
 * \config      BSWM_ENABLE_PDUR
 */
extern FUNC(void, BSWM_CODE) BswM_PduR_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, BSWM_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
 *  BswM_PduR_TpRxIndication()
 *********************************************************************************************************************/
/*! \brief      Function called by PduR to inform the BswM about a received TP PDU.
 * \details     Occurrence of event is stored and depending rules are arbitrated.
 * \param[in]   id      The PduR ID of the received PDU.
 * \param[in]   result  Result of the reception. Not used by this implementation.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for id which does not belong to the same configured port.
 * \synchronous TRUE
 * \config      BSWM_ENABLE_PDUR
 */
extern FUNC(void, BSWM_CODE) BswM_PduR_TpRxIndication(PduIdType id, Std_ReturnType result);

/**********************************************************************************************************************
 *  BswM_PduR_TpStartOfReception()
 *********************************************************************************************************************/
/*! \brief      Function called by PduR to inform the BswM about the start of TP PDU Reception.
 * \details     Occurrence of event is stored and depending rules are arbitrated.
 * \param[in]   id             The PduR ID of the received PDU.
 * \param[in]   info           Pointer which stores all informations about the PDU. Not used by this implementation.
 * \param[in]   TpSduLength    Total length of the I-PDU to be received. Not used by this implementation.
 * \param[in]   bufferSizePtr  Pointer to the receive buffer. Not used by this implementation.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for id which does not belong to the same configured port.
 * \synchronous TRUE
 * \config      BSWM_ENABLE_PDUR
 */
extern FUNC(void, BSWM_CODE) BswM_PduR_TpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, BSWM_APPL_DATA) info,
                                                          PduLengthType TpSduLength,
                                                          P2VAR(PduLengthType, AUTOMATIC, BSWM_APPL_DATA) bufferSizePtr);

/**********************************************************************************************************************
 *  BswM_PduR_TpTxConfirmation()
 *********************************************************************************************************************/
/*! \brief      Function called by PduR to inform the BswM about a sent TP PDU.
 * \details     Occurrence of event is stored and depending rules are arbitrated.
 * \param[in]   id      The PduR ID of the sent TP PDU.
 * \param[in]   result  Result of the transmission. Not used by this implementation.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for id which does not belong to the same configured port.
 * \synchronous TRUE
 * \config      BSWM_ENABLE_PDUR
 */
extern FUNC(void, BSWM_CODE) BswM_PduR_TpTxConfirmation(PduIdType id, Std_ReturnType result);

/**********************************************************************************************************************
 *  BswM_PduR_Transmit()
 *********************************************************************************************************************/
/*! \brief      Function called by PduR to inform the BswM about a PDU Transmit Event.
 * \details     Occurrence of event is stored and depending rules are arbitrated.
 * \param[in]   id          The PduR ID of PDU to transmit.
 * \param[in]   PduInfoPtr  Pointer which stores all informations about the PDU.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for id which does not belong to the same configured port.
 * \synchronous TRUE
 * \config      BSWM_ENABLE_PDUR
 */
extern FUNC(void, BSWM_CODE) BswM_PduR_Transmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, BSWM_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
 *  BswM_PduR_TxConfirmation()
 *********************************************************************************************************************/
/*! \brief      Function called by PduR to inform the BswM about a sent PDU.
 * \details     Occurrence of event is stored and depending rules are arbitrated.
 * \param[in]   TxPduId     The PduR ID of the sent PDU.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for TxPduId which does not belong to the same configured port.
 * \synchronous TRUE
 * \config      BSWM_ENABLE_PDUR
 */
extern FUNC(void, BSWM_CODE) BswM_PduR_TxConfirmation(PduIdType TxPduId);

# define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 

#endif

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
