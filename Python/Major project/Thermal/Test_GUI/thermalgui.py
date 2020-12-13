import numpy as np
import cv2
import tkinter
from tkinter import *
top = tkinter.Tk()
top.geometry('900x600')
top.title("LIFT")
top['background']='#333333'

import sys





lbl2 = Label(top, text="5", bg='#333333', fg="white", font=("Monotype Corsiva",199), anchor=CENTER,height=1, width=4)

lbl1 = Label(top, text = " You have selected Floor No. ",font =("Monotype Corsiva", 59),height=2,background='#333333',foreground='#AAAAAA') 

lbl3 = Label(top, text = " Please \nWear \na mask ..!!  \U0001F637",font =("Monotype Corsiva", 109),background='#333333',foreground='#AAAAAA') 

lbl4 = Label(top, text = " Please \nStep Out \nof Lift ..!!",font =("Monotype Corsiva", 109),background='#333333',foreground='#AAAAAA') 

lbl5 = Label(top, text = " Not more than 2 people \n allowed..!! \n Please Step Out \nof Lift ..!!",font =("Monotype Corsiva", 79),background='#333333',foreground='#AAAAAA') 

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


def tempWarning():
    forget()
    lebelPack()
    lbl4.pack()

def messege():
    forget()
    lebelPack()
    l.pack()







face_cascade = cv2.CascadeClassifier('cascade.xml')

img = cv2.imread('D:/GITHUB/MyFiles-master/Python/Major project/Thermal/RGB_thermal/thermal_13.jpg')

img = cv2.resize(img, (500, 500))

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

faces = face_cascade.detectMultiScale(gray,1.01,7)
flag=0
for (x,y,w,h) in faces:
    img_dect = cv2.rectangle(img,(x,y),(x+int(1.4*w),y+int(1.4*h)),(0,200,0),3)
    if x>=0:
        flag=1

cv2.imshow('img',img)

if flag==1:
    crop_img = img[y:y+int(1.4*h), x:x+int(1.4*w)]
    # cv2.imshow("cropped", crop_img)

if flag==0:
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    sys.exit("No face detected")

# crop_img=cv2.cvtColor(crop_img, cv2.COLOR_BGR2RGB)

lower = np.array([0,0,170])
higher=np.array([35,35,255])
mask=cv2.inRange(crop_img,lower,higher)


cont,_=cv2.findContours(mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)
cont_img=cv2.drawContours(crop_img,cont,-1,100,3)

flag=0

for cnt in cont:

    x,y,w,h=cv2.boundingRect(cnt)
    if w>30:
        print(w,h)
        cv2.rectangle(crop_img,(x,y),(x+w,y+h),(255,255,255),3)
        flag=1

if flag==1:
    tempWarning()
else:
    messege()

cv2.imshow('mask',crop_img)

top.mainloop()

cv2.waitKey(0)
cv2.destroyAllWindows()
