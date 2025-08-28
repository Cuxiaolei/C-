#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//双目运算符重载
//使用：L#R
//operator#(L,R);  全局函数
//L.operator#(R);  局部函数

//只能重载已有的操作符，不能自定义操作符
//"."".*""::""?:"四个运算符不能重载

//重载不能改变操作对象的个数

//重载不能改变运算符的优先级别

//重载不能改变运算符的结合性

//重载运算符的函数不能有默认的参数

//重载的运算符必须和用户定义的自定义类型的对象一起使用，其参数至少应有一个是类对象（或类对象的引用）

//“=”和“&”不必用户重载


class Complex
{
public:
	Complex()
	{

	}
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

	//双目运算符

	//成员操作符重载函数
	Complex operator+(Complex& another)
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}
	Complex operator-(Complex& another)
	{
		Complex temp(this->a - another.a, this->b - another.b);
		return temp;
	}

	Complex& operator+=(Complex& another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;
	}

	//单目运算符

	//重载前++运算符
	Complex& operator++()
	{
		this->a ++;
		this->b ++;
		return *this;
	}

	//重载后++运算符
	const Complex operator++(int)//亚元，必须要有
	{
		Complex temp(this->a, this->b);
		this->a++;
		this->b++;
		return temp;
	}
#if 0
	//左移操作符重载
	ostream& operator<<(ostream& os)	//这种情况必须要
	{									//c1<<cout;改变了原义，古左移操作符不建议写在成员方法中
		os << "(" << this->a << "," << this->b << ")" << endl;
		return os;
	}
#endif
	friend Complex complexAdd(Complex& c1, Complex& c2);
	//friend Complex operator+(Complex& c1, Complex& c2);
	//friend const Complex operator++(Complex& c1, int);
	friend ostream& operator<<(ostream& os, Complex& c);
	friend istream& operator>>(istream& is, Complex& c);

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
//双目
Complex operator+(Complex& c1, Complex& c2)
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}

//单目
//重载前++运算符
Complex& operator++(Complex& c1)
{
	c1.a++;
	c1.b++;
	return c1;
}

//重载后++运算符
const Complex operator++(Complex& c1, int)
{
	Complex temp(c1.a, c1.b);
	//对
	c1.a++;
	c1.b++;
	return temp;
}

#endif
//左移右移运算符
//左移
ostream& operator<<(ostream& os, Complex& c)
{
	os << "(" << c.a << "," << c.b << ")" << endl;
	return os;
}
//右移
istream& operator>>(istream& is, Complex& c)
{
	cout << "a:";
	is >> c.a;
	cout << "b:";
	is >> c.b;
	return is;
}

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

	//成员操作符重载方式
	Complex c7 = c1.operator+(c2);
	c7.printComplex();

	Complex c8 = c1 - c2;
	c8.printComplex();

	Complex c9 = c1.operator-(c2);
	c9.printComplex();
	//可以连减
	Complex c10 = c1 - c1 - c2;
	c10.printComplex();

	c1 += c2;
	c1.printComplex();

	c1.operator+=(c2);
	c1.printComplex();

	(c2 += c1) += c2;
	c2.printComplex();

	//前缀++
	++c2;
	c2.printComplex();

	//后缀++
	c2++;
	c2.printComplex();

	//左移操作符重载
	cout << c1;
	cout << c2;
	//c1 << cout;(成员方法)

	//右移操作符重载
	Complex c11;
	cin >> c11;
	cout << c11; 
	return 0;
}