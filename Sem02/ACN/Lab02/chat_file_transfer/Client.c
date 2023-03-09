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
#include <ctype.h>

#define MAXIN 255
#define MAXOUT 255
#define SIZE 1024
 
void send_file(FILE *fp, int sockfd){
  int n;
  char data[SIZE] = {0};
 
  while(fgets(data, SIZE, fp) != NULL) {
    if (send(sockfd, data, sizeof(data), 0) == -1) {
      perror("[-]Error in sending file.");
      exit(1);
    }
    bzero(data, SIZE);
  }
}

char *getreq(char *inbuf, int len, int sockfd) {
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
    // FILE *f;
    // int words=0;
    // char c;
    // f = fopen("input.txt", "r");
    // if(f != NULL) {
    //   printf("\nOpened file successfully!");
    // }
    // while((c = getc(f))!=EOF) {
    //   fscanf(f, "%s", inbuf);
    //   if(isspace(c) || c=='\t') {
    //     words++;
    //   }
    // }
    // write(inbuf, &words, sizeof(int));
    // rewind(f);
    // char ch;
    // while(ch!=EOF) {
    //   fscanf(f, "%s", inbuf);
    //   write(sockfd, inbuf, 255);
    //   ch = fgetc(f);
    // }



    FILE *f;
    f = fopen("input.txt", "r");
    if(f != NULL) {
      printf("\nOpened file successfully!");
    }
    send_file(f, sockfd);
    printf("\nSent file successfully!");
  }

  printf("\n[1] Send text to server.\n[2] Send file(filename) to server.\n> ");
  memset(inbuf, 0, len);
  fgets(inbuf, len, stdin);

}

void client(int sockfd) {
  int n;
  char sndbuf[MAXIN]; char rcvbuf[MAXOUT];
  // memset(sndbuf, 0, MAXIN);
  memset(sndbuf, 0, MAXIN); //added
  getreq(sndbuf, MAXIN, sockfd);        /* prompt */
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
      getreq(sndbuf, MAXIN, sockfd);                 /* prompt */
    } else if (rcvbuf[0] == '2') {
      //do something for file transfer
      memset(sndbuf, 0, MAXIN);
      sndbuf[0] = '2';
      getreq(sndbuf, MAXIN, sockfd);




      // FILE *f;
      // int words=0;
      // char c;
      // f = fopen("input.txt", "r");
      // if(f != NULL) {
      //   printf("\nOpened file successfully!");
      // }
      // while((c = getc(f))!=EOF) {
      //   fscanf(f, "%s", sndbuf);
      //   if(isspace(c) || c=='\t') {
      //     words++;
      //   }
      // }
      // write(sockfd, &words, sizeof(int));
      // rewind(f);
      // char ch;
      // while(ch!=EOF) {
      //   fscanf(f, "%s", sndbuf);
      //   write(sockfd, sndbuf, 255);
      //   ch = fgetc(f);
      // }
      // send_file(f, sockfd);
      // printf("File was successfully transferred!");
    } else {
      //exception case
      memset(sndbuf, 0, MAXIN);
      getreq(sndbuf, MAXIN, sockfd);
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
