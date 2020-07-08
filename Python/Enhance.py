import cv2
import numpy as np
import math

def nothing(x):
	pass

cap = cv2.VideoCapture(0)
ret, a = cap.read()	
scale=0.4
t=0
w=0
b=cv2.resize(a,(int (a.shape[1]*scale),int (a.shape[0]*scale)))

cv2.namedWindow("Trackbars")
cv2.createTrackbar("A","Trackbars",0,255,nothing)


# c=np.matrix(np.zeros((b.shape[0],b.shape[1])),dtype=np.uint16)

c=np.zeros((b.shape[0],b.shape[1],3),dtype=np.uint16)
for j in range (0,b.shape[1]):
    for i in range (0,b.shape[0]):
        c[i,j,0]=np.uint16(b[i,j,0])
        c[i,j,1]=np.uint16(b[i,j,1])
        c[i,j,2]=np.uint16(b[i,j,2])
        
        c[i,j,0]= (255/math.log(256))*(math.log(int(c[i,j,0])+1))  
              
        c[i,j,1]= (255/math.log(256))*(math.log(int(c[i,j,1])+1))
        
        c[i,j,2]= (255/math.log(256))*(math.log(int(c[i,j,2])+1))



e=np.zeros((b.shape[0],b.shape[1],3),dtype=np.uint16)

for j in range (0,b.shape[1]):
    for i in range (0,b.shape[0]):
        e[i,j,0]=np.uint16(b[i,j,0])
        e[i,j,1]=np.uint16(b[i,j,1])
        e[i,j,2]=np.uint16(b[i,j,2])
        
        e[i,j,0]=e[i,j,0]-e[i,j,0]*0.6

        e[i,j,1]=e[i,j,1]-e[i,j,1]*0.6

        e[i,j,2]=e[i,j,2]-e[i,j,2]*0.6




d=np.zeros((b.shape[0],b.shape[1],3),dtype=np.uint16)


while True:

    mult = cv2.getTrackbarPos("A","Trackbars")

    mult=float(mult/127)

    for j in range (0,b.shape[1]):
        for i in range (0,b.shape[0]):
            d[i,j,0]=np.uint16(b[i,j,0])
            d[i,j,1]=np.uint16(b[i,j,1])
            d[i,j,2]=np.uint16(b[i,j,2])
            
            if (d[i,j,0]+d[i,j,0]*mult)>255:
                d[i,j,0]=255
            else:
                d[i,j,0]=d[i,j,0]+d[i,j,0]*mult

            if (d[i,j,1]+d[i,j,1]*mult)>255:
                d[i,j,1]=255
            else:
                d[i,j,1]=d[i,j,1]+d[i,j,1]*mult

            if (d[i,j,2]+d[i,j,2]*mult)>255:
                d[i,j,2]=255
            else:
                d[i,j,2]=d[i,j,2]+d[i,j,2]*mult

    for j in range (0,b.shape[1]):
        for i in range (0,b.shape[0]):
            d[i,j]=d[i,j]*2**8

    cv2.imshow('brighten',d)

    key = cv2.waitKey(5) & 0xFF
    if key==27:
	    break


for j in range (0,b.shape[1]):
    for i in range (0,b.shape[0]):
        c[i,j]=c[i,j]*2**8



for j in range (0,b.shape[1]):
    for i in range (0,b.shape[0]):
        e[i,j]=e[i,j]*2**8

cv2.imshow('Colour',b)
cv2.imshow('Enhanced',e)
cv2.imshow('brighten',d)
cv2.imshow('morebrighten',c)
cv2.waitKey(0)