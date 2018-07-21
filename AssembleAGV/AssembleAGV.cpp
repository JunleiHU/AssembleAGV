// AssembleAGV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "URcontrol.h"
#include "CVcontrol.h"



Mat handEyeCalibration(){
	
}


int main()
{
	URDataHandle UR;
	CVcontrol CVcont;
	CVcont.OpenCamera();


	// ÷—€±Í∂®

	UR.Control(1, 1, 1, 1, 1, 1, 0.1, 0.1);
	Sleep(5000);
	CVcont.handEyeCalibration();
	Sleep(1000);
	UR.Control(2, 2, 2, 2, 2, 2, 0.1, 0.1);
	Sleep(5000);
	CVcont.handEyeCalibration();
	Sleep(1000);
	UR.Control(3, 3, 3, 3, 3, 3, 0.1, 0.1);
	Sleep(5000);
	CVcont.handEyeCalibration();
	Sleep(1000);
	UR.Control(4,4,4,4,4,4, 0.1, 0.1);
	Sleep(5000);
	CVcont.handEyeCalibration();
	Sleep(1000);
	
	



	
	
	
	
	
	system("pause");

}
