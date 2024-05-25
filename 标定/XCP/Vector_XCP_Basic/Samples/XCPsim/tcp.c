/*----------------------------------------------------------------------------
| File:
|   TCP.C
|
| Project:
|   Ethernet Transport Layer for XCPsim
|
 ----------------------------------------------------------------------------*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <io.h>
#include <conio.h>
#include <dos.h>
#include <winsock2.h>


#include "xcpsim.h"
#include "xcpbasic.h"


/***************************************************************************/

extern int mainRunning;

/***************************************************************************/


#define DEFAULT_PORT  5555
#define DEFAULT_PROTO SOCK_STREAM // TCP-SOCK_STREAM, UDP-SOCK_DGRAM

unsigned short gPort = DEFAULT_PORT;
int gProto = DEFAULT_PROTO;

unsigned int gOverunCount = 0;
SOCKET gListenSocket = INVALID_SOCKET; 
SOCKET gDataSocket = INVALID_SOCKET;
int gRemoteAddrLen = 0;
struct sockaddr_in gRemoteAddr;


/* TX */
unsigned char gSendBuffer[2048];
int gSendBufferLen = 0;
unsigned char *gSendMessage = gSendBuffer;
WORD gLastCmdCtr = 0;
WORD gLastDaqCtr = 0;


/***************************************************************************/

#define MAX_TCPMSG_DATA 4096

typedef struct tcppacket {

  unsigned short dlc;                    /* BYTE 1,2 */   
  unsigned short ctr;                    /* BYTE 3,4 */   
  unsigned char  data[MAX_TCPMSG_DATA];  // BYTE[] 

} TCPPACKET;


typedef struct {

  int byte_pos;
  int bytes_to_read;
  TCPPACKET p;

} TCPMSG;



/***************************************************************************/
// Time


static int sPerformanceCounter = 0;
static __int64 sFactor = 1;
static __int64 sOffset = 0;


void tmTimerInit(void);

// Timer 100us 
unsigned __int64 tmTimer (void) {

  LARGE_INTEGER t;
  __int64 td;

  if (sPerformanceCounter==0) {
    tmTimerInit();
  }
  if (sPerformanceCounter<=0) {
    return 0;
  }

  QueryPerformanceCounter(&t);
  td = (((__int64)t.u.HighPart)<<32) | (__int64)t.u.LowPart;
  return (unsigned __int64)(((td-sOffset)*10000)/sFactor);
}

// Init and Reset tmTimer()
void tmTimerInit(void) {

  LARGE_INTEGER tF, tC;

  if (QueryPerformanceFrequency(&tF)) {

    if (tF.u.HighPart) {
      printf("Error: Unexpected Performance Counter Frequency");
      sPerformanceCounter = -1;
    }
    
    sFactor = tF.u.LowPart; // Ticks pro s
    
    QueryPerformanceCounter(&tC);
    sOffset = (((__int64)tC.u.HighPart)<<32) | (__int64)tC.u.LowPart;

    sPerformanceCounter = 1;
  }
  else {
    printf("Error: Performance Counter not available");
    sPerformanceCounter = -1;
  }
  
}


/***************************************************************************/


static void tcpmsg_clear(TCPMSG *tm)
{
  tm->byte_pos = 0;
  tm->bytes_to_read = 4;
  tm->p.dlc = 0;
  tm->p.ctr = 0;
  memset(tm->p.data, 0, MAX_TCPMSG_DATA);
}


static int tcpmsg_add_byte(TCPMSG *tm, unsigned char b)
{
  switch (tm->byte_pos) {
    case 0:
      tm->p.dlc = b;
      tm->bytes_to_read += b;
      break;
    case 1:
      tm->p.dlc += (b<<8);
      tm->bytes_to_read += (b<<8);
      break;
    case 2: 
      tm->p.ctr = b;
      break;
    case 3: 
      tm->p.ctr += (b<<8);
      break;
    default:
      tm->p.data[tm->byte_pos-4] = b;
  }

  tm->byte_pos++;
  if (tm->byte_pos >= tm->bytes_to_read) return 1;
  return 0;
}

