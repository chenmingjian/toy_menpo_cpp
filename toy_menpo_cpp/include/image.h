#pragma once
#include <opencv2/core.hpp>  
#include <iostream>


namespace menpo {
	class image
	{
	public:
		image();
		std::vector<cv::Point2f> &landmark();

		~image();
	private:
		std::vector<cv::Point2f> _landmark;
	};

}