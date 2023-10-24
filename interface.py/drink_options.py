import tkinter as tk
from PIL import Image, ImageTk

def funcaoBotao1():
    pass

def funcaoBotao2():
    pass

def funcaoBotao3():
    pass

def funcaoBotao4():
    pass

def sair():
    root.destroy()

def botaoSobre(event):
    event.widget.config(bg="LightGray") 
    event.widget.config(relief=tk.SUNKEN)   

def botaoFora(event):
    event.widget.config(bg="white")  
    event.widget.config(relief=tk.RAISED)

def botaoSobreSair(event):
    event.widget.config(bg="FireBrick")
    event.widget.config(relief=tk.SUNKEN)

def botaoForaSair(event):
    event.widget.config(bg="DarkRed")
    event.widget.config(relief=tk.RAISED)

root = tk.Tk()
root.title("Opções de Drinks")
root.iconbitmap("C:/Users/Dominggues/Desktop/Jarvis/JarvisMk2/interface.py/img/icone.ico")
root.geometry("500x500")

imagem_pil = Image.open("C:/Users/Dominggues/Desktop/Jarvis/JarvisMk2/interface.py/img/img.png")
imagem_tk = ImageTk.PhotoImage(imagem_pil)

label_fundo = tk.Label(root, image=imagem_tk)
label_fundo.place(x=0, y=0, relwidth=1, relheight=1)


tittle_font = ("Georgia", 25)
tittle = tk.Label(root, text=" - SELECIONE O DRINK -", font=tittle_font, fg="black")
tittle.place(relx=0.5, rely=0.1, anchor=tk.CENTER)

botao_font = ("Georgia", 15)
botao1 = tk.Button(root, text="Drink 1", command=funcaoBotao1, font=botao_font, bg="white", fg="black", borderwidth=3,bd=0, highlightthickness=0)
botao2 = tk.Button(root, text="Drink 2", command=funcaoBotao2, font=botao_font, bg="white", fg="black", borderwidth=3,bd=0, highlightthickness=0)
botao3 = tk.Button(root, text="Drink 3", command=funcaoBotao3, font=botao_font, bg="white", fg="black", borderwidth=3,bd=0, highlightthickness=0)
botao4 = tk.Button(root, text="Drink 4", command=funcaoBotao4, font=botao_font, bg="white", fg="black", borderwidth=3,bd=0, highlightthickness=0)
botaoSair = tk.Button(root, text="Voltar ao Menu", command=sair, font=botao_font, bg="DarkRed", fg="white", borderwidth=3,bd=0, highlightthickness=0)


botao1.place(relx=0.5, rely=0.3, anchor=tk.CENTER)
botao2.place(relx=0.5, rely=0.4, anchor=tk.CENTER)
botao3.place(relx=0.5, rely=0.5, anchor=tk.CENTER)
botao4.place(relx=0.5, rely=0.6, anchor=tk.CENTER)
botaoSair.place(relx=0.5, rely=0.9, anchor=tk.CENTER)

botao1.bind("<Enter>", botaoSobre)
botao1.bind("<Leave>", botaoFora)
botao2.bind("<Enter>", botaoSobre)
botao2.bind("<Leave>", botaoFora)
botao3.bind("<Enter>", botaoSobre)
botao3.bind("<Leave>", botaoFora)
botao4.bind("<Enter>", botaoSobre)
botao4.bind("<Leave>", botaoFora)
botaoSair.bind("<Enter>", botaoSobreSair)
botaoSair.bind("<Leave>", botaoForaSair)

root.mainloop()
