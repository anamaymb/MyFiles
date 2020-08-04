import tkinter
from tkinter import *
top = tkinter.Tk()
top.geometry('700x400')
top['background']='#856ff8'
flag=0



# Function Definitions for the dropbox

def dist():
    global flag
    flag=1
    mystr1 = StringVar() 
    mystr1.set('Centimeter') 
    entry1 = Entry(textvariable=mystr1,state=DISABLED).place(x = 150,y = 60)

def wt():
    global flag
    flag=1
    mystr1 = StringVar() 
    mystr1.set('Grams') 
    entry1 = Entry(textvariable=mystr1,state=DISABLED).place(x = 150,y = 60)

def temp():
    global flag
    flag=3
    mystr1 = StringVar() 
    mystr1.set('Celsius') 
    entry1 = Entry(textvariable=mystr1,state=DISABLED).place(x = 150,y = 60)


def dist1():
    mystr2 = StringVar() 
    mystr2.set('Meter') 
    entry2 = Entry(textvariable=mystr2,state=DISABLED).place(x = 550,y = 60)

def wt1():
    mystr2 = StringVar() 
    mystr2.set('Kilorams') 
    entry2 = Entry(textvariable=mystr2,state=DISABLED).place(x = 550,y = 60)

def temp1():
    mystr2 = StringVar() 
    mystr2.set('Fahreniet') 
    entry2 = Entry(textvariable=mystr2,state=DISABLED).place(x =550,y = 60)

def cnt():
    global input,res
    mystr3 = StringVar() 
    if flag==1:
        res=int(input.get())/1000
    if flag==3:
        res=int(input.get())*9/5+32
    mystr3.set(res) 
    entry3 = Entry(textvariable=mystr3,state=DISABLED).place(x =500,y = 260)




# Title

l = Label(top, text = " * Units Converter using TKinter * ") 
l.config(font =("Calibri", 14)) 



# Setting for the first dropbox (COnvert from)

menubutton1 = Menubutton(top, text = "Convert From")    
menubutton1.menu = Menu(menubutton1)   
menubutton1["menu"]= menubutton1.menu   
  
menubutton1.menu.add_checkbutton(label = "Centimeter",command=dist)   
menubutton1.menu.add_checkbutton(label = "Grams",command=wt) 
menubutton1.menu.add_checkbutton(label = "Celsius",command=temp) 



# Setting for the first dropbox (Convert to)

menubutton2 = Menubutton(top, text = "Convert To")    
menubutton2.menu = Menu(menubutton2)   
menubutton2["menu"]= menubutton2.menu   
  
menubutton2.menu.add_checkbutton(label = "Meter",command=dist1)   
menubutton2.menu.add_checkbutton(label = "KiloGrams",command=wt1) 
menubutton2.menu.add_checkbutton(label = "Fahreniet",command=temp1) 





# Selction widgets

mystr1 = StringVar() 
mystr1.set('-Select-') 
entry1 = Entry(textvariable=mystr1,state=DISABLED).place(x = 150,y = 60)

mystr2 = StringVar() 
mystr2.set('-Select-') 
entry2 = Entry(textvariable=mystr2,state=DISABLED).place(x = 550,y = 60)


# Placing the widgets

menubutton1.place(x = 50,y = 60) 
menubutton2.place(x = 450,y = 60) 


# Input Widget

input = Entry(top,width = 20)
input.place(x = 60,y = 260)


# Final Output Widget

mystr3 = StringVar() 
mystr3.set('0') 
entry3 = Entry(textvariable=mystr3,state=DISABLED).place(x = 500,y = 260)



# Convert Button
cnvt = Button(top,text=' Convert ',bg = 'yellow',command=cnt)
cnvt.place(x = 300,y = 260)

l.pack()
top.mainloop()