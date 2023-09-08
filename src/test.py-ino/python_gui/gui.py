import tkinter as tk
import serial
import time

class Application(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Controle de Bombas")
        self.geometry("800x600")
        self.create_widgets()
        #self.arduino = serial.Serial('COM3', 9600)

    def create_widgets(self):
        test_menu_button = tk.Button(self, text="Test Menu", command=self.open_test_menu)
        test_menu_button.pack(pady=100)

    def open_test_menu(self):
        test_menu_window = tk.Toplevel(self)
        test_menu_window.title("Test Menu")

        btn_testPump1 = tk.Button(test_menu_window, text="Test Pump 1", command=self.test_pump1)
        btn_testPump2 = tk.Button(test_menu_window, text="Test Pump 2", command=self.test_pump2)
        btn_testPump3 = tk.Button(test_menu_window, text="Test Pump 3", command=self.test_pump3)
        btn_testPump4 = tk.Button(test_menu_window, text="Test Pump 4", command=self.test_pump4)
        btn_allPumps = tk.Button(test_menu_window, text="All Pumps", command=self.test_all_pumps)
        btn_emergencyStop = tk.Button(test_menu_window, text="Emergency Stop", command=self.emergency_stop)
        btn_back = tk.Button(test_menu_window, text="Back", command=test_menu_window.destroy)

        buttons = [btn_testPump1, btn_testPump2, btn_testPump3, btn_testPump4, btn_allPumps, btn_emergencyStop]
        row = 0
        for i in range(0, len(buttons), 2):
            buttons[i].grid(row=row, column=0, padx=10, pady=10)
            if i + 1 < len(buttons):
                buttons[i + 1].grid(row=row, column=1, padx=10, pady=10)
            row += 1
        btn_back.grid(row=row, column=0, columnspan=2, padx=10, pady=10)

    def test_pump1(self):
        self.send_command('1')

    def test_pump2(self):
        self.send_command('2')

    def test_pump3(self):
        self.send_command('3')

    def test_pump4(self):
        self.send_command('4')

    def test_all_pumps(self):
        for pump_number in range(1, 5):
            self.send_command(str(pump_number))
            time.sleep(2)

    def emergency_stop(self):
        self.send_command('0')

    def send_command(self, command):
        self.arduino.write(command.encode())

if __name__ == "__main__":
    app = Application()
    app.mainloop()
