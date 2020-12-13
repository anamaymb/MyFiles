import numpy as np
import cv2
import sys

face_cascade = cv2.CascadeClassifier('cascade.xml')

img = cv2.imread('D:/GITHUB/MyFiles-master/Python/Major project/Thermal/RGB_thermal/thermal_6.jpg')

img = cv2.resize(img, (500, 500))

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

faces = face_cascade.detectMultiScale(gray,1.01,7)
flag=0
for (x,y,w,h) in faces:
    img_dect = cv2.rectangle(img,(x,y),(x+int(1.4*w),y+int(1.4*h)),(0,200,0),3)
    if x>=0:
        flag=1

cv2.imshow('img',img)

if flag==1:
    crop_img = img[y:y+int(1.4*h), x:x+int(1.4*w)]
    cv2.imshow("cropped", crop_img)

if flag==0:
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    sys.exit("No face detected")

# crop_img=cv2.cvtColor(crop_img, cv2.COLOR_BGR2RGB)

lower = np.array([0,0,170])
higher=np.array([35,35,255])
mask=cv2.inRange(crop_img,lower,higher)


cont,_=cv2.findContours(mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)
cont_img=cv2.drawContours(crop_img,cont,-1,100,3)


for cnt in cont:

    x,y,w,h=cv2.boundingRect(cnt)
    if w>30:
        print(w,h)
        cv2.rectangle(crop_img,(x,y),(x+w,y+h),(255,255,255),3)

cv2.imshow('mask',crop_img)


cv2.waitKey(0)
cv2.destroyAllWindows()
