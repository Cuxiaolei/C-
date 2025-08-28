#include "Manager.h"


Manager::Manager()
{
	cout << "Manager()..." << endl;
}
Manager::~Manager()
{
	cout << "~Manager().." << endl;
}
//初始化
void Manager::init()
{
	cout << "请输入经理的姓名:";
	cin >> this->name;
	this->fixsalary = 8000;
}
//提供员工薪资计算方法
void Manager:: getPay()
{
	this->salary = fixsalary;
}
//升级的方法
void Manager::Uplevel()
{
	this->level++;
	this->fixsalary += 1000;
}