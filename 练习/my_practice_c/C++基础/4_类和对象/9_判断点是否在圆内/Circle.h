#pragma once
#include "Point.h"
class Circle
{
public:
	void setXY(int x, int y);
	void setR(int r);
	//提供一个判断点是否在圆内
	bool judgePoint(Point& p);

private:
	int x0;
	int y0;
	int r0;
};

