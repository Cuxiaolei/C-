#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


template<class T>
class Person
{
public:
	Person(T age)
	{
		this->mage = age;
	}
public:
	T mage;
	static int a;
};

//类外初始化
template<class T> int Person<T>::a = 100;



int main()
{
	Person<int> p1(10), p2(20), p3(30);
	Person<char> pp1(10), pp2(20), pp3(30);


	cout << p1.a << endl;//100
	cout << pp1.a << endl;//100
	p1.a = 101; 
	pp1.a = 102;
	//每种模板会生成一个自己独有的静态变量，由该模板类型使用
	cout << p1.a << endl;//101
	cout << p2.a << endl;//101
	cout << p3.a << endl;//101
	cout << pp1.a << endl;//102
	cout << pp2.a << endl;//102
	cout << pp3.a << endl;//102


	return 0;
}