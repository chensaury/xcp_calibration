

/*****************************************************************************
| Project Name:   XCP on CAN demo for Infineon Tricore TC17x7
|    File Name:   
|
|  Description:  
|   This module demonstrates how to implement a calibration concept with 
|   FLASH overlays created on demand.
|	It uses the 8KByte Tricore OVRAM in 16 512Byte segments
|   It can be easily enhanced to use Tricore EMEM
|
|-----------------------------------------------------------------------------
|               D E M O
|-----------------------------------------------------------------------------
|
|       Please note, that the demo and example programs 
|       only show special aspects of the software. 
|       With regard to the fact that these programs are meant 
|       for demonstration purposes only,
|       Vector Informatik's liability shall be expressly excluded in cases 
|       of ordinary negligence, to the extent admissible by law or statute.
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2010 by Vector Informatik GmbH.           All rights reserved.
|
|       This software is copyright protected and 
|       proporietary to Vector Informatik GmbH.
|       Vector Informatik GmbH grants to you only
|       those rights as set out in the license conditions.
|       All other rights remain with Vector Informatik GmbH.
| 
|       Diese Software ist urheberrechtlich geschuetzt. 
|       Vector Informatik GmbH raeumt Ihnen an dieser Software nur 
|       die in den Lizenzbedingungen ausdruecklich genannten Rechte ein.
|       Alle anderen Rechte verbleiben bei Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|***************************************************************************/

#include "project.h"

#ifdef XCP_CC_TC_OVRAM


/*
Needs the below XCP driver functions enabled:

#define XCP_ENABLE_CALIBRATION
#define XCP_ENABLE_MEM_ACCESS_BY_APPL
#define XCP_ENABLE_CALIBRATION_PAGE
#define XCP_ENABLE_PAGE_COPY

It is recomended to enable text messages to get additional information 
on failed memory accesses

#define XCP_ENABLE_SERV_TEXT_PRINT

Please note that there is a potential conflict with the VX1000 system when
using the Tricore OVC feature. It is recomended to use VX1000 tool detection
to avoid problems.


*/

#define IGNORE_SEGMENT_NUMBER
// #define PMU0_OVRCON               (*((unsigned int volatile *) 0xF8000520))
//------------------------------------------------------------------------------
// Tricore overlay control
// Helper functions

