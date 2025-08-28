#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


void EmptyRet(pair<map<int, int>::iterator, bool> ret)
{
	if (ret.second)//返回value是因为second的位置是bool类型,但实际是根据key值是否相等来判断的
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}
}
//初始化
void test1()
{
	//map容器模板参数 第一个key的类型,第二个value类型
	//根据key进行排序,key不能相等
	//键值不可修改，实值可以修改
	
	map<int, int> mymap;
	   
	//插入数据 pair.first key值 piar.second vlaue值

#if 0
	//如果出现key值相同的话只会插入第一次出现的key的值的对象
	mymap.insert(pair<int, int>(10, 10));	//1 把匿名对象放进去
	mymap.insert(make_pair(20, 40));		//2 利用make_pair返回pairl类型
	mymap.insert(map<int, int>::value_type(30, 30));//3
	mymap[40] = 400;	//40为键值，400为实值
#endif
	pair<map<int, int>::iterator, bool> ret;
	ret = mymap.insert(pair<int, int>(10, 10));				//1 把匿名对象放进去
	ret = mymap.insert(make_pair(20, 40));					//2 利用make_pair返回pairl类型
	ret = mymap.insert(map<int, int>::value_type(30, 30));	//3
	ret = mymap.insert(make_pair(20, 5000));
	//出现key相等的值进行判断
	EmptyRet(ret);
	mymap[40] = 400;	//40为键值，400为实值
	mymap[40] = 1000;   
	// 发现如果key不存在，创建pair插入到map容器中
	// 如果key存在，则修改该位置的value值
	//如果通过[] 方式去访问map中不存在的key值
	// 那么map会将这个访问的key插入到map中，并给一个默认的value值
	cout << mymap[60] << endl;//输出value值，默认为0
	// 打印
	for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}


class MyKey
{
public:
	MyKey(int index, int id)
	{
		this->mIndex = index;
		this->mID = id;
	}
public:
	int mIndex;
	int mID;
};

class mycompare
{
public:
	bool operator()(MyKey key1, MyKey key2)const
	{
		return key1.mIndex > key2.mIndex;
	}
};

//由类中数据排序，在类中添加key值
void test2()
{
	map<MyKey, int ,mycompare> mymap;
	mymap.insert(make_pair(MyKey(1, 2), 10));
	mymap.insert(make_pair(MyKey(4, 5), 20));

	for (map<MyKey, int, mycompare>::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		cout << it->first.mID << " " << it->second << endl;
	}

	
}


int main()
{
	//test1();
	test2();



	return 0;
}