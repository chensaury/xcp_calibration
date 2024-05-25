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
/**         \file  ComM_Types.h
 *         \brief  Communication Manager ASR4
 *
 *       \details  Implementation of the Autosar Communication Manager, type definitions
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

#ifndef COMM_TYPES_H
# define COMM_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComStack_Types.h"  /* Include standard types */
# include "ComM_GenTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define COMM_TYPES_MAJOR_VERSION          (9u)
# define COMM_TYPES_MINOR_VERSION          (0u)
# define COMM_TYPES_PATCH_VERSION          (1u)

/*! Network bus types */
# define COMM_BUS_TYPE_CAN                 (0u)
# define COMM_BUS_TYPE_FR                  (1u)
# define COMM_BUS_TYPE_LIN                 (3u)
# define COMM_BUS_TYPE_ETH                 (4u)
# define COMM_BUS_TYPE_INTERNAL            (5u)

/*! ComM channel states */
# define COMM_NO_COM_NO_PENDING_REQUEST    (0u)
# define COMM_NO_COM_REQUEST_PENDING       (1u)
# define COMM_FULL_COM_NETWORK_REQUESTED   (2u)
# define COMM_FULL_COM_READY_SLEEP         (3u)
# define COMM_SILENT_COM                   (4u)
# define COMM_MAX_NUMBER_OF_STATES         (5u)

/*! ComM PNC states */
# define COMM_PNC_NO_COMMUNICATION         (0u)
# define COMM_PNC_PREPARE_SLEEP            (1u)
# define COMM_PNC_READY_SLEEP              (2u)
# define COMM_PNC_REQUESTED                (3u)
# define COMM_PNC_REQUESTED_PASSIVE        (4u) /*!< Internal state representing PNC requested via ERA, which is received on PASSIVE channels only */

/*! PNC gateway types */
# define COMM_GATEWAY_TYPE_ACTIVE          (0u)
# define COMM_GATEWAY_TYPE_PASSIVE         (1u)
# define COMM_GATEWAY_TYPE_NONE            (2u)

/*! Initialization status */
# define COMM_UNINIT                       (0u)
# define COMM_INIT                         (1u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Initialization status type of the ComM */
typedef uint8 ComM_InitStatusType;
/*! Bus type of a channel */
typedef uint8 ComM_BusType;
/*! State type of a channel */
typedef uint8 ComM_StateType;
/*! Mode type of a PNC */
typedef uint8 ComM_PncModeType;

#endif /* COMM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: ComM_Types.h
 *********************************************************************************************************************/
