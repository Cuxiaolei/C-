#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class Test
{
public:
	Test(int x, int y)
	{
		x0 = x;
		y0 = y;
	}

	//显示的拷贝构造函数
	//不写也可以，系统默认的有此拷贝函数
	Test(const Test& another)
	{
		x0 = another.x0;
		y0 = another.y0;
	}
	void print() 
	{
		cout << "x=" << x0 << endl;
		cout << "y=" << y0 << endl;
	}
	~Test()
	{
		cout << "结束" << endl;
	}

private:
	int x0;
	int y0;
};



Test print1(Test t1)//形参结束之后回收，引用的话不回收
{
	return t1;//返回形参回收，进行析构（1）
}

Test print2(Test &t1)//引用的话不回收，即此函数结束之后对t1不析构
{
	return t1;//返回引用值不析构
}

int main()
{
	Test t1(10, 999);
	//存在默认的拷贝构造函数接口
	Test t2(t1);//相当于t1 = t2；
	print1(t1);//此时无接收指，直接进行析构（2）
	print2(t1);//此时无接收指，直接进行析构（3）
	t1.print();
	t2.print();

	return 0;
}

