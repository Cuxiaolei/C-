#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

template<class T>
class MyArray
{
public:
	MyArray()
	{

	}
	MyArray(int capacity)
	{
		this->mcapacity = capacity;
		this->msize = 0;
		//申请内存
		this->pAddr = new T[this->mcapacity];
	}

	MyArray(const MyArray& arr)
	{
		this->msize = arr.msize;
		this->mcapacity = arr.mcapacity;

		//申请内存空间
		this->pAddr = new T[this->mcapacity];
		for (int i = 0; i < this->msize; i++)
		{
			this->pAddr[i] = arr.pAddr[i];
		}
	}
	~MyArray()
	{
		if (this->pAddr != NULL)
		{
			delete[] this->pAddr;
		}
	}
	template<class T>
	T& operator[](int index)
	{
		return this->pAddr[index];
	}
	template<class T>
	MyArray<T>& operator=(const MyArray<T>& arr)
	{
		if (this->pAddr != NULL)
		{
			delete[] this->pAddr;
		}
		this->msize = arr.msize;
		this->mcapacity = arr.mcapacity;

		//申请内存空间
		this->pAddr = new T[this->mcapacity];
		for (int i = 0; i < this->msize; i++)
		{
			this->pAddr[i] = arr.pAddr[i];
		} 

		return *this;
	}

	template<class T>
	void PushBack(T& data)
	{
		//判断容器是否有位置
		if (this->msize >= this->mcapacity)
		{
			return;
		}
		//调用拷贝构造 =号操作符
		//1. 对象元素必须能够拷贝
		//2. 容器都是值寓意，而非引用寓意 向容器中放入元素，都是放入元素的拷贝份
		//3. 如果元素的成员有指针，注意深拷贝和浅拷贝问题
		//
		this->pAddr[this->msize] = data;
		this->msize++;
	}

	void show()
	{
		for (int i = 0; i < this->msize; i++)
		{
			cout << this->pAddr[i] << " ";
		}
		cout << endl;
	}
#if 1
	//可以插入右值
	template<class T>
	void PushBack(T&& data)
	{
		//判断容器是否有位置
		if (this->msize >= this->mcapacity)
		{
			return;
		}
		this->pAddr[this->msize] = data;
		this->msize++;
	}
#endif
private:
	//容量
	int mcapacity;
	//当前空间
	int msize;
	//保存数据的首地址
	T* pAddr;
};

void test01()
{
	MyArray<int> marray(20);
	int a = 10; 
	int b = 20; 
	int c = 30;
	marray.PushBack(a);
	marray.PushBack(b); 
	marray.PushBack(c);
	marray.PushBack(590);
	marray.PushBack(6000);
	MyArray<int> arr2(marray);
	arr2.show();
	MyArray<int> arr3;
	marray.show();

	arr3 = arr2;
	arr3.show();

	//cout << arr3[2] << endl;
}

class Person
{

};
//也可以在模板中放入类
void test02()
{
	Person p1, p2;

	MyArray<Person> arr(10);
	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.show();
}

int main()
{
	test01();



	return 0;
}