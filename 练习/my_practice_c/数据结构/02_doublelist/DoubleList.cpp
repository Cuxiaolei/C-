#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef struct ListNode
{
	int date;
	ListNode* next;
	ListNode* prev;
}ListNode;


ListNode* ListInit()
{
	ListNode* p = (ListNode*)calloc(1, sizeof(ListNode));
	p->next = p;
	p->prev = p;
	return p;
}

//β��
void ListPushBack(ListNode* p, int x)
{
	assert(p);

	ListNode* tail = p->prev;
	ListNode* newnode = (ListNode*)calloc(1, sizeof(ListNode));
	newnode->date = x;

	newnode->next = p;
	newnode->prev = tail;

	tail->next = newnode;
	p->prev = newnode;
}
//βɾ
void ListPopBack(ListNode* p)
{
	if (p->next == p)
	{
		cout << "����Ϊ��" << endl;
		return;
	}
	ListNode* pd = p->prev;
	ListNode* tail = pd->prev;
	tail->next = p;
	p->prev = tail;
	free(pd);
}
//ͷ��
void ListPushFront(ListNode* p, int x)
{
	ListNode* newnode = (ListNode*)calloc(1, sizeof(ListNode));
	ListNode* p1 = p->next;

	newnode->date = x;

	newnode->prev = p;
	newnode->next = p1;

	p1->prev = newnode;
	p->next = newnode;
}
//ͷɾ
void ListPopFront(ListNode* p)
{
	if (p->next == p)
	{
		cout << "�����ѿ�" << endl;
		return;
	}
	ListNode* pd = p->next;
	ListNode* p1 = pd->next;

	p->next = p1;
	p1->prev = p;
	free(pd);
}

//����
ListNode* ListFind(ListNode* p)
{
	int x;
	cin >> x;
	ListNode* cur = p->next;
	while (cur != p)
	{
		if (cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	cout << "�Ҳ���" << endl;
	return NULL;
}

//���루ǰ��
void ListInsert(ListNode* pos)
{
	if (pos == NULL)
	{
		return;
	}
	int x;
	cout << "������Ҫ���������";
	cin >> x;
	ListNode* pf = pos->prev;
	ListNode* newnode = (ListNode*)calloc(1, sizeof(ListNode));
	newnode->date = x;

	newnode->prev = pf;
	newnode->next = pos;

	pos->prev = newnode;
	pf->next = newnode;
}

//ɾ��
void Listdele(ListNode* p)
{
	if (p == NULL)
	{
		return;
	}
	ListNode* pf = p->prev;
	ListNode* pn = p->next;

	pf->next = pn;
	pn->prev = pf;
	free(p);
	p = NULL;
}

//��ӡ
void ListPrint(ListNode* p)
{
	if (p->next == p)
	{
		cout << "����Ϊ�գ�" << endl;
		return;
	}
	ListNode* cur = p->next;
	while (cur != p)
	{
		cout << cur->date << ' ';
		cur = cur->next;
	}
	cout << endl;
}

//���
void ListDestroy(ListNode* p)
{
	ListNode* cur = p->next;
	while (cur != p)
	{
		ListNode* pd = cur;
		cur = cur->next;
		free(pd);
	}
	p->next = p;
	p->prev = p;
	cout << "����ɹ���" << endl;
}






void TestList1()
{
	cout << "1.����    2.ɾ��    3.���    4.��ӡ����    0.�˳�" << endl;
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPopBack(plist);
	ListPushFront(plist, 666);
	ListPushFront(plist, 555);
	ListPopFront(plist);
	ListPrint(plist);
	while (1)
	{
		int input;
		cout << "��ѡ��";
		cin >> input;
		if (input == 1)//���루ǰ��
		{
			cout << "������Ҫ�����λ�ã�";
			ListInsert(ListFind(plist));
			ListPrint(plist);
		}
		else if (input == 2)
		{
			cout << "������Ҫɾ��������";
			Listdele(ListFind(plist));
			ListPrint(plist);
		}
		else if (input == 3)
		{
			ListDestroy(plist);
			cout << "�������" << endl;
			ListPrint(plist);
		}
		else if (input == 4)
		{
			ListPrint(plist);
		}
		else
		{
			cout << endl;
			cout << "���˳�����";
			return;
		}
	}
}



int main()
{
	TestList1();
	return 0;
}