#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//���ࣨ���ࣩ��������ࣩ
class Student
{
public:
	Student(int id, string name)
	{
		this->id = id;
		//string �Ѿ����������
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
//ͨ���̳�
//����һ���µ�ѧ���࣬����score����
//���ࣨ�����ࣩ
class Student2 :public Student
{
public:
	//����Ķ�����Ҫ���ø���ĺ���
	//������͸���Ŀռ��Ƕ����ģ�����ռ�ȸ���ռ�ÿռ��
	Student2(int id, string name, int score) :Student(id, name)
	{//�����д�вι��죬��ô���Զ������޲ι���
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