from gui import *

mac_adress = "98:da:50:00:dc:da"
 
def iniciar_bebida1():
    comando = 1
    enviar_comando_arduino(mac_adress, comando)

def iniciar_bebida2():
    comando = 2
    enviar_comando_arduino(mac_adress, comando)
    
def iniciar_bebida3():
    comando = 3
    enviar_comando_arduino(mac_adress, comando)

def iniciar_bebida4():
    comando = 4
    enviar_comando_arduino(mac_adress, comando)