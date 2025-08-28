#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


//������
class Point;
//���ʹĳ��������ĺ�����Ҫ�����������˽�г�Ա
class PointManager
{
public:
	//����������Ϊ�ڸú��������õ���Point���еĳ�Ա����������Point����������Ҫ��Point�����涨��ú���
	//���߽��ж��ļ�д�����Խ��������
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

	//��Ȩһ������(ȫ��)������ʹ�ú������Է��ʴ����˽�г�Ա
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