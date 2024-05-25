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
/**        \file  Xcp_Types.h
 *        \brief  XCP types header file
 *
 *      \details  Types header of the XCP protocol layer.
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

#if !defined (XCP_TYPES_H)
# define XCP_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComStack_Types.h"
# include "Xcp_Cfg.h"


/* Keyword macros */
# if !defined (STATIC)
#  define STATIC static
# endif

# if !defined (INLINE)
#  define INLINE
# endif

# if !defined (LOCAL_INLINE)
#  define LOCAL_INLINE INLINE STATIC
# endif

# if !defined (XCP_LOCAL)
#  define XCP_LOCAL STATIC
# endif

# if !defined (XCP_LOCAL_INLINE)
#  define XCP_LOCAL_INLINE LOCAL_INLINE
# endif


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* DAQ Timestamp Size */
#define XCP_DAQ_TIMESTAMP_OFF                 (0<<0)
#define XCP_DAQ_TIMESTAMP_BYTE                (1<<0)
#define XCP_DAQ_TIMESTAMP_WORD                (2<<0)
#define XCP_DAQ_TIMESTAMP_DWORD               (4<<0)
/**\} */

/*-------------------------------------------------------------------------*/
/* Checksum Types (BUILD_CHECKSUM) */
#define XCP_CHECKSUM_TYPE_NONE                (0x00u)  /*!< Not supported. */
#define XCP_CHECKSUM_TYPE_ADD11               (0x01u)  /*!< Add BYTE into a BYTE checksum, ignore overflows. */
#define XCP_CHECKSUM_TYPE_ADD12               (0x02u)  /*!< Add BYTE into a WORD checksum, ignore overflows. */
#define XCP_CHECKSUM_TYPE_ADD14               (0x03u)  /*!< Add BYTE into a DWORD checksum, ignore overflows. */
#define XCP_CHECKSUM_TYPE_ADD22               (0x04u)  /*!< Add WORD into a WORD checksum, ignore overflows, blocksize must be modulo 2. */
#define XCP_CHECKSUM_TYPE_ADD24               (0x05u)  /*!< Add WORD into a DWORD checksum, ignore overflows, blocksize must be modulo 2. */ 
#define XCP_CHECKSUM_TYPE_ADD44               (0x06u)  /*!< Add DWORD into DWORD, ignore overflows, blocksize must be modulo 4. */
#define XCP_CHECKSUM_TYPE_CRC16               (0x07u)  /*!< See CRC error detection algorithms. */
#define XCP_CHECKSUM_TYPE_CRC16CITT           (0x08u)  /*!< See CRC error detection algorithms. */
#define XCP_CHECKSUM_TYPE_CRC32               (0x09u)  /*!< See CRC error detection algorithms. */
#define XCP_CHECKSUM_TYPE_DLL                 (0xFFu)  /*!< User defined, ASAM MCD 2MC DLL Interface. */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if( XCP_CANOE_EMU == STD_ON )
typedef uint64 Xcp_AddressPtrType; /*<! An pointer as integer */
#else
typedef uint32 Xcp_AddressPtrType; /*<! An pointer as integer */
#endif

#if( XCP_MAX_ODT_ENTRIES < 256 )
typedef uint8 Xcp_OdtEntryIdxType; /*<! index in ODT Entry table */
#else
typedef uint16 Xcp_OdtEntryIdxType; /*<! index in ODT Entry table */
#endif

typedef uint16 Xcp_OdtIdxType; /*<! index in ODT table */
typedef uint8  Xcp_ChannelType; /*<! XCP channel index type */


typedef struct
{
  P2FUNC(void, XCP_CODE, XcpTl_Send)( Xcp_ChannelType XcpChannel, uint8 len, P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) msg );
  P2FUNC(void, XCP_CODE, XcpTl_SendFlush)( Xcp_ChannelType XcpChannel, uint8 FlushType );
  P2FUNC(uint8, XCP_CODE, XcpTl_TlService)( Xcp_ChannelType XcpChannel, P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) pCmd );
} Xcp_TlApiType;


typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  uint8     b[XCP_MAX_CTO_MAX];
  uint16    w[XCP_MAX_CTO_MAX/2];
  uint32    l[XCP_MAX_CTO_MAX/4];
} Xcp_AlignedCTOFrameType;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  uint8     b[XCP_MAX_DTO_MAX];
  uint16    w[XCP_MAX_DTO_MAX/2];
  uint32    l[XCP_MAX_DTO_MAX/4];
} Xcp_AlignedDTOFrameType;

# if ( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_OFF )
typedef uint8 Xcp_TimestampType; /*<! Timestamp used during DAQ measurement */
# elif ( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_BYTE )
typedef uint8 Xcp_TimestampType; /*<! Timestamp used during DAQ measurement */
# elif ( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_WORD )
typedef uint16 Xcp_TimestampType; /*<! Timestamp used during DAQ measurement */
# elif ( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_DWORD )
typedef uint32 Xcp_TimestampType; /*<! Timestamp used during DAQ measurement */
# else
#  error "Please define a valid timestamp size. Valid sizes are 0, 1, 2 and 4 Bytes"
# endif

#if ( XCP_DAQ == STD_ON )
typedef struct {
  uint8 b[XCP_MAX_DTO_MAX];
  uint8 l;
} tXcpDtouS;

typedef union { /* PRQA S 0750 */ /* MD_MSR_18.4 */
  tXcpDtouS buffer;
  uint16 w[ ((XCP_MAX_DTO_MAX + 3) & 0xFFFC) / 2  ];
  uint32 dw[ ((XCP_MAX_DTO_MAX + 3) & 0xFFFC) / 4 ];
} tXcpDto;

