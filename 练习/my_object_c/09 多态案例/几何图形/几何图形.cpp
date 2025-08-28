#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

class Shape
{
public:
	//��ӡ��ͼ�εĻ�������
	virtual void show() = 0;
	//�õ�ͼ�����
	virtual double getArea() = 0;
};


class Circle :public Shape
{
public:
	Circle(double r)
	{
		this->r = r;
	}

	virtual void show()
	{
		cout << "��ӡ����һ��Բ" << endl;
	}

	virtual double getArea()
	{
		cout << "��ȡԲ�������";
		return 3.14 * this->r * this->r;
	}
	~Circle()
	{
		cout << "Բ����������������" << endl;
	}
private:
	double r;
};


class Square :public Shape
{
public:
	Square(double a)
	{
		this->a = a;
	}

	virtual void show()
	{
		cout << "�����εı߳�Ϊ��" << this->a << endl;
	}

	virtual double getArea()
	{
		cout << "���������Ϊ��";
		return this->a * this->a;
	}

	~Square()
	{
		cout << "�����ε�����������" << endl;
	}
private:
	double a;
};


int main()
{
	Shape* arr[2] = { 0 };
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			double r;
			cout << "������Բ�İ뾶��";
			cin >> r;
			arr[i] = new Circle(r);
		}

		else
		{
			double a;
			cout << "�����������εı߳�:";
			cin >> a;
			arr[i] = new Square(a);
		}
	}

	//�����������
	for (int i = 0; i < 2; i++)
	{
		arr[i]->show();
		cout << arr[i]->getArea() << endl;
		delete arr[i];
	}




	return 0;
}