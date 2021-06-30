#pragma once
#include <iostream>
#include "cv.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Utils/util.h"

#define Max_Pix 255.0
#define Min_Pix 0.0
#define Inf_Num 0.00001

using namespace std;

//! Notification : image as a 3 channels matrix in OpenCV has the R,G,B index as 2, 1, 0
//! besides, we stock converted L,a,b channel in index of matrix as 0, 1, 2
//! RGB -> Lab : [0 256] of int give a range of L[-3.64672,9.59555] a[-2.21439,1.98422] b[-0.470511,0.467668]
//! besides, only the range of channel L is extended with the step refining

namespace ColorSpace
{
	//! ===== (uchar) RGB <---> (double) RGB
	cv::Mat uRGB2dRGB(cv::Mat srcImage);
	cv::Mat dRGB2uRGB(cv::Mat srcImage);

	//! ===== RGB <---> YCbCr
	cv::Mat RGB2YCbCr(cv::Mat srcImage);   //data type: uchar/double->double
	cv::Mat YCbCr2RGB(cv::Mat srcImage);   //data type: double->uchar
	cv::Mat RGB2YCbCr(const cv::Mat &srcImage, const vector<int> &roiIndexs);
	cv::Mat YCbCr2RGB(const cv::Mat &srcImage, const vector<int> &roiIndexs);
	cv::Vec3i YCbCr2BGR(double Y, double Cb, double Cr);
	cv::Vec3d RGB2YCbCr(uchar R, uchar G, uchar B);
};

