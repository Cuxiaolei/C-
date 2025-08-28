#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <math.h>
using namespace std;

class Point
{
public:
	void setXY(double x, double y)
	{
		x0 = x;
		y0 = y;
	}
	double getX()
	{
		return x0;
	}
	double getY()
	{
		return y0;
	}

	double Distance(Point& p)
	{
		return sqrt((p.getX() - x0) * (p.getX() - x0) + (p.getY() - y0) * (p.getY() - y0));
	}
private:
	double x0;
	double y0;
};

class Circle
{
public:
	void getCircle(double x, double y, double r)
	{
		p0.setXY(x, y);
		r0 = r;
	}
	bool Judge(Circle& another)
	{
		//两个半径之和
		double rr = r0 + another.r0;
		//两圆心的距离
		double dd = p0.Distance(another.p0);

		if (rr > dd)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	double r0;
	Point p0;
};




int main()
{
	Circle c1;
	Circle c2;
	double x1, x2, y1, y2, r1, r2;
	cout << "请输入第一个圆的圆心坐标和半径：" << endl;
	cin >> x1 >> y1 >> r1;
	cout << "请输入第二个圆的圆心坐标和半径：" << endl;
	cin >> x2 >> y2 >> r2;
	c1.getCircle(x1, y1, r1);
	c2.getCircle(x2, y2, r2);

	if (c1.Judge(c2))
	{
		cout << "两圆相交！" << endl;
	}
	else
	{
		cout << "两圆不相交" << endl;
	}

}