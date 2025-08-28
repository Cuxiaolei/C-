#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class MyPrint :public binary_function<int, int, void>//绑定适配器
{
public:
	void operator()(int v,int val) const//仿函数只能有一个参数
	{
		cout << v << " " << val << " ";
		cout << v + val << " " << endl;;
	}
};

//仿函数适配器 bindlst bind2nd
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//仿函数中只能有一个参数，不能再次传参
	//绑定适配器
	for_each(v.begin(), v.end(), bind2nd(MyPrint(),200));
	//将一个二元函数对象转变成一元的函数对象
	

	//bind1st bind2nd 绑定适配器,将第二个参数进行绑定
	//bind1st 绑定的是第一个参数
	//bind2nd 绑定的是第二个参数
}



class MyCompare :public binary_function<int, int, bool>
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
	void operator()(int v)
	{
		cout << v << " ";
	}
};

struct MyGreater5 :public unary_function<int, bool>
{
	bool operator()(int v) const
	{
		return v < 5;
	}
};
//仿函数适配器 not1      not2
//取反适配器
void test2()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 100 + 3);
	}


	//not2是取反适配器，将排序逆转
	//如果对二元谓词取反，用not2()
	//如果对一元谓词取反，用not1()
	sort(v.begin(), v.end(), not2(MyCompare()));
	for_each(v.begin(), v.end(), MyCompare());
	cout << endl;

	//返回 第一个 符合条件的迭代器,和容器中的顺序有关
	vector<int>::iterator it = find_if(v.begin(), v.end(), not1(MyGreater5()));
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	cout << *it << endl;

}
void MyPrint3(int val,int v)
{
	cout << "val:" << val << "  v:" << v <<"  ";
	cout << val << " " << endl;
}

//仿函数适配器 ptr_fun
void test3()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 100 + 3);
	}
	//把普通函数 转成 函数对象
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint3), 10));
}

class Person
{
public:
	Person(int age, int id) :age(age), id(id) {}
	void show()
	{
		cout << "age:" << age << "  id:" << id << endl;
	}
public:
	int age;
	int id;
};
//成员函数适配器 mem_fun     mem_fun_ref
void test4()
{
	//如果容器中存放的对象或对象指针，我们for_each算法打印的时候
	//调用类自己提供的打印函数
	vector<Person> v;
	Person p1(10, 20);
	Person p2(20, 20);
	Person p3(30, 20);
	Person p4(40, 20);
	Person p5(50, 20);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//格式：mem_fun_ref(&类名::函数名)
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::show));


	vector<Person*> v1;
	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);
	v1.push_back(&p5);
	//格式：mem_fun(&类名::函数名)
	for_each(v1.begin(), v1.end(), mem_fun(&Person::show));
	

	//如果存放的是对象指针 使用mem_fun
	//如果使用的是对象     使用mem_fun_ref
	
}
int main()
{
	//仿函数适配器 bindlst bind2nd
	//test1();


	//仿函数适配器 not1      not2
	//取反适配器
	//test2();

	//仿函数适配器 ptr_fun
	//test3();

	//成员函数适配器 mem_fun     mem_fun_ref
	test4();




	return 0;
}