#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class B;

class A
{
public:
	A(int a)
	{
		this->a = a;
	}
	void printA()
	{	
		////��������
		//B objB(100);
		//cout << objB.b << endl;
		cout << "A::a = " << this->a << endl;
	}

	//����һ����Ԫ��B,ʹB��Ҳ���Է���A�е�˽�г�Ա
	//��A�в��ܷ���B����ΪA��B�����ǣ�����B��û�а�A������
	//Ҫ������A�з���B��˽�г�Ա����ҪB��A������Ԫ
	//��Ԫ��ϵ���ܱ��̳�
	//��Ԫ��ϵ�ǵ���ģ������н�����
	//��Ԫ��ϵû�й�ϵ��
	friend class B;
private:
	int a;
};

class B
{
public:
	B(int b)
	{
		this->b = b;
	}
	void printB()
	{
		A objA(100);
		cout << objA.a << endl;
		cout << "B::b = " << this->b << endl;
	}

	friend class A;
private:
	int b;
};




int main()
{
	B objB(199);
	objB.printB();


	return 0;
}