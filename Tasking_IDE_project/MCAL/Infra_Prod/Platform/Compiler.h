/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Compiler.h                                                    **
**                                                                            **
**  VERSION   : 3.0.0                                                         **
**                                                                            **
**  DATE      : 2018-07-30                                                    **
**                                                                            **
**  VARIANT   : NA                                                            **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY : [cover parentID={FB97B5EA-8796-4991-B969-37114769C0BA}]    **
**                                                                            **
**  DESCRIPTION  : Compiler Abstraction Macros                                **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_CompilerAbstraction, AUTOSAR Release 4.2.2 **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef COMPILER_H
#define COMPILER_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Compiler_Cfg.h"

/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/
/*
 * Vendor ID of the dedicated implementation of this module according
 * to the AUTOSAR vendor list
 */
#define COMPILER_VENDOR_ID        (17u)


#define COMPILER_AR_RELEASE_MAJOR_VERSION    (4u)
#define COMPILER_AR_RELEASE_MINOR_VERSION    (2u)
#define COMPILER_AR_RELEASE_REVISION_VERSION (2u)

#if defined(__GNUC__)
#define _GNU_C_TRICORE_ 1U
/*
 * HIGHTEC V4.9.2.0
 */
#define COMPILER_SW_MAJOR_VERSION (4u)
#define COMPILER_SW_MINOR_VERSION (9u)
#define COMPILER_SW_PATCH_VERSION (2u)
#endif

#if defined (__TASKING__)
#define _TASKING_C_TRICORE_ 1U
/*
 * TASKING V6.2R2
 */
#define COMPILER_SW_MAJOR_VERSION (6u)
#define COMPILER_SW_MINOR_VERSION (2u)
#define COMPILER_SW_PATCH_VERSION (2u)
#endif
/*
 * WINDRIVER V6.0R1P2
 */

#if defined(__DCC__)
#define _DIABDATA_C_TRICORE_ 1U
/*
 * WINDRIVER 5.9.6.4
 */
#define COMPILER_SW_MAJOR_VERSION (5u)
#define COMPILER_SW_MINOR_VERSION (9u)
#define COMPILER_SW_PATCH_VERSION (6u)
#endif

#if defined (__ghs__)
#define _GHS_C_TRICORE_ 1U
/*
 * GREEN HILLS V2017.5.5
 */
#define COMPILER_SW_MAJOR_VERSION (17u)
#define COMPILER_SW_MINOR_VERSION (5u)
#define COMPILER_SW_PATCH_VERSION (5u)
#endif

/*used for local non static variables*/
#define AUTOMATIC

#define TYPEDEF

#define NULL_PTR ((void *)0)

/*abstraction of the keyword inline in functions with “static” scope*/
#ifdef _GNU_C_TRICORE_

#ifndef INLINE
#define INLINE      __inline__
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE    static __inline__
#endif

#endif

#ifdef _TASKING_C_TRICORE_

#ifndef INLINE
#define INLINE      inline
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE    static inline
#endif

#endif

#ifdef _DIABDATA_C_TRICORE_

#ifndef INLINE
#define INLINE      __inline__
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE  static __inline__
#endif

#endif

#ifdef _GHS_C_TRICORE_

#ifndef INLINE
#define INLINE     __inline__
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE   static inline
#endif

#endif


/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/

/******************************************************************************
**                      Global Constant Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/
#endif /* } COMPILER_H  */

