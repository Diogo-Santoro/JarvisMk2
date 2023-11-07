import socket

def enviar_comando_arduino(mac_address, comando):
    try:
        if comando == 1:
            bebida = "1"
        if comando == 2:
            bebida = "11"
        if comando == 3:
            bebida = "111"
        if comando == 4:
            bebida = "1111"
        sock = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)
        sock.connect((mac_address, 1))
        sock.send(bebida.encode())
        print(sock.send(bebida.encode()))
        sock.close()
        print("FUNCIONOU")
        return True
    except Exception as e:
        print(f"Erro ao enviar valor para Arduino: {e}")
        return False

def receber_comando_arduino(mac_address):
    try:

        sock = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)
        sock.connect((mac_address, 1)) 
        resposta = sock.recv(1024).decode()  
        sock.close()
        return resposta
    except Exception as e:
        print(f"Erro ao receber resposta do Arduino: {e}")
        return None