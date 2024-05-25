/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  vstdlib.c
 *        \brief  Implementation of the generic Vector Standard Library (VStdLib_GenericAsr)
 *
 *      \details  The generic Vector Standard Library provides a hardware independent implementation
 *                of memory manipulation services used by several MICROSAR BSW components.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define VSTDLIB_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "vstdlib.h"

#if (VSTDLIB_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of the VStdLib header file */
#if (  (VSTDLIB_SW_MAJOR_VERSION != (2u)) \
    || (VSTDLIB_SW_MINOR_VERSION != (0u)) \
    || (VSTDLIB_SW_PATCH_VERSION != (2u)) )
# error "Vendor specific version numbers of vstdlib.c and vstdlib.h are inconsistent!"
#endif

/* Check the version of the configuration header file */
#if (  (VSTDLIB_CFG_MAJOR_VERSION != (2u)) \
    || (VSTDLIB_CFG_MINOR_VERSION != (0u)) )
# error "Version numbers of vstdlib.c and VStdLib_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Used to mask internal parameters to ensure an upper limit of 3, respectively 31 */
#define VSTDLIB_MASK_3               (0x03u)
#define VSTDLIB_MASK_31              (0x1Fu)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/* Return the number of bytes that are missing to the next 32-bit boundary */
#define VSTDLIB_ALIGN_OFFSET(ptr) \
  (uint8_least)((4 - (uint32_least)(ptr)) & VSTDLIB_MASK_3) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  LOCAL TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Module specific definition of LOCAL_INLINE */
#if !defined (VSTDLIB_LOCAL_INLINE)
# define VSTDLIB_LOCAL_INLINE        LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VSTDLIB_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON)
# if (VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON)

/**********************************************************************************************************************
 *  VStdLib_Loc_MemSet_8_3()
 *********************************************************************************************************************/
/*! \brief         Initializes up to 3 bytes at pDst to the character nPattern (any alignment).
 *  \details       Depending on VSTDLIB_USE_JUMPTABLES either with a jumptable or a for loop.
 *  \param[out]    pDst8         8-bit pointer to the memory location to be initialized.
 *  \param[in]     nPattern      The character to be used to initialize the memory.
 *  \param[in]     nCnt          Number of bytes to initialize, pDst must be valid for this amount.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON && VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON
 *  \pre           The parameters 'pDst8' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemSet_8_3(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  uint8 nPattern,
  uint8_least nCnt);

/**********************************************************************************************************************
 *  VStdLib_Loc_MemSet_8_31()
 *********************************************************************************************************************/
/*! \brief         Initializes up to 31 bytes at pDst to the character nPattern (any alignment).
 *  \details       Depending on VSTDLIB_USE_JUMPTABLES either with a jumptable or a for loop.
 *  \param[out]    pDst8         8-bit pointer to the memory location to be initialized.
 *  \param[in]     nPattern      The character to be used to initialize the memory.
 *  \param[in]     nCnt          Number of bytes to initialize, pDst must be valid for this amount.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON && VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON
 *  \pre           The parameters 'pDst8' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemSet_8_31(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  uint8 nPattern,
  uint8_least nCnt);

/**********************************************************************************************************************
 *  VStdLib_Loc_MemSet_32_Aligned()
 *********************************************************************************************************************/
/*! \brief         Initializes memory at pDst to the character nPattern (32-bit aligned).
 *  \details       With a for loop, the tail depending on VSTDLIB_USE_JUMPTABLES either with a jumptable or a for loop.
 *  \param[out]    pDst32        32-bit pointer to the memory location to be initialized.
 *  \param[in]     nPattern      The character to be used to initialize the memory.
 *  \param[in]     nCnt          Number of bytes to initialize, pDst must be valid for this amount.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON && VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON
 *  \pre           The parameters 'pDst32' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemSet_32_Aligned(
  P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst32,
  uint8 nPattern,
  uint32_least nCnt);

/**********************************************************************************************************************
 *  VStdLib_Loc_MemCpy_8_3()
 *********************************************************************************************************************/
/*! \brief         Copies up to 3 bytes from pSrc to pDst (any alignment).
 *  \details       Depending on VSTDLIB_USE_JUMPTABLES either with a jumptable or a for loop.
 *  \param[out]    pDst8         8-bit pointer to the memory location to copy to.
 *  \param[in]     pSrc8         8-bit pointer to the memory location to copy from.
 *  \param[in]     nCnt          Number of bytes to copy, pDst must be valid for this amount.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON && VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON
 *  \pre           The parameters 'pDst8' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_8_3(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc8,
  uint8_least nCnt);

/**********************************************************************************************************************
 *  VStdLib_Loc_MemCpy_8_31()
 *********************************************************************************************************************/
/*! \brief         Copies up to 31 bytes from pSrc to pDst (any alignment).
 *  \details       Depending on VSTDLIB_USE_JUMPTABLES either with a jumptable or a for loop.
 *  \param[out]    pDst8         8-bit pointer to the memory location to copy to.
 *  \param[in]     pSrc8         8-bit pointer to the memory location to copy from.
 *  \param[in]     nCnt          Number of bytes to copy, pDst must be valid for this amount.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON && VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON
 *  \pre           The parameters 'pDst8' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_8_31(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc8,
  uint8_least nCnt);

/**********************************************************************************************************************
 *  VStdLib_Loc_MemCpy_32_Aligned()
 *********************************************************************************************************************/
/*! \brief         Copies 32-bit aligned data from pSrc to pDst.
 *  \details       With a for loop, the tail depending on VSTDLIB_USE_JUMPTABLES either with a jumptable or a for loop.
 *  \param[out]    pDst32        32-bit pointer to the memory location to copy to.
 *  \param[in]     pSrc32        32-bit pointer to the memory location to copy from.
 *  \param[in]     nCnt          Number of bytes to copy, pDst must be valid for this amount.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON && VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON
 *  \pre           The parameters 'pDst32' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_32_Aligned(
  P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst32,
  P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc32,
  uint32_least nCnt);

/**********************************************************************************************************************
 *  VStdLib_Loc_MemCpy_8_PartialWord()
 *********************************************************************************************************************/
