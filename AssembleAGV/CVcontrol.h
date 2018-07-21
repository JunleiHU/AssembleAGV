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

	void OpenCamera(); //����һ��ʼ��

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
	
	void handEyeCalibration(); 

	void computeProjectMat(vector<Point3f>);  //���۱궨��ʹ��



private:

	

	void SearchingFeaturePt();

	

	void computeWorldCoordinate(Mat Transform, vector<Point2f> search_2D_Pt);


	VideoCapture capture;
	Mat worldMat;
	Mat imageMat;
	Mat projectMat; //for hand eye calibration
	vector<Point3f> _3DfeaturePtList; //�����㣨�ڵ㣩����������ϵ
	vector<Point2f> _2DfeaturePtList; //


	vector<Point2f> _2DPtHandEyeCali;



	const Mat cameraMat;

	//math thing
	float* Calculata(float* a, float* b);
	bool cmpy(cv::Point const& a, cv::Point const& b);
};



