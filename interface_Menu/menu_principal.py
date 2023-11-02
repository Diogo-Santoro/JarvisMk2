from customtkinter import *
import customtkinter as ctk
from PIL import Image

def funcaoBotao1():
    # Adicione a ação desejada para o botão "Menu de Drinks"
    pass

janela = ctk.CTk()
janela.title("Menu Principal")
janela.iconbitmap("icone.ico")
janela.geometry("500x500")
ctk.set_appearance_mode("dark")


imgFundo = ctk.CTkImage(Image.open("img/fundoMenu.png"), size=(500, 500))
imgLabel = ctk.CTkLabel(janela, image=imgFundo, text="")
imgLabel.pack()

tittleFont = ctk.CTkFont(family="Georgia", size=30)
titulo = ctk.CTkLabel(janela, text="JARVIS MK2", text_color="white", font=tittleFont, fg_color="#1c1b20")
titulo.place(x=480, y=20, anchor="ne")


botaoFont = ctk.CTkFont(family="Georgia", size=18)
botao1 = ctk.CTkButton(janela, text="Menu de Drinks", command=funcaoBotao1, font=botaoFont, fg_color="DeepPink", hover_color="HotPink",border_color="")
botaoSair = ctk.CTkButton(janela, text="Sair do Aplicativo", command=janela.quit, font=botaoFont, fg_color="DarkRed", hover_color="FireBrick",border_color="", width=300)

botao1.place(x=10, y=294)
botaoSair.place(x=100, y=440)

janela.mainloop()