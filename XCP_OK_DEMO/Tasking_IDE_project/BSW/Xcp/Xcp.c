/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Xcp.c
 *        \brief  XCP source file
 *
 *      \details  Implementation of the XCP protocol layer.
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
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

/* Configuration, interrupt handling implementations differ from the source identification define used in this example.
 * The naming schemes for those files can be taken from this list:
 *
 * Xcp_Cfg.c:     XCP_CFG_SOURCE
 * Xcp_LCfg.c:    XCP_LCFG_SOURCE
 * Xcp_PBCfg.c:   XCP_PBCFG_SOURCE
 * Xcp_Irq.c:     XCP_IRQ_SOURCE
 */
#define XCP_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Xcp.h"
#include "Xcp_Priv.h"
#include "SchM_Xcp.h"

#if( XCP_AUTOSAR_CRC_MODULE == STD_ON )
# include "Crc.h"
#endif

#if( XCP_DEV_ERROR_REPORT == STD_ON )
# include "Det.h"
#endif

#if( XCP_NUMBER_OF_CORES > 1u )
# include "Os.h"
#endif

#if( XCP_AMD_RUNTIME_MEASUREMENT == STD_ON )
# include "Rtm.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of Xcp header file */
#if (  (XCP_SW_MAJOR_VERSION != (4u)) \
    || (XCP_SW_MINOR_VERSION != (0u)) \
    || (XCP_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of <Xcp>.c and <Xcp>.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
/* Macros for AMD abstraction */
#if( XCP_AMD_RUNTIME_MEASUREMENT == STD_ON )
  /* PRQA S 0342 2 */ /* MD_MSR_19.13_0342 */
  #define Xcp_Rtm_Start(channel) Rtm_Start(RtmConf_RtmMeasurementPoint_##channel)
  #define Xcp_Rtm_Stop(channel)  Rtm_Stop(RtmConf_RtmMeasurementPoint_##channel)
#else
  #define Xcp_Rtm_Start(channel)
  #define Xcp_Rtm_Stop(channel)
#endif

#if !defined ( Xcp_Enter_Exclusive_Area_Common )
# define Xcp_Enter_Exclusive_Area_Common      SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0
#endif
#if !defined ( Xcp_Leave_Exclusive_Area_Common )
# define Xcp_Leave_Exclusive_Area_Common      SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0
#endif
#if !defined ( Xcp_Enter_Exclusive_Area_Daq )
# define Xcp_Enter_Exclusive_Area_Daq         SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_1
#endif
#if !defined ( Xcp_Leave_Exclusive_Area_Daq )
# define Xcp_Leave_Exclusive_Area_Daq         SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_1
#endif
#if !defined ( Xcp_Enter_Exclusive_Area_Stim )
# define Xcp_Enter_Exclusive_Area_Stim        SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_2
#endif
#if !defined ( Xcp_Leave_Exclusive_Area_Stim )
# define Xcp_Leave_Exclusive_Area_Stim        SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_2
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/*lint -e511 */ /* Suppress ID511 because the pointer is of type uint64* */

#define XCP_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if( XCP_DAQ == STD_ON )
/*! Flag used to signal overload condition via MSB */
# if( XCP_DAQ_OVERRUN_INDICATION == STD_ON )
XCP_LOCAL VAR(uint8, XCP_VAR_NOINIT) Xcp_OverloadFlag[XCP_NUMBER_OF_CHANNELS][XCP_NUMBER_OF_CORES];
# endif
#endif /* ( XCP_DAQ == STD_ON ) */

#define XCP_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define XCP_START_SEC_VAR_NOCACHE_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if( XCP_DAQ == STD_ON )
/*! Send Queue specific write index */
XCP_LOCAL volatile VAR(uint32, XCP_VAR_NOINIT_NOCACHE) Xcp_SendQueueWriteIdx[XCP_NUMBER_OF_CHANNELS][XCP_NUMBER_OF_CORES];
/*! Send Queue specific read index */
XCP_LOCAL volatile VAR(uint32, XCP_VAR_NOINIT_NOCACHE) Xcp_SendQueueReadIdx[XCP_NUMBER_OF_CHANNELS][XCP_NUMBER_OF_CORES];
/*! Send Queue specific size */
XCP_LOCAL VAR(uint32, XCP_VAR_NOINIT_NOCACHE) Xcp_SendQueueSizeLimit[XCP_NUMBER_OF_CHANNELS][XCP_NUMBER_OF_CORES];
#endif /* ( XCP_DAQ == STD_ON ) */

#define XCP_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define XCP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if( XCP_DAQ == STD_ON )
/*! Send Queue specific size of one entry */
XCP_LOCAL VAR(uint16, XCP_VAR_NOINIT) Xcp_SendQueueEntrySize[XCP_NUMBER_OF_CHANNELS];
#endif

# if ( XCP_STIM == STD_ON )
/*! STIM ODT buffer */
/* PRQA S 3218 1 */ /* MD_Xcp_3218_FileScopeStatic */
XCP_LOCAL VAR(tXcpDto, XCP_VAR_NOINIT) Xcp_StimBuffer[XCP_NUMBER_OF_CHANNELS][XCP_MAX_ODT_STIM];
/*! STIM mode to select continuous or single shot mode */
XCP_LOCAL VAR(uint8, XCP_VAR_NOINIT) Xcp_StimMode;
# endif

#define XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define XCP_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Initialization state of the module */
XCP_LOCAL VAR(uint8, XCP_VAR_ZERO_INIT) Xcp_ModuleInitialized = XCP_UNINIT;
#if (XCP_DEV_ERROR_REPORT == STD_ON) && ( XCP_NUMBER_OF_CORES > 1u )
/*! Asynchronous error thrown on another core */
XCP_LOCAL VAR(uint8, XCP_VAR_ZERO_INIT) Xcp_BswErrorId = XCP_E_NO_ERROR;
XCP_LOCAL VAR(uint8, XCP_VAR_ZERO_INIT) Xcp_BswFctId = 0u;
#endif

#define XCP_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#if( XCP_CONTROL == STD_ON )
# define XCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*! Control variable to completely deactivate the XCP */
VAR(uint8, XCP_VAR_INIT) Xcp_ControlState = kXcp_Control_Enable;

# define XCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif


#define XCP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Contains all channel information */
VAR(Xcp_ChannelStruct, XCP_VAR_NOINIT) Xcp_ChannelInfo[XCP_NUMBER_OF_CHANNELS]; /* PRQA S 0612 */ /* MD_XCP_1.1_0612 */

#define XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#if( XCP_CONTROL == STD_ON )
# define XCP_START_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*! Used to verify correct deactivation of XCP */
VAR(uint8, XCP_VAR_ZERO_INIT) Xcp_ControlDeniedCount = 0u; /* PRQA S 3408 */ /* MD_Xcp_3408 */

# define XCP_STOP_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif


#if( XCP_CHECKSUM == STD_ON )
# if( XCP_AUTOSAR_CRC_MODULE == STD_OFF )
/* Table for CCITT checksum calculation */
#  if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16CITT )

#define XCP_START_SEC_CONST_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* PRQA S 3218 1 */ /* MD_Xcp_3218_FileScopeStatic */  
XCP_LOCAL CONST(uint16, XCP_CONST) CRC16CCITTtab[256] = {
    0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7u,
    0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1efu,
    0x1231,0x0210,0x3273,0x2252,0x52b5,0x4294,0x72f7,0x62d6u,
    0x9339,0x8318,0xb37b,0xa35a,0xd3bd,0xc39c,0xf3ff,0xe3deu,
    0x2462,0x3443,0x0420,0x1401,0x64e6,0x74c7,0x44a4,0x5485u,
    0xa56a,0xb54b,0x8528,0x9509,0xe5ee,0xf5cf,0xc5ac,0xd58du,
    0x3653,0x2672,0x1611,0x0630,0x76d7,0x66f6,0x5695,0x46b4u,
    0xb75b,0xa77a,0x9719,0x8738,0xf7df,0xe7fe,0xd79d,0xc7bcu,
    0x48c4,0x58e5,0x6886,0x78a7,0x0840,0x1861,0x2802,0x3823u,
    0xc9cc,0xd9ed,0xe98e,0xf9af,0x8948,0x9969,0xa90a,0xb92bu,
    0x5af5,0x4ad4,0x7ab7,0x6a96,0x1a71,0x0a50,0x3a33,0x2a12u,
    0xdbfd,0xcbdc,0xfbbf,0xeb9e,0x9b79,0x8b58,0xbb3b,0xab1au,
    0x6ca6,0x7c87,0x4ce4,0x5cc5,0x2c22,0x3c03,0x0c60,0x1c41u,
    0xedae,0xfd8f,0xcdec,0xddcd,0xad2a,0xbd0b,0x8d68,0x9d49u,
    0x7e97,0x6eb6,0x5ed5,0x4ef4,0x3e13,0x2e32,0x1e51,0x0e70u,
    0xff9f,0xefbe,0xdfdd,0xcffc,0xbf1b,0xaf3a,0x9f59,0x8f78u,
    0x9188,0x81a9,0xb1ca,0xa1eb,0xd10c,0xc12d,0xf14e,0xe16fu,
    0x1080,0x00a1,0x30c2,0x20e3,0x5004,0x4025,0x7046,0x6067u,
    0x83b9,0x9398,0xa3fb,0xb3da,0xc33d,0xd31c,0xe37f,0xf35eu,
    0x02b1,0x1290,0x22f3,0x32d2,0x4235,0x5214,0x6277,0x7256u,
    0xb5ea,0xa5cb,0x95a8,0x8589,0xf56e,0xe54f,0xd52c,0xc50du,
    0x34e2,0x24c3,0x14a0,0x0481,0x7466,0x6447,0x5424,0x4405u,
    0xa7db,0xb7fa,0x8799,0x97b8,0xe75f,0xf77e,0xc71d,0xd73cu,
    0x26d3,0x36f2,0x0691,0x16b0,0x6657,0x7676,0x4615,0x5634u,
    0xd94c,0xc96d,0xf90e,0xe92f,0x99c8,0x89e9,0xb98a,0xa9abu,
    0x5844,0x4865,0x7806,0x6827,0x18c0,0x08e1,0x3882,0x28a3u,
    0xcb7d,0xdb5c,0xeb3f,0xfb1e,0x8bf9,0x9bd8,0xabbb,0xbb9au,
    0x4a75,0x5a54,0x6a37,0x7a16,0x0af1,0x1ad0,0x2ab3,0x3a92u,
    0xfd2e,0xed0f,0xdd6c,0xcd4d,0xbdaa,0xad8b,0x9de8,0x8dc9u,
    0x7c26,0x6c07,0x5c64,0x4c45,0x3ca2,0x2c83,0x1ce0,0x0cc1u,
    0xef1f,0xff3e,0xcf5d,0xdf7c,0xaf9b,0xbfba,0x8fd9,0x9ff8u,
    0x6e17,0x7e36,0x4e55,0x5e74,0x2e93,0x3eb2,0x0ed1,0x1ef0u
};

#define XCP_STOP_SEC_CONST_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#   endif /* ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16CITT ) */

#  endif /* ( XCP_AUTOSAR_CRC_MODULE == STD_OFF ) */

#endif /* ( XCP_CHECKSUM == STD_ON ) */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define XCP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ####################################################################################################################
 *   HH      HH  EEEEEEEEEE  LL          PPPPPPPP    EEEEEEEEEE  RRRRRRRR
 *   HH      HH  EE          LL          PP      PP  EE          RR      RR
 *   HH      HH  EE          LL          PP      PP  EE          RR      RR
 *   HHHHHHHHHH  EEEEEEEE    LL          PPPPPPPP    EEEEEEEE    RRRRRRRR
 *   HH      HH  EE          LL          PP          EE          RR    RR
 *   HH      HH  EE          LL          PP          EE          RR      RR
 *   HH      HH  EEEEEEEEEE  LLLLLLLLLL  PP          EEEEEEEEEE  RR      RR
 * ################################################################################################################# */

#if( (XCP_CHECKSUM == STD_ON) && (XCP_CUSTOM_CRC == STD_OFF) )
/**********************************************************************************************************************
  Xcp_Hlp_CalcAndSendChecksumResult()
**********************************************************************************************************************/
/*!
 *
 * \brief       Calculates the requested checksum.
 * \details     Calculates the requested checksum and sends the result if ready.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_CHECKSUM == STD_ON and XCP_CUSTOM_CRC == STD_OFF.
 * \pre         -
 * \ingroup     hlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_Hlp_CalcAndSendChecksumResult( void );
#endif

/**********************************************************************************************************************
  Xcp_Hlp_MemSet()
**********************************************************************************************************************/
/*!
 *
 * \brief       Writes a value to a range of memory.
 * \details     The complete destination memory range is overwritten with the same value.
 * \param[out]  Destination            The destination where the data is copied to.
 * \param[in]   Length                 The number of bytes that should be overwritten.
 * \param[in]   Value                  The value that is written to the destination.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     hlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_Hlp_MemSet( P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR) Destination,
                                                      uint32 Length,
                                                      uint8 Value );

#if( (XCP_SEND_EVENT == STD_ON) || (XCP_SERV_TEXT == STD_ON) )
/**********************************************************************************************************************
  Xcp_Hlp_SendAsyncEvent()
**********************************************************************************************************************/
/*!
 *
 * \brief       Sends the next pending event message.
 * \details     Sends the next pending event message or text.
 * \param[in]   XcpChannel             The channel from which the data should be send.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_SEND_EVENT == STD_ON or XCP_SERV_TEXT == STD_ON.
 * \pre         -
 * \ingroup     hlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_Hlp_SendAsyncEvent( Xcp_ChannelType XcpChannel );

/**********************************************************************************************************************
  Xcp_Hlp_OccurredPendingTxConfirmation()
**********************************************************************************************************************/
/*!
 *
 * \brief       Blocks execution until the pending condition is gone.
 * \details     -
 * \param[in]   XcpChannel             The channel from which the data should be send.
 * \return      FALSE                  Transmission could not commence and was interrupted due to timeout condition.
 * \return      TRUE                   Transmission was successful
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_SEND_EVENT == STD_ON or XCP_SERV_TEXT == STD_ON.
 * \pre         -
 * \ingroup     hlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(boolean, XCP_CODE) Xcp_Hlp_OccurredPendingTxConfirmation( Xcp_ChannelType XcpChannel );
#endif

#if( XCP_DAQ == STD_ON )
/**********************************************************************************************************************
  Xcp_Hlp_SendDtoFromQueue()
**********************************************************************************************************************/
/*!
 *
 * \brief       Sends the next pending data package within context of Xcp_TxConfirmation.
 * \details     Sends the next pending data package within context of Xcp_TxConfirmation.
 * \param[in]   XcpChannel             The channel from which the data should be send.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_DAQ == STD_ON.
 * \pre         -
 * \ingroup     hlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_Hlp_SendDtoFromQueue( Xcp_ChannelType XcpChannel );

/**********************************************************************************************************************
  Xcp_Hlp_CalcSendQueueEntrySizeAndLimit()
**********************************************************************************************************************/
/*!
 *
 * \brief       Calculates the maximal size of send queue entries.
 * \details     Calculates the maximal size of send queue entries, additionally the send queue size limit is 
 *              calculated.
 * \param[in]   XcpChannel             The active channel.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_DAQ == STD_ON.
 * \pre         -
 * \ingroup     hlp
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_Hlp_CalcSendQueueEntrySizeAndLimit( Xcp_ChannelType XcpChannel );

/**********************************************************************************************************************
  Xcp_Hlp_EventDaq()
**********************************************************************************************************************/
/*!
 *
 * \brief       Performs DAQ data collection.
 * \details     Performs DAQ data collection.
 * \param[in]   XcpChannel             The active channel.
 * \param[in]   coreIdx                The core the function is running on.
 * \param[in]   pXcp                   Pointer to current EventChannel structure.
 * \param[in]   daq                    The DAQ list number
 * \return      XCP_EVENT_DAQ          DAQ data copied.
 * \return      XCP_EVENT_DAQ_OVERLOAD Send Queue is full, data lost.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_DAQ == STD_ON.
 * \pre         -
 * \ingroup     hlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_Hlp_EventDaq( uint8_least XcpChannel,
                                                         uint16 CoreIdx,
                                                         P2CONST(Xcp_ChannelStruct, AUTOMATIC, XCP_VAR_NOINIT) pXcp,
                                                         uint16_least Daq );

# if( XCP_STIM == STD_ON )
/**********************************************************************************************************************
  Xcp_Hlp_StimEventStatus()
**********************************************************************************************************************/
/*!
 *
 * \brief       Performs action on STIM data
 * \details     Checks for available STIM data or resets STIM buffer.
 * \param[in]   XcpChannel             The active channel.
 * \param[in]   Daq                    The DAQ list number
 * \param[in]   Action                 What kind of action to be performed.
 * \return      XCP_NO_STIM_DATA_AVAILABLE STIM buffer is empty, nothing to be done.
 * \return      XCP_STIM_DATA_AVAILABLE    STIM data is available and can be copied with Xcp_Event.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_DAQ == STD_ON and XCP_STIM == STD_ON.
 * \pre         -
 * \ingroup     hlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_Hlp_StimEventStatus( uint8_least XcpChannel, uint16_least Daq, uint8 Action );

/**********************************************************************************************************************
  Xcp_Hlp_EventStim()
**********************************************************************************************************************/
/*!
 *
 * \brief       Performs STIM data to Application transfer.
 * \details     Performs STIM data to Application transfer.
 * \param[in]   XcpChannel             The active channel.
 * \param[in]   pXcp                   Pointer to current EventChannel structure.
 * \param[in]   Daq                    The DAQ list number
 * \return      XCP_EVENT_STIM         STIM data copied.
 * \return      XCP_EVENT_STIM_OVERRUN STIM data overrun.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_DAQ == STD_ON and XCP_STIM == STD_ON.
 * \pre         -
 * \ingroup     hlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_Hlp_EventStim( uint8_least XcpChannel,
                                                          P2CONST(Xcp_ChannelStruct, AUTOMATIC, XCP_VAR_NOINIT) pXcp, 
                                                          uint16_least Daq );
# endif /* ( XCP_STIM == STD_ON ) */
#endif /* ( XCP_DAQ == STD_ON ) */


/* ####################################################################################################################
 *      CCCC    MM      MM  DDDDDD          HH      HH  EEEEEEEEEE  LL          PPPPPPPP    EEEEEEEEEE  RRRRRRRR
 *    CC    CC  MMMM  MMMM  DD    DD        HH      HH  EE          LL          PP      PP  EE          RR      RR
 *  CC          MM  MM  MM  DD      DD      HH      HH  EE          LL          PP      PP  EE          RR      RR
 *  CC          MM  MM  MM  DD      DD      HHHHHHHHHH  EEEEEEEE    LL          PPPPPPPP    EEEEEEEE    RRRRRRRR
 *  CC          MM      MM  DD      DD      HH      HH  EE          LL          PP          EE          RR    RR
 *    CC    CC  MM      MM  DD    DD        HH      HH  EE          LL          PP          EE          RR      RR
 *      CCCC    MM      MM  DDDDDD          HH      HH  EEEEEEEEEE  LLLLLLLLLL  PP          EEEEEEEEEE  RR      RR
 * ################################################################################################################# */

/**********************************************************************************************************************
  Xcp_CmdHlp_PrepareError()
**********************************************************************************************************************/
/*!
 *
 * \brief       Prepares error response.
 * \details     Prepares error response containing the ErrorCode.
 * \param[in]   XcpChannel             The channel on which the error occurred.
 * \param[in]   ErrorCode              The error code to be reported in the response.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdHlp
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdHlp_PrepareError( Xcp_ChannelType XcpChannel, uint8 ErrorCode );

/**********************************************************************************************************************
  Xcp_CmdHlp_PrepareErrorOrPending()
**********************************************************************************************************************/
/*!
 *
 * \brief       Prepares pending or forward ErrorCode to Xcp_CmdHlp_PrepareError().
 * \details     Prepares pending or forward ErrorCode to Xcp_CmdHlp_PrepareError().
 * \param[in]   XcpChannel             The channel on which the error occurred or pending is requested.
 * \param[in]   ErrorCode              The error code to be reported in the response.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdHlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CmdHlp_PrepareErrorOrPending( Xcp_ChannelType XcpChannel, uint8 ErrorCode );

/**********************************************************************************************************************
  Xcp_CmdHlp_ReadMta()
**********************************************************************************************************************/
/*!
 *
 * \brief       Reads the memory address the MTA is pointing to.
 * \details     Reads and returns the memory address the MTA is pointing to.
 * \param[in]   XcpChannel             The channel from which the data should be read.
 * \param[in]   size                   The number of bytes to be read.
 * \param[out]  data                   The destination to which the data should be copied.
 * \return      XCP_CMD_OK             The measurement value was successfully read
 * \return      XCP_CMD_PENDING        The measurement value is read asynchronously
 * \return      XCP_CMD_DENIED         The measurement value is protected
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdHlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_CmdHlp_ReadMta( Xcp_ChannelType XcpChannel,
                                                           uint8 Size,
                                                           P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) Data );

#if( XCP_CALIBRATION == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdHlp_WriteMta()
**********************************************************************************************************************/
/*!
 *
 * \brief         Writes to the memory address the MTA is pointing to.
 * \details       Writes to the memory address the MTA is pointing to.
 * \param[in]     XcpChannel             The channel to which the data should be written.
 * \param[in]     size                   The number of bytes to be written.
 * \param[in,out] data                   The source from which the data should be copied.
 * \return        XCP_CMD_OK             The calibration value was successfully written
 * \return        XCP_CMD_PENDING        The calibration value is written asynchronously
 * \return        XCP_CMD_DENIED         The calibration value is protected
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \config        Available only if XCP_SEED_KEY == STD_ON.
 * \pre           -
 * \ingroup       cmdHlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_CmdHlp_WriteMta( Xcp_ChannelType XcpChannel,
                                                            uint8 Size,
                                                            CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) Data );
#endif

/**********************************************************************************************************************
  Xcp_CmdHlp_SetMta()
**********************************************************************************************************************/
/*!
 *
 * \brief         Sets the MTA address and the MTA address extension as specified.
 * \details       Sets the MTA address and the MTA address extension as specified.
 * \param[in]     XcpChannel             The channel to which the data should be written.
 * \param[in]     Address                The new address for the MTA.
 * \param[in]     AddressExtension       The new address extension for the MTA.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \ingroup       cmdHlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CmdHlp_SetMta( Xcp_ChannelType XcpChannel,
                                                         Xcp_AddressPtrType Address,
                                                         uint8              AddressExtension );

#if( XCP_SEED_KEY == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdHlp_BitCounter()
**********************************************************************************************************************/
/*!
 *
 * \brief       Counts the number of bits set in a 32bit variable.
 * \details     Counts and returns the number of bits set in a 32bit variable.
 * \param[in]   ValueToCheck             The variable from which the bits are counted.
 * \return      The number of bits set in variable ValueToCheck.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_SEED_KEY == STD_ON.
 * \pre         -
 * \ingroup     cmdHlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_CmdHlp_BitCounter( uint32 ValueToCheck );
#endif


#if( XCP_SEED_KEY == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdHlp_CheckResourceProtection()
**********************************************************************************************************************/
/*!
 *
 * \brief       Checks if the requested resource is locked.
 * \details     Prepares error response containing the ErrorCode.
 * \param[in]   XcpChannel             The channel on which the error occurred.
 * \param[in]   Resource               The resource to be checked.
 * \return      XCP_CMD_OK             The resource is unlocked.
 * \return      XCP_ERR_ACCESS_LOCKED  The resource is locked.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_SEED_KEY == STD_ON.
 * \pre         -
 * \ingroup     cmdHlp
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_CmdHlp_CheckResourceProtection( Xcp_ChannelType XcpChannel, 
                                                                           uint8 Resource );
#endif

#if( XCP_DAQ == STD_ON )
# if( XCP_STIM == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdHlp_AllocStimMemory()
**********************************************************************************************************************/
/*!
 *
 * \brief       Allocates STIM DTOs.
 * \details     This service allocates STIM ODTs depending on the command from the Master.
 * \param[in]   XcpChannel             The channel from which the data should be send.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_DAQ == STD_ON and XCP_STIM == STD_ON.
 * \pre         -
 * \ingroup     hlp
**********************************************************************************************************************/
XCP_LOCAL FUNC(uint8, XCP_CODE) Xcp_CmdHlp_AllocStimMemory( Xcp_ChannelType XcpChannel );
# endif
#endif /* ( XCP_DAQ == STD_ON ) */


#if( XCP_DAQ == STD_ON )
/* ####################################################################################################################
 *      CCCC      OOOOOO    NN      NN  TTTTTTTTTT  RRRRRRRR            DDDDDD        AAAAAA      QQQQQQ
 *    CC    CC  OO      OO  NNNN    NN      TT      RR      RR          DD    DD    AA      AA  QQ      QQ
 *  CC          OO      OO  NN NN   NN      TT      RR      RR          DD      DD  AA      AA  QQ      QQ
 *  CC          OO      OO  NN  NN  NN      TT      RRRRRRRR            DD      DD  AAAAAAAAAA  QQ      QQ
 *  CC          OO      OO  NN   NN NN      TT      RR    RR            DD      DD  AA      AA  QQ    Q QQ
 *    CC    CC  OO      OO  NN    NNNN      TT      RR      RR  ::::    DD    DD    AA      AA  QQ     QQQ
 *      CCCC      OOOOOO    NN      NN      TT      RR      RR  ::::    DDDDDD      AA      AA    QQQQQQ QQ
 * ################################################################################################################# */

/**********************************************************************************************************************
  Xcp_CtrDaq_QueueInit()
**********************************************************************************************************************/
/*!
 *
 * \brief         Initializes all Send Queues.
 * \details       Initializes all Send Queues.
 * \param[in]     The XCP channel
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \config        Available only if XCP_DAQ == STD_ON.
 * \pre           -
 * \ingroup       ctrDaq
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CtrDaq_QueueInit( Xcp_ChannelType XcpChannel );

/**********************************************************************************************************************
  Xcp_CtrDaq_StartDaq()
**********************************************************************************************************************/
/*!
 *
 * \brief         Starts the selected DAQ list on the selected channel.
 * \details       Starts the selected DAQ list on the selected channel.
 * \param[in]     XcpChannel   The XCP channel.
 * \param[in]     Daq          The DAQ list number to start.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \config        Available only if XCP_DAQ == STD_ON.
 * \pre           -
 * \ingroup       ctrDaq
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CtrDaq_StartDaq( Xcp_ChannelType XcpChannel, uint16_least Daq );

/**********************************************************************************************************************
  Xcp_CtrDaq_StartAllSelectedDaq()
**********************************************************************************************************************/
/*!
 *
 * \brief         Start all DAQ lists selected for start.
 * \details       Iterates over all DAQ lists and starts the DAQ lists which have been marked as selected.
 * \param[in]     XcpChannel   The XCP channel.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \config        Available only if XCP_DAQ == STD_ON.
 * \pre           -
 * \ingroup       ctrDaq
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CtrDaq_StartAllSelectedDaq( Xcp_ChannelType XcpChannel );

/**********************************************************************************************************************
  Xcp_CtrDaq_StopDaq()
**********************************************************************************************************************/
/*!
 *
 * \brief         Stops the selected DAQ list on the selected channel.
 * \details       Stops the selected DAQ list on the selected channel.
 * \param[in]     XcpChannel   The XCP channel.
 * \param[in]     Daq          The DAQ list number to stop.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \config        Available only if XCP_DAQ == STD_ON.
 * \pre           -
 * \ingroup       ctrDaq
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CtrDaq_StopDaq( Xcp_ChannelType XcpChannel, uint16_least Daq );

/**********************************************************************************************************************
  Xcp_CtrDaq_StopAllSelectedDaq()
**********************************************************************************************************************/
/*!
 *
 * \brief         Stop all DAQ lists selected for stop.
 * \details       Iterates over all DAQ lists and stops the DAQ lists which have been marked as selected.
 * \param[in]     XcpChannel   The XCP channel.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \config        Available only if XCP_DAQ == STD_ON.
 * \pre           -
 * \ingroup       ctrDaq
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CtrDaq_StopAllSelectedDaq( Xcp_ChannelType XcpChannel );

/**********************************************************************************************************************
  Xcp_CtrDaq_StopAllDaq()
**********************************************************************************************************************/
/*!
 *
 * \brief         Stops all DAQ lists unconditionally.
 * \details       Stops all DAQ lists unconditionally.
 * \param[in]     XcpChannel   The XCP channel.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \config        Available only if XCP_DAQ == STD_ON.
 * \pre           -
 * \ingroup       ctrDaq
**********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CtrDaq_StopAllDaq( Xcp_ChannelType XcpChannel );
#endif /* ( XCP_DAQ == STD_ON ) */


/* ####################################################################################################################
 *      CCCC    MM      MM  DDDDDD    
 *    CC    CC  MMMM  MMMM  DD    DD  
 *  CC          MM  MM  MM  DD      DD
 *  CC          MM  MM  MM  DD      DD
 *  CC          MM      MM  DD      DD
 *    CC    CC  MM      MM  DD    DD  
 *      CCCC    MM      MM  DDDDDD    
 * ################################################################################################################# */

/**********************************************************************************************************************
  Xcp_Cmd_ReservedCmd()
**********************************************************************************************************************/
/*!
 *
 * \brief       Prepares error response if the requested command is not available.
 * \details     Prepares error response if the requested command is not available. Response contains XCP_E_CMD_UNKNOWN.
 * \param[in]   XcpChannel            The channel on which the error occurred or pending is requested.
 * \param[in]   CmdPtr                Containing the received XCP message for an unknown command.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdUnkown
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_Cmd_ReservedCmd( Xcp_ChannelType XcpChannel,
                                                    CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );


/*
 *  STANDARD COMMANDS
 */
/**********************************************************************************************************************
  Xcp_CmdStd_Connect()
**********************************************************************************************************************/
/*!
 *
 * \brief       Requests to connect an XCP channel.
 * \details     Command to set a connection to XCP Master active.
 * \param[in]   XcpChannel            The channel which should be connected.
 * \param[in]   CmdPtr                Containing the received XCP message for Connect Command.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_Connect( Xcp_ChannelType XcpChannel,
                                                   CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdStd_Disconnect()
**********************************************************************************************************************/
/*!
 *
 * \brief       Requests to disconnect an XCP channel.
 * \details     Command to set a connection to XCP Master inactive.
 * \param[in]   XcpChannel            The channel which should be disconnected.
 * \param[in]   CmdPtr                Containing the received XCP message for Disconnect Command.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_Disconnect( Xcp_ChannelType XcpChannel,
                                                      CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdStd_GetStatus()
**********************************************************************************************************************/
/*!
 *
 * \brief       Requests to respond the current session and protection status.
 * \details     Command to request a response message containing the session and the protection status.
 * \param[in]   XcpChannel            The channel which should be disconnected.
 * \param[in]   CmdPtr                Containing the received XCP message for GetStatus Command.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_GetStatus( Xcp_ChannelType XcpChannel,
                                                     CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdStd_Synch()
**********************************************************************************************************************/
/*!
 *
 * \brief       Prepare Synch response.
 * \details     Prepare Synch response.
 * \param[in]   XcpChannel            The channel to send response on.
 * \param[in]   CmdPtr                Containing the received XCP message for Synch Command.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_Synch( Xcp_ChannelType XcpChannel,
                                                 CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdStd_GetCommModeInfo()
**********************************************************************************************************************/
/*!
 *
 * \brief       Prepare response to the command GET_COMM_MODE_INFO.
 * \details     Prepare response to the command GET_COMM_MODE_INFO.
 * \param[in]   XcpChannel            The channel to send response on.
 * \param[in]   CmdPtr                Containing the received XCP message for Disconnect Command.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_GetCommModeInfo( Xcp_ChannelType XcpChannel,
                                                           CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

#if( (XCP_DAQ_RESUME == STD_ON) || (XCP_PAGE_FREEZE == STD_ON) )
/**********************************************************************************************************************
  Xcp_CmdStd_SetRequest()
**********************************************************************************************************************/
/*!
 *
 * \brief       Requests to store DAQ or Calibration data in non-volatile memory.
 * \details     Command to request storing or clearing of DAQ or Calibration data in non-volatile memory.
 * \param[in]   XcpChannel            The channel from which the DAQ or calibration data should be stored or cleared.
 * \param[in]   CmdPtr                Containing the received XCP message for SetRequest Command.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_DAQ_RESUME == STD_ON or if XCP_PAGE_FREEZE == STD_ON.
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_SetRequest( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

#if( XCP_SEED_KEY == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdStd_GetSeed()
**********************************************************************************************************************/
/*!
 *
 * \brief       Returns one part of the seed.
 * \details     Command to request one part of the seed that is required to unlock a protected resource.
 * \param[in]   XcpChannel            The channel from which the seed is requested.
 * \param[in]   CmdPtr                Containing the received XCP message for GetSeed Command.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_SEED_KEY == STD_ON.
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_GetSeed( Xcp_ChannelType XcpChannel,
                                                   CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdStd_Unlock()
**********************************************************************************************************************/
/*!
 *
 * \brief       Unlocks a protected resource.
 * \details     Command to unlock a protected resource depending on the previous Xcp_CmdStd_GetSeed sequence.
 * \param[in]   XcpChannel            The channel from which the resource should be unlocked.
 * \param[in]   CmdPtr                Containing the received XCP message for Unlock Command.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_SEED_KEY == STD_ON.
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_Unlock( Xcp_ChannelType XcpChannel,
                                                  CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

/**********************************************************************************************************************
  Xcp_CmdStd_SetMta()
**********************************************************************************************************************/
/*!
 *
 * \brief       Sets the address where the MTA is pointing to.
 * \details     Command to set the address where the MTA is pointing to.
 * \param[in]   XcpChannel            The channel from which the MTA should be set.
 * \param[in]   CmdPtr                Containing the received XCP message for SetMTA Command.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_SetMta( Xcp_ChannelType XcpChannel,
                                                  CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdStd_GetId()
**********************************************************************************************************************/
/*!
 *
 * \brief       Moves MTA to the requested position.
 * \details     Moves MTA to the requested position. Upload commands are recommended to follow this command.
 * \param[in]   XcpChannel            The channel from which the MTA should be set.
 * \param[in]   CmdPtr                Containing the received XCP message for GetId Command.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_GetId( Xcp_ChannelType XcpChannel,
                                                 CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdStd_Upload()
**********************************************************************************************************************/
/*!
 *
 * \brief       Reads and sends the data where the MTA is pointing to.
 * \details     Command to read and send the data where the MTA is pointing to. Increments the MTA afterwards.
 * \param[in]   XcpChannel            The channel from which the data should be uploaded to Master.
 * \param[in]   CmdPtr                Containing the received XCP message for Upload Command.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_Upload( Xcp_ChannelType XcpChannel,
                                                  CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdStd_ShortUpload()
**********************************************************************************************************************/
/*!
 *
 * \brief       Reads and sends data from a specific address.
 * \details     Command to read and send data from a specific address that is specified in the request XCP message 
 *              (CmdPtr).
 * \param[in]   XcpChannel            The channel from which the data should be uploaded to Master.
 * \param[in]   CmdPtr                Containing the received XCP message for ShortUpload Command.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_ShortUpload( Xcp_ChannelType XcpChannel,
                                                       CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

#if( XCP_CHECKSUM == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdStd_BuildChecksum()
**********************************************************************************************************************/
/*!
 *
 * \brief       Requests the calculation of a checksum.
 * \details     Command to request the calculation of a checksum. Sends the result in response frame.
 * \param[in]   XcpChannel            The channel for which the checksum should be calculated.
 * \param[in]   CmdPtr                Containing the received XCP message for BuildChecksum Command.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_CHECKSUM == STD_ON.
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_BuildChecksum( Xcp_ChannelType XcpChannel,
                                                         CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

/**********************************************************************************************************************
  Xcp_CmdStd_TlCmd()
**********************************************************************************************************************/
/*!
 *
 * \brief       Requests a service of a transport layer.
 * \details     Command to request a service of a transport layer.
 * \param[in]   XcpChannel            The channel for which the command should be executed.
 * \param[in]   CmdPtr                Containing the received XCP message for TlCmd Command.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_TlCmd( Xcp_ChannelType XcpChannel,
                                                 CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

#if( XCP_USER_COMMAND == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdStd_UserCmd()
**********************************************************************************************************************/
/*!
 *
 * \brief       Requests a service of the XCP Application.
 * \details     Command to request a service of the XCP Application. It forwards the request message (CmdPtr).
 * \param[in]   XcpChannel            The channel for which the command should be executed.
 * \param[in]   CmdPtr                Containing the received XCP message for UserCmd Command.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only if XCP_USER_COMMAND == STD_ON.
 * \pre         -
 * \ingroup     cmdStd
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_UserCmd( Xcp_ChannelType XcpChannel,
                                                   CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif


/*
 *  CALIBRATION COMMANDS
 */
#if( XCP_CALIBRATION == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdCal_Download()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process DOWNLOAD command.
 * \details       Process DOWNLOAD command to write received bytes to memory.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_CALIBRATION == STD_ON.
 * \ingroup       cmdCal
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdCal_Download( Xcp_ChannelType XcpChannel,
                                                    CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

# if( XCP_BLOCK_DOWNLOAD == STD_OFF )
/**********************************************************************************************************************
  Xcp_CmdCal_DownloadMax()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process DOWNLOAD_MAX command.
 * \details       Process DOWNLOAD_MAX command to write received bytes to memory.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_CALIBRATION == STD_ON and XCP_BLOCK_DOWNLOAD == STD_ON.
 * \ingroup       cmdCal
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdCal_DownloadMax( Xcp_ChannelType XcpChannel,
                                                       CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
# endif

# if( XCP_SHORT_DOWNLOAD == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdCal_ShortDownload()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process SHORT_DOWNLOAD command.
 * \details       Process SHORT_DOWNLOAD command to write received bytes to memory.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_CALIBRATION == STD_ON and XCP_SHORT_DOWNLOAD == STD_ON.
 * \ingroup       cmdCal
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdCal_ShortDownload( Xcp_ChannelType XcpChannel,
                                                         CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
# endif

# if( XCP_BLOCK_DOWNLOAD == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdCal_DownloadNext()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process DOWNLOAD_NEXT command.
 * \details       Process DOWNLOAD_NEXT command to write received bytes to memory.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_CALIBRATION == STD_ON and XCP_BLOCK_DOWNLOAD == STD_ON.
 * \ingroup       cmdCal
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdCal_DownloadNext( Xcp_ChannelType XcpChannel,
                                                       CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
# endif

# if( XCP_MODIFY_BITS == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdCal_ModifyBits()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process MODIFY_BITS command.
 * \details       Process MODIFY_BITS command to modify selected bits in memory.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_CALIBRATION == STD_ON and XCP_MODIFY_BITS == STD_ON.
 * \ingroup       cmdCal
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdCal_ModifyBits( Xcp_ChannelType XcpChannel,
                                                      CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
# endif
#endif /* ( XCP_CALIBRATION == STD_ON ) */

/*
 *  PAGE SWITCHING COMMANDS
 */
#if( XCP_CALIBRATION_PAGE == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdPag_SetCalPage()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process SET_CAL_PAGE command.
 * \details       Process SET_CAL_PAGE command with application call-back to switch pages.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_CALIBRATION_PAGE == STD_ON.
 * \ingroup       cmdPag
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPag_SetCalPage( Xcp_ChannelType XcpChannel,
                                                      CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdPag_GetCalPage()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process GET_CAL_PAGE command.
 * \details       Process GET_CAL_PAGE command with application call-back to get currently active page.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_CALIBRATION_PAGE == STD_ON.
 * \ingroup       cmdPag
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPag_GetCalPage( Xcp_ChannelType XcpChannel,
                                                      CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

#if( XCP_PAGE_INFO == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdPag_GetPageProcessorInfo()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process GET_PAG_PROCESSOR_INFO command.
 * \details       Process GET_PAG_PROCESSOR_INFO command.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_PAGE_INFO == STD_ON.
 * \ingroup       cmdPag
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPag_GetPageProcessorInfo( Xcp_ChannelType XcpChannel,
                                                                CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

#if( XCP_PAGE_FREEZE == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdPag_GetSegmentMode()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process GET_SEGMENT_MODE command.
 * \details       Process GET_SEGMENT_MODE command.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_PAGE_FREEZE == STD_ON.
 * \ingroup       cmdPag
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPag_GetSegmentMode( Xcp_ChannelType XcpChannel,
                                                          CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdPag_SetSegmentMode()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process SET_SEGMENT_MODE command.
 * \details       Process SET_SEGMENT_MODE command.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_PAGE_FREEZE == STD_ON.
 * \ingroup       cmdPag
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPag_SetSegmentMode( Xcp_ChannelType XcpChannel,
                                                          CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

#if( XCP_COPY_CAL_PAGE == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdPag_CopyCalPage()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process COPY_CAL_PAGE command.
 * \details       Process COPY_CAL_PAGE command to copy one page to another.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_COPY_CAL_PAGE == STD_ON.
 * \ingroup       cmdPag
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPag_CopyCalPage( Xcp_ChannelType XcpChannel,
                                                       CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif


/*
 *  DATA ACQUISITION AND STIMULATION COMMANDS
 */
#if( XCP_DAQ == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdDaq_SetDaqPtr()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process SET_DAQ_PTR command.
 * \details       Process SET_DAQ_PTR command to set the DAQ pointer accordingly.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_SetDaqPtr( Xcp_ChannelType XcpChannel,
                                                     CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdDaq_WriteDaq()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process WRITE_DAQ command.
 * \details       Process WRITE_DAQ command to write an DAQ entry.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_WriteDaq( Xcp_ChannelType XcpChannel,
                                                    CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

# if( XCP_WRITE_DAQ_MULTIPLE == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdDaq_WriteDaqMultiple()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process WRITE_DAQ_MULTIPLE command.
 * \details       Process WRITE_DAQ_MULTIPLE command to write multiple DAQ entries.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON and XCP_WRITE_DAQ_MULTIPLE == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_WriteDaqMultiple( Xcp_ChannelType XcpChannel,
                                                            CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
# endif

/**********************************************************************************************************************
  Xcp_CmdDaq_SetDaqListMode()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process SET_DAQ_LIST_MODE command.
 * \details       Process SET_DAQ_LIST_MODE command to set the mode of a DAQ list.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_SetDaqListMode( Xcp_ChannelType XcpChannel,
                                                          CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdDaq_GetDaqListMode()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process GET_DAQ_LIST_MODE command.
 * \details       Process GET_DAQ_LIST_MODE command to get the mode of a DAQ list.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_GetDaqListMode( Xcp_ChannelType XcpChannel,
                                                          CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdDaq_StartStopDaqList()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process START_STOP_DAQ_LIST command.
 * \details       Process START_STOP_DAQ_LIST command to select a DAQ list.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_StartStopDaqList( Xcp_ChannelType XcpChannel,
                                                            CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdDaq_StartStopSynch()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process START_STOP_SYNCH command.
 * \details       Process START_STOP_SYNCH command to start measurement.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_StartStopSynch( Xcp_ChannelType XcpChannel,
                                                          CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

# if( XCP_DAQ_TIMESTAMP_SIZE > 0 )
/**********************************************************************************************************************
  Xcp_CmdDaq_GetDaqClock()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process GET_DAQ_CLOCK command.
 * \details       Process GET_DAQ_CLOCK command to get the current timestamp.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON and XCP_DAQ_TIMESTAMP_SIZE greater 0.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_GetDaqClock( Xcp_ChannelType XcpChannel,
                                                       CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
# endif

/**********************************************************************************************************************
  Xcp_CmdDaq_GetDaqProcessorInfo()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process GET_DAQ_PROCESSOR_INFO command.
 * \details       Process GET_DAQ_PROCESSOR_INFO command to get DAQ plug&play info.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_GetDaqProcessorInfo( Xcp_ChannelType XcpChannel,
                                                               CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdDaq_GetDaqResolutionInfo()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process GET_DAQ_RESOLUTION_INFO command.
 * \details       Process GET_DAQ_RESOLUTION_INFO command to get DAQ plug&play info.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_GetDaqResolutionInfo( Xcp_ChannelType XcpChannel,
                                                                CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

#if( XCP_DAQ_EVENT_INFO == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdDaq_GetDaqEventInfo()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process GET_DAQ_EVENT_INFO command.
 * \details       Process GET_DAQ_EVENT_INFO command to get EventChannel plug&play info.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ_EVENT_INFO == STD_ON and XCP_MAX_EVENT is greater 0.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_GetDaqEventInfo( Xcp_ChannelType XcpChannel,
                                                           CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

/**********************************************************************************************************************
  Xcp_CmdDaq_FreeDaq()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process FREE_DAQ command.
 * \details       Process FREE_DAQ command to free all DAQ memory.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_FreeDaq( Xcp_ChannelType XcpChannel,
                                                   CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdDaq_AllocDaq()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process ALLOC_DAQ command.
 * \details       Process ALLOC_DAQ command to allocate DAQ lists.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_AllocDaq( Xcp_ChannelType XcpChannel,
                                                    CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdDaq_AllocOdt()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process ALLOC_ODT command.
 * \details       Process ALLOC_ODT command to allocate ODTs to DAQ lists.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_AllocOdt( Xcp_ChannelType XcpChannel,
                                                    CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdDaq_AllocOdtEntry()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process ALLOC_ODT_ENTRY command.
 * \details       Process ALLOC_ODT_ENTRY command to allocate ODTs Entries to DAQ lists.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_DAQ == STD_ON.
 * \ingroup       cmdDaq
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_AllocOdtEntry( Xcp_ChannelType XcpChannel,
                                                         CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif /* ( XCP_DAQ == STD_ON ) */


/*
 *  PROGRAMMING COMMANDS
 */
#if( (XCP_PROGRAM == STD_ON) || (XCP_BOOTLOADER_DOWNLOAD == STD_ON) )
/**********************************************************************************************************************
  Xcp_CmdPgm_ProgramStart()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process PROGRAM_START command.
 * \details       Process PROGRAM_START command to start programming sequence.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_PROGRAM == STD_ON or XCP_BOOTLOADER_DOWNLOAD == STD_ON.
 * \ingroup       cmdPgm
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_ProgramStart( Xcp_ChannelType XcpChannel,
                                                        CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

#if( XCP_PROGRAM == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdPgm_ProgramClear()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process PROGRAM_CLEAR command.
 * \details       Process PROGRAM_CLEAR command to clear flash memory.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_PROGRAM == STD_ON.
 * \ingroup       cmdPgm
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_ProgramClear( Xcp_ChannelType XcpChannel,
                                                        CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdPgm_Program()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process PROGRAM command.
 * \details       Process PROGRAM command to write to flash memory.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_PROGRAM == STD_ON.
 * \ingroup       cmdPgm
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_Program( Xcp_ChannelType XcpChannel,
                                                   CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdPgm_ProgramReset()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process PROGRAM command.
 * \details       Process PROGRAM command to write to flash memory.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_PROGRAM == STD_ON.
 * \ingroup       cmdPgm
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_ProgramReset( Xcp_ChannelType XcpChannel,
                                                        CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

#if( (XCP_PROGRAM == STD_ON) && (XCP_PROGRAM_INFO == STD_ON) )
/**********************************************************************************************************************
  Xcp_CmdPgm_GetPgmProcessorInfo()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process GET_PGM_PROCESSOR_INFO command.
 * \details       Process GET_PGM_PROCESSOR_INFO command to get flash plug&play info.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_PROGRAM == STD_ON and XCP_PROGRAM_INFO == STD_ON.
 * \ingroup       cmdPgm
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_GetPgmProcessorInfo( Xcp_ChannelType XcpChannel,
                                                               CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );

/**********************************************************************************************************************
  Xcp_CmdPgm_GetSectorInfo()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process GET_SECTOR_INFO command.
 * \details       Process GET_SECTOR_INFO command to get flash plug&play info.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_PROGRAM == STD_ON and XCP_PROGRAM_INFO == STD_ON.
 * \ingroup       cmdPgm
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_GetSectorInfo( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

#if( XCP_BOOTLOADER_DOWNLOAD == STD_ON )
/**********************************************************************************************************************
  Xcp_CmdPgm_ProgramPrepare()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process PROGRAM_PREPARE command.
 * \details       Process PROGRAM_PREPARE command to prepare for programming.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_BOOTLOADER_DOWNLOAD == STD_ON.
 * \ingroup       cmdPgm
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_ProgramPrepare( Xcp_ChannelType XcpChannel,
                                                          CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

#if( (XCP_PROGRAM == STD_ON) && (XCP_BLOCK_DOWNLOAD == STD_ON) )
/**********************************************************************************************************************
  Xcp_CmdPgm_ProgramNext()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process PROGRAM_NEXT command.
 * \details       Process PROGRAM_NEXT command to write to flash memory.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_PROGRAM == STD_ON and XCP_BLOCK_DOWNLOAD == STD_ON.
 * \ingroup       cmdPgm
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_ProgramNext( Xcp_ChannelType XcpChannel,
                                                       CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

#if( (XCP_PROGRAM == STD_ON) && (XCP_BLOCK_DOWNLOAD == STD_OFF) )
/**********************************************************************************************************************
  Xcp_CmdPgm_ProgramMax()
**********************************************************************************************************************/
/*!
 *
 * \brief         Process PROGRAM_MAX command.
 * \details       Process PROGRAM_MAX command to write to flash memory.
 * \param[in]     XcpChannel            The channel for which the command should be executed.
 * \param[in]     CmdPtr                The received command.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \pre           -
 * \config        Available only if XCP_PROGRAM == STD_ON and XCP_BLOCK_DOWNLOAD == STD_OFF.
 * \ingroup       cmdPgm
**********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_ProgramMax( Xcp_ChannelType XcpChannel,
                                                      CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr );
#endif

#define XCP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define XCP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* PRQA S 3218 1 */ /* MD_Xcp_3218_FileScopeStatic */
XCP_LOCAL CONSTP2FUNC(void, XCP_CODE, Xcp_CmdFct[64])( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr ) =
{
  Xcp_CmdStd_Connect,                     /* 0xFF = CONNECT */
  Xcp_CmdStd_Disconnect,                  /* 0xFE = DISCONNECT */
  Xcp_CmdStd_GetStatus,                   /* 0xFD = GET_STATUS */
  Xcp_CmdStd_Synch,                       /* 0xFC = SYNCH */
  Xcp_CmdStd_GetCommModeInfo,             /* 0xFB = GET_COMM_MODE_INFO */
  Xcp_CmdStd_GetId,                       /* 0xFA = GET_ID */
#if( (XCP_DAQ_RESUME == STD_ON) || (XCP_PAGE_FREEZE == STD_ON) )
  Xcp_CmdStd_SetRequest,                  /* 0xF9 = SET_REQUEST */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xF9 = SET_REQUEST */
#endif
#if( XCP_SEED_KEY == STD_ON )
  Xcp_CmdStd_GetSeed,                     /* 0xF8 = GET_SEED */
  Xcp_CmdStd_Unlock,                      /* 0xF7 = UNLOCK */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xF8 = GET_SEED */
  Xcp_Cmd_ReservedCmd,                    /* 0xF7 = UNLOCK */
#endif
  Xcp_CmdStd_SetMta,                      /* 0xF6 = SET_MTA */
  Xcp_CmdStd_Upload,                      /* 0xF5 = UPLOAD */
  Xcp_CmdStd_ShortUpload,                 /* 0xF4 = SHORT_UPLOAD */
#if( XCP_CHECKSUM == STD_ON )
  Xcp_CmdStd_BuildChecksum,               /* 0xF3 = BUILD_CHECKSUM */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xF3 = BUILD_CHECKSUM */
#endif
  Xcp_CmdStd_TlCmd,                       /* 0xF2 = TRANSPORT_LAYER_CMD */
#if( XCP_USER_COMMAND == STD_ON )
  Xcp_CmdStd_UserCmd,                     /* 0xF1 = USER_CMD */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xF1 = USER_CMD */
#endif
#if( XCP_CALIBRATION == STD_ON )
  Xcp_CmdCal_Download,                    /* 0xF0 = DOWNLOAD */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xF0 = DOWNLOAD */
#endif
#if( XCP_BLOCK_DOWNLOAD == STD_ON )
  Xcp_CmdCal_DownloadNext,                /* 0xEF = DOWNLOAD_NEXT */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xEF = DOWNLOAD_NEXT */
#endif
#if( (XCP_CALIBRATION == STD_ON) && (XCP_BLOCK_DOWNLOAD == STD_OFF) )
  Xcp_CmdCal_DownloadMax,                 /* 0xEE = DOWNLOAD_MAX */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xEE = DOWNLOAD_MAX */
#endif
#if( XCP_SHORT_DOWNLOAD == STD_ON ) && ( XCP_CALIBRATION == STD_ON )
  Xcp_CmdCal_ShortDownload,               /* 0xED = SHORT_DOWNLOAD */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xED = SHORT_DOWNLOAD */
#endif
#if( XCP_MODIFY_BITS == STD_ON ) && ( XCP_CALIBRATION == STD_ON )
  Xcp_CmdCal_ModifyBits,                  /* 0xEC = MODIFY_BITS */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xEC = MODIFY_BITS */
#endif
#if( XCP_CALIBRATION_PAGE == STD_ON )
  Xcp_CmdPag_SetCalPage,                  /* 0xEB = SET_CAL_PAGE */
  Xcp_CmdPag_GetCalPage,                  /* 0xEA = GET_CAL_PAGE */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xEB = SET_CAL_PAGE */
  Xcp_Cmd_ReservedCmd,                    /* 0xEA = GET_CAL_PAGE */
#endif
#if( XCP_PAGE_INFO == STD_ON )
  Xcp_CmdPag_GetPageProcessorInfo,        /* 0xE9 = GET_PAG_PROCESSOR_INFO */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xE9 = GET_PAG_PROCESSOR_INFO */
#endif
  Xcp_Cmd_ReservedCmd,                    /* 0xE8 = GET_SEGMENT_INFO */
  Xcp_Cmd_ReservedCmd,                    /* 0xE7 = GET_PAGE_INFO */
#if( XCP_PAGE_FREEZE == STD_ON )
  Xcp_CmdPag_SetSegmentMode,              /* 0xE6 = SET_SEGMENT_MODE */
  Xcp_CmdPag_GetSegmentMode,              /* 0xE5 = GET_SEGMENT_MODE */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xE6 = SET_SEGMENT_MODE */
  Xcp_Cmd_ReservedCmd,                    /* 0xE5 = GET_SEGMENT_MODE */
#endif
#if( XCP_COPY_CAL_PAGE == STD_ON )
  Xcp_CmdPag_CopyCalPage,                 /* 0xE4 = COPY_CAL_PAGE */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xE4 = COPY_CAL_PAGE */
#endif
#if( XCP_DAQ == STD_ON )
  Xcp_Cmd_ReservedCmd,                    /* 0xE3 = CLEAR_DAQ_LIST */
  Xcp_CmdDaq_SetDaqPtr,                   /* 0xE2 = SET_DAQ_PTR */
  Xcp_CmdDaq_WriteDaq,                    /* 0xE1 = WRITE_DAQ */
  Xcp_CmdDaq_SetDaqListMode,              /* 0xE0 = SET_DAQ_LIST_MODE */
  Xcp_CmdDaq_GetDaqListMode,              /* 0xDF = GET_DAQ_LIST_MODE */
  Xcp_CmdDaq_StartStopDaqList,            /* 0xDE = START_STOP_DAQ_LIST */
  Xcp_CmdDaq_StartStopSynch,              /* 0xDD = START_STOP_SYNCH */
# if( XCP_DAQ_TIMESTAMP_SIZE > 0 )
  Xcp_CmdDaq_GetDaqClock,                 /* 0xDC = GET_DAQ_CLOCK */
# else
  Xcp_Cmd_ReservedCmd,                    /* 0xDC = GET_DAQ_CLOCK */
# endif
  Xcp_Cmd_ReservedCmd,                    /* 0xDB = READ_DAQ */
  Xcp_CmdDaq_GetDaqProcessorInfo,         /* 0xDA = GET_DAQ_PROCESSOR_INFO */
  Xcp_CmdDaq_GetDaqResolutionInfo,        /* 0xD9 = GET_DAQ_RESOLUTION_INFO */
  Xcp_Cmd_ReservedCmd,                    /* 0xD8 = GET_DAQ_LIST_INFO */
# if( XCP_DAQ_EVENT_INFO == STD_ON )
  Xcp_CmdDaq_GetDaqEventInfo,             /* 0xD7 = GET_DAQ_EVENT_INFO */
# else
  Xcp_Cmd_ReservedCmd,                    /* 0xD7 = GET_DAQ_EVENT_INFO */
# endif
  Xcp_CmdDaq_FreeDaq,                     /* 0xD6 = FREE_DAQ */
  Xcp_CmdDaq_AllocDaq,                    /* 0xD5 = ALLOC_DAQ */
  Xcp_CmdDaq_AllocOdt,                    /* 0xD4 = ALLOC_ODT */
  Xcp_CmdDaq_AllocOdtEntry,               /* 0xD3 = ALLOC_ODT_ENTRY */
#else /* ( XCP_DAQ == STD_ON ) */
  Xcp_Cmd_ReservedCmd,                    /* 0xE3 = CLEAR_DAQ_LIST */
  Xcp_Cmd_ReservedCmd,                    /* 0xE2 = SET_DAQ_PTR */
  Xcp_Cmd_ReservedCmd,                    /* 0xE1 = WRITE_DAQ */
  Xcp_Cmd_ReservedCmd,                    /* 0xE0 = SET_DAQ_LIST_MODE */
  Xcp_Cmd_ReservedCmd,                    /* 0xDF = GET_DAQ_LIST_MODE */
  Xcp_Cmd_ReservedCmd,                    /* 0xDE = START_STOP_DAQ_LIST */
  Xcp_Cmd_ReservedCmd,                    /* 0xDD = START_STOP_SYNCH */
  Xcp_Cmd_ReservedCmd,                    /* 0xDC = GET_DAQ_CLOCK */
  Xcp_Cmd_ReservedCmd,                    /* 0xDB = READ_DAQ */
  Xcp_Cmd_ReservedCmd,                    /* 0xDA = GET_DAQ_PROCESSOR_INFO */
  Xcp_Cmd_ReservedCmd,                    /* 0xD9 = GET_DAQ_RESOLUTION_INFO */
  Xcp_Cmd_ReservedCmd,                    /* 0xD8 = GET_DAQ_LIST_INFO */
  Xcp_Cmd_ReservedCmd,                    /* 0xD7 = GET_DAQ_EVENT_INFO */
  Xcp_Cmd_ReservedCmd,                    /* 0xD6 = FREE_DAQ */
  Xcp_Cmd_ReservedCmd,                    /* 0xD5 = ALLOC_DAQ */
  Xcp_Cmd_ReservedCmd,                    /* 0xD4 = ALLOC_ODT */
  Xcp_Cmd_ReservedCmd,                    /* 0xD3 = ALLOC_ODT_ENTRY */
#endif /* ( XCP_DAQ == STD_ON ) */
#if( (XCP_PROGRAM == STD_ON) || (XCP_BOOTLOADER_DOWNLOAD == STD_ON) )
  Xcp_CmdPgm_ProgramStart,                /* 0xD2 = PROGRAM_START */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xD2 = PROGRAM_START */
#endif
#if( XCP_PROGRAM == STD_ON )
  Xcp_CmdPgm_ProgramClear,                /* 0xD1 = PROGRAM_CLEAR */
  Xcp_CmdPgm_Program,                     /* 0xD0 = PROGRAM */
  Xcp_CmdPgm_ProgramReset,                /* 0xCF = PROGRAM_RESET */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xD1 = PROGRAM_CLEAR */
  Xcp_Cmd_ReservedCmd,                    /* 0xD0 = PROGRAM */
  Xcp_Cmd_ReservedCmd,                    /* 0xCF = PROGRAM_RESET */
#endif
#if( (XCP_PROGRAM == STD_ON) && (XCP_PROGRAM_INFO == STD_ON) )
  Xcp_CmdPgm_GetPgmProcessorInfo,         /* 0xCE = GET_PGM_PROCESSOR_INFO */
  Xcp_CmdPgm_GetSectorInfo,               /* 0xCD = GET_SECTOR_INFO */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xCE = GET_PGM_PROCESSOR_INFO */
  Xcp_Cmd_ReservedCmd,                    /* 0xCD = GET_SECTOR_INFO */
#endif
#if( XCP_BOOTLOADER_DOWNLOAD == STD_ON )
  Xcp_CmdPgm_ProgramPrepare,              /* 0xCC = PROGRAM_PREPARE */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xCC = PROGRAM_PREPARE */
#endif
  Xcp_Cmd_ReservedCmd,                    /* 0xCB = PROGRAM_FORMAT */
#if( (XCP_PROGRAM == STD_ON) && (XCP_BLOCK_DOWNLOAD == STD_ON) )
  Xcp_CmdPgm_ProgramNext,                 /* 0xCA = PROGRAM_NEXT */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xCA = PROGRAM_NEXT */
#endif
#if( (XCP_PROGRAM == STD_ON) && (XCP_BLOCK_DOWNLOAD == STD_OFF) )
  Xcp_CmdPgm_ProgramMax,                  /* 0xC9 = PROGRAM_MAX */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xC9 = PROGRAM_MAX */
#endif
  Xcp_Cmd_ReservedCmd,                    /* 0xC8 = PROGRAM_VERIFY */
#if( XCP_WRITE_DAQ_MULTIPLE == STD_ON )
  Xcp_CmdDaq_WriteDaqMultiple,            /* 0xC7 = WRITE_DAQ_MULTIPLE */
#else
  Xcp_Cmd_ReservedCmd,                    /* 0xC7 = WRITE_DAQ_MULTIPLE */
#endif
  Xcp_Cmd_ReservedCmd,                    /* 0xC6 = RESERVED */
  Xcp_Cmd_ReservedCmd,                    /* 0xC5 = RESERVED */
  Xcp_Cmd_ReservedCmd,                    /* 0xC4 = RESERVED */
  Xcp_Cmd_ReservedCmd,                    /* 0xC3 = RESERVED */
  Xcp_Cmd_ReservedCmd,                    /* 0xC2 = RESERVED */
  Xcp_Cmd_ReservedCmd,                    /* 0xC1 = RESERVED */
  Xcp_Cmd_ReservedCmd,                    /* 0xC0 = RESERVED */
};

#define XCP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define XCP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if( (XCP_CHECKSUM == STD_ON) && (XCP_CUSTOM_CRC == STD_OFF) )
/**********************************************************************************************************************
 *  Xcp_Hlp_CalcAndSendChecksumResult()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_Hlp_CalcAndSendChecksumResult( void )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least XcpChannel;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Multi Client - Iteration over all available channels. */
  for( XcpChannel = 0; XcpChannel < XCP_NUMBER_OF_CHANNELS; XcpChannel++ )
  {
    /* #20 Calculation is done block wise:
     *           If there is still something to calculate, determine the next blocksize.*/
    if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSumSize) > 0u )
    {
# if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16CITT )
# else
#  if( XCP_AUTOSAR_CRC_MODULE == STD_OFF )
      tXcpChecksumAddType checkSum = 0;
#  endif
# endif
      uint16 checksumSize;

      if( Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSumSize <= (kXcpChecksumBlockSize - 1) )
      {
        checksumSize = Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSumSize;
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSumSize = 0;
      }
      else
      {
        checksumSize = kXcpChecksumBlockSize;
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSumSize = Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSumSize - kXcpChecksumBlockSize;
      }

      /* #30 And perform checksum calculation over the blocksize. The algorithm is either: */
# if( XCP_AUTOSAR_CRC_MODULE == STD_ON )

      /* #40 Calculate CRC with AUTOSAR CRC module. */
      /* PRQA S 0306 4 */ /* MD_Xcp_0306 */
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSum = 
        XcpCalculateCrc( (P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA))Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA,
                         (uint32)checksumSize, 
                         Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSum );
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA += (Xcp_AddressPtrType)checksumSize;

# else

      /* #50 Use built in CRC algorithm. */
      do
      {
#  if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16CITT )
        uint8 mtaValue = 0;
        (void)XcpAppl_MeasurementRead( (P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR))&mtaValue, 
                                       Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA, 
                                       1
                                     );

        Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSum = CRC16CCITTtab[((uint8)((Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSum >> 8) &
                                                                       0xff)) ^ mtaValue] ^ 
                                                             (Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSum << 8);

        Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA += 1;
        checksumSize                         -= 1;
#  else
#   if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD22 ) || ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD24 ) || ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD44 )
        uint32 tempCheckSum;
#   endif
        /* #60 Checksum calculation method: XCP_ADD_xx */
        (void)XcpAppl_MeasurementRead( (P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR))&checkSum, 
                                       Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA, 
                                       (uint8)sizeof(tXcpChecksumAddType)
                                     );
#   if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD22 ) || ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD24 )
        tempCheckSum = Xcp_GetVal16(&checkSum);
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSum += (tXcpChecksumType)tempCheckSum;
#   elif ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD44 )
        tempCheckSum = Xcp_GetVal32(&checkSum);
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSum += (tXcpChecksumType)tempCheckSum;
#   else
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSum += (tXcpChecksumType)checkSum;
#   endif
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA      += (uint8)sizeof(tXcpChecksumAddType);
        checksumSize                              -= (uint8)sizeof(tXcpChecksumAddType);
#  endif
      }
      while( checksumSize > 0 );
# endif /* ( XCP_AUTOSAR_CRC_MODULE == STD_ON ) */

      /* #70 Prepare response string containing CRC if, and only, block is finished. */
      if( Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSumSize == 0 )
      {
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_BUILD_CHECKSUM_TYPE]         = kXcpChecksumMethod;
        /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
        /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
        Xcp_PutVal32( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.l[XCP_CRM_BUILD_CHECKSUM_RESULT >> 2u], 
                      (uint32)Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSum );
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_BUILD_CHECKSUM_LEN;

        Xcp_SendCrm((Xcp_ChannelType)XCP_CHANNEL_IDX);
      }
    }
  }
} /* Xcp_Hlp_CalcAndSendChecksumResult */
#endif /* ( XCP_CHECKSUM == STD_ON ) && ( XCP_CUSTOM_CRC == STD_OFF ) */


/**********************************************************************************************************************
 *  Xcp_Hlp_MemSet()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_Hlp_MemSet( P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR) Destination,
                                                      uint32 Length,
                                                      uint8 Value )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32_least index;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set memory area to value. */
  for( index = 0; index < Length; index++ )
  {
    Destination[index] = Value;
  }
} /* Xcp_Hlp_MemSet */


#if( XCP_DAQ == STD_ON )
/**********************************************************************************************************************
 *  Xcp_Hlp_SendDtoFromQueue()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_Hlp_SendDtoFromQueue( Xcp_ChannelType XcpChannel )
{
  uint32 ReadIdx;
  uint16_least i;
  /* ----- Implementation ----------------------------------------------- */
  Xcp_Enter_Exclusive_Area_Common(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* #10 The Send Queue is core specific. Iterate over all Cores/Send Queues. If any of them contains data: */
  for( i = 0u; i < XCP_NUMBER_OF_CORES; i++ )
  {
    /* Send Queue contains data? */
    if ( ((Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus & (uint8)XCP_SEND_PENDING) == 0u)
       && (Xcp_SendQueueWriteIdx[XCP_CHANNEL_IDX][i] != Xcp_SendQueueReadIdx[XCP_CHANNEL_IDX][i]) )
    {
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus |= (uint8)XCP_DTO_PENDING;
      /* #20 Call XcpTl_Send. First uint16 of Send Queue entry always contains the length and the remaining bytes of the current DTO. */

      /* PRQA S 3305 5 */ /* MD_Xcp_3305 */
      /* PRQA S 0310 4 */ /* MD_Xcp_0310 */
      (void)Xcp_CallTlFunction_3_Param( XCP_CHANNEL_IDX,
                                        XcpTl_Send,
                                        (uint8)*((P2VAR(uint16, AUTOMATIC, XCP_VAR_NOINIT))&(Xcp_SendQueueRef[i][(XCP_CHANNEL_IDX * Xcp_SendQueueSize[i]) + Xcp_SendQueueReadIdx[XCP_CHANNEL_IDX][i]])),
                                        &(Xcp_SendQueueRef[i][(XCP_CHANNEL_IDX * Xcp_SendQueueSize[i]) + Xcp_SendQueueReadIdx[XCP_CHANNEL_IDX][i] + 2u]) );

      /* #30 Increment Send Queue read index with round robin handling - thread safe. */
      ReadIdx = Xcp_SendQueueReadIdx[XCP_CHANNEL_IDX][i];
      ReadIdx = ReadIdx + Xcp_SendQueueEntrySize[XCP_CHANNEL_IDX];
      if( ReadIdx >= Xcp_SendQueueSizeLimit[XCP_CHANNEL_IDX][i] )
      {
        ReadIdx = 0u;
      }
      Xcp_SendQueueReadIdx[XCP_CHANNEL_IDX][i] = ReadIdx;
      break;
    }
  }
  Xcp_Leave_Exclusive_Area_Common(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_Hlp_SendDtoFromQueue */


/**********************************************************************************************************************
 *  Xcp_Hlp_CalcSendQueueEntrySizeAndLimit()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_Hlp_CalcSendQueueEntrySizeAndLimit( Xcp_ChannelType XcpChannel )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least i;
  
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate Send Queue parameters based on MaxDto parameter (variable entry size). */
  Xcp_SendQueueEntrySize[XCP_CHANNEL_IDX] = (uint16)((Xcp_ChannelInfo[XCP_CHANNEL_IDX].MaxDto + XCP_CONNECT_DTO_OFFSET + 1u) & 0xFFFE);
  for( i = 0; i < XCP_NUMBER_OF_CORES; i++)
  {
    /* MaxDto is always >= 8, therefore a division by zero is not possible */
    Xcp_SendQueueSizeLimit[XCP_CHANNEL_IDX][i] = 
      (Xcp_SendQueueSize[i] / ((Xcp_ChannelInfo[XCP_CHANNEL_IDX].MaxDto + XCP_CONNECT_DTO_OFFSET + 1u) & 0xFFFE))
      * Xcp_SendQueueEntrySize[XCP_CHANNEL_IDX];
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_Hlp_CalcSendQueueEntrySizeAndLimit */


/**********************************************************************************************************************
 *  Xcp_Hlp_EventDaq()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_Hlp_EventDaq( uint8_least XcpChannel,
                                                         uint16 CoreIdx,
                                                         P2CONST(Xcp_ChannelStruct, AUTOMATIC, XCP_VAR_NOINIT) pXcp,
                                                         uint16_least Daq )
{
  P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) pDto;
  Xcp_OdtEntryIdxType entryIdx;
  uint16_least dtoLength;
  uint8_least  odt;
  uint8_least  odtEntry;
  uint8 retVal = XCP_EVENT_DAQ;

  /* #10 Iterate over all ODTs of this DAQ list: */
  for( odt = 0; odt < pXcp->DaqList.nOdtsDaq[Daq]; odt++ )
  {
    uint32 WriteIdx;

    /* determine first ODT entry for later use */
    entryIdx = pXcp->DaqList.FirstOdtEntry[pXcp->DaqList.FirstOdt[Daq] + odt];

    /* #20 Enter XCP_EXCLUSIVE_AREA_1. */
    Xcp_Enter_Exclusive_Area_Daq(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* Any space left in the Send Queue? */
    /* #30 Increment Send Queue write index with round robin handling - thread safe. */
    WriteIdx = Xcp_SendQueueWriteIdx[XCP_CHANNEL_IDX][CoreIdx] + Xcp_SendQueueEntrySize[XCP_CHANNEL_IDX];
    if( WriteIdx >= Xcp_SendQueueSizeLimit[XCP_CHANNEL_IDX][CoreIdx] )
    {
      WriteIdx = 0u;
    }

    /* #40 Try to allocate new entry. If no space left in queue, signal overload condition, break current ODT and leave XCP_EXCLUSIVE_AREA_1. */
    if( WriteIdx != Xcp_SendQueueReadIdx[XCP_CHANNEL_IDX][CoreIdx] )
    {
      /* Yes, allocate new entry. */
      pDto = Xcp_SendQueueRef[CoreIdx];
      pDto = &(pDto[(XCP_CHANNEL_IDX * Xcp_SendQueueSize[CoreIdx]) + Xcp_SendQueueWriteIdx[XCP_CHANNEL_IDX][CoreIdx]]);
    }
    else
    {
# if ( XCP_DAQ_OVERRUN_INDICATION == STD_ON )
      Xcp_OverloadFlag[XCP_CHANNEL_IDX][CoreIdx] = XCP_DAQ_OVERLOAD_MSB;
# endif
      retVal |= XCP_EVENT_DAQ_OVERLOAD;
      Xcp_Leave_Exclusive_Area_Daq(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      break;
    }

    /* #50 Determine PID of response frame. */
# if (XCP_DAQ_HDR_LEN == 1u)
    pDto[2u] = (uint8)(pXcp->DaqList.FirstOdt[Daq] + odt);
# elif (XCP_DAQ_HDR_LEN == 2u)
    pDto[2u] = (uint8)odt;
    pDto[3u] = (uint8)Daq;
# else
#  error "Unsupported XCP Identification Field!"
# endif
# if ( XCP_DAQ_OVERRUN_INDICATION == STD_ON )
    pDto[2u] = pDto[2u] | Xcp_OverloadFlag[XCP_CHANNEL_IDX][CoreIdx];
    Xcp_OverloadFlag[XCP_CHANNEL_IDX][CoreIdx] = 0u;
# endif
    /* #60 We reserve the first 2 bytes for the DTO length. */
    dtoLength = 2u + XCP_DAQ_HDR_LEN;

# if( XCP_DAQ_TIMESTAMP_SIZE > 0 )
    /* #70 If it is the first ODT and timestamp mode is enabled, acquire timestamp and insert in response frame. */
    if( (odt == 0u) 
#  if( XCP_DAQ_TIMESTAMP_FIXED == STD_OFF )
     && ((pXcp->DaqList.Mode[Daq] & XCP_DAQ_LIST_TIMESTAMP) > 0u) 
#  endif
      )
    {
      Xcp_TimestampType xcpTimestamp;
      /* Yes, acquire timestamp and insert in response frame. */
      xcpTimestamp = XcpAppl_GetTimestamp();
#  if( XCP_DAQ_TIMESTAMP_SIZE == 1u )
      pDto[dtoLength] = xcpTimestamp;
#  elif( XCP_DAQ_TIMESTAMP_SIZE == 2u )
      /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
      /* PRQA S 0310 3 */ /* MD_Xcp_0310 */
      Xcp_PutVal16( &pDto[dtoLength], xcpTimestamp );
#  elif( XCP_DAQ_TIMESTAMP_SIZE == 4u )
      Xcp_PutVal32( &pDto[dtoLength], xcpTimestamp );
#  else
#  error "Illegal time stamp size configured!"
#  endif
      dtoLength += sizeof(Xcp_TimestampType);
    }
# endif
    
    /* #80 Iterate over all ODT entries and copy data, as long as we do not have an illegal DAQ list (break in this case). */
    for( odtEntry = 0u; odtEntry < pXcp->DaqList.nOdtEntriesOdt[pXcp->DaqList.FirstOdt[Daq] + odt]; odtEntry++ ) /* PRQA S 3689 */ /* MD_Xcp_3689 */
    {
      if( pXcp->DaqList.OdtEntriesSize[entryIdx] > 0u )
      {
        /* Size check. Verify if we have an illegal DAQ list and break in this case. */
        if( (dtoLength + pXcp->DaqList.OdtEntriesSize[entryIdx]) > Xcp_SendQueueEntrySize[XCP_CHANNEL_IDX] )
        {
          break;
        }
        /* Copy measurement value */
# if( XCP_DAQ_MEM_ACCESS_BY_APPL == STD_ON )
        (void)XcpAppl_MeasurementRead( &pDto[dtoLength],
                                       pXcp->DaqList.OdtEntries[entryIdx],
                                       pXcp->DaqList.OdtEntriesSize[entryIdx] );
# else
        /* PRQA S 0306 3 */ /* MD_Xcp_0306 */
        XcpAppl_MemCpy( &pDto[dtoLength],
                        (P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR))((Xcp_AddressPtrType)pXcp->DaqList.OdtEntries[entryIdx]),
                        pXcp->DaqList.OdtEntriesSize[entryIdx] );
# endif
        dtoLength = dtoLength + pXcp->DaqList.OdtEntriesSize[entryIdx];
      }
      else
      {
        break; /* PRQA S 0771 */ /* MD_Xcp_0771 */
      }

      entryIdx++;
    }

    /* #90 Post processing, store length of this DTO in the first 2 bytes of the DTO and write queue index to insert the entry. 
     *     Transmission is triggered in the Xcp_MainFunction. */
    /* PRQA S 3305 1 */ /* MD_Xcp_3305 */
    ((P2VAR(uint16, AUTOMATIC, XCP_VAR_NOINIT))pDto)[0] = (uint16)dtoLength - 2; /* PRQA S 0310 */ /* MD_Xcp_0310 */
    Xcp_SendQueueWriteIdx[XCP_CHANNEL_IDX][CoreIdx] = WriteIdx;

    /* #100 Leave XCP_EXCLUSIVE_AREA_1. */
    Xcp_Leave_Exclusive_Area_Daq(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return retVal;
} /* Xcp_Hlp_EventDaq */


# if( XCP_STIM == STD_ON )
/**********************************************************************************************************************
 *  Xcp_Hlp_EventStim()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_Hlp_EventStim( uint8_least XcpChannel,
                                                          P2CONST(Xcp_ChannelStruct, AUTOMATIC, XCP_VAR_NOINIT) pXcp, 
                                                          uint16_least Daq )
{
  P2VAR(tXcpDto, AUTOMATIC, XCP_VAR_NOINIT) pStimBuf;
  Xcp_OdtEntryIdxType entryIdx;
  uint16_least dtoLength;
  uint8_least  odtEntry;
  Xcp_OdtIdxType odt;
  uint8 retVal = XCP_EVENT_STIM;

  /* #10 Iterate over all ODTs of this DAQ list: */
  for( odt = pXcp->DaqList.FirstOdt[Daq];
       odt < (pXcp->DaqList.FirstOdt[Daq] + pXcp->DaqList.nOdtsDaq[Daq]);
       odt++ )
  {
    /* determine first ODT entry for later use */
    entryIdx = Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.FirstOdtEntry[odt];

    if( pXcp->DaqList.nOdtEntriesOdt[odt] == 0u )
    {
      break;
    }

    /* #20 Get pointer to STIM buffer of current ODT. If valid data is available: */
    pStimBuf = pXcp->DaqList.pStimBuffer[odt];
    if( pStimBuf == NULL_PTR )
    {
      break; /* PRQA S 0771 */ /* MD_Xcp_0771 */
    }

    if ( pStimBuf->buffer.b[0] == 0xFFu )
    { /* No STIM data available */
      retVal |= XCP_EVENT_STIM_OVERRUN; 
    }
    else
    {
      Xcp_Enter_Exclusive_Area_Stim(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      if (Xcp_StimMode == XCP_STIM_SINGLE_SHOT_MODE)
      {
        /* #30 Invalidate STIM data buffer. */
        pStimBuf->buffer.b[0] = 0xFFu;
      }
# if (XCP_DAQ_HDR_LEN == 1u)
      dtoLength = 1u;
# else
      dtoLength = 2u;
# endif
#  if( XCP_DAQ_TIMESTAMP_SIZE > 0u )
      /* #40 Time stamp is only applicable in first ODT of STIM. If it is the 1st ODT, remove the timestamp. */
      if( odt == pXcp->DaqList.FirstOdt[Daq] )
      {
#   if( XCP_DAQ_TIMESTAMP_FIXED == STD_OFF )
        if( (pXcp->DaqList.Mode[Daq] & XCP_DAQ_FLAG_TIMESTAMP) > 0u )
#   endif
        {
          dtoLength += sizeof(Xcp_TimestampType);
        }
      }
#  endif
      /* #50 Iterate over all entries of this ODT and copy calibration data to application space, as long as we do not 
       *     have an illegal DAQ list (break in this case). */
      for( odtEntry = 0u; odtEntry < pXcp->DaqList.nOdtEntriesOdt[odt]; odtEntry++ )
      {
        if( pXcp->DaqList.OdtEntriesSize[entryIdx] > 0u )
        {
          /* Size check. Verify if we have an illegal DAQ list and break in this case. */
          if( (dtoLength + pXcp->DaqList.OdtEntriesSize[entryIdx]) > pXcp->MaxDto )
          {
            break;
          }

          /* Copy the calibration data to application space. */
#  if ( XCP_DAQ_MEM_ACCESS_BY_APPL == STD_ON )
          (void)XcpAppl_CalibrationWrite(pXcp->DaqList.OdtEntries[entryIdx], &pStimBuf->buffer.b[dtoLength], pXcp->DaqList.OdtEntriesSize[entryIdx]);
#  else
          /* PRQA S 0306 3 */ /* MD_Xcp_0306 */
          XcpAppl_MemCpy( (P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR))((Xcp_AddressPtrType)(pXcp->DaqList.OdtEntries[entryIdx])),
                           &pStimBuf->buffer.b[dtoLength],
                           pXcp->DaqList.OdtEntriesSize[entryIdx] );
#  endif
          dtoLength = dtoLength + pXcp->DaqList.OdtEntriesSize[entryIdx];
        }
        else
        {
          break; /* PRQA S 0771 */ /* MD_Xcp_0771 */
        }
        entryIdx++;
      }
      Xcp_Leave_Exclusive_Area_Stim(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return retVal;
  /* PRQA S 6010 3 */ /* MD_MSR_STPTH */
  /* PRQA S 6030 2 */ /* MD_MSR_STCYC */
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_Hlp_EventStim */


/**********************************************************************************************************************
 *  Xcp_Hlp_StimEventStatus()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_Hlp_StimEventStatus( uint8_least XcpChannel, uint16_least Daq, uint8 Action )
{
  P2VAR(tXcpDto, AUTOMATIC, XCP_VAR_NOINIT) pStimBuf;
  uint16_least   entryIdx;
  Xcp_OdtIdxType odt;
  uint8 result = XCP_NO_STIM_DATA_AVAILABLE;

  /* #10 Iterate over all ODTs of this DAQ list: */
  for( odt = Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.FirstOdt[Daq];
       odt < (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.FirstOdt[Daq] + Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtsDaq[Daq]);
       odt++ )
  {
    /* #20 Get the first entry Idx of this ODT and check if it is valid. */
    entryIdx = Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.FirstOdtEntry[odt];
    if ( Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.OdtEntriesSize[entryIdx] == 0u )
    {
      continue; /* PRQA S 0770 */ /* MD_Xcp_0770 */
    }

    /* #30 Get pointer to STIM buffer and check if it is valid. If so, perform the requested action on it. */
    pStimBuf = Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.pStimBuffer[odt];
    if( pStimBuf == NULL_PTR )
    {
      continue; /* PRQA S 0770 */ /* MD_Xcp_0770 */
    }

    if (Action == XCP_STIM_CHECK_ODT_BUFFER)
    {
      if ( pStimBuf->buffer.b[0u] != (uint8)0xFFu )
      {
         result = XCP_STIM_DATA_AVAILABLE; /* STIM data available */
      }
    }
    else /* STIM_RESET_ODT_BUFFER */
    if (Action == XCP_STIM_RESET_ODT_BUFFER)
    {
      pStimBuf->buffer.b[0u] = 0xFFu;
    }
    else
    {
       /* No action selected. MISRA confirming else branch. */
    }
  } /* ODT */

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return result;
} /* Xcp_Hlp_StimEventStatus */
# endif /* XCP_STIM */
#endif /* ( XCP_DAQ == STD_ON ) */


#if( (XCP_SEND_EVENT == STD_ON) || (XCP_SERV_TEXT == STD_ON) )
/**********************************************************************************************************************
 *  Xcp_Hlp_SendAsyncEvent()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_Hlp_SendAsyncEvent( Xcp_ChannelType XcpChannel )
{
  /* ----- Implementation ----------------------------------------------- */
  Xcp_Enter_Exclusive_Area_Common(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* #10 If there is still a transmission pending, indicate an error.
   *     Otherwise, forward the event to XCP Transport Layer. */
  if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus & (uint8)XCP_SEND_PENDING) != 0 )
  {
    if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus & (uint8)XCP_EVT_REQUEST) != 0 )
    {
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus |= (uint16)XCP_SESSION_ERROR;
    }
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus |= (uint8)XCP_EVT_REQUEST;
  }
  else
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus |= (uint8)XCP_EVT_PENDING;

    (void)Xcp_CallTlFunction_3_Param( XCP_CHANNEL_IDX,
                                      XcpTl_Send,
                                      Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrameLength,
                                      &Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrame.b[0] );
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrameLength = 0;
  }

  Xcp_Leave_Exclusive_Area_Common(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_Hlp_SendAsyncEvent */


/**********************************************************************************************************************
 *  Xcp_Hlp_OccurredPendingTxConfirmation()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
XCP_LOCAL_INLINE FUNC(boolean, XCP_CODE) Xcp_Hlp_OccurredPendingTxConfirmation( Xcp_ChannelType XcpChannel )
{
  boolean isMsgAccepted = TRUE;

  /* #10 If a TxConfirmation is pending, wait until it occurs.
   *     The application has the possibility to reject the message and stop the waiting. */
  while( ((Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus & (uint8)XCP_SEND_PENDING) != 0)
      && (isMsgAccepted == TRUE) )
  {
    if( XcpAppl_SendStall(XCP_CHANNEL_IDX) == 0 )
    {
      isMsgAccepted = FALSE;
    }
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  return isMsgAccepted;
} /* Xcp_Hlp_OccurredPendingTxConfirmation */
#endif




#if( XCP_SEED_KEY == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdHlp_BitCounter()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_CmdHlp_BitCounter( uint32 ValueToCheck )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least numberOfBits;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Perform algorithm to count the number of bits in an uint32. */
  for( numberOfBits = 0; (ValueToCheck > 0) && (numberOfBits <= 32); numberOfBits++ )
  {
    ValueToCheck &= (ValueToCheck - 1);
  }

  return (uint8)numberOfBits;
} /* Xcp_CmdHlp_BitCounter */
#endif


#if( XCP_SEED_KEY == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdHlp_CheckResourceProtection()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_CmdHlp_CheckResourceProtection( Xcp_ChannelType XcpChannel, 
                                                                           uint8 Resource )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 retVal = XCP_CMD_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the resource protection state (Seed&Key) and return the result. */
  if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatus & (Resource)) != 0 )
  { 
    retVal = XCP_ERR_ACCESS_LOCKED;
  }
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  return retVal;
} /* Xcp_CmdHlp_CheckResourceProtection */
#endif


/**********************************************************************************************************************
 *  Xcp_CmdHlp_PrepareError()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdHlp_PrepareError( Xcp_ChannelType XcpChannel, uint8 ErrorCode )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare a default error response with the error codes as parameter. */
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_CMD] = XCP_PID_ERR;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_ERR] = ErrorCode;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_ERR_LEN;
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdHlp_PrepareError */


