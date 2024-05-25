/*-------------------------------------------------------------------------------
 VX1000_TRICORE.C
 Program instrumentation for Vector VX with Tricore DAP
 Don't modify this file, parameters defined in VX1000_TRICORE_CFG.H
 Version 2.2 10.3.2011
 Vector Informatik GmbH
-------------------------------------------------------------------------------*/

/*
Violated MISRA rules:
 - Macros shall not be used
 - #undef should not be used
 - Identifiers shall not have more than 31 characters
   Example: #define VX1000_OLDA_FEATURE_SIZE_DYNAMIC        (0 << 1)
 - restrict the use of implicit conversions for integer types
   Example: gVX1000.Stim.Version = 0; 
 - a 'U' suffix should be applied to all constants of unsigned type
     Example: gVX1000.Stim.Event[i].Ctr = 0; 
 - the 'goto' statement shall not be used
 - unions shall not be used
 - a null statement shall only occur on a line by itself
   Example: VX1000_RESET_TIMEOUT();
 - a function should have a single point of exit
   Example: return 1; else return 0;
- don't use ~ or << on small unsigned types without a cast
    Example: 1UL<<1
- array indexing shall be the only allowed form of pointer arithmetic
    Example: *src++
-  a complex integer expression may only be cast to a narrower type
   Example: ((VX1000_INT32)(VX1000_CLOCK - sTimeout))
- a shift count shall be between 0 and the operand width minus 1
  Example: (((VX1000_UINT32)VX1000_OLDA_VERSION)<<16)
- bitwise operations shall not be performed on signed operands
  Example: ((VX1000_UINT32)dst >> VX1000_OLDA_SIZE_OFFSET) & 0x3F;
- the value of an expression shall be evaluation order independent
    Example: gVX1000.Stim.Event[e-VX1000_STIM_EVENT_OFFSET].Ctr!=gVX1000.Stim.Event[e-VX1000_STIM_EVENT_OFFSET].RqCtr)
	Example: gVX1000.EventTimestamp.d = gVX1000.EventTimestamp.d = VX1000_CLOCK
- the operands of a logical && or || shall be primary expressions
- the right hand side of && or || shall not contain side effects

Advisory Rules:
- a function should be used in preference to a function-like macro
- a pointer type should not be cast to/from an integral type
- tests of a value against zero should be made explicit
- no dependency should be placed on operator precedence rules
- the ++ and -- operators should not be mixed with other operators
- the same identifier shall not be used in multiple name spaces
*/


#include "VX1000_TRICORE.H"

#if VX1000_FILE_VERSION!=0x0202
  #error "version of VX1000_TRICORE.h does not match version of VX1000_TRICORE.c!"
#endif


/*----------------------------------------------------------------------------*/
/* Bypassing */

#ifdef VX1000_STIM

#ifdef VX1000_STIM_BY_OLDA
  static void VX1000_STIM_TRANSFER( VX1000_UINT8 eventNumber );
#endif

/* Timeout (us) */
static VX1000_UINT32 sTimeout;
#define VX1000_RESET_TIMEOUT(timeout) sTimeout = VX1000_CLOCK + ((VX1000_UINT32)timeout*(VX1000_CLOCK_TICKS_PER_MS/1000U))
#define VX1000_CHECK_TIMEOUT() (((VX1000_INT32)(VX1000_CLOCK - sTimeout))>0)


/* Initialize the STIM data structure */
/* Reset all counters */
/* Called once in VX1000_INIT and everytime STIM is turned off */
void VX1000_STIM_INIT(void) { 

  VX1000_UINT32 i;

  gVX1000.Stim.Version = 0; 
  gVX1000.Stim.Control = 0; 
  gVX1000.Stim.EvtOffset = VX1000_STIM_EVENT_OFFSET; 
  gVX1000.Stim.EvtNumber = VX1000_STIM_EVENT_COUNT; 
  gVX1000.Stim.Control = 0; \
  for (i=0;i<VX1000_STIM_EVENT_COUNT;i++) { 
    gVX1000.Stim.Event[i].Ctr = 0; 
    gVX1000.Stim.Event[i].RqCtr = 0; 
    gVX1000.Stim.Event[i].Enable = 0; 
    gVX1000.Stim.Event[i].Copying = 0; 
  } 
  gVX1000.Stim.MagicId = VX1000_STIM_MAGIC; 
  gVX1000.Stim.Enable = 0; 

  /* @@@@ TODO: Do we need a STIM_INIT event here ? */
  /* gVX1000.EventNumber.d = VX1000_EVENT_STIM_INIT; */

}

