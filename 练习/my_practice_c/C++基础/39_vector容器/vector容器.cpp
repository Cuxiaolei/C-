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
	vector<int> v1;//Ĭ�Ϲ���
	int arr[] = { 10,20,30,49 };
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));//��ʼ������
	vector<int> v3(v2.begin(), v2.end());//��ʼ������
	vector<int> v4(v3);//��������

#if 0
	//�㷨ʵ�ֱ���
	for (vector<int>::iterator it = v4.begin(); it != v4.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
#endif

	PrintVector(v1);//Ϊ��
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);
}


//vector��Ա�ĳ�ʼ��
void test2()
{
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));//Ĭ�Ϲ���

	//��Ա������ʼ��assign(v.begin(),v.end())
	vector<int> v2;
	v2.assign(v1.begin(), v1.end());

	//����=
	vector<int> v3;
	v3 = v2;

	int arr1[] = { 100,42353,2342,324634 };
	vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));
	v4.swap(v1);//��������������ֵ

	PrintVector(v1);
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);
}

//vector��С����
void test3()
{
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));//Ĭ�Ϲ���

	cout << "size:" << v1.size() << endl;
	if (v1.empty())//����ture��Ϊ�գ���false����Ϊ�գ�
	{
		cout << "����Ϊ��" << endl;
	}
	else {
		cout << "������Ϊ��" << endl;
	}
	PrintVector(v1);
	v1.resize(2);//�ı�������С���Ѷ����ֵ�ӳ�ȥ
	PrintVector(v1);
	v1.resize(6);//�����������ֵ�ķ�Χ��Ĭ�ϲ�Ϊ0
	PrintVector(v1);
	v1.resize(10, 1);//����ʱ��1,��֮ǰ����0������
	PrintVector(v1);

	for (int i = 0; i < 1000; i++)
	{
		v1.push_back(i);
	}

	cout << v1.capacity() << endl;//����������1234  ��������ʱ����һ��һ�������
	cout << v1.size() << endl;		//Ԫ�ظ���1010
}


void test4()
{
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));//Ĭ�Ϲ���
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//at���ú���
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
	//����at�����쳣��[]�����쳣
	cout << "front:" << v1.front() << endl;//�׸�Ԫ��
	cout << "back:" << v1.back() << endl;//���һ��Ԫ��
}

//�����ɾ��
void test5()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	PrintVector(v);
	v.insert(v.begin(), 1000);//ͷ��
	v.insert(v.end(), 99999);//β�壬�൱��push_back()
	PrintVector(v);

	v.insert(v.begin() + 2, 100);//vector֧���������//�嵽������λ��
	//֧�������±�
	//������Ҳ���Խ��мӼ�λ��
	PrintVector(v);

	//ɾ��
	v.erase(v.begin());//ͷɾ
	PrintVector(v);
	v.erase(v.begin() + 1, v.end());//ɾ��ĳ��λ�õ�ĳ��λ��
	PrintVector(v);
	v.clear();//�������
	cout << v. size() << endl;//��պ�Ϊ0
	cout << v.capacity() << endl;//�����������������䣬Ϊ6
}

//����swap()�����ռ�

void test6()
{
	//vector���Ԫ�� �����Զ����� ��ɾ��Ԫ��ʱ���������
	vector<int> v;
	for(int i = 0; i < 10000; i++)
	{
		v.push_back(i);
	}

	cout << "size:" << v.size() << endl;//10000
	cout << "capacity:" << v.capacity() << endl;//12138

	v.resize(10);
	cout << "_________________________" << endl;
	cout << "size:" << v.size() << endl;//10
	cout << "capacity:" << v.capacity() << endl;//12138

	//�����ռ�
	vector<int>(v).swap(v);//�ȳ�ʼ��������������v���н���

	cout << "_________________________" << endl;
	cout << "size:" << v.size() << endl;//10
	cout << "capacity:" << v.capacity() << endl;//10

}

//reserve  resize ����
void test7()
{
	//reserve Ԥ���ռ�
	
	int num = 0;
	int* address = NULL;
	vector<int> v;
	v.reserve(100000);//��ǰ����Ԥ���ռ�
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (address != &(v[0]))//��ǰ�׵�ַ����������Ԫ�غ���׵�ַʱ����Ϊ����������һ��
		{
			address = &(v[0]);
			num++;
		}
	}
	num--;
	cout << num << endl;//30��
						//0��

	//�����֪�����������Ҫ�������������ʹ��reserve()Ԥ���ռ䣬�����������
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();


	return 0;
}