import cv2
import numpy as np
import math

def nothing(x):
	pass

shorten=0.4	


# cap = cv2.VideoCapture(0)
	

cv2.namedWindow("Trackbars")
cv2.createTrackbar("X","Trackbars",0,255,nothing)
cv2.createTrackbar("Y","Trackbars",0,255,nothing)


a = cv2.imread("solar.jpg",-1)
z = cv2.imread("solar.jpg",-1)
# ret, a = cap.read()
# z=a
a=cv2.resize(a,(int(a.shape[1]*shorten),int(a.shape[0]*shorten)))
z=cv2.resize(z,(int(z.shape[1]*shorten),int(z.shape[0]*shorten)))

temp0=0
temp2=0
temp1=0
min=[256,256,256]
max=[0,0,0]
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
    cv2.imshow('Q to start takinig samples, t to exit taking samples, p to exit code',z)

    # a=z
    temp0=a[y,x,0]
    temp1=a[y,x,1]
    temp2=a[y,x,2]

    if cv2.waitKey(1) & 0xFF == ord('q'):
        print('Hi')
        while True:

            
            # mult1 = cv2.getTrackbarPos("X","Trackbars")
            # mult2 = cv2.getTrackbarPos("Y","Trackbars")

            ###############
            if cv2.waitKey(0) & 0xFF == ord('s'):
                mult2=mult2+2
            elif cv2.waitKey(0) & 0xFF == ord('w'):
                mult2=mult2-2
            elif cv2.waitKey(0) & 0xFF == ord('d'):
                mult1=mult1+2
            elif cv2.waitKey(0) & 0xFF == ord('a'):
                mult1=mult1-2
            elif cv2.waitKey(0) & 0xFF == ord('t'):
                print('f')
                break

            ###############

            scale1=mult1/255
            scale2=mult2/255

            x=int(scale1*a.shape[1])
            y=int(scale2*a.shape[0])

            if temp0!=a[y,x,0] or temp1!=a[y,x,1] or temp2!=a[y,x,2]:
                print(a[y,x,0],a[y,x,1],a[y,x,2])
                if min[0]>a[y,x,0]:
                    min[0]=a[y,x,0]
                if min[1]>a[y,x,1]:
                    min[1]=a[y,x,1]
                if min[2]>a[y,x,2]:
                    min[2]=a[y,x,2]
                if max[0]<a[y,x,0]:
                    max[0]=a[y,x,0]
                if max[1]<a[y,x,1]:
                    max[1]=a[y,x,1]
                if max[2]<a[y,x,2]:
                    max[2]=a[y,x,2]


            z = cv2.circle(z,(x,y), 1, (0,0,255), -1)

            cv2.imshow('Z',z)

            temp0=a[y,x,0]
            temp1=a[y,x,1]
            temp2=a[y,x,2]

            key = cv2.waitKey(1) & 0xFF
            if key==27:
                print('get')
                break


    # key = cv2.waitKey(5) & 0xFF
    # if key==27:
    if cv2.waitKey(2) & 0xFF == ord('p'):
        print('out')
        break

print(min)
print(max)



d=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)

e=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)

f=np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8)

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

        # if (d[i,j]>=0 and d[i,j]<=25) and (f[i,j]>=180 and f[i,j]<=230) and (e[i,j]>=45 and e[i,j]<105):          #green
        # if (d[i,j]>=25 and d[i,j]<=100) and (f[i,j]>=18 and f[i,j]<=75) and (e[i,j]>=60 and e[i,j]<135):          #skincolour
        if (d[i,j]>=min[0]-5 and d[i,j]<=max[0]+5) and (f[i,j]>=min[1]-5 and f[i,j]<=max[1]+5) and (e[i,j]>=min[2]-5 and e[i,j]<=max[2]+5):
            f[i,j]=255
            sample[i,j]=a[i,j]
            arrbx=arrbx+i
            arrby=arrby+j
            countx=countx+1
            county=county+1
        else:
            f[i,j]=0
            sample[i,j]=sm[i,j]


cv2.imshow('sample',sample)

cv2.imshow('f',f)

cv2.waitKey(0)

