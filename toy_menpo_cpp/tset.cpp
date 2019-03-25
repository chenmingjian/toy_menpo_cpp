#include <iostream>
#include <typeinfo>
#include <opencv2/opencv.hpp>



int main()
{
	cv::Mat img = cv::imread("C:\\Users\\chen\\Desktop\\data_set\\RawImage\\TrainingData\\001.bmp", 1);
	img = img / 255;
	return 0;
}