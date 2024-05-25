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
/**        \file  Xcp.h
 *        \brief  XCP header file
 *
 *      \details  Header of the XCP protocol layer.
 *                XCP V1.1 slave device driver
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Andreas Herkommer             vishr         Vector Informatik GmbH
 *  David Zentner                 viszda        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author    Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2016-07-08  vishr
 *                        viszda    ESCAN00094455 Creation
 *  02.00.00  2017-04-25  vishr     ESCAN00094537 BETA version - the BSW module has a feature with BETA state (FEAT-2084)
 *                                  FEAT-2618     [XCP] Release of FEAT-2084 (XCP MultiCore)
 *  02.01.00  2017-08-28  vishr     ESCAN00096133 Compiler warning: warning C4310: cast truncates constant value
 *  03.00.00  2017-10-23  vishr     ESCAN00096911 Compiler warning: type qualifier is meaningless on cast type
 *                        vishr     ESCAN00097141 The Xcp Module ID is not according to AR 4
 *                        vishr     ESCAN00096776 Execution of daq lists may fail.
 *            2017-11-06  vishr     ESCAN00097288 When fixed timestamps are configured but the XCP Master does not
 *                                                request them, no negative response is returned
 *                        vishr     ESCAN00097176 When the XCP Master requests Timestamps but none are configured no
 *                                                negative response is returned
 *                        vishr     ESCAN00097367 DAQ overrun indication not deactivateable
 *                        vishr     ESCAN00097377 Communication not possible in Multi Channel use case on channels > 0
 *  03.00.01  2018-05-24  vishr     ESCAN00099495 Measurement failure when more than 255 measurement values are configured and used
 *                        vishr     ESCAN00099092 CONNECT will stop a running DAQ measurement from resume mode
 *                        vishr     ESCAN00097925 Memory read access exception due to incorrect address conversion
 *  03.00.02  2018-09-18  vishr     ESCAN00099905 XCP internal memory not initialized correctly in huge configurations.
 *                        vishr     ESCAN00100579 bswmd: Wrong enum naming for CRC_16_CITT
 *                        vishr     ESCAN00100583 XcpAppl_UserService is missing channel parameter
 *                        vishr     ESCAN00099909 GET_DAQ_PROCESSOR_INFO reported parameter MAX_DAQ is wrong
 *  04.00.00  2018-11-09  vishr     STORYC-4424   Absolute DAQ, relative ODT
 *                        vishr     ESCAN00101269 The command DOWNLOAD\UPLOAD accepts a size of 0
 *                        vishr     ESCAN00100243 incorrect ODT messages assembled if ODT Entries are initialized incompletely
 *                        vishr     ESCAN00099665 Xcp_Event throws DET check if called before Xcp_Init
 *                        vishr     ESCAN00101320 STIM not working correctly when more than one ODT is used.
 *********************************************************************************************************************/

/* Configuration, interrupt handling and call-back headers use different names for the multiple inclusion protection
 * define, shown in this example. The appropriate names for these files can be taken from this list:
 *
 * Xcp_Cfg.h:     XCP_CFG_H
 */
/* PRQA S 883 EOF */ /* MD_Xcp_0883 */

#if !defined (XCP_H)
# define XCP_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Xcp_Cfg.h"
# include "Xcp_Lcfg.h"
# include "Xcp_Types.h"
# include "ComStack_Types.h"

# include "_XcpAppl.h"

/* Include the Transport Layer for CAN (AUTOSAR CAN Interface) if available. */
# if defined ( XCP_TRANSPORT_LAYER_TYPE_CAN_ASR )
#  include "CanXcp.h"
#  include "CanXcp_Cfg.h"
# endif

/* Include the Transport Layer for FlexRay (AUTOSAR FlexRay Interface) if available. */
# if defined ( XCP_TRANSPORT_LAYER_TYPE_FLEXRAY_ASR )
#  include "FrXcp.h"
# endif

/* Include the Transport Layer for Ethernet if available. */
# if defined ( XCP_TRANSPORT_LAYER_TYPE_TCPIP_ASR )
#  include "TcpIpXcp.h"
# endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if( XCP_NUMBER_OF_CHANNELS > 1 )
# define XCP_CHANNEL_IDX (XcpChannel)
#else
# define XCP_CHANNEL_IDX (0u)
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define XCP_VENDOR_ID                        (30u)
# define XCP_MODULE_ID                        (212u)

/* AUTOSAR Software specification version information */
# define XCP_AR_RELEASE_MAJOR_VERSION         (4u)
# define XCP_AR_RELEASE_MINOR_VERSION         (2u)
# define XCP_AR_RELEASE_REVISION_VERSION      (2u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define XCP_SW_MAJOR_VERSION                 (4u)
# define XCP_SW_MINOR_VERSION                 (0u)
# define XCP_SW_PATCH_VERSION                 (0u)

# define XCP_INSTANCE_ID_DET                  (0x00u)

/* ASAM Spec information */
# define XCP_PROTOCOL_LAYER_VERSION           (0x0101)
# define XCP_TRANSPORT_LAYER_VERSION          (0x0101)

