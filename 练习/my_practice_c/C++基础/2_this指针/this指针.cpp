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
	int getK() const//�����Ҫ����thisָ�룬�����ں���β����const
	{
		//this���մ����Test��ָ��
		//�������const���Σ������޸ģ�this��һ������ָ��
		// �����const���Σ������޸�
		//this->m_k = 100;
		return this->m_k;
	}
#if 0
	static int s_getK()
	{
		//����:thisֻ�����ڷǾ�̬��Ա�����ڲ�
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

	//t1.getK()ʵ�����ǽ�t1�ĵ�ַ����getK()��Ĭ����this����
	cout << t1.getK() << endl;


	return 0;
}