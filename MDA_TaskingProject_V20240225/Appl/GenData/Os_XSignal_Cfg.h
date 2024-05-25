/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_XSignal_Cfg.h
 *   Generation Time: 2024-01-08 16:27:33
 *           Project: Bsw_Project - Version 1.0
 *          Delivery: CBD1900078_D01
 *      Tool Version: DaVinci Configurator (beta) 5.18.42 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#ifndef OS_XSIGNAL_CFG_H
# define OS_XSIGNAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether the X-Signal module is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_XSIGNAL                          (STD_ON)

/*! Defines whether cross core calls shall be performed asynchronous (STD_ON) or not (STD_OFF). */
# define OS_CFG_XSIG_USEASYNC                    (STD_ON)

/* X-Signal defines for core: OsCore0 */
# define OS_CFG_NUM_XSIG_OSCORE0_ISRS     (1uL)
# define OS_CFG_SIZE_OSCORE0_SEND0_XSIGNALISR_OSCORE4_RECV0_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE0_SEND1_XSIGNALISR_OSCORE3_RECV0_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE0_SEND2_XSIGNALISR_OSCORE2_RECV0_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE0_SEND3_XSIGNALISR_OSCORE1_RECV0_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE0_SEND4_XSIGNALISR_OSCORE5_RECV0_BUFFER     (2uL)
# define OS_CFG_NUM_ISR_XSIGNALISR_OSCORE0_PORTS     (5uL)

/* X-Signal defines for core: OsCore1 */
# define OS_CFG_NUM_XSIG_OSCORE1_ISRS     (1uL)
# define OS_CFG_SIZE_OSCORE1_SEND0_XSIGNALISR_OSCORE4_RECV1_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE1_SEND1_XSIGNALISR_OSCORE3_RECV1_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE1_SEND2_XSIGNALISR_OSCORE2_RECV1_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE1_SEND3_XSIGNALISR_OSCORE0_RECV0_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE1_SEND4_XSIGNALISR_OSCORE5_RECV1_BUFFER     (2uL)
# define OS_CFG_NUM_ISR_XSIGNALISR_OSCORE1_PORTS     (5uL)

/* X-Signal defines for core: OsCore2 */
# define OS_CFG_NUM_XSIG_OSCORE2_ISRS     (1uL)
# define OS_CFG_SIZE_OSCORE2_SEND0_XSIGNALISR_OSCORE4_RECV2_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE2_SEND1_XSIGNALISR_OSCORE3_RECV2_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE2_SEND2_XSIGNALISR_OSCORE1_RECV1_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE2_SEND3_XSIGNALISR_OSCORE0_RECV1_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE2_SEND4_XSIGNALISR_OSCORE5_RECV2_BUFFER     (2uL)
# define OS_CFG_NUM_ISR_XSIGNALISR_OSCORE2_PORTS     (5uL)

/* X-Signal defines for core: OsCore3 */
# define OS_CFG_NUM_XSIG_OSCORE3_ISRS     (1uL)
# define OS_CFG_SIZE_OSCORE3_SEND0_XSIGNALISR_OSCORE4_RECV3_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE3_SEND1_XSIGNALISR_OSCORE2_RECV2_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE3_SEND2_XSIGNALISR_OSCORE1_RECV2_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE3_SEND3_XSIGNALISR_OSCORE0_RECV2_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE3_SEND4_XSIGNALISR_OSCORE5_RECV3_BUFFER     (2uL)
# define OS_CFG_NUM_ISR_XSIGNALISR_OSCORE3_PORTS     (5uL)

/* X-Signal defines for core: OsCore4 */
# define OS_CFG_NUM_XSIG_OSCORE4_ISRS     (1uL)
# define OS_CFG_SIZE_OSCORE4_SEND0_XSIGNALISR_OSCORE3_RECV3_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE4_SEND1_XSIGNALISR_OSCORE2_RECV3_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE4_SEND2_XSIGNALISR_OSCORE1_RECV3_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE4_SEND3_XSIGNALISR_OSCORE0_RECV3_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE4_SEND4_XSIGNALISR_OSCORE5_RECV4_BUFFER     (2uL)
# define OS_CFG_NUM_ISR_XSIGNALISR_OSCORE4_PORTS     (5uL)

/* X-Signal defines for core: OsCore5 */
# define OS_CFG_NUM_XSIG_OSCORE5_ISRS     (1uL)
# define OS_CFG_SIZE_OSCORE5_SEND0_XSIGNALISR_OSCORE4_RECV4_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE5_SEND1_XSIGNALISR_OSCORE3_RECV4_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE5_SEND2_XSIGNALISR_OSCORE2_RECV4_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE5_SEND3_XSIGNALISR_OSCORE1_RECV4_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE5_SEND4_XSIGNALISR_OSCORE0_RECV4_BUFFER     (2uL)
# define OS_CFG_NUM_ISR_XSIGNALISR_OSCORE5_PORTS     (5uL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_XSIGNAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_XSignal_Cfg.h
 *********************************************************************************************************************/
