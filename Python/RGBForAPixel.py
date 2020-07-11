import cv2
import numpy as np

def nothing(x):
	pass

shorten=0.4
	
cv2.namedWindow("Trackbars")
cv2.createTrackbar("X","Trackbars",0,255,nothing)
cv2.createTrackbar("Y","Trackbars",0,255,nothing)


a = cv2.imread("solar.jpg",-1)
z = cv2.imread("solar.jpg",-1)
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

    # cv2.imshow('A',a)
    cv2.imshow('Z',z)

    temp0=a[y,x,0]
    temp1=a[y,x,1]
    temp2=a[y,x,2]

    key = cv2.waitKey(5) & 0xFF
    if key==27:
	    break



