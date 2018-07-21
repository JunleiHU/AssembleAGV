// AssembleAGV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "URcontrol.h"

int main()
{
	URDataHandle a;

	double ang_start[6] = { 200.0, -90.0, -100.0, -20.0, 60.0, 200.0 };
	double ang_getBody[6] = { 214.44, -108.34, -90.48, -31.15, 95.13, 170.67 };
	double ang_putTable[6] = { 235.71, -89.46, -105.27, -77.09, 90.68, 189.68 };
	double ang_getController[6] = { 253.75, -102.65, -104.45, -24.35, 70.60, 201.85 };
	double ang_inter[6] = { 249.18, -88.40, -85.58, -69.60, 88.57, 193.22 };
	double ang_putCtrlOnBody[6] = { 237.42, -84.99, -103.80, -84.20, 88.74, 193.24 };
	double ang0[6] = { -5.04, -86.21, 80.47, -82.98, -90.5, 0 };
	double ang1[6] = { -1.38, -31.37, 26.54, -86.64, -90.48 };
	double ang2[6] = { 16.51, -35.05, 26.41, -81.83, -90.49, 90 };
	std::cout << "success!";
	a.SetDigitalOutput(0, false);
	a.GetJoint();
	a.ControlJ(ang_start[0] / 57.3,
		ang_start[1] / 57.3,
		ang_start[2] / 57.3,
		ang_start[3] / 57.3,
		ang_start[4] / 57.3,
		ang_start[5] / 57.3,
		0.5, 0.5, 0, 0);  //Ô­µã
	Sleep(5000);
	a.SetDigitalOutput(0, true);
	a.ControlJ(ang_getBody[0] / 57.3,
		ang_getBody[1] / 57.3,
		ang_getBody[2] / 57.3,
		ang_getBody[3] / 57.3,
		ang_getBody[4] / 57.3,
		ang_getBody[5] / 57.3,
		0.5, 0.5, 0, 0);
	Sleep(5000);
	//start to grab body
	a.GetTCPPositions();
	a.TCPContol(a.Positions_X, a.Positions_Y, a.Positions_Z, a.Positions_RX, a.Positions_RY, a.Positions_RZ,
		0, 0, 0.045, 0, 0, 0, 0.1, 0.1);
	Sleep(2000);
	a.SetDigitalOutput(0, false);//±ÕºÏ
	Sleep(1000);
	a.GetTCPPositions();
	a.TCPContol(a.Positions_X, a.Positions_Y, a.Positions_Z, a.Positions_RX, a.Positions_RY, a.Positions_RZ,
		0, 0, -0.1, 0, 0, 0, 0.1, 0.1);
	Sleep(2000);
	a.ControlJ(ang_putTable[0] / 57.3,
		ang_putTable[1] / 57.3,
		ang_putTable[2] / 57.3,
		ang_putTable[3] / 57.3,
		ang_putTable[4] / 57.3,
		ang_putTable[5] / 57.3,
		0.5, 0.5, 0, 0);
	Sleep(5000);
	a.SetDigitalOutput(0, true);
	Sleep(1500);
	a.GetTCPPositions();
	a.TCPContol(a.Positions_X, a.Positions_Y, a.Positions_Z, a.Positions_RX, a.Positions_RY, a.Positions_RZ,
		0, 0, -0.1, 0, 0, 0, 0.1, 0.1);
	Sleep(5000);
	//to grab the controller
	a.SetDigitalOutput(0, true);
	a.ControlJ(ang_getController[0] / 57.3,
		ang_getController[1] / 57.3,
		ang_getController[2] / 57.3,
		ang_getController[3] / 57.3,
		ang_getController[4] / 57.3,
		ang_getController[5] / 57.3,
		0.5, 0.5, 0, 0);
	Sleep(5000);
	a.GetTCPPositions();
	a.TCPContol(a.Positions_X, a.Positions_Y, a.Positions_Z, a.Positions_RX, a.Positions_RY, a.Positions_RZ,
		0, 0, 0.05, 0, 0, 0, 0.1, 0.1);
	Sleep(1500);
	a.SetDigitalOutput(0, false);
	Sleep(500);
	a.GetTCPPositions();
	a.TCPContol(a.Positions_X, a.Positions_Y, a.Positions_Z, a.Positions_RX, a.Positions_RY, a.Positions_RZ,
		0, 0, -0.1, 0, 0, 0, 0.1, 0.1);
	Sleep(1500);
	a.ControlJ(ang_inter[0] / 57.3,
		ang_inter[1] / 57.3,
		ang_inter[2] / 57.3,
		ang_inter[3] / 57.3,
		ang_inter[4] / 57.3,
		ang_inter[5] / 57.3,
		0.15, 0.15, 0, 0);
	Sleep(5000);
	a.ControlJ(ang_putCtrlOnBody[0] / 57.3,
		ang_putCtrlOnBody[1] / 57.3,
		ang_putCtrlOnBody[2] / 57.3,
		ang_putCtrlOnBody[3] / 57.3,
		ang_putCtrlOnBody[4] / 57.3,
		ang_putCtrlOnBody[5] / 57.3,
		0.15, 0.15, 0, 0);
	Sleep(5000);
	a.GetTCPPositions();
	a.TCPContol(a.Positions_X, a.Positions_Y, a.Positions_Z, a.Positions_RX, a.Positions_RY, a.Positions_RZ,
		0, 0, 0.02, 0, 0, 0, 0.1, 0.1);
	Sleep(1500);
	a.SetDigitalOutput(0, true);
	a.GetTCPPositions();
	a.TCPContol(a.Positions_X, a.Positions_Y, a.Positions_Z, a.Positions_RX, a.Positions_RY, a.Positions_RZ,
		0, 0, -0.04, 0, 0, 0, 0.1, 0.1);
	Sleep(2000);
	a.SetDigitalOutput(0, false);
	a.GetTCPPositions();
	a.TCPContol(a.Positions_X, a.Positions_Y, a.Positions_Z, a.Positions_RX, a.Positions_RY, a.Positions_RZ,
		0, 0, 0.025, 0, 0, 0, 0.1, 0.1);


	system("pause");

}
