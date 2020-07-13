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



for i in range (1,a.shape[0]-1):
    for j in range (1,a.shape[1]-1):

        sample[i,j]=  np.uint8(a[i+1,j])/8  +   a[i,j+1]/8    +   a[i-1,j]/8    +   a[i,j-1]/8    +   a[i+1,j+1]/8  +   a[i-1,j-1]/8    +   a[i+1,j-1]/8  +   a[i-1,j+1]/8

cv2.imshow('sample',sample)

p=3
cnt=0

for i in range (p,a.shape[0]-p):
    for j in range (p,a.shape[1]-p):

        cnt=0        
        for m in range(-p,p):
            for n in range(-p,p):
                if m!=0 or n!=0:
                    sm[i,j]=sm[i,j]+a[i+m,j+n]
                    cnt=cnt+1

        sm[i,j]=sm[i,j]/(cnt)

for j in range (0,a.shape[1]):
    for i in range (0,a.shape[0]):
        sm[i,j]=sm[i,j]*2**8

cv2.imshow('sm',sm)

# for i in range (1,a.shape[0]-1):
#     for j in range (1,a.shape[1]-1):

#         sample[i,j]=  np.uint8(a[i+1,j])/4  +   a[i,j+1]/4    +   a[i-1,j]/4    +   a[i,j-1]/4  #  +   a[i+1,j+1]/4  +   a[i-1,j-1]/4

# cv2.imshow('simple',sample)

w=0

# for i in range (1,a.shape[0]-1):
#     for j in range (1,a.shape[1]-1):

#         sample[i,j]=  (0.5-w/2)*np.uint8(a[i+1,j])  +   (w/2)*a[i,j+1]    +   (0.5-w/2)*a[i-1,j]    +   (w/2)*a[i,j-1]  #  +   a[i+1,j+1,0]/4  +   a[i-1,j-1,0]/4
       

# cv2.imshow('weighted',sample)

w=0.25

# for i in range (1,a.shape[0]-1):
#     for j in range (1,a.shape[1]-1):

#         sample[i,j]=  (2-w*2)*np.uint8(a[i+1,j])/4  +   (w*2)*a[i,j+1]/4    +   (2-w*2)*a[i-1,j]/4    +   (w*2)*a[i,j-1]/4  #  +   a[i+1,j+1,0]/4  +   a[i-1,j-1,0]/4
        

# cv2.imshow('weigh',sample)

w=1

# for i in range (2,a.shape[0]-2):
#     for j in range (2,a.shape[1]-2):

#         sample[i,j]=  (w)*np.uint8(a[i,j+2])/4  +   (w)*a[i,j+1]/4    +   (w)*a[i,j-2]/4    +   (w)*a[i,j-1]/4  #  +   a[i+1,j+1,0]/4  +   a[i-1,j-1,0]/4


# cv2.imshow('weight',sample)


w=1

n=12
for i in range (n,a.shape[0]-n):
    for j in range (n,a.shape[1]-n):
        
        for k in range (-n,n):
            if n!=0:
                green[i,j]=green[i,j]+a[i,j+k]
                ana[i,j]=ana[i,j]+a[i+k,j]
                may[i,j]=may[i,j]+a[i+k,j+k]
 
        green[i,j]=green[i,j]/(2*n)
        ana[i,j]=ana[i,j]/(2*n)
        may[i,j]=may[i,j]/(2*n)            

for j in range (0,a.shape[1]):
    for i in range (0,a.shape[0]):
        green[i,j]=green[i,j]*2**8
        ana[i,j]=ana[i,j]*2**8
        may[i,j]=may[i,j]*2**8


cv2.imshow('Ana',ana)
cv2.imshow('May',may)
cv2.imshow('greenUpdated',green)

cv2.waitKey(0)

