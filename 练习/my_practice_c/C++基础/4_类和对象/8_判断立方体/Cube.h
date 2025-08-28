#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

class Cube
{
public:
	void setABC(int a, int b, int c);
	double getArea();
	double getVolume();
	double getA();
	double getB();
	double getC();
	bool Judge(Cube& anther);
private:
	double m_a;
	double m_b;
	double m_c;
};

