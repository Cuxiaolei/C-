#pragma once
#include "employee.h"
class Salesman:virtual public Employee
{
public:
	Salesman();
	~Salesman();
	//初始化
	virtual void init();
	//薪资计算方法
	virtual void getPay();
	//级别
	virtual void Uplevel();
protected:
	//当月的销售额
	double saleAmount;
	//提成的比例
	double salePercent;
};

