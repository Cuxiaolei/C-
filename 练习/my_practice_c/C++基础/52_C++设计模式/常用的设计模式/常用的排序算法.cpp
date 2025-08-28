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
class MyCompare1
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};


void test1()
{
	vector<int> v1;
	vector<int> v2;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(rand() % 10);
	}

	cout << "排序前" << endl;
	PrintVector(v1);
	PrintVector(v2);
	sort(v1.begin(), v1.end(), MyCompare1());
	sort(v2.begin(), v2.end(), MyCompare1());
	cout << "排序后" << endl;
	PrintVector(v1);
	PrintVector(v2);
	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	//进行合并时必须合并两个有序的序列
	//默认是从小到大
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), MyCompare1());

	cout << "合并后" << endl;
	PrintVector(v3);
}

void test2()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);
	//打乱（洗牌）
	random_shuffle(v1.begin(), v1.end());
	PrintVector(v1);
}


//reverse  翻转容器
void test3()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);
	reverse(v1.begin(), v1.end());
	PrintVector(v1);
	
}


int main()
{

	//test1();
	//test2();
	test3();



	return 0;
}