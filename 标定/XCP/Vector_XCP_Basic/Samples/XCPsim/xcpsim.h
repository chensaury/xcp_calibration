// XCPSIM.H


extern int hwType;
extern int hwChannel; 
extern int hwIndex;
extern unsigned int gBitRate;
extern DWORD gDtoId;
extern DWORD gCroId;
extern void canGetDefaults( void );
extern void canMain( void );
extern int  canSend( unsigned char len, const unsigned char *msg );



extern int gProto;
unsigned short gPort;
extern void tcpMain( void );
extern void tcpSend( unsigned char len, const unsigned char *msg );
extern int  tcpSendFlush( void );



extern int handleKey( int key );

extern int mainRunning;


