#pragma once
#pragma once
#include"Model_3DS.h"
#include <vector> 
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include<stdio.h>
#include "PHiscsBall.h"
class Ball1
{
public:

	/*double m = 100;
	double W;
	double R;
	double Ft;// ﬁÊ… «Õ ﬂ«ﬂ
	double Fc = 50;//ﬁÊ… «·—ﬂ· Õ«·Ì« 50 Ê«·« ÂÌ » ⁄ „œ ⁄·Ï «··«⁄»
	double g = 10;
	double a;
	double F;
	double V;
	double t1 = 45;
	double t2 = 45;// “«ÊÌ…
	double timet;
	double Vx = 100, Vy = 100, Vz = 100;
	double X = 0, Y = -350, Z = 4000;
	float r=0; //‰’› ﬁÿ—
	bool change = false;//ﬂ—…  €Ì— „ﬂ«‰Â«
	Ball1();
	PHiscsBall phiscs;
	void ball1(int texture, int color, float x, float y, float z, float r,double tata, double tt);
	void ColorBall(int choices);
	void ballid(float x, float y, float z, float r, double tata, double tt);
	void ballssleep(int ball);
	void ballsperfect(int ball);
	void ballsft(int ball);





	float x = 0;
	float y = 150;
	float z = 4000;
	float x0 = 0;
	float y0 = 0;
	float z0 = 0;
	bool move = false;
	bool mov1 = false;
	bool movement = false;
	void force(int ball, int choices1);

	~Ball1();*/



	
	double V0=40 ;
	int choices = 0;
	Diagonal diagonal;
	double Mplayer ;
	Vector3D Vplayer;
	float xberfore = 0;
	float yberfore = 0;
	float zberfore = 0;
	float xberforewall = 0;
	float yberforewall = 0;
	float zberforewall = 0;
	bool out = false;
	float r=0.1;
	Vector3D Fd;//ﬁÊ… ”Õ» 
	Vector3D Fm;// √ÀÌ— „«€‰Ê” 
	float p ;
	float cd = 0.3;
	float A ;
	float g ;


	double M =0.5;
	double tata1=0 ;
	double tata2=70 ;
	Vector3D V;
	Vector3D a;
	double t ;
	double u ;
	int typeball ;
	Vector3D SUMFORCES;

	float x = 0;
	float y = 150;
	float z = 4000;
	float x0 = 0;
	float y0 = 0;
	float z0 = 0;
	bool move = false;
	bool mov1 = false;
	bool movement = false;
	
	bool movement1 = false;
	double ValocityAbs;
	float tt = 0;
	bool change = false;//ﬂ—…  €Ì— „ﬂ«‰Â«
	Ball1();
	PHiscsBall phiscs;
	void ball1(int texture, int color, float x, float y, float z, float r, double tata, double tt);
	void force(int ball, int choices1);
	void ColorBall(int choices);
	int Initball();
	

	void ballid(float x, float y, float z, float r, double tata, double tt);
	void ballssleep(int ball);
	void ballsperfect(int ball);
	void ballsft(int ball);
	void ballsthrow(int ball);
	void ballsthrow1(int ball);








	~Ball1();






};

