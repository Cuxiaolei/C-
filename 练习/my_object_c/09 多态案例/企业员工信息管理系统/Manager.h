#pragma once
#include "employee.h"
class Manager:virtual public Employee
{
public:
	Manager();
	~Manager();
	//��ʼ��
	virtual void init();
	//�ṩԱ��н�ʼ��㷽��
	virtual void getPay();
	//�����ķ���
	virtual void Uplevel();
protected:
	double fixsalary;
};

