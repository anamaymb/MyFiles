import numpy as np
import cv2
import matplotlib.pyplot as plt

img=cv2.imread('thermal_1.jpg')
IMG=cv2.imread('thermal_1.jpg')

# gray=np.zeros((img.shape[0],img.shape[1],1),dtype=np.uint16)

# img=cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
IMG=cv2.cvtColor(IMG, cv2.COLOR_BGR2RGB)


# for i in range (0,img.shape[0]):
#     for j in range (0,img.shape[1]):
#         gray[i,j]=img[i,j,2]
#         gray[i,j]=gray[i,j]*255
# cv2.imshow('Gray',gray)


# lower=np.array([25,25,240])
# lower=np.array([0,0,0])  
lower = np.array([0,0,240])
higher=np.array([35,35,255])
mask=cv2.inRange(img,lower,higher)


cont,_=cv2.findContours(mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)
cont_img=cv2.drawContours(img,cont,-1,100,3)

# c=max(cont,key=cv2.contourArea)
for cnt in cont:

    x,y,w,h=cv2.boundingRect(cnt)
    if w>7:
        print(w,h)
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,255,255),3)

plt.imshow(mask,'gray')
plt.show()
# plt.imshow(cont_img)
# plt.show()


# f = plt.figure()
# f.add_subplot(1,2, 1)
# plt.imshow(mask,'gray')
# f.add_subplot(1,2, 2)
# plt.imshow(IMG)
# plt.show(block=True)

img=cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

plt.imshow(img)
plt.show()

cv2.waitKey(0)