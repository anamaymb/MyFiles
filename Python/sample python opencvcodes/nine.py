import cv2 #importing module opencv
import numpy as np

def nothing(x):
    pass

#taking an image
cap = cv2.VideoCapture(0)
#lower= np.array([86,31,4])
#upper=np.array([220,88,50])

win_name='Trackbars'
cv2.namedWindow(win_name)

#create trackbars
cv2.createTrackbar('Ru',win_name,0,255,nothing)
cv2.createTrackbar('Gu',win_name,0,255,nothing)
cv2.createTrackbar('Bu',win_name,0,255,nothing)
cv2.createTrackbar('Rl',win_name,0,255,nothing)
cv2.createTrackbar('Gl',win_name,0,255,nothing)
cv2.createTrackbar('Bl',win_name,0,255,nothing)

while(True):
    ret, img = cap.read()
    hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
    
    cv2.imshow('Video',hsv)

    ru=cv2.getTrackbarPos('Ru',win_name)
    gu=cv2.getTrackbarPos('Gu',win_name)
    bu=cv2.getTrackbarPos('Bu',win_name)
    rl=cv2.getTrackbarPos('Rl',win_name)
    gl=cv2.getTrackbarPos('Gl',win_name)
    bl=cv2.getTrackbarPos('Bl',win_name)

    lower= np.array([rl,gl,bl])
    upper= np.array([ru,gu,bu])
    mask=cv2.inRange(hsv, lower, upper)
    #cv2.imshow('Video1',gray)

    cv2.imshow('Video4',mask)
    k = cv2.waitKey(1)

    if(k==27):
        break
cv2.destroyAllWindows()
cap.release()

