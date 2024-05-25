/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_MemMap.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  RTE Memory Mapping header file
 *********************************************************************************************************************/

/* PRQA S 0883 EOF */ /* MD_Rte_0883 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * RTE specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CODE
# undef RTE_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_ZERO_INIT_8BIT
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_ZERO_INIT_8BIT
# undef RTE_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_8BIT
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# undef RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CONST_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CONST_UNSPECIFIED
# undef RTE_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_APPL_CODE
# undef RTE_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CODE
# undef RTE_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef RTE_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_8BIT
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# undef RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CONST_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
# undef RTE_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_APPL_CODE
# undef RTE_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * SW-C specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BSWM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BSWM_APPL_CODE
# undef RTE_START_SEC_BSWM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_COMM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_COMM_APPL_CODE
# undef RTE_START_SEC_COMM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CORE5SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CORE5SWC_APPL_CODE
# undef RTE_START_SEC_CORE5SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CTCDD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CTCDD_APPL_CODE
# undef RTE_START_SEC_CTCDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CTIOHARDWARE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CTIOHARDWARE_APPL_CODE
# undef RTE_START_SEC_CTIOHARDWARE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CTMDA_CONTROL_LOGIC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CTMDA_CONTROL_LOGIC_APPL_CODE
# undef RTE_START_SEC_CTMDA_CONTROL_LOGIC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CTMOTOR_FL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CTMOTOR_FL_APPL_CODE
# undef RTE_START_SEC_CTMOTOR_FL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CTMOTOR_FR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CTMOTOR_FR_APPL_CODE
# undef RTE_START_SEC_CTMOTOR_FR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CTMOTOR_RL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CTMOTOR_RL_APPL_CODE
# undef RTE_START_SEC_CTMOTOR_RL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CTMOTOR_RR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CTMOTOR_RR_APPL_CODE
# undef RTE_START_SEC_CTMOTOR_RR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CTPSI5_HANDLER_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CTPSI5_HANDLER_APPL_CODE
# undef RTE_START_SEC_CTPSI5_HANDLER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CTPT2000_HANDLER_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CTPT2000_HANDLER_APPL_CODE
# undef RTE_START_SEC_CTPT2000_HANDLER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CTPWM_HANDLER_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CTPWM_HANDLER_APPL_CODE
# undef RTE_START_SEC_CTPWM_HANDLER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DET_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DET_APPL_CODE
# undef RTE_START_SEC_DET_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_ECUM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_ECUM_APPL_CODE
# undef RTE_START_SEC_ECUM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE
# undef RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_OS_OSCORE1_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_OS_OSCORE1_SWC_APPL_CODE
# undef RTE_START_SEC_OS_OSCORE1_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_OS_OSCORE2_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_OS_OSCORE2_SWC_APPL_CODE
# undef RTE_START_SEC_OS_OSCORE2_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_OS_OSCORE3_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_OS_OSCORE3_SWC_APPL_CODE
# undef RTE_START_SEC_OS_OSCORE3_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_OS_OSCORE4_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_OS_OSCORE4_SWC_APPL_CODE
# undef RTE_START_SEC_OS_OSCORE4_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_OS_OSCORE5_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_OS_OSCORE5_SWC_APPL_CODE
# undef RTE_START_SEC_OS_OSCORE5_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BSWM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BSWM_APPL_CODE
# undef RTE_STOP_SEC_BSWM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_COMM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_COMM_APPL_CODE
# undef RTE_STOP_SEC_COMM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CORE5SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CORE5SWC_APPL_CODE
# undef RTE_STOP_SEC_CORE5SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CTCDD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CTCDD_APPL_CODE
# undef RTE_STOP_SEC_CTCDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CTIOHARDWARE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CTIOHARDWARE_APPL_CODE
# undef RTE_STOP_SEC_CTIOHARDWARE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CTMDA_CONTROL_LOGIC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CTMDA_CONTROL_LOGIC_APPL_CODE
# undef RTE_STOP_SEC_CTMDA_CONTROL_LOGIC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CTMOTOR_FL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CTMOTOR_FL_APPL_CODE
# undef RTE_STOP_SEC_CTMOTOR_FL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CTMOTOR_FR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CTMOTOR_FR_APPL_CODE
# undef RTE_STOP_SEC_CTMOTOR_FR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CTMOTOR_RL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CTMOTOR_RL_APPL_CODE
# undef RTE_STOP_SEC_CTMOTOR_RL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CTMOTOR_RR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CTMOTOR_RR_APPL_CODE
# undef RTE_STOP_SEC_CTMOTOR_RR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CTPSI5_HANDLER_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CTPSI5_HANDLER_APPL_CODE
# undef RTE_STOP_SEC_CTPSI5_HANDLER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CTPT2000_HANDLER_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CTPT2000_HANDLER_APPL_CODE
# undef RTE_STOP_SEC_CTPT2000_HANDLER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CTPWM_HANDLER_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CTPWM_HANDLER_APPL_CODE
# undef RTE_STOP_SEC_CTPWM_HANDLER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DET_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DET_APPL_CODE
# undef RTE_STOP_SEC_DET_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_ECUM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_ECUM_APPL_CODE
# undef RTE_STOP_SEC_ECUM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE
# undef RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_OS_OSCORE1_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_OS_OSCORE1_SWC_APPL_CODE
# undef RTE_STOP_SEC_OS_OSCORE1_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_OS_OSCORE2_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_OS_OSCORE2_SWC_APPL_CODE
# undef RTE_STOP_SEC_OS_OSCORE2_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_OS_OSCORE3_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_OS_OSCORE3_SWC_APPL_CODE
# undef RTE_STOP_SEC_OS_OSCORE3_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_OS_OSCORE4_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_OS_OSCORE4_SWC_APPL_CODE
# undef RTE_STOP_SEC_OS_OSCORE4_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_OS_OSCORE5_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_OS_OSCORE5_SWC_APPL_CODE
# undef RTE_STOP_SEC_OS_OSCORE5_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * OS Application specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore1_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore1_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore1_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore1_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore1_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore1_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore1_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore1_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore1_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore1_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore1_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore1_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore1_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore2_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore2_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore2_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore2_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore2_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore2_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore2_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore2_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore2_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore2_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore2_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore2_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore2_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore2_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore2_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore2_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore2_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore2_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore2_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore2_NOCACHE_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore2_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore2_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore3_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore3_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore3_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore3_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore3_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore3_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore3_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore3_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore3_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore3_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore3_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore3_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore3_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore3_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore3_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore3_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore3_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore3_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore3_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore3_NOCACHE_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore3_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore3_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore4_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore4_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore4_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore4_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore4_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore4_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore4_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore4_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore4_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore4_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore4_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore4_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore4_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore4_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore4_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore4_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore4_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore4_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore4_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore4_NOCACHE_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore4_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore4_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore5_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore5_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore5_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore5_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore5_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore5_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore5_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore5_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore5_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore5_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore5_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore5_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore5_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore5_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore5_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore5_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore5_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore5_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_SystemApplication_OsCore5_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore5_NOCACHE_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_SystemApplication_OsCore5_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_SystemApplication_OsCore5_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore1_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore1_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore1_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore1_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore1_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore1_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore1_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore1_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore1_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore2_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore2_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore2_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore2_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore2_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore2_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore2_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore2_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOCACHE_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore2_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore3_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore3_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore3_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore3_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore3_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore3_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore3_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore3_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOCACHE_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore3_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore4_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore4_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore4_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore4_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore4_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore4_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore4_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore4_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOCACHE_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore4_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore5_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore5_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore5_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore5_NOCACHE_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore5_NOCACHE_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore5_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore5_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore5_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore5_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore5_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore5_NOCACHE_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore5_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore5_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore5_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore5_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore5_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore5_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_SystemApplication_OsCore5_NOCACHE_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore5_NOCACHE_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore5_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_SystemApplication_OsCore5_VAR_NOCACHE_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!        << Start of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_OS_MEMMAP_INCLUDE
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0883:  MISRA rule: 19.15
     Reason:     AUTOSAR SWS Memory Mapping requires inclusion of MemMap.h multiple times in a file in order to
                 select appropriate #pragma directives.
     Risk:       MemMap.h is provided by the integrator, hence many risks may occur, caused by wrong implementation of this file.
     Prevention: The integrator strictly has to adhere to the definitions of the AUTOSAR SWS Memory Mapping. Extensions to
                 the file not described in the SWS may not be put into MemMap.h. This has to be verified by code inspection.

*/
