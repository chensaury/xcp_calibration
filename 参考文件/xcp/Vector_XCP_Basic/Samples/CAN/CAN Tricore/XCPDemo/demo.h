

/*****************************************************************************
| Project Name:   XCP on CAN demo for Infineon Tricore TC17x7
|    File Name:   
|
|  Description:   Application main include file
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


// Macros
#ifdef VX1000_ENABLED
  #define DELAY(us) { unsigned int timeout= VX1000_CLOCK+((VX1000_UINT32)us*(VX1000_CLOCK_TICKS_PER_MS/1000));  while ((int)(VX1000_CLOCK-timeout)<0); }
#else
  #define DELAY(us)
#endif

	   
// Prototypes
extern void mainloop( void );
extern void led_on( unsigned char b );
extern void led_off( unsigned char b );