// Set an individual OVC overlay segment but do start overlay yet
static vuint8 ovc_set_ovram_block( vuint8 i, vuint32 targetAddr, vuint32 overlayBlockSize, vuint32 overlayBlockOffset ) {

  vuint32 overlayBlockMask;

  #define OVRAM_ADDR 0xAFE80000UL
  #define _OVC_BASE 0xF880FB00
  #define _OVC_OTAR(x) *(vuint32*)(_OVC_BASE+0x24+(x)*0xC)
  #define _OVC_RABR(x) *(vuint32*)(_OVC_BASE+0x20+(x)*0xC)
  #define _OVC_OMASK(x) *(vuint32*)(_OVC_BASE+0x28+(x)*0xC)
  #define _OVC_OCON *(vuint32*)(_OVC_BASE+0xE0)


  // Check overlayBlockOffset must have size Granularity
  if ( (overlayBlockOffset & (overlayBlockSize - 1)) != 0) return 0;

  // targetAddress must have size granularity
  if (targetAddr & (overlayBlockSize - 1)) return 0;

  #if OVC_EMEM

  // Check overlayBlockSize must be a power of 2 which is >= 1K and <=128K
  switch (overlayBlockSize) {
    case 1*1024UL:
    case 2*1024UL:
    case 4*1024UL:
    case 8*1024UL:
    case 16*1024UL:
    case 32*1024UL:
    case 64*1024UL:
    case 128*1024UL:
      break;
    default:
      return 0;
  }

  // Redirected Address Base Register
  _OVC_RABR(i) = 0x4FF00000 | overlayBlockOffset | (gTricoreEmemOverlayBase & 0x00078000); // IEMS(0x40000000)=1 
  // Overlay Mask Register
  _OVC_OMASK(i) =  (~(overlayBlockSize - 1)) & 0x0FFFFFFF;
  // Overlay Target Address Register
  _OVC_OTAR(i) = targetAddr; 

  #else // OVRAM 

  // Blocksize is 2^n n=4-11
  #define OVC_OVRAM_BLOCKSIZE_2K 0x00 // 2^11 0000000B 2 Kbyte
  #define OVC_OVRAM_BLOCKSIZE_1K 0x40 // 2^10 1000000B 1 Kbyte
  #define OVC_OVRAM_BLOCKSIZE_512B 0x60 // 2^9  1100000B 512 byte
  #define OVC_OVRAM_BLOCKSIZE_256B 0x70 // 2^8  1110000B 256 byte
  #define OVC_OVRAM_BLOCKSIZE_128B 0x78 // 2^7  1111000B 128 byte
  #define OVC_OVRAM_BLOCKSIZE_64B 0x7C // 2^6  1111100B 64 byte
  #define OVC_OVRAM_BLOCKSIZE_32B 0x7E // 2^5  1111110B 32 byte
  #define OVC_OVRAM_BLOCKSIZE_16B 0x7F // 2^4  1111111B 16 byte

  // Check overlayBlockSize
  switch (overlayBlockSize) {
      case 2048: overlayBlockMask = OVC_OVRAM_BLOCKSIZE_2K; break;
      case 1024: overlayBlockMask = OVC_OVRAM_BLOCKSIZE_1K; break;
      case 512: overlayBlockMask = OVC_OVRAM_BLOCKSIZE_512B; break;
      case 256: overlayBlockMask = OVC_OVRAM_BLOCKSIZE_256B; break;
      case 128: overlayBlockMask = OVC_OVRAM_BLOCKSIZE_128B; break;
      case 64: overlayBlockMask = OVC_OVRAM_BLOCKSIZE_64B; break;
      case 32: overlayBlockMask = OVC_OVRAM_BLOCKSIZE_32B; break;
      case 16: overlayBlockMask = OVC_OVRAM_BLOCKSIZE_16B; break;
      default: return 0;
  } 

  // Redirected Address Base Register
  _OVC_RABR(i) = 0x0FE80000 | (overlayBlockOffset&0x00001FFF); // IEMS=0 
  // Overlay Mask Register
  _OVC_OMASK(i) = 0x0FFFF8000 | ((overlayBlockMask&0x7F)<<4);
  // Overlay Target Address Register
  _OVC_OTAR(i) =  targetAddr;
  
  #endif

  return 1;
}



// Enable overlay RAM (OVRAM)
// Reset and stop OVC 
static void ovc_init( void ) {

//   Init OVRRAM
//  PMU0_OVRCON = 0;

  // Test if OVRAM is accessible
  #ifdef OVR_TEST
  {
    volatile vuint8 *ovram = (vuint8*)OVRAM_ADDR; // size = 0x2000 8K
    volatile vuint8 *flash = (vuint8*)0xa0100000;
    vuint8 ub;
    ovram[64] = 0xAA;
    ub = ovram[64];
    if (ub!=0xAA) {
        XcpPrintf("Error\n");
    }
    ovram[64] = 0x55;
    ub = ovram[64];
    if (ub!=0x55) {
        XcpPrintf("Error\n");
    }
    for (i=0;i<8*1024;i++) ovram[i] = 0x00;
  }
  #endif

  _OVC_OCON = 0x00000000;  // SHOWENx=0
  _OVC_OCON = 0x00060000;  // OVSTP=1  -> all RABRx enable bits cleared
  // DCINVAL, OVCONF, POVCONF not used yet

  // Test if FLASH is now overlaid by OVRRAM
  #ifdef OVC_TEST
  {
    volatile vuint8 *ovram = (vuint8*)OVRAM_ADDR; // size = 0x2000 8K
    volatile vuint8 *flash = (vuint8*)0xa0100000;
    vuint32 i,j;
    // Create an overlay
    memcpy(ovram,flash,8*1024);
    ovc_set_ovram_block( 0, (vuint32)flash+0x0000, 2048, 0 );
    ovc_set_ovram_block( 1, (vuint32)flash+0x0800, 2048, 2048 );
    ovc_set_ovram_block( 2, (vuint32)flash+0x1000, 2048, 2*2048 );
    ovc_set_ovram_block( 3, (vuint32)flash+0x1800, 2048, 3*2048 );
    _OVC_OCON = 0x0000000F;
    _OVC_OCON = 0x0000000F | 0x00050000; 
    for (i=0;i<8*1024;i++) {
      if (ovram[i] != flash[i]) {
        XcpPrintf("Error\n");
      }
    }
    
    // Test if we can write to FLASH now
	for (j=0;j<4;j++) {
    for (i=0;i<16;i++) {
      flash[j*2048+i] = (unsigned char)i+j;
    }
    for (i=0;i<16;i++) {
      if (flash[j*2048+i]!=(unsigned char)i+j) {
        XcpPrintf("Error\n");
      }
    }
	}
  }    
  #endif

}



