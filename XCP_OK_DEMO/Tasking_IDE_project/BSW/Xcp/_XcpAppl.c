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
/**        \file  XcpAppl.c
 *        \brief  XCP Template source file
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

#define XCPAPPL_SOURCE

#include "_XcpAppl.h"

#if defined (V_COMP_ANSI) && defined (V_PROCESSOR_CANOEEMU)
  #ifndef C_COMP_ANSI_CANOE
    #define C_COMP_ANSI_CANOE
  #endif
#endif

#if defined ( C_COMP_ANSI_CANOE )
# undef CONST
# undef SetEvent
# ifdef _MSC_VER
#  pragma warning( push ) /* store the current warning state for every warning */
#  pragma warning( disable : 4826 ) /* warning C4826: Conversion from 'const void *' to 'void *' is sign-extended. This may cause unexpected runtime behavior. */
#  pragma warning( disable : 4255 ) /* warning C4255: 'FARPROC' : no function prototype given: converting '()' to '(void)' */
#  pragma warning( disable : 4668 ) /* warning C4668: '__midl' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif' */
# endif
# include <stdio.h>
# include <Windows.h>
# include <malloc.h> 
# include <psapi.h>
# ifdef _MSC_VER
#  pragma warning( pop ) /* restore the last warning state pushed onto the stack */
# endif
EXTERN_C IMAGE_DOS_HEADER __ImageBase;

unsigned int GetBaseAddr(void) /* PRQA S 5013 */ /* MD_Xcp_TemplateCode */
{
  HMODULE hModule;
  HANDLE  hProcess;
  MODULEINFO moduleInfo;
  char strDLLPath[256]; /* PRQA S 5013 */ /* MD_Xcp_TemplateCode */

  GetModuleFileName((HINSTANCE)&__ImageBase, strDLLPath, 255);
  hProcess = GetCurrentProcess();
  hModule = GetModuleHandle(strDLLPath);
  GetModuleInformation(hProcess, hModule, &moduleInfo, sizeof(MODULEINFO));
  return (unsigned int)(moduleInfo.lpBaseOfDll); /* PRQA S 5013 */ /* MD_Xcp_TemplateCode */
}
# undef CONST
# include "Platform_Types.h"
#endif

#if defined ( _MICROSOFT_C_VTT_ )
  #include "VttCntrl_Base.h"
#endif


/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/

/***************************************************************************/
/*  GLOBAL DATA                                                            */
/***************************************************************************/

/* PRQA S 3408 EOF */ /* MD_Xcp_TemplateCode */
#define XCP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_Xcp_TemplateCode */

#if( XCP_SEED_KEY == STD_ON )
VAR(uint8, XCP_VAR_NOINIT) XcpAppl_Resource;
#endif

#if( XCP_CALIBRATION_PAGE == STD_ON )
VAR(XcpAppl_CalPageType, XCP_VAR_NOINIT) XcpAppl_CalPageInfo[XCP_MAX_SEGMENT];
#endif

# if( XCP_DAQ_RESUME == STD_ON)
VAR(uint8, XCP_VAR_NOINIT)  XcpAppl_MeasurementStart;
# endif /* ( XCP_DAQ_RESUME == STD_ON) */

#if( XCP_PAGE_FREEZE == STD_ON ) || ( XCP_DAQ_RESUME == STD_ON)
VAR(uint8, XCP_VAR_NOINIT)  XcpAppl_ResumeNVMemory[XCP_NUMBER_OF_CHANNELS][XCPAPPL_RESUME_NVMEMORY_SIZE];
VAR(uint16, XCP_VAR_NOINIT) XcpAppl_ResumeSize[XCP_NUMBER_OF_CHANNELS];
#endif

VAR(uint8, XCP_VAR_NOINIT)  XcpAppl_ConnectionState[XCP_NUMBER_OF_CHANNELS];

VAR(uint32, XCP_VAR_NOINIT) XcpAppl_FrConfigParameter[XCP_NUMBER_OF_CHANNELS];

#define XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_Xcp_TemplateCode */


#define XCP_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_Xcp_TemplateCode */

#if( (XCP_PROGRAM == STD_ON) || (XCP_BOOTLOADER_DOWNLOAD == STD_ON) )
/* Indicates whether programming was already started. If not started, some Programming Commands are disabled. */
VAR(uint8, XCP_VAR_INIT) XcpAppl_ProgramStartFlag = 0;
#endif

#define XCP_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_Xcp_TemplateCode */


#define XCP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_Xcp_TemplateCode */

#if ( XCP_DAQ == STD_ON ) && ( XCP_DAQ_TIMESTAMP_SIZE > 0 )
/****************************************************************************/
/* DAQ Timestamp                                                            */
/****************************************************************************/
/**********************************************************************************************************************
 *  XcpAppl_GetTimestamp()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Xcp_TimestampType, XCP_CODE) XcpAppl_GetTimestamp( void )
{
  Xcp_TimestampType XcpTimestamp;

  /* #10 Returns the current time in ticks. */
  /* Adapt this function to return a valid timestamp and remove the error message */
