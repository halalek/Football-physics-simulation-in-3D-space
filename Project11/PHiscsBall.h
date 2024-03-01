#pragma once
#pragma once
#include "Vector3D.h"
#include <vector> 
#include "Diagonal.h"


class PHiscsBall
{
public:
	int choices = 0;
	double x = 0;
	double y = 0;
	double z = 0;
	float H = 0;
	Diagonal diagonal;

	double Mplayer = 5;
	Vector3D Vplayer;

	float xberfore = 0;
	float yberfore = 0;
	float zberfore = 0;
	float xberforewall = 0;
	float yberforewall = 0;
	float zberforewall = 0;
	bool out = false;
	double r = 1.2;
	double M = 1;//kg

	double tata1 = 0;
	double tata2 = 0;

	Vector3D V;
	Vector3D a;
	double t = 1;
	double u = 1;

	int typeball = 2;
	Vector3D SUMFORCES;

	std::vector<Vector3D> VextorsForces;
	PHiscsBall();
	void STARTPHiscs();
	void SETF(Vector3D FORCE);
	void SETV(Vector3D V);
	double GETMU();

	//Impact im;
	Vector3D GETV();


	Vector3D W;
	Vector3D R;
	Vector3D Ft;// ﬁÊ… «Õ ﬂ«ﬂ
	Vector3D Fc;//ﬁÊ… «·—ﬂ· Õ«·Ì« 50 Ê«·« ÂÌ » ⁄ „œ ⁄·Ï «··«⁄»
	double g = 10;

	//Impact im;
	




	~PHiscsBall();
};

