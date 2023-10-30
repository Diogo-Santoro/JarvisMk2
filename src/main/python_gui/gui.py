import bluetooth
def enviar_comando_arduino(mac_address, comando):
    try:
        if comando  == 1:           
            ingrediente = "FUNCIONOU"
            tempo_bomba1 = 10
            tempo_bomba2 = 10
            
        if comando == 2:
            ingrediente = "FUNCIONOU 2"
            tempo_bomba1 = 20
            tempo_bomba2 = 20
            
        sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
        sock.connect((mac_address, 1))  # O segundo argumento é o canal RFCOMM, que geralmente é 1

        sock.send(tempo_bomba1,tempo_bomba2, ingrediente)  # Envie o comando como uma string

        sock.close()
        return True
    except Exception as e:
        print(f"Erro ao enviar o comando: {e}")
        return False


def receber_resposta_arduino(mac_address):
            
    try:
        sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
        sock.connect((mac_address, 1))  # O segundo argumento é o canal RFCOMM, que geralmente é 1

        resposta = sock.recv(1024)  # Receba a resposta do Arduino (você pode ajustar o tamanho do buffer conforme necessário)

        sock.close()
        return resposta
    except Exception as e:
        print(f"Erro ao receber a resposta: {e}")
        return None