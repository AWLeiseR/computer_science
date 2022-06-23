import socket
import os
import math

def clearTerminal():
    print("\n" * os.get_terminal_size().lines)

packageArray = []

clearTerminal()

# filePath = input("Digite o arquivo que deseja enviar: ")
filePath = "./teste.txt"

try:
    file = open(filePath,"rb")
except:
    print("Arquivo não encontrado!")
    exit()


fileSize = os.path.getsize(filePath)
fileName = os.path.basename(filePath)

clearTerminal()

print("Arquivo aberto com sucesso! Tamanho: " + str(fileSize))

print("Insira quantos bytes deseja enviar cada pacote (1) 100 (2) 500 (3) 1000")
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

arrayData = [None] * packageArray.__len__()

for package in packageArray:
    index = int.from_bytes(package[:4], byteorder="big")
    data = package[4:]
    arrayData[index] = data

finalData = b''

for idx, val in enumerate(packageArray):
    finalData += arrayData[idx]

print(finalData)
