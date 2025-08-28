#include "Salesman.h"


Salesman::Salesman()
{
	cout << "SaleMan().." << endl;
}

Salesman::~Salesman()
{
	cout << "~Salesman()..." << endl;
}

void Salesman::init()
{
	cout << "请输入销售员工的姓名:";
	cin >> this->name;
	this->salePercent = 0.04;
	cout << "请输入当月的销售额:";
	cin >> this->saleAmount;
}
//薪资计算方法
void Salesman::getPay()
{
	this->salary = this->saleAmount * this->salePercent;
}
//级别
void Salesman::Uplevel()
{
	this->level++;
	this->salePercent += 0.01;
}
