import tkinter as tk

class Controller:

    def mostrar_bebidas():
        telaMenu.pack_forget()
        telaBebida.pack()

    def mostrar_menu():   
        telaMenu.pack_forget()  #
        telaBebida.pack()

    
    def sair_aplicacao():
        root.destroy()