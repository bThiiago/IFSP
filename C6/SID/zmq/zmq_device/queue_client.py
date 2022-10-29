import zmq
import random

port = "5559"
context = zmq.Context()
print("Conectando ao server...")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:%s" % port)
client_id = random.randrange(1, 10005)

for request in range(1, 10):
    print("Enviando requisição ", request, "...")
    socket.send_string("Ola do %s" % client_id)
    
    message = socket.recv()
    print("Resposta recebida ", request, "[", message, "]")


