#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


//C������
//malloc��free()
void test1()
{
	int* p = (int*)malloc(sizeof(int));
	*p = 10;
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}


	//C���Կ�������ռ�
	int* arr = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
		printf("%d ", arr[i]);
	}
	if (arr != NULL)
	{
		free(arr);	//��malloc�Ŀռ����ʹ��delete��
		//delete[] arr;
		arr = NULL;
	}
	cout << endl;

}


//C++��
//new��delete
void test2()
{
	//new�ǹؼ��֣���malloc�Ǻ���
	int* p = new int;
	*p = 10;
	if (p != NULL)
	{
		delete p;
		p = NULL;
	}

	//����һ���ռ䲢��ʼ��
	int* arr0 = new int(10);//�ȼ���int a = 10;

	//���ٶ���ռ�
	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
		cout << arr[i] << " ";
	}
	cout << endl;

	if (arr != NULL)
	{
		delete[] arr;//�̶��﷨����ʾ�ͷŶ���ռ䣻
		//free(arr);	//new���ٵĿռ�Ҳ������free
						//˵��delete��free��������ͬ
						//��ͬ����delete�ǹؼ��֣���free()�Ǻ������ⲻ�˺���ѹջ;
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
	Test* t = (Test*)malloc(sizeof(Test));//���ٿռ�֮����������ٲ��ᴥ������
	//(*t)(10, 20);//���﷨����
	t->print();//��ӡ������ֵ

	if (t != NULL)
	{
		free(t);//free()���ͷ�ʱ�����ᴥ������������ж��⿪�ٵĿռ�û��ͨ�����������ͷţ��������ڴ�й©����
		t = NULL;
	}
}


void test4()
{
	//new�����ڿ��ٿռ��ǵ��ù��캯������malloc��������
	Test* t1 = new Test(10, 20);//���ٿռ�֮����������ٲ��ᴥ������
	t1->print();

	if (t1 != NULL)
	{
		delete t1;//delete���ͷ�ʱ�ᴥ���������������� �����ͷ���������⿪�ٵĿռ䣩
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