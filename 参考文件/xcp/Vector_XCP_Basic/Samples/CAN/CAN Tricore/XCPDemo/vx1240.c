//-------------------------------------------------------------------------------
// VX1240.C
// Program instrumentation for Vector VXS with VX1240 Tricore DAP ECU Interface
// Parameters defined in VX1240_CFG.H
// Version 1.9 15.10.2010
// Vector Informatik GmbH
//-------------------------------------------------------------------------------

#include "VX1240.H"

#if VX1000_FILE_VERSION!=0x0109
  #error "version of vx1240.h does not match version of vx1240.c!"
#endif


//-------------------------------------------------------------------------------
// Bypassing

#ifdef VX1000_STIM

static unsigned int sTimeout;
#define VX1000_RESET_TIMEOUT(timeout) sTimeout = VX1000_CLOCK + ((unsigned int)timeout*VX1000_CLOCK_TICKS_PER_MS);
#define VX1000_CHECK_TIMEOUT() ((int)(VX1000_CLOCK - sTimeout)>0)



// Initialize the STIM data structure
void VX1000_STIM_INITIALIZE(void) { 

  unsigned int i;

  gVX1000_STIM.Version = 0; 
  gVX1000_STIM.Control = 0; 
  gVX1000_STIM.EvtOffset = VX1000_STIM_EVENT_OFFSET; 
  gVX1000_STIM.EvtNumber = VX1000_STIM_EVENT_COUNT; 
  gVX1000_STIM.Control = 0; \
  for (i=0;i<VX1000_STIM_EVENT_COUNT;i++) { 
    gVX1000_STIM.Event[i].Ctr = 0; 
    gVX1000_STIM.Event[i].RqCtr = 0; 
    gVX1000_STIM.Event[i].Enable = 0; 
    gVX1000_STIM.Event[i].Copying = 0; 
  } 
  gVX1000_STIM.MagicId = VX1000_STIM_MAGIC; 
  gVX1000_STIM_Timeout_Ctr = 0; 
  gVX1000_STIM_Enable = 0; 

  #ifdef VX1000_STIM_BENCHMARK
  {
    unsigned int i;
    for (i=0;i<32;i++) gVX1000_STIM_Duration[i] = 0;
  }
  #endif
}


// Stim Handler
void VX1000_STIM_CONTROL(void) {

  if (gVX1000_STIM.Control && gVX1000_STIM_Enable==0) {
    #ifdef VX1000_STIM_TYPE_0    
      VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_ACK); // Send an acknowledge STIM event when the ECU is ready for STIM 
    #endif
    gVX1000_STIM_Enable = 1;
  }
  else if (gVX1000_STIM.Control==0 && gVX1000_STIM_Enable==1) {
    VX1000_STIM_INIT; // Reinitialize STIM when VX1100 turn STIM off
  }
  
}



// Wait until a specific STIM request is fullfilled
void VX1000_STIM_WAIT(unsigned char e, unsigned int timeout) {

  #ifdef VX1000_STIM_BENCHMARK
    unsigned int t0 = VX1000_CLOCK;
  #endif

  // Busy wait until stimulation is done
  VX1000_RESET_TIMEOUT(timeout);
  while (gVX1000_STIM.Event[e-VX1000_STIM_EVENT_OFFSET].Ctr!=gVX1000_STIM.Event[e-VX1000_STIM_EVENT_OFFSET].RqCtr) {
    
    // Check for timeout
    if (VX1000_CHECK_TIMEOUT()) {
      
      // Check if stim data is currently beeing copied
      // Wait another 1 ms to complete copying
      if (gVX1000_STIM.Event[e-VX1000_STIM_EVENT_OFFSET].Copying) {
        VX1000_RESET_TIMEOUT(1);
        while (gVX1000_STIM.Event[e-VX1000_STIM_EVENT_OFFSET].Ctr!=gVX1000_STIM.Event[e-VX1000_STIM_EVENT_OFFSET].RqCtr); {
          if (VX1000_CHECK_TIMEOUT()) {
            VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_ERR(e)); 
            goto timeout;
          }
        }
        break;
      }
      
      // If data is not beeing copied yet, inform the VX1121 about the timeout 
      else {
        if (VX1000_STIM_ACTIVE(e)) VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_TIMEOUT(e));
        goto timeout;
      }
      
    } // Timeout

  } // While
  goto exit;
   
