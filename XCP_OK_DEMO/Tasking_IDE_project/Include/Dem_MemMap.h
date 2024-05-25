/* ********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Template file for Dem memory map
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vector Informatik GmbH
 *  Anna Bosch                    visanh        Vector Informatik GmbH
 *  Stefan Huebner                vishrs        Vector Informatik GmbH
 *  Thomas Dedler                 visdth        Vector Informatik GmbH
 *  Alexander Ditte               visade        Vector Informatik GmbH
 *  Matthias Heil                 vismhe        Vector Informatik GmbH
 *  Erik Jeglorz                  visejz        Vector Informatik GmbH
 *  Friederike Schulze            visfrs        Vector Informatik GmbH
 *  Aswin Vijayamohanan Nair      visavi        Vector Informatik GmbH
 *  Fabian Wild                   viszfa        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.0.0     2017-07-05  visavi  -             Initial version
 *********************************************************************************************************************/

 /* PRQA S 0883 */  /* MD_DEM_1915 */
#if defined (DEM_START_SEC_0_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_0_VAR_NOINIT_UNSPECIFIED                                                                                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_STOP_SEC_0_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_0_VAR_NOINIT_UNSPECIFIED                                                                                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* Sample Preprocessor directive for a newly configured OS-Application instance <OS_APPLICATION_NAME>

  #if defined (DEM_START_SEC_<OS_APPLICATION_NAME>_VAR_NOINIT_UNSPECIFIED)
  # undef DEM_START_SEC_<OS_APPLICATION_NAME>_VAR_NOINIT_UNSPECIFIED                                                             
  # define START_SEC_VAR_NOINIT_UNSPECIFIED
  #endif
  
  #if defined (DEM_STOP_SEC_<OS_APPLICATION_NAME>_VAR_NOINIT_UNSPECIFIED)
  # undef DEM_STOP_SEC_<OS_APPLICATION_NAME>_VAR_NOINIT_UNSPECIFIED                                                              
  # define STOP_SEC_VAR
  #endif 
 
 */

/**********************************************************************************************************************
      Project:  Vector Basic Runtime System for MICROSAR4
       Module:  BrsAsr@Impl_Stubs

  \brief Description:  Stub of Dem_MemMap.h for a simple default UseCase with up to 6 Cores.

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

#if defined (DEM_START_SEC_SYSTEMAPPLICATION_OSCORE_CORE0_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_SYSTEMAPPLICATION_OSCORE_CORE0_VAR_NOINIT_UNSPECIFIED
/*# define START_SEC_VAR_NOINIT_UNSPECIFIED*/
# define OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_STOP_SEC_SYSTEMAPPLICATION_OSCORE_CORE0_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_SYSTEMAPPLICATION_OSCORE_CORE0_VAR_NOINIT_UNSPECIFIED
/*# define STOP_SEC_VAR*/
# define OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_SYSTEMAPPLICATION_OSCORE_CORE1_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_SYSTEMAPPLICATION_OSCORE_CORE1_VAR_NOINIT_UNSPECIFIED
/*# define START_SEC_VAR_NOINIT_UNSPECIFIED*/
# define OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_STOP_SEC_SYSTEMAPPLICATION_OSCORE_CORE1_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_SYSTEMAPPLICATION_OSCORE_CORE1_VAR_NOINIT_UNSPECIFIED
/*# define STOP_SEC_VAR*/
# define OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_SYSTEMAPPLICATION_OSCORE_CORE2_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_SYSTEMAPPLICATION_OSCORE_CORE2_VAR_NOINIT_UNSPECIFIED
/*# define START_SEC_VAR_NOINIT_UNSPECIFIED*/
# define OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_STOP_SEC_SYSTEMAPPLICATION_OSCORE_CORE2_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_SYSTEMAPPLICATION_OSCORE_CORE2_VAR_NOINIT_UNSPECIFIED
/*# define STOP_SEC_VAR*/
# define OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_SYSTEMAPPLICATION_OSCORE_CORE3_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_SYSTEMAPPLICATION_OSCORE_CORE3_VAR_NOINIT_UNSPECIFIED
/*# define START_SEC_VAR_NOINIT_UNSPECIFIED*/
# define OS_START_SEC_SystemApplication_OsCore_Core3_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_STOP_SEC_SYSTEMAPPLICATION_OSCORE_CORE3_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_SYSTEMAPPLICATION_OSCORE_CORE3_VAR_NOINIT_UNSPECIFIED
/*# define STOP_SEC_VAR*/
# define OS_STOP_SEC_SystemApplication_OsCore_Core3_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_SYSTEMAPPLICATION_OSCORE_CORE4_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_SYSTEMAPPLICATION_OSCORE_CORE4_VAR_NOINIT_UNSPECIFIED
/*# define START_SEC_VAR_NOINIT_UNSPECIFIED*/
# define OS_START_SEC_SystemApplication_OsCore_Core4_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_STOP_SEC_SYSTEMAPPLICATION_OSCORE_CORE4_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_SYSTEMAPPLICATION_OSCORE_CORE4_VAR_NOINIT_UNSPECIFIED
/*# define STOP_SEC_VAR*/
# define OS_STOP_SEC_SystemApplication_OsCore_Core4_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_SYSTEMAPPLICATION_OSCORE_CORE5_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_SYSTEMAPPLICATION_OSCORE_CORE5_VAR_NOINIT_UNSPECIFIED
/*# define START_SEC_VAR_NOINIT_UNSPECIFIED*/
# define OS_START_SEC_SystemApplication_OsCore_Core5_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_STOP_SEC_SYSTEMAPPLICATION_OSCORE_CORE5_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_SYSTEMAPPLICATION_OSCORE_CORE5_VAR_NOINIT_UNSPECIFIED
/*# define STOP_SEC_VAR*/
# define OS_STOP_SEC_SystemApplication_OsCore_Core5_VAR_NOINIT_UNSPECIFIED
#endif
