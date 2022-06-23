#!/usr/bin/env python3
from socket import AF_INET, socket, SOCK_STREAM
from threading import Thread

def accept_incoming_connections():
    while True:
        client, client_address = SERVER.accept()
        print("%s:%s has connected." % client_address)
        client.send(bytes("Olá humano! Digite seu nome antes de começar a conversar.", "utf8"))
        addresses[client] = client_address
        Thread(target=handle_client, args=(client,)).start()


def handle_client(client):

    name = client.recv(BUFSIZ).decode("utf8")
    welcome = 'Seja bem-vindo %s! Digite {sair} para sair do chat.' % name
    client.send(bytes(welcome, "utf8"))
    msg = "%s entrou no chat! Dê boas-vindas!" % name
    broadcast(bytes(msg, "utf8"))
    clients[client] = name

    while True:
        msg = client.recv(BUFSIZ)
        if msg != bytes("{sair}", "utf8"):
            broadcast(msg, name+": ")
        else:
            client.send(bytes("{sair}", "utf8"))
            client.close()
            del clients[client]
            broadcast(bytes("%s saiu do chat." % name, "utf8"))
            break


def broadcast(msg, prefix=""): 

    for sock in clients:
        sock.send(bytes(prefix, "utf8")+msg)

        
clients = {}
addresses = {}

HOST = ''
PORT = 3400
BUFSIZ = 1024
ADDR = (HOST, PORT)

SERVER = socket(AF_INET, SOCK_STREAM)
SERVER.bind(ADDR)

if __name__ == "__main__":
    SERVER.listen(5)
    print(SERVER.getsockname())
    print("Esperando conexão...")
    ACCEPT_THREAD = Thread(target=accept_incoming_connections)
    ACCEPT_THREAD.start()
    ACCEPT_THREAD.join()
    SERVER.close()