/* Init the STIM benchmark data */
#ifdef VX1000_STIM_BENCHMARK
static void VX1000_STIM_BENCHMARK_INIT( void ) {

  VX1000_UINT32 i;
  
  for (i=0;i<32;i++) { gVX1000_STIM_Duration[i] = 0; }
  #ifdef VX1000_STIM_HISTOGRAM
    for (i=0;i<256;i++) { gVX1000_STIM_Histogram[i] = 0; }
    for (i=0;i<16;i++) { gVX1000_STIM_Histogram2[i] = 0; }
  #endif  
}
#endif


/* Stim Handler */
/* Called cyclic */
void VX1000_STIM_CONTROL(void) {

  /* STIM turned on */
  if (gVX1000.Stim.Control!=0 && gVX1000.Stim.Enable==0) {

    /* Clear benchmark data */
    #ifdef VX1000_STIM_BENCHMARK
      VX1000_STIM_BENCHMARK_INIT();
    #endif
    gVX1000.Stim.TimeoutCtr = 0;
    gVX1000.Stim.TimeoutCtr2 = 0;

    #ifdef VX1000_STIM_TYPE_0    
      VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_ACK); /* Send an acknowledge STIM event when the ECU is ready for STIM  */
    #endif
    gVX1000.Stim.Enable = 1;
  }

  /* STIM turned off */
  else if (gVX1000.Stim.Control==0 && gVX1000.Stim.Enable!=0) {
    VX1000_STIM_INIT(); /* Reinitialize STIM when turned off (resets Stim.Enable) */
  }

  else {
  }
  
}



/* Wait until a specific STIM request is fullfilled */
/* Timeout specified in us */
/* Return 1 in case of timeout */
VX1000_UINT8 VX1000_STIM_WAIT(VX1000_UINT8 e, VX1000_UINT32 timeout /*us*/) {

  /* Timing measurement */
  #ifdef VX1000_STIM_BENCHMARK
    VX1000_UINT32 t0 = VX1000_CLOCK;
  #endif

  /* Busy wait until stimulation is done or stimulation data arrived */
  VX1000_RESET_TIMEOUT(timeout);
  while (gVX1000.Stim.Event[e-VX1000_STIM_EVENT_OFFSET].Ctr!=gVX1000.Stim.Event[e-VX1000_STIM_EVENT_OFFSET].RqCtr) {
    
    /* Check for timeout */
    if (VX1000_CHECK_TIMEOUT()) {
      
	  #ifdef VX1000_STIM_BY_OLDA
        if (VX1000_STIM_ACTIVE(e)) { 
          VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_TIMEOUT(e));
		}
        goto timeout;
      #else
	      /* Check if stim data is currently beeing copied */
	      /* Wait another 1 ms to complete copying */
	      if (gVX1000.Stim.Event[e-VX1000_STIM_EVENT_OFFSET].Copying) {
	        VX1000_RESET_TIMEOUT(1000U);
	        while (gVX1000.Stim.Event[e-VX1000_STIM_EVENT_OFFSET].Ctr!=gVX1000.Stim.Event[e-VX1000_STIM_EVENT_OFFSET].RqCtr) {
	          if (VX1000_CHECK_TIMEOUT()) {
	            VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_ERR(e)); 
	            goto timeout;
	          }
	        }
	        break;
	      }
	      
	      /* If data is not beeing copied yet, inform the VX1121 about the timeout  */
	      else {
	        if (VX1000_STIM_ACTIVE(e)) { VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_TIMEOUT(e)); }
	        goto timeout;
	      }
      #endif
            
    } /* Timeout */

  } /* While */

  /* Copy the STIM data to final memory locations */
  #ifdef VX1000_STIM_BY_OLDA
    VX1000_STIM_TRANSFER(e); 
  #endif

  /* Timing measurement */
  #ifdef VX1000_STIM_BENCHMARK
    gVX1000_STIM_Duration[e] = VX1000_CLOCK-t0; 	  
    #ifdef VX1000_STIM_HISTOGRAM
	  t0 = (VX1000_CLOCK-t0)/(VX1000_CLOCK_TICKS_PER_MS/50); /* 20us resolution, 0..5100us */
	  if (t0>=256) { t0 = 255; }
	  gVX1000_STIM_Histogram[t0]++;
	  t0 = gVX1000.Stim.TimeoutCtr2;
	  if (t0>=16) { t0 = 15; }
	  gVX1000_STIM_Histogram2[t0]++;
	#endif  
  #endif

  /* No timeout */
  gVX1000.Stim.TimeoutCtr2 = 0; /* Reset the timeout in sequence counter */
  goto exit;
   
