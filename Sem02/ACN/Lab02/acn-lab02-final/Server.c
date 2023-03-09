#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#define MAXREQ 1024
#define MAXQUEUE 5

struct header {
  char mode;
  int length;
  int client_id;
};

void checkClient(int consockfd, char *fulldir, int flag, struct header head) {
  char direc[100];
  struct stat st = {0};

  sprintf(direc, "%d", head.client_id);
  strcpy(fulldir, "./");
  strcat(fulldir, direc);

  if (stat(fulldir, &st) == -1) {
    mkdir(fulldir, 0700);
  }

  if (flag == 1) {
    char filename[100];
    memset(filename, 0, sizeof(filename));
    recv(consockfd, filename, 100, 0);
    strcat(fulldir, "/");
    strcat(fulldir, filename);
  }
}

void ls(int consockfd, struct header head) {
  DIR *d;
  struct dirent *dir;
  char fulldir[100];

  checkClient(consockfd, fulldir, 0, head);

  d = opendir(fulldir);

  if (d) {
    while ((dir = readdir(d)) != NULL) {
      send(consockfd, dir->d_name, strlen(dir->d_name), 0);
      send(consockfd, "\t", sizeof(char), 0);
    }
    closedir(d);
    send(consockfd, "\0", sizeof(char), 0);
  } else {
    printf("[-]Error opening directory");
  }
}

void sentFile(int consockfd, struct header head) {
  char sndbuf[MAXREQ];
  int n;
  FILE *fp;
  char fpath[60];

  checkClient(consockfd, fpath, 1, head);

  fp = fopen(fpath, "r");
  if (fp == NULL) {
    exit(1);
  }

  while (fgets(sndbuf, MAXREQ, fp) != NULL) {
    if (send(consockfd, sndbuf, sizeof(sndbuf), 0) == -1) {
      return;
    }
    memset(sndbuf, 0, MAXREQ);
  }
  send(consockfd, "\0", sizeof(char), 0);

  fclose(fp);
  printf("File Sent SuccessFully!!!\n");
}

void receiveFile(int consockfd, struct header head) {
  char reqbuf[MAXREQ];
  int n;
  FILE *fp;
  char fpath[120];

  checkClient(consockfd, fpath, 1, head);
  fp = fopen(fpath, "w");
  if (fp == NULL) {
    return;
  }

  while (1) {
    memset(reqbuf, 0,MAXREQ);
    n = recv(consockfd, reqbuf, MAXREQ, 0);
    if (n <= 1) {
      if (reqbuf[0] == '\0') {
        break;
      }
    }
    fprintf(fp, "%s", reqbuf);
  }
  printf("Client %d : File Received\n", head.client_id);
  fclose(fp);
}

void server(int consockfd) {
  struct header head;

  while (1) {
    read(consockfd, &head, sizeof(head));
    printf("[%d]: \n", head.client_id);

    if (head.mode == '1') {
      char reqbuf[MAXREQ];
      memset(reqbuf, 0, MAXREQ);
      recv(consockfd, reqbuf, head.length, 0);
      printf("[%d](received): %s\n", head.client_id, reqbuf);
      write(consockfd, reqbuf, strlen(reqbuf)); /* echo*/
    } else if (head.mode == '2') {
      receiveFile(consockfd, head);
    } else if (head.mode == '3') {
      sentFile(consockfd, head);
    } else {
      ls(consockfd, head);
    } 
    memset(&head, 0, sizeof(head));
  }
}

int main() {
  // int lower = 1025, upper = 65535;
  // srand(time(0));
  // int portno = (rand() % (upper - lower + 1)) + lower;
  int lstnsockfd, consockfd, err, portno=5033;
  struct sockaddr_in serv_addr, cli_addr;
  socklen_t clilen;

  memset((char *)&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  lstnsockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (lstnsockfd == -1) {
    printf("[-]Error in creating socket.");
    exit(1);
  }

  err = bind(lstnsockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (err == -1) {
    printf("[-]Error in binding to the port.");
    exit(1);
  }

  printf("Bounded to port\n");
  while (1) {
    printf("Listening for incoming connections\n");

    err = listen(lstnsockfd, MAXQUEUE);
    if (err == -1) {
      printf("[-]Error in listning.");
      exit(1);
    }

    consockfd = accept(lstnsockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (consockfd == -1) {
      printf("[-]Error in accepting connection.");
      exit(1);
    }
    printf("Accepted connection\n");

    if (fork() == 0) {
      close(lstnsockfd);
      server(consockfd);
      close(consockfd);
    } 
    close(consockfd);
  }
  close(lstnsockfd);
}