/**********************************************************************************************************************
 *  Xcp_CmdHlp_PrepareError()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CmdHlp_PrepareErrorOrPending( Xcp_ChannelType XcpChannel, uint8 ErrorCode )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 First check if the response shall be set to pending, otherwise prepare error response with error code as parameter. */
  if( ErrorCode != XCP_CMD_OK )
  {
    if( ErrorCode == XCP_CMD_PENDING )
    {
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponsePending = XCP_TRUE;
    }
    else
    {
      Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, ErrorCode );
    }
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdHlp_PrepareErrorOrPending */


/**********************************************************************************************************************
 *  Xcp_CmdHlp_ReadMta()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_CmdHlp_ReadMta( Xcp_ChannelType XcpChannel,
                                                           uint8 Size,
                                                           P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) Data )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If memory read access is valid: */
#if( XCP_READ_PROTECTION == STD_ON )
  retVal = XcpAppl_CheckReadAccess( XCP_CHANNEL_IDX,
                                    Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA,
                                    (uint32)Size );
  if ( retVal != (uint8)XCP_CMD_OK )
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA = Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA + Size;
  }
  else
#endif
  {
    /* #20 Then perform the read. Callout to XCP application, copying MTA to response message. */
    retVal = XcpAppl_MeasurementRead( Data, Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA, Size );

    /* #30 Move MTA to next value. */
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA = Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA + Size;
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return retVal;
} /* Xcp_CmdHlp_ReadMta */


