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
	cout << "����������Ա��������:";
	cin >> this->name;
	this->salePercent = 0.04;
	cout << "�����뵱�µ����۶�:";
	cin >> this->saleAmount;
}
//н�ʼ��㷽��
void Salesman::getPay()
{
	this->salary = this->saleAmount * this->salePercent;
}
//����
void Salesman::Uplevel()
{
	this->level++;
	this->salePercent += 0.01;
}
