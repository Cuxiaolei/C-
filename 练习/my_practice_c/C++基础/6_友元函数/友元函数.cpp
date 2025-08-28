#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


//声明类
class Point;
//如果使某个类里面的函数需要访问其他类的私有成员
class PointManager
{
public:
	//先声明，因为在该函数里面用到了Point类中的成员，仅仅声明Point还不够，需要在Point类下面定义该函数
	//或者进行多文件写，可以解决该问题
	double PointDistance(Point& p1, Point& p2);
private:

};

class Point
{
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int getX()
	{
		return this->x;
	}

	int getY()
	{
		return this->y;
	}

	//授权一个朋友(全局)函数，使该函数可以访问此类的私有成员
	friend double PointDistance(Point& p1, Point& p2);
	friend double PointManager::PointDistance(Point& p1, Point& p2);
private:
	int x;
	int y;
};


double PointDistance(Point& p1, Point& p2)
{
	double dis;
	int dd_x = p1.x - p2.x;
	int dd_y = p1.y - p2.y;

	dis = sqrt(dd_x * dd_x + dd_y * dd_y);

	return dis;
}

double PointManager::PointDistance(Point& p1, Point& p2)
{
	double dis;
	int dd_x = p1.x - p2.x;
	int dd_y = p1.y - p2.y;

	dis = sqrt(dd_x * dd_x + dd_y * dd_y);

	return dis;
}




int main()
{
	Point p1(3, 4);
	Point p2(4, 10);
	
	PointManager pm;
	cout << PointDistance(p1, p2) << endl;
	cout << pm.PointDistance(p1, p2) << endl;


	return 0;
}