timeout:

  gVX1000_STIM_Timeout_Ctr++;
  
exit:  

  #ifdef VX1000_STIM_BENCHMARK
    gVX1000_STIM_Duration[e] = VX1000_CLOCK-t0; // Timing measurement
  #endif

  return;
}


// Event number daq_event is the bypass stimulation event, it indicates that the ECU is now waiting for completion of the stimulation
// Event number stim_event is the bypass trigger event, it should be used to trigger calculation of the bypass in the tool, as long as the bypass is not activated in the tool, this event is not executed                                  
// Return 1, if the bypass is active and the bypassed code has to be disabled
unsigned char VX1000_BYPASS( unsigned char daq_event, unsigned char stim_event, unsigned int timeout) {

	if (VX1000_STIM_ACTIVE(stim_event)) {
	  VX1000_EVENT(daq_event);
	  VX1000_STIM_REQUEST(stim_event);
	  VX1000_STIM_WAIT(stim_event,timeout);
	  return 1;	// Disable the bypassed code
	}
	else {
	  return 0;	// Enable the bypassed code
	}
}

#endif


//-------------------------------------------------------------------------------
// Measurement data acquisition


// Copy routine
// Event number is limited to 0..30, event number 31 is reserved, >= 32 is not possible 
// Source addresses restricted to 0xD0xxxxxxxx
// Format of a transfer entry is address[23..0] & dwordsize[7..0]
// Address must be dword aligned

#ifdef VX1000_OLDA

// Enable OLDA
void VX1000_OLDA_INITIALIZE( void ) {

  // This is done by VX1000, only if OLDA is really used 
  // OVRCON = 3; // Disable OLDA write trap generation

  gVX1000.Olda.MagicId = VX1000_OLDA_MAGIC; 
  gVX1000.Olda.Version = VX1000_OLDA_VERSION;
  gVX1000.Olda.Runing = 0; 
  #ifndef VX1000_OLDA_MEMORY_ADDR
    gVX1000.Olda.MemoryAddr = (unsigned int)&gVX1000.Olda.Data; 
  #else
    gVX1000.Olda.MemoryAddr = VX1000_OLDA_MEMORY_ADDR; 
  #endif
  gVX1000.Olda.Memorysize = VX1000_OLDA_MEMORY_SIZE; 
  gVX1000.Olda.EventCount = 0;
  gVX1000.Olda.EventList = 0; 
  gVX1000.Olda.TransferList = 0; 
  gVX1000.Olda.SizeOffset = VX1000_OLDA_SIZE_OFFSET;
  gVX1000.Olda.Res1 = 0;
  gVX1000.Olda.Res2 = 0;
  gVX1000.Olda.Res3 = 0;
  gVX1000.Olda.Res4 = 0;

  #ifdef VX1000_OLDA_BENCHMARK
	{
	  unsigned int i;
	  for (i=0;i<VX1000_OLDA_EVENT_COUNT;i++) gVX1000_OLDA_Duration[i] = 0;
	}
  #endif

}

