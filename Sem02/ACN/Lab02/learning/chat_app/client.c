/**
 * Running the code
 *      filename server_ipadd portno
 *  argv[0] filename
 *  argv[1] server_ipaddress
 *  argc[2] port number
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h> //for read/write/close
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h> //for hostent structure

void error(const char *msg) {
    perror(msg); //interprets the error number and returns the error description using stderr
    exit(1); //terminate the program
}


int main(int argc, char* argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[255];

    if(argc < 3) {
        fprintf(stderr, "Port number not provided. Program terminated.\n");
        exit(1);
    }
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) { //socket creation failed
        error("Error opening socket!");
    }

    //since we are not accepting any connection we only need one socket(sockfd)
    server = gethostbyname(argv[1]);
    if(server == NULL) {
        fprintf(stderr, "Error, no such host!");
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection failed!");
    }
    while(1) {
        bzero(buffer, 255);
        fgets(buffer, 255, stdin);
        n = write(sockfd, buffer, strlen(buffer));
        if(n < 0) {
            error("Error on writing!");
        }
        bzero(buffer, 255); //need to clear again to hold the message that the server is passing
        n = read(sockfd, buffer, 255);
        if(n < 0) {
            error("Error on reading!");
        }
        printf("Server: %s\n", buffer);
        int i = strncmp("Bye", buffer, 3); //third arg string length
        if(i == 0) {
            break;
        }
    }
    close(sockfd);
    return 0;
}