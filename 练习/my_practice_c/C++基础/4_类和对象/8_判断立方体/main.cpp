
#include "Cube.h"


bool Judge(Cube& c1, Cube& c2)
{
	if (c1.getA() == c2.getA() &&
		c1.getB() == c2.getB() &&
		c1.getC() == c2.getC())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Cube c1;
	Cube c2;

	c1.setABC(10, 20, 30);
	c2.setABC(10, 20, 31);

	cout << "c1的表面积是：" << c1.getArea() << endl;
	cout << "c2的表面积是：" << c2.getArea() << endl;

	if (c1.Judge(c2))
	{
		cout << "相同" << endl;
	}
	else
	{
		cout << "不相同" << endl;
	}





	return 0;
}