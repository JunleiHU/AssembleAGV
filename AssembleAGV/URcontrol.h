#ifndef URCONT_H        
#define URCONT_H

#include <WINSOCK2.H>     
#include <stdio.h>       
#include <string>  
#include <iostream>  
#include <sstream> 
#include <Windows.h>
using namespace std;

//定义程序中使用的常量        
#define SERVER_ADDRESS "169.254.174.117" //服务器端IP地址       
#define PORT          30003      //服务器的端口号        
#define MSGSIZE        1060       //收发缓冲区的大小       
#pragma comment(lib, "ws2_32.lib")  

class URDataHandle
{
	//定义几组全局的变量，用来实时存储当前的六个坐标值，角度值，以及机械手的状态等，以方便在任何时候调用
	//六个TCP坐标值
public:
	URDataHandle();
	~URDataHandle();

	double Positions_X;
	double Positions_Y;
	double Positions_Z;
	double Positions_RX;
	double Positions_RY;
	double Positions_RZ;

	double Force_X;
	double Force_Y;
	double Force_Z;
	double Force_RX;
	double Force_RY;
	double Force_RZ;

	double R1;
	double R2;
	double R3;
	double R4;
	double R5;
	double R6;

	//移动相对于tcp坐标系；参数1-6为原始的相对基座的坐标；7-12为
	void TCPContol(double PX, double PY, double PZ, double RX, double RY, double RZ, double PdX, double PdY, double PdZ, double RdX, double RdY, double RdZ, double a, double v);

	void TCPContol2(double PX, double PY, double PZ, double RX, double RY, double RZ, double PdX, double PdY, double PdZ, double RdX, double RdY, double RdZ, double a, double v);

	//移动到位置（参数1-6为相对于机器人基座坐标系的位姿）
	void Control(double PX, double PY, double PZ, double RX, double RY, double RZ, double a, double v);

	string ControlS(double RR1, double RR2, double RR3, double RR4, double RR5, double RR6, double t, double lookaheadtime, int gain);

	void ControlJ(double RR1, double RR2, double RR3, double RR4, double RR5, double RR6, double a, double v, double t, double r);
	void ControlL(double PX, double PY, double PZ, double RX, double RY, double RZ, double a, double v, double t, double r);

	//取得关节角度值
	void GetJoint();

	//取得TCP的受力
	void GetTCPForce();

	//取得TCP位姿
	void GetTCPPositions();

	//设置TCP位姿
	void SetTCPPosition(double PX, double PY, double PZ, double PRX, double PRY, double PRZ);

	double* rpy2rotvec(double R, double P, double Y);

	void ServoC(double PX, double PY, double PZ, double RX, double RY, double RZ, double a, double v, double r);

	SOCKET connectPort502();

	string int2str(const double &int_temp);

	SOCKET Reset();

	void StopUR();

	double GetAnalogInput();

	void SetAnalogOutput(int n, float f);
	void SetDigitalOutput(int n, bool b);
	bool GetDigitalInput(int n);
	bool GetDigitalOutput(int n);

private:
	int _msg_id;

};

#endif
