import cv2
import numpy as np
import math

cap = cv2.VideoCapture(0)
ret, a = cap.read()	
scale=0.4
t=0
w=0
b=cv2.resize(a,(int (a.shape[1]*scale),int (a.shape[0]*scale)))

# c=np.matrix(np.zeros((b.shape[0],b.shape[1])),dtype=np.uint16)
c=np.zeros((b.shape[0],b.shape[1],3),dtype=np.uint16)
for j in range (0,b.shape[1]):
    for i in range (0,b.shape[0]):
        c[i,j,0]=np.uint16(b[i,j,0])
        c[i,j,1]=np.uint16(b[i,j,1])
        c[i,j,2]=np.uint16(b[i,j,2])
        # w=c[i,j]
        # t=float(w*1.1)
        # if c[i,j,0]+20>255:
        #     c[i,j,0]=255
        # else:
        #     c[i,j,0]=c[i,j,0]+20

        # if c[i,j,1]+20>255:
        #     c[i,j,1]=255
        # else:
        #     c[i,j,1]=c[i,j,1]+20

        # if c[i,j,1]+20>255:
        #     c[i,j,1]=255
        # else:
        #     c[i,j,1]=c[i,j,1]+20

        # if int(c[i,j,0]) != 0:
        c[i,j,0]= (255/math.log(256))*(math.log(int(c[i,j,0])+1))  
            # 104*(math.log(int(c[i,j,0])))+2
        # if int(c[i,j,1]) != 0:    
        c[i,j,1]= (255/math.log(256))*(math.log(int(c[i,j,1])+1))
        # if int(c[i,j,2]) != 0:
        c[i,j,2]= (255/math.log(256))*(math.log(int(c[i,j,2])+1))

        # if c[i,j,0]>255:
        #     c[i,j,0]=255
        # if c[i,j,1]>255:
        #     c[i,j,1]=255
        # if c[i,j,2]>255:
        #     c[i,j,2]=255


        # print(c[i,j,2])

        # print(math.log(0))
        # if int(c[i,j,0]) != 0:
        #     print(math.log(int(c[i,j,0])))


d=np.zeros((b.shape[0],b.shape[1],3),dtype=np.uint16)

for j in range (0,b.shape[1]):
    for i in range (0,b.shape[0]):
        d[i,j,0]=np.uint16(b[i,j,0])
        d[i,j,1]=np.uint16(b[i,j,1])
        d[i,j,2]=np.uint16(b[i,j,2])
        # w=c[i,j]
        # t=float(w*1.1)
        if (d[i,j,0]+d[i,j,0]*1.6)>255:
            d[i,j,0]=255
        else:
            d[i,j,0]=d[i,j,0]+d[i,j,0]*1.6

        if (d[i,j,1]+d[i,j,1]*1.6)>255:
            d[i,j,1]=255
        else:
            d[i,j,1]=d[i,j,1]+d[i,j,1]*1.6

        if (d[i,j,2]+d[i,j,2]*1.6)>255:
            d[i,j,2]=255
        else:
            d[i,j,2]=d[i,j,2]+d[i,j,2]*1.6




e=np.zeros((b.shape[0],b.shape[1],3),dtype=np.uint16)

for j in range (0,b.shape[1]):
    for i in range (0,b.shape[0]):
        e[i,j,0]=np.uint16(b[i,j,0])
        e[i,j,1]=np.uint16(b[i,j,1])
        e[i,j,2]=np.uint16(b[i,j,2])
        # w=c[i,j]
        # t=float(w*1.1)
        # if (e[i,j,0]+e[i,j,0]*0.4)>255:
        #     e[i,j,0]=255
        # else:
        e[i,j,0]=e[i,j,0]-e[i,j,0]*0.6

        # if (e[i,j,1]+e[i,j,1]*0.4)>255:
        #     e[i,j,1]=255
        # else:
        e[i,j,1]=e[i,j,1]-e[i,j,1]*0.6

        # if (e[i,j,2]+e[i,j,2]*0.4)>255:
        #     e[i,j,2]=255
        # else:
        e[i,j,2]=e[i,j,2]-e[i,j,2]*0.6


for j in range (0,b.shape[1]):
    for i in range (0,b.shape[0]):
        c[i,j]=c[i,j]*2**8

for j in range (0,b.shape[1]):
    for i in range (0,b.shape[0]):
        d[i,j]=d[i,j]*2**8

for j in range (0,b.shape[1]):
    for i in range (0,b.shape[0]):
        e[i,j]=e[i,j]*2**8

cv2.imshow('Colour',b)
cv2.imshow('Enhanced',e)
cv2.imshow('brighten',d)
cv2.imshow('morebrighten',c)
cv2.waitKey(0)