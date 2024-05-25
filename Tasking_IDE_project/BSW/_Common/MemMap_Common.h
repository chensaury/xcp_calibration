/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 - 2017 by Vector Informatik GmbH.                                           All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples respectively
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, the liability of Vector Informatik
 *                shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MemMap_Common.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defined for all BSW modules
 *                which are used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Eugen Stripling               Seu           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id      Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.11.00  2017-07-05  Seu     ESCAN00095756  FEAT-2455: Support ASR4.2 compatible MemMap for MCALs
 *********************************************************************************************************************/
 
  
/* PRQA S 0841 MEMMAP_COMMON_0841_TAG */ /* MD_MSR_19.6 */

/* ------------------- provide compatibility to former specifications --------- */

#ifdef START_SEC_CONST_8
# define START_SEC_CONST_8BIT
# undef START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_CONST_16
# define START_SEC_CONST_16BIT
# undef START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_CONST_32
# define START_SEC_CONST_32BIT
# undef START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_CONST_64
# define START_SEC_CONST_64BIT
# undef START_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_CONST_FAST_8
# define START_SEC_CONST_FAST_8BIT
# undef START_SEC_CONST_FAST_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_CONST_FAST_16
# define START_SEC_CONST_FAST_16BIT
# undef START_SEC_CONST_FAST_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_CONST_FAST_32
# define START_SEC_CONST_FAST_32BIT
# undef START_SEC_CONST_FAST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_CONST_FAST_64
# define START_SEC_CONST_FAST_64BIT
# undef START_SEC_CONST_FAST_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_INIT_8
# define START_SEC_VAR_INIT_8BIT
# undef START_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_INIT_16
# define START_SEC_VAR_INIT_16BIT
# undef START_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_INIT_32
# define START_SEC_VAR_INIT_32BIT
# undef START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_INIT_64
# define START_SEC_VAR_INIT_64BIT
# undef START_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NO_INIT_8
# define START_SEC_VAR_NOINIT_8BIT
# undef START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NO_INIT_16
# define START_SEC_VAR_NOINIT_16BIT
# undef START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NO_INIT_32
# define START_SEC_VAR_NOINIT_32BIT
# undef START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NO_INIT_64
# define START_SEC_VAR_NOINIT_64BIT
# undef START_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NO_INIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
# undef START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_CLEARED_8
# define START_SEC_VAR_ZERO_INIT_8BIT
# undef START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_ZERO_INIT_16BIT
# undef START_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_ZERO_INIT_32BIT
# undef START_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_CLEARED_64
# define START_SEC_VAR_ZERO_INIT_64BIT
# undef START_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_CLEARED_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_INIT_8
# define START_SEC_VAR_FAST_INIT_8BIT
# undef START_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_INIT_16
# define START_SEC_VAR_FAST_INIT_16BIT
# undef START_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_INIT_32
# define START_SEC_VAR_FAST_INIT_32BIT
# undef START_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_INIT_64
# define START_SEC_VAR_FAST_INIT_64BIT
# undef START_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_NO_INIT_8
# define START_SEC_VAR_FAST_NOINIT_8BIT
# undef START_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_NO_INIT_16
# define START_SEC_VAR_FAST_NOINIT_16BIT
# undef START_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_NO_INIT_32
# define START_SEC_VAR_FAST_NOINIT_32BIT
# undef START_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_NO_INIT_64
# define START_SEC_VAR_FAST_NOINIT_64BIT
# undef START_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_CLEARED_8
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef START_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_CLEARED_16
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef START_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_CLEARED_32
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef START_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_CLEARED_64
# define START_SEC_VAR_FAST_ZERO_INIT_64BIT
# undef START_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef START_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_INIT_8
# define START_SEC_VAR_NOCACHE_INIT_8BIT
# undef START_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_INIT_16
# define START_SEC_VAR_NOCACHE_INIT_16BIT
# undef START_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_INIT_32
# define START_SEC_VAR_NOCACHE_INIT_32BIT
# undef START_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_INIT_64
# define START_SEC_VAR_NOCACHE_INIT_64BIT
# undef START_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_NO_INIT_8
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef START_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_NO_INIT_16
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef START_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_NO_INIT_32
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef START_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_NO_INIT_64
# define START_SEC_VAR_NOCACHE_NOINIT_64BIT
# undef START_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_CLEARED_8
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef START_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_CLEARED_16
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef START_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_CLEARED_32
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef START_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_CLEARED_64
# define START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
# undef START_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */

