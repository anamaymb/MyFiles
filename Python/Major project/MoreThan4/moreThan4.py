import cv2
face_cascade=cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

eye_cascade=cv2.CascadeClassifier('haarcascade_eye.xml')

cap = cv2.VideoCapture(0)

prevf=0
flag=0

while(True):
    ret, img = cap.read()

    gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    faces=face_cascade.detectMultiScale(gray,1.3,5)
    f=0

    for[x,y,w,h] in faces:
        f=f+1
        img= cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),3)

    if f!=prevf:
        # print(f)
        if f>4:
            # print('Get Out of Lift')
            flag=1
        else:
            flag=0
        prevf=f
    
    print(flag)
    cv2.imshow('Video',img)

    k = cv2.waitKey(1)

    if(k==27):
        break
cv2.destroyAllWindows()
cap.release()