#error "The function XcpAppl_GetTimestamp must return a valid timestamp"

  XcpTimestamp = 0u;
  return XcpTimestamp;
} /* XcpAppl_GetTimestamp */
#endif

/****************************************************************************/
/* Mem Access                                                               */
/****************************************************************************/
/**********************************************************************************************************************
 *  XcpAppl_MemCpy()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
#if !defined ( XcpAppl_MemCpy )
FUNC(void, XCP_CODE)  XcpAppl_MemCpy( P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR) Dst,
                                      P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) Src,
                                      uint16 Size )
{
  /* #10 Copy data from source to destination byte for byte. */
  for( ; Size > 0u; Size-- )
  {
    *Dst = *Src;
    Dst = &Dst[1];
    Src = &Src[1];
  }
} /* XcpAppl_MemCpy */
#endif

/**********************************************************************************************************************
 *  XcpAppl_MeasurementRead()
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
#if !defined ( XCP_PREVENT_SRC_READ_TRAP )
# define XCP_PREVENT_SRC_READ_TRAP STD_ON
#endif
#if !defined ( XCP_PREVENT_DST_WRITE_TRAP )
# define XCP_PREVENT_DST_WRITE_TRAP STD_ON
#endif

FUNC(uint8, XCP_CODE) XcpAppl_MeasurementRead( P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR) Dst,
                                               Xcp_AddressPtrType Src,
                                               uint8 Size )
{
  uint8_least i;

  /* #10 If number of byte to be copied and the source address are divisible by 4: */
  if( ((Size % sizeof(uint32)) == 0)
#if( XCP_PREVENT_SRC_READ_TRAP == STD_ON )
      && (((uint32)Src % sizeof(uint32)) == 0)
#endif
    ) 
  {
#if( XCP_PREVENT_DST_WRITE_TRAP == STD_ON )
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) d = (P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA))Dst; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */
#else
    P2VAR(uint32, AUTOMATIC, XCP_APPL_DATA) d = (P2VAR(uint32, AUTOMATIC, XCP_APPL_DATA))Dst; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */
#endif
    P2CONST(uint32, AUTOMATIC, XCP_APPL_DATA) s = (P2CONST(uint32, AUTOMATIC, XCP_APPL_DATA))Src; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */

    /* #20 Copy the bytes from source to destination in 4 byte steps. */
    for( i = 0; i < (Size/sizeof(uint32)); i++ )
    {
#if( XCP_PREVENT_DST_WRITE_TRAP == STD_ON )
      uint32 srcData;
      srcData = s[i];
# if( CPU_BYTE_ORDER == HIGH_BYTE_FIRST )
      d[(i<<2)+0] = (uint8)(srcData >> 24);
      d[(i<<2)+1] = (uint8)(srcData >> 16);
      d[(i<<2)+2] = (uint8)(srcData >>  8);
      d[(i<<2)+3] = (uint8)(srcData);
# else
      d[(i<<2)+0] = (uint8)(srcData);
      d[(i<<2)+1] = (uint8)(srcData >>  8);
      d[(i<<2)+2] = (uint8)(srcData >> 16);
      d[(i<<2)+3] = (uint8)(srcData >> 24);
# endif
#else
      d[i] = s[i];
#endif
    }
  }
  /* #30 Otherwise, if number of byte to be copied and the source address are divisible by 2: */
  else if ( ((Size % sizeof(uint16)) == 0)
#if( XCP_PREVENT_SRC_READ_TRAP == STD_ON )
            && (((uint32)Src % sizeof(uint16)) == 0)
#endif
          )
  {
#if( XCP_PREVENT_DST_WRITE_TRAP == STD_ON )
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) d = (P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA))Dst; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */
#else
    P2VAR(uint16, AUTOMATIC, XCP_APPL_DATA) d = (P2VAR(uint16, AUTOMATIC, XCP_APPL_DATA))Dst; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */
#endif
    P2CONST(uint16, AUTOMATIC, XCP_APPL_DATA) s = (P2CONST(uint16, AUTOMATIC, XCP_APPL_DATA))Src; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */

    /* #40 Copy the bytes from source to destination in 2 byte steps. */
    for( i = 0; i < (Size/sizeof(uint16)); i++ )
    {
#if( XCP_PREVENT_DST_WRITE_TRAP == STD_ON )
      uint16 srcData;
      srcData = s[i];
# if( CPU_BYTE_ORDER == HIGH_BYTE_FIRST )
      d[(i<<1)+0] = (uint8)(srcData >> 8);
      d[(i<<1)+1] = (uint8)(srcData);
# else
      d[(i<<1)+0] = (uint8)(srcData);      
      d[(i<<1)+1] = (uint8)(srcData >> 8);
# endif
#else
      d[i] = s[i];
#endif
    }
  }
  /* #50 Otherwise, copy the bytes from source to destination byte for byte. */
  else 
  {
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) d = (P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA))Dst; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */
    P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) s = (P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA))Src; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */

    for( i = 0; i < Size; i++ ) 
    {
      d[i] = s[i];
    }
  }

  return (uint8)XCP_CMD_OK;
} /* XcpAppl_MeasurementRead */