// Trigger OLDA event
void VX1000_OLDA_EVENT( unsigned char eventNumber ) { 

  register unsigned char size; 
  register unsigned int *src;
  register unsigned int *dst;
  //register unsigned int sizeOffset,sizeMask;
  unsigned short i,n; 
  VX1000_OLDA_EVENT_T *event;
  
  #ifdef VX1000_OLDA_BENCHMARK
    unsigned int t0 = VX1000_CLOCK; // Timing measurement
  #endif
  
  // Is OLDA runing ?
  if ( *(volatile unsigned int*)&gVX1000.Olda != ( (((unsigned int)1)<<24) | (((unsigned int)VX1000_OLDA_VERSION)<<16) | VX1000_OLDA_MAGIC )	 ) goto exit; 
  
  // Is eventNumer valid ?
  if (eventNumber>=gVX1000.Olda.EventCount) goto exit; 
  event = &gVX1000.Olda.EventList[eventNumber]; 

  // Is eventNumber active ?
  n = event->TransferCount; 
  if (n==0) {
    goto exit; // No data to be copied
  }
  
  // Check for overruns
  // @@@@ t.b.d.
  
  // Take a timestamp
  event->EventTimestamp = VX1000_CLOCK;
  event->EventCounter++;

  // Copy data to an intermediate location
  i = event->TransferIndex; 
  dst = (unsigned int*)event->TransferDest; 
  //sizeOffset = gVX1000.Olda.SizeOffset; // VX1000_OLDA_SIZE_OFFSET; 
  //sizeMask = ~(0x3FUL<<gVX1000.Olda.SizeOffset); //~(0x3FUL<<VX1000_OLDA_SIZE_OFFSET); 
  while (n-- > 0) {    
    #if VX1000_OLDA_VERSION>=4
	    src = (unsigned int*)gVX1000.Olda.TransferList[i++]; 
	    size = (unsigned int)src >> VX1000_OLDA_SIZE_OFFSET; 
		size &= 0x3F;
	    src = (unsigned int*)((unsigned int)src & ~(0x3FUL<<VX1000_OLDA_SIZE_OFFSET)); 
    #elif VX1000_OLDA_VERSION==3
	    src = (unsigned int*)gVX1000.Olda.TransferList[i++];	
	    size = (unsigned int)src >> 22;
		size &= 0x3F;
	    src = (unsigned int*)((unsigned int)src & 0xF03FFFFF);
	#else
	    src = (unsigned int*)gVX1000.Olda.TransferList[i++];
	    size = (unsigned int)src & 0xFF;
	    src = (unsigned int *)(((unsigned int)src >>8 ) | 0xD0000000);
	#endif
    while (size--) *dst++ = *src++; 
  } 
  
  // Trigger the VX1240 to copy the data
  OCDS_TRIGS = 1<<eventNumber;

exit: // Return without triggering the event

  #ifdef VX1000_OLDA_BENCHMARK
    gVX1000_OLDA_Duration[eventNumber] = VX1000_CLOCK-t0; // Timing measurement
  #endif

  return;
} 

#endif // VX1000_OLDA

//-------------------------------------------------------------------------------
// VX1000 detection and initialization

