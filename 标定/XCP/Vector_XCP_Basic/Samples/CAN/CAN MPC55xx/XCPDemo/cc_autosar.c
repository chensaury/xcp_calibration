//-------------------------------------------------------------------------------
// CC_AUTOSAR.C
// AUTOSAR calibration concept support
// Version 1.1 13.5.2011
// Vector Informatik GmbH
//-------------------------------------------------------------------------------

													
#include "project.h"

//-------------------------------------------------------------------------------
// AUTOSAR calibration concept (calibration set redirection)

#if defined(CC_AUTOSAR) || defined(CC_INCIRCUIT)

#include "cc_autosar.h"


#ifdef CC_TRICORE		
  #pragma section all "cal_data"
  #define CC_FLASH_ATTRIBUTE
  #define CC_RAM_ATTRIBUTE
#endif	
#ifdef CC_PPC
  // Attribute for original pointer table, size table and descriptor in flash
  #define CC_FLASH_ATTRIBUTE __attribute__((section("calflash_signature")))
  // Attribute for reprogrammable incircuit flash pointer table 
  #define CC_FLASH_INCIRCUIT_ATTRIBUTE __attribute__((section("calflash_incircuit")))   
  // Attribute for calibration ram
  #define CC_RAM_ATTRIBUTE __attribute__((section("ccram")))
#endif  
						 
#define CC_SET_COUNT sizeof(gCC_SetSizeFlashTable)/2

// Calibration Set Pointer Table in FLASH
//-----------------------------------------------
CC_FLASH_ATTRIBUTE const struct CC_SetPtrFlashTable gCC_SetPtrFlashTable = { 
	#ifdef CC_SET_1
	  &CC_SET_1,		 
	#endif
	#ifdef CC_SET_2
	  &CC_SET_2,
	#endif
	#ifdef CC_SET_3
	  &CC_SET_3, 
	#endif
	#ifdef CC_SET_4
	  &CC_SET_4, 
	#endif
	#ifdef CC_SET_5
	  &CC_SET_5, 
	#endif
	#ifdef CC_SET_6
	  &CC_SET_6, 
	#endif
};
#define CC_SetPtrFlashTable_ADDR  (unsigned int)&gCC_SetPtrFlashTable

// Original Calibration Set Size Table in FLASH
//-----------------------------------------------
CC_FLASH_ATTRIBUTE const struct CC_SetSizeFlashTable gCC_SetSizeFlashTable =  { 
	#ifdef CC_SET_1
	  sizeof(struct CC_SET_1), 
	#endif
	#ifdef CC_SET_2
	  sizeof(struct CC_SET_2), 
	#endif
	#ifdef CC_SET_3
	  sizeof(struct CC_SET_3), 
	#endif
	#ifdef CC_SET_4
	  sizeof(struct CC_SET_4), 
	#endif
	#ifdef CC_SET_5
	  sizeof(struct CC_SET_5), 
	#endif
	#ifdef CC_SET_6
	  sizeof(struct CC_SET_6), 
	#endif
};
#define CC_SetSizeFlashTable_ADDR  (unsigned int)&gCC_SetSizeFlashTable

#ifdef CC_TRICORE		
  #pragma section all
#endif		


