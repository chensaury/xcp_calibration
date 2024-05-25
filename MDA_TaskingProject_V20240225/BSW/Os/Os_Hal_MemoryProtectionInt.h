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
 *  \ingroup    Os_Hal
 *  \defgroup   Os_Hal_MemoryProtection  HAL Memory Protection
 *  \brief      Internal functions and data types related to memory protection.
 *  \details
 *
 *  \note Consider Memory barriers and sync instructions.
 *
 *  \{
 *
 *  \file      Os_Hal_MemoryProtectionInt.h
 *  \brief
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef OS_HAL_MEMORYPROTECTIONINT_H
# define OS_HAL_MEMORYPROTECTIONINT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_MemoryProtection_Types.h"

/* Os kernel module dependencies */

/* Os Hal dependencies */
# include "Os_Hal_CoreInt.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! \brief    Memory protection region type. */
typedef struct
{
  /*! Start address of a region */
  uint32 StartAddress;

  /*! End address of a region */
  uint32 EndAddress;
} Os_Hal_MpuRegionRangeConfigType;


/*! \brief    System wide memory protection configuration.
 *  \details
 *  The kernel uses this data type to initialize access rights for different bus masters (cores, DMAs, etc.).
 *  These are typically MPU, MMU or PPU settings such as region descriptors.
 */
struct Os_Hal_MpSystemConfigType_Tag
{
  uint32 SysMpuId;
};


/*! \brief    Memory protection configuration of a core.
 *  \details  The kernel uses this data type to initialize access rights of a core.
 *            These are typically MPU, MMU or PPU settings such as region descriptors.
 */
struct Os_Hal_MpCoreConfigType_Tag
{
  /*! Data region configuration for all protection sets */
  uint8 MpuDataRegionStartSlot;
  uint8 MpuDataRegionCount;
  P2CONST(Os_Hal_MpuRegionRangeConfigType, AUTOMATIC, OS_CONST) MpuDataRegions;
  uint32 MpuDataRegionReadEnable[OS_HAL_COREMPU_NUM_OF_PS];
  uint32 MpuDataRegionWriteEnable[OS_HAL_COREMPU_NUM_OF_PS];

  /*! Code region configuration for all protection sets */
  uint8 MpuCodeRegionStartSlot;
  uint8 MpuCodeRegionCount;
  P2CONST(Os_Hal_MpuRegionRangeConfigType, AUTOMATIC, OS_CONST) MpuCodeRegions;
  uint32 MpuCodeRegionExecutionEnable[OS_HAL_COREMPU_NUM_OF_PS];
};


/*! \brief    Memory protection configuration of an OS application.
 *  \details  The kernel uses this data type to switch access rights, if the active application changes.
 *            These are typically MPU, MMU or PPU settings such as region descriptors or an ASID.
 */
struct Os_Hal_MpAppConfigType_Tag
{
  uint8 ProtectionSet;

  /*! Data region configuration */
  uint8 MpuDataRegionStartSlot;
  uint8 MpuDataRegionCount;
  P2CONST(Os_Hal_MpuRegionRangeConfigType, AUTOMATIC, OS_CONST) MpuDataRegions;
  uint32 MpuDataRegionEnableMask;
  uint32 MpuDataRegionReadEnable;
  uint32 MpuDataRegionWriteEnable;

  /*! Code region configuration */
  uint8 MpuCodeRegionStartSlot;
  uint8 MpuCodeRegionCount;
  P2CONST(Os_Hal_MpuRegionRangeConfigType, AUTOMATIC, OS_CONST) MpuCodeRegions;
  uint32 MpuCodeRegionEnableMask;
  uint32 MpuCodeRegionExecutionEnable;
};


/*! \brief    Memory protection configuration of an OS thread.
 *  \details  The kernel uses this data type to switch access rights, if the active thread changes.
 *            These are typically MPU, MMU or PPU settings such as region descriptors or an ASID.
 */
struct Os_Hal_MpThreadConfigType_Tag
{
  uint8 ProtectionSet;

  /*! Data region configuration */
  uint8 MpuDataRegionStartSlot;
  uint8 MpuDataRegionCount;
  P2CONST(Os_Hal_MpuRegionRangeConfigType, AUTOMATIC, OS_CONST) MpuDataRegions;
  uint32 MpuDataRegionEnableMask;
  uint32 MpuDataRegionReadEnable;
  uint32 MpuDataRegionWriteEnable;

  /*! Code region configuration */
  uint8 MpuCodeRegionStartSlot;
  uint8 MpuCodeRegionCount;
  P2CONST(Os_Hal_MpuRegionRangeConfigType, AUTOMATIC, OS_CONST) MpuCodeRegions;
  uint32 MpuCodeRegionEnableMask;
  uint32 MpuCodeRegionExecutionEnable;
};



/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  Os_Hal_MpSystemInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the system memory protection.
 *  \details        Initializes system's memory protection mechanism and set the passed memory protection settings for
 *                  the system. This function is called once on the master core during OS initialization.
 *                  It typically initializes and enables any system related protection mechanism (system MPU/MMU/PPU).
 *
 *  \param[in]      SystemConfig  Configuration for system's memory protection mechanism.
 *                                Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode.
 *  \pre            Executed on master core.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_MpSystemInit,
(
  P2CONST(Os_Hal_MpSystemConfigType, TYPEDEF, OS_CONST) SystemConfig
));


