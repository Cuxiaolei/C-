#pragma once
#include "Point.h"
class Circle
{
public:
	void setXY(int x, int y);
	void setR(int r);
	//�ṩһ���жϵ��Ƿ���Բ��
	bool judgePoint(Point& p);

private:
	int x0;
	int y0;
	int r0;
};

