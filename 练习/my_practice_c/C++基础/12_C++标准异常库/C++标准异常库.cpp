#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<stdexcept>
#include<exception>
using namespace std;
//�����Լ����쳣��̳б�׼�쳣��
//���̳б�׼�쳣��ʱ��Ӧ�����ظ����what����

int divide(int x, int y)
{
	if (y == 0)
	{
		throw out_of_range("����Ϊ0");

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
			throw out_of_range("�����������䷶Χ");
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
	throw MyOutOffRange("���Լ���out_of_range");
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
	//û�п������죬ֻ�����ù������ӹ�throw
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