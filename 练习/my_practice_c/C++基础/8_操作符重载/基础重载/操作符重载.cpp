#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class Complex
{
public:
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void printComplex()
	{
		cout << "(" << this->a << "," << this->b << ")" << endl;
	}

	//��Ա����
	Complex complexAdd(Complex& another)
	{
		Complex temp(a + another.a, b + another.b);
		return temp;
	}

	//��Ա���������غ���
	Complex operator+(Complex& another)
	{
		Complex temp(a + another.a, b + another.b);
		return temp;
	}

	friend Complex complexAdd(Complex& c1, Complex& c2);
	//friend Complex operator+(Complex& c1, Complex& c2);

private:
	int a;//ʵ��
	int b;//����
};



//ȫ�ֺ���
Complex complexAdd(Complex& c1, Complex& c2)
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}


//����������д��ȫ��
#if 0
Complex operator+(Complex& c1, Complex& c2)
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}
#endif


int main()
{
	Complex c1(1, 2);
	Complex c2(2, 3);
	c1.printComplex();
	c2.printComplex();

	//ȫ�ַ�ʽ
	Complex c3 = complexAdd(c1, c2);
	c3.printComplex();

	//�ֲ�����
	Complex c4 = c1.complexAdd(c2);
	c4.printComplex();

#if 0
	//ȫ�ֲ��������ط�ʽ1
	Complex c5 = c1 + c2;
	c5.printComplex();


	//ȫ�ֲ��������ط�ʽ2
	Complex c6 = operator+(c1, c2);
	c6.printComplex();
#endif

	//�����ַ�ʽ��+���ҵ����е�operator+����ƥ��
	//���������ַ�ʽʹ�õĻ�ֻ��ʹoperator+ͬʱ����һ��
	//��Ա���������ط�ʽ1
	Complex c6 = c1 + c2;
	c6.printComplex();

	//��Ա���������ط�ʽ1
	Complex c7 = c1.operator+(c2);
	c7.printComplex();

	return 0;
}