#elif defined START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */

#endif

/*------------------------------GLOBAL-SECTIONS-----------------------------*/
/* Check_1: Check code / const / data sections - 1
 * NOTE: Check all in one in order to avoid wrong usage of MemMap-abstraction! 
 */ 
#ifdef MEMMAP_DETECT_ANY_ERROR

/* CODE_SEC_OPEN combined with SEC_CODE_* sections - START */

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CODE))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CODE is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CODE_FAST))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CODE_FAST is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CODE_ISR))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CODE_ISR is still defined as well. Please remove the obsolete define!"
# endif

/* CODE_SEC_OPEN combined with SEC_CODE_* sections - END */

/* CODE_SEC_OPEN combined with SEC_CONST_* sections - START */

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_FAST_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_FAST_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_FAST_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_FAST_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_FAST_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_PBCFG))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_PBCFG is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_PBCFG_GLOBALROOT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_PBCFG_GLOBALROOT is still defined as well. Please remove the obsolete define!"
# endif

/* CODE_SEC_OPEN combined with SEC_CONST_* sections - END */

/* CODE_SEC_OPEN combined with SEC_VAR_* sections - START */

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_INIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_INIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_INIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_INIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_INIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_PBCFG))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_PBCFG is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

/* CODE_SEC_OPEN combined with SEC_VAR_* sections - END */


/* CONST_SEC_OPEN combined with SEC_CODE_* sections - START */

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CODE))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CODE is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CODE_FAST))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CODE_FAST is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CODE_ISR))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CODE_ISR is still defined as well. Please remove the obsolete define!"
# endif

/* CONST_SEC_OPEN combined with SEC_CODE_* sections - END */

/* CONST_SEC_OPEN combined with SEC_CONST_* sections - START */

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_FAST_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_FAST_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_FAST_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_FAST_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_FAST_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_PBCFG))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_PBCFG is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_PBCFG_GLOBALROOT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_PBCFG_GLOBALROOT is still defined as well. Please remove the obsolete define!"
# endif

/* CONST_SEC_OPEN combined with SEC_CONST_* sections - END */

/* CONST_SEC_OPEN combined with SEC_VAR_* sections - START */

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_INIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_INIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_INIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_INIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_INIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_PBCFG))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_PBCFG is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

/* CONST_SEC_OPEN combined with SEC_VAR_* sections - END */


/* VAR_SEC_OPEN combined with SEC_CODE_* sections - START */

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CODE))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CODE is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CODE_FAST))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CODE_FAST is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CODE_ISR))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CODE_ISR is still defined as well. Please remove the obsolete define!"
# endif

/* VAR_SEC_OPEN combined with SEC_CODE_* sections - END */

/* VAR_SEC_OPEN combined with SEC_CONST_* sections - START */

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_FAST_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_FAST_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_FAST_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_FAST_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_FAST_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_PBCFG))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_PBCFG is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_PBCFG_GLOBALROOT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_PBCFG_GLOBALROOT is still defined as well. Please remove the obsolete define!"
# endif

/* VAR_SEC_OPEN combined with SEC_CONST_* sections - END */

/* VAR_SEC_OPEN combined with SEC_VAR_* sections - START */

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_INIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_INIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_INIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_INIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_INIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_PBCFG))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_PBCFG is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

/* VAR_SEC_OPEN combined with SEC_VAR_* sections - END */

