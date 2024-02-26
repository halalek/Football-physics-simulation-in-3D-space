#pragma once
#pragma once
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <math.h>		// Header File For The Glaux Library
#include <cmath>		// Header File For The Glaux Library
#include "math3d.h"	// Header File For The Glaux Library
#include"Model_3DS.h"
#include <vector> 
class Diagonal
{
public:
	Diagonal();
	const double P = 3.141;

	static	float tita;
	int X = -30;
	int X1 = -130;

	int Z1 = 50;
	int Z = 100;

	void Drawtable();
	void inttable();

	float Diagonalball(float r1, float v1, float t1);
	float Diagonalballmag(float t1, float w);
	int Impact(float xx, float yy, float zz, float r);
	float  Y(float xx, float yy, float zz, float r);
	void  Settita(float t1);

	~Diagonal();
};


