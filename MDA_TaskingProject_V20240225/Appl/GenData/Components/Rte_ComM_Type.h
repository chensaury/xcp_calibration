/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_ComM_Type.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Application types header file for SW-C <ComM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_COMM_TYPE_H
# define _RTE_COMM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef COMM_NO_COMMUNICATION
#   define COMM_NO_COMMUNICATION (0U)
#  endif

#  ifndef COMM_SILENT_COMMUNICATION
#   define COMM_SILENT_COMMUNICATION (1U)
#  endif

#  ifndef COMM_FULL_COMMUNICATION
#   define COMM_FULL_COMMUNICATION (2U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_ComMMode
#  define RTE_MODETYPE_ComMMode
typedef ComM_ModeType Rte_ModeType_ComMMode;
# endif

# define RTE_MODE_ComM_ComMMode_COMM_FULL_COMMUNICATION (0U)
# ifndef RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION
#  define RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION (0U)
# endif
# define RTE_MODE_ComM_ComMMode_COMM_NO_COMMUNICATION (1U)
# ifndef RTE_MODE_ComMMode_COMM_NO_COMMUNICATION
#  define RTE_MODE_ComMMode_COMM_NO_COMMUNICATION (1U)
# endif
# define RTE_MODE_ComM_ComMMode_COMM_SILENT_COMMUNICATION (2U)
# ifndef RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION
#  define RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION (2U)
# endif
# define RTE_TRANSITION_ComM_ComMMode (3U)
# ifndef RTE_TRANSITION_ComMMode
#  define RTE_TRANSITION_ComMMode (3U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_COMM_TYPE_H */
