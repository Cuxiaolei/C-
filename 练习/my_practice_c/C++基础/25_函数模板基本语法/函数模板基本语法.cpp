#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


//模板技术 类型参数化 编写代码可以忽略类型
//为了让编译器区分是普通函数 还是 模板函数

//告诉编译器 我下面写模板函数，看到奇怪的不要报错了
//且是一次性的
template<class T> // template<typename T> 
void MySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


int main()
{
	double a = 10;
	double b = 20;
	MySwap(a, b);//编译器根据你传的值 进行类型自动推导
	cout << a << b;

	//显式的制定类型
	MySwap<double>(a, b);

	return 0;
}