/* ----- API service IDs ----- */
# define XCP_SID_INIT                         (0x00u) /*!< Service ID: Xcp_Init() */
# define XCP_SID_SEND_EVENT                   (0x03u) /*!< Service ID: Xcp_SendEvent() */
# define XCP_SID_PUT_CHAR                     (0x04u) /*!< Service ID: Xcp_PutChar() */
# define XCP_SID_PRINT                        (0x05u) /*!< Service ID: Xcp_Print() */
# define XCP_SID_DISCONNECT                   (0x06u) /*!< Service ID: Xcp_Disconnect() */
# define XCP_SID_SEND_CRM                     (0x07u) /*!< Service ID: Xcp_SendCrm() */
# define XCP_SID_GET_XCP_DATA_POINTER         (0x08u) /*!< Service ID: Xcp_GetXcpDataPointer() */
# define XCP_SID_GET_VERSION_INFO             (0x0Au) /*!< Service ID: Xcp_GetVersionInfo() */
# define XCP_SID_TL_RX_INDICATION             (0x0Bu) /*!< Service ID: Xcp_TlRxIndication() */
# define XCP_SID_TL_TX_CONFIRMATION           (0x0Cu) /*!< Service ID: Xcp_TlTxConfirmation() */
# define XCP_SID_GET_SESSION_STATUS           (0x0Eu) /*!< Service ID: Xcp_GetSessionStatus() */
# define XCP_SID_SET_ACTIVE_TL                (0x0Fu) /*!< Service ID: Xcp_SetActiveTl() */
# define XCP_SID_GET_ACTIVE_TL                (0x10u) /*!< Service ID: Xcp_GetActiveTl() */
# define XCP_SID_SET_STIM_MODE                (0x11u) /*!< Service ID: Xcp_SetStimMode() */
# define XCP_SID_MODIFY_PROTECTION_STATE      (0x14u) /*!< Service ID: Xcp_ModifyProtectionStatus() */
# define XCP_SID_MAINFUNCTION                 (0xC8u) /*!< Service ID: Xcp_MainFunction() */
# define XCP_SID_EVENT                        (0xC9u) /*!< Service ID: Xcp_Event() */
# define XCP_SID_STIM_EVENT_STATUS            (0xFDu) /*!< Service ID: Xcp_StimEventStatus() */

/* ----- Error codes ----- */ /* \trace SPEC-4004 */
# define XCP_E_NO_ERROR                       (0x00u) /*!< used to check if no error occurred - use a value unequal to any error code */
# define XCP_E_PARAM_CONFIG                   (0x0Au) /*!< Error code: API service Xcp_Init() called with wrong parameter */
# define XCP_E_PARAM_CHANNEL                  (0x0Bu) /*!< Error Code: API service used with an invalid channel identifier or channel
                                                              was not configured for the functionality of the calling API */
# define XCP_E_PARAM_EVENTCHANNEL             (0x0Cu) /*!< Error Code: API service used with an invalid event channel identifier or
                                                              event channel was not configured for the functionality of the calling API */
# define XCP_E_PARAM_POINTER                  (0x0Du) /*!< Error code: API service used with invalid pointer parameter (NULL) */
# define XCP_E_PARAM_VALUE                    (0x0Eu) /*!< Error Code: API service used with an invalid channel identifier or channel was not configured for the functionality of the calling API */
# define XCP_E_UNINIT                         (0x10u) /*!< Error code: API service used without module initialization */
# define XCP_E_ALREADY_INITIALIZED            (0x11u) /*!< Error code: The service Xcp_Init() is called while the module is already initialized */
# define XCP_E_INVALID_CORE_ID                (0x12u) /*!< Error code: The service Xcp_Event() is called with a wrong channel id on a wrong core */

/* ----- Modes ----- */
# define XCP_UNINIT                           (0x00u)
# define XCP_INIT                             (0x01u)

# define kXcp_Control_Disable                 (0x00u)
# define kXcp_Control_Enable                  (0x01u)

# define XCP_FALSE                            (0x00u)
# define XCP_TRUE                             (0x01u)

/* Check if a XCP stimulation event can perform or delete the buffers */
/* Returns 1 (TRUE) if new stimulation data is available */
# if( XCP_STIM == STD_ON )
  /* action */
#  define XCP_STIM_CHECK_ODT_BUFFER           (0x01u)
#  define XCP_STIM_RESET_ODT_BUFFER           (0x02u)

#  define XCP_NO_STIM_DATA_AVAILABLE          (0x00u)
#  define XCP_STIM_DATA_AVAILABLE             (0x01u)

#  define XCP_STIM_SINGLE_SHOT_MODE           (0x00u)
#  define XCP_STIM_CONTINUOUS_MODE            (0x01u)
# endif

/* ----- Return values for Xcp_Event() ----- */
#define XCP_EVENT_NOP                         (0x00u) /*!< Inactive (DAQ not running, Event not configured) */
#define XCP_EVENT_DAQ                         (0x01u) /*!< DAQ active */
#define XCP_EVENT_DAQ_OVERLOAD                (0x02u) /*!< DAQ queue overflow */
#define XCP_EVENT_DAQ_TIMEOUT                 (0x04u) /*!< Timeout supervision violation */
#define XCP_EVENT_STIM                        (0x08u) /*!< STIM active */
#define XCP_EVENT_STIM_OVERRUN                (0x10u) /*!< STIM data not available */


/* ----- DAQ status ----- */
/* DAQ_LIST_MODE (GET_DAQ_LIST_MODE, SET_DAQ_LIST_MODE) */
#define XCP_DAQ_LIST_SELECTED                 (0x01u) /*!< Start/Stop selection */
#define XCP_DAQ_LIST_DIRECTION                (0x02u) /*!< Data Stimulation Mode */
#define XCP_DAQ_LIST_TIMESTAMP                (0x10u) /*!< Timestamps active */
#define XCP_DAQ_LIST_NO_PID                   (0x20u) /*!< No PID */
#define XCP_DAQ_LIST_RUNNING                  (0x40u) /*!< DAQ list is running */
#define XCP_DAQ_LIST_RESUME                   (0x80u) /*!< Resume Mode */

