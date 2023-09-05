import serial
import time

ser = serial.Serial('COMX', 9600)  # Substitua 'COMX' pela porta serial correta
enviar_comando = True  # Sinaliza quando o Python deve enviar comandos

def receber_dados():
    while True:
        linha = ser.readline().decode().strip()  # Leia a linha recebida via Bluetooth
        if linha.startswith("P:"):
            presenca = int(linha[2:])  # Extrai a detecção de presença dos dados
            if presenca == 1:
                print("Presença detectada")
            else:
                print("Nenhuma presença detectada")

        # Verifique se é hora de enviar um comando ao Arduino
        if enviar_comando:
            ser.write('1'.encode())  # Envie o comando '1' para ativar a bomba 1
            time.sleep(1)  # Aguarde um pouco para o Arduino processar o comando
            enviar_comando = False  # Aguarde a próxima vez para enviar um comando

# Chame a função para começar a receber dados
receber_dados()
