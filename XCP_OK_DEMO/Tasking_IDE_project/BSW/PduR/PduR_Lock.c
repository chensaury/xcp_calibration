/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PduR_Lock.c
 *      Project:  Gw_AsrPduRCfg5
 *       Module:  MICROSAR PDU Router
 *    Generator:  Configurator 5
 *
 *  Description:  Vector implementation of AUTOSAR PDU Router
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */
/* PRQA  S 4304 EOF */ /* MD_MSR_AutosarBoolean */
/* PRQA  S 1881 EOF */ /* MD_MSR_AutosarBoolean */
/* *INDENT-ON* */

#define PDUR_LOCK_SOURCE
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Lock.h"
#include "SchM_PduR.h"
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif
#if (PDUR_SPINLOCKRAM == STD_ON)
# include "Os.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#if (PDUR_SPINLOCKRAM == STD_ON)
/**********************************************************************************************************************
 * Appl_GetSpinlock
 *********************************************************************************************************************/
/*! \brief          Application specific function which gets the lock on the provided variable. It waits until the lock is acquired.
 *  \details        -
 *  \param[in,out]  lockVar  pointer to the variable which shall be used for the lock.
 *  \return         result of request
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) Appl_GetSpinlock(P2VAR(uint32, AUTOMATIC, PDUR_APPL_DATA) lockVar);
#endif

#if (PDUR_SPINLOCKRAM == STD_ON)
/**********************************************************************************************************************
 * Appl_ReleaseSpinlock
 *********************************************************************************************************************/
/*! \brief          Application specific function which releases the lock on the provided variable.
 *  \details        -
 *  \param[in,out]  lockVar  pointer to the variable which shall be used for the lock.
 *  \return         result of request
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) Appl_ReleaseSpinlock(P2VAR(uint32, AUTOMATIC, PDUR_APPL_DATA) lockVar);
#endif

#if (PDUR_SPINLOCKRAM == STD_ON)
/**********************************************************************************************************************
 * Appl_GetSpinlockInitVal
 *********************************************************************************************************************/
/*! \brief          Application specific function which gets the init value for the lock variable.
 *  \details        -
 *  \return         Init value
 *  \pre            -
 *********************************************************************************************************************/
FUNC(uint32, PDUR_CODE) Appl_GetSpinlockInitVal(void);
#endif

/**********************************************************************************************************************
 * PduR_Lock_Lock
 *********************************************************************************************************************/
/*! \brief      PduR Lock function.
 *  \details    -
 *  \param[in]  lockIdx  instance Idx.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Lock_Lock(PduR_LockRomIterType lockIdx);

/**********************************************************************************************************************
 * PduR_Lock_Unlock
 *********************************************************************************************************************/
/*! \brief      PduR Unlock function.
 *  \details    -
 *  \param[in]  lockIdx  instance Idx.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Lock_Unlock(PduR_LockRomIterType lockIdx);

#define PDUR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (PDUR_SPINLOCKRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Lock_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_Init(void)
{
  PduR_SpinlockRamIterType spinlockRamIdx;
  uint32 spinLockInitValue = Appl_GetSpinlockInitVal();

  for(spinlockRamIdx = 0u; spinlockRamIdx < PduR_GetSizeOfSpinlockRam(); spinlockRamIdx++)
  {
    VStdLib_MemClr(PduR_GetAddrCounterOfSpinlockRam(spinlockRamIdx), PDUR_MAX_NUMBER_OF_CORES); /* SBSW_PDUR_CSL01 */ /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    PduR_SetLockVariableOfSpinlockRam(spinlockRamIdx, spinLockInitValue);       /* SBSW_PDUR_CSL01 */
  }
}
#endif
/**********************************************************************************************************************
 * PduR_Lock_Lock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Lock_Lock(PduR_LockRomIterType lockIdx)
{
#if (PDUR_SPINLOCKRAM == STD_ON)
  if(!PduR_IsExclusiveAreaRomUsedOfLockRom(lockIdx))
  {
    SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
    {
      uint8 core_id = (uint8) GetCoreID();
      if(core_id < (uint8) PDUR_MAX_NUMBER_OF_CORES)
      {
        if(0u == PduR_GetCounterOfSpinlockRam(lockIdx)[core_id])
        {
          if(E_OK != Appl_GetSpinlock(PduR_GetAddrLockVariableOfSpinlockRam(PduR_GetSpinlockRamIdxOfLockRom(lockIdx)))) /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */ /* COV_PDUR_FATAL_ERROR */
          {
            PduR_Det_ReportError(PDUR_LOCK_LOCK, PDUR_E_FATAL);
          }
        }
        PduR_GetCounterOfSpinlockRam(lockIdx)[core_id]++;       /* SBSW_PDUR_CORE_ID_RTCHECK */
      }
      else
      {
        PduR_Det_ReportError(PDUR_LOCK_LOCK, PDUR_E_FATAL);
      }
    }
  }
  else
