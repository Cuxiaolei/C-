#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//�쳣����
class BaseMyException
{
public:
	virtual void what() = 0;
	virtual ~BaseMyException()
	{
		//����������Ҫ����0
	}

};

class TargetSpaceNULLException :public BaseMyException
{
public:
	virtual void what()
	{
		cout << "Ŀ��ռ�Ϊ�գ�" << endl;
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
		cout << "ԭ�ռ�Ϊ�գ�" << endl;
	}
	~SourceSpaceNULLException()
	{

	}
};

void copy_str(char* taget,const char* source)
{
	if (taget == NULL)
	{
		//����Ҫthrow�����ģ�ֱ��throw�����
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
		//���Ե������ú���
		copy_str(NULL, source);
	}
	catch (BaseMyException& e)
	{
		e.what();
	}

	cout << buf << endl;
	return 0;



}