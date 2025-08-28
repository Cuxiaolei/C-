#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class Building
{

};
class Animal
{
public:

};

class Cat :public Animal
{

};


void test01()
{
	//static_cast<需要转换的类型>(其他类型数据);
	//比较安全
	//static_cast 用于内置的数据类型
	//还有具有继承关系的指针或引用
	int a = 99;
	char c = static_cast<char>(a);
	cout << c << endl;

	//指针
#if 0
	//基础数据类型指针不可以转换
	int* p = NULL;
	char* sp = static_cast<char*>(p);//类型转换无效

	//对象指针不可以转换
	Building* a1;
	Animal* b1 = static_cast<Animal*>(a1);//不存在跨类的转换
#endif
#if 0
	//可以转换具有继承关系的对象指针
	Animal* ani = NULL;
	Cat* cat = static_cast<Cat*>(ani);//父类转换为子类

	Cat* cat1 = NULL;
	Animal* ani1 = static_cast<Animal*>(cat1);//子类转换为父类；
	//引用
	//具有继承关系的引用可以转换
	Animal ani2;
	Animal& ani3 = ani2;
	Cat& cat2= static_cast<Cat&>(ani3);//父类转子类

	Cat cat3;
	Cat& cat4 = cat3;
	Animal& ani4 = static_cast<Animal&>(cat4);//子类转父类
#endif
}

	//dynamic_cast 转换具有继承关系的指针或引用，在转换之前会进行对象类的检查
void test02()
{
	//不可转换的
#if 0
	//基础数据类型
	int a = 99;
	char b = dynamic_cast<char>(a);//错误，只能转换指针或引用

	//非继承关系的指针
	Animal* ani = NULL;
	Building* building = dynamic_cast<Building*>(ani);//dynamic_cast必须包含多态类型，即只能转换继承关系的指针

	Animal* ani1 = NULL;
	Cat* cat1 = dynamic_cast<Cat*>(ani1);//dynamic_cast不能从父类转为子类（一般子类比父类大）
#endif

	//可以转换的
#if 0
	Cat* cat2 = NULL;
	Animal* ani2 = dynamic_cast<Animal*>(cat2);//子类成功转为父类
#endif
	//结论：dynamic_cast只能转换具有继承关系的指针或者引用，且只能由子类转为父类
}


//const_cast 指针 引用 或者对象指针
void test03()
{
	//可以增加或去除变量的const性
#if 0
	//基础数据类型可以转换
	int a = 10;
	const int& b = a;
	int& c = const_cast<int&>(b);
	c = 20;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	//指针
	const int* p = NULL;
	int* p2 = const_cast<int*>(p);
#endif
}


//reinterprte_cast 强制类型转换
typedef void(FUNC1)(int, int);//函数指针
typedef int(FUNC2)(int, char*);
void test04()
{
	//1. 无关的指针类型可以进行转换
	Building* building = NULL;
	Animal* ani = reinterpret_cast<Animal*>(building);

	//2. 函数指针转换
	FUNC1* func1;
	FUNC2* func2 = reinterpret_cast<FUNC2*>(func1);
}

//1. 一般情况下，不建议进行类型转换



int main()
{
	//test01();
	test03();



	return 0;




}