/* Flush the send buffer */
int tcpSendFlush( void ) {

  int r;

  if (gSendBufferLen==0) return (0);

  if (gProto==SOCK_STREAM) {

    // TCP Paket senden
    while (gSendBufferLen > 0) {
      int r;

      #ifdef XCP_TESTMODE
        if (gDebugLevel>=3) {
          int i;
          printf("send: ");
          for (i=0;i<gSendBufferLen;i++) printf(" %02X",gSendBuffer[i]);
          printf("\n");
        }
      #endif

      r = send(gDataSocket,gSendBuffer,gSendBufferLen,0);
      if (r == SOCKET_ERROR) { 
        int err = WSAGetLastError(); 
         if (err == WSAEWOULDBLOCK) {
            Sleep(1);
            continue;
          }
         if ((gOverunCount%256) == 0) {
          printf("Error: send overun (r=%d,c=%u), WSAGetLastError()=%d\n",r,gOverunCount,err);
         }
        gOverunCount++;
        if(gOverunCount > 20) return(1);//@@@@ Muss später eine Fehlerroutine rein
      }
      else {
       gSendBufferLen -= r;
      }
    
    }

  } else {

    #ifdef XCP_TESTMODE
      if (gDebugLevel>=3) {
        int i;
        printf("sendto: ");
        for (i=0;i<gSendBufferLen;i++) printf(" %02X",gSendBuffer[i]);
        printf("\n");
      }
    #endif

    {

      // UDP Paket senden
      for (;;) {
        // @@@@ Respond to same port
        // gRemoteAddr.sin_port = htons(9001);
        r = sendto(gDataSocket,gSendBuffer,gSendBufferLen,0,(struct sockaddr *)&gRemoteAddr,gRemoteAddrLen);
        if (r<0) {
          int err = WSAGetLastError(); 
          if (err==WSAEWOULDBLOCK) {
            Sleep(1);
            continue;
          }
          printf("Error: sendto failed (result=%d,error=%d)\n",r,err);
        }
        break;
      }
    }
  }

  gSendBufferLen = 0;
  gSendMessage = gSendBuffer;

 return (0);
}


/* Send an XCP message */
void tcpSend( BYTE len, const BYTEPTR msg ) {

  TCPPACKET *p;

  if (gDataSocket==INVALID_SOCKET) return;

  /* Write this XCP message into the send buffer */ 

  p = (TCPPACKET*)gSendMessage;
  p->dlc = len;
  p->ctr = msg[0]>=0xFC ? gLastCmdCtr : gLastDaqCtr++;
  memcpy(p->data, msg, len );	 
  gSendMessage += (len+4);
  gSendBufferLen += (len+4);
  
  /* Flush the send buffer if full */
  if (gSendBufferLen>1200) {
    ApplXcpSendFlush();
  }

}


/***************************************************************************/

