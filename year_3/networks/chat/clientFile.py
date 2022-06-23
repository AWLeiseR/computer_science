import socket
import time
from threading import Thread

def receive():
    packages = 1

    while True:
        try:
            package = tcp.recv(nBytes)
            if package == b'':
               break
            packages = packages + 1
            arq.write(package)
        except :
            print("Erro no pacote " + str(packages))
            break

HOST="201.54.100.10"
PORT=33000

tcp = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

destination=(HOST,PORT)

tcp.connect(destination)

input("Pressione ENTER para começar a receber os arquivos...")

msg = tcp.recv(1024).decode("utf-8")

print("mensagem "+msg)

x=msg.split("|")

print(x)

numMsg = int(x[0])
nBytes = int(x[1])
lastPackageSize = int(x[2])
print("LastPackageSiz: "+x[2])
nomeArq = str(x[3])

recebida=bytes("msg recebida","utf-8")

tcp.send(recebida)

arrayData=[]

tempo_ini = time.time()

# for i in range(0,int(numMsg)):
#     print(str(i))
#     if i < numMsg - 1:
#         #print(tcp.recv(nBytes))
#         arrayData.append(tcp.recv(nBytes))
#     else:
#         #print(tcp.recv(lastPackageSize))
#         arrayData.append(tcp.recv(lastPackageSize))

arq=open(nomeArq,"wb")
arq.close()

arq=open(nomeArq,"ab")

receive()

# receiveThread= Thread(target=receive)
# receiveThread.start()

arq.close()

tempo_fim = time.time()
tempo_execucao = tempo_fim - tempo_ini
print("Tempo de execução: " + str(tempo_execucao))
bPs = (nBytes + lastPackageSize) / tempo_execucao
print("Bytes por segundo = " + str(bPs))



# for i in range(0,int(numMsg)):
#     arq.write(arrayData[i])
    


tcp.close()
