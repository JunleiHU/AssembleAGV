#include "stdafx.h"
#include "URcontrol.h"
#include <cmath>



URDataHandle::URDataHandle()
{
	_msg_id = 1;
}


URDataHandle::~URDataHandle()
{
}


void URDataHandle::GetJoint()
{
	SOCKET sClient = Reset();

	char receiveBuf[MSGSIZE];
	int A = recv(sClient, receiveBuf, MSGSIZE, 0);
	int data[MSGSIZE];

	for (int i = 0; i < MSGSIZE; i++)//逐个输出每个元素。
	{
		data[i] = receiveBuf[i];
	}

	int a1 = 259;
	unsigned char pxArray[8] = { data[a1], data[a1 - 1], data[a1 - 2], data[a1 - 3], data[a1 - 4], data[a1 - 5], data[a1 - 6], data[a1 - 7] };
	unsigned char* px = (unsigned char*)&R1;
	px[0] = pxArray[0];
	px[1] = pxArray[1];
	px[2] = pxArray[2];
	px[3] = pxArray[3];
	px[4] = pxArray[4];
	px[5] = pxArray[5];
	px[6] = pxArray[6];
	px[7] = pxArray[7];

	int a2 = a1 + 8;
	unsigned char pyArray[8] = { data[a2], data[a2 - 1], data[a2 - 2], data[a2 - 3], data[a2 - 4], data[a2 - 5], data[a2 - 6], data[a2 - 7] };
	unsigned char* py = (unsigned char*)&R2;
	py[0] = pyArray[0];
	py[1] = pyArray[1];
	py[2] = pyArray[2];
	py[3] = pyArray[3];
	py[4] = pyArray[4];
	py[5] = pyArray[5];
	py[6] = pyArray[6];
	py[7] = pyArray[7];

	int a3 = a2 + 8;
	unsigned char pzArray[8] = { data[a3], data[a3 - 1], data[a3 - 2], data[a3 - 3], data[a3 - 4], data[a3 - 5], data[a3 - 6], data[a3 - 7] };
	unsigned char* pz = (unsigned char*)&R3;
	pz[0] = pzArray[0];
	pz[1] = pzArray[1];
	pz[2] = pzArray[2];
	pz[3] = pzArray[3];
	pz[4] = pzArray[4];
	pz[5] = pzArray[5];
	pz[6] = pzArray[6];
	pz[7] = pzArray[7];

	int a4 = a3 + 8;
	unsigned char prxArray[8] = { data[a4], data[a4 - 1], data[a4 - 2], data[a4 - 3], data[a4 - 4], data[a4 - 5], data[a4 - 6], data[a4 - 7] };
	unsigned char* prx = (unsigned char*)&R4;
	prx[0] = prxArray[0];
	prx[1] = prxArray[1];
	prx[2] = prxArray[2];
	prx[3] = prxArray[3];
	prx[4] = prxArray[4];
	prx[5] = prxArray[5];
	prx[6] = prxArray[6];
	prx[7] = prxArray[7];

	int a5 = a4 + 8;
	unsigned char pryArray[8] = { data[a5], data[a5 - 1], data[a5 - 2], data[a5 - 3], data[a5 - 4], data[a5 - 5], data[a5 - 6], data[a5 - 7] };
	unsigned char* pry = (unsigned char*)&R5;
	pry[0] = pryArray[0];
	pry[1] = pryArray[1];
	pry[2] = pryArray[2];
	pry[3] = pryArray[3];
	pry[4] = pryArray[4];
	pry[5] = pryArray[5];
	pry[6] = pryArray[6];
	pry[7] = pryArray[7];

	int a6 = a5 + 8;
	unsigned char przArray[8] = { data[a6], data[a6 - 1], data[a6 - 2], data[a6 - 3], data[a6 - 4], data[a6 - 5], data[a6 - 6], data[a6 - 7] };
	unsigned char* prz = (unsigned char*)&R6;
	prz[0] = przArray[0];
	prz[1] = przArray[1];
	prz[2] = przArray[2];
	prz[3] = przArray[3];
	prz[4] = przArray[4];
	prz[5] = przArray[5];
	prz[6] = przArray[6];
	prz[7] = przArray[7];

	closesocket(sClient);
	WSACleanup();

}

