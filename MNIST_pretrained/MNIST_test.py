
# coding: utf-8

# In[10]:


import caffe
import numpy as np
from skimage import color
import skimage
import imageio
import matplotlib.pyplot as plt

# caffe.set_mode_cpu()
caffe.set_device(0)
caffe.set_mode_gpu()
net = caffe.Net('lenet_deploy.prototxt', 'lenet_iter_10000.caffemodel', caffe.TEST)
print("Loaded OK!")


# In[14]:


img = caffe.io.load_image('sketch-9.png')

# plt.imshow(im)
# plt.show()

# print(img)
img_gray = color.rgb2gray(img)
img_gray = 1 - img_gray # invert the white background image

# plt.imshow(img_gray)
# plt.show()

img_gray_resized = skimage.transform.resize(img_gray, (28, 28), mode='constant')
# plt.imshow(img_gray_resized)
# plt.show()
# print(img_gray_resized.shape)

# print("Sum = ", np.sum(img_gray_resized))
net.blobs['data'].data[...] = img_gray_resized[np.newaxis, np.newaxis, :, :]

out = net.forward()
print(np.sum(out['prob']))
print(out['prob'].shape)
print("Number:", out['prob'].argmax())
print(out['prob'])
print(out['prob'].max())
# print(out['argmax'])

