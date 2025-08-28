#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;


//�ж��Ƿ�Ϊ��
bool QueueEmpty(Queue* p)
{
	assert(p);
	return p->head == NULL;
}

//��ʼ��
void QueueInit(Queue* p)
{
	assert(p);
	p->head = NULL;
	p->tail = NULL;

}

//����
void QueueDestroy(Queue* p)
{
	assert(p);
	QueueNode* cur = p->head;
	while (cur != NULL)
	{
		QueueNode* pn = cur->next;
		free(cur);
		cur = pn;
	}

	p->head = p->tail = NULL;
}

//��β������
void QueuePush(Queue* p, QDataType x)
{
	assert(p);
	QueueNode* newnode = (QueueNode*)calloc(1, sizeof(QueueNode));
	newnode->data = x;
	if (p->head == NULL)
	{
		p->head = newnode;
	}
	else
	{
		p->tail->next = newnode;
	}
	p->tail = newnode;
}

//��ͷ������
void QueuePop(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	QueueNode* pd = p->head;
	QueueNode* pn = pd->next;
	if (pn == NULL)
	{
		p->tail = pn;
	}
	free(pd);
	p->head = pn;
}

//��ӡ����
void QueuePrint(Queue* p)
{
	assert(p);
	if (p->head == NULL)
	{
		cout << "����Ϊ��" << endl;
		return;
	}
	QueueNode* pf = p->head;
	while (pf != NULL)
	{
		cout << pf->data << ' ';
		pf = pf->next;
	}
	cout << endl;
}

//ȡͷֵ
QDataType QueueFront(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	return p->head->data;
}
//ȡβֵ
QDataType QueueBack(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	return p->tail->data;
}

//���ض��г���
//int QueueSize(Queue* p)
//{
//
//}

//ȡ����������
void QueueGo_out(Queue* p)
{
	while (!QueueEmpty(p))
	{
		QDataType date = QueueFront(p);
		cout << date << ' ';
		QueuePop(p);
	}
	cout << endl;
}


void TestQueue1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePrint(&q);
	cout << QueueFront(&q) << endl;

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePrint(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePrint(&q);

	QueueGo_out(&q);


	QueueDestroy(&q);
}




int main()
{
	TestQueue1();



	return 0;
}