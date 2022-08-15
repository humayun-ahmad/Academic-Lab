import numpy as np
from matplotlib import pyplot as plt
import cv2

img_path = "C:/Users/acer/Desktop/Waterfall/Digital_Image_Processing/butterfly.jpg"
print(img_path)

img = plt.imread(img_path)
# print(img.shape)
# plt.imshow(img, cmap='gray')
# plt.title('RGB Image')
# plt.show()

grayscale = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
plt.imshow(grayscale, cmap='gray')
plt.title('Grayscale Image')
plt.show()

""" Slicing an 8-bit grayscale image into 8 planes """

b0 = (grayscale >> 0) & 1
b1 = (grayscale >> 1) & 1
b2 = (grayscale >> 2) & 1
b3 = (grayscale >> 3) & 1
b4 = (grayscale >> 4) & 1
b5 = (grayscale >> 5) & 1
b6 = (grayscale >> 6) & 1
b7 = (grayscale >> 7) & 1

fig = plt.figure(figsize=(20,20))

plt.subplot(4,4,1)
plt.imshow(b0,cmap='gray')
plt.title('Bit 0')


plt.subplot(4,4,2)
plt.imshow(b1,cmap='gray')
plt.title('Bit 1')

plt.subplot(4,4,3)
plt.imshow(b3,cmap='gray')
plt.title('Bit 3')

plt.subplot(4,4,4)
plt.imshow(b4,cmap='gray')
plt.title('Bit 4')

plt.subplot(4,4,5)
plt.imshow(b5,cmap='gray')
plt.title('Bit 5')

plt.subplot(4,4,6)
plt.imshow(b6,cmap='gray')
plt.title('Bit 6')

plt.subplot(4,4,7)
plt.imshow(b7,cmap='gray')
plt.title('Bit 7')



""" effect of convolution of a grayscale image with a Laplacian filters """
img = grayscale
laplacian = cv2.Laplacian(img,cv2.CV_64F)
plt.subplot(4,4,8)
plt.imshow(laplacian,cmap='gray')
plt.title('Laplacian')

""" effect of convolution of a grayscale image with a sobel filters """

sobelx = cv2.Sobel(img,cv2.CV_64F,1,0,ksize=5)  # x
plt.subplot(4,4,9)
plt.imshow(sobelx,cmap='gray')
plt.title('Sobel x')

sobely = cv2.Sobel(img,cv2.CV_64F,0,1,ksize=5)  # y
plt.subplot(4,4,10)
plt.imshow(sobely,cmap='gray')
plt.title('Sobel y')

"""  applying a binary mask on a grayscale image """
binary_mask = np.zeros(grayscale.shape, dtype=np.uint8)
binary_mask = cv2.circle(binary_mask, (500, 400), 300, (255,255,255), -1)
result = cv2.bitwise_and(grayscale, binary_mask)

plt.subplot(4,4,11)
plt.imshow(binary_mask,cmap='gray')
plt.title('Binary Mask')


plt.subplot(4,4,12)
plt.imshow(result,cmap='gray')
plt.title('After Masking')

plt.savefig('Final Output')    
plt.show()