#if( XCP_CALIBRATION == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_CalibrationWrite()
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
FUNC(uint8, XCP_CODE) XcpAppl_CalibrationWrite( Xcp_AddressPtrType Dst,
                                                P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Src,
                                                uint8 Size )
{
  uint8_least i;

  /* #10 If number of byte to be copied and the destination address are divisible by 4: */
  if( ((Size % sizeof(uint32)) == 0)
#if( XCP_PREVENT_DST_WRITE_TRAP == STD_ON )
      && (((uint32)Dst % sizeof(uint32)) == 0)
#endif
    )
  {
#if( XCP_PREVENT_SRC_READ_TRAP == STD_ON )
    P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) s = (P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA))Src; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */
#else
    P2CONST(uint32, AUTOMATIC, XCP_APPL_DATA) s = (P2CONST(uint32, AUTOMATIC, XCP_APPL_DATA))Src; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */
#endif
    P2VAR(uint32, AUTOMATIC, XCP_APPL_DATA) d = (P2VAR(uint32, AUTOMATIC, XCP_APPL_DATA))Dst; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */

    /* #20 Copy the bytes from source to destination in 4 byte steps. */
    for( i = 0; i < (Size/sizeof(uint32)); i++ )
    {
#if( XCP_PREVENT_SRC_READ_TRAP == STD_ON )
# if( CPU_BYTE_ORDER == HIGH_BYTE_FIRST )
       d[i] = ((((uint32)(s[(i*4)+0])) << 24)
            |  (((uint32)(s[(i*4)+1])) << 16)
            |  (((uint32)(s[(i*4)+2])) <<  8)
            |  ((uint32)(s[(i*4)+3])));
# else
       d[i] = (((uint32)(s[(i*4)+0]))
            |  (((uint32)(s[(i*4)+1])) <<  8)
            |  (((uint32)(s[(i*4)+2])) << 16)
            |  (((uint32)(s[(i*4)+3])) << 24));
# endif
#else
      d[i] = s[i];
#endif
    }
  }
  /* #30 Otherwise, if number of byte to be copied and the destination address are divisible by 2: */
  else if( ((Size % sizeof(uint16)) == 0)
#if( XCP_PREVENT_SRC_READ_TRAP == STD_ON )
            && (((uint32)Dst % sizeof(uint16)) == 0)
#endif
         ) 
  {
#if( XCP_PREVENT_SRC_READ_TRAP == STD_ON )
    P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) s = (P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA))Src; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */
#else
    P2CONST(uint16, AUTOMATIC, XCP_APPL_DATA) s = (P2CONST(uint16, AUTOMATIC, XCP_APPL_DATA))Src; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */
#endif
    P2VAR(uint16, AUTOMATIC, XCP_APPL_DATA) d = (P2VAR(uint16, AUTOMATIC, XCP_APPL_DATA))Dst; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */

    /* #40 Copy the bytes from source to destination in 2 byte steps. */
    for( i = 0; i < (Size/sizeof(uint16)); i++ ) 
    {
#if( XCP_PREVENT_DST_WRITE_TRAP == STD_ON )
# if( CPU_BYTE_ORDER == HIGH_BYTE_FIRST )
       d[i] = (((uint16)(s[(i*2)+0])) << 8)
            | ((uint16)(s[(i*2)+1]));
# else
       d[i] = ((uint16)(s[(i*2)+0]))
            | (((uint16)s[(i*2)+1]) << 8);
# endif
#else
      d[i] = s[i];
#endif
    }
  }
  /* #50 Otherwise, copy the bytes from source to destination byte for byte. */
  else 
  {
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) d = (P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA))Dst; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */
    P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) s = (P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA))Src; /* PRQA S 0306 */ /* MD_Xcp_TemplateCode */
 
    for( i = 0; i < Size; i++ ) 
    {
      d[i] = s[i];
    }
  }

  return (uint8)XCP_CMD_OK;
} /* XcpAppl_CalibrationWrite */
#endif

/**********************************************************************************************************************
 *  XcpAppl_GetPointer()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
#if defined ( C_COMP_ANSI_CANOE )
# pragma comment(lib,"Psapi.lib") /* PRQA S 3116 */ /* MD_Xcp_TemplateCode */
#endif

