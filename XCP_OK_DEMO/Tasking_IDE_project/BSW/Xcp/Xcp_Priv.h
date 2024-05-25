/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Xcp_Priv.h
 *        \brief  XCP private header file
 *
 *      \details  Private header of the XCP protocol layer.
 *                XCP V1.1 slave device driver
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file.
 *********************************************************************************************************************/

#if !defined (XCP_PRIV_H)
# define XCP_PRIV_H

/** 
* \defgroup IF Embedded Interfaces
* \{
*/
/** \defgroup hlp Helper */
/** \defgroup cmdHlp Command: Helper */
/** \defgroup cmdStd Standard Commands */
/* \{ */
/**   \defgroup stdDef Defines */
/** \} */
/** \defgroup cmdCal Calibration Commands */
/* \{ */
/**   \defgroup calDef Defines */
/** \} */
/** \defgroup cmdPag Page Switching Commands */
/* \{ */
/**   \defgroup pagDef Defines*/
/** \} */
/** \defgroup cmdPgm Programming Commands */
/* \{ */
/**   \defgroup pgmDef Defines */
/** \} */
/** \defgroup cmdDaq Data Aquisition and Stimulation Commands */
/* \{ */
/**   \defgroup daqDef Defines */
/**   \defgroup ctrDaq Control DAQ */
/** \} */
/** \} */ 

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/****************************************************************************/
/* XCP Driver Variables, Type Definition                                    */
/****************************************************************************/

/*-------------------------------------------------------------------------*/
/** 
 * \defgroup SEND_EVENT SEND_EVENT
 * \details Sends event message
 * \ingroup hlp
 * \{
 */
#define XCP_SENDEVENT_INITIAL_LENGTH                (0x02u)
/**\} */

/** 
 * \defgroup SEND_STATUS SEND_STATUS
 * \details Bitmasks for SendStatus
 * \ingroup hlp
 * \{
 */
#define XCP_CRM_REQUEST                             (0x01u)
#define XCP_DTO_REQUEST                             (0x02u)
#define XCP_EVT_REQUEST                             (0x04u)
#define XCP_CRM_PENDING                             (0x10u)
#define XCP_DTO_PENDING                             (0x20u)
#define XCP_EVT_PENDING                             (0x40u)
#define XCP_SEND_PENDING                            (XCP_DTO_PENDING|XCP_CRM_PENDING|XCP_EVT_PENDING)
/**\} */


/***************************************************************************/
/* Flags and Masks to access XCP Requests and Responses.                   */
/***************************************************************************/

/* GET_DAQ_PROCESSOR_INFO */

/** 
 * \defgroup DAQ_PROPERTIES DAQ_PROPERTIES
 * \ingroup daqDef
 * \{
 */
#define XCP_DAQ_PROPERTY_CONFIG_TYPE                (0x01)
#define XCP_DAQ_PROPERTY_PRESCALER                  (0x02)
#define XCP_DAQ_PROPERTY_RESUME                     (0x04)
#define XCP_DAQ_PROPERTY_BIT_STIM                   (0x08)
#define XCP_DAQ_PROPERTY_TIMESTAMP                  (0x10)
#define XCP_DAQ_PROPERTY_NO_PID                     (0x20)
#define XCP_DAQ_PROPERTY_OVERLOAD_INDICATION        (0xC0)
/**\} */

/** 
 * \defgroup DAQ_OVERLOAD DAQ_OVERLOAD
 * \ingroup daqDef
 * \{
 */
#define XCP_DAQ_OVERLOAD_INDICATION_NONE            (0<<6)
#define XCP_DAQ_OVERLOAD_INDICATION_PID             (1<<6)
#define XCP_DAQ_OVERLOAD_INDICATION_EVENT           (2<<6)
#define XCP_DAQ_OVERLOAD_MSB                        (0x80u) /*<! Bitmasks for internal statii */
/**\} */

/** 
 * \defgroup DAQ_KEY_BYTE DAQ_KEY_BYTE
 * \ingroup daqDef
 * \{
 */
#define XCP_DAQ_OPT_TYPE                            (0x0Fu)
#define XCP_DAQ_EXT_TYPE                            (0x30u)
#define XCP_DAQ_HDR_TYPE                            (0xC0u)
/**\} */

/** 
 * \defgroup DAQ_OPT DAQ_OPT
 * \ingroup daqDef
 * \{
 */
#define XCP_DAQ_OPT_DEFAULT                         (0<<0)
#define XCP_DAQ_OPT_ODT_16                          (1<<0)
#define XCP_DAQ_OPT_ODT_32                          (2<<0)
#define XCP_DAQ_OPT_ODT_64                          (3<<0)
#define XCP_DAQ_OPT_ALIGNMENT                       (4<<0)
#define XCP_DAQ_OPT_MAX_ENTRY_SIZE                  (5<<0)
/**\} */

/** 
 * \defgroup DAQ_EXT DAQ_EXT
 * \ingroup daqDef
 * \{
 */
#define XCP_DAQ_EXT_FREE                            (0<<4)
#define XCP_DAQ_EXT_ODT                             (1<<4)
#define XCP_DAQ_EXT_DAQ                             (3<<4)
/**\} */

/** 
 * \defgroup DAQ_HDR DAQ_HDR
 * \ingroup daqDef
 * \{
 */
#define XCP_DAQ_HDR_PID                             (0<<6)
#define XCP_DAQ_HDR_ODT_DAQB                        (1<<6)
#define XCP_DAQ_HDR_ODT_DAQW                        (2<<6)
#define XCP_DAQ_HDR_ODT_FIL_DAQW                    (3<<6)
/**\} */

/*-------------------------------------------------------------------------*/
/* GET_DAQ_RESOLUTION_INFO */

/** 
 * \defgroup DAQ_TIMESTAMP DAQ_TIMESTAMP
 * \ingroup daqDef
 * \{
 */
#define XCP_DAQ_RES_TIMESTAMP_SIZE                  (0x07)
#define XCP_DAQ_RES_TIMESTAMP_FIXED                 (0x08)
#define XCP_DAQ_RES_TIMESTAMP_UNIT                  (0xF0)