/* Timeout */
timeout:
  gVX1000.Stim.TimeoutCtr++;    /* Increment the timeout and timeout in sequence counter */
  gVX1000.Stim.TimeoutCtr2++;
exit:
  return 1;  
}


/* Event number daq_event is the bypass stimulation event, it indicates that the ECU is now waiting for completion of the stimulation */
/* Event number stim_event is the bypass trigger event, it should be used to trigger calculation of the bypass in the tool, as long as the bypass is not activated in the tool, this event is not executed                                   */
/* Return 1, if the bypass is active and the bypassed code has to be disabled */
/* Return 2, in case of timeout */
VX1000_UINT8 VX1000_BYPASS( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event, VX1000_UINT32 timeout) {

	if (VX1000_STIM_ACTIVE(stim_event)) {
	  VX1000_EVENT(daq_event);
	  VX1000_STIM_REQUEST(stim_event);
	  if (VX1000_STIM_WAIT(stim_event,timeout)) {
	    /* Timeout; */
        return 2;
	  }
	  /* Ok, No Timeout */
	  return 1;	/* Disable the bypassed code */
	}
	else {
	  /* Bypass disabled */
	  return 0;	/* Enable the bypassed code */
	}
}

VX1000_UINT8 VX1000_BYPASS_TRIGGER( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event ) {

  if (VX1000_STIM_ACTIVE(stim_event)) {
	VX1000_EVENT(daq_event);
    return 1; /* Bypass active */
	}
  else {
    return 0; /* Bypass inactive */
  }
}

VX1000_UINT8 VX1000_BYPASS_WAIT( VX1000_UINT8 stim_event, VX1000_UINT32 timeout) {

  if (VX1000_STIM_ACTIVE(stim_event)) {
    VX1000_STIM_REQUEST(stim_event);
    if (VX1000_STIM_WAIT(stim_event,timeout)) {
      return 2;	/* Bypass active, timeout       */
    }
    else {
	  return 1;	/* Bypass active, ok, disable the bypassed code */
    }
  }
  else {
    return 0;	/* Bypass inactive, enable the bypassed code */
  }
}

#endif


/*----------------------------------------------------------------------------*/
/* Measurement data acquisition */


/* Copy routine */
/* Event number is limited to 0..30, event number 31 is reserved, >= 32 is not possible  */
/* Source addresses restricted to 0xD0xxxxxxxx */
/* Format of a transfer entry is address[23..0] & dwordsize[7..0] */
/* Address must be dword aligned */

#ifdef VX1000_OLDA

