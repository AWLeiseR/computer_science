import socket
import time
import threading
import os

HOST = ''             
UDPPORT = 33000            
TCPPORT = 33001        

def downloadProgress():

    prev = -1

    while(True):

        count = 0

        for x in packageArray:
            if(x != None):
                count += 1

        percentage = (count * 100) / arraySize
        
        if(percentage != prev):
            print(str(round(percentage, 1)) + "%")   
            prev = percentage

        if(percentage >= 100):
            break

        time.sleep(1)

    return
    

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

udporig = (HOST, UDPPORT)
tcporig = (HOST, TCPPORT)

udp.bind(udporig)
tcp.bind(tcporig)
tcp.listen(TCPPORT)

print("Aguardando conexão...")

tcpclient, tcp_client_address = tcp.accept()

finalCount = 0

packageSize = 0
lastPackageSize = 0

while True:

    try:
        udp.settimeout(5.0)
        package, cliente = udp.recvfrom(1024)
    except socket.timeout:
        print("Limite de tempo para receber o tamanho do pacote!")
        exit(1)

    if package == b'?!?==?!?':
        finalCount += 1

        if finalCount >= 3:
            break

    else:
        packageSize = int.from_bytes(package[:4], byteorder="big")
        lastPackageSize = int.from_bytes(package[4:], byteorder="big")

finalCount = 0

fileName = ""

while True:

    try:
        udp.settimeout(5.0)
        package, cliente = udp.recvfrom(1024)
    except socket.timeout:
        print("Limite de tempo para receber o nome do arquivo!")
        exit(1)

    if package == b'*!*!()!*!*':
        finalCount += 1

        if finalCount >= 3:
            break

    elif package == b'?!?==?!?':
        continue

    else:
        fileName = package.decode("utf8")

print("Recebendo arquivo " +  fileName)

finalCount = 0
arraySize = 0

while True:

    try:
        udp.settimeout(5.0)
        package, cliente = udp.recvfrom(1024)
    except socket.timeout:
        print("Limite de tempo para receber o tamanho do arquivo!")
        exit(1)

    if package == b'&&*--*&&':
        finalCount += 1

        if finalCount >= 3:
            break

    else:
        arraySize = int.from_bytes(package, byteorder="big")


packageArray = arraySize * [None]

finalCount = 0

path = "./" + fileName + ".download"

arq = open(path, "wb")

progress = threading.Thread(target=downloadProgress)
progress.start()

initialTime = time.time()

while True:

    try:
        udp.settimeout(5.0)
        package, cliente = udp.recvfrom(1024)
    except socket.timeout:
        break

    if package == b'()()**()()':
        finalCount += 1

        if finalCount >= 3:
            break

    elif package == b'&&*--*&&':
        continue

    else:
        index = int.from_bytes(package[:4], byteorder="big")
        # data = package[4:]
        packageArray[index] = True
        arq.write(package)

missingPackages = []

for index, package in enumerate(packageArray):

    if(package == None):
        missingPackages.append(index)


def sendback():
    for index in missingPackages:
        value = index.to_bytes(4, byteorder='big')
        tcpclient.send(value)

def recieveMissing():
    
    while True:

        try:
            udp.settimeout(5.0)
            package, cliente = udp.recvfrom(1024)
        except socket.timeout:
            break

        if package == b'*!()-()!*':
            finalCount += 1

            if finalCount >= 3:
                break

        elif package == b'()()**()()':
            continue

        else:
            index = int.from_bytes(package[:4], byteorder="big")
            # data = package[4:]
            packageArray[index] = True
            missingPackages.remove(index)
            arq.write(package)

while missingPackages.__len__() > 0:

    threadEnvia = threading.Thread(target=sendback)
    threadRecebe = threading.Thread(target=recieveMissing)

    threadEnvia.start()
    threadRecebe.start()
    
    threadEnvia.join()
    threadRecebe.join()

tcpclient.send(b'!-!-')

udp.close()
tcp.close()

arq.close()

endTime = time.time()

excetutionTime = endTime - initialTime

print("Arquivo baixado em " + str(round(excetutionTime, 1)) + "s")
bPs = (os.path.getsize(path) / 8) / excetutionTime
print("Bits por segundo (b/s) = " + str(round(bPs, 2)) + "b/s")
BPs = (os.path.getsize(path) * pow(10, -6)) / excetutionTime
print("MBytes por segundo (MB/s) = " + str(round(BPs, 2)) + "MB/s")

fileReader = open(path, "rb")
fileSaver = open("./" + fileName, "wb")

fileArray = [b''] * arraySize

for idx, x in enumerate(fileArray):
    fileIndex = int.from_bytes(fileReader.read(4), byteorder="big")

    if(fileIndex == fileArray.__len__() - 1):
        fileData = fileReader.read(lastPackageSize)
        fileArray[fileArray.__len__() - 1] = fileData
    else:
        fileData = fileReader.read(packageSize)
        fileArray[fileIndex] = fileData

for data in fileArray:
    fileSaver.write(data)


fileReader.close()
fileSaver.close()
os.remove(path)
