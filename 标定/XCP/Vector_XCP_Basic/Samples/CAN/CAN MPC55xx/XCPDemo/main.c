/*----------------------------------------------------------------------------
| File:
|   main.c  
|
| Project:
|   XCP Demo with CANape Calibration Tool
|
| Description:
|   Uses an iSystem or Freescale 5554 Eval Board to demonstrate 
|   XCP on CAN or the XCP on Ethernet VX1000 system.
|
 ----------------------------------------------------------------------------*/

#include "project.h"

#include <math.h>
#include "filter.h"


//-----------------------------------------------------------------
// Defines
 
#define mem(addr) (*(unsigned char volatile *)(addr))
#define memw(addr) (*(unsigned short volatile *)(addr))

#define SIU_PCR203  0xC3F901D6
#define SIU_PCR204  0xC3F901D8
#define SIU_GPDO203 0xC3F906CB // GPIO pin data output register 203
#define SIU_GPDO204 0xC3F906CC // GPIO pin data output register 204

#define SIU_PCR206  0xC3F901DC
#define SIU_PCR207  0xC3F901DE
#define SIU_GPDO206 0xC3F906CE // GPIO pin data output register 206 
#define SIU_GPDO207 0xC3F906CF // GPIO pin data output register 207 
#define SIU_GPDI206 0xC3F908CE // GPIO pin data input register 206 
#define SIU_GPDI207 0xC3F908CF // GPIO pin data input register 207 

#ifdef ISYSTEM_BOARD
  #define PCR_LED1 SIU_PCR203
  #define PCR_LED2 SIU_PCR204
  #define OUT_LED1 SIU_GPDO203
  #define OUT_LED2 SIU_GPDO204  
  #define PCR_EN1 SIU_PCR206
  #define PCR_EN2 SIU_PCR207
  #define OUT_EN1 SIU_GPDO206
  #define OUT_EN2 SIU_GPDO207  
#else
  #define PCR_LED1 SIU_PCR206
  #define PCR_LED2 SIU_PCR207
  #define OUT_LED1 SIU_GPDO206
  #define OUT_LED2 SIU_GPDO207  
  #define PCR_EN1 SIU_PCR203
  #define PCR_EN2 SIU_PCR204
  #define OUT_EN1 SIU_GPDO203
  #define OUT_EN2 SIU_GPDO204  
#endif




//-----------------------------------------------------------------
// Measurement Data in RAM

vuint8 counter1 = 0;  // Incremented every slow task, XCP event number 1
vuint8 counter0 = 0;  // Incremented every fast task, XCP event number 0

// ADC
unsigned short adc0 = 0;
unsigned short adc0_filtered = 0;
unsigned int adc0_timeout = 0;
unsigned char adc0_conversion = 0;
float adc = 0;

// Test values
struct {
  unsigned int b1 : 3;
  unsigned int b2 : 8;
  unsigned int b3 : 5;
} test_bits = { 3,8,5 };
unsigned char test_byte = 1;
unsigned short test_word = 2;
unsigned int test_dword = 4;
float test_float = 0.4;
double test_double = 0.8;
unsigned short test_array[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};



//-----------------------------------------------------------------
// Calibration Parameters
// Using 3 different calibration concepts



// Calibration concept 1:
//------------------------------
// Parameters in FLASH handled with a pointer based calibration concept

// Memory segment 0x00180000-0x001FFFFF

// AUTOSAR single/pointers with page switching via XCP_SET/GET_CAL_PAGE
// CANape settings:
// Pointer table addr: 0x4000e000
// Pointer table size: 4*4 Bytes
// Pointer size: 4 Bytes
// Pointer table init values in FLASH addr: 0x180020
// Pointer table format: Motorola
// PoolRAM: 0x4000e010
// PoolRAM size: 0x200 Bytes


#define DEFINE_PARAMETERS
#include "cc_autosar_params.h"  // Include parameter definitions from the Simulink modell



// Calibration concept 2:
//------------------------------
// Readonly parameters in FLASH 

// Memory segment 0x00180000-0x001FFFFF

