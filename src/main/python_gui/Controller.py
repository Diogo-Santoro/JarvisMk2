from gui import *

mac_adress = "XX:XX:XX:XX:XX:XX"
 
def iniciar_primeira_bebida():
    comando = 1
    enviar_comando_arduino(mac_adress, comando)