import matplotlib.pyplot as plt
import cv2 as cv
def main():

    # load an image from my local device
    
    img_path = 'C:/Users/acer/Desktop/Waterfall/Digital_Image_Processing/butterfly.jpg'
    rgb = plt.imread(img_path)
    
    # split loaded image into red,green,blue channel
    red = rgb[:,:,0]
    green = rgb[:,:,1]
    blue = rgb[:,:,2]
    
    
    # rgb to grayscale convertion
    grayscale = cv.cvtColor(rgb,cv.COLOR_RGB2GRAY)
    
    # grayscale image to binary image
    _, binary = cv.threshold(grayscale, 127, 255,cv.THRESH_BINARY)
    
    
    # Ploting histogram
    img_set = [rgb,rgb,red,green,blue,grayscale,binary]
    title_set = ['null','RGB','RED','GREEN','BLUE','GRAYSCALE','BINARY']
    plt.figure(figsize = (20, 20))

    # For image plot
    for i in range (1,7):
        plt.subplot(6,2,2*i-1)
        plt.title(title_set[i])

        ch = len(img_set[i].shape)
        if(ch == 3):
            plt.imshow(img_set[i])
        else:

            plt.imshow(img_set[i],cmap = 'gray')
    
    # For histogram plot
    for i in range (1,7):
        plt.subplot(6,2,2*i)
        plt.title(title_set[i])
        #img = cv.imread(rgb)
        plt.hist(img_set[i].ravel(),255,[0,255])
    
    
    plt.subplots_adjust(left=0.2, bottom=0.2, right=1, top=1, wspace=.4,hspace=1)
    plt.savefig('Histrogram along with photo')
    
    
if __name__ == '__main__':
    main()