// Calibration Set Pointer Table in RAM or FLASH 
// depending on the calibration concept
//-----------------------------------------------
#if defined(CC_INCIRCUIT)

  #ifdef CC_TRICORE		
    #pragma section all "cal_ptr_data"
  #endif	

  // Pointer table in FLASH
  CC_FLASH_INCIRCUIT_ATTRIBUTE const struct CC_SetPtrRamTable gCC_SetPtrRamTable = {
  
#else
  
  // Pointer table in RAM
  #if defined(CC_CALRAM_ADDR) && defined(CC_TRICORE)
    struct CC_SetPtrRamTable gCC_SetPtrRamTable __at(CC_RAM_TABLE_ADDR) = {
  #else
    CC_RAM_ATTRIBUTE struct CC_SetPtrRamTable gCC_SetPtrRamTable = {
  #endif

#endif 

	#ifdef CC_SET_1
	  (volatile struct CC_SET_1 *)&CC_SET_1, 	
	#endif
	#ifdef CC_SET_2
	  (volatile struct CC_SET_2 *)&CC_SET_2, 
	#endif
	#ifdef CC_SET_3
	  (volatile struct CC_SET_3 *)&CC_SET_3, 
	#endif
	#ifdef CC_SET_4
	  (volatile struct CC_SET_4 *)&CC_SET_4, 
	#endif
	#ifdef CC_SET_5
	  (volatile struct CC_SET_5 *)&CC_SET_5, 
	#endif
	#ifdef CC_SET_6
	  (volatile struct CC_SET_6 *)&CC_SET_6, 
	#endif
};
#define CC_SetPtrRamTable_ADDR  (unsigned int)&gCC_SetPtrRamTable

#ifdef CC_TRICORE		
  #pragma section all "cal_ptr_data"
#endif	

// Double pointer
//-----------------------------------------------
#ifdef CC_DOUBLE_POINTERED
  struct CC_SetPtrRamTable *gCC_Pointer = (struct CC_SetPtrRamTable *)&gCC_SetPtrFlashTable;	// Startup page is FLASH
  #define CC_DoublePtr_ADDR (unsigned int)&gCC_Pointer    
#else 
  #define CC_DoublePtr_ADDR 
#endif

// Calibration RAM
//-----------------------------------------------
#ifdef CC_CALRAM_SIZE
  #if defined(CC_CALRAM_ADDR) && defined(CC_TRICORE)
    CC_UINT32 gCC_Ram[(CC_CALRAM_SIZE-1)/4+1] __at(CC_CALRAM_ADDR);
  #else
    CC_RAM_ATTRIBUTE CC_UINT32 gCC_Ram[(CC_CALRAM_SIZE-1)/4+1];
  #endif
#define CC_CALRAM_PTR (unsigned int)&gCC_Ram[0]
CC_UINT8 gCC_RamValid = 0; // Calibration RAM invalid, not initialized yet 
#else
  #define CC_CALRAM_PTR 0
  #define CC_CALRAM_SIZE 0
#endif

// Calibration concept info structure in FLASH
//-----------------------------------------------
CC_FLASH_ATTRIBUTE const CC_T gCC = { 
  CC_MAGIC, 
  CC_VERSION, 
  0U
  #ifdef CC_INCIRCIUT
    |CC_FLAG_INCIRCUIT
  #endif
  #ifdef CC_DOUBLE_POINTERED
    |CC_FLAG_DOUBLE_POINTERED
  #endif
  ,  
  CC_CALRAM_PTR, 
  CC_CALRAM_SIZE, 
  CC_SET_COUNT, 
  CC_SetSizeFlashTable_ADDR, 
  CC_SetPtrFlashTable_ADDR, 
  CC_SetPtrRamTable_ADDR,
  CC_DoublePtr_ADDR
};



//-------------------------------------------------------------------------------
// Functions

// Some definitions taken from Vector XCP Driver
#define CAL_ECU                 0x01
#define CAL_XCP                 0x02
#define CAL_ALL                 0x80        

#define CRC_CMD_UNKNOWN         0x20
#define CRC_CMD_SYNTAX          0x21
#define CRC_OUT_OF_RANGE        0x22
#define CRC_WRITE_PROTECTED     0x23
#define CRC_ACCESS_DENIED       0x24
#define CRC_ACCESS_LOCKED       0x25
#define CRC_PAGE_NOT_VALID      0x26
#define CRC_PAGE_MODE_NOT_VALID 0x27
#define CRC_SEGMENT_NOT_VALID   0x28
#define CRC_MEMORY_OVERFLOW     0x30
#define CRC_GENERIC             0x31
#define CRC_VERIFY              0x32


static CC_UINT8 cc_copy_flash_to_ram( void ) {

  CC_UINT32 i,p_ram,p_flash;
  CC_UINT16 p_size;

  // Clear the calibration RAM
  memset((void*)gCC_Ram,0,sizeof(gCC_Ram));
   
  // Loop over all calibration set pointers	and initialize the calibration RAM if used
  // This is needed for the incircuit calibration concept, were the pointers to RAM are in FLASH and be persistent
  for (i=0;i<CC_SET_COUNT;i++) {
  	p_ram = ((CC_UINT32*)&gCC_SetPtrRamTable)[i];
  	p_flash = ((CC_UINT32*)&gCC_SetPtrFlashTable)[i];
  	p_size = ((CC_UINT16*)&gCC_SetSizeFlashTable)[i];
  	if (p_ram!=p_flash) {
  	  if (p_ram>=(CC_UINT32)&gCC_Ram && p_ram<(CC_UINT32)&gCC_Ram+sizeof(gCC_Ram)) {
  	    // Initialize
          memcpy((void*)p_ram,(void*)p_flash,p_size);
  	  } 
  	  else {
       	#ifdef CC_AUTOSAR
      	  // Initialize the RAM pointer to FLASH
    	    ((CC_UINT32*)&gCC_SetPtrRamTable)[i] = ((CC_UINT32*)&gCC_SetPtrFlashTable)[i];
        #else
    	    // Illegal calibration set pointer entry
          return 0;
        #endif
  	  }
  	}
  }

  return 1;
}

// Init 
void cc_init_cal_page( void ) {

  CC_UINT32 i;

  // Switch to FLASH page
  gCC_RamValid = 0;
  cc_set_cal_page(0,0,CAL_ALL|CAL_ECU|CAL_XCP); 

  // Initialize RAM
  if (!cc_copy_flash_to_ram()) {

    // Illegal calibration set pointer entry
  	#ifdef CC_INCIRCUIT
  	  #ifdef CC_DOUBLE_POINTERED
          // Stay on FLASH page
  	    return; // Invalid RAM pointers, switching to RAM inhibited (gCC_RamValid=0)
  	  #else
  	    // Don't know how to resolve this problem
        // Flash pointer array is inconsistent
  		  for (;;);
  	  #endif
  	#endif
  }

  // Switch to RAM page
  gCC_RamValid = 1;
  cc_set_cal_page(0,1,CAL_ALL|CAL_ECU|CAL_XCP); 
}
  
// Get active page
CC_UINT8 cc_get_cal_page( CC_UINT8 segment, CC_UINT8 mode ) {

  // Segment number is ignored
  #ifndef IGNORE_SEGMENT_NUMBER
    if (segment!=0) return CRC_SEGMENT_NOT_VALID; // Only segment 0 allowed
  #endif

  return gCC_Pointer==&gCC_SetPtrRamTable;  // Page may be 0=FLASH or 1=RAM
}

// Set active page
CC_UINT8 cc_set_cal_page( CC_UINT8 segment, CC_UINT8 page, CC_UINT8 mode ) 
{

  // Segment number is ignored
  #ifndef IGNORE_SEGMENT_NUMBER
    if (segment!=0) return CRC_SEGMENT_NOT_VALID; // Only segment 0 allowed
  #endif

  if (!(mode&CAL_ALL)) return CRC_OUT_OF_RANGE; // Mode must be CAL_ALL (all segments)
  if (page>1) return CRC_PAGE_NOT_VALID; // Page may be 0=FLASH or 1=RAM

  // Simultanious access
  if ((mode&(CAL_ECU|CAL_XCP))==(CAL_ECU|CAL_XCP)) { // Switch ECU and XCP access
     if (page==1) { // RAM
       if (gCC_RamValid==0) return CRC_PAGE_NOT_VALID;
	   gCC_Pointer = (struct CC_SetPtrRamTable *)&gCC_SetPtrRamTable;
     } else {                 // FLASH
	   gCC_Pointer = (struct CC_SetPtrRamTable *)&gCC_SetPtrFlashTable;
     } 
  }

  // Independant access not implemented
  else if (mode&CAL_ECU) { // Switch only ECU access
	  return CRC_OUT_OF_RANGE;
  }
  else if (mode&CAL_XCP) { // Switch only XCP access
	  return CRC_OUT_OF_RANGE;
  }

  return 0;
}

// Copy page
CC_UINT8 cc_copy_cal_page( CC_UINT8 srcSeg, CC_UINT8 srcPage, CC_UINT8 dstSeg, CC_UINT8 dstPage ) {

  // Segment number is ignored
  #ifndef IGNORE_SEGMENT_NUMBER
    if (srcSeg!=0 || dstSeg!=0) return CRC_SEGMENT_NOT_VALID; // Only segment 0 allowed
  #endif

  // Check parameters
  // Only copy from FLASH to RAM makes sense
  if (dstPage==srcPage) return CRC_PAGE_NOT_VALID; // Can not copy on itself
  if (dstPage==0) return CRC_ACCESS_DENIED; // Can not copy to FLASH page 

  if (!cc_copy_flash_to_ram()) {
    return CRC_GENERIC;
  }

  return 0;
}

#endif