void URDataHandle::GetTCPPositions()
{
	SOCKET sClient = Reset();

	char receiveBuf[MSGSIZE];
	int A = recv(sClient, receiveBuf, MSGSIZE, 0);
	int data[MSGSIZE];

	for (int i = 0; i < MSGSIZE; i++)//逐个输出每个元素。
	{
		data[i] = receiveBuf[i];
	}

	int a1 = 451;
	unsigned char pxArray[8] = { data[a1], data[a1 - 1], data[a1 - 2], data[a1 - 3], data[a1 - 4], data[a1 - 5], data[a1 - 6], data[a1 - 7] };
	unsigned char* px = (unsigned char*)&Positions_X;
	px[0] = pxArray[0];
	px[1] = pxArray[1];
	px[2] = pxArray[2];
	px[3] = pxArray[3];
	px[4] = pxArray[4];
	px[5] = pxArray[5];
	px[6] = pxArray[6];
	px[7] = pxArray[7];

	int a2 = a1 + 8;
	unsigned char pyArray[8] = { data[a2], data[a2 - 1], data[a2 - 2], data[a2 - 3], data[a2 - 4], data[a2 - 5], data[a2 - 6], data[a2 - 7] };
	unsigned char* py = (unsigned char*)&Positions_Y;
	py[0] = pyArray[0];
	py[1] = pyArray[1];
	py[2] = pyArray[2];
	py[3] = pyArray[3];
	py[4] = pyArray[4];
	py[5] = pyArray[5];
	py[6] = pyArray[6];
	py[7] = pyArray[7];

	int a3 = a2 + 8;
	unsigned char pzArray[8] = { data[a3], data[a3 - 1], data[a3 - 2], data[a3 - 3], data[a3 - 4], data[a3 - 5], data[a3 - 6], data[a3 - 7] };
	unsigned char* pz = (unsigned char*)&Positions_Z;
	pz[0] = pzArray[0];
	pz[1] = pzArray[1];
	pz[2] = pzArray[2];
	pz[3] = pzArray[3];
	pz[4] = pzArray[4];
	pz[5] = pzArray[5];
	pz[6] = pzArray[6];
	pz[7] = pzArray[7];

	int a4 = a3 + 8;
	unsigned char prxArray[8] = { data[a4], data[a4 - 1], data[a4 - 2], data[a4 - 3], data[a4 - 4], data[a4 - 5], data[a4 - 6], data[a4 - 7] };
	unsigned char* prx = (unsigned char*)&Positions_RX;
	prx[0] = prxArray[0];
	prx[1] = prxArray[1];
	prx[2] = prxArray[2];
	prx[3] = prxArray[3];
	prx[4] = prxArray[4];
	prx[5] = prxArray[5];
	prx[6] = prxArray[6];
	prx[7] = prxArray[7];

	int a5 = a4 + 8;
	unsigned char pryArray[8] = { data[a5], data[a5 - 1], data[a5 - 2], data[a5 - 3], data[a5 - 4], data[a5 - 5], data[a5 - 6], data[a5 - 7] };
	unsigned char* pry = (unsigned char*)&Positions_RY;
	pry[0] = pryArray[0];
	pry[1] = pryArray[1];
	pry[2] = pryArray[2];
	pry[3] = pryArray[3];
	pry[4] = pryArray[4];
	pry[5] = pryArray[5];
	pry[6] = pryArray[6];
	pry[7] = pryArray[7];

	int a6 = a5 + 8;
	unsigned char przArray[8] = { data[a6], data[a6 - 1], data[a6 - 2], data[a6 - 3], data[a6 - 4], data[a6 - 5], data[a6 - 6], data[a6 - 7] };
	unsigned char* prz = (unsigned char*)&Positions_RZ;
	prz[0] = przArray[0];
	prz[1] = przArray[1];
	prz[2] = przArray[2];
	prz[3] = przArray[3];
	prz[4] = przArray[4];
	prz[5] = przArray[5];
	prz[6] = przArray[6];
	prz[7] = przArray[7];

	closesocket(sClient);
	WSACleanup();

}