/** 
 * \defgroup DAQ_FLAG DAQ_FLAG
 * \ingroup daqDef
 * \{
 */
#define XCP_DAQ_FLAG_SELECTED                       (0x01u) /* */
#define XCP_DAQ_FLAG_DIRECTION                      (0x02u) /*<! Data Stimulation Mode */

#define XCP_DAQ_FLAG_TIMESTAMP                      (0x10u) /*<! Timestamps */
#define XCP_DAQ_FLAG_NO_PID                         (0x20u) /*<! No PID */
#define XCP_DAQ_FLAG_RUNNING                        (0x40u) /*<! Is started */
#define XCP_DAQ_FLAG_RESUME                         (0x80u) /*<! Resume Mode */
/**\} */

/*-------------------------------------------------------------------------*/
/* Protocol Info (GET_COMM_MODE_INFO - COMM_OPTIONAL) */
#define XCP_CMO_MASTER_BLOCK_MODE                   (0x01)
#define XCP_CMO_INTERLEAVED_MODE                    (0x02)


/*-------------------------------------------------------------------------*/
/* CommModeBasic (CONNECT) */
#define XCP_PI_MOTOROLA                             (0x01)

#define XCP_CMB_BYTE_ORDER                          (0x01u)
#define XCP_CMB_ADDRESS_GRANULARITY                 (0x06u)
#define XCP_CMB_SLAVE_BLOCK_MODE                    (0x40u)
#define XCP_CMB_OPTIONAL                            (0x80u)

#define XCP_CMB_ADDRESS_GRANULARITY_BYTE            (0u)
#define XCP_CMB_ADDRESS_GRANULARITY_WORD            (2u)
#define XCP_CMB_ADDRESS_GRANULARITY_DWORD           (4u)
#define XCP_CMB_ADDRESS_GRANULARITY_QWORD           (6u)

/*-------------------------------------------------------------------------*/
/* Protocol command structure definition */
/* Command Request Object */
# define XCP_CRO_CMD                                (0u)
/* Command Response Message */
# define XCP_CRM_CMD                                (0u)
# define XCP_CRM_ERR                                (1u)
# define XCP_CRM_ERR_LEN                            (2u)


/***************************************************************************/
/* Commands IDs                                                            */
/***************************************************************************/

/** 
 * \defgroup STD_CMD_IDS STD_CMD_IDS
 * \details Standard Commands IDs
 * \ingroup stdDef
 * \{
 */
# define XCP_CMD_CONNECT                            (0xFFu)
# define XCP_CMD_DISCONNECT                         (0xFEu)
# define XCP_CMD_GET_STATUS                         (0xFDu)
# define XCP_CMD_SYNC                               (0xFCu)

# define XCP_CMD_GET_COMM_MODE_INFO                 (0xFBu)
# define XCP_CMD_GET_ID                             (0xFAu)
# define XCP_CMD_SET_REQUEST                        (0xF9u)
# define XCP_CMD_GET_SEED                           (0xF8u)
# define XCP_CMD_UNLOCK                             (0xF7u)
# define XCP_CMD_SET_MTA                            (0xF6u)
# define XCP_CMD_UPLOAD                             (0xF5u)
# define XCP_CMD_SHORT_UPLOAD                       (0xF4u)
# define XCP_CMD_BUILD_CHECKSUM                     (0xF3u)

# define XCP_CMD_TRANSPORT_LAYER_CMD                (0xF2u)
# define XCP_CMD_USER_CMD                           (0xF1u)
/**\} */

/** 
 * \defgroup CAL_CMD_IDS CAL_CMD_IDS
 * \details Calibration Commands
 * \ingroup calDef
 * \{
 */
# define XCP_CMD_DOWNLOAD                           (0xF0u)

# define XCP_CMD_DOWNLOAD_NEXT                      (0xEFu)
# define XCP_CMD_DOWNLOAD_MAX                       (0xEEu)
# define XCP_CMD_SHORT_DOWNLOAD                     (0xEDu)
# define XCP_CMD_MODIFY_BITS                        (0xECu)
/**\} */

/** 
 * \defgroup PAG_CMD_IDS PAG_CMD_IDS
 * \details Page switching Commands (PAG)
 * \ingroup pagDef
 * \{
 */
# define XCP_CMD_SET_CAL_PAGE                       (0xEBu)
# define XCP_CMD_GET_CAL_PAGE                       (0xEAu)

# define XCP_CMD_GET_PAG_PROCESSOR_INFO             (0xE9u)
# define XCP_CMD_GET_SEGMENT_INFO                   (0xE8u)
# define XCP_CMD_GET_PAGE_INFO                      (0xE7u)
# define XCP_CMD_SET_SEGMENT_MODE                   (0xE6u)
# define XCP_CMD_GET_SEGMENT_MODE                   (0xE5u)
# define XCP_CMD_COPY_CAL_PAGE                      (0xE4u)
/**\} */

/** 
 * \defgroup DAQ_CMD_IDS DAQ_CMD_IDS
 * \details  DATA Acquisition and Stimulation Commands (DAQ/STIM)
 * \ingroup daqDef
 * \{
 */
# define XCP_CMD_CLEAR_DAQ_LIST                     (0xE3u)
# define XCP_CMD_SET_DAQ_PTR                        (0xE2u)
# define XCP_CMD_WRITE_DAQ                          (0xE1u)
# define XCP_CMD_SET_DAQ_LIST_MODE                  (0xE0u)
# define XCP_CMD_GET_DAQ_LIST_MODE                  (0xDFu)
# define XCP_CMD_START_STOP_DAQ_LIST                (0xDEu)
# define XCP_CMD_START_STOP_SYNCH                   (0xDDu)

# define XCP_CMD_GET_DAQ_CLOCK                      (0xDCu)
# define XCP_CMD_READ_DAQ                           (0xDBu)
# define XCP_CMD_GET_DAQ_PROCESSOR_INFO             (0xDAu)
# define XCP_CMD_GET_DAQ_RESOLUTION_INFO            (0xD9u)
# define XCP_CMD_GET_DAQ_LIST_INFO                  (0xD8u)
# define XCP_CMD_GET_DAQ_EVENT_INFO                 (0xD7u)

