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
/**        \file  vstdlib.h
 *        \brief  Interface of the generic Vector Standard Library (VStdLib_GenericAsr)
 *
 *      \details  The generic Vector Standard Library provides a hardware independent implementation
 *                of memory manipulation services used by several MICROSAR BSW components.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Timo Vanoni                   vistvi        Vector Informatik GmbH
 *  Torsten Kercher               vistkr        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id      Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2012-05-08  vistvi                 Creation
 *  01.00.01  2013-09-04  vistvi  ESCAN00064708: Inconsistent file names
 *  01.01.00  2013-12-10  vistvi  ESCAN00073131: MISRA Improvements
 *  02.00.00  2015-01-12  vistkr  ESCAN00080277: FEAT-427: SafeBSW Step I
 *                                ESCAN00081720: Extended version check is not available for MSR4
 *            2015-05-04  vistkr  ESCAN00081765: FEAT-1275: SafeBSW Step 2
 *                                ESCAN00082267: FEAT-1379: Optimized copy operation for large data
 *  02.00.01  2015-12-02  vistkr  ESCAN00086942: Compiler error: Last line of file ends without a newline
 *  02.00.02  2016-04-14  vistkr  ESCAN00089506: Remove trace links for memory manipulation services
 *********************************************************************************************************************/

#if !defined (VSTDLIB_H)
# define VSTDLIB_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Std_Types.h"

# include "VStdLib_Cfg.h"

/**********************************************************************************************************************
 * CONFIGURATION CHECK
 *********************************************************************************************************************/

# if !defined (VSTDLIB_USE_LIBRARY_FUNCTIONS)
#  error "VSTDLIB_USE_LIBRARY_FUNCTIONS has to be defined.. check VStdLib_Cfg.h!"
# endif

# if (VSTDLIB_USE_LIBRARY_FUNCTIONS == STD_ON)
#  if (!defined (VStdLib_MemClr) || !defined (VStdLib_MemSet) || !defined (VStdLib_MemCpy) || \
       !defined (VStdLib_MemCpy16) || !defined (VStdLib_MemCpy32))
#   error "VStdLib_MemClr, VStdLib_MemSet, VStdLib_MemCpy, VStdLib_MemCpy16 and VStdLib_MemCpy32 have to be defined!"
#  endif
# endif

# if !defined (VSTDLIB_RUNTIME_OPTIMIZATION)
#  error "VSTDLIB_RUNTIME_OPTIMIZATION has to be defined.. check VStdLib_Cfg.h!"
# endif

# if !defined (VSTDLIB_USE_JUMPTABLES)
#  error "VSTDLIB_USE_JUMPTABLES has to be defined.. check VStdLib_Cfg.h!"
# endif

# if !defined (VSTDLIB_DEV_ERROR_DETECT)
#  error "VSTDLIB_DEV_ERROR_DETECT has to be defined.. check VStdLib_Cfg.h!"
# endif

# if !defined (VSTDLIB_DEV_ERROR_REPORT)
#  error "VSTDLIB_DEV_ERROR_REPORT has to be defined.. check VStdLib_Cfg.h!"
# endif

# if ((VSTDLIB_DEV_ERROR_REPORT == STD_ON) && (VSTDLIB_DEV_ERROR_DETECT != STD_ON))
#  error "VSTDLIB_DEV_ERROR_REPORT defined to STD_ON requires VSTDLIB_DEV_ERROR_DETECT also to be defined to STD_ON!"
# endif

# if !defined (VSTDLIB_VERSION_INFO_API)
#  error "VSTDLIB_VERSION_INFO_API has to be defined.. check VStdLib_Cfg.h!"
# endif

# if !defined (VSTDLIB_DUMMY_STATEMENT)
#  error "VSTDLIB_DUMMY_STATEMENT has to be defined.. check VStdLib_Cfg.h!"
# endif

# if !defined (VSTDLIB_CFG_MAJOR_VERSION)
#  error "VSTDLIB_CFG_MAJOR_VERSION has to be defined.. check VStdLib_Cfg.h!"
# endif

# if !defined (VSTDLIB_CFG_MINOR_VERSION)
#  error "VSTDLIB_CFG_MINOR_VERSION has to be defined.. check VStdLib_Cfg.h!"
# endif

