import cv2
import numpy as np
import math

# def nothing(x[0]):
# 	pass

shorten=0.4	

cap = cv2.VideoCapture(0)
ret, a = cap.read()
z=a
z=cv2.resize(z,(int(a.shape[0]*1.2),int(a.shape[0]*1.2)))

# cv2.namedWindow("Trackbars")
# cv2.createTrackbar("X","Trackbars",0,255,nothing)
# cv2.createTrackbar("Y","Trackbars",0,255,nothing)

flag=[0,0,0,0,0]
flag1=[0,0,0,0,0]
flag2=[0,0,0,0,0]
flag3=[0,0,0,0,0]

c=0

mult1=[37,50,0,0,0]               # initial position  (x[0])
mult2=[127,154,0,0,0]               # (y[0])

h=[0,0,0,0,0]

scale1=[0,0,0,0,0]
scale2=[0,0,0,0,0]
x=[0,0,0,0,0]
y=[0,0,0,0,0]

speed=[0.5,0.0,0,0,0]               # Speed of Piece
brk=[0.0,0.0,0,0,0]                 # Friction
m=[1.7,1,0,0,0]                   # slope[0] (magnitude)
an=[-1,-1,0,0,0]                   # slope[0] (direction) (inital) (+ve/-ve)
slope=[m[0],m[1],0,0,0]
q=[1,1,0,0,0]
cv2.imshow('WASD to move',a)
tog=[0,0,0,0,0]


def graphics(z):
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

scale1[1]=mult1[1]/255
scale2[1]=mult2[1]/255    
x[1]=int(scale1[1]*z.shape[1])
y[1]=int(scale2[1]*z.shape[0])


while True:
    ret, a = cap.read()
    a=cv2.resize(a,(int(a.shape[0]*1.2),int(a.shape[0]*1.2)))
    z=a

    if cv2.waitKey(0) & 0xFF == ord('s'):
        mult2[0]=mult2[0]+3
    elif cv2.waitKey(0) & 0xFF == ord('w'):
        mult2[0]=mult2[0]-3
    elif cv2.waitKey(0) & 0xFF == ord('d'):
        mult1[0]=mult1[0]+4
    elif cv2.waitKey(0) & 0xFF == ord('a'):
        mult1[0]=mult1[0]-4

    elif cv2.waitKey(0) & 0xFF == ord('l'):
        slope[0]=slope[0]+0.2
    elif cv2.waitKey(0) & 0xFF == ord('j'):
        slope[0]=slope[0]-0.2
    elif cv2.waitKey(0) & 0xFF == ord('i'):
        q[0]=1
    elif cv2.waitKey(0) & 0xFF == ord('k'):
        q[0]=-1

    elif cv2.waitKey(0) & 0xFF == ord('t'):
        break


    scale1[0]=mult1[0]/255
    scale2[0]=mult2[0]/255    
    x[0]=int(scale1[0]*z.shape[1])
    y[0]=int(scale2[0]*z.shape[0])

    z = cv2.circle(z,(x[0],y[0]), 8, (255,255,255), -1)
    z = cv2.circle(z,(x[1],y[1]), 8, (0,255,255), -1)

    graphics(z)

    z = cv2.line(z, (x[0],y[0]), (q[0]*25+x[0],int(q[0]*slope[0]*25+y[0])), (0,255,0),2)

    cv2.imshow('Init',z)
    
    key = cv2.waitKey(5) & 0xFF
    if key==27:
	    break

m[0]=abs(slope[0])

if slope[0]>=0:
    an[0]=1
else:
    an[0]=-1

h[0]=(mult2[0]/255)-an[0]*m[0]*(mult1[0]/255)          # y[0]-intercept
h[1]=(mult2[1]/255)-an[1]*m[1]*(mult1[1]/255)

tog[0]=q[0]*speed[0]
tog[1]=q[1]*speed[1]