# define XCP_CMD_FREE_DAQ                           (0xD6u)
# define XCP_CMD_ALLOC_DAQ                          (0xD5u)
# define XCP_CMD_ALLOC_ODT                          (0xD4u)
# define XCP_CMD_ALLOC_ODT_ENTRY                    (0xD3u)
/**\} */

/** 
 * \defgroup PGM_CMD_IDS PGM_CMD_IDS
 * \details  Non volatile memory Programming Commands PGM
 * \ingroup pgmDef
 * \{
 */
# define XCP_CMD_PROGRAM_START                      (0xD2u)
# define XCP_CMD_PROGRAM_CLEAR                      (0xD1u)
# define XCP_CMD_PROGRAM                            (0xD0u)
# define XCP_CMD_PROGRAM_RESET                      (0xCFu)

# define XCP_CMD_GET_PGM_PROCESSOR_INFO             (0xCEu)
# define XCP_CMD_GET_SECTOR_INFO                    (0xCDu)
# define XCP_CMD_PROGRAM_PREPARE                    (0xCCu)
# define XCP_CMD_PROGRAM_FORMAT                     (0xCBu)
# define XCP_CMD_PROGRAM_NEXT                       (0xCAu)
# define XCP_CMD_PROGRAM_MAX                        (0xC9u)
# define XCP_CMD_PROGRAM_VERIFY                     (0xC8u)
/**\} */

/*-------------------------------------------------------------------------*/
/* Customer specific commands */
# define XCP_CMD_WRITE_DAQ_MULTIPLE                 (0xC7u)

/*-------------------------------------------------------------------------*/
/* STIM frames */
# define XCP_CMD_BORDER                             (0xC0u)


/***************************************************************************/
/* Indices to access XCP Command Request and Responses. */
/***************************************************************************/

/** 
 * \defgroup CONNECT_IDX CONNECT_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
# define XCP_CRO_CONNECT_LEN                        (2u)
# define XCP_CRM_CONNECT_LEN                        (8u)
/* uint8 */
# define XCP_CRO_CONNECT_MODE                       (1u)
# define XCP_CRM_CONNECT_RESOURCE                   (1u)
# define XCP_CRM_CONNECT_COMM_BASIC                 (2u)
# define XCP_CRM_CONNECT_MAX_CTO_SIZE               (3u)
# define XCP_CRM_CONNECT_PROTOCOL_VERSION           (6u)
# define XCP_CRM_CONNECT_TRANSPORT_VERSION          (7u)
/* uint16 */
# define XCP_CRM_CONNECT_MAX_DTO_SIZE               (4u)
/* Offset of + 2 is due to initial length of dto */
# define XCP_CONNECT_DTO_OFFSET                     (2u)
/**\} */

/** 
 * \defgroup GET_ID_IDX GET_ID_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
#define XCP_CRO_GET_ID_LEN                          (2u)
#define XCP_CRO_GET_ID_TYPE                         (1u)

#define XCP_CRM_GET_ID_LEN                          (8u)
#define XCP_CRM_GET_ID_MODE                         (1u)
#define XCP_CRM_GET_ID_LENGTH                       (4u)
#define XCP_CRM_GET_ID_DATA                         (8u)
/**\} */

/** 
 * \defgroup GET_STATUS_IDX GET_STATUS_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
#define XCP_CRO_GET_STATUS_LEN                      (1u)

#define XCP_CRM_GET_STATUS_LEN                      (6u)
#define XCP_CRM_GET_STATUS_STATUS                   (1u)
#define XCP_CRM_GET_STATUS_PROTECTION               (2u)
#define XCP_CRM_GET_STATUS_CONFIG_ID                (4u)
/**\} */

/** 
 * \defgroup SET_REQUEST_IDX SET_REQUEST_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
#define XCP_CRO_SET_REQUEST_LEN                     (4u)
#define XCP_CRO_SET_REQUEST_MODE                    (1u)
#define XCP_CRO_SET_REQUEST_CONFIG_ID               (2u)

#define XCP_CRM_SET_REQUEST_LEN                     (1u)
/**\} */

/** 
 * \defgroup GET_COMM_MODE_INFO_IDX GET_COMM_MODE_INFO_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
#define XCP_CRO_GET_COMM_MODE_INFO_LEN              (1u)

#define XCP_CRM_GET_COMM_MODE_INFO_LEN              (8u)
#define XCP_CRM_GET_COMM_MODE_INFO_COMM_OPTIONAL    (2u)
#define XCP_CRM_GET_COMM_MODE_INFO_MAX_BS           (4u)
#define XCP_CRM_GET_COMM_MODE_INFO_MIN_ST           (5u)
#define XCP_CRM_GET_COMM_MODE_INFO_QUEUE_SIZE       (6u)
#define XCP_CRM_GET_COMM_MODE_INFO_DRIVER_VERSION   (7u)
/**\} */

/** 
 * \defgroup GET_SEED_IDX GET_SEED_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
#define XCP_CRO_GET_SEED_LEN                        (3u)
#define XCP_CRO_GET_SEED_MODE                       (1u)
#define XCP_CRO_GET_SEED_RESOURCE                   (2u)

#define XCP_CRM_GET_SEED_LEN                        (2u)
#define XCP_CRM_GET_SEED_LENGTH                     (1u)
#define XCP_CRM_GET_SEED_DATA                       (2u)
/**\} */

/** 
 * \defgroup UNLOCK_IDX UNLOCK_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
#define XCP_CRO_UNLOCK_LEN                          (8u)
#define XCP_CRO_UNLOCK_LENGTH                       (1u)
#define XCP_CRO_UNLOCK_KEY                          (2u)

#define XCP_CRM_UNLOCK_LEN                          (2u)
#define XCP_CRM_UNLOCK_PROTECTION                   (1u)
/**\} */

/** 
 * \defgroup SET_MTA_IDX SET_MTA_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
#define XCP_CRO_SET_MTA_LEN                         (8u)
#define XCP_CRO_SET_MTA_EXT                         (3u)
#define XCP_CRO_SET_MTA_ADDR                        (4u) /* 5, 6 and 7 */

#define XCP_CRM_SET_MTA_LEN                         (1u)
/**\} */

