#pragma once
#include "Manager.h"
#include "Salesman.h"
class SalesManager :public Manager, public Salesman
{
public:
	SalesManager();
	~SalesManager();
	//��ʼ��
	virtual void init();
	//�ṩԱ��н�ʼ��㷽��
	virtual void getPay();
	//����
	virtual void Uplevel();
private:
};