/* Large data support */
# if !defined (VSTDLIB_SUPPORT_LARGE_DATA)
#  define VSTDLIB_SUPPORT_LARGE_DATA         STD_ON
# endif

# if (VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON)
#  if ((VSTDLIB_SUPPORT_LARGE_DATA != STD_ON) && (VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON))
#   error "VSTDLIB_RUNTIME_OPTIMIZATION must not be enabled if large data support is not given!"
#  endif
# endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define VSTDLIB_VENDOR_ID                   (30u)
# define VSTDLIB_MODULE_ID                   (255u)

/* Component version information (decimal version of ALM implementation package) */
# define VSTDLIB_SW_MAJOR_VERSION            (2u)
# define VSTDLIB_SW_MINOR_VERSION            (0u)
# define VSTDLIB_SW_PATCH_VERSION            (2u)

# if !defined (VSTDLIB_INSTANCE_ID_DET)
#  define VSTDLIB_INSTANCE_ID_DET            (0u)
# endif

/* API service IDs */
# define VSTDLIB_SID_MEM_SET                 (0x00u) /*!< Service ID: VStdLib_MemClr(), VStdLib_MemSet() */
# define VSTDLIB_SID_MEM_COPY                (0x01u) /*!< Service ID: VStdLib_MemCpy() */
# define VSTDLIB_SID_MEM_COPY_16             (0x02u) /*!< Service ID: VStdLib_MemCpy16() */
# define VSTDLIB_SID_MEM_COPY_32             (0x03u) /*!< Service ID: VStdLib_MemCpy32() */
# define VSTDLIB_SID_MEM_COPY_S              (0x04u) /*!< Service ID: VStdLib_MemCpy_s() */
# define VSTDLIB_SID_GET_VERSION_INFO        (0x05u) /*!< Service ID: VStdLib_GetVersionInfo() */

/* Error codes */
# define VSTDLIB_E_NO_ERROR                  (0x00u) /*!< Used to check if no error occurred */
# define VSTDLIB_E_PARAM_POINTER             (0x01u) /*!< Error code: API used with invalid pointer parameter (NULL) */
# define VSTDLIB_E_PARAM_SIZE                (0x02u) /*!< Error code: VStdLib_MemCpy_s() used with invalid dst size */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES
 *********************************************************************************************************************/

/*! Data type for nCnt API parameters */
# if (VSTDLIB_SUPPORT_LARGE_DATA == STD_ON)
typedef uint32_least VStdLib_CntType;
# else
typedef uint16_least VStdLib_CntType;
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS (MACRO API)
 *********************************************************************************************************************/

/* PRQA S 3453 VSTDLIB_FUNCTION_LIKE_MACRO */ /* MD_VStdLib_3453 */

# if (VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON)

/**********************************************************************************************************************
 *  VStdLib_MemClr()
 *********************************************************************************************************************/
/*! \brief       Initializes memory to zero.
 *  \details     Sets nCnt bytes starting at pDst to zero.
 *  \param[out]  pDst          Pointer to the memory location to be initialized, must not be NULL.
 *  \param[in]   nCnt          Number of bytes to initialize, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      This service is implemented externally if VSTDLIB_USE_LIBRARY_FUNCTIONS == STD_ON,
 *               else it is realized by a call to VStdLib_MemSet() with 'nPattern' == 0.
 *               The compatible definition VStdLib_MemClrLarge() exists additionally (and solely)
 *               if VSTDLIB_SUPPORT_LARGE_DATA == STD_ON.
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
#  define VStdLib_MemClr(pDst, nCnt)                       VStdLib_MemSet((pDst), 0, (nCnt))

# endif /* VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON */

# if (VSTDLIB_SUPPORT_LARGE_DATA == STD_ON)

/**********************************************************************************************************************
 *  VStdLib_MemClrLarge()
 *********************************************************************************************************************/
/*! \brief       Initializes memory to zero.
 *  \details     Sets nCnt bytes starting at pDst to zero.
 *  \param[out]  pDst          Pointer to the memory location to be initialized, must not be NULL.
 *  \param[in]   nCnt          Number of bytes to initialize, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      VSTDLIB_SUPPORT_LARGE_DATA == STD_ON
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
#  define VStdLib_MemClrLarge(pDst, nCnt)                    VStdLib_MemClr((pDst), (nCnt))

/**********************************************************************************************************************
 *  VStdLib_MemSetLarge()
 *********************************************************************************************************************/
