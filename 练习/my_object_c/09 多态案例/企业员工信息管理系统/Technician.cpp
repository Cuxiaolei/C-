#include "Technician.h"

Technician::Technician()
{
	cout << "Technician()..." << endl;
}
Technician::~Technician()
{
	cout << "~Techincian()..." << endl;
}
//��ʼ��
void Technician::init()
{
	cout << "������Ա��������:" << endl;
	cin >> this->name;
	this->perHourMoney = 100;
	cout << "�������Ա��һ�������˶���Сʱ:";
	cin >> this->workHour;

}
//�ṩԱ��н�ʼ��㷽��
void Technician::getPay()
{
	this->salary = this->perHourMoney * this->workHour;
}


//�����ķ���
void Technician::Uplevel()
{
	this->level++;
}
