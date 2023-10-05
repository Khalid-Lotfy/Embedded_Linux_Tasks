#include <asm-generic/socket.h>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#define PORT 8888




int main(int argc, char const* argv[])
{

int server_fd,client_socket;
int valread;

struct sockaddr_in address;

int opt=1;
int addrlen=sizeof(address);
char buffer [1024]={0};
const char * hello="hello from server";


if((server_fd=socket(AF_INET, SOCK_STREAM, 0))<0)
{
    perror("socket failed");
    exit(EXIT_FAILURE);

}
if(setsockopt(server_fd, SOL_SOCKET,  SO_REUSEADDR|SO_REUSEPORT, &opt,sizeof(opt))<0)
{
    perror("setsocketopt");
    exit(EXIT_FAILURE);

}

address.sin_family=AF_INET;
address.sin_addr.s_addr=INADDR_ANY;
address.sin_port=htons(PORT);

if((bind(server_fd, (struct sockaddr *)&address, sizeof(address)))<0)
{
    perror("bind failed");
    exit(EXIT_FAILURE);

}

if(listen(server_fd, 5))
{
    perror("listen");
    exit(EXIT_FAILURE);
  
}
std::cout<<"server is listennig on prot "<<PORT<<"......"<<std::endl;

if((client_socket=accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0)
{
    perror("accept failed");
    exit(EXIT_FAILURE);

}
    std::cout<<"client "<<client_socket<<"  is connected"<<std::endl;
    send(client_socket, hello, strlen(hello), 0);
   
   

   std::map<const char *, const char *> linux_commands
   { {"terminal\n","gnome-terminal"},
         { "files\n","nautilus"},
         {"browser\n","firefox" },
         {"calc\n","gnome-calculator"},
         { "vs\n","code"},
         {"brows\n","firefox" }

   };

  


 while(1)
 {
    int flag=0;
    memset(buffer, 0, sizeof(buffer));
    valread=read(client_socket, buffer, 1024);
        

     if (valread <= 0) {
        if (valread == 0) {
            std::cout << "client disconnected" << std::endl;
        } else {
            perror("read failed");
        }
        break;
    }
    std::cout<<"[client]: "<<buffer<<std::endl;
    

   
 
    for(auto i : linux_commands)
    {
       
       if(strcmp(buffer, i.first)==0)
       {
           pid_t pid=fork();
           if(pid==0)
           {
            execlp(i.second, i.second, NULL);
            exit(0);
            
           }
            flag=1;
            
       }
    }

   
    

   if(flag==0)
   {
     std::cout<<"command not found!"<<std::endl;
     strcpy(buffer, "command not fount!");
     send(client_socket, buffer, strlen("command not found! "), 0);
     fflush(stdout);

       
   }
 }

   close(client_socket);
   shutdown(server_fd, SHUT_RDWR);


}


