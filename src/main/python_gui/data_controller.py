import tkinter as tk

class Controller:
    def __init__(self, root):
        self.root = root
        self.root.title("Tkinter Controller")
        
        self.label = tk.Label(root, text="Hello, Tkinter!")
        self.label.pack()
        
        self.button = tk.Button(root, text="Change Text", command=self.change_text)
        self.button.pack()
        
    def change_text(self):
        self.label.config(text="Text Changed!")

if __name__ == "__main__":
    root = tk.Tk()
    app = Controller(root)
    root.mainloop()