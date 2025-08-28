#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<string>
#include<iomanip>
#define SALER 10	//�������������
#define SALES 15	//���۶��������
#define SSALES 15	//�����ܶ��������
#define FU '-'		//�߿���ʽ
using namespace std;

//�ṹ��   -----------------------------------------------------------------------------------

//����1������ÿ������ݣ�
//��Ʒ���ݣ���Ʒ���+��Ʒ���۶
typedef struct Protect
{
	int code_p;
	long long sales;
}Protect;
//ÿ������Ա������
typedef struct Note
{
	int code_c;
	Protect pro1;
	Protect pro2;
	Protect pro3;
	Protect pro4;
	Protect pro5;
}Note;
//ÿ���ĸ�����Ա������
typedef struct Day
{
	Note man1;
	Note man2;
	Note man3;
	Note man4;
	Day* next;
}Day;
Day* head = NULL;
Day* tail = NULL;
//����
typedef struct Sum
{
	//ÿ�ֲ�Ʒ���۶����
	long long spro1 = 0;
	long long spro2 = 0;
	long long spro3 = 0;
	long long spro4 = 0;
	long long spro5 = 0;
	//ÿ���˵�ÿ�ֲ�Ʒ���۶����
	long long sman1_1 = 0;
	long long sman1_2 = 0;
	long long sman1_3 = 0;
	long long sman1_4 = 0;
	long long sman1_5 = 0;

	long long sman2_1 = 0;
	long long sman2_2 = 0;
	long long sman2_3 = 0;
	long long sman2_4 = 0;
	long long sman2_5 = 0;

	long long sman3_1 = 0;
	long long sman3_2 = 0;
	long long sman3_3 = 0;
	long long sman3_4 = 0;
	long long sman3_5 = 0;

	long long sman4_1 = 0;
	long long sman4_2 = 0;
	long long sman4_3 = 0;
	long long sman4_4 = 0;
	long long sman4_5 = 0;
	//ÿ���˵������۶����
	long long sman1 = 0;
	long long sman2 = 0;
	long long sman3 = 0;
	long long sman4 = 0;
}Sum;
Sum s;



//��Ա����(���+���ֲ�Ʒ���۶�)
typedef struct ManDate
{
	int code;
	long long spro_1;
	long long spro_2;
	long long spro_3;
	long long spro_4;
	long long spro_5;
	long long sman;
}ManDate;
//����1
typedef struct ArrMan
{
	ManDate* dateman;  //Ϊ�˷���������Ҫ�����ݷ���һ���ṹ����
}ArrMan;

//��Ʒ���ݣ����+ÿ�ֲ�Ʒ�������۶
typedef struct ProtectDate
{
	int ProtectCode;
	long long SumProtect;
}ProtectDate;
//����2
typedef struct ArrProtect
{
	ProtectDate* dateprotect;	//Ϊ�˷���������Ҫ�����ݷ���һ���ṹ����
}Arr1;



//�������� --------------------------------------------------------------------------

//��ʼ��
void Init(Day* p)
{
	p->man1.code_c = 1;
	p->man2.code_c = 2;
	p->man3.code_c = 3;
	p->man4.code_c = 4;

	p->man1.pro1.code_p = 1;
	p->man1.pro2.code_p = 2;
	p->man1.pro3.code_p = 3;
	p->man1.pro4.code_p = 4;
	p->man1.pro5.code_p = 5;

	p->man2.pro1.code_p = 1;
	p->man2.pro2.code_p = 2;
	p->man2.pro3.code_p = 3;
	p->man2.pro4.code_p = 4;
	p->man2.pro5.code_p = 5;

	p->man3.pro1.code_p = 1;
	p->man3.pro2.code_p = 2;
	p->man3.pro3.code_p = 3;
	p->man3.pro4.code_p = 4;
	p->man3.pro5.code_p = 5;

	p->man4.pro1.code_p = 1;
	p->man4.pro2.code_p = 2;
	p->man4.pro3.code_p = 3;
	p->man4.pro4.code_p = 4;
	p->man4.pro5.code_p = 5;
}

