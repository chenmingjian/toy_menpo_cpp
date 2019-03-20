#include <iostream>
#include <opencv2/core.hpp>
#include <typeinfo>

using namespace cv;
using namespace std;
int main()
{
	vector<vector<Point2f> > shapes;

	for (int i = 0; i < 150; ++i)
	{
		vector<Point2f> shape;
		for (int j = 0; j < 19; ++j)
		{
			shape.push_back(Point2f(18 -j, j));
		}
		shapes.push_back(shape);
	}
	Mat all;
	for (auto s : shapes)
	{
		Mat mat = Mat(s);
		all.push_back(mat.t());
	}

	cv::Mat sum_rows;
	cv::reduce(all, sum_rows, 0, cv::REDUCE_SUM);
	auto a = sum_rows / all.rows;
	cv::Mat result(a);
	cout << sum_rows << endl;
	cout << result << endl;
	cout << "row=" << result.rows << endl;
	cout << "cols=" << result.cols << endl;
    std::cout << "Hello World!\n"; 
}