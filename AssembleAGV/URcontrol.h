#ifndef URCONT_H        
#define URCONT_H

#include <WINSOCK2.H>     
#include <stdio.h>       
#include <string>  
#include <iostream>  
#include <sstream> 
#include <Windows.h>
using namespace std;

//���������ʹ�õĳ���        
#define SERVER_ADDRESS "169.254.174.117" //��������IP��ַ       
#define PORT          30003      //�������Ķ˿ں�        
#define MSGSIZE        1060       //�շ��������Ĵ�С       
#pragma comment(lib, "ws2_32.lib")  

class URDataHandle
{
	//���弸��ȫ�ֵı���������ʵʱ�洢��ǰ����������ֵ���Ƕ�ֵ���Լ���е�ֵ�״̬�ȣ��Է������κ�ʱ�����
	//����TCP����ֵ
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

	//�ƶ������tcp����ϵ������1-6Ϊԭʼ����Ի��������ꣻ7-12Ϊ
	void TCPContol(double PX, double PY, double PZ, double RX, double RY, double RZ, double PdX, double PdY, double PdZ, double RdX, double RdY, double RdZ, double a, double v);

	void TCPContol2(double PX, double PY, double PZ, double RX, double RY, double RZ, double PdX, double PdY, double PdZ, double RdX, double RdY, double RdZ, double a, double v);

	//�ƶ���λ�ã�����1-6Ϊ����ڻ����˻�������ϵ��λ�ˣ�
	void Control(double PX, double PY, double PZ, double RX, double RY, double RZ, double a, double v);

	string ControlS(double RR1, double RR2, double RR3, double RR4, double RR5, double RR6, double t, double lookaheadtime, int gain);

	void ControlJ(double RR1, double RR2, double RR3, double RR4, double RR5, double RR6, double a, double v, double t, double r);
	void ControlL(double PX, double PY, double PZ, double RX, double RY, double RZ, double a, double v, double t, double r);

	//ȡ�ùؽڽǶ�ֵ
	void GetJoint();

	//ȡ��TCP������
	void GetTCPForce();

	//ȡ��TCPλ��
	void GetTCPPositions();

	//����TCPλ��
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
