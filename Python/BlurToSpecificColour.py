import cv2
import numpy as np

def nothing(x):
	pass

shorten=0.3

cap = cv2.VideoCapture(0)
	
cv2.namedWindow("Trackbars")
cv2.createTrackbar("X","Trackbars",0,255,nothing)
cv2.createTrackbar("Y","Trackbars",0,255,nothing)

# a = cv2.imread("solar.jpg",-1)
# z = cv2.imread("solar.jpg",-1)

ret, a = cap.read()
z=a
a=cv2.resize(a,(int(a.shape[1]*shorten),int(a.shape[0]*shorten)))
z=cv2.resize(z,(int(z.shape[1]*shorten),int(z.shape[0]*shorten)))

temp0=0
temp2=0
temp1=0
while True:

    mult1 = cv2.getTrackbarPos("X","Trackbars")
    mult2 = cv2.getTrackbarPos("Y","Trackbars")

    scale1=mult1/255
    scale2=mult2/255

    x=int(scale1*a.shape[1])
    y=int(scale2*a.shape[0])

    if temp0!=a[y,x,0] or temp1!=a[y,x,1] or temp2!=a[y,x,2]:
        print(a[y,x,0],a[y,x,1],a[y,x,2])

    z = cv2.circle(z,(x,y), 1, (0,0,255), -1)

    cv2.imshow('Z',z)

    temp0=a[y,x,0]
    temp1=a[y,x,1]
    temp2=a[y,x,2]

    key = cv2.waitKey(5) & 0xFF
    if key==27:
	    break



d=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
blue=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
e=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
red=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
f=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
green=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint16)

sm=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint16)

sample=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint16)



for i in range (12,a.shape[0]-12):
    for j in range (12,a.shape[1]-12):

        d[i,j]=np.uint8(a[i,j,0])
        f[i,j]=np.uint8 (a[i,j,1]) 
        e[i,j]=np.uint8 (a[i,j,2])

        if (d[i,j]>=5 and d[i,j]<=66) and (f[i,j]>=20 and f[i,j]<=120) and (e[i,j]>=50 and e[i,j]<=170):
        # if (d[i,j]>=0 and d[i,j]<=50) and (f[i,j]>=0 and f[i,j]<=50) and (e[i,j]>=0 and e[i,j]<50):            #Black
        # if (d[i,j]>=0 and d[i,j]<=80) and (f[i,j]>=80 and f[i,j]<=246) and (e[i,j]>=0 and e[i,j]<=90):              #green
            d[i,j]=255

        else:
            d[i,j]=0

cv2.imshow('d before',d)

p=5
cnt=0

for i in range (p,a.shape[0]-p):
    for j in range (p,a.shape[1]-p):

        cnt=0        
        for m in range(-p,p):
            for n in range(-p,p):
                if m!=0 or n!=0:
                    sample[i,j]=sample[i,j]+d[i+m,j+n]
                    cnt=cnt+1

        sample[i,j]=sample[i,j]/(cnt) 

for i in range (12,a.shape[0]-12):
    for j in range (12,a.shape[1]-12):
        if sample[i,j,0]!=0:
            n=12
                    
            # for k in range (-n,n):
            #     if n!=0:
            #         green[i,j]=green[i,j]+a[i,j+k]
            # green[i,j]=green[i,j]/(2*n)
            
            p=5
            cnt=0        
            for m in range(-p,p):
                for n in range(-p,p):
                    if m!=0 or n!=0:
                        green[i,j]=green[i,j]+a[i+m,j+n]
                        cnt=cnt+1

            green[i,j]=green[i,j]/(cnt)
        else:
            green[i,j]=a[i,j]

for j in range (0,a.shape[1]):
    for i in range (0,a.shape[0]):
        
        green[i,j]=green[i,j]*2**8
        sample[i,j]=sample[i,j]*2**8

cv2.imshow('Green',green)
cv2.imshow('sample',sample)



while True:

    mult1 = cv2.getTrackbarPos("X","Trackbars")
    mult2 = cv2.getTrackbarPos("Y","Trackbars")

    scale1=mult1/255
    scale2=mult2/255

    x=int(scale1*a.shape[1])
    y=int(scale2*a.shape[0])

    if temp0!=a[y,x,0] or temp1!=a[y,x,1] or temp2!=a[y,x,2]:
        print(a[y,x,0],a[y,x,1],a[y,x,2])

    z = cv2.circle(z,(x,y), 1, (0,0,255), -1)

    cv2.imshow('Y',z)

    temp0=a[y,x,0]
    temp1=a[y,x,1]
    temp2=a[y,x,2]

    key = cv2.waitKey(5) & 0xFF
    if key==27:
	    break




cv2.waitKey(0)