#if defined( XcpAppl_GetPointer )
#else
FUNC(Xcp_AddressPtrType, XCP_CODE) XcpAppl_GetPointer( Xcp_ChannelType XcpChannel,
                                                       uint8 AddrExt,
                                                       const Xcp_AddressPtrType Addr )
{
  Xcp_AddressPtrType tempAddr;
  XCP_DUMMY_STATEMENT( AddrExt ); /* PRQA S 3112, 3199 */ /* MD_Xcp_TemplateCode */ /*lint -e{438} */
  XCP_DUMMY_STATEMENT( XcpChannel ); /* PRQA S 3112, 3199 */ /* MD_Xcp_TemplateCode */ /*lint -e{438} */

  /* #10 If the address extension characterize an FlexRay related memory address:
   *       Read FlexRay parameters to get the memory address to be accessed. */
# if( XCP_READCCCONFIG == STD_ON )
  /* Example code to perform memory mapped API call. In this case to read FlexRay parameters via XCP. */
  if( AddrExt == XCP_ADDR_EXT_READCCCONFIG )
  {
    FrIf_ReadCCConfig((uint8)((uint32)Addr >> 10), (uint8)((uint32)Addr >> 2), &XcpAppl_FrConfigParameter[XCP_CHANNEL_IDX]);
    tempAddr = &XcpAppl_FrConfigParameter[XCP_CHANNEL_IDX];
  }
  /* #20 Otherwise, calculate the actual memory address to be accessed. */
  else
  {
# endif
# if defined( _MICROSOFT_C_VTT_ )
    tempAddr = Addr + VttCntrl_Base_GetBaseAddressOfDll();
# elif defined( C_COMP_ANSI_CANOE )
    tempAddr = Addr + GetBaseAddr();
# else
    tempAddr = Addr;
# endif
# if( XCP_READCCCONFIG == STD_ON )
  }
# endif

  return tempAddr;
} /* XcpAppl_GetPointer */
#endif

#if( XCP_SEED_KEY == STD_ON )
/*****************************************************************************/
/* Seed & Key                                                                */
/* This is just an example how seed & key could be implemented.              */
/*****************************************************************************/
/**********************************************************************************************************************
 *  XcpAppl_GetSeed()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_GetSeed( const uint8 Resource, P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) Seed )
{
  uint8 resourceSize;
  
  /* #10 Generate a seed depending on the requested Resource (XCP_RM_CAL_PAG, XCP_RM_DAQ, XCP_RM_STIM or XCP_RM_PGM) 
   *     and return the seed length. */
  Seed[0] = 0;
  Seed[1] = 1;
  Seed[2] = 2;
  Seed[3] = 3;
  Seed[4] = 4;
  Seed[5] = 5;

  /* The seed has a maximum length of MAX_CTO-2 bytes. */
  resourceSize = 6u;

  /* Store resource mask */
  XcpAppl_Resource = Resource;

  return resourceSize;
} /* XcpAppl_GetSeed */

/**********************************************************************************************************************
 *  XcpAppl_Unlock()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_Unlock( P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) Key, const uint8 Length )
{
  uint8 retVal = 0; /* Init Value: Resource is invalid. */

  /* #10 Checks if the key fits to the prior generated seed and return the resource (XCP_RM_CAL_PAG, XCP_RM_DAQ, 
   *     XCP_RM_STIM, XCP_RM_PGM or Invalid=0) to be unlocked. */
  /*
    Check the key
    key[0],key[1],key[2],key[3],key[4],key[5]
  */
  (void)Key; /* PRQA S 3112 */ /* MD_Xcp_TemplateCode */
  (void)Length; /* PRQA S 3112 */ /* MD_Xcp_TemplateCode */

  return retVal;
} /* XcpAppl_Unlock */
#endif /* XCP_SEED_KEY == STD_ON */

#if( XCP_CALIBRATION_PAGE == STD_ON )
/*****************************************************************************/
/* Page Switching                                                            */
/*****************************************************************************/
/**********************************************************************************************************************
 *  XcpAppl_SetCalPage()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_SetCalPage( uint8 Segment, uint8 Page, uint8 Mode )
{
  uint8 retVal = XCP_CMD_OK;

  /* #10 Check parameters for validity. */
  if( Segment > 0 )
  {
    retVal = XCP_CRC_OUT_OF_RANGE; /* Only one segment supported */
  }
  else if( (Mode & 0x83) == 0 )
  {
    retVal =  XCP_CRC_PAGE_MODE_NOT_VALID; /* Invalid mode requested */
  }
  else if( Page > 1 ) /* Only one page supported */
  {
    retVal =  XCP_CRC_PAGE_NOT_VALID; 
  }
  /* #20 If all parameters are valid, set the specified calibration page to active. */
  else
  {
    XcpAppl_CalPageInfo[Segment].ActiveCalPage = Page;
  }

  return retVal;
} /* XcpAppl_SetCalPage */

