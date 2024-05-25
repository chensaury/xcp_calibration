//-------------------------------------------------------------------------------
// CC_AUTOSAR.H
// AUTOSAR calibration concept support
// Version 1.1 13.5.2011
// Vector Informatik GmbH
//-------------------------------------------------------------------------------

#ifndef __CC_AUTOSAR_H__
#define __CC_AUTOSAR_H__

#if defined(CC_AUTOSAR) || defined(CC_INCIRCUIT)

#define CC_UINT8   unsigned char
#define CC_UINT16  unsigned short
#define CC_UINT32  unsigned int

// Calibration concept info struct
#define CC_MAGIC                 0x11353954
#define CC_VERSION               0x0100
#define CC_FLAG_INCIRCUIT        0x0001
#define CC_FLAG_DOUBLE_POINTERED 0x0002
typedef struct {
  unsigned int MagicId;
  unsigned short Version;             
  unsigned short Flags;             
  unsigned int MemoryAddr;         
  unsigned int MemorySize;
  unsigned int SetCount;
  unsigned int SetSizeFlashTableAddr;  
  unsigned int SetPtrFlashTableAddr;
  unsigned int SetPtrRamTableAddr;
  unsigned int DoublePtrAddr;
  unsigned int res1;
  unsigned int res2;
  unsigned int res3;
  unsigned int res4;
  unsigned int res5;
  unsigned int res6;
  unsigned int res7;
} CC_T;

// Declaration of the Calibration Set Pointer Table in FLASH
struct CC_SetPtrFlashTable {
	#ifdef CC_SET_1
	  volatile const struct CC_SET_1 *CC_SET_1;
	#endif
	#ifdef CC_SET_2
	  volatile const struct CC_SET_2 *CC_SET_2;
	#endif
	#ifdef CC_SET_3
	  volatile const struct CC_SET_3 *CC_SET_3;
	#endif
	#ifdef CC_SET_4
	  volatile const struct CC_SET_4 *CC_SET_4;
	#endif
	#ifdef CC_SET_5
	  volatile const struct CC_SET_5 *CC_SET_5;
	#endif
	#ifdef CC_SET_6
	  volatile const struct CC_SET_6 *CC_SET_6;
	#endif
};  

// Declaration of the Calibration Set Size Table in FLASH
struct CC_SetSizeFlashTable{
	#ifdef CC_SET_1
	  unsigned short s1;
	#endif
	#ifdef CC_SET_2
	  unsigned short s2;
	#endif
	#ifdef CC_SET_3
	  unsigned short s3;
	#endif
	#ifdef CC_SET_4
	  unsigned short s4;
	#endif
	#ifdef CC_SET_5
	  unsigned short s5;
	#endif
	#ifdef CC_SET_6
	  unsigned short s6;
	#endif
};
        

// Declaration of the Calibration Set Pointer Table in RAM
struct CC_SetPtrRamTable {
	#ifdef CC_SET_1
	  volatile struct CC_SET_1 *CC_SET_1;	  
	#endif
	#ifdef CC_SET_2
	  volatile struct CC_SET_2 *CC_SET_2;	
	#endif
	#ifdef CC_SET_3
	  volatile struct CC_SET_3 *CC_SET_3;
	#endif
	#ifdef CC_SET_4
	  volatile struct CC_SET_4 *CC_SET_4;	  
	#endif
	#ifdef CC_SET_5
	  volatile struct CC_SET_5 *CC_SET_5;	
	#endif
	#ifdef CC_SET_6
	  volatile struct CC_SET_6 *CC_SET_6;
	#endif
};

#if defined(CC_AUTOSAR)

// Pointer Table in RAM
extern struct CC_SetPtrRamTable gCC_SetPtrRamTable;
extern struct CC_SetPtrRamTable gCC_SetPtrRamBackupTable;

#endif

#if defined(CC_INCIRCUIT)

// Pointer Table in FLASH
extern const struct CC_SetPtrRamTable gCC_SetPtrRamTable;

#endif

// Double pointer
#ifdef CC_DOUBLE_POINTERED
  extern struct CC_SetPtrRamTable *gCC_Pointer;
#endif

// FLASH
extern const struct CC_SetPtrFlashTable gCC_SetPtrFlashTable;
extern const struct CC_SetSizeFlashTable gCC_SetSizeFlashTable;
extern const CC_T gCC;


// CALRAM
#ifdef CC_CALRAM_SIZE
 extern unsigned int gCC_Ram[(CC_CALRAM_SIZE-1)/4+1];
#endif

// Functions
extern void cc_init_cal_page( void ); 
extern CC_UINT8 cc_get_cal_page( CC_UINT8 segment, CC_UINT8 mode ); 
extern CC_UINT8 cc_set_cal_page( CC_UINT8 segment, CC_UINT8 page, CC_UINT8 mode);
extern CC_UINT8 cc_copy_cal_page( CC_UINT8 srcSeg, CC_UINT8 srcPage, CC_UINT8 destSeg, CC_UINT8 destPage );

#endif
#endif


