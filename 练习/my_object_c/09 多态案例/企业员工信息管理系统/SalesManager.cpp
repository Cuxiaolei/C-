#include "SalesManager.h"


SalesManager::SalesManager()
{
	cout << "SalesManager()..." << endl;
}
SalesManager::~SalesManager()
{
	cout << "~SalesManager()..." << endl;
}

//初始化
void SalesManager::init()
{
	cout << "请输入销售经理的姓名:";
	cin >> this->name;
	this->fixsalary = 5000;
	this->salePercent = 0.05;
}
//提供员工薪资计算方法
void SalesManager::getPay()
{
	cout << "请输入当月的销售额：" << endl;
	cin >> this->saleAmount;
	this->salary = this->fixsalary + this->salePercent * this->saleAmount;
}
//升级
void SalesManager::Uplevel()
{
	this->level++;
	this->fixsalary += 1000;
}