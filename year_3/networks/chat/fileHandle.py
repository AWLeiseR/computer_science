from socket import AF_INET, socket, SOCK_STREAM
from threading import Thread
import os
import math

def clearTerminal():
    print("\n" * os.get_terminal_size().lines)

def sendPackage(packageID):
    try:
        print("Enviando pacote " + (packageID+1) + "/" + arraySize)
        client.send(packageArray[packageID])
    except:
        print("Erro ao enviar o pacote de ID " + packageID + ". Tentando novamente...")
        sendPackage(packageID)

packageArray = []

clearTerminal()

filePath = input("Digite o arquivo que deseja enviar: ")

try:
    file = open(filePath,"rb")
except:
    print("Arquivo não encontrado!")
    exit()


fileSize = os.path.getsize(filePath)

clearTerminal()

print("Arquivo aberto com sucesso! Tamanho: " + str(fileSize))

print("Insira quantos bytes deseja enviar cada pacote (1) 100 (2) 500 (3) 1000")
ch = int(input())

if ch == 1:
    packageSize = 100
elif ch == 2:
    packageSize = 500
elif ch == 3:
    packageSize = 1000
else:
    packageSize = 1024

arraySize = math.ceil(fileSize / packageSize)

for i in range(0, arraySize):
    # packageID = i.to_bytes(4, byteorder='little')
    packageData = file.read(100)
    finalPackage = packageData
    packageArray.append(finalPackage)

print("\nO seu arquivo foi dividido em " + str(arraySize) + " pacotes de " + str(packageSize) + " bytes")
input("Pressione ENTER para continuar... ")
clearTerminal()

HOST = ''
PORT = 33000
BUFSIZ = 1024
ADDR = (HOST, PORT)

SERVER = socket(AF_INET, SOCK_STREAM)
SERVER.bind(ADDR)
SERVER.listen(PORT)  


print("Arquivo pronto para ser enviado! Aguardando conexão...")

client, client_address = SERVER.accept()

print("Conexão estabelecida com ", client_address)

client.send(bytes(str(arraySize), "utf8"))

print("Esperando cliente iniciar a transferência de arquivos...")

clearTerminal()

print("Enviando arquivo " + filePath)

for i in range(0, arraySize):
    sendPackage(i)

print("\n\nPacotes enviados.")
print("Pressione ENTER para finalizar o programa.")
SERVER.close()

exit()
