/*****************************************************************************
| Project Name:   XCP V1.0 - Driver
|    File Name:   test1.c
|
|  Description: 
|   XCP on RS232 demonstration on Atmel ATMEGA
|                                                   
|   
|***************************************************************************/
#include "project.h"
                  

//------------------------------------------------------------------------------
// Timer
// Uses a timer interrupt with 1ms cycle time 
 
unsigned int timer_counter = 0;

#define TIMER0_VALUE 0x83
void timer0_init(void)
{
 TCCR0= 0x00; //stop
 TCNT0= TIMER0_VALUE; //set count
 TCCR0= 0x03; //start timer
}

// 1ms Interrupt
#pragma interrupt_handler timer0_ovf_isr:iv_TIMER0_OVF
void timer0_ovf_isr(void)
{
  TCNT0 = TIMER0_VALUE; //reload counter value
 
  // Example
  // Trigger XCP data acquisition event 1 
  XCP_INTERUPT_CONTROL_OFF; // Notify XCP that interrupt is already disabled 
  XcpEvent(0);
  XCP_INTERUPT_CONTROL_ON;

  timer_counter++;
  PORTB ^= 0x04;
}

unsigned int Clock(void) 
{
  unsigned int t; 
  CLI(); //disable all interrupts
  t = timer_counter;
  SEI(); //re-enable interrupts
  return t;
}

void Delay(unsigned int w)
{
  unsigned int t= Clock();
  while (Clock()-t<w);
}

//------------------------------------------------------------------------------

unsigned int t0,t1,t;

//extern RAM tXcpDataType xcp;

void main( void )
{

  CLI(); //disable all interrupts

  // Init PORTB
  // LEDs
  DDRB  = 0xFF; // Outputs
  PORTB = 0xFF; // PullUps or Out 

  // Init PORTD
  // UART
  DDRD = 0x00;
  PORTD = 0xFF;

#if defined(__iom128v_h)

  XDIV  = 0x00; //xtal divider
  XMCRA = 0x00; //external memory  

  MCUCR = 0x00;
  EICRA = 0x00; //extended ext ints
  EICRB = 0x00; //extended ext ints
  EIMSK = 0x00;
  TIMSK = 0x31; // Timer Interrupt Mask
                // Timer1 Cap=BIT5, CmpA=BIT4, Timer0 Overflow=BIT0
  ETIMSK = 0x00; //extended timer interrupt sources

#else

  TIMSK = 0x01; //timer interrupt sources

#endif

  timer0_init();  
  InitUART(38400);

  SEI(); //re-enable interrupts

//#define TEST_UART
#ifdef TEST_UART
  for (;;) {
    
    if (DataInReceiveBuffer())  {
      unsigned char b = ReceiveByte();
      TransmitByte(b);
    }
      
    TransmitByte('H');
    Delay(50);
    PORTB ^= 0x01;
  }
#endif
            
  for (t=0;t<=255;t++) {
	PORTB = (unsigned char)t;
	Delay(2);
  }

  // XCP Initialisation 
  XcpInit();
  t0 = t1 = t = Clock();
        
  // Mainloop
  for (;;) { 


    t = Clock();

    // 10ms task
    if (t-t0>10) {
      t0 = t;

      // Poll for incoming XCP packets
      XcpReceiveCommand();

      PORTB ^= 0x02;
	  //PORTB = ((~xcp.SessionStatus) & 0xF0) | (PORTB & 0x0F); 

      XCP_INTERUPT_CONTROL_OFF; // Notify XCP that interrupt is already disabled 
      XcpEvent(1);
      XCP_INTERUPT_CONTROL_ON;
    }

    // 100ms task
    if (t-t1>100) {
      t1 = t;
    
      PORTB ^= 0x01;

      XCP_INTERUPT_CONTROL_OFF; // Notify XCP that interrupt is already disabled 
      XcpEvent(2);
      XCP_INTERUPT_CONTROL_ON;
    }

  } // for (;;)         

}







           