void URDataHandle::GetTCPForce()
{
	SOCKET sClient = Reset();

	char receiveBuf[MSGSIZE];
	int A = recv(sClient, receiveBuf, MSGSIZE, 0);
	int data[MSGSIZE];

	for (int i = 0; i < MSGSIZE; i++)//逐个输出每个元素。
	{
		data[i] = receiveBuf[i];
	}

	int a1 = 547;
	unsigned char pxArray[8] = { data[a1], data[a1 - 1], data[a1 - 2], data[a1 - 3], data[a1 - 4], data[a1 - 5], data[a1 - 6], data[a1 - 7] };
	unsigned char* px = (unsigned char*)&Force_X;
	px[0] = pxArray[0];
	px[1] = pxArray[1];
	px[2] = pxArray[2];
	px[3] = pxArray[3];
	px[4] = pxArray[4];
	px[5] = pxArray[5];
	px[6] = pxArray[6];
	px[7] = pxArray[7];

	int a2 = a1 + 8;
	unsigned char pyArray[8] = { data[a2], data[a2 - 1], data[a2 - 2], data[a2 - 3], data[a2 - 4], data[a2 - 5], data[a2 - 6], data[a2 - 7] };
	unsigned char* py = (unsigned char*)&Force_Y;
	py[0] = pyArray[0];
	py[1] = pyArray[1];
	py[2] = pyArray[2];
	py[3] = pyArray[3];
	py[4] = pyArray[4];
	py[5] = pyArray[5];
	py[6] = pyArray[6];
	py[7] = pyArray[7];

	int a3 = a2 + 8;
	unsigned char pzArray[8] = { data[a3], data[a3 - 1], data[a3 - 2], data[a3 - 3], data[a3 - 4], data[a3 - 5], data[a3 - 6], data[a3 - 7] };
	unsigned char* pz = (unsigned char*)&Force_Z;
	pz[0] = pzArray[0];
	pz[1] = pzArray[1];
	pz[2] = pzArray[2];
	pz[3] = pzArray[3];
	pz[4] = pzArray[4];
	pz[5] = pzArray[5];
	pz[6] = pzArray[6];
	pz[7] = pzArray[7];

	int a4 = a3 + 8;
	unsigned char prxArray[8] = { data[a4], data[a4 - 1], data[a4 - 2], data[a4 - 3], data[a4 - 4], data[a4 - 5], data[a4 - 6], data[a4 - 7] };
	unsigned char* prx = (unsigned char*)&Force_RX;
	prx[0] = prxArray[0];
	prx[1] = prxArray[1];
	prx[2] = prxArray[2];
	prx[3] = prxArray[3];
	prx[4] = prxArray[4];
	prx[5] = prxArray[5];
	prx[6] = prxArray[6];
	prx[7] = prxArray[7];

	int a5 = a4 + 8;
	unsigned char pryArray[8] = { data[a5], data[a5 - 1], data[a5 - 2], data[a5 - 3], data[a5 - 4], data[a5 - 5], data[a5 - 6], data[a5 - 7] };
	unsigned char* pry = (unsigned char*)&Force_RY;
	pry[0] = pryArray[0];
	pry[1] = pryArray[1];
	pry[2] = pryArray[2];
	pry[3] = pryArray[3];
	pry[4] = pryArray[4];
	pry[5] = pryArray[5];
	pry[6] = pryArray[6];
	pry[7] = pryArray[7];

	int a6 = a5 + 8;
	unsigned char przArray[8] = { data[a6], data[a6 - 1], data[a6 - 2], data[a6 - 3], data[a6 - 4], data[a6 - 5], data[a6 - 6], data[a6 - 7] };
	unsigned char* prz = (unsigned char*)&Force_RZ;
	prz[0] = przArray[0];
	prz[1] = przArray[1];
	prz[2] = przArray[2];
	prz[3] = przArray[3];
	prz[4] = przArray[4];
	prz[5] = przArray[5];
	prz[6] = przArray[6];
	prz[7] = przArray[7];

	cout << "********" << endl;
	cout << "Forcex=" << Force_X << endl;
	cout << "Forcey=" << Force_Y << endl;
	cout << "Forcez=" << Force_Z << endl;
	cout << "********" << endl;

	closesocket(sClient);
	WSACleanup();

}

