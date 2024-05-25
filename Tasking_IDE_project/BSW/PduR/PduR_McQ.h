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
 *         File:  PduR_McQ.h
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
#if !defined (PDUR_MCQ_H)
# define PDUR_MCQ_H

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
# define PDUR_MCQ_UNUSED_HEADER         0x00u
# define PDUR_MCQ_DATA_HEADER           0x01u
# define PDUR_MCQ_TXCONFIRMATION_HEADER 0x02u
# define PDUR_MCQ_SIZE_OF_HEADER        0x01u

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

# if(PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
  PduR_McQ_Init
**********************************************************************************************************************/
/*! \brief       This function initializes the multicore queue administration values.
 *  \details     -
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 ********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_McQ_Init(void);
# endif

# if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_WriteData
 *********************************************************************************************************************/
/*! \brief       Write Id and data into the multicore queue.
 *  \details     -
 *  \param[in]   mcQBufferRomIdx          Id of the queue to be used
 *  \param[in]   rmDestRomIdx             Index to the destination Pdu to be queued
 *  \param[in]   data                     pointer to the data
 *  \return      E_OK                     Copy action was successful.
 *               E_NOT_OK                 Copy action was not successful.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_McQ_WriteData(PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx, PduR_RmDestRomEndIdxOfRmSrcRomType rmDestRomIdx,
                                                   CONSTP2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) data);
# endif

# if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_WriteTxConfirmation
 *********************************************************************************************************************/
/*! \brief       Write TxConfirmation Id into the multicore queue.
 *  \details     -
 *  \param[in]   mcQBufferRomIdx   Id of the queue to be used
 *  \param[in]   rmSrcRomIdx       Src Idx where the TxConfirmation shall be called
 *  \return      E_OK              Copy action was successful.
 *               E_NOT_OK          Copy action was not successful.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_McQ_WriteTxConfirmation(PduR_McQBufferRomIdxOfSrcCoreRomType mcQBufferRomIdx, PduR_RmSrcRomIdxOfRmDestRomType rmSrcRomIdx);
# endif

# if (PDUR_MCQBUFFERROM == STD_ON)
/**********************************************************************************************************************
 * PduR_McQ_MainFunction
 *********************************************************************************************************************/
/*!
 * \brief        Process deferred If Pdus which are handled by the multicore queue in context of cyclic MainFunction
 * \details      -
 * \param[in]    coreManagerRomIdx   internal coreManagerRom index
 * \pre          -
 * \context      TASK
 * \reentrant    TRUE
 * \synchronous  TRUE
**********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_McQ_MainFunction(PduR_CoreManagerRomIdxOfMmRomType coreManagerRomIdx);
# endif

# define PDUR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
#endif /* PDUR_MCQ_H */
/**********************************************************************************************************************
 *  END OF FILE: PduR_McQ.h
 *********************************************************************************************************************/
