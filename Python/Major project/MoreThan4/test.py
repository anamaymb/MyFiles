

# print (moreThan4.flag)

import cv2
import tkinter
from tkinter import *
top = tkinter.Tk()
top.geometry('900x600')
top.title("LIFT")
top['background']='#333333'


face_cascade=cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

eye_cascade=cv2.CascadeClassifier('haarcascade_eye.xml')



prevf=0
flag=0

lbl2 = Label(top, text="5", bg='#333333', fg="white", font=("Monotype Corsiva",199), anchor=CENTER,height=1, width=4)

lbl1 = Label(top, text = " You have selected Floor No. ",font =("Monotype Corsiva", 59),height=2,background='#333333',foreground='#AAAAAA') 

lbl3 = Label(top, text = " Please \nWear \na mask ..!!  \U0001F637",font =("Monotype Corsiva", 109),background='#333333',foreground='#AAAAAA') 

lbl4 = Label(top, text = " Please \nStep Out \nof Lift ..!!",font =("Monotype Corsiva", 109),background='#333333',foreground='#AAAAAA') 

lbl5 = Label(top, text = " Not more than 4 people \n allowed..!! \n Please Step Out \nof Lift ..!!",font =("Monotype Corsiva", 79),background='#333333',foreground='#AAAAAA') 

l = Label(top, text = " Welcome \nto \nLift ",font =("Monotype Corsiva", 109),background='#333333',foreground='#AAAAAA') 

def lebelPack():
    global lbl1,lbl2,lbl3,lbl4,l

def all_children (top) :
    _list = top.winfo_children()

    for item in _list :
        if item.winfo_children() :
            _list.extend(item.winfo_children())

    return _list

def forget():
    widget_list = all_children(top)
    for item in widget_list:
        item.pack_forget()

def flr():
    forget()
    lebelPack()

    lbl1.pack()
    lbl2.pack()

def maskWarning():
    forget()
    lebelPack()

    lbl3.pack()

def tempWarning():
    forget()
    lebelPack()

    lbl4.pack()

def morePeopleWarning():
    forget()
    lebelPack()

    lbl5.pack()

def messege():
    forget()
    lebelPack()

    l.pack()

messege()

# top.after(2000, flr)
# top.after(4000, maskWarning)
# top.after(6000, morePeopleWarning)
flag=0
# cap = cv2.VideoCapture(0)
def my_mainloop():
    print ("Hello World!")
    
    # top.after(1000, flr)
    # top.after(2000, maskWarning)
    # top.after(3000, morePeopleWarning)
   
     moreThan4
    if moreThan4.flag==0:
        flr()
    if moreThan4.flag==1:
        morePeopleWarning()
    k = cv2.waitKey(1)

    if(k==27):
        return

    top.after(1, my_mainloop)    

# cv2.destroyAllWindows()
# cap.release()
top.after(1, my_mainloop)

# while True:


top.mainloop()