/** 
 * \defgroup UPLOAD_IDX UPLOAD_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
#define XCP_CRO_UPLOAD_LEN                          (2u)
#define XCP_CRO_UPLOAD_SIZE                         (1u)

#define XCP_CRM_UPLOAD_BLOCK_MAX_SIZE               (255u)
#define XCP_CRM_UPLOAD_LEN                          (1u)
#define XCP_CRM_UPLOAD_DATA                         (1u)
/**\} */

/** 
 * \defgroup SHORT_UPLOAD_IDX SHORT_UPLOAD_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
#define XCP_CRO_SHORT_UPLOAD_LEN                    (8u)
#define XCP_CRO_SHORT_UPLOAD_SIZE                   (1u)
#define XCP_CRO_SHORT_UPLOAD_EXT                    (3u)
#define XCP_CRO_SHORT_UPLOAD_ADDR                   (4u)

#define XCP_CRM_SHORT_UPLOAD_LEN                    (1u) /* +XCP_CRO_SHORT_UPLOAD_SIZE */
#define XCP_CRM_SHORT_UPLOAD_DATA                   (1u)
/**\} */

/** 
 * \defgroup BUILD_CHECKSUM_IDX BUILD_CHECKSUM_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
#define XCP_CRO_BUILD_CHECKSUM_LEN                  (8u)
#define XCP_CRO_BUILD_CHECKSUM_SIZE                 (4u)

#define XCP_CRM_BUILD_CHECKSUM_LEN                  (8u)
#define XCP_CRM_BUILD_CHECKSUM_TYPE                 (1u)
#define XCP_CRM_BUILD_CHECKSUM_RESULT               (4u)
/**\} */

/** 
 * \defgroup DOWNLOAD_IDX DOWNLOAD_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup calDef
 * \{
 */
#define XCP_CRO_DOWNLOAD_LEN                        (2u) /* + XCP_CRO_DOWNLOAD_SIZE */
#define XCP_CRO_DOWNLOAD_SIZE                       (1u)
#define XCP_CRO_DOWNLOAD_DATA                       (2u)

#define XCP_CRM_DOWNLOAD_LEN                        (1u)
/**\} */

/** 
 * \defgroup DOWNLOAD_NEXT_IDX DOWNLOAD_NEXT_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup calDef
 * \{
 */
#define XCP_CRO_DOWNLOAD_NEXT_LEN                   (2u) /* + XCP_CRO_DOWNLOAD_NEXT_SIZE */
#define XCP_CRO_DOWNLOAD_NEXT_SIZE                  (1u)
#define XCP_CRO_DOWNLOAD_NEXT_DATA                  (2u)

#define XCP_CRM_DOWNLOAD_NEXT_LEN                   (1u)
#define XCP_CRM_DOWNLOAD_NEXT_DATA_BLOCK_SIZE       (2u)
#define XCP_CRM_DOWNLOAD_NEXT_ERR_RESPONSE_LENGTH   (3u)
/**\} */

/** 
 * \defgroup DOWNLOAD_MAX_IDX DOWNLOAD_MAX_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup calDef
 * \{
 */
#define XCP_CRO_DOWNLOAD_MAX_DATA                   (1u)

#define XCP_CRM_DOWNLOAD_MAX_LEN                    (1u)
/**\} */

/** 
 * \defgroup SHORT_DOWNLOAD_IDX SHORT_DOWNLOAD_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup calDef
 * \{
 */
#define XCP_CRO_SHORT_DOWNLOAD_LEN                  (8u)
#define XCP_CRO_SHORT_DOWNLOAD_SIZE                 (1u)
#define XCP_CRO_SHORT_DOWNLOAD_EXT                  (3u)
#define XCP_CRO_SHORT_DOWNLOAD_ADDR                 (4u)
#define XCP_CRO_SHORT_DOWNLOAD_DATA                 (8u)

#define XCP_CRM_SHORT_DOWNLOAD_LEN                  (1u) /* +XCP_CRO_SHORT_UPLOAD_SIZE */
/**\} */

/** 
 * \defgroup MODIFY_BITS_IDX MODIFY_BITS_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup calDef
 * \{
 */
#define XCP_CRO_MODIFY_BITS_LEN                     (6u)
#define XCP_CRO_MODIFY_BITS_SHIFT                   (1u)
#define XCP_CRO_MODIFY_BITS_AND                     (2u)
#define XCP_CRO_MODIFY_BITS_XOR                     (4u)

#define XCP_CRM_MODIFY_BITS_LEN                     (1u)
/**\} */

/** 
 * \defgroup SET_CAL_PAGE_IDX SET_CAL_PAGE_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pagDef
 * \{
 */
#define XCP_CRO_SET_CAL_PAGE_LEN                    (4u)
#define XCP_CRO_SET_CAL_PAGE_MODE                   (1u)
#define XCP_CRO_SET_CAL_PAGE_SEGMENT                (2u)
#define XCP_CRO_SET_CAL_PAGE_PAGE                   (3u)

#define XCP_CRM_SET_CAL_PAGE_LEN                    (1u)
/**\} */

/** 
 * \defgroup GET_CAL_PAGE_IDX GET_CAL_PAGE_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pagDef
 * \{
 */
#define XCP_CRO_GET_CAL_PAGE_LEN                    (3u)
#define XCP_CRO_GET_CAL_PAGE_MODE                   (1u)
#define XCP_CRO_GET_CAL_PAGE_SEGMENT                (2u)

#define XCP_CRM_GET_CAL_PAGE_LEN                    (4u)
#define XCP_CRM_GET_CAL_PAGE_PAGE                   (3u)
/**\} */

/** 
 * \defgroup GET_PAG_PROCESSOR_INFO_IDX GET_PAG_PROCESSOR_INFO_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pagDef
 * \{
 */
#define XCP_CRO_GET_PAG_PROCESSOR_INFO_LEN          (1u)

#define XCP_CRM_GET_PAG_PROCESSOR_INFO_LEN          (3u)
#define XCP_CRM_GET_PAG_PROCESSOR_INFO_MAX_SEGMENT  (1u)
#define XCP_CRM_GET_PAG_PROCESSOR_INFO_PROPERTIES   (2u)
/**\} */

