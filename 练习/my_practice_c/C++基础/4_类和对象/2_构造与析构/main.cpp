#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Test
{
public:
	//�����д���캯����ϵͳ�Զ��ṩһ���޲οպ���
	//���д���вι��캯����Ĭ�Ϻ����Ͳ������ڣ�����ʱ�����ṩ����
	//Ĭ�Ϲ��캯�����գ�
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
	//���������͹��캯����û�з���ֵ
	//��������û���β�
	//��һ����������ǰ�Զ�������������
	//���ڷ�ֹ�ڴ�й¶
	//Ĭ�ϵ������������յģ�
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
		cout << "������name�Ŀռ�" << endl;
	}
private:
	int x0;
	int y0;
	char* name;
};
//����������
void test8()
{
	Test t(10, 20);
}


int main()
{
	test8();
	return 0;
}