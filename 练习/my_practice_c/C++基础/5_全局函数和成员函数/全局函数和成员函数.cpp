#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class Test
{
public:
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void print()
	{
		cout << "a = " << this->a << ",b = " << this->b << endl;
	}

	int getA()
	{
		return this->a;
	}
	int getB()
	{
		return this->b;
	}


	//2成员方法
	Test TestAdd(Test& another)
	{
		Test temp(this->a + another.a, this->b + another.b);
		return temp;
	}

	//+=方法
	//1，返回Test类，不改变被调用对象本身
	Test TestAdd2(Test& another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;
	}

	//2,返回引用，改变被调用对象本身
	Test& TestAdd3(Test& another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;
	}
private:
	int a;
	int b;
};



//1 在全局提供一个Test相加的函数
#if 0
Test TestAdd(Test& t1, Test& t2)
{
	Test temp(t1.getA() + t2.getA(), t1.getB() + t2.getB());

	return temp;
}
#endif

int main()
{
	Test t1(10, 20);
	Test t2(100, 200);

//1全局方法
#if 0
	Test t3 = TestAdd(t1, t2);
	t3.print();
#endif
//2成员方法
	Test t3 = t1.TestAdd(t2);
	t3.print();




//+=方法
//如果相对一个对象连续使用掉用成员方法，每次都会改变对象本身，成员方法需要返回引用

//返回Test类，只能改变一次t1
	Test t4 = t1.TestAdd2(t2).TestAdd2(t2).TestAdd2(t2);
	t4.print();
//返回t1(对t1进行引用，返回引用),改变t1
	t1.TestAdd3(t2).TestAdd3(t2).TestAdd3(t2);//此时带上前面改变的一次，共改变了4次
	t1.print();





	return 0;
}























































