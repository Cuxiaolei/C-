
#include "Person.hcpp"


int main()
{
	//使用类模板多文件时就要写在同一个文件，即引用hcpp文件(表示是引用类模板)
	Person<int> p(200);
	p.Show();




	return 0;
}