#pragma once
#include <vector>
#include "Ball1.h"
class Impact1
{
public:
	bool isImpact;
	Impact1();
	Ball1* ball;
	Diagonal diagonal;
	void startImpact(Ball1* ball,int ball1, int w);
	//void ImpactWall();
	void ImpactWall1(int tex);
	//void ImpactWall_1(std::vector <Ball> ballList1);
	int Impactwall(int x, int y, int z, int r);
	int Impactmag(int x, int y, int z, int r);

	float dd(float r1, float v1, float t);
	float Y(float xx, float yy, float zz, float r);
	void fallingBall();
	int root = 1;
	~Impact1();
};

