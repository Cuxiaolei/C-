#pragma once
#include "Manager.h"
#include "Salesman.h"
class SalesManager :public Manager, public Salesman
{
public:
	SalesManager();
	~SalesManager();
	//初始化
	virtual void init();
	//提供员工薪资计算方法
	virtual void getPay();
	//升级
	virtual void Uplevel();
private:
};

