import cv2
import numpy as np
import math

# def nothing(x):
# 	pass

shorten=0.4	

cap = cv2.VideoCapture(0)
ret, a = cap.read()
z=a
# a=cv2.resize(a,(int(a.shape[1]*shorten),int(a.shape[0]*shorten)))
z=cv2.resize(z,(int(z.shape[1]*shorten),int(z.shape[0]*shorten)))

# print(z.shape)
# cv2.namedWindow("Trackbars")
# cv2.createTrackbar("X","Trackbars",0,255,nothing)
# cv2.createTrackbar("Y","Trackbars",0,255,nothing)



flag=0
flag1=0
flag2=0
flag3=0
i=0

mult1=127               # initial position  (x)
mult2=127               # (y)

speed=5.5               # Speed of Piece
brk=0.05                # Friction
m=1.7                   # slope (magnitude)
an=-1                   # slope (direction) (inital) (+ve/-ve)


h=(mult2/255)-an*m*(mult1/255)          # y-intercept


tog=speed

while True:
    if speed>0 :
        if tog>0:
            speed=speed-brk
            tog=speed
        elif tog<0:
            speed=speed-brk
            tog=-speed
    else:
        tog=0
    ret, a = cap.read()
    a=cv2.resize(a,(int(a.shape[0]*1.2),int(a.shape[0]*1.2)))

    # cv2.imshow('insidem',sm)
    # mult1 = cv2.getTrackbarPos("X","Trackbars")
    # mult2 = cv2.getTrackbarPos("Y","Trackbars")

    if mult1>=255:
        tog=-speed
    elif mult1<=0:
        tog=speed
        if an==1:
            an=-1
        elif an==-1:
            an=1
    mult1=mult1+tog
    scale1=mult1/255
    # m=1

    if mult2>5:
        flag=0
    if mult1<250:
        flag3=0

    if mult2>=255 and an==1 and tog>0:
        h=scale1*m+1
        # print('scale2')
        an=-1

    elif mult2>=255 and an==-1 and tog<0:
        # print('k')
        flag=0
        h=1-m*scale1
        print(scale2)
        an=1
    
    if mult1>=255 and flag3==0:
        print('hi')
        if an==-1:
            # print('belekar')
            an=1
            h=scale2-m
        elif an==1:
            # print('anaamay')
            an=-1
            h=scale2+m
        flag3=1

    if mult2<0 and flag==0:
        # print('b',i)
        # print('mult22222',mult2)
        if tog<0:
            an=-1
            h=m*scale1
        elif tog>0:
            an=1
            h=-m*scale1
        flag=1
        

    elif mult2<=0 and tog>0 and flag2==0:
        # print('z')
        an=1
        flag2=1
        h=-m*scale1
        
    
    scale2=mult2/255

    x=int(scale1*a.shape[1])
    y=int(scale2*a.shape[0])

    

    z = cv2.circle(a,(x,y), 8, (255,255,255), -1)
    # z = cv2.rectangle(z, (0,0), (z.shape[0],z.shape[0]), (155,255,255),-1)
    z = cv2.circle(a,(x,y), 8, (255,255,255), -1)
    z = cv2.circle(z,(x,y), 5, (255,0,0), -1)
    
    z = cv2.rectangle(z, (75,55), (500,70), (0,255,0),1)
    z = cv2.rectangle(z, (75,505), (500,520), (0,255,0),1)
    
    z = cv2.circle(z,(75,62), 8, (0,0,255), -1)
    z = cv2.circle(z,(500,62), 8, (0,0,255), -1)
    z = cv2.circle(z,(500,512), 8, (0,0,255), -1)
    z = cv2.circle(z,(75,512), 8, (0,0,255), -1)


    z = cv2.rectangle(z, (55,75), (70,500), (0,255,0),1)
    z = cv2.rectangle(z, (505,75), (520,500), (0,255,0),1)

    z = cv2.circle(z,(62,75), 8, (0,0,255), -1)
    z = cv2.circle(z,(62,500), 8, (0,0,255), -1)
    z = cv2.circle(z,(512,500), 8, (0,0,255), -1)
    z = cv2.circle(z,(512,75), 8, (0,0,255), -1)


    z = cv2.circle(z,(0,0), 18, (0,0,255), -1)
    z = cv2.circle(z,(0,z.shape[0]), 18, (0,0,255), -1)
    z = cv2.circle(z,(z.shape[0],0), 18, (0,0,255), -1)
    z = cv2.circle(z,(z.shape[0],z.shape[0]), 18, (0,0,255), -1)

    z = cv2.line(z, (35,35), (170,170), (0,255,0),1)
    z = cv2.line(z, (z.shape[0]-35,35), (z.shape[0]-170,170), (0,255,0),1)    
    z = cv2.line(z, (35,z.shape[0]-35), (170,z.shape[0]-170), (0,255,0),1)
    z = cv2.line(z, (z.shape[0]-35,z.shape[0]-35), (z.shape[0]-170,z.shape[0]-170), (0,255,0),1)



    z = cv2.line(z, (int(z.shape[0]/2-48),int(z.shape[0]/2)), (int(z.shape[0]/2+48),int(z.shape[0]/2)), (0,0,255),1)
    z = cv2.line(z, (int(z.shape[0]/2),int(z.shape[0]/2-48)), (int(z.shape[0]/2),int(z.shape[0]/2+48)), (0,0,255),1)
    z = cv2.line(z, (int(z.shape[0]/2-34),int(z.shape[0]/2-34)), (int(z.shape[0]/2+34),int(z.shape[0]/2+34)), (0,0,0),1)
    z = cv2.line(z, (int(z.shape[0]/2+34),int(z.shape[0]/2-34)), (int(z.shape[0]/2-34),int(z.shape[0]/2+34)), (0,0,0),1)

    z = cv2.circle(z,(170,170), 18, (0,255,255), 1)
    z = cv2.circle(z,(z.shape[0]-170,170), 18, (0,255,255), 1)
    z = cv2.circle(z,(170,z.shape[0]-170), 18, (0,255,255), 1)
    z = cv2.circle(z,(z.shape[0]-170,z.shape[0]-170), 18, (0,255,255), 1)
    z = cv2.circle(z,(int(z.shape[0]/2),int(z.shape[0]/2)), 48, (0,0,0), 1)
    z = cv2.circle(z,(int(z.shape[0]/2),int(z.shape[0]/2)), 8, (0,0,255), -1)
    
    cv2.imshow('Z',z)
    
    if i==0:
        print('h is :',h)
        print('mult2 is :',mult2)


    if i==1:
        print('i is :',i)
        print('mult2 is :',mult2)
    i=i+1

    scale2=h+an*m*scale1
    mult2=scale2*255


    if i==1:
        print('After calculation:')
        print('h is :',h)
        print('mult2 is :',mult2)
        print('an is :',an)
        print('scale1 is :',scale1)

    key = cv2.waitKey(5) & 0xFF
    if key==27:
	    break

cv2.waitKey(0)

