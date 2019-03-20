#pragma once
#include "../include/image.h"

namespace menpo
{
	image compute_features()
	{
		return image();
	}

	image scale_images()
	{
		return image();
	}

	cv::Mat compute_reference_shape(cv::Mat shapes, int diagonal=0)
	{
		//cv::Mat mat = cv::Mat(shapes);
		cv::Mat sum_rows;
		cv::reduce(shapes, sum_rows, 0, cv::ReduceTypes::REDUCE_SUM);
		cv::Mat result(sum_rows / shapes.rows);
		if (diagonal != 0)
		{
			std::vector<cv::Mat> splitXY;
			cv::split(result, splitXY);
			auto xs = splitXY.at(0);
			auto ys = splitXY.at(1);
			double minx, maxx, miny, maxy;
			cv::minMaxLoc(xs, &minx, &maxx);
			cv::minMaxLoc(ys, &miny, &maxy);
			auto x = maxx - minx;
			auto y = maxy - miny;
			auto scale = diagonal / sqrt(pow(x, 2) + pow(y, 2));
			result = result * scale;
		}
		return 	result;
	}

	image rescale_images_to_reference_shape(std::vector<image> images, cv::Mat reference_shape)
	{
		for (auto i : images)
		{
			auto scale = cv::norm(i.landmark()) / cv::norm(reference_shape);
			//i.rescale(scale);
		}
		return image();
	}
}