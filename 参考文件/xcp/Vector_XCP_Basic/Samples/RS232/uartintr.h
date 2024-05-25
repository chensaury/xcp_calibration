/* uartintr.h */ 

#define __UARTINTR_H__
#ifdef __UARTINTR_H__

void InitUART( unsigned long baudrate );
unsigned char ReceiveByte( void );
unsigned char TransmitByte( unsigned char data );
unsigned char DataInReceiveBuffer( void );

#ifndef UARTINTR_SMALL 
  
  void FlushReceiveBuffer( void );
  unsigned char DataInTransmitBuffer( void );
  void TransmitString( char *fmt );
  void TransmitStringFormat( char *fmt, ...);

#endif

#endif



