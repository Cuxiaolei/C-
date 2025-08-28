#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>
using namespace std;

namespace spaceA
{
	int a = 11;
	int b = 20;

}

namespace spaceB
{
	int a = 12;
	int b = 22;
	namespace spaceC
	{
		int c = 13;
		int b = 33;
	}
}

void test1()
{
	using namespace spaceB::spaceC;
	cout << b << endl;
}

void test2()
{
	int a = 10;
	int& re = a;
	re = 20;
	cout << a << endl;
}


typedef struct teacher
{
	int a;
	char b[100];
}teacher;

void add_teacher(teacher*& p)
{
	p = (teacher*)malloc(sizeof(teacher));
	p->a = 100;
	strcpy(p->b, "libai");

}

void free_teacher(teacher*& p)
{
	if (p == NULL)
	{
		return;
	}
	free(p);
}

void test3()
{
	teacher* t = NULL;

	add_teacher(t);

	cout << t->a << ",,," << t->b << endl;

	free_teacher(t);
}

inline void printab1(int a, int b)
{
	for (int i = 0; i < 2; i++)
	{
		a++;
		b++;
	}

}
void printab2(int a, int b)
{
	for (int i = 0; i < 2; i++)
	{
		a++;
		b++;
	}

}

void test4()
{
	int a = 1;
	int b = 2;

	int begin1 = clock();
	for (int i = 0; i < 1000000000; i++)
	{
		a++;
		b++;
		printab1(a, b);
	}
	int end1 = clock();
	cout << "inline时间" << end1 - begin1 << endl;


	int begin2 = clock();
	for (int i = 0; i < 1000000000; i++)
	{
		a++;
		b++;
		printab2(a, b);
	}
	int end2 = clock();

	cout << "非inline时间" << end2 - begin2 << endl;
}


void func(int a, int b)
{
	cout << a << b << endl;
}

void func(int a)
{
	cout << a << endl;
}

void test5()
{
	int a = 10;
	int b = 20;
	func(a, b);
	func(a);

}


class Advhero
{
public://访问权限
	char name[100];
	int sex;
	void printadv()
	{
		cout << "advhero" << endl;
		cout << name << endl;
		cout << sex << endl;
	}


private:

	char name1[100];
	int sex1;


	void printadv1()
	{
		cout << "advhero1" << endl;
		cout << name1 << endl;
		cout << sex1 << endl;
	}


};

void test6()
{
	Advhero adv;
	strcpy(adv.name, "asd");
	adv.sex = 10;
	adv.printadv();
}


typedef class Mydate
{
public:
	void init_data()
	{
		cout << "请输入" << endl;
		cin >> year;
	}

	void print_data()
	{
		cout << year << "年";
	}

	void is_leap_year()
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			cout << "是闰年" << endl;
		}
		else
		{
			cout << "不是闰年" << endl;
		}
	}

	int get_year()
	{
		return year;
	}
protected://保护控制权限，在类的继承中和private有区别



private:
	int year;
}Mydate;
void test7()
{
	Mydate d;
	d.init_data();
	d.print_data();
	d.is_leap_year();
	cout << d.get_year() << endl;
}





int main(void)
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
}