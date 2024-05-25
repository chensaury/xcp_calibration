/* Interrupt mode driver for UART */                

#include "project.h"

#if defined(__iom644v_h) 

    #define UCSRB UCSR0B
    #define UCSRA UCSR0A
    #define UCSRC UCSR0C
    #define UBRRL UBRR0L
    #define UBRRH UBRR0H
    #define UDR   UDR0
    #define RXCIE RXCIE0   
    #define TXCIE TXCIE0   
    #define UDRIE UDRIE0   
    #define RXEN RXEN0    
    #define TXEN TXEN0
    
#endif

#if defined(__iom128v_h)
  #ifdef UART_0

    #define UCSRB UCSR0B
    #define UCSRA UCSR0A
    #define UCSRC UCSR0C
    #define UBRRL UBRR0L
    #define UBRRH UBRR0H
    #define UDR   UDR0
    #define RXCIE RXCIE0   
    #define TXCIE TXCIE0   
    #define UDRIE UDRIE0   
    #define RXEN RXEN0    
    #define TXEN TXEN0

  #else

    #define UCSRB UCSR1B
    #define UCSRA UCSR1A
    #define UCSRC UCSR1C
    #define UBRRL UBRR1L
    #define UBRRH UBRR1H
    #define UDR   UDR1
    #define RXCIE RXCIE1   
    #define TXCIE TXCIE1   
    #define UDRIE UDRIE1   
    #define RXEN RXEN1    
    #define TXEN TXEN1

  #endif

#endif
  
/* UART Buffer Defines */
#ifndef UART_RX_BUFFER_SIZE
  #define UART_RX_BUFFER_SIZE 256 /* 1,2,4,8,16,32,64,128 or 256 bytes */
#endif
#define UART_RX_BUFFER_MASK ( UART_RX_BUFFER_SIZE - 1 )

#ifndef UART_TX_BUFFER_SIZE
  #define UART_TX_BUFFER_SIZE 256 /* 1,2,4,8,16,32,64,128 or 256 bytes */
#endif
#define UART_TX_BUFFER_MASK ( UART_TX_BUFFER_SIZE - 1 )

#if ( UART_RX_BUFFER_SIZE & UART_RX_BUFFER_MASK )
  #error RX buffer size is not a power of 2
#endif
#if ( UART_TX_BUFFER_SIZE & UART_TX_BUFFER_MASK )
  #error TX buffer size is not a power of 2
#endif

/* Static Variables */
static unsigned char UART_RxBuf[UART_RX_BUFFER_SIZE];
static volatile unsigned char UART_RxHead;
static volatile unsigned char UART_RxTail;
static unsigned char UART_TxBuf[UART_TX_BUFFER_SIZE];
static volatile unsigned char UART_TxHead;
static volatile unsigned char UART_TxTail;



/* initialize UART */
void InitUART( unsigned long baudrate ) {

  UCSRB  = 0x00; // Disable while setting baud rate

  UCSRA = 0; // Normal mode
  
  #if !defined(__iom163v_h) 
  #ifdef URSEL
    UCSRC = BIT(URSEL) | 0x06; // Asynchronous, 1 Stop, no parity
  #else
    UCSRC = 0x06; // Asynchronous, 1 Stop, no parity
  #endif
  #endif
  
  // Double speed mode
  #ifdef UART_UBBRL
    UBRRL = UART_UBBRL;
  #else
  #ifdef UART_DOUBLE_SPEED
  UCSRA |= (1<<U2X); // Double speed
    // UBBR = F / (8*BAUDRATE) - 1
    // BAUDRATE = F / (UBBR+1) / 8
      // 20000000 / (115200 * 8) - 1 = 20.7 ->  UBBR = 21
      // 20000000 / 22 / 8 = 113.6
      // 20000000 / (57600 * 8) - 1 = 42.4  ->  UBBR = 42
      // 20000000 / 43 / 8 = 58.139
      // 14745600 / (115200 * 8) - 1 = 15   ->  UBBR = 15 
    UART_UBBRL = UBRRL = (unsigned char)((float)SYSCLK / (float)(baudrate * 8L) - 1.0 + 0.51); // Round 
    UBRRH = 0;      
  #else
    // UBBR = F / (16*BAUDRATE) - 1
    // BAUDRATE = F / (UBBR+1) / 16
      // 20000000 / (115200 * 16) - 1 = 9.85 ->  UBBR = 10
      // 20000000 / 11 / 8 = 113.636
      // 20000000 / (57600 * 16) - 1 = 20.7  ->  UBBR = 21
      // 20000000 / 22 / 16 = 56.818
      // 14745600 / (115200 * 16) - 1 = 7   ->  UBBR = 7 
    UBRRL = (unsigned char)((float)SYSCLK / (float)(baudrate * 16L) - 1.0 + 0.51); // Round 
    UBRRH = 0;      
  #endif
  #endif
    
  /* Enable UART receiver and transmitter, enable receive interrupt */
  UCSRB = ( (1<<RXCIE) | (1<<RXEN) | (1<<TXEN) );
	
  /* Flush receive buffer */
  UART_RxTail = 0;
  UART_RxHead = 0;
  UART_TxTail = 0;
  UART_TxHead = 0;
}