/**********************************************************************************************************************
 *  XcpAppl_GetCalPage()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_GetCalPage( uint8 Segment, uint8 Mode )
{
  /* #10 Check parameters for validity. */
  
  /* #20 If all parameters are valid, return the active calibration page of the specified segment. */
  return (uint8)XcpAppl_CalPageInfo[Segment].ActiveCalPage;
} /* XcpAppl_GetCalPage */
#endif /* ( XCP_CALIBRATION_PAGE == STD_ON ) */

#if( XCP_PAGE_FREEZE == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_SetFreezeMode()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, XCP_CODE) XcpAppl_SetFreezeMode( uint8 Segment, uint8 Mode )
{
  /* #10 Check parameters for validity. */
  
  /* #20 If all parameters are valid, set the new freeze mode to the calibration page segment. */
  XcpAppl_CalPageInfo[Segment].CalPageSegmentMode = Mode;
} /* XcpAppl_SetFreezeMode */

/**********************************************************************************************************************
 *  XcpAppl_GetFreezeMode()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_GetFreezeMode( uint8 Segment )
{
  uint8 retVal;
  /* #10 Check parameters for validity. */

  /* #20 If all parameters are valid, return the current freeze mode of the specified calibration page segment. */
  retVal = 0x00u; /* Freeze is Off (Bit0 = 0) */

  return (uint8)retVal;
} /* XcpAppl_GetFreezeMode */
#endif

#if( XCP_COPY_CAL_PAGE == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_CopyCalPage()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_CopyCalPage( uint8 SrcSeg, uint8 SrcPage, uint8 DestSeg, uint8 DestPage )
{
  uint8 retVal;
  /* #10 Check parameters for validity. */

  /* #20 If all parameters are valid, copy a page from SrcSeg:SrcPage to DestSeg:DestPage and return if copy succeeded. */

  retVal = (uint8)XCP_CMD_OK;

  return retVal;
} /* XcpAppl_CopyCalPage */
#endif /* ( XCP_COPY_CAL_PAGE == STD_ON ) */


#if( XCP_READ_PROTECTION == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_CheckReadAccess()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
# if defined ( XcpAppl_CheckReadAccess ) /* defined as macro */
# else
FUNC(uint8, XCP_CODE) XcpAppl_CheckReadAccess( Xcp_ChannelType XcpChannel, 
                                               Xcp_AddressPtrType Address, 
                                               uint32 Size )
{
  uint8 retVal = XCP_CMD_OK;

  /* #10 Check whether it is allowed to read access the specified memory range. */
  /* Protect xcp own memory from being accessed */
  /* PRQA S 0306 2 */ /* MD_Xcp_TemplateCode */
  if( (((Address + (Xcp_AddressPtrType)Size) > (Xcp_AddressPtrType)&Xcp_ChannelInfo[XcpChannel]))
   && (Address < ((Xcp_AddressPtrType)&Xcp_ChannelInfo[XcpChannel] + sizeof(Xcp_ChannelInfo[XcpChannel]))) 
    )
  {
    retVal = XCP_ERR_ACCESS_DENIED;
  }

  return (uint8)retVal;
} /* XcpAppl_CheckReadAccess */
# endif /* defined ( XcpAppl_CheckReadAccess ) */
#endif /* ( XCP_READ_PROTECTION == STD_ON ) */

#if( XCP_CHECKSUM == STD_ON ) && ( XCP_CUSTOM_CRC == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_CalculateChecksum()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_CalculateChecksum( P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) MemArea, 
                                                 P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Result, 
                                                 uint32 Length )
{
  uint8 retVal;
  (void)Length; /* PRQA S 3112 */ /* MD_Xcp_TemplateCode */
  (void)MemArea; /* PRQA S 3112 */ /* MD_Xcp_TemplateCode */

  /* #10 Calculate CRC synchronously and return XCP_CMD_OK (keep runtime and possible timeouts in mind!). */
  /* #20 Or, trigger calculation of CRC asynchronously and trigger response by call of Xcp_SendCrm after calculation. */
  uint32 crc = 0xcafebabe;
  /* crc = Crc_CalculateCRC32( MemArea, Length, 0x00 ); */
  Result[0] = 0xFF; /* Positive Response */
  Result[1] = XCP_CHECKSUM_TYPE_CRC32;
  Result[2] = 0x00; /* Reserved */
  Result[3] = 0x00; /* Reserved */
  /* Consider endianness, this is little endian architecture */
  Result[4] = (uint8)crc;
  Result[5] = (uint8)(crc >> 8);
  Result[6] = (uint8)(crc >> 16);
  Result[7] = (uint8)(crc >> 24);

  retVal = (uint8)XCP_CMD_OK;

  return retVal;
} /* XcpAppl_CalculateChecksum */
#endif /* ( XCP_CHECKSUM == STD_ON ) && ( XCP_CUSTOM_CRC == STD_ON ) */

