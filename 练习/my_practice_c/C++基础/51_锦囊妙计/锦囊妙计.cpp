#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//����𿪽��ҷ���������
typedef void(Tips)(void);

//�������
struct tip
{
	char from[64];
	char to[64];
	//���ҵ�����
	Tips* tp;//�൱�ڳ�����Ĵ��麯��
};


//��Ҫһ���򿪽��ҵĹ��ܺ���
void open_tips(struct tip* tip_p)
{
	cout << "���˽���" << endl;
	cout << "�˽�������" << tip_p->from << "д��" << tip_p->to << "�ġ�" << endl;
	cout << "�˽��ҵ�������:";
	tip_p->tp();
}
struct tip* creat_tips(const char* from, const char* to, Tips* tp)
{
	struct tip* temp = (struct tip*)malloc(sizeof(struct tip));
	if (temp == NULL)
	{
		return NULL;
	}
	strcpy(temp->from, from);
	strcpy(temp->to, to);
	temp->tp = tp;
	return temp;
}

void destory_tip(struct tip* tp)
{
	if (tp != NULL)
	{
		free(tp);
		tp = NULL;
	}
}
//ʵ�ֲ�
void tip1_func(void)
{
	cout << "һ������Ͱݼ��ǹ���" << endl;
}
void tip2_func(void)
{
	cout << "��������ֲ�˼�񣬾�ƭ��" << endl;
}
void tip3_func(void)
{
	cout << "�������Ȩ׷ɱ����������" << endl;
}
int main()
{
	struct tip* tip1 = creat_tips("�����", "����", tip1_func);
	struct tip* tip2 = creat_tips("�����", "����", tip2_func);
	struct tip* tip3 = creat_tips("�����", "����", tip3_func);

	cout << "���1" << endl;
	open_tips(tip1);
	cout << "���2" << endl;
	open_tips(tip2);
	cout << "���3" << endl;
	open_tips(tip3);


	destory_tip(tip1);
	destory_tip(tip2);
	destory_tip(tip3);

	return 0;
}