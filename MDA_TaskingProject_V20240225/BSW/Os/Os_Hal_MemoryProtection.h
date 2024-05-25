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
 *  \addtogroup Os_Hal_MemoryProtection
 *  \{
 *
 *  \file      Os_Hal_MemoryProtection.h
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/
                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */


#ifndef OS_HAL_MEMORYPROTECTION_H
# define OS_HAL_MEMORYPROTECTION_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_MemoryProtectionInt.h"
# include "Os_Hal_MemoryProtection_Lcfg.h"

/* Os kernel module dependencies */
# include "Os_MemoryProtection_Cfg.h"

/* Os Hal dependencies */
# include "Os_Hal_Core.h"

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


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_MpSystemInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_Hal_MpSystemInit,
(
  P2CONST(Os_Hal_MpSystemConfigType , TYPEDEF, OS_CONST) SystemConfig
))
{
  /* #10 Do nothing */
  OS_IGNORE_UNREF_PARAM(SystemConfig);                                                                                  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}


/***********************************************************************************************************************
 *  Os_Hal_MpCoreInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_Hal_MpCoreInit,
(
  P2CONST(Os_Hal_MpCoreConfigType, TYPEDEF, OS_CONST) CoreConfig,
  P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) InitialStackRegion
))
{
  Os_Hal_IntGlobalStateType previousState;

  /* #10 If there are MPU data regions configured which need to be reprogrammed: */
  if(CoreConfig->MpuDataRegionCount > 0u)
  {
    /* #20 Set up data regions. */
    Os_Hal_ProgramDataRegions(CoreConfig->MpuDataRegionStartSlot,                                                       /* SBSW_OS_HAL_FC_MPUCONFIG */
        CoreConfig->MpuDataRegionCount,
        CoreConfig->MpuDataRegions);

    /* #30 Set up data protection read enable set configuration register. */
    Os_Hal_InitializeAccessDPRE(CoreConfig->MpuDataRegionReadEnable);                                                   /* SBSW_OS_HAL_FC_MPUCONFIG */

    /* #40 Set up data protection write enable set configuration register. */
    Os_Hal_InitializeAccessDPWE(CoreConfig->MpuDataRegionWriteEnable);                                                  /* SBSW_OS_HAL_FC_MPUCONFIG */
  }

  /* #50 If there are MPU code regions configured which need to be reprogrammed: */
  if(CoreConfig->MpuCodeRegionCount > 0u)
  {
    /* #60 Set up code regions */
    Os_Hal_ProgramCodeRegions(CoreConfig->MpuCodeRegionStartSlot,                                                       /* SBSW_OS_HAL_FC_MPUCONFIG */
        CoreConfig->MpuCodeRegionCount,
        CoreConfig->MpuCodeRegions);

    /* #70 Set up code protection execution enable set configuration register. */
    Os_Hal_InitializeAccessCPXE(CoreConfig->MpuCodeRegionExecutionEnable);                                              /* SBSW_OS_HAL_FC_MPUCONFIG */
  }

  /* #80 set the stack regions. */
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER0, InitialStackRegion->StackRegionEnd);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW0,   InitialStackRegion->StackRegionStart);

  /* #85 Store the current interrupt global state and disable all interrupts. */
  Os_Hal_IntGetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */
  Os_Hal_Disable();

  /* #90 Activate the core MPU unit. */
  Os_Hal_Mtcr(OS_HAL_SYSCON_OFFSET, Os_Hal_Mfcr(OS_HAL_SYSCON_OFFSET) | OS_HAL_SYSCON_MP_MASK);

  /* #100 Instruction sync barrier. */
  Os_Hal_Isync();
  
  /* #110 Restore the previous interrupt global state. */
  Os_Hal_IntSetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Hal_MpAppSwitch()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_Hal_MpAppSwitch,
(
  P2CONST(Os_Hal_MpAppConfigType, TYPEDEF, OS_CONST) AppConfig
))
{
  /* #10 If there are MPU data regions configured which need to be reprogrammed: */
  if(AppConfig->MpuDataRegionCount > 0u)
  {
    /* #20 Set up data regions */
    Os_Hal_ProgramDataRegions(AppConfig->MpuDataRegionStartSlot,                                                        /* SBSW_OS_HAL_FC_MPUCONFIG */
        AppConfig->MpuDataRegionCount,
        AppConfig->MpuDataRegions);

    /* #30 Set up data protection read enable set configuration register */
    Os_Hal_ReadModifyAccessDPRE(AppConfig->ProtectionSet,
        AppConfig->MpuDataRegionEnableMask,
        AppConfig->MpuDataRegionReadEnable);

    /* #40 Set up data protection write enable set configuration register */
    Os_Hal_ReadModifyAccessDPWE(AppConfig->ProtectionSet,
        AppConfig->MpuDataRegionEnableMask,
        AppConfig->MpuDataRegionWriteEnable);
  }

  /* #50 If there are MPU code regions configured which need to be reprogrammed: */
  if(AppConfig->MpuCodeRegionCount > 0u)                                                                                 /* COV_OS_HALUNSUPPORTEDCODEREGIONS */
  {
    /* #60 Set up code regions */
    Os_Hal_ProgramCodeRegions(AppConfig->MpuCodeRegionStartSlot,                                                        /* SBSW_OS_HAL_FC_MPUCONFIG */
        AppConfig->MpuCodeRegionCount,
        AppConfig->MpuCodeRegions);

    /* #70 Set up code protection execution enable set configuration register */
    Os_Hal_ReadModifyAccessCPXE(AppConfig->ProtectionSet,
        AppConfig->MpuCodeRegionEnableMask,
        AppConfig->MpuCodeRegionExecutionEnable);
  }

  /*! \note Switch of protection set is done during the context switch, since the protection set is in the PSW. */

  /* #80 Instruction sync barrier. */
  Os_Hal_Isync();
}


