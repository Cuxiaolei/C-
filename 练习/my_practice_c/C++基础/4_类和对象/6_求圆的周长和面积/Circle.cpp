#include "Circle.h"

void Circle::setR(double r)
{
	m_r = r;
}
//半径
double Circle::getR()
{
	return m_r;
}
//面积
double Circle::getArea()
{
	m_area = 3.14 * getR() * getR();
	return m_area;
}
//周长
double Circle::getGirth()
{
	m_girth = m_r * 3.14 * 2;
	return m_girth;
}