/** 
 * \defgroup GET_PAGE_INFO_IDX GET_PAGE_INFO_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pagDef
 * \{
 */
#define XCP_CRO_GET_PAGE_INFO_LEN                   (4u)
#define XCP_CRO_GET_PAGE_INFO_SEGMENT_NUMBER        (2u)
#define XCP_CRO_GET_PAGE_INFO_PAGE_NUMBER           (3u)

#define XCP_CRM_GET_PAGE_INFO_LEN                   (3u)
#define XCP_CRM_GET_PAGE_INFO_PROPERTIES            (1u)
#define XCP_CRM_GET_PAGE_INFO_INIT_SEGMENT          (2u)
/**\} */

/** 
 * \defgroup SET_SEGMENT_MODE_IDX SET_SEGMENT_MODE_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pagDef
 * \{
 */
#define XCP_CRO_SET_SEGMENT_MODE_LEN                (3u)
#define XCP_CRO_SET_SEGMENT_MODE_MODE               (1u)
#define XCP_CRO_SET_SEGMENT_MODE_SEGMENT            (2u)

#define XCP_CRM_SET_SEGMENT_MODE_LEN                (1u)
/**\} */

/** 
 * \defgroup GET_SEGMENT_MODE_IDX GET_SEGMENT_MODE_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
#define XCP_CRO_GET_SEGMENT_MODE_LEN                (3u)
#define XCP_CRO_GET_SEGMENT_MODE_SEGMENT            (2u)

#define XCP_CRM_GET_SEGMENT_MODE_LEN                (3u)
#define XCP_CRM_GET_SEGMENT_MODE_MODE               (2u)
/**\} */

/** 
 * \defgroup COPY_CAL_PAGE_IDX COPY_CAL_PAGE_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup calDef
 * \{
 */
#define CRO_COPY_CAL_PAGE_LEN                       (5u)
#define CRO_COPY_CAL_PAGE_SRC_SEGMENT               (1u)
#define CRO_COPY_CAL_PAGE_SRC_PAGE                  (2u)
#define CRO_COPY_CAL_PAGE_DEST_SEGMENT              (3u)
#define CRO_COPY_CAL_PAGE_DEST_PAGE                 (4u)

#define CRM_COPY_CAL_PAGE_LEN                       (1u)
/**\} */

/** 
 * \defgroup SET_DAQ_PTR_IDX SET_DAQ_PTR_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_SET_DAQ_PTR_LEN                     (6u)
#define XCP_CRO_SET_DAQ_PTR_DAQ                     (2u) /* and 3 */
#define XCP_CRO_SET_DAQ_PTR_ODT                     (4u)
#define XCP_CRO_SET_DAQ_PTR_IDX                     (5u)

#define XCP_CRM_SET_DAQ_PTR_LEN                     (1u)
/**\} */

/** 
 * \defgroup WRITE_DAQ_IDX WRITE_DAQ_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_WRITE_DAQ_LEN                       (8u)
#define XCP_CRO_WRITE_DAQ_BITOFFSET                 (1u)
#define XCP_CRO_WRITE_DAQ_SIZE                      (2u)
#define XCP_CRO_WRITE_DAQ_EXT                       (3u)
#define XCP_CRO_WRITE_DAQ_ADDR                      (4u) /* 5, 6 and 7 */

#define XCP_CRM_WRITE_DAQ_LEN                       (1u)
/**\} */

/** 
 * \defgroup WRITE_DAQ_MULTIPLE_IDX WRITE_DAQ_MULTIPLE_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_WRITE_DAQ_MULTIPLE_LEN              (8u)
#define XCP_CRO_WRITE_DAQ_MULTIPLE_COMMAND          (0u)
#define XCP_CRO_WRITE_DAQ_MULTIPLE_NODAQ            (1u)

#define XCP_CRM_WRITE_DAQ_MULTIPLE_LEN              (1u)
/**\} */

/** 
 * \defgroup SET_DAQ_LIST_MODE_IDX SET_DAQ_LIST_MODE_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_SET_DAQ_LIST_MODE_LEN               (8u)
#define XCP_CRO_SET_DAQ_LIST_MODE_MODE              (1u)
#define XCP_CRO_SET_DAQ_LIST_MODE_DAQ               (2u) /* and 3 */
#define XCP_CRO_SET_DAQ_LIST_MODE_EVENTCHANNEL      (4u) /* and 5 */
#define XCP_CRO_SET_DAQ_LIST_MODE_PRESCALER         (6u)
#define XCP_CRO_SET_DAQ_LIST_MODE_PRIORITY          (7u)

#define XCP_CRM_SET_DAQ_LIST_MODE_LEN               (6u)
/**\} */

/** 
 * \defgroup GET_DAQ_LIST_MODE_IDX GET_DAQ_LIST_MODE_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_GET_DAQ_LIST_MODE_LEN               (4u)
#define XCP_CRO_GET_DAQ_LIST_MODE_DAQ               (2u)

#define XCP_CRM_GET_DAQ_LIST_MODE_LEN               (8u)
#define XCP_CRM_GET_DAQ_LIST_MODE_MODE              (1u)
#define XCP_CRM_GET_DAQ_LIST_MODE_EVENTCHANNEL      (4u)
#define XCP_CRM_GET_DAQ_LIST_MODE_PRESCALER         (6u)
#define XCP_CRM_GET_DAQ_LIST_MODE_PRIORITY          (7u)
/**\} */

/** 
 * \defgroup START_STOP_DAQ_LIST_IDX START_STOP_DAQ_LIST_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_START_STOP_LEN                      (4u)
#define XCP_CRO_START_STOP_MODE                     (1u)
#define XCP_CRO_START_STOP_DAQ                      (2u)

#define XCP_CRM_START_STOP_LEN                      (2u)
#define XCP_CRM_START_STOP_FIRST_PID                (1u)

#define XCP_CMO_START_STOP_STOP_DAQ_LIST            (0x00u)
#define XCP_CMO_START_STOP_START_DAQ_LIST           (0x01u)
#define XCP_CMO_START_STOP_SELECT_DAQ_LIST          (0x02u)
/**\} */

