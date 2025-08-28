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
	vector<int> v1;//默认构造
	int arr[] = { 10,20,30,49 };
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));//起始迭代器
	vector<int> v3(v2.begin(), v2.end());//起始迭代器
	vector<int> v4(v3);//拷贝构造

#if 0
	//算法实现遍历
	for (vector<int>::iterator it = v4.begin(); it != v4.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
#endif

	PrintVector(v1);//为空
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);
}


//vector成员的初始化
void test2()
{
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));//默认构造

	//成员方法初始化assign(v.begin(),v.end())
	vector<int> v2;
	v2.assign(v1.begin(), v1.end());

	//重载=
	vector<int> v3;
	v3 = v2;

	int arr1[] = { 100,42353,2342,324634 };
	vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));
	v4.swap(v1);//交换两个容器的值

	PrintVector(v1);
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);
}

//vector大小操作
void test3()
{
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));//默认构造

	cout << "size:" << v1.size() << endl;
	if (v1.empty())//返回ture（为空）或false（不为空）
	{
		cout << "容器为空" << endl;
	}
	else {
		cout << "容器不为空" << endl;
	}
	PrintVector(v1);
	v1.resize(2);//改变容器大小，把多余的值扔出去
	PrintVector(v1);
	v1.resize(6);//如果超出容器值的范围，默认补为0
	PrintVector(v1);
	v1.resize(10, 1);//超出时补1,但之前补的0还存在
	PrintVector(v1);

	for (int i = 0; i < 1000; i++)
	{
		v1.push_back(i);
	}

	cout << v1.capacity() << endl;//容器的容量1234  容量扩充时不是一个一个扩充的
	cout << v1.size() << endl;		//元素个数1010
}


void test4()
{
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));//默认构造
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//at内置函数
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
	//区别，at会抛异常，[]不抛异常
	cout << "front:" << v1.front() << endl;//首个元素
	cout << "back:" << v1.back() << endl;//最后一个元素
}

//插入和删除
void test5()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	PrintVector(v);
	v.insert(v.begin(), 1000);//头插
	v.insert(v.end(), 99999);//尾插，相当于push_back()
	PrintVector(v);

	v.insert(v.begin() + 2, 100);//vector支持随机访问//插到第三个位置
	//支持数组下标
	//迭代器也可以进行加减位置
	PrintVector(v);

	//删除
	v.erase(v.begin());//头删
	PrintVector(v);
	v.erase(v.begin() + 1, v.end());//删除某个位置到某个位置
	PrintVector(v);
	v.clear();//清空容器
	cout << v. size() << endl;//清空后为0
	cout << v.capacity() << endl;//但容器的容量还不变，为6
}

//巧用swap()缩减空间

void test6()
{
	//vector添加元素 他会自动增长 你删除元素时，会减少吗
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

	//收缩空间
	vector<int>(v).swap(v);//先初始化匿名对象，再与v进行交换

	cout << "_________________________" << endl;
	cout << "size:" << v.size() << endl;//10
	cout << "capacity:" << v.capacity() << endl;//10

}

//reserve  resize 区别
void test7()
{
	//reserve 预留空间
	
	int num = 0;
	int* address = NULL;
	vector<int> v;
	v.reserve(100000);//提前申请预留空间
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (address != &(v[0]))//当前首地址不等于增加元素后的首地址时，认为容器扩充了一次
		{
			address = &(v[0]);
			num++;
		}
	}
	num--;
	cout << num << endl;//30次
						//0次

	//如果你知道容器大概需要多大容量，可以使用reserve()预留空间，减少扩充次数
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