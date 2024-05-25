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
/**        \file  XcpAppl.h
 *        \brief  XCP Template header file
 *
 *      \details  Template component to demonstrate the usage of XCP application call-backs.
 *                This file can be customized to the users needs.
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

/* PRQA S 883 EOF */ /* MD_Xcp_TemplateCode */

#if !defined (XCPAPPL_H)
# define XCPAPPL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Xcp_Cfg.h"
#include "Xcp.h"
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Freeze Mode */
#define XCPAPPL_FREEZE_MODE_DISABLE      (0U)
#define XCPAPPL_FREEZE_MODE_ENABLE       (1U)

#define XCPAPPL_CAL_PAGE_SIZE            (20U)

/* Seed Key */
#define XCPAPPL_SEED_KEY_CAL_PAGE        (0U)
#define XCPAPPL_SEED_KEY_DAQ             (1U)
#define XCPAPPL_SEED_KEY_STIM            (2U)
#define XCPAPPL_SEED_KEY_PGM             (3U)

# if( XCP_GET_ID_GENERIC == STD_ON )
#define XCPAPPL_ASCII_STRING_LENGTH      (0x0Au)
#define XCPAPPL_MAP_NAME_LENGTH          (0x08u)
# endif

#define XCPAPPL_RESUME_NVMEMORY_SIZE     (sizeof(Xcp_ChannelStruct))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if( XCP_CALIBRATION_PAGE == STD_ON )
typedef struct
{
  uint8 CalPages[XCP_MAX_PAGES][XCPAPPL_CAL_PAGE_SIZE];
  uint8 ActiveCalPage;
# if( XCP_PAGE_FREEZE == STD_ON )
  uint8 CalPageSegmentMode;
# endif
} XcpAppl_CalPageType;
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/* CONSTANTS */
# if( XCP_GET_ID_GENERIC == STD_ON )
extern const uint8 XcpAppl_AsciiString[11];
extern const uint8 XcpAppl_MapName[9];
# endif


#define XCP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_Xcp_TemplateCode */

/* VARIABLES */
/* From Xcp */

# if( XCP_CALIBRATION_PAGE == STD_ON )
extern VAR(XcpAppl_CalPageType, XCP_VAR_NOINIT) XcpAppl_CalPageInfo[XCP_MAX_SEGMENT];
# endif

/* To Test */
# if( (XCP_PROGRAM == STD_ON) || (XCP_BOOTLOADER_DOWNLOAD == STD_ON) )
/* Indicates whether programming was already started. If not started, some Programming Commands are disabled. */
extern VAR(uint8, XCP_VAR_INIT) XcpAppl_ProgramStartFlag;
# endif
extern VAR(Xcp_TimestampType, XCP_VAR_INIT) XcpAppl_Timestamp;
extern VAR(uint8, XCP_VAR_NOINIT) XcpAppl_StimulationFromTscTest;

#if( XCP_DAQ == STD_ON )
# if( XCP_DAQ_RESUME == STD_ON)
extern VAR(uint8, XCP_VAR_NOINIT)  XcpAppl_MeasurementStart;
# endif /* ( XCP_DAQ_RESUME == STD_ON) */
#endif /* ( XCP_DAQ == STD_ON ) */

#if( XCP_PAGE_FREEZE == STD_ON ) || ( XCP_DAQ_RESUME == STD_ON)
extern VAR(uint8, XCP_VAR_NOINIT)  XcpAppl_ResumeNVMemory[XCP_NUMBER_OF_CHANNELS][XCPAPPL_RESUME_NVMEMORY_SIZE];
extern VAR(uint16, XCP_VAR_NOINIT) XcpAppl_ResumeSize[XCP_NUMBER_OF_CHANNELS];
#endif

extern VAR(uint8, XCP_VAR_NOINIT)  XcpAppl_ConnectionState[XCP_NUMBER_OF_CHANNELS];

extern VAR(uint32, XCP_VAR_NOINIT) XcpAppl_FrConfigParameter[XCP_NUMBER_OF_CHANNELS];

#define XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_Xcp_TemplateCode */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define XCP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_Xcp_TemplateCode */

/* GENERIC */
# if( XCP_DAQ_TIMESTAMP_SIZE > 0 )
/**********************************************************************************************************************
 *  XcpAppl_GetTimestamp()
 *********************************************************************************************************************/