// Initialize the global data
// Must be called before any other VX1000_XXXX routine is called
void VX1000_INIT( void ) {  

  if ((SCU_RSTSTAT & 0xFFFFFFFE) == 0x00000010) {

    // Check if the gVX1000 data structure is still valid
	if (gVX1000.MagicId==VX1000_STRUCT_MAGIC && gVX1000.Version==VX1000_STRUCT_VERSION) {
  	  
	  unsigned int t,n;

  	  // Reenable OLDA trace
      OVRCON = 0x00000003; // Disable OLDA write trap generation

	  // Trigger special event 0x1
      VX1000_SPECIAL_EVENT(0x00050001);

      gVX1000.ToolDetectState |= VX1000_TDS_APPRST; 

      // Wait 10ms
      // First create enough trace traffic to empty the tile buffer
      // Give VX1240 a chance to set the timestamp offset
      t = VX1000_CLOCK;
	  n = 0;
      while (VX1000_CLOCK-t<VX1000_CLOCK_TICKS_PER_MS*10) {
 	    while (++n<0x1000) { // Generate max. 64K Trace data
 	      VX1000_TIMESTAMP();
 	      VX1000_TIMESTAMP();
 	      VX1000_TIMESTAMP();
 	      VX1000_TIMESTAMP();
 	      VX1000_TIMESTAMP();
		}
      }

      return; // Success
	}

  }


  // Initialize
  gVX1000.EventNumber.d = 0;         
  gVX1000.EventTimestamp.d = VX1000_CLOCK;
  gVX1000.MagicId = VX1000_STRUCT_MAGIC; 
  gVX1000.Version = VX1000_STRUCT_VERSION; 
  gVX1000.GetIdPtr = VX1000_ECUID_PTR; 
  gVX1000.GetIdLen = VX1000_ECUID_LEN; 
  gVX1000.XcpMailboxPtr = VX1000_MAILBOX_PTR; 
  gVX1000.StimCtrlPtr = VX1000_STIM_PTR; 
  gVX1000.RamSynchField = 0; 
  gVX1000.ToolDetectState = VX1000_TDS_INIT; 
  gVX1000.OldaPtr = VX1000_OLDA_PTR; 
  gVX1000.OldaEventNumber = 0; 
  gVX1000.CalPtr = CC_PTR;
  gVX1000.ToolCtrlState = 0; 
  gVX1000.res6 = 0;
  gVX1000.res7 = 0;

  VX1000_OLDA_INIT; 
  VX1000_STIM_INIT;
  VX1000_MAILBOX_INIT; 

  // Lock DAP in 2 PIN mode to improve communication during tool detection and coldstart by the VX1000
  // This is only possible in 2 PIN mode with the VX1542 FPGA POD
  OCDS_OCNTRL =  0x00000007;  // DJMODE = 01 Two-pin DAP with disabled BYPASS

  // VX1000 detection
  if (VX1000_DETECT()) {
    // If tool detection was successfull, DAP is always in 2 pin mode
  }
  else {
    OCDS_OCNTRL =  VX1000_OCDS_OCNTRL; // Lock DAP in the user selected pin mode
  }
}  

		
// Detect a connected VX1000 and confirm the detection
// Delay for initialization of a cold start measurement
// Must be called after ENDINIT is set 							   
unsigned char VX1000_DETECT( void ) {

  unsigned int t0,s;

  // Check if 1st call after reset
  if (!(gVX1000.ToolDetectState&VX1000_TDS_DETECT)) {

    #ifdef VX1000_COLDSTART_BENCHMARK
      gVX1000_DETECT_StartTime = VX1000_CLOCK;	  
	#endif

    gVX1000.ToolDetectState |= VX1000_TDS_DETECT; 

    // Wait 50us to give VX1240 a chance to set OCDS_TRIG
    t0 = VX1000_CLOCK;
    while (VX1000_CLOCK-t0<VX1000_CLOCK_TICKS_PER_MS/20);

    // Check tool signature
    // 0x31636556: Tool present signature
    // 0x32636556: Tool present and requires cold start init
	s = OCDS_TRIG;
    if (s==0x31636556 || s==0x32636556) { 
      gVX1000.ToolDetectState |= VX1000_TDS_DETECTED; 

      // Tool detect acknowledge with TRIG = 0x0005555
      OCDS_TRIGC = 0xFFFFFFFF;
      OCDS_TRIGS = 0x00005555;
      // CBS_OSTATE.OJC[3..1]  0x001 für No Powerfail, 0x011 für Powerfail

      // Wait until the VX has completed initializations
      // Check timeout
      if (s==0x32636556) { 

        for (;;) {
          if ((VX1000_CLOCK-t0)>=VX1000_CLOCK_TICKS_PER_MS*VX1000_COLDSTART_TIMEOUT) {
            // Timeout acknowledge
            gVX1000.ToolDetectState |= VX1000_TDS_COLDSTART_TIMEOUT; 
            break;
		  }
          if (OCDS_TRIG==0x00000000) {
            // Init acknowledge
            gVX1000.ToolDetectState |= VX1000_TDS_COLDSTART_DONE; 
            break;
		  }
        } // for(;;)
      
      }
       
	}

    #ifdef VX1000_COLDSTART_BENCHMARK
      gVX1000_DETECT_EndTime = VX1000_CLOCK;
	#endif

  }	// 1st

  return gVX1000.ToolDetectState&VX1000_TDS_DETECTED;
}   
  


//----------------------------------------------------------------------------
// Mailbox

#ifdef VX1000_MAILBOX

#include <string.h>

