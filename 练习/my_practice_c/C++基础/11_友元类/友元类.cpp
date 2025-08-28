#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class B;

class A
{
public:
	A(int a)
	{
		this->a = a;
	}
	void printA()
	{	
		////这样不行
		//B objB(100);
		//cout << objB.b << endl;
		cout << "A::a = " << this->a << endl;
	}

	//声明一个友元类B,使B中也可以访问A中的私有成员
	//但A中不能访问B，因为A把B当哥们，但是B并没有把A当哥们
	//要是想在A中访问B的私有成员，需要B对A进行友元
	//友元关系不能被继承
	//友元关系是单向的，不具有交换性
	//友元关系没有关系性
	friend class B;
private:
	int a;
};

class B
{
public:
	B(int b)
	{
		this->b = b;
	}
	void printB()
	{
		A objA(100);
		cout << objA.a << endl;
		cout << "B::b = " << this->b << endl;
	}

	friend class A;
private:
	int b;
};




int main()
{
	B objB(199);
	objB.printB();


	return 0;
}