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

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(rand() % 10);
	}

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	PrintVector(v1);
	PrintVector(v2);

	//swap
	vector<int> v3;
	for (int i = 0; i < 10; i++)
	{
		v3.push_back(rand() % 10);
	}
	PrintVector(v3);
	swap(v3, v2);//交换
	cout << "交换之后" << endl;
	PrintVector(v2);
	PrintVector(v3);
}
class Myconpare2
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test2()
{
	vector<int> v1;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(rand() % 10);
	}
	PrintVector(v1);

	replace(v1.begin(), v1.end(), 5, 100);
	PrintVector(v1);
	
	replace_if(v1.begin(), v1.end(), Myconpare2(),200);//把符合条件的进行替换
	PrintVector(v1);
}

int main()
{
	srand((unsigned int)time(NULL));

	test2();
#if 0
	test1();
	test3();
	test4();
	test5();
#endif






	return 0;


}