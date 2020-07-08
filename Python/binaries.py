import cv2
import numpy as np

cap = cv2.VideoCapture(0)
	
ret, a = cap.read()
cv2.imshow('A',a)



d=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
e=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
f=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)

for i in range (0,a.shape[0]):
    for j in range (0,a.shape[1]):
        d[i,j]=np.uint8(a[i,j,0]/3 +  a[i,j,1]/3 + a[i,j,2]/3)
        
        if d[i,j]>64:
            f[i,j]=255
        else:
            f[i,j]=0
        if d[i,j]>191:
            e[i,j]=255
        else:
            e[i,j]=0
        if d[i,j]>127:
            d[i,j]=255
        else:
            d[i,j]=0
        
cv2.imshow('D',d)
cv2.imshow('E',e)
cv2.imshow('F',f)

# while True:
#     ret, a = cap.read()
#     cv2.imshow('A',a)
#     key = cv2.waitKey(5) & 0xFF
#     if key==27:
# 	    break

cv2.waitKey(0)

