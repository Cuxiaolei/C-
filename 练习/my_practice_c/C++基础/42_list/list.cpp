#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



void PrintList(list<int> l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//初始化
void test1()
{
	list<int> l1;
	list<int> l2(10, 9);//有参构造  十个9
	list<int> l3(l2);//拷贝构造
	list<int> l4(l3.begin(), l3.end());
	PrintList(l4);
}
//插入删除
void test2()
{
	list<int> l1;
	l1.push_back(100);//尾插
	l1.push_front(200);//头插

	l1.insert(l1.begin(), 300);//头插
	l1.insert(l1.end(), 300);//尾插

	list<int>::iterator it = l1.begin();
	it++;
	it++;
	l1.insert(it, 500);
	//理解为插入到 插入之后 的下标位置
	PrintList(l1);
	list<int> l2(l1);

	//删除
	l1.pop_back();
	l1.pop_front();
	l1.clear();//删除全部
	PrintList(l1);
	l1.erase(l1.begin(), l1.end());
	PrintList(l1);
	l2.remove(300);//删除所有匹配值
	PrintList(l2);

	//容器元素反转
	l2.reverse();
	PrintList(l2);
}

void test3()
{
	list<int> l;
	l.assign(10, 10);//和构造一样

	list<int> l2;
	l2 = l;
	l2.swap(l);
}

//排序
void test4()
{
	list<int> l1;
}

bool myCompare(int v1, int v2)
{
	return v1 > v2;
}
void test5()
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(15);
	l1.push_back(14);
	l1.push_back(16);
	l1.push_back(12);
	l1.push_back(188);
	l1.push_back(134);

	PrintList(l1);
	l1.sort();//默认从小到大
	PrintList(l1);
	//从大到小
	l1.sort(myCompare);//添加bool函数
	PrintList(l1);
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	//test5();


	return 0;
}