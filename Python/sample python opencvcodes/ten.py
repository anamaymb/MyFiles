import cv2 #importing module opencv
import numpy as np

img=cv2.imread('1.jpeg')

gray= cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

ret, thresh = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)

ret, contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

cv2.drawContours(img, contours, -1, (0,0,255),3)

cv2.imshow('Contours',img)
cv2.imshow('Binary',thresh)
