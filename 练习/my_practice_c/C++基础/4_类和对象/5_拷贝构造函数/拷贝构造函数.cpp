#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class Test
{
public:
	Test(int x, int y)
	{
		x0 = x;
		y0 = y;
	}

	//��ʾ�Ŀ������캯��
	//��дҲ���ԣ�ϵͳĬ�ϵ��д˿�������
	Test(const Test& another)
	{
		x0 = another.x0;
		y0 = another.y0;
	}
	void print() 
	{
		cout << "x=" << x0 << endl;
		cout << "y=" << y0 << endl;
	}
	~Test()
	{
		cout << "����" << endl;
	}

private:
	int x0;
	int y0;
};



Test print1(Test t1)//�βν���֮����գ����õĻ�������
{
	return t1;//�����βλ��գ�����������1��
}

Test print2(Test &t1)//���õĻ������գ����˺�������֮���t1������
{
	return t1;//��������ֵ������
}

int main()
{
	Test t1(10, 999);
	//����Ĭ�ϵĿ������캯���ӿ�
	Test t2(t1);//�൱��t1 = t2��
	print1(t1);//��ʱ�޽���ָ��ֱ�ӽ���������2��
	print2(t1);//��ʱ�޽���ָ��ֱ�ӽ���������3��
	t1.print();
	t2.print();

	return 0;
}

