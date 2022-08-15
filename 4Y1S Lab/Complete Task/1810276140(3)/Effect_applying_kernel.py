from matplotlib import pyplot as plt
import cv2
import numpy as np


# Load an RGB IMAGE
img_path = "C:/Users/acer/Desktop/Waterfall/Digital_Image_Processing/butterfly.jpg"
#print(img_path)
rgb = plt.imread(img_path)
print(rgb.shape)

# converting RGB image into grayscale image
grayscale = cv2.cvtColor(rgb,cv2.COLOR_RGB2GRAY)

print(grayscale.shape)

# prepare kernels here
print("------------kernel1----------------")
kernel1 = np.ones((3,3), dtype=np.float32)*2/9
print(kernel1.shape, '\n', kernel1)

print("------------kernel2----------------")
kernel2 = np.array([[0, -1, 0], [-1, 4, -1], [0, -1, 0]])
print(kernel2.shape, '\n' ,kernel2)

print("------------kernel3----------------")
kernel3 = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print(kernel3.shape, '\n' ,kernel3)

print("------------kernel4----------------")
kernel4 = np.array([[1, 0, 1], [1, 0, 1], [1, 0, 1]])
print(kernel4.shape, '\n' ,kernel4)

print("------------kernel5----------------")
kernel5 = np.ones((3,3), dtype=np.float32)*(9)
print(kernel5.shape, '\n' ,kernel5)

print("------------kernel6----------------")
kernel6 = np.ones((3,3), dtype=np.float32)*(1/16)
print(kernel6.shape, '\n', kernel6)

processed_img1 = cv2.filter2D(grayscale,-1,kernel1)
processed_img2 = cv2.filter2D(grayscale,-1,kernel2)
processed_img3 = cv2.filter2D(grayscale,-1,kernel3)
processed_img4 = cv2.filter2D(grayscale,-1,kernel4)
processed_img5 = cv2.filter2D(grayscale,-1,kernel5)
processed_img6 = cv2.filter2D(grayscale,-1,kernel6)


# Image ploting
img_set = [rgb,grayscale,processed_img1,processed_img2,processed_img3,processed_img4,processed_img5,processed_img6]
title_set = ['RGB', 'Grayscale', 'Kernel1','Kernel2', 'Kernel3','Kernel4','Kernel5','Kernel6']

n = len(img_set)
plt.figure(figsize = (20,20))

for i in range(n):
    plt.subplot(4,4,i+1) # Value of i will start from 0
    img = img_set[i]
    ch = len(img.shape)
    
    if(ch == 3):
        plt.imshow(img_set[i])
    else:
        plt.imshow(img_set[i],cmap='gray')
    
    plt.title(title_set[i])


plt.savefig('Six different kinds of kernels providing on a 2D image')    
plt.show()
    
    
    



