#include "SalesManager.h"


SalesManager::SalesManager()
{
	cout << "SalesManager()..." << endl;
}
SalesManager::~SalesManager()
{
	cout << "~SalesManager()..." << endl;
}

//��ʼ��
void SalesManager::init()
{
	cout << "���������۾��������:";
	cin >> this->name;
	this->fixsalary = 5000;
	this->salePercent = 0.05;
}
//�ṩԱ��н�ʼ��㷽��
void SalesManager::getPay()
{
	cout << "�����뵱�µ����۶" << endl;
	cin >> this->saleAmount;
	this->salary = this->fixsalary + this->salePercent * this->saleAmount;
}
//����
void SalesManager::Uplevel()
{
	this->level++;
	this->fixsalary += 1000;
}