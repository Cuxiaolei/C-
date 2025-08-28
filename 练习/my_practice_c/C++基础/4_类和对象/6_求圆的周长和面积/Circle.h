#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Circle
{
public:
	//设置半径
	void setR(double r);
	//得到半径，周长，面积
	double getR();
	double getArea();
	double getGirth();

private:
	double m_r;
	double m_area;
	double m_girth;
};

