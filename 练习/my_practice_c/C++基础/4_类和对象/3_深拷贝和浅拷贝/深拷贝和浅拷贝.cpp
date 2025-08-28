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
	//�ֶ�д�Ŀ������캯��
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

	//����ָ��Ļ���Ҫ�ֶ��ṩһ����������
	//��ֹ���ʷǷ��ռ䣬

	//��ʱ������t1,t2�е�m_nameָ�����ͬһ��ռ䣬
	//������һ�����ٵĻ�����һ���ͻ�Ƿ����ʿռ�
	Teacher t2(t1);
	t2.print();
}

int main()
{
	test();



	return 0;
}