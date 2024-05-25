/*****************************************************************************
| Project Name:   XCP V1.0 - Driver
|    File Name:   xcp_cc_xxxx.c
|
|  Description: 
|   This module demonstrates how to implemtent a calibration concept with 
|   FLASH overlays created on demand.
|	It uses the 8KByte Tricore OVRAM in 16 512Byte segments
|   It can be easily enhanced to use Tricore EMEM
|***************************************************************************/

#include "project.h"
             
#ifdef XCP_CC_PPC_MMU


/*
Needs the below XCP driver functions enabled:

#define XCP_ENABLE_CALIBRATION
#define XCP_ENABLE_MEM_ACCESS_BY_APPL
#define XCP_ENABLE_CALIBRATION_PAGE
#define XCP_ENABLE_PAGE_COPY

It is recomended to enable text messages to get additional information 
on failed memory accesses

#define XCP_ENABLE_SERV_TEXT_PRINT

*/


//------------------------------------------------------------------------------
  
#define CALFLASH_ADDR     0x00180000  // FLASH overlay address
#define CALRAM_SIZE       0x40000     // FLASH overlay size 256K 
#define CALRAM_ADDR       0x3FFC0000  // External RAM address
#define CALRAM_TLB        8           // Number of the TLB entry used to define 256K FLASH at 0x00180000


#define CALPAGE_RAM 1
#define CALPAGE_FLASH 0
static vuint8 gCC_XCP_CalPage = CALPAGE_RAM; // RAM
static vuint8 gCC_ECU_CalPage = CALPAGE_RAM; // RAM

unsigned char MMUWriteTLBEntry(
  unsigned char n, 
  unsigned int ea, 
  unsigned int ra, 
  unsigned int pagesize, 
  unsigned char cache_inhibit, 
  unsigned char cache_writethrough,
  unsigned char permissions) {  

  unsigned int rpn,epn;
  unsigned char pagetype,pageshift;
  
  switch (pagesize) {
    case 0x001000: pagetype = 1; pageshift = 12; break; // 4 K
    case 0x004000: pagetype = 2; pageshift = 14; break; // 16 K
    case 0x010000: pagetype = 3; pageshift = 16; break; // 64 K
    case 0x040000: pagetype = 4; pageshift = 18; break; // 256 K
    case 0x100000: pagetype = 5; pageshift = 20; break; // 1M
    default: return 0;
  }

  if ((ra%pagesize) || (ea%pagesize)) return 0;                         
  rpn = ra/pagesize;
  epn = ea/pagesize;
   
  /* Select TLB entry */
  mtMAS0(0x10000000|(n<<16));

  /* Define description context and configuration control:*/
  /* VALID=1, IPROT=0, TID=0, TS=0, TSIZE=pagetype */
  mtMAS1(0x80000000|(pagetype<<8)); 

  /* Define EPN and page attributes: */
  /* EPN = 0x06000 (addr=0x60000000), WIMAGE = xx000 */
  mtMAS2((epn<<pageshift) | (cache_inhibit?0x8:0) | (cache_writethrough?0x10:0)); 
 
  /* Define RPN and access control for data R/W */
  /* RPN = , U0:3=0, UX/SX=0, UR/SR=1, UW/SW=1 */
  mtMAS3((rpn<<pageshift)|(0x3F&permissions)); 

  asm("tlbwe"); /* Write entry defined in MAS0 to MMU TLB */
  // tlbwe();

  return 1;
}


static vuint8 read( vuint32 a ) {

  // Address within mapped area
  if (a>=CALFLASH_ADDR && a<CALFLASH_ADDR+CALRAM_SIZE) { // Read from a FLASH address

    vuint8 r;

    //  XCP reads from FLASH and hardware address translation is turned on (ECU cal page is RAM)  
    if (gCC_XCP_CalPage==CALPAGE_FLASH && gCC_ECU_CalPage==CALPAGE_RAM) {
      // Map FLASH, cache inhibit, RWE */
      MMUWriteTLBEntry(CALRAM_TLB,CALFLASH_ADDR,CALFLASH_ADDR,CALRAM_SIZE,1,1,0x3F);
      r = *(vuint8*)(a);  // Read from FLASH
      // Map RAM over FLASH, cache inhibit, RWE */
      MMUWriteTLBEntry(CALRAM_TLB,CALFLASH_ADDR,CALRAM_ADDR,CALRAM_SIZE,1,1,0x3F);
	    return r;
	  }

    //  XCP reads from RAM and hardware address translation is turned off (ECU cal page is FLASH)
    if (gCC_XCP_CalPage==CALPAGE_RAM && gCC_ECU_CalPage==CALPAGE_FLASH) {
      r = *(vuint8*)(a-CALFLASH_ADDR+CALRAM_ADDR);  // Read from RAM
   	  return r;
  	}

  } 

  return *(vuint8*)a; // Normal read
}


