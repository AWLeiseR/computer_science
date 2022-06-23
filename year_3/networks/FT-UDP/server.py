import socket
import os
import math
import time

def clearTerminal():
    print("\n" * os.get_terminal_size().lines)

packageArray = []

clearTerminal()

# filePath = input("Digite o arquivo que deseja enviar: ")
filePath = "./redes100.txt"

try:
    file = open(filePath,"rb")
except:
    print("Arquivo não encontrado!")
    exit()


fileSize = os.path.getsize(filePath)
fileName = os.path.basename(filePath)

clearTerminal()

print("Arquivo aberto com sucesso! Tamanho: " + str(fileSize))

print("Insira com quantos bytes deseja enviar cada pacote (1) 100 (2) 500 (3) 1000")
# ch = int(input())
ch = 1

if ch == 1:
    packageSize = 100
elif ch == 2:
    packageSize = 500
elif ch == 3:
    packageSize = 1000
else:
    packageSize = 100

arraySize = math.ceil(fileSize / packageSize)
lastPackageSize = fileSize % packageSize

print("LPS = " + str(lastPackageSize))

for i in range(0, arraySize):
    packageID = i.to_bytes(4, byteorder='big')
    # packageDelimitator = bytes(str("="), "utf8")

    if i < arraySize - 1:
        packageData = file.read(packageSize)
    else:
        packageData = file.read(lastPackageSize)

    finalPackage = packageID + packageData
    packageArray.append(finalPackage)


print("\nO seu arquivo foi dividido em " + str(arraySize) + " pacotes de " + str(packageSize) + " bytes")
input("Pressione ENTER iniciar a transmissão")

HOST = '189.103.132.134'      
UDPPORT = 33000
TCPPORT = 33001
udpdest = (HOST, UDPPORT)
tcpdest = (HOST, TCPPORT)

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

tcp.connect(tcpdest)

sizeFile = arraySize.to_bytes(4, byteorder='big')

packageSizeInBytes = packageSize.to_bytes(4, byteorder="big")
lastPackageSizeInBytes = lastPackageSize.to_bytes(4, byteorder="big")

for n in range(0,6):
    udp.sendto(packageSizeInBytes + lastPackageSizeInBytes, udpdest)

for n in range(0,6):
    udp.sendto(bytes("?!?==?!?", "utf8"), udpdest)

for n in range(0,6):
    udp.sendto(bytes(fileName, "utf8"), udpdest)

for n in range(0,6):
    udp.sendto(bytes("*!*!()!*!*", "utf8"), udpdest)

for n in range(0,6):
    udp.sendto(sizeFile, udpdest)

for i in range(0, 6):
    udp.sendto(bytes("&&*--*&&", "utf8"), udpdest)
    print("Enviando pacote final intermediario " + str(i))

time.sleep(3.5)

for package in packageArray:
    udp.sendto (package, udpdest)

for i in range(0, 6):
    udp.sendto(bytes("()()**()()", "utf8"), udpdest)
    print("Enviando pacote final " + str(i))

    
def sendMissingPackage(index):
    print(index)
    index = int.from_bytes(index, byteorder="big")
    udp.sendto(packageArray[index], udpdest)

while True:
    
    msg = tcp.recv(4)

    if msg == b'!-!-':
        break
    else:
        sendMissingPackage(msg)

tcp.close()
udp.close()

print("\nO seu arquivo foi dividido em " + str(arraySize) + " pacotes de " + str(packageSize) + " bytes")
print("LPS = " + str(lastPackageSize))