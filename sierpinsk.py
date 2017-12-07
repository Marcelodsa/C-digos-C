import tkinter as tk
import math
 
class App(tk.Tk):
 
    def __init__(self):
        tk.Tk.__init__(self)
 
        self.title("Triangulo de Sierpinski")
 
        self.width = 512
        self.height = int(round(self.width*math.sqrt(3.0)/2.0))
        self.margin = 10
        self.canvas = tk.Canvas(self, width=self.width+(2*self.margin), height=self.height+(2*self.margin), bg="white")
        self.canvas.pack()
        self.btn = tk.Button(self, text="Desenhar!", command=self.desenho)
        self.btn.pack(side=tk.LEFT)
        self.label = tk.Label(self, text="Divisão")
        self.label.pack()
        self.level = tk.Entry(self, width=3, justify=tk.CENTER)
        self.level.insert(tk.INSERT, "1")
        self.level.pack()
 
        self.mainloop()        
 
    def desenho(self):
 
        self.canvas.delete("all")
        level = int(self.level.get())
        x1 = self.margin + 0
        y1 = self.margin + self.height
 
        x2 = self.margin + self.width/2
        y2 = self.margin + 0
         
        x3 = self.margin + self.width
        y3 = self.margin + self.height
        self.repeticao(level, x1, y1, x2, y2, x3, y3)
 
    def repeticao(self, level, x1, y1, x2, y2, x3, y3):
        if level <= 1:
            self.canvas.create_line(x1, y1, x2, y2)
            self.canvas.create_line(x2, y2, x3, y3)
            self.canvas.create_line(x3, y3, x1, y1)
        else:
            level = level - 1
 
            mx1 = (x1 + x2)/2
            my1 = (y1 + y2)/2
            mx2 = (x2 + x3)/2
            my2 = (y2 + y3)/2
            mx3 = (x3 + x1)/2
            my3 = (y3 + y1)/2
 
            self.repeticao(level, x1, y1, mx1, my1, mx3, my3)
            self.repeticao(level, mx1, my1, x2, y2, mx2, my2)
            self.repeticao(level, mx3, my3, mx2, my2, x3, y3)
 
App()