/**********************************************************************************************************************
 *  Xcp_CmdHlp_SetMta()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CmdHlp_SetMta( Xcp_ChannelType XcpChannel,
                                                         Xcp_AddressPtrType Address,
                                                         uint8              AddressExtension )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the MTA and the address extension. */
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTAExtension = AddressExtension;

  Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA = XcpAppl_GetPointer( XCP_CHANNEL_IDX, AddressExtension, Address );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdHlp_SetMta */


#if( XCP_DAQ == STD_ON )
# if( XCP_STIM == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdHlp_AllocStimMemory()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(uint8, XCP_CODE) Xcp_CmdHlp_AllocStimMemory( Xcp_ChannelType XcpChannel )
{
  Xcp_OdtIdxType odt;
  Xcp_OdtIdxType n;
  uint16_least daq;
  uint8 retVal = XCP_CMD_OK;

  n = 0;
  /* #10 Iterate over all allocated DAQ lists: */
  for( daq = 0u; (daq < Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists) && (retVal == XCP_CMD_OK); daq++)
  {
    /* #20 Iterate over all ODTs of this DAQ list: */
    for( odt = Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.FirstOdt[daq];
        (odt < (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.FirstOdt[daq] + Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtsDaq[daq]))
           && (retVal == XCP_CMD_OK);
         odt++ )
    {
      /* #30 Check if STIM is enabled on this DAQ List? If so, allocate STIM buffer. */
      if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[daq] & XCP_DAQ_FLAG_DIRECTION) > 0u )
      {
        if (n >= (uint8)XCP_MAX_ODT_STIM)
        {
          retVal = XCP_CRC_MEMORY_OVERFLOW;
        }
        else
        {
          /* Invalidate this buffer */
          Xcp_StimBuffer[XCP_CHANNEL_IDX][n].buffer.b[0] = 0xFFu;
          Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.pStimBuffer[odt] = &Xcp_StimBuffer[XCP_CHANNEL_IDX][n];
          n++;
        }
      }
      else
      {
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.pStimBuffer[odt] = (tXcpDto*)NULL_PTR;
      }
    } /* ODT */
  } /* DAQ */

  XCP_DUMMY_STATEMENT(XcpChannel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return retVal;
} /* Xcp_CmdHlp_AllocStimMemory */
# endif /* ( XCP_STIM == STD_ON ) */
#endif /* ( XCP_DAQ == STD_ON ) */


