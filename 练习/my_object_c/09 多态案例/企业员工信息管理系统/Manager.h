#pragma once
#include "employee.h"
class Manager:virtual public Employee
{
public:
	Manager();
	~Manager();
	//初始化
	virtual void init();
	//提供员工薪资计算方法
	virtual void getPay();
	//升级的方法
	virtual void Uplevel();
protected:
	double fixsalary;
};

