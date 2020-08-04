import tkinter
from tkinter import *
top = tkinter.Tk()
top.geometry('700x400')
top['background']='#856ff8'

# self.canvas.create_rectangle(230, 10, 290, 60,outline = "black", fill = "blue", width = 2) 
# btn = Button(top, text = 'Simple Calculator using TKinter', bd = '10', command = top.destroy)  
# btn.pack(side = 'top')
res=0

def printtext():
    global res 
    print (res) 
    mystr = StringVar() 
    mystr.set(res) 
    entry = Entry(textvariable=mystr,state=DISABLED).place(x = 140,y = 300)

def sum():
    global input1, input2,res
    res=(int(input1.get())  +  int(input2.get()))

def sub():
    global input1, input2,res
    res=(int(input1.get())   -   int(input2.get()))

def mult():
    global input1, input2,res
    res=(int(input1.get())   *   int(input2.get()))

def div():
    global input1, input2,res
    res=(int(input1.get())   /  int(input2.get()))


# Title 

l = Label(top, text = " * Simple Calculator using TKinter * ") 
l.config(font =("Calibri", 14)) 



# Input Label

user_name = Label(top,bg = 'white', text = "Give First Input :").place(x = 40,y = 60)   
user_password = Label(top,bg = 'white', text = "Give Second Input :").place(x = 40, y = 100)




# Input Widgets

input1 = Entry(top,width = 30)
input1.place(x = 160,y = 60)

input2 = Entry(top,width = 30)
input2.place(x = 160,y = 100)




# Operator buttons

sm = Button(top,text=' + ',bg = 'yellow',command=sum)
sm.place(x = 150,y = 180)

mn = Button(top,text=' - ',bg = 'orange',command=sub)
mn.place(x = 190,y = 180)

ml = Button(top,text=' * ',bg = 'green',command=mult)
ml.place(x = 230,y = 180)

dv = Button(top,text=' / ',bg = 'red',command=div)
dv.place(x = 270,y = 180)






# Final Result button

b = Button(top,text='            =            ',command=printtext)
b.place(x = 300,y = 250)

Output = Label(top,bg = 'white', text = "Output : ").place(x = 40,y = 300)   

mystr = StringVar() 
mystr.set('0') 
entry = Entry(textvariable=mystr,state=DISABLED).place(x = 140,y = 300)

l.pack()
top.mainloop()