import cv2
import numpy as np


shorten=0.5	

cap = cv2.VideoCapture(0)
	



ret, a = cap.read()
# a = cv2.imread("rgb.jpg",-1)

a=cv2.resize(a,(int(a.shape[1]*shorten),int(a.shape[0]*shorten)))

# scale1=0.7
# scale2=0.5

# x=int(scale1*a.shape[1])
# y=int(scale2*a.shape[0])

# print(a.shape[0],a.shape[1])
# print(x,y)

# print(a[y,x,0],a[y,x,1],a[y,x,2])

# a = cv2.circle(a,(x,y), 1, (0,0,255), -1)




# a = cv2.line(a,(x,y),(x,y),(255,0,0),5)
cv2.imshow('A',a)
d=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
blue=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
e=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
red=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
f=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
green=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)

sm=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)

sample=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint8)

for i in range (0,a.shape[0]):
    for j in range (0,a.shape[1]):
        sm[i,j]=np.uint8(a[i,j,0]/3 +  a[i,j,1]/3 + a[i,j,2]/3)
        d[i,j]=np.uint8(a[i,j,0])

        f[i,j]=np.uint8 (a[i,j,1]) 
        e[i,j]=np.uint8 (a[i,j,2])
        red[i,j]=e[i,j]
        blue[i,j]=d[i,j]
        green[i,j]=f[i,j]



        if f[i,j]>167:#and f[i,j]<204:
            f[i,j]=255
            sample[i,j]=a[i,j]
        else:
            f[i,j]=0
            sample[i,j,0]=sm[i,j]
            sample[i,j,1]=sm[i,j]
            sample[i,j,2]=sm[i,j]

        # if e[i,j]>197 | e[i,j]<107 :
        #     e[i,j]=255
        # else:
        #     e[i,j]=0
        # if d[i,j]>127:
        #     d[i,j]=255
        # else:
        #     d[i,j]=0
        
# cv2.imshow('d',d)
# cv2.imshow('Blue',blue)
# cv2.imshow('e',e)
# cv2.imshow('Red',red)
cv2.imshow('sample',sample)
cv2.imshow('f',f)
# cv2.imshow('Green',green)
# while True:
#     ret, a = cap.read()
#     cv2.imshow('A',a)
#     key = cv2.waitKey(5) & 0xFF
#     if key==27:
# 	    break

cv2.waitKey(0)

