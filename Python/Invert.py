import cv2
import numpy as np


shorten=0.4

cap = cv2.VideoCapture(0)

# a = cv2.imread("grn.jpg",-1)
# z = cv2.imread("grn.jpg",-1)

ret, a = cap.read()
z=a
a=cv2.resize(a,(int(a.shape[1]*shorten),int(a.shape[0]*shorten)))
z=cv2.resize(z,(int(z.shape[1]*shorten),int(z.shape[0]*shorten)))

cv2.imshow('A',a)


green=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint16)
ana=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint16)


sm=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint8)

sample=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint8)

print(a.shape[0],a.shape[1])

for i in range (0,a.shape[0]):
    for j in range (0,a.shape[1]):
        sm[a.shape[0]-i-1,j]=a[i,j]

cv2.imshow('ierted',sm)

for i in range (0,a.shape[0]):
    for j in range (0,a.shape[1]):
        sm[i,a.shape[1]-j-1]=a[i,j]

cv2.imshow('inverted',sm)

for i in range (0,a.shape[0]):
    for j in range (0,a.shape[1]):
        sm[i,j]=255-a[i,j]

cv2.imshow('intument',sm)

cv2.waitKey(0)