#else

# if (((defined CODE_SEC_OPEN) || (defined CONST_SEC_OPEN) || (defined VAR_SEC_OPEN)) && \
      ((defined START_SEC_CODE                                                      ) || \
       (defined START_SEC_CODE_FAST                                                 ) || \
       (defined START_SEC_CODE_ISR                                                  ) || \
       (defined START_SEC_CONST_8BIT                                                ) || \
       (defined START_SEC_CONST_16BIT                                               ) || \
       (defined START_SEC_CONST_32BIT                                               ) || \
       (defined START_SEC_CONST_64BIT                                               ) || \
       (defined START_SEC_CONST_UNSPECIFIED                                         ) || \
       (defined START_SEC_CONST_FAST_8BIT                                           ) || \
       (defined START_SEC_CONST_FAST_16BIT                                          ) || \
       (defined START_SEC_CONST_FAST_32BIT                                          ) || \
       (defined START_SEC_CONST_FAST_64BIT                                          ) || \
       (defined START_SEC_CONST_FAST_UNSPECIFIED                                    ) || \
       (defined START_SEC_CONST_PBCFG                                               ) || \
       (defined START_SEC_PBCFG_GLOBALROOT                                          ) || \
       (defined START_SEC_VAR_INIT_8BIT                                             ) || \
       (defined START_SEC_VAR_INIT_16BIT                                            ) || \
       (defined START_SEC_VAR_INIT_32BIT                                            ) || \
       (defined START_SEC_VAR_INIT_64BIT                                            ) || \
       (defined START_SEC_VAR_INIT_UNSPECIFIED                                      ) || \
       (defined START_SEC_VAR_NOINIT_8BIT                                           ) || \
       (defined START_SEC_VAR_NOINIT_16BIT                                          ) || \
       (defined START_SEC_VAR_NOINIT_32BIT                                          ) || \
       (defined START_SEC_VAR_NOINIT_64BIT                                          ) || \
       (defined START_SEC_VAR_NOINIT_UNSPECIFIED                                    ) || \
       (defined START_SEC_VAR_PBCFG                                                 ) || \
       (defined START_SEC_VAR_ZERO_INIT_8BIT                                        ) || \
       (defined START_SEC_VAR_ZERO_INIT_16BIT                                       ) || \
       (defined START_SEC_VAR_ZERO_INIT_32BIT                                       ) || \
       (defined START_SEC_VAR_ZERO_INIT_64BIT                                       ) || \
       (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED                                 ) || \
       (defined START_SEC_VAR_FAST_INIT_8BIT                                        ) || \
       (defined START_SEC_VAR_FAST_INIT_16BIT                                       ) || \
       (defined START_SEC_VAR_FAST_INIT_32BIT                                       ) || \
       (defined START_SEC_VAR_FAST_INIT_64BIT                                       ) || \
       (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED                                 ) || \
       (defined START_SEC_VAR_FAST_NOINIT_8BIT                                      ) || \
       (defined START_SEC_VAR_FAST_NOINIT_16BIT                                     ) || \
       (defined START_SEC_VAR_FAST_NOINIT_32BIT                                     ) || \
       (defined START_SEC_VAR_FAST_NOINIT_64BIT                                     ) || \
       (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED                               ) || \
       (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT                                   ) || \
       (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT                                  ) || \
       (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT                                  ) || \
       (defined START_SEC_VAR_FAST_ZERO_INIT_64BIT                                  ) || \
       (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED                            ) || \
       (defined START_SEC_VAR_NOCACHE_INIT_8BIT                                     ) || \
       (defined START_SEC_VAR_NOCACHE_INIT_16BIT                                    ) || \
       (defined START_SEC_VAR_NOCACHE_INIT_32BIT                                    ) || \
       (defined START_SEC_VAR_NOCACHE_INIT_64BIT                                    ) || \
       (defined START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED                              ) || \
       (defined START_SEC_VAR_NOCACHE_NOINIT_8BIT                                   ) || \
       (defined START_SEC_VAR_NOCACHE_NOINIT_16BIT                                  ) || \
       (defined START_SEC_VAR_NOCACHE_NOINIT_32BIT                                  ) || \
       (defined START_SEC_VAR_NOCACHE_NOINIT_64BIT                                  ) || \
       (defined START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED                            ) || \
       (defined START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT                                ) || \
       (defined START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT                               ) || \
       (defined START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT                               ) || \
       (defined START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT                               ) || \
       (defined START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED                         )    \
      ))