/** 
 * \defgroup START_STOP_SYNCH_IDX START_STOP_SYNCH_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_START_STOP_SYNC_LEN                 (2u)
#define XCP_CRO_START_STOP_SYNC_MODE                (1u)

#define XCP_CRM_START_STOP_SYNC_LEN                 (1u)

#define XCP_CMO_START_STOP_SYNCH_STOP_ALL           (0x00u)
#define XCP_CMO_START_STOP_SYNCH_START_SELECTED     (0x01u)
#define XCP_CMO_START_STOP_SYNCH_STOP_SELECTED      (0x02u)
/**\} */

/** 
 * \defgroup GET_DAQ_CLOCK_IDX GET_DAQ_CLOCK_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_GET_DAQ_CLOCK_LEN                   (1u)

#define XCP_CRM_GET_DAQ_CLOCK_LEN                   (8u)
#define XCP_CRM_GET_DAQ_CLOCK_TIME                  (4u)
/**\} */

/** 
 * \defgroup GET_DAQ_PROCESSOR_INFO_IDX GET_DAQ_PROCESSOR_INFO_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_GET_DAQ_PROCESSOR_INFO_LEN          (1u)

#define XCP_CRM_GET_DAQ_PROCESSOR_INFO_LEN          (8u)
#define XCP_CRM_GET_DAQ_PROCESSOR_INFO_PROPERTIES   (1u)
#define XCP_CRM_GET_DAQ_PROCESSOR_INFO_MAX_DAQ      (2u)
#define XCP_CRM_GET_DAQ_PROCESSOR_INFO_MAX_EVENT    (4u)
#define XCP_CRM_GET_DAQ_PROCESSOR_INFO_MIN_DAQ      (6u)
#define XCP_CRM_GET_DAQ_PROCESSOR_INFO_DAQ_KEY_BYTE (7u)
/**\} */

/** 
 * \defgroup GET_DAQ_RESOLUTION_INFO_IDX GET_DAQ_RESOLUTION_INFO_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_GET_DAQ_RESOLUTION_INFO_LEN                 (1u)

#define XCP_CRM_GET_DAQ_RESOLUTION_INFO_LEN                 (8u)
#define XCP_CRM_GET_DAQ_RESOLUTION_INFO_GRANULARITY_DAQ     (1u)
#define XCP_CRM_GET_DAQ_RESOLUTION_INFO_MAX_SIZE_DAQ        (2u)
#define XCP_CRM_GET_DAQ_RESOLUTION_INFO_GRANULARITY_STIM    (3u)
#define XCP_CRM_GET_DAQ_RESOLUTION_INFO_MAX_SIZE_STIM       (4u)
#define XCP_CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_MODE      (5u)
#define XCP_CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_TICKS     (6u)
/**\} */

/** 
 * \defgroup GET_DAQ_EVENT_INFO_IDX GET_DAQ_EVENT_INFO_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_GET_DAQ_EVENT_INFO_LEN                      (4u)
#define XCP_CRO_GET_DAQ_EVENT_INFO_EVENT                    (2u)

#define XCP_CRM_GET_DAQ_EVENT_INFO_LEN                      (7u)
#define XCP_CRM_GET_DAQ_EVENT_INFO_PROPERTIES               (1u)
#define XCP_CRM_GET_DAQ_EVENT_INFO_MAX_DAQ_LIST             (2u)
#define XCP_CRM_GET_DAQ_EVENT_INFO_NAME_LENGTH              (3u)
#define XCP_CRM_GET_DAQ_EVENT_INFO_TIME_CYCLE               (4u)
#define XCP_CRM_GET_DAQ_EVENT_INFO_TIME_UNIT                (5u)
#define XCP_CRM_GET_DAQ_EVENT_INFO_PRIORITY                 (6u)
/**\} */

/** 
 * \defgroup ALLOC_DAQ_IDX ALLOC_DAQ_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup stdDef
 * \{
 */
#define XCP_CRO_ALLOC_DAQ_LEN                       (4u)
#define XCP_CRO_ALLOC_DAQ_COUNT                     (2u) /* and 3 */

#define XCP_CRM_ALLOC_DAQ_LEN                       (1u)
/**\} */

/** 
 * \defgroup ALLOC_ODT_IDX ALLOC_ODT_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_ALLOC_ODT_LEN                       (5u)
#define XCP_CRO_ALLOC_ODT_DAQ                       (2u) /* and 3 */
#define XCP_CRO_ALLOC_ODT_COUNT                     (4u)

#define XCP_CRM_ALLOC_ODT_LEN                       (1u)
/**\} */

/** 
 * \defgroup ALLOC_ODT_ENTRY_IDX ALLOC_ODT_ENTRY_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup daqDef
 * \{
 */
#define XCP_CRO_ALLOC_ODT_ENTRY_LEN                 (6u)
#define XCP_CRO_ALLOC_ODT_ENTRY_DAQ                 (2u) /* and 3 */
#define XCP_CRO_ALLOC_ODT_ENTRY_ODT                 (4u)
#define XCP_CRO_ALLOC_ODT_ENTRY_COUNT               (5u)

#define XCP_CRM_ALLOC_ODT_ENTRY_LEN                 (1u)
/**\} */

/** 
 * \defgroup PROGRAM_START_IDX PROGRAM_START_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pgmDef
 * \{
 */
#define XCP_CRO_PROGRAM_START_LEN                   (1u)

#define XCP_CRM_PROGRAM_START_LEN                   (7u)
#define XCP_CRM_PROGRAM_COMM_MODE_PGM               (2u) 
#define XCP_CRM_PROGRAM_MAX_CTO_PGM                 (3u) 
#define XCP_CRM_PROGRAM_MAX_BS_PGM                  (4u) 
#define XCP_CRM_PROGRAM_MIN_ST_PGM                  (5u) 
#define XCP_CRM_PROGRAM_QUEUE_SIZE_PGM              (6u)
/**\} */

/** 
 * \defgroup PROGRAM_CLEAR_IDX PROGRAM_CLEAR_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pgmDef
 * \{
 */
