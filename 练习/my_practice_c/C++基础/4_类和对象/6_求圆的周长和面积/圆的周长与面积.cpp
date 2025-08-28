
#include "Circle.h"

int main()
{
	Circle c;
	c.setR(10);
	cout << "圆半径:" << c.getR() << endl;
	cout << "圆面积:" << c.getArea() << endl;
	cout << "圆周长:" << c.getGirth() << endl;

	return 0;
}