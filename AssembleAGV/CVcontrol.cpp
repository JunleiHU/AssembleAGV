#include "stdafx.h"
#include "CVcontrol.h"


CVcontrol::CVcontrol()
{
	worldMat = (Mat_<float>(4, 3) << -239.52, -325.84, 0, -335.4, -430.81, 0, -457.4, -322, 0, -349.3, -217.29, 0);
	imageMat = (Mat_<float>(4, 2) << 690, 660, 277, 658, 274, 185, 711, 213);
}


CVcontrol::~CVcontrol()
{
}

void CVcontrol::OpenCamera(){
	VideoCapture usbCap(1);
	if (!usbCap.isOpened())
	{
		std::cout << "Cannot open the camera" << std::endl;
	}
	else{
		usbCap.set(CV_CAP_PROP_FRAME_WIDTH, 2048);
		usbCap.set(CV_CAP_PROP_FRAME_HEIGHT, 1536);
		std::cout << "Open camera successfully!";
		capture = usbCap;
	}
}


void CVcontrol::computeProjectMat(vector<Point3f> worldPts){
	imageMat = (Mat_<float>(4, 2) << _2DPtHandEyeCali[0].x, _2DPtHandEyeCali[0].y,
		_2DPtHandEyeCali[1].x, _2DPtHandEyeCali[1].y,
		_2DPtHandEyeCali[2].x, _2DPtHandEyeCali[2].y,
		_2DPtHandEyeCali[3].x, _2DPtHandEyeCali[3].y);

	worldMat = (Mat_<float>(4, 3) << worldPts[0].x, worldPts[0].y, worldPts[0].z,
		worldPts[1].x, worldPts[1].y, worldPts[1].z, 
		worldPts[2].x, worldPts[2].y, worldPts[2].z, 
		worldPts[3].x, worldPts[3].y, worldPts[3].z);

	cv::Mat tvecsMat;
	cv::Mat rvecsMat;
	cv::Mat RT;
	solvePnP(worldMat, imageMat, cameraMat, cv::noArray(), rvecsMat, tvecsMat);
	Rodrigues(rvecsMat, rvecsMat);
	cv::hconcat(rvecsMat, tvecsMat, RT);
	projectMat = cameraMat*RT;
}


void CVcontrol::SearchingFeaturePt(){
	Mat frame1, frame;
	capture >> frame1;
	while (1)
	{
		capture >> frame1;
		if (!frame1.data)
		{
			continue;
		}
		else
		{
			resize(frame1, frame, Size(1024, 768));
			break;
		}
	}
	//得到待标定的图像
	try{
		Mat srcImage = frame;
		Mat midImage, dstImage;
		cvtColor(srcImage, midImage, CV_BGR2GRAY);
		Mat ROI = midImage(Rect(150, 200, 600, 500));
		//根据实际情况进行调整
		vector<Vec3f> circles;
		vector<Point2f> Coordinate;
		HoughCircles(ROI, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 45, 0, 0);
		//根据实际情况进行调整
		for (size_t i = 0; i < circles.size(); i++)
		{
			Point center(cvRound(circles[i][0] + 150), cvRound(circles[i][1] + 200));
			int radius = cvRound(circles[i][2]);
			if (radius < 20)
			{
				//绘制圆心
				circle(srcImage, center, 3, Scalar(0, 255, 0), -1, 8, 0);
				//绘制圆轮廓
				circle(srcImage, center, radius, Scalar(155, 50, 255), 3, 8, 0);
				//偏置值与ROI的坐标相对应，根据实际情况调整
				Coordinate.push_back(center);
				//加判断语句，保证检测到的角点为小车特征角点
			}
		}
		Point topone, bottomone;
		topone = Coordinate[0];
		bottomone = Coordinate[0];
		for (size_t j = 0; j < Coordinate.size(); j++)
		{
			if (Coordinate[j].y>topone.y)
			{
				topone = Coordinate[j];
			}
			if (Coordinate[j].y<bottomone.y)
			{
				bottomone = Coordinate[j];
			}
		}
		circle(srcImage, topone, 3, Scalar(0, 0, 255), -1, 8, 0); //
		circle(srcImage, bottomone, 3, Scalar(0, 0, 255), -1, 8, 0); //
		_2DfeaturePtList.push_back(topone);
		_2DfeaturePtList.push_back(bottomone);
		int count = 1;
		while (count > 0)
		{
			imshow("ROI", ROI);
			imshow("特征点寻找", srcImage);
			count = count - 1;
			waitKey(100);
		}
	}
	catch (std::exception ex){
		std::cout << "没有检测到特征点";
	}
}


