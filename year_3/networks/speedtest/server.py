import socket
import os
import math
import sys
import time
import threading

HOST = '131.108.229.105'      
UDPPORT = 33000
TCPPORT = 33001

advance = True
count = 0

def timerControl():
    global advance, count
    
    while(count < 20):
        print(count)
        time.sleep(1)
        count += 1
    
    print("20 segundos")
    advance = False


def speedTestTCP():

    timerCounter = threading.Thread(target=timerControl)
    timerCounter.start()

    packagesSent = 0

    while(advance):
        data = 'a' * 500
        packagesSent += 1
        connection.sendto(bytes(data, "utf8"), prot)

    connection.sendto(bytes('&&--!--&&', "utf8"), prot)

    time.sleep(1)

    print("UPLOAD")

    recievedData = b''
    pacotes = 0

    while(True):
        msg = connection.recv(500)

        if msg.decode('utf8').find('!!-&*&-!!') != -1:
            break

        print(msg)
        recievedData += msg
        pacotes += 1

    connection.close()
        
    bytesRecieved = sys.getsizeof(recievedData)
    bps = (bytesRecieved * 8) / 20
    pps = pacotes / 20

    connection.sendto(bytes(str(bps),"utf-8"), prot)
    connection.sendto(bytes(str(pps),"utf-8"), prot)

    print(packagesSent)
    print(pacotes)
    

def speedTestUDP(tcp):
    packagesSent = 0
    packagesRecieved = 0

    timerCounter = threading.Thread(target=timerControl)
    timerCounter.start()

    while(advance):
        data = 'a' * 500

        connection.sendto(bytes(data, "utf8"), prot)
        
        packagesSent += 1

    time.sleep(2)

    for x in range(0, 100):
        connection.sendto(bytes("&&--!--&&", "utf8"), prot)

    time.sleep(1)

    tcp.sendto(bytes(str(packagesSent),"utf-8"), tcpdest)


    print("UPLOAD")

    recievedData = b''
    pacotes = 0

    while(True):
        msg, cliente = connection.recvfrom(500)

        if msg.decode('utf8').find('!!-&*&-!!') != -1:
            break
        
        packagesRecieved += 1

        print(msg)
        recievedData += msg
        pacotes += 1
        
    bytesRecieved = sys.getsizeof(recievedData)
    bps = (bytesRecieved * 8) / 20
    pps = pacotes / 20

    time.sleep(1)
    tcp.sendto(bytes(str(bps),"utf-8"), tcpdest)
    time.sleep(1)
    tcp.sendto(bytes(str(pps),"utf-8"), tcpdest)
    time.sleep(1)
    tcp.sendto(bytes(str(packagesRecieved),"utf-8"), tcpdest)

        
choice = int(input('Escolha o protocolo TCP (1) ou UDP (2)'))

if choice == 1: #TCP
    prot = (HOST, TCPPORT)
    connection = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    connection.connect(prot)
    connection.sendto(bytes("tcp", "utf8"), prot)
    speedTestTCP()
elif choice == 2:  #UDP
    prot = (HOST, UDPPORT)

    tcpdest = (HOST, TCPPORT)
    tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    tcp.connect(tcpdest)

    connection = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    connection.connect(prot)

    tcp.sendto(bytes("udp", "utf8"), tcpdest)

    speedTestUDP(tcp)
    tcp.close()
else:
    exit()


connection.close()