void URDataHandle::SetTCPPosition(double PX, double PY, double PZ, double PRX, double PRY, double PRZ)
{
	SOCKET sClient = Reset();
	string to_send = "set_tcp(p[";
	to_send += int2str(PX);
	to_send += ",";
	to_send += int2str(PY);
	to_send += ",";
	to_send += int2str(PZ);
	to_send += ",";
	to_send += int2str(PRX);
	to_send += ",";
	to_send += int2str(PRY);
	to_send += ",";
	to_send += int2str(PRZ);
	to_send += "])\n";
	send(sClient, to_send.c_str(), strlen(to_send.c_str()), 0);
	closesocket(sClient);
	WSACleanup();
}

//移动到位置（参数1-6为相对于机器人基座坐标系的位姿）
void URDataHandle::Control(double PX, double PY, double PZ, double RX, double RY, double RZ, double a, double v)
{
	SOCKET sClient = Reset();
	string to_send = "movel(p[";
	to_send += int2str(PX);
	to_send += ",";
	to_send += int2str(PY);
	to_send += ",";
	to_send += int2str(PZ);
	to_send += ",";
	to_send += int2str(RX);
	to_send += ",";
	to_send += int2str(RY);
	to_send += ",";
	to_send += int2str(RZ);
	to_send += "],a=";
	to_send += int2str(a);
	to_send += ",v=";
	to_send += int2str(v);
	to_send += ")\n";
	send(sClient, to_send.c_str(), strlen(to_send.c_str()), 0);
	closesocket(sClient);
	WSACleanup();
}

string URDataHandle::ControlS(double RR1, double RR2, double RR3, double RR4, double RR5, double RR6, double t, double lookaheadtime, int gain)
{
	SOCKET sClient = Reset();
	string to_send = "([";
	to_send += int2str(RR1);
	to_send += ",";
	to_send += int2str(RR2);
	to_send += ",";
	to_send += int2str(RR3);
	to_send += ",";
	to_send += int2str(RR4);
	to_send += ",";
	to_send += int2str(RR5);
	to_send += ",";
	to_send += int2str(RR6);
	to_send += "],t=";
	to_send += int2str(t);
	to_send += ",lookahead.time=";
	to_send += int2str(lookaheadtime);
	to_send += ",gain=";
	to_send += int2str(gain);
	to_send += ")\n";
	return to_send;
}

void URDataHandle::ControlJ(double RR1, double RR2, double RR3, double RR4, double RR5, double RR6, double a, double v, double t, double r)
{
	SOCKET sClient = Reset();
	string to_send = "movej([";
	to_send += int2str(RR1);
	to_send += ",";
	to_send += int2str(RR2);
	to_send += ",";
	to_send += int2str(RR3);
	to_send += ",";
	to_send += int2str(RR4);
	to_send += ",";
	to_send += int2str(RR5);
	to_send += ",";
	to_send += int2str(RR6);
	to_send += "],a=";
	to_send += int2str(a);
	to_send += ",v=";
	to_send += int2str(v);
	to_send += ",t=";
	to_send += int2str(t);
	to_send += ",r=";
	to_send += int2str(r);
	to_send += ")\n";

	send(sClient, to_send.c_str(), strlen(to_send.c_str()), 0);
	closesocket(sClient);
	WSACleanup();
}


void URDataHandle::ControlL(double PX, double PY, double PZ, double RX, double RY, double RZ, double a, double v, double t, double r)
{
	SOCKET sClient = Reset();
	string to_send = "movel(p[";
	to_send += int2str(PX);
	to_send += ",";
	to_send += int2str(PY);
	to_send += ",";
	to_send += int2str(PZ);
	to_send += ",";
	to_send += int2str(RX);
	to_send += ",";
	to_send += int2str(RY);
	to_send += ",";
	to_send += int2str(RZ);
	to_send += "],a=";
	to_send += int2str(a);
	to_send += ",v=";
	to_send += int2str(v);
	to_send += ",t=";
	to_send += int2str(t);
	to_send += ",r=";
	to_send += int2str(r);
	to_send += ")\n";

	send(sClient, to_send.c_str(), strlen(to_send.c_str()), 0);
	closesocket(sClient);
	WSACleanup();
}


