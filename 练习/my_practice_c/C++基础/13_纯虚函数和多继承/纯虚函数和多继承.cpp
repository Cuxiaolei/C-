#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

class Interface1
{
public:
	virtual void func1(int a, int b) = 0;
};

class Interface2
{
public:
	virtual void func2(int a) = 0;
};


//可以一个孩子有多个父亲,但每个父亲只能调用自己的虚函数
class Child :public Interface1, public Interface2
{
public:
	virtual void func1(int a, int b)
	{
		cout << "func1" << endl;
	}

	virtual void func2(int a)
	{
		cout << "func2" << endl;
	}
};

void test1()
{
	Interface1* sp1 = new Child;
	sp1->func1(10,20);
	Interface2* sp2 = new Child;
	sp2->func2(10);
}


int main()
{
	test1();
	return 0;
}