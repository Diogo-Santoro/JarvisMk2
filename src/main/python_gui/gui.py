import tkinter as tk  # Importa a biblioteca Tkinter (para interface gráfica)
#import bluetooth  # Importa a biblioteca Bluetooth (comentada porque não é usada no código atual)

class Application(tk.Tk):  # Define uma classe chamada Application que herda de tk.Tk
    def __init__(self):  # Define o construtor da classe
        super().__init__()  # Chama o construtor da classe pai
        self.title("Controle de Bombas")  # Define o título da janela
        self.geometry("800x600")  # Define o tamanho da janela
        self.create_widgets()  # Chama o método para criar widgets

        # Endereço MAC do módulo Bluetooth do Arduino (substitua pelo seu endereço)
        #self.arduino_mac_address = '00:00:00:00:00:00'

        self.feedback_label = tk.Label(self, text="", fg="black")  # Cria um rótulo para exibir feedback
        self.feedback_label.pack()  # Adiciona o rótulo à janela

    def create_widgets(self):  # Define um método para criar widgets
        test_menu_button = tk.Button(self, text="Test Menu", command=self.open_test_menu)  # Cria um botão chamado "Test Menu"
        test_menu_button.pack(pady=100)  # Adiciona o botão à janela

    def open_test_menu(self):  # Define um método para abrir o menu de teste
        test_menu_window = tk.Toplevel(self)  # Cria uma nova janela
        test_menu_window.title("Test Menu")  # Define o título da nova janela
        test_menu_window.geometry("600x400")  # Define o tamanho da nova janela

        buttons = []  # Inicializa uma lista vazia para armazenar botões
        for pump_number in range(1, 5):  # Loop de 1 a 4
            button_text = f"Test Pump {pump_number}"  # Define o texto do botão dinamicamente
            buttons.append(tk.Button(test_menu_window, text=button_text, command=lambda num=pump_number: self.test_pump(num)))  # Cria botões dinamicamente

        for button in buttons:  # Loop pelos botões criados
            button.pack(fill='y', expand=False, pady=5)  # Adiciona os botões à nova janela

        btn_emergency_stop = tk.Button(test_menu_window, text="Emergency Stop", command=self.emergency_stop)  # Cria um botão "Emergency Stop"
        btn_emergency_stop.pack(fill='y', expand=False, pady=5)  # Adiciona o botão à nova janela

    def test_pump(self, pump_number):  # Define um método para testar a bomba
        command = str(pump_number)  # Converte o número da bomba em uma string
        response = self.send_command(command)  # Chama a função para enviar comandos ao Arduino
        feedback_text = f"Comando enviado: {command}, Resposta: {response}"  # Cria um texto de feedback
        if "Erro" in response:  # Verifica se a resposta contém "Erro"
            self.update_feedback(feedback_text, "red")  # Atualiza o feedback em vermelho em caso de erro
        else:
            self.update_feedback(feedback_text, "green")  # Atualiza o feedback em verde em caso de sucesso

    def emergency_stop(self):  # Define um método para a parada de emergência
        command = '0'  # Define o comando de parada de emergência
        response = self.send_command(command)  # Chama a função para enviar comandos ao Arduino
        feedback_text = f"Comando enviado: {command}, Resposta: {response}"  # Cria um texto de feedback
        if "Erro" in response:  # Verifica se a resposta contém "Erro"
            self.update_feedback(feedback_text, "red")  # Atualiza o feedback em vermelho em caso de erro
        else:
            self.update_feedback(feedback_text, "green")  # Atualiza o feedback em verde em caso de sucesso

    def send_command(self, command):  # Define um método para enviar comandos
        try:
            # Conecta-se ao módulo Bluetooth do Arduino pelo endereço MAC
            sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
            sock.connect((self.arduino_mac_address, 1))

            #Envia o comando para o Arduino via Bluetooth
            sock.send(command)

            # Recebe a resposta do Arduino
            response = sock.recv(1024)
            sock.close()

            # Simulação de resposta (descomente as linhas acima para usar o Bluetooth)
            response = "Comando recebido pelo Arduino."

            return response
        except Exception as e:
            error_message = f"Erro ao enviar comando para Arduino: {str(e)}"
            self.update_feedback(error_message, "red")  # Atualiza o feedback em vermelho em caso de erro
            return error_message

    def update_feedback(self, text, color):  # Define um método para atualizar o feedback
        self.feedback_label.config(text=text, fg=color)  # Atualiza o rótulo de feedback com texto e cor

if __name__ == "__main__":  # Verifica se o código está sendo executado como um programa principal
    app = Application()  # Cria uma instância da classe Application
    app.mainloop()  # Inicia o loop principal da interface gráfica