//ͳ������
int Count()
{
	Day* p = head;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

//����
void sum(Day* p)
{
	Day* ps = p;
	//��ʼ������ֹÿ�μ�����ӣ�
	s.sman1 = 0; s.sman1_1 = 0; s.sman1_2 = 0; s.sman1_3 = 0; s.sman1_4 = 0; s.sman1_5 = 0;
	s.sman2 = 0; s.sman2_1 = 0; s.sman2_2 = 0; s.sman2_3 = 0; s.sman2_4 = 0; s.sman2_5 = 0;
	s.sman2 = 0; s.sman3_1 = 0; s.sman3_2 = 0; s.sman3_3 = 0; s.sman3_4 = 0; s.sman3_5 = 0;
	s.sman4 = 0; s.sman4_1 = 0; s.sman4_2 = 0; s.sman4_3 = 0; s.sman4_4 = 0; s.sman4_5 = 0;
	//ÿ���˵�ÿ�ֲ�Ʒ�������۶�
	while (ps != NULL)
	{
		s.sman1_1 += ps->man1.pro1.sales;
		s.sman1_2 += ps->man1.pro2.sales;
		s.sman1_3 += ps->man1.pro3.sales;
		s.sman1_4 += ps->man1.pro4.sales;
		s.sman1_5 += ps->man1.pro5.sales;

		s.sman2_1 += ps->man2.pro1.sales;
		s.sman2_2 += ps->man2.pro2.sales;
		s.sman2_3 += ps->man2.pro3.sales;
		s.sman2_4 += ps->man2.pro4.sales;
		s.sman2_5 += ps->man2.pro5.sales;

		s.sman3_1 += ps->man3.pro1.sales;
		s.sman3_2 += ps->man3.pro2.sales;
		s.sman3_3 += ps->man3.pro3.sales;
		s.sman3_4 += ps->man3.pro4.sales;
		s.sman3_5 += ps->man3.pro5.sales;

		s.sman4_1 += ps->man4.pro1.sales;
		s.sman4_2 += ps->man4.pro2.sales;
		s.sman4_3 += ps->man4.pro3.sales;
		s.sman4_4 += ps->man4.pro4.sales;
		s.sman4_5 += ps->man4.pro5.sales;
		ps = ps->next;
	}
	//ÿ�ֲ�Ʒ�������۶�
	s.spro1 = s.sman1_1 + s.sman2_1 + s.sman3_1 + s.sman4_1;
	s.spro2 = s.sman1_2 + s.sman2_2 + s.sman3_2 + s.sman4_2;
	s.spro3 = s.sman1_3 + s.sman2_3 + s.sman3_3 + s.sman4_3;
	s.spro4 = s.sman1_4 + s.sman2_4 + s.sman3_4 + s.sman4_4;
	s.spro5 = s.sman1_5 + s.sman2_5 + s.sman3_5 + s.sman4_5;

	//ÿ������Ա�������۶
	s.sman1 = s.sman1_1 + s.sman1_2 + s.sman1_3 + s.sman1_4 + s.sman1_5;
	s.sman2 = s.sman2_1 + s.sman2_2 + s.sman2_3 + s.sman2_4 + s.sman2_5;
	s.sman3 = s.sman3_1 + s.sman3_2 + s.sman3_3 + s.sman3_4 + s.sman3_5;
	s.sman4 = s.sman4_1 + s.sman4_2 + s.sman4_3 + s.sman4_4 + s.sman4_5;
}

//��ͷ
void biaotou()
{
	cout << setw(10) << left << "����Ա";
	cout << setw(SALES) << left << "��Ʒ1(Ԫ)";
	cout << setw(SALES) << left << "��Ʒ2(Ԫ)";
	cout << setw(SALES) << left << "��Ʒ3(Ԫ)";
	cout << setw(SALES) << left << "��Ʒ4(Ԫ)";
	cout << setw(SALES) << left << "��Ʒ5(Ԫ)";
}

//��ͷ1��ֻ�в�Ʒ12345��
void biaotou1()
{
	cout << setw(SALES) << left << "��Ʒ1(Ԫ)";
	cout << setw(SALES) << left << "��Ʒ2(Ԫ)";
	cout << setw(SALES) << left << "��Ʒ3(Ԫ)";
	cout << setw(SALES) << left << "��Ʒ4(Ԫ)";
	cout << setw(SALES) << left << "��Ʒ5(Ԫ)";
}

//����
void shuru(Day* p)
{
	cout << "�������һ������Ա�ı�����" << endl;
	cout << "��Ʒ1�����۶";
	cin >> p->man1.pro1.sales;
	cout << "��Ʒ2�����۶";
	cin >> p->man1.pro2.sales;
	cout << "��Ʒ3�����۶";
	cin >> p->man1.pro3.sales;
	cout << "��Ʒ4�����۶";
	cin >> p->man1.pro4.sales;
	cout << "��Ʒ5�����۶";
	cin >> p->man1.pro5.sales;

	cout << "������ڶ�������Ա�ı�����" << endl;
	cout << "��Ʒ1�����۶";
	cin >> p->man2.pro1.sales;
	cout << "��Ʒ2�����۶";
	cin >> p->man2.pro2.sales;
	cout << "��Ʒ3�����۶";
	cin >> p->man2.pro3.sales;
	cout << "��Ʒ4�����۶";
	cin >> p->man2.pro4.sales;
	cout << "��Ʒ5�����۶";
	cin >> p->man2.pro5.sales;

	cout << "���������������Ա�ı�����" << endl;
	cout << "��Ʒ1�����۶";
	cin >> p->man3.pro1.sales;
	cout << "��Ʒ2�����۶";
	cin >> p->man3.pro2.sales;
	cout << "��Ʒ3�����۶";
	cin >> p->man3.pro3.sales;
	cout << "��Ʒ4�����۶";
	cin >> p->man3.pro4.sales;
	cout << "��Ʒ5�����۶";
	cin >> p->man3.pro5.sales;

	cout << "��������ĸ�����Ա�ı�����" << endl;
	cout << "��Ʒ1�����۶";
	cin >> p->man4.pro1.sales;
	cout << "��Ʒ2�����۶";
	cin >> p->man4.pro2.sales;
	cout << "��Ʒ3�����۶";
	cin >> p->man4.pro3.sales;
	cout << "��Ʒ4�����۶";
	cin >> p->man4.pro4.sales;
	cout << "��Ʒ5�����۶";
	cin >> p->man4.pro5.sales;
}

//�޸ģ�����Ա1��
void shuru1(Day* p)
{
	cout << "���޸ĵ�һ������Ա�ı�����" << endl;
	cout << "��Ʒ1�����۶";
	cin >> p->man1.pro1.sales;
	cout << "��Ʒ2�����۶";
	cin >> p->man1.pro2.sales;
	cout << "��Ʒ3�����۶";
	cin >> p->man1.pro3.sales;
	cout << "��Ʒ4�����۶";
	cin >> p->man1.pro4.sales;
	cout << "��Ʒ5�����۶";
	cin >> p->man1.pro5.sales;
}
//�޸ģ�����Ա2��
void shuru2(Day* p)
{
	cout << "���޸ĵڶ�������Ա�ı�����" << endl;
	cout << "��Ʒ1�����۶";
	cin >> p->man2.pro1.sales;
	cout << "��Ʒ2�����۶";
	cin >> p->man2.pro2.sales;
	cout << "��Ʒ3�����۶";
	cin >> p->man2.pro3.sales;
	cout << "��Ʒ4�����۶";
	cin >> p->man2.pro4.sales;
	cout << "��Ʒ5�����۶";
	cin >> p->man2.pro5.sales;
}
//�޸ģ�����Ա3��
void shuru3(Day* p)
{
	cout << "���޸ĵ���������Ա�ı�����" << endl;
	cout << "��Ʒ1�����۶";
	cin >> p->man3.pro1.sales;
	cout << "��Ʒ2�����۶";
	cin >> p->man3.pro2.sales;
	cout << "��Ʒ3�����۶";
	cin >> p->man3.pro3.sales;
	cout << "��Ʒ4�����۶";
	cin >> p->man3.pro4.sales;
	cout << "��Ʒ5�����۶";
	cin >> p->man3.pro5.sales;
}
//�޸ģ�����Ա4��
void shuru4(Day* p)
{
	cout << "���޸ĵ��ĸ�����Ա�ı�����" << endl;
	cout << "��Ʒ1�����۶";
	cin >> p->man4.pro1.sales;
	cout << "��Ʒ2�����۶";
	cin >> p->man4.pro2.sales;
	cout << "��Ʒ3�����۶";
	cin >> p->man4.pro3.sales;
	cout << "��Ʒ4�����۶";
	cin >> p->man4.pro4.sales;
	cout << "��Ʒ5�����۶";
	cin >> p->man4.pro5.sales;
}

//���
void shuchu(Day* p)
{
	cout << setw(SALER) << left << p->man1.code_c;
	cout << setw(SALES) << left << p->man1.pro1.sales;
	cout << setw(SALES) << left << p->man1.pro2.sales;
	cout << setw(SALES) << left << p->man1.pro3.sales;
	cout << setw(SALES) << left << p->man1.pro4.sales;
	cout << setw(SALES) << left << p->man1.pro5.sales;
	cout << endl;

	cout << setw(SALER) << left << p->man2.code_c;
	cout << setw(SALES) << left << p->man2.pro1.sales;
	cout << setw(SALES) << left << p->man2.pro2.sales;
	cout << setw(SALES) << left << p->man2.pro3.sales;
	cout << setw(SALES) << left << p->man2.pro4.sales;
	cout << setw(SALES) << left << p->man2.pro5.sales;
	cout << endl;

	cout << setw(SALER) << left << p->man3.code_c;
	cout << setw(SALES) << left << p->man3.pro1.sales;
	cout << setw(SALES) << left << p->man3.pro2.sales;
	cout << setw(SALES) << left << p->man3.pro3.sales;
	cout << setw(SALES) << left << p->man3.pro4.sales;
	cout << setw(SALES) << left << p->man3.pro5.sales;
	cout << endl;

	cout << setw(SALER) << left << p->man4.code_c;
	cout << setw(SALES) << left << p->man4.pro1.sales;
	cout << setw(SALES) << left << p->man4.pro2.sales;
	cout << setw(SALES) << left << p->man4.pro3.sales;
	cout << setw(SALES) << left << p->man4.pro4.sales;
	cout << setw(SALES) << left << p->man4.pro5.sales;
	cout << endl;
}

//qsort������
int com_ManDate(const void* e1, const void* e2)
{
	//return (int)(((ManDate*)e2)->sman - ((ManDate*)e1)->sman);
	if (((ManDate*)e2)->sman > ((ManDate*)e1)->sman)
		return 1;
	if (((ManDate*)e2)->sman == ((ManDate*)e1)->sman)
		return 0;
	if (((ManDate*)e2)->sman < ((ManDate*)e1)->sman)
		return -1;
	return 0;
}
int com_ProtectDate(const void* e1, const void* e2)
{
	//return (int)(((ProtectDate*)e2)->SumProtect - ((ProtectDate*)e1)->SumProtect);
	if (((ProtectDate*)e2)->SumProtect > ((ProtectDate*)e1)->SumProtect)
		return 1;
	if (((ProtectDate*)e2)->SumProtect == ((ProtectDate*)e1)->SumProtect)
		return 0;
	if (((ProtectDate*)e2)->SumProtect < ((ProtectDate*)e1)->SumProtect)
		return -1;
	return 0;
}







//���ܺ���  ----------------------------------------------------------------------------
//1.��ȡ�������
void ShowEveryday(Day* p)
{
	if (p == NULL)
	{
		cout << "���ϵͳ����Ϊ�գ��Ͻ�ȥ¼����Ϣ�ɣ���" << endl;
		return;
	}
	int i = 1;
	int count = Count();
	cout << "Ŀǰ��¼��" << count << "����Ϣ������" << endl;
	while (p != NULL)
	{
		cout << endl << "��" << i << "��������۶" << endl;
		for (int j = 0; j < SALER + 5 * SALES - 3; j++)
		{
			cout << FU;
		}
		cout << endl;
		i++;
		biaotou();
		cout << endl;
		shuchu(p);
		for (int j = 0; j < SALER + 5 * SALES - 3; j++)
		{
			cout << FU;
		}
		cout << endl;
		p = p->next;
	}
	cout << endl;
}

//2.������Ϣ¼��
void Add()
{
	Day* ps;
	cout << "���������ı�����" << endl;
	ps = (Day*)calloc(1, sizeof(Day));
	Init(ps);		//��ʼ��p,����Ա����Ʒ
	shuru(ps);		//������ʾ��Ϣ+����
	ps->next = NULL;
	if (head == NULL)
	{
		head = ps;
	}
	else
	{
		tail->next = ps;
	}
	tail = ps;
	cout << "¼��ɹ�����" << endl << endl;
}

//3.����ÿ����ÿ�ֲ�Ʒ�����۶�
void Calculate_Sort(Day* p)
{
	sum(p);
	ArrMan arr1;
	arr1.dateman = (ManDate*)calloc(4, sizeof(ManDate));
	arr1.dateman[0].code = 1;
	arr1.dateman[0].spro_1 = s.sman1_1;
	arr1.dateman[0].spro_2 = s.sman1_2;
	arr1.dateman[0].spro_3 = s.sman1_3;
	arr1.dateman[0].spro_4 = s.sman1_4;
	arr1.dateman[0].spro_5 = s.sman1_5;
	arr1.dateman[0].sman = s.sman1;

	arr1.dateman[1].code = 2;
	arr1.dateman[1].spro_1 = s.sman2_1;
	arr1.dateman[1].spro_2 = s.sman2_2;
	arr1.dateman[1].spro_3 = s.sman2_3;
	arr1.dateman[1].spro_4 = s.sman2_4;
	arr1.dateman[1].spro_5 = s.sman2_5;
	arr1.dateman[1].sman = s.sman2;

	arr1.dateman[2].code = 3;
	arr1.dateman[2].spro_1 = s.sman3_1;
	arr1.dateman[2].spro_2 = s.sman3_2;
	arr1.dateman[2].spro_3 = s.sman3_3;
	arr1.dateman[2].spro_4 = s.sman3_4;
	arr1.dateman[2].spro_5 = s.sman3_5;
	arr1.dateman[2].sman = s.sman3;

	arr1.dateman[3].code = 4;
	arr1.dateman[3].spro_1 = s.sman4_1;
	arr1.dateman[3].spro_2 = s.sman4_2;
	arr1.dateman[3].spro_3 = s.sman4_3;
	arr1.dateman[3].spro_4 = s.sman4_4;
	arr1.dateman[3].spro_5 = s.sman4_5;
	arr1.dateman[3].sman = s.sman4;
	qsort(arr1.dateman, 4, sizeof(ManDate), com_ManDate);
	for (int i = 0; i < 2 * SALER + 5 * SALES - 5 + SSALES; i++)
	{
		cout << FU;
	}
	cout << endl;
	biaotou();
	cout << setw(SSALES) << left << "�����۶�(Ԫ)";
	cout << setw(SALER) << left << "����" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << setw(SALER) << left << arr1.dateman[i].code;
		cout << setw(SALES) << left << arr1.dateman[i].spro_1;
		cout << setw(SALES) << left << arr1.dateman[i].spro_2;
		cout << setw(SALES) << left << arr1.dateman[i].spro_3;
		cout << setw(SALES) << left << arr1.dateman[i].spro_4;
		cout << setw(SALES) << left << arr1.dateman[i].spro_5;
		cout << setw(SSALES) << left << arr1.dateman[i].sman;
		cout << setw(SALER) << left << i + 1;
		cout << endl;
	}
	for (int i = 0; i < 2 * SALER + 5 * SALES - 5 + SSALES; i++)
	{
		cout << FU;
	}
	cout << endl;
}

