#include "Mystring.h"

void test1()
{
	Mystring s1("asdasdasd");
	Mystring s2 = s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s1[3] << endl;

	Mystring s3 = "12345";
	cout << s3 << endl;

	s3 = s2;
	cout << s3 << endl;

	cout << "请输入一个字符串:";
	cin >> s3;
	cout << s3 << endl;

	Mystring s4;
	cout << "请输入一个字符串:";
	cin >> s4;
	cout << s4 << endl;

	s4 = s3 + s4 + s1 + s2;
	cout << s4 << endl;
}


int main()
{
#if 0
	//string已包装好的类在头文件中
	string s1 = "123";
	string s2 = "aasd";
	//表明string类里面已经有+的重载
	cout << s1 + s2 << endl;
#endif
	test1();

	return 0;
}