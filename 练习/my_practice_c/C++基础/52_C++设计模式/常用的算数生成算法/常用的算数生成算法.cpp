#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


void PrintVector(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(rand() % 10);
	}
	PrintVector(v1);
	//相加
	int ret = accumulate(v1.begin(), v1.end(), 10);
	cout << "ret:" << ret << endl;

	//将值换为22
	fill(v1.begin(), v1.end(),22);
	PrintVector(v1);


}


int main()
{

	srand((unsigned int)time(NULL));
	test1();
#if 0
	test2();
	test3();
	test4();
	test5();
#endif



	return 0;
}