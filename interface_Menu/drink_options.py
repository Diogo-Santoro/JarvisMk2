from customtkinter import *
import customtkinter as ctk
from PIL import Image

def mostrarMenuDrinks():
    pass

def funcaoBotao1():
    pass

def funcaoBotao2():
    pass

def funcaoBotao3():
    pass

def funcaoBotao4():
    pass

def funcaoBotaoVoltar():
    pass


janela2 = ctk.CTk()
janela2.iconbitmap("icone.ico")
janela2.title("Opções de Drinks")
janela2.geometry("500x500")
janela2.resizable(width=False, height=False)
tittleFont = ("Georgia", 35)
imgFundo = ctk.CTkImage(Image.open("img/img.png"), size=(500, 500))
imgLabel = ctk.CTkLabel(janela2, image=imgFundo, font=tittleFont, text="")
imgLabel.pack()

tittle = ctk.CTkLabel(janela2, text=" - SELECIONE O DRINK -", font=tittleFont, fg_color="#1b1819", text_color="white")
tittle.place(x= 43, y=30)


botao_font = ("Georgia", 20)
botao1 = ctk.CTkButton(janela2, text="Drink 1", command=funcaoBotao1, font=botao_font, fg_color="Chartreuse4", hover_color="Chartreuse3",border_color="")
botao2 = ctk.CTkButton(janela2, text="Drink 2", command=funcaoBotao2, font=botao_font, fg_color="Chartreuse4", hover_color="Chartreuse3", border_color="")
botao3 = ctk.CTkButton(janela2, text="Drink 3", command=funcaoBotao3, font=botao_font, fg_color="Chartreuse4", hover_color="Chartreuse3", border_color="")
botao4 = ctk.CTkButton(janela2, text="Drink 4", command=funcaoBotao4, font=botao_font, fg_color="Chartreuse4", hover_color="Chartreuse3", border_color="")
botaoVoltar = ctk.CTkButton(janela2, text="Voltar ao Menu", command=funcaoBotaoVoltar, font=ctk.CTkFont("Georgia", size=(29)), fg_color="DarkRed", hover_color="FireBrick", border_color="", width=300)

botao1.place(x=180, y=120)
botao2.place(x=180, y=190)
botao3.place(x=180, y=260)
botao4.place(x=180, y=330)
botaoVoltar.place(relx=0.5, rely=0.9, anchor=ctk.CENTER)


janela2.mainloop()
