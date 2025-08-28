#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class A
{
public:
	A(int a)
	{
		m_a = a;
	}

	void print()
	{
		cout << m_a << endl;
	}

	~A()
	{
		cout << "~A" << endl;
	}
private:
	int m_a;
};

//构造函数的初始化列表
class B
{
public:
	//在函数之后加冒号，相当于调用A的构造函数
	B(A& a1, A& a2, int b) :m_a1(a1), m_a2(a2), m_b(b)
	{
	}

	void print()
	{
		cout << m_b << "__";
		m_a1.print();
		cout << "__";
		m_a2.print();
		cout << "__";
		cout << endl;
	}

	~B()
	{
		cout << "~B()" << endl;
	}
private:
	int m_b;
	A m_a1;
	A m_a2;
};

int main()
{
	A a1(100);
	A a2(1000);
	B b1(a1, a2, 999);

	a1.print();
	a2.print();
	b1.print();


}