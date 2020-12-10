import cv2 #importing module opencv


#taking an image
img=cv2.imread("1.jpeg")
hsv= cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
gray= cv2.cvtColor(hsv, cv2.COLOR_BGR2GRAY)


#Binary thresholding

ret, thresh1 = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)
ret, thresh2 = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY_INV)
ret, thresh3 = cv2.threshold(img, 127, 255, cv2.THRESH_TRUNC)
ret, thresh4 = cv2.threshold(img, 127, 255, cv2.THRESH_TOZERO)
ret, thresh5 = cv2.threshold(img, 127, 255, cv2.THRESH_TOZERO_INV)

print(ret)

cv2.imshow('Binary1',thresh1)
cv2.imshow('Binary2',thresh2)
cv2.imshow('Binary3',thresh3)
cv2.imshow('Binary4',thresh4)
cv2.imshow('Binary5',thresh5)
