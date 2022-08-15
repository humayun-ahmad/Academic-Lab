import cv2
import numpy as np
from matplotlib import pyplot as plt
import pandas as pd

# Load an RGB IMAGE
img_path = "C:/Users/acer/Desktop/Waterfall/Digital_Image_Processing/butterfly.jpg"
#print(img_path)
rgb = plt.imread(img_path)
# print(rgb.shape)

# converting RGB image into grayscale image
grayscale = cv2.cvtColor(rgb,cv2.COLOR_RGB2GRAY)

plt.figure(figsize=(15,10))
plt.subplot(2,1,1)

# using buit-in function hist diagram here
plt.hist(grayscale.ravel(),256,[0,256])

m,n = grayscale.shape

print(m,n)
count =[]
r = []

# counting the density of pixel value here
for k in range(0, 256):
    r.append(k)
    cnt1 = 0
    for i in range(m): 
        for j in range(n):
            if grayscale[i, j] == k: 
                cnt1+= 1
    count.append(cnt1)

# after implementing the histogram function from scratch ploting here
# creating the bar plot
plt.subplot(2,1,2)
plt.bar(r, count,color='maroon',width=0.4) 
plt.title("Histogram function from scratch")
plt.ylabel('Density of shape value within 0-256')
plt.savefig('Using function and without using function output') # For saving the output file
plt.show()