//4.����ĳ������Աÿ��ı���
void SearchSomebodyEveryDay(Day* p)
{
	cout << "������Ҫ���ҵ�����Ա��";
	char ch;
	cin >> ch;
	if (ch == '1')
	{
		cout << "����Ա1�ı�����" << endl;
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		cout << setw(SALER) << left << "Day\\pro";
		biaotou1();
		cout << endl;
		int i = 1;
		while (p != NULL)
		{
			cout << "��" << i << setw(SALER - 3) << left << "��";
			cout << setw(SALES) << left << p->man1.pro1.sales;
			cout << setw(SALES) << left << p->man1.pro2.sales;
			cout << setw(SALES) << left << p->man1.pro3.sales;
			cout << setw(SALES) << left << p->man1.pro4.sales;
			cout << setw(SALES) << left << p->man1.pro5.sales;
			cout << endl;
			p = p->next;
			i++;
		}
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		return;
	}
	else if (ch == '2')
	{
		cout << "����Ա2�ı�����" << endl;
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		cout << setw(SALER) << left << "Day\\pro";
		biaotou1();
		cout << endl;
		int i = 1;
		while (p != NULL)
		{
			cout << "��" << i << setw(SALER - 3) << left << "��";
			cout << setw(SALES) << left << p->man2.pro1.sales;
			cout << setw(SALES) << left << p->man2.pro2.sales;
			cout << setw(SALES) << left << p->man2.pro3.sales;
			cout << setw(SALES) << left << p->man2.pro4.sales;
			cout << setw(SALES) << left << p->man2.pro5.sales;
			cout << endl;
			p = p->next;
			i++;
		}
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		return;
	}
	else if (ch == '3')
	{
		cout << "����Ա3�ı�����" << endl;
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		cout << setw(SALER) << left << "Day\\pro";
		biaotou1();
		cout << endl;
		int i = 1;
		while (p != NULL)
		{
			cout << "��" << i << setw(SALER - 3) << left << "��";
			cout << setw(SALES) << left << p->man3.pro1.sales;
			cout << setw(SALES) << left << p->man3.pro2.sales;
			cout << setw(SALES) << left << p->man3.pro3.sales;
			cout << setw(SALES) << left << p->man3.pro4.sales;
			cout << setw(SALES) << left << p->man3.pro5.sales;
			cout << endl;
			p = p->next;
			i++;
		}
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		return;
	}
	else if (ch == '4')
	{
		cout << "����Ա4�ı�����" << endl;
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		cout << setw(SALER) << left << "Day\\pro";
		biaotou1();
		cout << endl;
		int i = 1;
		while (p != NULL)
		{
			cout << "��" << i << setw(SALER - 3) << left << "��";
			cout << setw(SALES) << left << p->man4.pro1.sales;
			cout << setw(SALES) << left << p->man4.pro2.sales;
			cout << setw(SALES) << left << p->man4.pro3.sales;
			cout << setw(SALES) << left << p->man4.pro4.sales;
			cout << setw(SALES) << left << p->man4.pro5.sales;
			cout << endl;
			p = p->next;
			i++;
		}
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		return;
	}
	else
	{
		cout << "���벻�Ϸ�����" << endl;
		return;
	}
}

