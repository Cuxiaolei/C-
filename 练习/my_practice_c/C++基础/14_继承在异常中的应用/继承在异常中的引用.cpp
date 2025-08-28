#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//异常基类
class BaseMyException
{
public:
	virtual void what() = 0;
	virtual ~BaseMyException()
	{
		//虚析构不需要等于0
	}

};

class TargetSpaceNULLException :public BaseMyException
{
public:
	virtual void what()
	{
		cout << "目标空间为空！" << endl;
	}
	~TargetSpaceNULLException()
	{

	}
};

class SourceSpaceNULLException :public BaseMyException
{
public:
	virtual void what()
	{
		cout << "原空间为空！" << endl;
	}
	~SourceSpaceNULLException()
	{

	}
};

void copy_str(char* taget,const char* source)
{
	if (taget == NULL)
	{
		//不需要throw其他的，直接throw类对象
		throw TargetSpaceNULLException();
	}

	if (source == NULL)
	{
		throw SourceSpaceNULLException();
	}

	int len = strlen(source);
	while (*source != '\0')
	{
		*taget = *source;
		taget++;
		source++;
	}
}


int main()
{
	const char* source = "asdfagt";
	char buf[1024] = { 0 };
	try
	{
		//可以当作调用函数
		copy_str(NULL, source);
	}
	catch (BaseMyException& e)
	{
		e.what();
	}

	cout << buf << endl;
	return 0;



}