#define XCP_DAQ_LIST_RESERVED                 (0x08u)


/*-------------------------------------------------------------------------*/
/* Packet Identifiers Slave -> Master */
#define XCP_PID_RES                           (0xFFu) /*!< response packet        */
#define XCP_PID_ERR                           (0xFEu) /*!< error packet           */
#define XCP_PID_EV                            (0xFDu) /*!< event packet           */
#define XCP_PID_SERV                          (0xFCu) /*!< service request packet */


/*-------------------------------------------------------------------------*/
/* Command Error Codes */
#define XCP_ERR_CMD_SYNCH                     (0x00u)

#define XCP_ERR_CMD_BUSY                      (0x10u)
#define XCP_ERR_DAQ_ACTIVE                    (0x11u)
#define XCP_ERR_PRM_ACTIVE                    (0x12u)

#define XCP_ERR_CMD_UNKNOWN                   (0x20u)
#define XCP_ERR_CMD_SYNTAX                    (0x21u)
#define XCP_ERR_OUT_OF_RANGE                  (0x22u)
#define XCP_ERR_WRITE_PROTECTED               (0x23u)
#define XCP_ERR_ACCESS_DENIED                 (0x24u)
#define XCP_ERR_ACCESS_LOCKED                 (0x25u)
#define XCP_ERR_PAGE_NOT_VALID                (0x26u)
#define XCP_ERR_PAGE_MODE_NOT_VALID           (0x27u)
#define XCP_ERR_SEGMENT_NOT_VALID             (0x28u)
#define XCP_ERR_SEQUENCE                      (0x29u)
#define XCP_ERR_DAQ_CONFIG                    (0x2Au)

#define XCP_ERR_MEMORY_OVERFLOW               (0x30u)
#define XCP_ERR_GENERIC                       (0x31u)
#define XCP_ERR_VERIFY                        (0x32u)
#define XCP_ERR_RESOURCE_TEMP_NOT_ACCESSIBLE  (0x33u)


/*-------------------------------------------------------------------------*/
/* Command Return Codes */
#define XCP_CRC_CMD_SYNCH                     (0x00u)

#define XCP_CRC_CMD_BUSY                      (0x10u)
#define XCP_CRC_DAQ_ACTIVE                    (0x11u)
#define XCP_CRC_PRM_ACTIVE                    (0x12u)

#define XCP_CRC_CMD_UNKNOWN                   (0x20u)
#define XCP_CRC_CMD_SYNTAX                    (0x21u)
#define XCP_CRC_OUT_OF_RANGE                  (0x22u)
#define XCP_CRC_WRITE_PROTECTED               (0x23u)
#define XCP_CRC_ACCESS_DENIED                 (0x24u)
#define XCP_CRC_ACCESS_LOCKED                 (0x25u)
#define XCP_CRC_PAGE_NOT_VALID                (0x26u)
#define XCP_CRC_PAGE_MODE_NOT_VALID           (0x27u)
#define XCP_CRC_SEGMENT_NOT_VALID             (0x28u)
#define XCP_CRC_SEQUENCE                      (0x29u)
#define XCP_CRC_DAQ_CONFIG                    (0x2Au)

#define XCP_CRC_MEMORY_OVERFLOW               (0x30u)
#define XCP_CRC_GENERIC                       (0x31u)
#define XCP_CRC_VERIFY                        (0x32u)
#define XCP_CRC_RESOURCE_TEMP_NOT_ACCESSIBLE  (0x33u)


/*-------------------------------------------------------------------------*/
/* Return values */
#define XCP_CMD_OK                            (0x00u)
#define XCP_CMD_PENDING                       (0x01u)

#define XCP_CMD_BUSY                          (0x10u)
#define XCP_CMD_UNKNOWN                       (0x20u)
#define XCP_CMD_SYNTAX                        (0x21u)
#define XCP_CMD_OUT_OF_RANGE                  (0x22u)
#define XCP_CMD_PROTECTED                     (0x23u)
#define XCP_CMD_DENIED                        (0x24u)
#define XCP_CMD_ERROR                         (0xFFu)


/*-------------------------------------------------------------------------*/
/* Event Codes */
#define XCP_EVC_RESUME_MODE                   (0x00)
#define XCP_EVC_CLEAR_DAQ                     (0x01)
#define XCP_EVC_STORE_DAQ                     (0x02)
#define XCP_EVC_STORE_CAL                     (0x03)
#define XCP_EVC_CMD_PENDING                   (0x05)
#define XCP_EVC_DAQ_OVERLOAD                  (0x06)
#define XCP_EVC_SESSION_TERMINATED            (0x07)
#define XCP_EVC_TIME_SYNC                     (0x08)
#define XCP_EVC_STIM_TIMEOUT                  (0x09)
#define XCP_EVC_SLEEP                         (0x0A)
#define XCP_EVC_WAKE_UP                       (0x0B)
#define XCP_EVC_USER                          (0xFE)
#define XCP_EVC_TRANSPORT                     (0xFF)