/*! \brief       Returns the current timestamp.
 *  \details     Returns the current timestamp.
 *  \return      Xcp_TimestampType   The timestamp which is either uint8, uint16 or uint32, depending on configuration.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \config      Available only if XCP_DAQ_TIMESTAMP_SIZE greater 0.
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(Xcp_TimestampType, XCP_CODE)   XcpAppl_GetTimestamp(void);
# endif

/**********************************************************************************************************************
 *  XcpAppl_MemCpy()
 *********************************************************************************************************************/
/*! \brief       Copies data from Src to Dst.
 *  \details     Copies data from Src to Dst.
 *  \param[in]   Dst                 Pointer to target to copy data to.
 *  \param[in]   Src                 Pointer to source to copy data from.
 *  \param[in]   Size                Length of data to copy.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE)               XcpAppl_MemCpy( P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR) Dst,
                                                          P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) Src,
                                                          uint16 Size );

/**********************************************************************************************************************
 *  XcpAppl_MeasurementRead()
 *********************************************************************************************************************/
/*! \brief       Copies data from Src to Dst.
 *  \details     Copy n bytes from Src to Dst with the largest possible basic data type to ensure data consistency while reading. 
 *               A maximum of 255 Bytes can be copied at once.
 *               Optimizations are possible depending on the used platform:
 *               * XCP_PREVENT_SRC_READ_TRAP is necessary in case:
 *                 - unaligned memory read access leads to traps or exceptions
 *                 - the linker does not align the measured XCP data properly
 *               * XCP_PREVENT_DST_WRITE_TRAP is necessary in case:
 *                 - unaligned memory write access to the XCP DAQ buffer leads to traps or exceptions
 *  \param[in]   Dst                 Pointer to target to copy data to.
 *  \param[in]   Src                 Pointer to source to copy data from.
 *  \param[in]   Size                Length of data to copy.
 *  \return      uint8               Status information whether copy was successful, denied or done asynchronously.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_MeasurementRead( P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR) Dst,
                                                                   Xcp_AddressPtrType Src,
                                                                   uint8 Size );

# if( XCP_CALIBRATION == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_CalibrationWrite()
 *********************************************************************************************************************/
/*! \brief       Copies data from Src to Dst.
 *  \details     Copy n bytes from Src to Dst with the largest possible basic data type to ensure data consistency while writing. 
 *               A maximum of 255 Bytes can be copied at once.
 *               Optimizations are possible depending on the used platform:
 *               * XCP_PREVENT_SRC_READ_TRAP is necessary in case:
 *                 - unaligned memory read access leads to traps or exceptions
 *                 - the linker does not align the measured XCP data properly
 *               * XCP_PREVENT_DST_WRITE_TRAP is necessary in case:
 *                 - unaligned memory write access to the XCP DAQ buffer leads to traps or exceptions.
 *  \param[in]   Dst                 Pointer to target to copy data to.
 *  \param[in]   Src                 Pointer to source to copy data from.
 *  \param[in]   Size                Length of data to copy.
 *  \return      uint8               Status information whether copy was successful, denied or done asynchronously.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_CALIBRATION == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_CalibrationWrite( Xcp_AddressPtrType Dst,
                                                                    P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Src,
                                                                    uint8 Size );
# endif
# if defined ( XcpAppl_GetPointer )
# else
/**********************************************************************************************************************
 *  XcpAppl_GetPointer()
 *********************************************************************************************************************/
/*! \brief       Convert XCP address to platform address.
 *  \details     This function converts a memory address from XCP format (32-bit address plus 8-bit address extension) 
 *               to a C style pointer. An MCS like CANape usually reads this memory addresses from the ASAP2 database 
 *               or from a linker map file. 
 *               The address extension may be used to distinguish different address spaces or memory types. In most 
 *               cases, the address extension is not used and may be ignored. 
 *               This function is used to convert an address from the Master Tool. 
 *  \param[in]   XcpChannel          The channel the service is triggered from.
 *  \param[in]   AddrExt             The XCP address extension.
 *  \param[in]   Addr                The XCP address.
 *  \return      Xcp_AddressPtrType  The converted platform address.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \ingroup     xcpappl
 *  \trace SPEC-4028
 *********************************************************************************************************************/
extern FUNC(Xcp_AddressPtrType, XCP_CODE) XcpAppl_GetPointer( Xcp_ChannelType XcpChannel,
                                                              uint8 AddrExt,
                                                              const Xcp_AddressPtrType Addr );
# endif

# if( XCP_READ_PROTECTION == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_CheckReadAccess()
 *********************************************************************************************************************/
