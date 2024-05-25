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
/**        \file  BswM_ComM.h
 *        \brief  MICROSAR Basic Software Mode Manager
 *
 *      \details  Callback header for ComM.
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
#if !defined BSWM_COMM_H
# define BSWM_COMM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "ComM.h"
# include "ComM_Types.h"
# include "ComM_EcuMBswM.h"

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
 *  BswM_ComM_CurrentMode()
 *********************************************************************************************************************/
/*! \brief      Function called by ComM to indicate the current communication mode of a ComM channel.
 * \details     Passed RequestedMode is stored and depending rules are arbitrated.
 * \param[in]   Network       The ComM communication channel that the indicated state corresponds to.
 * \param[in]   RequestedMode The current state of the ComM communication channel.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different networks
 * \synchronous TRUE
 * \config      BSWM_ENABLE_COMM
 * \trace       SPEC-7782, SPEC-7924, SPEC-7863, SPEC-7903
 */
extern FUNC(void, BSWM_CODE) BswM_ComM_CurrentMode(NetworkHandleType Network, ComM_ModeType RequestedMode);

/**********************************************************************************************************************
 *  BswM_ComM_InitiateReset()
 *********************************************************************************************************************/
/*! \brief      Function called by ComM to request a ECU reset.
 * \details     Reset Request is stored and depending rules are arbitrated.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      BSWM_ENABLE_COMM
 * \trace       SPEC-7804
 */
extern FUNC(void, BSWM_CODE) BswM_ComM_InitiateReset(void);

/**********************************************************************************************************************
 *  BswM_ComM_CurrentPNCMode()
 *********************************************************************************************************************/
/*! \brief      Function called by ComM to indicate the current mode of the PNC.
 * \details     Passed RequestedMode is stored and depending rules are arbitrated.
 * \param[in]   PNC            The handle of the PNC for which the current state is reported.
 * \param[in]   RequestedMode  The current mode of the PNC.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different PNCs
 * \synchronous TRUE
 * \config      BSWM_ENABLE_COMM && BSWM_COMM_PNC_SUPPORT
 * \trace       SPEC-16742, SPEC-16710, SPEC-16754
 */
extern FUNC(void, BSWM_CODE) BswM_ComM_CurrentPNCMode(PNCHandleType PNC, ComM_PncModeType RequestedMode);
 

# define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 

#endif

/**********************************************************************************************************************
 *  END OF FILE: BswM_ComM.h
 *********************************************************************************************************************/
