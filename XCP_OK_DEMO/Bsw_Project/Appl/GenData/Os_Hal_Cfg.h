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
 *              File: Os_Hal_Cfg.h
 *   Generation Time: 2023-04-13 22:02:37
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


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_CFG_H
# define OS_HAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! HAL configuration major version identification. */
# define OS_CFG_HAL_MAJOR_VERSION                (2u)

/*! HAL configuration minor version identification. */
# define OS_CFG_HAL_MINOR_VERSION                (16u)

/* ISR core and level definitions */
# define OS_ISR_CANISR_0_CORE      (0)
# define OS_ISR_CANISR_0_LEVEL     (37)
# define OS_ISR_COUNTERISR_SYSTEMTIMER0_CORE      (0)
# define OS_ISR_COUNTERISR_SYSTEMTIMER0_LEVEL     (12)
# define OS_ISR_COUNTERISR_SYSTEMTIMER1_CORE      (1)
# define OS_ISR_COUNTERISR_SYSTEMTIMER1_LEVEL     (20)
# define OS_ISR_COUNTERISR_SYSTEMTIMER2_CORE      (2)
# define OS_ISR_COUNTERISR_SYSTEMTIMER2_LEVEL     (20)
# define OS_ISR_COUNTERISR_SYSTEMTIMER3_CORE      (3)
# define OS_ISR_COUNTERISR_SYSTEMTIMER3_LEVEL     (20)
# define OS_ISR_COUNTERISR_SYSTEMTIMER4_CORE      (4)
# define OS_ISR_COUNTERISR_SYSTEMTIMER4_LEVEL     (20)
# define OS_ISR_COUNTERISR_SYSTEMTIMER5_CORE      (6)
# define OS_ISR_COUNTERISR_SYSTEMTIMER5_LEVEL     (20)
# define OS_ISR_XSIGNALISR_OSCORE0_CORE      (0)
# define OS_ISR_XSIGNALISR_OSCORE0_LEVEL     (18)
# define OS_ISR_XSIGNALISR_OSCORE1_CORE      (1)
# define OS_ISR_XSIGNALISR_OSCORE1_LEVEL     (18)
# define OS_ISR_XSIGNALISR_OSCORE2_CORE      (2)
# define OS_ISR_XSIGNALISR_OSCORE2_LEVEL     (18)
# define OS_ISR_XSIGNALISR_OSCORE3_CORE      (3)
# define OS_ISR_XSIGNALISR_OSCORE3_LEVEL     (18)
# define OS_ISR_XSIGNALISR_OSCORE4_CORE      (4)
# define OS_ISR_XSIGNALISR_OSCORE4_LEVEL     (18)
# define OS_ISR_XSIGNALISR_OSCORE5_CORE      (6)
# define OS_ISR_XSIGNALISR_OSCORE5_LEVEL     (18)

/* Hardware counter timing macros */

/* Counter timing macros and constants: SystemTimer0 */
# define OSMAXALLOWEDVALUE_SystemTimer0     (1073741823uL) /* 0x3FFFFFFFuL */
# define OSMINCYCLE_SystemTimer0            (1uL)
# define OSTICKSPERBASE_SystemTimer0        (1uL)
# define OSTICKDURATION_SystemTimer0        (10uL)

/* OSEK compatibility for the system timer. */
# define OSMAXALLOWEDVALUE     (OSMAXALLOWEDVALUE_SystemTimer0)
# define OSMINCYCLE            (OSMINCYCLE_SystemTimer0)
# define OSTICKSPERBASE        (OSTICKSPERBASE_SystemTimer0)
# define OSTICKDURATION        (OSTICKDURATION_SystemTimer0)

/*! Macro OS_NS2TICKS_SystemTimer0 was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer0(x)     ( (TickType) (((((uint32)(x)) * 1) + 5) / 10) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_SystemTimer0 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer0(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 10) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_SystemTimer0 was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer0(x)     ( (TickType) (((((uint32)(x)) * 100) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_SystemTimer0 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2US_SystemTimer0(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50) / 100) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_SystemTimer0 was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer0(x)     ( (TickType) (((((uint32)(x)) * 100000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_SystemTimer0 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer0(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50000) / 100000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_SystemTimer0 was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer0(x)     ( (TickType) (((((uint32)(x)) * 100000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_SystemTimer0 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer0(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50000000) / 100000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/* Counter timing macros and constants: SystemTimer1 */
# define OSMAXALLOWEDVALUE_SystemTimer1     (1073741823uL) /* 0x3FFFFFFFuL */
# define OSMINCYCLE_SystemTimer1            (1uL)
# define OSTICKSPERBASE_SystemTimer1        (1uL)
# define OSTICKDURATION_SystemTimer1        (10uL)

