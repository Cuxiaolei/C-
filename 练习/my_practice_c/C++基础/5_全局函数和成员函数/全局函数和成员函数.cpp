#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class Test
{
public:
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void print()
	{
		cout << "a = " << this->a << ",b = " << this->b << endl;
	}

	int getA()
	{
		return this->a;
	}
	int getB()
	{
		return this->b;
	}


	//2��Ա����
	Test TestAdd(Test& another)
	{
		Test temp(this->a + another.a, this->b + another.b);
		return temp;
	}

	//+=����
	//1������Test�࣬���ı䱻���ö�����
	Test TestAdd2(Test& another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;
	}

	//2,�������ã��ı䱻���ö�����
	Test& TestAdd3(Test& another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;
	}
private:
	int a;
	int b;
};



//1 ��ȫ���ṩһ��Test��ӵĺ���
#if 0
Test TestAdd(Test& t1, Test& t2)
{
	Test temp(t1.getA() + t2.getA(), t1.getB() + t2.getB());

	return temp;
}
#endif

int main()
{
	Test t1(10, 20);
	Test t2(100, 200);

//1ȫ�ַ���
#if 0
	Test t3 = TestAdd(t1, t2);
	t3.print();
#endif
//2��Ա����
	Test t3 = t1.TestAdd(t2);
	t3.print();




//+=����
//������һ����������ʹ�õ��ó�Ա������ÿ�ζ���ı��������Ա������Ҫ��������

//����Test�ֻ࣬�ܸı�һ��t1
	Test t4 = t1.TestAdd2(t2).TestAdd2(t2).TestAdd2(t2);
	t4.print();
//����t1(��t1�������ã���������),�ı�t1
	t1.TestAdd3(t2).TestAdd3(t2).TestAdd3(t2);//��ʱ����ǰ��ı��һ�Σ����ı���4��
	t1.print();





	return 0;
}























































