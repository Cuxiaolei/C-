#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
 

//�Ҿ���(����)
class Furniture
{
public:
	int m;//����
};

//������
//��������̳и����� �ó���̳У���ֹ�����ڶ�̳ж������ʱ�򣬳��ָ����еı���������ݶ���ɲ���ȷ
class Bed :virtual public Furniture
{
public:
	void sleep()
	{
		cout << "����˯��" << endl; 
	}
};

//������
class Sofa :virtual public Furniture
{
public:
	void sit()
	{
		cout << "��ɳ������Ϣ" << endl;
	}
};

//ɳ����(��̳У�//������
class SofaBed :public Bed, public Sofa
{
public:
	void SleepAndSit()
	{
		Bed::sleep();
		Sofa::sit();
	}
};


int main()
{
	Bed b;
	b.sleep();

	Sofa s;
	s.sit();

	SofaBed sb;
	sb.sit();
	sb.sleep();
	sb.SleepAndSit();


	//s�̳�һ��m, b�̳�һ��m, ����sb����2��m
	//sb.m = 100;//m����ȷ
#if 0
	//����ͨ�����������
	sb.Bed::m = 100;
	sb.Sofa::m = 100;
#endif
	//�����ڶ����ࣨs,b)�ϼ�virtual
	//��ʱ����
	sb.m = 100;//��sb�еĵ�����m
	return 0;
}