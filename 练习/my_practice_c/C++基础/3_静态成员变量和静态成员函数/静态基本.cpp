#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



class A1
{
public:
	A1(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

	void print()
	{
		cout << m_a << "   " << m_b << endl;
	}
	//static修饰的静态成员变量
	static int m_c;//初始化必须在类的外部

	~A1()
	{
		cout << "~A1" << endl;
	}
private:
	int m_a;
	int m_b;
};

//静态成员变量的初始化，一定写在类的外面
int A1::m_c = 0;


class A2
{
public:
	A2(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

	void print()
	{
		cout << m_a << "   " << m_b << endl;
	}

	~A2()
	{
		cout << "~A2" << endl;
	}
private:
	int m_a;
	int m_b;
};

void test()
{
	//static定义子在静态区中
	static int a = 10;
	a++;
	cout << a << endl;
}


int main()
{
	A1 a1(10, 20);
	A1 a2(100, 200);
	a1.print();
	a2.print(); 
	test();
	test();//打印11，12；
			//因为static修饰的只能初始化一次；
	cout << a1.m_c << endl;


	return 0;
}