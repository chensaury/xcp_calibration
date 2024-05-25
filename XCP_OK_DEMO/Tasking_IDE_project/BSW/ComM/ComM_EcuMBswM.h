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
/**         \file  ComM_EcuMBswM.h
 *         \brief  Communication Manager ASR4
 *
 *       \details  Callback API of the communication manager for the EcuM and BswM
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

#ifndef COMM_ECUMBSWM_H
# define COMM_ECUMBSWM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComM_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define COMM_ECUMBSWM_MAJOR_VERSION    (9u)
# define COMM_ECUMBSWM_MINOR_VERSION    (0u)
# define COMM_ECUMBSWM_PATCH_VERSION    (1u)

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
 *  CALLBACK FUNCTIONS PROTOTYPES (called by EcuM)
 *********************************************************************************************************************/

# define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

/**********************************************************************************************************************
 * ComM_CommunicationAllowed()
 *********************************************************************************************************************/
/*! \brief       This functions indicates the ComM if communication is allowed. The flag is only evaluated during the
 *               startup of a communication channel out of COMM_NO_COMMUNICATION.
 *  \details     -
 *  \param[in]   Channel                Valid channel identifier (network handle)
 *  \param[in]   Allowed                TRUE communication is allowed on the channel.
 *                                      FALSE (default) communication is not allowed and the communication channel
 *                                      is not started until the ComM gets the indication with TRUE.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-102676
 *  \trace       SPEC-5470, SPEC-5481
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_CommunicationAllowed(NetworkHandleType Channel, boolean Allowed);

/**********************************************************************************************************************
 * ComM_EcuM_WakeUpIndication()
 *********************************************************************************************************************/
/*! \brief       Indication of a passive wake-up by the EcuM.
 *  \details     -
 *  \param[in]   Channel                Valid channel identifier (network handle)
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \trace       CREQ-109578
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_EcuM_WakeUpIndication(NetworkHandleType Channel);

# if ((COMM_WAKEUPENABLEDOFPNC == STD_ON) && (COMM_PNC_PS_TIMER > 0U))
/**********************************************************************************************************************
 * ComM_EcuM_PNCWakeUpIndication()
 *********************************************************************************************************************/
/*! \brief       Indication of a wake-up on the corresponding Partial Network Cluster.
 *  \details     -
 *  \param[in]   PNCid                  Valid PNC identifier
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \trace       CREQ-116499
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_EcuM_PNCWakeUpIndication( PNCHandleType PNCid );
# endif

# define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

#endif  /* COMM_ECUM_H */

/**********************************************************************************************************************
  END OF FILE: ComM_EcuM.h
**********************************************************************************************************************/
