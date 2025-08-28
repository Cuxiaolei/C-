#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



class Sqr
{
public:
	Sqr()
	{

	}
	Sqr(int a)
	{
		this->a = a;
	}

	int operator()(int value)
	{
		return value * value;
	}
	int operator()(int a, int b)
	{
		return a * b;
	}
private:
	int a;

};
void test1()
{
	Sqr s(10);

	//调用一个参数的重载
	int value = s(4);//将一个对象，当成一个普通函数来调用
	int a = s.operator()(6);	//称这种对象是仿函数，伪函数

	cout << value << endl;
	cout << a << endl;

	//调用两个参数的重载
	int c = s(10, 20); //10*20

	cout << c << endl;
}


class A
{
public:
	A(int a)
	{
		this->a = a;
	}
	//void*是万能指针
	//重载new操作符
	void* operator new(size_t size)
	{
		cout << "重载了new操作符" << endl;
		return malloc(size);
	}

	void* operator new[](size_t size)
	{
		cout << "重载了new操作符" << endl;
		return malloc(size);
	}
	//重载delete操作符
	//即使重载了delete，在使用时也会触发析构函数
	void operator delete(void* p)
	{
		cout << "重载了delete操作符" << endl;
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
	}

	~A()
	{
		cout << "~A()..." << endl;
	}


private:
	int a;
};

void test2()
{
	int* a = new int;

	A* ap = new A(10);

	delete ap;//重载之后依然会触发析构函数

}

int main()
{
	//test1();
	test2();


	return 0;
}