#if( XCP_USER_COMMAND == STD_ON )
/****************************************************************************/
/* User defined service                                                     */
/****************************************************************************/
/**********************************************************************************************************************
 *  XcpAppl_UserService()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_UserService( Xcp_ChannelType XcpChannel, P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Cmd )
{
  uint8 retVal = XCP_CMD_OK;

  /* #10 If the received command is supported:
   *       Execute the command as specified and return XCP_CMD_OK or XCP_CMD_PENDING. */
  if( Cmd[0] == 0xf1 /* Command: USER_COMMAND */ )
  {
    if( Cmd[1] == 0x00 /* SubCommand: TBD */ )
    {
      retVal = XCP_CMD_PENDING;
    }
  }
  /* #20 Otherwise, reject the command and return XCP_CMD_SYNTAX. */

  return retVal;
} /* XcpAppl_UserService */
#endif /* ( XCP_USER_COMMAND == STD_ON ) */

#if( XCP_BOOTLOADER_DOWNLOAD == STD_ON )
/****************************************************************************/
/* BootLoad Download                                                     */
/****************************************************************************/
/**********************************************************************************************************************
 *  XcpAppl_DisableNormalOperation()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_DisableNormalOperation( Xcp_AddressPtrType Address, uint16 Size )
{
  uint8 retVal;
  
  /* #10 Initiate download sequence of the flash kernel and indicate if initiation was successful. */
  /* CANape attempts to download the flash kernel to XCP_RAM. */
  
  retVal = XCP_CMD_OK;

  return retVal;
} /* XcpAppl_DisableNormalOperation */

/**********************************************************************************************************************
 *  XcpAppl_StartBootLoader()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_StartBootLoader( void )
{
  uint8 retVal;

  /* #10 If start of BootLoader is rejected:
   *         Return error code XCP_CMD_DENIED. */
  retVal = XCP_CMD_DENIED;
  
  /* #20 Otherwise, execute the BootLoader download what never return. */

  return retVal;
} /* XcpAppl_StartBootLoader */
#endif /* ( XCP_BOOTLOADER_DOWNLOAD == STD_ON ) */

#if( XCP_PROGRAM == STD_ON )
# if( XCP_BOOTLOADER_DOWNLOAD == STD_OFF )
/*****************************************************************************/
/* Flash Programming                                                         */
/*****************************************************************************/
/**********************************************************************************************************************
 *  XcpAppl_ProgramStart()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_ProgramStart( void )
{
  uint8 retVal;

  retVal = XCP_CMD_OK;
  
  /* #10 Prepare flash programming. */
  XcpAppl_ProgramStartFlag = 1;

  return retVal;
} /* XcpAppl_ProgramStart */
# endif

/**********************************************************************************************************************
 *  XcpAppl_FlashClear()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 3673 1 */ /* MD_Xcp_TemplateCode */
FUNC(uint8, XCP_CODE) XcpAppl_FlashClear( P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Address, uint32 Size )
{
  uint8 retVal = XCP_CMD_OK;

  /* #10 If Programming was not started, return XCP_ERR_SEQUENCE. */
  if( XcpAppl_ProgramStartFlag == 0 )
  {
    retVal = XCP_ERR_SEQUENCE;
  }
  /* #20 Otherwise, clear the flash memory range specified by the address and size. */
  else
  {
    /* to be implemented */
  }  

  return (uint8)retVal;
} /* XcpAppl_FlashClear */

/**********************************************************************************************************************
 *  XcpAppl_FlashProgram()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 3673 3 */ /* MD_Xcp_TemplateCode */
FUNC(uint8, XCP_CODE) XcpAppl_FlashProgram( P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Data, 
                                            P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Address, 
                                            uint8 Size )
{
  uint8 retVal = XCP_CMD_OK;

  /* #10 If Programming was not started, return XCP_ERR_SEQUENCE. */
  if( XcpAppl_ProgramStartFlag == 0 )
  {
    retVal = XCP_ERR_SEQUENCE;
  }
  /* #20 Otherwise, program a flash area specified by address and size with data. */
  else
  {
    /* to be implemented */
  }

  return (uint8)retVal;
} /* XcpAppl_FlashProgram */

/**********************************************************************************************************************
 *  XcpAppl_Reset()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, XCP_CODE) XcpAppl_Reset( void )
{
  /* #10 Terminate a flash programming sequence. */
  XcpAppl_ProgramStartFlag = 0;
} /* XcpAppl_Reset */
#endif /* ( XCP_PROGRAM == STD_ON ) */

