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
 *  \ingroup     Os_Kernel
 *  \defgroup    Os_MemoryProtection Memory Protection
 *  \brief       Provides functions to switch memory access rights.
 *  \details
 *  The kernel handles any kind of spatial isolation mechanism as memory protection settings. The concrete
 *  implementation may use a MPU, MMU, PPU or something else. The kernel does not define how memory protection
 *  settings look like. The platform is free to define which attributes they have. This allows hiding details about
 *  hardware specific information. Typically they contain a hardware dependent encoding for the following information:
 *
 *  - Start Address
 *  - End Address
 *  - Cachable flag
 *  - Read/Write/Execute Rights
 *
 *
 *  Owners Of Memory Protection Settings
 *  ------------------------------------
 *  The kernel expects the following entities to have memory protection settings:
 *
 *  - **System:**   These memory protection settings represent the configuration of the system MPU/MMU etc..
 *                  This typically makes only sense in a multi core environment. They define the constant access to
 *                  peripherals or data from different active system members (cores/DMAs). These settings are setup
 *                  on the master core during OS initialization and are not modified during runtime.
 *  - **Core:**     These memory protection settings represent the configuration of the core local MPU/MMU etc..
 *                  They define the constant core local common access settings (e.g. read access to whole RAM, execute
 *                  rights in code flash, etc.). These settings are setup on each core during OS initialization and
 *                  are not modified during runtime.
 *  - **Application:** These memory protection settings represent the configuration of the application.
 *                  They are switched by the OS, if the current application is changed.
 *  - **Thread and Service Function:** These memory protection settings represent the configuration of the
 *                  thread/service function. They are switched by the OS, if the thread is switched or a
 *                  service function is called.
 *
 *  ![MPU Example](MemProtExampleMpu.png)
 *
 *
 *  ### Memory Protection Violation Handling ###
 *  ![Memory Protection Violation Handling](MemoryProtection_MemFault.png)
 *
 *
 *  \trace       CREQ-1201
 *  \trace       SPEC-63903
 *
 *
 *  \see \ref StackOverflowDetection
 *
 *  \{
 *
 *  \file
 *  \brief       Internal functions and data types to work with memory protection settings.
 *  \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_MEMORYPROTECTIONINT_H
# define OS_MEMORYPROTECTIONINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_MemoryProtection_Types.h"
# include "Os_MemoryProtection_Cfg.h"

/* Os kernel module dependencies */

/* Os Hal dependencies */
# include "Os_Hal_CompilerInt.h"
# include "Os_Hal_MemoryProtectionInt.h"
# include "Os_Hal_CoreInt.h"
# include "Os_Hal_ContextInt.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! This data type defines the system's memory protection settings.
 * \trace CREQ-844
 * \trace SPEC-63791 */
struct Os_MpSystemConfigType_Tag
{
  /*! Memory protection configuration for the system memory protection. */
  P2CONST(Os_Hal_MpSystemConfigType, TYPEDEF, OS_CONST) HwConfig;
};


/*! This data type defines the core's memory protection settings.
 * \trace CREQ-844
 * \trace SPEC-63791 */
struct Os_MpCoreConfigType_Tag
{
  /*! Memory protection configuration for the core memory protection. */
  P2CONST(Os_Hal_MpCoreConfigType, TYPEDEF, OS_CONST) HwConfig;
};


/*! Dynamic memory protection setup used by threads and service functions. */
struct Os_MpAccessRightsType_Tag
{
  /*! Memory protection configuration which shall be switched in case of application switching.
   * \trace CREQ-41
   * \trace SPEC-64014 */
  P2CONST(Os_Hal_MpAppConfigType, TYPEDEF, OS_CONST) AppAccessRights;

  /*! Memory protection configuration which shall be switched in case of thread switching.
   * \trace CREQ-62 */
  P2CONST(Os_Hal_MpThreadConfigType, TYPEDEF, OS_CONST) ThreadAccessRights;
};


/*! Pointer to memory protection configuration. */
typedef P2CONST(Os_MpAccessRightsType, TYPEDEF, OS_CONST) Os_MpAccessRightsRefType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  Os_MpSystemInit()
 **********************************************************************************************************************/
/*! \brief          Initializes system access rights (Init-Step2).
 *  \details        Initializes system's memory protection mechanism and set the passed memory protection settings for
 *                  the system.
 *
 *  \param[in]      SystemConfig  Configuration for system's memory protection mechanism. Parameter must not be NULL,
 *                                if Memory protection is enabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to memory protection hardware prevented by caller.
 *
 *  \trace          CREQ-844
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_MpSystemInit,
(
  P2CONST(Os_MpSystemConfigType, AUTOMATIC, OS_CONST) SystemConfig
));


/***********************************************************************************************************************
 *  Os_MpCoreInit()
 **********************************************************************************************************************/
/*! \brief          Initializes core access rights.
 *  \details        Initializes the core's memory protection mechanism and set the passed memory protection settings
 *                  for the core. Initialize the initial MPU stack window.
 *
 *  \param[in]      CoreConfig   Core configuration for memory protection mechanism. Parameter must not be NULL,
 *                               if memory protection is enabled.
 *
 *  \param[in]      InitialStackRegion  Stack configuration for memory protection mechanism. Parameter must not be NULL,
 *                                      if memory protection is enabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to memory protection hardware prevented by caller.
 *
 *  \trace          CREQ-844
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_MpCoreInit,
(
  P2CONST(Os_MpCoreConfigType, AUTOMATIC, OS_CONST) CoreConfig,
  P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) InitialStackRegion
));


/***********************************************************************************************************************
 *  Os_MpThreadInit()
 **********************************************************************************************************************/
/*! \brief          Initializes thread access rights.
 *  \details        Initializes the threads's memory protection settings. This function is called for the first tine in
 *                  Init-Step3 and Init-Step4 in order to handle the situation that Init-Step3 is optional. However,
 *                  it is also called when re-initialization is necessary.
 *
 *
 *  \param[in]      Config    Threads's memory protection configuration. Parameter must not be NULL, if Memory
 *                            protection is enabled.
 *  \param[out]     Settings  Threads current memory protection settings. Parameter must not be NULL, if Memory
 *                            protection is enabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_MpThreadInit,
(
  P2CONST(Os_MpAccessRightsType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_MpAccessRightsRefType, AUTOMATIC, OS_VAR_NOINIT_FAST) Settings
));


/***********************************************************************************************************************
 *  Os_MpIsEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether memory protection is enabled (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval         !0    Memory protection is enabled.
 *  \retval         0     Memory protection is disabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_MpIsEnabled,
(
  void
));


/***********************************************************************************************************************
 *  Os_MpIsEnabledForTrusted()
 **********************************************************************************************************************/
/*! \brief          Returns whether memory protection is enabled for trusted applications (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval         !0    Memory protection is enabled for trusted applications.
 *  \retval         0     Memory protection is disabled for trusted applications.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_MpIsEnabledForTrusted,
(
  void
));


/***********************************************************************************************************************
 *  Os_MpIsEnabledForApplications()
 **********************************************************************************************************************/
/*! \brief          Returns whether memory protection is enabled for applications (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval         !0    Memory protection is enabled for applications.
 *  \retval         0     Memory protection is disabled for applications.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_MpIsEnabledForApplications,
(
  void
));


/***********************************************************************************************************************
 *  Os_MpIsEnabledForThreads()
 **********************************************************************************************************************/
/*! \brief          Returns whether memory protection is enabled for threads (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval         !0    Memory protection is enabled for applications.
 *  \retval         0     Memory protection is disabled for applications.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_MpIsEnabledForThreads,
(
  void
));


/***********************************************************************************************************************
 *  Os_MpSwitch()
 **********************************************************************************************************************/
/*! \brief          Switches access rights.
 *  \details        Switches thread related access rights and application related access rights.
 *                  Application related access rights are only switched, if they are different to speed up thread
 *                  switching within the same application.
 *
 *  \param[in]      Current   Current access rights. Parameter must not be NULL, if Memory protection is enabled.
 *  \param[in]      Next      Access rights to switch to. Parameter must not be NULL, if Memory protection is enabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to memory protection hardware prevented by caller.
 *  \pre            Current is the active memory protection configuration.
 *
 *  \trace          CREQ-41, CREQ-62
 *  \trace          SPEC-63794, SPEC-63893, SPEC-64006, SPEC-63740, SPEC-63931, SPEC-63705, SPEC-63978, SPEC-64037
 *  \trace          SPEC-63930, SPEC-63762
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_MpSwitch,
(
  P2CONST(Os_MpAccessRightsType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_MpAccessRightsType, AUTOMATIC, OS_CONST) Next
));


/***********************************************************************************************************************
 *  Os_MpSwitchTo()
 **********************************************************************************************************************/
/*! \brief          Switch to given access rights.
 *  \details        Switch thread related access rights and application related access rights.
 *
 *  \param[in]      AccessRights      Access rights to switch to. Parameter must not be NULL, if Memory protection
 *                                    is enabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to memory protection hardware prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_MpSwitchTo,
(
  P2CONST(Os_MpAccessRightsType, AUTOMATIC, OS_CONST) AccessRights
));


/***********************************************************************************************************************
 *  Os_MpTrustedSwitchTo()
 **********************************************************************************************************************/
/*! \brief          Switch to given access rights if trusted applications are memory protected.
 *  \details        This function performs no-op, if the OS has write access to its data in supervisor mode.
 *
 *  \param[in]      AccessRights  Access rights to switch to. Parameter must not be NULL, if Memory protection
 *                                is enabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to memory protection hardware prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_MpTrustedSwitchTo,
(
  P2CONST(Os_MpAccessRightsType, AUTOMATIC, OS_CONST) AccessRights
));


/***********************************************************************************************************************
 *  Os_MemFault()
 **********************************************************************************************************************/
/*! \brief        Kernel behavior for memory fault exceptions.
 *  \details      This function never returns.
 *
 *  \param[in]    ExceptionInstructionAddress  Address of the instruction that caused MemFault.
 *  \param[in]    ExceptionCauserPrivileged    Defines whether the system was in privileged mode during occurence of
 *                                             the violation:
 *                                               - TRUE:  Privileged mode was active.
 *                                               - FALSE: Non-Privileged mode was active.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \trace        SPEC-63706
 *
 *  \pre          -
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_MemFault
(
  Os_AddressOfConstType ExceptionInstructionAddress,
  boolean ExceptionCauserPrivileged
);



/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */




#endif /* OS_MEMORYPROTECTIONINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_MemoryProtectionInt.h
 **********************************************************************************************************************/
