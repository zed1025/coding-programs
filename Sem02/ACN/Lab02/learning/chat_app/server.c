#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void error(const char *msg) {
    perror(msg); //interprets the error number and returns the error description using stderr
    exit(1); //terminate the program
}

int main(int argc, char* argv[]) {
    //check if user doesnt provide port number
    if(argc < 2) {
        fprintf(stderr, "Port number not provided. Program terminated.\n");
        exit(1);
    }
    int sockfd, newsockfd, portno, n;
    char buffer[255];
    struct sockaddr_in serv_addr, cli_addr; //https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html
    socklen_t clilen; //32bit data type
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) { //socket creation failed
        error("Error opening socket!");
    }

    bzero((char*) &serv_addr, sizeof(serv_addr)); //clears data in the space pointed by the parameter
    portno = atoi(argv[1]);
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Binding failed!");
    }

    //server will now listen
    listen(sockfd, 5); //5 is max no of clients that can connect to the client
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if(newsockfd < 0) {
        error("Error on accept!");
    }

    //code for communication between client and server
    while(1) {
        bzero(buffer, 255);
        n = read(newsockfd, buffer, sizeof(buffer));
        if (n < 0) {
            error("Error on reading!");
        }
        printf("Client: %s\n", buffer);
        bzero(buffer, 255);
        fgets(buffer, 255, stdin); //take reply from server

        n = write(newsockfd, buffer, strlen(buffer));
        if(n < 0) {
            error("Error on writing!");
        }

        int i = strncmp("Bye", buffer, 3); //third arg string length
        if(i == 0) {
            break;
        }
    }
    close(newsockfd);
    close(sockfd);
    return 0;
}

