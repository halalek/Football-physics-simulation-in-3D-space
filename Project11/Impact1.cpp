#include "Impact1.h"
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "math3d.h"
#include <windows.h>
#include <iostream>
#include <vector> 
#include "Ball1.h"
#include<iostream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Impact1::Impact1()
{
}



Impact1::~Impact1()
{
}

/*float w=0;
float Impact1::dd(float r1,float v1,float t1)
{
	float v =v1;//100
	r1 = r1 /100 ;
	 w = abs(v  / r1);  //r
	float t =( 2 * M3D_PI * r1) / v;
	float tita1 = w / t1;
	//cout << "titaaaaaa    " << tita1;

	//cout << "circle    " << w /(2* M3D_PI );
	return tita1;
}*/


float r=0;

bool ds = false;
void Impact1::startImpact(Ball1* ball2, int ball,int w)
{
	this->ball = ball2;
	//(*ball)[0].phiscs.x +=10;
	//std::cout << "\n" << (*ballList)[0].phiscs.x;
	//fallingBall();
	
		ImpactWall1(ball);
	

	/*if (ds == false) {
		r = dd(150);
	ds = true;
}*/
	//ImpactBalls();
	//ImpactDiagonal();
}

BOOLEAN Impa = false;
BOOLEAN Impax = false;
BOOLEAN Impay = false;
BOOLEAN Impaz = true;
Ball1 ba2;

float x2 = 400;
float y3 = 150;
float z2 = 4000;
//float r = 90;
int r1 = 1; int r2 = 0;
const double P = 3.141;
static	float tita;
int X = 130;
int X1 = -130;

int Z1 = -100;
int Z = 100;

float Y(float xx, float yy, float zz, float r)
{
	float L1 = 0;
	if (xx + r  < 0) {
		L1 = abs(xx + r );
	}
	double tan_pi_2 = tan(tita);
	tan_pi_2 = ((tan_pi_2 < 0.0001 && tan_pi_2 > -0.0001) ? 0 : tan_pi_2);
	return abs(tan_pi_2)*L1;
}



//float r = Y(x2, y3, z2, y3);

int Impact1::Impactwall(int x, int y,int z,int r)////z=6850 , -850//x=-5850 , 5850
{

	if ((x + r >= 5850) ||
		(z - r <= -850) ||
		(x - r <= -5850) ||
		(z + r >= 6850))
	{
		Impa = true;
		//cout << "trrrrrrrrrrrrrrrrrrrrrrrrr";

	}

	


	if (Impa == true)// «·’œ„ ⁄·Ï „ÕÊ— X
	{
		if ( (x - r <= -5990))//Ì”«—
		{
			Impax = true;//-5990
			return 0;
		}
		if((x + r >= 5990))//Ì„Ì‰
		{
			Impax = true;
			return 3;
		}

		if ((z - r <= -900) )// «·’œ„ ⁄·Ï „ÕÊ— Z
		{
			Impaz = true;
			return 1;
		}

		if ((z + r >= 6900))
		{
			Impaz = true;
			return 4;
		}

	}


	
		return 2;
	


}




int Impact1::Impactmag(int x, int y, int z, int r)
{

	if ((x + r >= 5850) ||
		(z - r <= -850) ||
		(x - r <= -5800) ||
		(z + r >= 6850) || (y - r < 150))
	{
		Impa = true;
	}

	if (Impa == true)
	{
		if ((x - r <= -5800))// «·’œ„ ⁄·Ï „ÕÊ—   X// Ì”«—
		{
			Impax = true;
			return 0;
		}
		if ((x + r >= 5990))// «·’œ„ ⁄·Ï „ÕÊ—   X// Ì„Ì‰
		{
			Impax = true;
			return 3;
		}

		if ((z - r <= -900))// «·’œ„ ⁄·Ï „ÕÊ—   Z//√„«„
		{
			Impaz = true;
			return 1;
		}

		if ((z + r >= 6900))// «·’œ„ ⁄·Ï „ÕÊ—   Z//Œ·›
		{
			Impaz = true;
			return 4;
		}


		if ((y - r) < 150)//«·’œ„ »«·√—÷
		{
			Impay = true;
			cout << "kkkkkkkkkkk";
			return 5;
		}
	}



	return 2;



}