/* Enable OLDA */
void VX1000_OLDA_INIT( void ) {

  /* This is done by VX1000, only if OLDA is really used  */
  /* OVRCON = 3; Disable OLDA write trap generation */

  gVX1000.Olda.MagicId = VX1000_OLDA_MAGIC; 
  gVX1000.Olda.Version = VX1000_OLDA_VERSION;
  gVX1000.Olda.Runing = 0; 
  #ifndef VX1000_OLDA_MEMORY_ADDR
    gVX1000.Olda.MemoryAddr = (VX1000_UINT32)&gVX1000.Olda.Data; 
  #else
    gVX1000.Olda.MemoryAddr = VX1000_OLDA_MEMORY_ADDR; 
  #endif
  gVX1000.Olda.Memorysize = VX1000_OLDA_MEMORY_SIZE; 
  gVX1000.Olda.EventCount = 0;
  gVX1000.Olda.EventList = 0; 
  gVX1000.Olda.TransferList = 0; 
  gVX1000.Olda.SizeOffset = VX1000_OLDA_SIZE_OFFSET;
  gVX1000.Olda.SizeSwapValue = VX1000_OLDA_SIZE_SWAP_VALUE;
  gVX1000.Olda.OldaFeatures = VX1000_OLDA_FEATURE_OVERLOAD_DETECTION | VX1000_OLDA_FEATURE_SIZE_DYNAMIC|VX1000_OLDA_FEATURE_STIM;
  gVX1000.Olda.Res1 = 0;
  gVX1000.Olda.Res2 = 0;

  #ifdef VX1000_OLDA_BENCHMARK
	{
	  VX1000_UINT32 i;
	  for (i=0;i<VX1000_OLDA_EVENT_COUNT;i++) { gVX1000_OLDA_Duration[i] = 0; }
	}
  #endif

}

/* Trigger OLDA event */
void VX1000_OLDA_EVENT( VX1000_UINT8 e ) { 

  register VX1000_UINT8 size; 
  register VX1000_UINT32 *src;
  register VX1000_UINT32 *dst;
  #ifdef VX1000_OLDA_SIZE_DYNAMIC
    register VX1000_UINT32 sizeMask, sizeReplace;
  #endif
  VX1000_UINT16 i,n; 
  VX1000_OLDA_EVENT_T *event;
  
  /* Take the timestamp first to have maximum precision */
  /* This timestamp will be needed for data trace as well */
  /* This will also update the timestamp for GET_DAQ_CLOCK in case of direct access to STM_TIMx is not used */
  gVX1000.EventTimestamp.d = VX1000_CLOCK; 
  
  /* Is OLDA runing ? */
  if ( *(volatile VX1000_UINT32*)&gVX1000.Olda != ( (((VX1000_UINT32)1UL)<<24U) | (((VX1000_UINT32)VX1000_OLDA_VERSION)<<16U) | VX1000_OLDA_MAGIC )	 ) { goto exit; }
  
  /* Is eventNumer valid ? */
  if (e>=gVX1000.Olda.EventCount) { goto exit; }
  event = &gVX1000.Olda.EventList[e]; 
  #ifdef VX1000_OLDA_BENCHMARK
	gVX1000_OLDA_TransferSize[e] = 0; /* Size of all transfers */
    gVX1000_OLDA_TransferCount[e] = event->TransferCount; /* Number of tranfers */
  #endif
	 
  /* Is eventNumber active ? */
  n = event->TransferCount; 
  if (n==0) { goto exit; } /* No data to be copied */
  
  #ifdef VX1000_OLDA_OVERLOAD_DETECTION
    /* Increase the Event-Counter to detect Overruns */
    event->EventCounter++;
  #endif

  /* Copy data to an intermediate location */
  i = event->TransferIndex; 
  dst = (VX1000_UINT32*)event->TransferDest; 
  #ifdef VX1000_OLDA_SIZE_DYNAMIC
    sizeMask = ~(0x3FUL << gVX1000.Olda.SizeOffset);
    sizeReplace = ((gVX1000.Olda.SizeSwapValue&0x3FUL) << gVX1000.Olda.SizeOffset);
  #endif
  while (n-- > 0) {    
    #if VX1000_OLDA_VERSION>=5
      src = (VX1000_UINT32*)gVX1000.Olda.TransferList[i++]; 
      #ifdef VX1000_OLDA_SIZE_DYNAMIC
        size = ((VX1000_UINT32)src >> gVX1000.Olda.SizeOffset) & 0x3FU;
        src = (VX1000_UINT32*)(((VX1000_UINT32)src & sizeMask) | sizeReplace);
      #else
	    size = ((VX1000_UINT32)src >> VX1000_OLDA_SIZE_OFFSET) & 0x3FU;
	    src = (VX1000_UINT32*)((VX1000_UINT32)src & ~(0x3FUL<<VX1000_OLDA_SIZE_OFFSET)); 
	  #endif
    #elif VX1000_OLDA_VERSION==4
	    src = (VX1000_UINT32*)gVX1000.Olda.TransferList[i++]; 
	    size = (VX1000_UINT32)src >> VX1000_OLDA_SIZE_OFFSET; 
		size &= 0x3FU;
	    src = (VX1000_UINT32*)((VX1000_UINT32)src & ~(0x3FUL<<VX1000_OLDA_SIZE_OFFSET)); 
    #elif VX1000_OLDA_VERSION==3
	    src = (VX1000_UINT32*)gVX1000.Olda.TransferList[i++];	
	    size = (VX1000_UINT32)src >> 22U;
		size &= 0x3FU;
	    src = (VX1000_UINT32*)((VX1000_UINT32)src & 0xF03FFFFFUL);
	#else
	    src = (VX1000_UINT32*)gVX1000.Olda.TransferList[i++];
	    size = (VX1000_UINT32)src & 0xFFU;
	    src = (VX1000_UINT32 *)(((VX1000_UINT32)src >> 8 ) | 0xD0000000UL);
	#endif
    #ifdef VX1000_OLDA_BENCHMARK
      gVX1000_OLDA_TransferSize[e] += size; /* Size of all transfers */
	#endif
    while (size--) { *dst++ = *src++; }
  } 
  
  /* Write the timestamp */
  event->EventTimestamp = gVX1000.EventTimestamp.d;

   #ifdef VX1000_OLDA_OVERLOAD_DETECTION
    /* Increase the Event-Counter a second time to detect Overruns */
    event->EventCounter++;
  #endif

  /* Trigger the VX to copy the data */
  OCDS_TRIGS = 1U<<e;

exit: /* Return without triggering the OLDA event */

  #ifdef VX1000_OLDA_BENCHMARK
    gVX1000_OLDA_Duration[e] = VX1000_CLOCK-gVX1000.EventTimestamp.d; /* Timing measurement */
  #endif

  /* Dummy write to work around Tricores dual queue problem */
  gVX1000.EventTimestamp.d = gVX1000.EventTimestamp.d; 

  /* Event number for data trace mode */
  gVX1000.EventNumber.d = e;

  return;
} 

