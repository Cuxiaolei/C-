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
	cout << "������Բ��Բ������Ͱ뾶��" << endl;
	cin >> x1 >> y1 >> r1;
	cout << "�������жϵ������:" << endl;
	cin >> x2 >> y2;
	c.setXY(x1, y1);
	c.setR(r1);
	p.setXY(x2, y2);

	if (c.judgePoint(p))
	{
		cout << "�õ���Բ��" << endl;
	}
	else
	{
		cout << "�õ㲻��Բ��" << endl;
	}

	return 0;
}