/*! \brief       Checks if memory range is valid for read/CRC access.
 *  \details     Checks if memory range is valid for read/CRC access.
 *  \param[in]   XcpChannel          The channel the service is triggered from.
 *  \param[in]   Address             The address of the memory range.
 *  \param[in]   Size                The size of the memory range.
 *  \return      XCP_CMD_OK            Access is granted.
 *               XCP_CMD_ACCESS_DENIED Access is denied.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_READ_PROTECTION == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_CheckReadAccess( Xcp_ChannelType XcpChannel, 
                                                                   Xcp_AddressPtrType Address,
                                                                   uint32 Size );
# endif

# if( XCP_CHECKSUM == STD_ON ) && ( XCP_CUSTOM_CRC == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_CalculateChecksum()
 *********************************************************************************************************************/
/*! \brief       Calculates checksum over memory range.
 *  \details     Normally the XCP uses internal checksum calculation functions. If the internal checksum calculation 
 *               does not fit the user requirements this call-back can be used to calculate the checksum by the 
 *               application.
 *  \param[in]   MemArea             Pointer to memory area to create checksum from.
 *  \param[in]   Result              Result string, sent as response.
 *  \param[in]   Length              The size of the memory area.
 *  \return      XCP_CMD_OK          Access is granted.
 *               XCP_CMD_PENDING     Pending response, triggered by call of Xcp_SendCrm.
 *               XCP_CMD_DENIED      Access is denied.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous FALSE (depending on application behavior)
 *  \config      Available only if XCP_CHECKSUM == STD_ON and XCP_CUSTOM_CRC == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_CalculateChecksum( P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) MemArea, 
                                                                     P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Result, 
                                                                     uint32 Length );
# endif

# if( XCP_OPEN_COMMAND_IF == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_OpenCmdIf()
 *********************************************************************************************************************/
/*! \brief       User specific command.
 *  \details     Call back that can be used to extend the XCP commands of the XCP protocol layer.
 *  \param[in]   XcpChannel          Related XCP channel
 *  \param[in]   pCmd                Pointer to command string.
 *  \param[in]   Response            Pointer to response string.
 *  \param[in]   Length              Pointer to response length.
 *  \return      uint8               XCP_CMD_UNKNOWN : command not accepted.
 *                                   XCP_CMD_OK     : if access is granted.
 *                                   XCP_CMD_PENDING: Pending response, triggered by call of Xcp_SendCrm.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous FALSE (depending on application behavior)
 *  \config      Available only if XCP_OPEN_COMMAND_IF == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_OpenCmdIf( Xcp_ChannelType XcpChannel,
                                                             P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Cmd,
                                                             P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Response,
                                                             P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Length );
# endif

# if( XCP_GET_ID_GENERIC == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_GetIdData()
 *********************************************************************************************************************/
/*! \brief       Generic Get ID command.
 *  \details     Returns a pointer to identification information as requested by the Xcp Master.
 *  \param[in]   Data                Pointer to response string.
 *  \param[in]   Id                  identifier of request.
 *  \return      uint32              Length of resulting ID information.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_GET_ID_GENERIC == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint32, XCP_CODE)             XcpAppl_GetIdData( P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) *Data, uint8 Id );
# endif

# if( XCP_PROGRAMMING_WRITE_PROTECTION == STD_ON )
#  if defined ( XcpAppl_CheckProgramAccess ) /* defined as macro */
#  else
/**********************************************************************************************************************
 *  XcpAppl_CheckProgramAccess()
 *********************************************************************************************************************/
/*! \brief       Check if address range is protected from programming.
 *  \details     Check if address range is protected from programming.
 *  \param[in]   Address             Base address of range.
 *  \param[in]   Size                Size of range.
 *  \return      uint8               XCP_CMD_OK     : if access is granted.
 *                                   XCP_CMD_DENIED : if access is denied.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_PROGRAMMING_WRITE_PROTECTION == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_CheckProgramAccess( Xcp_AddressPtrType Address, 
                                                                      uint32 Size );
#  endif
# endif

/**********************************************************************************************************************
 *  XcpAppl_ConStateNotification()
 *********************************************************************************************************************/