#if( XCP_PROGRAMMING_WRITE_PROTECTION == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_CheckProgramAccess()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
# if defined ( XcpAppl_CheckProgramAccess ) /* defined as macro */
# else
FUNC(uint8, XCP_CODE) XcpAppl_CheckProgramAccess( Xcp_AddressPtrType Address, 
                                                  uint32 Size )
{
  uint8 retVal = XCP_CMD_OK;

  /* #10 Check if the specified memory range is valid to be flashed. */
  return retVal;
} /* XcpAppl_CheckProgramAccess */
# endif /* defined ( XcpAppl_CheckProgramAccess ) */
#endif /* XCP_PROGRAMMING_WRITE_PROTECTION == STD_ON */

#if( XCP_GET_ID_GENERIC == STD_ON )
const uint8 XcpAppl_AsciiString[11] = "HelloWorld";
const uint8 XcpAppl_MapName[9] = "Test.map";

/**********************************************************************************************************************
 *  XcpAppl_GetIdData()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint32, XCP_CODE) XcpAppl_GetIdData( P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) *Data, 
                                          uint8 Id )
{
  uint32 retVal = 0;

  /* #10 If the specified ID is supported, execute the command accordingly and return the length of data to be uploaded
   *     later on. */
  switch( Id )
  { /* Example code, fit to your needs: */
    case( XCP_IDT_ASCII ): 
      /* Handle ASCII text. */
      *Data = (P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))&XcpAppl_AsciiString; /* PRQA S 0310 */ /* MD_Xcp_TemplateCode */
      retVal = (uint32)sizeof(XcpAppl_AsciiString)-1;
      break;
    case( XCP_IDT_VECTOR_MAPNAMES ): 
      /* Handle map file name. */
      *Data = (P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT))&XcpAppl_MapName; /* PRQA S 0310 */ /* MD_Xcp_TemplateCode */
      retVal = (uint32)sizeof(XcpAppl_MapName)-1;
      break;

    /* #20 Otherwise, return a length of 0 to indicate that ID was not supported. */
    default:
      /* Id not available. */
      break;
  }

  return retVal;
} /* XcpAppl_GetIdData */
#endif

#if( XCP_OPEN_COMMAND_IF == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_OpenCmdIf()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_OpenCmdIf( Xcp_ChannelType XcpChannel,
                                         P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Cmd,
                                         P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Response,
                                         P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Length )
{
  uint8 retVal = XCP_CMD_UNKNOWN;
  /* Implemented user specific command */
  
  /* #10 If the command is supported:
   *       Execute it accordingly and return XCP_CMD_OK or XCP_CMD_PENDING. */
   
  /* #20 Otherwise, return error code XCP_ERR_CMD_UNKNOWN. */

  (void)XcpChannel;

  return retVal;
} /* XcpAppl_OpenCmdIf */
#endif

/****************************************************************************/
/* XcpAppl_SendStall                                                        */
/****************************************************************************/
#if( XCP_SEND_EVENT == STD_ON ) || ( XCP_SERV_TEXT == STD_ON )
# if defined ( XcpAppl_SendStall )
 /* XcpAppl_SendStall is already defined or a macro */
# else
/**********************************************************************************************************************
 *  XcpAppl_OpenCmdIf()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_SendStall( Xcp_ChannelType XcpChannel )
{
  uint8 retVal = 0; /* Reject sending of new message. */
  (void)XcpChannel; /* PRQA S 3112 */ /* MD_Xcp_TemplateCode */
  
  /* #10 If the waiting for pending TxConfirmation should be canceled, return 0. */

  /* #20 Otherwise, return another value. */

  return retVal;
} /* XcpAppl_SendStall */
# endif
#endif

#if( XCP_DAQ == STD_ON )
# if( XCP_DAQ_RESUME == STD_ON)
/*****************************************************************************/
/* DAQ list resume feature                                                   */
/*****************************************************************************/
/**********************************************************************************************************************
 *  XcpAppl_DaqResumeStore()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, XCP_CODE) XcpAppl_DaqResumeStore( Xcp_ChannelType XcpChannel,
                                             P2CONST(Xcp_ChannelStruct, AUTOMATIC, XCP_APPL_DATA) Channel,
                                             boolean MeasurementStart )
{
  uint16 size = (uint16)sizeof(Xcp_ChannelStruct);
  
  /* #10 Copy the whole DAQ configuration of the specified XcpChannel to non-volatile memory. */
  XcpAppl_MemCpy(&(XcpAppl_ResumeNVMemory[XcpChannel][0]), (P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA))Channel, size); /* PRQA S 0310 */ /* MD_Xcp_TemplateCode */
  XcpAppl_ResumeSize[XcpChannel] = size;

  /* #20 Remember whether Resume mode is active or not. */
  XcpAppl_MeasurementStart = MeasurementStart; /* Must be checked within XcpAppl_DaqResume. */
} /* XcpAppl_DaqResumeStore */

