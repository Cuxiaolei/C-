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
		//�����ڴ�
		this->pAddr = new T[this->mcapacity];
	}

	MyArray(const MyArray& arr)
	{
		this->msize = arr.msize;
		this->mcapacity = arr.mcapacity;

		//�����ڴ�ռ�
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

		//�����ڴ�ռ�
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
		//�ж������Ƿ���λ��
		if (this->msize >= this->mcapacity)
		{
			return;
		}
		//���ÿ������� =�Ų�����
		//1. ����Ԫ�ر����ܹ�����
		//2. ��������ֵԢ�⣬��������Ԣ�� �������з���Ԫ�أ����Ƿ���Ԫ�صĿ�����
		//3. ���Ԫ�صĳ�Ա��ָ�룬ע�������ǳ��������
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
	//���Բ�����ֵ
	template<class T>
	void PushBack(T&& data)
	{
		//�ж������Ƿ���λ��
		if (this->msize >= this->mcapacity)
		{
			return;
		}
		this->pAddr[this->msize] = data;
		this->msize++;
	}
#endif
private:
	//����
	int mcapacity;
	//��ǰ�ռ�
	int msize;
	//�������ݵ��׵�ַ
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
//Ҳ������ģ���з�����
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