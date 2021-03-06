#!/usr/bin/env python3
"""Script for Tkinter GUI chat client."""
from socket import AF_INET, socket, SOCK_STREAM
from threading import Thread
import tkinter 

"""Processar mensagem recebida."""
def receive():
    
    while True:
        try:
            msg = client_socket.recv(BUFSIZ).decode("utf8")
            msg_list.insert(tkinter.END, msg)
        except OSError: 
            break

"""Processar mensagem enviada."""
def send(event=None):
    
    msg = my_msg.get()
    my_msg.set("")  # Clears input field.
    client_socket.send(bytes(msg, "utf8"))
    if msg == "{sair}":
        client_socket.close()
        top.destroy()

"""Processar saida do chat."""
def on_closing(event=None):
    
    my_msg.set("{sair}")
    send()

top = tkinter.Tk()
top.title("Chat - Redes")

messages_frame = tkinter.Frame(top)
my_msg = tkinter.StringVar()
my_msg.set("Digite sua mensagem aqui.")
scrollbar = tkinter.Scrollbar(messages_frame)
msg_list = tkinter.Listbox(messages_frame, height=15, width=50, yscrollcommand=scrollbar.set)
scrollbar.pack(side=tkinter.RIGHT, fill=tkinter.Y)
msg_list.pack(side=tkinter.LEFT, fill=tkinter.BOTH)
msg_list.pack()
messages_frame.pack()

entry_field = tkinter.Entry(top, textvariable=my_msg)
entry_field.bind("<Return>", send)
entry_field.pack()
send_button = tkinter.Button(top, text="Enviar", command=send)
send_button.pack()

top.protocol("WM_DELETE_WINDOW", on_closing)

HOST = input('Digite o IP do host: ')
PORT = input('Digite a porta (default 33000): ')
if not PORT:
    PORT = 33000
else:
    PORT = int(PORT)

BUFSIZ = 1024
ADDR = (HOST, PORT)

client_socket = socket(AF_INET, SOCK_STREAM)
client_socket.connect(ADDR)

receive_thread = Thread(target=receive)
receive_thread.start()
tkinter.mainloop()