#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#pragma once
using namespace std;

//抽象的员工
class Employee
{
public:
	Employee();

	virtual ~Employee();
	//初始化
	virtual void init() = 0;
	//提供员工薪资计算方法
	virtual void getPay() = 0;
	//升级的方法
	virtual void Uplevel() = 0;
	//显示员工信息
	void displayStatus();

protected:
	string name;//姓名
	int id;//编号
	double salary;//薪资
	int level;//级别
	static int startNum;//员工编号基础值
};