//
// Initialize the Master->Slave and Slave->Master mailboxes.
//
void vx1000_MailboxInit(void) {
  
    gVX1000.Mailbox.MagicId = VX1000_MAILBOX_MAGIC; 
    gVX1000.Mailbox.Version = 0; 
    gVX1000.Mailbox.SlotSize = 0; 
   
    gVX1000.Mailbox.MS_ReadIdx = 0; 
    gVX1000.Mailbox.MS_WriteIdx = 0;
    gVX1000.Mailbox.SM_ReadIdx = 0; 
    gVX1000.Mailbox.SM_WriteIdx = 0;
  
    gVX1000.Mailbox.RstReq = 0;
    gVX1000.Mailbox.RstAck = 0;

    gVX1000.Mailbox.SlotSize = MAILBOX_SLOT_DWORDS << 2;
    gVX1000.Mailbox.MS_Slots = MAILBOX_SLOTS;
    gVX1000.Mailbox.SM_Slots = MAILBOX_SLOTS;
    gVX1000.Mailbox.MS_Ptr = (unsigned int)gVX1000.Mailbox.MSData;
    gVX1000.Mailbox.SM_Ptr = (unsigned int)gVX1000.Mailbox.SMData;
  
    VX1000_SPECIAL_EVENT(VX1000_EVENT_MAILBOX_INIT);
}
 

//
// Write len bytes from pBuf to the Slave->Master mailbox
// and notify the master.
//
unsigned int vx1000_MailboxWrite(unsigned int len, unsigned char* pBuf) {
  if (!MAILBOX_FREE_WR_SLOTS) {
    return MAILBOX_ERR_FULL;
  }
  if (!pBuf) {
    return MAILBOX_ERR_NULL;
  }
  if (len > MAILBOX_SLOT_DWORDS << 2) {
    return MAILBOX_ERR_SIZE;
  }
  memcpy((void*)&gVX1000.Mailbox.SMData[gVX1000.Mailbox.SM_WriteIdx][1], pBuf, len);
  gVX1000.Mailbox.SMData[gVX1000.Mailbox.SM_WriteIdx][0] = len;
  gVX1000.Mailbox.SM_WriteIdx = MAILBOX_NEXT(gVX1000.Mailbox.SM_WriteIdx);
  VX1000_SPECIAL_EVENT(VX1000_EVENT_MAILBOX_UPDATE);
  return MAILBOX_OK;
}
  


//
// Read the data from the next filled Master->Slave mailbox slot
// into pBuf and return the number of bytes in pLen.
// Upon calling pLen contains the maximum number of bytes that
// can be read into pBuf. If the number of bytes exceeds pLen,
// an error is returned and no data is copied.
//
unsigned int vx1000_MailboxRead(unsigned int* pLen, unsigned char* pBuf) {
  unsigned int len;
  if (!MAILBOX_USED_RD_SLOTS) {
    return MAILBOX_ERR_EMPTY;
  }
  if (!pLen || !pBuf) {
    return MAILBOX_ERR_NULL;
  }
  len = gVX1000.Mailbox.MSData[gVX1000.Mailbox.MS_ReadIdx][0];
  if (len > *pLen) {
    return MAILBOX_ERR_SIZE;
  }
  *pLen = len;
  memcpy(pBuf, (void*)&gVX1000.Mailbox.MSData[gVX1000.Mailbox.MS_ReadIdx][1], len);
  gVX1000.Mailbox.MS_ReadIdx = MAILBOX_NEXT(gVX1000.Mailbox.MS_ReadIdx);
  VX1000_SPECIAL_EVENT(VX1000_EVENT_MAILBOX_UPDATE);
  return MAILBOX_OK;
}
  


// XCP compliant protocol handler
#undef CRO_BYTE
#define CRO_BYTE(n) rxBuf[n]
#undef CRM_BYTE
#define CRM_BYTE(n) txBuf[n]
#undef CRO_CMD
#define CRO_CMD rxBuf[0]
#undef CRM_CMD
#define CRM_CMD txBuf[0]
#undef CRM_ERR
#define CRM_ERR txBuf[1]


