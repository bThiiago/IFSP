import zmq
import time
import random

port = "5560"
context = zmq.Context()
socket = context.socket(zmq.REP)
socket.connect("tcp://localhost:%s" % port)
server_id = random.randrange(1, 10005)
while True:

    message = socket.recv()
    print("Requisição recebida: ", message)
    time.sleep(1)
    socket.send_string("Ola do servidor: %s" % server_id)
