#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


void test1()
{
	stack<int> s1;
	stack<int> s2(s1);

	//stack����
	s1.push(10);
	s1.push(20);
	s1.push(30);

	s1.push(100);
	cout << "ջ��Ԫ�أ�" << s1.top() << endl;
	s1.pop();
	cout << "ջ��Ԫ�أ�" << s1.top() << endl;

	//��ӡջ��������
	while (!s1.empty())
	{
		cout << s1.top() << " " << endl;
		s1.pop();
	}

}


int main()
{

	test1();




	return 0;
}