#  error "MemMap_Common.h: New section opened before closing the former one. Please close the former code/const/data section before opening a new one. (Check_1)"
# endif

#endif /* MEMMAP_DETECT_ANY_ERROR */

/*------------------------------GLOBAL-START-SECTIONS------------------------------*/

/* Code sections */
#ifdef START_SEC_CODE
# define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CODE" is the obsolete one!"
# endif

#elif defined START_SEC_CODE_FAST
# define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CODE_FAST" is the obsolete one!"
# endif

#elif defined START_SEC_CODE_ISR
# define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CODE_ISR" is the obsolete one!"
# endif

/* Const sections */
#elif defined START_SEC_CONST_8BIT
# define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CONST_8BIT" is the obsolete one!"
# endif

#elif defined START_SEC_CONST_16BIT
# define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CONST_16BIT" is the obsolete one!"
# endif

#elif defined START_SEC_CONST_32BIT
# define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CONST_32BIT" is the obsolete one!"
# endif

#elif defined START_SEC_CONST_64BIT
# define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CONST_64BIT" is the obsolete one!"
# endif

#elif defined START_SEC_CONST_UNSPECIFIED
# define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CONST_UNSPECIFIED" is the obsolete one!"
# endif

#elif defined START_SEC_CONST_FAST_8BIT
# define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CONST_FAST_8BIT" is the obsolete one!"
# endif

#elif defined START_SEC_CONST_FAST_16BIT
# define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CONST_FAST_16BIT" is the obsolete one!"
# endif

#elif defined START_SEC_CONST_FAST_32BIT
# define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CONST_FAST_32BIT" is the obsolete one!"
# endif

#elif defined START_SEC_CONST_FAST_64BIT
# define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CONST_FAST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CONST_FAST_64BIT" is the obsolete one!"
# endif

#elif defined START_SEC_CONST_FAST_UNSPECIFIED
# define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CONST_FAST_UNSPECIFIED" is the obsolete one!"
# endif

#elif defined START_SEC_CONST_PBCFG
# define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_CONST_PBCFG" is the obsolete one!"
# endif

#elif defined START_SEC_PBCFG_GLOBALROOT
# define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_PBCFG_GLOBALROOT" is the obsolete one!"
# endif

/* Var sections */
#elif defined START_SEC_VAR_INIT_8BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_INIT_8BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_INIT_16BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_INIT_16BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_INIT_32BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_INIT_32BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_INIT_64BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_INIT_64BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_INIT_UNSPECIFIED
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_INIT_UNSPECIFIED" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOINIT_8BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOINIT_8BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOINIT_16BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOINIT_16BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOINIT_32BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOINIT_32BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOINIT_64BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOINIT_64BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOINIT_UNSPECIFIED
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOINIT_UNSPECIFIED" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_PBCFG
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_PBCFG" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_ZERO_INIT_8BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_ZERO_INIT_8BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_ZERO_INIT_16BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_ZERO_INIT_16BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_ZERO_INIT_32BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_ZERO_INIT_32BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_ZERO_INIT_64BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_ZERO_INIT_64BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_ZERO_INIT_UNSPECIFIED" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_INIT_8BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_INIT_8BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_INIT_16BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_INIT_16BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_INIT_32BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_INIT_32BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_INIT_64BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_INIT_64BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_INIT_UNSPECIFIED
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_INIT_UNSPECIFIED" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_NOINIT_8BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_NOINIT_8BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_NOINIT_16BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_NOINIT_16BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_NOINIT_32BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_NOINIT_32BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_NOINIT_64BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_NOINIT_64BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_NOINIT_UNSPECIFIED" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_ZERO_INIT_8BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_ZERO_INIT_8BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_ZERO_INIT_16BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_ZERO_INIT_16BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_ZERO_INIT_32BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_ZERO_INIT_32BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_ZERO_INIT_64BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_ZERO_INIT_64BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_INIT_8BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_INIT_8BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_INIT_16BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_INIT_16BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_INIT_32BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_INIT_32BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_INIT_64BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_INIT_64BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_NOINIT_8BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_NOINIT_8BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_NOINIT_16BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_NOINIT_16BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_NOINIT_32BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_NOINIT_32BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_NOINIT_64BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_NOINIT_64BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT" is the obsolete one!"
# endif

