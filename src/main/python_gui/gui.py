import socket

def enviar_comando_arduino(mac_address, comando):
    try:

        if comando == 1:
            ingrediente1 = "FUNCIONOU"
            ingrediente2 = "a"
            
        if comando == 2:
            ingrediente1 = "FUNCIONOU"
            ingrediente2 = "b"
        if comando == 3:
            ingrediente1 = "FUNCIONOU"
            ingrediente2 = "c"
        if comando == 4:
            ingrediente1 = "FUNCIONOU"
            ingrediente2 = "ad"

        sock = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)
        sock.connect((mac_address, 1))
        sock.send(ingrediente1.encode(), ingrediente2.encode()) 
        sock.close()
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