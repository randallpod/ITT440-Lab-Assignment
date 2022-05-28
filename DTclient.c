
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>




 int main(int argc, char *argv[])
{
int socTime,new_socket,c;
struct sockaddr_in server;
char response[30];


//create socket
socTime=socket(AF_INET, SOCK_STREAM, 0);
if(socTime==-1)
{
printf("Failed to create!");
}


server.sin_family=AF_INET;
server.sin_port=htons(13);//use port 13
server.sin_addr.s_addr=inet_addr("192.168.56.104");//Server IP address

//connect to remote server
if(connect(socTime,(struct sockaddr *)&server, sizeof(server))<0)
{
puts("CONNECTION ERROR");
return 1;
}
puts("CONNECTED SUCCESSFULLY! \n");

 //receive time from server
  recv(socTime, response, 29, 0);
  printf("Time received from server= %s", response);

  //close socket
  close(socTime);

return 0;
}
