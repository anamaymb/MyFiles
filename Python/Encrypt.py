import cv2
import numpy as np
import math

def nothing(x):
	pass

shorten=0.4

cap = cv2.VideoCapture(0)

# a = cv2.imread("grn.jpg",-1)

ret, a = cap.read()

a=cv2.resize(a,(int(a.shape[1]*shorten),int(a.shape[1]*shorten)))

em=np.matrix(np.zeros((a.shape[0],a.shape[1],1),dtype=np.int32))
dm=np.matrix(np.zeros((a.shape[0],a.shape[1],1),dtype=np.int32))
tm=np.matrix(np.zeros((a.shape[0],a.shape[1],1),dtype=np.int32))
temp=np.matrix(np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint16))
sm=np.matrix(np.zeros((a.shape[0],a.shape[1],1),dtype=np.int32))
m=np.matrix(np.zeros((a.shape[0],a.shape[1],1),dtype=np.uint8))

for i in range (0,a.shape[0]):
    for j in range (0,a.shape[1]):
        sm[i,j]=np.uint8(a[i,j,0]/3 +  a[i,j,1]/3 + a[i,j,2]/3)

for j in range (0,a.shape[1]):
    for i in range (0,a.shape[0]):
        m[i,j]=sm[i,j]
cv2.imshow('smbif',m)

# b=[[14,2,-35,9],
#    [0,19,-9,0],
#    [-34,1,40,5],
#    [10,41,2,-52]]

b=[[-1,0,0,0],
   [0,1,0,0],
   [0,0,-2,0],
   [0,0,0,1]]


for i in range (0,int(a.shape[0]/4)):
    for j in range (0,int(a.shape[1]/4)):
        for l in range (0,4):
            for k in range (0,4):
                em[4*i+l,4*j+0+k]=float(b[l][0])*sm[4*i+0,4*j+k] + float(b[l][1])*sm[4*i+1,4*j+k] + float(b[l][2])*sm[4*i+2,4*j+k] + float(b[l][3])*sm[4*i+3,4*j+k]


for j in range (0,a.shape[1]):
    for i in range (0,a.shape[0]):
        temp[i,j]=em[i,j]
cv2.imshow('smfincr',temp)

# for i in range (0,4):
#     for j in range (0,4):
#         b[i][j]=b[i][j]/(2**8)

bt = np.linalg.inv(b)

print(bt)

for i in range (0,int(a.shape[0]/4)):
    for j in range (0,int(a.shape[1]/4)):
        for l in range (0,4):
            for k in range (0,4):
                dm[4*i+l,4*j+0+k]=float(bt[l][0])*em[4*i+0,4*j+k] + float(bt[l][1])*em[4*i+1,4*j+k] + float(bt[l][2])*em[4*i+2,4*j+k] + float(bt[l][3])*em[4*i+3,4*j+k]

# for j in range (0,a.shape[1]):
#     for i in range (0,a.shape[0]):
#         dm[i,j]=dm[i,j]*2**8

for j in range (0,a.shape[1]):
    for i in range (0,a.shape[0]):
        temp[i,j]=dm[i,j]*2**8
cv2.imshow('smf',temp)


        # sm[i+0,j+0]=b[0,0]*sm[i+0,j+0]
        # sm[i+1,j+0]=b[0,1]*sm[i+1,j+0]
        # sm[i+2,j+0]=b[0,2]*sm[i+2,j+0]
        # sm[i+3,j+0]=b[0,3]*sm[i+3,j+0]

        # sm[i+0,j+0]=b[1,0]*sm[i+0,j+0]
        # sm[i+1,j+0]=b[1,1]*sm[i+1,j+0]
        # sm[i+2,j+0]=b[1,2]*sm[i+2,j+0]
        # sm[i+3,j+0]=b[1,3]*sm[i+3,j+0]

        # sm[i+0,j+0]=b[2,0]*sm[i+0,j+0]
        # sm[i+1,j+0]=b[2,1]*sm[i+1,j+0]
        # sm[i+2,j+0]=b[2,2]*sm[i+2,j+0]
        # sm[i+3,j+0]=b[2,3]*sm[i+3,j+0]

        # sm[i+0,j+0]=b[3,0]*sm[i+0,j+0]
        # sm[i+1,j+0]=b[3,1]*sm[i+1,j+0]
        # sm[i+2,j+0]=b[3,2]*sm[i+2,j+0]
        # sm[i+3,j+0]=b[3,3]*sm[i+3,j+0]



print(sm.shape)

print(sm[32,32])
print(em[32,32])
print(dm[32,32])


cv2.waitKey(0)

