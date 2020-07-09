import cv2
import numpy as np


shorten=0.1	


a = cv2.imread("rgb.jpg",-1)
z = cv2.imread("rgb.png",-1)

print(z.shape)
print(z.shape[0])
print(z.shape[1])
print(z.shape[2])
print(z.shape[3])
