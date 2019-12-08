
from matplotlib import image as mpimg 
from matplotlib import pyplot as plt

 
img = mpimg.imread('mario.jfif',1)
plt.imshow(img)
print(img)
