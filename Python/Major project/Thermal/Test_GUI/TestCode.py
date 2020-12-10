import numpy as np
import cv2

face_cascade = cv2.CascadeClassifier('cascade.xml')

img = cv2.imread('D:/GITHUB/MyFiles-master/Python/Major project/RGB_thermal/thermal_6.jpg')

img = cv2.resize(img, (500, 500))

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

faces = face_cascade.detectMultiScale(gray,1.01,7)
flag=0
for (x,y,w,h) in faces:
    img_dect = cv2.rectangle(img,(x,y),(x+int(1.4*w),y+int(1.4*h)),(0,200,0),3)
    if x>=0:
        flag=1

cv2.imshow('img',img_dect)

if flag==1:
    crop_img = img[y:y+int(1.4*h), x:x+int(1.4*w)]
    cv2.imshow("cropped", crop_img)

cv2.waitKey(0)
cv2.destroyAllWindows()