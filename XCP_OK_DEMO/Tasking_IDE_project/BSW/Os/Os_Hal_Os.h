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
 *  \addtogroup Os_Hal_Os
 *  \{
 *
 *  \file       Os_Hal_Os.h
 *  \brief      HAL interfaces which are visible to the user.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Benjamin Seifert              virbse        Vector Informatik GmbH
 *  Bilal Parvez                  visbpz        Vector Informatik GmbH
 *  Da He                         visdhe        Vector Informatik GmbH
 *  David Feuerstein              visdfe        Vector Informatik GmbH
 *  Rainer Kuennemeyer            visrk         Vector Informatik GmbH
 *  Torsten Schmidt               visto         Vector Informatik GmbH
 *  Senol Cendere                 visces        Vector Informatik GmbH
 *  Andreas Jehl                  virjas        Vector Informatik GmbH
 *  Martin Schultheiss            virsmn        Vector Informatik GmbH
 *  Michael Kock                  vismkk        Vector Informatik GmbH
 *  Stefano Simoncelli            virsso        Vector Informatik GmbH
 *  Susann Rothweiler             visror        Vector Informatik GmbH
 *  Hendrik Stoffers              visshk        Vector Informatik GmbH
 *  Alexander Egorenkov           visaev        Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2015-01-26  visdhe  -             Initial version
 *  01.01.00  2015-04-29  visdhe  -             Developer version
 *  01.01.01  2015-05-10  visrk   -             Add coverage justifications
 *  01.01.02  2016-05-23  visto   ESCAN00088874 Adaption to HAL interface changes
 *  01.01.03  2016-06-03  visdfe  ESCAN00088874 Rework from previous adaption
 *                                              Add preconditions to service function interface (from FMEA).
 *  01.01.04  2016-06-23  visdhe                Adaption to HAL interface changes
 *  01.01.05  2016-07-05  visdhe                Adaption to HAL interface changes
 *  01.01.06  2016-07-19  visdfe                Adaption to HAL interface changes
 *  01.02.00  2016-08-31  visdhe                Added support for TriCore Aurix TC3xx
 *  01.02.01  2016-09-08  visdhe  FEAT-1931     Provide access to interrupt control register (Step2)
 *  01.02.02  2016-09-28  visdhe                Updated version for Sprint 10 (no functionality changes)
 *  01.03.00  2016-10-12  visdhe                Updated version for Sprint 11 (no hal functionality changes)
 *  01.03.01  2016-10-28  visdhe                Updated version for Sprint 12 (fixed issues)
                                  ESCAN00092399 OS stays in a loop due to incorrectly initialized PCXI
                                  ESCAN00092193 Idle task terminates due to compiler options
 *  01.04.00  2016-11-14  virbse                Updated Generator to latest BSWMD version
 *                        visto                 Re-Create the derivative headers with hardware documentation references
 *  01.05.00  2016-11-28  visdhe  WORKITEM10645 Code Coverage Analysis
 *  01.06.00  2016-12-05  virbse  WORKITEM11413 Reworked Os_Hal_DerivativeInt.h to use OS_CFG_DERIVATIVEGROUP_x defines
 *  01.07.00  2016-12-15  -       -             Internal improvements
 *  01.08.00  2017-01-12  -       -             Internal improvements
 *  02.00.00  2017-02-01  -       -             Internal improvements
 *  02.01.00  2017-03-17  visdhe  ESCAN00094000 Wrong core assignment of interrupts on systems with mixed core IDs
 *            2017-03-17  visdhe  ESCAN00093917 Timing protection ISR always lowers its interrupt level to the OS 
 *                                              system level during interrupt prologue
 *  02.02.00  2017-03-28  visto   WORKITEM14883 Keep compatibility to core generator
 *  02.03.00  2017-05-04  virbse  WORKITEM6746  The core generator shall provide a common core entry symbol for each 
 *                                              core.
 *  02.04.00  2017-06-01  visdfe  ESCAN00094046 Wrong validation of the maximum available MPU regions
 *            2017-06-19  visces  ESCAN00095247 Stack protection is disabled when PreTaskHook runs for the first time
 *  02.05.00  2017-06-28  visces  STORY-1038    Added interrupts of CATEGORY_0
 *            2017-06-28  visces  ESCAN00095476 Compiler warning: non-portable path to file '"Os_MemMap_OsCode.h"';
 *                                              specified path differs in case from file name on disk
 *            2017-06-28  visces  ESCAN00094528 Using OS_ISR1 leads to compiler error
 *  02.06.00  2017-07-06  virjas  WORKITEM15088 Internal improvements
 *  02.07.00  2017-07-24  virsmn  ESCAN00094867 Compiler warning: warning #1514-D: incorrect GHS #pragma: small data
 *                                              area is not supported in this configuration
 *            2017-07-15  visto   ESCAN00094965 Interrupt Vector table is not created by compiler
 *  02.08.00  2017-09-14  vismkk  STORYC-1658   #Core:Generator: Remove support of IOC inline interface
 *  02.09.00  2017-10-25  visces  ESCAN00095552 Free Running Timers configured as non High Resolution Counters do not 
 *                                              work properly.
 *  02.10.00  2017-10-18  virbse  FEAT-2816     Support shared stack for non-preemptive Basic tasks
 *                                FEAT-2815     Support shared stack for tasks with same internal resource
 *                        virsso  ESCAN00096029 Compiler error: Tasking compiler option "--tasking-sfr" leads to 
 *                                              compile errors
 *  02.11.00  2017-11-03  virsmn  ESCAN00096854 Usage of High Resolution Timer and Master Protection Mechanism of INTC 
 *                                              could lead to protection violation.
 *  02.12.00  2017-11-22  visdhe  STORYC-1751   Performance improvements for some IOC configurations
 *                        visdhe  ESCAN00097051 Compiler error: OS_ISR_<X> macro redefined for category 0 and 1 ISRs
 *                        visbpz  STORY-2769    OS Interrupt API optimization by replacement of a call sequence for 
 *                                              modification of the global interrupt flag.
 *                        visto   STORY-3259    Support for TC38x
 *  02.13.00  2017-01-10  virsso  STORYC-3218   Support for user configurable FPU cotext saving
 *  02.14.00  2017-01-29  virsmn  STORYC-3600   Update according to CDK coding guidelines.
 *                                STORYC-3282   Support for user Msr settings.
 *  02.15.00  2018-01-29  virsmn  STORYC-3042   Support for OS internal exception detection.
 *  02.16.00  2018-03-23  visbpz  STORYC-4068   Performance improvment by avoiding traps
 *  02.17.00  2018-05-03  virsmn  STORYC-3965   Added support for derivatives without interrupt level support.
 *  02.18.00  2018-05-14  virsmn  STORYC-3320   Added support for interrupt mapping feature.
 *            2018-06-06  visdhe  ESCAN00099430 Memory violation on core 5 (ID 6) is not correctly handled.
 *  02.19.00  2018-06-19  visdhe  STORYC-4824   Optimized TriCore SC1 context switching
 *            2018-06-29  virsmn  STORYC-5594   Added support fo aggregated stack configuration view.
 *  02.20.00  2018-07-18  virsmn  STORYC-4159   Improvement for internal testing.
 *  02.21.00  2018-08-06  virsmn  STORYC-4094   Achieve 100 percent variant coverage.
 *  02.22.00  2018-09-05  visces  ESCAN00100648 Compiler warning: Compiler HighTec V4.9.x.x outputs warnings
 *  02.23.00  2018-10-09  visror  STORYC-6211   Internal improvement
 *            2018-10-09  visshk  STORYC-4537   MISRA-C 2012 Compliance
 *  02.24.00  2018-11-06  virsmn  STORYC-4796   Interrupt API optimization.
 *  02.25.00  2018-12-05  visces  ESCAN00101240 ProtectionHook is called twice with status = E_OS_PROTECTION_MEMORY.
 *                        visces  PSC-1304      Adapted the SBSW CounterMeasures for hardware write access in HAL.
 *  02.26.00  2019-01-07  visror  -             Added MISRA justification.
 *  02.27.00  2019-01-17  visaev  -             Internal improvement.
 *            2019-01-18  visto   PSC-1515      stack switching behavior changed for exceptions (unhandled and memprot).
 *            2019-02-08  visaev  STORYC-7166   Added support for initial enabling of interrupt sources.
 **********************************************************************************************************************/


#ifndef OS_HAL_OS_H
# define OS_HAL_OS_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_OsInt.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* ----- Component version information ----- */
# define OS_HAL_SW_MAJOR_VERSION                     (2u)
# define OS_HAL_SW_MINOR_VERSION                     (27u)
# define OS_HAL_SW_PATCH_VERSION                     (0u)

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

#endif /* OS_HAL_OS_H */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Os.h
 **********************************************************************************************************************/

