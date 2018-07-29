#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MYPORT "9999"
#define BACKLOG 10

int main(int argc, char** argv)
{
	struct sockaddr_storage their_addr;	// could be IPv4 or IPv6
	socklen_t addr_size;
	struct addrinfo hints, *res;
	int sockfd, new_fd;			// socket file descriptors

	// don't forget errorchecking for these calls!!
	
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;		// dunno if IPv4 or IPv6, yet
	hints.ai_socktype = SOCK_STREAM;	// TCP
	hints.ai_flags = AI_PASSIVE;		// fill in the IP for me
	
	getaddrinfo(NULL, MYPORT, &hints, &res); // fill linked list res with infos

	// make socket, bind it and listen to it
	
	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	bind(sockfd, res->ai_addr, res->ai_addrlen);
	listen(sockfd, BACKLOG);

	addr_size = sizeof(their_addr);
	new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
	


	// ready to communicate on socket descriptor new_fd!
	//
	// We will exclusively use socket descriptor new_fd for send() and recv()
	// if we do not want additional incoming connections, we can close sockfd
	// after accepting the first connection
	close(sockfd);
	
	char* msg = "hello!";
	int len = strlen(msg);
	int bytes_sent, bytes_recv;
	char buffer[1024];
	
	
	bytes_sent = send(new_fd, msg, len, 0);		
	while (1)
	{
		if (bytes_recv = recv(new_fd, buffer, strlen(buffer), 0) > 0) {
			printf("%s\n", buffer);
			bytes_recv = 0;
			bytes_sent = send(new_fd, msg, len, 0);		
		}
	}
	close(new_fd);
}
