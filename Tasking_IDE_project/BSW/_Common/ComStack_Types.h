/*********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2013 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  ComStack_Types.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Provision of Comunication Stack Types
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *      
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik GmbH
 *  Gunnar Meiss                  Ms            Vector Informatik GmbH
 *  Heike Honert                  Ht            Vector Informatik GmbH
 *  Eugen Stripling               Seu           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  03.00.00  2007-09-14  Jk                    Addaption for AUTOSAR 3.0 / NetworkHandleType added
 *  03.00.01  2007-11-20  Jk                    Version defines for CFG management added
 *  03.01.00  2008-03-18  Jk                    Version defines changed to specification version
 *  03.01.01  2008-04-18  Ms      ESCAN00026158 Support more than 255 Pdus per component
 *                        Ms      ESCAN00026165 COMSTACKTYPE_VENDOR_ID
 *                        Ms      ESCAN00028208 Remove non ISO-5.2.1 Characters
 *  03.02.00  2008-07-16  Jk                    BUSTRCV_E_OK added (specification inconsistency ComStackTypes <-> FrTrcv)
 *  03.02.01  2008-10-30  Lo                    Fixed COMSTACKTYPE_AR_MAJOR_VERSION
 *  03.02.02  2009-06-15  Ht      ESCAN00035189 Compiler Error due to storage qualifier used in struct definition             
 *  03.03.00  2010-03-23  Ht      ESCAN00041756 support TPParameterType
 *  03.03.01  2010-05-11  Ht      ESCAN00042906 correct version defines COMMONASR__COMMON_IMPL_COMSTACKTYPES..
 *  03.04.00  2011-03-04  Ht                    support ASR 4.0R1
 *  03.04.01  2011-02-28  visht   ESCAN00049578 incorrect BSW version scan information
 *  03.04.02  2011-04-15  visht                 support TP_NORETRY for TpDataStateType (used in CANTP and PDURouter) 
 *  04.00.00  2012-07-19  visht   ESCAN00058421 support ASR 4.0 R3 (support TPParameterType as enum, include generated ComStack_Cfg.h)
 *  04.00.01  2012-08-31  visht                 version define corrected - replace PATCH by REVISION - (COMSTACKTYPE_AR_RELEASE_REVISION_VERSION, COMSTACKTYPE_AR_RELEASE_REVISION_VERSION)
 *            2012-10-23  visseu                Add COMSTACKTYPE_MODULE_ID as specified in "AUTOSAR_TR_BSWModuleList.pdf" (R4.0 Rev 3)
 *  04.00.02  2013-01-10  visseu                MISRA deviation comments added
 *  04.00.03  2013-05-29  visseu  ESCAN00067745 Add general defines with prefix: COMTYPE
 *********************************************************************************************************************/

#ifndef COMSTACK_TYPES_H
# define COMSTACK_TYPES_H

/* PRQA S 3453 COMSTACK_TYPES_3453_TAG */ /* MD_MSR_19.7 */
/* PRQA S 0850 COMSTACK_TYPES_0850_TAG */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "Std_Types.h"

#  include "ComStack_Cfg.h" 
 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : CommonAsr__Common CQComponent : Impl_ComStackTypes */
# define COMMONASR__COMMON_IMPL_COMSTACKTYPES_VERSION 0x0400
# define COMMONASR__COMMON_IMPL_COMSTACKTYPES_RELEASE_VERSION 0x03
 
/* AUTOSAR Software Specification Version Information */
/*  AUTOSAR release 4.0 R3 */
#     define COMSTACKTYPE_AR_RELEASE_MAJOR_VERSION      (4u)
#     define COMSTACKTYPE_AR_RELEASE_MINOR_VERSION      (0u)
#     define COMSTACKTYPE_AR_RELEASE_REVISION_VERSION   (3u)

