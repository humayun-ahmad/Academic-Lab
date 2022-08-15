# import
import cv2
import matplotlib.pyplot as plt
import numpy as np


# image 
img_path = "C:/Users/acer/Desktop/Waterfall/Digital_Image_Processing/123.jpg"
# print(img_path)
rgb_img = plt.imread(img_path)
# print(rgb_img.shape)

# image convertion GRB to GRAY
gray = cv2.cvtColor(rgb_img,cv2.COLOR_RGB2GRAY)
print(gray.shape)

# image convertion RGB to BINARY
binary = cv2.threshold(gray,127,255,cv2.THRESH_BINARY)[1]


# demo practice
# figure = plt.figure(figsize=(20,20))
# plt.subplot(321)
# plt.imshow(binary,cmap='gray')


kernel = np.ones((10,10), np.uint16)
# kernel = np.ones((10,10), np.uint8)
print(kernel)


rgb_erosion = cv2.erode(rgb_img,kernel,iterations=1)
# figure = plt.figure(figsize=(20,20))
# plt.subplot(321)
# plt.imshow(binary,cmap='gray')

bin_erosion = cv2.erode(binary, kernel, iterations=1)

rgb_dilation = cv2.dilate(rgb_img, kernel, iterations=1)

bin_dilation = cv2.dilate(binary, kernel, iterations=1) 

figure = plt.figure(figsize=(20,20))
# plt.subplot(321)
# plt.imshow(rgb_erosion,cmap='gray')

img_set = [rgb_img, binary, rgb_erosion, bin_erosion, rgb_dilation, bin_dilation]
title_set = ['RGB IMAGE', 'BINARY IMAGE','RGB EROSION', 'BINARY EROSION','RGB DILATION', 'BINARY DILATION']

n = len(img_set)
a = 3 # col
b = 2 # row
for i in range(n):
    img = img_set[i]
    channel = len(img.shape)
    
    plt.subplot(a,b,i+1)
    if channel == 3:
        plt.imshow(img_set[i]) # RGB Image
    else:
        plt.imshow(img_set[i], cmap='gray') # For gray and binary image
    plt.title(title_set[i]) # Title

# For saving the figure
plt.savefig('output_figure.jpg')