/*! \brief       Initializes memory to a specified pattern.
 *  \details     Sets nCnt bytes starting at pDst to the character nPattern.
 *  \param[out]  pDst          Pointer to the memory location to be initialized, must not be NULL.
 *  \param[in]   nPattern      The character to be used to initialize the memory.
 *  \param[in]   nCnt          Number of bytes to initialize, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      VSTDLIB_SUPPORT_LARGE_DATA == STD_ON
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
#  define VStdLib_MemSetLarge(pDst, nPattern, nCnt)          VStdLib_MemSet((pDst), (nPattern), (nCnt))

/**********************************************************************************************************************
 *  VStdLib_MemCpyLarge()
 *********************************************************************************************************************/
/*! \brief       Copies data from one memory location to another.
 *  \details     Copies nCnt bytes starting at pSrc to another memory location starting at pDst.
 *  \param[out]  pDst          Pointer to the memory location to copy to, must not be NULL.
 *  \param[in]   pSrc          Pointer to the memory location to copy from, must not be NULL.
 *  \param[in]   nCnt          Number of bytes to copy, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      VSTDLIB_SUPPORT_LARGE_DATA == STD_ON
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
#  define VStdLib_MemCpyLarge(pDst, pSrc, nCnt)              VStdLib_MemCpy((pDst), (pSrc), (nCnt))

/**********************************************************************************************************************
 *  VStdLib_MemCpy16Large()
 *********************************************************************************************************************/
/*! \brief       Copies data from one memory location to another.
 *  \details     Copies nCnt 16-bit blocks starting at pSrc to another memory location starting at pDst.
 *  \param[out]  pDst          Pointer to the memory location to copy to, 16-bit aligned and not NULL.
 *  \param[in]   pSrc          Pointer to the memory location to copy from, 16-bit aligned and not NULL.
 *  \param[in]   nCnt          Number of 16-bit blocks to copy, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      VSTDLIB_SUPPORT_LARGE_DATA == STD_ON
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
#  define VStdLib_MemCpy16Large(pDst, pSrc, nCnt)            VStdLib_MemCpy16((pDst), (pSrc), (nCnt))

/**********************************************************************************************************************
 *  VStdLib_MemCpy32Large()
 *********************************************************************************************************************/
/*! \brief       Copies data from one memory location to another.
 *  \details     Copies nCnt 32-bit blocks starting at pSrc to another memory location starting at pDst.
 *  \param[out]  pDst          Pointer to the memory location to copy to, 32-bit aligned and not NULL.
 *  \param[in]   pSrc          Pointer to the memory location to copy from, 32-bit aligned and not NULL.
 *  \param[in]   nCnt          Number of 32-bit blocks to copy, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      VSTDLIB_SUPPORT_LARGE_DATA == STD_ON
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
#  define VStdLib_MemCpy32Large(pDst, pSrc, nCnt)            VStdLib_MemCpy32((pDst), (pSrc), (nCnt))

/**********************************************************************************************************************
 *  VStdLib_MemCpyLarge_s()
 *********************************************************************************************************************/
/*! \brief       Verifies the destination size and copies data from one memory location to another.
 *  \details     Uses VStdLib_MemCpy() to copy nCnt bytes starting at pSrc to another memory location starting
 *               at pDst, if nDstSize is greater than or equal to nCnt.
 *  \param[out]  pDst          Pointer to the memory location to copy to, must not be NULL.
 *  \param[in]   nDstSize      Maximum number of bytes to modify in the destination (typically the size of the
 *                             destination object).
 *  \param[in]   pSrc          Pointer to the memory location to copy from, must not be NULL.
 *  \param[in]   nCnt          Number of bytes to copy.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      VSTDLIB_SUPPORT_LARGE_DATA == STD_ON
 *  \pre         The parameters 'pDst' and 'nDstSize' have to define a valid memory area.
 *********************************************************************************************************************/
#  define VStdLib_MemCpyLarge_s(pDst, nDstSize, pSrc, nCnt)  VStdLib_MemCpy_s((pDst), (nDstSize), (pSrc), (nCnt))

# endif /* VSTDLIB_SUPPORT_LARGE_DATA == STD_ON */

/* PRQA L:VSTDLIB_FUNCTION_LIKE_MACRO */

/* PRQA S 3458 BRACED_CODE_STATEMENT_BLOCK */ /* MD_MSR_19.4 */

