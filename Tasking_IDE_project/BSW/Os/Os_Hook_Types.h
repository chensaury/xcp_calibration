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
 * \addtogroup  Os_Hook
 * \brief       Hook function calling.
 * \details     --no details--
 *
 *
 * \{
 *
 * \file
 * \brief       Hook data types.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_HOOK_TYPES_H
# define OS_HOOK_TYPES_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Std_Types.h"

# include "Os_Common_Types.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! No hooks active bit mask. */
# define OS_HOOKFLAG_NOHOOKS                ((Os_HookFlagType)0U)
/*! The Error Hook mask bit. */
# define OS_HOOKFLAG_ERRORHOOK              ((Os_HookFlagType)1U << 0U)
/*! The Protection Hook mask bit. */
# define OS_HOOKFLAG_PROTECTIONHOOK         ((Os_HookFlagType)1U << 1U)
/*! The Startup Hook mask bit. */
# define OS_HOOKFLAG_STARTUPHOOK            ((Os_HookFlagType)1U << 2U)
/*! The Shutdown Hook mask bit. */
# define OS_HOOKFLAG_SHUTDOWNHOOK           ((Os_HookFlagType)1U << 3U)
/*! The IOC callback mask bit. */
# define OS_HOOKFLAG_IOCCALLBACK            ((Os_HookFlagType)1U << 4U)
/*! The Init Hook mask bit. */
# define OS_HOOKFLAG_INITHOOK               ((Os_HookFlagType)1U << 5U)



/*! Specifies the hooks which may nest an error hook call. */
# define OS_HOOKNESTINGMASK_ERRORHOOK       ((Os_HookFlagType)(  (OS_HOOKFLAG_STARTUPHOOK) \
                                                              |  (OS_HOOKFLAG_IOCCALLBACK) ))

/*! Specifies the hooks which may nest a protection hook call. */
# define OS_HOOKNESTINGMASK_PROTECTIONHOOK  ((Os_HookFlagType)(  (OS_HOOKFLAG_ERRORHOOK) \
                                                              |  (OS_HOOKFLAG_STARTUPHOOK) \
                                                              |  (OS_HOOKFLAG_IOCCALLBACK) ))

/*! Specifies the hooks which may nest a startup hook call. */
# define OS_HOOKNESTINGMASK_STARTUPHOOK     ((Os_HookFlagType)    OS_HOOKFLAG_INITHOOK)

/*! Specifies the hooks which may nest a shutdown hook call. */
# define OS_HOOKNESTINGMASK_SHUTDOWNHOOK    ((Os_HookFlagType)(  (OS_HOOKFLAG_ERRORHOOK) \
                                                              |  (OS_HOOKFLAG_PROTECTIONHOOK) \
                                                              |  (OS_HOOKFLAG_STARTUPHOOK) \
                                                              |  (OS_HOOKFLAG_IOCCALLBACK) ))

/*! Specifies the hooks which may nest an IOC callback. */
# define OS_HOOKNESTINGMASK_IOCCALLBACK     ((Os_HookFlagType)(  (OS_HOOKFLAG_ERRORHOOK) \
                                                              |  (OS_HOOKFLAG_PROTECTIONHOOK) \
                                                              |  (OS_HOOKFLAG_STARTUPHOOK) \
                                                              |  (OS_HOOKFLAG_SHUTDOWNHOOK) ))

/*! Specifies the hooks which may nest a init hook call. */
# define OS_HOOKNESTINGMASK_INITHOOK        ((Os_HookFlagType)    0)


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

struct Os_HookType_Tag;
typedef struct Os_HookType_Tag Os_HookType;

struct Os_HookConfigType_Tag;
typedef struct Os_HookConfigType_Tag Os_HookConfigType;

struct Os_HookStatusHookConfigType_Tag;
typedef struct Os_HookStatusHookConfigType_Tag Os_HookStatusHookConfigType;

struct Os_HookCallbackConfigType_Tag;
typedef struct Os_HookCallbackConfigType_Tag Os_HookCallbackConfigType;

struct Os_HookProtectionHookConfigType_Tag;
typedef struct Os_HookProtectionHookConfigType_Tag Os_HookProtectionHookConfigType;

struct Os_HookInitHookConfigType_Tag;
typedef struct Os_HookInitHookConfigType_Tag Os_HookInitHookConfigType;

typedef uint32 Os_HookFlagType;

/*! Tells which hooks are currently executing. */
typedef struct
{
  /*! Contains one true bit per nested hook type. */
  Os_HookFlagType InHookFlags;
} Os_HookInfoType;

/*! Hook identifier type. */
typedef uint32 Os_HookIdType;

/*! Pointer to Hook configuration */
typedef P2CONST(Os_HookConfigType, TYPEDEF, OS_CONST) Os_HookConfigRefType;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



#endif /* OS_HOOK_TYPES_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hook_Types.h
 **********************************************************************************************************************/
