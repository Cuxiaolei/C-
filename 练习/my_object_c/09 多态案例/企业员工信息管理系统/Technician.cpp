#include "Technician.h"

Technician::Technician()
{
	cout << "Technician()..." << endl;
}
Technician::~Technician()
{
	cout << "~Techincian()..." << endl;
}
//初始化
void Technician::init()
{
	cout << "请输入员工的姓名:" << endl;
	cin >> this->name;
	this->perHourMoney = 100;
	cout << "请输入该员工一共工作了多少小时:";
	cin >> this->workHour;

}
//提供员工薪资计算方法
void Technician::getPay()
{
	this->salary = this->perHourMoney * this->workHour;
}


//升级的方法
void Technician::Uplevel()
{
	this->level++;
}