/*
 * UART_RX_interrupt set to UART, Rx Complete
 * UART_TX_interrupt set to UART Data Register Empty
 */


#if defined(__iom128v_h) 

  #ifdef UART_0

    #pragma interrupt_handler UART_RX_interrupt:iv_USART0_RX UART_TX_interrupt:iv_USART0_UDRE

  #else

    #pragma interrupt_handler UART_RX_interrupt:iv_USART1_RX UART_TX_interrupt:iv_USART1_UDRE

  #endif
    
#elif defined(__iom32v_h) || defined(__iom8v_h)

  #pragma interrupt_handler UART_RX_interrupt:iv_USART_RX UART_TX_interrupt:iv_USART_UDRE

#elif defined(__iom644v_h)

  #pragma interrupt_handler UART_RX_interrupt:iv_USART0_RX UART_TX_interrupt:iv_USART0_UDRE

#else

  #pragma interrupt_handler UART_RX_interrupt:iv_UART_RX UART_TX_interrupt:iv_UART_UDRE

#endif





/* interrupt handlers */
void UART_RX_interrupt( void )
{
	unsigned char data;
	unsigned char tmphead;

	data = UDR; /* read the received data */

	/* calculate buffer index */
	tmphead = ( UART_RxHead + 1 ) & UART_RX_BUFFER_MASK;
	UART_RxHead = tmphead; /* store new index */
	if ( tmphead == UART_RxTail )
		{
		/* ERROR! Receive buffer overflow */
		}
	UART_RxBuf[tmphead] = data; /* store received data in buffer */
}

void UART_TX_interrupt( void )
{
	unsigned char tmptail;
            
	/* check if all data is transmitted */
	if ( UART_TxHead != UART_TxTail ) {

          /* calculate buffer index */
          tmptail = ( UART_TxTail + 1 ) & UART_TX_BUFFER_MASK;
          UART_TxTail = tmptail; /* store new index */
          UDR = UART_TxBuf[tmptail]; /* start transmition */

	}
	else {

	  UCSRB &= ~(1<<UDRIE); /* disable UDRE interrupt */

          #ifdef XCP_ON_UART
            XCP_INTERUPT_CONTROL_OFF; // XCP function called with interupt disabled
            XcpSendCallBack(); 
            XCP_INTERUPT_CONTROL_ON;
          #endif 

	}
}

/* Read and write functions */
unsigned char ReceiveByte( void )
{
  unsigned char tmptail;

  while ( UART_RxHead == UART_RxTail ); /* wait for incomming data */
  tmptail = ( UART_RxTail + 1 ) & UART_RX_BUFFER_MASK;/* calculate buffer index */
  UART_RxTail = tmptail; /* store new index */
  return UART_RxBuf[tmptail]; /* return data */
}

unsigned char TransmitByte( unsigned char data )
{
  unsigned char tmphead;
	
  /* calculate buffer index */
  tmphead = ( UART_TxHead + 1 ) & UART_TX_BUFFER_MASK; 

  /* wait for free space in buffer or return */
  #ifdef UART_TRANSMIT_BLOCKING
    while ( tmphead == UART_TxTail ) ;
  #else
    if ( tmphead == UART_TxTail ) return 0;
  #endif
  	
  UART_TxBuf[tmphead] = data; /* store data in buffer */
  UART_TxHead = tmphead; /* store new index */
  UCSRB |= (1<<UDRIE); /* enable UDRE interrupt */

  return 1;
}


unsigned char DataInReceiveBuffer( void )
{
  return ( UART_RxHead != UART_RxTail ); /* return 0 (FALSE) if the receive buffer is empty */
}



#ifndef UARTINTR_SMALL 


/* Flush receive buffer */
void FlushReceiveBuffer( void ) {

  UART_RxTail = 0;
  UART_RxHead = 0;
}


/* Check if all bytes are transmited */
unsigned char DataInTransmitBuffer( void )
{
  return ( UART_TxHead != UART_TxTail ); /* return 0 (FALSE) if the transmit buffer is empty */
}


/* Transmit a formatted string */
void TransmitString( char *s ) {
               
  while (*s!=0) {
    TransmitByte(*s);
    s++;
  }
}


/* Transmit a formatted string */
void TransmitStringFormat( char *fmt, ...) {

  va_list va;

  buf_p = buf;
  va_start(va, fmt);
  _print(_depi, fmt, va);
  va_end(va);
  TransmitString(buf);  
}

#endif

