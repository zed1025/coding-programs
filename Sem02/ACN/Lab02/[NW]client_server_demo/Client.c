// Client.c
//https://idiotdeveloper.com/file-transfer-using-tcp-socket-in-c/
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
#define SIZE 1024

//FILE TRANSFER
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
  /* Get request char stream */
  printf("\nEnter 1 for text.\nEnter 2 for file transfer.\n> ");              /* prompt */
  char n[1]; //buffer
  scanf(" %c", n);
  write(sockfd, n, sizeof(n));
  if(n[0]=='1') {
    memset(inbuf,0,len);          /* clear for good measure */
    fgets(inbuf,len,stdin); /* read up to a EOL */
    return fgets(inbuf,len,stdin); /* read up to a EOL */
  } else if (n[0]=='2') {
    //code for file transfer
    FILE *fp;
    printf("Enter filename: ");
    char filename[] = "source.txt";
    // scanf(" %s",filename);
    // getchar();
    // fgets(filename, 100, stdin);
    // printf("Entered filename: %s", filename);
    printf("Hello");
    fp = fopen(filename, "r");
    if (fp == NULL) {
      perror("[-]Error in reading file.");
      exit(1);
    }
    printf("Hello");
    send_file(fp, sockfd);
    return NULL;
  } else {
    //error case. 
  }
  // memset(inbuf,0,len);          /* clear for good measure */
  // return fgets(inbuf,len,stdin); /* read up to a EOL */
}

void client(int sockfd) {
  int n;
  char sndbuf[MAXIN]; char rcvbuf[MAXOUT];
  getreq(sndbuf, MAXIN, sockfd);        /* prompt */
  
  while (strlen(sndbuf) > 0) {
    write(sockfd, sndbuf, strlen(sndbuf)); /* send */

    printf("Wrote message: %s\n",sndbuf);
    
    memset(rcvbuf,0,MAXOUT);               /* clear */
    n=read(sockfd, rcvbuf, MAXOUT-1);      /* receive */
    printf("Received reply: %d",n);
    
    write(STDOUT_FILENO, rcvbuf, n);	      /* echo */
    getreq(sndbuf, MAXIN, sockfd);                 /* prompt */
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
	
	buildServerAddr(&serv_addr, serverIP, portno);

	/* Create a TCP socket */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("[-]Error in socket");
    exit(1);
  }
  printf("[+]Server socket created successfully.\n");

	/* Connect to server on port */
	connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
	printf("Connected to %s:%d\n",serverIP, portno);

	/* Carry out Client-Server protocol */
	client(sockfd);

	/* Clean up on termination */
	close(sockfd);
}