# if !defined (VStdLib_MemClrMacro)
/**********************************************************************************************************************
 *  VStdLib_MemClrMacro()
 *********************************************************************************************************************/
/*! \brief       Initializes memory to zero (macro implementation).
 *  \details     Sets nCnt blocks starting at pDst to zero (block-size is given by the type of pDst).
 *  \param[out]  pDst          Any typed pointer to the memory location to be initialized, must be aligned
 *                             corresponding to its type and not be NULL.
 *  \param[in]   nCnt          Number of blocks to initialize, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
#  define VStdLib_MemClrMacro(pDst, nCnt) \
    { VStdLib_CntType __i; for ( __i = 0u; __i < (nCnt); ++__i) { (pDst)[__i] = 0; } } \
    /* SBSW_VSTDLIB_ACCESS_LOOP */
# endif

# if !defined (VStdLib_MemSetMacro)
/**********************************************************************************************************************
 *  VStdLib_MemSetMacro()
 *********************************************************************************************************************/
/*! \brief       Initializes memory to a specified pattern (macro implementation).
 *  \details     Sets nCnt blocks starting at pDst to nPattern (block-size is given by the type of pDst).
 *  \param[out]  pDst          Any typed pointer to the memory location to be initialized, must be aligned
 *                             corresponding to its type and not be NULL.
 *  \param[in]   nPattern      The pattern to be used to initialize the memory (consider the correlation between its
 *                             type and the type of pDst).
 *  \param[in]   nCnt          Number of blocks to initialize, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
#  define VStdLib_MemSetMacro(pDst, nPattern, nCnt) \
    { VStdLib_CntType __i; for ( __i = 0u; __i < (nCnt); ++__i) { (pDst)[__i] = (nPattern); } } \
    /* SBSW_VSTDLIB_ACCESS_LOOP */
# endif

# if !defined (VStdLib_MemCpyMacro)
/**********************************************************************************************************************
 *  VStdLib_MemCpyMacro()
 *********************************************************************************************************************/
/*! \brief       Copies data from one memory location to another (macro implementation).
 *  \details     Copies nCnt blocks starting at pSrc to another memory location starting at pDst (block-size is given
 *               by the type of pDst).
 *  \param[out]  pDst          Any typed pointer to the memory location to copy to, must be aligned corresponding
 *                             to its type and not be NULL.
 *  \param[in]   pSrc          Any typed pointer to the memory location to copy from, must be aligned corresponding
 *                             to its type and not be NULL.
 *  \param[in]   nCnt          Number of blocks to copy, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
#  define VStdLib_MemCpyMacro(pDst, pSrc, nCnt) \
    { VStdLib_CntType __i; for ( __i = 0u; __i < (nCnt); ++__i) { (pDst)[__i] = (pSrc)[__i]; } } \
    /* SBSW_VSTDLIB_ACCESS_LOOP */
# endif

# if !defined (VStdLib_MemCpyMacro_s)
/**********************************************************************************************************************
 *  VStdLib_MemCpyMacro_s()
 *********************************************************************************************************************/
/*! \brief       Verifies the destination size and copies data from one memory location to another (macro
 *               implementation).
 *  \details     Uses VStdLib_MemCpyMacro() to copy nCnt blocks starting at pSrc to another memory location starting
 *               at pDst (block-size is given by the type of pDst), if nDstSize is greater than or equal to nCnt.
 *  \param[out]  pDst          Any typed pointer to the memory location to copy to, must be aligned corresponding
 *                             to its type and not be NULL.
 *  \param[in]   nDstSize      Maximum number of blocks to modify in the destination (typically the size of the
 *                             destination object).
 *  \param[in]   pSrc          Any typed pointer to the memory location to copy from, must be aligned corresponding
 *                             to its type and not be NULL.
 *  \param[in]   nCnt          Number of blocks to copy.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \pre         The parameters 'pDst' and 'nDstSize' have to define a valid memory area.
 *********************************************************************************************************************/
#  define VStdLib_MemCpyMacro_s(pDst, nDstSize, pSrc, nCnt) \
    { if ((nDstSize) >= (nCnt)) { VStdLib_MemCpyMacro((pDst), (pSrc), (nCnt)); } } \
    /* SBSW_VSTDLIB_CALL_UNMODIFIED */
# endif