static vuint8 write( vuint32 a, vuint8 d ) {

  // Address within mapped area
  if (a>=CALFLASH_ADDR && a<CALFLASH_ADDR+CALRAM_SIZE) { // Read from a FLASH address

    vuint8 r;

    //  XCP writes to FLASH 
    if (gCC_XCP_CalPage==CALPAGE_FLASH) {
      return XCP_CMD_OK; // Ignore
	  }

    //  XCP writes to RAM
    else {
      *(vuint8*)(a-CALFLASH_ADDR+CALRAM_ADDR) = d;  // Write to RAM
   	  return XCP_CMD_OK;
  	}

  } 

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

  if ((mode&(CAL_ECU|CAL_XCP))==CAL_ECU) return gCC_ECU_CalPage;
  if ((mode&(CAL_ECU|CAL_XCP))==CAL_XCP) return gCC_XCP_CalPage;
  return gCC_ECU_CalPage; // Should not happen
}


vuint8 ApplXcpSetCalPage( vuint8 segment, vuint8 page, vuint8 mode ) 
{
  if (segment!=0) return CRC_OUT_OF_RANGE; // Only one segment supported
  if (page>1) return CRC_PAGE_NOT_VALID; 

  if ((mode&(CAL_ECU|CAL_XCP))==(CAL_ECU|CAL_XCP)) {
	  if (page!=gCC_ECU_CalPage) {
	    if (page==CALPAGE_RAM) { // RAM
        // Map RAM over FLASH, cache inhibit, RWE */
        MMUWriteTLBEntry(CALRAM_TLB,CALFLASH_ADDR,CALRAM_ADDR,CALRAM_SIZE,1,1,0x3F);
	    } else {
        // Map FLASH, cache inhibit, RWE */
        MMUWriteTLBEntry(CALRAM_TLB,CALFLASH_ADDR,CALFLASH_ADDR,CALRAM_SIZE,1,1,0x3F);
	    }
	    gCC_XCP_CalPage = page;
	    gCC_ECU_CalPage = page;
	  } 
  }
  else if (mode&CAL_ECU) {
	  if (page!=gCC_ECU_CalPage) {
	    if (page==CALPAGE_RAM) { // RAM
        // Map RAM over FLASH, cache inhibit, RWE */
        MMUWriteTLBEntry(CALRAM_TLB,CALFLASH_ADDR,CALRAM_ADDR,CALRAM_SIZE,1,1,0x3F);
	    } else {
        // Map FLASH, cache inhibit, RWE */
        MMUWriteTLBEntry(CALRAM_TLB,CALFLASH_ADDR,CALFLASH_ADDR,CALRAM_SIZE,1,1,0x3F);
	    }
	    gCC_ECU_CalPage = page;
	  } 
  }
  else if (mode&CAL_XCP) {
    gCC_XCP_CalPage = page;   
  }

  return 0;
}


vuint8 ApplXcpCopyCalPage( vuint8 srcSeg, vuint8 srcPage, vuint8 dstSeg, vuint8 dstPage ) {


  // Check parameters
  // Only copy from RAM to FLASH makes sense
  if (srcSeg!=0 || dstSeg!=0) return CRC_SEGMENT_NOT_VALID; // Segments are not supported
  if (dstPage==srcPage) return CRC_PAGE_NOT_VALID; // Can not copy on itself
  if (dstPage==0) return CRC_ACCESS_DENIED; // Can not copy to FLASH page 

  // Initialize CALRAM, copy from FLASH to RAM
  // Turn mapping of, if needed
  if (gCC_ECU_CalPage==CALPAGE_RAM) {
    ApplXcpSetCalPage(0,CALPAGE_FLASH,CAL_ECU);
    memcpy((void*)CALRAM_ADDR,(void*)CALFLASH_ADDR,CALRAM_SIZE);
    ApplXcpSetCalPage(0,CALPAGE_RAM,CAL_ECU);
  } else {
    memcpy((void*)CALRAM_ADDR,(void*)CALFLASH_ADDR,CALRAM_SIZE);
  }

  return 0; // Ok
}


void ApplXcpInit( void ) {

  // Initialize CALRAM
  memcpy((void*)CALRAM_ADDR,(void*)CALFLASH_ADDR,CALRAM_SIZE);
  // Map RAM over FLASH, cache inhibit, RWE */
  if (!MMUWriteTLBEntry(CALRAM_TLB,CALFLASH_ADDR,CALRAM_ADDR,CALRAM_SIZE,1,1,0x3F)) {
    FatalError();
  }

  gCC_XCP_CalPage = CALPAGE_RAM; // RAM
  gCC_ECU_CalPage = CALPAGE_RAM; // RAM
}



#endif // XCP_CC_PPC_MMU       
