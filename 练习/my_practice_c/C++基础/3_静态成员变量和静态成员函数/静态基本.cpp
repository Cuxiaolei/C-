#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



class A1
{
public:
	A1(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

	void print()
	{
		cout << m_a << "   " << m_b << endl;
	}
	//static���εľ�̬��Ա����
	static int m_c;//��ʼ������������ⲿ

	~A1()
	{
		cout << "~A1" << endl;
	}
private:
	int m_a;
	int m_b;
};

//��̬��Ա�����ĳ�ʼ����һ��д���������
int A1::m_c = 0;


class A2
{
public:
	A2(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

	void print()
	{
		cout << m_a << "   " << m_b << endl;
	}

	~A2()
	{
		cout << "~A2" << endl;
	}
private:
	int m_a;
	int m_b;
};

void test()
{
	//static�������ھ�̬����
	static int a = 10;
	a++;
	cout << a << endl;
}


int main()
{
	A1 a1(10, 20);
	A1 a2(100, 200);
	a1.print();
	a2.print(); 
	test();
	test();//��ӡ11��12��
			//��Ϊstatic���ε�ֻ�ܳ�ʼ��һ�Σ�
	cout << a1.m_c << endl;


	return 0;
}