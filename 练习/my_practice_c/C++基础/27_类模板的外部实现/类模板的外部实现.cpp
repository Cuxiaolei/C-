#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


template<class T>
class Person
{
public:
	//ʹ����Ԫģ��ʱҲҪ����Ԫ����ǰ��������  template<class T>
	template<T>//����class
	friend ostream& operator<<(ostream& os, Person<T>& p);
	Person(T age, T id);
	void show();
public:
	T mage;
	T mid;
};

//����
template<class T>
ostream& operator<<(ostream& os, Person<T>& p)
{
	os << p.mage << endl;
	os << p.mid << endl;
	return os;
}


//������ж��庯��ʱ��������������<T>,����ǰ����ʱģ�庯��template<class T>
template<class T>
Person<T>::Person(T age, T id)
{
	this->mage = age;
	this->mid = id;
}

template<class T>
void Person<T>::show()
{
	cout << this->mage << endl;
	cout << this->mid << endl;
}


int main()
{
	Person<int>* per = new Person<int>(10, 20);
	per->show();

	cout << "----------------" << endl;
	cout << (*per);

	return 0;
}