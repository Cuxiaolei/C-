#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

class A
{
public:
	void func()
	{
		cout << "funcA" << endl;
	}
	int a;
private:
};

//��Bӵ����A�ĳ�Ա������ B has A  //B��������A
class B
{
public:
	void funcB()
	{

	}
	A a;
};

//��϶� ���ھ� �����
//��C �ĳ�Ա������Ҫ��A���βΣ� ˵��C use 
class C
{
public:
	void funcC(A *a)
	{

	}
};

//D�̳���A//��D is A //��D�̳���A����϶Ⱥܸ�
class D :public A
{
public:
	void funcD()
	{
		//���Է���A�еĹ����������޷�����˽�б���
		cout << a << endl;
	}
};

class E :public D
{

};

int main()
{
	






	return 0;
}






