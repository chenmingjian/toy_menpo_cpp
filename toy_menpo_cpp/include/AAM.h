#pragma once
#include "../include/image.h"
#include <iostream>


namespace menpo {
	class AAM
	{
		public:
			
			AAM(std::vector<image>& images, int diagonal, std::vector<float> scales, void(*transform)(), std::vector<int> max_shape_components, std::vector<int> max_appearance_components, void(*holistic_features)());
			void _train(std::vector<image>* images);
			~AAM();

		public:  //fuction 

		private:  //fuction

		private:  //property
			int diagonal;
			std::vector<float> scales;
			void(*transform)();
			void(*holistic_features)();
			std::vector<int> max_shape_components;
			std::vector<int> max_appearance_components;
			std::vector<cv::Point2f> reference_shape;
	};

}