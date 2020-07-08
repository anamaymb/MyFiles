import cv2
import numpy as np

# a = cv2.imread("solar.jpg",-1)

cap = cv2.VideoCapture(0)
ret, a = cap.read()																# Take the first capture of the camera


shorten=0.4																		# scale to resize

d=0

# cv2.imshow('colour1',a)

b=cv2.resize(a,(int(a.shape[1]*shorten),int(a.shape[0]*shorten)))				# Resizing the image by given scale

# print(sizeof(b[2,2,0]))

cv2.imshow('colour',b)

c=np.matrix(np.zeros((b.shape[0],b.shape[1],1)),dtype=np.uint8)					# creating a zero square matrix of size same as of the resized image
temp=np.matrix(np.zeros((b.shape[0],b.shape[1],1)),dtype=np.uint16)

print(a.shape,b.shape,c.shape)

gray= cv2.cvtColor(b, cv2.COLOR_BGR2GRAY)


for i in range(0,b.shape[0]):
	for j in range(0,b.shape[1]):

		c[i,j]=int(( ( b[i,j,0]/3   +   b[i,j,1]/3    +   b[i,j,2]/3 ) ))
		
		temp[i,j]=np.uint16(( np.uint16(b[i,j,0]) + np.uint16(b[i,j,1]) + np.uint16(b[i,j,2]) )/3)*2**8
		
		if d<temp[i,j]:
			d=temp[i,j]



print(d)
cv2.imshow('grayman',c)													# The biggest flaw of imshow is that it maps size of pixel of the output matrix to uint8
cv2.imshow('temp',temp)													# e.g. pixel Size if uint16 hence imshow maps 0to 2^16 to 2^8 hence damping the image 2^8 times
																		# So first we amplify the image 2^8 times which gives perfect matcing to the 2^8 window of imshow
# cv2.imshow('grayauto',gray)
cv2.waitKey(0)