//5.����ĳһ��ı���
void SearchSomeday(Day* p)
{
	cout << "������Ҫ���ҵ���һ�죺";
	int n;
	cin >> n;
	if (n < 1)
	{
		cout << "���벻�Ϸ���������û�и���Ŷ~" << endl;
		return;
	}
	for (int i = 1; i <= Count(); i++)
	{
		if (n == i)
		{
			cout << "��" << i << "�������" << endl;
			for (int j = 0; j < SALER + 5 * SALES - 3; j++)
			{
				cout << FU;
			}
			cout << endl;
			biaotou();
			cout << endl;
			shuchu(p);
			for (int j = 0; j < SALER + 5 * SALES - 3; j++)
			{
				cout << FU;
			}
			cout << endl;
			return;
		}
		p = p->next;
	}
	cout << "��û����һ��ı���Ŷ~,�ٵȼ����" << endl;
	return;
}

//6.ɾ��ĳһ��ı���
void DeleteSomeday(Day** p)
{
	Day* pd = *p;
	Day* pf = *p;
	cout << "������Ҫɾ������һ�죺";
	int n;
	cin >> n;
	if (n < 1)
	{
		cout << "���벻�Ϸ���������û�и���Ŷ~" << endl;
		return;
	}
	if (n == 1)
	{
		*p = (*p)->next;
		free(pd);
		cout << "ɾ���ɹ���" << endl;
		return;
	}
	for (int i = 1; i <= Count(); i++)
	{
		if (i == n)
		{
			pf->next = pd->next;
			free(pd);
			cout << "ɾ���ɹ���" << endl;
			return;
		}
		pf = pd;
		pd = pd->next;
	}
	cout << "��û����һ��ı���Ŷ~,�ٵȼ����" << endl;
	return;
}

