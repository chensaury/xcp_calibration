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
/**        \file  BswM_LinSM.h
 *        \brief  MICROSAR Basic Software Mode Manager
 *
 *      \details  Callback header for LinSM.
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
#if !defined BSWM_LINSM_H
# define BSWM_LINSM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "LinSM.h"
# include "Lin_GeneralTypes.h"
# include "LinIf_Types.h"

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
 *  BswM_LinSM_CurrentState()
 *********************************************************************************************************************/
/*! \brief      Function called by LinSM to indicate its current state.
 * \details     Passed network state is stored and depending rules are arbitrated.
 * \param[in]   Network       The LIN channel that the indicated state corresponds to.
 * \param[in]   CurrentState  The current state of the LIN channel.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different networks
 * \synchronous TRUE
 * \config      BSWM_ENABLE_LINSM
 * \trace       SPEC-7937, SPEC-7943, SPEC-7911, SPEC-7883
 */
extern FUNC(void, BSWM_CODE) BswM_LinSM_CurrentState(NetworkHandleType Network, LinSM_ModeType CurrentState);

/**********************************************************************************************************************
 *  BswM_LinSM_CurrentSchedule()
 *********************************************************************************************************************/
/*! \brief      Function called by LinSM to indicate its current schedule.
 * \details     Passed schedule is stored and depending rules are arbitrated.
 * \param[in]   Network           The LIN channel that the indicated schedule corresponds to.
 * \param[in]   CurrentSchedule   The current schedule of the LIN channel.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different networks
 * \synchronous TRUE
 * \config      BSWM_ENABLE_LINSM
 * \trace       SPEC-7764, SPEC-7856, SPEC-7753
 */
extern FUNC(void, BSWM_CODE) BswM_LinSM_CurrentSchedule(NetworkHandleType Network, LinIf_SchHandleType CurrentSchedule);



/**********************************************************************************************************************
 *  BswM_LinSM_ScheduleEndNotification()
 *********************************************************************************************************************/
/*! \brief      Function called by LinSM to notify the end of a schedule.
 * \details     Passed schedule is stored and depending rules are arbitrated.
 * \param[in]   Network       The LIN channel that the indicated schedule corresponds to.
 * \param[in]   Schedule      The ended schedule of the LIN channel.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different networks
 * \synchronous TRUE
 * \config      BSWM_ENABLE_LINSM
 */
extern FUNC(void, BSWM_CODE) BswM_LinSM_ScheduleEndNotification(NetworkHandleType Network, LinIf_SchHandleType Schedule);

# define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 

#endif

/**********************************************************************************************************************
 *  END OF FILE: BswM_LinSM.h
 *********************************************************************************************************************/
