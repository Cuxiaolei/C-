
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



class Mystring
{
public:
	Mystring();
	Mystring(int len);
	Mystring(const char* str);
	Mystring(const Mystring& another);
	~Mystring();

	//重载操作符[]//返回某个下标的字符（直接使用类变量名）
	char& operator[](int index);

	//重载操作符+
	Mystring operator+(Mystring& another);
	//重载操作符=
	Mystring& operator=(const Mystring& another);
	//重载操作符==

	friend ostream& operator<<(ostream& os, Mystring& str);
	friend istream& operator>>(istream& is, Mystring& s);

private:
	int len;
	char* str;
};
//重载操作符<<
ostream& operator<<(ostream& os, Mystring& str);
//重载操作符>>
istream& operator>>(istream& is, Mystring& s);