void URDataHandle::ServoC(double PX, double PY, double PZ, double RX, double RY, double RZ, double a, double v, double r)
{
	SOCKET sClient = Reset();
	string to_send = "servoc(p[";
	to_send += int2str(PX);
	to_send += ",";
	to_send += int2str(PY);
	to_send += ",";
	to_send += int2str(PZ);
	to_send += ",";
	to_send += int2str(RX);
	to_send += ",";
	to_send += int2str(RY);
	to_send += ",";
	to_send += int2str(RZ);
	to_send += "],a=";
	to_send += int2str(a);
	to_send += ",v=";
	to_send += int2str(v);
	to_send += ",r=";
	to_send += int2str(r);
	to_send += ")\n";


	send(sClient, to_send.c_str(), strlen(to_send.c_str()), 0);
	closesocket(sClient);
	WSACleanup();
}


//移动相对于tcp坐标系；参数1-6为原始的相对基座的坐标；7-12为相对自动移动时的相对坐标
void URDataHandle::TCPContol(double PX, double PY, double PZ, double RX, double RY, double RZ, double PdX, double PdY, double PdZ, double RdX, double RdY, double RdZ, double a, double v)
{

	SOCKET sClient = Reset();
	string to_send = "pose_trans(p[";
	to_send += int2str(PX);
	to_send += ",";
	to_send += int2str(PY);
	to_send += ",";
	to_send += int2str(PZ);
	to_send += ",";
	to_send += int2str(RX);
	to_send += ",";
	to_send += int2str(RY);
	to_send += ",";
	to_send += int2str(RZ);
	to_send += "],p[";
	to_send += int2str(PdX);
	to_send += ",";
	to_send += int2str(PdY);
	to_send += ",";
	to_send += int2str(PdZ);
	to_send += ",";
	to_send += int2str(RdX);
	to_send += ",";
	to_send += int2str(RdY);
	to_send += ",";
	to_send += int2str(RdZ);
	to_send += "])";

	string cmd = "movel(";
	cmd += to_send;
	cmd += ",a=";
	cmd += int2str(a);
	cmd += ",v=";
	cmd += int2str(v);
	cmd += ")\n";

	send(sClient, cmd.c_str(), strlen(cmd.c_str()), 0);
	closesocket(sClient);
	WSACleanup();
}
void URDataHandle::TCPContol2(double PX, double PY, double PZ, double RX, double RY, double RZ, double PdX, double PdY, double PdZ, double RdX, double RdY, double RdZ, double a, double v)
{
	SOCKET sClient = Reset();
	string to_send = "pose_trans(p[";
	to_send += int2str(PX);
	to_send += ",";
	to_send += int2str(PY);
	to_send += ",";
	to_send += int2str(PZ);
	to_send += ",";
	to_send += int2str(RX);
	to_send += ",";
	to_send += int2str(RY);
	to_send += ",";
	to_send += int2str(RZ);
	to_send += "],p[";
	to_send += int2str(PdX);
	to_send += ",";
	to_send += int2str(PdY);
	to_send += ",";
	to_send += int2str(PdZ);
	to_send += ",";
	to_send += int2str(RdX);
	to_send += ",";
	to_send += int2str(RdY);
	to_send += ",";
	to_send += int2str(RdZ);
	to_send += "])";

	string cmd = "movep(";
	cmd += to_send;
	cmd += ",a=";
	cmd += int2str(a);
	cmd += ",v=";
	cmd += int2str(v);
	cmd += ")\n";

	send(sClient, cmd.c_str(), strlen(cmd.c_str()), 0);
	closesocket(sClient);
	WSACleanup();

}
void URDataHandle::StopUR()
{
	SOCKET sClient = Reset();
	string to_send = "stopl(a=";
	to_send += int2str(0.1);
	to_send += ")\n";
	send(sClient, to_send.c_str(), strlen(to_send.c_str()), 0);
	closesocket(sClient);
	WSACleanup();
}

