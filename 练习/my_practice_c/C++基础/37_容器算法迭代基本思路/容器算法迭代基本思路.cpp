#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//�㷨������ͳ��ĳ��Ԫ�صĸ���
int mycount(int* start, int* end, int val)
{
	int num = 0;
	while (start != end)
	{
		if (*start == val)
		{
			num++;
		}
		start++;
	}
	return num;
}





int main()
{
	//���� ����
	int arr[] = { 0,10,7,5,7,4,6 };
	
	int* pbegin = arr;//��������ʼλ��
	int* pend = &(arr[sizeof(arr) / sizeof(int)]);

	cout << mycount(pbegin, pend, 7) << endl;


	return 0;
}