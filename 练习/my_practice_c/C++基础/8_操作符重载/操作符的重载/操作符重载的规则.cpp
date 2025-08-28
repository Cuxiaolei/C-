#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//˫Ŀ���������
//ʹ�ã�L#R
//operator#(L,R);  ȫ�ֺ���
//L.operator#(R);  �ֲ�����

//ֻ���������еĲ������������Զ��������
//"."".*""::""?:"�ĸ��������������

//���ز��ܸı��������ĸ���

//���ز��ܸı�����������ȼ���

//���ز��ܸı�������Ľ����

//����������ĺ���������Ĭ�ϵĲ���

//���ص������������û�������Զ������͵Ķ���һ��ʹ�ã����������Ӧ��һ��������󣨻����������ã�

//��=���͡�&�������û�����


class Complex
{
public:
	Complex()
	{

	}
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

	//˫Ŀ�����

	//��Ա���������غ���
	Complex operator+(Complex& another)
	{
		Complex temp(this->a + another.a, this->b + another.b);
		return temp;
	}
	Complex operator-(Complex& another)
	{
		Complex temp(this->a - another.a, this->b - another.b);
		return temp;
	}

	Complex& operator+=(Complex& another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;
	}

	//��Ŀ�����

	//����ǰ++�����
	Complex& operator++()
	{
		this->a ++;
		this->b ++;
		return *this;
	}

	//���غ�++�����
	const Complex operator++(int)//��Ԫ������Ҫ��
	{
		Complex temp(this->a, this->b);
		this->a++;
		this->b++;
		return temp;
	}
#if 0
	//���Ʋ���������
	ostream& operator<<(ostream& os)	//�����������Ҫ
	{									//c1<<cout;�ı���ԭ�壬�����Ʋ�����������д�ڳ�Ա������
		os << "(" << this->a << "," << this->b << ")" << endl;
		return os;
	}
#endif
	friend Complex complexAdd(Complex& c1, Complex& c2);
	//friend Complex operator+(Complex& c1, Complex& c2);
	//friend const Complex operator++(Complex& c1, int);
	friend ostream& operator<<(ostream& os, Complex& c);
	friend istream& operator>>(istream& is, Complex& c);

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
//˫Ŀ
Complex operator+(Complex& c1, Complex& c2)
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}

//��Ŀ
//����ǰ++�����
Complex& operator++(Complex& c1)
{
	c1.a++;
	c1.b++;
	return c1;
}

//���غ�++�����
const Complex operator++(Complex& c1, int)
{
	Complex temp(c1.a, c1.b);
	//��
	c1.a++;
	c1.b++;
	return temp;
}

#endif
//�������������
//����
ostream& operator<<(ostream& os, Complex& c)
{
	os << "(" << c.a << "," << c.b << ")" << endl;
	return os;
}
//����
istream& operator>>(istream& is, Complex& c)
{
	cout << "a:";
	is >> c.a;
	cout << "b:";
	is >> c.b;
	return is;
}

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

	//��Ա���������ط�ʽ
	Complex c7 = c1.operator+(c2);
	c7.printComplex();

	Complex c8 = c1 - c2;
	c8.printComplex();

	Complex c9 = c1.operator-(c2);
	c9.printComplex();
	//��������
	Complex c10 = c1 - c1 - c2;
	c10.printComplex();

	c1 += c2;
	c1.printComplex();

	c1.operator+=(c2);
	c1.printComplex();

	(c2 += c1) += c2;
	c2.printComplex();

	//ǰ׺++
	++c2;
	c2.printComplex();

	//��׺++
	c2++;
	c2.printComplex();

	//���Ʋ���������
	cout << c1;
	cout << c2;
	//c1 << cout;(��Ա����)

	//���Ʋ���������
	Complex c11;
	cin >> c11;
	cout << c11; 
	return 0;
}