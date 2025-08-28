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

//尾插
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
//尾删
void ListPopBack(ListNode* p)
{
	if (p->next == p)
	{
		cout << "链表为空" << endl;
		return;
	}
	ListNode* pd = p->prev;
	ListNode* tail = pd->prev;
	tail->next = p;
	p->prev = tail;
	free(pd);
}
//头插
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
//头删
void ListPopFront(ListNode* p)
{
	if (p->next == p)
	{
		cout << "链表已空" << endl;
		return;
	}
	ListNode* pd = p->next;
	ListNode* p1 = pd->next;

	p->next = p1;
	p1->prev = p;
	free(pd);
}

//查找
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
	cout << "找不到" << endl;
	return NULL;
}

//插入（前）
void ListInsert(ListNode* pos)
{
	if (pos == NULL)
	{
		return;
	}
	int x;
	cout << "请输入要插入的数：";
	cin >> x;
	ListNode* pf = pos->prev;
	ListNode* newnode = (ListNode*)calloc(1, sizeof(ListNode));
	newnode->date = x;

	newnode->prev = pf;
	newnode->next = pos;

	pos->prev = newnode;
	pf->next = newnode;
}

//删除
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

//打印
void ListPrint(ListNode* p)
{
	if (p->next == p)
	{
		cout << "链表为空！" << endl;
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

//清空
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
	cout << "清除成功！" << endl;
}






void TestList1()
{
	cout << "1.插入    2.删除    3.清空    4.打印链表    0.退出" << endl;
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
		cout << "请选择：";
		cin >> input;
		if (input == 1)//插入（前）
		{
			cout << "请输入要插入的位置：";
			ListInsert(ListFind(plist));
			ListPrint(plist);
		}
		else if (input == 2)
		{
			cout << "请输入要删除的数：";
			Listdele(ListFind(plist));
			ListPrint(plist);
		}
		else if (input == 3)
		{
			ListDestroy(plist);
			cout << "已清除！" << endl;
			ListPrint(plist);
		}
		else if (input == 4)
		{
			ListPrint(plist);
		}
		else
		{
			cout << endl;
			cout << "已退出！！";
			return;
		}
	}
}



int main()
{
	TestList1();
	return 0;
}