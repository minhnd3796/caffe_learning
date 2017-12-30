g++ \
    classification.cpp \
    -DUSE_OPENCV \
    -lboost_system \
    -lglog \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -L/home/minhnd/caffe/build/lib/ -lcaffe \
    -I/home/minhnd/caffe/include \
    -I/usr/local/cuda/include \
    -o classify.out