/*! \brief       Signal connection state.
 *  \details     Signal connection state.
 *  \param[in]   XcpChannel          The channel of the changed connection state.
 *  \param[in]   ConnectionState     XCP_CON_STATE_CONNECTED : The XCP changed to state connected.
 *                                   XCP_CON_STATE_RESUME : The XCP changed to state resume.
 *                                   XCP_CON_STATE_DISCONNECTED : The XCP changed to state disconnected.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE)               XcpAppl_ConStateNotification( Xcp_ChannelType XcpChannel,
                                                                        uint8 ConnectionState );

/* COMMAND SPECIFIC */
/*  - STANDARD */
# if( XCP_SEED_KEY == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_GetSeed()
 *********************************************************************************************************************/
/*! \brief       Generates a seed.
 *  \details     Attention: The seed has a maximum length of MAX_CTO-2 bytes.
 *  \param[in]   Resource          resource (either XCP_RM_CAL_PAG or XCP_RM_DAQ or XCP_RM_STIM or XCP_RM_PGM)
 *  \param[out]  Seed              Pointer to the generated seed.
 *  \return      uint8             The length of the seed.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_SEED_KEY == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_GetSeed( const uint8 Resource,
                                                           P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) Seed );

/**********************************************************************************************************************
 *  XcpAppl_Unlock()
 *********************************************************************************************************************/
/*! \brief       Checks if the key fits to the previously requested seed.
 *  \details     Indicates which resource is unlocked.
 *  \param[in]   Key               Pointer to the key.
 *  \param[out]  Length            Length of the key.
 *  \return      0                 The key is not valid (no resource has to be unlocked).
 *  \return      XCP_RM_CAL_PAG    The calibration page resource has to be unlocked.
 *  \return      XCP_RM_DAQ        The data acquisition resource has to be unlocked.
 *  \return      XCP_RM_STIM       The data stimulation resource has to be unlocked.
 *  \return      XCP_RM_PGM        The programming resource has to be unlocked.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_SEED_KEY == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_Unlock( P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) Key,
                                                          const uint8 Length );
# endif

/*  - PAGE SWITCHING */
# if( XCP_CALIBRATION_PAGE == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_SetCalPage()
 *********************************************************************************************************************/
/*! \brief       Set active calibration page.
 *  \details     Switch pages, e.g. from reference page to working page
 *  \param[in]   Segment           The segment of the page.
 *  \param[in]   Page              The page itself.
 *  \param[out]  Mode              The selected mode.
 *  \return      XCP_CMD_OK              Operation completed successfully.
 *               XCP_CMD_PENDING         Command execution is pending, call XcpSendCrm() when it is finished.
 *               CRC_OUT_OF_RANGE        Segment check failed.
 *               CRC_PAGE_NOT_VALID      Page check failed.
 *               CRC_PAGE_MODE_NOT_VALID Mode check failed.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous FALSE (depending on application behavior)
 *  \config      Available only if XCP_CALIBRATION_PAGE == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_SetCalPage( uint8 Segment, uint8 Page, uint8 Mode );

/**********************************************************************************************************************
 *  XcpAppl_GetCalPage()
 *********************************************************************************************************************/
/*! \brief       Get active calibration page.
 *  \details     Get active calibration page.
 *  \param[in]   Segment           The segment of the page.
 *  \param[out]  Mode              The selected mode.
 *  \return      The currently active page.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_CALIBRATION_PAGE == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_GetCalPage( uint8 Segment, uint8 Mode );
# endif

# if( XCP_PAGE_FREEZE == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_SetFreezeMode()
 *********************************************************************************************************************/
/*! \brief       Freezes one segment, e.g. transfer it back to flash memory.
 *  \details     Freezes one segment, e.g. transfer it back to flash memory.
 *  \param[in]   Segment           The segment to freeze.
 *  \param[out]  Mode              The freeze mode.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_PAGE_FREEZE == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE)               XcpAppl_SetFreezeMode( uint8 Segment, uint8 Mode );

/**********************************************************************************************************************
 *  XcpAppl_GetFreezeMode()
 *********************************************************************************************************************/
/*! \brief       Get active freeze mode.
 *  \details     Get active freeze mode.
 *  \param[in]   Segment           The segment of the freeze mode.
 *  \return      0                 The freeze mode is inactive.
 *               1                 The freeze mode is active.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_PAGE_FREEZE == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_GetFreezeMode( uint8 Segment );
# endif

# if( XCP_COPY_CAL_PAGE == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_CopyCalPage()
 *********************************************************************************************************************/