#ifdef VX1000_STIM

/* Trigger an STIM request event */
/* A STIM request is not be associated to DAQ data, it is associated to STIM data */
void VX1000_STIM_REQUEST_EVENT( VX1000_UINT8 e ) { 

  VX1000_OLDA_EVENT_T *event;
  
  gVX1000.EventTimestamp.d = VX1000_CLOCK; 
  
  /* Is OLDA runing ? */
  if ( *(volatile VX1000_UINT32*)&gVX1000.Olda != ( (((VX1000_UINT32)1)<<24U) | (((VX1000_UINT32)VX1000_OLDA_VERSION)<<16U) | VX1000_OLDA_MAGIC )	 ) { goto exit; }
  
  /* Is eventNumer valid ? */
  if (e>=gVX1000.Olda.EventCount) { goto exit; }
  event = &gVX1000.Olda.EventList[e]; 

  #ifdef VX1000_OLDA_OVERLOAD_DETECTION
    /* Increase the Event-Counter to detect Overruns */
    event->EventCounter++;
  #endif
  
  /* Write the timestamp */
  event->EventTimestamp = gVX1000.EventTimestamp.d;

   #ifdef VX1000_OLDA_OVERLOAD_DETECTION
    /* Increase the Event-Counter a second time to detect Overruns */
    event->EventCounter++;
  #endif

  /* Trigger the VX  */
  OCDS_TRIGS = 1U<<e;

exit: /* Return without triggering the OLDA event */

  /* Dummy write to work around Tricores dual queue problem */
  gVX1000.EventTimestamp.d = gVX1000.EventTimestamp.d; 

  /* Event number for data trace mode */
  gVX1000.EventNumber.d = e;

  return;
} 

#endif

#ifdef VX1000_STIM_BY_OLDA


