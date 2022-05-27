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


int main(int argc, char **argv)
{
    int sockfd, n = 0;
    char recvline[1000 + 1];
    struct sockaddr_in servaddr;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket Error");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);


    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
		perror("Connect Error");
    }

	if ((n = read(sockfd, recvline, 1000)) > 0) {
	    recvline[n] = 0;
	    fputs(recvline, stdout);
	}

	return 0;
}
