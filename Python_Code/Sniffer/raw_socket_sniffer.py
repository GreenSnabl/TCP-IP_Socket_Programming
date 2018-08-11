import socket
import os
import sys

#   host to listen on
#if (len(sys.argv) < 2):
#    raise Exception("Need IP!")
host = "192.168.178.72" 

socket_protocol = socket.IPPROTO_ICMP

sniffer = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket_protocol)

sniffer.bind((host, 0))

sniffer.setsockopt(socket.IPPROTO_IP, socket.IP_HDRINCL, 1)

print (sniffer.recvfrom(65565))

