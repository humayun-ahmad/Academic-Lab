import cv2
import numpy as np
from matplotlib import pyplot as plt
from skimage.util import random_noise
import random

img_path = "C:/Users/acer/Desktop/Waterfall/Digital_Image_Processing/butterfly.jpg"
print(img_path)

img_original = plt.imread(img_path)

plt.figure(figsize=(20,20))

""" For original grayscale image """
grayscale = cv2.cvtColor(img_original,cv2.COLOR_RGB2GRAY)
plt.subplot(231)
plt.imshow(grayscale, cmap='gray')
plt.title('Grayscale Image')

def noise_add(grayscale,f_title,sub):
    
    row, col = grayscale.shape
    print(row,col)

    random_pixels = random.randint(500,10000)
    
    for i in range(random_pixels):
        x_coord = random.randint(0,row-1)
        y_coord = random.randint(0,col-1)
        
        grayscale[x_coord][y_coord] = 255 #salt(white)
    for i in range(random_pixels):
        x_coord = random.randint(0,row-1)
        y_coord = random.randint(0,col-1)
        
        grayscale[x_coord][y_coord] = 0 #Pepper(black)
    
    plt.subplot(sub)
    plt.imshow(grayscale,cmap='gray')
    plt.title(f_title)
    return grayscale




# grayscale = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
# plt.imshow(grayscale, cmap='gray')
# plt.title('Grayscale Image')
# plt.show()



""" For Filtered Image(Averaging) """
avarage_kernel = np.ones((3,3),np.float32)/25
processed_img1 = cv2.filter2D(grayscale_image,-1,avarage_kernel)
plt.subplot(232)
plt.imshow(processed_img1,cmap='gray')
plt.title('Filtered Image(Averaging)')

""" Noisey Image(Salt and Pepper) """
noisy_img = noise_add(grayscale_image,'Noisey Image(Salt and Pepper)',233)


processed_img2 = cv2.filter2D(noisy_img,-1,avarage_kernel)
plt.subplot(234)
plt.imshow(processed_img2,cmap='gray')
plt.title('Filtered Noisy Image(Averaging)')

gaussian_kernel = cv2.getGaussianKernel(3, 1)
processed_img3 = cv2.filter2D(noisy_img,-1,gaussian_kernel)
plt.subplot(235)
plt.imshow(processed_img3,cmap='gray')
plt.title('Filtered Noisy Image(GaussianKernel)')


median = cv2.medianBlur(noisy_img,5)
plt.subplot(236)
plt.imshow(median,cmap='gray')
plt.title('Filtered Noisy Image(Median Filter)')


plt.savefig('Final_output')
