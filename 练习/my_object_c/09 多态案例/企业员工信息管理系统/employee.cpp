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


//��ʾԱ����Ϣ
void Employee::displayStatus()
{
	cout << "Ա������" << this->name << endl;
	cout << "Ա�����" << this->id << endl;
	cout << "Ա������" << this->level << endl;
	cout << "Ա��н��" << this->salary << endl;
}