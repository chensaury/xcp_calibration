

extern unsigned char MMUWriteTLBEntry( 
  unsigned char n, 
  unsigned int ea, 
  unsigned int ra,
  unsigned int pagesize, 
  unsigned char cache_inhibit, 
  unsigned char cache_writethrough, 
  unsigned char permissions);  


