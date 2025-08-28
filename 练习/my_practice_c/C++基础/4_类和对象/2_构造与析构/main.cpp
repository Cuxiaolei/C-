#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Test
{
public:
	//如果不写构造函数，系统自动提供一个无参空函数
	//如果写了有参构造函数，默认函数就不复存在，则定义时必须提供参数
	//默认构造函数（空）
#if 0
	Test()
	{

	}
#endif
	Test(int x, int y)
	{
		x0 = x;
		y0 = y;
		name = (char*)malloc(100);
		strcpy(name, "zhangcan");
	}
	//析构函数和构造函数都没有返回值
	//析构函数没有形参
	//在一个对象临死前自动调用析构函数
	//用于防止内存泄露
	//默认的析构函数（空的）
#if 0
	~test()
	{

	}
#endif

	~Test()
	{
		cout << "~Test()....." << endl;
		if (name != NULL)
		{
			free(name);
		}
		cout << "已销毁name的空间" << endl;
	}
private:
	int x0;
	int y0;
	char* name;
};
//构造与析构
void test8()
{
	Test t(10, 20);
}


int main()
{
	test8();
	return 0;
}