/*! \brief         Copies a partial word of 1 to 3 bytes from pSrc to pDst to reach a 32-bit boundary (any alignment).
 *  \details       Depending on VSTDLIB_USE_JUMPTABLES either with a jumptable or a for loop.
 *  \param[out]    pDst8         8-bit pointer to the memory location to copy to.
 *  \param[in]     nCnt          Number of bytes to copy, pDst must be valid for this amount.
 *  \param[in,out] pPrev         Word to copy from (is modified and used by caller afterwards).
 *  \param[in,out] pDPos         Index for pDst8 to copy to (is modified and used by caller afterwards).
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON && VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON
 *  \pre           The parameters 'pDst8' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_8_PartialWord(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  uint8_least nCnt,
  P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pPrev,
  P2VAR(uint32_least, AUTOMATIC, VSTDLIB_VAR_FAR) pDPos);

/**********************************************************************************************************************
 *  VStdLib_Loc_MemCpy_32_Unaligned()
 *********************************************************************************************************************/
/*! \brief         Copies data from 32-bit aligned pSrc to unaligned pDst.
 *  \details       With a for loop using 32-bit accesses, the head and tail depending on VSTDLIB_USE_JUMPTABLES either
                   with a jumptable or a for loop.
 *  \param[out]    pDst8         8-bit pointer to the memory location to copy to.
 *  \param[in]     pSrc32        32-bit pointer to the memory location to copy from.
 *  \param[in]     nCnt          Number of bytes to copy, pDst must be valid for this amount.
 *  \param[in]     nDstOffset    pDst offset to the next 32-bit boundary.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON && VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON
 *  \pre           The parameters 'pDst8' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_32_Unaligned(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc32,  
  uint32_least nCnt,
  uint8_least nDstOffset);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * VStdLib_Loc_MemSet_8_3()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemSet_8_3(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  uint8 nPattern,
  uint8_least nCnt)
{
#  if (VSTDLIB_USE_JUMPTABLES == STD_ON)

  /* #10 Initialize up to 3 bytes using a jump table */
  /* PRQA S 2003 VSTDLIB_NO_CASE_BREAK */ /* MD_VStdLib_2003 */
  switch (nCnt)
  {
    case 3:
      pDst8[2] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 2:
      pDst8[1] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 1:
      pDst8[0] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    default:
      /* nothing to do */
      break;
  }
  /* PRQA L:VSTDLIB_NO_CASE_BREAK */

#  else /* VSTDLIB_USE_JUMPTABLES == STD_OFF */

  uint8_least remaining;

  /* #20 Linearly initialize the bytes using a loop */
  for (remaining = 0; remaining < nCnt; remaining++)
  {
    pDst8[remaining] = nPattern; /* SBSW_VSTDLIB_ACCESS_LOOP */
  }

#  endif /* VSTDLIB_USE_JUMPTABLES */
} /* VStdLib_Loc_MemSet_8_3() */

/**********************************************************************************************************************
 * VStdLib_Loc_MemSet_8_31()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemSet_8_31(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  uint8 nPattern,
  uint8_least nCnt)
{
#  if (VSTDLIB_USE_JUMPTABLES == STD_ON)

  /* #10 Initialize up to 31 bytes using a jump table */
  /* PRQA S 2003 VSTDLIB_NO_CASE_BREAK */ /* MD_VStdLib_2003 */
  switch (nCnt)
  {
    case 31:
      pDst8[30] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 30:
      pDst8[29] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 29:
      pDst8[28] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 28:
      pDst8[27] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 27:
      pDst8[26] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 26:
      pDst8[25] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 25:
      pDst8[24] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 24:
      pDst8[23] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 23:
      pDst8[22] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 22:
      pDst8[21] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 21:
      pDst8[20] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 20:
      pDst8[19] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 19:
      pDst8[18] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 18:
      pDst8[17] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 17:
      pDst8[16] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 16:
      pDst8[15] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 15:
      pDst8[14] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 14:
      pDst8[13] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 13:
      pDst8[12] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 12:
      pDst8[11] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 11:
      pDst8[10] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 10:
      pDst8[9] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 9:
      pDst8[8] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 8:
      pDst8[7] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 7:
      pDst8[6] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 6:
      pDst8[5] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 5:
      pDst8[4] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 4:
      pDst8[3] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 3:
      pDst8[2] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 2:
      pDst8[1] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 1:
      pDst8[0] = nPattern; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    default:
      /* nothing to do */
      break;
  }
  /* PRQA L:VSTDLIB_NO_CASE_BREAK */

#  else /* VSTDLIB_USE_JUMPTABLES == STD_OFF */

  uint8_least remaining;

  /* #20 Linearly initialize the bytes using a loop */
  for (remaining = 0; remaining < nCnt; remaining++)
  {
    pDst8[remaining] = nPattern;  /* SBSW_VSTDLIB_ACCESS_LOOP */
  }

#  endif /* VSTDLIB_USE_JUMPTABLES */
} /* VStdLib_Loc_MemSet_8_31() */ /* PRQA S 6030 */ /* MD_VStdLib_6030 */

/**********************************************************************************************************************
 * VStdLib_Loc_MemSet_32_Aligned()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemSet_32_Aligned(
  P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst32,
  uint8 nPattern,
  uint32_least nCnt)
{
  uint32_least dPos = 0;
  uint32_least remaining;
  uint32 nPattern32 = 
    (uint32)(((uint32)nPattern << 24) | ((uint32)nPattern << 16) | ((uint32)nPattern << 8) | nPattern);

  /* #10 Linearly initialize 16-byte blocks using 32-bit accesses in a loop */
  for (remaining = nCnt; remaining >= 16; remaining -= 16)
  {
    pDst32[dPos + 0] = nPattern32; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
    pDst32[dPos + 1] = nPattern32; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
    pDst32[dPos + 2] = nPattern32; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
    pDst32[dPos + 3] = nPattern32; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
    dPos += 4;
  }

