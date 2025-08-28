#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



//岳不群
class Yuebuqun
{
public:
	Yuebuqun(string kongfu)
	{
		this->kongfu = kongfu;
	}

	virtual void fight()//虚继承，名字相同时为了区分父类和子类的同名函数
	{
		cout << "岳不群" << "使出了" << kongfu << "打人" << endl;
	}
	string kongfu;
private:
};


//林平之
class Linpingzhi :public Yuebuqun
{
public:
	Linpingzhi(string kongfu) :Yuebuqun( kongfu)
	{

	}
	virtual void fight()//虚继承，名字相同时为了区分父类和子类的同名函数
	{
		cout << "林平之使出了" << kongfu << "打人" << endl;
	}
};

class Linhuchong :public Yuebuqun
{
public:
	Linhuchong(string kongfu) :Yuebuqun(kongfu)
	{

	}
	void fight()
	{
		cout << "令狐冲使用了" << kongfu << endl;
	}
};


//在全局提供一个打斗的方法
void fightPeople(Yuebuqun* hero)
{
	//如果不加virtual，则只会调用Yuebuqun的fight
	hero->fight();//希望传递进来的如果是子类，调用子类的fight
					//如果传递进来的是父类，调用父类的fight
					//需要在fight函数前加virtual	
					//这种行为就是 多态行为
}
//多态发生的必要条件
//1 要有继承
//2 要有虚函数重写
//3 父类指针或引用 指向子类对象

int main()
{
	Yuebuqun *xiao = new Yuebuqun("僻邪剑谱");

	fightPeople(xiao);
	delete xiao;

	Linpingzhi* tong = new Linpingzhi("葵花宝典");
	fightPeople(tong);
	//编译器默认做了一个安全的处理。编译认为 不管传递时是子类对象还是父类对象
	//如果统一执行父类的方法 ，那么一定可以被成功执行
	//即父类指针可以指向子类，但子类指针不一定能指向父类
	Linhuchong* qiao = new Linhuchong("独孤九剑");
	fightPeople(qiao);
	delete tong;




	return 0;
}