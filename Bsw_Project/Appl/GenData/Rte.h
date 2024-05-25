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
 *          File:  Rte.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  ITMS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header file containing RTE types
 *********************************************************************************************************************/

/* double include prevention */

#ifndef _RTE_H
# define _RTE_H

# define RTE_SW_MAJOR_VERSION (0x04U)
# define RTE_SW_MINOR_VERSION (0x13U)
# define RTE_SW_PATCH_VERSION (0x00U)

# define RTE_VENDOR_ID (0x001EU)
# define RTE_MODULE_ID (0x0002U)

# define RTE_AR_RELEASE_MAJOR_VERSION     (0x04U)
# define RTE_AR_RELEASE_MINOR_VERSION     (0x02U)
# define RTE_AR_RELEASE_REVISION_VERSION  (0x02U)

# include "Std_Types.h"

# include "Rte_UserTypes.h"

# if !defined (TYPEDEF) && defined (AUTOMATIC)
#  define TYPEDEF AUTOMATIC
# endif

# if !defined (FUNC_P2CONST)
#  define FUNC_P2CONST(rettype, ptrclass, memclass) FUNC(P2CONST(rettype, AUTOMATIC, ptrclass), memclass) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif

/* Note: application errors are in the range between 1-63
         overlayed error (ORed with application errors) is 64
         structural errors are in the range between 128-256 */

/* common errors */
# define RTE_E_OK               (0U)
# define RTE_E_INVALID          (1U)

/* overlayed errors */
# define RTE_E_LOST_DATA        (64U)
# define RTE_E_MAX_AGE_EXCEEDED (64U)

# define Rte_HasOverlayedError(status) (((status) & 64U) != 0) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* immediate infrastructure errors */
# define RTE_E_COM_STOPPED      (128U)
# define RTE_E_TIMEOUT          (129U)
# define RTE_E_LIMIT            (130U)
# define RTE_E_NO_DATA          (131U)
# define RTE_E_TRANSMIT_ACK     (132U)
# define RTE_E_NEVER_RECEIVED   (133U)
# define RTE_E_UNCONNECTED            (134U)
# define RTE_E_IN_EXCLUSIVE_AREA      (135U)
# define RTE_E_SEG_FAULT              (136U)
# define RTE_E_OUT_OF_RANGE           (137U)
# define RTE_E_SERIALIZATION_ERROR    (138U)
# define RTE_E_HARD_TRANSFORMER_ERROR (138U)
# define RTE_E_SERIALIZATION_LIMIT    (139U)
# define RTE_E_TRANSFORMER_LIMIT      (139U)
# define RTE_E_SOFT_TRANSFORMER_ERROR (140U)
# define RTE_E_COM_BUSY               (141U)

/* common SchM errors */
# define SCHM_E_OK                    (0U)
# define SCHM_E_TIMEOUT               (129U)
# define SCHM_E_LIMIT                 (130U)
# define SCHM_E_NO_DATA               (131U)
# define SCHM_E_TRANSMIT_ACK          (132U)
# define SCHM_E_IN_EXCLUSIVE_AREA     (135U)

# define Rte_IsInfrastructureError(status) (((status) & 128U) != 0) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define Rte_IsHardTransformerError Rte_IsInfrastructureError
# define Rte_ApplicationError(status) ((status) & 63U) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Macros for reporting Det Errors
 *********************************************************************************************************************/

# define Rte_CheckDetErrorReturnVoid( CONDITION, API_ID, ERROR_CODE )            { if(!(CONDITION)) { (void)Det_ReportError( RTE_MODULE_ID, 0, (API_ID), (ERROR_CODE)); return; } } /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define Rte_CheckDetErrorReturnValue( CONDITION, API_ID, ERROR_CODE, RET_VAL )  { if(!(CONDITION)) { (void)Det_ReportError( RTE_MODULE_ID, 0, (API_ID), (ERROR_CODE)); return (RET_VAL); } } /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define Rte_CheckDetErrorContinue( CONDITION, API_ID, ERROR_CODE )              { if(!(CONDITION)) { (void)Det_ReportError( RTE_MODULE_ID, 0, (API_ID), (ERROR_CODE)); } } /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define Rte_CallDetReportError( API_ID, ERROR_CODE )                            ((void)Det_ReportError( RTE_MODULE_ID, 0, (API_ID), (ERROR_CODE))) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Service IDs of Rte APIs
 *********************************************************************************************************************/