# if defined COMSTACKTYPE_AR_RELEASE_REVISION_VERSION
#   define COMSTACKTYPE_AR_RELEASE_PATCH_VERSION   COMSTACKTYPE_AR_RELEASE_REVISION_VERSION
/* ESCAN00067745 */
#   define COMTYPE_AR_RELEASE_MAJOR_VERSION        COMSTACKTYPE_AR_RELEASE_MAJOR_VERSION
#   define COMTYPE_AR_RELEASE_MINOR_VERSION        COMSTACKTYPE_AR_RELEASE_MINOR_VERSION
#   define COMTYPE_AR_RELEASE_REVISION_VERSION     COMSTACKTYPE_AR_RELEASE_REVISION_VERSION
#   define COMTYPE_AR_RELEASE_PATCH_VERSION        COMSTACKTYPE_AR_RELEASE_REVISION_VERSION
# endif


/* Component Version Information */
# define COMSTACKTYPE_SW_MAJOR_VERSION       (4u)
# define COMSTACKTYPE_SW_MINOR_VERSION       (0u)
# define COMSTACKTYPE_SW_PATCH_VERSION       (3u)

/* ESCAN00067745 */
# define COMTYPE_SW_MAJOR_VERSION            COMSTACKTYPE_SW_MAJOR_VERSION
# define COMTYPE_SW_MINOR_VERSION            COMSTACKTYPE_SW_MINOR_VERSION
# define COMTYPE_SW_PATCH_VERSION            COMSTACKTYPE_SW_PATCH_VERSION

# define COMSTACKTYPE_VENDOR_ID              (30u)  /* SREQ00015385, SREQ00015364, SREQ00015372 */
# define COMSTACKTYPE_MODULE_ID              (196u) /* SREQ00015385, SREQ00015364, SREQ00015372 */

/* ESCAN00067745 */
# define COMTYPE_VENDOR_ID                   COMSTACKTYPE_VENDOR_ID
# define COMTYPE_MODULE_ID                   COMSTACKTYPE_MODULE_ID

/*General return codes for NotifResultType*/
 
# define NTFRSLT_OK                        0x00  /*Action has been successfully finished:
                                                          - message sent out (in case of confirmation),
                                                          - message received (in case of indication) */
# define NTFRSLT_E_NOT_OK                  0x01  /*Error notification:
                                                          - message not successfully sent out (in case of confirmation),
                                                          - message not successfully received (in case of indication) */
# define NTFRSLT_E_TIMEOUT_A               0x02  /*Error notification:
                                                          - timer N_Ar/N_As (according to ISO specification [ISONM]) has passed its time-out value N_Asmax/N_Armax.
                                                       This value can be issued to service user on both the sender and receiver side. */
# define NTFRSLT_E_TIMEOUT_BS              0x03  /*Error notification:
                                                          - timer N_Bs has passed its time-out value N_Bsmax (according to ISO specification [ISONM]).
                                                       This value can be issued to the service user on the sender side only. */
# define NTFRSLT_E_TIMEOUT_CR              0x04  /*Error notification:
                                                          - timer N_Cr has passed its time-out value N_Crmax.
                                                       This value can be issued to the service user on the receiver side only. */
# define NTFRSLT_E_WRONG_SN                0x05  /*Error notification:
                                                          - unexpected sequence number (PCI.SN) value received.
                                                       This value can be issued to the service user on the receiver side only. */
# define NTFRSLT_E_INVALID_FS              0x06  /*Error notification:
                                                          - invalid or unknown FlowStatus value has been received in a flow control (FC) N_PDU.
                                                       This value can be issued to the service user on the sender side only. */
# define NTFRSLT_E_UNEXP_PDU               0x07  /*Error notification:
                                                          - unexpected protocol data unit received.
                                                       This value can be issued to the service user on both the sender and receiver side. */
# define NTFRSLT_E_WFT_OVRN                0x08  /*Error notification:
                                                          - flow control WAIT frame that exceeds the maximum counter N_WFTmax received.
                                                       This value can be issued to the service user on the receiver side. */

#  define NTFRSLT_E_ABORT                  0x09  /*Error notification:
                                                          - Flow control (FC) N_PDU with FlowStatus = ABORT received.
                                                            It indicates an abort of a transmission. A possible reason for this is that the receiver is currently busy and
                                                            can not take the request at that point in time. */
