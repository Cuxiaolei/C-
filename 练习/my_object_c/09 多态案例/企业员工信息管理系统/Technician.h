#include "employee.h"
#pragma once
class Technician :public Employee
{
public:
	Technician();
	~Technician();
	//��ʼ��
	virtual void init();
	//�ṩԱ��н�ʼ��㷽��
	virtual void getPay();
	//����
	virtual void Uplevel();
private:
	//һ���¹����˶೤ʱ��
	int workHour;
	//ÿСʱ����Ǯ
	double perHourMoney;
};

