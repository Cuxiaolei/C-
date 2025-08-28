#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//仿函数
struct mycompare {
	bool operator()(int v1, int v2)const//必须加const
	{
		return v1 > v2;
	}
};






void PrintSet(set<int> s1)
{
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *(it) << " ";
	}
	cout << endl;
}



//初始化
void  test1()
{

#if 0
	mycompare com;
	//com.operator()(10, 20);
	com(10, 20);//相同
#endif
	set<int,mycompare> s1;//多加一个伪函数可以变为从大到小排序
	//set<int> s1;
	s1.insert(4);
	s1.insert(3);
	s1.insert(65);
	s1.insert(1);
	s1.insert(2);
	s1.insert(8);
	s1.insert(5);
	s1.insert(66);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *(it) << " ";
	}
	cout << endl;
#if 0
	PrintSet(s1);//二叉搜索树可以自动排序
	//赋值操作
	set<int> s2(s1);
	set<int> s3;
	s3 = s1;

	//删除操作
	s1.erase(s1.begin());//删除指定位置
	s1.erase(4);//删除指定数据
	PrintSet(s1);
#endif
}

//find(key)返回迭代器，不存在的话返回s.end()
void test2()
{
	//实值
	set<int> s1;
	s1.insert(4);
	s1.insert(3);
	s1.insert(65);
	s1.insert(1);
	s1.insert(2);
	s1.insert(8);
	s1.insert(5);
	s1.insert(66);
	PrintSet(s1);
	set<int>::iterator it = s1.find(4);//返回迭代器

	if (it == s1.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了这个数据" << endl;
	}

	//lower_bound//返回第一个 大于等于 指定值的元素，若没找到则返回end()
	it = s1.lower_bound(55);
	if (it == s1.end())
	{
		cout << "没找到" << endl;
	}
	else
	cout << "找到了" << *it<< endl;

	//upper_bound//返回第一个 大于 指定值的元素，若没找到则返回end()
	it = s1.upper_bound(105);
	if (it == s1.end())
	{
		cout << "没找到" << endl;
	}
	else
	cout << "找到了" << *it << endl;

	//equal_range 返回Lower_bound 和 upper_bound的值//即返回一对迭代器
	pair<set<int>::iterator ,set<int>::iterator> myret = s1.equal_range(66);
	if (myret.first == s1.end())
	{
		cout << "没有找到lower_bound" << endl;
	}
	else
	{
		cout << "找到了lower_bound" << *(myret.first) << endl;
	}

	if (myret.second == s1.end())
	{
		cout << "没有找到upper_bound" << endl;
	}
	else
	{
		cout << "找到了upper_bound" << *(myret.second) << endl;
	}

}

class Person
{
public:
	Person(int age,int id):age(age),id(id){}

public:
	int id;
	int age;

};
class mycompare2
{
public:
	bool operator()(Person p1, Person p2)const
	{
		return p1.age > p2.age;
	}
};
void test3()
{
	set<Person,mycompare2> s1;//按照年龄从大到小排序
	Person p1(10, 213);
	Person p2(20, 202);
	Person p3(30, 133);
	Person p4(40, 244);
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);

	for (set<Person, mycompare2>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << (*it).age << " " << (*it).id << endl;
	}

	Person p5(100, 200);
	set<Person, mycompare2>::iterator ret = s1.find(p4);
	if (ret == s1.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了" << (*ret).age << " " << (*ret).id << endl;
	}

}

int main()
{


	//test1();
	//test2();
	test3();
	//test4();
	//test5();
	//test6();
	//test7();







	
	
	return 0;

}