#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
//��ί��ְ�����sort �㷨����
//����5��ѡ�֣��������÷֣���10����ί��5��ѡ�ֽ��д��
//�÷ֹ���ȥ����߷֣�ȥ����ͷ֣�ȡ��ƽ����
//���÷ֶ�5��ѡ������

class Player
{
public:
	Player()
	{

	}
	Player(string name, int score)
	{
		this->mname = name;
		this->mscore = score;
	}
public:
	string mname;
	int mscore;
};
//����ѡ��
void Creat_Player(vector<Player>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Player p;
		p.mname = "ѡ��";
		p.mname += nameSeed[i];
		p.mscore = 0;

		v.push_back(p);
	}
}

//���
void Set_Score(vector<Player>& v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		//��ǰѧ�����д��
		deque<int> dScore;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			dScore.push_back(score);
		}

		//��ʮ�������������� Ĭ�ϴ�С����
		sort(dScore.begin(), dScore.end());

		//ȥ�����߷֣�ȥ����ͷ�
		dScore.pop_back();
		dScore.pop_front();

		//��ƽ����
		int sum = 0;
		for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); dit++)
		{
			sum += (*dit);
		}
		int ave = sum / dScore.size();
		//�������
		(*it).mscore = ave;
	}
}

//�������
bool myCompare(Player& p1, Player& p2)
{
	return p1.mscore > p2.mscore;
}

//���ݷ�������
void Print_Rank(vector<Player>& v)
{
	//����
	sort(v.begin(), v.end(), myCompare);
	//��ӡ
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << (*it).mname << "   " << "�÷֣�" << (*it).mscore << endl;
	}
}
int main()
{
	//����vector����������ѡ����Ϣ
	vector<Player> v;
	Creat_Player(v);
	Set_Score(v);
	Print_Rank(v);



	return 0;
}