void Impact1::ImpactWall1(int tex)////z=6850 , -850//x=-5850 , 5850
{
	
	glPushMatrix();
	glTranslated(x2, y3, z2);//z=6850 , -850//x=-5850 , 5850
	//glRotated(r, 0, 0, 1);
	glRotated(r * 180 / M3D_PI, 0, 0, 1);
	ba2.ball1(tex, 0, x2, y3, z2, 150,0,0);
	glPopMatrix();

	//glRotated(tita * 180 / M3D_PI, 1, 0, 0);
	if (Impax == false)
	{
		
		x2 += 20;
		//r -= dd(150,100,1);
		(*ball).phiscs.x = x2;
		//cout << (*ball).phiscs.x <<"\n";
	}

	if (Impaz == false)
	{
		z2 += 20;
		(*ball).phiscs.z = z2;
		//cout << (*ball).phiscs.z << "\n";
	}
	if ( ( (*ball).phiscs.x + (*ball).phiscs.r >= 5850) ||
		((*ball).phiscs.z - (*ball).phiscs.r <= -850) ||
		((*ball).phiscs.x - (*ball).phiscs.r <= -5850) ||
		( (*ball).phiscs.z + (*ball).phiscs.r >= 6850) )
	{
		Impa = true;
		cout << "trrrrrrrrrrrrrrrrrrrrrrrrr";

	}

	

	if (Impa == true)
	{
		if (((*ball).phiscs.x + (*ball).phiscs.r >= 5850) || ((*ball).phiscs.x - (*ball).phiscs.r <= -5850))
		{
			Impax= true;
		}

		if (((*ball).phiscs.z - (*ball).phiscs.r <= -850) || ((*ball).phiscs.z + (*ball).phiscs.r >= 6850))
		{
			Impaz = true;
		}
	}
	

	if (Impax == true)
	{
		x2 -= 20;
		//r += w;
		(*ball).phiscs.x = x2;
	}

	/*if (Impaz == true)
	{
		z2 -= 20;
		(*ball).phiscs.z = z2;
	}*/

}
/*void Impact1::ImpactWall()
{
	Ball1 b;
	std::vector <Ball1>* ball; ball->push_back(b);
	//int i = 0;
	//std::cout << "\nr=" << choises;
	//z = 6850, -850//x=-5850 , 5850
	float dx,dz,dx1,dz1,d,d1;
	if ((*ball)[0].phiscs.x >= 0)
	{
		dx = (5850 - (*ball)[0].phiscs.x) + (*ball)[0].phiscs.r;
		d = dx;
	}
	if ((*ball)[0].phiscs.x < 0)
	{
		dx1 = -(-5850 - (*ball)[0].phiscs.x) + (*ball)[0].phiscs.r;
		d = dx1;
	}
	if ((*ball)[0].phiscs.z >= 0) {
		dz = (6850 - (*ball)[0].phiscs.z) + (*ball)[0].phiscs.r;
		d1 = dz;
	}
	if ((*ball)[0].phiscs.z < 0) {
		dz1 = -(-850 - (*ball)[0].phiscs.z) + (*ball)[0].phiscs.r;
		d1 = dz1;
	}
	
	for (int i = 0; i < (*ball).size(); i++) {
		glPushMatrix();
		//(*ball)[i].phiscs.STARTPHiscs();
		BOOLEAN Impa = false;
		BOOLEAN Impax = false;
		BOOLEAN Impaz = false;
		// cout << (*ball)[i].phiscs.z<<"\n";
		//out
		if ((*ball)[i].phiscs.out || ((*ball)[i].phiscs.y >= 25 && ((*ball)[i].phiscs.x >= 118 || (*ball)[i].phiscs.x <= -95))) {
			(*ball)[i].phiscs.out = true;
		//	cout << "44444444444444444444444444444444";
		}

		/*if (  (*ball)[i].phiscs.x == 5850 || ((*ball)[i].phiscs.x ==-5850 || (*ball)[i].phiscs.z == 6850 || (*ball)[i].phiscs.z == -850)) {
			//(*ball)[i].phiscs.out = true;
			Impa = true;
			//cout << "impact";
		}*/
