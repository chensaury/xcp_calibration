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
/**        \file  VStdLib_Cfg.h
 *        \brief  Configuration of the generic Vector Standard Library (VStdLib_GenericAsr)
 *
 *      \details  The generic Vector Standard Library provides a hardware independent implementation
 *                of memory manipulation services used by several MICROSAR BSW components.
 *
 *********************************************************************************************************************/

#if !defined (VSTDLIB_CFG_H)
# define VSTDLIB_CFG_H

/**
 * Additional include files
 *
 * If necessary include additional files below (e.g. if VSTDLIB_USE_LIBRARY_FUNCTIONS is defined to STD_ON).
 */
/* # include ... */

/**********************************************************************************************************************
 *  General configuration
 *********************************************************************************************************************/

/**
 * VSTDLIB_USE_LIBRARY_FUNCTIONS
 *
 * If set to STD_ON all memory manipulation routines are mapped to external functions (e.g. compiler libraries or other
 * implementations that are optimized for the target platform). This is recommended when using 16bit MCUs for example
 * as the generic VStdLib implementation provides optimized routines only for 32bit platforms.
 *
 * Values:
 * STD_ON  - Use external memory manipulation functions - requires additional configuration, see below.
 * STD_OFF - Use generic memory manipulation functions provided by VStdLib
 *
 * Default:
 * STD_OFF
 */
# define VSTDLIB_USE_LIBRARY_FUNCTIONS STD_OFF

/**
 * VSTDLIB_RUNTIME_OPTIMIZATION
 *
 * If set to STD_ON optimized routines are used to increase the performance of the memory manipulation functions.
 * The setting if this define is only relevant if VSTDLIB_USE_LIBRARY_FUNCTIONS == STD_OFF.
 *
 * Values:
 * STD_ON  - Use optimized routines for memory operations (runtime efficient, but increases code size)
 * STD_OFF - Use simple routines for memory operations (code efficient, but significantly increases runtime)
 *
 * Default:
 * STD_ON
 */
# define VSTDLIB_RUNTIME_OPTIMIZATION STD_ON

/**
 * VSTDLIB_USE_JUMPTABLES
 *
 * If set to STD_ON jump tables are used to increase the performance of the memory manipulation functions.
 * The setting of this define is only relevant if VSTDLIB_USE_LIBRARY_FUNCTIONS == STD_OFF and
 * VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON.
 *
 * Values:
 * STD_ON  - Use jump tables for memory operations (runtime efficient in general, but may depend on compiler)
 * STD_OFF - Use loops for memory operations (code efficient, also use this if the compiler generates no efficient 
 *           code for the jump tables)
 *
 * Default:
 * STD_ON
 */
# define VSTDLIB_USE_JUMPTABLES STD_ON

/**
 * VSTDLIB_DEV_ERROR_DETECT
 *
 * If set to STD_ON the development error detection is enabled. In this case the pointer arguments of all global
 * module functions are checked. If any NULL_PTR is passed, these functions return without performing any action.
 * Please note that this setting is only relevant for development error detection and has no influence on
 * MICROSAR SafeBSW.
 *
 * Values:
 * STD_ON  - Check function arguments
 * STD_OFF - Disable development error detection
 *
 * Default:
 * STD_OFF
 */
# define VSTDLIB_DEV_ERROR_DETECT STD_OFF

/**
 * VSTDLIB_DEV_ERROR_REPORT
 *
 * If set to STD_ON the development error reporting is enabled. In this case Det_ReportError() is called if any
 * development error is detected.
 *
 * Values:
 * STD_ON  - Enable calls of Det_ReportError() - requires VSTDLIB_DEV_ERROR_DETECT also to be defined to STD_ON
 * STD_OFF - Disable development error reporting
 *
 * Default:
 * STD_OFF
 */
# define VSTDLIB_DEV_ERROR_REPORT STD_OFF

/**
 * VSTDLIB_VERSION_INFO_API
 *
 * If set to STD_ON the API VStdLib_GetVersionInfo() is provided.
 *
 * Values:
 * STD_ON  - Provide the version info API
 * STD_OFF - Do not provide the version info API
 *
 * Default:
 * STD_OFF
 */
