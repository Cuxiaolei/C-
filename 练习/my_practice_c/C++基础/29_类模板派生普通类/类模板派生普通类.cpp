#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


template<class T>
class Person
{
public:
	Person(T age)
	{
		this->mAge = age;
	}
private:
	T mAge;
};

//类区定义对象，这个对象是不是需要编译分配内存
//所以在继承的时候需要指定类型
class SubPerson :public Person<int>
{

};

int main()
{





	return 0;
}