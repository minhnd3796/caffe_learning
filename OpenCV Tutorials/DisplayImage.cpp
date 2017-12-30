#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    
    Mat image = imread(argv[1], 0);
    
    if (!image.data)
    {
        printf("No image data!\n");
        return -1;
    }

    cout << "Size =" << endl << image.size() << endl;
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);

    waitKey(0);
    return 0;
}