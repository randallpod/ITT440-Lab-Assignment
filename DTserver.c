#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>

int main(int argc, char *argv[] )
{
  int socTime,new_socket,c, n_client = 0;
  struct sockaddr_in server, client;



  //create socket
    socTime = socket(AF_INET,SOCK_STREAM,0);
    if(socTime==-1)
      {

        printf("\nFailed to create socket!");

      }

  //create socket address
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(13); //use port 13

  //binding
    if(bind(socTime,(struct sockaddr *)&server, sizeof(server))<0)
      {

       puts("\nbind failed");
       return 1;
      }
     puts("\nSocket is  binded! ");


  //listen
    listen (socTime,3);

  //to accept incoming connection
    puts("\nPlease wait for  connections....");
    c=sizeof(struct sockaddr_in);


  //server client connection
    new_socket=accept(socTime,(struct sockaddr *)&client,(socklen_t*)&c);
    if(new_socket<0)
      {
       perror("\nCONNECTION FAILED!");
       return 1;
      }
    puts("CONNECTION ACCEPTED!");

    //Getting current time
    time_t currentTime;
    time(&currentTime);

    //Send time to client
    printf("Sending Client current time = %s ", ctime(&currentTime));
    send(new_socket, ctime(&currentTime), 30, 0);
 // }

  //Close socket
    close(new_socket);

return 0;
}


