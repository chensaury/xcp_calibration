/*----------------------------------------------------------------------------
| File:
|   MAIN.C
|
| Project:
|   XCP on SPI Sample
|
| Description:
|   Main routine, Timer interrupt
|
 ----------------------------------------------------------------------------*/


#include "reg_m63200.h"
#include "atmel91.h"


#include "main.h"
#include "spi.h"
#include "xcpBasic.h"


uint32 ulMainCounter, ulMsCounter;


uint32 ulTimerCounter0, ulMaxTimerCounter0;
uint32 ulTimerCounter1, ulMaxTimerCounter1;
uint32 ulTimerCounter2, ulMaxTimerCounter2;
Bool bTimerTriggered0, bTimerTriggered1, bTimerTriggered2;



/* Test */
/* Dummy measurement data, enough to supply up to 400 KB/sec DAQ in the 2ms event */
uint32  ulData000 = 0; 
uint32  ulData001 = 0; 
uint32  ulData002 = 0; 
uint32  ulData003 = 0; 
uint32  ulData004 = 0; 
uint32  ulData005 = 0; 
uint32  ulData006 = 0; 
uint32  ulData007 = 0; 
uint32  ulData008 = 0; 
uint32  ulData009 = 0; 
uint32  ulData010 = 0; 
uint32  ulData011 = 0; 
uint32  ulData012 = 0; 
uint32  ulData013 = 0; 
uint32  ulData014 = 0; 
uint32  ulData015 = 0; 
uint32  ulData016 = 0; 
uint32  ulData017 = 0; 
uint32  ulData018 = 0; 
uint32  ulData019 = 0; 
uint32  ulData020 = 0; 
uint32  ulData021 = 0; 
uint32  ulData022 = 0; 
uint32  ulData023 = 0; 
uint32  ulData024 = 0; 
uint32  ulData025 = 0; 
uint32  ulData026 = 0; 
uint32  ulData027 = 0; 
uint32  ulData028 = 0; 
uint32  ulData029 = 0; 
uint32  ulData030 = 0; 
uint32  ulData031 = 0; 
uint32  ulData032 = 0; 
uint32  ulData033 = 0; 
uint32  ulData034 = 0; 
uint32  ulData035 = 0; 
uint32  ulData036 = 0; 
uint32  ulData037 = 0; 
uint32  ulData038 = 0; 
uint32  ulData039 = 0; 
uint32  ulData040 = 0; 
uint32  ulData041 = 0; 
uint32  ulData042 = 0; 
uint32  ulData043 = 0; 
uint32  ulData044 = 0; 
uint32  ulData045 = 0; 
uint32  ulData046 = 0; 
uint32  ulData047 = 0; 
uint32  ulData048 = 0; 
uint32  ulData049 = 0; 
uint32  ulData050 = 0; 
uint32  ulData051 = 0; 
uint32  ulData052 = 0; 
uint32  ulData053 = 0; 
uint32  ulData054 = 0; 
uint32  ulData055 = 0; 
uint32  ulData056 = 0; 
uint32  ulData057 = 0; 
uint32  ulData058 = 0; 
uint32  ulData059 = 0; 
uint32  ulData060 = 0; 
uint32  ulData061 = 0; 
uint32  ulData062 = 0; 
uint32  ulData063 = 0; 
uint32  ulData064 = 0; 
uint32  ulData065 = 0; 
uint32  ulData066 = 0; 
uint32  ulData067 = 0; 
uint32  ulData068 = 0; 
uint32  ulData069 = 0; 
uint32  ulData070 = 0; 
uint32  ulData071 = 0; 
uint32  ulData072 = 0; 
uint32  ulData073 = 0; 
uint32  ulData074 = 0; 
uint32  ulData075 = 0; 
uint32  ulData076 = 0; 
uint32  ulData077 = 0; 
uint32  ulData078 = 0; 
uint32  ulData079 = 0; 
uint32  ulData080 = 0; 
uint32  ulData081 = 0; 
uint32  ulData082 = 0; 
uint32  ulData083 = 0; 
uint32  ulData084 = 0; 
uint32  ulData085 = 0; 
uint32  ulData086 = 0; 
uint32  ulData087 = 0; 
uint32  ulData088 = 0; 
uint32  ulData089 = 0; 
uint32  ulData090 = 0; 
uint32  ulData091 = 0; 
uint32  ulData092 = 0; 
uint32  ulData093 = 0; 
uint32  ulData094 = 0; 
uint32  ulData095 = 0; 
uint32  ulData096 = 0; 
uint32  ulData097 = 0; 
uint32  ulData098 = 0; 
uint32  ulData099 = 0; 
uint32  ulData100 = 0;
uint32  ulData101 = 0;
uint32  ulData102 = 0;
uint32  ulData103 = 0;
uint32  ulData104 = 0;
uint32  ulData105 = 0;
uint32  ulData106 = 0;
uint32  ulData107 = 0;
uint32  ulData108 = 0;
uint32  ulData109 = 0;
uint32  ulData110 = 0;
uint32  ulData111 = 0;
uint32  ulData112 = 0;
uint32  ulData113 = 0;
uint32  ulData114 = 0;
uint32  ulData115 = 0;
uint32  ulData116 = 0;
uint32  ulData117 = 0;
uint32  ulData118 = 0;
uint32  ulData119 = 0;
uint32  ulData120 = 0;
uint32  ulData121 = 0;
uint32  ulData122 = 0;
uint32  ulData123 = 0;
uint32  ulData124 = 0;
uint32  ulData125 = 0;
uint32  ulData126 = 0;
uint32  ulData127 = 0;
uint32  ulData128 = 0;
uint32  ulData129 = 0;
uint32  ulData130 = 0;
uint32  ulData131 = 0;
uint32  ulData132 = 0;
uint32  ulData133 = 0;
uint32  ulData134 = 0;
uint32  ulData135 = 0;
uint32  ulData136 = 0;
uint32  ulData137 = 0;
uint32  ulData138 = 0;
uint32  ulData139 = 0;
uint32  ulData140 = 0;
uint32  ulData141 = 0;
uint32  ulData142 = 0;
uint32  ulData143 = 0;
uint32  ulData144 = 0;
uint32  ulData145 = 0;
uint32  ulData146 = 0;
uint32  ulData147 = 0;
uint32  ulData148 = 0;
uint32  ulData149 = 0;
uint32  ulData150 = 0;
uint32  ulData151 = 0;
uint32  ulData152 = 0;
uint32  ulData153 = 0;
uint32  ulData154 = 0;
uint32  ulData155 = 0;
uint32  ulData156 = 0;
uint32  ulData157 = 0;
uint32  ulData158 = 0;
uint32  ulData159 = 0;
uint32  ulData160 = 0;
uint32  ulData161 = 0;
uint32  ulData162 = 0;
uint32  ulData163 = 0;
uint32  ulData164 = 0;
uint32  ulData165 = 0;
uint32  ulData166 = 0;
uint32  ulData167 = 0;
uint32  ulData168 = 0;
uint32  ulData169 = 0;
uint32  ulData170 = 0;
uint32  ulData171 = 0;
uint32  ulData172 = 0;
uint32  ulData173 = 0;
uint32  ulData174 = 0;
uint32  ulData175 = 0;
uint32  ulData176 = 0;
uint32  ulData177 = 0;
uint32  ulData178 = 0;
uint32  ulData179 = 0;
uint32  ulData180 = 0;
uint32  ulData181 = 0;
uint32  ulData182 = 0;
uint32  ulData183 = 0;
uint32  ulData184 = 0;
uint32  ulData185 = 0;
uint32  ulData186 = 0;
uint32  ulData187 = 0;
uint32  ulData188 = 0;
uint32  ulData189 = 0;
uint32  ulData190 = 0;
uint32  ulData191 = 0;
uint32  ulData192 = 0;
uint32  ulData193 = 0;
uint32  ulData194 = 0;
uint32  ulData195 = 0;
uint32  ulData196 = 0;
uint32  ulData197 = 0;
uint32  ulData198 = 0;
uint32  ulData199 = 0;