/* PRQA L:BRACED_CODE_STATEMENT_BLOCK */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES (FUNCTION API)
 *********************************************************************************************************************/

# define VSTDLIB_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# if (VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON)

/**********************************************************************************************************************
 *  VStdLib_MemSet()
 *********************************************************************************************************************/
/*! \brief       Initializes memory to a specified pattern.
 *  \details     Sets nCnt bytes starting at pDst to the character nPattern.
 *  \param[out]  pDst          Pointer to the memory location to be initialized, must not be NULL.
 *  \param[in]   nPattern      The character to be used to initialize the memory.
 *  \param[in]   nCnt          Number of bytes to initialize, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      This service is implemented externally if VSTDLIB_USE_LIBRARY_FUNCTIONS == STD_ON.
 *               The compatible definition VStdLib_MemSetLarge() exists additionally (and solely)
 *               if VSTDLIB_SUPPORT_LARGE_DATA == STD_ON.
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
FUNC(void, VSTDLIB_CODE) VStdLib_MemSet(P2VAR(void, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                        uint8 nPattern,
                                        VStdLib_CntType nCnt);

/**********************************************************************************************************************
 *  VStdLib_MemCpy()
 *********************************************************************************************************************/
/*! \brief       Copies data from one memory location to another.
 *  \details     Copies nCnt bytes starting at pSrc to another memory location starting at pDst.
 *  \param[out]  pDst          Pointer to the memory location to copy to, must not be NULL.
 *  \param[in]   pSrc          Pointer to the memory location to copy from, must not be NULL.
 *  \param[in]   nCnt          Number of bytes to copy, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      This service is implemented externally if VSTDLIB_USE_LIBRARY_FUNCTIONS == STD_ON.
 *               The compatible definition VStdLib_MemCpyLarge() exists additionally (and solely)
 *               if VSTDLIB_SUPPORT_LARGE_DATA == STD_ON.
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
FUNC(void, VSTDLIB_CODE) VStdLib_MemCpy(P2VAR(void, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                        P2CONST(void, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc,
                                        VStdLib_CntType nCnt);


/**********************************************************************************************************************
 *  VStdLib_MemCpy16()
 *********************************************************************************************************************/
/*! \brief       Copies data from one memory location to another.
 *  \details     Copies nCnt 16-bit blocks starting at pSrc to another memory location starting at pDst.
 *  \param[out]  pDst          Pointer to the memory location to copy to, 16-bit aligned and not NULL.
 *  \param[in]   pSrc          Pointer to the memory location to copy from, 16-bit aligned and not NULL.
 *  \param[in]   nCnt          Number of 16-bit blocks to copy, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      This service is implemented externally if VSTDLIB_USE_LIBRARY_FUNCTIONS == STD_ON.
 *               The compatible definition VStdLib_MemCpy16Large() exists additionally (and solely)
 *               if VSTDLIB_SUPPORT_LARGE_DATA == STD_ON.
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
FUNC(void, VSTDLIB_CODE) VStdLib_MemCpy16(P2VAR(uint16, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                          P2CONST(uint16, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc,
                                          VStdLib_CntType nCnt);

/**********************************************************************************************************************
 *  VStdLib_MemCpy32()
 *********************************************************************************************************************/
/*! \brief       Copies data from one memory location to another.
 *  \details     Copies nCnt 32-bit blocks starting at pSrc to another memory location starting at pDst.
 *  \param[out]  pDst          Pointer to the memory location to copy to, 32-bit aligned and not NULL.
 *  \param[in]   pSrc          Pointer to the memory location to copy from, 32-bit aligned and not NULL.
 *  \param[in]   nCnt          Number of 32-bit blocks to copy, pDst must be valid for this amount.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      This service is implemented externally if VSTDLIB_USE_LIBRARY_FUNCTIONS == STD_ON.
 *               The compatible definition VStdLib_MemCpy32Large() exists additionally (and solely)
 *               if VSTDLIB_SUPPORT_LARGE_DATA == STD_ON.
 *  \pre         The parameters 'pDst' and 'nCnt' have to define a valid memory area.
 *********************************************************************************************************************/
FUNC(void, VSTDLIB_CODE) VStdLib_MemCpy32(P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                          P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc,
                                          VStdLib_CntType nCnt);

# endif /* VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON */

/**********************************************************************************************************************
 *  VStdLib_MemCpy_s()
 *********************************************************************************************************************/