/*-------------------------------------------------------------------------*/
/* DAQ Timestamp Unit */
#define XCP_DAQ_TIMESTAMP_UNIT_1NS            (0<<4)
#define XCP_DAQ_TIMESTAMP_UNIT_10NS           (1<<4)
#define XCP_DAQ_TIMESTAMP_UNIT_100NS          (2<<4)
#define XCP_DAQ_TIMESTAMP_UNIT_1US            (3<<4)
#define XCP_DAQ_TIMESTAMP_UNIT_10US           (4<<4)
#define XCP_DAQ_TIMESTAMP_UNIT_100US          (5<<4)
#define XCP_DAQ_TIMESTAMP_UNIT_1MS            (6<<4)
#define XCP_DAQ_TIMESTAMP_UNIT_10MS           (7<<4)
#define XCP_DAQ_TIMESTAMP_UNIT_100MS          (8<<4)
#define XCP_DAQ_TIMESTAMP_UNIT_1S             (9<<4)
#define XCP_DAQ_TIMESTAMP_UNIT_1PS            (10<<4)
#define XCP_DAQ_TIMESTAMP_UNIT_10PS           (11<<4)
#define XCP_DAQ_TIMESTAMP_UNIT_100PS          (12<<4)

/*-------------------------------------------------------------------------*/
/* DAQ_LIST_PROPERTIES (GET_DAQ_LIST_INFO) */
#define XCP_DAQ_LIST_PREDEFINED               (0x01u)
#define XCP_DAQ_LIST_FIXED_EVENT              (0x02u)
#define XCP_DAQ_LIST_DIR_DAQ                  (0x04u)
#define XCP_DAQ_LIST_DIR_STIM                 (0x08u)

/*-------------------------------------------------------------------------*/
/* EVENT_PROPERTY (GET_DAQ_EVENT_INFO) */
#define XCP_DAQ_EVENT_DIRECTION_DAQ           (0x04u)
#define XCP_DAQ_EVENT_DIRECTION_STIM          (0x08u)
#define XCP_DAQ_EVENT_DIRECTION_DAQ_STIM      (0x0Cu)
#define XCP_DAQ_EVENT_CONSISTENCY_DAQ         (0x40u)
#define XCP_DAQ_EVENT_CONSISTENCY_EVENT       (0x80u)

/*-------------------------------------------------------------------------*/
/* Connection states */
#define XCP_CON_STATE_DISCONNECTED            (0x00u)
#define XCP_CON_STATE_RESUME                  (0x01u)
#define XCP_CON_STATE_CONNECTED               (0x02u)

/*-------------------------------------------------------------------------*/
/* PGM_PROPERTIES (GET_PGM_PROCESSOR_INFO) */
#define XCP_PGM_ACCESS_TYPE                   (0x03u)
#define XCP_PGM_COMPRESSION_TYPE              (0x0Cu)
#define XCP_PGM_ENCRYPTION_TYPE               (0x30u)
#define XCP_PGM_NON_SEQ_TYPE                  (0xC0u)

/* PGM Access Mode */
#define XCP_PGM_ACCESS_ABSOLUTE               (1<<0u)
#define XCP_PGM_ACCESS_FUNCTIONAL             (2<<0u)
#define XCP_PGM_ACCESS_FREE                   (3<<0u)

/* PGM Compression type */
#define XCP_PGM_COMPRESSION_NONE              (0<<2u)
#define XCP_PGM_COMPRESSION_SUPPORTED         (1<<2u)
#define XCP_PGM_COMPRESSION_REQUIRED          (3<<2u)

/* PGM Encryption type */
#define XCP_PGM_ENCRYPTION_NONE               (0<<4u)
#define XCP_PGM_ENCRYPTION_SUPPORTED          (1<<4u)
#define XCP_PGM_ENCRYPTION_REQUIRED           (3<<4u)

/* PGM non sequential programming type */
#define XCP_PGM_NON_SEQ_NONE                  (0<<6u)
#define XCP_PGM_NON_SEQ_SUPPORTED             (1<<6u)
#define XCP_PGM_NON_SEQ_REQUIRED              (3<<6u)

/*-------------------------------------------------------------------------*/
/* Identifier Type (GET_ID) */
#define XCP_IDT_ASCII                         (0x00u)
#define XCP_IDT_ASAM_NAME                     (0x01u)
#define XCP_IDT_ASAM_PATH                     (0x02u)
#define XCP_IDT_ASAM_URL                      (0x03u)
#define XCP_IDT_ASAM_UPLOAD                   (0x04u)
#define XCP_IDT_VECTOR_MAPNAMES               (0xDBu)
#define XCP_IDT_VECTOR_INFOMEM                (0xDCu)
#define XCP_IDT_VECTOR_GENMEAS                (0xA2u)

/*-------------------------------------------------------------------------*/
/* Flush Types */
#define XCP_FLUSH_CTO   0u
#define XCP_FLUSH_DTO   1u
#define XCP_FLUSH_ALL   2u

/*-------------------------------------------------------------------------*/
/** 
 * \defgroup SESSION_STATUS SESSION_STATUS
 * \details Session Status (GET_STATUS and SET_REQUEST)
 * \ingroup hlp
 * \{
 */
#define XCP_SESSION_STORE_CAL_REQ                    (0x0001u)
#define XCP_SESSION_STORE_DAQ_REQ_NO_RESUME          (0x0002u)
#define XCP_SESSION_STORE_DAQ_REQ_RESUME             (0x0004u)
#define XCP_SESSION_CLEAR_DAQ_REQ                    (0x0008u)
#define XCP_SESSION_ERROR                            (0x0010u) /* Internal */
#define XCP_SESSION_CONNECTED                        (0x0020u) /* Internal */
#define XCP_SESSION_DAQ                              (0x0040u)
#define XCP_SESSION_RESUME                           (0x0080u)
#define XCP_SESSION_POLLING                          (0x0100u) /* Internal */
#define XCP_SESSION_STORE_DAQ_REQ_NO_RESUME_INTERNAL (0x0200u) /* Internal */
#define XCP_SESSION_BLOCK_UPLOAD                     (0x0400u) /* Internal */
/**\} */

