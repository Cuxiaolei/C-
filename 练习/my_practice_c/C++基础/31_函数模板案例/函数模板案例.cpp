#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//��char���ͺ�int���������������

//��ӡ����
template<class T>
void PrintArray(T* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//����
template<class T>
void MySort(T* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main()
{
	int arr[] = { 2,3,5,4,7,234,75,34 };
	//���鳤��
	int len = sizeof(arr) / sizeof(int);
	PrintArray(arr, len);
	MySort(arr, len);
	PrintArray(arr, len);


	char carr[] = { 'a','n','r','g','a','p' };
	int clen = sizeof(carr) / sizeof(char);
	PrintArray(carr, clen);
	MySort(carr, clen);
	PrintArray(carr, clen);

	return 0;
}