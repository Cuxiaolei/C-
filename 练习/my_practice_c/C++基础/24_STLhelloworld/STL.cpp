#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<vector>//��̬���� �ɱ�����
using namespace std;


void PrintVector(int v)
{
	cout << v << " ";
}


//STL�����﷨
void test1()
{
	//����һ������������ָ�����������ŵ�Ԫ������ʱint
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);

	//ͨ��STL�ṩ��for_each�㷨
	//�����ṩ�ĵ�����

	vector<int>::iterator pbegin = v.begin();
	vector<int>::iterator pend = v.end();


	//�����п��ܴ�Ż������������ͣ�Ҳ���ܴ���Զ�����������
	for_each(pbegin, pend, PrintVector);
}

//����Ҳ���Դ���Զ������������
class Person
{
public:
	Person(int age,int id)
	{
		this->mage = age;
		this->mid = id;
	}

public:
	int mage;
	int mid;
};
void PrintVector1(Person v)
{
	cout << v.mage << " " << v.mid << endl;
}
void test2()
{
	vector<Person> v;
	Person p1(10, 20), p2(200, 343), p3(23, 465);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//����1
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).mage << " ";
		cout << (*it).mid << endl;
	}
	cout << endl;

	//����2
	for_each(v.begin(), v.end(), PrintVector1);
	cout << endl;
}


int main()
{
	//test1();
	test2();
	return 0;
}