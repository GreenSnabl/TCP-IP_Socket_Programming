import socket

target_host = "127.0.0.1"
target_port = 9999

# create a socket object
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# connect the client
client.connect((target_host, target_port))  # (ip, port)-touple

# send some data
message = input()
byte = message.encode()
client.send(byte)

# receive some data
response = client.recv(4096)

print(response)
