#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

void func1()
{
	throw 1;
}

void func2()
{
	throw "chaoefsfa";
}


class MyException
{
public:
	MyException()
	{
		cout << "构造函数" << endl;
	}
	MyException(const char* str)
	{
		cout << "构造函数" << endl;
		error = new char[strlen(str) + 1];
		strcpy(error, str);
	}
	void what()
	{
		cout << "未知异常！" << endl;
	}
	~MyException()
	{
		cout << "析构函数" << endl;
	}
public:
	char* error;
};

void func3()
{
	MyException a("我写的异常");//注意加括号
	throw a;
}


void test1()
{
	try
	{
		func1();
	}
	catch (int e)
	{
		cout << "异常捕获" << e <<endl;
	}
}

void test2()
{
	try
	{
		func2();
	}
	catch (const char* e)
	{
		cout << "出现异常：" << e <<endl;
	}
}


//在类对象中捕获异常
void test3()
{
	//普通类型元组 引用 指针
	//普通元素 异常对象catch处理完之后就析构
	try
	{
		func3();
	}
	catch (MyException e)
	{
		e.what();
	}
}

int main()
{
	//test1();
	//test2();
	test3();



	return 0;
}