#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class Complex
{
public:
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void printComplex()
	{
		cout << "(" << this->a << "," << this->b << ")" << endl;
	}

	//成员函数
	Complex complexAdd(Complex& another)
	{
		Complex temp(a + another.a, b + another.b);
		return temp;
	}

	//成员操作符重载函数
	Complex operator+(Complex& another)
	{
		Complex temp(a + another.a, b + another.b);
		return temp;
	}

	friend Complex complexAdd(Complex& c1, Complex& c2);
	//friend Complex operator+(Complex& c1, Complex& c2);

private:
	int a;//实数
	int b;//虚数
};



//全局函数
Complex complexAdd(Complex& c1, Complex& c2)
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}


//操作符重载写在全局
#if 0
Complex operator+(Complex& c1, Complex& c2)
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}
#endif


int main()
{
	Complex c1(1, 2);
	Complex c2(2, 3);
	c1.printComplex();
	c2.printComplex();

	//全局方式
	Complex c3 = complexAdd(c1, c2);
	c3.printComplex();

	//局部方法
	Complex c4 = c1.complexAdd(c2);
	c4.printComplex();

#if 0
	//全局操作符重载方式1
	Complex c5 = c1 + c2;
	c5.printComplex();


	//全局操作符重载方式2
	Complex c6 = operator+(c1, c2);
	c6.printComplex();
#endif

	//但这种方式的+会找到所有的operator+进行匹配
	//所以以这种方式使用的话只能使operator+同时存在一个
	//成员操作符重载方式1
	Complex c6 = c1 + c2;
	c6.printComplex();

	//成员操作符重载方式1
	Complex c7 = c1.operator+(c2);
	c7.printComplex();

	return 0;
}