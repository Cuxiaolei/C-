#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

void test1()
{
	string s1;//�޲ι���
	string s2(10, 'a');//ʮ��λ�ã����ǡ�a'
	string s3("asdfwg");
	string s4(s3);//��������

	cout << s1 << endl;//���ء�<<"������
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}


void test2()
{
	string s1;
	string s2("asdd");
	s1 = "qwetr";
	cout << s1 << endl;
	s1 = s2;
	cout << s1 << endl;
	s1 = 'a';
	cout << s1 << endl;

	//��Ա����
	s1.assign("asfdsasdfasdf");//�͡�=��һ��
	cout << s1 << endl;
}
void test3()
{
	string s1 = "asfad";

	//����[]������
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	//at��Ա����
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1.at(i) << " ";
	}
	cout << endl;

	//����[]��ʽ���������Խ�磬ֱ�ӹҵ�
	//at��ʽ ����Խ�� ���쳣out_of_range

	try
	{
		cout << s1.at(100) << endl;
	}
	catch (...)
	{
		cout << "��Խ����" << endl;
	}
}

//ƴ�Ӳ���
void test4()
{
	string s1 = "abc";
	s1 += "defg";
	string s2 = "123456";
	s1 += s2;
	cout << s1 << endl;

	string s3 = "2222";
	s2.append(s3);//��s3ƴ�ӵ�s2β��
	cout << s2 << endl;

	string s4 = s2 + s3;
	cout << s4 << endl;
}

//����
void test5()
{
	string s1 = "gabcdefgh";
	cout << s1 << endl;

	//���ҵ�һ�γ��ֵ�λ��
	int pos = s1.find("ac");//���ҵ�һ�γ��ֵ�λ�ã����û�ҵ�����-1
	cout << pos << endl;

	//�������һ�γ��ֵ�λ��
	pos = s1.rfind("g");
	cout << pos << endl;

}

//�滻
void test6()
{
	string s = "abcdefgh";
	cout << s << endl;
	s.replace(0, 2, "111");//��aλ�ÿ�ʼ��b���ַ����滻��c
	cout << s << endl;//111cdefgh
}

//�Ƚ�
void test7()
{
	string s1 = "abcd";
	string s2 = "abce";
	if (s1.compare(s2) == 0)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
}

//�Ӵ�����
void test8()
{
	string s = "abcdefgh";
	string s1 = s.substr(1, 4);//����һ���ִ�
	cout << s << endl;
	cout << s1 << endl;
}

void test9()
{
	string s = "abcdefg";
	s.insert(1, "66666");//����ĳ��λ��ǰ��
	cout << s << endl;

	s.erase(0, 2);//��ĳ��λ�ÿ�ʼɾ�������ַ�
	cout << s << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	return 0;
}