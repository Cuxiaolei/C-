#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



//����Ⱥ
class Yuebuqun
{
public:
	Yuebuqun(string kongfu)
	{
		this->kongfu = kongfu;
	}

	virtual void fight()//��̳У�������ͬʱΪ�����ָ���������ͬ������
	{
		cout << "����Ⱥ" << "ʹ����" << kongfu << "����" << endl;
	}
	string kongfu;
private:
};


//��ƽ֮
class Linpingzhi :public Yuebuqun
{
public:
	Linpingzhi(string kongfu) :Yuebuqun( kongfu)
	{

	}
	virtual void fight()//��̳У�������ͬʱΪ�����ָ���������ͬ������
	{
		cout << "��ƽ֮ʹ����" << kongfu << "����" << endl;
	}
};

class Linhuchong :public Yuebuqun
{
public:
	Linhuchong(string kongfu) :Yuebuqun(kongfu)
	{

	}
	void fight()
	{
		cout << "�����ʹ����" << kongfu << endl;
	}
};


//��ȫ���ṩһ���򶷵ķ���
void fightPeople(Yuebuqun* hero)
{
	//�������virtual����ֻ�����Yuebuqun��fight
	hero->fight();//ϣ�����ݽ�������������࣬���������fight
					//������ݽ������Ǹ��࣬���ø����fight
					//��Ҫ��fight����ǰ��virtual	
					//������Ϊ���� ��̬��Ϊ
}
//��̬�����ı�Ҫ����
//1 Ҫ�м̳�
//2 Ҫ���麯����д
//3 ����ָ������� ָ���������

int main()
{
	Yuebuqun *xiao = new Yuebuqun("Ƨа����");

	fightPeople(xiao);
	delete xiao;

	Linpingzhi* tong = new Linpingzhi("��������");
	fightPeople(tong);
	//������Ĭ������һ����ȫ�Ĵ���������Ϊ ���ܴ���ʱ����������Ǹ������
	//���ͳһִ�и���ķ��� ����ôһ�����Ա��ɹ�ִ��
	//������ָ�����ָ�����࣬������ָ�벻һ����ָ����
	Linhuchong* qiao = new Linhuchong("���¾Ž�");
	fightPeople(qiao);
	delete tong;




	return 0;
}