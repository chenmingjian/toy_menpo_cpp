#include "../include/AAM.h"
#include "../include/builder.hpp"

using namespace menpo;


cv::Mat _build_shape_model()
{
	return cv::Mat();
}



image _warp_images()
{
	return image();
}

std::vector<cv::Point2f> PCAModel(image)
{
	return std::vector<cv::Point2f>();
}

AAM::AAM(std::vector<image> &images, int diagonal, std::vector<float> scales, 
	void(*transform)(), std::vector<int> max_shape_components, std::vector<int> max_appearance_components,
	void(*holistic_features)() = NULL):
	diagonal(diagonal), 
	scales(scales), 
	transform(transform), 
	holistic_features(holistic_features), 
	max_shape_components(max_shape_components), 
	max_appearance_components(max_appearance_components)
{
	this->_train(&images);
}

void AAM::_train(std::vector<image> *images)
{
	std::vector<cv::Mat> shape_models;
	//this->reference_shape = compute_reference_shape();
	for (int iScale = 0; iScale < scales.size(); ++iScale)
	{
		for (auto i : *images)
		{
			//image images = rescale_images_to_reference_shape();
			image feature_images = compute_features();
			if (scales.at(iScale) != 1.0)
			{
				image scaled_images = scale_images();
			}
			else
			{
				image scaled_images = feature_images;
			}
			std::vector<cv::Point2f> scale_shapes = i.landmark();
			cv::Mat shape_model = _build_shape_model();
			shape_models.push_back(shape_model);
			std::vector<cv::Point2f> scaled_reference_shape = std::vector<cv::Point2f>();	
			image warped_images = _warp_images();

			std::vector<cv::Point2f> appearance_model = PCAModel(warped_images);
			if (max_appearance_components.at(iScale) != 0)
			{
				//auto appearance_model.trim_components(this->max_appearance_components[j]);
				//this->appearance_models.append(appearance_model);
			}
		}
	}
}



AAM::~AAM()
{
}	
