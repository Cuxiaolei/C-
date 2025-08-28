#include "employee.h"


int Employee::startNum = 1000;


Employee::Employee()
{
	cout << "Employee()..." << endl;
	startNum++;
	id = startNum;
	level = 1;
	salary = 0;
}

Employee::~Employee()
{
	cout << "~Employee()..." << endl;
}


//显示员工信息
void Employee::displayStatus()
{
	cout << "员工姓名" << this->name << endl;
	cout << "员工编号" << this->id << endl;
	cout << "员工级别" << this->level << endl;
	cout << "员工薪资" << this->salary << endl;
}