g++ \
    classification.cpp \
    -DUSE_OPENCV \
    -DCPU_ONLY \
    -lboost_system \
    -lglog \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_imgcodecs \
    -L/home/minhnd/Desktop/caffe/build/lib/ -lcaffe \
    -I/home/minhnd/Desktop/caffe/include \
    -I/usr/local/cuda/include \
    -o classify.out