/* Trigger an OLDA STIM event */
static void VX1000_STIM_TRANSFER( VX1000_UINT8 eventNumber ) { 

  register VX1000_UINT8 size; 
  register VX1000_UINT8 *src;
  register VX1000_UINT8 *dst;
  #ifdef VX1000_OLDA_SIZE_DYNAMIC
    register VX1000_UINT32 sizeMask, sizeReplace;
  #endif
  VX1000_UINT16 i,n; 
  VX1000_OLDA_EVENT_T *event;
  #ifdef VX1000_OLDA_BENCHMARK
    VX1000_UINT32 t;		 
    t = VX1000_CLOCK; /* Timing measurement */
  #endif
 
  /* Is OLDA runing ? */
  if ( *(volatile VX1000_UINT32*)&gVX1000.Olda != ( (((VX1000_UINT32)1)<<24) | (((VX1000_UINT32)VX1000_OLDA_VERSION)<<16) | VX1000_OLDA_MAGIC )	 ) { goto exit; }
  
  /* Is eventNumer valid ? */
  if (eventNumber>=gVX1000.Olda.EventCount) { goto exit; }
  event = &gVX1000.Olda.EventList[eventNumber]; 
  #ifdef VX1000_OLDA_BENCHMARK
	gVX1000_OLDA_TransferSize[eventNumber] = 0; /* Size of all transfers */
    gVX1000_OLDA_TransferCount[eventNumber] = event->TransferCount; /* Number of tranfers */
  #endif

  /* Is eventNumber active ? */
  n = event->TransferCount; 
  if (n==0) { goto exit; } /* No data to be copied */

  /* Bytewise copy of data from intermediate location to memory */
  i = event->TransferIndex; 
  src = (VX1000_UINT8*)event->TransferDest; 
  #ifdef VX1000_OLDA_SIZE_DYNAMIC
    sizeMask = ~(0x3FUL << gVX1000.Olda.SizeOffset);
    sizeReplace = ((gVX1000.Olda.SizeSwapValue&0x3FUL) << gVX1000.Olda.SizeOffset);	
  #endif
  while (n-- > 0) {    
      dst = (VX1000_UINT8*)gVX1000.Olda.TransferList[i++]; 
      #ifdef VX1000_OLDA_SIZE_DYNAMIC
        size = ((VX1000_UINT32)dst >> gVX1000.Olda.SizeOffset) & 0x3f;
        dst = (VX1000_UINT8*)(((VX1000_UINT32)dst & sizeMask) | sizeReplace);
      #else
	    size = ((VX1000_UINT32)dst >> VX1000_OLDA_SIZE_OFFSET) & 0x3F;
	    dst = (VX1000_UINT8*)((VX1000_UINT32)dst & ~(0x3FUL<<VX1000_OLDA_SIZE_OFFSET)); 
	  #endif
     #ifdef VX1000_OLDA_BENCHMARK
       gVX1000_OLDA_TransferSize[eventNumber] += size; /* Size of all transfers */
	 #endif
     while (size--) { *dst++ = *src++; }
  } 

exit: /* Return without triggering the event */

  #ifdef VX1000_OLDA_BENCHMARK
    gVX1000_OLDA_Duration[eventNumber] = VX1000_CLOCK-t; /* Timing measurement */
  #endif

  return;
} 

#endif /* VX1000_STIM_BY_OLDA */


#endif /* VX1000_OLDA */

/*----------------------------------------------------------------------------*/
/* VX1000 detection and initialization */