#elif defined START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
# undef START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifdef MEMMAP_DETECT_ANY_ERROR
#  error "The DEFINE: "START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED" is the obsolete one!"
# endif


/*------------------------------GENERAL-STOP-SECTIONS-------------------------------*/

/* Default segment for code */
#elif defined STOP_SEC_CODE
# if defined CODE_SEC_OPEN
#  undef CODE_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
#  undef STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# else
#  error "MemMap_Common.h: Code section closed but not opened one. Please close a code section [== usage of *_STOP_SEC_CODE_*] only if you have opened one [== usage of *_START_SEC_CODE_*]!"
# endif
/*default segment for Constants*/
#elif defined STOP_SEC_CONST
# if defined CONST_SEC_OPEN
#  undef CONST_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
#  undef STOP_SEC_CONST /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# else
#  error "MemMap_Common.h: Const section closed but not opened one. Please close a const section [== usage of *_STOP_SEC_CONST_*] only if you have opened one [== usage of *_START_SEC_CONST_*]!"
# endif
/*default segment for Datas*/
#elif defined STOP_SEC_VAR
# if defined VAR_SEC_OPEN
#  undef VAR_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
#  undef STOP_SEC_VAR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# else
#  error "MemMap_Common.h: Var section closed but not opened one. Please close a var section [== usage of *_STOP_SEC_VAR_*] only if you have opened one [== usage of *_START_SEC_VAR_*]!"
# endif
#else 
/* Intentionally left empty! I.a. errors are catched via the define "MEMMAP_ERROR". */
#endif

#ifdef MEMMAP_ERROR
# error "MemMap_Common.h: Wrong pragma command / unknown memory section used. Please use only valid pragma commands and known memory sections."
#endif

/* Check_2: Check code/const/data sections - 2: NO error, reason for this 2nd check after re-definition:
 * Due to usage of #elif-construct after re-definition any further keyword(s) may be still defined which is not allowed [wrong usage of MemMap-abstraction]!
 * NOTE: Check all in one in order to avoid wrong usage of MemMap-abstraction!
 */ 
#ifdef MEMMAP_DETECT_ANY_ERROR

/* CODE_SEC_OPEN combined with SEC_CODE_* sections - START */

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CODE))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CODE is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CODE_FAST))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CODE_FAST is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CODE_ISR))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CODE_ISR is still defined as well. Please remove the obsolete define!"
# endif

/* CODE_SEC_OPEN combined with SEC_CODE_* sections - END */

/* CODE_SEC_OPEN combined with SEC_CONST_* sections - START */

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_FAST_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_FAST_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_FAST_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_FAST_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_FAST_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_CONST_PBCFG))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_CONST_PBCFG is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_PBCFG_GLOBALROOT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_PBCFG_GLOBALROOT is still defined as well. Please remove the obsolete define!"
# endif

/* CODE_SEC_OPEN combined with SEC_CONST_* sections - END */