/*! \brief       Verifies the destination size and copies data from one memory location to another.
 *  \details     Uses VStdLib_MemCpy() to copy nCnt bytes starting at pSrc to another memory location starting
 *               at pDst, if nDstSize is greater than or equal to nCnt.
 *  \param[out]  pDst          Pointer to the memory location to copy to, must not be NULL.
 *  \param[in]   nDstSize      Maximum number of bytes to modify in the destination (typically the size of the
 *                             destination object).
 *  \param[in]   pSrc          Pointer to the memory location to copy from, must not be NULL.
 *  \param[in]   nCnt          Number of bytes to copy.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      The compatible definition VStdLib_MemCpyLarge_s() exists additionally (and solely)
 *               if VSTDLIB_SUPPORT_LARGE_DATA == STD_ON.
 *  \pre         The parameters 'pDst' and 'nDstSize' have to define a valid memory area.
 *********************************************************************************************************************/
FUNC(void, VSTDLIB_CODE) VStdLib_MemCpy_s(P2VAR(void, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                          VStdLib_CntType nDstSize,
                                          P2CONST(void, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc,
                                          VStdLib_CntType nCnt);

# if (VSTDLIB_VERSION_INFO_API == STD_ON)

/**********************************************************************************************************************
 *  VStdLib_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information of this module.
 *  \details     Returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  versioninfo   Pointer to where to store the version information, must not be NULL.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      VSTDLIB_VERSION_INFO_API == STD_ON
 *  \pre         The parameter 'versioninfo' has to be valid and reference an object of type Std_VersionInfoType.
 *  \trace       CREQ-1016
 *********************************************************************************************************************/
FUNC(void, VSTDLIB_CODE) VStdLib_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VSTDLIB_APPL_VAR) versioninfo);

# endif /* VSTDLIB_VERSION_INFO_API == STD_ON */

# define VSTDLIB_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  COMPATIBILITY MACROS
 *********************************************************************************************************************/

# define VSTDLIB__COREHLL_VERSION            (0x0308u) /* last core version this branch was based on */
# define VSTDLIB__COREHLL_RELEASE_VERSION    (0x00u)
# define VSTDLIB_GENERICASR_VERSION          ((VSTDLIB_SW_MAJOR_VERSION << 8u) | VSTDLIB_SW_MINOR_VERSION)
# define VSTDLIB_GENERICASR_RELEASE_VERSION  VSTDLIB_SW_PATCH_VERSION
# define kVStdMainVersion                    VSTDLIB_SW_MAJOR_VERSION
# define kVStdSubVersion                     VSTDLIB_SW_MINOR_VERSION
# define kVStdReleaseVersion                 VSTDLIB_SW_PATCH_VERSION

# define kVStdErrorIntDisableTooOften        (0x01u)
# define kVStdErrorIntRestoreTooOften        (0x02u)
# define kVStdErrorMemClrInvalidParameter    (0x03u)
# define kVStdErrorMemCpyInvalidParameter    (0x04u)
# define kVStdErrorFunctionNotSupportedByHw  (0x05u)
# define kVStdErrorMemSetInvalidParameter    (0x06u)
# define kVStdErrorUnexpectedLockState       (0x07u)

# define VSTD_HL_DISABLE_SUPPORT_MEM_FCT
# define VSTD_HL_DISABLE_MEM_FCT_MAPPING
# define VSTD_HL_USE_VSTD_MEMCLR
# define VSTD_HL_USE_VSTD_MEMSET
# define VSTD_HL_USE_VSTD_RAMMEMCPY
# define VSTD_HL_USE_VSTD_ROMMEMCPY
# define VSTD_HL_USE_VSTD_WORD_MEMCPY
# define VSTD_HL_USE_VSTD_DWORD_MEMCPY

# define VStdInitPowerOn()

/* PRQA S 3453 VSTDLIB_FUNCTION_LIKE_MACRO */ /* MD_VStdLib_3453 */

# if !defined (VStdLib_MemCpyRom)
#  define VStdLib_MemCpyRom(d, s, c)         VStdLib_MemCpy((d), (s), (c))
# endif

