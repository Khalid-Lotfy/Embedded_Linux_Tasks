import socket
import threading

     

#the function executed for each connected client
def handle_client(client_socket, client_address):
    
        print(f"\nNew client is connected  {client_address}")
        print("================================================")
        while True:
            # receiving new data 
            rodata=client_socket.recv(1024)
            # disconnect the client when receiving no data
            if not rodata:
                 print(f'\n{client_address} is disconnected ')
                 print("================================================")
                 client_socket.close()
                 break
            print(f"{client_address} sent :  {rodata.decode('UTF-8')} ")
            print("================================================")
            # reply with that the message is received correctly
            msg_encoded="I got your message".encode("UTF-8")
            client_socket.send(msg_encoded)






# create a new socket
server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_ip=socket.gethostbyname(socket.gethostname())

print("ip is : ",server_ip)
print("=============================================")

# bind with port number
server_socket.bind((server_ip,5000))
# start listening for new connections
server_socket.listen(5)

# create a thread for each new client to handle more than one
while True:
    client,address=server_socket.accept()

    client_thread= threading.Thread(target=handle_client,args=(client,address))
    
    client_thread.start()
    