//------------------------------------------------------------------------------
// Calibration concept
    
// DAQ and STIM runs with memcpy
// All other memory accesses via ApplXcpRead, ApplXcpWrite and ApplXcpReadChecksumValue

#define CC_SEGMENT_COUNT 16
#define CC_SEGMENT_SIZE 512
vuint32 gCC_FLASH[CC_SEGMENT_COUNT];
#define SEGMENT_FLASH_PTR(x) gCC_FLASH[x]
#define SEGMENT_RAM_PTR(i) (OVRAM_ADDR+(i)*CC_SEGMENT_SIZE)
//vuint32 gCC_RAM[CC_SEGMENT_COUNT];
//#define SEGMENT_RAM_PTR(x)   gCC_RAM[x]

vuint8 XcpCalSetLocked = 0;

static vuint8 gCC_NextFreeSegment = 0;
static vuint32 gCC_FlashOverlayActiveMask = 0;

#define CALPAGE_RAM 1
#define CALPAGE_FLASH 0
static vuint8 gCC_XCP_CalPage = CALPAGE_RAM; // RAM
static vuint8 gCC_ECU_CalPage = CALPAGE_RAM; // RAM


// Redirect the addr a
static unsigned char redirectCalSet(vuint32 a) { 

  vuint8 i;

  // Check if there is a free segment 
  if (gCC_NextFreeSegment >= CC_SEGMENT_COUNT) {
    #ifdef XCP_ENABLE_SERV_TEXT_PRINT    
      XcpPrint("@E: Error: Calibration memory exceeded!\n");
	#endif
    return 0; // Error: Out of calibration memory
  }

  // Allocate a segment
  i  = gCC_NextFreeSegment;
  SEGMENT_FLASH_PTR(i) = a & ~((vuint32)CC_SEGMENT_SIZE-1);

  // Copy the FLASH content to RAM
  memcpy((void*)SEGMENT_RAM_PTR(i),(void*)SEGMENT_FLASH_PTR(i),CC_SEGMENT_SIZE);
  
  // Initialize the segment
  if (!ovc_set_ovram_block(i,SEGMENT_FLASH_PTR(i),CC_SEGMENT_SIZE,SEGMENT_RAM_PTR(i))) {
    return 0;
  }
  gCC_FlashOverlayActiveMask |= 1UL << i;
  _OVC_OCON = gCC_FlashOverlayActiveMask;

  // Start overlay if currently enabled
  if (gCC_ECU_CalPage==CALPAGE_RAM) _OVC_OCON = gCC_FlashOverlayActiveMask | 0x00050000; // SHOWENx=0, OVSTRT=1 -> all RABRx enable bits taken from SHWENx, start overlay

  gCC_NextFreeSegment++;

  #ifdef XCP_ENABLE_SERV_TEXT_PRINT    
    XcpPrintf("Segment %X-%X redirected to %X, %u left\n",SEGMENT_FLASH_PTR(i),SEGMENT_FLASH_PTR(i)+CC_SEGMENT_SIZE-1,SEGMENT_RAM_PTR(i),CC_SEGMENT_COUNT-gCC_NextFreeSegment);
  #endif

  return 1; // Ok
}

static void delay( void ) {
  volatile vuint32 i;
  for (i=0;i<16;i++);
}
 
