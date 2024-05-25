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
 *  \defgroup    Os_MemMap MemMap
 *
 * \{
 *
 * \file
 * \brief       MemMap file for code sections.
 * \details     Provides the memmap section existence check.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/
                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#define MEMMAP_ERROR                                                                                                    /* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */

#include "Os_MemMap_OsCodeInt.h"

#if defined MEMMAP_ERROR                                                                                                /* COV_OS_MEMMAPERROR */
#error No MemMap section found. Check your section define for validity.
#endif

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_MemMap_OsCode.h
 **********************************************************************************************************************/
/* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */
