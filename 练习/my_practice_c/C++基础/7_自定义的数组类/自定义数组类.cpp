#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include "MyArray.h"
using namespace std;



int main()
{
	MyArray arr1(10);//����10��Ԫ�ص�����

	//��ֵ����
	for (int i = 0; i < 10; i++)
	{
		arr1.setData(i, i + 10);
	}


	for (int i = 0; i < 10; i++)
	{
		cout << arr1.getData(i) << "  ";
	}
	cout << endl;

#if 1
	MyArray arr2(arr1);

	for (int i = 0; i < 10; i++)
	{
		cout << arr2.getData(i) << "  ";
	}
	cout << endl;
#endif
	
	arr1[3] = 999;
	arr1.printMyarray();

	MyArray arr3(arr1);

	cout << arr3;
#if 0
	cin >> arr3;

	cout << arr3;
#endif
	if (arr1 == arr3)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}









	return 0;
}