double* URDataHandle::rpy2rotvec(double R, double P, double Y){
	double c1 = cos(P / 2);
	double s1 = sin(P / 2);
	double c2 = cos(Y / 2);
	double s2 = sin(Y / 2);
	double c3 = cos(R / 2);
	double s3 = sin(R / 2);
	double w = c1*c2*c3 - s1*s2*s3;
	double RX = c1*c2*s3 + s1*s2*c3;
	double RY = s1*c2*c3 + c1*s2*s3;
	double RZ = c1*s2*c3 - s1*c2*s3;
	double angle = 2 * acos(w);
	double norm = RX*RX + RY*RY + RZ*RZ;
	if (norm < 0.001) { // when all euler angles are zero angle =0 so
		// we can set axis to anything to avoid divide by zero
		RX = 1;
		RY = RZ = 0;
	}
	else {
		norm = sqrt(norm);
		RX /= norm;
		RY /= norm;
		RZ /= norm;
	}

	double* RXRYRZ = new double[3];
	RXRYRZ[0] = RX * angle;
	RXRYRZ[1] = RY * angle;
	RXRYRZ[2] = RZ * angle;
	cout << RX*angle << "\t" << RY*angle << "\t" << RZ*angle << endl;
	return RXRYRZ;
}


string URDataHandle::int2str(const double &int_temp)
{
	string string_temp;
	stringstream stream;
	stream << int_temp;
	string_temp = stream.str();   //此处也可以用 stream>>string_temp    
	return string_temp;
}

SOCKET URDataHandle::Reset()
{
	WSADATA wsaData;
	//连接所用套节字        
	SOCKET sClient;
	//保存远程服务器的地址信息        
	SOCKADDR_IN server;
	//收发缓冲区     

	WORD wVersionRequested;

	// Initialize Windows socket library        
	WSAStartup(0x0202, &wsaData);

	// 创建客户端套节字        
	sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //AF_INET指明使用TCP/IP协议族；        
	//SOCK_STREAM, IPPROTO_TCP具体指明使用TCP协议        
	// 指明远程服务器的地址信息(端口号、IP地址等)        
	memset(&server, 0, sizeof(SOCKADDR_IN)); //先将保存地址的server置为全0        
	server.sin_family = PF_INET; //声明地址格式是TCP/IP地址格式        
	server.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
	server.sin_port = htons(PORT); //指明连接服务器的端口号，htons()用于 converts values between the host and network byte order        

	connect(sClient, (SOCKADDR*)&server, sizeof(SOCKADDR));

	return sClient;
}

SOCKET URDataHandle::connectPort502()
{
	WSADATA wsaData;
	//连接所用套节字        
	SOCKET sClient;
	//保存远程服务器的地址信息        
	SOCKADDR_IN server;
	//收发缓冲区     

	WORD wVersionRequested;

	// Initialize Windows socket library        
	WSAStartup(MAKEWORD(1, 1), &wsaData);

	// 创建客户端套节字        
	sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //AF_INET指明使用TCP/IP协议族；        
	//SOCK_STREAM, IPPROTO_TCP具体指明使用TCP协议        
	// 指明远程服务器的地址信息(端口号、IP地址等)        
	memset(&server, 0, sizeof(SOCKADDR_IN)); //先将保存地址的server置为全0        
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
	server.sin_port = htons(502); //指明连接服务器的端口号，htons()用于 converts values between the host and network byte order        

	connect(sClient, (SOCKADDR*)&server, sizeof(SOCKADDR));

	return sClient;
}



double URDataHandle::GetAnalogInput(){
	if (_msg_id > 65535) _msg_id = 1;
	SOCKET sClient = connectPort502();
	char to_send[12];
	to_send[0] = (char)_msg_id >> 8;
	to_send[1] = (char)(_msg_id & 0x00FF);
	to_send[2] = 0;
	to_send[3] = 0;
	to_send[4] = 0;
	to_send[6] = 0;// (uint8_t)_slaveid;
	to_send[7] = 3;
	to_send[8] = 0;
	to_send[9] = 16; // address for analog output 0
	to_send[5] = 6;
	to_send[10] = 0;
	to_send[11] = 1;
	send(sClient, to_send, 12, 0);
	char to_rec[11];
	recv(sClient, to_rec, 1024, 0);
	unsigned char buff10 = (unsigned char)to_rec[10];
	unsigned char buff09 = (unsigned char)to_rec[9];
	closesocket(sClient);
	WSACleanup();
	_msg_id++;
	cout << (int)buff09 << "\t" << (int)buff10 << endl;
	double buff_DEC = buff09 * 256 + buff10;
	return buff_DEC / 65535. * 10.;  //voltage
}