void CVcontrol::computeWorldCoordinate(Mat Transform, vector<Point2f> search_2D_Pt){
	float platform = 0;
	float carheight = 35;//待定
	float cameraheight = 684;
	for (int i = 0; i < search_2D_Pt.size(); i++)
	{
		Mat point = Mat_<double>(search_2D_Pt[i]);
		//cout << point;
		std::cout << point.ptr<double>(0)[0] << std::endl << point.ptr<double>(1)[0];
		float b[2] = { point.ptr<double>(0)[0] * cameraheight - Transform.ptr<double>(0)[3] - Transform.ptr<double>(0)[2] * platform, point.ptr<double>(1)[0] * cameraheight - Transform.ptr<double>(1)[3] - Transform.ptr<double>(1)[2] * platform };
		float a[4] = { Transform.ptr<double>(0)[0], Transform.ptr<double>(0)[1], Transform.ptr<double>(1)[0], Transform.ptr<double>(1)[1] };
		float *world = Calculata(a, b);
		float biaoding[2] = { world[0], world[1] };
		Point3f worldxy;
		worldxy.x = biaoding[0];
		worldxy.y = biaoding[1];
		worldxy.z = carheight;
		_3DfeaturePtList.push_back(worldxy);
	}
}




void CVcontrol::handEyeCalibration(){
	Mat frame1, frame;
	vector<Vec3f> circles;
	vector<Point2f> Coordinate;
	while (Coordinate.size() != 1)
	{
		Coordinate.clear();
		capture >> frame1;
		while (1)
		{
			capture >> frame1;
			if (!frame1.data)
			{
				continue;
			}
			else
			{
				resize(frame1, frame, Size(1024, 768));
				break;
			}
		}
		//得到待标定的图像
		try{
			Mat srcImage = frame;
			Mat midImage, dstImage;
			cvtColor(srcImage, midImage, CV_BGR2GRAY);
			Mat ROI = midImage(Rect(150, 200, 600, 500));
			//根据实际情况进行调整
			HoughCircles(ROI, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 45, 0, 0);
			//根据实际情况进行调整
			for (size_t i = 0; i < circles.size(); i++)
			{
				Point center(cvRound(circles[i][0] + 150), cvRound(circles[i][1] + 200));
				int radius = cvRound(circles[i][2]);
				if (radius < 20)
				{
					//绘制圆心
					circle(srcImage, center, 3, Scalar(0, 255, 0), -1, 8, 0);
					//绘制圆轮廓
					circle(srcImage, center, radius, Scalar(155, 50, 255), 3, 8, 0);
					//偏置值与ROI的坐标相对应，根据实际情况调整
					Coordinate.push_back(center);
					//加判断语句，保证检测到的角点为小车特征角点
				}
			}
			int count = 1;
			while (count > 0)
			{
				imshow("ROI", ROI);
				imshow("特征点寻找", srcImage);
				count = count - 1;
				waitKey(100);
			}
		}
		catch (std::exception ex){
			std::cout << "没有检测到特征点";
		}
	}
	_2DPtHandEyeCali.push_back(Coordinate[0]);
}


//Pose CVcontrol::getControllerPose(){
//}






float* CVcontrol::Calculata(float* a, float* b)
{
	CvMat *Mb = cvCreateMat(2, 1, CV_32FC1);  //创建 6行1列 矩阵Mb
	cvSetData(Mb, b, CV_AUTOSTEP);    //给矩阵复制
	CvMat  *Ma = cvCreateMat(2, 2, CV_32FC1); //左边的坐标矩阵  
	cvSetData(Ma, a, CV_AUTOSTEP);
	CvMat* Mx = cvCreateMat(2, 1, CV_32FC1); //要求解的矩阵  
	cvSolve(Ma, Mb, Mx, CV_LU); // solve (Ax=b) for x  
	float result[2];
	for (int i = 0; i<2; i++)
	{
		result[i] = Mx->data.fl[i];
	}
	cvReleaseMat(&Ma);
	cvReleaseMat(&Mb);
	cvReleaseMat(&Mx);
	return result;
}

bool CVcontrol::cmpy(cv::Point const& a, cv::Point const& b)
{
	return a.x < b.x;
}


