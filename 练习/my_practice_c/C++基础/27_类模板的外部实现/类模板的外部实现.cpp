#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


template<class T>
class Person
{
public:
	//使用友元模板时也要在友元函数前单独加上  template<class T>
	template<T>//不加class
	friend ostream& operator<<(ostream& os, Person<T>& p);
	Person(T age, T id);
	void show();
public:
	T mage;
	T mid;
};

//重载
template<class T>
ostream& operator<<(ostream& os, Person<T>& p)
{
	os << p.mage << endl;
	os << p.mid << endl;
	return os;
}


//类外进行定义函数时必须在类后面加上<T>,且在前标明时模板函数template<class T>
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