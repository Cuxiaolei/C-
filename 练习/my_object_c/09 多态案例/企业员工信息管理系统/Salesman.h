#pragma once
#include "employee.h"
class Salesman:virtual public Employee
{
public:
	Salesman();
	~Salesman();
	//��ʼ��
	virtual void init();
	//н�ʼ��㷽��
	virtual void getPay();
	//����
	virtual void Uplevel();
protected:
	//���µ����۶�
	double saleAmount;
	//��ɵı���
	double salePercent;
};