#  if (VSTDLIB_USE_JUMPTABLES == STD_ON)

  /* #20 Initialize the remaining block using a jump table */
  /* PRQA S 2003 VSTDLIB_NO_CASE_BREAK */ /* MD_VStdLib_2003 */
  switch (remaining)
  {
    case 15:
    case 14:
    case 13:
    case 12:
      pDst32[dPos] = nPattern32; /* SBSW_VSTDLIB_ACCESS_32_JUMPTABLE */
      dPos++;
      /* intentionally no break */
    case 11:
    case 10:
    case 9:
    case 8:
      pDst32[dPos] = nPattern32; /* SBSW_VSTDLIB_ACCESS_32_JUMPTABLE */
      dPos++;
      /* intentionally no break */
    case 7:
    case 6:
    case 5:
    case 4:
      pDst32[dPos] = nPattern32; /* SBSW_VSTDLIB_ACCESS_32_JUMPTABLE */
      dPos++;
      /* intentionally no break */
    case 3:
    case 2:
    case 1:
      VStdLib_Loc_MemSet_8_3( /* SBSW_VSTDLIB_CALL_REMAINING_JUMPTABLE */
        (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pDst32[dPos], /* PRQA S 0310 */ /* MD_VStdLib_0310 */
        nPattern,
        (uint8_least) (remaining & VSTDLIB_MASK_3));
      /* intentionally no break */
    default:
      /* nothing to do */
      break;
  }
  /* PRQA L:VSTDLIB_NO_CASE_BREAK */

#  else /* VSTDLIB_USE_JUMPTABLES == STD_OFF */

  /* #30 Initialize the remaining block using a byte-wise algorithm */
  VStdLib_Loc_MemSet_8_31( /* SBSW_VSTDLIB_CALL_REMAINING */
    (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pDst32[dPos], /* PRQA S 0310 */ /* MD_VStdLib_0310 */
    nPattern,
    (uint8_least) (remaining & VSTDLIB_MASK_31));

#  endif /* VSTDLIB_USE_JUMPTABLES */
} /* VStdLib_Loc_MemSet_32_Aligned() */

/**********************************************************************************************************************
 * VStdLib_Loc_MemCpy_8_3()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_8_3(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc8,
  uint8_least nCnt)
{
#  if (VSTDLIB_USE_JUMPTABLES == STD_ON)

  /* #10 Copy up to 3 bytes using a jump table */
  /* PRQA S 2003 VSTDLIB_NO_CASE_BREAK */ /* MD_VStdLib_2003 */
  switch (nCnt)
  {
    case 3:
      pDst8[2] = pSrc8[2]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 2:
      pDst8[1] = pSrc8[1]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 1:
      pDst8[0] = pSrc8[0]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    default:
      /* nothing to do */
      break;
  }
  /* PRQA L:VSTDLIB_NO_CASE_BREAK */

#  else /* VSTDLIB_USE_JUMPTABLES == STD_OFF */

  uint8_least remaining;
  
  /* #20 Linearly copy the bytes using a loop */
  for (remaining = 0; remaining < nCnt; remaining++)
  {
    pDst8[remaining] = pSrc8[remaining]; /* SBSW_VSTDLIB_ACCESS_LOOP */
  }

#  endif /* VSTDLIB_USE_JUMPTABLES */
} /* VStdLib_Loc_MemCpy_8_3() */

/**********************************************************************************************************************
 * VStdLib_Loc_MemCpy_8_31()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_8_31(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc8,
  uint8_least nCnt)
{
#  if (VSTDLIB_USE_JUMPTABLES == STD_ON)

  /* #10 Copy up to 31 bytes using a jump table */
  /* PRQA S 2003 VSTDLIB_NO_CASE_BREAK */ /* MD_VStdLib_2003 */
  switch (nCnt)
  {
    case 31:
      pDst8[30] = pSrc8[30]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 30:
      pDst8[29] = pSrc8[29]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 29:
      pDst8[28] = pSrc8[28]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 28:
      pDst8[27] = pSrc8[27]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 27:
      pDst8[26] = pSrc8[26]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 26:
      pDst8[25] = pSrc8[25]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 25:
      pDst8[24] = pSrc8[24]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 24:
      pDst8[23] = pSrc8[23]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 23:
      pDst8[22] = pSrc8[22]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 22:
      pDst8[21] = pSrc8[21]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 21:
      pDst8[20] = pSrc8[20]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 20:
      pDst8[19] = pSrc8[19]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 19:
      pDst8[18] = pSrc8[18]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 18:
      pDst8[17] = pSrc8[17]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 17:
      pDst8[16] = pSrc8[16]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 16:
      pDst8[15] = pSrc8[15]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 15:
      pDst8[14] = pSrc8[14]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 14:
      pDst8[13] = pSrc8[13]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 13:
      pDst8[12] = pSrc8[12]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 12:
      pDst8[11] = pSrc8[11]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 11:
      pDst8[10] = pSrc8[10]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 10:
      pDst8[9] = pSrc8[9]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 9:
      pDst8[8] = pSrc8[8]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 8:
      pDst8[7] = pSrc8[7]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 7:
      pDst8[6] = pSrc8[6]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 6:
      pDst8[5] = pSrc8[5]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 5:
      pDst8[4] = pSrc8[4]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 4:
      pDst8[3] = pSrc8[3]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 3:
      pDst8[2] = pSrc8[2]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 2:
      pDst8[1] = pSrc8[1]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    case 1:
      pDst8[0] = pSrc8[0]; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      /* intentionally no break */
    default:
      /* nothing to do */
      break;
  }
  /* PRQA L:VSTDLIB_NO_CASE_BREAK */

#  else /* VSTDLIB_USE_JUMPTABLES == STD_OFF */

  uint8_least remaining;

  /* #20 Linearly copy the bytes using a loop */
  for (remaining = 0; remaining < nCnt; remaining++)
  {
    pDst8[remaining] = pSrc8[remaining]; /* SBSW_VSTDLIB_ACCESS_LOOP */
  }

#  endif /* VSTDLIB_USE_JUMPTABLES */
} /* VStdLib_Loc_MemCpy_8_31() */ /* PRQA S 6030 */ /* MD_VStdLib_6030 */

/**********************************************************************************************************************
 * VStdLib_Loc_MemCpy_32_Aligned()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_32_Aligned(
  P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst32,
  P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc32,
  uint32_least nCnt)
{
  uint32_least dPos = 0; /* == sPos */
  uint32_least remaining;
  uint32 x0, x1, x2, x3;

  /* #10 Linearly copy 16-byte blocks using 32-bit accesses in a loop */
  for (remaining = nCnt; remaining >= 16; remaining -= 16)
  {
    x0 = pSrc32[dPos + 0];
    x1 = pSrc32[dPos + 1];
    x2 = pSrc32[dPos + 2];
    x3 = pSrc32[dPos + 3];
    pDst32[dPos + 0] = x0; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
    pDst32[dPos + 1] = x1; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
    pDst32[dPos + 2] = x2; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
    pDst32[dPos + 3] = x3; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
    dPos += 4;
  }