#define XCP_CRO_PROGRAM_CLEAR_LEN                   (8u)
#define XCP_CRO_PROGRAM_CLEAR_MODE                  (1u)
#define XCP_CRO_PROGRAM_CLEAR_SIZE                  (4u)

#define XCP_CRM_PROGRAM_CLEAR_LEN                   (1u)
/**\} */

/** 
 * \defgroup PROGRAM_IDX PROGRAM_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pgmDef
 * \{
 */
#define XCP_CRO_PROGRAM_LEN                         (2u) /* + CRO_PROGRAM_SIZE */ 
#define XCP_CRO_PROGRAM_SIZE                        (1u)
#define XCP_CRO_PROGRAM_DATA                        (2u)

#define XCP_CRM_PROGRAM_LEN                         (1u)
/**\} */

/** 
 * \defgroup GET_PGM_PROCESSOR_INFO_IDX GET_PGM_PROCESSOR_INFO_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pgmDef
 * \{
 */
#define XCP_CRO_GET_PGM_PROCESSOR_INFO_LEN          (1u)

#define XCP_CRM_GET_PGM_PROCESSOR_INFO_LEN          (3u)
#define XCP_CRM_GET_PGM_PROCESSOR_INFO_PROPERTIES   (1u)
#define XCP_CRM_GET_PGM_PROCESSOR_INFO_MAX_SECTOR   (2u)
/**\} */

/** 
 * \defgroup GET_SECTOR_INFO_IDX GET_SECTOR_INFO_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pgmDef
 * \{
 */
#define XCP_CRO_PROGRAM_GET_SECTOR_INFO_LEN         (3u)
#define XCP_CRO_PROGRAM_GET_SECTOR_INFO_MODE        (1u)
#define XCP_CRO_PROGRAM_GET_SECTOR_INFO_NUMBER      (2u)

#define XCP_CRM_PROGRAM_GET_SECTOR_INFO_LEN         (8u)
#define XCP_CRM_PROGRAM_GET_SECTOR_CLEAR_SEQ_NUM    (1u)
#define XCP_CRM_PROGRAM_GET_SECTOR_PGM_SEQ_NUM      (2u)
#define XCP_CRM_PROGRAM_GET_SECTOR_PGM_METHOD       (3u)
#define XCP_CRM_PROGRAM_GET_SECTOR_SECTOR_INFO      (4u)
#define XCP_CRM_PROGRAM_GET_SECTOR_NAME_LENGTH      (1u)
/**\} */

/** 
 * \defgroup PROGRAM_PREPARE_IDX PROGRAM_PREPARE_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pgmDef
 * \{
 */
#define XCP_CRO_PROGRAM_PREPARE_LEN                 (4u)
#define XCP_CRO_PROGRAM_PREPARE_SIZE                (2u)

#define XCP_CRM_PROGRAM_PREPARE_LEN                 (1u)
/**\} */

/** 
 * \defgroup PROGRAM_FORMAT_IDX PROGRAM_FORMAT_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pgmDef
 * \{
 */
#define XCP_CRO_PROGRAM_FORMAT_LEN                  (5u)
#define XCP_CRO_PROGRAM_FORMAT_COMPRESSION_METHOD   (1u)
#define XCP_CRO_PROGRAM_FORMAT_ENCRYPTION_METHOD    (2u)
#define XCP_CRO_PROGRAM_FORMAT_PROGRAMMING_METHOD   (3u)
#define XCP_CRO_PROGRAM_FORMAT_ACCESS_METHOD        (4u)

#define XCP_CRM_PROGRAM_FORMAT_LEN                  (1u)
/**\} */

/** 
 * \defgroup PROGRAM_NEXT_IDX PROGRAM_NEXT_IDX
 * \details The Lock Register is write-only. Reading the register will return 0x00000000.
 * \ingroup pgmDef
 * \{
 */
#define XCP_CRO_PROGRAM_NEXT_LEN                    (2u) /*<! + size */
#define XCP_CRO_PROGRAM_NEXT_SIZE                   (1u)
#define XCP_CRO_PROGRAM_NEXT_DATA                   (2u)

#define XCP_CRM_PROGRAM_NEXT_LEN                    (3u)
#define XCP_CRM_PROGRAM_NEXT_ERR_SEQUENCE           (1u)
#define XCP_CRM_PROGRAM_NEXT_SIZE_EXPECTED_DATA     (2u)
/**\} */

/** 
 * \defgroup PROGRAM_MAX_IDX PROGRAM_MAX_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pgmDef
 * \{
 */
#define XCP_CRO_PROGRAM_MAX_DATA                    (1u)

#define XCP_CRM_PROGRAM_MAX_LEN                     (1u)
/**\} */

/** 
 * \defgroup PROGRAM_VERIFY_IDX PROGRAM_VERIFY_IDX
 * \details  Indices to access XCP Command Request and Responses.
 * \ingroup pgmDef
 * \{
 */
#define XCP_CRO_PROGRAM_VERIFY_LEN                  (8u)
#define XCP_CRO_PROGRAM_VERIFY_MODE                 (1u)
#define XCP_CRO_PROGRAM_VERIFY_TYPE                 (2u)
#define XCP_CRO_PROGRAM_VERIFY_VALUE                (4u)

#define XCP_CRM_PROGRAM_VERIFY_LEN                  (1u)
/**\} */

/*-------------------------------------------------------------------------*/
/* COMMON GLOBAL CONSTANT MACROS */
#define XCP_MAX_DOWNLOAD_BYTES                      (254u)

#define XCP_UPPER_LIMIT_LEFT_SHIFT                  (31u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */

/** \ingroup UNLOCK_IDX */
#define XCP_CRO_UNLOCK_MAX_KEY_SIZE(channel)        ((uint8)(Xcp_ChannelInfo[(channel)].MaxCto - 2))
/** \ingroup UPLOAD_IDX */
#define XCP_CRM_UPLOAD_MAX_SIZE(channel)            ((uint8)(Xcp_ChannelInfo[(channel)].MaxCto - 1))
/** \ingroup SHORT_UPLOAD_IDX */
#define XCP_CRM_SHORT_UPLOAD_MAX_SIZE(channel)      ((uint8)(Xcp_ChannelInfo[(channel)].MaxCto - 1))

