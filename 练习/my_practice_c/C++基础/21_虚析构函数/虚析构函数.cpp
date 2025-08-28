#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()..." << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);
		strcpy(this->p, "A String...");
	}

	virtual void print()
	{
		cout << "B:" << this->p << endl;
	}

	virtual ~A()
	{
		cout << "~A()..." << endl;
		if (this->p != NULL)
		{
			delete[]this->p;
			this->p = NULL;
		}
	}
private:
	char* p;
};

class B :public A
{
public:
	B()
	{
		cout << "B()..." << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);
		strcpy(this->p, "B String...");
	}
	virtual void print()
	{
		cout << "B:"<<this->p << endl;
	}
	//�����������������ڴ���������ж�̬ʱ�����������Ļ������������࣬��Ĭ����������
	virtual ~B()
	{
		cout << "~B()..." << endl;
		if (this->p != NULL)
		{
			delete[]this->p;
			this->p = NULL;
		}
	}
private:
	char* p;
};


void func(A* ap)
{
	ap->print();
	delete ap;
}


void test()
{
#if 0
	A aobj;
	B bobj;
	func(&aobj);
	func(&bobj);
#endif
	B* bp = new B;
	func(bp);
}

int main()
{
	test();


	return 0;
}