/* CODE_SEC_OPEN combined with SEC_VAR_* sections - START */

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_INIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_INIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_INIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_INIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_INIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_PBCFG))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_PBCFG is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CODE_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED))
#  error "Section: CODE_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

/* CODE_SEC_OPEN combined with SEC_VAR_* sections - END */


/* CONST_SEC_OPEN combined with SEC_CODE_* sections - START */

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CODE))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CODE is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CODE_FAST))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CODE_FAST is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CODE_ISR))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CODE_ISR is still defined as well. Please remove the obsolete define!"
# endif

/* CONST_SEC_OPEN combined with SEC_CODE_* sections - END */

/* CONST_SEC_OPEN combined with SEC_CONST_* sections - START */

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_FAST_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_FAST_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_FAST_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_FAST_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_FAST_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_CONST_PBCFG))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_CONST_PBCFG is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_PBCFG_GLOBALROOT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_PBCFG_GLOBALROOT is still defined as well. Please remove the obsolete define!"
# endif

/* CONST_SEC_OPEN combined with SEC_CONST_* sections - END */

/* CONST_SEC_OPEN combined with SEC_VAR_* sections - START */

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_INIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_INIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_INIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_INIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_INIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_PBCFG))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_PBCFG is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined CONST_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED))
#  error "Section: CONST_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

/* CONST_SEC_OPEN combined with SEC_VAR_* sections - END */


/* VAR_SEC_OPEN combined with SEC_CODE_* sections - START */

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CODE))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CODE is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CODE_FAST))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CODE_FAST is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CODE_ISR))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CODE_ISR is still defined as well. Please remove the obsolete define!"
# endif

/* VAR_SEC_OPEN combined with SEC_CODE_* sections - END */

/* VAR_SEC_OPEN combined with SEC_CONST_* sections - START */

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_FAST_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_FAST_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_FAST_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_FAST_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_FAST_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_FAST_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_CONST_PBCFG))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_CONST_PBCFG is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_PBCFG_GLOBALROOT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_PBCFG_GLOBALROOT is still defined as well. Please remove the obsolete define!"
# endif

/* VAR_SEC_OPEN combined with SEC_CONST_* sections - END */

/* VAR_SEC_OPEN combined with SEC_VAR_* sections - START */

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_INIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_INIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_INIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_INIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_INIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOINIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_PBCFG))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_PBCFG is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT is still defined as well. Please remove the obsolete define!"
# endif

# if ((defined VAR_SEC_OPEN) && (defined START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED))
#  error "Section: VAR_SEC_OPEN opened but in addition: START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is still defined as well. Please remove the obsolete define!"
# endif

/* VAR_SEC_OPEN combined with SEC_VAR_* sections - END */

