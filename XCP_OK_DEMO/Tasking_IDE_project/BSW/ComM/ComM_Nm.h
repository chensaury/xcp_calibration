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
/**         \file  ComM_Nm.h
 *         \brief  Communication Manager ASR4
 *
 *       \details  Callback API of the communication manager for the Network Management
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

#ifndef COMM_NM_H
# define COMM_NM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComM_Cfg.h"

# if (COMM_PNC_SUPPORT == STD_ON)
#  if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
#   include "NmStack_Types.h"
#  endif
# endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define COMM_NM_MAJOR_VERSION    (9u)
# define COMM_NM_MINOR_VERSION    (0u)
# define COMM_NM_PATCH_VERSION    (1u)

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
 *  CALLBACK FUNCTIONS PROTOTYPES (called by Nm)
 *********************************************************************************************************************/

# define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

/**********************************************************************************************************************
 *  ComM_Nm_NetworkStartIndication()
 *********************************************************************************************************************/
/*! \brief       Indication that a Nm-message has been received in the Bus Sleep Mode, what indicates that some nodes
 *               in the network have already entered the Network Mode.
 *  \details     -
 *  \param[in]   Channel               Valid channel identifier (network handle)
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication( NetworkHandleType  Channel );

/**********************************************************************************************************************
 *  ComM_Nm_NetworkMode()
 *********************************************************************************************************************/
/*! \brief       Indication that the Network Management has entered Network Mode.
 *  \details     -
 *  \param[in]   Channel               Valid channel identifier (network handle)
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-5141
 *********************************************************************************************************************/
FUNC(void, COMM_CODE) ComM_Nm_NetworkMode( NetworkHandleType  Channel );

# if (COMM_SILENTSUPPORTOFCHANNEL == STD_ON)
/**********************************************************************************************************************
 *  ComM_Nm_PrepareBusSleepMode()
 *********************************************************************************************************************/
/*! \brief       Indication that the Network Management has entered Prepare Bus-Sleep Mode.
 *  \details     -
 *  \param[in]   Channel               Valid channel identifier (network handle)
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-5142
 *********************************************************************************************************************/
FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode( NetworkHandleType  Channel );
# endif

/**********************************************************************************************************************
 *  ComM_Nm_BusSleepMode()
 *********************************************************************************************************************/
/*! \brief       Indication that the Network Management has entered Bus-Sleep Mode.
 *  \details     -
 *  \param[in]   Channel               Valid channel identifier (network handle)
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-5132, SPEC-5367
 *********************************************************************************************************************/
FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode( NetworkHandleType  Channel );

/**********************************************************************************************************************
 *  ComM_Nm_RestartIndication()
 *********************************************************************************************************************/
/*! \brief       Indication that Nm has restarted on at least one of the coordinated busses.
 *  \details     -
 *  \param[in]   Channel               Valid channel identifier (network handle)
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, COMM_CODE) ComM_Nm_RestartIndication( NetworkHandleType  Channel );

# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  ComM_Nm_StateChangeNotification()
 *********************************************************************************************************************/
/*! \brief       Notification that the Nm state has changed.
 *  \details     The Pnc Routing Limitation state is updated depending on Nm has left or entered the state NM_STATE_REPEAT_MESSAGE.
 *  \param[in]   Channel                Valid channel identifier (network handle)
 *  \param[in]   NmPreviousState        Previous state of Nm
 *  \param[in]   NmCurrentState         Current state of Nm
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, COMM_CODE) ComM_Nm_StateChangeNotification( CONST(NetworkHandleType, AUTOMATIC) Channel, CONST(Nm_StateType, AUTOMATIC) NmPreviousState, CONST(Nm_StateType, AUTOMATIC) NmCurrentState );
# endif

# define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

#endif  /* COMM_NM_H */

/**********************************************************************************************************************
  END OF FILE: ComM_Nm.h
**********************************************************************************************************************/
