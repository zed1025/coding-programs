// Client.c
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define MAXIN 20
#define MAXOUT 20

char *getreq(char *inbuf, int len) {
  // printf("\nREQ: ");              /* prompt */
  // memset(inbuf,0,len);          /* clear for good measure */
  // return fgets(inbuf,len,stdin); /* read up to a EOL */

  if(inbuf[0] == '1') { //handle text
    printf("\nEnter Message: ");
    memset(inbuf, 0, len);
    fgets(inbuf, len, stdin);
    printf("Entered Message is: %s", inbuf);
    // getchar();
    return NULL;
  } else if(inbuf[0] == '2') {
    //handle file transfer
  }

  printf("\n[1] Send text to server.\n[2] Send file to server.\n> ");
  // char response[1];
  // scanf(" %c", response);
  memset(inbuf, 0, len);
  // getchar();
  fgets(inbuf, len, stdin);
  // if(response[0] == '1') {
  //   memset(inbuf, 0, len);
  //   getchar();
  //   fgets(inbuf, len, stdin);
  // } else if (response[0] == '2') {
  //   //sending file
  // } else {
  //   //handle exceptions
  // }
}

void client(int sockfd) {
  int n;
  char sndbuf[MAXIN]; char rcvbuf[MAXOUT];
  // memset(sndbuf, 0, MAXIN);
  memset(sndbuf, 0, MAXIN); //added
  getreq(sndbuf, MAXIN);        /* prompt */
  while (strlen(sndbuf) > 0) {
    // printf("\nWritten Message: %s\n", sndbuf);
    write(sockfd, sndbuf, strlen(sndbuf)); /* send */

    printf("Wrote message: %s",sndbuf);
    
    memset(rcvbuf,0,MAXOUT);               /* clear */
    n=read(sockfd, rcvbuf, MAXOUT-1);      /* receive */
    printf("Received reply: [%d] -> %s",n, rcvbuf);

    //if received  reply from server is 1 allow him to send text next
    if(rcvbuf[0] == '1') {
      // write(STDOUT_FILENO, rcvbuf, n);	      /* echo */
      memset(sndbuf, 0, MAXIN);
      sndbuf[0] = '1';
      getreq(sndbuf, MAXIN);                 /* prompt */
    } else if (rcvbuf[0] == '2') {
      //do something for file transfer
      //need file name
      char* filename;
      printf("Enter Filename/Path: ");
      scanf("%s", filename);
      printf("Entered filename: %s", filename);
      //have the filename -> do someting with it
      
    } else {
      //exception case
      memset(sndbuf, 0, MAXIN);
      getreq(sndbuf, MAXIN);
    }
    
    // write(STDOUT_FILENO, rcvbuf, n);	      /* echo */
    // // memset(sndbuf, 0, MAXIN);
    // getreq(sndbuf, MAXIN);                 /* prompt */
  }
}

// Server address
//struct hostent *buildServerAddr(struct sockaddr_in *serv_addr,
void buildServerAddr(struct sockaddr_in *serv_addr, char *serverIP, int portno) {
  /* Construct an address for remote server */
  memset((char *) serv_addr, 0, sizeof(struct sockaddr_in));
  serv_addr->sin_family = AF_INET;
  inet_aton(serverIP, &(serv_addr->sin_addr));
  serv_addr->sin_port = htons(portno);
 }


int main() {
	//Client protocol
	char *serverIP = "127.0.0.1";
	int sockfd, portno = 5033;
	struct sockaddr_in serv_addr;
	
	buildServerAddr(&serv_addr, serverIP, portno); //custom method

	/* Create a TCP socket */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	/* Connect to server on port */
	connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
	printf("Connected to %s:%d\n",serverIP, portno);

	/* Carry out Client-Server protocol */
	client(sockfd); //custom method

	/* Clean up on termination */
	close(sockfd);
}
