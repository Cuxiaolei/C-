#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


class Teacher
{
public:
	Teacher(int id, const char* name)
	{
		m_id = id;
		m_name = (char*)malloc(strlen(name) + 1);
		strcpy(m_name, name);
	}
	//手动写的拷贝构造函数
	Teacher(const Teacher& another)
	{
		m_id = another.m_id;
		m_name = (char*)malloc(strlen(another.m_name) + 1);
		strcpy(m_name, another.m_name);
	}
	void print()
	{
		cout << m_id << m_name << endl;
	}

	~Teacher()
	{
		cout << "~Teacher" << endl;
		if (m_name != NULL)
		{
			free(m_name);
			cout << "free success" << endl;
		}
	}
private:
	int m_id;
	char* m_name;
};

void test()
{
	Teacher t1(1, "zhangsan");
	t1.print();

	//存在指针的话需要手动提供一个拷贝函数
	//防止访问非法空间，

	//此时拷贝的t1,t2中的m_name指向的是同一块空间，
	//当其中一个销毁的话，另一个就会非法访问空间
	Teacher t2(t1);
	t2.print();
}

int main()
{
	test();



	return 0;
}