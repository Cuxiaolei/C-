#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class MyPlus
{
public:
	int operator()(int val)
	{
		return val;
	}
};

//transform 将一个容器的元素 搬运 到另一个容器中
void test1()
{
	vector<int> v1;
	vector<int> v2;
	v2.resize(11);//必须用resize开辟空间(默认值为0)，reserve开辟的空间不能直接用(没有默认值)

	for (int i = 0; i < 10; i++)
	{ 
		v1.push_back(i);
	}


	transform(v1.begin(), v1.end(), v2.begin(), MyPlus());//先将v1的值在MyPlus()中拿到,再返回进v2的迭代器中

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << endl;
	}
}


//常用的查找算法
void test2()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>::iterator ret = find(v1.begin(), v1.end(), 5);
	if (ret == v1.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了" << *ret << endl;
	}
}


class Person
{
public:
	Person(int age, int id) :age(age), id(id) {}
	bool operator==(const Person& p) const
	{
		return p.id == this->id && p.age == this->age;
	}
public:
	int id;
	int age;
};
void test3()
{
	vector<Person> v1;

	Person p1(10, 20);
	Person p2(20, 20);
	Person p3(30, 20);
	Person p4(40, 20);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);

	vector<Person>::iterator ret = find(v1.begin(), v1.end(), p1);
	if (ret == v1.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了" << endl;
	}
}

bool MySearch(int val)
{
	return val > 5;
}

bool MySearch2(int val)
{
	return val > 5;
}

//binary_serach二分查找
void test4()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//v1.push_back(9);
	//只能判断是否能找到，不能返回位置
	bool ret = binary_search(v1.begin(), v1.end(), 5);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}

	//寻找相邻重复元素
	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
	if (it == v1.end())
	{
		cout << "没有找到相邻重复元素" << endl;
	}
	else
		cout << "找到了相邻重复元素  " << *it << endl;


	//find_if
	it = find_if(v1.begin(), v1.end(), MySearch);
	if (it == v1.end())
	{
		cout << "没有找到符合条件的元素" << endl;
	}
	else
		cout << "找到了第一个符合条件的元素：" << *it << endl;

	//count count_if
	int num = count(v1.begin(), v1.end(), 9);//查找元素的个数
	cout << "找到了" << num << "个" << endl;
	num = count_if(v1.begin(), v1.end(), MySearch2);//查找符合条件的元素个数
	cout << "符合条件的个数为：" << num << endl;


}


int main()
{
	test1();
	//test2();
	//test3();
	//test4();




	return 0;
}