/* Initialize the global data */
/* Must be called before any other VX1000_XXXX routine is called */
void VX1000_INIT( void ) {  

  if ((SCU_RSTSTAT & 0xFFFFFFFEUL) == 0x00000010UL) {

    /* Check if the gVX1000 data structure is still valid */
	if (gVX1000.MagicId==VX1000_STRUCT_MAGIC && gVX1000.Version==VX1000_STRUCT_VERSION) {
  	  
	  VX1000_UINT32 t,n;

  	  /* Reenable OLDA trace */
      OVRCON = 0x00000003UL; /* Disable OLDA write trap generation */

	  /* Trigger special event 0x1 */
      VX1000_SPECIAL_EVENT(0x00050001UL);

      gVX1000.ToolDetectState |= VX1000_TDS_APPRST; 

      /* Wait 10ms */
      /* First create enough trace traffic to empty the tile buffer */
      /* Give VX a chance to set the timestamp offset */
      t = VX1000_CLOCK;
	  n = 0;
      while (VX1000_CLOCK-t<VX1000_CLOCK_TICKS_PER_MS*10U) {
 	    while (++n<0x1000U) { /* Generate max. 64K Trace data */
 	      VX1000_TIMESTAMP();
 	      VX1000_TIMESTAMP();
 	      VX1000_TIMESTAMP();
 	      VX1000_TIMESTAMP();
 	      VX1000_TIMESTAMP();
		}
      }

      return; /* Success */
	}

  }


  /* Initialize the gVX1000 data structure   */
  /* gVX1000.EventNumber.d = 0; Eventnumer is not touched, to be sure no event is triggered */
  gVX1000.EventNumber.d = 0;         
  gVX1000.EventTimestamp.d = VX1000_CLOCK;
  gVX1000.MagicId = VX1000_STRUCT_MAGIC; 
  gVX1000.Version = VX1000_STRUCT_VERSION; 
  gVX1000.GetIdPtr = VX1000_ECUID_PTR; 
  gVX1000.GetIdLen = VX1000_ECUID_LEN; 
  gVX1000.XcpMailboxPtr = VX1000_MAILBOX_PTR; 
  gVX1000.StimCtrlPtr = VX1000_STIM_PTR; 
  gVX1000.RamSynchField = 0; 
  gVX1000.ToolDetectState = 0; 
  gVX1000.OldaPtr = VX1000_OLDA_PTR; 
  gVX1000.OldaEventNumber = 0; 
  gVX1000.CalPtr = CC_PTR;
  gVX1000.ToolCtrlState = 0; 
  gVX1000.res6 = 0;
  gVX1000.res7 = 0;

  #ifdef VX1000_OLDA
    VX1000_OLDA_INIT(); 
  #endif

  #ifdef VX1000_MAILBOX
    VX1000_MAILBOX_INIT(); 
  #endif

  #ifdef VX1000_STIM
    VX1000_STIM_INIT();
    gVX1000.Stim.TimeoutCtr = 0;  /* TimeoutCtr is persistent (not cleared every restart) */
    gVX1000.Stim.TimeoutCtr2 = 0;
    #ifdef VX1000_STIM_BENCHMARK
      VX1000_STIM_BENCHMARK_INIT();
    #endif
  #endif

  /* Lock DAP in 2 PIN mode to improve communication during tool detection and coldstart by the VX1000 */
  /* This is only possible in 2 PIN mode with the VX1542 FPGA POD */
  OCDS_OCNTRL =  0x00000007UL;  /* DJMODE = 01 Two-pin DAP with disabled BYPASS */

  gVX1000.ToolDetectState = VX1000_TDS_INIT; 

  /* VX1000 detection */
  if (VX1000_DETECT()) {
    /* If tool detection was successfull, DAP is always in 2 pin mode */
  }
  else {
    OCDS_OCNTRL =  VX1000_OCDS_OCNTRL; /* Lock DAP in the user selected pin mode */
  }
}  

		
/* Detect a connected VX1000 and confirm the detection */
/* Delay for initialization of a cold start measurement	  */
/* Must be called after ENDINIT is set */
VX1000_UINT8 VX1000_DETECT( void ) {

  VX1000_UINT32 t0,s;

  /* Check if 1st call after reset */
  if (!(gVX1000.ToolDetectState&VX1000_TDS_DETECT)) {

    #ifdef VX1000_COLDSTART_BENCHMARK
      gVX1000_DETECT_StartTime = VX1000_CLOCK;	  
	#endif

    gVX1000.ToolDetectState |= VX1000_TDS_DETECT; 

    /* Wait 50us to give VX a chance to set OCDS_TRIG */
    t0 = VX1000_CLOCK;
    while (VX1000_CLOCK-t0<VX1000_CLOCK_TICKS_PER_MS/20) {}

    /* Check tool signature */
    /* 0x31636556: Tool present signature */
    /* 0x32636556: Tool present and requires cold start init */
	s = OCDS_TRIG;
    if (s==0x31636556UL || s==0x32636556UL) { 
      gVX1000.ToolDetectState |= VX1000_TDS_DETECTED; 

      /* Tool detect acknowledge with TRIG = 0x0005555 */
      OCDS_TRIGC = 0xFFFFFFFFUL;
      OCDS_TRIGS = 0x00005555UL;
      /* CBS_OSTATE.OJC[3..1]  0x001 für No Powerfail, 0x011 für Powerfail */

      /* Wait until the VX has completed initializations */
      /* Check timeout */
      if (s==0x32636556UL) { 

        for (;;) {
          if ((VX1000_CLOCK-t0)>=VX1000_CLOCK_TICKS_PER_MS*VX1000_COLDSTART_TIMEOUT) {
            /* Timeout acknowledge */
            gVX1000.ToolDetectState |= VX1000_TDS_COLDSTART_TIMEOUT; 
            break;
		  }
          if (OCDS_TRIG==0x00000000UL) {
            /* Init acknowledge */
            gVX1000.ToolDetectState |= VX1000_TDS_COLDSTART_DONE; 
            break;
		  }
        } /* for(;;) */
      
      }
       
	}

    #ifdef VX1000_COLDSTART_BENCHMARK
      gVX1000_DETECT_EndTime = VX1000_CLOCK;
	#endif

  }	/* 1st */

  return gVX1000.ToolDetectState&VX1000_TDS_DETECTED;
}   
  


