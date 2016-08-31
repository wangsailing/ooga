#pragma once

const double PI = 3.1415926535898;

#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <vector>

#include "PerformanceTimer.h"

//to counter Miika's non-standard C++ definiton of dynamic arrays
template <typename T>
T* makeDynArray(int sz) {
	T* arr = new T[sz];
	return arr;
}

template<typename T>
void delDynArray(T* arr) {
	delete[] arr;
}

//cv::Mat log_mvnpdf(cv::Mat x, cv::Mat mu, cv::Mat C);

class GlintFinder
{
public:
	GlintFinder();
	~GlintFinder();

	//void Initialize();
	void Initialize(cv::Mat initCM, float initMU_X[], float initMU_Y[], int muSize);
	void setCropWindowSize(int xmin, int ymin, int width, int height);

	//moved MU's and CM here, remove from parameters
	//std::vector<cv::Point2d> getGlints(cv::UMat eyeImage_diff,
	//	cv::Point2d pupil_center,
	//	std::vector<cv::Point2d> glintPoints_prev,
	//	float theta, float MU_X[], float MU_Y[], cv::Mat CM, cv::Mat glint_kernel,
	//	double &score, float loglhoods[], float glint_beta, float glint_reg_coef);
	std::vector<cv::Point2d> getGlints(cv::UMat eyeImage_diff,
		cv::Point2d pupil_center,
		std::vector<cv::Point2d> glintPoints_prev,
		float theta, cv::Mat glint_kernel,
		double &score, float loglhoods[], float glint_beta, float glint_reg_coef);

private:
	int cropminX;
	int cropminY;
	int cropsizeX;
	int cropsizeY;

	cv::UMat eyeImage_filtered;
	cv::UMat eyeImage_filtered_clone;
	cv::UMat eyeImage_aux;
	cv::UMat eyeImage_cropped;
	cv::UMat eyeImage_aux_crop;

	//load these in init
	//these should be moved here?

	float MU_X[6], MU_Y[6];
	cv::Mat CM;

	TPerformanceTimer* pt;

};
