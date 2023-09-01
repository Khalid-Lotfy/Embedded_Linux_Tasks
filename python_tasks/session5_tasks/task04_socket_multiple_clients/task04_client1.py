import socket


# create new socket
client=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
ip=socket.gethostbyname(socket.gethostname())

print("ip is : ",ip)
print("=============================================")
# connect to the server's port
client.connect((ip,5000))

# sending and receiving data with the server
while True:

    msg=input("please enter the message you want to send: ")
    msg_encoded=msg.encode("UTF-8")

    client.send(msg_encoded)
    print("=============================================")

    rodata=client.recv(1024)
    print(f"({ip}) sent: {rodata.decode('UTF-8')}")
    print("=============================================")



