
# Pc_controller_project
Control PC from ( Tcp Udp server & client) mobile application and socket programming c++ program on the PC.
The c++ program is the server and mobile application is the client. The idea is sending commands from the client (application),the c++ program receives it and decides what linux command to execute depending on the command it received or its a wrong command. 
Server uses for() and execp() mechanism to execute the linux commands providing more efficiet and faster way than system().  

### Steps 

1-download (Tcp Udp server & client) application
![Logo](https://play-lh.googleusercontent.com/zxwe4CELzZvw-SDKTda2UmUKN-S0HMnj8ny1D_zym4b7Vo1E8p8aUZq3YhWqBMTOfoY=w240-h480)

2-create new client and type your device IP address and your port number used in the program and choose TCP
![logo](https://play-lh.googleusercontent.com/jA4fYZUulKkI7D4mK53cQ1VeLDN2Mqv4RgNfYiHZgLK6AZXsnU7IkdhfJ6x3HtAH_Q=w2560-h1440)
![logo](https://play-lh.googleusercontent.com/LzfQgUnRHurjl2pJfcODLgy1jm05DBVDCCFXHo8wxyEBOdn9gFagfRgQHghXisOnj2E=w526-h296)

3-run the program on PC and click play button in the app to start connection
![logo](https://play-lh.googleusercontent.com/eI1MKrJB7PgVow2MpHQOnJ0okBTjBuRVJLCzL5DSlHW1CfbOLQR3p6UMqwUfyqTRKPM=w526-h296)

4- send and receive data from the screen below
![logo](https://play-lh.googleusercontent.com/TTYvfDNCs7DBouJc-VYB4PAZFLxBbe8z770TM3O9gDLG4ovJPFYZAT-ruqS0AMCvgCQ=w526-h296)

5-use + button to add specific lables to send.

6-the program will decide which command linux to run depending on the message it received.

### explanning server 

the steps of creating server in socket programming ctreating a socket - bind - listen and when client wants to connect  accept the connection:
```
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
```
creating a map to store some lables as keys and string as the corresponding linux commands we can add any linux commands we want

```
std::map<const char *, const char *> linux_commands
   { {"terminal\n","gnome-terminal"},
         { "files\n","nautilus"},
         {"browser\n","firefox" },
         {"calc\n","gnome-calculator"},
         { "vs\n","code"},
         {"brows\n","firefox" }

   };

```
start an infinite loop to read from the client and loop on the map to determine what linux command to execute depending on the key.use uses for() and execp() mechanism to execute the linux commands providing more efficiet and faster way than system().

```
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
```