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
/**        \file  BswM_EcuM.h
 *        \brief  MICROSAR Basic Software Mode Manager
 *
 *      \details  Callback header for EcuM.
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
#if !defined BSWM_ECUM_H
# define BSWM_ECUM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "EcuM.h"

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
 *  BswM_EcuM_CurrentState()
 *********************************************************************************************************************/
/*! \brief      Function called by EcuM to indicate the current ECU Operation Mode.
 * \details     Passed state is stored and depending rules are arbitrated.
 * \param[in]   CurrentState    The requested ECU Operation Mode.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      BSWM_ENABLE_ECUM
 * \trace       SPEC-7876, SPEC-7791, SPEC-7739
 */
extern FUNC(void, BSWM_CODE) BswM_EcuM_CurrentState(EcuM_StateType CurrentState);

/**********************************************************************************************************************
 *  BswM_EcuM_CurrentWakeup()
 *********************************************************************************************************************/
/*! \brief      Function called by EcuM to indicate the current state of a wakeup source.
 * \details     Passed state is stored and depending rules are arbitrated.
 * \param[in]   source  The wakeup source(s) that changed state.
 * \param[in]   state   The new state of the wakeup source(s).
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different sources
 * \synchronous TRUE
 * \config      BSWM_ENABLE_ECUM
 * \trace       SPEC-7744, SPEC-7850, SPEC-7921
 */
extern FUNC(void, BSWM_CODE) BswM_EcuM_CurrentWakeup(EcuM_WakeupSourceType source, EcuM_WakeupStateType state);

/**********************************************************************************************************************
 *  BswM_EcuM_RequestedState()
 *********************************************************************************************************************/
/*! \brief      Function called by EcuM to indicate the request of a run request protocol state.
 * \details     Passed state is stored and depending rules are arbitrated.
 * \param[in]   State           The requested state by EcuMFlex.
 * \param[in]   CurrentStatus   The new result of the Run Request Protocol.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different states
 * \synchronous TRUE
 * \config      BSWM_ENABLE_ECUM
 */
extern FUNC(void, BSWM_CODE) BswM_EcuM_RequestedState(EcuM_StateType State, EcuM_RunStatusType CurrentStatus);

# define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 

#endif  /* BSWM_ECUM_H */

/**********************************************************************************************************************
 *  END OF FILE: BswM_EcuM.h
 *********************************************************************************************************************/