typedef struct
{
  uint16 SendQueueCoreIdx; /*<! The index of the Send Queue related to the Event Channel */
  uint16 CoreId; /*<! The CoreId as reported by the OS related to the Event Channel */
} Xcp_ECcIDType;

typedef struct
{
  /* DAQ lists */
  Xcp_OdtIdxType      FirstOdt[XCP_MAX_DAQ]; /*<! The first ODT of an DAQ list */
  Xcp_OdtEntryIdxType FirstOdtEntry[XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM]; /*<! The first Entry of and ODT */
  uint8               nOdtsDaq[XCP_MAX_DAQ]; /*<! The number of ODTs per DAQ list */
  uint8               nOdtEntriesOdt[XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM]; /*<! The number of ODT Entries per DAQ */
  /* STIM buffer reference */
# if ( XCP_STIM == STD_ON )
  P2VAR(tXcpDto, AUTOMATIC, XCP_VAR_NOINIT) pStimBuffer[XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM]; /*<! A pointer to the assigned STIM DTO buffer */
# endif
  /* Configurable event */
  uint16              Daq2EventMapping[XCP_MAX_DAQ]; /*<! A Mapping of the used Event Channel for each DAQ list */
  /* ODT entries list */
  Xcp_AddressPtrType  OdtEntries[XCP_MAX_ODT_ENTRIES]; /*<! All the ODT Entries there are */
  uint8               OdtEntriesSize[XCP_MAX_ODT_ENTRIES]; /*<! All the ODT Entry sizes there are */
  /* DAQ list state */
  uint8               Mode[XCP_MAX_DAQ]; /*<! The mode of the DAQ list */
  uint8               DaqStatus[XCP_MAX_DAQ]; /*<! The state of the DAQ list */
  /* Prescaler */
  uint8               DaqPrescaler[XCP_MAX_DAQ]; /*<! The prescaler for each DAQ list - initial value */
  uint8               DaqPrescalerCnt[XCP_MAX_DAQ]; /*<! The prescaler for each DAQ list - counter value */
  /* Parameter check */
  uint16              nDaqLists; /*<! The number of DAQ lists there are */
  uint16              nOdts; /*<! The number of ODTs there are */
  uint16              nOdtEntries; /*<! The number of ODT Entries there are */
  Xcp_OdtEntryIdxType odtEntryIdx; /*<! Index of the currently active Entry */
} Xcp_DaqListType;
#endif


#if( XCP_CHECKSUM == STD_ON )
# if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD11 )
  typedef uint8 tXcpChecksumType; /* tXcpChecksumType */
#  define tXcpChecksumTypeMask  0xFF
# elif ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD12 ) || \
       ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD22 ) || \
       ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16 ) || \
       ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_CRC16CITT )
  typedef uint16 tXcpChecksumType; /*<! The size of the resulting checksum */
#  define tXcpChecksumTypeMask  0xFFFF
# else
  typedef uint32 tXcpChecksumType; /*<! The size of the resulting checksum */
#  define tXcpChecksumTypeMask  0xFFFFFFFF
# endif
#endif


typedef struct
{
#if( XCP_CHECKSUM == STD_ON )
  tXcpChecksumType CheckSum; /*<! The checksum intermediate result */
#endif
#if ( XCP_DAQ == STD_ON )
  Xcp_DaqListType DaqList; /*<! the complete DAQ list information */
  uint16 SessionConfigId; /*<! The session configuration id */
#endif
  /* The following 3 variable are moved here, because they are relevant in Resume Mode */
  uint16 MaxDto; /*<! The currently active MaxDto, dependent on active TL */
  uint8  MaxCto; /*<! The currently active MaxCto, dependent on active TL */
  uint8  ActiveTl; /*<! The currently active TL */
  /* --- The following variables are not relevant for Resume Mode --- */
  Xcp_AlignedCTOFrameType ResponseFrame; /*<! The response frame buffer */
  Xcp_AddressPtrType MTA; /*<! The MTA (memory transfer address) */
#if( XCP_CHECKSUM == STD_ON )
  uint16 CheckSumSize; /*<! The size of the checksum block */
#endif
  uint16 SessionStatus;
  uint8  MTAExtension; /*<! The address extension of the MTA */
  uint8  ResponseFrameLength; /*<! The length of the response frame string */
  uint8  ResponsePending; /*<! true in case a response is pending and triggered asynchronously */
  uint8  ConnectState; /*<! The current connection state */
#if ( XCP_SEED_KEY == STD_ON )
  uint8  ProtectionStatus; /*!< Resource Protection Status */
  uint8  ProtectionStatusInit; /*<! Initial Resource Protection Status */
#endif
#if( (XCP_BLOCK_UPLOAD == STD_ON) || (XCP_BLOCK_DOWNLOAD == STD_ON) )
  uint8  NextDataBlockSize; /*<! The intermediate block size used during block transfer */
#endif
#if( (XCP_SEND_EVENT == STD_ON) || (XCP_SERV_TEXT == STD_ON) )
  Xcp_AlignedCTOFrameType EventFrame;       /*<! EV,SERV Message buffer */
  uint8                   EventFrameLength; /*<! EV,SERV Message length */
#endif
  uint8  SendStatus; /*<! Status variable of transmission, must be last element. */
} Xcp_ChannelStruct;

typedef P2VAR(Xcp_ChannelStruct, TYPEDEF, XCP_APPL_DATA) Xcp_ChannelStructPtr;

#endif /* XCP_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Xcp_Types.h
 *********************************************************************************************************************/
