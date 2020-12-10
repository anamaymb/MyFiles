import cv2 #importing module opencv


#taking an image
img=cv2.imread("1.jpeg")

hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)



cv2.imshow("image frame",img)
cv2.imshow("image a frame",hsv)

cv2.imshow("image b frame",gray)