// XCP calibration page handling
#ifdef VX1000_MAILBOX_OVERLAY_CONTROL

  #define CC_SET_CAL_PAGE                   0xEB
  #define CC_GET_CAL_PAGE                   0xEA
  #define CC_COPY_CAL_PAGE                  0xE4
  
  /* SET_CAL_PAGE */                          
  #define CRO_SET_CAL_PAGE_LEN                            4
  #define CRO_SET_CAL_PAGE_MODE                           CRO_BYTE(1)
  #define CRO_SET_CAL_PAGE_SEGMENT                        CRO_BYTE(2)
  #define CRO_SET_CAL_PAGE_PAGE                           CRO_BYTE(3)
  #define CRM_SET_CAL_PAGE_LEN                            1
                                                          
  /* GET_CAL_PAGE */
  #define CRO_GET_CAL_PAGE_LEN                            3
  #define CRO_GET_CAL_PAGE_MODE                           CRO_BYTE(1)
  #define CRO_GET_CAL_PAGE_SEGMENT                        CRO_BYTE(2)
  #define CRM_GET_CAL_PAGE_LEN                            4
  #define CRM_GET_CAL_PAGE_PAGE                           CRM_BYTE(3)
  
  /* COPY_CAL_PAGE */
  #define CRO_COPY_CAL_PAGE_LEN                           5
  #define CRO_COPY_CAL_PAGE_SRC_SEGMENT                   CRO_BYTE(1)
  #define CRO_COPY_CAL_PAGE_SRC_PAGE                      CRO_BYTE(2)
  #define CRO_COPY_CAL_PAGE_DEST_SEGMENT                  CRO_BYTE(3)
  #define CRO_COPY_CAL_PAGE_DEST_PAGE                     CRO_BYTE(4)
  #define CRM_COPY_CAL_PAGE_LEN                           1
#endif

// XCP flash programming
#ifdef VX1000_MAILBOX_FLASH

  #define CC_PROGRAM_START                  0xD2
  #define CC_PROGRAM_CLEAR                  0xD1
  #define CC_PROGRAM                        0xD0
  #define CC_PROGRAM_RESET                  0xCF
  #define CC_PROGRAM_PREPARE                0xCC
  #define CC_PROGRAM_NEXT                   0xCA
  #define CC_PROGRAM_MAX                    0xC9
  #define CC_PROGRAM_VERIFY                 0xC8

  /* PROGRAM_PREPARE */                                   
  #define CRO_PROGRAM_PREPARE_LEN                         4
  #define CRO_PROGRAM_PREPARE_SIZE                        CRO_WORD(1)
  #define CRM_PROGRAM_PREPARE_LEN                         1
                                                          
  /* PROGRAM_START */
  #define CRO_PROGRAM_START_LEN                           1
  #define CRM_PROGRAM_START_LEN                           7
  #define CRM_PROGRAM_COMM_MODE_PGM                       CRM_BYTE(2) 
  #define CRM_PROGRAM_MAX_CTO_PGM                         CRM_BYTE(3) 
  #define CRM_PROGRAM_MAX_BS_PGM                          CRM_BYTE(4) 
  #define CRM_PROGRAM_MIN_ST_PGM                          CRM_BYTE(5) 
  #define CRM_PROGRAM_QUEUE_SIZE_PGM                      CRM_BYTE(6) 

  /* PROGRAM_CLEAR */                                 
  #define CRO_PROGRAM_CLEAR_LEN                           8
  #define CRO_PROGRAM_CLEAR_MODE                          CRO_BYTE(1)
  #define CRO_PROGRAM_CLEAR_SIZE                          CRO_DWORD(1)
  #define CRM_PROGRAM_CLEAR_LEN                           1

                                                        
  /* PROGRAM */
  #define CRO_PROGRAM_MAX_SIZE                            ((vuint8)((kXcpMaxCTO-2)/kXcpAG))                                           
  #define CRO_PROGRAM_LEN                                 2 /* + CRO_PROGRAM_SIZE */ 
  #define CRO_PROGRAM_SIZE                                CRO_BYTE(1)
  #define CRO_PROGRAM_DATA                                (&CRO_BYTE(2))
  #define CRM_PROGRAM_LEN                                 1

 
#endif