/***********************************************************************************************************************
 *  Os_Hal_MpCoreInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the core memory protection.
 *  \details        Initializes the core's memory protection mechanism and set the passed memory protection settings
 *                  for the core. This function is called once on each core during OS initialization.
 *                  It typically initializes and enables any core related protection mechanism (system MPU/MMU/PPU).
 *
 *  \param[in]      CoreConfig  Configuration for core's memory protection mechanism.
 *                              Parameter must not be NULL.
 *
 *  \param[in]      InitialStackRegion  Stack configuration for memory protection mechanism. Used to set the initially
 *                                      open stack window. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_MpCoreInit,
(
  P2CONST(Os_Hal_MpCoreConfigType, TYPEDEF, OS_CONST) CoreConfig,
  P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_CONST) InitialStackRegion
));


/***********************************************************************************************************************
 *  Os_Hal_MpAppSwitch()
 **********************************************************************************************************************/
/*! \brief          Switches application related access rights.
 *  \details        Switches the current memory protection settings to the passed ones.
 *
 *  \param[in]      AppConfig   Configuration for application's memory protection mechanism.
 *                              Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Supervisor mode.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_MpAppSwitch,
(
  P2CONST(Os_Hal_MpAppConfigType, TYPEDEF, OS_CONST) AppConfig
));


/***********************************************************************************************************************
 *  Os_Hal_MpThreadSwitch()
 **********************************************************************************************************************/
/*! \brief          Switches thread related access rights.
 *  \details        Switches the current memory protection settings to the passed ones.
 *
 *  \param[in]      ThreadConfig   Configuration for thread's memory protection mechanism.
 *                                 Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Supervisor mode.
 *  \pre            Application rights are switched (see \ref Os_Hal_MpAppSwitch()).
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_MpThreadSwitch,
(
  P2CONST(Os_Hal_MpThreadConfigType, TYPEDEF, OS_CONST) ThreadConfig
));


/***********************************************************************************************************************
 *  Os_Hal_ProgramDataRegions()
 **********************************************************************************************************************/
/*! \brief          Program the data regions.
 *  \details        This function should program the MPU data regions.
 *
 *  \param[in]      StartSlot      Start slot, from which the regions should be programmed. It must be in range [0, 17].
 *  \param[in]      Count          How many regions should be programmed. It must be in range [0, 17].
 *  \param[in]      RegionsConfig  MPU configuration, which is to be programmed. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts disabled.
 *  \pre            Supervisor mode.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_ProgramDataRegions,
(
  uint8 StartSlot,
  uint8 Count,
  P2CONST(Os_Hal_MpuRegionRangeConfigType, TYPEDEF, OS_CONST) RegionsConfig
));


/***********************************************************************************************************************
 *  Os_Hal_ProgramCodeRegions()
 **********************************************************************************************************************/
/*! \brief          Program the code regions.
 *  \details        This function should program the MPU code regions.
 *
 *  \param[in]      StartSlot      Start slot, from which the regions should be programmed. It must be in range [0, 7].
 *  \param[in]      Count          How many regions should be programmed. It must be in range [0, 7].
 *  \param[in]      RegionsConfig  MPU configuration, which is to be programmed. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts disabled.
 *  \pre            Supervisor mode.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_ProgramCodeRegions,
(
  uint8 StartSlot,
  uint8 Count,
  P2CONST(Os_Hal_MpuRegionRangeConfigType, TYPEDEF, OS_CONST) RegionsConfig
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_MEMORYPROTECTIONINT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtectionInt.h
 **********************************************************************************************************************/
