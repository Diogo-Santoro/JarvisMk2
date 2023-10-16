import tkinter as tk
#import bluetooth  

class Application(tk.Tk):  
    def ativa_bomba(self, pump_number):  # Define um método para ativar a bomba
        command = str(pump_number)
        response = self.send_command(command)  # Chama a função para enviar comandos ao Arduino
        feedback_text = f"Comando enviado: {command}, Resposta: {response}"
        if "Erro" in response:
            self.update_feedback(feedback_text, "red")
        else:
            self.update_feedback(feedback_text, "green")

    def parada_emergencia(self):  # Define um método para a parada de emergência
        command = '0'
        response = self.send_command(command)
        feedback_text = f"Comando enviado: {command}, Resposta: {response}"
        if "Erro" in response:  # Verifica se a resposta contém "Erro"
            self.update_feedback(feedback_text, "red")
            self.update_feedback(feedback_text, "green") 

    def envia_comando_bluetooth(self, command): # Envia um comando e retorno do bluetooth
        try:
            sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
            sock.connect((self.arduino_mac_address, 1))
            sock.send(command)
            response = sock.recv(1024)
            sock.close()
            response = "Comando recebido pelo Arduino."
            return response
        
        except Exception as e:
            error_message = f"Erro ao enviar comando para Arduino: {str(e)}"
            self.update_feedback(error_message, "red")
            return error_message

    def atualiza_feedback(self, text, color):
        self.feedback_label.config(text=text, fg=color)

