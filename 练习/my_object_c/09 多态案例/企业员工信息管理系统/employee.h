#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#pragma once
using namespace std;

//�����Ա��
class Employee
{
public:
	Employee();

	virtual ~Employee();
	//��ʼ��
	virtual void init() = 0;
	//�ṩԱ��н�ʼ��㷽��
	virtual void getPay() = 0;
	//�����ķ���
	virtual void Uplevel() = 0;
	//��ʾԱ����Ϣ
	void displayStatus();

protected:
	string name;//����
	int id;//���
	double salary;//н��
	int level;//����
	static int startNum;//Ա����Ż���ֵ
};
