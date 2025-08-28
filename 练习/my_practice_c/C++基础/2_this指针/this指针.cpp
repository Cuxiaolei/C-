#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;




class Test
{
public:
	Test(int k)
	{
		m_k = k;
	}
	int getK() const//如果想要修饰this指针，可以在函数尾部加const
	{
		//this接收传入的Test类指针
		//如果不用const修饰，可以修改，this是一个常量指针
		// 如果用const修饰，则不能修改
		//this->m_k = 100;
		return this->m_k;
	}
#if 0
	static int s_getK()
	{
		//报错:this只能用于非静态成员函数内部
		return this->s_k;
	}
#endif
private:
	int m_k;
	static int s_k;
};
int Test::s_k = 0;






int main()
{
	Test t1(10);

	//t1.getK()实际上是将t1的地址传入getK()，默认由this接收
	cout << t1.getK() << endl;


	return 0;
}