/*


if (d <= (*ball)[i].phiscs.r) {
	Impax = true;
	cout << "kkkkkkkkkkkkkkkkkkkkkk" << "\n";

}
if (d1 <= (*ball)[i].phiscs.r) {
	Impax = true;
	cout << "qqqqqqqqqqqqqqqqqqqqqqqq" << "\n";
}

if (d <= (*ball)[i].phiscs.r || d1 <= (*ball)[i].phiscs.r) {
	//(*ball)[i].phiscs.out = true;
	Impa = true;
	cout << "impactttttttttttttttttttttttttttttttttttttttttttttttt" << "\n";
	Vector3D forcetemp2;
	forcetemp2.x = -(*ball)[i].phiscs.SUMFORCES.x;
	forcetemp2.y = -(*ball)[i].phiscs.SUMFORCES.y;
	forcetemp2.z = -(*ball)[i].phiscs.SUMFORCES.z;

	if ((*ball)[i].phiscs.x + (*ball)[i].phiscs.r >= 126) {
		forcetemp2.y = (*ball)[i].phiscs.SUMFORCES.y;
		forcetemp2.z = (*ball)[i].phiscs.SUMFORCES.z;
	}
}




else if (((*ball)[i].phiscs.x + (*ball)[i].phiscs.r >= 126) ||
((*ball)[i].phiscs.z - (*ball)[i].phiscs.r <= -148) ||
((*ball)[i].phiscs.x - (*ball)[i].phiscs.r <= -108) ||
((*ball)[i].phiscs.z + (*ball)[i].phiscs.r >= 87)
//	||((*ballList)[i].phiscs.y== (*ballList)[i].phiscs.r) 
)
{
	//cout << "55555555555555555555555555555555555555555";
	//std::cout << "\niiiiiiiiiii";
	Impa = true;


	Vector3D forcetemp2;
	forcetemp2.x = -(*ball)[i].phiscs.SUMFORCES.x;
	forcetemp2.y = -(*ball)[i].phiscs.SUMFORCES.y;
	forcetemp2.z = -(*ball)[i].phiscs.SUMFORCES.z;

	if ((*ball)[i].phiscs.x + (*ball)[i].phiscs.r >= 126) {
		forcetemp2.y = (*ball)[i].phiscs.SUMFORCES.y;
		forcetemp2.z = (*ball)[i].phiscs.SUMFORCES.z;
	}
	else if ((*ball)[i].phiscs.z - (*ball)[i].phiscs.r <= -148) {
		forcetemp2.x = (*ball)[i].phiscs.SUMFORCES.x;
		forcetemp2.y = (*ball)[i].phiscs.SUMFORCES.y;
	}
	else if ((*ball)[i].phiscs.x - (*ball)[i].phiscs.r <= -108) {
		forcetemp2.y = (*ball)[i].phiscs.SUMFORCES.y;
		forcetemp2.z = (*ball)[i].phiscs.SUMFORCES.z;
	}
	else if ((*ball)[i].phiscs.z + (*ball)[i].phiscs.r >= 87) {
		forcetemp2.x = (*ball)[i].phiscs.SUMFORCES.x;
		forcetemp2.y = (*ball)[i].phiscs.SUMFORCES.y;

	}
	else if ((*ball)[i].phiscs.y == (*ball)[i].phiscs.r) {
		/*forcetemp2.x = 0;
		forcetemp2.y = 0;
		forcetemp2.z = 0;*/
	/*	std::cout << "::::::::::::::::::::::::::::::::::::::";

	}
	(*ball)[i].phiscs.x = (*ball)[i].phiscs.xberforewall;
	(*ball)[i].phiscs.y = (*ball)[i].phiscs.yberforewall;
	(*ball)[i].phiscs.z = (*ball)[i].phiscs.zberforewall;


	Vector3D SUMFORCES;
	SUMFORCES.x = -(*ball)[i].phiscs.SUMFORCES.x;
	SUMFORCES.z = -(*ball)[i].phiscs.SUMFORCES.z;
	SUMFORCES.y = -(*ball)[i].phiscs.SUMFORCES.y;
	forcetemp2.x *= 0.8;
	forcetemp2.y *= 0.8;
	forcetemp2.z *= 0.8;
	if (forcetemp2.y < 0) {
		forcetemp2.y = 0;
	}
	/*if (SUMFORCES.y < 0) {
		SUMFORCES.y = 0;
	}*/
/*	(*ball)[i].phiscs.SETF(forcetemp2);

	(*ball)[i].phiscs.SETF(SUMFORCES);

	//(*ballList)[i].phiscs.SETV(forcetemp);


}
if (!Impa) {
	(*ball)[i].phiscs.xberforewall = (*ball)[i].phiscs.x;
	(*ball)[i].phiscs.yberforewall = (*ball)[i].phiscs.y;
	(*ball)[i].phiscs.zberforewall = (*ball)[i].phiscs.z;
	//cout << "7777777777777777777777777777777777777777777777777";
}


glPopMatrix();
	}*/




