#if( XCP_CALIBRATION == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdHlp_WriteMta()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_CmdHlp_WriteMta( Xcp_ChannelType XcpChannel, uint8 Size, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) Data )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Callout to XCP application, copying MTA to response message and move MTA to next value. */
  retVal = XcpAppl_CalibrationWrite( Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA, Data, Size );
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA = Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA + Size;

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return retVal;
} /* Xcp_CmdHlp_WriteMta */
#endif


/**********************************************************************************************************************
 *  Xcp_Cmd_ReservedCmd()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_Cmd_ReservedCmd( Xcp_ChannelType XcpChannel,
                                                    CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 If open command interface is enabled, call XcpAppl call-back, otherwise prepare default error message. */
#if( XCP_OPEN_COMMAND_IF == STD_ON )
  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX,
                                    XcpAppl_OpenCmdIf( XCP_CHANNEL_IDX,
                                                       &CmdPtr[0],
                                                       &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[0],
                                                       &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength )
                                  );
#else
  Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_CMD_UNKNOWN );
  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_Cmd_ReservedCmd */


/**********************************************************************************************************************
 *  Xcp_CmdStd_Connect()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_Connect( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */
  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* #10 If seed key is enabled, lock all resources with initial value. */
#if ( XCP_SEED_KEY == STD_ON )
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatus = Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatusInit;
#endif

  /* #20 Set connection state of this channel. */
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ConnectState = XCP_TRUE;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus |= XCP_SESSION_CONNECTED; /* ESCAN00099092 */

  /* #30 Prepare response message with communication parameters. */
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_CONNECT_RESOURCE] = 0x00
#if( XCP_CALIBRATION_PAGE == STD_ON )
    | (uint8)XCP_RM_CAL_PAG
#endif
#if( XCP_DAQ == STD_ON )
    | (uint8)XCP_RM_DAQ
#endif
#if( XCP_STIM == STD_ON )
    | (uint8)XCP_RM_STIM
#endif
#if( XCP_PROGRAM == STD_ON )
    | (uint8)XCP_RM_PGM
#endif
    ;

  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_CONNECT_COMM_BASIC] = 0x00
#if ( XCP_COMM_MODE_INFO == STD_ON )
    | (uint8)XCP_CMB_OPTIONAL
#endif
#if ( XCP_BLOCK_UPLOAD == STD_ON )
    | (uint8)XCP_CMB_SLAVE_BLOCK_MODE
#endif
    ;

  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_CONNECT_MAX_CTO_SIZE] = 
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].MaxCto;
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
  Xcp_PutVal16( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.w[XCP_CRM_CONNECT_MAX_DTO_SIZE >> 1u],
                Xcp_ChannelInfo[XCP_CHANNEL_IDX].MaxDto );
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_CONNECT_PROTOCOL_VERSION] =
    (uint8)(XCP_PROTOCOL_LAYER_VERSION >> 8);
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_CONNECT_TRANSPORT_VERSION] =
    (uint8)(XCP_TRANSPORT_LAYER_VERSION >> 8);
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_CONNECT_LEN;

  /* #40 Calculate Send Queue Entry size based on MaxDto parameter. */
#if( XCP_DAQ == STD_ON )
  Xcp_Hlp_CalcSendQueueEntrySizeAndLimit( XCP_CHANNEL_IDX );
#endif

  /* #50 Indicate connection state change to state CONNECTED. */
  XcpAppl_ConStateNotification( XCP_CHANNEL_IDX, XCP_CON_STATE_CONNECTED );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

} /* Xcp_CmdStd_Connect */


/**********************************************************************************************************************
 *  Xcp_CmdStd_Disconnect()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_Disconnect( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Disconnect this XCP channel. */
  Xcp_Disconnect( XCP_CHANNEL_IDX );

  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_Disconnect */


/**********************************************************************************************************************
 *  Xcp_CmdStd_GetStatus()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_GetStatus( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare response with GetStatus parameters. */
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_STATUS_STATUS] = (uint8)Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus;
#if ( XCP_SEED_KEY == STD_ON )
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_STATUS_PROTECTION] = (uint8)Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatus;
#else
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_STATUS_PROTECTION] = 0u;
#endif
#if ( XCP_DAQ == STD_ON )
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
  Xcp_PutVal16( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.w[XCP_CRM_GET_STATUS_CONFIG_ID >> 1u],
                Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionConfigId );
#else
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.w[XCP_CRM_GET_STATUS_CONFIG_ID >> 1u] = 0u;
#endif
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_STATUS_LEN;

  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_GetStatus */


#if( (XCP_DAQ_RESUME == STD_ON) || (XCP_PAGE_FREEZE == STD_ON) )
/**********************************************************************************************************************
 *  Xcp_CmdStd_SetRequest()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_SetRequest( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isInValidRange = FALSE;

  /* ----- Implementation ----------------------------------------------- */
# if( XCP_PAGE_FREEZE == STD_ON )
  /* #10 If the request to save calibration data into non-volatile memory was received: 
   *       Store the request to be processed in the MainFunction. */
  if( (CmdPtr[XCP_CRO_SET_REQUEST_MODE] & (uint8)(XCP_SESSION_STORE_CAL_REQ)) == (uint8)XCP_SESSION_STORE_CAL_REQ )
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus |= XCP_SESSION_STORE_CAL_REQ;
    isInValidRange = TRUE;
  }
# endif
# if( XCP_DAQ_RESUME == STD_ON )
  /* #20 If a request to save or clear DAQ data into non-volatile memory was received:
   *       Store the request to be processed in the MainFunction. */
  if( (CmdPtr[XCP_CRO_SET_REQUEST_MODE]               & 
        (uint8)((XCP_SESSION_STORE_DAQ_REQ_NO_RESUME) | 
                (XCP_SESSION_STORE_DAQ_REQ_RESUME)    |
                (XCP_SESSION_CLEAR_DAQ_REQ)))         >
      (uint8)0 )
  {
    isInValidRange = TRUE;

    if( (CmdPtr[XCP_CRO_SET_REQUEST_MODE] & (uint8)(XCP_SESSION_STORE_DAQ_REQ_NO_RESUME)) == (uint8)XCP_SESSION_STORE_DAQ_REQ_NO_RESUME )
    {
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus |= XCP_SESSION_STORE_DAQ_REQ_NO_RESUME;
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionConfigId = Xcp_GetVal16( &CmdPtr[XCP_CRO_SET_REQUEST_CONFIG_ID] );
    }
    if( (CmdPtr[XCP_CRO_SET_REQUEST_MODE] & (uint8)(XCP_SESSION_STORE_DAQ_REQ_RESUME)) == (uint8)XCP_SESSION_STORE_DAQ_REQ_RESUME )
    {
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus |= XCP_SESSION_STORE_DAQ_REQ_RESUME;
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionConfigId = Xcp_GetVal16( &CmdPtr[XCP_CRO_SET_REQUEST_CONFIG_ID] );
    }
    if( (CmdPtr[XCP_CRO_SET_REQUEST_MODE] & (uint8)(XCP_SESSION_CLEAR_DAQ_REQ)) == (uint8)XCP_SESSION_CLEAR_DAQ_REQ )
    {
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus |= XCP_SESSION_CLEAR_DAQ_REQ;
    }
  }
# endif
  /* #30 If the request mode is invalid, report an out of range error. */
  if( isInValidRange == FALSE )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_CMD_OUT_OF_RANGE );
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_SetRequest */
#endif /* ( (XCP_DAQ_RESUME == STD_ON) || (XCP_PAGE_FREEZE == STD_ON) ) */


/**********************************************************************************************************************
 *  Xcp_CmdStd_Synch()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_Synch( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set error code for synch command to response message. */
  Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_CMD_SYNCH );

  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_Synch */


/**********************************************************************************************************************
 *  Xcp_CmdStd_GetCommModeInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_GetCommModeInfo( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare response for GetCommModeInfo parameters. */
#if( XCP_BLOCK_DOWNLOAD == STD_ON )
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_COMM_MODE_INFO_COMM_OPTIONAL] = XCP_CMO_MASTER_BLOCK_MODE;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_COMM_MODE_INFO_MAX_BS] = XCP_MAX_DOWNLOAD_BLOCK_SIZE(XCP_CHANNEL_IDX);
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_COMM_MODE_INFO_MIN_ST] = XCP_BLOCK_DOWNLOAD_MIN_ST;
#else
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_COMM_MODE_INFO_COMM_OPTIONAL] = 0u;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_COMM_MODE_INFO_MAX_BS] = 0u;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_COMM_MODE_INFO_MIN_ST] = 0u;
#endif
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_COMM_MODE_INFO_QUEUE_SIZE] = 0u;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_COMM_MODE_INFO_DRIVER_VERSION] = 
    ((XCP_SW_MAJOR_VERSION & 0x0F) << 4u) | (XCP_SW_MINOR_VERSION & 0x0F);
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_COMM_MODE_INFO_LEN;

  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_GetCommModeInfo */


#if( XCP_SEED_KEY == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdStd_GetSeed()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_GetSeed( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorCode = XCP_CMD_OK;
  uint8 mode;
  uint8 resource;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get command string parameters. */
  mode     = CmdPtr[XCP_CRO_GET_SEED_MODE];
  resource = CmdPtr[XCP_CRO_GET_SEED_RESOURCE];

  /* #20 Check whether the requested seed fits in a single CTO (remaining parts of seeds are not supported so far). */
  if( mode != 0x00u )
  {
    errorCode = XCP_ERR_OUT_OF_RANGE;
  }
  /* #30 Check that only one resource is requested. */
  else if( Xcp_CmdHlp_BitCounter((uint32)resource) > 1 )
  {
    errorCode = XCP_ERR_OUT_OF_RANGE;
  }
  /* #40 Check if at least one valid resource is requested. */
  else if( ((resource & XCP_RM_ALL_RESOURCES) == 0) 
        && (resource > 0) )
  {
    errorCode = XCP_ERR_OUT_OF_RANGE;
  }
  /* #50 If all checks passed:
   *       And the resource is not locked: */
  else
  {
    if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatus & resource) != 0u )
    {
      uint8 seedLength;

      /* #60 Get the seed and check if the seed length is smaller equal than MAX_CTO-2. 
       *     Otherwise, prepare a negative response. */
      seedLength = XcpAppl_GetSeed(resource, &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_SEED_DATA]);
      if( seedLength > (uint8)(Xcp_ChannelInfo[XCP_CHANNEL_IDX].MaxCto - XCP_CRM_GET_SEED_LEN) )
      {
        errorCode = XCP_ERR_OUT_OF_RANGE;
      }
      else
      {
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_SEED_LEN + seedLength;
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_SEED_LENGTH] = seedLength;
      }
    }
    /* #70 Otherwise, return 0 as length, since the resource is unprotected. */
    else
    {      
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_SEED_LENGTH] = 0u;
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_SEED_LEN;
    }
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_CmdStd_GetSeed */


/**********************************************************************************************************************
 *  Xcp_CmdStd_Unlock()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_Unlock( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorCode = XCP_CMD_OK;
  uint8 keyLength;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get command string parameters. */
  keyLength = CmdPtr[XCP_CRO_UNLOCK_LENGTH];

  /* #20 Check whether the requested key fits in a single CTO (remaining parts of keys are not supported so far). */
  if( keyLength > XCP_CRO_UNLOCK_MAX_KEY_SIZE(XCP_CHANNEL_IDX) )
  {
    errorCode = XCP_CRC_SEQUENCE;
  }
  /* #30 Otherwise, check if the key fits to the seed. */
  else
  {
    uint8 resource;

    /* #40 If the key is invalid prepare negative response and go to disconnected state.
     *     Otherwise, unlock the resource and return the appropriate resource protection mask bit. */
    resource = XcpAppl_Unlock( &CmdPtr[XCP_CRO_UNLOCK_KEY], keyLength );
    if ( resource == (uint8)0x00u )
    {
      Xcp_CmdStd_Disconnect( XCP_CHANNEL_IDX, CmdPtr );
      errorCode = XCP_ERR_ACCESS_LOCKED;
    }
    else
    {
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatus &= (uint8)~resource;

      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_UNLOCK_PROTECTION] = Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatus;
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_UNLOCK_LEN;
    }
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_Unlock */
#endif /* ( XCP_SEED_KEY == STD_ON ) */


/**********************************************************************************************************************
 *  Xcp_CmdStd_SetMta()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_SetMta( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the global MTA (Memory Transfer Address) to the value passed in the CMD string. Perform pointer conversion first. */
  Xcp_CmdHlp_SetMta( XCP_CHANNEL_IDX, (Xcp_AddressPtrType)Xcp_GetVal32(&CmdPtr[XCP_CRO_SET_MTA_ADDR]), CmdPtr[XCP_CRO_SET_MTA_EXT] );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_SetMta */


/**********************************************************************************************************************
 *  Xcp_CmdStd_GetId()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_GetId( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Get command string parameters. */
  uint8 getIdType = CmdPtr[XCP_CRO_GET_ID_TYPE];

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Prepare response frame:
   *         * Mode = 0 = Transfer Mode: UPLOAD commands recommended to get data.
   *         * Length field = 0 = In this response no data is transmitted.*/
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_ID_LEN;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_ID_MODE] = 0;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.l[XCP_CRM_GET_ID_LENGTH >> 2] = 0;

#if( kXcpStationIdLength > 0 )
  /* #30 Either prepare response based on station ID if configured. */
  if ( getIdType == XCP_IDT_ASAM_NAME ) /* Type = ASAM MC2 */
  {
    /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
    /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
    Xcp_PutVal32( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.l[XCP_CRM_GET_ID_LENGTH >> 2], (uint32)kXcpStationIdLength );
    /* PRQA S 0306 3 */ /* MD_Xcp_0306 */
    Xcp_CmdHlp_SetMta( XCP_CHANNEL_IDX, 
                       (Xcp_AddressPtrType)(&kXcpStationId[0]),
                       0x00 );
  }
  else
#endif
  {
#if( XCP_GET_ID_GENERIC == STD_ON )
    /* #40 Or prepare response based on XcpAppl call-back (Generic Get ID). */
    P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR) pData;
    /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
    /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
    Xcp_PutVal32( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.l[XCP_CRM_GET_ID_LENGTH >> 2],
                  (uint32)XcpAppl_GetIdData(&pData, getIdType) );
    
    if( Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.l[XCP_CRM_GET_ID_LENGTH >> 2] > 0u )
    {
      Xcp_CmdHlp_SetMta( XCP_CHANNEL_IDX, (Xcp_AddressPtrType)pData, 0x00 ); /* PRQA S 0306 */ /* MD_Xcp_0306 */
    }
