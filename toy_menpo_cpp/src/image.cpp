#include "..\include\image.h"
using namespace menpo;


image::image()
{
}


image::~image()
{
}


std::vector<cv::Point2f>& image::landmark()
{
	return _landmark;
}