/*! \brief       Copy a page from srcSeg:srcPage to destSeg:destPage.
 *  \details     Copy a page from srcSeg:srcPage to destSeg:destPage.
 *  \param[in]   SrcSeg            Source segment to copy from.
 *  \param[in]   SrcPage           Source page to copy from.
 *  \param[in]   DestSeg           Destination segment to copy to.
 *  \param[in]   DestPage          Destination page to copy to.
 *  \return      XCP_CMD_OK                Operation completed successfully.
 *               XCP_CMD_PENDING           Command execution is pending, call XcpSendCrm() when it is finished.
 *               XCP_CRC_PAGE_NOT_VALID    Page check failed
 *               XCP_CRC_SEGMENT_NOT_VALID Segment check failed
 *               XCP_CRC_WRITE_PROTECTED   Destination page is write protected
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous FALSE (depending on application behavior)
 *  \config      Available only if XCP_COPY_CAL_PAGE == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_CopyCalPage( uint8 SrcSeg, uint8 SrcPage, uint8 DestSeg, uint8 DestPage );
# endif


# if( XCP_USER_COMMAND == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_UserService()
 *********************************************************************************************************************/
/*! \brief       Implemented user command.
 *  \details     Application specific user command.
 *  \param[in]   Cmd               Pointer to command string.
 *  \return      XCP_CMD_OK        Success.
 *               XCP_CMD_SYNTAX    Command not accepted.
 *               XCP_CMD_PENDING   Command in progress, call Xcp_SendCrm when done.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous FALSE (depending on application behavior)
 *  \config      Available only if XCP_USER_COMMAND == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_UserService( Xcp_ChannelType XcpChannel, P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Cmd );
# endif

# if( XCP_PROGRAM == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_ProgramStart()
 *********************************************************************************************************************/
/*! \brief       Prepare for Flash programming.
 *  \details     Prepare for Flash programming.
 *  \return      XCP_CMD_OK        Success.
 *  \return      XCP_CMD_PENDING   Success, response is delayed.
 *  \return      XCP_CMD_ERROR     Preparation failed.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous FALSE (depending on application behavior)
 *  \config      Available only if XCP_PROGRAM == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_ProgramStart( void );

/**********************************************************************************************************************
 *  XcpAppl_FlashClear()
 *********************************************************************************************************************/
/*! \brief       Clear a flash are specified by the address and size.
 *  \details     Clear a flash are specified by the address and size.
 *  \param[in]   Address           Pointer to memory address.
 *  \param[in]   Size              Memory size.
 *  \return      XCP_CMD_OK        Success
 *  \return      XCP_CMD_ERROR     Clearing failed.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_PROGRAM == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_FlashClear( P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Address, uint32 Size );

/**********************************************************************************************************************
 *  XcpAppl_FlashProgram()
 *********************************************************************************************************************/
/*! \brief       Program a flash area specified by address and size with data.
 *  \details     Program a flash area specified by address and size with data.
 *  \param[in]   Data              Pointer to data.
 *  \param[in]   Address           Pointer to memory address
 *  \param[in]   Size              Memory size.
 *  \return      XCP_CMD_OK        Flashing successfully done.
 *  \return      XCP_CMD_ERROR     Flashing failed.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_PROGRAM == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_FlashProgram( P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Data, 
                                                                P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Address, 
                                                                uint8 Size );
/**********************************************************************************************************************
 *  XcpAppl_Reset()
 *********************************************************************************************************************/
/*! \brief       Reset flash programming.
 *  \details     Reset flash programming.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_PROGRAM == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE)              XcpAppl_Reset( void );
# endif /* ( XCP_PROGRAM == STD_ON ) */

# if( XCP_BOOTLOADER_DOWNLOAD == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_DisableNormalOperation()
 *********************************************************************************************************************/
/*! \brief       Initiate Flash Download.
 *  \details     Used only if Download of the Flash Kernel is required.
 *  \param[in]   Address           The address where to be flashed.
 *  \param[in]   Size              The number of bytes.
 *  \return      XCP_CMD_OK        Normal operation successfully stopped.
 *  \return      XCP_CMD_DENIED    Request rejected.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_BOOTLOADER_DOWNLOAD == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_DisableNormalOperation( Xcp_AddressPtrType Address,
                                                                          uint16 Size );

/**********************************************************************************************************************
 *  XcpAppl_StartBootLoader()
 *********************************************************************************************************************/
/*! \brief       Initiate Flash Download.
 *  \details     Used only if Download of the Flash Kernel is required.
 *  \return      XCP_CMD_OK        Flash download prepared.
 *  \return      XCP_CMD_DENIED    Request rejected.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_BOOTLOADER_DOWNLOAD == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE)              XcpAppl_StartBootLoader( void );
# endif

# if( XCP_SEND_EVENT == STD_ON ) || ( XCP_SERV_TEXT == STD_ON )
#  if defined ( XcpAppl_SendStall )
 /* XcpAppl_SendStall is already defined or a macro */