//7.�޸�ĳһ��ı�����Ϣ
void ModifySomeday(Day* p)
{
	cout << "������Ҫ�޸ĵ���һ�죺";
	int n;
	cin >> n;
	if (n < 1)
	{
		cout << "���벻�Ϸ���������û�и���Ŷ~" << endl;
		return;
	}
	for (int i = 1; i <= Count(); i++)
	{
		if (i == n)
		{
			cout << "��ѡ��0.ȫ���޸�  1.�޸�����Ա1�ı���  2.�޸�����Ա2�ı���  3.�޸�����Ա3�ı���  4.�޸�����Ա4�ı���)��" << endl;
			int ch;
			cin >> ch;
			cout << "���޸�";
			if (ch == 0)
			{
				shuru(p);
			}
			else if (ch == 1)
			{
				shuru1(p);
			}
			else if (ch == 2)
			{
				shuru2(p);
			}
			else if (ch == 3)
			{
				shuru3(p);
			}
			else if (ch == 4)
			{
				shuru4(p);
			}
			cout << "�޸ĳɹ�" << endl;
			return;
		}
		p = p->next;
	}
	cout << "��û����һ��ı���Ŷ~,�ٵȼ����" << endl;
	return;

}

//8.ͳ��ÿ�ֲ�Ʒ���۶����
void Statistic_EveryProtect_Sort(Day* p)
{
	sum(p);
	ArrProtect arr2;
	arr2.dateprotect = (ProtectDate*)calloc(5, sizeof(ProtectDate));
	arr2.dateprotect[0].ProtectCode = 1;
	arr2.dateprotect[0].SumProtect = s.spro1;
	arr2.dateprotect[1].ProtectCode = 2;
	arr2.dateprotect[1].SumProtect = s.spro2;
	arr2.dateprotect[2].ProtectCode = 3;
	arr2.dateprotect[2].SumProtect = s.spro3;
	arr2.dateprotect[3].ProtectCode = 4;
	arr2.dateprotect[3].SumProtect = s.spro4;
	arr2.dateprotect[4].ProtectCode = 5;
	arr2.dateprotect[4].SumProtect = s.spro5;

	qsort(arr2.dateprotect, 5, sizeof(ProtectDate), com_ProtectDate);
	cout << "���ֲ�Ʒ�����۶��������£�" << endl;
	for (int j = 0; j < 2 * SALER + SSALES - 5; j++)
	{
		cout << FU;
	}
	cout << endl;
	cout << setw(SALER) << left << "��Ʒ";
	cout << setw(SSALES) << left << "�����۶�(Ԫ)";
	cout << setw(SALER) << left << "����" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "��Ʒ";
		cout << setw(SALER - 4) << left << arr2.dateprotect[i].ProtectCode;
		cout << setw(SSALES) << left << arr2.dateprotect[i].SumProtect;
		cout << setw(SALER) << left << i + 1;
		cout << endl;
	}
	for (int j = 0; j < 2 * SALER + SSALES - 5; j++)
	{
		cout << FU;
	}
	cout << endl;
}

