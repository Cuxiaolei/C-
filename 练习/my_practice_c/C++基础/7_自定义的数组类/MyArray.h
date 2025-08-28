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


	//等号的重载
	MyArray& operator=(const MyArray& another);
	//中括号的重载
	int& operator[](int index) const;
private: 
	int len;
	int* space;
};

//<<的重载
ostream& operator<<(ostream& os, const MyArray& arr);

//>>的重载
istream& operator>>(istream& is, const MyArray& arr);

//==的重载
bool operator==(MyArray& arr1, MyArray& arr2);


