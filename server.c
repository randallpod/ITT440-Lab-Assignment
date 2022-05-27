#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

#define BACKLOG 10
#define PORT 13

int main(int argc, char **argv){
  if(argc != 2){
    printf("Usage: %s <port>\n", argv[0]);
    exit(0);
  }

  char buffer[1024]={0};

  int port = atoi(argv[1]);
  printf("Port: %d\n", port);

  int n_client = 0;
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in serverAddress,client;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(13);

  bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
  printf("[+]Bind\n");

  listen(sockfd, 10);
  printf("[+]Listening for the client\n");


 int i = 1;

    valread = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
// while(i){
// int client_socket = accept(sockfd, NULL, NULL);
// n_client++;
// time_t currentTime;
// time(&currentTime);
// printf("Client %d requested for time at %s",n_client, ctime(&currentTime));
// send(client_socket, ctime(&currentTime), 30, 0);

}

return 0;

}


