#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


void test1()
{

	//构造1
	pair<int, int> p1(10, 20);
	cout << p1.first << " " << p1.second << endl;

	//构造2
	pair<int, string> p2 = make_pair(100, "大傻逼");
	cout << p2.first << " " << p2.second << endl;

	pair<int, string> p3 = p2;

}





int main()
{
	test1();






	return 0;
}