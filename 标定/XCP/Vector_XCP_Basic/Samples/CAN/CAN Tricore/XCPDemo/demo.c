

/*****************************************************************************
| Project Name:   XCP on CAN demo for Infineon Tricore TC17x7
|    File Name:   Demo.c
|
|  Description:   Application main file
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


//----------------------------------------------------------------------------
// Includes
// Definitions and declarations


#include "project.h"
#include "demo.h"    
#include "bypass.h"    


//----------------------------------------------------------------------------
// Defines

// DAQ event numbers
#define EVENT_10MS            0 
#define EVENT_100MS           1

// DAQ event cycles (us)
#define EVENT_CYCLE_10MS      10000UL   // 10ms
#define EVENT_CYCLE_100MS     100000UL  // 100ms


// Clock
#define CLOCK STM_TIM0
#if defined(TRIBOARD_TC1797) || defined(TRIBOARD_TC1387) || defined(TRIBOARD_TC1782)
  #define CLOCK_TICKS_PER_MS 45000ULL   // STM_TIM0 resolution (180.000 MHz)
#else
  #define CLOCK_TICKS_PER_MS 33333ULL   // STM_TIM0 resolution (133.333 MHz)
#endif


//----------------------------------------------------------------------------
// Measurement values

// Calibration demo
unsigned int led_counter = 0; // Incremented in 100ms task
unsigned char led_value = 0;  // Current state of the leds


// Analog converter
unsigned int adc_task_cycle = EVENT_CYCLE_10MS;
unsigned int adc_task_timeout = 3500; // us
unsigned int adc_task_counter = 0;
unsigned short adc_raw = 0;
float adc = 0;

// Test measurement values
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
unsigned char test_byte_4 = 1;
unsigned short test_word_1 = 2;
double test_double_1 = 0.8;
unsigned short test_word_4 = 2;
unsigned int test_dword_1 = 4;
unsigned short test_word_2 = 2;
unsigned char test_byte_1 = 1;
unsigned short test_word_3 = 2;
unsigned int test_dword_4 = 4;
float test_float_1 = 0.4;
unsigned int test_dword_3 = 4;
float test_float_3 = 0.4;
double test_double_2 = 0.8;
float test_float_4 = 0.4;
double test_double_4 = 0.8;
unsigned char test_byte_2 = 1;
unsigned int test_dword_2 = 4;
unsigned char test_byte_3 = 1;
double test_double_3 = 0.8;
float test_float_2 = 0.4;


//----------------------------------------------------------------------------
// Calibration parameters in FLASH

// Even if parameters are located in FLASH, they have to be volatile to prevent the compiler from optimizing


// Parameters handled with the FLASH overlay calibration concept

// Rename all sections to type.cal_data
// The farrom section rodata.cal_data is allocated at 0xA0100000 in the linker settings
// All calibration parameters must be farrom, zrodata.cal_data is nearrom and can not be relocated 
#pragma section all "cal_data" 
#define CAL_PAR volatile const __far 

CAL_PAR unsigned char led_pattern[16] = { 0x01,0x02,0x02,0x04,0x04,0x04,0x08,0x08,0x08,0x10,0x10,0x20,0x20,0x40,0x40,0x80 };
CAL_PAR float adc_ampl = 1;
CAL_PAR float adc_filter = 0.01;
CAL_PAR unsigned int map0[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map1[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map2[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map3[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map4[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map5[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map6[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map7[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map8[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map9[16][8]  = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map10[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map11[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map12[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map13[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map14[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map15[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};
CAL_PAR unsigned int map16[16][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8}};

#pragma section all
 



//----------------------------------------------------------------------------
// LED driver for Infineon EasyKit or TriBoard

void led_init( void ) {

  led_value = 0;
  
  // Initialize LED ports
  // Set LED pin out direction.
  #ifdef TRIBOARD_TC1797
    P3_IOCR0 = (P3_IOCR0 & 0x00000000) | 0x80808080;     
    P3_IOCR4 = (P3_IOCR4 & 0x00000000) | 0x80808080;
  #else
    P5_IOCR0 = (P5_IOCR0 & 0x00000000) | 0x80808080;    
    P5_IOCR4 = (P5_IOCR4 & 0x00000000) | 0x80808080;
  #endif

}

void led_set( unsigned char b ) {

  led_value = b;
  
  // LEDs 0=ON, 1=OFF
  #ifdef TRIBOARD_TC1797
      P3_OUT |= 0xFF;                   
      P3_OUT &=  ~b;                          
  #else
	  P5_OUT |= 0xFF;	  
	  P5_OUT &=  ~b;
  #endif

}

void led_on( unsigned char b ) {
  led_value |= b;
  led_set(led_value);
}

void led_off( unsigned char b ) {
  led_value &= ~b;
  led_set(led_value);
}



//----------------------------------------------------------------------------
// External memory configuration

#ifdef EXTERNAL_RAM

void ram_init( void ) {

    ///  ---------------------------------------------------------------------
    ///  System Peripheral Bus Control Unit (SBCU):
    ///  ---------------------------------------------------------------------
    ///  SBCU starvation protection is enabled
    ///  the debug trace is enabled. Error information is captured in 
    ///  register SBCU_EADD, SBCU_EDAT and SBCU_ECON
    ///  sample period of request for starvation protection: 64
    ///  SBCU bus time-out value: 65536 cycles

     SBCU_CON  =  0x4009FFFF;

    ///  ---------------------------------------------------------------------
    ///  LMB External Bus Unit (EBU):
    ///  ---------------------------------------------------------------------

    ///  - enable the EBU module clock
    ///  - disable EndInit Protection of the CLC Register
    ///  - request EBU to run off input clock divided by 3
    EBU_CLC  =  0x00190000;  // Entspricht Cummins

    ///  External Arbitration:
    ///  - arbitration mode: sole master mode
    ///  - arbitration inputs are asynchronous
    ///  - external bus is not locked after EBU gains ownership
    ///  - disable Time-out
    ///  - Lock Time-out disabled
    ///  - Output is #ADV
    ///  Global Chip Select Activation:
    ///  - no activation selected
    EBU_MODCON  =  0x000000E0; // Entspricht Cummins

    ///  Address Region 0:
    ///  - disable memory region 0
    ///  - Region is enabled for write access
    ///  - length of the region: 1 Mbyte
    ///  - Alternate segment to be compared to LMB address bit[31:28]
    ///  - Base address to be compared to LMB address in conjunction with the 
    ///    mask control.
    EBU_ADDRSEL0  =  0xD8000070;

    ///  - mode:  Demuxed Asynchronous Type External Memory
    ///  - Continuous mode. All data required for transaction is transferred 
    ///    in a single burst.
    ///  - CS is not delayed
    ///  - ADV is not delayed
    ///  - Two stages of synchronisation used
    ///  - BFCLK feedback not used
    ///  - Burst Flash Clock is disabled between accesses.
    ///  - OFF, input at WAIT pin is active low
    ///  - external waitstate insertion is disabled
    ///  - byte control signal control: to follow control signal (RD, RD/WR)
    ///  - Clock is enabled at beginning of access.
    EBU_BUSRCON0  =  0x40D30040;

    ///  - mode:  Demuxed Asynchronous Type External Memory
    ///  - Continuous mode. All data required for transaction is transferred 
    ///    in a single burst.
    ///  - CS is not delayed
    ///  - ADV is not delayed
    ///  - OFF, input at WAIT pin is active low
    ///  - external waitstate insertion is disabled
    ///  - byte control signal control: to follow control signal (RD, RD/WR)
    ///  - Clock is enabled at beginning of access.
    EBU_BUSWCON0  =  0x40D30000;

    ///  - RDDTACS: 15 clock cycles selected
    ///  - RDRECOVC: 7 clock cycles selected
    ///  - WAITRDC: 31 wait state
    ///  - external memory outputs data every 4 Cycle(s)
    ///  - Equal to INT_CLK/ 4 Frequency
    ///  - CMDDELAY: 7 clock cycles selected
    ///  - AHOLDC: 15 clock cycles selected
    ///  - ADDRC: 15 clock cycles selected
    EBU_BUSRAP0  =  0xFF7FFFFF;

    ///  - WRDTACS: 15 clock cycles selected
    ///  - WRRECOVC: 7 clock cycles selected
    ///  - WAITWRC: 31 wait state
    ///  - DATAC: 15 wait state
    ///  - external memory outputs data every 4 Cycle(s)
    ///  - Equal to INT_CLK/ 4 Frequency
    ///  - CMDDELAY: 7 clock cycles selected
    ///  - AHOLDC: 15 clock cycles selected
    ///  - ADDRC: 15 clock cycles selected
    EBU_BUSWAP0  =  0xFF7FFFFF;

    ///  Address Region 1:
    ///  - enable memory region 1
    ///  - Region is enabled for write access
    ///  - length of the region: 512 kbyte
    ///  - address: 0xD8000000 - 0xD807FFFF
    ///  - Alternate segment to be compared to LMB address bit[31:28]
    ///  - Base address to be compared to LMB address in conjunction with the 
    ///    mask control.
    //// this register must be set in the start-up file
    EBU_ADDRSEL1  =  0xD8000081;

    ///  - mode:  Demuxed Asynchronous Type External Memory
    ///  - Continuous mode. All data required for transaction is transferred 
    ///    in a single burst.
    ///  - CS is not delayed
    ///  - ADV is not delayed
    ///  - Two stages of synchronisation used
    ///  - BFCLK feedback not used
    ///  - Burst Flash Clock is disabled between accesses.
    ///  - OFF, input at WAIT pin is active low
    ///  - external waitstate insertion is disabled
    ///  - byte control signal control: to follow control signal (RD, RD/WR)
    ///  - Clock is enabled at beginning of access.
    //// this register must be set in the start-up file
    EBU_BUSRCON1  =  0x40430040;   // Cummins 0x40430040

    ///  - mode:  Demuxed Asynchronous Type External Memory
    ///  - Continuous mode. All data required for transaction is transferred 
    ///    in a single burst.
    ///  - CS is not delayed
    ///  - ADV is not delayed
    ///  - OFF, input at WAIT pin is active low
    ///  - external waitstate insertion is disabled
    ///  - byte control signal control: to follow control signal (RD, RD/WR)
    ///  - Clock is enabled at beginning of access.
    //// this register must be set in the start-up file
    EBU_BUSWCON1  =  0x00430000;   // Cummins 0x00430000

    ///  - RDDTACS: 1 clock cycles selected
    ///  - RDRECOVC: 0 Clock cycles Selected.
    ///  - WAITRDC: 1 wait state
    ///  - external memory outputs data every 1 Cycle(s)
    ///  - Equal to INT_CLK/ 1 Frequency
    ///  - CMDDELAY: 1 clock cycles selected
    ///  - AHOLDC: 1 clock cycles selected
    ///  - ADDRC: 1 clock cycles selected
    //// this register must be set in the start-up file
    EBU_BUSRAP1  =  0x11100081;   // Fehler im DAVE

    ///  - WRDTACS: 1 clock cycles selected
    ///  - WRRECOVC: 0 Clock cycles Selected.
    ///  - WAITWRC: 1 wait state
    ///  - DATAC: 1 wait state
    ///  - external memory outputs data every 1 Cycle(s)
    ///  - Equal to INT_CLK/ 1 Frequency
    ///  - CMDDELAY: 1 clock cycles selected
    ///  - AHOLDC: 1 clock cycles selected
    ///  - ADDRC: 1 clock cycles selected
    //// this register must be set in the start-up file
    EBU_BUSWAP1  =  0x11100081;


    ///  Address Region 2:
    ///  - disable memory region 2
    ///  - Region is enabled for write access
    ///  - length of the region: 128 Mbyte
    ///  - Alternate segment to be compared to LMB address bit[31:28]
    ///  - Base address to be compared to LMB address in conjunction with the 
    ///    mask control.
    EBU_ADDRSEL2  =  0x00000000;

    ///  - 32-bit Multiplexed Muxed Asynchronous Type External Memory 
    ///    (default after reset)
    ///  - Continuous mode. All data required for transaction is transferred 
    ///    in a single burst.
    ///  - CS is not delayed
    ///  - ADV is not delayed
    ///  - Two stages of synchronisation used
    ///  - BFCLK feedback not used
    ///  - Burst Flash Clock is disabled between accesses.
    ///  - OFF, input at WAIT pin is active low
    ///  - external waitstate insertion is disabled
    ///  - byte control signal control: to follow control signal (RD, RD/WR)
    ///  - Clock is enabled at beginning of access.
    EBU_BUSRCON2  =  0x00D30040;

    ///  - 32-bit Multiplexed Muxed Asynchronous Type External Memory 
    ///    (default after reset)
    ///  - Continuous mode. All data required for transaction is transferred 
    ///    in a single burst.
    ///  - CS is not delayed
    ///  - ADV is not delayed
    ///  - OFF, input at WAIT pin is active low
    ///  - external waitstate insertion is disabled
    ///  - byte control signal control: to follow control signal (RD, RD/WR)
    ///  - Clock is enabled at beginning of access.
    EBU_BUSWCON2  =  0x00D30000;

    ///  - RDDTACS: 15 clock cycles selected
    ///  - RDRECOVC: 7 clock cycles selected
    ///  - WAITRDC: 31 wait state
    ///  - external memory outputs data every 4 Cycle(s)
    ///  - Equal to INT_CLK/ 4 Frequency
    ///  - CMDDELAY: 7 clock cycles selected
    ///  - AHOLDC: 15 clock cycles selected
    ///  - ADDRC: 15 clock cycles selected
    EBU_BUSRAP2  =  0xFF7FFFFF;

    ///  - WRDTACS: 15 clock cycles selected
    ///  - WRRECOVC: 7 clock cycles selected
    ///  - WAITWRC: 31 wait state
    ///  - DATAC: 15 wait state
    ///  - external memory outputs data every 4 Cycle(s)
    ///  - Equal to INT_CLK/ 4 Frequency
    ///  - CMDDELAY: 7 clock cycles selected
    ///  - AHOLDC: 15 clock cycles selected
    ///  - ADDRC: 15 clock cycles selected
    EBU_BUSWAP2  =  0xFF7FFFFF;

    ///  Address Region 3:
    ///  - disable memory region 3
    ///  - Region is enabled for write access
    ///  - length of the region: 128 Mbyte
    ///  - Alternate segment to be compared to LMB address bit[31:28]
    ///  - Base address to be compared to LMB address in conjunction with the 
    ///    mask control.
    EBU_ADDRSEL3  =  0x00000000;

    ///  - 32-bit Multiplexed Muxed Asynchronous Type External Memory 
    ///    (default after reset)
    ///  - Continuous mode. All data required for transaction is transferred 
    ///    in a single burst.
    ///  - CS is not delayed
    ///  - ADV is not delayed
    ///  - Two stages of synchronisation used
    ///  - BFCLK feedback not used
    ///  - Burst Flash Clock is disabled between accesses.
    ///  - OFF, input at WAIT pin is active low
    ///  - external waitstate insertion is disabled
    ///  - byte control signal control: to follow control signal (RD, RD/WR)
    ///  - Clock is enabled at beginning of access.
    EBU_BUSRCON3  =  0x00D30040;

    ///  - 32-bit Multiplexed Muxed Asynchronous Type External Memory 
    ///    (default after reset)
    ///  - Continuous mode. All data required for transaction is transferred 
    ///    in a single burst.
    ///  - CS is not delayed
    ///  - ADV is not delayed
    ///  - OFF, input at WAIT pin is active low
    ///  - external waitstate insertion is disabled
    ///  - byte control signal control: to follow control signal (RD, RD/WR)
    ///  - Clock is enabled at beginning of access.
    EBU_BUSWCON3  =  0x00D30000;

    ///  - RDDTACS: 15 clock cycles selected
    ///  - RDRECOVC: 7 clock cycles selected
    ///  - WAITRDC: 31 wait state
    ///  - external memory outputs data every 4 Cycle(s)
    ///  - Equal to INT_CLK/ 4 Frequency
    ///  - CMDDELAY: 7 clock cycles selected
    ///  - AHOLDC: 15 clock cycles selected
    ///  - ADDRC: 15 clock cycles selected
    EBU_BUSRAP3  =  0xFF7FFFFF;

    ///  - WRDTACS: 15 clock cycles selected
    ///  - WRRECOVC: 7 clock cycles selected
    ///  - WAITWRC: 31 wait state
    ///  - DATAC: 15 wait state
    ///  - external memory outputs data every 4 Cycle(s)
    ///  - Equal to INT_CLK/ 4 Frequency
    ///  - CMDDELAY: 7 clock cycles selected
    ///  - AHOLDC: 15 clock cycles selected
    ///  - ADDRC: 15 clock cycles selected
    EBU_BUSWAP3  =  0xFF7FFFFF;

    ///  ---------------------------------------------------------------------
    ///  Data Memory Interface (DMI):
    ///  ---------------------------------------------------------------------
    ///  - No Data Cache
    ///  - 128 Kbyte Data Memory

    //// this register must be set in the start-up file
    //// DMI_CON  =  0x08000802;

    ///  ---------------------------------------------------------------------
    ///  Program Memory Interface (PMI):
    ///  ---------------------------------------------------------------------
    ///  - No Instruction Cache
    ///  - 40 Kbyte Program Memory

    //// this register must be set in the start-up file
    //// PMI_CON2  =  0x02800284;

  {
    unsigned int *p;
    unsigned int i;
    unsigned int v;


	// Check external RAM (256KByte)
	p = (unsigned int *)0xD8000000;
	for (i=0;i<0x10000/4;i++) *p++ = i;
	p = (unsigned int *)0xD8000000;
	for (i=0;i<0x10000/4;i++) {
      led_set((unsigned char)i);
	  v = *p++;
	  if (v != i) {
	    // RAM error
    	for (;;) {
     	  for (i=0;i<100000;i++);
          led_set(1&v++);
		}

	  }
	}
  }

}

#endif // EXTERNAL_RAM




//----------------------------------------------------------------------------
// PLL configuration

#if defined(TRIBOARD_TC1387) || defined(TRIBOARD_TC1782)

// Dave does not support TC1387 and TC1782 yet
// TC1767 used, reconfigure the PLL for 180MHz

#define PLLCON0    0x01018E40 	 // PDIV[24..27]=1+1, NDIV[9..15]=71+1 -> VCO=720MHz	
#define PLLCON1    0x00000003 	 // K1DIV=0+1,K2DIV=3+1
			   																																						
void pll_init( void ) {

  if (!SCU_PLLSTAT_PWDSTAT) {
     MAIN_vResetENDINIT();
     SCU_CCUCON0  =  0x00000001; // set FPI,LMB and PCP dividers
     SCU_PLLCON0_VCOBYP  =  1;  // set VCO bypass (goto Prescaler Mode)
     while (!SCU_PLLSTAT_VCOBYST);// wait for prescaler mode
     SCU_PLLCON0  =  PLLCON0; // set P,N divider, connect OSC
     SCU_PLLCON1  =  PLLCON1; // set K1,K2 divider
     MAIN_vSetENDINIT();
     while (SCU_PLLSTAT_VCOLOCK == 0);// wait for LOCK
     MAIN_vResetENDINIT();
     SCU_PLLCON0_VCOBYP  =  0;  // Reset VCO bypass (Leave Prescaler Mode)
     MAIN_vSetENDINIT();
  }

}

#endif



//----------------------------------------------------------------------------
// Main loop

void mainloop( void )
{
  static unsigned int clock;
  static unsigned int clock_adc;
  static unsigned int clock_background;

		 
  // Initialize the clock PLL
  #if defined(TRIBOARD_TC1387) || defined(TRIBOARD_TC1782)
    pll_init();			  
  #endif

  // Init status LEDs
  led_init();
  led_counter = 0;
  led_set(VERSION);
  DELAY(500000);
  
  // Init external RAM
  #ifdef EXTERNAL_RAM
    ram_init();
  #endif

  // Init XCP on CAN
  XcpInit();
    
  // Mainloop
  clock_adc = clock_background = 0;
  while(1) {

    // Read the 32 bit system timer     
    clock = CLOCK;    

    // Handle incoming XCP on CAN commands 
    XcpHandler();

    // 10ms Task (adc_task_cycle)
    if (clock-clock_adc>(CLOCK_TICKS_PER_MS*adc_task_cycle)/1000) {
      clock_adc = clock;

	  test_bits.b1 += 1;
	  test_bits.b2 += 1;
	  test_bits.b3 += 1;
	  test_byte += 1;
	  test_word += 1;
	  test_dword += 1;
	  test_float += 0.1;
	  test_double += 0.1;
      test_array[test_byte&0xF] += 1;
	  
      #ifdef EXTERNAL_RAM
	    (*(unsigned int*)0xD8000000)++;
	  #endif

      // Read ADC channel 0
      adc_task_counter++;
      ADC0_vStartSeq0ReqChNum(0,0,0,ADC0_ANA_0);
      while (ADC0_uwBusy());
      adc_raw = ADC0_uwGetResultData(RESULT_REG_0);

      // Bypass demo with VX1000 
      #ifdef VX1000_STIM // Bypass Begin
  	    BypassInput_2++;
        // Replace the ADC filter algo 
        // Event number EVENT_BYPASS_STIM is the bypass stimulation event, it indicates that the ECU is now waiting for completion of the stimulation
        // Event number EVENT_BYPASS_DAQ is the bypass trigger event, it should be used to trigger calculation of the bypass in the tool, as long as the bypass is not activated in the tool, this event is not executed                                  
        // Timeout is adc_task_timeout (default 3500us)
        #define EVENT_BYPASS_STIM   3
        #define EVENT_BYPASS_DAQ    2 
        if (!VX1000_BYPASS(EVENT_BYPASS_DAQ,EVENT_BYPASS_STIM,adc_task_timeout/*us*/)) {
	  #endif

      adc = adc_filter*((float)adc_raw/4095.0*adc_ampl) + (1-adc_filter)*adc; 
     
      #ifdef VX1000_STIM // Bypass End
	    // Set test output variables
	    BypassCalculateOutputs();
        }
      #endif

      XcpEvent(EVENT_10MS); // Trigger the 10ms XCP DAQ event

      XcpBackground(); // Handle XCP on CAN background tasks
	  
    }
    
    // 100ms Task
    if (clock-clock_background>(CLOCK_TICKS_PER_MS*(EVENT_CYCLE_100MS/1000))) {
      clock_background = clock;

      // LED activity signal with calibratable pattern
      led_counter++;
      led_value = led_pattern[led_counter&0xF];             
      led_set(led_value);

      // CAN activity message
      // Transmit a CAN message with the led_counter
      CAN_vLoadData(0, (unsigned char*)&led_counter); 
      CAN_vTransmit(0);

      XcpEvent(EVENT_100MS); // Trigger the 100ms XCP DAQ event
    }


  }

}















