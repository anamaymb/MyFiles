import cv2 #importing module opencv


#taking an image
cap = cv2.VideoCapture(0)

while(True):
    ret, img = cap.read()

    hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
    gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)



    #ret, thresh1 = cv2.threshold(gray, 125, 125, cv2.THRESH_BINARY)
    #ret, thresh2 = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
    #ret, thresh3 = cv2.threshold(gray, 52, 255, cv2.THRESH_BINARY)
    #ret, thresh4 = cv2.threshold(gray, 14, 55, cv2.THRESH_BINARY)
    #ret, thresh5 = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)


    ret, thresh2 = cv2.threshold(img, 0, 125, cv2.THRESH_BINARY_INV)
    #ret, thresh3 = cv2.threshold(img, 127, 255, cv2.THRESH_TRUNC)
    #ret, thresh4 = cv2.threshold(img, 127, 255, cv2.THRESH_TOZERO)
    #ret, thresh5 = cv2.threshold(img, 127, 255, cv2.THRESH_TOZERO_INV)

    

    #cv2.imshow('Binary1',thresh1)
    cv2.imshow('Binary2',thresh2)
    #cv2.imshow('Binary3',thresh3)
    #cv2.imshow('Binary4',thresh4)
    #cv2.imshow('Binary5',thresh5)


    #cv2.imshow('Video',hsv)
    cv2.imshow('Video1',gray)


    k = cv2.waitKey(1)

    if(k==27):
        break
cv2.destroyAllWindows()
cap.release()

