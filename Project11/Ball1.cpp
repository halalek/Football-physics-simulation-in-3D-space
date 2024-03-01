#include "Ball1.h"

#include<time.h>
#include <math.h>
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include "texture.h"
#include <iostream>
#include "Impact1.h"
#include <fstream>
#include <string>
using namespace std;
Ball1::Ball1()
{
}



void Ball1::ColorBall(int choices)
{

	switch (choices)
	{
		//case 0:
		//	glColor3d(1, 1, 1);
			//break;
	case 1:
		glPushMatrix();
		glColor3d(0, 1, 1);
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();
		glColor3d(0, 0, 0);
		glPopMatrix();
		break;
	case 3:
		glPushMatrix();
		glColor3d(1, 0, 0);
		glPopMatrix();
		break;
	case 4:
		glPushMatrix();
		glColor3d(1, 1, 0);
		glPopMatrix();
		break;
	case 5:
		glPushMatrix();
		glColor3d(1, 0, 1);
		glPopMatrix();
		break;
	case 6:
		glPushMatrix();
		glColor3f(1, 0.1, 0.2);
		glPopMatrix();
		break;
	default:
		break;
	}

}


void Ball1::ballid(float x, float y, float z, float r, double tata, double tt) {

	this->phiscs.x = x;
	this->phiscs.y = y;
	this->phiscs.z = z;
	this->phiscs.r = r;


	this->phiscs.tata1 = tata;
	this->phiscs.tata2 = 90 - tata;
	this->phiscs.t = tt;
	this->phiscs.Mplayer = 20;
}



