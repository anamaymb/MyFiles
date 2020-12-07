import cv2
import numpy as np

shorten=0.4	

# cap = cv2.VideoCapture(0)

def function(event, x, y, flags, params):
    
    if event == cv2.EVENT_LBUTTONDOWN:
        print(x,y,a[y,x,0],a[y,x,1],a[y,x,2])
        cv2.circle(z,(x,y),5,(0,0,255),-1)
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


a = cv2.imread("solar.jpg",-1)
z = cv2.imread("solar.jpg",-1)
# ret, a = cap.read()
# a = cv2.imread("thermal_4.jpg",-1)
# z = cv2.imread("thermal_4.jpg",-1)

cv2.namedWindow('image')
cv2.setMouseCallback('image', function)

a=cv2.resize(a,(int(a.shape[1]*shorten),int(a.shape[0]*shorten)))
z=cv2.resize(z,(int(z.shape[1]*shorten),int(z.shape[0]*shorten)))

min=[256,256,256]
max=[0,0,0]

while(1):
    cv2.imshow('image',z)

    k = cv2.waitKey(20) & 0xFF
    if k == 27:
        break
    # elif k == ord('a'):
    #     print (mouseX,mouseY)

print(min)
print(max)
print ('Wait...')




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








