#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class MyPrint :public binary_function<int, int, void>//��������
{
public:
	void operator()(int v,int val) const//�º���ֻ����һ������
	{
		cout << v << " " << val << " ";
		cout << v + val << " " << endl;;
	}
};

//�º��������� bindlst bind2nd
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//�º�����ֻ����һ�������������ٴδ���
	//��������
	for_each(v.begin(), v.end(), bind2nd(MyPrint(),200));
	//��һ����Ԫ��������ת���һԪ�ĺ�������
	

	//bind1st bind2nd ��������,���ڶ����������а�
	//bind1st �󶨵��ǵ�һ������
	//bind2nd �󶨵��ǵڶ�������
}



class MyCompare :public binary_function<int, int, bool>
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
	void operator()(int v)
	{
		cout << v << " ";
	}
};

struct MyGreater5 :public unary_function<int, bool>
{
	bool operator()(int v) const
	{
		return v < 5;
	}
};
//�º��������� not1      not2
//ȡ��������
void test2()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 100 + 3);
	}


	//not2��ȡ������������������ת
	//����Զ�Ԫν��ȡ������not2()
	//�����һԪν��ȡ������not1()
	sort(v.begin(), v.end(), not2(MyCompare()));
	for_each(v.begin(), v.end(), MyCompare());
	cout << endl;

	//���� ��һ�� ���������ĵ�����,�������е�˳���й�
	vector<int>::iterator it = find_if(v.begin(), v.end(), not1(MyGreater5()));
	if (it == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	cout << *it << endl;

}
void MyPrint3(int val,int v)
{
	cout << "val:" << val << "  v:" << v <<"  ";
	cout << val << " " << endl;
}

//�º��������� ptr_fun
void test3()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 100 + 3);
	}
	//����ͨ���� ת�� ��������
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint3), 10));
}

class Person
{
public:
	Person(int age, int id) :age(age), id(id) {}
	void show()
	{
		cout << "age:" << age << "  id:" << id << endl;
	}
public:
	int age;
	int id;
};
//��Ա���������� mem_fun     mem_fun_ref
void test4()
{
	//��������д�ŵĶ�������ָ�룬����for_each�㷨��ӡ��ʱ��
	//�������Լ��ṩ�Ĵ�ӡ����
	vector<Person> v;
	Person p1(10, 20);
	Person p2(20, 20);
	Person p3(30, 20);
	Person p4(40, 20);
	Person p5(50, 20);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//��ʽ��mem_fun_ref(&����::������)
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::show));


	vector<Person*> v1;
	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);
	v1.push_back(&p5);
	//��ʽ��mem_fun(&����::������)
	for_each(v1.begin(), v1.end(), mem_fun(&Person::show));
	

	//�����ŵ��Ƕ���ָ�� ʹ��mem_fun
	//���ʹ�õ��Ƕ���     ʹ��mem_fun_ref
	
}
int main()
{
	//�º��������� bindlst bind2nd
	//test1();


	//�º��������� not1      not2
	//ȡ��������
	//test2();

	//�º��������� ptr_fun
	//test3();

	//��Ա���������� mem_fun     mem_fun_ref
	test4();




	return 0;
}