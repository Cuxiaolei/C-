#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



//这个函数只能抛出int float char三种类型异常，抛出其他的就报错,但catch(...)可以捕获到其他异常
void func() throw(int, float, char)
{
	throw 'a';
}

//不能抛出任何异常
void func2() throw()
{
	throw - 1;
}

//可以抛出任何类型异常
void func3()
{

}

int main()
{
	try
	{
		func();
	}
	catch (char str)
	{
		cout << str << endl;
	}
	catch (int e)
	{
		cout << "异常" << endl;
	}
	catch (...)//捕获所有异常
	{
		cout << "未知类型异常" << endl;
	}



	return 0;
}