// g++ MNIST_test.cpp -L/home/minhnd/Desktop/caffe/build/lib/-lcaffe -I/home/minhnd/Desktop/caffe/include -I/usr/local/cuda/include -lopencv_imgcodecs -lopencv_core -lboost_system

#include <iostream>
#include <caffe/caffe.hpp>
#include <opencv2/opencv.hpp>

bool PairCompare(const std::pair<float, int>& lhs,
                        const std::pair<float, int>& rhs) {
  return lhs.first > rhs.first;
}

std::vector<int> Argmax(const std::vector<float>& v, int N) {
  std::vector<std::pair<float, int> > pairs;
  for (size_t i = 0; i < v.size(); ++i)
    pairs.push_back(std::make_pair(v[i], i));
  std::partial_sort(pairs.begin(), pairs.begin() + N, pairs.end(), PairCompare);

  std::vector<int> result;
  for (int i = 0; i < N; ++i)
    result.push_back(pairs[i].second);
  return result;
}

int main(int argc, char *argv[])
{
    int num_channels_input; // number of color channel
    caffe::Caffe::set_mode(caffe::Caffe::CPU); // use CPU only
    cv::Mat img = cv::imread("sketch-5.png", CV_LOAD_IMAGE_GRAYSCALE); // image variable
    std::shared_ptr<caffe::Net<float> > net_; // declare a network variable

    net_.reset(new caffe::Net<float>("lenet_deploy.prototxt", caffe::TEST)); // network architecture
    net_->CopyTrainedLayersFrom("lenet_iter_10000.caffemodel"); // pretrained weights

    caffe::Blob<float>* input_layer = net_->input_blobs()[0];
    num_channels_input = input_layer->channels(); // number of colour channel


    /* cv::Mat sample;
    if (img.channels() == 3 && num_channels_ == 1)
        cv::cvtColor(img, sample, cv::COLOR_BGR2GRAY);
    else if (img.channels() == 4 && num_channels_ == 1)
        cv::cvtColor(img, sample, cv::COLOR_BGRA2GRAY);
    else
        sample = img; */
    
    
    cv::Mat img_resized;
    cv::Size input_size = cv::Size(28, 28);
    cv::resize(img, img_resized, input_size);

    /* cv::namedWindow("Preview Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Preview Image", cv::Scalar::all(255) - img_resized);
    cv::waitKey(0); */

    cv::Mat sample_float;
    img_resized.convertTo(sample_float, CV_32FC1);
    std::vector<cv::Mat> input_channels;
    float* input_data = input_layer->mutable_cpu_data();
    cv::Mat channel(28, 28, CV_32FC1, input_data);
    input_channels.push_back(channel);
    cv::split(sample_float, input_channels);
    /* for (int i = 0; i < 784; i++)
    {
        std::cout << net_->input_blobs()[0]->cpu_data()[i] << " ";
    }
    std::cout << std::endl; */
    /* float* input_data = input_layer->mutable_cpu_data();
    for (int i = 0; i < 28 * 28; i++)
    {
        std::cout << input_data[i] << " ";
    }
    std::cout << std::endl; */
    // net_->input_blobs()[0]->cpu_data() = sample_float;

    net_->Forward();
    caffe::Blob<float>* output_layer = net_->output_blobs()[0];
    const float* begin = output_layer->cpu_data();
    const float* end = begin + output_layer->channels();
    std::vector<float> output(begin, end);

    std::vector<int> maxN = Argmax(output, 10);

    for(int n : maxN)
    {
        std::cout << n << std::endl;
    }

    /* std::cout << "Image size: Width: " << img.size().width << " Height: " << img.size().height << std::endl;
    std::cout << "Number of channels in the loaded image: " << img.channels() << std::endl;
    std::cout << "Number of channels in the input layer: " << num_channels_input << std::endl;
    std::cout << "Size of input layer: " << input_layer->width() << " " << input_layer->height() << std::endl; */
    return 0;
}