#endif
  }

  XCP_DUMMY_STATEMENT( getIdType ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_GetId */


/**********************************************************************************************************************
 *  Xcp_CmdStd_Upload()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_Upload( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Get command string parameters. */
  uint8 size = CmdPtr[XCP_CRO_UPLOAD_SIZE];
  uint8 errorCode;

  /* ----- Implementation ----------------------------------------------- */
  if( size == 0u )
  {
    errorCode = XCP_CMD_OUT_OF_RANGE;
  }
  else
#if( XCP_BLOCK_UPLOAD == STD_ON )
  /* #20 If the number of requested bytes to be uploaded exceeds max CTO-1: 
   *       Store missing number of bytes to be uploaded and copy maximum valid number of bytes from MTA. */
  if( size > XCP_CRM_UPLOAD_MAX_SIZE(XCP_CHANNEL_IDX) )
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize = size - XCP_CRM_UPLOAD_MAX_SIZE(XCP_CHANNEL_IDX);
    size = XCP_CRM_UPLOAD_MAX_SIZE(XCP_CHANNEL_IDX);

    errorCode = Xcp_CmdHlp_ReadMta( XCP_CHANNEL_IDX, size, &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_UPLOAD_DATA] );
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = (XCP_CRM_UPLOAD_LEN + XCP_CRM_UPLOAD_MAX_SIZE(XCP_CHANNEL_IDX));

    if( (errorCode == XCP_CMD_OK) 
     || (errorCode == XCP_CMD_PENDING) )
    {
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus |= (uint16)XCP_SESSION_BLOCK_UPLOAD;
    }
  }
  /* #30 Otherwise, if requested number of bytes to be copied is invalid: 
   *       Respond error XCP_CMD_OUT_OF_RANGE. */
  else
#else
  if( size > XCP_CRM_UPLOAD_MAX_SIZE(XCP_CHANNEL_IDX) )
  {
    errorCode = XCP_CMD_OUT_OF_RANGE;
  }
  else
#endif
  /* #40 Otherwise, copy requested data. */
  {
    errorCode = Xcp_CmdHlp_ReadMta( XCP_CHANNEL_IDX, size, &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_UPLOAD_DATA] );
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = (uint8)(XCP_CRM_UPLOAD_LEN + size);
  }
  
  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_Upload */


/**********************************************************************************************************************
 *  Xcp_CmdStd_ShortUpload()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_ShortUpload( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Xcp_AddressPtrType address;
  uint8              addrExt;
  uint8              size;
  uint8              errorCode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get command string parameters. */
  size = CmdPtr[XCP_CRO_SHORT_UPLOAD_SIZE];
  addrExt = CmdPtr[XCP_CRO_SHORT_UPLOAD_EXT];
  address = (Xcp_AddressPtrType)Xcp_GetVal32(&CmdPtr[XCP_CRO_SHORT_UPLOAD_ADDR]);

  /* #20 If the number of requested bytes to be uploaded exceeds max CTO-1:
   *       Respond error XCP_CMD_OUT_OF_RANGE. */
  if( (size == 0u) || (size > XCP_CRM_SHORT_UPLOAD_MAX_SIZE(XCP_CHANNEL_IDX)) )
  {
    errorCode = XCP_CMD_OUT_OF_RANGE;
  }
  /* #30 Otherwise, set MTA as specified in received command frame and copy requested data from MTA to response frame. */
  else
  {
    Xcp_CmdHlp_SetMta( XCP_CHANNEL_IDX, address, addrExt );

    errorCode = Xcp_CmdHlp_ReadMta( XCP_CHANNEL_IDX, size, &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_SHORT_UPLOAD_DATA] );
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = (uint8)(XCP_CRM_SHORT_UPLOAD_LEN + size);
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_ShortUpload */


#if( XCP_CHECKSUM == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdStd_BuildChecksum()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_BuildChecksum( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 checksumSize = Xcp_GetVal32(&CmdPtr[XCP_CRO_BUILD_CHECKSUM_SIZE]);
# if( XCP_CUSTOM_CRC == STD_ON )
  uint8  errorCode = XCP_CMD_OK;
# endif

  /* ----- Implementation ----------------------------------------------- */
# if( XCP_CUSTOM_CRC == STD_OFF )
#  if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16CITT ) || \
      ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC32 )
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSum = (tXcpChecksumType)(0xFFFFFFFFu & tXcpChecksumTypeMask);
#  else
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSum = (tXcpChecksumType)(0x00000000u);
#  endif
  /* #10 If the Checksum size is greater than 0xffff. */
  if( (checksumSize & (uint32)0xffff0000U) > 0 )
  {
    /* #20 Respond error frame indicating OUT_OF_RANGE and containing the maximal Checksum size. */
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
    
    /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
    /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
    Xcp_PutVal32( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.l[XCP_CRM_BUILD_CHECKSUM_RESULT >> 2u],
                  (uint32)0x0000ffff ); /* Maximum valid block size. */
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = (uint8)XCP_CRM_BUILD_CHECKSUM_LEN;
  }
  else
# endif
  {
# if( (kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD22) || \
      (kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD24) || \
      (kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD44) )
    if( (checksumSize % (uint32)sizeof(tXcpChecksumAddType)) != (uint32)0u )
    {
      Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
    }
    else
# endif
    {
      /* #30 Check memory read access. */
# if( XCP_READ_PROTECTION == STD_ON )
      if( (uint8)XCP_ERR_ACCESS_DENIED
       ==  XcpAppl_CheckReadAccess( XCP_CHANNEL_IDX, 
                                    Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA,
                                    checksumSize ) 
        )
      {
        /* #40 Move MTA to next value. */
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA = Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA + checksumSize;

        /* #50 Set first bytes of response: byte 0 to 0xfe, byte 1 to XCP_ERR_ACCESS_DENIED. */
        Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_ACCESS_DENIED );
        /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
        /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
        Xcp_PutVal32( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.l[XCP_CRM_BUILD_CHECKSUM_RESULT >> 2u],
                      (uint32)0x0000ffff ); /* Maximum valid block size. */
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = (uint8)XCP_CRM_BUILD_CHECKSUM_LEN;
      }
      else
# endif
      {
# if( XCP_CUSTOM_CRC == STD_ON )
        /* PRQA S 0306 3 */ /* MD_Xcp_0306 */
        errorCode = XcpAppl_CalculateChecksum( (P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR))Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA,
                                               (P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR))&Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[0],
                                               checksumSize );
        /* #60 Move MTA to next value. */
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA = Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA + checksumSize;
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = (uint8)XCP_CRM_BUILD_CHECKSUM_LEN;
# else
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].CheckSumSize = (uint16)checksumSize;
        /* #70 Avoid Response. Will be send in Xcp_MainFunction. */
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = (uint8)0;
# endif
      }
    }
  }

# if( XCP_CUSTOM_CRC == STD_ON )
  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );
# endif
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_BuildChecksum */
#endif /* ( XCP_CHECKSUM == STD_ON ) */


/**********************************************************************************************************************
 *  Xcp_CmdStd_TlCmd()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_TlCmd( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorCode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward transport layer command to transport layer and perform follow up evaluation of error code. */
  errorCode = Xcp_CallTlFunction_2_Param( XCP_CHANNEL_IDX, XcpTl_TlService, &CmdPtr[0] );

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_TlCmd */


#if( XCP_USER_COMMAND == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdStd_UserCmd()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdStd_UserCmd( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward user command to XcpAppl call-back and perform follow up evaluation of error code. */
  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, XcpAppl_UserService( XCP_CHANNEL_IDX, CmdPtr ) );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdStd_UserCmd */
#endif


#if( XCP_CALIBRATION == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdCal_Download()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdCal_Download( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 size = CmdPtr[XCP_CRO_DOWNLOAD_SIZE];
  uint8 errorCode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Perform initial check of download size, resource protection. */
# if( XCP_BLOCK_DOWNLOAD == STD_ON )
  if( (size == 0u) || (size > XCP_MAX_DOWNLOAD_BYTES) )
# else
  if( (size == 0u) || (size > XCP_CRO_DOWNLOAD_MAX_SIZE(XCP_CHANNEL_IDX)) )
# endif
  {
    errorCode = XCP_CMD_OUT_OF_RANGE;
  }
  else
# if( XCP_SEED_KEY == STD_ON )
  if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_CAL_PAG ) != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_LOCKED;
  }
  else
# endif
  {
# if( XCP_BLOCK_DOWNLOAD == STD_ON )
    if( size > XCP_CRO_DOWNLOAD_MAX_SIZE(XCP_CHANNEL_IDX) )
    {
      /* #20 Perform transfer to memory for block mode case. */
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize = size - XCP_CRO_DOWNLOAD_MAX_SIZE(XCP_CHANNEL_IDX);
      size = XCP_CRO_DOWNLOAD_MAX_SIZE(XCP_CHANNEL_IDX);
      errorCode = Xcp_CmdHlp_WriteMta(XCP_CHANNEL_IDX, size, &CmdPtr[XCP_CRO_DOWNLOAD_DATA]);

      /* #30 Do not send a response now, we are in block mode. */
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = 0;
    }
    else
# endif
    { /* #40 Perform transfer to memory for non block mode case. */
      errorCode = Xcp_CmdHlp_WriteMta(XCP_CHANNEL_IDX, size, &CmdPtr[XCP_CRO_DOWNLOAD_DATA]);
    }
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdCal_Download */


# if( XCP_BLOCK_DOWNLOAD == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdCal_DownloadNext()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdCal_DownloadNext( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 size = CmdPtr[XCP_CRO_DOWNLOAD_NEXT_SIZE];
  uint8 errorCode = XCP_CMD_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If more than allowed bytes are requested to be downloaded: 
   *       Reject the complete download request and respond with error XCP_CMD_OUT_OF_RANGE. */
  if( size > (XCP_MAX_DOWNLOAD_BYTES - XCP_CRO_DOWNLOAD_NEXT_MAX_SIZE(XCP_CHANNEL_IDX)) )
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize = 0;
    
    errorCode = (uint8)XCP_CMD_OUT_OF_RANGE;
  }
  /* #20 Otherwise, if the requested number of bytes does not match the expected number: 
   *       The current request is rejected and an error XCP_ERR_SEQUENCE with the correct number of missing bytes is
   *       responded. */
  else if( size != Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize )
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_CMD] = XCP_PID_ERR;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_ERR] = XCP_ERR_SEQUENCE;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_DOWNLOAD_NEXT_DATA_BLOCK_SIZE] = Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_DOWNLOAD_NEXT_ERR_RESPONSE_LENGTH;
  }
  /* #30 Otherwise, if the requested number of bytes fit in this request: 
   *       Write the last bytes to MTA. This block download is successfully finished. */
  else if( size <= XCP_CRO_DOWNLOAD_NEXT_MAX_SIZE(XCP_CHANNEL_IDX) )
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize = 0;

    errorCode = Xcp_CmdHlp_WriteMta(XCP_CHANNEL_IDX, size, &CmdPtr[XCP_CRO_DOWNLOAD_NEXT_DATA]);
  }
  /* #40 Otherwise, there are more outstanding byte to receive, so copy the currently received bytes to MTA but
   *       do not send a response now. */
  else
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize = size - XCP_CRO_DOWNLOAD_MAX_SIZE(XCP_CHANNEL_IDX);
    size = XCP_CRO_DOWNLOAD_MAX_SIZE(XCP_CHANNEL_IDX);
    errorCode = Xcp_CmdHlp_WriteMta(XCP_CHANNEL_IDX, size, &CmdPtr[XCP_CRO_DOWNLOAD_DATA]);

    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = 0;
  }
  
  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdCal_DownloadNext */
# endif /* ( XCP_BLOCK_DOWNLOAD == STD_ON ) */


# if( XCP_BLOCK_DOWNLOAD == STD_OFF )
/**********************************************************************************************************************
 *  Xcp_CmdCal_DownloadMax()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdCal_DownloadMax( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorCode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check resource protection, if granted perform transfer of data to memory. */
#   if( XCP_SEED_KEY == STD_ON )
  if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_CAL_PAG ) != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_LOCKED;
  }
  else
#   endif
  {
    errorCode = Xcp_CmdHlp_WriteMta( XCP_CHANNEL_IDX, 
                                     (XCP_CRO_DOWNLOAD_MAX_MAX_SIZE(XCP_CHANNEL_IDX)), 
                                     &CmdPtr[XCP_CRO_DOWNLOAD_MAX_DATA] );
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdCal_DownloadMax */
# endif


# if( XCP_SHORT_DOWNLOAD == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdCal_ShortDownload()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdCal_ShortDownload( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Xcp_AddressPtrType address;
  uint8              addrExt;
  uint8              size;
  uint8              errorCode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  address = (Xcp_AddressPtrType)Xcp_GetVal32(&CmdPtr[XCP_CRO_SHORT_DOWNLOAD_ADDR]);
  size = (CmdPtr[XCP_CRO_SHORT_DOWNLOAD_SIZE]);
  addrExt = CmdPtr[XCP_CRO_SHORT_DOWNLOAD_EXT];

  /* #20 Perform initial check of download size, resource protection. */
  if( (size == 0u) || (size > XCP_CRM_SHORT_DOWNLOAD_MAX_SIZE(XCP_CHANNEL_IDX)) )
  {
    errorCode = XCP_CMD_OUT_OF_RANGE;
  }
#  if( XCP_SEED_KEY == STD_ON )
  else if( Xcp_CmdHlp_CheckResourceProtection(XCP_CHANNEL_IDX, XCP_RM_CAL_PAG) != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_LOCKED;
  }
#  endif
  /* #30 If checks passed, set MTA and copy data. MTA is incremented in WriteMta call. */
  else
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTAExtension = addrExt;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA = XcpAppl_GetPointer( XCP_CHANNEL_IDX, addrExt, address );
    errorCode = Xcp_CmdHlp_WriteMta(XCP_CHANNEL_IDX, size, &CmdPtr[XCP_CRO_SHORT_DOWNLOAD_DATA]);
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdCal_ShortDownload */
# endif /* ( XCP_SHORT_DOWNLOAD == STD_ON ) */


# if( XCP_MODIFY_BITS == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdCal_ModifyBits()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdCal_ModifyBits( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Xcp_AddressPtrType mtaLocation;
  uint32             calc;
  uint16             maskAnd;
  uint16             maskXor;
  uint8              shiftValue;
  uint8              errorCode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  shiftValue = CmdPtr[XCP_CRO_MODIFY_BITS_SHIFT];

  /* #20 Perform initial check of resource protection, shift limit. */
#  if( XCP_SEED_KEY == STD_ON )
  if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_CAL_PAG ) != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_LOCKED;
  }
  else
#  endif
  if( shiftValue <= XCP_UPPER_LIMIT_LEFT_SHIFT )
  {
    /* #30 Get more parameters from command string. */
    maskAnd = Xcp_GetVal16(&CmdPtr[XCP_CRO_MODIFY_BITS_AND]);
    maskXor = Xcp_GetVal16(&CmdPtr[XCP_CRO_MODIFY_BITS_XOR]);

    /* #40 And perform modification of bits by ReadMta, modification, WriteMta operation. MTA is not incremented. */
    mtaLocation = Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA;
    errorCode = Xcp_CmdHlp_ReadMta( XCP_CHANNEL_IDX, 4, (P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR))&calc ); /* PRQA S 0310 */ /* MD_Xcp_0310 */
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA = mtaLocation;

    if( errorCode == XCP_CMD_OK )
    {
      calc = (uint32)( (calc & (~((uint32)(((uint16)~maskAnd) << shiftValue)))) ^ ((uint32)(maskXor << shiftValue)) );

      errorCode = Xcp_CmdHlp_WriteMta( XCP_CHANNEL_IDX, 4, (P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR))&calc ); /* PRQA S 0310 */ /* MD_Xcp_0310 */
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA = mtaLocation;
    }
    else
    {
      /* If Xcp_CmdHlp_ReadMta indicated response pending, the bit modification failed. */
      if( errorCode == XCP_CMD_PENDING )
      {
        errorCode = XCP_ERR_ACCESS_DENIED;
      }
    }
  }
  else
  {
    errorCode = XCP_CMD_OUT_OF_RANGE;
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdCal_ModifyBits */
# endif /* ( XCP_MODIFY_BITS == STD_ON ) */
#endif /* ( XCP_CALIBRATION == STD_ON ) */


#if( XCP_CALIBRATION_PAGE == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdPag_SetCalPage()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPag_SetCalPage( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Get parameters from command string. */
  uint8 calMode = CmdPtr[XCP_CRO_SET_CAL_PAGE_MODE];
  uint8 calSegNumber = CmdPtr[XCP_CRO_SET_CAL_PAGE_SEGMENT];
  uint8 calPageNumber = CmdPtr[XCP_CRO_SET_CAL_PAGE_PAGE];

  /* ----- Implementation ----------------------------------------------- */
  /* #20 And forward call to XcpAppl call-back to set page, follow up error handling. */
  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, 
                                    XcpAppl_SetCalPage( calSegNumber,
                                                        calPageNumber,
                                                        calMode ) 
                                  );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPag_SetCalPage */


/**********************************************************************************************************************
 *  Xcp_CmdPag_GetCalPage()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPag_GetCalPage( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Get parameters from command string. */
  uint8 calMode = CmdPtr[XCP_CRO_GET_CAL_PAGE_MODE];
  uint8 calSegNumber = CmdPtr[XCP_CRO_GET_CAL_PAGE_SEGMENT];

  /* ----- Implementation ----------------------------------------------- */
  /* #20 If a valid calibration page mode is specified:
   *       Forward the call to XcpAppl call-back to get the calibration page. */
  if( (calMode == 1) || (calMode == 2) )
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_CAL_PAGE_PAGE] = XcpAppl_GetCalPage( calSegNumber, calMode );

    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_CAL_PAGE_LEN;
  }
  /* #30 Otherwise, prepare error XCP_ERR_PAGE_MODE_NOT_VALID. */
  else
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_PAGE_MODE_NOT_VALID );
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPag_GetCalPage */
#endif /* ( XCP_CALIBRATION_PAGE == STD_ON ) */


#if( XCP_PAGE_INFO == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdPag_GetPageProcessorInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPag_GetPageProcessorInfo( Xcp_ChannelType XcpChannel,
                                                                CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare response for GetPageProcessorInfo. */
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_PAG_PROCESSOR_INFO_MAX_SEGMENT] = (uint8)XCP_MAX_SEGMENT;
# if( XCP_PAGE_FREEZE == STD_ON )
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_PAG_PROCESSOR_INFO_PROPERTIES] = 0x01;
# else  
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_PAG_PROCESSOR_INFO_PROPERTIES] = 0x00;
# endif
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_PAG_PROCESSOR_INFO_LEN;

  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPag_GetPageProcessorInfo */
#endif /* ( XCP_PAGE_INFO == STD_ON ) */


#if( XCP_PAGE_FREEZE == STD_ON )
/**********************************************************************************************************************
 *  Xcp_GetSegmentInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPag_GetSegmentMode( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Get parameters from command string. */
  uint8 segment = CmdPtr[XCP_CRO_GET_SEGMENT_MODE_SEGMENT];

  /* ----- Implementation ----------------------------------------------- */
  /* #20 If segment is in range, call XcpAppl call-back to get the current Freeze Mode. */
  if( segment < (uint8)XCP_MAX_SEGMENT )
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_SEGMENT_MODE_MODE] = (uint8)XcpAppl_GetFreezeMode( segment );
  
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_SEGMENT_MODE_LEN;
  }
  /* #30 Otherwise, prepare error XCP_ERR_OUT_OF_RANGE. */
  else
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_GetSegmentInfo */


/**********************************************************************************************************************
 *  Xcp_CmdPag_SetSegmentMode()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPag_SetSegmentMode( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Get parameters from command string. */
  uint8 mode = CmdPtr[XCP_CRO_SET_SEGMENT_MODE_MODE];
  uint8 segment = CmdPtr[XCP_CRO_SET_SEGMENT_MODE_SEGMENT];

  /* ----- Implementation ----------------------------------------------- */
  /* #20 If segment is in range, call XcpAppl call-back to set the current Freeze Mode. */
  if( segment < XCP_MAX_SEGMENT )
  {
    XcpAppl_SetFreezeMode( segment, mode );
  }
  /* #30 Otherwise, prepare error XCP_ERR_OUT_OF_RANGE. */
  else
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPag_SetSegmentMode */
#endif /* ( XCP_PAGE_FREEZE == STD_ON ) */


#if( XCP_COPY_CAL_PAGE == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdPag_CopyCalPage()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPag_CopyCalPage( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Get parameters from command string. */
  uint8 srcSeg   = CmdPtr[CRO_COPY_CAL_PAGE_SRC_SEGMENT];
  uint8 srcPage  = CmdPtr[CRO_COPY_CAL_PAGE_SRC_PAGE];
  uint8 destSeg  = CmdPtr[CRO_COPY_CAL_PAGE_DEST_SEGMENT];
  uint8 destPage = CmdPtr[CRO_COPY_CAL_PAGE_DEST_PAGE];
  uint8 errorCode;

  /* ----- Implementation ----------------------------------------------- */
  /* #20 If segments and pages are in range, call XcpAppl call-back to copy the page. */
  if( (srcSeg < XCP_MAX_SEGMENT) && 
      (srcPage < XCP_MAX_PAGES) && 
      (destSeg < XCP_MAX_SEGMENT) && 
      (destPage < XCP_MAX_PAGES) 
    )
  {
    errorCode = XcpAppl_CopyCalPage(srcSeg, srcPage, destSeg, destPage);
  }
  /* #30 Otherwise, prepare error XCP_ERR_OUT_OF_RANGE. */
  else
  {
    errorCode = (uint8)XCP_ERR_OUT_OF_RANGE;
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPag_CopyCalPage */
#endif /* ( XCP_COPY_CAL_PAGE == STD_ON ) */


#if( XCP_DAQ == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdDaq_SetDaqPtr()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_SetDaqPtr( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 daqNumber;
  uint8  odtNumber;
  uint8  odtEntryNumber;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  daqNumber = Xcp_GetVal16( &CmdPtr[XCP_CRO_SET_DAQ_PTR_DAQ] );
  odtNumber = CmdPtr[XCP_CRO_SET_DAQ_PTR_ODT];
  odtEntryNumber = CmdPtr[XCP_CRO_SET_DAQ_PTR_IDX];

  /* #20 Check for valid parameter range, and if so set the DAQ list pointer accordingly. */
  if( daqNumber >= Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
  }
  else if( odtNumber >= Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtsDaq[daqNumber] )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
  }
  else if( odtEntryNumber >= Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtEntriesOdt[odtNumber] )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
  }
  else
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.odtEntryIdx = 
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.FirstOdtEntry[Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.FirstOdt[daqNumber] + odtNumber] + odtEntryNumber;
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdDaq_SetDaqPtr */


/**********************************************************************************************************************
 *  Xcp_CmdDaq_WriteDaq()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_WriteDaq( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Xcp_AddressPtrType completeAddress;
  uint32 address;
  uint8 elSize;
  uint8 addrExt;
  uint8 bitOfs;
  uint8 errorCode = XCP_CMD_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  bitOfs  = CmdPtr[XCP_CRO_WRITE_DAQ_BITOFFSET];
  elSize  = CmdPtr[XCP_CRO_WRITE_DAQ_SIZE];
  addrExt = CmdPtr[XCP_CRO_WRITE_DAQ_EXT];
  address = Xcp_GetVal32( &CmdPtr[XCP_CRO_WRITE_DAQ_ADDR] );
  completeAddress = XcpAppl_GetPointer( XCP_CHANNEL_IDX, addrExt, address );

  /* #20 Report an error if
   *   * the resource is locked,
   *   * memory read access is rejected,
   *   * the DAQ list is empty,
   *   * a bit offset is used,
   *   * value size is in invalid range or 
   *   * there are too many ODT entries. */
# if( XCP_SEED_KEY == STD_ON )
  if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_DAQ ) != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_LOCKED;
  }
  else
# endif
# if( XCP_READ_PROTECTION == STD_ON )
  if( (uint8)XCP_ERR_ACCESS_DENIED ==  XcpAppl_CheckReadAccess( XCP_CHANNEL_IDX, completeAddress, elSize ) )
  {
    errorCode = XCP_ERR_ACCESS_DENIED;
  }
  else
# endif
  if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists == 0u)
   || (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdts == 0u)
   || (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtEntries == 0u) )
  {
    errorCode = XCP_ERR_DAQ_CONFIG;
  }
  else
  if( bitOfs != 0xFF )
  {
    errorCode = XCP_ERR_OUT_OF_RANGE;
  }
  else
  if( (elSize == 0u) || (elSize > XCP_MAX_ODT_ENTRY_SIZE(XCP_CHANNEL_IDX)) )
  {
    errorCode = XCP_ERR_OUT_OF_RANGE;
  }
  else
  if( Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.odtEntryIdx >= XCP_MAX_ODT_ENTRIES )
  {
    errorCode = XCP_ERR_DAQ_CONFIG;
  }
  /* #30 If all parameters are valid, add a new ODT entry. */
  else
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.OdtEntries[Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.odtEntryIdx] = completeAddress;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.OdtEntriesSize[Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.odtEntryIdx] = elSize;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.odtEntryIdx++;
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_CmdDaq_WriteDaq */


# if( XCP_WRITE_DAQ_MULTIPLE == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdDaq_WriteDaqMultiple()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_WriteDaqMultiple( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Xcp_AddressPtrType completeAddress;
  uint32      address;
  uint8_least daqIdx;
  uint8       addrExt;
  uint8       elSize;
  uint8       bitOfs;
  uint8       errorCode = XCP_CMD_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Report an error if:
   *   * the resource is locked,
   *   * the DAQ list is empty,
   *   * for each ODT write request:
   *     * value size is in invalid range,
   *     * a bit offset is used,
   *     * value size is in invalid range or 
   *     * memory read access is rejected. */
#  if( XCP_SEED_KEY == STD_ON )
  if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_DAQ ) != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_LOCKED;
  }
  else