# define SCHM_INIT_SERVICE_ID                      (0x00U)
# define SCHM_DEINIT_SERVICE_ID                    (0x01U)
# define SCHM_ENTER_SERVICE_ID                     (0x03U)
# define SCHM_EXIT_SERVICE_ID                      (0x04U)
# define RTE_SEND_SERVICE_ID                       (0x13U)
# define RTE_WRITE_SERVICE_ID                      (0x14U)
# define RTE_SWITCH_SERVICE_ID                     (0x15U)
# define RTE_INVALIDATE_SERVICE_ID                 (0x16U)
# define RTE_FEEDBACK_SERVICE_ID                   (0x17U)
# define RTE_SWITCHACK_SERVICE_ID                  (0x18U)
# define RTE_READ_SERVICE_ID                       (0x19U)
# define RTE_DREAD_SERVICE_ID                      (0x1AU)
# define RTE_RECEIVE_SERVICE_ID                    (0x1BU)
# define RTE_CALL_SERVICE_ID                       (0x1CU)
# define RTE_RESULT_SERVICE_ID                     (0x1DU)
# define RTE_CDATA_SERVICE_ID                      (0x1FU)
# define RTE_PRM_SERVICE_ID                        (0x20U)
# define RTE_IRVREAD_SERVICE_ID                    (0x28U)
# define RTE_IRVWRITE_SERVICE_ID                   (0x29U)
# define RTE_ENTER_SERVICE_ID                      (0x2AU)
# define RTE_EXIT_SERVICE_ID                       (0x2BU)
# define RTE_MODE_SERVICE_ID                       (0x2CU)
# define RTE_TRIGGER_SERVICE_ID                    (0x2DU)
# define RTE_ISUPDATED_SERVICE_ID                  (0x30U)
# define RTE_START_SERVICE_ID                      (0x70U)
# define RTE_STOP_SERVICE_ID                       (0x71U)
# define RTE_PARTITIONTERMINATED_SERVICE_ID        (0x72U)
# define RTE_PARTITIONRESTARTING_SERVICE_ID        (0x73U)
# define RTE_RESTARTPARTITION_SERVICE_ID           (0x74U)
# define RTE_INIT_SERVICE_ID                       (0x75U)
# define RTE_STARTTIMING_SERVICE_ID                (0x76U)
# define RTE_COMCBKTACK_SN_SERVICE_ID              (0x90U)
# define RTE_COMCBKTERR_SN_SERVICE_ID              (0x91U)
# define RTE_COMCBKINV_SN_SERVICE_ID               (0x92U)
# define RTE_COMCBKRXTOUT_SN_SERVICE_ID            (0x93U)
# define RTE_COMCBKTXTOUT_SN_SERVICE_ID            (0x94U)
# define RTE_COMCBK_SG_SERVICE_ID                  (0x95U)
# define RTE_COMCBKTACK_SG_SERVICE_ID              (0x96U)
# define RTE_COMCBKTERR_SG_SERVICE_ID              (0x97U)
# define RTE_COMCBKINV_SG_SERVICE_ID               (0x98U)
# define RTE_COMCBKRXTOUT_SG_SERVICE_ID            (0x99U)
# define RTE_COMCBKTXTOUT_SG_SERVICE_ID            (0x9AU)
# define RTE_SETMIRROR_SERVICE_ID                  (0x9BU)
# define RTE_GETMIRROR_SERVICE_ID                  (0x9CU)
# define RTE_NVMNOTIFYJOBFINISHED_SERVICE_ID       (0x9DU)
# define RTE_NVMNOTIFYINITBLOCK_SERVICE_ID         (0x9EU)
# define RTE_COMCBK_SN_SERVICE_ID                  (0x9FU)
# define RTE_LDCOMCBKRXINDICATION_SERVICE_ID       (0xA0U)
# define RTE_LDCOMCBKSTARTOFRECEPTION_SERVICE_ID   (0xA1U)
# define RTE_LDCOMCBKCOPYRXDATA_SERVICE_ID         (0xA2U)
# define RTE_LDCOMCBKTPRXINDICATION_SERVICE_ID     (0xA3U)
# define RTE_LDCOMCBKCOPYTXDATA_SERVICE_ID         (0xA4U)
# define RTE_LDCOMCBKTPTXCONFIRMATION_SERVICE_ID   (0xA5U)
# define RTE_LDCOMCBKTRIGGERTRANSMIT_SERVICE_ID    (0xA6U)
# define RTE_LDCOMCBKTXCONFIRMATION_SERVICE_ID     (0xA7U)
/* additional service ids */
# define RTE_TASK_SERVICE_ID                       (0xF0U)
# define RTE_INCDISABLEFLAGS_SERVICE_ID            (0xF1U)
# define RTE_DECDISABLEFLAGS_SERVICE_ID            (0xF2U)

/**********************************************************************************************************************
 * Det Error Values
 *********************************************************************************************************************/

# define RTE_E_DET_ILLEGAL_SIGNAL_ID               (0x01U)
# define RTE_E_DET_ILLEGAL_VARIANT_CRITERION_VALUE (0x02U)
# define RTE_E_DET_ILLEGAL_NESTED_EXCLUSIVE_AREA   (0x05U)
# define RTE_E_DET_UNINIT                          (0x07U)
/* additional errors */
# define RTE_E_DET_MODEARGUMENT                    (0x20U)
# define RTE_E_DET_TRIGGERDISABLECOUNTER           (0x21U)
# define RTE_E_DET_TRANSITIONSTATE                 (0x22U)
# define RTE_E_DET_BLOCKSIZECHECK                  (0x23U)
# define RTE_E_DET_MULTICORE_STARTUP               (0x24U)
# define RTE_E_DET_MODESTATE                       (0x25U)

#endif /* _RTE_H */
