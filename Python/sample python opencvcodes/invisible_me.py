import cv2 #importing module opencv
import numpy as np


#taking an image
cap = cv2.VideoCapture(0)
lower= np.array([0,0,0])
upper=np.array([255,255,35])
a=1

while(True):
    ret, img = cap.read()
    
    if a==1:
       img1 = img
       a=a+1
    #hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
    #gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)


    #ret, thresh1 = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)
    

    cv2.imshow('Video',img)

    mask=cv2.inRange(img, lower, upper)

    onlyimg=cv2.bitwise_or(img1,img1,mask= mask)

    mask2=cv2.bitwise_not(mask)

    maskcolor=cv2.bitwise_or(img,img,mask= mask2)

    final=onlyimg+maskcolor

    cv2.imshow('Video6',final)

    #cv2.imshow('Video7',onlyimg)

    #cv2.imshow('Video5',maskcolor)

    #cv2.imshow('image',img1) 

    k = cv2.waitKey(1)

    if(k==27):
        break
cv2.destroyAllWindows()
cap.release()