#  endif
  if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists   == 0u) ||
      (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdts       == 0u) ||
      (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtEntries == 0u) 
    )
  {
    errorCode = XCP_ERR_DAQ_CONFIG;
  }
  else
  {
    for( daqIdx = 0; (daqIdx < CmdPtr[XCP_CRO_WRITE_DAQ_MULTIPLE_NODAQ]) && (errorCode == XCP_CMD_OK); daqIdx++ )
    {
      /* #20 Get parameters from command string. */
      address = Xcp_GetVal32(&CmdPtr[XCP_CRO_WRITE_DAQ_MULTIPLE_ADDR(daqIdx)]);
      addrExt = CmdPtr[XCP_CRO_WRITE_DAQ_MULTIPLE_EXT(daqIdx)];
      elSize = CmdPtr[XCP_CRO_WRITE_DAQ_MULTIPLE_SIZE(daqIdx)];
      bitOfs = CmdPtr[XCP_CRO_WRITE_DAQ_MULTIPLE_BITOFFSET(daqIdx)];
      completeAddress = XcpAppl_GetPointer( XCP_CHANNEL_IDX, addrExt, address );

      if( (elSize == 0u) || (elSize >= XCP_MAX_ODT_ENTRY_SIZE(XCP_CHANNEL_IDX)) )
      {
        errorCode = XCP_ERR_OUT_OF_RANGE;
      }
      else
      if( bitOfs != 0xFF )
      {
        errorCode = XCP_ERR_OUT_OF_RANGE;
      }
      else
      if( Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.odtEntryIdx >= XCP_MAX_ODT_ENTRIES )
      {
        errorCode = XCP_ERR_DAQ_CONFIG;
      }
      else
# if( XCP_READ_PROTECTION == STD_ON )
      if( (uint8)XCP_ERR_ACCESS_DENIED ==  XcpAppl_CheckReadAccess( XCP_CHANNEL_IDX, completeAddress, elSize ) )
      {
        errorCode = XCP_ERR_ACCESS_DENIED;
      }
      else
# endif
      {
        /* #30 If all checks passed, store the new entry and increment entry index. */
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.OdtEntries[Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.odtEntryIdx] = completeAddress;
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.OdtEntriesSize[Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.odtEntryIdx] = elSize;
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.odtEntryIdx++;
      }
    }
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_CmdDaq_WriteDaqMultiple */
# endif /* XCP_WRITE_DAQ_MULTIPLE == STD_ON */


/**********************************************************************************************************************
 *  Xcp_CmdDaq_SetDaqListMode()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_SetDaqListMode( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 daqNumber;
  uint16 eventNumber;
  uint8  prescaler;
#if( XCP_STIM == STD_ON )
  uint8  errorCode;
#else
  uint8  errorCode = XCP_CMD_OK;
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  daqNumber = Xcp_GetVal16(&CmdPtr[XCP_CRO_SET_DAQ_LIST_MODE_DAQ]);
  eventNumber = Xcp_GetVal16(&CmdPtr[XCP_CRO_SET_DAQ_LIST_MODE_EVENTCHANNEL]);
  prescaler = CmdPtr[XCP_CRO_SET_DAQ_LIST_MODE_PRESCALER];

  /* #20 Check parameter ranges to be valid. */
  if( daqNumber >= XCP_MAX_DAQ )
  {
    errorCode = XCP_ERR_OUT_OF_RANGE;
  }
  else
  if( eventNumber >= XCP_MAX_EVENT )
  {
    errorCode = XCP_ERR_OUT_OF_RANGE;
  }
  else
#if( XCP_DAQ_TIMESTAMP_SIZE == 0 )
  if( (CmdPtr[XCP_CRO_SET_DAQ_LIST_MODE_MODE] & XCP_DAQ_LIST_TIMESTAMP) > 0u ) /* ESCAN00097176 */
  {
    errorCode = XCP_ERR_OUT_OF_RANGE;
  }
  else
#endif
#if( XCP_DAQ_TIMESTAMP_FIXED == STD_ON )
  if( (CmdPtr[XCP_CRO_SET_DAQ_LIST_MODE_MODE] & XCP_DAQ_LIST_TIMESTAMP) == 0u ) /* ESCAN00097288 */
  {
    errorCode = XCP_ERR_CMD_SYNTAX;
  }
  else
#endif
  if( CmdPtr[XCP_CRO_SET_DAQ_LIST_MODE_PRIORITY] > 0u )
  {
    /* Priorization is not supported */
    errorCode = XCP_ERR_OUT_OF_RANGE;
  }
  /* #30 If parameter ranges are valid, set the mode of the selected DAQ list. */
  else
  {
    if( prescaler == 0u )
    {
      prescaler = 1u;
    }

    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[daqNumber] = CmdPtr[XCP_CRO_SET_DAQ_LIST_MODE_MODE];
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Daq2EventMapping[daqNumber] = eventNumber;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.DaqPrescaler[daqNumber] = prescaler;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.DaqPrescalerCnt[daqNumber] = prescaler;
#if( XCP_STIM == STD_ON )
    /* #40 Once it is known which DAQ list is used for STIM, allocated STIM buffers. */
    errorCode = Xcp_CmdHlp_AllocStimMemory( XCP_CHANNEL_IDX );
#endif
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_CmdDaq_SetDaqListMode */


/**********************************************************************************************************************
 *  Xcp_CmdDaq_GetDaqListMode()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_GetDaqListMode( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 daqNumber;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  daqNumber = Xcp_GetVal16( &CmdPtr[XCP_CRO_GET_DAQ_LIST_MODE_DAQ] );

  /* #20 Check parameter ranges to be valid. */
  if( daqNumber >= Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
  }
  /* #30 If all checks passed, prepare response that contains all information of the requested DAQ list. */
  else
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_LIST_MODE_MODE] = Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[daqNumber];
    /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
    /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
    Xcp_PutVal16( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.w[XCP_CRM_GET_DAQ_LIST_MODE_EVENTCHANNEL >> 1u],
                  Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Daq2EventMapping[daqNumber] );
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_LIST_MODE_PRESCALER] = Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.DaqPrescaler[daqNumber];
    /* DAQ-list prioritization is not supported. */
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_LIST_MODE_PRIORITY] = 0u;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_DAQ_LIST_MODE_LEN;
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdDaq_GetDaqListMode */


/**********************************************************************************************************************
 *  Xcp_CmdDaq_StartStopDaqList()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_StartStopDaqList( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 daqNumber;
  uint8  mode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  mode = CmdPtr[XCP_CRO_START_STOP_MODE];
  daqNumber = Xcp_GetVal16(&CmdPtr[XCP_CRO_START_STOP_DAQ]);

  /* #20 Check parameter ranges to be valid. */
# if( XCP_SEED_KEY == STD_ON )
  if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_DAQ ) != XCP_CMD_OK )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_ACCESS_LOCKED );
  }
  else
# endif
  if( daqNumber >= Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
  }
  /* #30 If all checks passed, perform DAQ list start/stop and prepare response. */
  else
  {
    if( (mode == XCP_CMO_START_STOP_START_DAQ_LIST) || (mode == XCP_CMO_START_STOP_SELECT_DAQ_LIST) )
    {
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[daqNumber] |= (uint8)XCP_DAQ_FLAG_SELECTED;
      if( mode == XCP_CMO_START_STOP_START_DAQ_LIST )
      {
        Xcp_CtrDaq_StartDaq( XCP_CHANNEL_IDX, (uint16_least)daqNumber );
      }
    }
    else
    {
      Xcp_CtrDaq_StopDaq( XCP_CHANNEL_IDX, (uint16_least)daqNumber );
    }
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_START_STOP_FIRST_PID] = (uint8)Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.FirstOdt[daqNumber];
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_START_STOP_LEN;
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdDaq_StartStopDaqList */


/**********************************************************************************************************************
 *  Xcp_CmdDaq_StartStopSynch()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_StartStopSynch( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8  mode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  mode = CmdPtr[XCP_CRO_START_STOP_SYNC_MODE];

  /* #20 Check parameter ranges and initially condition to be valid. */
# if( XCP_SEED_KEY == STD_ON )
  if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_DAQ ) != XCP_CMD_OK )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_ACCESS_LOCKED );
  }
  else
# endif
  if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists == 0u)
   || (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdts == 0u)
   || (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtEntries == 0u) )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_CRC_DAQ_CONFIG );
  }
  else
  {
    /* #30 Parameters valid, perform selected action. */
    switch( mode )
    {
      case( XCP_CMO_START_STOP_SYNCH_START_SELECTED ):
        Xcp_CtrDaq_StartAllSelectedDaq( XCP_CHANNEL_IDX );
        break;
      case( XCP_CMO_START_STOP_SYNCH_STOP_SELECTED ):
        Xcp_CtrDaq_StopAllSelectedDaq( XCP_CHANNEL_IDX );
        break;
      default :
        Xcp_CtrDaq_StopAllDaq( XCP_CHANNEL_IDX );
        break;
    }
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdDaq_StartStopSynch */


#if( XCP_DAQ_TIMESTAMP_SIZE > 0 )
/**********************************************************************************************************************
 *  Xcp_CmdDaq_GetDaqClock()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_GetDaqClock( Xcp_ChannelType XcpChannel,
                                                       CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return current time stamp. */
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
  Xcp_PutVal32( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.l[XCP_CRM_GET_DAQ_CLOCK_TIME >> 2u],
                (uint32)XcpAppl_GetTimestamp() );
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_DAQ_CLOCK_LEN;

  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdDaq_GetDaqClock */
# endif


/**********************************************************************************************************************
 *  Xcp_CmdDaq_GetDaqProcessorInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_GetDaqProcessorInfo( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Create response frame for GetDaqProcessorInfo command. */
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_PROCESSOR_INFO_PROPERTIES] =
   ( XCP_DAQ_PROPERTY_CONFIG_TYPE
# if( XCP_DAQ_TIMESTAMP_SIZE > 0 )
   | XCP_DAQ_PROPERTY_TIMESTAMP
# endif
   | XCP_DAQ_PROPERTY_PRESCALER
# if( XCP_DAQ_RESUME == STD_ON )
   | XCP_DAQ_PROPERTY_RESUME
#endif
   | XCP_DAQ_OVERLOAD_INDICATION_PID );

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
  Xcp_PutVal16( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.w[XCP_CRM_GET_DAQ_PROCESSOR_INFO_MAX_DAQ >> 1u], Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists );
  Xcp_PutVal16( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.w[XCP_CRM_GET_DAQ_PROCESSOR_INFO_MAX_EVENT >> 1u], XCP_MAX_EVENT );
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_PROCESSOR_INFO_MIN_DAQ] = 0u;
  /* DTO identification field type: Absolute ODT number */
#if (XCP_DAQ_HDR_LEN == 1u)
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_PROCESSOR_INFO_DAQ_KEY_BYTE] = XCP_DAQ_HDR_PID;
#else
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_PROCESSOR_INFO_DAQ_KEY_BYTE] = XCP_DAQ_HDR_ODT_DAQB;
#endif

  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_DAQ_PROCESSOR_INFO_LEN;

  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdDaq_GetDaqProcessorInfo */


/**********************************************************************************************************************
 *  Xcp_CmdDaq_GetDaqResolutionInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_GetDaqResolutionInfo( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Create response frame for GetDaqResolutionInfo command. */
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_RESOLUTION_INFO_GRANULARITY_DAQ] = 1u;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_RESOLUTION_INFO_MAX_SIZE_DAQ] = (uint8)XCP_MAX_ODT_ENTRY_SIZE( XCP_CHANNEL_IDX );
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_RESOLUTION_INFO_GRANULARITY_STIM] = 1u;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_RESOLUTION_INFO_MAX_SIZE_STIM] = (uint8)XCP_MAX_ODT_ENTRY_SIZE( XCP_CHANNEL_IDX );
# if( XCP_DAQ_TIMESTAMP_SIZE > 0 )
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_MODE] = XCP_DAQ_TIMESTAMP_UNIT | sizeof(Xcp_TimestampType)
#  if( XCP_DAQ_TIMESTAMP_FIXED == STD_ON )
    | XCP_DAQ_RES_TIMESTAMP_FIXED
#  endif
    ;
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
  Xcp_PutVal16( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.w[XCP_CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_TICKS >> 1u],
                XCP_DAQ_TIMESTAMP_TICKS_PER_UNIT );
# else
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_MODE] = 0u;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.w[XCP_CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_TICKS >> 1u] = 0u;
# endif
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_DAQ_RESOLUTION_INFO_LEN;

  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdDaq_GetDaqResolutionInfo */


#if( XCP_DAQ_EVENT_INFO == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdDaq_GetDaqEventInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_GetDaqEventInfo( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 eventNumber;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  eventNumber = Xcp_GetVal16( &CmdPtr[XCP_CRO_GET_DAQ_EVENT_INFO_EVENT] );

  /* #20 Check for valid parameter range. */
  if( eventNumber >= XCP_MAX_EVENT )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
  }
  /* #30 If all checks passed, prepare response for GetDaqEventInfo command. */
  else
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_EVENT_INFO_PROPERTIES] = kXcpEventDirection[eventNumber];
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_EVENT_INFO_MAX_DAQ_LIST] = 1u;
    /* Limitation to only 1 DAQ list per event channel. Not evaluated by CANape. Can this still be valid if DAQ/STIM event? */
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_EVENT_INFO_NAME_LENGTH] = kXcpEventNameLength[eventNumber];
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_EVENT_INFO_TIME_CYCLE] = kXcpEventCycle[eventNumber];
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_EVENT_INFO_TIME_UNIT] = (uint8)(kXcpEventUnit[eventNumber] >> 4u);
    /* Event channel prioritization is not supported. */
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_DAQ_EVENT_INFO_PRIORITY] = 0u;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_DAQ_EVENT_INFO_LEN;

    /* PRQA S 0306 1 */ /* MD_Xcp_0306 */
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA = (const Xcp_AddressPtrType)kXcpEventName[eventNumber]; /* ESCAN00097925 */
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTAExtension = 0x00;
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdDaq_GetDaqEventInfo */
#endif /* ( XCP_DAQ_EVENT_INFO == STD_ON ) && ( XCP_MAX_EVENT > 0 ) */


/**********************************************************************************************************************
 *  Xcp_CmdDaq_FreeDaq()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_FreeDaq( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check resource protection status. */
# if( XCP_SEED_KEY == STD_ON )
  if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_DAQ ) != XCP_CMD_OK )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_ACCESS_LOCKED );
  }
  else
# endif
  /* #20 If all checks passed, clear the whole DAQ list. */
  {
    /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
    Xcp_Hlp_MemSet( (P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))&Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList, 
                    sizeof(Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList), 0u );
  }

  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdDaq_FreeDaq */


/**********************************************************************************************************************
 *  Xcp_CmdDaq_AllocDaq()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_AllocDaq( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 daqCount;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  daqCount = Xcp_GetVal16(&CmdPtr[XCP_CRO_ALLOC_DAQ_COUNT]);

  /* #20 Check for correct setup sequence and valid parameter range. */
  if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdts != 0u) || (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtEntries != 0u) )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_SEQUENCE );
  }
  else
  if( daqCount > XCP_MAX_DAQ )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
  }
  /* #30 If all checks passed, remember the number of allocated DAQ lists here. */
  else
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists = daqCount;
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdDaq_AllocDaq */


/**********************************************************************************************************************
 *  Xcp_CmdDaq_AllocOdt()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_AllocOdt( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 daqNumber;
  uint8  odtCount;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  daqNumber = Xcp_GetVal16(&CmdPtr[XCP_CRO_ALLOC_ODT_DAQ]);
  odtCount = CmdPtr[XCP_CRO_ALLOC_ODT_COUNT];

  /* #20 Check for correct setup sequence and valid parameter range. */
  if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists == 0u) || (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtEntries != 0u) )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_SEQUENCE );
  }
  else
  if( daqNumber > Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
  }
  /* #30 If all checks passed:
   *       Remember the number of allocated ODTs lists here and check if number of ODTs is in valid range. */
  else
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.FirstOdt[daqNumber] = (Xcp_OdtIdxType)Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdts;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtsDaq[daqNumber] = odtCount;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdts = Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdts + odtCount;

    if( Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdts > (XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM) )
    {
      Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
      /* PRQA S 0310 1 */ /* MD_Xcp_0310 */
      Xcp_Hlp_MemSet( (P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))&Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList, sizeof(Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList), 0u );
    }
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdDaq_AllocOdt */


/**********************************************************************************************************************
 *  Xcp_CmdDaq_AllocOdtEntry()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdDaq_AllocOdtEntry( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 daqNumber;
  uint8  odtNumber;
  uint8  odtEntriesCount;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  daqNumber = Xcp_GetVal16(&CmdPtr[XCP_CRO_ALLOC_ODT_ENTRY_DAQ]);
  odtNumber = CmdPtr[XCP_CRO_ALLOC_ODT_ENTRY_ODT];
  odtEntriesCount = CmdPtr[XCP_CRO_ALLOC_ODT_ENTRY_COUNT];

  /* #20 Check for correct setup sequence and valid parameter range. */
  if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists == 0u) || (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdts == 0u) )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_SEQUENCE );
  }
  else
  if( daqNumber > Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
  }
  else
  if(odtNumber > Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtsDaq[daqNumber])
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
  }
  /* #30 If all checks passed:
   *       Remember the number of allocated ODT Entries here and check if number of ODT entries is in valid range. */
  else
  {
    uint16 odtIdx;
    odtIdx = Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.FirstOdt[daqNumber] + odtNumber;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.FirstOdtEntry[odtIdx] = (Xcp_OdtEntryIdxType)Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtEntries; /* ESCAN00099495 */
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtEntriesOdt[odtIdx] = odtEntriesCount;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtEntries = Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtEntries + odtEntriesCount;

    if( Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdtEntries > XCP_MAX_ODT_ENTRIES )
    {
      Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_OUT_OF_RANGE );
      /* PRQA S 0310 1 */ /* MD_Xcp_0310 */
      Xcp_Hlp_MemSet( (P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))&Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList, sizeof(Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList), 0u );
    }
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdDaq_AllocOdtEntry */
#endif /* ( XCP_DAQ == STD_ON ) */


#if( (XCP_PROGRAM == STD_ON) || (XCP_BOOTLOADER_DOWNLOAD == STD_ON) )
/**********************************************************************************************************************
 *  Xcp_CmdPgm_ProgramStart()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_ProgramStart( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorCode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check resource protection state. */
# if( XCP_SEED_KEY == STD_ON )
  if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_PGM ) != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_LOCKED;
  }
  else
# endif
  /* #20 If all checks passed, prepare response and call XcpAppl call-back to notify application. */
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = (uint8)XCP_CRM_PROGRAM_START_LEN;

    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_MAX_CTO_PGM]   = Xcp_ChannelInfo[XCP_CHANNEL_IDX].MaxCto;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_COMM_MODE_PGM] = 0;
# if( XCP_BLOCK_UPLOAD == STD_ON )
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_COMM_MODE_PGM] |= (uint8)XCP_CMB_SLAVE_BLOCK_MODE;
# endif
# if( XCP_BLOCK_DOWNLOAD == STD_ON )
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_COMM_MODE_PGM] |= (uint8)XCP_CMO_MASTER_BLOCK_MODE;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_MAX_BS_PGM]     = (uint8)((254 / XCP_CRO_PROGRAM_MAX_SIZE(XCP_CHANNEL_IDX)) + (uint8)1u);
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_MIN_ST_PGM]     = (uint8)kXcpProgramMinStPgm;
# else
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_MAX_BS_PGM]     = 0;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_MIN_ST_PGM]     = 0;
# endif
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_QUEUE_SIZE_PGM] = 0; /* Interleaved mode is not implemented */

# if( XCP_BOOTLOADER_DOWNLOAD == STD_ON )
    errorCode = XCP_CMD_OK;
    if( XcpAppl_StartBootLoader() != (uint8)XCP_CMD_OK )
    {
      errorCode =  XCP_ERR_GENERIC; /* Forced to be Generic. */
    }
# else
    errorCode = XcpAppl_ProgramStart();
# endif
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPgm_ProgramStart */
#endif /* ( (XCP_PROGRAM == STD_ON) || (XCP_BOOTLOADER_DOWNLOAD == STD_ON) ) */


#if( XCP_PROGRAM == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdPgm_ProgramClear()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_ProgramClear( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 size;
  uint8  errorCode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  size = Xcp_GetVal32( &CmdPtr[XCP_CRO_PROGRAM_CLEAR_SIZE] );

  /* #20 Check resource protection state. */
# if( XCP_SEED_KEY == STD_ON )
  if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_PGM ) != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_LOCKED;
  }
  else
# endif
  /* #30 Check memory range to be valid to be cleared. */
# if( XCP_PROGRAMMING_WRITE_PROTECTION == STD_ON )
  if( XcpAppl_CheckProgramAccess( Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA, size ) != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_DENIED;
  }
  else
# endif
  /* #40 Call XcpAppl call-back to clear the flash memory. Only the Absolute Access Mode is available. Prepare negative response otherwise. */
  if( CmdPtr[XCP_CRO_PROGRAM_CLEAR_MODE] == 0 )
  {
    /* PRQA S 0306 2 */ /* MD_Xcp_0306 */
    errorCode = XcpAppl_FlashClear( (P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA,
                                    size );
  }
  else
  {
    errorCode = XCP_ERR_CMD_SYNTAX;
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPgm_ProgramClear */


/**********************************************************************************************************************
 *  Xcp_CmdPgm_Program()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_Program( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorCode;
  uint8 size;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  size = CmdPtr[XCP_CRO_PROGRAM_SIZE];

  /* #- Perform parameter range and protection checks. Additionally check if memory are may be written. */
# if( XCP_BLOCK_DOWNLOAD == STD_ON )
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize = size;
  if( size > XCP_CRO_PROGRAM_MAX_SIZE(XCP_CHANNEL_IDX) )
  {
    size = XCP_CRO_PROGRAM_MAX_SIZE(XCP_CHANNEL_IDX);
  }
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize = Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize - size;
# else
  if( size > XCP_CRO_PROGRAM_MAX_SIZE(XCP_CHANNEL_IDX) )
  {
    errorCode = XCP_ERR_OUT_OF_RANGE;
  }
  else
# endif
# if( XCP_SEED_KEY == STD_ON )
  if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_PGM ) != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_LOCKED;
  }
  else
# endif
# if( XCP_PROGRAMMING_WRITE_PROTECTION == STD_ON )
  if( XcpAppl_CheckProgramAccess( Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA,
                                  (uint32)XCP_CRO_PROGRAM_MAX_SIZE( XCP_CHANNEL_IDX ) ) 
   != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_DENIED;
  }
  else
# endif
  {
    /* #20 Range checks were successful, perform write operation back calling XcpAppl call-back. */
    /* PRQA S 0306 4 */ /* MD_Xcp_0306 */
    errorCode = XcpAppl_FlashProgram( &CmdPtr[XCP_CRO_PROGRAM_DATA],
                                      (P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA,
                                      size
                                    );

    Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA = Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA + size;
  }

# if( XCP_BLOCK_DOWNLOAD )
  if( Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize > 0 )
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = 0;
  }
# endif

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPgm_Program */


/**********************************************************************************************************************
 *  Xcp_CmdPgm_ProgramReset()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_ProgramReset( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Perform unconditional Reset. First disconnect then call XcpAppl call-back to perform reset operation. ECU may restart. */
  Xcp_CmdStd_Disconnect( XCP_CHANNEL_IDX, CmdPtr );
  XcpAppl_Reset(); /* May not return */

  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = 0;

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPgm_ProgramReset */


#if( XCP_PROGRAM_INFO == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdPgm_GetPgmProcessorInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_GetPgmProcessorInfo( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare response for GetPgmProcessorInfo command. */
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_GET_PGM_PROCESSOR_INFO_LEN;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_PGM_PROCESSOR_INFO_PROPERTIES] = (uint8)
    (XCP_PGM_ACCESS_ABSOLUTE | XCP_PGM_COMPRESSION_NONE | XCP_PGM_ENCRYPTION_NONE | XCP_PGM_NON_SEQ_NONE );

  Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_GET_PGM_PROCESSOR_INFO_MAX_SECTOR] = XCP_MAX_SECTOR;

  XCP_DUMMY_STATEMENT_CONST( CmdPtr ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPgm_GetPgmProcessorInfo */


/**********************************************************************************************************************
 *  Xcp_CmdPgm_GetSectorInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_GetSectorInfo( Xcp_ChannelType XcpChannel, CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorCode = XCP_CMD_OK;
  uint8 sector;
  uint8 mode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  mode   = CmdPtr[XCP_CRO_PROGRAM_GET_SECTOR_INFO_MODE];
  sector = CmdPtr[XCP_CRO_PROGRAM_GET_SECTOR_INFO_NUMBER];

  /* #20 Check sector range to be valid. */
  if( sector >= XCP_MAX_SECTOR )
  {
    errorCode = XCP_ERR_OUT_OF_RANGE;
  }
  else
  {
    /* #30 Return sector information depending on mode. Either in response string for mode 0 and 1 or via UPLOAD for mode 2. */
    if( mode == 2 )
    {
      uint32 address;
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = 2;
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_GET_SECTOR_NAME_LENGTH] = kXcpSectorNameLength[sector];

      address = Xcp_GetVal32( &kXcpSectorName[sector] ); /* PRQA S 0310 */ /* MD_Xcp_0310 */
      Xcp_CmdHlp_SetMta( XCP_CHANNEL_IDX, address, 0x00 );
    }
    else
    {
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = XCP_CRM_PROGRAM_GET_SECTOR_INFO_LEN;

      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_GET_SECTOR_CLEAR_SEQ_NUM] = 0x00;
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_GET_SECTOR_PGM_SEQ_NUM] = 0x00;
      /* The programming method is per default Sequential Programming. */
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_GET_SECTOR_PGM_METHOD] = 0x00;

      if( mode == 0 )
      {
        /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
        /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
        Xcp_PutVal32( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.l[XCP_CRM_PROGRAM_GET_SECTOR_SECTOR_INFO >> 2],
                      (uint32)kXcpProgramSectorStart[sector] );
      }
      else if( mode == 1 )
      {
        /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
        /* PRQA S 0310 2 */ /* MD_Xcp_0310 */
        Xcp_PutVal32( &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.l[XCP_CRM_PROGRAM_GET_SECTOR_SECTOR_INFO >> 2],
                      (uint32)(((kXcpProgramSectorEnd[sector]) - (kXcpProgramSectorStart[sector])) + 1) );
      }
      else
      {
        errorCode = XCP_ERR_CMD_SYNTAX;
      }
    }
  }

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPgm_GetSectorInfo */
# endif /* ( XCP_PROGRAM_INFO == STD_ON ) */
#endif /* ( XCP_PROGRAM == STD_ON ) */


