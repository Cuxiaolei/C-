#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<stdexcept>
#include<exception>
using namespace std;
//建议自己的异常类继承标准异常类
//当继承标准异常类时。应该重载父类的what函数

int divide(int x, int y)
{
	if (y == 0)
	{
		throw out_of_range("除数为0");

	}
	return x / y;
}

class Person
{
public:
	Person()
	{
		mAge = 0;
	}
	void setAge(int age)
	{
		if (age < 0 || age>100)
		{
			throw out_of_range("不在理论年龄范围");
		}
		this->mAge = age;
	}
public:
	int mAge;
};

class MyOutOffRange :public exception
{
public:
	MyOutOffRange(const char* error)
	{
		pError = new char[strlen(error) + 1];
		strcpy(pError, error);
	}
	~MyOutOffRange()
	{
		if (this->pError != NULL)
		{
			delete[] this->pError;
		}
	}

	virtual const char* what()
	{
		return pError;
	}
public:
	char* pError;
};

void func2()
{
	throw MyOutOffRange("我自己的out_of_range");
}



void test1()
{
	Person p;
	try
	{
		p.setAge(1000);
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}

void test2()
{
	try
	{
		func2();
	}
	//没有拷贝构造，只能引用过来，接过throw
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}


int main()
{

	//test1();
	test2();



	return 0;
}