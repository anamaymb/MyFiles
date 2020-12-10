import cv2 #importing module opencv


#taking an image
img = cv2.imread("1.jpeg")

blur = cv2.blur(img,(3,3))

#hsv= cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
#gray= cv2.cvtColor(hsv, cv2.COLOR_BGR2GRAY)

cv2.imshow('sdodv',img)
cv2.imshow('sfewf',blur)
