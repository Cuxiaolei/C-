#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

void test1()
{
	string s1;//无参构造
	string s2(10, 'a');//十个位置，都是‘a'
	string s3("asdfwg");
	string s4(s3);//拷贝构造

	cout << s1 << endl;//重载“<<"操作符
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}


void test2()
{
	string s1;
	string s2("asdd");
	s1 = "qwetr";
	cout << s1 << endl;
	s1 = s2;
	cout << s1 << endl;
	s1 = 'a';
	cout << s1 << endl;

	//成员方法
	s1.assign("asfdsasdfasdf");//和“=”一样
	cout << s1 << endl;
}
void test3()
{
	string s1 = "asfad";

	//重载[]操作符
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	//at成员函数
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1.at(i) << " ";
	}
	cout << endl;

	//区别：[]方式，如果访问越界，直接挂掉
	//at方式 访问越界 抛异常out_of_range

	try
	{
		cout << s1.at(100) << endl;
	}
	catch (...)
	{
		cout << "你越界了" << endl;
	}
}

//拼接操作
void test4()
{
	string s1 = "abc";
	s1 += "defg";
	string s2 = "123456";
	s1 += s2;
	cout << s1 << endl;

	string s3 = "2222";
	s2.append(s3);//将s3拼接到s2尾部
	cout << s2 << endl;

	string s4 = s2 + s3;
	cout << s4 << endl;
}

//查找
void test5()
{
	string s1 = "gabcdefgh";
	cout << s1 << endl;

	//查找第一次出现的位置
	int pos = s1.find("ac");//查找第一次出现的位置，如果没找到返回-1
	cout << pos << endl;

	//查找最后一次出现的位置
	pos = s1.rfind("g");
	cout << pos << endl;

}

//替换
void test6()
{
	string s = "abcdefgh";
	cout << s << endl;
	s.replace(0, 2, "111");//从a位置开始，b个字符，替换成c
	cout << s << endl;//111cdefgh
}

//比较
void test7()
{
	string s1 = "abcd";
	string s2 = "abce";
	if (s1.compare(s2) == 0)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
}

//子串操作
void test8()
{
	string s = "abcdefgh";
	string s1 = s.substr(1, 4);//返回一个字串
	cout << s << endl;
	cout << s1 << endl;
}

void test9()
{
	string s = "abcdefg";
	s.insert(1, "66666");//插在某个位置前面
	cout << s << endl;

	s.erase(0, 2);//从某个位置开始删除几个字符
	cout << s << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	return 0;
}