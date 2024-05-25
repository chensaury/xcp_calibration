//-----------------------------------------------------------------------------
// Program instrumentation for Vector VX with Tricore DAP                                                                                                                               
// User specific configuration parameters
// Example for 17x7 demo project
//-----------------------------------------------------------------------------


#include "project.h"

//-----------------------------------------------------------------------------
// Define the target ECU identification string (for XCP GET_ID)
// This is optional and may be used by CANape to autodetect the A2L file name

#define VX1000_ECU_ID         "DEMO" // CANape can automatically load DEMO.A2L
#define VX1000_ECU_ID_LEN     4


//-----------------------------------------------------------------------------
// DAP mode

// Enable 3 or 2 wire DAP mode and disable BYPASS (JTAG) to increase immunity againt disturbances 
// 2 wire DAP mode is highly recomended
// VX1000_OCDS_OCNTRL =  0x0000000F;  // DJMODE = 11 Three PIN DAP with disabled BYPASS  
// VX1000_OCDS_OCNTRL =  0x00000007;  // DJMODE = 01 Two-pin DAP with disabled BYPASS
#define VX1000_OCDS_OCNTRL 0x00000007


//-----------------------------------------------------------------------------
// Timestamps
// Define a free runing 32 Bit timer to generate DAQ timestamps and specify the resolution
#ifndef STM_TIM0
  #define STM_TIM0 *(volatile unsigned int*)0xF0000210 /* Use System Timer 0 */
#endif
#define VX1000_CLOCK STM_TIM0
#if defined(TRIBOARD_TC1797) || defined(TRIBOARD_TC1387) || defined(TRIBOARD_TC1782)
  #define VX1000_CLOCK_TICKS_PER_MS 45000UL // STM_TIM0 resolution (180.000 MHz)    
#else
  #define VX1000_CLOCK_TICKS_PER_MS 33333UL // STM_TIM0 resolution (133.333 MHz)
#endif

//-----------------------------------------------------------------------------
// Olda (daq display table based measurment data acquisition)

// Define a memory location were the OLDA (daq display) tables are stored

// Option 1:
// Use 8KByte OVRAM 
#define VX1000_OLDA_MEMORY_ADDR 0xAFE80000 // Must always be non cached !
#define VX1000_OLDA_MEMORY_SIZE 0x2000 

// Option 2:
// Use 16KByte EMEM
//#define VX1000_OLDA_MEMORY_ADDR 0 
//#define VX1000_OLDA_MEMORY_SIZE 0

// Option 3:
// Use 2KByte memory defined in within VX1000_DATA
// #define VX1000_OLDA_MEMORY_SIZE 0x800

// Option 4:
// Share the memory with the XCP on CAN driver
//#include "XCPBasic.h"
//#define VX1000_OLDA_MEMORY_ADDR ((unsigned int)&xcp.Daq) // Addr
//#define VX1000_OLDA_MEMORY_SIZE sizeof(xcp.Daq) // Size in Bytes

// Turn on overload detection
#define VX1000_OLDA_OVERLOAD_DETECTION

// Turn on benchmarking of the event copy durations, remove this to save memory
#define VX1000_OLDA_BENCHMARK 


//-----------------------------------------------------------------------------
// Bypassing

// Enable Bypassing
#define VX1000_STIM

// Enable indirect stimulation with OLDA transfers
#define VX1000_STIM_BY_OLDA

// Turn on benchmarking of the stim wait durations, remove this to save memory
#define VX1000_STIM_BENCHMARK 
// Create a histogram from 0 to 255*10us stim wait duration
// Create a histogram from 0 to 255 timeouts in sequence
#define VX1000_STIM_HISTOGRAM



//-----------------------------------------------------------------------------
// Coldstart

// Define the maximum coldstart delay
// 0 = disable
// #define VX1000_COLDSTART_TIMEOUT 50 // ms

// Turn on benchmarking of the cold start behaviour, undef this to save memory
// #define VX1000_COLDSTART_BENCHMARK 



//-----------------------------------------------------------------------------
// Mailbox

// Use the mailbox to do handle PrintF or Calibration Page Switching
//#define VX1000_MAILBOX
//#define VX1000_MAILBOX_OVERLAY_CONTROL
//#define VX1000_MAILBOX_PRINTF




//-----------------------------------------------------------------------------
// Code instrumentation example:

/*

#include "VX1240.h"


// Global data of the VX1000 system
// Must be in a defined address location within on the the trace memory windows !!!!
// Its address (&gVX1000) must be configured in VXPARAMS.INI
VX1000_DATA;  


void main( void ) {

  // Initialize the VX1000 system
  // Must be called before any other VX1000_xxx function is called
  VX1000_INIT();

  // Check if the VX1000 is connected and powered
  // Confirm that the VX1000 has been detected
  // Take any actions needed to enable a cold start data acquisition
  if (VX1000_DETECT()) {
	// VX1000 detected !
	
	// VX1000 will take over control for EDRAM and OVRCON 
	// It may be nessesary to avoid resource conflicts
	// For instance, disable a XCP on CAN driver which uses the overlay mechanism for calibration
  }

  ...

  for (;;) {
  
    ...
  
    // Measurement    
    VX1000_EVENT(0); // Trigger XCP measurement event number 0
    
    
    // Bypassing
    // Event number 2 is the bypass stimulation event, it indicates that the ECU is now waiting for completion of the stimulation
    // Event number 1 is the bypass trigger event, it is used to trigger calculation of the bypass in the tool, as long as the bypass is not activated in the tool, this event is not executed                                  
    // 2000 is the timeout in ms, in case of timeout, the original code will not be executed
    if (!VX1000_BYPASS(1,2,2000)) {
        
      // Original code to be bypassed
      out = function(in);
    }  

    VX1000_STIM_CONTROL(); // Put this cyclic call anywhere in your code, but outside of a bypassed function

   
  }
}

void task1 {
  ...
  // Measurement
  VX1000_EVENT(7); // Trigger XCP event number 7
}



Notes:
Event numbers may range from 0 to 30
VX1240.C has to be linked to your project


*/