void tcpMain( void )
{
  HANDLE notification_event_listen = 0;
  HANDLE notification_event_data = 0;
  TCPMSG tcpmsg;
  int r;
  unsigned short ver = MAKEWORD(2, 0);
  struct sockaddr_in addr_local;
  static WSADATA wsa_data;


  // Init TCP/IP
  r = WSAStartup(ver, &wsa_data);
  if (r != 0) {
    printf("Error: No network access! Error %d\n",WSAGetLastError());
    goto error;
  }

  // Create a socket
  gListenSocket = socket(AF_INET, gProto, 0);
  if (gListenSocket < 0) {
    printf("Error: Can not create socket! Error %d\n",WSAGetLastError());
    goto error;
  }

  // Bind to a local address
  addr_local.sin_family = AF_INET;
  addr_local.sin_addr.s_addr = INADDR_ANY;
  // local.sin_addr.s_addr = inet_addr("x.x.x.x"); 
  addr_local.sin_port = htons(gPort);
  if (bind(gListenSocket, (struct sockaddr*)&addr_local, sizeof(addr_local)) < 0) {
    printf("Error: Can not bind TCP socket! Error %d\n",WSAGetLastError());
    goto error;
  }

  // TCP
  if (gProto!=SOCK_DGRAM) {

    if ((listen(gListenSocket, 5)) < 0) {
      printf("Error: Can not listen on TCP socket! Error %d\n",WSAGetLastError());
      goto error;
    }

    // Set an event and enable Nonblocking Mode
    notification_event_listen = CreateEvent(NULL, FALSE, FALSE, NULL);
    WSAEventSelect(gListenSocket, notification_event_listen, FD_CONNECT | FD_ACCEPT);
  
  }


  // UDP
  else {

    gDataSocket = gListenSocket;
    gListenSocket = INVALID_SOCKET;

    // Set an event and enable Nonblocking Mode
    notification_event_data = CreateEvent(NULL, FALSE, FALSE, NULL);
    WSAEventSelect(gDataSocket, notification_event_data, FD_READ);

  }

  // Main Loop
  printf("\nListening on %s port %d ....\n", gProto==SOCK_DGRAM?"UDP":"TCP", gPort );
  tcpmsg_clear(&tcpmsg);
  mainRunning = 1;
  while (mainRunning) {

    int r, event_count = 0, evnum_keyb = -1, evnum_listen = -1, evnum_data = -1;
    unsigned long n;
    HANDLE event_array[5];
    
    event_array[event_count] = GetStdHandle(STD_INPUT_HANDLE);
    evnum_keyb = event_count++;

    if (notification_event_listen) {
      event_array[event_count] = notification_event_listen;
      evnum_listen = event_count++;
    }

    if (notification_event_data && (gDataSocket != INVALID_SOCKET)) {
      event_array[event_count] = notification_event_data;
      evnum_data = event_count++;
    }

    // Wait for events
    while ((r = WaitForMultipleObjects(event_count, event_array, FALSE, 1000)) == WAIT_TIMEOUT) {
      #ifdef XCP_TESTMODE
        if (gDebugLevel>=3) printf(".");
      #endif
    }
      
    // Keyboard event 
    if (r == evnum_keyb) {
      INPUT_RECORD ir;
      ReadConsoleInput(event_array[evnum_keyb], &ir, 1, &n);
      if ((n == 1) && (ir.EventType == KEY_EVENT)) {
        if (ir.Event.KeyEvent.bKeyDown) {
          mainRunning = !handleKey(ir.Event.KeyEvent.uChar.AsciiChar);
        }
      }
    } // Keyboard

    // TCP listen socket event
    if (notification_event_listen && (r == evnum_listen)) {
      struct sockaddr_in addr_remote, addr_local;
      int n;

      printf("Connect...\n");

      if (gDataSocket == INVALID_SOCKET) {

        n = sizeof(addr_remote);
        gDataSocket = accept(gListenSocket, (struct sockaddr*) &addr_remote, &n);

        n = sizeof(addr_local);
        if (getsockname(gDataSocket, (struct sockaddr *) &addr_local, &n)==SOCKET_ERROR) {
          printf("Error: Can't get socket address (%d)!\n", WSAGetLastError());
          closesocket(gDataSocket);
          gDataSocket = INVALID_SOCKET;
        }

        notification_event_data = CreateEvent(NULL, FALSE, FALSE, NULL);
        if(WSAEventSelect(gDataSocket, notification_event_data, FD_READ | FD_CLOSE)) {
          printf("Error: Network events and the associated event object was not successful!\n");
        
        }

        printf("Socket [%u] connected to %s port %u from ",gDataSocket,inet_ntoa(addr_remote.sin_addr),ntohs(addr_remote.sin_port));
        printf("%s port %u.\n",inet_ntoa(addr_local.sin_addr),ntohs(addr_local.sin_port));
      }
      else {
        printf("Error: Connect rejected, another client is already connected to this server!\n");
      }
    }

    // TCP/UDP data received event
    if (notification_event_data && (r == evnum_data)) {
      
      unsigned char buffer[2048];
      int n;

      if (gProto==SOCK_DGRAM) {

        gRemoteAddrLen = sizeof(gRemoteAddr);
        n = recvfrom(gDataSocket,buffer,2048,0,(struct sockaddr *)&gRemoteAddr,&gRemoteAddrLen);

        #ifdef XCP_TESTMODE
        if (gDebugLevel>=3) {
          int j;
          printf("recvfrom: result=%d, from=%s",n,inet_ntoa(gRemoteAddr.sin_addr));
          for (j=0;j<n;j++) printf(" %02X",buffer[j]);
          printf("\n");
        }
        #endif


      } else {

        n = recv(gDataSocket, buffer, 2048, 0);


      }

      if (n > 0) {
        int i;
        for (i = 0; i < n; ++i) {
          int r;
          r = tcpmsg_add_byte(&tcpmsg, buffer[i]);
          if (r < 0) {
            printf("Error: Invalid data received!\n");
            tcpmsg_clear(&tcpmsg);
            goto error;
          }
          else if (r == 1) {

            
              gLastCmdCtr = tcpmsg.p.ctr;
              XcpCommand((MEMORY_CONST vuint32*)tcpmsg.p.data);
              tcpmsg_clear(&tcpmsg);
          }
        }
      }

      // Error handling, n<=0
      else {
        
        int err = WSAGetLastError(); 
	
        // UDP	
        if (gProto==SOCK_DGRAM) {
        
          printf("Error: recvfrom()=%d, WSAGetLastError()=%d\n",n,err);
        
        }

        // TCP
        else {

 	  if (n==0) {
            printf("Client has closed connection\n");
          } 
          else if (err==WSAEWOULDBLOCK) { // @@@@ Warum kann dies auftreten
	          // Ignorieren
            continue;
	        }
	        else {
            printf("Error: recv()= %d, WSAGetLastError()=%d\n",n,err);
	        }
          if (notification_event_data) {
            CloseHandle(notification_event_data);
            notification_event_data = 0;
	        }
	        closesocket(gDataSocket);
          gDataSocket = INVALID_SOCKET;
          printf("Data socket closed\n");
        }
      }

    }

  } // while(!ende)

  
error:  

  if (notification_event_data) CloseHandle(notification_event_data);
  if (notification_event_listen) CloseHandle(notification_event_data);
  if (gListenSocket != INVALID_SOCKET) closesocket(gListenSocket);
  if (gDataSocket != INVALID_SOCKET) closesocket(gDataSocket);
  WSACleanup();
  return;

} 



