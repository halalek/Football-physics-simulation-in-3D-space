#include "player.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <math.h>
#include "texture.h"
#include <Model_3DS.h>
#include <texture.h>
#include <cmath>
#include "math3d.h"

player::player()
{
}
int player::Drawstad(bool o, bool shadow)
{
	glPushMatrix();
	//glTranslated(95, -51, -295);
	glTranslated(800, 150, 3850);
	glRotated(-90, 0, 1, 0);
	glScalef(150, 150, 150);
	if (o == 0)
	{
		glPushMatrix();
		m.Draw();
		glPopMatrix();
	}
	else if (shadow == 0)
	{
		if (rot < 162)
			rot += 0.8;
	}
	if (rot >= 0 && rot < 10 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m.Draw();
		glPopMatrix();
		return 0;
	}
	else if (rot >= 10 && rot < 20 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m2.Draw();
		glPopMatrix();
		return 0;
	}
	else if (rot >= 20 && rot < 30 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m3.Draw();
		glPopMatrix();
		return 0;
	}
	else if (rot >= 30 && rot < 40 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m4.Draw();
		glPopMatrix();
		return 0;

	}
	else if (rot >= 40 && rot < 50 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m5.Draw();
		glPopMatrix();
		return 0;

	}
	else if (rot >= 50 && rot < 60 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m6.Draw();
		glPopMatrix();
		return 0;

	}
	else if (rot >= 60 && rot < 70 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m7.Draw();
		glPopMatrix();
		return 0;

	}
	else if (rot >= 70 && rot < 80 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m8.Draw();
		glPopMatrix();
		return 0;

	}
	else if (rot >= 80 && rot < 90 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m9.Draw();
		glPopMatrix();
		return 1;

	}
	else if (rot >= 90 && rot < 100 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m10.Draw();
		glPopMatrix();
		return 1;

	}
	else if (rot >= 100 && rot < 110 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m11.Draw();
		glPopMatrix();
		return 1;

	}
	else if (rot >= 110 && rot < 120 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m12.Draw();
		glPopMatrix();
		return 1;

	}
	else if (rot >= 120 && rot < 130 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m13.Draw();
		glPopMatrix();
		return 1;

	}
	else if (rot >= 130 && rot < 140 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m14.Draw();
		glPopMatrix();
		return 1;

	}
	else if (rot >= 140 && rot < 150 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m15.Draw();
		glPopMatrix();
		return 1;

	}
	else if (rot >= 150 && rot < 160 && o == 1)
	{
		//rot += 0.256;
		glPushMatrix();
		m16.Draw();
		glPopMatrix();
		return 1;

	}
	else if (o == 1)
	{
		glPushMatrix();
		m17.Draw();
		glPopMatrix();
		return 1;

	}

	glPopMatrix();
	return 0;

}

void player::textplayer(Model_3DS k)
{
	k.Materials[7].tex.Load(lp7);
	k.Materials[1].tex.Load(lp7);
	k.Materials[8].tex.Load(lp1);
	k.Materials[10].tex.Load(lp4);
	k.Materials[4].tex.Load(lp6);
	k.Materials[9].tex.Load(lp2);
	k.Materials[3].tex.Load(lp6);
	k.Materials[5].tex.Load(lp5);
	k.Materials[6].tex.Load(lp3);

}

void player::shadowplayer(float * Lightpos, double x, bool p)
{
	glPushMatrix();
	x -= 1.2;
	glDisable(GL_LIGHTING);
	m3dMakePlanarShadowMatrix(shadow, equation, Lightpos);
	// glLightfv(GL_LIGHT1, GL_POSITION, Lightpos);
	glDisable(GL_LIGHTING);
	glMultMatrixf((GLfloat *)shadow);
	//glBindTexture(GL_TEXTURE_2D, tex);
	glColor3d(0, 0, 0);
	if (p == 1)
	{
		Drawstad(1, 1);

	}
	else
	{
		Drawstad(0, 1);
	}

	glPopMatrix();
}





void player::intstad()
{
	// Really Nice Perspective Calculations
	m.Load(stadium);
	m2.Load(stadium2);
	m3.Load(stadium3);
	m4.Load(stadium4);
	m5.Load(stadium5);
	m6.Load(stadium6);
	m7.Load(stadium7);
	m8.Load(stadium8);
	m9.Load(stadium9);
	m10.Load(stadium10);
	m11.Load(stadium11);
	m12.Load(stadium12);
	m13.Load(stadium13);
	m14.Load(stadium14);
	m15.Load(stadium15);
	m16.Load(stadium16);
	m17.Load(stadium17);



	textplayer(m);
	textplayer(m2);
	textplayer(m3);
	textplayer(m4);
	textplayer(m5);
	textplayer(m6);
	textplayer(m7);
	textplayer(m8);
	textplayer(m9);
	textplayer(m10);
	textplayer(m11);
	textplayer(m12);
	textplayer(m13);
	textplayer(m14);
	textplayer(m15);
	textplayer(m16);
	textplayer(m17);
	//tex = LoadTexture(a,255);

	///////////////////
	M3DVector3f points[3] = { { -9, -52.8, -8 }, { -9, -52.8, 8 }, { 10, -52.8, 8 } };
	m3dGetPlaneEquation(equation, points[0], points[1], points[2]);
	//q = gluNewQuadric();
}


player::~player()
{
}
