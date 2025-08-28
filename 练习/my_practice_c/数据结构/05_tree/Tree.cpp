#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define MY_FaLSE 0
#define MY_TRUE 1

using namespace std;


typedef char BinaryTreeType;

//������
typedef struct BinaryNode
{
	char ch;
	BinaryNode* left;
	BinaryNode* right;
}BinaryNode;
//�ǵݹ����������
typedef struct BinaryTreeStackNode
{
	BinaryNode* root;
	int flag;
}BinaryTreeStackNode;
//ջ
typedef struct Stack
{
	BinaryTreeStackNode* a;
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
void StackPush(ST* ps, BinaryTreeStackNode x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		int newCapacity = (ps->capacity == 0) ? 4 : ps->capacity * 2;
		ps->a = (BinaryTreeStackNode*)realloc(ps->a, sizeof(BinaryTreeStackNode) * newCapacity);
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
BinaryTreeStackNode StackTop(ST* ps)
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













//�������
void BinaryTreeRecursionDLR(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->ch << ' ';
	BinaryTreeRecursionDLR(root->left);
	BinaryTreeRecursionDLR(root->right);
}

//�������
void BinaryTreeRecursionLDR(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeRecursionLDR(root->left);
	cout << root->ch << ' ';
	BinaryTreeRecursionLDR(root->right);
}

//�������
void BinaryTreeRecursionLRD(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeRecursionLRD(root->left);
	BinaryTreeRecursionLRD(root->right);
	cout << root->ch << ' ';
}

//Ҷ�ӵ���Ŀ
int BinaryTreeCaculateLeaf(BinaryNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		return BinaryTreeCaculateLeaf(root->left) + BinaryTreeCaculateLeaf(root->right);
	}
}

//�ڵ����
int BinaryTreeCaculateNode(BinaryNode* root)
{
	return (root == NULL) ? 0 : BinaryTreeCaculateNode(root->left) + BinaryTreeCaculateNode(root->right) + 1;
}

//�������߶�
int BinaryTreeCaculateHigh(BinaryNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = BinaryTreeCaculateHigh(root->left);
	int right = BinaryTreeCaculateHigh(root->right);
	return left > right ? left + 1 : right + 1;
}

//������k��ڵ�ĸ���
int BinaryTreeCaculateKFloor(BinaryNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeCaculateKFloor(root->left, k - 1) + BinaryTreeCaculateKFloor(root->right, k - 1);
}

//����ֵΪx�Ľڵ�
BinaryNode* BinaryTreeFind(BinaryNode* root, BinaryTreeType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->ch == x)
	{
		return root;
	}
	if (BinaryTreeFind(root->left, x) == NULL)
	{
		return BinaryTreeFind(root->right, x);
	}
	else
	{
		return BinaryTreeFind(root->left, x);
	}
}




////�ж϶������Ƿ�����ȫ������
//bool BinaryTreeComplete(BinaryNode* root)
//{
//
//}

//������-ջ�еĽڵ㲢��ʼ��
BinaryTreeStackNode CreatBinaryTreeStackNode(BinaryNode* node, int flag)
{
	BinaryTreeStackNode newnode;
	newnode.root = node;
	newnode.flag = flag;

	return newnode;
}




//�ǵݹ����
void BinaryTreeNonRecursion(BinaryNode* root)
{
	//��������ʼ��ջ
	ST stack;
	StackInit(&stack);
	//�Ѹ��ڵ��ӽ�ջ��
	StackPush(&stack, CreatBinaryTreeStackNode(root, MY_FaLSE));


	while (!StackEmpty(&stack))
	{
		//�ȵ���ջ��Ԫ��
		BinaryTreeStackNode node = StackTop(&stack);
		StackPop(&stack);

		//�жϵ����Ľڵ��Ƿ�Ϊ��
		if (node.root == NULL)
		{
			continue;
		}

		//�жϽڵ�ı�־
		if (node.flag == MY_TRUE)
		{
			cout << node.root->ch << ' ';
		}
		else
		{
			//��ǰ�ڵ��ҽڵ���ջ
			StackPush(&stack, CreatBinaryTreeStackNode(node.root->right, MY_FaLSE));
			//��ǰ�ڵ���ڵ���ջ
			StackPush(&stack, CreatBinaryTreeStackNode(node.root->left, MY_FaLSE));
			//��ǰ�ڵ���ջ
			node.flag = MY_TRUE;
			StackPush(&stack, node);
		}
	}



}




//�ͷŽڵ�
void BinaryTreeFree(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeFree(root->left);
	BinaryTreeFree(root->right);
	free(root);
}

//�������Ŀ���
BinaryNode* CopyBinaryTree(BinaryNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	BinaryNode* left = CopyBinaryTree(root->left);
	BinaryNode* right = CopyBinaryTree(root->right);

	BinaryNode* newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
	newnode->ch = root->ch;
	newnode->left = root->left;
	newnode->right = root->right;
	return newnode;
}

void CreatBinaryTree()
{

	BinaryNode node1 = { 'A',NULL,NULL };
	BinaryNode node2 = { 'B',NULL,NULL };
	BinaryNode node3 = { 'C',NULL,NULL };
	BinaryNode node4 = { 'D',NULL,NULL };
	BinaryNode node5 = { 'E',NULL,NULL };
	BinaryNode node6 = { 'F',NULL,NULL };
	BinaryNode node7 = { 'G',NULL,NULL };
	BinaryNode node8 = { 'H',NULL,NULL };

	node1.left = &node2;
	node1.right = &node6;
	node2.right = &node3;
	node3.left = &node4;
	node3.right = &node5;
	node6.right = &node7;
	node7.left = &node8;

	BinaryTreeRecursionDLR(&node1);
	cout << endl;
	BinaryTreeRecursionLDR(&node1);
	cout << endl;
	BinaryTreeRecursionLRD(&node1);
	cout << endl;


	cout << BinaryTreeCaculateLeaf(&node1) << endl;
	cout << BinaryTreeCaculateNode(&node1) << endl;
	cout << BinaryTreeCaculateHigh(&node1) << endl;
	cout << BinaryTreeCaculateKFloor(&node1, 3) << endl;
	cout << BinaryTreeFind(&node1, 'F')->ch << endl;

	BinaryNode* root = CopyBinaryTree(&node1);
	BinaryTreeRecursionDLR(root);
	cout << endl;
	cout << endl;


	BinaryTreeNonRecursion(&node1);


	//BinaryTreeFree(root);
}


int main()
{
	CreatBinaryTree();

	return 0;
}