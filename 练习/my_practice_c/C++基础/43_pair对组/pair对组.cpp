#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


void test1()
{

	//����1
	pair<int, int> p1(10, 20);
	cout << p1.first << " " << p1.second << endl;

	//����2
	pair<int, string> p2 = make_pair(100, "��ɵ��");
	cout << p2.first << " " << p2.second << endl;

	pair<int, string> p3 = p2;

}





int main()
{
	test1();






	return 0;
}