
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

	//���ز�����[]//����ĳ���±���ַ���ֱ��ʹ�����������
	char& operator[](int index);

	//���ز�����+
	Mystring operator+(Mystring& another);
	//���ز�����=
	Mystring& operator=(const Mystring& another);
	//���ز�����==

	friend ostream& operator<<(ostream& os, Mystring& str);
	friend istream& operator>>(istream& is, Mystring& s);

private:
	int len;
	char* str;
};
//���ز�����<<
ostream& operator<<(ostream& os, Mystring& str);
//���ز�����>>
istream& operator>>(istream& is, Mystring& s);
