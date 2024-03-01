

#pragma once
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <math.h>
#include "texture.h"
#include <Model_3DS.h>
#include <cmath>
#include"Model_3DS.h"
#include "3DTexture.h"
#include "math3d.h"
class player
{
public:
	Model_3DS m;
	Model_3DS m2;
	Model_3DS m3;
	Model_3DS m4;
	Model_3DS m5;
	Model_3DS m6;
	Model_3DS m7;
	Model_3DS m8;
	Model_3DS m9;
	Model_3DS m10;
	Model_3DS m11;
	Model_3DS m12;
	Model_3DS m13;
	Model_3DS m14;
	Model_3DS m15;
	Model_3DS m16;
	Model_3DS m17;

	double rot = 0;
	char stadium[25] = "pla1.3ds";
	char stadium2[25] = "pla2.3ds";
	char stadium3[25] = "pla3.3ds";
	char stadium4[25] = "pla4.3ds";
	char stadium5[25] = "pla5.3ds";
	char stadium6[25] = "pla6.3ds";
	char stadium7[25] = "pla7.3ds";
	char stadium8[25] = "pla8.3ds";
	char stadium9[25] = "pla9.3ds";
	char stadium10[25] = "pla10.3ds";
	char stadium11[25] = "pla11.3ds";
	char stadium12[25] = "pla12.3ds";
	char stadium13[25] = "pla13.3ds";
	char stadium14[25] = "pla14.3ds";
	char stadium15[25] = "pla15.3ds";
	char stadium16[25] = "pla16.3ds";
	char stadium17[25] = "pla17.3ds";


	char lp1[20] = "s//bb1.bmp";
	char lp2[20] = "s//b2.bmp";
	char lp3[20] = "s//b.bmp";
	char lp4[20] = "s//b4.bmp";
	char lp5[20] = "s//ballr.bmp";
	char lp6[20] = "s//b6.bmp";
	char lp7[20] = "s//b7.bmp";
	M3DMatrix44f shadow;
	M3DVector4f equation;
	int tex;
	//char a[25] = "image//earth.bmp";

	player();
	int Drawstad(bool o, bool shadow);
	void textplayer(Model_3DS k);
	void shadowplayer(float * Lightpos, double x, bool p);

	void intstad();

	~player();
};

