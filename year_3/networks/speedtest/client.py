import socket
import time
import threading
import os
import sys

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


def TCPUploadTest():

    timerCounter = threading.Thread(target=timerControl)
    timerCounter.start()

    while(advance):
        data = 'a' * 500
        tcpclient.send(bytes(data, "utf8"))

    tcpclient.send(bytes("!!-&*&-!!", "utf8"))

    bps = tcpclient.recv(500).decode("utf8")
    pps = tcpclient.recv(500).decode("utf8")

    print("--- UPLOAD ---")

    print("Bytes/segundo = " + str(bps))
    print("MBytes/segundo = " + str(int(bps)/1000000))
    print("Pacotes/segundo = " + str(pps))

def TCPDownloadTest():

    recievedData = b''
    pacotes = 0

    while(True):
        msg = tcpclient.recv(500)

        if msg.decode('utf8').find('&&--!--&&') != -1:
            break

        recievedData += msg
        pacotes += 1

    print("--- DOWNLOAD ---")

    packagesSent = tcpclient.recv(500).decode("utf8")
        
    bytesRecieved = sys.getsizeof(recievedData)
    print("Bytes recebidos = " + str(bytesRecieved))
    print("Pacotes enviados = " + packagesSent)
    print("Pacotes recebidos = " + str(pacotes))

    bps = bytesRecieved / 20
    pps = pacotes / 20

    print("Bytes/segundo = " + str(bps))
    print("MBytes/segundo = " + str(bps/1000000))
    print("Pacotes/segundo = " + str(pps))

def UDPUploadTest():

    packagesSent = 0

    dest = (tcp_client_address, UDPPORT)

    timerCounter = threading.Thread(target=timerControl)
    timerCounter.start()

    while(advance):
        data = 'a' * 500
        udp.sendto(bytes(data, "utf8"), dest)
        packagesSent += 1

    tcpclient.send(bytes("!!-&*&-!!", "utf8"))

    bps = tcpclient.recv(500).decode("utf8")
    pps = tcpclient.recv(500).decode("utf8")
    packagesRecieved = tcpclient.recv(500).decode("utf8")

    print("--- UPLOAD ---")

    print("Pacotes enviados = " + str(packagesSent))
    print("Pacotes perdidos = " + str(packagesSent - int(packagesRecieved)))

    print("Bytes/segundo = " + str(bps))
    print("MBytes/segundo = " + str(int(bps)/1000000))
    print("Pacotes/segundo = " + str(pps))

def UDPDownloadTest():

    recievedData = b''
    pacotes = 0

    while (True):
        msg, client = udp.recvfrom(500)

        if msg.decode('utf8').find('&&--!--&&') != -1:
            break

        recievedData += msg
        pacotes += 1

    packagesSent = tcpclient.recv(500).decode("utf8")

    print("--- DOWNLOAD ---")
        
    bytesRecieved = sys.getsizeof(recievedData)
    print("Bytes recebidos = " + str(bytesRecieved))
    print("Pacotes recebidos = " + str(pacotes))
    print("Pacotes perdidos = " + str(int(packagesSent) - pacotes))

    bps = bytesRecieved / 20
    pps = pacotes / 20

    print("Bytes/segundo = " + str(bps))
    print("MBytes/segundo = " + str(bps/1000000))
    print("Pacotes/segundo = " + str(pps))


HOST = ''             
UDPPORT = 33000            
TCPPORT = 33001        

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

udporig = (HOST, UDPPORT)
tcporig = (HOST, TCPPORT)

udp.bind(udporig)
tcp.bind(tcporig)

tcp.listen(TCPPORT)

print("Aguardando conexão...")

tcpclient, tcp_client_address = tcp.accept()

print("Conexão estabelecida.")

msg = tcpclient.recv(500)

if msg == b'udp':
    print("Speedtest com UDP")
    UDPDownloadTest()
    UDPUploadTest()

elif msg == b'tcp': 
    print("Speedtest com TCP")
    TCPDownloadTest()
    TCPUploadTest()


tcp.close()
udp.close()