/*-------------------------------------------------------------------------*/
/** 
 * \defgroup RESOURCE_MASK RESOURCE_MASK
 * \details ResourceMask (CONNECT)
 * \ingroup hlp
 * \{
 */
#define XCP_RM_CAL_PAG                              (0x01u)
#define XCP_RM_DAQ                                  (0x04u)
#define XCP_RM_STIM                                 (0x08u)
#define XCP_RM_PGM                                  (0x10u)

#define XCP_RM_ALL_RESOURCES                        (0x1Du)
/**\} */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 FUNCTIONLIKEMACROS */ /* MD_MSR_19.7 */
#if !defined (XCP_DUMMY_STATEMENT)
#define XCP_DUMMY_STATEMENT(id) (void)(id)
#endif

#if !defined (XCP_DUMMY_STATEMENT_CONST)
#define XCP_DUMMY_STATEMENT_CONST(id) (void)(id)
#endif

/* Activation/Deactivation control macros */
#if( XCP_CONTROL == STD_ON )
/* En- or disable the XCP Protocol Layer globally */

  #if defined ( XCP_ACTIVATE )
  #else
    #if defined ( XCP_TRANSPORT_LAYER_TYPE_CAN_ASR )
      #if ( CANXCP_ENABLE_CONTROL == STD_ON )
        #define XCP_ACTIVATE_CAN() CanXcp_ControlState = kXcponCan_Control_Enable
      #else
        #define XCP_ACTIVATE_CAN()
      #endif
    #else
      #define XCP_ACTIVATE_CAN()
    #endif
    #if defined ( XCP_TRANSPORT_LAYER_TYPE_FLEXRAY_ASR )
      #if ( FRXCP_ENABLE_CONTROL == STD_ON )
        #define XCP_ACTIVATE_FR() FrXcp_ControlState = kXcponFr_Control_Enable
      #else
        #define XCP_ACTIVATE_FR() 
      #endif
    #else
      #define XCP_ACTIVATE_FR() 
    #endif
    #if defined ( XCP_TRANSPORT_LAYER_TYPE_TCPIP_ASR )
      #if ( TCPIPXCP_ENABLE_CONTROL == STD_ON )
        #define XCP_ACTIVATE_TCPIP() TcpIpXcp_ControlState = kXcponTcpIp_Control_Enable
      #else
        #define XCP_ACTIVATE_TCPIP()
      #endif
    #else
      #define XCP_ACTIVATE_TCPIP()
    #endif
    #if defined ( XCP_TRANSPORT_LAYER_TYPE_LIN_ASR )
      #if ( LINXCP_ENABLE_CONTROL == STD_ON )
        #define XCP_ACTIVATE_LIN() LinXcp_Control(kXcponLin_Control_Enable)
      #else
        #define XCP_ACTIVATE_LIN()
      #endif
    #else
      #define XCP_ACTIVATE_LIN()
    #endif
    #define XCP_ACTIVATE() { XCP_ACTIVATE_CAN(); XCP_ACTIVATE_FR(); XCP_ACTIVATE_TCPIP(); XCP_ACTIVATE_LIN(); Xcp_ControlState = kXcp_Control_Enable; } /* PRQA S 3458 */ /* MD_MSR_19.4 */
  #endif

  #if defined ( XCP_DEACTIVATE )
  #else
    #if defined ( XCP_TRANSPORT_LAYER_TYPE_CAN_ASR )
      #if ( CANXCP_ENABLE_CONTROL == STD_ON )
        #define XCP_DEACTIVATE_CAN() CanXcp_ControlState = kXcponCan_Control_Disable
      #else
        #define XCP_DEACTIVATE_CAN()
      #endif
    #else
      #define XCP_DEACTIVATE_CAN()
    #endif
    #if defined ( XCP_TRANSPORT_LAYER_TYPE_FLEXRAY_ASR )
      #if ( FRXCP_ENABLE_CONTROL == STD_ON )
        #define XCP_DEACTIVATE_FR() FrXcp_ControlState = kXcponFr_Control_Disable
      #else
        #define XCP_DEACTIVATE_FR() 
      #endif
    #else
      #define XCP_DEACTIVATE_FR() 
    #endif
    #if defined ( XCP_TRANSPORT_LAYER_TYPE_TCPIP_ASR )
      #if ( TCPIPXCP_ENABLE_CONTROL == STD_ON )
        #define XCP_DEACTIVATE_TCPIP() TcpIpXcp_ControlState = kXcponTcpIp_Control_Disable
      #else
        #define XCP_DEACTIVATE_TCPIP()
      #endif
    #else
      #define XCP_DEACTIVATE_TCPIP()
    #endif
    #if defined ( XCP_TRANSPORT_LAYER_TYPE_LIN_ASR )
      #if ( LINXCP_ENABLE_CONTROL == STD_ON )
        #define XCP_DEACTIVATE_LIN() LinXcp_Control(kXcponLin_Control_Disable)
      #else
        #define XCP_DEACTIVATE_LIN()
      #endif
    #else
      #define XCP_DEACTIVATE_LIN()
    #endif
    #define XCP_DEACTIVATE() { XCP_DEACTIVATE_CAN(); XCP_DEACTIVATE_FR(); XCP_DEACTIVATE_TCPIP(); XCP_DEACTIVATE_LIN(); Xcp_ControlState = kXcp_Control_Disable; } /* PRQA S 3458 */ /* MD_MSR_19.4 */
  #endif
