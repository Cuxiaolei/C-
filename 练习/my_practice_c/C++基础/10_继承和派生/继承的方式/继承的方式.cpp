#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



//����1��ֻҪ�Ǹ�����private�еĳ�Ա������ʲô�̳з�ʽ�����Ӷ����ʲ���
//����2��������У�public���̳У������еķ��ʿ���Ȩ�ޱ��ֲ���
//����3������Ǳ�����protected���̳У��ڶ����У��̳и��׵ġ�public��Ա���͡�protected��Ա������protected��Ա����private��Ա��Ȼ��private��Ա�����ӿ��Է��ʣ��ⲿ���ɷ���
//����4�������˽�У�private���̳У��ڶ����У��̳и��׵ġ�public��Ա���͡�protected��Ա������private��Ա����private��Ա��Ȼ��private��Ա,�������к��ⲿ�����ɷ���

class Parent
{
public:
	int pub;	//������ڲ����ⲿ���ܷ���
protected:
	int pro;	//������ڲ����Է��ʣ�������ⲿ�����Է���
private:
	int pri;	//������ڲ����Է��ʣ�������ⲿ�����Է���
};

//���м̳�
class Child :public Parent
{
public:
	void func()
	{
		cout << pub << endl;	//pub �Ǹ����public��Ա��������public�̳���ġ��ڲ� �ⲿ�������Է��ʡ�
		cout << pro << endl;	//pro �Ǹ���protected��Ա��������public�̳���ġ��ڲ������Է��ʣ����ⲿ�����ɷ���	���������е��ڲ�Ҳ���Է���
#if 0
		cout << pri << endl;	//pri�Ǹ����private�����������Լ��ⲿ�����ɷ���
#endif
	}
};

//�����̳�
class Child2 :protected Parent
{
public:
	void func2()
	{
		cout << pub << endl;//��ʱpub ͨ��protected�̳У�������ڲ��ܹ�����
							//pub ������ڲ����Է��ʣ�����ⲿ���ʲ��ˣ�����������Է���
	}
};

//˽�м̳�
class Child3 :private Parent
{
public:
	void func3()
	{
		cout << pub << endl;//pub������ڲ����Է��ʣ�������ⲿ���ɷ���
		cout << pro << endl;//����ı�����Ա�����ӿ��Է��ʣ�������˽�м̳У��ڶ������Ѿ����˽�г�Ա�����Ӻ��ⲿ�����ɷ���
#if 0
		cout << pri << endl;//�����˽�г�Ա���ɷ���
#endif
	}
};

//����ԭ��
//1 �����õĳ�Ա������������ڲ�����������ⲿ
//2 �����ӵļ̳з�ʽ
//3 ��ǰ�����ڶ����еķ���Ȩ��

int main()
{
	Child c1;
	c1.func();
#if 1
	Child2 c2;
	c2.func2();

	//����pub����Child2�еģ�����ͨ���������̳С�Parent��public�еĳ�Ա
	//c2.pub;
#endif
	return 0;
}