#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Circle
{
public:
	//���ð뾶
	void setR(double r);
	//�õ��뾶���ܳ������
	double getR();
	double getArea();
	double getGirth();

private:
	double m_r;
	double m_area;
	double m_girth;
};