/*! Macro OS_NS2TICKS_SystemTimer1 was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer1(x)     ( (TickType) (((((uint32)(x)) * 1) + 5) / 10) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_SystemTimer1 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer1(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 10) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_SystemTimer1 was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer1(x)     ( (TickType) (((((uint32)(x)) * 100) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_SystemTimer1 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2US_SystemTimer1(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50) / 100) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_SystemTimer1 was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer1(x)     ( (TickType) (((((uint32)(x)) * 100000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_SystemTimer1 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer1(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50000) / 100000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_SystemTimer1 was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer1(x)     ( (TickType) (((((uint32)(x)) * 100000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_SystemTimer1 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer1(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50000000) / 100000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/* Counter timing macros and constants: SystemTimer2 */
# define OSMAXALLOWEDVALUE_SystemTimer2     (1073741823uL) /* 0x3FFFFFFFuL */
# define OSMINCYCLE_SystemTimer2            (1uL)
# define OSTICKSPERBASE_SystemTimer2        (1uL)
# define OSTICKDURATION_SystemTimer2        (10uL)

/*! Macro OS_NS2TICKS_SystemTimer2 was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer2(x)     ( (TickType) (((((uint32)(x)) * 1) + 5) / 10) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_SystemTimer2 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer2(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 10) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_SystemTimer2 was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer2(x)     ( (TickType) (((((uint32)(x)) * 100) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_SystemTimer2 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2US_SystemTimer2(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50) / 100) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_SystemTimer2 was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer2(x)     ( (TickType) (((((uint32)(x)) * 100000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_SystemTimer2 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer2(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50000) / 100000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_SystemTimer2 was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer2(x)     ( (TickType) (((((uint32)(x)) * 100000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_SystemTimer2 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer2(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50000000) / 100000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/* Counter timing macros and constants: SystemTimer3 */
# define OSMAXALLOWEDVALUE_SystemTimer3     (1073741823uL) /* 0x3FFFFFFFuL */
# define OSMINCYCLE_SystemTimer3            (1uL)
# define OSTICKSPERBASE_SystemTimer3        (1uL)
# define OSTICKDURATION_SystemTimer3        (10uL)

/*! Macro OS_NS2TICKS_SystemTimer3 was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer3(x)     ( (TickType) (((((uint32)(x)) * 1) + 5) / 10) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_SystemTimer3 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer3(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 10) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_SystemTimer3 was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer3(x)     ( (TickType) (((((uint32)(x)) * 100) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_SystemTimer3 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2US_SystemTimer3(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50) / 100) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_SystemTimer3 was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer3(x)     ( (TickType) (((((uint32)(x)) * 100000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_SystemTimer3 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer3(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50000) / 100000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_SystemTimer3 was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer3(x)     ( (TickType) (((((uint32)(x)) * 100000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_SystemTimer3 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer3(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50000000) / 100000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/* Counter timing macros and constants: SystemTimer4 */
# define OSMAXALLOWEDVALUE_SystemTimer4     (1073741823uL) /* 0x3FFFFFFFuL */
# define OSMINCYCLE_SystemTimer4            (1uL)
# define OSTICKSPERBASE_SystemTimer4        (1uL)
# define OSTICKDURATION_SystemTimer4        (10uL)

/*! Macro OS_NS2TICKS_SystemTimer4 was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer4(x)     ( (TickType) (((((uint32)(x)) * 1) + 5) / 10) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_SystemTimer4 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer4(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 10) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_SystemTimer4 was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer4(x)     ( (TickType) (((((uint32)(x)) * 100) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_SystemTimer4 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2US_SystemTimer4(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50) / 100) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_SystemTimer4 was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer4(x)     ( (TickType) (((((uint32)(x)) * 100000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_SystemTimer4 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer4(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50000) / 100000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_SystemTimer4 was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer4(x)     ( (TickType) (((((uint32)(x)) * 100000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_SystemTimer4 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer4(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50000000) / 100000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/* Counter timing macros and constants: SystemTimer5 */
# define OSMAXALLOWEDVALUE_SystemTimer5     (1073741823uL) /* 0x3FFFFFFFuL */
# define OSMINCYCLE_SystemTimer5            (1uL)
# define OSTICKSPERBASE_SystemTimer5        (1uL)
# define OSTICKDURATION_SystemTimer5        (10uL)

/*! Macro OS_NS2TICKS_SystemTimer5 was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer5(x)     ( (TickType) (((((uint32)(x)) * 1) + 5) / 10) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_SystemTimer5 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer5(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 10) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_SystemTimer5 was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer5(x)     ( (TickType) (((((uint32)(x)) * 100) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_SystemTimer5 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2US_SystemTimer5(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50) / 100) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_SystemTimer5 was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer5(x)     ( (TickType) (((((uint32)(x)) * 100000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_SystemTimer5 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer5(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50000) / 100000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_SystemTimer5 was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer5(x)     ( (TickType) (((((uint32)(x)) * 100000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_SystemTimer5 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer5(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50000000) / 100000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */




/* CAT0 and CAT1 ISR core and level definitions */



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_HAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Cfg.h
 *********************************************************************************************************************/
