#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



class Sqr
{
public:
	Sqr()
	{

	}
	Sqr(int a)
	{
		this->a = a;
	}

	int operator()(int value)
	{
		return value * value;
	}
	int operator()(int a, int b)
	{
		return a * b;
	}
private:
	int a;

};
void test1()
{
	Sqr s(10);

	//����һ������������
	int value = s(4);//��һ�����󣬵���һ����ͨ����������
	int a = s.operator()(6);	//�����ֶ����Ƿº�����α����

	cout << value << endl;
	cout << a << endl;

	//������������������
	int c = s(10, 20); //10*20

	cout << c << endl;
}


class A
{
public:
	A(int a)
	{
		this->a = a;
	}
	//void*������ָ��
	//����new������
	void* operator new(size_t size)
	{
		cout << "������new������" << endl;
		return malloc(size);
	}

	void* operator new[](size_t size)
	{
		cout << "������new������" << endl;
		return malloc(size);
	}
	//����delete������
	//��ʹ������delete����ʹ��ʱҲ�ᴥ����������
	void operator delete(void* p)
	{
		cout << "������delete������" << endl;
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
	}

	~A()
	{
		cout << "~A()..." << endl;
	}


private:
	int a;
};

void test2()
{
	int* a = new int;

	A* ap = new A(10);

	delete ap;//����֮����Ȼ�ᴥ����������

}

int main()
{
	//test1();
	test2();


	return 0;
}