void vx1000_MailboxHandler(void) {
  
  unsigned int rxLen,txLen;
  unsigned char rxBuf[8],txBuf[8];
  
  rxLen = 8;
  if (MAILBOX_OK==vx1000_MailboxRead(&rxLen,&rxBuf[0])) {
    txLen = 2;
    CRM_CMD = 0xFF;
    CRM_ERR = 0x00;
    switch (CRO_CMD) {
      
      #ifdef VX1000_MAILBOX_OVERLAY_CONTROL
        case CC_GET_CAL_PAGE:
          CRM_GET_CAL_PAGE_PAGE = VX1000_GET_CAL_PAGE(CRO_GET_CAL_PAGE_SEGMENT,CRO_GET_CAL_PAGE_MODE);
          txLen = CRM_GET_CAL_PAGE_LEN;
          break;
        case CC_SET_CAL_PAGE:
          CRM_ERR = VX1000_SET_CAL_PAGE(CRO_SET_CAL_PAGE_SEGMENT,CRO_SET_CAL_PAGE_PAGE,CRO_SET_CAL_PAGE_MODE);
          txLen = CRM_SET_CAL_PAGE_LEN;
          break;
        case CC_COPY_CAL_PAGE:
          CRM_ERR = VX1000_COPY_CAL_PAGE(CRO_COPY_CAL_PAGE_SRC_SEGMENT,CRO_COPY_CAL_PAGE_SRC_PAGE,CRO_COPY_CAL_PAGE_DEST_SEGMENT,CRO_COPY_CAL_PAGE_DEST_PAGE);
          txLen = CRM_COPY_CAL_PAGE_LEN;
          break;
      #endif

      #ifdef VX1000_MAILBOX_FLASH
        case CC_PROGRAM_PREPARE:
          // CRO_PROGRAM_PREPARE_SIZE                  
		  // @@@@ Problem: How to get start addr ??
          txLen = CRM_PROGRAM_PREPARE_LEN;
          break;
        case CC_PROGRAM_START:
          CRM_PROGRAM_COMM_MODE_PGM = 0;                    
          CRM_PROGRAM_MAX_CTO_PGM = 8;                                  
          CRM_PROGRAM_MAX_BS_PGM = 1;                      
          CRM_PROGRAM_MIN_ST_PGM = 0;                
          CRM_PROGRAM_QUEUE_SIZE_PGM = 1;              
          txLen = CRM_PROGRAM_START_LEN;
          break;
      #endif


        
      default:
        CRM_ERR = 0x20; // CRC_CMD_UNKNOWN         
    }
    if (CRM_ERR) CRM_CMD = 0xFE;
    vx1000_MailboxWrite(txLen,txBuf);    
  }
}


#ifdef VX1000_MAILBOX_PRINTF

#include <stdarg.h>

unsigned int gVx1000EvLen = 0;
char gVx1000EvBuf[8];

void vx1000_MailboxPutchar( char c ) {
  
  if (gVx1000EvLen<2 || gVx1000EvBuf[0]!=0xFC || gVx1000EvBuf[1]!=0x01) {
    gVx1000EvLen = 2; 
    gVx1000EvBuf[0] = 0xFC; /* SERV */
    gVx1000EvBuf[1] = 0x01; /* SERV_TEXT*/
  }  
  gVx1000EvBuf[gVx1000EvLen] = c;
  gVx1000EvLen++;
  if ( (gVx1000EvLen>=8) || (c==0) ) { 
    vx1000_MailboxWrite(gVx1000EvLen,(unsigned char*)gVx1000EvBuf);    
  }

}

void vx1000_MailboxPrintf( const char *str, ... ) {

  va_list argptr;
  char buf[256];

  va_start(argptr,str);
  vsprintf(buf,str,argptr );
  va_end(argptr);

  /* Transmit the text message */
  {
    char *p = buf;
    while (*p != 0) {
      vx1000_MailboxPutchar(*p);
      p++;
    }
  }
  
  /* Transmit the terminating 0x00. */
  vx1000_MailboxPutchar( 0x00 );
}

#endif // MAILBOX_PRINTF


#endif