#endif

/* Legacy defines */
#define Xcp_SendCallBack(xcpChannel)    Xcp_TlTxConfirmation(xcpChannel)
#define Xcp_Command(xcpChannel, cmdPtr) Xcp_TlRxIndication(xcpChannel, (P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR))(cmdPtr))
#define Xcp_MemCpy(Dst, Src, Size)      XcpAppl_MemCpy(Dst, Src, Size)
#if defined ( DAQBYTEPTR )
#else
  #define DAQBYTEPTR P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)
#endif
#if defined ( ROMDAQBYTEPTR )
#else
  #define ROMDAQBYTEPTR P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA)
#endif
#define CP_XCP_VERSION 0x0300u
typedef uint16 SessionStatusType;
#define SS_CONNECTED XCP_SESSION_CONNECTED

/* PRQA L:FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */



/****************************************************************************/
/* Checksum, Type Definition                                                */
/****************************************************************************/
#if( XCP_CHECKSUM == STD_ON )
# if( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD11 ) || \
    ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD12 ) || \
    ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD14 ) || \
    ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16 ) || \
    ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16CITT ) || \
    ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC32 )
  typedef uint8 tXcpChecksumAddType;    /* Data type (width) of the data to be added.  */
# endif
# if( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD22 ) || \
    ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD24 )
  typedef uint16 tXcpChecksumAddType;   /* Data type (width) of the data to be added.  */
# endif
# if( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD44 )
  typedef uint32 tXcpChecksumAddType;   /* Data type (width) of the data to be added.  */
# endif
#endif /* ( XCP_CHECKSUM == STD_ON ) */

/****************************************************************************/
/* Default data type definitions                                            */
/****************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
#if( XCP_CONTROL == STD_ON )
# define XCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, XCP_VAR_INIT) Xcp_ControlState;

# define XCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif


#define XCP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Contains all channel information */
extern VAR(Xcp_ChannelStruct, XCP_VAR_NOINIT) Xcp_ChannelInfo[XCP_NUMBER_OF_CHANNELS];

#define XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#if( XCP_CONTROL == STD_ON )
#define XCP_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, XCP_VAR_INIT) Xcp_ControlDeniedCount;

#define XCP_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define XCP_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Xcp_InitMemory()
 *********************************************************************************************************************/
/*! \brief       Function for *_INIT_*-variable initialization
 *  \details     Service to initialize module global variables at power up. This function initializes the
 *               variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre         Module is uninitialized.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \ingroup     general
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) Xcp_InitMemory( void );


/**********************************************************************************************************************
 * Xcp_Init()
 *********************************************************************************************************************/
/*! \brief       Initializes the Xcp module.
 *  \details     This function initializes the module Xcp. It initializes all variables and sets the module state to
 *               initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Specification of module initialization
 *  \pre         Interrupts are disabled.
 *  \pre         Module is uninitialized.
 *  \pre         Xcp_InitMemory has been called unless Xcp_ModuleInitialized is initialized by start-up code.
 *  \ingroup     general
 *  \trace       SPEC-4263
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) Xcp_Init( void );


# if( XCP_VERSION_INFO_API == STD_ON )
/**********************************************************************************************************************
 *  Xcp_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information.
 *  \details     Returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      Available only if XCP_VERSION_INFO_API == STD_ON.
 *  \pre         -
 *  \ingroup     general
 *  \trace       SPEC-4268
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) Xcp_GetVersionInfo( P2VAR(Std_VersionInfoType, AUTOMATIC, XCP_APPL_VAR) versioninfo );
# endif


#if( XCP_GET_SESSION_STATUS_API == STD_ON )
/**********************************************************************************************************************
 *  Xcp_GetSessionStatus()
 *********************************************************************************************************************/
/*! \brief       Returns the current Session Status.
 *  \details     This service can be used to get the session state of the XCP Protocol Layer. The session state is 
 *               returned as a bit mask where the individual bits can be tested. 
 *  \param[in]   XcpChannel              The XCP Channel.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_GET_SESSION_STATUS_API == STD_ON.
 *  \pre         -
 *  \ingroup     general
 *********************************************************************************************************************/
FUNC(uint16, XCP_CODE) Xcp_GetSessionStatus( Xcp_ChannelType XcpChannel );
#endif


/**********************************************************************************************************************
 * Xcp_SetActiveTl()
 *********************************************************************************************************************/
/*! \brief       Sets active transport layer for one channel.
 *  \details     This service is used by the XCP Transport Layers to set the Transport Layer to be used by the XCP 
 *               Protocol Layer.
 *  \param[in]   XcpChannel              The XCP Channel.
 *  \param[in]   MaxCto                  The maximum number of Command Transfer Objects.
 *  \param[in]   MaxDto                  The maximum number of Data Transfer Objects.
 *  \param[in]   ActiveTl                The new active transport layer.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \ingroup     transportLayer
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) Xcp_SetActiveTl( Xcp_ChannelType XcpChannel, uint8 MaxCto, uint16 MaxDto, uint8 ActiveTl );


/**********************************************************************************************************************
 * Xcp_GetActiveTl()
 *********************************************************************************************************************/
/*! \brief       Returns the active transport layer of one channel.
 *  \details     This service is used by the XCP Transport Layers to get the currently active Transport Layer used by  
 *               the XCP Protocol Layer.
 *  \param[in]   XcpChannel              The XCP Channel.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \ingroup     transportLayer
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE) Xcp_GetActiveTl( Xcp_ChannelType XcpChannel );


/**********************************************************************************************************************
 *  Xcp_TlRxIndication()
 *********************************************************************************************************************/
