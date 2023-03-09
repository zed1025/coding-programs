// Server.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#define MAXREQ 20
#define MAXQUEUE 5
#define SIZE 1024

//FILE TRANSFER
void write_file(int sockfd){
  int n;
  FILE *fp;
  char *filename = "recv.txt";
  char buffer[SIZE];
 
  fp = fopen(filename, "w");
  while (1) {
    n = recv(sockfd, buffer, SIZE, 0);
    if (n <= 0){
      break;
      fclose(fp);
      return;
    }
    fprintf(fp, "%s", buffer);
    bzero(buffer, SIZE);
  }
  return;
}

void server(int consockfd) {
  char reqbuf[MAXREQ];
  int n; //no of bytes read
  while (1) {                   
    memset(reqbuf,0, MAXREQ);
    n = read(consockfd,reqbuf,MAXREQ-1); /* Recv */
    printf("Recvd msg:%s\n", reqbuf);
    if (n <= 0) return;
    if(reqbuf[0] == '2') { //file transfer code
      printf("File transfer started\n");
      write_file(consockfd);
    } else if(reqbuf[0] == '1') {
      //code for messaging
      n = write(consockfd, reqbuf, strlen(reqbuf)); /* echo*/
    } else {
      //error
    }
  }
}

int main() {

int lstnsockfd, consockfd, clilen, portno = 5033;
struct sockaddr_in serv_addr, cli_addr;

 memset((char *) &serv_addr,0, sizeof(serv_addr));
 serv_addr.sin_family      = AF_INET;
 serv_addr.sin_addr.s_addr = INADDR_ANY;
 serv_addr.sin_port        = htons(portno);

// Server protocol
/* Create Socket to receive requests*/
lstnsockfd = socket(AF_INET, SOCK_STREAM, 0);

/* Bind socket to port */
bind(lstnsockfd, (struct sockaddr *)&serv_addr,sizeof(serv_addr));
printf("Bounded to port\n");
while (1) {
   printf("Listening for incoming connections\n");

/* Listen for incoming connections */
   listen(lstnsockfd, MAXQUEUE); 

   //clilen = sizeof(cl_addr);

/* Accept incoming connection, obtaining a new socket for it */
   consockfd = accept(lstnsockfd, (struct sockaddr *) &cli_addr,       
                      &clilen);
   printf("Accepted connection\n");
   int pid;
   if(fork() == 0 ) { //child
     server(consockfd);
     close(consockfd);
   } else { //parent
     printf("New process to service the request created!\n");
   }
  }
close(lstnsockfd);
}
