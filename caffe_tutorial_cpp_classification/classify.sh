# params
# *.prototxt    - model_file
# *.caffemodel  - trained_file
# *.binaryproto - mean_file
# *.txt         - label_file
# $1            - file (image file)
./classify.out \
    deploy.prototxt \
    bvlc_reference_caffenet.caffemodel \
    imagenet_mean.binaryproto \
    synset_words.txt \
    $1