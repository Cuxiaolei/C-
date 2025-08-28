#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<iomanip>  //���������ʽ
#include<string>
#include<stdio.h>
#include<stdlib.h>

#define NAME 20
using namespace std;

//�ṹ�嵥Ԫ---------------------------------------------------------------------------------
typedef struct stu
{
	int count = 0;
	int id;
	char name[NAME];
	float E;
	float M;
	float C;
	float Sum;
}stu;
typedef struct sys
{
	int count = 0;
	stu date;
	sys* next;
}sys;
sys* head = NULL;
sys* tail = NULL;

//Ϊ���򴴽�������
typedef struct sysarr
{
	stu* date1;
	int count;
}sysarr;
//��ʼ��
void init(sysarr* ps)
{
	ps->date1 = (stu*)calloc(1, sizeof(stu));
	ps->count = 0;
	cout << "666666666" << endl;
}



//��������1-----------------------------------------------------------------------------------

//��ӡ��ͷ
void showbiaotou()
{
	cout << setw(8) << left << "���";
	cout << setw(10) << left << "ѧ��";
	cout << setw(15) << left << "����";
	cout << setw(15) << left << "Ӣ��ɼ�";
	cout << setw(15) << left << "��ѧ�ɼ�";
	cout << setw(15) << left << "������ɼ�";
	cout << setw(15) << left << "�ܷ�";
	cout << setw(8) << left << "����";
	cout << endl;
}

//���ѧ���Ƿ��ظ�
int check(int id, sys* ps)
{
	int n = 1;
	sys* p = head;
	void shuchuxinxi(sys * ps, int i);
	while (p != NULL)
	{
		if (p->date.id == id)
		{
			cout << "��ѧ���Ѵ���,���£�" << endl;
			showbiaotou();
			shuchuxinxi(p, n);
			n++;
			cout << endl << "����������!" << endl;
			free(ps);
			return 1;
		}
		p = p->next;
	}
	return 0;
}

//���ѧ���Ƿ��ظ�(�޸�ģʽ�汾)
int check1(int id, sys* ps, int x)
{
	int n = 1;
	sys* p = head;
	void shuchuxinxi(sys * ps, int i);
	while (p != NULL)	//��ʵ����Ҫwhile��ps������ʱps->date.id���Ѿ�����id��
	{
		if (p->date.id == id)
		{
			if (id == x)
			{
				p = p->next;
				continue;
			}
			cout << "��ѧ���Ѵ���,���£�" << endl;
			showbiaotou();
			shuchuxinxi(p, n);
			n++;
			cout << endl << "����������!" << endl;
			free(ps);
			return 1;
		}
		p = p->next;
	}
	return 0;
}

//������Ϣ
int shurustu(sys* ps)
{
	cout << "������ѧ��ѧ��:";
	cin >> ps->date.id;
	int a = check(ps->date.id, ps);		//�ж�ѧ���ظ�
	if (a == 1)
	{
		return 1;
	}
	cout << "������ѧ������:";
	cin >> ps->date.name;
	cout << "������Ӣ��ɼ�:";
	cin >> ps->date.E;
	cout << "��������ѧ�ɼ�:";
	cin >> ps->date.M;
	cout << "�����������ɼ�:";
	cin >> ps->date.C;
	ps->date.Sum = ps->date.M + ps->date.C + ps->date.E;
	//ps->date.count = 0;
	return 0;
}

//������Ϣ2(�޸�ģʽ�汾)
int shurustu1(sys* ps, int x)
{
	cout << "������ѧ��ѧ��:";
	cin >> ps->date.id;
	int a = check1(ps->date.id, ps, x);		//�ж�ѧ���ظ�
	if (a == 1)
	{
		return 1;
	}
	cout << "������ѧ������:";
	cin >> ps->date.name;
	cout << "������Ӣ��ɼ�:";
	cin >> ps->date.E;
	cout << "��������ѧ�ɼ�:";
	cin >> ps->date.M;
	cout << "�����������ɼ�:";
	cin >> ps->date.C;
	ps->date.Sum = ps->date.M + ps->date.C + ps->date.E;
	//ps->date.count = 0;
	return 0;
}

