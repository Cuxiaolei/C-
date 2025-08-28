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
		//�����뾶֮��
		double rr = r0 + another.r0;
		//��Բ�ĵľ���
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
	cout << "�������һ��Բ��Բ������Ͱ뾶��" << endl;
	cin >> x1 >> y1 >> r1;
	cout << "������ڶ���Բ��Բ������Ͱ뾶��" << endl;
	cin >> x2 >> y2 >> r2;
	c1.getCircle(x1, y1, r1);
	c2.getCircle(x2, y2, r2);

	if (c1.Judge(c2))
	{
		cout << "��Բ�ཻ��" << endl;
	}
	else
	{
		cout << "��Բ���ཻ" << endl;
	}

}