#  else
/**********************************************************************************************************************
 *  XcpAppl_SendStall()
 *********************************************************************************************************************/
/*! \brief       Resolve stall condition.
 *  \details     Resolve stall condition.
 *  \param[in]   XcpChannel        The channel with the stall condition.
 *  \return      0                 Reject sending of new message.
 *  \return      1                 OK.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_SEND_EVENT == STD_ON and XCP_SERV_TEXT == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE) XcpAppl_SendStall( Xcp_ChannelType XcpChannel );
#  endif
# endif

# if( XCP_DAQ == STD_ON )
#  if( XCP_DAQ_RESUME == STD_ON)
/**********************************************************************************************************************
 *  XcpAppl_DaqResumeStore()
 *********************************************************************************************************************/
/*! \brief       Store DAQ list in NV memory.
 *  \details     This application callback service has to store the whole dynamic DAQ list structure in non-volatile 
 *               memory for the DAQ resume mode. Any old DAQ list configuration that might have been stored in non-
 *               volatile memory before this command, must not be applicable anymore. 
 *               After a cold start or reset the dynamic DAQ list structure has to be restored by the application 
 *               callback service XcpAppl_DaqResume()when the flag measurementStart is > 0.
 *  \param[in]   XcpChannel        Related XCP channel.
 *  \param[in]   Channel           Pointer to DAQ list.
 *  \param[in]   MeasurementStart  Indicates if measurement shall be started after reset.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_DAQ == STD_ON and XCP_DAQ_RESUME == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) XcpAppl_DaqResumeStore( Xcp_ChannelType XcpChannel,
                                                    P2CONST(Xcp_ChannelStruct, AUTOMATIC, XCP_APPL_DATA) Channel,
                                                    boolean MeasurementStart );

/**********************************************************************************************************************
 *  XcpAppl_DaqResume()
 *********************************************************************************************************************/
/*! \brief       Restore DAQ list from NV memory.
 *  \details     Resume the automatic data transfer. The whole dynamic DAQ list structure that had been stored in non-
 *               volatile memory within the service XcpAppl_DaqResumeStore() has to be restored to RAM. 
 *  \param[in]   XcpChannel        Related XCP channel.
 *  \param[in]   Channel           Pointer to DAQ list.
 *  \return      FALSE             DAQ list was not restored.
 *  \return      TRUE              DAQ list was restored.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_DAQ == STD_ON and XCP_DAQ_RESUME == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE) XcpAppl_DaqResume( Xcp_ChannelType XcpChannel,
                                               P2VAR(Xcp_ChannelStruct, AUTOMATIC, XCP_APPL_DATA) Channel );

/**********************************************************************************************************************
 *  XcpAppl_DaqResumeClear()
 *********************************************************************************************************************/
/*! \brief       Clear DAQ list from NV memory.
 *  \details     The whole dynamic DAQ list structure that had been stored in non-volatile memory within the service 
 *               XcpAppl_DaqResumeStore() has to be cleared. 
 *  \param[in]   XcpChannel        Related XCP channel.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_DAQ == STD_ON and XCP_DAQ_RESUME == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(void, XCP_CODE) XcpAppl_DaqResumeClear( Xcp_ChannelType XcpChannel );


#  endif
# endif
# if( XCP_PAGE_FREEZE == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_CalResumeStore()
 *********************************************************************************************************************/
/*! \brief       Store calibration data.
 *  \details     This application callback service has to store the current calibration data in non-volatile memory for 
 *               the resume mode. 
 *               After a cold start or reset the calibration data has to be restored by the application. 
 *  \param[in]   XcpChannel        related XCP channel.
 *  \return      FALSE             Calibration data was not stored.
 *  \return      TRUE              Calibration data was successfully stored.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if XCP_PAGE_FREEZE == STD_ON.
 *  \pre         -
 *  \ingroup     xcpappl
 *********************************************************************************************************************/
extern FUNC(boolean, XCP_CODE) XcpAppl_CalResumeStore( Xcp_ChannelType XcpChannel );
# endif

#define XCP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_Xcp_TemplateCode */

#endif /* XCPAPPL_H */

/**********************************************************************************************************************
 *  END OF FILE: XcpAppl.h
 *********************************************************************************************************************/
