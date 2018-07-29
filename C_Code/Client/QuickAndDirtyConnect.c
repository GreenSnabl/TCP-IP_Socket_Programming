#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>     // here are all the defines like AF_INET (2), AF_INET6 (10)
#include <netdb.h>
#include <arpa/inet.h>      // here resides addrinfo


int main(int argc, char** argv)
{
    // establish a socket connection
    // in this case establish a connection with our running Server.c application
   

    struct addrinfo hints, *res;
    int sockfd;
    
    memset(&hints,0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    getaddrinfo("127.0.0.1", "9999", &hints, &res);
    
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    
    connect(sockfd, res->ai_addr, res->ai_addrlen);

}