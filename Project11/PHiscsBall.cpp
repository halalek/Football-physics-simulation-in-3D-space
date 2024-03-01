#include "PHiscsBall.h"
#include "PHiscsBall.h"
#include<iostream>
#include <iomanip> // for std::setprecision()

PHiscsBall::PHiscsBall()
{

	std::cout << std::setprecision(3); // show 3 digits of precision

}
void PHiscsBall::STARTPHiscs()
{
	if ((out && y< -100)) {

		return;
	}

	if (VextorsForces.size() == 0) {
		Vector3D FORCES;
		FORCES.y = -0.98*M;
		VextorsForces.push_back(FORCES);
		FORCES.y = 0.98*M;
		VextorsForces.push_back(FORCES);
		FORCES.y = 0;

		FORCES.x = (rand() % 2) - 1;
		FORCES.z = (rand() % 2) - 1;

		VextorsForces.push_back(FORCES);

	}


	if (y < r && !out) {

		/*Vector3D SUMFORCES1;
		SUMFORCES1.x = 0;
		SUMFORCES1.y = -SUMFORCES.y;
		SUMFORCES1.z = 0;
		VextorsForces.push_back(SUMFORCES1);*/
		y = r;

	}



	if (y == r && !out) {
		//std::cout << "\nH:" << H;

		if (VextorsForces[1].y == 0) {
			if (VextorsForces.size() == 2) {
				SUMFORCES.y = VextorsForces[0].y;
			}
			VextorsForces[1].y = -SUMFORCES.y;

			/*	std::cout << "\n*************\nSUMFORCES.y:" << SUMFORCES.y;
				std::cout << "\nVextorsForces[0].y:" << VextorsForces[0].y;
				std::cout << "\nVextorsForces[1].y:" << VextorsForces[1].y;*/
			if (VextorsForces[0].y != -0.98*M) {
				VextorsForces[1].y = -SUMFORCES.y + (0.98*M + VextorsForces[0].y);
				VextorsForces[0].y = -0.98*M;


			}

		}

		if (H != 0 && typeball == 2) {
			H *= 0.8;
			Vector3D FORCESRF;
			FORCESRF.y = H * 0.2;
			VextorsForces.push_back(FORCESRF);
		}
		if (H < 2) {
			H = 0;
		}

	}
	else if ((y > r && !(diagonal.Impact(x, y, z, r) == 1)) || (y > diagonal.Y(x, y, z, r) + r) || (out)) {
		if (H == 0 && VextorsForces[1].y != 0) {
			H = y;
			if (H < r * 2) {
				H = 0;
			}


		}
		VextorsForces[1].y = 0;

		for (int i = 2; i < VextorsForces.size(); i++) {
			if (VextorsForces[i].y > 0) {
				VextorsForces[i].y += VextorsForces[0].y;
				if (VextorsForces[i].y < 0) {
					VextorsForces[i].y = 0;
				}
			}

		}

		if (SUMFORCES.y < 0) {
			VextorsForces[0].y -= 0.05;

		}


	}
	//std::cout << "\nX:" << x;

	//std::cout << "\nY:" << y;

	if (diagonal.Impact(x, y, z, r) == 1 && !(y > diagonal.Y(x, y, z, r) + r)) {

		H = 0;
		y = diagonal.Y(x, y, z, r) + r;

	}
	else if (diagonal.Impact(x, y, z, r) == 2) {
		std::cout << "dddddddddddd\n";
		y = r;
		z -= 5;
	}
	//std::cout << "\n**********\nX:" << x;
	//std::cout << "\nZ:" << z;

	SUMFORCES.x = 0;
	SUMFORCES.y = 0;
	SUMFORCES.z = 0;
	for (int i = 0; i < VextorsForces.size(); i++) {
		if (!(std::abs(SUMFORCES.y + VextorsForces[i].y) >= std::fmax(std::abs(SUMFORCES.y), std::abs(VextorsForces[i].y))
			* std::numeric_limits<float>::epsilon())) {
			SUMFORCES.y = 0;

		}
		else {
			SUMFORCES.y += VextorsForces[i].y;
		}
		///////////////////////
		if (!(std::abs(SUMFORCES.x + VextorsForces[i].x) >= std::fmax(std::abs(SUMFORCES.x), std::abs(VextorsForces[i].x))
			* std::numeric_limits<float>::epsilon())) {
			SUMFORCES.x = 0;

		}
		else {
			SUMFORCES.x += VextorsForces[i].x;
		}
		////////////////////////////////////
		if (!(std::abs(SUMFORCES.z + VextorsForces[i].z) >= std::fmax(std::abs(SUMFORCES.z), std::abs(VextorsForces[i].z))
			* std::numeric_limits<float>::epsilon())) {
			SUMFORCES.z = 0;

		}
		else {
			SUMFORCES.z += VextorsForces[i].z;
		}

	}
	if (SUMFORCES.y != 0) {

	}

	//std::cout << "\n***********\nSUMFORCES.y1:" << SUMFORCES.y;


	if (SUMFORCES.x == 0 && SUMFORCES.y == 0 && SUMFORCES.z == 0 && VextorsForces.size() > 2 && y == r) {
		VextorsForces.erase(VextorsForces.begin() + 2, VextorsForces.end());
		VextorsForces[0].y = -0.98*M;
		VextorsForces[1].y = -VextorsForces[0].y;
		//VextorsForces.clear();
	}
	//std::cout << "\n:::::::::::::::" << VextorsForces.size();
	/*for (int i = 2; i < VextorsForces.size(); i++) {
		if (VextorsForces[i].x == 0 &z& VextorsForces[i].y == 0 && VextorsForces[i].z == 0) {
			VextorsForces.erase(VextorsForces.begin() + i);
		}

	}*/


	////////////////////////////////////////////////////////////////////////////////

	/*if (SUMFORCES.y<0) {
		Vector3D SUMFORCES1;
		SUMFORCES1.x = 0;
		SUMFORCES1.y = -SUMFORCES.y;
		SUMFORCES1.z = 0;
		SETV(SUMFORCES1);
	}*/

	//	std::cout << "\nZZ:" <<  z<<"  YY:"<< y;

	if (SUMFORCES.x != 0 && SUMFORCES.y == 0) {

		if (SUMFORCES.x > 0) {

			Vector3D FORCESRF;
			FORCESRF.x = -M * GETMU();
			if (SUMFORCES.x + FORCESRF.x <= 0)
				FORCESRF.x = -SUMFORCES.x;
			VextorsForces.push_back(FORCESRF);
		}
		else {

			Vector3D FORCESRF;
			FORCESRF.x = M * GETMU();
			if (SUMFORCES.x + FORCESRF.x >= 0)
				FORCESRF.x = -SUMFORCES.x;
			//	SUMFORCES.x = SUMFORCES.x + FORCESRF.x;
			VextorsForces.push_back(FORCESRF);
		}

	}


	if (SUMFORCES.z != 0 && SUMFORCES.y == 0) {
		//std::cout << "\nZ:" << VextorsForces.size();
		//std::cout << "\nZZ::::::::::::::::::::" << SUMFORCES.z;

		if (SUMFORCES.z > 0) {

			Vector3D FORCESRF;
			FORCESRF.z = -M * GETMU();
			if (SUMFORCES.z + FORCESRF.z <= 0) {
				FORCESRF.z = -SUMFORCES.z;
			}
			VextorsForces.push_back(FORCESRF);
			//std::cout << "\nZZ:" << FORCESRF.z;

		}
		else {

			Vector3D FORCESRF;
			FORCESRF.z = M * GETMU();
			if (SUMFORCES.z + FORCESRF.z >= 0)
				FORCESRF.z = -SUMFORCES.z;
			VextorsForces.push_back(FORCESRF);

		}

	}

	x += (SUMFORCES.x*t) / M;
	y += (SUMFORCES.y*t) / M;
	z += (SUMFORCES.z*t) / M;
	//std::cout << "deaa";



}



void PHiscsBall::SETF(Vector3D F)
{

	VextorsForces.push_back(F);

}

void PHiscsBall::SETV(Vector3D V)
{
	Vector3D FORCE;
	FORCE.x = (V.x * M) / t;
	FORCE.y = ((V.y * M) / t);
	FORCE.z = (V.z * M) / t;
	VextorsForces.push_back(FORCE);
}

double PHiscsBall::GETMU()
{
	if (typeball == 0) {
		return 0.015;

	}
	if (typeball == 1) {
		return 0.02;

	}
	if (typeball == 2) {
		return 0.005;

	}
	return 0.0;
}

Vector3D PHiscsBall::GETV()
{
	Vector3D V;
	V.x = (SUMFORCES.x / M) * t;
	V.y = ((SUMFORCES.y / M) * t);
	V.z = (SUMFORCES.z / M) * t;
	return V;

}

PHiscsBall::~PHiscsBall()
{
}

