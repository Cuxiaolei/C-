#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

class A
{
public:
	void func()
	{
		cout << "funcA" << endl;
	}
	int a;
private:
};

//类B拥有类A的成员变量， B has A  //B依赖与类A
class B
{
public:
	void funcB()
	{

	}
	A a;
};

//耦合度 高内聚 低耦合
//类C 的成员方法需要类A的形参， 说明C use 
class C
{
public:
	void funcC(A *a)
	{

	}
};

//D继承于A//类D is A //类D继承与A，耦合度很高
class D :public A
{
public:
	void funcD()
	{
		//可以访问A中的公共变量，无法访问私有变量
		cout << a << endl;
	}
};

class E :public D
{

};

int main()
{
	






	return 0;
}