#  define NTFRSLT_E_NO_BUFFER              0x0A  /*Error notification:
                                                          - flow control (FC) N_PDU with FlowStatus = OVFLW received. 
                                                            It indicates that the buffer on the receiver side of a segmented message transmission
                                                            cannot store the number of bytes specified by the FirstFrame DataLength (FF_DL) parameter
                                                            in the FirstFrame and therefore the transmission of the 19 of 23 AUTOSAR_SWS_ComStackTypes
                                                            segmented message was aborted.
                                                          - no buffer within the TP available to transmit the segmented I-PDU.
                                                        This value can be issued to the service user on both the sender and receiver side. */
#  define NTFRSLT_E_CANCELATION_OK         0x0B  /*Action has been successfully finished:
                                                          - Requested cancellation has been executed.*/
#  define NTFRSLT_E_CANCELATION_NOT_OK     0x0C  /*Error notification:
                                                          - Due to an internal error the requested cancelation has not been executed. This will happen e.g., if the to be canceled transmission has been executed already.*/


/* extension since R4.0 R1 */
# define NTFRSLT_PARAMETER_OK              0x0D     /* The parameter change request has been successfully executed */
# define NTFRSLT_E_PARAMETER_NOT_OK        0x0E     /* The request for the change of the parameter did not complete successfully */
# define NTFRSLT_E_RX_ON                   0x0F     /* The parameter change request not executed successfully due to an ongoing reception */
# define NTFRSLT_E_VALUE_NOT_OK            0x10     /* The parameter change request not executed successfully due to a wrong value */

/* 0x11-0x1E Reserved values for future usage. */


/*General return codes for BusTrcvErrorType*/
# define BUSTRCV_OK         0x00
/*BUSTRCV_E_OK needed by FrTrcv specification inconcistency between ComStackTypes and FrTrcv*/
# define BUSTRCV_E_OK       0x00
# define BUSTRCV_E_ERROR    0x01



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef  P2VAR(uint8, TYPEDEF, AUTOSAR_COMSTACKDATA) SduDataPtrType;
typedef struct
{
  SduDataPtrType SduDataPtr;
  PduLengthType SduLength;
} PduInfoType;

typedef enum                          
{
  BUFREQ_OK,           /*Buffer request accomplished successful.*/
  BUFREQ_E_NOT_OK,     /*Buffer request not successful. Buffer cannot be accessed.*/
  BUFREQ_E_BUSY,       /*Temporarily no buffer available. It's up the requestor to retry request for a certain time.*/
  BUFREQ_E_OVFL        /*No Buffer of the required length can be provided.*/
} BufReq_ReturnType;

typedef uint8        NotifResultType;
 
typedef uint8        BusTrcvErrorType;

typedef uint8        NetworkHandleType;

typedef uint8        PNCHandleType;                 /* Neccessary for partial network */

typedef enum                          
{
  TP_DATACONF,         /* TP_DATACONF  indicates  that  all  data,  that  have been  copied  so  far,  are  confirmed  and  can  be 
                          removed  from  the  TP  buffer.  Data  copied  by  this API call are excluded and will be confirmed later. */
  TP_DATARETRY,        /* TP_DATARETRY  indicates  that  this  API  call  shall copy already copied data in order to recover from 
                          an  error.  In  this  case  TxTpDataCnt  specifies  the offset of the first byte to be copied by the API call.  */
  TP_CONFPENDING
} TpDataStateType;

typedef struct
{
  TpDataStateType TpDataState;
  PduLengthType TxTpDataCnt;
} RetryInfoType;


typedef enum
{
  TP_STMIN,           /* Separation Time  */
  TP_BS,              /* Block Size  */
  TP_BC               /* The Band width control parameter used in FlexRay transport protocol module. */
} TPParameterType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/* PRQA L:COMSTACK_TYPES_3453_TAG */
/* PRQA L:COMSTACK_TYPES_0850_TAG */
 
#endif  /* COMSTACK_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: ComStack_Types.h
 *********************************************************************************************************************/
