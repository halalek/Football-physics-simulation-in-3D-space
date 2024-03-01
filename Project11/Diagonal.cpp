#include "Diagonal.h"
#include "Diagonal.h"
#include"Model_3DS.h"
#include <vector> 
#include <iostream>
#include "Vector3D.h"


using namespace std;


Diagonal::Diagonal()
{
}



float w = 0;
float Diagonal::Diagonalball(float r1, float v1, float t1)
{
	float v = v1;//100
	r1 = r1 / 100;
	w = abs(v / r1);  //r
	float t = (2 * M3D_PI * r1) / v;
	float tita1 = w / t1;

	//cout << "circle    " << w /(2* M3D_PI );
	return tita1;
}





float Diagonal::Diagonalballmag( float w, float t1)

{ 
	
	float tita1 = (w / (t1 ));
	//cout << "circle    " << w /(2* M3D_PI );
	return tita1;

}



void Diagonal::Drawtable()
{
	/*glBegin(GL_QUADS);
	glVertex3d(-25, 0, 0);
	glVertex3d(25, 0, 0);
	glVertex3d(25, 25, -35);
	glVertex3d(-25, 25, -35);
	glEnd();*/
	glTranslated(0, 0, 5);
	glTranslated(0, 0, -Z1);

	glRotated(tita * 180 / M3D_PI, 1, 0, 0);//ояли

	glBegin(GL_QUADS);
	glVertex3d(X1, 0, 0);
	glVertex3d(X, 0, 0);
	glVertex3d(X, 0, -Z);
	glVertex3d(X1, 0, -Z);
	glEnd();

}

void Diagonal::inttable()
{
}

int Diagonal::Impact(float xx, float yy, float zz, float r)
{
	if (tita > 0 && tita <= 90) {
		float L1 = 0;
		if (zz + r + Z1 < 0) {
			L1 = abs(zz + r + Z1);
		}
		double tan_pi_2 = tan(tita);
		tan_pi_2 = ((tan_pi_2 < 0.0001 && tan_pi_2 > -0.0001) ? 0 : tan_pi_2);
		if (zz < -Z1 && yy + r> Y(xx, yy, zz, r) - r && yy  < Y(xx, yy, zz, r) - r && xx > X1&&xx < X) {
			return 2;
		}



		if (zz + r >= -Z1) {
			if ((!(zz - r >= -Z1)) && xx > X1&&xx<X&&yy + r>abs(tan_pi_2)*L1) {
				return 1;

			}
		}
		else {
			double cos_pi_2 = cos(tita);
			cos_pi_2 = ((cos_pi_2 < 0.0001 && cos_pi_2 > -0.0001) ? 0 : cos_pi_2);
			if ((!(zz <= -Z - Z1 * abs(cos_pi_2))) && xx > X1&&xx < X&&yy + r>abs(tan_pi_2)*L1) {

				return 1;

			}
		}
	}
	return 0;

}

float Diagonal::Y(float xx, float yy, float zz, float r)
{
	float L1 = 0;
	if (zz + r + Z1 < 0) {
		L1 = abs(zz + r + Z1);
	}
	/*std::cout << "\n***********\nL1:" << L1;
//	std::cout << "\nwatar:" << (L1*L1) + (abs(tanf(tita))*L1 *abs(tanf(tita))*L1);
	std::cout << "\nwatar2:" << L1 / abs(cos(tita));*/
	/*double cos_pi_2 = cos(tita);
	cos_pi_2 = ((cos_pi_2 < 0.0001 && cos_pi_2 > -0.0001) ? 0 : cos_pi_2);*/
	//std::cout << "\nZZZ:" << -Z * abs(cos_pi_2) << "\n";
//	std::cout << "\nL2:" << (L1 / abs(cos(tita)))*abs(sin(tita));
	double tan_pi_2 = tan(tita);
	tan_pi_2 = ((tan_pi_2 < 0.0001 && tan_pi_2 > -0.0001) ? 0 : tan_pi_2);
	//	std::cout << "\nL1:" << L1;

		//std::cout << "\nL2:" << abs(tan_pi_2)*L1;


	return abs(tan_pi_2)*L1;
}
float Diagonal::tita = 0;
void Diagonal::Settita(float t1)
{
	tita = t1 * M3D_PI / 180;//rad//t1 ояли
}


Diagonal::~Diagonal()
{
}

