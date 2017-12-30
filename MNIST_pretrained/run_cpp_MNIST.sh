#!/bin/sh
g++ \
    -std=c++11 \
    MNIST_test.cpp \
    -L/home/minhnd/caffe/build/lib/ -lcaffe \
    -I/home/minhnd/caffe/include \
    -I/usr/local/cuda/include \
    -lopencv_highgui \
    -lopencv_core \
    -lopencv_imgproc \
    -lboost_system \
    -lglog && ./a.out $1
