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
z=a
a=cv2.resize(a,(int(a.shape[1]*shorten),int(a.shape[0]*shorten)))
z=cv2.resize(z,(int(z.shape[1]*shorten),int(z.shape[0]*shorten)))

cv2.imshow('A',a)


green=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint16)
ana=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint16)
may=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint16)

sm=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint16)

sample=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint8)



# for i in range (1,a.shape[0]-1):
#     for j in range (1,a.shape[1]-1):

#         sample[i,j]=  np.uint8(a[i+1,j])/8  +   a[i,j+1]/8    +   a[i-1,j]/8    +   a[i,j-1]/8    +   a[i+1,j+1]/8  +   a[i-1,j-1]/8    +   a[i+1,j-1]/8  +   a[i-1,j+1]/8

# cv2.imshow('sample',sample)


matrix=[[0, 0, 0, 0, 0, 0, 0], 
        [0, 0, 0, 0, 0, 0, 0], 
        [0, 0, 0, 0, 0, 0, 0], 
        [2, 2, 2, 2, 2, 2, 2], 
        [0, 0, 0, 0, 0, 0, 0], 
        [0, 0, 0, 0, 0, 0, 0], 
        [0, 0, 0, 0, 0, 0, 0]]


# matrix=[[0, 0, 0, 0, 0, 0, 0], 
#         [0, 0, 0, 0, 0, 0, 0], 
#         [0, 0, 0, 0, 0, 0, 0], 
#         [1, 1, 1, 0, 1, 1, 1], 
#         [0, 0, 0, 0, 0, 0, 0], 
#         [0, 0, 0, 0, 0, 0, 0], 
#         [0, 0, 0, 0, 0, 0, 0]]

# matrix=[[1, 0, 0, 0, 0, 0, 0], 
#         [0, 1, 0, 0, 0, 0, 0], 
#         [0, 0, 1, 0, 0, 0, 0], 
#         [0, 0, 0, 0, 0, 0, 0], 
#         [0, 0, 0, 0, 1, 0, 0], 
#         [0, 0, 0, 0, 0, 1, 0], 
#         [0, 0, 0, 0, 0, 0, 1]]

# matrix=[[1, 1, 1, 1, 1, 1, 1], 
#         [1, 2, 2, 2, 2, 2, 1], 
#         [1, 2, 4, 4, 4, 2, 1], 
#         [1, 2, 4, 8, 4, 2, 1], 
#         [1, 2, 4, 4, 4, 2, 1], 
#         [1, 2, 2, 2, 2, 2, 1], 
#         [1, 1, 1, 1, 1, 1, 1]]

p=3
s=0
grt=0
for i in range (0,7):
    for j in range (0,7):
        s=s+matrix[i][j]

print(s)

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