// Flash signature
__attribute__((section("calflash_signature"))) const char calflash_sign[18] =  {0x00,'D','E','F','A','U','L','T',0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
// Flash EPK
__attribute__((section("calflash_signature"))) const char epk[] = "XCPDEMO V1.1";

// This also includes all variables in rodata (const)

#define FLASH_CAL_PAR __attribute__((section("calflash")))

FLASH_CAL_PAR unsigned int map0[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
FLASH_CAL_PAR unsigned int map1[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
FLASH_CAL_PAR unsigned int map2[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
FLASH_CAL_PAR unsigned int map3[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
FLASH_CAL_PAR unsigned int map4[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
FLASH_CAL_PAR unsigned int map5[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
FLASH_CAL_PAR unsigned int map6[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
FLASH_CAL_PAR unsigned int map7[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};





// Calibration concept 3:
//------------------------------

// Memory segment RAM 0x40000000-0x40003FFF 

// Parameters in RAM initialized from FLASH during startup routine
// No page switching support
// A2L/MAP contains RAM addresses starting at 0x40000000 
// FLASH address of startup initialization values is 0x00080000

__attribute__((section("calram"))) volatile unsigned short h = 4000; // Setpoint


#define RAM_CAL_PAR __attribute__((section("calram"))) volatile

RAM_CAL_PAR unsigned int adc_cycle_time = 100; // 100us default cycle time for fast task

RAM_CAL_PAR float adc_factor = 1/16000.0;
RAM_CAL_PAR  unsigned char adc_filter_depth = 4; // Depth of the floating average filter for ADC

RAM_CAL_PAR unsigned int main_cycle_time = 10; // 10ms default cycle time for slow task

RAM_CAL_PAR unsigned int msg_trigger = 0; // Trigger for a single CAN message
RAM_CAL_PAR unsigned int msg_enable = 0; // Enable for a periodic CAN message
RAM_CAL_PAR unsigned char msg_data[8]  = {1,2,3,4,5,6,7,8};
RAM_CAL_PAR unsigned char msg_len  = 8;

RAM_CAL_PAR unsigned int map8[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
RAM_CAL_PAR unsigned int map9[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
RAM_CAL_PAR unsigned int map10[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
RAM_CAL_PAR unsigned int map11[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
RAM_CAL_PAR unsigned int map12[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
RAM_CAL_PAR unsigned int map13[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
RAM_CAL_PAR unsigned int map14[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
RAM_CAL_PAR unsigned int map15[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};


RAM_CAL_PAR unsigned char reserved[0x1000] = {0}; // Fill to 0x40001fff





//-----------------------------------------------------------------
// Utility

void FatalError( void ) {
  
  // Stop
  static unsigned char i;
  static unsigned int j; 
  for (i=0;;i++) {
    mem(OUT_LED1 ) = i&1; 
    mem(OUT_LED2) = i&1;
    for (j=0;j<1000000;i++);
  }
}


void __eabi() {
}




//-----------------------------------------------------------------
// Main

int main(void)
{
  static vuint32 clock1, clock0;  
  static filter_t adc0_filter;

  vuint32 clock;  
  
  // Configure and test external RAM
  // External RAM is used to overlay FLASH with RAM for calibration of constant parameters
  cfg_mpc5500ccd();

  // Initialize LEDs
  memw(PCR_LED1) = 0x200; // Output
  memw(PCR_LED2) = 0x200; // Output
  mem(OUT_LED1) = 0; // LED off
  mem(OUT_LED2) = 0;
  
  // Init XCP on CAN
  CanInit();
  XcpInit();
  
  // Init ADC
  adc0 = 0;
  adc0_filtered = 0;
  adc0_timeout = 0;
  adc0_conversion = 0;
  filter_init(0,&adc0_filter,adc_filter_depth);
	Init_AD(ADC0, SCDF_24, 0, ST_SINGLE_SCAN, POLL);				// initialize ADC module
  
  // Initialize other measurement data
  counter1 = counter0 = 0;
  
  // Mainloop
  clock1 = clock0 = clock = 0;
  for (;;) {
                                             
    clock = SYSTEM_CLOCK();

    
    // Slow cyclic task (cycle time is in parameter main_cycle_time, default is 10ms, 0 is off)
    if (main_cycle_time>0) {
      if (clock - clock1 > main_cycle_time*SYSTEM_CLOCK_TICKS_PER_MS) {
        clock1 = clock;
        counter1++;     
  
        // ADC
        // Normalize the sensor value
        adc = (adc0_filtered+adc_offset)*adc_factor;
        if (adc>adc_max) adc=adc_max;
        if (adc<adc_min) adc=adc_min;
  
        // Test measurement values
        test_bits.b1 += 1;
  	    test_bits.b2 += 1;
  	    test_bits.b3 += 1;
  	    test_byte += 1;
  	    test_word += 1;
  	    test_dword += 1;
  	    test_float += 0.1;
  	    test_double += 0.1;
        test_array[test_byte&0xF] += 1;
        
        // LED activity signal
        mem(OUT_LED1) = (led_pattern[(counter1>>4)&0xF]>>0) & 1;
        mem(OUT_LED2) = (led_pattern[(counter1>>4)&0xF]>>1) & 1;
  
        // Cyclic CAN message
        if (msg_trigger>0) msg_trigger--;
        if (msg_enable || msg_trigger==1) {
          msg_trigger = 0;
          if (CanMsgTransmitted()) {
            msg_data[0] = (vuint8)counter1;
            CanTransmit(CAN_CYCLIC_TX_ID, msg_len, (vuint8 *)msg_data);
            while (!CanMsgTransmitted());
            XcpEvent(0x02); // Trigger an XCP measurement event
          }
        }      
        
        XcpEvent(0x01); // Trigger an XCP measurement event
        
        // XCP on CAN incomming message Handler
        XcpRxHandler();
        XcpBackground();
  
      }
    }    

    // Fast cyclic task (cycle time is in parameter adc_cycle_time, default is 100us, 0 is off)  
    if (adc_cycle_time>0) {
      if (clock - clock0 > adc_cycle_time*SYSTEM_CLOCK_TICKS_PER_US) {
        clock0 = clock;
        counter0++;
  
        if (adc0_conversion!=0) { // Conversion in progress
          unsigned int tmp;
  	      if (Read_poll_Result(RESULT_FIFO_0, &tmp) == RESULT_AVAILABLE) { // Result available
            adc0 = tmp; 
            adc0_filtered = filter_calc(adc0,&adc0_filter,adc_filter_depth);
            adc0_conversion = 0;
          } 
          else {
            adc0_timeout++;
            if (adc0_timeout>10) {
              adc0_conversion = 0;
              adc0_timeout = 0;
            }
          }
        }
  
       if (adc0_conversion==0) { // Start a new conversion
        	Start_Conversion(ADC0, 0, RESULT_FIFO_0, SAMPLING_TIME_64, 0, 0, 0);
          adc0_conversion = 1;
          adc0_timeout = 0;
        }
        
        XcpEvent(0x00); // Trigger a measurement event
      }
    }
    
    // XCP on CAN outgoing message Handler
    XcpTxHandler();
    
  } // for (;;)
  
}