static vuint8 read( vuint32 a ) {

  // Transform address if there is an access to FLASH
  if ((a&0xD0000000)==0x80000000) { // Read from a FLASH address

    vuint8 r;

    //  XCP reads from FLASH and hardware address translation is turned on (ECU cal page is RAM)  
    if (gCC_XCP_CalPage==CALPAGE_FLASH && gCC_ECU_CalPage==CALPAGE_RAM) {

      // @@@@ Disable interrupts      
      // Temporarily turn off address translation
      _OVC_OCON = gCC_FlashOverlayActiveMask | 0x00060000;  // DCINVAL|OVSTP Stop overlay and invalidate the cache
	  delay();
      r = *(vuint8*)(a);	   // Read from FLASH
      _OVC_OCON = gCC_FlashOverlayActiveMask | 0x00050000;  // DCINVAL|OVSTRT Start overlay and invalidate the cache
 	  return r;
	}

    //  XCP reads from RAM and hardware address translation is turned off (ECU cal page is FLASH)
    if (gCC_XCP_CalPage==CALPAGE_RAM && gCC_ECU_CalPage==CALPAGE_FLASH) {

      // @@@@ Disable interrupts      
      // Temporarily turn on address translation
      _OVC_OCON = gCC_FlashOverlayActiveMask | 0x00050000;  // DCINVAL|OVSTRT Start overlay and invalidate the cache
	  delay();
      r = *(vuint8*)(a);	   // Read from RAM
      _OVC_OCON = gCC_FlashOverlayActiveMask | 0x00060000;  // DCINVAL|OVSTP Stop overlay and invalidate the cache
 	  return r;
      #if 0
      for (i=0;i<gCC_NextFreeSegment;i++) { // Find cal set 
        if (a>=SEGMENT_FLASH_PTR(i) && a<SEGMENT_FLASH_PTR(i)+SEGMENT_SIZE(i)) {
          o = SEGMENT_RAM_PTR(i)-SEGMENT_FLASH_PTR(i); // Calculate address offset 
          return *(vuint8*)(a+o);	// Read directly from OVRAM
        }
      }
	  #endif
	}

  }  // FLASH address 

  return *(vuint8*)a; // Normal read
}


static vuint8 XCP_FAR write( vuint32 a, vuint8 d ) {

  vuint32 o,i;

  // XCP write access to RAM
  if ((a&0xD0000000)==0x80000000 && gCC_XCP_CalPage==CALPAGE_RAM) {

    // ECU access redirected to RAM
	if (gCC_ECU_CalPage==CALPAGE_RAM) {

        *(vuint8*)a = d;
		if (*(volatile vuint8*)a == d) return XCP_CMD_OK; // Write access successfull or no change 

        // Allocate a new overlay
        if (XcpCalSetLocked) {
          #ifdef XCP_ENABLE_SERV_TEXT_PRINT    
            XcpPrintf("@E: Error: Calibration memory locked by VX1000!\n");
		  #endif
          return XCP_CMD_DENIED;
        }
        if ((!redirectCalSet(a))) { // Error: Out of calibration memory
          return XCP_CMD_DENIED;
        }
        *(vuint8*)a = d; // Write access should be possible now
		return XCP_CMD_OK;
	} // ECU access redirected to RAM

    // ECU access not redirected, ECU accesses FLASH
	else {

		if (*(volatile vuint8*)a == d) return XCP_CMD_OK; // No change in FLASH, ignore this access

	    // Find if address is within an already overlaid segment
		o = 0;
	    for (i=0;i<gCC_NextFreeSegment;i++) { 
	      if (a>=SEGMENT_FLASH_PTR(i) && a<SEGMENT_FLASH_PTR(i)+CC_SEGMENT_SIZE) {
	        o = SEGMENT_RAM_PTR(i)-SEGMENT_FLASH_PTR(i); // Calculate address offset 
	        break;
	      }
	    }
        if (i==gCC_NextFreeSegment) { // No segment found

          // Allocate a new overlay
	      if (XcpCalSetLocked) {
            #ifdef XCP_ENABLE_SERV_TEXT_PRINT    
	          XcpPrintf("@E: Error: Calibration memory locked by VX1000!\n");
			#endif
	        return XCP_CMD_DENIED;
	      }
	      if ((!redirectCalSet(a))) { // Error: Out of calibration memory
	        return XCP_CMD_DENIED;
	      }
	      o = SEGMENT_RAM_PTR(i)-SEGMENT_FLASH_PTR(i); // Calculate address offset for the new segment
	    }

        *(vuint8*)(a+o) = d; // Write directly to OVRAM because ECU is not redirected to RAM
        return XCP_CMD_OK;
    
	 } // ECU access not redirected

  } // XCP write access to RAM


  *(vuint8*)a = d; // Normal write
  return XCP_CMD_OK;
}

vuint8 ApplXcpCalibrationWrite(MTABYTEPTR addr, vuint8 size, MEMORY_ROM BYTEPTR data) {

  vuint8 r;

  while ( size > 0 ) {
    r = write( (vuint32)addr, *data );
	if (r!=XCP_CMD_OK) return r;
    addr++;
    data++;
    size--;
  }
  return XCP_CMD_OK;
}

