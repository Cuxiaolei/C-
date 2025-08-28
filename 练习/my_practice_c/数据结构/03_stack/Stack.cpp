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

//初始化
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

//释放空间
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

//数据入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		int newCapacity = (ps->capacity == 0) ? 4 : ps->capacity * 2;
		ps->a = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (ps->a == NULL)
		{
			cout << "增容失败" << endl;
			return;
		}
		ps->capacity = newCapacity;
	}

	ps->a[ps->top] = x;
	ps->top++;
}

//删除栈顶数据
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

//返回栈顶数据
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

//返回栈内有多少数据
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

//判断是否为空(为空返回true,不为空返回false）
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}



//匹配括号题目(typedef char)
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
			//遇到右括号了，但是栈里面没有数据，
			// 说明前面没有左括号，不匹配，返回false
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
	// 如果栈不是空，说明栈中还有括号未出
	// 没有匹配返回false
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

	//取出数据
	while (!StackEmpty(&st))
	{
		cout << StackTop(&st) << endl;
		StackPop(&st);
	}


	StackDestroy(&st);	//释放空间
}



int main()
{

	//TestStack();
	string s;
	cin >> s;
	cout << isValid(s);
	return 0;
}