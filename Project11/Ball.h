#pragma once
#include"Model_3DS.h"
class Ball
{
public:
	double m = 100;
	double W;
	double R;
	double Ft;// ��� ������
	double Fc=50;//��� ����� ����� 50 ���� �� ������ ��� ������
	double g = 10;
	double a;
	double F;
	double V;
	double t1=45;
	double t2=45;// �����
	double timet;
	double Vx = 100,Vy=100,Vz=100;
	double X = 0, Y = -350, Z = 4000;
	

	Ball();

	void ball1(int b);
	void force(double tt);
	int Initball();
	~Ball();
};

