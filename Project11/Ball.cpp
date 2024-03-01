#include "Ball.h"
#include<time.h>
#include <math.h>
Ball::Ball()
{
}


void Ball::ball1(int b){
	bool	keys[256];
	GLUquadric*quad;
	//x = 0, y = -350, z = 4000;
	
	glPushMatrix();
	//glTranslated(X, Y, Z); 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, b);
	quad = gluNewQuadric();
	gluQuadricTexture(quad, GL_TRUE);
	gluSphere(quad, 150, 100, 150);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void Ball::force(double tt){
	W = m*g;
	W = 1000;
	R = -1000;
	if (Fc == 0)//Óßæä
	{
		F = W + R;
		F = 0;
		a = 0;
		V = 0;
	}
	
	else if ( Fc!=0)//ÞÐÝ
	{
	
		
		Vx = Vx*cos(t1)*sin(t2);
		Vy = Vy*sin(t1);
		Vz = Vz*cos(t1)*cos(t2);
		X = Vx*timet + X;
		Y = (-1 / 2)*g*(timet)*(timet) + Vy*timet + Y;
		Z = Vz*timet + Z;
	}           
	

}
Ball::~Ball()
{
}