//�����Ϣ
void shuchuxinxi(sys* ps, int i)
{
	cout << setw(8) << left << i;
	cout << setprecision(2) << fixed;
	cout << setw(10) << left << ps->date.id;
	cout << setw(15) << left << ps->date.name;
	cout << setw(15) << left << ps->date.E;
	cout << setw(15) << left << ps->date.M;
	cout << setw(15) << left << ps->date.C;
	cout << setw(15) << left << ps->date.Sum;
	cout << setw(8) << left << ps->date.count;
	cout << endl;
}

//������Ϣ
void loadsys(sys* ps)
{
	FILE* pfread = fopen("stusys.txt", "rb");
	if (pfread == NULL)
	{
		perror("loadsys");
		return;
	}
	ps = (sys*)calloc(1, sizeof(sys));
	while (fread(&ps->date, sizeof(stu), 1, pfread))
	{
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
		ps = (sys*)calloc(1, sizeof(sys));
	}
	fclose(pfread);
	pfread = NULL;
}

//�ⲿ��������(ѧ��)
int cmp_arr1(const void* e1, const void* e2)
{
	return (int)(((stu*)e1)->id - ((stu*)e2)->id);
}

//�ⲿ��������(����)
int cmp_arr2(const void* e1, const void* e2)
{
	return strcmp(((stu*)e1)->name, ((stu*)e2)->name);
}

//�ⲿ��������(�ܷ�)
int cmp_arr3(const void* e1, const void* e2)
{
	return (int)(((stu*)e2)->Sum - ((stu*)e1)->Sum);
}



//��������2--------------------------------------------------------

//ͳ������
int Count(sys* ps)
{
	int count = 0;
	while (ps != NULL)
	{
		count++;
		ps = ps->next;
	}
	return count;
}

//Ӣ����߷�
float MaxEnglish(sys* ps)
{
	float max = 0;
	while (ps != NULL)
	{
		if (max < ps->date.E)
		{
			max = ps->date.E;
		}
		ps = ps->next;
	}
	return max;
}

//Ӣ����ͷ�
float MinEnglish(sys* ps)
{
	float min = 101;
	while (ps != NULL)
	{
		if (min > ps->date.E)
		{
			min = ps->date.E;
		}
		ps = ps->next;
	}
	return min;
}

//Ӣ��ƽ����
float AveEnglish(sys* ps)
{
	float count = (float)Count(ps);
	float sum = 0;
	float ave;
	while (ps != NULL)
	{
		sum += ps->date.E;
		ps = ps->next;
	}
	ave = sum / count;
	return ave;
}

//��ѧ��߷�
float MaxMath(sys* ps)
{
	float max = 0;
	while (ps != NULL)
	{
		if (max < ps->date.M)
		{
			max = ps->date.M;
		}
		ps = ps->next;
	}
	return max;
}

//��ѧ��ͷ�
float MinMath(sys* ps)
{
	float min = 101;
	while (ps != NULL)
	{
		if (min > ps->date.M)
		{
			min = ps->date.M;
		}
		ps = ps->next;
	}
	return min;
}

//��ѧƽ����
float AveMath(sys* ps)
{
	float count = (float)Count(ps);
	float sum = 0;
	float ave;
	while (ps != NULL)
	{
		sum += ps->date.M;
		ps = ps->next;
	}
	ave = sum / count;
	return ave;
}

//�������߷�
float MaxComputer(sys* ps)
{
	float max = 0;
	while (ps != NULL)
	{
		if (max < ps->date.C)
		{
			max = ps->date.C;
		}
		ps = ps->next;
	}
	return max;
}

//�������ͷ�
float MinComputer(sys* ps)
{
	float min = 101;
	while (ps != NULL)
	{
		if (min > ps->date.C)
		{
			min = ps->date.C;
		}
		ps = ps->next;
	}
	return min;
}

//�����ƽ����
float AveComputer(sys* ps)
{
	float count = (float)Count(ps);
	float sum = 0;
	float ave;
	while (ps != NULL)
	{
		sum += ps->date.C;
		ps = ps->next;
	}
	ave = sum / count;
	return ave;
}