//--------------------------------------------------------------------------------------------------
// Utilities

static int intr_dis_ctr = 0; 

// Disables all interrupts by setting the FIQ and IRQ flags in CPSR. 
void utils_disable_interrupts (void) { 
  // disable the interrupts 
#pragma asm 
  stmdb r13!, {r1}        ; push r1 to stack
  mrs r1, CPSR            ; move content of CPSR to register r1 
  orr r1, r1, #0b11000000 ; set IRQ and FIQ flags to disable IRQ and FIQ, don't change the others 
  msr CPSR_c, r1          ; write content of r1 back to CPSR  
  nop
  ldmia r13!, {r1}        ; pop original content r1 from stack 
#pragma endasm 

  intr_dis_ctr++; 

  return; 
} // utils_disable_interrupts 


// Enables FIQ and IRQ interrupts by clearing the FIQ and IRQ flags in the CPSR register. 
void utils_enable_interrupts (void) { 

  intr_dis_ctr--; 

  if (intr_dis_ctr <= 0) { 
    intr_dis_ctr = 0; 

    // enable the interrupts 
    #pragma asm 
      stmdb r13!, {r1}        ; push r1 to stack
      mrs r1, CPSR            ; move content of CPSR to register r1 
      and r1, r1, #0xFFFFFF3F ; clear IRQ and FIQ flags to enable IRQ and FIQ, don't change the others 
      msr CPSR_c, r1          ; write content of r1 back to CPSR 
      nop
      ldmia r13!, {r1}        ; pop r1 from stack 
    #pragma endasm 
  } 

  return; 
} // utils_enable_interrupts 


