#include "Circle.h"
#include "Point.h"
void Circle::setXY(int x, int y)
{
	x0 = x;
	y0 = y;
}
void Circle::setR(int r)
{
	r0 = r;
}

bool Circle::judgePoint(Point& p)
{
	int d;
	d = (p.getX() - x0) * (p.getX() - x0) + (p.getY() - y0) * (p.getY() - y0);

	if (d >= r0 * r0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

