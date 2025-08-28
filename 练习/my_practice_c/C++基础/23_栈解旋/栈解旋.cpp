#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "对象构建！。。" << endl;
	}
	~Person()
	{
		cout << "对象析构" << endl;
	}
};

int divide(int x, int y)
{
	Person p1, p2;
	if (y == 0)
	{
		throw y;//只要抛出异常，对象自动被析构，相当于return
	}
	return x / y;
}


int main()
{
	
	try
	{
		divide(10, 10);
		divide(10, 0);
	}
	catch (int e)
	{
		cout << "异常捕获" << endl;
		cout << "除数为" << e << endl;
	}


	return 0;
}