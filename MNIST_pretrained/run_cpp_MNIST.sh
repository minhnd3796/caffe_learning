#!/bin/sh
g++ MNIST_test.cpp -L/home/minhnd/Desktop/caffe/build/lib/-lcaffe -I/home/minhnd/Desktop/caffe/include -I/usr/local/cuda/include -lopencv_imgcodecs -lopencv_highgui -lopencv_core -lopencv_imgproc -lboost_system -lglog && ./a.out