void URDataHandle::SetAnalogOutput(int n, float f){
	SOCKET sClient = Reset();
	string to_send = "set_standard_analog_out(";
	to_send += int2str(n);
	to_send += ",";
	to_send += int2str(f / 10);  //测试了一下必须除10
	to_send += ")\n";

	send(sClient, to_send.c_str(), strlen(to_send.c_str()), 0);
	closesocket(sClient);
	WSACleanup();
}

void URDataHandle::SetDigitalOutput(int n, bool b){
	SOCKET sClient = Reset();
	if (b)
	{
		string to_send = "set_standard_digital_out(";
		to_send += int2str(n);
		to_send += ",True)\n";
		send(sClient, to_send.c_str(), strlen(to_send.c_str()), 0);
	}
	else{
		string to_send = "set_standard_digital_out(";
		to_send += int2str(n);
		to_send += ",False)\n";
		send(sClient, to_send.c_str(), strlen(to_send.c_str()), 0);
	}
	closesocket(sClient);
	WSACleanup();
}

bool URDataHandle::GetDigitalInput(int n){
	if (_msg_id > 65535) _msg_id = 1;
	SOCKET sClient = connectPort502();
	char to_send[12];
	to_send[0] = (char)_msg_id >> 8;
	to_send[1] = (char)(_msg_id & 0x00FF);
	to_send[2] = 0;
	to_send[3] = 0;
	to_send[4] = 0;
	to_send[6] = 0;// (uint8_t)_slaveid;
	to_send[7] = 3;
	to_send[8] = 0;
	to_send[9] = 0; // address for digital input 0
	to_send[5] = 6;
	to_send[10] = 0;
	to_send[11] = 1;
	send(sClient, to_send, 12, 0);
	char to_rec[11];
	recv(sClient, to_rec, 1024, 0);
	unsigned char buff10 = (unsigned char)to_rec[10];
	unsigned char buff09 = (unsigned char)to_rec[9];
	closesocket(sClient);
	WSACleanup();
	_msg_id++;

	int outputBit = (int)buff09 * 256 + (int)buff10;
	switch (n){
	case 0: return (outputBit & 0x01);
	case 1: return (outputBit & 0x02);
	case 2: return (outputBit & 0x04);
	case 3: return (outputBit & 0x08);
	case 4: return (outputBit & 0x10);
	case 5: return (outputBit & 0x20);
	case 6: return (outputBit & 0x40);
	case 7: return (outputBit & 0x80);
	case 8: return (outputBit & 0x100);
	case 9: return (outputBit & 0x200);
	}

}


bool URDataHandle::GetDigitalOutput(int n){
	if (_msg_id > 65535) _msg_id = 1;
	SOCKET sClient = connectPort502();
	char to_send[12];
	to_send[0] = (char)_msg_id >> 8;
	to_send[1] = (char)(_msg_id & 0x00FF);
	to_send[2] = 0;
	to_send[3] = 0;
	to_send[4] = 0;
	to_send[6] = 0;// (uint8_t)_slaveid;
	to_send[7] = 3;
	to_send[8] = 0;
	to_send[9] = 1; // address for digital input 0
	to_send[5] = 6;
	to_send[10] = 0;
	to_send[11] = 1;
	send(sClient, to_send, 12, 0);
	char to_rec[11];
	recv(sClient, to_rec, 1024, 0);
	unsigned char buff10 = (unsigned char)to_rec[10];
	unsigned char buff09 = (unsigned char)to_rec[9];
	closesocket(sClient);
	WSACleanup();
	_msg_id++;

	int outputBit = (int)buff09 * 256 + (int)buff10;
	switch (n){
	case 0: return (outputBit & 0x01);
	case 1: return (outputBit & 0x02);
	case 2: return (outputBit & 0x04);
	case 3: return (outputBit & 0x08);
	case 4: return (outputBit & 0x10);
	case 5: return (outputBit & 0x20);
	case 6: return (outputBit & 0x40);
	case 7: return (outputBit & 0x80);
	case 8: return (outputBit & 0x100);
	case 9: return (outputBit & 0x200);
	}

}