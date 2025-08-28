#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<vector>//动态数组 可变数组
using namespace std;


void PrintVector(int v)
{
	cout << v << " ";
}


//STL基本语法
void test1()
{
	//定义一个容器，并且指定这个容器存放的元素类型时int
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);

	//通过STL提供的for_each算法
	//容器提供的迭代器

	vector<int>::iterator pbegin = v.begin();
	vector<int>::iterator pend = v.end();


	//容器中可能存放基础的数据类型，也可能存放自定义数据类型
	for_each(pbegin, pend, PrintVector);
}

//容器也可以存放自定义的数据类型
class Person
{
public:
	Person(int age,int id)
	{
		this->mage = age;
		this->mid = id;
	}

public:
	int mage;
	int mid;
};
void PrintVector1(Person v)
{
	cout << v.mage << " " << v.mid << endl;
}
void test2()
{
	vector<Person> v;
	Person p1(10, 20), p2(200, 343), p3(23, 465);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//遍历1
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).mage << " ";
		cout << (*it).mid << endl;
	}
	cout << endl;

	//遍历2
	for_each(v.begin(), v.end(), PrintVector1);
	cout << endl;
}


int main()
{
	//test1();
	test2();
	return 0;
}