//c.����
void Clean()
{
	cout << "\033c";
}

//d.�������
void Alldele(Day** ps)
{
	Day* p = *ps;
	while (p != NULL)
	{
		Day* pd = p;
		p = p->next;
		free(pd);
	}
	*ps = p;
	cout << "ϵͳ��������գ�" << endl;
}

//s.����
void Save(Day* p)
{
	FILE* pfwrite = fopen("system.txt", "wb");
	if (pfwrite == NULL)
	{
		perror("save");
		return;
	}
	while (p != NULL)
	{
		fwrite(&p->man1, 1, sizeof(Note), pfwrite);
		fwrite(&p->man2, 1, sizeof(Note), pfwrite);
		fwrite(&p->man3, 1, sizeof(Note), pfwrite);
		fwrite(&p->man4, 1, sizeof(Note), pfwrite);
		p = p->next;
	}
	cout << "����ɹ�����";
	fclose(pfwrite);
	pfwrite = NULL;
}








//�˵�
void menu()
{
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "    *   |    *   |   *   1.��ȡ���������ľ������۶�             2.¼���ĸ���һ��ı���     *   |   *   |   *    " << endl;
	cout << "     *  |   * *  |  *    3.�������۶������Ա����             4.��ѯĳ������Աÿ��ı���  *  |  * *  |  *     " << endl;
	cout << "      * |  *   * | *     5.��ѯĳһ��ı�����Ϣ                 6.ɾ��������Ϣ               * | *   * | *      " << endl;
	cout << "       * *      * *      7.�޸ı�����Ϣ                         8.ͳ��ÿ�ֲ�Ʒ�����۶����  * *     * *       " << endl;
	cout << "        |        |       9.                                     0.                             |       |        " << endl;
	cout << "        *        *   c(clear).����   d(delete).�������   s(save).����   e(exit).�˳�ϵͳ      *       *        " << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}

