#include "Manager.h"


Manager::Manager()
{
	cout << "Manager()..." << endl;
}
Manager::~Manager()
{
	cout << "~Manager().." << endl;
}
//��ʼ��
void Manager::init()
{
	cout << "�����뾭�������:";
	cin >> this->name;
	this->fixsalary = 8000;
}
//�ṩԱ��н�ʼ��㷽��
void Manager:: getPay()
{
	this->salary = fixsalary;
}
//�����ķ���
void Manager::Uplevel()
{
	this->level++;
	this->fixsalary += 1000;
}