#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//父类（基类）（和树差不多）
class Student
{
public:
	Student(int id, string name)
	{
		this->id = id;
		//string 已经有深拷贝函数
		this->name = name;
	}

	void printS()
	{
		cout << "id = " << this->id << ",name = " << this->name << endl;
	}
private:
	int id;
	string name;
};
//通过继承
//创建一个新的学生类，增加score功能
//子类（派生类）
class Student2 :public Student
{
public:
	//父类的东西需要调用父类的函数
	//但子类和父类的空间是独立的，子类空间比父类占用空间大
	Student2(int id, string name, int score) :Student(id, name)
	{//如果不写有参构造，那么会自动调用无参构造
		this->score = score;
	}

	void printS()
	{
		Student::printS();
		cout << "score = " << this->score << endl;
	}
private:
	int score;

};


int main()
{

	Student2 s2(1, "zhang3", 80);
	 s2.printS();
	





	return 0;
}