#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "���󹹽�������" << endl;
	}
	~Person()
	{
		cout << "��������" << endl;
	}
};

int divide(int x, int y)
{
	Person p1, p2;
	if (y == 0)
	{
		throw y;//ֻҪ�׳��쳣�������Զ����������൱��return
	}
	return x / y;
}


int main()
{
	
	try
	{
		divide(10, 10);
		divide(10, 0);
	}
	catch (int e)
	{
		cout << "�쳣����" << endl;
		cout << "����Ϊ" << e << endl;
	}


	return 0;
}