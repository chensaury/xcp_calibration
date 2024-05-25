/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup Os_XSignal
 * \{
 *
 * \file
 * \brief       forward declarations for XSignal types
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_XSIGNAL_TYPES_H
# define OS_XSIGNAL_TYPES_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Std_Types.h"

# include "Os_XSignal_Cfg.h"

/* Os module dependencies */
# include "Os_Common_Types.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! The maximum number of supported cross core function parameters (of type Os_ParamType) */
# define OS_MAX_NUM_OF_CROSS_CORE_PARAMS       ((Os_ObjIdxType)4u)


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Identifies a queue element. */
typedef Os_ObjIdxType Os_XSigBufferIdxType;

struct Os_XSigConfigType_Tag;
typedef struct Os_XSigConfigType_Tag Os_XSigConfigType;

struct Os_XSigIsrConfigType_Tag;
typedef struct Os_XSigIsrConfigType_Tag Os_XSigIsrConfigType;
typedef P2CONST(Os_XSigIsrConfigType, AUTOMATIC, OS_CONST) Os_XSigIsrConfigRefType;

struct Os_XSigSendDataType_Tag;
typedef struct Os_XSigSendDataType_Tag Os_XSigSendDataType;

struct Os_XSigRecvDataType_Tag;
typedef struct Os_XSigRecvDataType_Tag Os_XSigRecvDataType;

struct Os_XSigSendPortConfigType_Tag;
typedef struct Os_XSigSendPortConfigType_Tag Os_XSigSendPortConfigType;

struct Os_XSigRecvPortConfigType_Tag;
typedef struct Os_XSigRecvPortConfigType_Tag Os_XSigRecvPortConfigType;
typedef P2CONST(Os_XSigRecvPortConfigType, AUTOMATIC, OS_CONST) Os_XSigRecvPortConfigRefType;

struct Os_XSigFunctionTableConfigType_Tag;
typedef struct Os_XSigFunctionTableConfigType_Tag Os_XSigFunctionTableConfigType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



#endif /* OS_XSIGNAL_TYPES_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_XSignal_Types.h
 **********************************************************************************************************************/