vuint8 ApplXcpCalibrationRead(MTABYTEPTR addr, vuint8 size, BYTEPTR data) {

  while (size > 0)
  {
    *data = read( (vuint32)addr );
    data++;
    addr++;
    size--;
  }
  return XCP_CMD_OK;
}

#if defined ( XCP_ENABLE_CHECKSUM )
tXcpChecksumAddType ApplXcpReadChecksumValue( vuint32 a ) {

  tXcpChecksumAddType s;

  ApplXcpCalibrationRead((MTABYTEPTR)a,sizeof(tXcpChecksumAddType),(BYTEPTR)&s);
  return s; 
}
#endif



vuint8 ApplXcpGetCalPage( vuint8 segment, vuint8 mode ) {

  // Segment number is ignored
  #ifndef IGNORE_SEGMENT_NUMBER
    if (segment!=0) return CRC_SEGMENT_NOT_VALID; // Only segment 0 allowed
  #endif

  if ((mode&(CAL_ECU|CAL_XCP))==CAL_XCP) return gCC_XCP_CalPage;
  return gCC_ECU_CalPage; 
}


vuint8 ApplXcpSetCalPage( vuint8 segment, vuint8 page, vuint8 mode ) 
{

  // Segment number is ignored
  #ifndef IGNORE_SEGMENT_NUMBER
    if (segment!=0) return CRC_SEGMENT_NOT_VALID; // Only segment 0 allowed
  #endif

  if (!(mode&CAL_ALL)) return CRC_OUT_OF_RANGE; // Mode must be CAL_ALL (all segments)
  if (page>1) return CRC_PAGE_NOT_VALID; // Page may be 0=FLASH or 1=RAM

  if ((mode&(CAL_ECU|CAL_XCP))==(CAL_ECU|CAL_XCP)) { // Switch ECU and XCP access
	  if (page!=gCC_ECU_CalPage) {
	    if (page==CALPAGE_RAM) { // RAM
	      _OVC_OCON = gCC_FlashOverlayActiveMask;
	      _OVC_OCON = gCC_FlashOverlayActiveMask | 0x00050000; // DCINVAL|OVSTRT  Start overlay
	    } else {
	      _OVC_OCON = gCC_FlashOverlayActiveMask | 0x00060000;  // DCINVAL|OVSTP Stop overlay
	    }
	    gCC_XCP_CalPage = page;
	    gCC_ECU_CalPage = page;
	  } 
  }
  else if (mode&CAL_ECU) { // Switch only ECU access
	  if (page!=gCC_ECU_CalPage) {
	    if (page==CALPAGE_RAM) { // RAM
	      _OVC_OCON = gCC_FlashOverlayActiveMask;
	      _OVC_OCON = gCC_FlashOverlayActiveMask | 0x00050000; // DCINVAL|OVSTRT  Start overlay
	    } else {
	      _OVC_OCON = gCC_FlashOverlayActiveMask | 0x00060000;  // DCINVAL|OVSTP Stop overlay
	    }
	    gCC_ECU_CalPage = page;
	  } 
  }
  else if (mode&CAL_XCP) { // Switch only XCP access
    gCC_XCP_CalPage = page;   
  }

  return 0;
}


vuint8 ApplXcpCopyCalPage( vuint8 srcSeg, vuint8 srcPage, vuint8 dstSeg, vuint8 dstPage ) {

  // Segment number is ignored
  #ifndef IGNORE_SEGMENT_NUMBER
    if (srcSeg!=0 || dstSeg!=0) return CRC_SEGMENT_NOT_VALID; // Only segment 0 allowed
  #endif

  // Check parameters
  // Only copy from RAM to FLASH makes sense
  if (dstPage==srcPage) return CRC_PAGE_NOT_VALID; // Can not copy on itself
  if (dstPage==0) return CRC_ACCESS_DENIED; // Can not copy to FLASH page 

  // Reinit and reset overlays
  // Keep the current calpage status
  ovc_init();
  gCC_NextFreeSegment = 0;
  gCC_FlashOverlayActiveMask = 0;

  return 0; // Ok
}


void ApplXcpInit( void ) {

  // Reset calibration memory
  gCC_NextFreeSegment = 0;
  gCC_FlashOverlayActiveMask = 0;
  if (!XcpCalSetLocked) {
    ovc_init();
  }
  gCC_XCP_CalPage = CALPAGE_RAM; // RAM
  gCC_ECU_CalPage = CALPAGE_RAM; // RAM
}



#endif // XCP_CC_TC_OVRAM       