# define VSTDLIB_VERSION_INFO_API STD_OFF

/**
 * VSTDLIB_DUMMY_STATEMENT
 *
 * Expression that is used for dummy statements to avoid compile warnings about unused identifiers.
 *
 * Example values:
 * (void)(v)
 * (v)=(v)
 * or leave the definition empty to disable the usage of dummy statements
 *
 * Default:
 * (void)(v)
 */
# define VSTDLIB_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  Additional configuration if VSTDLIB_USE_LIBRARY_FUNCTIONS == STD_ON
 *********************************************************************************************************************/

# if (VSTDLIB_USE_LIBRARY_FUNCTIONS == STD_ON)
/**
 * Memory manipulation library functions.
 *
 * If VSTDLIB_USE_LIBRARY_FUNCTIONS is set to STD_ON it is necessary to specify memory manipulation functions by
 * overwriting the definitions below. The error directive has to be removed.
 * 
 * NOTE:
 * - If the external functionality is not able to handle more than 65535 bytes it is necessary to define
 *   VSTDLIB_SUPPORT_LARGE_DATA to STD_OFF.
 * - It has to be ensured that the specified functions are able to copy from and to all memory locations independently
 *   of the pointer length. The specified functions must behave synchronously.
 */
#  error "Verify the setting for VSTDLIB_SUPPORT_LARGE_DATA and fill the macros in this section with correct values!"

#  define VSTDLIB_SUPPORT_LARGE_DATA             STD_ON

/* PRQA S 3453 FUNCTION_LIKE_MACRO */ /* MD_VStdLib_3453 */

/* Set nCnt bytes to zero at pDst (any alignment) */
#  define VStdLib_MemClr(pDst, nCnt)             memset((pDst), 0, (nCnt))

/* Set nCnt bytes to the character nPattern at pDst (any alignment) */
#  define VStdLib_MemSet(pDst, nPattern, nCnt)   memset((pDst), (nPattern), (nCnt))

/* Copy nCnt bytes from pSrc to pDst (any alignment) */
#  define VStdLib_MemCpy(pDst, pSrc, nCnt)       memcpy((pDst), (pSrc), (nCnt))

/* Copy nCnt 16bit blocks from pSrc to pDst (both pointers 16-bit aligned) */
#  define VStdLib_MemCpy16(pDst, pSrc, nCnt)     memcpy((pDst), (pSrc), ((nCnt)<<1))

/* Copy nCnt 32bit blocks from pSrc to pDst (both pointers 32-bit aligned) */
#  define VStdLib_MemCpy32(pDst, pSrc, nCnt)     memcpy((pDst), (pSrc), ((nCnt)<<2))

/* PRQA L:FUNCTION_LIKE_MACRO */

# endif /* VSTDLIB_USE_LIBRARY_FUNCTIONS == STD_ON */

/**********************************************************************************************************************
 * Compatibility for legacy Vector modules - can be ignored in general
 *********************************************************************************************************************/

# if defined(VSTD_ENABLE_INTCTRL_HANDLING) || defined(VSTD_ENABLE_DEFAULT_INTCTRL) || \
     defined(VSTD_ENABLE_OSEK_INTCTRL) || defined(VSTD_ENABLE_APPL_INTCTRL)
/**
 * Compatibility for legacy Vector modules.
 *
 * Legacy Vector modules that are used in a MICROSAR stack might rely on interrupt handling functionalities that
 * are no longer supported by VStdLib. Map relevant calls to functionalities that are provided by the MICROSAR stack
 * or application. VStdSuspendAllInterrupts() and VStdResumeAllInterrupts() can be mapped to an exclusive area that
 * is provided by the BSW scheduler for example.
 */
#  error "VStdLib_GenericAsr does not support interrupt control handling!"

# endif

/**********************************************************************************************************************
 *  Do not modify anything below
 *********************************************************************************************************************/

# define VSTDLIB_CFG_MAJOR_VERSION     (2u)
# define VSTDLIB_CFG_MINOR_VERSION     (0u)

#endif /* VSTDLIB_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: VStdLib_Cfg.h
 *********************************************************************************************************************/
