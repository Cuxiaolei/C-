#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//异常的基本语法




double divide(double x, double y)
{
	if (y == 0)
	{
		throw y;//抛异常
	}
	return x / y;
}
void test1()
{
	//试着去捕获异常
	try 
	{
		divide(10, 0); 
	}
	catch (double e)//捕获的为抛出来的值
	{
		//异常时根据类型进行匹配
		cout << "除数为" << e << endl;
	}
}






void CallDivide(int x, int y)
{
	divide(x, y);
}
void test2()
{
	try
	{
		CallDivide(10, 0);
	}
	catch (double e)
	{
		cout << "除数为" << e << endl;
	}
}

int main()
{
	//test1();
	test2();

	return 0;
}