/*! \brief       RxIndication function of XCP protocol layer
 *  \details     Every time the XCP Transport Layer receives a XCP CTO Packet this function has to be called. 
 *               The parameter is a pointer to the XCP protocol message, which must be extracted from the XCP protocol 
 *               packet. 
 *  \param[in]   XcpChannel              The XCP Channel.
 *  \param[in]   CmdPtr                  Command string of received XCP command, must not be NULL_PTR.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \ingroup     transportLayer
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) Xcp_TlRxIndication( Xcp_ChannelType XcpChannel, P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );


/**********************************************************************************************************************
 *  Xcp_TlTxConfirmation()
 *********************************************************************************************************************/
/*! \brief       TxConfirmation function of XCP protocol layer
 *  \details     The XCP Protocol Layer does not call <Bus>Xcp_Send again, until Xcp_TlTxConfirmation has confirmed the 
 *               successful transmission of the previous message. Xcp_TlTxConfirmation transmits pending data acquisition 
 *               messages by calling <Bus>Xcp_Send again.  
 *  \param[in]   XcpChannel              The XCP Channel.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \ingroup     transportLayer
 *  \note        If Xcp_TlTxConfirmation is called from inside <Bus>Xcp_Send a recursion occurs, which assumes enough 
 *               space on the call stack. 
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) Xcp_TlTxConfirmation( Xcp_ChannelType XcpChannel );


/**********************************************************************************************************************
 *  Xcp_Disconnect()
 *********************************************************************************************************************/
/*! \brief       Disconnects the connection between XCP master and slave.
 *  \details     If the XCP slave is connected to a XCP master a call of this function discontinues the connection 
 *               to (transition disconnected state). If the XCP slave is not connected this function performs no action.
 *  \param[in]   XcpChannel              The channel which disconnects.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \ingroup     general
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) Xcp_Disconnect( Xcp_ChannelType XcpChannel );


/**********************************************************************************************************************
 *  Xcp_ModifyProtectionStatus()
 *********************************************************************************************************************/
/*! \brief       Locks and unlocks resources.
 *  \details     Enables the slave to access resource locks which usually have to be changed by XCP master with the
 *               Seed Key mechanism.
 *  \param[in]   XcpChannel              The channel which disconnects.
 *  \param[in]   AndState                The following flags: XCP_RM_CAL_PAG, XCP_RM_DAQ, XCP_RM_STIM and XCP_RM_PGM 
 *                                       can be used to clear the protection state of the respective resource. 
 *                                       The modified state is persistent until Xcp_Init. 
 *  \param[in]   OrState                 The following flags: XCP_RM_CAL_PAG, XCP_RM_DAQ, XCP_RM_STIM and XCP_RM_PGM 
 *                                       can be used to set the protection state of the respective resource. 
 *                                       The modified state is persistent until Xcp_Init. 
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \ingroup     general
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE) Xcp_ModifyProtectionStatus( Xcp_ChannelType XcpChannel,
                                                         uint8 AndState,
                                                         uint8 OrState );

#if( XCP_DAQ == STD_ON )
# if( XCP_STIM == STD_ON )
/**********************************************************************************************************************
 * Xcp_StimEventStatus()
 *********************************************************************************************************************/
/*! \brief       Return the status of a STIM Event Channel.
 *  \details     Check if data stimulation (STIM) event can perform or delete the buffers. 
 *  \param[in]   EventChannel            Event channel number. 
 *  \param[in]   Action                  XCP_STIM_CHECK_ODT_BUFFER - check if STIM data available
 *                                       XCP_STIM_RESET_ODT_BUFFER - reset STIM buffer
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_DAQ == STD_ON and XCP_STIM == STD_ON.
 *  \pre         -
 *  \ingroup     general
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE) Xcp_StimEventStatus( uint16 EventChannel, uint8 Action );
# endif


/**********************************************************************************************************************
 * Xcp_Event()
 *********************************************************************************************************************/
/*! \brief       Triggers Data Acquisition.
 *  \details     Calling Xcp_Event with a particular event channel number triggers the sampling and transmission of all 
 *               DAQ lists that are assigned to this event channel. 
 *               The event channels are defined by the ECU developer in the application program. An MCS (e.g. CANape) 
 *               must know about the meaning of the event channel numbers. These are usually described in the tool 
 *               configuration files or in the interface specific part of the ASAM MC2 (ASAP2) database. 
 *  \param[in]   EventChannel            Event channel number. 
 *  \context     TASK/ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_DAQ == STD_ON.
 *  \pre         -
 *  \ingroup     general
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE) Xcp_Event( uint16 EventChannel );
#endif /* ( XCP_DAQ == STD_ON ) */


/**********************************************************************************************************************
 * Xcp_SendCrm()
 *********************************************************************************************************************/
/*! \brief       Sends command response message.
 *  \details     Transmission of a command response packet (RES), or error packet (ERR) if no other packet is pending. 
 *  \param[in]   XcpChannel              The XCP Channel.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \ingroup     general
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) Xcp_SendCrm( Xcp_ChannelType XcpChannel );


#if( XCP_SEND_EVENT == STD_ON )
/**********************************************************************************************************************
 * Xcp_SendEvent()
 *********************************************************************************************************************/
