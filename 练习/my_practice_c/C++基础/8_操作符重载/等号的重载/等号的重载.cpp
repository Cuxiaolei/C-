#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



class Student
{
public:
	Student()
	{
		this->id = 0;
		this->name = NULL;
	}
	Student(int id, const char* name)
	{
		this->id = id;
		int len = (int)strlen(name);
		this->name = new char[len + 1];
		strcpy(this->name, name);
	}
	Student(const Student& another)
	{
		this->id = another.id;
		int len = (int)strlen(another.name);
		this->name = new char[len + 1];
		strcpy(this->name,another.name);
	}

	void printS() 
	{
		cout << this->name << endl;
	}
	Student& operator=(const Student& another)
	{
		//防止自身赋值
		if (this == &another)
		{
			return *this;
		}

		//先将自身额外开辟的空间回收掉
		if (this->name != NULL)
		{
			delete[]this->name;
			this->name = NULL;
			this->id = 0;
		}

		//执行深拷贝
		this->id = another.id;
		int len = strlen(another.name);
		this->name = new char[len + 1];
		strcpy(this->name, another.name);
		return *this;
	}


	~Student()
	{
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
			this->id = 0;
		}
	}
private:
	int id;
	char* name;
};


int main()
{
	Student s1(1, "zhangsan");
	Student s2(s1);
	s2.printS();
	Student s3(34, "li4");
	s3.printS();
	//重载的等号
	s3 = s2;
	s3.printS();


	return 0;
}