while True:

    ret, a = cap.read()
    a=cv2.resize(a,(int(a.shape[0]*1.2),int(a.shape[0]*1.2)))

    for i in range (0,2):

        if speed[i]>0 :
            if tog[i]>0:
                speed[i]=speed[i]-brk[i]
                tog[i]=speed[i]
            elif tog[i]<0:
                speed[i]=speed[i]-brk[i]
                tog[i]=-speed[i]
        else:
            tog[i]=0


        if mult1[i]>=255:
            tog[i]=-speed[i]
        elif mult1[i]<=0:
            tog[i]=speed[i]
            if an[i]==1:
                an[i]=-1
            elif an[i]==-1:
                an[i]=1
        mult1[i]=mult1[i]+tog[i]
        scale1[i]=mult1[i]/255
        # m[0]=1

        if mult2[i]>5:
            flag[i]=0
        if mult1[i]<250:
            flag3[i]=0

        if mult2[i]>=255 and an[i]==1 and tog[i]>0:
            h[i]=scale1[i]*m[i]+1
            # print('scale2[0]')
            an[i]=-1
        elif mult2[i]>=255 and an[i]==-1 and tog[i]<0:
            # print('k')
            flag[i]=0
            h[i]=1-m[i]*scale1[i]
            print(scale2[i])
            an[i]=1
        
        if mult1[i]>=255 and flag3[i]==0:
            print('hi')
            if an[i]==-1:
                # print('belekar')
                an[i]=1
                h[i]=scale2[i]-m[i]
            elif an[i]==1:
                # print('anaamay')
                an[i]=-1
                h[i]=scale2[i]+m[i]
            flag3[i]=1

        if mult2[i]<=0 and flag[i]==0:
            # print('b',c)
            if tog[i]<0:
                an[i]=-1
                h[i]=m[i]*scale1[i]
            elif tog[i]>0:
                an[i]=1
                h[i]=-m[i]*scale1[i]
            flag[i]=1
            

        # elif mult2[i]<=0 and tog[i]>0 and flag2[i]==0:
        #     print('z')
        #     an[i]=1
        #     flag2[i]=1
        #     h[i]=-m[i]*scale1[i]
            
        

        scale2[i]=mult2[i]/255
        if (abs(mult1[0]-mult1[1])<8) and (abs(mult2[0]-mult2[1])<8) and flag2[0]==0 and i==1:
            print('Anamay')
            flag2[0]=1
            speed[1]=1.5
            
            tog[1]=speed[1]
            m[1]=(mult2[1]-mult2[0])/(mult1[1]-mult1[0])
            if m[1]>0 and mult2[0]>mult2[1] : 
                tog[1]=-speed[1]
            elif m[1]<0 and mult1[0]>mult1[1]:
                tog[1]=-speed[1]

            print('m',m[1])
            if m[1]>2.5:
                m[1]=2.5
            if m[1]<-2.5:
                m[1]=-2.5

            an[1]=an[0]
            if an[0]<0 and m[1]>0:
                an[1]=1 
            if m[1]>0:
                h[1]=abs((mult1[1]/255)*m[1]-(mult2[1]/255))
            else:
                an[1]=-1
                m[1]=-m[1]
                h[1]=(mult1[1]/255)*m[1]+(mult2[1]/255)
        
        # scale[i]=mult2[i]/255

        x[i]=int(scale1[i]*a.shape[1])
        y[i]=int(scale2[i]*a.shape[0])


    if flag2[0]==1 and i==1:
        flag2[0]=0
        print('mult2',mult2[1])
        print('mult1',mult1[1])
        print('h',h[1])
        # print('m',m[1])
        print('speed',speed[1])

        # scale2[1]=h[1]+an[1]*m[1]*scale1[1]
        # mult2[1]=scale2[1]*255

        # x[1]=int(scale1[1]*a.shape[1])
        # y[1]=int(scale2[1]*a.shape[0])

        # z = cv2.circle(a,(x[0],y[0]), 8, (255,255,255), -1)
        # z = cv2.circle(z,(x[0],y[0]), 5, (255,0,0), -1)

        # z = cv2.circle(z,(x[1],y[1]), 8, (0,255,255), -1)
        # z = cv2.circle(z,(x[1],y[1]), 5, (255,0,255), -1)
        # break        

    # z = cv2.circle(a,(x[0],y[0]), 8, (255,255,255), -1)
    # z = cv2.rectangle(z, (0,0), (z.shape[0],z.shape[0]), (155,255,255),-1)
    z = cv2.circle(a,(x[0],y[0]), 8, (255,255,255), -1)
    z = cv2.circle(z,(x[0],y[0]), 5, (255,0,0), -1)

    z = cv2.circle(z,(x[1],y[1]), 8, (0,255,255), -1)
    z = cv2.circle(z,(x[1],y[1]), 5, (255,0,255), -1)
    
    
    graphics(z)

    cv2.imshow('Z',z)
    
    c=c+1

    for i in range (0,2):
        scale2[i]=h[i]+an[i]*m[i]*scale1[i]
        mult2[i]=scale2[i]*255


    # if c==1:
    #     print('After calculation:')
    #     print('h[0] is :',h[0])
    #     print('mult2[0] is :',mult2[0])
    #     print('an[0] is :',an[0])
    #     print('scale1[0] is :',scale1[0])
        # break

    key = cv2.waitKey(5) & 0xFF
    if key==27:
	    break

cv2.waitKey(0)