void initLeds(void) {

  PIOB_BASE->PIO_PER = 0xffc0;      // PB8-PB15 enabled -> LEDs
  PIOB_BASE->PIO_OER = 0xffc0;      // output enable
  PIOB_BASE->PIO_MDDR = 0xffc0;
  PIOB_BASE->PIO_CODR = 0xffc0;

  PIOA_BASE->PIO_PER = 0x00f0;      // PA4-PA7 for debugging
  PIOA_BASE->PIO_OER = 0x00f0;      // PA4-PA7 for debugging
  PIOA_BASE->PIO_MDDR = 0x00f0;
  PIOA_BASE->PIO_CODR = 0x00f0;
}


//--------------------------------------------------------------------------------------------------
// Timer interrupt

// 1ms timer interrupt
__interrupt void t3_isr(void) {

  // Free running counter 1ms resolution
  // Used as XCP DAQ clock
  ulMsCounter++;

  // 10ms Event
  ulTimerCounter0++;
  if (ulTimerCounter0>=ulMaxTimerCounter0) {
    ulTimerCounter0 = 0;
    bTimerTriggered0 = kTrue;
  }

  // 20ms Event
  ulTimerCounter1++;
  if (ulTimerCounter1>=ulMaxTimerCounter1) {
    ulTimerCounter1 = 0;
    bTimerTriggered1 = kTrue;
  }

  // 500ms Event
  ulTimerCounter2++;
  if (ulTimerCounter2>=ulMaxTimerCounter2) {
    ulTimerCounter2 = 0;
    bTimerTriggered2 = kTrue;
  }

  TC3_CCR = 0x05;      //  restart timer 
  AIC_EOICR = TC3_SR;
}


void initTimerAndFlags(void) {

  ulTimerCounter0 = 0;          // Flags and Counters
  bTimerTriggered0 = kFalse;
  ulMaxTimerCounter0 = DUMMY_TIME_MS;
  ulTimerCounter1 = 0;
  bTimerTriggered1 = kFalse;
  ulMaxTimerCounter1 = TOGGLE_LED_TIME_MS;
  ulTimerCounter2 = 0;
  bTimerTriggered2 = kFalse;
  ulMaxTimerCounter2 = ECU_EVENT_TIME_MS;
  bEventSPIxcpCmd = kFalse;
  bEventSPIpacketLost = kFalse;
  
  utils_enable_interrupts();    // enable arm irq
  AIC_SMR9 = 0x22;              // advanced interrupt handler
  AIC_SVR9 = (uint32)t3_isr;
  AIC_ICCR = 0x0200;
  AIC_IECR = 0x0200;

  PMC_PCER = PMC_TC3_CLK_EN;
  TC3_BMR = 0x14;               // Timer 3
  TC3_CMR = 0x8002;
  TC3_RC = 770;
  TC3_IER = 0x10;
  TC3_CCR = 0x05;               //  enable and trigger timer 
}



//--------------------------------------------------------------------------------------------------
// Mainloop

void main(void) {

  uint8  ucToggle;
  uint8  ucCounter;

  spiInit();
  XcpInit();
  initTimerAndFlags();
  initLeds();
  
  ucCounter = 0;
  ucToggle = 0;

  while (TRUE) {

    ulMainCounter++;

    // Cyclic measurement data acquisition example 
    // Every 2 ms
    if (bTimerTriggered2!=0) {
      bTimerTriggered2 = kFalse;
	
      ulData000++;

      // Every 10 ms
      if (++ucCounter>=10) {
      	ucCounter = 0;
	
        ulData001++;

        XcpEvent(1);     

      }

      XcpEvent(0);
    }


    // Every 20ms
    // Transmit a dummy XCP event to keep SPI communication alive 
    if (bTimerTriggered0!=0) {
      bTimerTriggered0 = kFalse;

      spiTransmitDummy();
    }


    // Every 500 ms
    if (bTimerTriggered1!=0) {
      bTimerTriggered1 = kFalse;

      // Background processing for the XCP driver
      // Call this more often, if checksum calculation is too slow
      // Only needed if checksum calculation is used
      XcpBackground();

      // Show some activity 
      // Toggle the LEDs
      if (ucToggle==0) {
        ucToggle = 1;
        PIOB_BASE->PIO_SODR = PB8 | PB10 | PB6;
        PIOB_BASE->PIO_CODR = PB9 | PB11;
      } else {
        ucToggle = 0;
        PIOB_BASE->PIO_CODR = PB8 | PB10 | PB6;
        PIOB_BASE->PIO_SODR = PB9 | PB11;
      }

    }

    // Handle incoming XCP commands here
    // If this is done on interrupt level, care must ne taken to avoid nested execution
    if (bEventSPIxcpCmd!=kFalse) { 
      bEventSPIxcpCmd = kFalse;

      XcpCommand((void*)rx_xcp_buffer);
    }

    
  } 
}

