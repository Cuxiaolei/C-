#include "employee.h"
#pragma once
class Technician :public Employee
{
public:
	Technician();
	~Technician();
	//初始化
	virtual void init();
	//提供员工薪资计算方法
	virtual void getPay();
	//升级
	virtual void Uplevel();
private:
	//一个月工作了多长时间
	int workHour;
	//每小时多少钱
	double perHourMoney;
};

