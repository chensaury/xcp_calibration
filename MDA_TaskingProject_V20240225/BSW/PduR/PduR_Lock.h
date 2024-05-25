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
 *         File:  PduR_Lock.h
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
#if !defined (PDUR_LOCK_H)
# define PDUR_LOCK_H

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

# if (PDUR_SPINLOCKRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Lock_Init
 *********************************************************************************************************************/
/*! \brief       PduR Lock Ram Variable initialization function.
 *  \details     -
 *  \pre         PduR_InitMemory() has been executed, if the start up code does not initialize variables.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The function must be called on task level and has not to be interrupted by other administrative function calls.
 *  \warning     PduR_Lock_Init shall not pre-empt any PDUR function.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_Init(void);
# endif

/**********************************************************************************************************************
* PduR_Lock_LockRoutingPathBySrcPdu
*********************************************************************************************************************/
/*! \brief       PduR Lock function.
 *  \details     -
 *  \param[in]   rmSrcIdx  instance Idx.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_LockRoutingPathBySrcPdu(PduR_RmSrcRomIterType rmSrcIdx);

/**********************************************************************************************************************
* PduR_Lock_UnlockRoutingPathBySrcPdu
*********************************************************************************************************************/
/*! \brief       PduR unlock function.
 *  \details     -
 *  \param[in]   rmSrcIdx  instance Idx.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_UnlockRoutingPathBySrcPdu(PduR_RmSrcRomIterType rmSrcIdx);

/**********************************************************************************************************************
* PduR_Lock_LockRoutingPathByDestPdu
*********************************************************************************************************************/
/*! \brief       PduR Lock function.
 *  \details     -
 *  \param[in]   rmDestIdx  instance Idx.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_LockRoutingPathByDestPdu(PduR_RmDestRomIterType rmDestIdx);

/**********************************************************************************************************************
* PduR_Lock_UnlockRoutingPathByDestPdu
*********************************************************************************************************************/
/*! \brief       PduR unlock function.
 *  \details     -
 *  \param[in]   rmDestIdx  instance Idx.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_UnlockRoutingPathByDestPdu(PduR_RmDestRomIterType rmDestIdx);

/**********************************************************************************************************************
* PduR_Lock_LockRoutingPathByGDestPdu
*********************************************************************************************************************/
/*! \brief       PduR Lock function.
 *  \details     -
 *  \param[in]   rmGDestIdx  instance Idx.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_LockRoutingPathByGDestPdu(PduR_RmGDestRomIterType rmGDestIdx);

/**********************************************************************************************************************
* PduR_Lock_UnlockRoutingPathByGDestPdu
*********************************************************************************************************************/
/*! \brief       PduR unlock function.
 *  \details     -
 *  \param[in]   rmGDestIdx  instance Idx.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_UnlockRoutingPathByGDestPdu(PduR_RmGDestRomIterType rmGDestIdx);

# if (PDUR_SPINLOCKRAM == STD_ON)
/**********************************************************************************************************************
* PduR_Lock_LockBuffersByTxBufferInd
*********************************************************************************************************************/
/*! \brief       PduR Lock function.
 *  \details     -
 *  \param[in]   txBufferIndIdx  instance Idx.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_LockBuffersByTxBufferInd(PduR_BmTxBufferIndRomIterType txBufferIndIdx);
# endif

# if (PDUR_SPINLOCKRAM == STD_ON)
/**********************************************************************************************************************
* PduR_Lock_UnlockBuffersByTxBufferInd
*********************************************************************************************************************/
/*! \brief       PduR Lock function.
 *  \details     -
 *  \param[in]   txBufferIndIdx  instance Idx.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_UnlockBuffersByTxBufferInd(PduR_BmTxBufferIndRomIterType txBufferIndIdx);
# endif

# define PDUR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
#endif /* PDUR_LOCK_H */
/**********************************************************************************************************************
 *  END OF FILE: PduR_Lock.h
 *********************************************************************************************************************/
