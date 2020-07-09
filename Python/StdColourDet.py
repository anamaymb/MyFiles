import cv2
import numpy as np


shorten=0.3	

a = cv2.imread("solar.jpg",-1)
z = cv2.imread("solar.jpg",-1)
a=cv2.resize(a,(int(a.shape[1]*shorten),int(a.shape[0]*shorten)))
z=cv2.resize(z,(int(z.shape[1]*shorten),int(z.shape[0]*shorten)))


cv2.imshow('A',a)


d=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
blue=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
e=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
red=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
f=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
green=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint8)

sm=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)

sample=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint8)

for i in range (0,a.shape[0]):
    for j in range (0,a.shape[1]):
        sm[i,j]=np.uint8(a[i,j,0]/3 +  a[i,j,1]/3 + a[i,j,2]/3)

        d[i,j]=np.uint8(a[i,j,0])
        f[i,j]=np.uint8 (a[i,j,1]) 
        e[i,j]=np.uint8 (a[i,j,2])

        if (d[i,j]>=147 and d[i,j]<=208) and (f[i,j]>83 and f[i,j]<=164) and (e[i,j]>=56 and e[i,j]<134):
            f[i,j]=255
            sample[i,j]=a[i,j]
        else:
            f[i,j]=0
            sample[i,j,0]=sm[i,j]
            sample[i,j,1]=sm[i,j]
            sample[i,j,2]=sm[i,j]

cv2.imshow('f',f)

for i in range (0,a.shape[0]):
    for j in range (0,a.shape[1]):
        sm[i,j]=np.uint8(a[i,j,0]/3 +  a[i,j,1]/3 + a[i,j,2]/3)

        d[i,j]=np.uint8(a[i,j,0])
        f[i,j]=np.uint8 (a[i,j,1]) 
        e[i,j]=np.uint8 (a[i,j,2])

        if (d[i,j]>=0 and d[i,j]<=119) and (f[i,j]>83 and f[i,j]<=138) and (e[i,j]>=56 and e[i,j]<114):
            d[i,j]=255
            green[i,j]=a[i,j]
        else:
            d[i,j]=0
            green[i,j,0]=sm[i,j]
            green[i,j,1]=sm[i,j]
            green[i,j,2]=sm[i,j]

        
cv2.imshow('d',d)

cv2.imshow('sample',sample)

cv2.imshow('Green',green)


cv2.waitKey(0)