/*---------------------------------------------------------------------------- */
/* Mailbox */

#ifdef VX1000_MAILBOX

#include <string.h>

/* Initialize the Master->Slave and Slave->Master mailboxes. */
void VX1000_MAILBOX_INIT(void) {
  
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
    gVX1000.Mailbox.MS_Ptr = (VX1000_UINT32)gVX1000.Mailbox.MSData;
    gVX1000.Mailbox.SM_Ptr = (VX1000_UINT32)gVX1000.Mailbox.SMData;
  
    #ifdef VX1000_MAILBOX_OVERLAY_CONTROL
      VX1000_INIT_CAL_PAGE();
    #endif

    VX1000_SPECIAL_EVENT(VX1000_EVENT_MAILBOX_INIT);
}
 

/* Write len bytes from pBuf to the Slave->Master mailbox */
/* and notify the master. */
VX1000_UINT32 vx1000_MailboxWrite(VX1000_UINT32 len, VX1000_UINT8* pBuf) {
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
  


/* Read the data from the next filled Master->Slave mailbox slot */
/* into pBuf and return the number of bytes in pLen. */
/* Upon calling pLen contains the maximum number of bytes that */
/* can be read into pBuf. If the number of bytes exceeds pLen, */
/* an error is returned and no data is copied. */
VX1000_UINT32 vx1000_MailboxRead(VX1000_UINT32* pLen, VX1000_UINT8* pBuf) {
  VX1000_UINT32 len;
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
  


/* XCP compliant protocol handler */
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


/* XCP calibration page handling */
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

/* XCP flash programming */
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


void VX1000_MAILBOX_CONTROL(void) {
  
  VX1000_UINT32 rxLen,txLen;
  VX1000_UINT8 rxBuf[8],txBuf[8];
  
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
          /* CRO_PROGRAM_PREPARE_SIZE                   */
		  /* @@@@ Problem: How to get start addr ?? */
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
        CRM_ERR = 0x20; /* CRC_CMD_UNKNOWN          */
    }
    if (CRM_ERR) CRM_CMD = 0xFE;
    vx1000_MailboxWrite(txLen,txBuf);    
  }
}


#ifdef VX1000_MAILBOX_PRINTF

#include <stdarg.h>

VX1000_UINT32 gVx1000EvLen = 0;
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
    vx1000_MailboxWrite(gVx1000EvLen,(VX1000_UINT8*)gVx1000EvBuf);    
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

#endif /* MAILBOX_PRINTF */


#endif


/* History:  */
/*
$Log: /VX1000/TriCore/Hover/vx1000_tricore.c $
// 
// 49    10.05.11 13:23 Rainer
// VX1000_INIT_CAL_PAGE
// 
// 48    1.04.11 18:25 Rainer
// Some MISRA violations removed
// 
// 47    1.04.11 17:24 Rainer
// Some MISRA violations removed

// 46    8.03.11 8:23 Rainer
// Log
*/
