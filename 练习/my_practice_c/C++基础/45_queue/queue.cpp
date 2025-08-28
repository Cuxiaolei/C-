#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


void test1()
{
	queue<int> q1;

	q1.push(10);
	q1.push(20);
	q1.push(30);
	q1.push(40);
	cout << q1.back() << " ";//¶ÓÎ²ÔªËØ
	while (!q1.empty())
	{
		cout << q1.front() << " ";

		q1.pop();
	}


}



int main()
{
	test1();





	return 0;
}