//�����Ƿ��������(ѧ�Ų�ѯ)���еĻ�����1��û�еĻ�����0��
int find(sys* ps, int id)
{
	while (ps != NULL && ps->date.id != id)
	{
		ps = ps->next;
	}
	if (ps != NULL && ps->date.id == id)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//�����Ƿ��������(������ѯ)���еĻ�����1��û�еĻ�����0��
int find(sys* ps, char name[])
{
	while (ps != NULL && strcmp(ps->date.name, name) != 0)
	{
		ps = ps->next;
	}
	if (ps != NULL && strcmp(ps->date.name, name) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//���ܺ���------------------------------------------------------------------------------------

//1.¼����Ϣ
void addsys(sys* ps)
{
	cout << "��������Ҫ��ӵ�ѧ����Ϣ" << endl;
	ps = (sys*)calloc(1, sizeof(sys));
	ps->next = NULL;
	int a = shurustu(ps);		//�ж��Ƿ�ѧ���ظ�
	if (a == 1)
	{
		return;
	}
	if (head == NULL)
	{
		head = ps;
	}
	else
	{
		tail->next = ps;
	}
	tail = ps;
	cout << "��ӳɹ���" << endl << endl;
}

//2.��ʾ��Ϣ
void showsys(sys* ps)
{
	if (ps == NULL)
	{
		cout << "ϵͳΪ�գ�����¼��ѧ����Ϣ!" << endl;
		return;
	}
	showbiaotou();
	int n = 1;
	while (ps != NULL)
	{
		shuchuxinxi(ps, n);
		n++;
		ps = ps->next;
	}
	cout << endl;
}

//3.����
void search(sys* ps)
{
	if (ps == NULL)
	{
		cout << "ϵͳ��û��ѧ����Ϣ������Ҳ�ǰ��ң�" << endl;
		return;
	}
	char a;
	cout << "������Ҫ���ҵĹؼ��ʵ�ѡ�� (1.ѧ��   2.����   0.ȡ��):";
	cin >> a;
	//����ѧ��ѧ��
	if (a == '1')
	{
		int n = 1;
		int id;
		int flag = 0;
		cout << "������Ҫ���ҵ�ѧ�ţ�";
		cin >> id;
		while (ps != NULL)
		{
			while (ps != NULL && ps->date.id != id)
			{
				ps = ps->next;
			}
			if (ps != NULL && ps->date.id == id)
			{
				if (flag == 0)
				{
					showbiaotou();
				}
				flag = 1;
				shuchuxinxi(ps, n);
				n++;
				ps = ps->next;
			}
		}
		if (flag == 0)
		{
			cout << "���޴˺�!!" << endl;
			return;
		}
	}
	//����ѧ������
	else if (a == '2')
	{
		int n = 1;
		char name[NAME];
		int flag = 0;
		cout << "������Ҫ���ҵ�ѧ��������";
		cin >> name;
		while (ps != NULL)
		{
			while (ps != NULL && strcmp(ps->date.name, name) != 0)
			{
				ps = ps->next;
			}
			if (ps != NULL && strcmp(ps->date.name, name) == 0)
			{
				if (flag == 0)
				{
					showbiaotou();
				}
				flag = 1;
				shuchuxinxi(ps, n);
				n++;
				ps = ps->next;
			}
		}
		if (flag == 0)
		{
			cout << "���޴���!!" << endl;
			return;
		}
	}
	//�˳�
	else
	{
		cout << "���˳�����" << endl;
		return;
	}
}

//4.����
void sort(sys* ps)
{
	if (ps == NULL)
	{
		cout << "ϵͳΪ�գ��Ͻ�ȥ¼��ѧ����Ϣ��" << endl;
		return;
	}
	char n;
	cout << "��ѡ������ʽ(1.��ѧ������  2.����������  3.���ܷ�����+����):";
	cin >> n;
	if (n == '1')
	{
		sys* pd = ps;
		sysarr arr;
		init(&arr);
		while (pd != NULL)
		{
			arr.date1[arr.count] = pd->date;
			arr.count++;
			arr.date1 = (stu*)realloc(arr.date1, (arr.count + 1) * sizeof(stu));
			pd = pd->next;
		}
		qsort(arr.date1, arr.count, sizeof(stu), cmp_arr1);
		for (int i = 0; i < arr.count; i++)
		{
			ps->date = arr.date1[i];
			ps = ps->next;
		}
		free(arr.date1);
		cout << "��ѧ������ɹ�����" << endl;
	}
	else if (n == '2')
	{
		sys* pd = ps;
		sysarr arr;
		init(&arr);
		while (pd != NULL)
		{
			arr.date1[arr.count] = pd->date;
			arr.count++;
			arr.date1 = (stu*)realloc(arr.date1, (arr.count + 1) * sizeof(stu));
			pd = pd->next;
		}
		qsort(arr.date1, arr.count, sizeof(stu), cmp_arr2);
		for (int i = 0; i < arr.count; i++)
		{
			ps->date = arr.date1[i];
			ps = ps->next;
		}
		free(arr.date1);
		cout << "����������ɹ�����" << endl;
	}
	else if (n == '3')
	{
		sys* pd = ps;
		sysarr arr;
		init(&arr);
		while (pd != NULL)
		{
			arr.date1[arr.count] = pd->date;
			arr.count++;
			arr.date1 = (stu*)realloc(arr.date1, (arr.count + 1) * sizeof(stu));
			pd = pd->next;
		}
		qsort(arr.date1, arr.count, sizeof(stu), cmp_arr3);
		for (int i = 0; i < arr.count; i++)
		{
			ps->date = { 0 };
			ps->date = arr.date1[i];
			ps->date.count = i + 1;
			ps = ps->next;
		}
		free(arr.date1);
		cout << "���ܷ�����ɹ�����" << endl;
	}
	else
	{
		cout << "�������������ѡ���������˳�" << endl;
	}
}

//5.ͳ��
void statistic(sys* ps)
{
	if (ps == NULL)
	{
		cout << "ϵͳΪ�գ��Ͻ�ȥ¼��ѧ����Ϣ��" << endl;
		return;
	}
	char flag;
	int count = Count(ps);
	cout << "��ѡ���Ӧ���ſΣ�1.Ӣ��  2.��ѧ  3.�����  0.�˳�������ͳ�ƣ�";
	cin >> flag;
	//Ӣ��
	if (flag == '1')
	{
		float e1 = MaxEnglish(ps);
		float e2 = MinEnglish(ps);
		float e3 = AveEnglish(ps);
		int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
		while (ps != NULL)
		{
			if (ps->date.E >= 90.0)
			{
				a1++;
			}
			else if (ps->date.E >= 80.0)
			{
				a2++;
			}
			else if (ps->date.E >= 70.0)
			{
				a3++;
			}
			else if (ps->date.E >= 60.0)
			{
				a4++;
			}
			else if (ps->date.E < 60.0)
			{
				a5++;
			}
			ps = ps->next;
		}
		cout << setprecision(2) << fixed;
		cout << "*********************************************************" << endl;
		cout << "ѧ��������" << count << endl;
		cout << "��߷֣�" << e1 << endl;
		cout << "��ͷ֣�" << e2 << endl;
		cout << "ƽ���ɼ���" << e3 << endl;
		cout << "�ɼ��ֲ������" << endl;
		cout << setw(10) << left << "������";
		cout << setw(10) << left << "����";
		cout << setw(10) << left << "�ٷֱ�";
		cout << endl;
		cout << setw(10) << left << "[90,100]";
		cout << setw(10) << left << a1;
		cout << (a1 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[80,90)";
		cout << setw(10) << left << a2;
		cout << (a2 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[70,80)";
		cout << setw(10) << left << a3;
		cout << (a3 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[60,70)";
		cout << setw(10) << left << a4;
		cout << (a4 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[0,60)";
		cout << setw(10) << left << a5;
		cout << (a5 / (float)count) * 100 << "%" << endl;
		cout << "*********************************************************" << endl;
	}
	//��ѧ
	else if (flag == '2')
	{
		float e1 = MaxMath(ps);
		float e2 = MinMath(ps);
		float e3 = AveMath(ps);
		int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
		while (ps != NULL)
		{
			if (ps->date.M >= 90.0)
			{
				a1++;
			}
			else if (ps->date.M >= 80.0)
			{
				a2++;
			}
			else if (ps->date.M >= 70.0)
			{
				a3++;
			}
			else if (ps->date.M >= 60.0)
			{
				a4++;
			}
			else if (ps->date.M < 60.0)
			{
				a5++;
			}
			ps = ps->next;
		}
		cout << setprecision(2) << fixed;
		cout << "*********************************************************" << endl;
		cout << "ѧ��������" << count << endl;
		cout << "��߷֣�" << e1 << endl;
		cout << "��ͷ֣�" << e2 << endl;
		cout << "ƽ���ɼ���" << e3 << endl;
		cout << "�ɼ��ֲ������" << endl;
		cout << setw(10) << left << "������";
		cout << setw(10) << left << "����";
		cout << setw(10) << left << "�ٷֱ�";
		cout << endl;
		cout << setw(10) << left << "[90,100]";
		cout << setw(10) << left << a1;
		cout << (a1 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[80,90)";
		cout << setw(10) << left << a2;
		cout << (a2 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[70,80)";
		cout << setw(10) << left << a3;
		cout << (a3 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[60,70)";
		cout << setw(10) << left << a4;
		cout << (a4 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[0,60)";
		cout << setw(10) << left << a5;
		cout << (a5 / (float)count) * 100 << "%" << endl;
		cout << "*********************************************************" << endl;
	}
	//�����
	else if (flag == '3')
	{
		float e1 = MaxComputer(ps);
		float e2 = MinComputer(ps);
		float e3 = AveComputer(ps);
		int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
		while (ps != NULL)
		{
			if (ps->date.C >= 90.0)
			{
				a1++;
			}
			else if (ps->date.C >= 80.0)
			{
				a2++;
			}
			else if (ps->date.C >= 70.0)
			{
				a3++;
			}
			else if (ps->date.C >= 60.0)
			{
				a4++;
			}
			else if (ps->date.C < 60.0)
			{
				a5++;
			}
			ps = ps->next;
		}
		cout << setprecision(2) << fixed;
		cout << "*********************************************************" << endl;
		cout << "ѧ��������" << count << endl;
		cout << "��߷֣�" << e1 << endl;
		cout << "��ͷ֣�" << e2 << endl;
		cout << "ƽ���ɼ���" << e3 << endl;
		cout << "�ɼ��ֲ������" << endl;
		cout << setw(10) << left << "������";
		cout << setw(10) << left << "����";
		cout << setw(10) << left << "�ٷֱ�";
		cout << endl;
		cout << setw(10) << left << "[90,100]";
		cout << setw(10) << left << a1;
		cout << (a1 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[80,90)";
		cout << setw(10) << left << a2;
		cout << (a2 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[70,80)";
		cout << setw(10) << left << a3;
		cout << (a3 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[60,70)";
		cout << setw(10) << left << a4;
		cout << (a4 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[0,60)";
		cout << setw(10) << left << a5;
		cout << (a5 / (float)count) * 100 << "%" << endl;
		cout << "*********************************************************" << endl;
	}
	//�˳�
	else
	{
		cout << "���˳�ͳ��" << endl;
		return;
	}
}

//6.�޸�
void modify(sys* ps)
{
	if (ps == NULL)
	{
		cout << "ϵͳ�ﻹû��ѧ����Ϣ���Ͻ�ȥ��Ӱɣ�" << endl;
		return;
	}
	cout << "������ѡ��ѧ����ʽ��1.ѧ��  2.����  0.�˳�����";
	char n;
	cin >> n;
	if (n == '1')
	{
		cout << "��������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�";
		int id;
		cin >> id;
		while (ps != NULL && ps->date.id != id)
		{
			ps = ps->next;
		}
		if (ps->date.id == id)
		{
			cout << "�������޸ĺ����Ϣ��" << endl;
			ps->date = { 0 };
			int a = shurustu1(ps, id);
			if (a == 1)
			{
				return;
			}
			cout << "�޸ĳɹ���" << endl;
		}
	}
	else if (n == '2')
	{
		cout << "��������Ҫ�޸���Ϣ��ѧ����������";
		char name[NAME];
		cin >> name;
		while (ps != NULL && strcmp(ps->date.name, name) != 0)
		{
			ps = ps->next;
		}
		if (strcmp(ps->date.name, name) == 0)
		{
			cout << "�������޸ĺ����Ϣ��" << endl;
			int id = ps->date.id;
			ps->date = { 0 };
			int a = shurustu1(ps, id);
			if (a == 1)
			{
				return;
			}
			cout << "�޸ĳɹ���" << endl;
		}
	}
	else
	{
		cout << "���˳��޸�" << endl;
		return;
	}
}

//7.ɾ��
void Delete(sys** ps)
{
	if (*ps == NULL)
	{
		cout << "ϵͳ�л�û��ѧ����Ϣ���Ͻ�ȥ¼��ɣ�" << endl;
		return;
	}
	sys* pf = *ps;
	sys* pd = *ps;
	cout << "������ѡ��ɾ��ѧ����ʽ��1.ѧ��  2.����  0.�˳�����";
	char n;
	cin >> n;
	if (n == '1')
	{
		cout << "������Ҫɾ��ѧ����Ϣ��ѧ�ţ�";
		int id;
		cin >> id;
		while (pd != NULL && pd->date.id != id)
		{
			pf = pd;
			pd = pd->next;
		}
		if (pd->date.id == id)
		{
			if (pf == pd)
			{
				*ps = (*ps)->next;
				free(pd);
			}
			else
			{
				pf->next = pd->next;
				free(pd);
			}
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "��û���ҵ�����Ҫɾ������" << endl;
		}
	}
	else if (n == '2')
	{
		cout << "������Ҫɾ��ѧ����Ϣ��������";
		char name[NAME];
		cin >> name;
		while (pd != NULL && strcmp(pd->date.name, name) != 0)
		{
			pf = pd;
			pd = pd->next;
		}
		if (strcmp(pd->date.name, name) == 0)
		{
			if (pf == pd)
			{
				*ps = (*ps)->next;
				free(pd);
			}
			else
			{
				pf->next = pd->next;
				free(pd);
			}
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "��û���ҵ�����Ҫɾ������" << endl;
		}
	}

}

//8.����
void insert(sys** ps, sys* p)
{
	if (p == NULL)
	{
		cout << "ϵͳ��û����Ϣ����ȥ¼��ѧ����Ϣ��" << endl;
		return;
	}
	cout << "������ѡ��ѧ����ʽ��1.ѧ��  2.����  0.�˳�����";
	char n;
	cin >> n;
	if (n == '1')
	{
		cout << "������Ҫ����ѧ����Ϣ��λ�ã�ѧ�ţ���";
		int id;
		cin >> id;
		int a = find(p, id);
		sys* pf = p;
		sys* pd = p;
		if (a == 1)
		{
			cout << "������Ҫ����Ϣ���뵽��λ�õ����u.�Ϸ�  d.�·�����";
			char ch;
			cin >> ch;
			sys* pc = (sys*)calloc(1, sizeof(sys));
			pc->next = NULL;
			int a = shurustu(pc);
			if (a == 1)			//�ж������ѧ���Ƿ��ظ�
			{
				return;
			}
			while (pd->date.id != id)
			{
				pf = pd;
				pd = pd->next;
			}
			if (ch == 'u' || ch == 'U')
			{
				if (pf == pd)
				{
					*ps = pc;
					pc->next = pf;
				}
				else
				{
					pf->next = pc;
					pc->next = pd;
				}
			}
			else if (ch == 'd' || ch == 'D')
			{
				if (pf == pd)
				{
					sys* pl = pf->next;
					pf->next = pc;
					pc->next = pl;
				}
				else
				{
					sys* pl = pd->next;
					pd->next = pc;
					pc->next = pl;
				}
			}
			else
			{
				cout << "���벻�Ϸ������˳�����" << endl;
				return;
			}
			cout << "����ɹ���" << endl;
		}
		else
		{
			cout << "�Ҳ������ѧ�ţ��ǲ���������ˣ�" << endl;
			return;
		}
	}
	else if (n == '2')
	{
		cout << "������Ҫ����ѧ����Ϣ��λ�ã���������";
		char name[NAME];
		cin >> name;
		int a = find(p, name);
		sys* pf = p;
		sys* pd = p;
		if (a == 1)
		{
			cout << "������Ҫ����Ϣ���뵽��λ�õ����u.�Ϸ�  d.�·�����";
			char ch;
			cin >> ch;
			sys* pc = (sys*)calloc(1, sizeof(sys));
			pc->next = NULL;
			int a = shurustu(pc);		//�ж��Ƿ��ظ�
			if (a == 1)
			{
				return;
			}
			while (strcmp(pd->date.name, name) != 0)
			{
				pf = pd;
				pd = pd->next;
			}
			if (ch == 'u' || ch == 'U')
			{
				if (pf == pd)
				{
					*ps = pc;
					pc->next = pf;
				}
				else
				{
					pf->next = pc;
					pc->next = pd;
				}
			}
			else if (ch == 'd' || ch == 'D')
			{
				if (pf == pd)
				{
					sys* pl = pf->next;
					pf->next = pc;
					pc->next = pl;
				}
				else
				{
					sys* pl = pd->next;
					pd->next = pc;
					pc->next = pl;
				}
			}
			else
			{
				cout << "���벻�Ϸ������˳�����" << endl;
				return;
			}
			cout << "����ɹ���" << endl;
		}
		else
		{
			cout << "�Ҳ������ѧ�ţ��ǲ���������ˣ�" << endl;
			return;
		}
	}
	else
	{
		cout << "���˳�����" << endl;
		return;
	}
}

//9.����
void save(sys* ps)
{
	FILE* pfwrite = fopen("stusys.txt", "wb");
	if (pfwrite == NULL)
	{
		perror("save");
		return;
	}
	if (ps == NULL)
	{
		cout << "����ɹ���" << endl;
		fclose(pfwrite);
		pfwrite = NULL;
		return;
	}
	while (ps != NULL)
	{
		fwrite(&ps->date, sizeof(stu), 1, pfwrite);
		ps = ps->next;
	}
	cout << "����ɹ���" << endl;
	fclose(pfwrite);
	pfwrite = NULL;
}

//c.����
void clean()
{
	cout << "\033c";
}

//d.���ϵͳ����
void alldelete(sys** ps)
{
	sys* p = *ps;
	while (p != NULL)
	{
		sys* pd = p;
		p = p->next;
		free(pd);
	}
	*ps = p;
	cout << "����ɹ���" << endl;
}



//�˵�
void menu()
{
	cout << "------------------------------------------ѧ���ɼ�����ϵͳ---------------------------------------------------" << endl;
	cout << "1.¼��     2.��ʾ     3.����     4.����     5.ͳ��     6.�޸�     7.ɾ��     8.����     9.����     0.�˳�" << endl;
	cout << "c.����     d.���ϵͳ " << endl;
	cout << "-------------------------------------------------------------------------------------------------------------" << endl;
}

//������-------------------------------------------------------------------------------------------------
int main()
{
	cout << "������ѧ���ɼ�����ϵͳ���루��ֻ�����λ���)��";
	char IPN[20];
	cin >> IPN;
	int q = 0;
	while (strcmp(IPN, "woshi541hehe") != 0)
	{
		q++;
		if (q == 3)
		{
			cout << "���Ѿ�����������Σ�ϵͳ���Զ��˳�������" << endl;
			return 0;
		}
		cout << "����������������룺";
		cin >> IPN;
	}
	loadsys(head);		//������Ϣ
	menu();				//�˵�
	cout << endl << "��ѡ���ܣ�";
	int flag = 1;
	int flag1 = 1;
	char input;
	while (1)
	{
		if (flag == 0)
		{
			cout << "���ٴ�ѡ���ܣ�";
		}
		flag = 0;
		cin >> input;
		if (input == '1')
		{
			addsys(head);
			int flag1 = 1;
		}
		else if (input == '2')
		{
			showsys(head);
			int flag1 = 1;
		}
		else if (input == '3')
		{
			search(head);
			int flag1 = 1;
		}
		else if (input == '4')
		{
			sort(head);
			int flag1 = 1;
		}
		else if (input == '5')
		{
			statistic(head);
			int flag1 = 1;
		}
		else if (input == '6')
		{
			modify(head);
			int flag1 = 1;
		}
		else if (input == '7')
		{
			Delete(&head);
			int flag1 = 1;
		}
		else if (input == '8')
		{
			insert(&head, head);
			int flag1 = 1;
		}
		else if (input == '9')
		{
			save(head);
			flag1 = 0;
		}
		else if (input == 'c')
		{
			clean();
			menu();
		}
		else if (input == 'd')
		{
			alldelete(&head);
			int flag1 = 1;
		}
		else if (input == '0')
		{
			//�����Ƿ�Ҫ����
			if (flag1 == 1)
			{
				char ch;
				cout << "�˳�ǰ�Ƿ�Ҫ����?(y/n):";
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					save(head);
				}
			}
			cout << "�ݰ�~" << endl;
			break;
		}
		else
		{
			cout << "? ? ? ! ! ! ! ! ! ! ,��tm��ѡʲô��" << endl;
		}
	}
	return 0;
}
