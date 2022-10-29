import zmq

def main():

    try:
        context = zmq.Context(1)

        frontend = context.socket(zmq.XREP)
        frontend.bind("tcp://*:5559")

        backend = context.socket(zmq.XREQ)
        backend.bind("tcp://*:5560")

        zmq.device(zmq.QUEUE, frontend, backend)
    except Exception as e:
        print(e)
        print("Desligando o dispositivo.")
    finally:
        pass
        frontend.close()
        backend.close()
        context.term()


if __name__ == "__main__":
    main()