#endif
  {
    PduR_GetLockOfExclusiveAreaRom(PduR_GetExclusiveAreaRomIdxOfLockRom(lockIdx)) ();   /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
  }
  PDUR_DUMMY_STATEMENT(lockIdx);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
 * PduR_Lock_Uplock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Lock_Unlock(PduR_LockRomIterType lockIdx)
{
#if (PDUR_SPINLOCKRAM == STD_ON)
  if(!PduR_IsExclusiveAreaRomUsedOfLockRom(lockIdx))
  {
    {
      uint8 core_id = (uint8) GetCoreID();
      if(core_id < (uint8) PDUR_MAX_NUMBER_OF_CORES)
      {
        if(1u == PduR_GetCounterOfSpinlockRam(lockIdx)[core_id])
        {
          if(E_OK != Appl_ReleaseSpinlock(PduR_GetAddrLockVariableOfSpinlockRam(PduR_GetSpinlockRamIdxOfLockRom(lockIdx))))     /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */ /* COV_PDUR_FATAL_ERROR */
          {
            PduR_Det_ReportError(PDUR_LOCK_UNLOCK, PDUR_E_FATAL);
          }
        }
        PduR_GetCounterOfSpinlockRam(lockIdx)[core_id]--;       /* SBSW_PDUR_CORE_ID_RTCHECK */
      }
      else
      {
        PduR_Det_ReportError(PDUR_LOCK_UNLOCK, PDUR_E_FATAL);
      }
    }
    SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
  }
  else
#endif
  {
    PduR_GetUnlockOfExclusiveAreaRom(PduR_GetExclusiveAreaRomIdxOfLockRom(lockIdx)) (); /* SBSW_PDUR_API_CALL_FORWARDING_ID_ONLY */
  }
  PDUR_DUMMY_STATEMENT(lockIdx);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * PduR_Lock_LockRoutingPathBySrcPdu
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_LockRoutingPathBySrcPdu(PduR_RmSrcRomIterType rmSrcIdx) /* COV_PDUR_WRAPPER_FUNC */
{
  PduR_Lock_Lock(PduR_GetLockRomIdxOfRmSrcRom(rmSrcIdx));
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
 * PduR_Lock_UnlockRoutingPathBySrcPdu
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_UnlockRoutingPathBySrcPdu(PduR_RmSrcRomIterType rmSrcIdx)       /* COV_PDUR_WRAPPER_FUNC */
{
  PduR_Lock_Unlock(PduR_GetLockRomIdxOfRmSrcRom(rmSrcIdx));
  PDUR_DUMMY_STATEMENT(rmSrcIdx);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
 * PduR_Lock_LockRoutingPathByDestPdu
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_LockRoutingPathByDestPdu(PduR_RmDestRomIterType rmDestIdx)      /* COV_PDUR_WRAPPER_FUNC */
{
  PduR_Lock_Lock(PduR_GetLockRomIdxOfRmGDestRom(PduR_GetRmGDestRomIdxOfRmDestRom(rmDestIdx)));
  PDUR_DUMMY_STATEMENT(rmDestIdx);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
 * PduR_Lock_UnlockRoutingPathByDestPdu
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_UnlockRoutingPathByDestPdu(PduR_RmDestRomIterType rmDestIdx)    /* COV_PDUR_WRAPPER_FUNC */
{
  PduR_Lock_Unlock(PduR_GetLockRomIdxOfRmGDestRom(PduR_GetRmGDestRomIdxOfRmDestRom(rmDestIdx)));
  PDUR_DUMMY_STATEMENT(rmDestIdx);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
 * PduR_Lock_LockRoutingPathByGDestPdu
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_LockRoutingPathByGDestPdu(PduR_RmGDestRomIterType rmGDestIdx)   /* COV_PDUR_WRAPPER_FUNC */
{
  PduR_Lock_Lock(PduR_GetLockRomIdxOfRmGDestRom(rmGDestIdx));
  PDUR_DUMMY_STATEMENT(rmGDestIdx);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
 * PduR_Lock_UnlockRoutingPathByGDestPdu
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_UnlockRoutingPathByGDestPdu(PduR_RmGDestRomIterType rmGDestIdx) /* COV_PDUR_WRAPPER_FUNC */
{
  PduR_Lock_Unlock(PduR_GetLockRomIdxOfRmGDestRom(rmGDestIdx));
  PDUR_DUMMY_STATEMENT(rmGDestIdx);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

#if (PDUR_SPINLOCKRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Lock_LockBuffersByTxBufferInd
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_LockBuffersByTxBufferInd(PduR_BmTxBufferIndRomIterType txBufferIndIdx)
{
  if(PduR_IsLockRomUsedOfBmTxBufferIndRom(txBufferIndIdx))
  {
    PduR_Lock_Lock(PduR_GetLockRomIdxOfBmTxBufferIndRom(txBufferIndIdx));
  }
  PDUR_DUMMY_STATEMENT(txBufferIndIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_SPINLOCKRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Lock_UnlockBuffersByTxBufferInd
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Lock_UnlockBuffersByTxBufferInd(PduR_BmTxBufferIndRomIterType txBufferIndIdx)
{
  if(PduR_IsLockRomUsedOfBmTxBufferIndRom(txBufferIndIdx))
  {
    PduR_Lock_Unlock(PduR_GetLockRomIdxOfBmTxBufferIndRom(txBufferIndIdx));
  }
  PDUR_DUMMY_STATEMENT(txBufferIndIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: PduR_Lock.c
 *********************************************************************************************************************/