#  if (VSTDLIB_USE_JUMPTABLES == STD_ON)

  /* #20 Copy the remaining block using a jump table */
  /* PRQA S 2003 VSTDLIB_NO_CASE_BREAK */ /* MD_VStdLib_2003 */
  switch (remaining)
  {
    case 15:
    case 14:
    case 13:
    case 12:
      pDst32[dPos] = pSrc32[dPos]; /* SBSW_VSTDLIB_ACCESS_32_JUMPTABLE */
      dPos++;
      /* intentionally no break */
    case 11:
    case 10:
    case 9:
    case 8:
      pDst32[dPos] = pSrc32[dPos]; /* SBSW_VSTDLIB_ACCESS_32_JUMPTABLE */
      dPos++;
      /* intentionally no break */
    case 7:
    case 6:
    case 5:
    case 4:
      pDst32[dPos] = pSrc32[dPos]; /* SBSW_VSTDLIB_ACCESS_32_JUMPTABLE */
      dPos++;
      /* intentionally no break */
    case 3:
    case 2:
    case 1:
      VStdLib_Loc_MemCpy_8_3( /* SBSW_VSTDLIB_CALL_REMAINING_JUMPTABLE */
        (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pDst32[dPos], /* PRQA S 0310 */ /* MD_VStdLib_0310 */
        (P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pSrc32[dPos], /* PRQA S 0310 */ /* MD_VStdLib_0310 */
        (uint8_least) (remaining & VSTDLIB_MASK_3));
      /* intentionally no break */
    default:
      /* nothing to do */
      break;
  }
  /* PRQA L:VSTDLIB_NO_CASE_BREAK */

#  else /* VSTDLIB_USE_JUMPTABLES == STD_OFF */

  /* #30 Copy the remaining block using a byte-wise algorithm */
  VStdLib_Loc_MemCpy_8_31( /* SBSW_VSTDLIB_CALL_REMAINING */
    (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pDst32[dPos], /* PRQA S 0310 */ /* MD_VStdLib_0310 */
    (P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pSrc32[dPos], /* PRQA S 0310 */ /* MD_VStdLib_0310 */
    (uint8_least) (remaining & VSTDLIB_MASK_31));

#  endif /* VSTDLIB_USE_JUMPTABLES */
} /* VStdLib_Loc_MemCpy_32_Aligned() */

/**********************************************************************************************************************
 * VStdLib_Loc_MemCpy_8_PartialWord()
 *********************************************************************************************************************/
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
 */
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_8_PartialWord(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  uint8_least nCnt,
  P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pPrev,
  P2VAR(uint32_least, AUTOMATIC, VSTDLIB_VAR_FAR) pDPos)
{
#  if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
#   if (VSTDLIB_USE_JUMPTABLES == STD_ON)

  /* #10 Copy 1 to 3 bytes using a jump table and adapt '*pDPos' and '*pPrev' for little endian byte order */
  /* PRQA S 2003 VSTDLIB_NO_CASE_BREAK */ /* MD_VStdLib_2003 */
  switch (nCnt)
  {
    case 3:
      pDst8[*pDPos] = (uint8) *pPrev; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      (*pDPos)++; /* SBSW_VSTDLIB_ACCESS_LOCAL */
      (*pPrev) >>= 8; /* SBSW_VSTDLIB_ACCESS_LOCAL */
      /* intentionally no break */
    case 2:
      pDst8[*pDPos] = (uint8) *pPrev; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      (*pDPos)++; /* SBSW_VSTDLIB_ACCESS_LOCAL */
      (*pPrev) >>= 8; /* SBSW_VSTDLIB_ACCESS_LOCAL */
      /* intentionally no break */
    default: /* case 1 - nCnt is always in range [1..3] */
      pDst8[*pDPos] = (uint8) *pPrev; /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      (*pDPos)++; /* SBSW_VSTDLIB_ACCESS_LOCAL */
      (*pPrev) >>= 8; /* SBSW_VSTDLIB_ACCESS_LOCAL */
      break;
  }
  /* PRQA L:VSTDLIB_NO_CASE_BREAK */

#   else /* VSTDLIB_USE_JUMPTABLES == STD_OFF */

  uint8_least remaining;

  /* #20 Linearly copy the bytes using a loop and adapt '*pDPos' and '*pPrev' for little endian byte order */
  for (remaining = 0; remaining < nCnt; remaining++)
  {
    pDst8[*pDPos] = (uint8) (uint8) *pPrev; /* SBSW_VSTDLIB_ACCESS_LOOP */
    (*pDPos)++; /* SBSW_VSTDLIB_ACCESS_LOCAL */
    (*pPrev) >>= 8; /* SBSW_VSTDLIB_ACCESS_LOCAL */
  }

#   endif /* VSTDLIB_USE_JUMPTABLES */
#  else /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
#   if (VSTDLIB_USE_JUMPTABLES == STD_ON)

  /* #30 Copy 1 to 3 bytes using a jump table and adapt '*pDPos' and '*pPrev' for big endian byte order */
  /* PRQA S 2003 VSTDLIB_NO_CASE_BREAK */ /* MD_VStdLib_2003 */
  switch (nCnt)
  {
    case 3:
      pDst8[*pDPos] = (uint8) ((*pPrev) >> 24); /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      (*pDPos)++; /* SBSW_VSTDLIB_ACCESS_LOCAL */
      (*pPrev) <<= 8; /* SBSW_VSTDLIB_ACCESS_LOCAL */
      /* intentionally no break */
    case 2:
      pDst8[*pDPos] = (uint8) ((*pPrev) >> 24); /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      (*pDPos)++; /* SBSW_VSTDLIB_ACCESS_LOCAL */
      (*pPrev) <<= 8; /* SBSW_VSTDLIB_ACCESS_LOCAL */
      /* intentionally no break */
    default: /* case 1 -  nCnt is always in range [1..3] */
      pDst8[*pDPos] = (uint8) ((*pPrev) >> 24); /* SBSW_VSTDLIB_ACCESS_8_JUMPTABLE */
      (*pDPos)++; /* SBSW_VSTDLIB_ACCESS_LOCAL */
      (*pPrev) <<= 8; /* SBSW_VSTDLIB_ACCESS_LOCAL */
      break;
  }
  /* PRQA L:VSTDLIB_NO_CASE_BREAK */

#   else /* VSTDLIB_USE_JUMPTABLES == STD_OFF */

  uint8_least remaining;

  /* #40 Linearly copy the bytes using a loop and adapt '*pDPos' and '*pPrev' for big endian byte order */
  for (remaining = 0; remaining < nCnt; remaining++)
  {
    pDst8[*pDPos] = (uint8) ((*pPrev) >> 24); /* SBSW_VSTDLIB_ACCESS_LOOP */
    (*pDPos)++; /* SBSW_VSTDLIB_ACCESS_LOCAL */
    (*pPrev) <<= 8; /* SBSW_VSTDLIB_ACCESS_LOCAL */
  }

#   endif /* VSTDLIB_USE_JUMPTABLES */
#  endif /* CPU_BYTE_ORDER */
} /* VStdLib_Loc_MemCpy_8_PartialWord() */

/**********************************************************************************************************************
 * VStdLib_Loc_MemCpy_32_Unaligned()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_32_Unaligned(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc32,  
  uint32_least nCnt,
  uint8_least nDstOffset)
{
  uint32_least dPos = 0;
  uint32_least sPos = 0;
  uint32_least remaining = nCnt;
  
  /* #10 If more than 32 bytes have to be copied */
  if (remaining >= 32)
  {
    P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst32;
    uint32 prev;

    /* #20 Copy the first partial word to reach the 32-bit boundary and adjust the destination pointer */
    prev = pSrc32[sPos];
    remaining -= 4;
    VStdLib_Loc_MemCpy_8_PartialWord( /* SBSW_VSTDLIB_CALL_MODIFIED_CNT */
      pDst8,
      nDstOffset,
      &prev,
      &dPos);
 
    /* At this point 'pDst8[dPos]' is aligned to a 32-bit boundary */
    pDst32 = (uint32*) &pDst8[dPos]; /* PRQA S 3305, 0310 */ /* MD_VStdLib_3305, MD_VStdLib_0310 */
    dPos = 0;
    sPos++;

    /* #30 Linearly copy 16-byte blocks using 32-bit accesses by correcting the byte displacement of dst and src */
    if (nDstOffset == 3) /* 24-bit displacement */
    {
      for (; remaining >= 16; remaining -= 16)
      {
        uint32 x0, x1, x2, x3, x4;
        x1 = pSrc32[sPos + 0];
        x2 = pSrc32[sPos + 1];
        x3 = pSrc32[sPos + 2];
        x4 = pSrc32[sPos + 3];
#  if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
        x0 = prev | (x1 << 8);
        x1 = (x1 >> 24) | (x2 << 8);
        x2 = (x2 >> 24) | (x3 << 8);
        x3 = (x3 >> 24) | (x4 << 8);
        prev = x4 >> 24;
#  else /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        x0 = prev | (x1 >> 8);
        x1 = (x1 << 24) | (x2 >> 8);
        x2 = (x2 << 24) | (x3 >> 8);
        x3 = (x3 << 24) | (x4 >> 8);
        prev = x4 << 24;
#  endif /* CPU_BYTE_ORDER */
        pDst32[dPos + 0] = x0; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
        pDst32[dPos + 1] = x1; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
        pDst32[dPos + 2] = x2; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
        pDst32[dPos + 3] = x3; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
        dPos += 4;
        sPos += 4;
      }
    }
    else if (nDstOffset == 2) /* 16-bit displacement */
    {
      for (; remaining >= 16; remaining -= 16)
      {
        uint32 x0, x1, x2, x3, x4;
        x1 = pSrc32[sPos + 0];
        x2 = pSrc32[sPos + 1];
        x3 = pSrc32[sPos + 2];
        x4 = pSrc32[sPos + 3];
#  if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
        x0 = prev | (x1 << 16);
        x1 = (x1 >> 16) | (x2 << 16);
        x2 = (x2 >> 16) | (x3 << 16);
        x3 = (x3 >> 16) | (x4 << 16);
        prev = x4 >> 16;
#  else /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        x0 = prev | (x1 >> 16);
        x1 = (x1 << 16) | (x2 >> 16);
        x2 = (x2 << 16) | (x3 >> 16);
        x3 = (x3 << 16) | (x4 >> 16);
        prev = x4 << 16;
#  endif /* CPU_BYTE_ORDER */
        pDst32[dPos + 0] = x0; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
        pDst32[dPos + 1] = x1; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
        pDst32[dPos + 2] = x2; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
        pDst32[dPos + 3] = x3; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
        dPos += 4;
        sPos += 4;
      }

    }
    else /* nDstOffset == 1 - 8-bit displacement */
    {
      for (; remaining >= 16; remaining -= 16)
      {
        uint32 x0, x1, x2, x3, x4;
        x1 = pSrc32[sPos + 0];
        x2 = pSrc32[sPos + 1];
        x3 = pSrc32[sPos + 2];
        x4 = pSrc32[sPos + 3];
#  if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
        x0 = prev | (x1 << 24);
        x1 = (x1 >> 8) | (x2 << 24);
        x2 = (x2 >> 8) | (x3 << 24);
        x3 = (x3 >> 8) | (x4 << 24);
        prev = x4 >> 8;
#  else /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        x0 = prev | (x1 >> 24);
        x1 = (x1 << 8) | (x2 >> 24);
        x2 = (x2 << 8) | (x3 >> 24);
        x3 = (x3 << 8) | (x4 >> 24);
        prev = x4 << 8;
#  endif /* CPU_BYTE_ORDER */
        pDst32[dPos + 0] = x0; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
        pDst32[dPos + 1] = x1; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
        pDst32[dPos + 2] = x2; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
        pDst32[dPos + 3] = x3; /* SBSW_VSTDLIB_ACCESS_32_LOOP */
        dPos += 4;
        sPos += 4;
      }
    }

    /* #40 Linearly copy the remaining words using a loop */
    {
      uint8_least prevShift = (nDstOffset << 3) & VSTDLIB_MASK_31;
      uint8_least xShift = 32 - prevShift;
      /* At this point remaining is < 16 byte */
      for (; remaining >= 4; remaining -= 4)
      {
        uint32 x0, x1;
        x1 = pSrc32[sPos];
#  if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
        x0 = prev | (x1 << xShift);
        prev = x1 >> prevShift;
#  else /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        x0 = prev | (x1 >> xShift);
        prev = x1 << prevShift;
#  endif /* CPU_BYTE_ORDER */
        pDst32[dPos] = x0; /* SBSW_VSTDLIB_ACCESS_32_LOOP_REMAINING */
        dPos++;
        sPos++;
      }
    }

    /* #50 Copy the remaining partial word using a byte-wise algorithm */
    pDst8 = (uint8*) &pDst32[dPos]; /* PRQA S 0310 */ /* MD_VStdLib_0310 */
    dPos = 0;
    VStdLib_Loc_MemCpy_8_PartialWord( /* SBSW_VSTDLIB_CALL_REMAINING_PARTIAL */
      pDst8,
      (4 - nDstOffset),
      &prev,
      &dPos);
  }

  /* #60 Copy the remaining bytes using a byte-wise algorithm */
  VStdLib_Loc_MemCpy_8_31( /* SBSW_VSTDLIB_CALL_REMAINING */
    &pDst8[dPos],
    (P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pSrc32[sPos], /* PRQA S 0310 */ /* MD_VStdLib_0310 */
    (uint8_least) (remaining & VSTDLIB_MASK_31));
} /* VStdLib_Loc_MemCpy_32_Unaligned() */

# endif /* VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * VStdLib_MemSet()
 *********************************************************************************************************************/
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
 */
FUNC(void, VSTDLIB_CODE) VStdLib_MemSet(P2VAR(void, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                        uint8 nPattern,
                                        VStdLib_CntType nCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  VStdLib_CntType remaining;
  uint8 errorId = VSTDLIB_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (VSTDLIB_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check parameter 'pDst' */
  if (pDst == NULL_PTR)
  {
    errorId = VSTDLIB_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
# if (VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON)

    remaining = nCnt;
    
    /* #20 If less than 32 bytes have to be initialized */
    if (remaining < 32)
    {
      /* #30 Use a byte-wise algorithm */
      VStdLib_Loc_MemSet_8_31( /* SBSW_VSTDLIB_CALL_MASKED_CNT */
        (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst,
        nPattern,
        (uint8_least) (remaining & VSTDLIB_MASK_31));
    }
    /* #40 Else */
    else
    {
      /* #50 Get the destination pointer offset to the next 32-bit boundary */
      uint8_least nDstOffset = VSTDLIB_ALIGN_OFFSET(pDst); /* PRQA S 0306 */ /* MD_VStdLib_0306 */
      
      /* #60 If the destination is not aligned */
      if (nDstOffset != 0)
      {
        /* #70 Initialize the amount of bytes to reach the boundary on 'pDst' and adjust the pointer */
        VStdLib_Loc_MemSet_8_3( /* SBSW_VSTDLIB_CALL_MODIFIED_CNT */
          (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst,
          nPattern,
          nDstOffset);

        pDst = &((P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst)[nDstOffset];
        remaining -= nDstOffset;
      }

      /* #80 The pointer is aligned, use the 32-bit aligned memset */
      VStdLib_Loc_MemSet_32_Aligned( /* SBSW_VSTDLIB_CALL_MODIFIED_PTR_CNT */
        (P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst,
        nPattern,
        remaining);
    }

# else /* VSTDLIB_RUNTIME_OPTIMIZATION == STD_OFF */

    /* #90 Linearly initialize nCnt bytes using a loop */
    for (remaining = 0; remaining < nCnt; remaining++)
    {  
      ((P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR))(pDst))[remaining] = nPattern; /* SBSW_VSTDLIB_ACCESS_LOOP */
    }

# endif /* VSTDLIB_RUNTIME_OPTIMIZATION */
  }
  
  /* ----- Development Error Report ------------------------------------- */
# if (VSTDLIB_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VSTDLIB_E_NO_ERROR)
  {
    (void) Det_ReportError(VSTDLIB_MODULE_ID, VSTDLIB_INSTANCE_ID_DET, VSTDLIB_SID_MEM_SET, errorId);
  }
# else
  VSTDLIB_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif
} /* VStdLib_MemSet() */

/**********************************************************************************************************************
 * VStdLib_MemCpy()
 *********************************************************************************************************************/
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
 *
 *
 *
 */
FUNC(void, VSTDLIB_CODE) VStdLib_MemCpy(P2VAR(void, AUTOMATIC, VSTDLIB_VAR_FAR) pDst, 
                                        P2CONST(void, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc,
                                        VStdLib_CntType nCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  VStdLib_CntType remaining;
  uint8 errorId = VSTDLIB_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (VSTDLIB_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check parameters 'pDst' and 'pSrc' */
  if ((pDst == NULL_PTR) || (pSrc == NULL_PTR))
  {
    errorId = VSTDLIB_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
# if (VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON)

    remaining = nCnt;
    
    /* #20 If less than 32 bytes have to be copied */
    if (remaining < 32)
    {
      /* #30 Use a byte-wise algorithm */
      VStdLib_Loc_MemCpy_8_31( /* SBSW_VSTDLIB_CALL_MASKED_CNT */
        (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst,
        (P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pSrc,
        (uint8_least) (remaining & VSTDLIB_MASK_31));
    }
    /* #40 Else */
    else
    {
      /* #50 Get the source pointer offset to the next 32-bit boundary */
      uint8_least nSrcOffset = VSTDLIB_ALIGN_OFFSET(pSrc); /* PRQA S 0306 */ /* MD_VStdLib_0306 */
      uint8_least nDstOffset;
      
      /* #60 If the source is not aligned */
      if (nSrcOffset != 0)
      {
        /* #70 Copy the amount of bytes to reach the boundary on 'pSrc' and adjust the pointers */
        VStdLib_Loc_MemCpy_8_3( /* SBSW_VSTDLIB_CALL_MODIFIED_CNT */
          (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst,
          (P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pSrc,
          nSrcOffset);

        pSrc = &((P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pSrc)[nSrcOffset];
        pDst = &((P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst)[nSrcOffset];
        remaining -= nSrcOffset;
      }

      /* #80 Get the destination pointer offset to the next 32-bit boundary */
      nDstOffset = VSTDLIB_ALIGN_OFFSET(pDst); /* PRQA S 0306 */ /* MD_VStdLib_0306 */
      
      /* #90 If destination is aligned */
      if (nDstOffset == 0)
      {
        /* #100 Both pointers are aligned, use the 32-bit aligned memcpy */
        VStdLib_Loc_MemCpy_32_Aligned( /* SBSW_VSTDLIB_CALL_MODIFIED_PTR_CNT */
          (P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst,
          (P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR)) pSrc,
          remaining);
      }
      /* #110 Else */
      else
      {
        /* #120 Use the 32-bit unaligned memcpy */
        VStdLib_Loc_MemCpy_32_Unaligned( /* SBSW_VSTDLIB_CALL_MODIFIED_PTR_CNT */
          (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst,
          (P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR)) pSrc,
          remaining,
          nDstOffset);
      }
    }

# else /* VSTDLIB_RUNTIME_OPTIMIZATION == STD_OFF */

    /* #130 Linearly copy nCnt bytes using a loop */
    for (remaining = 0; remaining < nCnt; remaining++)
    {  
      ((P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR))(pDst))[remaining] =  
        ((P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR))(pSrc))[remaining]; /* SBSW_VSTDLIB_ACCESS_LOOP */
    }

# endif /* VSTDLIB_RUNTIME_OPTIMIZATION */
  }
  
  /* ----- Development Error Report ------------------------------------- */
# if (VSTDLIB_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VSTDLIB_E_NO_ERROR)
  {
    (void) Det_ReportError(VSTDLIB_MODULE_ID, VSTDLIB_INSTANCE_ID_DET, VSTDLIB_SID_MEM_COPY, errorId);
  }
# else
  VSTDLIB_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif
} /* VStdLib_MemCpy() */

/**********************************************************************************************************************
 * VStdLib_MemCpy16()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VSTDLIB_CODE) VStdLib_MemCpy16(P2VAR(uint16, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                          P2CONST(uint16, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc,
                                          VStdLib_CntType nCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  VStdLib_CntType remaining;
  uint8 errorId = VSTDLIB_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (VSTDLIB_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check parameters 'pDst' and 'pSrc' */
  if ((pDst == NULL_PTR) || (pSrc == NULL_PTR))
  {
    errorId = VSTDLIB_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Linearly copy nCnt 16-bit blocks using a loop */
    for (remaining = 0; remaining < nCnt; remaining++)
    {  
      (pDst)[remaining] = (pSrc)[remaining]; /* SBSW_VSTDLIB_ACCESS_LOOP */
    }
  }
  
  /* ----- Development Error Report --------------------------------------- */
# if (VSTDLIB_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VSTDLIB_E_NO_ERROR)
  {
    (void) Det_ReportError(VSTDLIB_MODULE_ID, VSTDLIB_INSTANCE_ID_DET, VSTDLIB_SID_MEM_COPY_16, errorId);
  }
# else
  VSTDLIB_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif
} /* VStdLib_MemCpy16() */

/**********************************************************************************************************************
 * VStdLib_MemCpy32()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VSTDLIB_CODE) VStdLib_MemCpy32(P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                          P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc,
                                          VStdLib_CntType nCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  VStdLib_CntType remaining;
  uint8 errorId = VSTDLIB_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (VSTDLIB_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check parameters 'pDst' and 'pSrc' */
  if ((pDst == NULL_PTR) || (pSrc == NULL_PTR))
  {
    errorId = VSTDLIB_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Linearly copy nCnt 32-bit blocks using a loop */
    for (remaining = 0u; remaining < nCnt; remaining++)
    {  
      (pDst)[remaining] = (pSrc)[remaining]; /* SBSW_VSTDLIB_ACCESS_LOOP */
    }
  }
  
  /* ----- Development Error Report --------------------------------------- */
# if (VSTDLIB_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VSTDLIB_E_NO_ERROR)
  {
    (void) Det_ReportError(VSTDLIB_MODULE_ID, VSTDLIB_INSTANCE_ID_DET, VSTDLIB_SID_MEM_COPY_32, errorId);
  }
# else
  VSTDLIB_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif
} /* VStdLib_MemCpy32() */

#endif /* VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON */

/**********************************************************************************************************************
 * VStdLib_MemCpy_s()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VSTDLIB_CODE) VStdLib_MemCpy_s(P2VAR(void, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                          VStdLib_CntType nDstSize,
                                          P2CONST(void, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc,
                                          VStdLib_CntType nCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VSTDLIB_E_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check parameter 'nDstSize' (independently of development error detection) */
  if (nCnt > nDstSize)
  {
    errorId = VSTDLIB_E_PARAM_SIZE;
  }
  else
  {
    /* #20 Call VStdLib_MemCpy() */
    VStdLib_MemCpy(pDst, pSrc, nCnt); /* SBSW_VSTDLIB_CALL_UNMODIFIED */
  }
  
  /* ----- Development Error Report ------------------------------------- */
#if (VSTDLIB_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VSTDLIB_E_NO_ERROR)
  {
    (void) Det_ReportError(VSTDLIB_MODULE_ID, VSTDLIB_INSTANCE_ID_DET, VSTDLIB_SID_MEM_COPY_S, errorId);
  }
#else
  VSTDLIB_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif
} /* VStdLib_MemCpy_s() */

#if (VSTDLIB_VERSION_INFO_API == STD_ON)

/**********************************************************************************************************************
 *  VStdLib_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VSTDLIB_CODE) VStdLib_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VSTDLIB_APPL_VAR) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VSTDLIB_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (VSTDLIB_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check parameter 'versioninfo' */
  if (versioninfo == NULL_PTR)
  {
    errorId = VSTDLIB_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Write component data to 'versioninfo' */
    versioninfo->vendorID = VSTDLIB_VENDOR_ID;                /* SBSW_VSTDLIB_ACCESS_VERSIONINFO */
    versioninfo->moduleID = VSTDLIB_MODULE_ID;                /* SBSW_VSTDLIB_ACCESS_VERSIONINFO */
    versioninfo->sw_major_version = VSTDLIB_SW_MAJOR_VERSION; /* SBSW_VSTDLIB_ACCESS_VERSIONINFO */
    versioninfo->sw_minor_version = VSTDLIB_SW_MINOR_VERSION; /* SBSW_VSTDLIB_ACCESS_VERSIONINFO */
    versioninfo->sw_patch_version = VSTDLIB_SW_PATCH_VERSION; /* SBSW_VSTDLIB_ACCESS_VERSIONINFO */
  }

  /* ----- Development Error Report ------------------------------------- */
# if (VSTDLIB_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VSTDLIB_E_NO_ERROR)
  {
    (void) Det_ReportError(VSTDLIB_MODULE_ID, VSTDLIB_INSTANCE_ID_DET, VSTDLIB_SID_GET_VERSION_INFO, errorId);
  }
# else
  VSTDLIB_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif
} /* VStdLib_GetVersionInfo() */

#endif /* VSTDLIB_VERSION_INFO_API == STD_ON */

#define VSTDLIB_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/* Justification for module-specific MISRA deviations:

 MD_VStdLib_3453: MISRA rule 19.7
   Reason:     Mapping between internal and external API of the module is performed.
   Risk:       Resulting code is difficult to understand and may not behave as expected.
   Prevention: Code inspection and test of the different variants in the component test.

 MD_VStdLib_2003: MISRA rule 15.2
   Reason:     Break statements are omitted due to performance reasons when using jump tables.
   Risk:       Resulting code is misleading and difficult to understand.
   Prevention: Code comments, code inspection and test of the different variants in the component test.

 MD_VStdLib_0310: MISRA rule 11.4
   Reason:     Pointer is casted as different memory access sizes are utilized due to performance reasons.
   Risk:       Resulting code is difficult to understand and wrong pointer access is performed.
   Prevention: Code inspection and test of the different variants in the component test.

 MD_VStdLib_0306: MISRA rule 11.3
   Reason:     Pointer is casted to integral type in order to get the target alignment.
   Risk:       None, as only LSBs are evaluated.
   Prevention: None.

 MD_VStdLib_6030: HIS Metric thresholds
   Reason:     No separation of functionality due to performance reasons when using jump tables.
   Risk:       None, as the complexity arises from one single switch statement that is easy to understand and test.
   Prevention: None.

 MD_VStdLib_3305: Operations
   Reason:     Pointer is casted to stricter alignment due to performance reasons.
   Risk:       Illegal pointer access is performed.
   Prevention: Code inspection and test of the different variants in the component test.

*/

/* SBSW_JUSTIFICATION_BEGIN

 \ID SBSW_VSTDLIB_CALL_UNMODIFIED
   \DESCRIPTION A function is called with unmodified 'pDst' and 'nCnt' parameters.
   \COUNTERMEASURE \N The caller of the function ensures that 'pDst' and 'nCnt' are valid. These parameters are
                      passed to the callee without modifications.

 \ID SBSW_VSTDLIB_CALL_MASKED_CNT
   \DESCRIPTION A static function is called with unmodified 'pDst' and 'nCnt' parameters.
   \COUNTERMEASURE \N The caller of the function ensures that 'pDst' and 'nCnt' are valid. The variable 'remaining'
                      equals 'nCnt' which is not changed by the applied mask. Therefore 'pDst' and 'nCnt' for the
                      callee are valid.

 \ID SBSW_VSTDLIB_CALL_MODIFIED_CNT
   \DESCRIPTION A static function is called with unmodified 'pDst' parameter and a modified 'nCnt' parameter.
   \COUNTERMEASURE \N The caller of the function ensures that 'pDst' and 'nCnt' are valid. The offset value is
                      always smaller than 4 due to VSTDLIB_ALIGN_OFFSET() and 'nCnt' is 32 or higher at this point.
                      Therefore 'pDst' and 'nCnt' for the callee are valid.

 \ID SBSW_VSTDLIB_CALL_MODIFIED_PTR_CNT
   \DESCRIPTION A static function can be called with unmodified or modified 'pDst' and 'nCnt' parameters.
   \COUNTERMEASURE \N The caller of the function ensures that 'pDst' and 'nCnt' are valid. In case the function is
                      called with unmodified parameters (no pointer alignment was performed) the variable 'remaining'
                      equals 'nCnt'. Else 'pDst' is incremented by the value of 'nDstOffset' and 'remaining' is
                      decremented by the same value. Therefore 'pDst' and 'nCnt' for the callee are valid.

 \ID SBSW_VSTDLIB_ACCESS_LOOP
   \DESCRIPTION Linear memory access using a for loop.
   \COUNTERMEASURE \N The caller of this function ensures that 'pDst' and 'nCnt' are valid. The for loop ensures that
                      the loop index is always smaller than nCnt. Therefore only valid memory is accessed.
         
 \ID SBSW_VSTDLIB_ACCESS_8_JUMPTABLE
   \DESCRIPTION Linear 8-bit-access using a switch statement.
   \COUNTERMEASURE \N The caller of this function ensures that 'pDst' and 'nCnt' are valid. The constant indices are
                      always smaller than the value of 'nCnt'. Therefore only valid memory is accessed.

 \ID SBSW_VSTDLIB_ACCESS_32_LOOP
   \DESCRIPTION Linear 32-bit-access using a for loop.
   \COUNTERMEASURE \N The caller of this function ensures that 'pDst' and 'nCnt' are valid. The access index 'dPos'
                      is initialized with 0. The loop control variable 'remaining' is decremented by 16 per iteration.
                      The exit condition ensures that at least 16 bytes are valid per iteration. The access index
                      'dPos' plus constant offset ensures that exactly 16 valid bytes are accessed. 'dPos' is
                      incremented by 4 (that equals 16 bytes) after the access.

 \ID SBSW_VSTDLIB_ACCESS_32_LOOP_REMAINING
   \DESCRIPTION Linear 32-bit-access using a for loop.
   \COUNTERMEASURE \N The caller of this function ensures that 'pDst' and 'nCnt' are valid. After the for loop above
                      'remaining' bytes of valid memory start at the address that is indicated by 'dPos'. The loop
                      control variable 'remaining' is decremented by 4 per iteration. The exit condition ensures that
                      at least 4 bytes are valid per iteration. The access index 'dPos' ensures that exactly 4 valid
                      bytes are accessed. 'dPos' is incremented by 1 (that equals 4 bytes) after the access.
         
 \ID SBSW_VSTDLIB_ACCESS_32_JUMPTABLE
   \DESCRIPTION Linear 32-bit-access using a switch statement.
   \COUNTERMEASURE \N The caller of this function ensures that 'pDst' and 'nCnt' are valid. After the for loop above
                      'remaining' bytes of valid memory start at the address that is indicated by 'dPos'. The switch
                      statement ensures that an access is only made if at least 4 byte are valid. 'dPos' is
                      incremented by 4 after the access.

 \ID SBSW_VSTDLIB_CALL_REMAINING_JUMPTABLE
   \DESCRIPTION A static function is called to access the remaining bytes at the end of processing a 32-bit jump table.
   \COUNTERMEASURE \N The caller of this function ensures that 'pDst' and 'nCnt' are valid. At this point 0-3
                      bytes of valid memory (indicated by the LSBs of 'remaining') start at the address that is 
                      indicated by 'dPos'. Due to the usage of VSTDLIB_MASK_3 'pDst' and 'nCnt' for the callee are
                      valid.

 \ID SBSW_VSTDLIB_CALL_REMAINING
   \DESCRIPTION A static function is called to access the remaining bytes after 32-bit operations.
   \COUNTERMEASURE \N The caller of this function ensures that 'pDst' and 'nCnt' are valid. After the for loop above
                      'remaining' bytes of valid memory start at the address that is indicated by 'dPos'. Therefore
                      'pDst' and 'nCnt' for the callee are valid.

 \ID SBSW_VSTDLIB_CALL_REMAINING_PARTIAL
   \DESCRIPTION A static function is called to access the remaining partial word after 32-bit displacement operations.
   \COUNTERMEASURE \N The caller of this function ensures that 'pDst' and 'nCnt' are valid. At this point at least
                      (4 - 'nDstOffset') bytes of valid memory start at the address that is indicated by 'dPos'.
                      Therefore 'pDst' and 'nCnt' for the callee are valid.

 \ID SBSW_VSTDLIB_ACCESS_LOCAL
   \DESCRIPTION Access to a pointer referencing a local variable.
   \COUNTERMEASURE \N The static function VStdLib_Loc_MemCpy_8_PartialWord() is only called with valid pointers to
                      local parameters.

 \ID SBSW_VSTDLIB_ACCESS_VERSIONINFO
   \DESCRIPTION The function VStdLib_GetVersionInfo() writes to the object referenced by parameter 'versioninfo'.
   \COUNTERMEASURE \N The caller ensures that the pointer passed to the parameter 'versioninfo' is valid and references
                      an object of type Std_VersionInfoType.

SBSW_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: vstdlib.c
 *********************************************************************************************************************/
