#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


void EmptyRet(pair<map<int, int>::iterator, bool> ret)
{
	if (ret.second)//����value����Ϊsecond��λ����bool����,��ʵ���Ǹ���keyֵ�Ƿ�������жϵ�
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}
}
//��ʼ��
void test1()
{
	//map����ģ����� ��һ��key������,�ڶ���value����
	//����key��������,key�������
	//��ֵ�����޸ģ�ʵֵ�����޸�
	
	map<int, int> mymap;
	   
	//�������� pair.first keyֵ piar.second vlaueֵ

#if 0
	//�������keyֵ��ͬ�Ļ�ֻ������һ�γ��ֵ�key��ֵ�Ķ���
	mymap.insert(pair<int, int>(10, 10));	//1 ����������Ž�ȥ
	mymap.insert(make_pair(20, 40));		//2 ����make_pair����pairl����
	mymap.insert(map<int, int>::value_type(30, 30));//3
	mymap[40] = 400;	//40Ϊ��ֵ��400Ϊʵֵ
#endif
	pair<map<int, int>::iterator, bool> ret;
	ret = mymap.insert(pair<int, int>(10, 10));				//1 ����������Ž�ȥ
	ret = mymap.insert(make_pair(20, 40));					//2 ����make_pair����pairl����
	ret = mymap.insert(map<int, int>::value_type(30, 30));	//3
	ret = mymap.insert(make_pair(20, 5000));
	//����key��ȵ�ֵ�����ж�
	EmptyRet(ret);
	mymap[40] = 400;	//40Ϊ��ֵ��400Ϊʵֵ
	mymap[40] = 1000;   
	// �������key�����ڣ�����pair���뵽map������
	// ���key���ڣ����޸ĸ�λ�õ�valueֵ
	//���ͨ��[] ��ʽȥ����map�в����ڵ�keyֵ
	// ��ômap�Ὣ������ʵ�key���뵽map�У�����һ��Ĭ�ϵ�valueֵ
	cout << mymap[60] << endl;//���valueֵ��Ĭ��Ϊ0
	// ��ӡ
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

//�����������������������keyֵ
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