#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


//ģ�弼�� ���Ͳ����� ��д������Ժ�������
//Ϊ���ñ�������������ͨ���� ���� ģ�庯��

//���߱����� ������дģ�庯����������ֵĲ�Ҫ������
//����һ���Ե�
template<class T> // template<typename T> 
void MySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


int main()
{
	double a = 10;
	double b = 20;
	MySwap(a, b);//�����������㴫��ֵ ���������Զ��Ƶ�
	cout << a << b;

	//��ʽ���ƶ�����
	MySwap<double>(a, b);

	return 0;
}