#if( XCP_BOOTLOADER_DOWNLOAD == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CmdPgm_ProgramPrepare()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_ProgramPrepare( Xcp_ChannelType XcpChannel,
                                                          CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 size;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get parameters from command string. */
  size = Xcp_GetVal16( &CmdPtr[XCP_CRO_PROGRAM_PREPARE_SIZE] );

  /* #20 Perform XcpAppl call-back to disable application operation and prepare for flash programming. */
  if( XcpAppl_DisableNormalOperation(Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA, size) != XCP_CMD_OK )
  {
    Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_GENERIC );
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPgm_ProgramPrepare */
#endif /* XCP_BOOTLOADER_DOWNLOAD == STD_ON */


#if( (XCP_PROGRAM == STD_ON) && (XCP_BLOCK_DOWNLOAD == STD_ON) )
/**********************************************************************************************************************
 *  Xcp_CmdPgm_ProgramNext()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_ProgramNext( Xcp_ChannelType XcpChannel, 
                                                CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if data block size is correct and perform next program step, otherwise return negative response. */
  if( Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize == CmdPtr[XCP_CRO_PROGRAM_NEXT_SIZE] )
  {
    Xcp_CmdPgm_Program( XCP_CHANNEL_IDX, CmdPtr );
  }
  else
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = 3;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[0] = XCP_PID_ERR;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_NEXT_ERR_SEQUENCE] = XCP_ERR_SEQUENCE;
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_PROGRAM_NEXT_SIZE_EXPECTED_DATA] = 
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize;
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPgm_ProgramNext */
#endif /* (XCP_PROGRAM == STD_ON) && (XCP_BLOCK_DOWNLOAD == STD_ON) */


#if( (XCP_PROGRAM == STD_ON) && (XCP_BLOCK_DOWNLOAD == STD_OFF) )
/**********************************************************************************************************************
 *  Xcp_CmdPgm_ProgramMax()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_CmdPgm_ProgramMax( Xcp_ChannelType XcpChannel, 
                                                      CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorCode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Perform resource protection check, followed by a range check if access is valid. */
# if( XCP_SEED_KEY == STD_ON )
  if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_PGM ) != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_LOCKED;
  }
  else
# endif
# if( XCP_PROGRAMMING_WRITE_PROTECTION == STD_ON )
  if( XcpAppl_CheckProgramAccess( Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA, 
                                  (uint32)XCP_CRO_PROGRAM_MAX_MAX_SIZE(XCP_CHANNEL_IDX) )
   != XCP_CMD_OK )
  {
    errorCode = XCP_ERR_ACCESS_DENIED;
  }
  else
# endif
  { /* #20 Call XcpAppl call-back to perform actual flash programming step. */
    /* PRQA S 0306 4 */ /* MD_Xcp_0306 */
    errorCode = XcpAppl_FlashProgram( &CmdPtr[XCP_CRO_PROGRAM_MAX_DATA],
                                      (P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA,
                                      XCP_CRO_PROGRAM_MAX_MAX_SIZE(XCP_CHANNEL_IDX)
                                    );
  }

  Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA = Xcp_ChannelInfo[XCP_CHANNEL_IDX].MTA + XCP_CRO_PROGRAM_MAX_MAX_SIZE(XCP_CHANNEL_IDX);

  Xcp_CmdHlp_PrepareErrorOrPending( XCP_CHANNEL_IDX, errorCode );

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CmdPgm_ProgramMax */
#endif


#if( XCP_DAQ == STD_ON )
/**********************************************************************************************************************
 *  Xcp_CtrDaq_QueueInit()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CtrDaq_QueueInit( Xcp_ChannelType XcpChannel )
{
  uint16_least i;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize send queue and overload condition on this XCP channel. */
  for( i = 0; i < XCP_NUMBER_OF_CORES; i++ )
  {
    Xcp_SendQueueReadIdx[XCP_CHANNEL_IDX][i] = 0u;
    Xcp_SendQueueWriteIdx[XCP_CHANNEL_IDX][i] = 0u;
#if ( XCP_DAQ_OVERRUN_INDICATION == STD_ON )
    Xcp_OverloadFlag[XCP_CHANNEL_IDX][i] = 0u;
#endif
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CtrDaq_QueueInit */


/**********************************************************************************************************************
 *  Xcp_CtrDaq_StartDaq()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CtrDaq_StartDaq( Xcp_ChannelType XcpChannel, uint16_least Daq )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Activate DAQ list and enter the data transfer mode. */
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[Daq] |= (uint8)XCP_DAQ_FLAG_RUNNING;
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.DaqPrescalerCnt[Daq] = 1u;

  Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus |= XCP_SESSION_DAQ;

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CtrDaq_StartDaq */


/**********************************************************************************************************************
 *  Xcp_CtrDaq_StartAllSelectedDaq()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CtrDaq_StartAllSelectedDaq( Xcp_ChannelType XcpChannel )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16_least daq;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Start all DAQ lists previous selected by command Xcp_CmdDaq_StartStopDaqList. */
  for( daq = 0; daq < Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists; daq++ )
  {
    if ( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[daq] & (uint8)XCP_DAQ_FLAG_SELECTED) != 0u )
    {
      Xcp_CtrDaq_StartDaq(XCP_CHANNEL_IDX, daq);
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[daq] &= (uint8)((~XCP_DAQ_FLAG_SELECTED) & 0xFFu);
    }
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CtrDaq_StartAllSelectedDaq */


/**********************************************************************************************************************
 *  Xcp_CtrDaq_StopDaq()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CtrDaq_StopDaq( Xcp_ChannelType XcpChannel, uint16_least Daq )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16_least i;
  uint8 mode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Stop this DAQ list and reset its selected state. */
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[Daq] &= (uint8)(XCP_DAQ_FLAG_DIRECTION | XCP_DAQ_FLAG_TIMESTAMP | XCP_DAQ_FLAG_NO_PID);

  /* #20 If no DAQ list on this channel is running anymore, the data transfer mode is left. */
  mode = 0u;
  for( i = 0; i < Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists; i++ )
  {
    mode |= Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[i];
  }

  if( (mode & (uint8)XCP_DAQ_FLAG_RUNNING) == 0u )
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus &= (uint16)((~XCP_SESSION_DAQ) & 0xFFFF);
    Xcp_CtrDaq_QueueInit(XCP_CHANNEL_IDX);
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CtrDaq_StopDaq */


/**********************************************************************************************************************
 *  Xcp_CtrDaq_StopAllSelectedDaq()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CtrDaq_StopAllSelectedDaq( Xcp_ChannelType XcpChannel )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16_least daq;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Stop all DAQ lists previously selected by command Xcp_CmdDaq_StartStopDaqList. */
  for( daq = 0; daq < Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists; daq++ )
  {
    if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[daq] & (uint8)XCP_DAQ_FLAG_SELECTED) != 0u )
    {
      Xcp_CtrDaq_StopDaq(XCP_CHANNEL_IDX, daq);
      /* The selected state is reset in Xcp_CtrDaq_StopDaq. Therefore this is not done here! */
    }
  }

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CtrDaq_StopAllSelectedDaq */


/**********************************************************************************************************************
 *  Xcp_CtrDaq_StopAllDaq()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_CtrDaq_StopAllDaq( Xcp_ChannelType XcpChannel )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16_least daq;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Stop all DAQ lists and remove their selected state. */
  for( daq = 0; daq < Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists; daq++ )
  {
    Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[daq] &= (uint8)(XCP_DAQ_FLAG_DIRECTION | XCP_DAQ_FLAG_TIMESTAMP | XCP_DAQ_FLAG_NO_PID);
  }
  /* #20 Leave data transfer mode. */
  Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus &= (uint16)((~XCP_SESSION_DAQ) & 0xFFFFu);

  Xcp_CtrDaq_QueueInit(XCP_CHANNEL_IDX);

  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
} /* Xcp_CtrDaq_StopAllDaq */
#endif /* ( XCP_DAQ == STD_ON ) */


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Xcp_InitMemory()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_InitMemory( void )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the following variables with the corresponding values. */
  Xcp_ModuleInitialized = XCP_UNINIT;
#if (XCP_DEV_ERROR_REPORT == STD_ON) && ( XCP_NUMBER_OF_CORES > 1u )
  Xcp_BswErrorId = XCP_E_NO_ERROR;
  Xcp_BswFctId = 0u;
#endif
#if( XCP_CONTROL == STD_ON )
  Xcp_ControlState = kXcp_Control_Enable;
  Xcp_ControlDeniedCount = 0u;
#endif
}  /* Xcp_InitMemory() */


/**********************************************************************************************************************
 *  Xcp_Init()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_Init( void )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least XcpChannel;

#if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Start runtime measurement. */
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Xcp_Rtm_Start(Xcp_Init); /* PRQA S 3112 */ /* MD_MSR_14.2 */ /*lint -e{438} */

    Xcp_ModuleInitialized = (uint8)XCP_INIT;
    /* #30 Initialize all XCP variables to zero. */
    Xcp_Hlp_MemSet((P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))&Xcp_ChannelInfo[0], sizeof(Xcp_ChannelInfo), 0u); /* PRQA S 0310 */ /* MD_Xcp_0310 */

#if( XCP_STIM == STD_ON )
      Xcp_StimMode = XCP_STIM_SINGLE_SHOT_MODE;
#endif

    for( XcpChannel = 0; XcpChannel < XCP_NUMBER_OF_CHANNELS; XcpChannel++ )
    {
#if( XCP_SEED_KEY == STD_ON )
      /* #40 Set initial lock state -> Lock all resources. May be modified by service function. */
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatusInit = (uint8)( XCP_RM_ALL_RESOURCES );
#endif

      /* #50 Set 8 bytes as maximum value for command and data messages as default for CAN. */
      Xcp_SetActiveTl( (Xcp_ChannelType)XCP_CHANNEL_IDX, 8, 8, (Xcp_ChannelType)XCP_CHANNEL_IDX );

      /* #60 Perform Resume Operation for DAQ measurement. */
#if( XCP_DAQ == STD_ON )
      Xcp_CtrDaq_QueueInit( (Xcp_ChannelType)XCP_CHANNEL_IDX );

# if( XCP_DAQ_RESUME == STD_ON )
      /* #70 If XcpChannel is in Resume Mode, start all selected DAQ lists. For these lists Xcp_Event is available immediately. */
      if ( XcpAppl_DaqResume( (Xcp_ChannelType)XCP_CHANNEL_IDX, (P2VAR(Xcp_ChannelStruct, AUTOMATIC, XCP_APPL_DATA))&Xcp_ChannelInfo[XCP_CHANNEL_IDX] ) == TRUE )
      {
        /* #80 Re-Initialize all variables to zero above Resume mode and lock all resources. */
        /* PRQA S 0306 3 */ /* MD_Xcp_0306 */
        /* PRQA S 0488 2 */ /* MD_Xcp_0488 */
        Xcp_Hlp_MemSet((P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))((Xcp_AddressPtrType)&Xcp_ChannelInfo[XcpChannel].ResponseFrame.b[0]), 
          (uint16)((&Xcp_ChannelInfo[XcpChannel].SendStatus - &Xcp_ChannelInfo[XcpChannel].ResponseFrame.b[0]) + 1), 0u);
#  if( XCP_SEED_KEY == STD_ON )
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatusInit = (uint8)( XCP_RM_ALL_RESOURCES );
#  endif

        Xcp_Hlp_CalcSendQueueEntrySizeAndLimit( (Xcp_ChannelType)XCP_CHANNEL_IDX );

        /* #90 Goto temporary disconnected mode and start all selected DAQ lists. */
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus |= (uint16)XCP_SESSION_RESUME;
        /* Select all DAQ lists. */
        Xcp_CtrDaq_StartAllSelectedDaq( (Xcp_ChannelType)XCP_CHANNEL_IDX );

        /* #100 Indicate connection state change to state RESUME. */
        XcpAppl_ConStateNotification( (Xcp_ChannelType)XCP_CHANNEL_IDX, XCP_CON_STATE_RESUME );
      }
      else
# endif
#endif
      /* #110 Otherwise, indicate connection state change to state DISCONNECTED. */
      {
        XcpAppl_ConStateNotification( (Xcp_ChannelType)XCP_CHANNEL_IDX, XCP_CON_STATE_DISCONNECTED );
      }
    }

    /* #120 Stop runtime measurement. */
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Xcp_Rtm_Stop(Xcp_Init); /* PRQA S 3112 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  }
#if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
#endif
  /* PRQA S 6050 1 */ /* MD_MSR_STCALL */
} /* Xcp_Init() */


#if( XCP_VERSION_INFO_API == STD_ON )
/**********************************************************************************************************************
 *  Xcp_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_GetVersionInfo( P2VAR(Std_VersionInfoType, AUTOMATIC, XCP_APPL_VAR) versioninfo )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = XCP_E_NO_ERROR;

# if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. \trace SPEC-4265 */
  if( Xcp_ControlState == kXcp_Control_Enable )
# endif
  {
    /* ----- Development Error Checks ------------------------------------- */
# if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( versioninfo == NULL_PTR )
    {
      errorId = XCP_E_PARAM_POINTER;
    }
    else
# endif
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #30 Copy version information. */
      versioninfo->vendorID         = (XCP_VENDOR_ID);
      versioninfo->moduleID         = (XCP_MODULE_ID);
      versioninfo->sw_major_version = (XCP_SW_MAJOR_VERSION);
      versioninfo->sw_minor_version = (XCP_SW_MINOR_VERSION);
      versioninfo->sw_patch_version = (XCP_SW_PATCH_VERSION);
    }

    /* ----- Development Error Report --------------------------------------- */
# if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_GET_VERSION_INFO, errorId );
    }
# else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
  }
# if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
# endif
} /* Xcp_GetVersionInfo */
#endif /* ( XCP_VERSION_INFO_API == STD_ON ) */


#if( XCP_GET_SESSION_STATUS_API == STD_ON )
/**********************************************************************************************************************
 * Xcp_GetSessionStatus()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint16, XCP_CODE) Xcp_GetSessionStatus( Xcp_ChannelType XcpChannel )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 result = 0;
  uint8 errorId = XCP_E_NO_ERROR;

#if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
#endif
  {
    /* ----- Development Error Checks ------------------------------------- */
#if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
# if ( XCP_NUMBER_OF_CHANNELS > 1 )
    else if( XcpChannel >= XCP_NUMBER_OF_CHANNELS )
    {
      errorId = XCP_E_PARAM_CHANNEL;
    }
# endif
    else
#endif
    {
      /* ----- Implementation ----------------------------------------------- */
      result = Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus;

      /* #30 Reset the polling state. */
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus &= (uint16)((~XCP_SESSION_POLLING) & 0xFFFF); 

      XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
    }

    /* ----- Development Error Report --------------------------------------- */
#if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_GET_SESSION_STATUS, errorId );
    }
#else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  }
#if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
#endif
  return result;
} /* Xcp_GetSessionStatus */
#endif


/**********************************************************************************************************************
 * Xcp_SetActiveTl()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_SetActiveTl( Xcp_ChannelType XcpChannel, uint8 MaxCto, uint16 MaxDto, uint8 ActiveTl )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = XCP_E_NO_ERROR;

#if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
#endif
  {
    /* ----- Development Error Checks ------------------------------------- */
#if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
# if( XCP_NUMBER_OF_CHANNELS > 1 )
    else if( XcpChannel >= XCP_NUMBER_OF_CHANNELS )
    {
      errorId = XCP_E_PARAM_CHANNEL;
    }
# endif
    else if( MaxCto > XCP_MAX_CTO_MAX )
    {
      errorId = XCP_E_PARAM_VALUE;
    }
    else if( MaxDto > XCP_MAX_DTO_MAX )
    {
      errorId = XCP_E_PARAM_VALUE;
    }
    else if( ActiveTl >= (sizeof(Xcp_TlApi) / sizeof(Xcp_TlApi[0])) )
    {
      errorId = XCP_E_PARAM_VALUE;
    }
    else
#endif
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #30 Set channel or TL information. If TL changes, stop running DAQ first. */
#if( XCP_DAQ == STD_ON )
      if( Xcp_ChannelInfo[XCP_CHANNEL_IDX].ActiveTl != ActiveTl )
      {
        Xcp_CtrDaq_StopAllDaq(XCP_CHANNEL_IDX);
      }
#endif
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ActiveTl = ActiveTl;
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].MaxCto = MaxCto;
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].MaxDto = MaxDto;
    }

    XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

    /* ----- Development Error Report --------------------------------------- */
#if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_SET_ACTIVE_TL, errorId );
    }
#else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  }
#if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
#endif
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_SetActiveTl */


/**********************************************************************************************************************
 * Xcp_GetActiveTl()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) Xcp_GetActiveTl( Xcp_ChannelType XcpChannel )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = XCP_E_NO_ERROR;
  uint8 activeTl = 0;

#if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
#endif
  {
    /* ----- Development Error Checks ------------------------------------- */
#if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
# if ( XCP_NUMBER_OF_CHANNELS > 1 )
    else if( XcpChannel >= XCP_NUMBER_OF_CHANNELS )
    {
      errorId = XCP_E_PARAM_CHANNEL;
    }
# endif
    else
#endif
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #30 Get the currently active TL. */
      activeTl = Xcp_ChannelInfo[XCP_CHANNEL_IDX].ActiveTl; /* ESCAN00097377 */

      XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
    }

    /* ----- Development Error Report --------------------------------------- */
#if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_GET_ACTIVE_TL, errorId );
    }
#else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  }
#if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
#endif

  return activeTl;
} /* Xcp_GetActiveTl */


/**********************************************************************************************************************
 * Xcp_TlRxIndication()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_TlRxIndication( Xcp_ChannelType XcpChannel, P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = XCP_E_NO_ERROR;

#if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
#endif
  {
    /* ----- Development Error Checks ------------------------------------- */
#if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
    else if( CmdPtr == NULL_PTR )
    {
      errorId = XCP_E_PARAM_POINTER;
    }
# if ( XCP_NUMBER_OF_CHANNELS > 1 )
    else if( XcpChannel >= XCP_NUMBER_OF_CHANNELS )
    {
      errorId = XCP_E_PARAM_CHANNEL;
    }
# endif
    else
#endif
    {
      /* #30 Start runtime measurement. */
      /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
      Xcp_Rtm_Start(Xcp_TlRxIndication); /* PRQA S 3112 */ /* MD_MSR_14.2 */ /*lint -e{438} */

      /* ----- Implementation ----------------------------------------------- */
      /* #40 Is it a connect command or are we in connected state already? */
      if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].ConnectState == XCP_TRUE)
       || (CmdPtr[XCP_CRO_CMD] == XCP_CMD_CONNECT) )
      {
        /* #50 Is it a CMD or a STIM frame? */
        if( CmdPtr[XCP_CRO_CMD] >= XCP_CMD_BORDER )
        {
          /* #60 Ignore commands if the previous command sequence has not been completed. */
          if( (CmdPtr[XCP_CRO_CMD] != XCP_CMD_CONNECT)
           && ((Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus & (uint8)(XCP_CRM_PENDING)) != 0 )
           && ((Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus & (uint8)(XCP_CRM_REQUEST)) != 0 ) )
          {
            Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus |= XCP_SESSION_ERROR;
            /* No response */
          }
          else
          {
            /* #70 It is a CMD frame, prepare default response and then call the function pointer from table. */
            Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[XCP_CRM_CMD] = XCP_PID_RES;
            Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = 1u;

            Xcp_CmdFct[(uint8)~CmdPtr[XCP_CRO_CMD]]( XCP_CHANNEL_IDX, CmdPtr );

#if( XCP_GET_SESSION_STATUS_API == STD_ON )
            Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus |= (uint16)XCP_SESSION_POLLING;
#endif

            if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength > 0u)
             && (Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponsePending == XCP_FALSE) )
            { /* Transmit CTO response packet */
              Xcp_SendCrm( XCP_CHANNEL_IDX );
            }
          }
        }
        else
        {
#if( XCP_STIM == STD_ON )
          /* #80 If the received frame is a STIM frame it is decoded in the following section. */
# if( XCP_SEED_KEY == STD_ON )
          if( Xcp_CmdHlp_CheckResourceProtection( XCP_CHANNEL_IDX, XCP_RM_STIM ) != XCP_CMD_OK )
          {
            Xcp_CmdHlp_PrepareError( XCP_CHANNEL_IDX, XCP_ERR_ACCESS_LOCKED );
          }
          else
# endif
          {
            P2VAR(tXcpDto, AUTOMATIC, XCP_VAR_NOINIT) pStimBuf;

            /* #90 Range Check: Is the PID within range? */
            if( CmdPtr[XCP_CRO_CMD] < Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nOdts )
            {
              /* #100 Get the correct STIM Buffer and copy the received data in the STIM buffer - thread safe. */
              pStimBuf = Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.pStimBuffer[CmdPtr[XCP_CRO_CMD]];
              if( pStimBuf != NULL_PTR )
              {
                Xcp_Enter_Exclusive_Area_Stim(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                /* And copy the DTO */
                XcpAppl_MemCpy( &(pStimBuf->buffer.b[1]), &CmdPtr[XCP_CRO_CMD + 1], Xcp_ChannelInfo[XCP_CHANNEL_IDX].MaxDto - 1 );
                /* Make it valid */
                pStimBuf->buffer.b[0] = CmdPtr[XCP_CRO_CMD];
                Xcp_Leave_Exclusive_Area_Stim(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
              }
            }
          }
#else
# if( XCP_OPEN_COMMAND_IF == STD_ON )
          Xcp_Cmd_ReservedCmd( XCP_CHANNEL_IDX,
                               (CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_VAR))&CmdPtr[0] );

          if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength > 0u)
           && (Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponsePending == XCP_FALSE) )
          { /* Transmit CTO response packet */
            Xcp_SendCrm( XCP_CHANNEL_IDX );
          }
# endif
#endif
        }
      }

      /* #110 Stop runtime measurement. */
      /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
      Xcp_Rtm_Stop(Xcp_TlRxIndication); /* PRQA S 3112 */ /* MD_MSR_14.2 */ /*lint -e{438} */

      XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
    }

    /* ----- Development Error Report --------------------------------------- */
#if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_TL_RX_INDICATION, errorId );
    }
#else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  }
#if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
#endif
  /* PRQA S 6030 3 */ /* MD_MSR_STCYC */
  /* PRQA S 6050 2 */ /* MD_MSR_STCALL */
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_TlRxIndication() */


/**********************************************************************************************************************
 * Xcp_TlTxConfirmation()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_TlTxConfirmation( Xcp_ChannelType XcpChannel )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = XCP_E_NO_ERROR;

#if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
#endif
  {
    /* ----- Development Error Checks ------------------------------------- */
#if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
# if ( XCP_NUMBER_OF_CHANNELS > 1 )
    else if( XcpChannel >= XCP_NUMBER_OF_CHANNELS )
    {
      errorId = XCP_E_PARAM_CHANNEL;
    }
# endif
    else
#endif
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #30 Start runtime measurement. */
      /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
      Xcp_Rtm_Start(Xcp_TlTxConfirmation); /* PRQA S 3112 */ /* MD_MSR_14.2 */ /*lint -e{438} */

      /* #40 Clear all pending flags. A pending flag indicates that ApplXcpSend() is in progress. */
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus &= (uint8)((~XCP_SEND_PENDING) & 0xFFu);

      /* #50 Now check if there is another transmit request. If yes, send a RES or ERR (CRM) message. */
      if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus & (uint8)XCP_CRM_REQUEST) != 0 )
      {
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus &= (uint8)((~XCP_CRM_REQUEST) & 0xFFu);
        Xcp_SendCrm(XCP_CHANNEL_IDX);
      }
      else
      /* #60 Check for EV pending flag. Send a EV or SERV message. */
#if( (XCP_SEND_EVENT == STD_ON) || (XCP_SERV_TEXT == STD_ON) )
      if ( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus & (uint8)XCP_EVT_REQUEST) != 0 )
      {
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus &= (uint8)((~XCP_EVT_REQUEST) & 0xFFu);
        Xcp_Hlp_SendAsyncEvent( XCP_CHANNEL_IDX );
      }
      else
#endif
#if( XCP_DAQ == STD_ON )
      /* #70 With lowest priority: Send a DAQ message from the queue. */
      if ( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus & XCP_SESSION_DAQ) != 0 )
      {
        Xcp_Hlp_SendDtoFromQueue( XCP_CHANNEL_IDX );
      }
      else
#endif
      {
#if( XCP_BLOCK_UPLOAD == STD_ON )
        /* #80 Otherwise, if pending upload data exist: */
        if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus & XCP_SESSION_BLOCK_UPLOAD) != 0 )
        {
          uint8 cmd[2];

          cmd[0] = (uint8)XCP_CMD_UPLOAD;
          cmd[1] = (uint8)Xcp_ChannelInfo[XCP_CHANNEL_IDX].NextDataBlockSize;

          /* #90 Reset PENDING flag, execute upload command and send the frame. */
          Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus &= (uint16)((~XCP_SESSION_BLOCK_UPLOAD) & 0xFFFFu);
          Xcp_CmdStd_Upload( XCP_CHANNEL_IDX, (P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR))&cmd[0] );
          Xcp_SendCrm( XCP_CHANNEL_IDX );
        }
#endif
      }

      /* #100 Stop runtime measurement. */
      /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
      Xcp_Rtm_Stop(Xcp_TlTxConfirmation); /* PRQA S 3112 */ /* MD_MSR_14.2 */ /*lint -e{438} */

      XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
    }

    /* ----- Development Error Report --------------------------------------- */
#if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_TL_TX_CONFIRMATION, errorId );
    }
#else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  }
#if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
#endif
  /* PRQA S 6050 2 */ /* MD_MSR_STCALL */
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_TlTxConfirmation() */


/**********************************************************************************************************************
 * Xcp_Disconnect()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_Disconnect( Xcp_ChannelType XcpChannel )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = XCP_E_NO_ERROR;

#if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
#endif
  {
    /* ----- Development Error Checks ------------------------------------- */
#if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
    else if( XcpChannel >= XCP_NUMBER_OF_CHANNELS )
    {
      errorId = XCP_E_PARAM_CHANNEL;
    }
    else
