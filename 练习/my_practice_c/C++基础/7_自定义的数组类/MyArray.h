#pragma once
#include <iostream>
using namespace std;
class MyArray
{
public:
	MyArray();
	MyArray(int len);
	MyArray(const MyArray& another);
	~MyArray();

	void setData(int index, int data);
	int getData(int index);
	int getLen() const;
	void printMyarray();


	//�Ⱥŵ�����
	MyArray& operator=(const MyArray& another);
	//�����ŵ�����
	int& operator[](int index) const;
private: 
	int len;
	int* space;
};

//<<������
ostream& operator<<(ostream& os, const MyArray& arr);

//>>������
istream& operator>>(istream& is, const MyArray& arr);

//==������
bool operator==(MyArray& arr1, MyArray& arr2);