/** \ingroup DOWNLOAD_MAX_IDX */
#define XCP_CRO_DOWNLOAD_MAX_SIZE(channel)          ((uint8)(Xcp_ChannelInfo[(channel)].MaxCto - 2))
/** \ingroup DOWNLOAD_NEXT_IDX */
#define XCP_CRO_DOWNLOAD_NEXT_MAX_SIZE(channel)     ((uint8)(Xcp_ChannelInfo[(channel)].MaxCto - 2))
/** \ingroup DOWNLOAD_MAX_IDX */
#define XCP_CRO_DOWNLOAD_MAX_MAX_SIZE(channel)      ((uint8)(Xcp_ChannelInfo[(channel)].MaxCto - 1))
/** \ingroup SHORT_DOWNLOAD_IDX */
#define XCP_CRM_SHORT_DOWNLOAD_MAX_SIZE(channel)    ((uint8)(Xcp_ChannelInfo[(channel)].MaxCto - 8))

/** \ingroup PROGRAM_IDX */
#define XCP_CRO_PROGRAM_MAX_SIZE(channel)           ((uint8)(Xcp_ChannelInfo[(channel)].MaxCto - 2))
/** \ingroup PROGRAM_MAX_IDX */
#define XCP_CRO_PROGRAM_MAX_MAX_SIZE(channel)       ((uint8)(Xcp_ChannelInfo[(channel)].MaxCto - 1))

/** \ingroup WRITE_DAQ_MULTIPLE_IDX */
#define XCP_CRO_WRITE_DAQ_MULTIPLE_BITOFFSET(i)     (2 + (8*(i))) 
/** \ingroup WRITE_DAQ_MULTIPLE_IDX */
#define XCP_CRO_WRITE_DAQ_MULTIPLE_SIZE(i)          (3 + (8*(i))) 
/** \ingroup WRITE_DAQ_MULTIPLE_IDX */
#define XCP_CRO_WRITE_DAQ_MULTIPLE_EXT(i)           (8 + (8*(i))) 
/** \ingroup WRITE_DAQ_MULTIPLE_IDX */
#define XCP_CRO_WRITE_DAQ_MULTIPLE_ADDR(i)          (4 + (2*((i)*4)))  /* DWORD steps */


/** \ingroup hlp */
#define XCP_MAX_DOWNLOAD_BLOCK_SIZE(channel)        ((uint8)(((XCP_MAX_DOWNLOAD_BYTES) / (XCP_CRO_DOWNLOAD_MAX_SIZE((channel)))) + 1)) 
/** \ingroup hlp */
#define XCP_SENDEVENT_CHECK_EVENTCODE(ec)           (((ec) == 0x04) || (((ec) >= 0x0C) && ((ec) <= 0xFD))) 
/** \ingroup hlp */
#define XCP_SENDEVENT_MAX_LENGTH(channel)           ((uint8)(Xcp_ChannelInfo[(channel)].MaxCto - 2)) 


/** \ingroup hlp */
#define Xcp_GetVal16(p)                                     ((uint16)(((P2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT))(p))[0])          \
                                                  | (uint16)((uint16)(((P2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT))(p))[1]) << 8u))

/** \ingroup hlp */
#define Xcp_GetVal32(p)                                     (((uint32)((P2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT))(p))[0])          \
                                                  | (uint32)(((uint32)((P2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT))(p))[1]) << 8u)   \
                                                  | (uint32)(((uint32)((P2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT))(p))[2]) << 16u)  \
                                                  | (uint32)(((uint32)((P2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT))(p))[3]) << 24u)) 

/* PRQA S 3412 8 */ /* MD_MSR_19.4 */
/** \ingroup hlp */
#define Xcp_PutVal16(p, data)                       (((P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))(p))[0] = (uint8)((data) & 0xFF));          \
                                                    (((P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))(p))[1] = (uint8)(((data) >> 8u) & 0xFF)); 
/** \ingroup hlp */
#define Xcp_PutVal32(p, data)                       (((P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))(p))[0] = (uint8)((data) & 0xFF));          \
                                                    (((P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))(p))[1] = (uint8)(((data) >> 8u) & 0xFF));  \
                                                    (((P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))(p))[2] = (uint8)(((data) >> 16u) & 0xFF)); \
                                                    (((P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))(p))[3] = (uint8)(((data) >> 24u) & 0xFF)); 

/** \ingroup daqDef */
#define XCP_MAX_ODT_ENTRY_SIZE(XCP_CHANNEL_IDX)     (Xcp_ChannelInfo[(XCP_CHANNEL_IDX)].MaxDto - 1u)


#if( XCP_AUTOSAR_CRC_MODULE == STD_ON )
  /* Macros for calculation of checksum with AUTOSAR CRC module. */
# if( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16CITT )
   /** \ingroup hlp */
#  define XcpCalculateCrc(data_ptr, length, start_value)  Crc_CalculateCRC16((data_ptr), (length), (start_value), FALSE) 
# endif
# if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC32 )
   /** \ingroup hlp */
#  define XcpCalculateCrc(data_ptr, length, start_value)  Crc_CalculateCRC32((data_ptr), (length), (start_value), FALSE) 
# endif
#endif  /* defined ( XCP_ENABLE_AUTOSAR_CRC_MODULE ) */

/* PRQA S 3410 3 */ /* MD_Xcp_3410 */
#define Xcp_CallTlFunction_1_Param( channel, function )                 ( Xcp_TlApi[Xcp_ChannelInfo[(channel)].ActiveTl].function((channel)) )  
#define Xcp_CallTlFunction_2_Param( channel, function, param )          ( Xcp_TlApi[Xcp_ChannelInfo[(channel)].ActiveTl].function((channel), (param)) )  
#define Xcp_CallTlFunction_3_Param( channel, function, param1, param2 ) ( Xcp_TlApi[Xcp_ChannelInfo[(channel)].ActiveTl].function((channel), (param1), (param2)) )  

/* PRQA L:FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */


#endif /* XCP_PRIV_H */

/**********************************************************************************************************************
 *  END OF FILE: Xcp_Priv.h
 *********************************************************************************************************************/
