#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



void PrintList(list<int> l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//��ʼ��
void test1()
{
	list<int> l1;
	list<int> l2(10, 9);//�вι���  ʮ��9
	list<int> l3(l2);//��������
	list<int> l4(l3.begin(), l3.end());
	PrintList(l4);
}
//����ɾ��
void test2()
{
	list<int> l1;
	l1.push_back(100);//β��
	l1.push_front(200);//ͷ��

	l1.insert(l1.begin(), 300);//ͷ��
	l1.insert(l1.end(), 300);//β��

	list<int>::iterator it = l1.begin();
	it++;
	it++;
	l1.insert(it, 500);
	//���Ϊ���뵽 ����֮�� ���±�λ��
	PrintList(l1);
	list<int> l2(l1);

	//ɾ��
	l1.pop_back();
	l1.pop_front();
	l1.clear();//ɾ��ȫ��
	PrintList(l1);
	l1.erase(l1.begin(), l1.end());
	PrintList(l1);
	l2.remove(300);//ɾ������ƥ��ֵ
	PrintList(l2);

	//����Ԫ�ط�ת
	l2.reverse();
	PrintList(l2);
}

void test3()
{
	list<int> l;
	l.assign(10, 10);//�͹���һ��

	list<int> l2;
	l2 = l;
	l2.swap(l);
}

//����
void test4()
{
	list<int> l1;
}

bool myCompare(int v1, int v2)
{
	return v1 > v2;
}
void test5()
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(15);
	l1.push_back(14);
	l1.push_back(16);
	l1.push_back(12);
	l1.push_back(188);
	l1.push_back(134);

	PrintList(l1);
	l1.sort();//Ĭ�ϴ�С����
	PrintList(l1);
	//�Ӵ�С
	l1.sort(myCompare);//���bool����
	PrintList(l1);
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	//test5();


	return 0;
}