/***********************************************************************************************************************
 *  Os_Hal_MpThreadSwitch()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_Hal_MpThreadSwitch,
(
  P2CONST(Os_Hal_MpThreadConfigType, TYPEDEF, OS_CONST) ThreadConfig
))
{
  /* #10 If there are MPU data regions configured which need to be reprogrammed: */
  if(ThreadConfig->MpuDataRegionCount > 0u)
  {
    /* #20 Set up data regions */
    Os_Hal_ProgramDataRegions(ThreadConfig->MpuDataRegionStartSlot,                                                     /* SBSW_OS_HAL_FC_MPUCONFIG */
        ThreadConfig->MpuDataRegionCount,
        ThreadConfig->MpuDataRegions);

    /* #30 Set up data protection read enable set configuration register */
    Os_Hal_ReadModifyAccessDPRE(ThreadConfig->ProtectionSet,
        ThreadConfig->MpuDataRegionEnableMask,
        ThreadConfig->MpuDataRegionReadEnable);

    /* #40 Set up data protection write enable set configuration register */
    Os_Hal_ReadModifyAccessDPWE(ThreadConfig->ProtectionSet,
        ThreadConfig->MpuDataRegionEnableMask,
        ThreadConfig->MpuDataRegionWriteEnable);
  }

  /* #50 If there are MPU code regions configured which need to be reprogrammed: */
  if(ThreadConfig->MpuCodeRegionCount > 0u)                                                                             /* COV_OS_HALUNSUPPORTEDCODEREGIONS */
  {
    /* #60 Set up code regions */
    Os_Hal_ProgramCodeRegions(ThreadConfig->MpuCodeRegionStartSlot,                                                     /* SBSW_OS_HAL_FC_MPUCONFIG */
        ThreadConfig->MpuCodeRegionCount,
        ThreadConfig->MpuCodeRegions);

    /* #70 Set up code protection execution enable set configuration register */
    Os_Hal_ReadModifyAccessCPXE(ThreadConfig->ProtectionSet,
        ThreadConfig->MpuCodeRegionEnableMask,
        ThreadConfig->MpuCodeRegionExecutionEnable);
  }

  /*! \note Switch of protection set is done during the context switch, since the protection set is in the PSW. */

  /* #80 Instruction sync barrier. */
  Os_Hal_Isync();
}


/***********************************************************************************************************************
 *  Os_Hal_ProgramDataRegions()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_ProgramDataRegions,
(
  uint8 StartSlot,
  uint8 Count,
  P2CONST(Os_Hal_MpuRegionRangeConfigType, TYPEDEF, OS_CONST) RegionsConfig
))
{
  uint8_least Index;

  /* #10 Go through all the regions in the configuration and program them into MPU unit. */
  for(Index=0; Index<Count; Index++)
  {
    Os_Hal_SetDataRegion(StartSlot + Index,                                                                             /* PRQA S 2016 */ /* MD_MSR_EmptyClause */ /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
        RegionsConfig[Index].StartAddress,
        RegionsConfig[Index].EndAddress);
  }
}                                                                                                                       /* PRQA S 6030 */ /* MD_Os_STCYC */


/***********************************************************************************************************************
 *  Os_Hal_ProgramCodeRegions()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_ProgramCodeRegions,
(
  uint8 StartSlot,
  uint8 Count,
  P2CONST(Os_Hal_MpuRegionRangeConfigType, TYPEDEF, OS_CONST) RegionsConfig
))
{
  uint8_least Index;

  /* #10 Go through all the regions in the configuration and program them into MPU unit. */
  for(Index=0; Index<Count; Index++)
  {
    Os_Hal_SetCodeRegion(StartSlot + Index,                                                                             /* PRQA S 2016 */ /* MD_MSR_EmptyClause */ /* COV_OS_HALUNSUPPORTEDCODEREGIONS */
        RegionsConfig[Index].StartAddress,
        RegionsConfig[Index].EndAddress);
  }
}                                                                                                                       /* PRQA S 6030 */ /* MD_Os_STCYC */


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_MEMORYPROTECTION_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection.h
 **********************************************************************************************************************/