/**********************************************************************************************************************
 *  XcpAppl_DaqResume()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint8, XCP_CODE) XcpAppl_DaqResume( Xcp_ChannelType XcpChannel, P2VAR(Xcp_ChannelStruct, AUTOMATIC, XCP_APPL_DATA) Channel )
{
#if( XCP_SEND_EVENT == STD_ON )
  /* Restore DAQ configuration data from non volatile memory */
  const uint8 eventResume[] = {0x00, 0x00};
#endif

  /* #10 If resume data is available: */
  if( XcpAppl_ResumeSize[XcpChannel] > 0 )
  {
    /* #20 Restores the whole DAQ configuration of the specified XcpChannel from non-volatile memory. */
    /* PRQA S 0310 3 */ /* MD_Xcp_TemplateCode */
    XcpAppl_MemCpy( (P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA))Channel,
                    &XcpAppl_ResumeNVMemory[XcpChannel][0],
                    XcpAppl_ResumeSize[XcpChannel] );
    XcpAppl_ResumeSize[XcpChannel] = 0;
#if( XCP_SEND_EVENT == STD_ON )
    /* #30 Send a asynchronous event to indicate XCP master that resume mode is entered. */
    Xcp_SendEvent( XcpChannel, 0, &eventResume[0], sizeof(eventResume));
#endif
  }

  return (XcpAppl_MeasurementStart);
} /* XcpAppl_DaqResume */

/**********************************************************************************************************************
 *  XcpAppl_DaqResumeClear()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, XCP_CODE) XcpAppl_DaqResumeClear( Xcp_ChannelType XcpChannel )
{
  uint16 i;

  XcpAppl_ResumeSize[XcpChannel] = 0;

  /* #10 Clear the DAQ configuration data in non volatile memory of the specified XcpChannel. */
  for( i = 0; i < XCPAPPL_RESUME_NVMEMORY_SIZE; i++ )
  {
    XcpAppl_ResumeNVMemory[XcpChannel][i] = 0;
  }
} /* XcpAppl_DaqResumeClear */
# endif /* ( XCP_DAQ_RESUME == STD_ON) */
#endif /* ( XCP_DAQ == STD_ON ) */

#if( XCP_PAGE_FREEZE == STD_ON )
/**********************************************************************************************************************
 *  XcpAppl_CalResumeStore()
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
FUNC(boolean, XCP_CODE) XcpAppl_CalResumeStore( Xcp_ChannelType XcpChannel )
{
  boolean storingCalDataReady = FALSE;
  uint8 i;

  /* #10 If the calibration page segment is in freeze mode: */
  if( XcpAppl_CalPageInfo[0].CalPageSegmentMode == XCPAPPL_FREEZE_MODE_ENABLE )
  {
    /* #20 Copy currently active calibration page content to page 0 and store the calibration page configuration data 
     *     to non-volatile memory for the specified XcpChannel. */
    for( i = 0; i < XCPAPPL_CAL_PAGE_SIZE; i++ )
    {
      XcpAppl_CalPageInfo[0].CalPages[0][i] = XcpAppl_CalPageInfo[0].CalPages[XcpAppl_CalPageInfo[0].ActiveCalPage][i];
    }
# if( XCP_SEND_EVENT == STD_ON )
    /* #30 Send asynchronous event to indicate XCP master that calibration page configuration was persisted. */
    {
      const uint8 eventResume[] = {0x00, 0x00};
      Xcp_SendEvent( XcpChannel, 0, &eventResume[0], sizeof(eventResume) );
    }
# endif
    /* The new active calibration page is page 0. */
    XcpAppl_CalPageInfo[0].ActiveCalPage = 0;

    storingCalDataReady = TRUE;
  }

  return storingCalDataReady;
  /* return (uint8)XCP_RESUME_ACTIVE; */
} /* XcpAppl_CalResumeStore */
#endif

/**********************************************************************************************************************
 *  XcpAppl_CalResumeStore()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, XCP_CODE) XcpAppl_ConStateNotification( Xcp_ChannelType XcpChannel,
                                                   uint8 ConnectionState )
{
  /* #10 Remember the new connection state (XCP_CON_STATE_DISCONNECTED, XCP_CON_STATE_RESUME or XCP_CON_STATE_CONNECTED)
   *     of the specified XcpChannel. */
  XcpAppl_ConnectionState[XcpChannel] = ConnectionState;
} /* XcpAppl_ConStateNotification */

#define XCP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_Xcp_TemplateCode */

/* Justification for module-specific MISRA deviations:

  MD_Xcp_TemplateCode: rule x.y
      Reason:     This MISRA violation is template code relevant. It is intended as an example and can be modified by the user
      Risk:       The user has responsibility for this file.
      Prevention: Covered by code review.
*/

