#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include "Circle.h"
#include "Point.h"
using namespace std;


int main()
{
	Circle c;
	Point p;
	int x1, y1, r1;
	int x2, y2;
	cout << "请输入圆的圆心坐标和半径：" << endl;
	cin >> x1 >> y1 >> r1;
	cout << "请输入判断点的坐标:" << endl;
	cin >> x2 >> y2;
	c.setXY(x1, y1);
	c.setR(r1);
	p.setXY(x2, y2);

	if (c.judgePoint(p))
	{
		cout << "该点在圆内" << endl;
	}
	else
	{
		cout << "该点不在圆内" << endl;
	}

	return 0;
}