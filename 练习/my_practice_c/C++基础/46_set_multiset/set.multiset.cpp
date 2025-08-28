#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//�º���
struct mycompare {
	bool operator()(int v1, int v2)const//�����const
	{
		return v1 > v2;
	}
};






void PrintSet(set<int> s1)
{
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *(it) << " ";
	}
	cout << endl;
}



//��ʼ��
void  test1()
{

#if 0
	mycompare com;
	//com.operator()(10, 20);
	com(10, 20);//��ͬ
#endif
	set<int,mycompare> s1;//���һ��α�������Ա�Ϊ�Ӵ�С����
	//set<int> s1;
	s1.insert(4);
	s1.insert(3);
	s1.insert(65);
	s1.insert(1);
	s1.insert(2);
	s1.insert(8);
	s1.insert(5);
	s1.insert(66);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *(it) << " ";
	}
	cout << endl;
#if 0
	PrintSet(s1);//���������������Զ�����
	//��ֵ����
	set<int> s2(s1);
	set<int> s3;
	s3 = s1;

	//ɾ������
	s1.erase(s1.begin());//ɾ��ָ��λ��
	s1.erase(4);//ɾ��ָ������
	PrintSet(s1);
#endif
}

//find(key)���ص������������ڵĻ�����s.end()
void test2()
{
	//ʵֵ
	set<int> s1;
	s1.insert(4);
	s1.insert(3);
	s1.insert(65);
	s1.insert(1);
	s1.insert(2);
	s1.insert(8);
	s1.insert(5);
	s1.insert(66);
	PrintSet(s1);
	set<int>::iterator it = s1.find(4);//���ص�����

	if (it == s1.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ����������" << endl;
	}

	//lower_bound//���ص�һ�� ���ڵ��� ָ��ֵ��Ԫ�أ���û�ҵ��򷵻�end()
	it = s1.lower_bound(55);
	if (it == s1.end())
	{
		cout << "û�ҵ�" << endl;
	}
	else
	cout << "�ҵ���" << *it<< endl;

	//upper_bound//���ص�һ�� ���� ָ��ֵ��Ԫ�أ���û�ҵ��򷵻�end()
	it = s1.upper_bound(105);
	if (it == s1.end())
	{
		cout << "û�ҵ�" << endl;
	}
	else
	cout << "�ҵ���" << *it << endl;

	//equal_range ����Lower_bound �� upper_bound��ֵ//������һ�Ե�����
	pair<set<int>::iterator ,set<int>::iterator> myret = s1.equal_range(66);
	if (myret.first == s1.end())
	{
		cout << "û���ҵ�lower_bound" << endl;
	}
	else
	{
		cout << "�ҵ���lower_bound" << *(myret.first) << endl;
	}

	if (myret.second == s1.end())
	{
		cout << "û���ҵ�upper_bound" << endl;
	}
	else
	{
		cout << "�ҵ���upper_bound" << *(myret.second) << endl;
	}

}

class Person
{
public:
	Person(int age,int id):age(age),id(id){}

public:
	int id;
	int age;

};
class mycompare2
{
public:
	bool operator()(Person p1, Person p2)const
	{
		return p1.age > p2.age;
	}
};
void test3()
{
	set<Person,mycompare2> s1;//��������Ӵ�С����
	Person p1(10, 213);
	Person p2(20, 202);
	Person p3(30, 133);
	Person p4(40, 244);
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);

	for (set<Person, mycompare2>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << (*it).age << " " << (*it).id << endl;
	}

	Person p5(100, 200);
	set<Person, mycompare2>::iterator ret = s1.find(p4);
	if (ret == s1.end())
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << (*ret).age << " " << (*ret).id << endl;
	}

}

int main()
{


	//test1();
	//test2();
	test3();
	//test4();
	//test5();
	//test6();
	//test7();







	
	
	return 0;

}