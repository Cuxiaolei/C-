#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


void PrintDeque(deque<int> d)
{
	//打印
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//deque初始化
void test1()
{
	deque<int> d1;
	deque<int> d2(10, 5);
	deque<int> d3(d2.begin(), d2.end());
	deque<int> d4(d3);

	PrintDeque(d1);
	PrintDeque(d2);
	PrintDeque(d3);
	PrintDeque(d4);
}

//赋值 大小操作
void test2()
{
	deque<int> d1;
	deque<int> d2;
	d1.assign(10, 5);//十个5
	d2.assign(d1.begin(), d1.end());//迭代器指定区间赋值
	deque<int> d3;
	d3 = d2;//等号赋值
	PrintDeque(d1);
	PrintDeque(d2);
	PrintDeque(d3);
	d1.swap(d2);//交换元素
	PrintDeque(d1);
	PrintDeque(d2);
	if (d1.empty())
	{
		cout << "空" << endl;
	}

	d1.resize(5);//后五个元素扔掉
	PrintDeque(d1);
}

//插入删除
void test3()
{
	deque<int> d1;
	d1.push_back(100);
	d1.push_front(101);//前面进
	d1.push_back(200);//后面进
	d1.push_back(300);
	d1.push_back(400);
	d1.push_front(401);//401 101 100 200 300 400
	PrintDeque(d1);
}

int main()
{

	//test1();
	//test2();
	test3();




	return 0;
}