//�����ļ�
void Load(Day* p)
{
	FILE* pfread = fopen("system.txt", "rb");
	if (pfread == NULL)
	{
		perror("Load");
		return;
	}
	int i = 0;
	p = (Day*)calloc(1, sizeof(Day));
	while (fread(&p->man1, sizeof(Note), 1, pfread) != 0)
	{
		i = 1;
		p->next = NULL;
		fread(&p->man2, sizeof(Note), 1, pfread);
		fread(&p->man3, sizeof(Note), 1, pfread);
		fread(&p->man4, sizeof(Note), 1, pfread);
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			tail->next = p;
		}
		tail = p;
		p = (Day*)calloc(1, sizeof(Day));
	}
	free(p);
	fclose(pfread);
	pfread = NULL;
}

//������--------------------------------------------------------------------------------------------------------------

int main()
{
	Load(head);		//�����ļ�
	menu();			//��ӡ�˵�		
	char input;		//�������ַ���ʽ���룬��ֹ�������ʱϵͳ����
	int flag = 0;
	cout << "��ѡ���ܣ�";
	cin >> input;
	while (1)
	{
		if (input == '1')
		{
			ShowEveryday(head);
		}
		else if (input == '2')
		{
			Add();
		}
		else if (input == '3')
		{
			Calculate_Sort(head);
		}
		else if (input == '4')
		{
			SearchSomebodyEveryDay(head);
		}
		else if (input == '5')
		{
			SearchSomeday(head);
		}
		else if (input == '6')
		{
			DeleteSomeday(&head);
		}
		else if (input == '7')
		{
			ModifySomeday(head);
		}
		else if (input == '8')
		{
			Statistic_EveryProtect_Sort(head);
		}
		else if (input == 's')
		{
			Save(head);
			flag = 1;
		}
		else if (input == 'c')
		{
			Clean();			//����֮���ӡ�˵�
			menu();
		}
		else if (input == 'd')
		{
			Alldele(&head);
		}
		else if (input == 'e')
		{
			//�ж��Ƿ񱣴棨y.���棩��������������
			if (flag == 0)
			{
				cout << "�Ƿ񱣴�(y/n)��";
				char ch;
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					Save(head);
				}
			}
			cout << endl << "�ݰ�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			return 0;
		}
		else
		{
			cout << "��tmѡ�������ʲô���Ͻ���ѡ��������" << endl;
		}
		cout << "���ٴ�ѡ���ܣ�";
		cin >> input;
	}
	return 0;
}

