#include "Cube.h"

void Cube::setABC(int a, int b, int c)
{
	m_a = a;
	m_b = b;
	m_c = c;
}
double Cube::getArea()
{
	return (m_a * m_b) * 2 + (m_a * m_c) * 2 + (m_b * m_c) * 2;
}
double Cube::getVolume()
{
	return m_a * m_b * m_c;
}

double Cube::getA()
{
	return m_a;
}

double Cube::getB()
{
	return m_b;
}

double Cube::getC()
{
	return m_c;
}

bool Cube::Judge(Cube& another)
{
	if (m_a == another.m_a &&
		m_b == another.m_b &&
		m_c == another.m_c)
	{
		return true;
	}
	else
	{
		return false;
	}
}