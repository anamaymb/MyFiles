import cv2 #importing module opencv


#taking an image
cap = cv2.VideoCapture(0)

while(1):
    ret, img = cap.read()
    cv2.imshow('XVideo',img)

    k = cv2.waitKey(1)

    if(k==27):
        break
cv2.destroyAllWindows()
cap.release()