#else
# if (((defined CODE_SEC_OPEN) || (defined CONST_SEC_OPEN) || (defined VAR_SEC_OPEN)) && \
      ((defined START_SEC_CODE                                                      ) || \
       (defined START_SEC_CODE_FAST                                                 ) || \
       (defined START_SEC_CODE_ISR                                                  ) || \
       (defined START_SEC_CONST_8BIT                                                ) || \
       (defined START_SEC_CONST_16BIT                                               ) || \
       (defined START_SEC_CONST_32BIT                                               ) || \
       (defined START_SEC_CONST_64BIT                                               ) || \
       (defined START_SEC_CONST_UNSPECIFIED                                         ) || \
       (defined START_SEC_CONST_FAST_8BIT                                           ) || \
       (defined START_SEC_CONST_FAST_16BIT                                          ) || \
       (defined START_SEC_CONST_FAST_32BIT                                          ) || \
       (defined START_SEC_CONST_FAST_64BIT                                          ) || \
       (defined START_SEC_CONST_FAST_UNSPECIFIED                                    ) || \
       (defined START_SEC_CONST_PBCFG                                               ) || \
       (defined START_SEC_PBCFG_GLOBALROOT                                          ) || \
       (defined START_SEC_VAR_INIT_8BIT                                             ) || \
       (defined START_SEC_VAR_INIT_16BIT                                            ) || \
       (defined START_SEC_VAR_INIT_32BIT                                            ) || \
       (defined START_SEC_VAR_INIT_64BIT                                            ) || \
       (defined START_SEC_VAR_INIT_UNSPECIFIED                                      ) || \
       (defined START_SEC_VAR_NOINIT_8BIT                                           ) || \
       (defined START_SEC_VAR_NOINIT_16BIT                                          ) || \
       (defined START_SEC_VAR_NOINIT_32BIT                                          ) || \
       (defined START_SEC_VAR_NOINIT_64BIT                                          ) || \
       (defined START_SEC_VAR_NOINIT_UNSPECIFIED                                    ) || \
       (defined START_SEC_VAR_PBCFG                                                 ) || \
       (defined START_SEC_VAR_ZERO_INIT_8BIT                                        ) || \
       (defined START_SEC_VAR_ZERO_INIT_16BIT                                       ) || \
       (defined START_SEC_VAR_ZERO_INIT_32BIT                                       ) || \
       (defined START_SEC_VAR_ZERO_INIT_64BIT                                       ) || \
       (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED                                 ) || \
       (defined START_SEC_VAR_FAST_INIT_8BIT                                        ) || \
       (defined START_SEC_VAR_FAST_INIT_16BIT                                       ) || \
       (defined START_SEC_VAR_FAST_INIT_32BIT                                       ) || \
       (defined START_SEC_VAR_FAST_INIT_64BIT                                       ) || \
       (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED                                 ) || \
       (defined START_SEC_VAR_FAST_NOINIT_8BIT                                      ) || \
       (defined START_SEC_VAR_FAST_NOINIT_16BIT                                     ) || \
       (defined START_SEC_VAR_FAST_NOINIT_32BIT                                     ) || \
       (defined START_SEC_VAR_FAST_NOINIT_64BIT                                     ) || \
       (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED                               ) || \
       (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT                                   ) || \
       (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT                                  ) || \
       (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT                                  ) || \
       (defined START_SEC_VAR_FAST_ZERO_INIT_64BIT                                  ) || \
       (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED                            ) || \
       (defined START_SEC_VAR_NOCACHE_INIT_8BIT                                     ) || \
       (defined START_SEC_VAR_NOCACHE_INIT_16BIT                                    ) || \
       (defined START_SEC_VAR_NOCACHE_INIT_32BIT                                    ) || \
       (defined START_SEC_VAR_NOCACHE_INIT_64BIT                                    ) || \
       (defined START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED                              ) || \
       (defined START_SEC_VAR_NOCACHE_NOINIT_8BIT                                   ) || \
       (defined START_SEC_VAR_NOCACHE_NOINIT_16BIT                                  ) || \
       (defined START_SEC_VAR_NOCACHE_NOINIT_32BIT                                  ) || \
       (defined START_SEC_VAR_NOCACHE_NOINIT_64BIT                                  ) || \
       (defined START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED                            ) || \
       (defined START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT                                ) || \
       (defined START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT                               ) || \
       (defined START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT                               ) || \
       (defined START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT                               ) || \
       (defined START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED                         )    \
      ))
#  error "MemMap_Common.h: New section opened before closing the former one. Please close the former code/const/data section before opening a new one. (Check_2)"
# endif

#endif /* MEMMAP_DETECT_ANY_ERROR */

/* Disable error detection, in order to limit the detection to the target.*/
#ifdef MEMMAP_DETECT_ANY_ERROR
# undef MEMMAP_DETECT_ANY_ERROR
#endif /* MEMMAP_DETECT_ANY_ERROR */


/* PRQA L:MEMMAP_COMMON_0841_TAG */

/**********************************************************************************************************************
 *  END OF FILE: MemMap_Common.h
 *********************************************************************************************************************/

