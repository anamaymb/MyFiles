import numpy as np
import cv2

shorten =2.1

face_cascade = cv2.CascadeClassifier('cascade.xml')

img = cv2.imread('thermal_9.jpg')

img=cv2.resize(img,(int(img.shape[1]*shorten),int(img.shape[0]*shorten)))
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

faces = face_cascade.detectMultiScale(gray,1.01,7)
for (x,y,w,h) in faces:
    img = cv2.rectangle(img,(x,y),(x+w,y+h),(250,250,12),2)

cv2.imshow('img',img)
cv2.waitKey(0)
cv2.destroyAllWindows()