/*! \brief       Sends an asynchronous event to XCP master.
 *  \details     Is used to send an asynchronous message the the XCP Master. Event Codes must be enabled by command first.
 *  \param[in]   XcpChannel              The XCP Channel.
 *  \param[in]   EventCode               The event code of the message to send.
 *  \param[in]   EventData               A pointer to the string of the event to send.
 *  \param[in]   Length                  The length of the event data.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_SEND_EVENT == STD_ON.
 *  \pre         -
 *  \ingroup     asynch
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) Xcp_SendEvent( Xcp_ChannelType XcpChannel, 
                                           uint8 EventCode, 
                                           P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) EventData, 
                                           uint8 Length );
#endif


#if( XCP_SERV_TEXT == STD_ON )
/**********************************************************************************************************************
 * Xcp_PutChar()
 *********************************************************************************************************************/
/*! \brief       Writes a single character in Event Message.
 *  \details     Put a char into a service request packet (SERV). The service request packet is transmitted if either 
 *               the maximum packet length is reached (the service request message packet is full) or the character 0x00 
 *               is in the service request packet. 
 *  \param[in]   XcpChannel              The XCP Channel.
 *  \param[in]   Character               The character that is written to event message.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_SERV_TEXT == STD_ON.
 *  \pre         -
 *  \ingroup     asynch
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) Xcp_PutChar( Xcp_ChannelType XcpChannel, CONST(uint8, AUTOMATIC) Character );


/**********************************************************************************************************************
 * Xcp_Print()
 *********************************************************************************************************************/
/*! \brief       Writes a string in event message.
 *  \details     Transmission of a service request packet (SERV). The string Str is sent via service request packets. 
 *               The string has to be terminated by 0x00.
 *  \param[in]   XcpChannel              The XCP Channel.
 *  \param[in]   Str                     The character that is written to event message.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_SERV_TEXT == STD_ON.
 *  \pre         -
 *  \ingroup     asynch
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) Xcp_Print( Xcp_ChannelType XcpChannel, P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) Str );
#endif


#if( XCP_BOOTLOADER_DOWNLOAD == STD_ON )
/**********************************************************************************************************************
 * Xcp_GetXcpDataPointer()
 *********************************************************************************************************************/
/*! \brief       Returns pointer to channel info.
 *  \details     Returns pointer to channel info.
 *  \param[out]  pXcpData                The pointer to XCP channel info.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_BOOTLOADER_DOWNLOAD == STD_ON.
 *  \pre         -
 *  \ingroup     general
 *********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_GetXcpDataPointer( P2VAR(Xcp_ChannelStructPtr, AUTOMATIC, XCP_APPL_DATA) pXcpData );
#endif


# if( XCP_STIM == STD_ON )
/**********************************************************************************************************************
 * Xcp_SetStimMode()
 *********************************************************************************************************************/
/*! \brief       Set the STIM mode (Continuous/Single Shot).
 *  \details     With this function it is possible to globally set the mode that is used during stimulation.
 *               It can either be XCP_STIM_SINGLE_SHOT_MODE to write a received DAQ list a single time, or
 *               XCP_STIM_CONTINUOUS_MODE to write a received DAQ list continuously.
 *  \param[out]  mode                The selected mode which can be either XCP_STIM_SINGLE_SHOT_MODE or 
 *                                   XCP_STIM_CONTINUOUS_MODE while the first one is the default.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_STIM == STD_ON.
 *  \pre         -
 *  \ingroup     general
 *********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_SetStimMode( uint8 mode );
#endif


/**********************************************************************************************************************
 *  Xcp_MainFunction()
 *********************************************************************************************************************/
/*! \fn          void Xcp_MainFunction(void)
 *  \brief       Cyclically executed API service of the XCP protocol layer.
 *  \details     If the XCP command for the calculation of the memory checksum has to be used for large memory areas, it 
 *               might not be appropriate to block the processor for a long period of time. Therefore, the checksum 
 *               calculation is divided into smaller sections that are handled in the Xcp_MainFunction. 
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-117292
 *  \pre         -
 *  \ingroup     general
 *  \trace       SPEC-4272
 *********************************************************************************************************************/
/* extern FUNC(void, XCP_CODE) Xcp_MainFunction( void ); */

# define XCP_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/*!
 * \exclusivearea SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0
 * Ensures consistency of code that runs on BSW core. They may be interrupted by application functionality or time critical CAT1 interrupts.
 * \protects SendStatus, Xcp_SendQueueReadIdx
 * \usedin Xcp_Hlp_SendDtoFromQueue, Xcp_Hlp_SendAsyncEvent
 * \exclude none
 * \length LONG Call to other BSW module
 * \endexclusivearea
 *
 * \exclusivearea SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_1
 * Ensures consistency of code that runs on any core. They may be interrupted by application functionality or time critical CAT1 interrupts.
 * \protects Xcp_SendQueueWriteIdx, data integrity on ODT level
 * \usedin Xcp_Hlp_EventDaq
 * \exclude none
 * \length LONG Assembly of DTO, ranges from 8 to 1500 bytes
 * \endexclusivearea
 *
 * \exclusivearea SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_2
 * Ensures consistency of code that runs on any core. They may be interrupted by application functionality or time critical CAT1 interrupts.
 * \protects pStimBuffer->buffer.b[0], data integrity on ODT level
 * \usedin Xcp_Hlp_EventStim
 * \exclude none
 * \length LONG Assembly of DTO, ranges from 8 to 1500 bytes
 * \endexclusivearea
 */

#endif /* XCP_H */

/**********************************************************************************************************************
 *  END OF FILE: Xcp.h
 *********************************************************************************************************************/
