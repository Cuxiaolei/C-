#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



//�������ֻ���׳�int float char���������쳣���׳������ľͱ���,��catch(...)���Բ��������쳣
void func() throw(int, float, char)
{
	throw 'a';
}

//�����׳��κ��쳣
void func2() throw()
{
	throw - 1;
}

//�����׳��κ������쳣
void func3()
{

}

int main()
{
	try
	{
		func();
	}
	catch (char str)
	{
		cout << str << endl;
	}
	catch (int e)
	{
		cout << "�쳣" << endl;
	}
	catch (...)//���������쳣
	{
		cout << "δ֪�����쳣" << endl;
	}



	return 0;
}