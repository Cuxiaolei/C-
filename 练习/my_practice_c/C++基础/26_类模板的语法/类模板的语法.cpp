#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


template<class T>
class Person
{
public:
	Person(T id, T age)
	{
		this->mid = id;
		this->mage = age;
	}
	void Show()
	{
		cout << "Id:" << this->mid << endl;
		cout << "Age:" << this->mage << endl;
	}
private:
	T mid;
	T mage;
};


void test01()
{
	//����ģ���ڵ��õ�ʱ�򣬿����Զ������Ƶ�
	//��ģ�������ʾָ������
	Person<int> p(10, 20);
	p.Show();
}


int main()
{
	test01();



	return 0;
}