void Ball1::ball1(int texture,int color, float x, float y, float z, float r, double tata, double tt) {

	this->phiscs.x = x;
	this->phiscs.y = y;
	this->phiscs.z = z;
	this->phiscs.r = r;


	this->phiscs.tata1 = tata;
	this->phiscs.tata2 = 90 - tata;
	this->phiscs.t =tt;
	this->phiscs.Mplayer = 20;
	bool	keys[256];
	GLUquadric*quad;
	//x = 0, y = -350, z = 4000;
/*
	glPushMatrix();
	//glTranslated(X, Y, Z); 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, b);
	quad = gluNewQuadric();
	gluQuadricTexture(quad, GL_TRUE);
	gluSphere(quad, 150, 100, 150);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	*/



	
	if (color == 0) {


		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		quad = gluNewQuadric();
		gluQuadricTexture(quad, GL_TRUE);
		gluSphere(quad, r, 100, 150);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	if (color != 0) {


		glPushMatrix();
		//glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, b);
		glDisable(GL_LIGHTING);
		ColorBall(color);
		quad = gluNewQuadric();
		
		glDisable(GL_COLOR);
		gluQuadricTexture(quad, GL_TRUE);
	
		gluSphere(quad,r,100, 150);
		//glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		
	}
	
	glPushMatrix();
	glColor3d(1, 1, 1);
	glPopMatrix();
	
}


//void Ball::ImpactWall(vector <> ballList1) {}

bool Impax = false;
bool Impaz = false;
Impact1 imp;
Diagonal diagonal;
float r1 = 0;
float r2 = 0;
float r3 = 0;
float r4 = 0;
int aa = 0;
int impact=2;
int index = 1;
int indez = 1;
int index1 = 1;
int indez1 = 1;
int indey = 1;
int direc = 1;
int direc1 = 1;
bool aq = false;
bool aqq = false;
bool vv = false;
float v1 = 0;
float v2 = 0;
float ft = 0;

void Ball1::ballssleep(int ball)
{
	
	phiscs.Fc.x = 0;
	phiscs.Fc.y = 0;
	phiscs.Fc.z = 0;
	phiscs.SUMFORCES.x = 0;
	phiscs.SUMFORCES.y = 0;
	phiscs.SUMFORCES.z = 0;

	glPushMatrix();
	glTranslated(x, 150, z);
	glRotated(r1 * 180 / M3D_PI, 0, 0, 1);
	ball1(ball, 0, x, y, z, 150, 65, phiscs.t);
	glPopMatrix();
}

void Ball1::ballsperfect(int ball) {

		phiscs.Fc.x = 10000 * cos(phiscs.tata1);
		phiscs.Fc.y = 0;
		phiscs.Fc.z = 10000 * sin(phiscs.tata2);
		phiscs.SUMFORCES.x = phiscs.Fc.x;
		phiscs.SUMFORCES.y = phiscs.Fc.y;
		phiscs.SUMFORCES.z = phiscs.Fc.z;

		phiscs.a.x = phiscs.SUMFORCES.x / phiscs.M;
		phiscs.a.y = phiscs.SUMFORCES.y / phiscs.M;
		phiscs.a.z = phiscs.SUMFORCES.z / phiscs.M;

		phiscs.V.x = index1 * (phiscs.a.x)*phiscs.t;
		phiscs.V.y = (phiscs.a.y)*phiscs.t;
		phiscs.V.z = indez1 * (phiscs.a.z)*phiscs.t;

		x = (phiscs.V.x)*phiscs.t + this->phiscs.x;
		y = (phiscs.V.y)*phiscs.t + this->phiscs.y;
		z = (phiscs.V.z)*phiscs.t + this->phiscs.z;



		glPushMatrix();
		glTranslated(x, 150, z);
		glRotated(r2 * 180 / M3D_PI, 0, 0, 1);
		ball1(ball, 0, x, 150, z, 150, 65, phiscs.t);
		glPopMatrix();

		impact = imp.Impactwall(x,y, z, r);
		if (impact == 2)
		{
           r2 -= direc1* abs(diagonal.Diagonalball(r, phiscs.V.x, phiscs.t));
          //	cout << "lkllllll";
		}

		if (impact == 0)
		{
			index1 = -1;
			direc1 = -1;
		}

		if (impact == 3 )
		{
			direc1 = +1;
			index1 = +1;
		}

		if (impact == 1)
		{
			indez1 = -1;
		}


		if (impact == 4)
		{
			indez1 = +1;
		}


	

}

void Ball1::ballsft(int ball) {


	phiscs.Ft.x = (-(phiscs.M*phiscs.g*phiscs.u) + ft);
	phiscs.Ft.z = (-(phiscs.M*phiscs.g*phiscs.u) + ft);
	phiscs.Ft.y = 0;
	phiscs.Fc.x = 12000 * cos(phiscs.tata1);// 1 n // 1000
	phiscs.Fc.y = 0;
	phiscs.Fc.z = 12000 * sin(phiscs.tata2);

	phiscs.a.x = phiscs.SUMFORCES.x / phiscs.M;
	phiscs.a.y = phiscs.SUMFORCES.y / phiscs.M;
	phiscs.a.z = phiscs.SUMFORCES.z / phiscs.M;
	phiscs.V.x = index * (phiscs.a.x)*phiscs.t;
	phiscs.V.y = (phiscs.a.y)*phiscs.t;
	phiscs.V.z = indez * (phiscs.a.z)*phiscs.t;

	x = (phiscs.V.x)*phiscs.t + phiscs.x;
	y = (phiscs.V.y)*phiscs.t + phiscs.y;
	z = (phiscs.V.z)*phiscs.t + phiscs.z;
	phiscs.x = x;
	phiscs.y = y;
	phiscs.z = z;

	
	if (movement == false)
	{
		if (phiscs.Fc.x < 0)
		{
			phiscs.SUMFORCES.x = phiscs.Fc.x - phiscs.Ft.x;
			move = true;
		}
		else
			phiscs.SUMFORCES.x = phiscs.Fc.x + phiscs.Ft.x;
		phiscs.SUMFORCES.y = phiscs.Fc.y + 0;
		if (phiscs.Fc.z < 0)
		{
			phiscs.SUMFORCES.z = phiscs.Fc.z - phiscs.Ft.z;
			mov1 = true;
		}
		else
			phiscs.SUMFORCES.z = phiscs.Fc.z + phiscs.Ft.z;
		movement = true;
	}
	else {
		if (move = true)
			phiscs.SUMFORCES.x = phiscs.SUMFORCES.x - phiscs.Ft.x;
		else
			phiscs.SUMFORCES.x = phiscs.SUMFORCES.x + phiscs.Ft.x;
		if (mov1 = true)
			phiscs.SUMFORCES.z = phiscs.SUMFORCES.z - phiscs.Ft.z;
		else
			phiscs.SUMFORCES.z = phiscs.SUMFORCES.z + phiscs.Ft.z;
		if ((phiscs.SUMFORCES.x >= 0) && (move = true))
		{
			phiscs.SUMFORCES.x = 0;

		}
		if ((phiscs.SUMFORCES.x <= 0) && (move = false))
		{
			phiscs.SUMFORCES.x = 0;

		}
		if ((phiscs.SUMFORCES.z >= 0) && (mov1 = true))
		{
			phiscs.SUMFORCES.z = 0;

		}
		if ((phiscs.SUMFORCES.z <= 0) && (mov1 = false))
		{
			phiscs.SUMFORCES.z = 0;

		}

	}


	
	glPushMatrix();
	glTranslated(x, 150, z);
	glRotated(r3 * 180 / M3D_PI, 0, 0, 1);
	ball1(ball,0, x, y, z, 150, 65, phiscs.t);
	glPopMatrix();
	cout << "Valocity        " << phiscs.V.x <<"\n";
	impact = imp.Impactwall(x,y, z, r);
	if (aq == false)
	{
		r3 = 0;//√”«”Ì//
		
		r3= abs(diagonal.Diagonalball(r, phiscs.V.x, phiscs.t));//√”«”Ì//
		v1 -= abs(diagonal.Diagonalball(r, phiscs.V.x, phiscs.t));//√”«”Ì//
		
		aq = true;//√”«”Ì//
	}

	if (phiscs.V.x != 0 && aqq==false)
	{
		v2 = abs(phiscs.V.x);
		aqq == true;
	}
	if (aq == true)
	{
		

		if (abs(phiscs.V.x) > 250)
		{
			

			r3 += direc * abs( (diagonal.Diagonalball(r, (v1 -phiscs.Ft.x), phiscs.t) ));//√”«”Ì//

		}
		



		if (abs(phiscs.V.x) > 80)
			r3 += direc * abs(diagonal.Diagonalball(r, (v1 - phiscs.Ft.x), phiscs.t));//√”«”Ì//
		


		if (abs(phiscs.V.x) != 0 && abs(phiscs.V.x) <= 80 && abs(phiscs.V.x) > 11)
		{
			
			r3 += direc * abs(phiscs.t);//√”«”Ì//
			
		}


	}

	if (impact == 0 )
	{
          index = -1;
			direc = -1;
			ft -=5;

	}

	if (impact == 3 )
	{
			direc = +1;
			index = +1;
			ft -=5;
		
	}

	if (impact == 1)
	{
		indez = -1;
		direc = +1;
		ft -=5;
	}


	if (impact == 4)
	{
		indez = +1;
		ft -=5;
	}

	

}
float cl;
int i = 0;
int ft1 = 0;
float w2 = 100;
float COR = 0.06;
int indey5 = 1;
int index5 = 1;
int indez5 = 1;
int direc5 = 1;
void Ball1::ballsthrow(int ball) {

	glPushMatrix();
	glTranslated(x, y, z);
	glRotated(r4 * 180 / M3D_PI, 0, 0, 1);
	ball1(ball, 0, x, y, z, 150, 65, phiscs.t);
	glPopMatrix();
	if (movement1 == false)
	{
		const float PI = atan(1.0f)*4.0f;


		V.x = 100 * cos((PI / 2) - (tata2 * PI) / 180.0f)*cos((PI)-(0 * PI) / 180.0f);
		V.y = 100 * sin((PI / 2) - (tata2 * PI) / 180.0f);
		V.z = 100 * cos((PI / 2) - (tata2 * PI) / 180.0f)*sin((PI)-(0 * PI) / 180.0f);

		cl = (r *w2) / V0;
		//cl = (r *w) / V0;
		//cout << "cllllllllllllllllll" << cl;
		movement1 = true;
	}
	else
	{
		//cl = 0.1;
		ValocityAbs = sqrt(pow(V.x, 2) + pow(V.y, 2) + pow(V.z, 2));
		Fd.x = 0.5*1.225*0.3 * 3.14*r*r*(ValocityAbs*V.x);
		Fd.y = 0.5*1.225*0.3 * 3.14*r*r*(ValocityAbs*V.y);
		Fd.z = 0.5*1.225*0.3  * 3.14*r*r*(ValocityAbs*V.z);

		Fm.x = 0.5*1.225*cl * 3.14*r*r*(ValocityAbs*V.x);
		Fm.y = 0.5*1.225*cl * 3.14*r*r*(ValocityAbs*V.y);
		Fm.z = 0.5*1.225*cl  * 3.14*r*r*(ValocityAbs*V.z);

		a.x = (-Fd.x - Fm.x + ft1) / M;
		a.y = (-(M * 10) - Fd.y - Fm.x + ft1) / M;
		a.z = (-Fd.z - Fm.x) / M;



		V.x = index5 * ((a.x)*0.06 + V.x);
		V.y = indey5 * ((a.y)*0.06 + V.y);
		V.z = indez5 * ((a.z)*0.06 + V.z);
		cout << "Valocity        " << V.x << "\n";
	}
	x = (40 * V.x)*0.06 + x;

	y = ((30 * V.y)*0.06 + y);

	z = (V.z)*0.06 + z;

	impact = imp.Impactmag(x, y, z, r);
	r4 -= direc5 * abs(diagonal.Diagonalballmag(w2, 0.06));

	





	if (impact == 5 && aa == 0)
	{
		indey5 = -1;

		if (i <= 6)
		{
			i++;
			y -= 0.1;
			w2 -= w2 * 0.12;
			ft1 -= 0.05;
		}

		if (i > 6)
		{
			aa = 1;
			indey5 = 0;
			ft1 = 0;
			V.x = 0;
			direc5 = 0;
			w2 = 0;
		}

		direc5 = +1;



		
	}
	if (impact == 2 && aa == 0)
	{
		
		indey5 = +1;

		direc5 = -1;
		
	}
	if (impact == 0)
	{
		
		index5 = -1;
		
		y += 5;
		

		ft1 -= 0.5;
		direc5 = -1;
		
		//indez = +1;
	}
}




void Ball1::ballsthrow1(int ball) {

	glPushMatrix();
	glTranslated(x, y, z);
	glRotated(r3 * 180 / M3D_PI, 0, 0, 1);
	ball1(ball, 0, x, y, z, 150, 65, phiscs.t);
	glPopMatrix();
	if (movement1 == false)
	{
		const float PI = atan(1.0f)*4.0f;


		V.x = V0 * cos((PI / 2) - (80 * PI) / 180.0f)*cos((PI)-(tata1 * PI) / 180.0f);
		V.y = V0 * sin((PI / 2) - (80 * PI) / 180.0f);
		V.z = V0 * cos((PI / 2) - (80 * PI) / 180.0f)*sin((PI)-(tata1 * PI) / 180.0f);

		cl = (r *w2) / V0;
		movement1 = true;
	}
	else
	{
		ValocityAbs = sqrt(pow(V.x, 2) + pow(V.y, 2) + pow(V.z, 2));
		Fd.x = 0.5*1.225*0.3 * 3.14*r*r*(ValocityAbs*V.x);
		Fd.y = 0.5*1.225*0.3 * 3.14*r*r*(ValocityAbs*V.y);
		Fd.z = 0.5*1.225*0.3  * 3.14*r*r*(ValocityAbs*V.z);

		Fm.x = 0.5*1.225*cl * 3.14*r*r*(ValocityAbs*V.x);
		Fm.y = 0.5*1.225*cl * 3.14*r*r*(ValocityAbs*V.y);
		Fm.z = 0.5*1.225*cl  * 3.14*r*r*(ValocityAbs*V.z);

		a.x = (-Fd.x - Fm.x + ft) / M;
		a.y = (-(M * 10) - Fd.y - Fm.x + ft) / M;
		a.z = (-Fd.z - Fm.x) / M;



		V.x = index * ((a.x)*0.06 + V.x);
		V.y = indey * ((a.y)*0.06 + V.y);
		V.z = indez * ((a.z)*0.06 + V.z);
	}
	x = (40 * V.x)*0.06 + x;

	y = ((30 * V.y)*0.06 + y);

	z = (V.z)*0.06 + z;

	impact = imp.Impactmag(x, y, z, r);
	r3 -= direc * abs(diagonal.Diagonalballmag(w2, 0.06));




	if (impact == 5 && aa == 0)
	{
		indey = -1;
		y += 5;
		w2 -= w2 * 0.12;
		ft -= 0.05;
		direc = +1;

	}

	if (V.z <=0.01)
	{
		aa = 1;
		indey = 0;
		ft = 0;
		V.x = 0;
		direc = 0;
		w2 = 0;
	}
	if (impact == 2 && aa == 0)
	{
		indey = +1;
		direc = -1;
	}
	if (impact == 0)
	{
		index = -1;
		y += 5;
		ft -= 0.5;
		direc = -1;
	}
}








void Ball1::force(int ball, int choices1) {



	switch (choices1)
	{

	case 7:
		ballssleep(ball);
		break;

	case 8:
		ballsperfect(ball);
		break;


	case 9:
		ballsft(ball);
		break;


	case 2:
		ballsthrow(ball);
		break;
	
	default:
		break;
	}







}






Ball1::~Ball1()
{
}