#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



//规则1：只要是父类中private中的成员，不管什么继承方式，儿子都访问不了
//规则2：如果共有（public）继承，儿子中的访问控制权限保持不变
//规则3：如果是保护（protected）继承，在儿子中，继承父亲的【public成员】和【protected成员】都是protected成员，而private成员依然是private成员，孙子可以访问，外部不可访问
//规则4：如果是私有（private）继承，在儿子中，继承父亲的【public成员】和【protected成员】都是private成员，而private成员依然是private成员,在孙子中和外部都不可访问

class Parent
{
public:
	int pub;	//在类的内部和外部都能访问
protected:
	int pro;	//在类的内部可以访问，在类的外部不可以访问
private:
	int pri;	//在类的内部可以访问，在类的外部不可以访问
};

//共有继承
class Child :public Parent
{
public:
	void func()
	{
		cout << pub << endl;	//pub 是父类的public成员变量，在public继承类的【内部 外部】都可以访问。
		cout << pro << endl;	//pro 是父类protected成员变量，在public继承类的【内部】可以访问，【外部】不可访问	在孙子类中的内部也可以访问
#if 0
		cout << pri << endl;	//pri是父类的private变量，子类以及外部都不可访问
#endif
	}
};

//保护继承
class Child2 :protected Parent
{
public:
	void func2()
	{
		cout << pub << endl;//此时pub 通过protected继承，在类的内部能够访问
							//pub 在类的内部可以访问，类的外部访问不了，在孙子类可以访问
	}
};

//私有继承
class Child3 :private Parent
{
public:
	void func3()
	{
		cout << pub << endl;//pub在类的内部可以访问，在类的外部不可访问
		cout << pro << endl;//父类的保护成员，儿子可以访问，但由于私有继承，在儿子里已经变成私有成员，孙子和外部都不可访问
#if 0
		cout << pri << endl;//父类的私有成员不可访问
#endif
	}
};

//三看原则：
//1 看调用的成员变量是在类的内部还是在类的外部
//2 看儿子的继承方式
//3 当前变量在儿子中的访问权限

int main()
{
	Child c1;
	c1.func();
#if 1
	Child2 c2;
	c2.func2();

	//报错，pub不是Child2中的，而是通过保护【继承】Parent的public中的成员
	//c2.pub;
#endif
	return 0;
}