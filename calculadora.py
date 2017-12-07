from tkinter import *
class Calc(Frame):
    def __init__(self, master=None):
        Frame.__init__(self,master)
        self.grid()
        self.criaComponet()
 
 
    def criaComponet(self):
        self.entrada = Entry(self.master, width=34, bd =3 )
        self.entrada.grid(row=1, column=0)
        botoes=["7","8","9","+","4","5","6","*","1","2","3","/","0","-","C","="]
        linha = 1
        coluna =1
        for i in botoes:
            comando= lambda x=i:self.calcular(x)
            self.botao=Button(self, text=i, width=6, height=2, command=comando)
            self.botao.grid(row=linha,column=coluna)
            if coluna >=4:
                linha+=1
                coluna=0
            coluna+=1
    def calcular(self, valor):
        if valor =="=":
            try:
                calculo=eval(self.entrada.get())
                self.entrada.insert(END, "="+str(calculo))
            except:
                self.entrada.insert(END, "ERRO")
        elif valor =="C":
            self.entrada.delete(0, END)
        else:
            if "=" in self.entrada.get():
                self.entrada.delete(0,END)
            self.entrada.insert(END, valor)
 
 
root =Tk()
a=Calc(master=root)
a.mainloop()
