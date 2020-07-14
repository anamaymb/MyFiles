import cv2
import numpy as np
import math

def nothing(x):
	pass

shorten=0.4

cap = cv2.VideoCapture(0)

# a = cv2.imread("grn.jpg",-1)
# z = cv2.imread("grn.jpg",-1)

ret, a = cap.read()

a=cv2.resize(a,(int(a.shape[1]*shorten),int(a.shape[0]*shorten)))

cv2.imshow('A',a)

sm=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint16)


matrix=[[1, 1, 1, 1, 1, 1, 1], 
        [1, 2, 2, 2, 2, 2, 1], 
        [1, 2, 4, 4, 4, 2, 1], 
        [1, 2, 4, 8, 4, 2, 1], 
        [1, 2, 4, 4, 4, 2, 1], 
        [1, 2, 2, 2, 2, 2, 1], 
        [1, 1, 1, 1, 1, 1, 1]]

p=3
s=0
grt=0
for i in range (0,7):
    for j in range (0,7):
        s=s+matrix[i][j]


for i in range (p,a.shape[0]-p):
    for j in range (p,a.shape[1]-p):
      
        for m in range(-p,p+1):
            for n in range(-p,p+1):
                sm[i,j,0]=sm[i,j,0]+a[i+m,j+n,0]*matrix[m+3][n+3]
                sm[i,j,1]=sm[i,j,1]+a[i+m,j+n,1]*matrix[m+3][n+3]
                sm[i,j,2]=sm[i,j,2]+a[i+m,j+n,2]*matrix[m+3][n+3]

        sm[i,j]=sm[i,j]/(s)
        if grt<sm[i,j,0]:
            grt=sm[i,j,0]

print(grt)

for j in range (0,a.shape[1]):
    for i in range (0,a.shape[0]):
        sm[i,j]=sm[i,j]*2**8

cv2.imshow('sm',sm)

cv2.waitKey(0)