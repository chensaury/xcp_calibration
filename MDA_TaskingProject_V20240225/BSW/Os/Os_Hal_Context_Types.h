/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup  Os_Hal_Context
 * \{
 *
 * \file        Os_Hal_Context_Types.h
 * \brief       Forward declarations of the HAL context module.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef OS_HAL_CONTEXT_TYPES_H
# define OS_HAL_CONTEXT_TYPES_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/
/*! Forward declaration of Os_Hal_ContextType */
struct Os_Hal_ContextType_Tag;
typedef struct Os_Hal_ContextType_Tag Os_Hal_ContextType;

/*! Forward declaration of Os_Hal_ContextConfigType */
struct Os_Hal_ContextConfigType_Tag;
typedef struct Os_Hal_ContextConfigType_Tag Os_Hal_ContextConfigType;

/*! Forward declaration of Os_Hal_ContextStackConfigType */
struct Os_Hal_ContextStackConfigType_Tag;
typedef struct Os_Hal_ContextStackConfigType_Tag Os_Hal_ContextStackConfigType;

/*! Forward declaration of Os_Hal_ContextFpuContextType */
struct Os_Hal_ContextFpuContextType_Tag;
typedef struct Os_Hal_ContextFpuContextType_Tag Os_Hal_ContextFpuContextType;

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


#endif /* OS_HAL_CONTEXT_TYPES_H */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_Types.h
 **********************************************************************************************************************/
