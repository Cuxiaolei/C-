#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//�쳣�Ļ����﷨




double divide(double x, double y)
{
	if (y == 0)
	{
		throw y;//���쳣
	}
	return x / y;
}
void test1()
{
	//����ȥ�����쳣
	try 
	{
		divide(10, 0); 
	}
	catch (double e)//�����Ϊ�׳�����ֵ
	{
		//�쳣ʱ�������ͽ���ƥ��
		cout << "����Ϊ" << e << endl;
	}
}






void CallDivide(int x, int y)
{
	divide(x, y);
}
void test2()
{
	try
	{
		CallDivide(10, 0);
	}
	catch (double e)
	{
		cout << "����Ϊ" << e << endl;
	}
}

int main()
{
	//test1();
	test2();

	return 0;
}