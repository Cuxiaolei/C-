#include "Mystring.h"


//成员
Mystring::Mystring()
{
	this->len = 0;
	this->str = NULL;
}

Mystring::Mystring(int len)
{
	this->len = len;
}

Mystring::Mystring(const char* str)
{
	if (str == NULL)
	{
		this->len = 0;
		this->str = new char[0 + 1];
		strcpy(this->str, "");
	}
	else
	{
		int len = (int)strlen(str);
		this->len = len;

		this->str = new char[len + 1]
			;
		strcpy(this->str, str);
	}
}

Mystring::Mystring(const Mystring& another)
{
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);
}

Mystring::~Mystring()
{
	if (this->str != NULL)
	{
		this->len = 0;
		delete[] this->str;
		this->str = NULL;
	}
}

char& Mystring::operator[](int index)
{
	return this->str[index];
}

Mystring& Mystring::operator=(const Mystring& another)
{
	if (this == &another)
	{
		return *this;
	}

	if (this->str != NULL)
	{
		delete[] this->str;
		this->str = NULL;
		this->len = 0;
	}

	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);

	return *this;
}

Mystring Mystring::operator+(Mystring& another)
{
	Mystring temp;

	int len = this->len + another.len;
	temp.len = len;
	temp.str = new char[len + 1];
	strcpy(temp.str, "");
	
	strcat(temp.str, this->str);
	strcat(temp.str, another.str);
	return temp;
	
}









//全局
istream& operator>>(istream& is, Mystring& s)
{
	if (s.str != NULL)
	{
		delete[] s.str;
		s.str = NULL;
		s.len = 0;
	}
	char temp_str[4096] = { 0 };
	//通过cin添加新的字符串

	cin >> temp_str;
	int len = (int)strlen(temp_str);
	s.len = len;
	s.str = new char[len + 1];
	strcpy(s.str, temp_str);
	return is;
}

ostream& operator<<(ostream& os, Mystring& str)
{
	os << str.str;
	return os;
}



