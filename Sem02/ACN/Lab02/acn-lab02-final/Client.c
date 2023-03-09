#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>
#include<dirent.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>

#define MAXIN 1024

struct header {
  char mode;
  int length;
  int client_id;
};

void tostring(char str[], int num) {
    int i, rem, len = 0, n;
 
    n = num;
    while (n != 0) {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++) {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

void ls(int sockfd, struct header head) {
  char reqbuf[MAXIN];
  int n;

  head.length = strlen(reqbuf);
  write(sockfd, (void *)&head, sizeof(head));

  memset(reqbuf,0,MAXIN);
  while (1) {
    n = recv(sockfd, reqbuf, sizeof(reqbuf), 0);
    if (reqbuf[n] == '\0' && reqbuf[n - 1] == '\0') {
      printf("%s", reqbuf);
      return;
    }
    printf("%s", reqbuf);
    memset(reqbuf, 0, sizeof((reqbuf)));
  }
}

void receiveFile(int sockfd, struct header head) {
  char reqbuf[MAXIN];
  int n;
  FILE *fp;
  char filename[110];
  memset(filename, 0, sizeof(filename));

  head.length = MAXIN;
  write(sockfd, (void *)&head, sizeof(head));

  printf("Enter file path :- ");
  scanf(" %s", filename);

  write(sockfd, filename, strlen(filename));

  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error in writing to file.");
    exit(1);
  }

  while (1) {
    memset(reqbuf, 0, MAXIN);
    n = recv(sockfd, reqbuf, MAXIN, 0);
    if (n <= 1) {
      if (reqbuf[0] == '\0') {
        break;
      }
    }
    fprintf(fp, "%s", reqbuf);
  }
  printf("file received\n");
  fclose(fp);
}

void sentFile(int sockfd, struct header head) {
  char sndbuf[MAXIN];
  int n;
  FILE *fp;
  char filename[32];
  char filename_temp[32];

  head.length = MAXIN;
  write(sockfd, (void *)&head, sizeof(head));

  printf("Enter file path :- ");
  scanf("%s", filename);
  strcpy(filename_temp, filename);
  srand(time(0));
  int t = rand()%10000;
  char arr[50];
  memset(arr, 0, strlen(arr));
  // tostring(arr,t);
  sprintf(arr, "%d", t);
  char *token = strtok(filename_temp, ".");
  strcat(filename_temp, "_");
  strcat(filename_temp, arr);
  strcat(filename_temp, ".txt");
  send(sockfd, filename_temp, sizeof(filename_temp), 0);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("[-]Error in reading file.");
    exit(1);
  }

  while (fgets(sndbuf, MAXIN, fp) != NULL) {
    if (send(sockfd, sndbuf, sizeof(sndbuf), 0) == -1) {
      printf("[-]Error in sending file.");
      exit(1);
    }
    memset(sndbuf, 0, MAXIN);
  }
  send(sockfd, "\0", sizeof(char), 0); //indicating end of file trans.
  fclose(fp);
  printf("File Sent SuccessFully!!!\n");
}

void client(int sockfd) {
  struct header head;
  srand(time(0));
  long long id;
  printf("Do you have a client id[y/n]: ");
  char ch;
  scanf("%c", &ch);
  
  if(ch == 'y') {
    printf("Enter client id: ");
    scanf(" %lld", &id);
  } else {
    id =  rand();
    printf("Joining with client id: %lld", id);
  }

  head.client_id = id;
  while (1) {
    printf("\n+ Echo Messages[1] \n+ File Upload[2] \n+ File Download[3]\n+ List Files on Server[4]\n");
    scanf(" %c", &head.mode);

    if (head.mode == '1') {
      char sndbuf[MAXIN], reqbuf[MAXIN];
      
      head.length = MAXIN;
      write(sockfd, (void *)&head, sizeof(head));
      
      printf("> ");                   /* prompt */
      memset(sndbuf, 0, sizeof(sndbuf)); /* clear for good measure */
      getchar();
      fgets(sndbuf, sizeof(sndbuf), stdin); /* read up to a EOL */
      write(sockfd, sndbuf, strlen(sndbuf));
      memset(reqbuf, 0, sizeof(reqbuf));
      read(sockfd, reqbuf, strlen(sndbuf)); /* echo*/
      printf("msg rcvd from server : %s\n", reqbuf);
    } else if (head.mode == '2') {
      sentFile(sockfd, head);
    } else if (head.mode == '3') {
      receiveFile(sockfd, head);
    } else {
      ls(sockfd, head);
    } 
  }
}

void buildServerAddr(struct sockaddr_in *serv_addr, char *serverIP, int portno) {
  /* Construct an address for remote server */
  memset((char *)serv_addr, 0, sizeof(struct sockaddr_in));
  serv_addr->sin_family = AF_INET;
  inet_aton(serverIP, &(serv_addr->sin_addr));
  serv_addr->sin_port = htons(portno);
}

int main() {
  // Client protocol
  char *serverIP = "127.0.0.1";
  int sockfd, portno = 5033, err;
  struct sockaddr_in serv_addr;

  buildServerAddr(&serv_addr, serverIP, portno);

  /* Create a TCP socket */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("[-]Error in creating socket.");
    exit(1);
  }

  /* Connect to server on port */
  err = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (err == -1) {
    printf("[-]Error in connecting.");
    exit(1);
  }
  printf("Connected to %s:%d\n", serverIP, portno);

  /* Carry out Client-Server protocol */
  client(sockfd);

  /* Clean up on termination */
  close(sockfd);
}
