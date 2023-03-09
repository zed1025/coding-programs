// Server.c
/**
 *    sudo netstat -tulpn | grep LISTEN
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#define MAXREQ 255
#define MAXQUEUE 255
#define SIZE 1024

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
      return;
    }
    fprintf(fp, "%s", buffer);
    bzero(buffer, SIZE);
  }
  return;
}

void server(int consockfd) {
  char reqbuf[MAXREQ];
  int n;
  while (1) {                   
    memset(reqbuf,0, MAXREQ);
    n = read(consockfd,reqbuf,MAXREQ-1); /* Recv */
    printf("Recvd msg:%s", reqbuf);
    if (n <= 0) return;
    //handle cases where the client is sending message or text file
    if(reqbuf[0] == '1') {
      memset(reqbuf,0, MAXREQ);
      strcpy(reqbuf, "1ST"); //send text
      n = write(consockfd, reqbuf, strlen(reqbuf)); /* echo*/
    } else if(reqbuf[0] == '2') {
      //handle file transfer case
      memset(reqbuf,0, MAXREQ);
      strcpy(reqbuf, "2FT"); //send file
      n = write(consockfd, reqbuf, strlen(reqbuf)); /* echo*/

      // FILE *fp;
      // int ch=0;
      // fp = fopen("output.txt", "a");
      // int words;
      // n = read(consockfd, &words, sizeof(int));
      // if(n < 0) {
      //   printf("\nError!");
      // }
      // while(ch != words) {
      //   read(consockfd, reqbuf, 255);
      //   fprintf(fp, "%s ", reqbuf);
      //   ch++;
      // }
      // write_file(consockfd);
      // printf("File received successfully!");


      write_file(consockfd);
    } else {
      //handle file transferred from client -> NOT CONFIRMED
      // n = write(consockfd, reqbuf, strlen(reqbuf)); /* echo*/

      // FILE *fp;
      // int ch=0;
      // fp = fopen("output.txt", "a");
      // int words;
      // n = read(consockfd, &words, sizeof(int));
      // if(n < 0) {
      //   printf("\nError!");
      // }
      // while(ch != words) {
      //   read(consockfd, reqbuf, 255);
      //   fprintf(fp, "%s ", reqbuf);
      //   ch++;
      // }
      
      printf("File received successfully!");
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

    /* Accept incoming connection, obtaining a new socket for it */
    consockfd = accept(lstnsockfd, (struct sockaddr *) &cli_addr, &clilen);
    printf("Accepted connection\n");

    if(fork() == 0) {
      //child
      server(consockfd); //custom function
      close(consockfd);
    } 
  }
  close(lstnsockfd);
}
