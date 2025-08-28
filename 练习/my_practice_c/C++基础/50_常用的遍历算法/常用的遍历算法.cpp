#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class MyPlus
{
public:
	int operator()(int val)
	{
		return val;
	}
};

//transform ��һ��������Ԫ�� ���� ����һ��������
void test1()
{
	vector<int> v1;
	vector<int> v2;
	v2.resize(11);//������resize���ٿռ�(Ĭ��ֵΪ0)��reserve���ٵĿռ䲻��ֱ����(û��Ĭ��ֵ)

	for (int i = 0; i < 10; i++)
	{ 
		v1.push_back(i);
	}


	transform(v1.begin(), v1.end(), v2.begin(), MyPlus());//�Ƚ�v1��ֵ��MyPlus()���õ�,�ٷ��ؽ�v2�ĵ�������

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << endl;
	}
}


//���õĲ����㷨
void test2()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>::iterator ret = find(v1.begin(), v1.end(), 5);
	if (ret == v1.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << *ret << endl;
	}
}


class Person
{
public:
	Person(int age, int id) :age(age), id(id) {}
	bool operator==(const Person& p) const
	{
		return p.id == this->id && p.age == this->age;
	}
public:
	int id;
	int age;
};
void test3()
{
	vector<Person> v1;

	Person p1(10, 20);
	Person p2(20, 20);
	Person p3(30, 20);
	Person p4(40, 20);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);

	vector<Person>::iterator ret = find(v1.begin(), v1.end(), p1);
	if (ret == v1.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << endl;
	}
}

bool MySearch(int val)
{
	return val > 5;
}

bool MySearch2(int val)
{
	return val > 5;
}

//binary_serach���ֲ���
void test4()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//v1.push_back(9);
	//ֻ���ж��Ƿ����ҵ������ܷ���λ��
	bool ret = binary_search(v1.begin(), v1.end(), 5);
	if (ret)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}

	//Ѱ�������ظ�Ԫ��
	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
	if (it == v1.end())
	{
		cout << "û���ҵ������ظ�Ԫ��" << endl;
	}
	else
		cout << "�ҵ��������ظ�Ԫ��  " << *it << endl;


	//find_if
	it = find_if(v1.begin(), v1.end(), MySearch);
	if (it == v1.end())
	{
		cout << "û���ҵ�����������Ԫ��" << endl;
	}
	else
		cout << "�ҵ��˵�һ������������Ԫ�أ�" << *it << endl;

	//count count_if
	int num = count(v1.begin(), v1.end(), 9);//����Ԫ�صĸ���
	cout << "�ҵ���" << num << "��" << endl;
	num = count_if(v1.begin(), v1.end(), MySearch2);//���ҷ���������Ԫ�ظ���
	cout << "���������ĸ���Ϊ��" << num << endl;


}


int main()
{
	test1();
	//test2();
	//test3();
	//test4();




	return 0;
}