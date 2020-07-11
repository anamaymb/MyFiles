import cv2
import numpy as np
import math

def nothing(x):
	pass

shorten=0.4	

cap = cv2.VideoCapture(0)
	
cv2.namedWindow("Trackbars")
cv2.createTrackbar("X","Trackbars",0,255,nothing)
cv2.createTrackbar("Y","Trackbars",0,255,nothing)

# a = cv2.imread("grn.jpg",-1)
# z = cv2.imread("grn.jpg",-1)

ret, a = cap.read()
z=a
a=cv2.resize(a,(int(a.shape[1]*shorten),int(a.shape[0]*shorten)))
z=cv2.resize(z,(int(z.shape[1]*shorten),int(z.shape[0]*shorten)))

temp0=0
temp2=0
temp1=0


d=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
blue=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
e=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
red=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
f=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)
green=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint8)

sm=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)

sample=np.zeros((a.shape[0],a.shape[1],3),dtype=np.uint8)



countx=0
county=0
arrbx=0
arrby=0

for i in range (0,a.shape[0]):
    for j in range (0,a.shape[1]):
        sm[i,j]=np.uint8(a[i,j,0]/3 +  a[i,j,1]/3 + a[i,j,2]/3)

        d[i,j]=np.uint8(a[i,j,0])
        f[i,j]=np.uint8 (a[i,j,1]) 
        e[i,j]=np.uint8 (a[i,j,2])

        if (d[i,j]>=160 and d[i,j]<=255) and (f[i,j]>20 and f[i,j]<=125) and (e[i,j]>=0 and e[i,j]<15):
            f[i,j]=255
            sample[i,j]=a[i,j]
            arrbx=arrbx+i
            arrby=arrby+j
            countx=countx+1
            county=county+1
        else:
            f[i,j]=0
            sample[i,j,0]=sm[i,j]
            sample[i,j,1]=sm[i,j]
            sample[i,j,2]=sm[i,j]

print(arrbx/countx,arrby/county)

sample = cv2.circle(sample,(int(arrby/county),int(arrbx/countx)), 10, (0,255,0), 3)

bx=int(arrbx/countx)
by=int(arrby/county)

cv2.imshow('sample',sample)

cv2.imshow('f',f)
countx=0
county=0
arrx=0
arry=0

for i in range (0,a.shape[0]):
    for j in range (0,a.shape[1]):
        sm[i,j]=np.uint8(a[i,j,0]/3 +  a[i,j,1]/3 + a[i,j,2]/3)

        d[i,j]=np.uint8(a[i,j,0])
        f[i,j]=np.uint8 (a[i,j,1]) 
        e[i,j]=np.uint8 (a[i,j,2])

        if (d[i,j]>=0 and d[i,j]<=80) and (f[i,j]>=80 and f[i,j]<=246) and (e[i,j]>=0 and e[i,j]<=90):
            d[i,j]=255
            green[i,j]=a[i,j]
            arrx=arrx+i
            arry=arry+j
            countx=countx+1
            county=county+1

        else:
            d[i,j]=0
            green[i,j,0]=sm[i,j]
            green[i,j,1]=sm[i,j]
            green[i,j,2]=sm[i,j]

print(arrx/countx,arry/county)

green = cv2.circle(green,(by,bx), 10, (0,255,0), 3)
green = cv2.circle(green,(int(arry/county),int(arrx/countx)), 10, (0,0,255), 3)
green = cv2.line(green, (int(arry/county),int(arrx/countx)), (by,bx), (0,0,0), 3)


angle=math.degrees(math.atan(((by-int(arry/county))/(bx-int(arrx/countx)))))

print(by-int(arry/county),bx-int(arrx/countx))

print((by-int(arry/county))/(bx-int(arrx/countx)))

print(angle)

cv2.imshow('d',d)
cv2.imshow('Green',green)


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

