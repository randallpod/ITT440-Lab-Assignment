#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

#define PORT 2000
#define LISTENQ 8  // number of incoming connections listened

int main(int argc, char **argv) {

   // socket servidor
   struct sockaddr_in servaddr;

   /*
   *  End-point descriptor:
   *
   *  - domain: IPv4 Internet Protocols
   *  - type: two-way connection-based byte stream. Garantee order
   *  - protocol: protocol that support that type of socket
   *
   */
   int sockfd = socket(AF_INET, SOCK_STREAM, 0);
   int connfd;
   char buff[1000];
   time_t ticks;

   if(sockfd == -1) {
       perror("socket");
       exit(1);
   }else {
      printf("socket created successfully\n");
   }

   bzero(&servaddr, sizeof(servaddr));           // set buffer to zero to make sure ther is no gar
   servaddr.sin_family    = AF_INET;             // same as the socket
   servaddr.sin_port       = htons(PORT);        // convert from host byte order to network byte order
   servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // use this when you don't need to bind a specific IP. Socket will accept connections to all the IPs of the machine

   // assign the address to the socket specified by the file descriptor
   if(bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
       perror("bind");
       exit(1);
    }

    listen(sockfd, LISTENQ); // sockfd is a passive socket, accept income connections request using accept()

    for( ; ; ) {
       if((connfd = accept(sockfd, (struct sockaddr *) NULL, NULL)) == -1) {
         perror("accept");
          exit(1);
      }

        ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		write(connfd, buff, strlen(buff));
		close(connfd);

    }

   return 0;
}
