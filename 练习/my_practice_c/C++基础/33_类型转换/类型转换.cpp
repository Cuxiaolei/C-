#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class Building
{

};
class Animal
{
public:

};

class Cat :public Animal
{

};


void test01()
{
	//static_cast<��Ҫת��������>(������������);
	//�Ƚϰ�ȫ
	//static_cast �������õ���������
	//���о��м̳й�ϵ��ָ�������
	int a = 99;
	char c = static_cast<char>(a);
	cout << c << endl;

	//ָ��
#if 0
	//������������ָ�벻����ת��
	int* p = NULL;
	char* sp = static_cast<char*>(p);//����ת����Ч

	//����ָ�벻����ת��
	Building* a1;
	Animal* b1 = static_cast<Animal*>(a1);//�����ڿ����ת��
#endif
#if 0
	//����ת�����м̳й�ϵ�Ķ���ָ��
	Animal* ani = NULL;
	Cat* cat = static_cast<Cat*>(ani);//����ת��Ϊ����

	Cat* cat1 = NULL;
	Animal* ani1 = static_cast<Animal*>(cat1);//����ת��Ϊ���ࣻ
	//����
	//���м̳й�ϵ�����ÿ���ת��
	Animal ani2;
	Animal& ani3 = ani2;
	Cat& cat2= static_cast<Cat&>(ani3);//����ת����

	Cat cat3;
	Cat& cat4 = cat3;
	Animal& ani4 = static_cast<Animal&>(cat4);//����ת����
#endif
}

	//dynamic_cast ת�����м̳й�ϵ��ָ������ã���ת��֮ǰ����ж�����ļ��
void test02()
{
	//����ת����
#if 0
	//������������
	int a = 99;
	char b = dynamic_cast<char>(a);//����ֻ��ת��ָ�������

	//�Ǽ̳й�ϵ��ָ��
	Animal* ani = NULL;
	Building* building = dynamic_cast<Building*>(ani);//dynamic_cast���������̬���ͣ���ֻ��ת���̳й�ϵ��ָ��

	Animal* ani1 = NULL;
	Cat* cat1 = dynamic_cast<Cat*>(ani1);//dynamic_cast���ܴӸ���תΪ���ࣨһ������ȸ����
#endif

	//����ת����
#if 0
	Cat* cat2 = NULL;
	Animal* ani2 = dynamic_cast<Animal*>(cat2);//����ɹ�תΪ����
#endif
	//���ۣ�dynamic_castֻ��ת�����м̳й�ϵ��ָ��������ã���ֻ��������תΪ����
}


//const_cast ָ�� ���� ���߶���ָ��
void test03()
{
	//�������ӻ�ȥ��������const��
#if 0
	//�����������Ϳ���ת��
	int a = 10;
	const int& b = a;
	int& c = const_cast<int&>(b);
	c = 20;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	//ָ��
	const int* p = NULL;
	int* p2 = const_cast<int*>(p);
#endif
}


//reinterprte_cast ǿ������ת��
typedef void(FUNC1)(int, int);//����ָ��
typedef int(FUNC2)(int, char*);
void test04()
{
	//1. �޹ص�ָ�����Ϳ��Խ���ת��
	Building* building = NULL;
	Animal* ani = reinterpret_cast<Animal*>(building);

	//2. ����ָ��ת��
	FUNC1* func1;
	FUNC2* func2 = reinterpret_cast<FUNC2*>(func1);
}

//1. һ������£��������������ת��



int main()
{
	//test01();
	test03();



	return 0;




}