#include "Circle.h"

void Circle::setR(double r)
{
	m_r = r;
}
//�뾶
double Circle::getR()
{
	return m_r;
}
//���
double Circle::getArea()
{
	m_area = 3.14 * getR() * getR();
	return m_area;
}
//�ܳ�
double Circle::getGirth()
{
	m_girth = m_r * 3.14 * 2;
	return m_girth;
}