#else
    XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
    {
      /* #30 Set connection state to disconnect and stop all running DAQ lists. */
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ConnectState = XCP_FALSE;

      Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus &= (uint16)((~XCP_SESSION_CONNECTED) & 0xFFFFu);

#if( XCP_DAQ == STD_ON )
      Xcp_CtrDaq_StopAllDaq( XCP_CHANNEL_IDX );
#endif
#if( XCP_SEED_KEY == STD_ON )
      /* Lock all resources */
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatus = (uint8)( XCP_RM_ALL_RESOURCES );
#endif

      /* #40 Indicate connection state change to state DISCONNECTED. */
      XcpAppl_ConStateNotification( XCP_CHANNEL_IDX, XCP_CON_STATE_DISCONNECTED );
    }

    /* ----- Development Error Report --------------------------------------- */
#if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_DISCONNECT, errorId );
    }
#else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  }
#if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
#endif
} /* Xcp_Disconnect() */


#if( XCP_SEED_KEY == STD_ON )
/**********************************************************************************************************************
 * Xcp_ModifyProtectionStatus()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) Xcp_ModifyProtectionStatus( Xcp_ChannelType XcpChannel, uint8 AndState, uint8 OrState )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 retVal = 0;
  uint8 errorId = XCP_E_NO_ERROR;

# if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
# endif
  {
    /* ----- Development Error Checks ------------------------------------- */
# if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
    else if( XcpChannel >= XCP_NUMBER_OF_CHANNELS )
    {
      errorId = XCP_E_PARAM_CHANNEL;
    }
    else if( (AndState & (uint8)((~XCP_RM_ALL_RESOURCES) & 0xFFu)) > 0 )
    {
      errorId = XCP_E_PARAM_VALUE;
    }
    else if( (OrState & (uint8)((~XCP_RM_ALL_RESOURCES) & 0xFFu)) > 0 )
    {
      errorId = XCP_E_PARAM_VALUE;
    }
    else
# else
    XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
    {
      /* Modify the protection state of Seed&Key according to application request. */
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatus = Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatus & AndState;
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatus = Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatus | OrState;

      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatusInit = Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatusInit & AndState;
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatusInit = Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatusInit | OrState;

      retVal = (Xcp_ChannelInfo[XCP_CHANNEL_IDX].ProtectionStatusInit);
    }

    /* ----- Development Error Report --------------------------------------- */
# if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_MODIFY_PROTECTION_STATE, errorId );
    }
# else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
  }
# if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
# endif

  return retVal;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_ModifyProtectionStatus */
#endif /* ( XCP_SEED_KEY == STD_ON ) */


/****************************************************************************/
/* Data Acquisition Processor                                               */
/****************************************************************************/
#if( XCP_DAQ == STD_ON )
# if( XCP_STIM == STD_ON )
/**********************************************************************************************************************
 * Xcp_StimEventStatus()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) Xcp_StimEventStatus( uint16 EventChannel, uint8 Action )
{
  uint16_least  daq;
  uint8_least   XcpChannel;
  uint8         result = XCP_NO_STIM_DATA_AVAILABLE;
  uint8         errorId = XCP_E_NO_ERROR;

#  if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
#  endif
  {
    /* ----- Development Error Checks ------------------------------------- */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
    }
    else
#  if (XCP_DEV_ERROR_DETECT == STD_ON)
    /* #20 Perform parameter plausibility checks. */
    if( EventChannel >= XCP_MAX_EVENT )
    {
      errorId = XCP_E_PARAM_EVENTCHANNEL;
    }
    else if( (Action != XCP_STIM_CHECK_ODT_BUFFER) && (Action != XCP_STIM_RESET_ODT_BUFFER) )
    {
      errorId = XCP_E_PARAM_VALUE;
    }
#   if( XCP_NUMBER_OF_CORES > 1u )
    else if( Xcp_ECcIdMapping[EventChannel].CoreId != GetCoreID() )
    {
      errorId = XCP_E_INVALID_CORE_ID;
    }
#   endif
    else
#  endif
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #30 Check for each XcpChannel if for this EventChannel STIM data is available. */
      for( XcpChannel = 0u; XcpChannel < XCP_NUMBER_OF_CHANNELS; XcpChannel++ )
      {
        if ( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus & XCP_SESSION_DAQ) == 0 )
        {
          continue; /* PRQA S 0770 */ /* MD_Xcp_0770 */
        }

        for( daq = 0u; daq < Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.nDaqLists; daq++ )
        {
          if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[daq] & XCP_DAQ_FLAG_RUNNING) == 0u )
          {
            continue; /* PRQA S 0770 */ /* MD_Xcp_0770 */
          }
          if( Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Daq2EventMapping[daq] != EventChannel )
          {
            continue; /* PRQA S 0770 */ /* MD_Xcp_0770 */
          }

          /* Is STIM enabled on this DAQ List? */
          if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].DaqList.Mode[daq] & XCP_DAQ_FLAG_DIRECTION) > 0u )
          {
            result = Xcp_Hlp_StimEventStatus(XCP_CHANNEL_IDX, daq, Action);
          }
        } /* DAQ */
      } /* XcpChannel */
    } /* DET */

    /* ----- Development Error Report --------------------------------------- */
#  if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
#   if( XCP_NUMBER_OF_CORES > 1u )
      Xcp_BswErrorId = errorId;
      Xcp_BswFctId = XCP_SID_STIM_EVENT_STATUS;
#   else
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_STIM_EVENT_STATUS, errorId );
#   endif
    }
#  else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  endif
  }
#  if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
#  endif

  return result;
  /* PRQA S 6080 4 */ /* MD_MSR_STMIF */
  /* PRQA S 6030 3 */ /* MD_MSR_STCYC */
  /* PRQA S 6010 2 */ /* MD_MSR_STPTH */
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* Xcp_StimEventStatus */
# endif /* ( XCP_STIM == STD_ON ) */


/**********************************************************************************************************************
 * Xcp_Event()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) Xcp_Event( uint16 EventChannel )
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(Xcp_ChannelStruct, AUTOMATIC, XCP_VAR_NOINIT) pXcp;
  uint16_least daq;
  uint8_least  XcpChannel;
  uint16 coreIdx;
  uint8 errorId = XCP_E_NO_ERROR;
  uint8 retVal = XCP_EVENT_NOP;


# if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
# endif
  {
    /* ----- Development Error Checks ------------------------------------- */
    if ( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
    }
    else
# if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( EventChannel >= XCP_MAX_EVENT )
    {
      errorId = XCP_E_PARAM_EVENTCHANNEL;
    }
#  if( XCP_NUMBER_OF_CORES > 1u )
    else if( Xcp_ECcIdMapping[EventChannel].CoreId != GetCoreID() )
    {
      errorId = XCP_E_INVALID_CORE_ID;
    }
#  endif
    else
# endif
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #30 Start runtime measurement. */
      /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
      Xcp_Rtm_Start(Xcp_Event); /* PRQA S 3112 */ /* MD_MSR_14.2 */ /*lint -e{438} */

      coreIdx = Xcp_ECcIdMapping[EventChannel].SendQueueCoreIdx;
      for( XcpChannel = 0; XcpChannel < XCP_NUMBER_OF_CHANNELS; XcpChannel++ )
      {
        pXcp = &Xcp_ChannelInfo[XCP_CHANNEL_IDX];

        /* #40 Check whether DAQ is running at all? If not, continue to next channel. */
        if( (pXcp->SessionStatus & XCP_SESSION_DAQ) != 0u )
        {
          for( daq = 0; daq < pXcp->DaqList.nDaqLists; daq++ )
          { /* #50 Check if current DAQ list is active and assigned to this event channel. */
            if( ((pXcp->DaqList.Mode[daq] & XCP_DAQ_LIST_RUNNING) != 0u ) && 
                (pXcp->DaqList.Daq2EventMapping[daq] == EventChannel)
              )
            {
              /* #60 Decrement prescaler and check if it is expired. If it is expired, reset to initial state and assemble DAQ list. */
              pXcp->DaqList.DaqPrescalerCnt[daq]--;
              if( pXcp->DaqList.DaqPrescalerCnt[daq] == 0u )
              { /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                pXcp->DaqList.DaqPrescalerCnt[daq] = pXcp->DaqList.DaqPrescaler[daq];

# if( XCP_STIM == STD_ON )
                /* #70 Check if STIM is enabled on this DAQ List? Call EventStim in that case. */
                if( (pXcp->DaqList.Mode[daq] & XCP_DAQ_FLAG_DIRECTION) > 0u )
                { /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                  retVal |= Xcp_Hlp_EventStim(XCP_CHANNEL_IDX, pXcp, daq);
                }
                else
# endif
                /* #80 Otherwise call EventDaq to assemble DAQ list. */
                { /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                  retVal |= Xcp_Hlp_EventDaq(XCP_CHANNEL_IDX, coreIdx, pXcp, daq);
                }
              }
            }
          }
        }
      }

      /* #90 Stop runtime measurement. */
      /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
      Xcp_Rtm_Stop(Xcp_Event); /* PRQA S 3112 */ /* MD_MSR_14.2 */ /*lint -e{438} */
    }
  
    /* ----- Development Error Report --------------------------------------- */
# if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
#  if( XCP_NUMBER_OF_CORES > 1u )
      Xcp_BswErrorId = errorId;
      Xcp_BswFctId = XCP_SID_EVENT;
#  else
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_EVENT, errorId );
#  endif
    }
# else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
  }
# if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
# endif

  return retVal;
  /* PRQA S 6030 2 */ /* MD_MSR_STCYC */
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_Event */ 
#endif /* ( XCP_DAQ == STD_ON ) */


/**********************************************************************************************************************
 *  Xcp_SendCrm()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_SendCrm( Xcp_ChannelType XcpChannel )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = XCP_E_NO_ERROR;

#if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
#endif
  {
    /* ----- Development Error Checks ------------------------------------- */
#if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
    else if( XcpChannel >= XCP_NUMBER_OF_CHANNELS )
    {
      errorId = XCP_E_PARAM_CHANNEL;
    }
    else
#else
    XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
    {
      /* ----- Implementation ----------------------------------------------- */
      Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponsePending = XCP_FALSE;
      /* #30 If a former transmission is pending:
       *       And this happend for the second time, indicate an error.
       *       Remember transmission request for next sending. 
       */
      if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus & (uint8)XCP_SEND_PENDING) != 0 )
      {
        if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus & (uint8)XCP_CRM_REQUEST) != 0 )
        {
          Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus |= (uint16)XCP_SESSION_ERROR;
        }
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus |= (uint8)XCP_CRM_REQUEST;
      }
      /* #60 Otherwise, remember pending request for next confirmation and send it. */
      else
      {
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].SendStatus |= (uint8)XCP_CRM_PENDING;

        (void)Xcp_CallTlFunction_3_Param( XCP_CHANNEL_IDX,
                                          XcpTl_Send,
                                          Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength,
                                          &Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[0] );
      }

      Xcp_CallTlFunction_2_Param( XCP_CHANNEL_IDX, XcpTl_SendFlush, XCP_FLUSH_CTO );
    }

    /* ----- Development Error Report --------------------------------------- */
#if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_SEND_CRM, errorId );
    }
#else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  }
#if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
#endif
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_SendCrm */


#if( XCP_SEND_EVENT == STD_ON )
/**********************************************************************************************************************
 *  Xcp_SendEvent()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_SendEvent( Xcp_ChannelType XcpChannel,
                                    uint8 EventCode,
                                    P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) EventData,
                                    uint8 Length )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least i;
  uint8 errorId = XCP_E_NO_ERROR;
  boolean eventFrameIsFree;

# if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
# endif
  {
    /* ----- Development Error Checks ------------------------------------- */
# if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
    else if( XcpChannel >= XCP_NUMBER_OF_CHANNELS )
    {
      errorId = XCP_E_PARAM_CHANNEL;
    }
    else if( XCP_SENDEVENT_CHECK_EVENTCODE(EventCode) )
    {
      errorId = XCP_E_PARAM_VALUE;
    }
    else if( EventData == NULL_PTR )
    {
      errorId = XCP_E_PARAM_POINTER;
    }
    else
# else
    XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
    {
      eventFrameIsFree = Xcp_Hlp_OccurredPendingTxConfirmation( XCP_CHANNEL_IDX );

      /* #30 If there is no pending TxConfirmation and the specified message length is valid,
       *     send the next EventFrame. */
      if( eventFrameIsFree == TRUE )
      {
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrame.b[0] = XCP_PID_EV; /* Event ID */
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrame.b[1] = EventCode; /* Event ID */
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrameLength = XCP_SENDEVENT_INITIAL_LENGTH;

        if( Length <= (uint8)XCP_SENDEVENT_MAX_LENGTH(XCP_CHANNEL_IDX) )
        {
          for( i = 0; i < Length; i++ )
          {
            Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrame.b[Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrameLength] = (uint8)EventData[i];
            Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrameLength++;
          } 
        }
        else
        {
          errorId = XCP_E_PARAM_VALUE;
        }

        Xcp_Hlp_SendAsyncEvent( XCP_CHANNEL_IDX );
      }
    }

    /* ----- Development Error Report --------------------------------------- */
# if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_SEND_EVENT, errorId );
    }
# else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
  }
# if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
# endif
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_SendEvent */
#endif /* ( XCP_SEND_EVENT == STD_ON ) */


#if( XCP_SERV_TEXT == STD_ON )
/**********************************************************************************************************************
 * Xcp_PutChar()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_PutChar( Xcp_ChannelType XcpChannel, CONST(uint8, AUTOMATIC) Character )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = XCP_E_NO_ERROR;
  boolean eventFrameIsFree;

# if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
# endif
  {
    /* ----- Development Error Checks ------------------------------------- */
# if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
    else if( XcpChannel >= XCP_NUMBER_OF_CHANNELS )
    {
      errorId = XCP_E_PARAM_CHANNEL;
    }
    else
# else
    XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
    {
      /* #30 If a TxConfirmation is pending, wait until it occurs.
       *     The application has the possibility to reject the message and stop the waiting. */
      eventFrameIsFree = Xcp_Hlp_OccurredPendingTxConfirmation( XCP_CHANNEL_IDX );

      /* #40 If there is no pending TxConfirmation, write the next character to the EventFrame. */
      if( eventFrameIsFree == TRUE )
      {
        if( Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrameLength < 2 )
        {
          Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrameLength = 2;
        }

        Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrame.b[Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrameLength] = Character;
        Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrameLength++;

        /* #50 If a terminating 0x00 is written to EventFrame or MaxCto is reached, send the EventFrame. */
        if( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrameLength >= (uint8)Xcp_ChannelInfo[XCP_CHANNEL_IDX].MaxCto) 
         || (Character == 0x00u) )
        {
          Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrame.b[0] = 0xFC; /* SERV */
          Xcp_ChannelInfo[XCP_CHANNEL_IDX].EventFrame.b[1] = 0x01; /* SERV_TEXT*/
          Xcp_Hlp_SendAsyncEvent( XCP_CHANNEL_IDX );
        }
      }
    }

    /* ----- Development Error Report --------------------------------------- */
# if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_PUT_CHAR, errorId );
    }
# else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
  }
# if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
# endif
} /* Xcp_PutChar */


/**********************************************************************************************************************
 * Xcp_Print()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_Print( Xcp_ChannelType XcpChannel, P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) Str )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = XCP_E_NO_ERROR;
  uint8_least i;

# if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
# endif
  {
    /* ----- Development Error Checks ------------------------------------- */
# if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
    else if( XcpChannel >= XCP_NUMBER_OF_CHANNELS )
    {
      errorId = XCP_E_PARAM_CHANNEL;
    }
    else if( Str == NULL_PTR )
    {
      errorId = XCP_E_PARAM_POINTER;
    }
    else
# else
    XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
    {
      /* #30 Transmit the text message. Keep string length in mind as this is blocking
       *     (if longer than Max DTO - 2, busy waiting for TxConfirmation). */
      for( i = 0; Str[i] != 0x00; i++  )
      {
        Xcp_PutChar( XCP_CHANNEL_IDX, (CONST(uint8, AUTOMATIC))Str[i] );
      }

      /* #40 Write terminating 0x00 which triggers the transmission. */
      Xcp_PutChar( XCP_CHANNEL_IDX, (uint8)0x00u );
    }

    /* ----- Development Error Report --------------------------------------- */
# if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_PRINT, errorId );
    }
# else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
  }
# if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
# endif
} /* Xcp_Print */
#endif /* ( XCP_SERV_TEXT == STD_ON ) */

#if( XCP_BOOTLOADER_DOWNLOAD == STD_ON )
/**********************************************************************************************************************
 * Xcp_GetXcpDataPointer()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_GetXcpDataPointer( P2VAR(Xcp_ChannelStructPtr, AUTOMATIC, XCP_APPL_DATA) pXcpData )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = XCP_E_NO_ERROR;

# if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
# endif
  {
    /* ----- Development Error Checks ------------------------------------- */
# if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
    else if( pXcpData == NULL_PTR )
    {
      errorId = XCP_E_PARAM_POINTER;
    }
    else
# endif
    {
      /* #30 Return pointer to complete XCP data (required for flash programming with a flash kernel). */
      *pXcpData = &Xcp_ChannelInfo[0];
    }
    /* ----- Development Error Report --------------------------------------- */
# if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_GET_XCP_DATA_POINTER, errorId );
    }
# else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
  }
# if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
# endif
} /* Xcp_GetXcpDataPointer */
#endif


# if( XCP_STIM == STD_ON )
/**********************************************************************************************************************
 * Xcp_SetStimMode()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_SetStimMode( uint8 mode )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = XCP_E_NO_ERROR;

# if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
# endif
  {
    /* ----- Development Error Checks ------------------------------------- */
# if( XCP_DEV_ERROR_DETECT == STD_ON )
    /* #20 Perform parameter plausibility checks and report error in failure case. */
    if( Xcp_ModuleInitialized == (uint8)XCP_UNINIT )
    {
      errorId = XCP_E_UNINIT;
    }
    else if((mode != XCP_STIM_SINGLE_SHOT_MODE) && (mode != XCP_STIM_CONTINUOUS_MODE))
    {
      errorId = XCP_E_PARAM_VALUE;
    }
    else
# endif
    /* #30 Otherwise, set Stim mode according to parameter. */
    {
      Xcp_StimMode = mode;
    }
    /* ----- Development Error Report --------------------------------------- */
# if( XCP_DEV_ERROR_REPORT == STD_ON )
    if( errorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, XCP_SID_SET_STIM_MODE, errorId );
    }
# else
    XCP_DUMMY_STATEMENT( errorId ); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
  }
# if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
# endif
} /* Xcp_SetStimMode */
#endif

/**********************************************************************************************************************
 * Xcp_MainFunction()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, XCP_CODE) Xcp_MainFunction( void )
{
  uint8_least XcpChannel;

#if( XCP_CONTROL == STD_ON )
  /* #10 Check whether XCP functionality shall be enabled. */
  if( Xcp_ControlState == kXcp_Control_Enable )
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Start runtime measurement. */
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Xcp_Rtm_Start(Xcp_MainFunction); /* PRQA S 3112 */ /* MD_MSR_14.2 */ /*lint -e{438} */

    /* #30 If XCP is initialized:
     *       Check for each XcpChannel: */
    if( Xcp_ModuleInitialized == (uint8)XCP_INIT )
    {
      for( XcpChannel = 0; XcpChannel < XCP_NUMBER_OF_CHANNELS; XcpChannel++ )
      {
#if( XCP_DAQ == STD_ON )
        /* #40 Whether a DTO frame is pending to transmit it. */
        Xcp_Hlp_SendDtoFromQueue( (Xcp_ChannelType)XCP_CHANNEL_IDX );

        /* #50 Whether a flag to trigger Resume Mode handling is set, then call the corresponding XcpAppl call-back. */
# if( XCP_DAQ_RESUME == STD_ON )
        if ( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus & (uint16)XCP_SESSION_STORE_DAQ_REQ_RESUME) != 0 )
        {
          Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus &= (uint16)((~XCP_SESSION_STORE_DAQ_REQ_RESUME) & 0xFFFFu);
          XcpAppl_DaqResumeStore( (Xcp_ChannelType)XCP_CHANNEL_IDX, (P2CONST(Xcp_ChannelStruct, AUTOMATIC, XCP_APPL_DATA))&Xcp_ChannelInfo[XCP_CHANNEL_IDX], TRUE /* Resume after init. */ );
        }
        else
        if ( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus & (uint16)XCP_SESSION_STORE_DAQ_REQ_NO_RESUME) != 0 )
        {
          Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus &= (uint16)((~XCP_SESSION_STORE_DAQ_REQ_NO_RESUME) & 0xFFFFu);
          XcpAppl_DaqResumeStore( (Xcp_ChannelType)XCP_CHANNEL_IDX, (P2CONST(Xcp_ChannelStruct, AUTOMATIC, XCP_APPL_DATA))&Xcp_ChannelInfo[XCP_CHANNEL_IDX], FALSE /* Not resume after init. */ );
        }
        else
        if ( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus & (uint16)XCP_SESSION_CLEAR_DAQ_REQ) != 0 )
        {
          Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus &= (uint16)((~XCP_SESSION_CLEAR_DAQ_REQ) & 0xFFFFu);
          XcpAppl_DaqResumeClear( (Xcp_ChannelType)XCP_CHANNEL_IDX );
          Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionConfigId = 0;
        }
        else
# endif
#endif
#if( XCP_PAGE_FREEZE == STD_ON )
        /* #60 Whether the persisting of calibration page was requested, then call the corresponding XcpAppl call-back. */
        if ( (Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus & (uint16)XCP_SESSION_STORE_CAL_REQ) != 0 )
        {
          if( XcpAppl_CalResumeStore( (Xcp_ChannelType)XCP_CHANNEL_IDX ) == TRUE )
          {
            Xcp_ChannelInfo[XCP_CHANNEL_IDX].SessionStatus &= (uint16)((~XCP_SESSION_STORE_CAL_REQ) & 0xFFFFu);
          }
        }
        else
#endif
        {
          /* Do nothing. */
        }
      }

#if( (XCP_CHECKSUM == STD_ON) && (XCP_CUSTOM_CRC == STD_OFF) )
      /* #70 Calculate pending checksum, if calculation is finished transmit the result. */
      Xcp_Hlp_CalcAndSendChecksumResult();
#endif
    }
    /* XCP is not initialized. */

    /* #80 Stop runtime measurement. */
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Xcp_Rtm_Stop(Xcp_MainFunction); /* PRQA S 3112 */ /* MD_MSR_14.2 */ /*lint -e{438} */

#if( XCP_DEV_ERROR_REPORT == STD_ON ) && ( XCP_NUMBER_OF_CORES > 1u )
    /* #90 Perform parameter plausibility checks. */
    if( Xcp_BswErrorId != XCP_E_NO_ERROR )
    {
      (void)Det_ReportError( XCP_MODULE_ID, XCP_INSTANCE_ID_DET, Xcp_BswFctId, Xcp_BswErrorId );
      Xcp_BswErrorId = XCP_E_NO_ERROR;
    }
#endif
  }
#if( XCP_CONTROL == STD_ON )
  else
  {
    Xcp_ControlDeniedCount++;
  }
#endif
  /* PRQA S 6030 3 */ /* MD_MSR_STCYC */
  /* PRQA S 6050 2 */ /* MD_MSR_STCAL */
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Xcp_MainFunction() */


#define XCP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:

  MD_Xcp_0306: rule 11.3
      Reason:     Pointer has to be created from protocol address information. Direct access is used for better performance.
      Risk:       Maintainability reduced due to optimization.
      Prevention: Covered by code review.

  MD_Xcp_0310: rule 11.4
      Reason:     Cast to different type might result in alignment issues.
      Risk:       A trap that is caused by misalignment
      Prevention: Alignment requirement has been considered during design.

  MD_Xcp_0488: rule: 17.4
      Reason:     Determine size of structure. The size of a structure is compiler dependent. Therefore it is not possible to
                  use a generated value. The size must be determined by some pointer arithmetic.
      Risk:       None.
      Prevention: Covered by code review.

  MD_XCP_1.1_0612: rule: 1.1
      Reason:     Due to buffering of measurement data of extensive configurations, buffer sizes can exceed 32kB.
      Risk:       None.
      Prevention: Covered by code review.

  MD_Xcp_0770: rule 14.5
      Reason:     For optimization reasons more than one break or continue was used to leave the for loop.
      Risk:       Maintainability reduced due to multiple break/continue statements.
      Prevention: Covered by code review.

  MD_Xcp_0771:    Rule 14.6
      Reason:     For optimization reasons more than one break was used to leave the for loop.
      Risk:       Maintainability reduced due to multiple break statements.
      Prevention: Covered by code review.

  MD_Xcp_0883: rule 19.15
      Reason:     Precautions shall be taken in order to prevent the contents of a header file being included twice.
                  The header is protected, but QAC does not detect this protection statement.
      Risk:       No risk.
      Prevention: Not required.

  MD_Xcp_1334: rule 16.4
      Reason:     Funktion pointers to different component. The components might name their API identifiers differently.
      Risk:       Difference in API parameter size
      Prevention: Covered by code review.

  MD_Xcp_3218_FileScopeStatic:
     Reason:      Objects are RAM and ROM variables with ROM variables usually extern const tables generated use-case
                  specific.
                  Different configuration variants (RAM and ROM): There might be setups where an object is used
                  in just one function but in other setups in multiple functions.
     Risk:        Unintended use of object in wrong scope.
     Prevention:  Architectural pattern supports prevention of incorrect use of objects in wrong context.
                  Code inspection focus on correct use of objects.

  MD_Xcp_3305:
      Reason:     A uint8 pointer is cast to a uint16 pointer.
      Risk:       Misaligned access might happen.
      Prevention: It is guaranteed in code that acces is always 16bit aligned. Covered by review.

  MD_Xcp_3408: rule 8.8
      Reason:     The variable is not defined as static to be accessible for calibration or debugging.
                  No prototype is required for this.
      Risk:       Unintended use of object in wrong scope.
      Prevention: Covered by code review.

  MD_Xcp_3410: rule 19.10
      Reason:     In the definition of a function-like macro each instance of a parameter shall be enclosed in 
                  parentheses unless it is used as the operand of # or ##.
                  Required because, last parameter is used as function to be called. Cannot be enclosed in parentheses.
      Risk:       Invalid parameter leads to compiler warning/error.
      Prevention: Only called within XCP, therefore a review is sufficient.

  MD_Xcp_3689: rule 21.1
      Reason:     The parameters are always in range due to plausibility checks during DAQ configuration.
      Risk:       Invalid parameter leads to out of bounds read access.
      Prevention: Plausibility checks during DAQ configuration.
*/

/**********************************************************************************************************************
 *  END OF FILE: Xcp.c
 *********************************************************************************************************************/
