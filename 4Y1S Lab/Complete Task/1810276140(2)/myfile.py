import pandas as pd
from matplotlib import pyplot as plt
%matplotlib inline
import random
import numpy as np
import cv2
import math


img_path = 'C:/Users/acer/Desktop/Waterfall/Digital_Image_Processing/butterfly.jpg'

img = cv2.imread(img_path, 0)

m,n = img.shape
print(m,n)

L = img.max()
print(L)

# negative image
img_neg = L-img


img_thresh = np.zeros((m,n), dtype = int)
print(img_thresh)

T = 150

img_thresh = np.zeros((m,n), dtype = int) 
   
for i in range(m):
      
    for j in range(n):
          
        if (img[i,j] >= T) and (img[i,j] <= T): 
            img_thresh[i,j]= 100
        else:
            img_thresh[i,j] = 10

cv2.imwrite('Condition1.png', img_thresh)


# the lower threshold value
T1 = 100
  
# the upper threshold value
T2 = 180 
  
# create a array of zeros
img_thresh_back = np.zeros((m,n), dtype = int)

for i in range(m):
      
    for j in range(n):
          
        if img[i,j] >= T1 and img[i,j] <= T2: 
            img_thresh_back[i,j]= 100
        else:
            img_thresh_back[i,j] = img[i,j]
  

cv2.imwrite('Condition2.png', img_thresh_back)

c = 100

img_thresh1 = np.zeros((m,n), dtype = int)

for i in range(m):
      
    for j in range(n):
        img_thresh1[i][j] = c*math.log(1+img_thresh1[i][j])

cv2.imwrite('Condition3.png', img_thresh_back)

p = 5
ep = 0.0000001
c = 2

img_thresh2 = np.zeros((m,n), dtype = int)

for i in range(m):
      
    for j in range(n):
        img_thresh2[i][j] = pow(c*(img_thresh2[i][j] + ep),p)
        

cv2.imwrite('Condition4.png', img_thresh_back)

