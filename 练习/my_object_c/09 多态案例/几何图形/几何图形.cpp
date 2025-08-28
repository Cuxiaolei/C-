#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

class Shape
{
public:
	//打印出图形的基本属性
	virtual void show() = 0;
	//得到图形面积
	virtual double getArea() = 0;
};


class Circle :public Shape
{
public:
	Circle(double r)
	{
		this->r = r;
	}

	virtual void show()
	{
		cout << "打印出了一个圆" << endl;
	}

	virtual double getArea()
	{
		cout << "获取圆的面积：";
		return 3.14 * this->r * this->r;
	}
	~Circle()
	{
		cout << "圆的析构函数。。。" << endl;
	}
private:
	double r;
};


class Square :public Shape
{
public:
	Square(double a)
	{
		this->a = a;
	}

	virtual void show()
	{
		cout << "正方形的边长为：" << this->a << endl;
	}

	virtual double getArea()
	{
		cout << "正方形面积为：";
		return this->a * this->a;
	}

	~Square()
	{
		cout << "正方形的析构。。。" << endl;
	}
private:
	double a;
};


int main()
{
	Shape* arr[2] = { 0 };
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			double r;
			cout << "请输入圆的半径：";
			cin >> r;
			arr[i] = new Circle(r);
		}

		else
		{
			double a;
			cout << "请输入正方形的边长:";
			cin >> a;
			arr[i] = new Square(a);
		}
	}

	//遍历这个数组
	for (int i = 0; i < 2; i++)
	{
		arr[i]->show();
		cout << arr[i]->getArea() << endl;
		delete arr[i];
	}




	return 0;
}