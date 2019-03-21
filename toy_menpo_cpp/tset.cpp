#include <iostream>
#include <opencv2/core.hpp>
#include <typeinfo>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;
int main()
{
	Ptr<xfeatures2d::SIFT> f2d = xfeatures2d::SIFT::create();

	auto img = imread("C:\\Users\\chen\\Desktop\\data_set\\RawImage\\TrainingData\\001.bmp", 1);

}