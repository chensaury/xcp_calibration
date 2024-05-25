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
/**        \file  BswM_Sd.h
 *        \brief  MICROSAR Basic Software Mode Manager
 *
 *      \details  Callback header for Sd.
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
#if !defined BSWM_SD_H
# define BSWM_SD_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Sd.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT VERSIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define BSWM_SD_CLIENT_SERVICE_RELEASED       SD_CLIENT_SERVICE_RELEASED
# define BSWM_SD_CLIENT_SERVICE_REQUESTED      SD_CLIENT_SERVICE_REQUESTED

# define BSWM_SD_CONSUMED_EVENTGROUP_RELEASED  SD_CONSUMED_EVENTGROUP_RELEASED
# define BSWM_SD_CONSUMED_EVENTGROUP_REQUESTED SD_CONSUMED_EVENTGROUP_REQUESTED

# define BSWM_SD_SERVER_SERVICE_AVAILABLE      SD_SERVER_SERVICE_AVAILABLE
# define BSWM_SD_SERVER_SERVICE_DOWN           SD_SERVER_SERVICE_DOWN

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
 *  BswM_Sd_ClientServiceCurrentState()
 *********************************************************************************************************************/
/*! \brief      Function called by Service Discovery to indicate current state of the client service.
 * \details     Passed state is stored and depending rules are arbitrated.
 * \param[in]   SdClientServiceHandleId  HandleId to identify the client service.
 * \param[in]   CurrentClientState       Current state of the client service (available/down).
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different handles
 * \synchronous TRUE
 * \config      BSWM_ENABLE_SD
 */
extern FUNC(void, BSWM_CODE) BswM_Sd_ClientServiceCurrentState(uint16 SdClientServiceHandleId, Sd_ClientServiceCurrentStateType CurrentClientState); 

/**********************************************************************************************************************
 *  BswM_Sd_ConsumedEventGroupCurrentState()
 *********************************************************************************************************************/
/*! \brief      Function called by Service Discovery to indicate current status of the consumed event group.
 * \details     Passed state is stored and depending rules are arbitrated.
 * \param[in]   SdConsumedEventGroupHandleId  HandleId to identify the consumed event group.
 * \param[in]   ConsumedEventGroupState       State of the consumed event group (available/down).
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different handles
 * \synchronous TRUE
 * \config      BSWM_ENABLE_SD
 */
extern FUNC(void, BSWM_CODE) BswM_Sd_ConsumedEventGroupCurrentState(uint16 SdConsumedEventGroupHandleId, Sd_ConsumedEventGroupCurrentStateType ConsumedEventGroupState); 

/**********************************************************************************************************************
 *  BswM_Sd_EventHandlerCurrentState()
 *********************************************************************************************************************/
/*! \brief      Function called by Service Discovery to indicate current status of the event handler.
 * \details     Passed state is stored and depending rules are arbitrated.
 * \param[in]   SdEventHandlerHandleId    HandleId to identify the event handler.
 * \param[in]   EventHandlerStatus        Status of the event handler (requested/released).
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different handles
 * \synchronous TRUE
 * \config      BSWM_ENABLE_SD
 */
extern FUNC(void, BSWM_CODE) BswM_Sd_EventHandlerCurrentState(uint16 SdEventHandlerHandleId, Sd_EventHandlerCurrentStateType EventHandlerStatus); 

# define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 

#endif /* BSWM_SD_H */

/**********************************************************************************************************************
 *  END OF FILE: BswM_Sd.h
 *********************************************************************************************************************/
