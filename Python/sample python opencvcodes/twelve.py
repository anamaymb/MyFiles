import cv2
face_cascade=cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

eye_cascade=cv2.CascadeClassifier('haarcascade_eye.xml')

cap = cv2.VideoCapture(0)

while(True):
    ret, img = cap.read()


    #img=cv2.imread('1.jpeg')
    gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    faces=face_cascade.detectMultiScale(gray,1.3,5)
    #print(faces)

    for[x,y,w,h] in faces:
        img= cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),3)
        
        
        #roi_img=img[y:y,x:x]
        #roi_gray=gray[y:y,x:x]

    crop_img = img[y:y+int(1.0*h), x:x+int(1.0*w)]
    cv2.imshow('Video',img)
    cv2.imshow('cropped', crop_img)

    k = cv2.waitKey(1)

    if(k==27):
        break
cv2.destroyAllWindows()
cap.release()









    














               










































































































               
