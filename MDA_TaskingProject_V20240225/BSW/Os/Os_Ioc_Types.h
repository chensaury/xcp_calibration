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
 * \addtogroup Os_Ioc
 * \{
 *
 * \file
 * \brief       The IOC type declarations.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_IOC_TYPES_H
# define OS_IOC_TYPES_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Std_Types.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Lock method types for accessing the IOC channel. */
typedef enum
{
  /*! Lock nothing. */
  OS_IOCLOCKMODE_NONE,
  /*! Lock interrupts. */
  OS_IOCLOCKMODE_INTERRUPTS,
  /*! Lock spinlocks. */
  OS_IOCLOCKMODE_SPINLOCKS,
  /*! Lock interrupts and spinlocks. */
  OS_IOCLOCKMODE_ALL
}Os_IocLockModeType;


/*! An IOC channel's state. */
typedef enum
{
  /*! The channel may not be used. */
  OS_IOCCHANNELSTATE_DISABLED,
  /*! The channel may be used. */
  OS_IOCCHANNELSTATE_ENABLED
}Os_IocChannelStateType;


struct Os_IocCallbacksConfigType_Tag;
typedef struct Os_IocCallbacksConfigType_Tag Os_IocCallbacksConfigType;

struct Os_Ioc32ReceiveConfigType_Tag;

typedef uint8_least Os_IocLostCounterType;

typedef struct Os_IocConfigType_Tag Os_IocConfigType;
typedef struct Os_IocType_Tag Os_IocType;

typedef struct Os_IocReceiveConfigType_Tag Os_IocReceiveConfigType;
typedef struct Os_IocSendConfigType_Tag Os_IocSendConfigType;
typedef struct Os_IocSendType_Tag Os_IocSendType;
typedef struct Os_IocReceiveType_Tag Os_IocReceiveType;

typedef struct Os_IocMultiReceiveType_Tag Os_IocMultiReceiveType;
typedef struct Os_IocMultiReceiveConfigType_Tag Os_IocMultiReceiveConfigType;

typedef struct Os_Ioc08ReceiveConfigType_Tag Os_Ioc08ReceiveConfigType;
typedef struct Os_Ioc08SendConfigType_Tag Os_Ioc08SendConfigType;
typedef struct Os_Ioc08MultiReceiveConfigType_Tag Os_Ioc08MultiReceiveConfigType;
typedef struct Os_Ioc08ReceiveType_Tag Os_Ioc08ReceiveType;
typedef struct Os_Ioc08SendType_Tag Os_Ioc08SendType;

typedef struct Os_Ioc16ReceiveConfigType_Tag Os_Ioc16ReceiveConfigType;
typedef struct Os_Ioc16SendConfigType_Tag Os_Ioc16SendConfigType;
typedef struct Os_Ioc16MultiReceiveConfigType_Tag Os_Ioc16MultiReceiveConfigType;
typedef struct Os_Ioc16ReceiveType_Tag Os_Ioc16ReceiveType;
typedef struct Os_Ioc16SendType_Tag Os_Ioc16SendType;

typedef struct Os_Ioc32ReceiveConfigType_Tag Os_Ioc32ReceiveConfigType;
typedef struct Os_Ioc32SendConfigType_Tag Os_Ioc32SendConfigType;
typedef struct Os_Ioc32MultiReceiveConfigType_Tag Os_Ioc32MultiReceiveConfigType;
typedef struct Os_Ioc32ReceiveType_Tag Os_Ioc32ReceiveType;
typedef struct Os_Ioc32SendType_Tag Os_Ioc32SendType;

typedef struct Os_IocRefReceiveConfigType_Tag Os_IocRefReceiveConfigType;
typedef struct Os_IocRefSendConfigType_Tag Os_IocRefSendConfigType;
typedef struct Os_IocRefMultiReceiveConfigType_Tag Os_IocRefMultiReceiveConfigType;
typedef struct Os_IocRefReceiveType_Tag Os_IocRefReceiveType;
typedef struct Os_IocRefSendType_Tag Os_IocRefSendType;


typedef struct Os_IocReadConfigType_Tag Os_IocReadConfigType;
typedef struct Os_IocWriteConfigType_Tag Os_IocWriteConfigType;
typedef struct Os_IocReadType_Tag Os_IocReadType;
typedef struct Os_IocWriteType_Tag Os_IocWriteType;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



#endif /* OS_IOC_TYPES_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Ioc_Types.h
 **********************************************************************************************************************/
