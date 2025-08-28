#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
 

//家具类(父类)
class Furniture
{
public:
	int m;//材质
};

//儿子类
//将儿子类继承父亲类 该成虚继承，防止孙子在多继承儿子类的时候，出现父类中的变量拷贝多份而造成不明确
class Bed :virtual public Furniture
{
public:
	void sleep()
	{
		cout << "床上睡觉" << endl; 
	}
};

//儿子类
class Sofa :virtual public Furniture
{
public:
	void sit()
	{
		cout << "在沙发上休息" << endl;
	}
};

//沙发床(多继承）//孙子类
class SofaBed :public Bed, public Sofa
{
public:
	void SleepAndSit()
	{
		Bed::sleep();
		Sofa::sit();
	}
};


int main()
{
	Bed b;
	b.sleep();

	Sofa s;
	s.sit();

	SofaBed sb;
	sb.sit();
	sb.sleep();
	sb.SleepAndSit();


	//s继承一个m, b继承一个m, 所以sb中有2个m
	//sb.m = 100;//m不明确
#if 0
	//可以通过作用域访问
	sb.Bed::m = 100;
	sb.Sofa::m = 100;
#endif
	//可以在儿子类（s,b)上加virtual
	//此时可以
	sb.m = 100;//即sb中的单独的m
	return 0;
}