# define VStdMemClr(d, c)                    VStdLib_MemClr((d), (c))
# define VStdMemNearClr(d, c)                VStdLib_MemClr((d), (c))
# define VStdMemFarClr(d, c)                 VStdLib_MemClr((d), (c))
# define VStdMemSet(d, p, c)                 VStdLib_MemSet((d), (p), (c))
# define VStdMemNearSet(d, p, c)             VStdLib_MemSet((d), (p), (c))
# define VStdMemFarSet(d, p, c)              VStdLib_MemSet((d), (p), (c))

# define VStdMemCpy(d, s, c)                 VStdLib_MemCpy((d), (s), (c))
# define VStdMemCpyRom(d, s, c)              VStdLib_MemCpyRom((d), (s), (c))
# define VStdMemCpyRamToRam(d, s, c)         VStdLib_MemCpy((d), (s), (c))
# define VStdMemCpyRomToRam(d, s, c)         VStdLib_MemCpyRom((d), (s), (c))
# define VStdMemCpyRamToNearRam(d, s, c)     VStdLib_MemCpy((d), (s), (c))
# define VStdMemCpyRomToNearRam(d, s, c)     VStdLib_MemCpyRom((d), (s), (c))
# define VStdMemCpyRamToFarRam(d, s, c)      VStdLib_MemCpy((d), (s), (c))
# define VStdMemCpyRomToFarRam(d, s, c)      VStdLib_MemCpyRom((d), (s), (c))
# define VStdMemCpyFarRamToRam(d, s, c)      VStdLib_MemCpy((d), (s), (c))
# define VStdMemCpyFarRamToFarRam(d, s, c)   VStdLib_MemCpy((d), (s), (c))
# define VStdMemCpyFarRomToFarRam(d, s, c)   VStdLib_MemCpyRom((d), (s), (c))
# define VStdRamMemCpy(d, s, c)              VStdLib_MemCpy((d), (s), (c))
# define VStdRomMemCpy(d, s, c)              VStdLib_MemCpyRom((d), (s), (c))

# define VStdMemCpy16(d, s, c)               VStdLib_MemCpy16((d), (s), (c))
# define VStdMemCpy16RamToRam(d, s, c)       VStdLib_MemCpy16((d), (s), (c))
# define VStdMemCpy16RamToNearRam(d, s, c)   VStdLib_MemCpy16((d), (s), (c))
# define VStdMemCpy16NearRamToRam(d, s, c)   VStdLib_MemCpy16((d), (s), (c))
# define VStdMemCpy16RamToFarRam(d, s, c)    VStdLib_MemCpy16((d), (s), (c))
# define VStdMemCpy16FarRamToRam(d, s, c)    VStdLib_MemCpy16((d), (s), (c))
# define VStdRamMemCpy16(d, s, c)            VStdLib_MemCpy16((d), (s), (c))

# define VStdMemCpy32(d, s, c)               VStdLib_MemCpy32((d), (s), (c))
# define VStdMemCpy32RamToRam(d, s, c)       VStdLib_MemCpy32((d), (s), (c))
# define VStdMemCpy32RamToNearRam(d, s, c)   VStdLib_MemCpy32((d), (s), (c))
# define VStdMemCpy32NearRamToRam(d, s, c)   VStdLib_MemCpy32((d), (s), (c))
# define VStdMemCpy32RamToFarRam(d, s, c)    VStdLib_MemCpy32((d), (s), (c))
# define VStdMemCpy32FarRamToRam(d, s, c)    VStdLib_MemCpy32((d), (s), (c))
# define VStdRamMemCpy32(d, s, c)            VStdLib_MemCpy32((d), (s), (c))

# if !defined (VStdLib_MemCpyRomMacro)
#  define VStdLib_MemCpyRomMacro(d, s, c)    VStdLib_MemCpyMacro((d), (s), (c))
# endif

# define VStdMemClr_Macro(d, c)              VStdLib_MemClrMacro((d), (c))
# define VStdMemSet_Macro(d, p, c)           VStdLib_MemSetMacro((d), (p), (c))
# define VStdMemCpy_Macro(d, s, c)           VStdLib_MemCpyMacro((d), (s), (c))
# define VStdMemCpyRom_Macro(d, s, c)        VStdLib_MemCpyRomMacro((d), (s), (c))

/* PRQA L:VSTDLIB_FUNCTION_LIKE_MACRO */

#endif /* VSTDLIB_H */

/**********************************************************************************************************************
 *  END OF FILE: vstdlib.h
 *********************************************************************************************************************/
