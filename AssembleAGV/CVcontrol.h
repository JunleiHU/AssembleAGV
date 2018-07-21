#pragma once
#include "stdafx.h"

using namespace cv;

struct Pose
{
	double x;
	float y;
	float z;
	float Rx;
	float Ry;
	float Rz;
};

class CVcontrol
{
public:
	CVcontrol();
	~CVcontrol();

	void OpenCamera(); //程序一开始打开

	//Pose getControllerPose();
	//Pose getBatteryPose();
	//Pose getWheelOnePose();
	//Pose getWheelTwoPose();
	//Pose getWheelThreePose();
	//Pose getWheelFourPose();

	//Pose getLineOnePose();
	//Pose getLineTwoPose();
	//Pose getLineThreePose();
	//Pose getLineFourPose();
	//Pose getLineFivePose();






private:

	//Mat handEyeCalibration(); 

	void SearchingFeaturePt();

	void computeProjectMat();

	void computeWorldCoordinate(Mat Transform, vector<Point2f> search_2D_Pt);


	VideoCapture capture;
	Mat worldMat;
	Mat imageMat;
	const Mat projectMat; //for hand eye calibration
	vector<Point3f> _3DfeaturePtList; //特征点（黑点）的世界坐标系
	vector<Point2f> _2DfeaturePtList; //



	Mat cameraMat;

	//math thing
	float* Calculata(float* a, float* b);
	bool cmpy(cv::Point const& a, cv::Point const& b);
};



