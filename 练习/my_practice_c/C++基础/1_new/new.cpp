#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


//C语言中
//malloc和free()
void test1()
{
	int* p = (int*)malloc(sizeof(int));
	*p = 10;
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}


	//C语言开辟数组空间
	int* arr = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
		printf("%d ", arr[i]);
	}
	if (arr != NULL)
	{
		free(arr);	//在malloc的空间可以使用delete；
		//delete[] arr;
		arr = NULL;
	}
	cout << endl;

}


//C++中
//new和delete
void test2()
{
	//new是关键字，而malloc是函数
	int* p = new int;
	*p = 10;
	if (p != NULL)
	{
		delete p;
		p = NULL;
	}

	//开辟一个空间并初始化
	int* arr0 = new int(10);//等价于int a = 10;

	//开辟多个空间
	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
		cout << arr[i] << " ";
	}
	cout << endl;

	if (arr != NULL)
	{
		delete[] arr;//固定语法，表示释放多个空间；
		//free(arr);	//new开辟的空间也可以用free
						//说明delete和free处理方法相同
						//不同的是delete是关键字，而free()是函数避免不了函数压栈;
	}
}


class Test
{
public:
	Test(int a, int b) :m_a(a), m_b(b)
	{

	}
	void print()
	{
		cout << m_a << " " << m_b << endl;
	}

	~Test()
	{
		cout << "~Test" << endl;
	}
private:
	int m_a;
	int m_b;
};


void test3()
{
	Test* t = (Test*)malloc(sizeof(Test));//开辟空间之后如果不销毁不会触发析构
	//(*t)(10, 20);//该语法错误
	t->print();//打印出任意值

	if (t != NULL)
	{
		free(t);//free()在释放时并不会触发析构（如果有额外开辟的空间没有通过析构函数释放，则会造成内存泄漏）；
		t = NULL;
	}
}


void test4()
{
	//new可以在开辟空间是调用构造函数，而malloc（）不能
	Test* t1 = new Test(10, 20);//开辟空间之后如果不销毁不会触发析构
	t1->print();

	if (t1 != NULL)
	{
		delete t1;//delete在释放时会触发析构（析构函数 负责释放类里面额外开辟的空间）
		t1 = NULL;
	}
}



int main()
{
	test1();

	test2();

	test3();

	test4();

	return 0;


}