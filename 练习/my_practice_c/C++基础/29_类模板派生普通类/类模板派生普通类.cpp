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

//�������������������ǲ�����Ҫ��������ڴ�
//�����ڼ̳е�ʱ����Ҫָ������
class SubPerson :public Person<int>
{

};

int main()
{





	return 0;
}