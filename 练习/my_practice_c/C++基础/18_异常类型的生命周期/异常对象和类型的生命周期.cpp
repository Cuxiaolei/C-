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
		cout << "���캯��" << endl;
	}
	MyException(const char* str)
	{
		cout << "���캯��" << endl;
		error = new char[strlen(str) + 1];
		strcpy(error, str);
	}
	void what()
	{
		cout << "δ֪�쳣��" << endl;
	}
	~MyException()
	{
		cout << "��������" << endl;
	}
public:
	char* error;
};

void func3()
{
	MyException a("��д���쳣");//ע�������
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
		cout << "�쳣����" << e <<endl;
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
		cout << "�����쳣��" << e <<endl;
	}
}


//��������в����쳣
void test3()
{
	//��ͨ����Ԫ�� ���� ָ��
	//��ͨԪ�� �쳣����catch������֮�������
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