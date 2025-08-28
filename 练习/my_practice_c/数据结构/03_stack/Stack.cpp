#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


typedef char STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//��ʼ��
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

//�ͷſռ�
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

//������ջ
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		int newCapacity = (ps->capacity == 0) ? 4 : ps->capacity * 2;
		ps->a = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (ps->a == NULL)
		{
			cout << "����ʧ��" << endl;
			return;
		}
		ps->capacity = newCapacity;
	}

	ps->a[ps->top] = x;
	ps->top++;
}

//ɾ��ջ������
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

//����ջ������
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

//����ջ���ж�������
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

//�ж��Ƿ�Ϊ��(Ϊ�շ���true,��Ϊ�շ���false��
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}



//ƥ��������Ŀ(typedef char)
bool isValid(string s)
{
	ST st;
	StackInit(&st);
	int i = 0;
	while (s[i])
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			StackPush(&st, s[i]);
		}
		else
		{
			//�����������ˣ�����ջ����û�����ݣ�
			// ˵��ǰ��û�������ţ���ƥ�䣬����false
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}
			STDataType top = StackTop(&st);
			StackPop(&st);
			if ((s[i] == ')' && top != '(') || (s[i] == ']' && top != '[') || (s[i] == '}' && top != '{'))
			{
				StackDestroy(&st);
				return false;
			}
		}
		i++;
	}
	// ���ջ���ǿգ�˵��ջ�л�������δ��
	// û��ƥ�䷵��false
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}




void TestStack()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	//ȡ������
	while (!StackEmpty(&st))
	{
		cout << StackTop(&st) << endl;
		StackPop(&st);
	}


	StackDestroy(&st);	//�ͷſռ�
}



int main()
{

	//TestStack();
	string s;
	cin >> s;
	cout << isValid(s);
	return 0;
}